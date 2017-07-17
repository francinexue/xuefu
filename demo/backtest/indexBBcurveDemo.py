# -*- coding: utf-8 -*-
"""
Created on Sun Sep 11 11:31:12 2016

@author: msi
根据丁鹏-<量化投资策略与技术>书中描述的依据布朗运动计算牛熊线，判断大盘指数，并作为择时操作的依据，牛市、熊市、震荡市策略各有不同
此处择时买卖策略仅是简单的超过牛线则买入，跌破熊线则卖出
"""

import pandas as pd
from pyalgotrade import strategy, plotter
from pyalgotrade.stratanalyzer import returns, sharpe
from pyalgotrade.technical import ma, cross

from cnx import dataFramefeed, pyalg_utils
from utils import BBcurve2


class kdj_backtest(strategy.BacktestingStrategy):
    def __init__(self, feed, instrument, param, df):
        strategy.BacktestingStrategy.__init__(self, feed)
        # 自定义日线级别dataseries
        self.__instrument = instrument
        self.__feed = feed
        self.setUseAdjustedValues(False)
        self.__position = None
        self.__param = param
        self.__bb = df
        self.__count = 0
        self.__prices = self.__feed[self.__instrument].getCloseDataSeries()

        self.__sma = ma.SMA(self.__prices, 5)

        # zhu yi weilai shuju

    def onEnterOk(self, position):
        execInfo = position.getEntryOrder().getExecutionInfo()
        self.info("BUY at ￥%.2f" % (execInfo.getPrice()))

    def onEnterCanceled(self, position):
        self.__position = None

    def onExitOk(self, position):
        execInfo = position.getExitOrder().getExecutionInfo()
        # self.info("SELL at ￥%.2f" % (execInfo.getPrice()))
        self.__position = None

    def onExitCanceled(self, position):
        # If the exit was canceled, re-submit it.
        self.__position.exitMarket()

    def checkBB(self, bars):
        signal = 0
        bb = self.__bb[['bull', 'bear', 'bb']][self.__bb.index <= bars.getDateTime()].tail(2)
        self.__bull, self.__bear = bb.bull.values, bb.bear.values

        if bb is None:  # to check the first item is Nan
            return signal

        if cross.cross_above(self.__prices, self.__bull):
            signal = 1
        elif cross.cross_below(self.__prices, self.__bear):
            signal = -1
        return signal

    def onBars(self, bars):

        self.__count += 1
        signal = self.checkBB(bars)
        # if self.__count > 2530 :
        #    print bars.getDateTime(), self.__k[-1], self.__d[-1], bars[self.__instrument].getClose()


        if self.__position is None or not self.__position.isOpen():
            if signal == 1:
                shares = 100 * (int(self.getBroker().getCash() * 0.7 / bars[self.__instrument].getPrice()) / 100)

                self.__position = self.enterLong(self.__instrument, shares, True)
                # print "BUY:", self.__prices[-1], self.getBroker().getShares(self.__instrument), shares, self.__prices[-1] * shares / self.getBroker().getCash(), self.getBroker().getCash()

        elif not self.__position.exitActive():
            if signal == -1:
                self.__position.exitMarket()
                # print "SELL: ", self.__prices[-1], self.getBroker().getShares(self.__instrument), self.getBroker().getCash()


def kdj(param=[14, 3, 0, 3, 0, 70, 30]):
    # dat = ts.get_k_data("000001", start='2006-07-01', end='2017-01-05', index=True)
    # dat.to_csv("000001.csv",encoding='gbk',index=False)
    dat = pd.read_csv("../../api/stock/csv/000001.csv", encoding='gbk', parse_dates=[0], index_col=0)
    dat = dat.fillna(method='pad')
    dat['Adj Close'] = dat['close']
    dat.index.name = 'date'
    dat = dat[['open', 'close', 'high', 'low', 'volume', 'Adj Close']]  # the index catch high<open in 2010-02-01

    def handle_data(x):
        if x[2] < x[0]:
            x[2] = x[0]
        if x[3] > x[0]:
            x[3] = x[0]
        return x

    dat = dat.apply(handle_data, axis=1)
    # print dat.head()

    feed = dataFramefeed.Feed()
    feed.addBarsFromDataFrame("orcl", dat)

    myStrategy = kdj_backtest(feed, 'orcl', param=param,
                              df=BBcurve2.BBcurve(data=dat,plot=False))  # set the param of STOCH and crossover
    sharpeRatioAnalyzer = sharpe.SharpeRatio()
    myStrategy.attachAnalyzer(sharpeRatioAnalyzer)

    returnsAnalyzer = returns.Returns()
    myStrategy.attachAnalyzer(returnsAnalyzer)
    plt = plotter.StrategyPlotter(myStrategy, True, True, True)
    plt.getOrCreateSubplot("returns").addDataSeries("Simple returns", returnsAnalyzer.getReturns())
    ds = pyalg_utils.dataSet(myStrategy)  # 抽取交易数据集语句，若使用系统自带画图功能则不需要该项
    myStrategy.run()
    plt.plot()

    # slowk,slowd = talib.STOCH(dat.high.values,dat.low.values,dat.close.values,14,3,0,3,0)
    # print slowk[-1],slowd[-1]
    print u'drawndown：\t%f\t tradingCount：\t%d\t profitCount：\t%d\n' % (
    ds.getMaxDrawDown(), ds.getCount(), ds.getProfitableCount())
    print u'culmutiveReturn：\t%f\t sharpRatio：\t%f\t' % (
    returnsAnalyzer.getCumulativeReturns()[-1], ds.getSharpeRatio())


if __name__ == '__main__':
    # ENE_trans_data()
    over = [70]
    blew = [30]
    day = [14]
    for i in over:
        for k in day:
            param = [k, 3, 0, 3, 0, i, blew[over.index(i)]]
            kdj(param)
