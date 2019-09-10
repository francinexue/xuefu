# -*- coding: utf-8 -*-
# PyAlgoTrade
# @ rebuild by chinese xuefu@pyalgteam.sdu,please call me leiFeng.<sdu.xuefu@gmail.com>
# 实现tushare的livefeed读写，与tushare格式兼容，同时允许自定义在开始livefeed前加载前面n天或者小时等的历史数据，请教我雷锋
# 饿肚子饿到下午
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

import time
import datetime
import threading
import Queue

from pyalgotrade import bar
from pyalgotrade import barfeed
from pyalgotrade.barfeed import membf
from pyalgotrade import dataseries
from pyalgotrade import resamplebase
import pyalgotrade.logger
from pyalgotrade.utils import dt
import tushare as ts
from quant.cnx import dataFramefeed

logger = pyalgotrade.logger.getLogger("tushare")
KTYPE_TO_BASE_FREQUENCY = {'5': bar.Frequency.MINUTE, '15': bar.Frequency.MINUTE, '30': bar.Frequency.MINUTE,
                           '60': bar.Frequency.HOUR
    , 'D': bar.Frequency.DAY, 'W': bar.Frequency.WEEK, 'M': bar.Frequency.MONTH}  # pyalgtrade 真实freq

KTYPE_TO_CALL_FREQUENCY = {'5': bar.Frequency.MINUTE * 5, '15': bar.Frequency.MINUTE * 15,
                           '30': bar.Frequency.MINUTE * 30, '60': bar.Frequency.HOUR
    , 'D': bar.Frequency.DAY, 'W': bar.Frequency.WEEK, 'M': bar.Frequency.MONTH}  # 调用tushare所使用的每隔几分钟启动一次docall


def localnow():
    return dt.as_utc(datetime.datetime.now())


class PollingThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self.__stopped = False

    def __wait(self):
        # Wait until getNextCallDateTime checking for cancelation every 0.5 second.
        nextCall = self.getNextCallDateTime()
        while not self.__stopped and localnow()<nextCall:
            time.sleep((nextCall-localnow()).total_seconds())

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


def build_bar(barDict, frequency):
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
    startDateTimeStr = barDict["date"].values()[0]

    if len(startDateTimeStr) == 10:
        startDateTime = datetime.datetime.strptime(startDateTimeStr, "%Y-%m-%d")
    else:
        startDateTime = datetime.datetime.strptime(startDateTimeStr[:16], '%Y-%m-%d %H:%M')

    return bar.BasicBar(startDateTime, barDict["open"].values()[0], barDict["high"].values()[0], barDict["low"].values()[0], barDict["close"].values()[0],
                        barDict["volume"].values()[0], None, frequency)


class GetBarThread(PollingThread):
    # Events
    ON_BARS = 1

    def __init__(self, queue, identifiers, ktype, frequency, apiCallDelay):
        PollingThread.__init__(self)
        # Map frequency to precision and period.
        self.__precision = ktype

        self.__queue = queue
        self.__identifiers = identifiers
        self.__frequency = frequency
        self.__nextBarClose = None
        # The delay between the bar's close and the API call.
        self.__apiCallDelay = apiCallDelay
        self.__updateNextBarClose()

    # 这段不能省，它是通过计算得出下一次doCall的时间，删了都不知道啥时候该调用了
    def __updateNextBarClose(self):

        self.__nextBarClose = resamplebase.build_range(localnow(), self.__frequency).getEnding()
        logger.info('local: {0} ,nextcall: {1}'.format(localnow(),self.__nextBarClose))

    def getNextCallDateTime(self):
        return self.__nextBarClose + self.__apiCallDelay

    def doCall(self):

        barDict = {}
        self.__updateNextBarClose()
        index_time = ts.get_k_data(code='000001', ktype=self.__precision,index=True).date.values[-1]
        for identifier in self.__identifiers:
            try:
                logger.info('loading data online: {0}'.format(identifier))
                response = ts.get_k_data(code=identifier, ktype=self.__precision)
                response_time = response.date.values[-1]
                if response_time >= index_time:
                    barDict[identifier] = build_bar(response[response.date == index_time].to_dict(), self.__frequency)    #以指数时间为基准，保持bar的一致性
            except:
                logger.error("tushare time out")

        if len(barDict):
            bars = bar.Bars(barDict)
            self.__queue.put((GetBarThread.ON_BARS, bars))


