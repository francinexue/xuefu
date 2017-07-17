# -*- coding: utf-8 -*-
"""

@author: msi
从tushare中加载5min。10min，日线，周线等各级别的实时数据并进行模拟测试
LiveFeed参数：
        :param identifiers: codes
        :param ktype: 同tushare一样，ktype：数据类型，D=日k线 W=周 M=月 5=5分钟 15=15分钟 30=30分钟 60=60分钟，默认为D
        :param preload_start:若需要豫加载前面的数据，则设置开始时间，同tushare的start，str类型
        :param apiCallDelay:后面每5分钟后调用ts的延时，一般用不到30秒
        :param maxLen:

"""
from pyalgotrade import strategy
from pyalgotrade.broker import backtesting
from pyalgotrade.technical import ma

from cnx.tushare import tushareLiveFeed


class LiveDemo_run(strategy.BaseStrategy):
    def __init__(self, feed, brk,instruments, n):
        strategy.BaseStrategy.__init__(self, feed, brk)
        self.__instruments = instruments
        self.__priceDataSeries = feed[instruments[0]].getCloseDataSeries()
        self.__sma = ma.SMA(self.__priceDataSeries, n)
        self.__position = None

    def onEnterCanceled(self, position):
        self.__position = None

    def onEnterOK(self):
        pass

    def onExitOk(self, position):
        self.__position = None
        # self.info("long close")

    def onExitCanceled(self, position):
        self.__position.exitMarket()

    def onBars(self, bars):
        # If a position was not opened, check if we should enter a long position.
        bar = bars[self.__instruments[0]]
        print bar.getDateTime(), bar.getClose(), self.__sma[-1]

    
    
def testStrategy():
    
    strat = LiveDemo_run
    liveFeed = tushareLiveFeed.LiveFeed(['600848'], '5', preload_start='2017-01-01')
    brk = backtesting.Broker(1000,liveFeed)
    strat = strat(liveFeed, brk,['600848'],3)
    strat.run()


if __name__ == "__main__": 
    testStrategy()























