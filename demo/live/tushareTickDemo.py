# -*- coding: utf-8 -*-
"""

@author: msi
# 实现tushare的tick级别livefeed读写，与tushare格式兼容，tick级别的与前面的不一样的地方在于策略需求少，就不预先加载数据了，
# 需要预先加载数据的可以照着tushareLiveFeed改
# tushare 请求一条数据平均耗时0.3秒

"""
from cnx import bar
from pyalgotrade.broker.fillstrategy import DefaultStrategy
from pyalgotrade.broker.backtesting import TradePercentage
from pyalgotrade import strategy
from pyalgotrade.broker import backtesting
from pyalgotrade.technical import ma
from cnx.tushare import tushareTickLiveFeed



class TickLiveDemo_run(strategy.BaseStrategy):
    def __init__(self, feed, brk,instruments, n):
        strategy.BaseStrategy.__init__(self, feed, brk)
        self.__instruments = instruments
        self.__apDataSeries = feed[instruments[0]].getApDataSeries()
        self.__sma = ma.SMA(self.__apDataSeries, n)
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
        print bar.getDateTime(), bar.getAp(), self.__sma[-1]

    
    
def testStrategy():
    
    strat = TickLiveDemo_run
    liveFeed = tushareTickLiveFeed.LiveFeed(['600848'], TUSHARE_INQUERY_PERIOD=3)
    brk = backtesting.Broker(1000,liveFeed)
    strat = strat(liveFeed, brk,['600848'],3)
    strat.run()


if __name__ == "__main__": 
    testStrategy()























