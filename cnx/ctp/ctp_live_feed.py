# -*- coding: utf-8 -*-
from api.ctpx.bar_event_listener import BarEventListener
from api.ctpx.ctpmd import CtpMd
import threading
import time
import datetime
from cnx import dataFramefeed, bar

def localnow():
    return datetime.datetime.now()


class CtpLiveFeed(BarEventListener):
    def __init__(self):
        self._lock = threading.Lock()
        self._bars = {}

    def onBarEvent(self, data):
        tradingDay = data.tradingDay #交易日
        instrumentID = data.instrumentID #合约ID
        exchangeID = data.exchangeID #交易所ID，有可能为空
        exchangeInstID = data.exchangeInstID #合约在交易所中的代码，有可能为空
        lastPrice = data.lastPrice #最新价, 最近成功的上一笔交易的价格
        preSettlementPrice = data.preSettlementPrice #上次结算价
        preClosePrice = data.preClosePrice #上次收盘价
        preOpenInterest = data.preOpenInterest #昨日持仓量
        openPrice = data.openPrice # 今天开盘价
        highestPrice = data.highestPrice #最高价
        lowestPrice = data.lowestPrice #最低价
        volume = data.volume #数量
        turnover = data.turnover #成交金额
        openInterest = data.openInterest #持仓量
        closePrice = data.closePrice #今收盘价, 可能出现Double最大值，表示尚未有值
        settlementPrice = data.settlementPrice #本次结算价
        upperLimitPrice = data.upperLimitPrice #涨停板价
        lowerLimitPrice = data.lowerLimitPrice #跌停板价
        preDelta = data.preDelta #昨虚实度
        currDelta = data.currDelta #今虚实度
        updateTime = data.updateTime #最后修改时间
        updateMillisec = data.updateMillisec #最后修改毫秒
        bidPrice1 = data.bidPrice1 #申买价1
        bidVolume1 = data.bidVolume1 #申买量1
        askPrice1 = data.askPrice1 #申卖价2
        askVolume1 = data.askVolume1 #申卖量2
        bidPrice2 = data.bidPrice2 #申买价2
        bidVolume2 = data.bidVolume2 #申买量2
        askPrice2 = data.askPrice2 #申卖价2
        askVolume2 = data.askVolume2 #申卖量2
        bidPrice3 = data.bidPrice3 #申买价3
        bidVolume3 = data.bidVolume3 #申买量3
        askPrice3 = data.askPrice3 #申卖价3
        askVolume3 = data.askVolume3 #申卖量3
        bidPrice4 = data.bidPrice4 #申买价4
        bidVolume4 = data.bidVolume4 #申买量4
        askPrice4 = data.askPrice4 #申卖价4
        askVolume4 = data.askVolume4 #申卖量4
        bidPrice5 = data.bidPrice5 #申买价5
        bidVolume5 = data.bidVolume5 #申买量5
        askPrice5 = data.askPrice5 #申卖价5
        askVolume5 = data.askVolume5 #申卖量5
        averagePrice = data.averagePrice #昨日均价
        actionDay = data.actionDay #业务日期
        tick = bar.BasicTick(data.updateTime, data.openPrice, data.highestPrice, data.lowestPrice, data.preClosePrice,
                             data.volume, None, data.bidPrice1, data.bidVolume1, data.askPrice1, data.askVolume1, data.preClosePrice,
                             data.volume, data.volume, None, None, bar.Frequency.TRADE, False, {'ap2': data.askPrice2, 'ap3': data.askPrice3,
                                                                                                'ap4': data.askPrice4, 'ap5': data.askPrice5, 'bp2': data.bidPrice2, 'bp3': data.bidPrice3, 'bp4': data.bidPrice4,
                                                                                                'bp5': data.bidPrice5, 'av2': data.askVolume2, 'av3': data.askVolume3, 'av4': data.askVolume4, 'av5': data.askVolume5,
                                                                                                'bv2': data.bidVolume2, 'bv3': data.bidVolume3, 'bv4': data.bidVolume4, 'bv5': data.bidVolume5})
        with self._lock:
            self._bars[data.instrumentID] = tick
            print data.instrumentID == 'cu1707'
            print("{0} acquire the lock.".format(threading.currentThread().getName()))


    def getNextBars(self):
        with self._lock:
            bars = self._bars
            self._bars = {}
        return bars



class CtpMdThread(threading.Thread):
    def __init__(self, barEventListener):
        threading.Thread.__init__(self)
        self.__stopped = False
        self._barEventListener = barEventListener
        self.__nextCallDatetime = localnow()
        self.__CTP_INQUERY_PERIOD = datetime.timedelta(milliseconds=300)

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
        while not self.__stopped:
            self.__wait()
            bars = self._barEventListener.getNextBars()
            print("处理代码")
            bar = bars.get('cu1707')
            if bar:
                print bar.getHigh()

    def getNextCallDateTime(self):
        self.__nextCallDatetime += self.__CTP_INQUERY_PERIOD
        if self.__nextCallDatetime < localnow():
            self.__nextCallDatetime = localnow()
        return self.__nextCallDatetime


if __name__ == "__main__":
    ctpMd = CtpMd("mdconn/")
    # print(ctpMd.getApiVersion())

    # address = "tcp://218.202.237.33:10012"
    address = "tcp://180.168.146.187:10031"
    ctpMd.login(address, "090285", "ABCabc", "9999")
    time.sleep(10)

    ctpMd.subscribeMarketData(['cu1707'])
    lsn = CtpLiveFeed()
    ctpMd.addBarEventListener(lsn)

    # t1 = threading.Thread(target=loop, args=(lsn,))
    t1 = CtpMdThread(lsn)
    t1.start()

    # ctpMd.logout()
    # ctpMd.release()
    # while True:
    #     time.sleep(2)

    ctpMd.join()


