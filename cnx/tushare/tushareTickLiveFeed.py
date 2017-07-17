# -*- coding: utf-8 -*-
# PyAlgoTrade
# @ rebuild by chinese xuefu@pyalgteam.sdu,please call me leiFeng.<sdu.xuefu@gmail.com>
# 实现tushare的tick级别livefeed读写，与tushare格式兼容，tick级别的与前面的不一样的地方在于策略需求少，就不预先加载数据了，
# 需要预先加载数据的可以照着tushareLiveFeed改
# tushare 请求一条数据平均耗时慢的日子7秒，可能赶上了速度慢的时候，平均0.3秒
# Copyright 2011-2015 Gabriel Martin Becedillas Ruiz
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""
.. moduleauthor:: Gabriel Martin Becedillas Ruiz <gabriel.becedillas@gmail.com>
"""

import Queue
import datetime
import threading
import time

import pyalgotrade.logger
import tushare as ts
from pyalgotrade import dataseries
from pyalgotrade import resamplebase
from pyalgotrade.barfeed import membf
from pyalgotrade.utils import dt

from quant.cnx.lib import dataFramefeed, bar

logger = pyalgotrade.logger.getLogger("tushare")


def localnow():
    return datetime.datetime.now()


class PollingThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self.__stopped = False

    def __wait(self):
        # Wait until getNextCallDateTime checking for cancelation every 0.5 second.
        nextCall = self.getNextCallDateTime()
        start_time = localnow()
        while not self.__stopped and localnow() < nextCall:
            time.sleep((nextCall - start_time).seconds)

    def stop(self):
        self.__stopped = True

    def stopped(self):
        return self.__stopped

    def run(self):
        logger.debug("Thread started.")
        while not self.__stopped:
            self.__wait()
            if not self.__stopped:
                try:
                    self.doCall()
                except Exception, e:
                    logger.critical("Unhandled exception", exc_info=e)
        logger.debug("Thread finished.")

    # Must return a non-naive datetime.
    def getNextCallDateTime(self):
        raise NotImplementedError()

    def doCall(self):
        raise NotImplementedError()


def build_bar(barDict):
    # "StartDate": "3/19/2014"
    # "StartTime": "9:55:00 AM"
    # "EndDate": "3/19/2014"
    # "EndTime": "10:00:00 AM"
    # "UTCOffset": 0
    # "Open": 31.71
    # "High": 31.71
    # "Low": 31.68
    # "Close": 31.69
    # "Volume": 2966
    # "Trades": 19
    # "TWAP": 31.6929
    # "VWAP": 31.693

    startDate = barDict["date"]
    startTime = barDict["time"]
    startDateTimeStr = startDate + " " + startTime
    startDateTime = datetime.datetime.strptime(startDateTimeStr, '%Y-%m-%d %H:%M:%S')
    #startDateTime = startDateTime.replace(microsecond=datetime.datetime.now().microsecond)  #rtushare返回的数值没有毫秒，自动添加一个
    return bar.BasicTick(startDateTime, float(barDict['open']), float(barDict['high']), float(barDict['low']), float(barDict['pre_close']),
                         float(barDict['volume']), float(barDict['amount']), float(barDict['b1_p']), float(barDict['b1_v']),
                         float(barDict['a1_p']), float(barDict['a1_v']),float(barDict['pre_close']), float(barDict['volume']),
                         float(barDict['volume']), float(barDict['amount']), float(barDict['amount']),bar.Frequency.TRADE, False,
                         {'ap2': float(barDict['a2_p']), 'ap3': float(barDict['a3_p']), 'ap4': float(barDict['a4_p']),
                          'ap5': float(barDict['a5_p']), 'bp2': float(barDict['b2_p']), 'bp3': float(barDict['b3_p']),
                          'bp4': float(barDict['b4_p']), 'bp5': float(barDict['b5_p']), 'av2': float(barDict['a2_v']),
                          'av3': float(barDict['a3_v']), 'av4': float(barDict['a4_v']), 'av5': float(barDict['a5_v']),
                          'bv2': float(barDict['b2_v']), 'bv3': float(barDict['b3_v']), 'bv4': float(barDict['b4_v']),
                          'bv5': float(barDict['b5_v'])})


class GetBarThread(PollingThread):
    # Events
    ON_BARS = 1

    def __init__(self, queue, identifiers, TUSHARE_INQUERY_PERIOD):
        PollingThread.__init__(self)
        # Map frequency to precision and period.

        self.__queue = queue
        self.__identifiers = identifiers
        self.__nextCallDatetime = localnow()
        self.__TUSHARE_INQUERY_PERIOD = TUSHARE_INQUERY_PERIOD
        self.__last_response_time = None  #tushare Feed live 独有，因为tushare返回的tick数据只到秒，导致存在重复的bar。

    def getNextCallDateTime(self):
        self.__nextCallDatetime += self.__TUSHARE_INQUERY_PERIOD
        if self.__nextCallDatetime < localnow():
            self.__nextCallDatetime = localnow()
        return self.__nextCallDatetime

    def doCall(self):
        barDict = {}
        try:
            a = time.time()
            response = ts.get_realtime_quotes(self.__identifiers)
            logger.info('response cost: %f'%(time.time()-a))
            if self.__last_response_time != response.iloc[-1]['time']:
                for identifier in self.__identifiers:
                    barDict[identifier] = build_bar(response[response.code == identifier].iloc[-1])  # dataFrame 格式转换
            else:
                logger.info("bar is the same with previous bar at time %s,not refresh"%response.iloc[-1]['time'])
            self.__last_response_time = response.iloc[-1]['time']

        except:
            logger.error("tushare time out")
            import traceback
            traceback.print_exc()

        if len(barDict):
            bars = bar.Ticks(barDict)
            self.__queue.put((GetBarThread.ON_BARS, bars))


class LiveFeed(dataFramefeed.TickFeed):
    """A real-time BarFeed that builds bars using XigniteGlobalRealTime API
    (https://www.xignite.com/product/global-real-time-stock-quote-data/).

        :param identifiers: codes

        :param TUSHARE_INQUERY_PERIOD 每隔几秒钟请求一次，默认3秒钟
        :param maxLen:

    .. note:: Valid exchange suffixes are:

         * **ARCX**: NYSE ARCA
         * **CHIX**: CHI-X EUROPE LIMITED
         * **XASE**: NYSE MKT EQUITIES
         * **XNAS**: NASDAQ
         * **XNYS**: NEW YORK STOCK EXCHANGE, INC
    """

    QUEUE_TIMEOUT = 0.01

    def __init__(self, identifiers, TUSHARE_INQUERY_PERIOD=3, maxLen=dataseries.DEFAULT_MAX_LEN):
        """

        :param identifiers: codes
        global KTYPE_TO_BASE_FREQUENCY, KTYPE_TO_CALL_FREQUENCY
        """

        dataFramefeed.TickFeed.__init__(self, bar.Frequency.TRADE, None, maxLen)
        if not isinstance(identifiers, list):
            raise Exception("identifiers must be a list")

        self.__queue = Queue.Queue()
        self.__thread = GetBarThread(self.__queue, identifiers, datetime.timedelta(seconds=TUSHARE_INQUERY_PERIOD))
        for instrument in identifiers:
            self.registerInstrument(instrument)

    def start(self):
        if self.__thread.is_alive():
            raise Exception("Already strated")

        # Start the thread that runs the client.
        self.__thread.start()

    def stop(self):
        self.__thread.stop()

    def join(self):
        if self.__thread.is_alive():
            self.__thread.join()

    def eof(self):
        return self.__thread.stopped()

    def peekDateTime(self):
        return dataFramefeed.TickFeed.peekDateTime(self)

    ######################################################################
    # barfeed.BaseBarFeed interface

    def getCurrentDateTime(self):
        return localnow()

    def barsHaveAdjClose(self):
        return False

    def getNextBars(self):

        ret = None

        try:
            eventType, eventData = self.__queue.get(True, LiveFeed.QUEUE_TIMEOUT)
            if eventType == GetBarThread.ON_BARS:
                ret = eventData
            else:
                logger.error("Invalid event received: %s - %s" % (eventType, eventData))
        except Queue.Empty:
            pass
        return ret


if __name__ == '__main__':
    liveFeed = LiveFeed(['600848'], TUSHARE_INQUERY_PERIOD=3)
    liveFeed.start()

    while not liveFeed.eof():
        bars = liveFeed.getNextBars()
        if bars is not None:
            print bars['600848'].getHigh(), bars['600848'].getDateTime(),type(bars['600848'].getVolume())
            # test/
