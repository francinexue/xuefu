# -*- coding: utf-8 -*-
"""
Created on 2017-05-29
@author:xuefu pyalgotrade chinese team
# 从csv中读取tick数据并进行回测
# 注意和pandasDemo一个样子，dataframe的index列需要为时间（可以str类型或者datetime），且将其中的
# ap1读取为pyalgotrade的ap，同理包括av1,bp1,bv1，其余的数据项自动加载不用管
# 图就不画了，pyalgotrade原作者封装的画图类不支持毫秒数，想画图的话用我封装的pyalg_utils抽取出来交易数据,然后使用matplotlib的时候
# 设置一下
plt.gca().xaxis.set_major_formatter(matplotlib.dates.DateFormatter('%Y-%m-%d %H:%M:%S.%f')

"""
import pandas as pd
from pyalgotrade import bar
from pyalgotrade import strategy
from pyalgotrade.broker.backtesting import TradePercentage
from pyalgotrade.broker.fillstrategy import DefaultStrategy
from pyalgotrade.technical import ma

from cnx import dataFramefeed


class tickDemo_run(strategy.BacktestingStrategy):
    def __init__(self, feed, instrument, n):
        strategy.BacktestingStrategy.__init__(self, feed)
        self.__instrument = instrument
        self.getBroker().setFillStrategy(DefaultStrategy(None))
        self.getBroker().setCommission(TradePercentage(0.001))
        self.__apDataSeries = feed['orcl'].getApDataSeries()
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
        bar = bars[self.__instrument]
        print bar.getDateTime(), bar.getBp(), bar.getAp(), self.__sma[-1]


def tickStrategy(plot=True):
    strat = tickDemo_run
    frequency = bar.Frequency.TRADE
    import time
    a = time.time()
    dat = pd.read_csv("../../api/stock/csv/600288SH.csv", index_col=0, encoding='gbk')
    dat.index = dat.datetime

    ######索引列为日期(格式可选str或datetime，不能含有重复，时间精确到毫秒
    tickfeed = dataFramefeed.TickFeed()
    # tickfeed.set_datetime_format('%Y-%m-%d %H:%M:%S.%f')  #可通过该选项设置数据index列的时间格式
    tickfeed.addBarsFromDataFrame("orcl", dat)

    print 'load time :', time.time() - a
    strat = strat(tickfeed, 'orcl', 5)
    strat.run()


if __name__ == "__main__":
    tickStrategy()