class LiveFeed(dataFramefeed.Feed):
    """A real-time BarFeed that builds bars using XigniteGlobalRealTime API
    (https://www.xignite.com/product/global-real-time-stock-quote-data/).

        :param identifiers: codes
        :param ktype: 同tushare一样，ktype：数据类型，D=日k线 W=周 M=月 5=5分钟 15=15分钟 30=30分钟 60=60分钟，默认为D
        :param preload_start:若需要预先加载前面的数据，则设置开始时间，同tushare的start，str类型
        :param apiCallDelay:后面每5分钟后调用ts的延时，一般用不到30秒
        :param maxLen:

    .. note:: Valid exchange suffixes are:

         * **ARCX**: NYSE ARCA
         * **CHIX**: CHI-X EUROPE LIMITED
         * **XASE**: NYSE MKT EQUITIES
         * **XNAS**: NASDAQ
         * **XNYS**: NEW YORK STOCK EXCHANGE, INC
    """

    QUEUE_TIMEOUT = 0.01

    def __init__(self, identifiers, ktype, preload_start=None, apiCallDelay=30, maxLen=dataseries.DEFAULT_MAX_LEN):
        """

        :param identifiers: codes
        :param ktype: 同tushare一样，ktype：数据类型，D=日k线 W=周 M=月 5=5分钟 15=15分钟 30=30分钟 60=60分钟，默认为D
        :param preload_start:若需要豫加载前面的数据，则设置开始时间，同tushare的start，str类型
        :param apiCallDelay:后面每5分钟后调用ts的延时，一般用不到30秒
        :param maxLen:
        """
        global KTYPE_TO_BASE_FREQUENCY, KTYPE_TO_CALL_FREQUENCY
        dataFramefeed.Feed.__init__(self, KTYPE_TO_BASE_FREQUENCY[ktype], None, maxLen)
        if not isinstance(identifiers, list):
            raise Exception("identifiers must be a list")
        if preload_start is not None:
            self.preload = True
            self.preloadDatas(identifiers, ktype, preload_start)

        self.__queue = Queue.Queue()
        self.__thread = GetBarThread(self.__queue, identifiers, ktype, KTYPE_TO_CALL_FREQUENCY[ktype],
                                     datetime.timedelta(seconds=apiCallDelay))
        for instrument in identifiers:
            self.registerInstrument(instrument)

    ######################################################################
    # observer.Subject interface
    def preloadDatas(self, identifiers, ktype, start):
        """
        预先加载当前日期之前的一段数据
        :param start:str
        :return:
        """

        for identifier in identifiers:
            try:
                response = ts.get_k_data(code=identifier, ktype=ktype, start=start)
                logger.info('preload datas:{0}'.format(identifier))
                response.index = response.date
                self.addBarsFromDataFrame(identifier, response)

            except:
                logger.error("tushare time out")

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
        return dataFramefeed.Feed.peekDateTime(self)

    ######################################################################
    # barfeed.BaseBarFeed interface

    def getCurrentDateTime(self):
        return localnow()

    def barsHaveAdjClose(self):
        return False

    def getNextBars(self):

        ret = None
        if self.preload:
            if not dataFramefeed.Feed.eof(self):
                # print 'not eof'
                # print membf.BarFeed.peekDateTime(self)
                ret = dataFramefeed.Feed.getNextBars(self)

            else:
                self.preload = False

        else:
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
    liveFeed = LiveFeed(['600848','000001'], '5', preload_start='2017-01-01')
    liveFeed.start()

    while not liveFeed.eof():
        bars = liveFeed.getNextBars()
        if bars is not None:
            print bars['600848'].getHigh(), bars['600848'].getDateTime(),bars['000001'].getHigh()
            # test/