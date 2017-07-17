# -*- coding: utf-8 -*-
"""
Created on Sun Sep 11 11:31:12 2016
ta-lib示例，示例包含使用原生talib,pyalgotrade自带talib，调用自己写的util.formular中的公式
@author:xuefu
#from stackoverflow we knows that when use talib in pyalgotrade,talibext only calculate once,it won't
calculate new result when new bar is feed,so the indicator should be call in every onBars call.
#another caution is the talibext's parameter 'count' starts from 0 to -1,as soon as
we must use count = len(barDs)
# the result of STOCH()  kdj is different with TongHuaShun, Reason unknown,Maybe 'MaType'

#slowk,slowd = talib.STOCH(dat.high.values,dat.low.values,dat.close.values,14,3,0,3,0)
 equals to indicator.STOCH(self.__feed[self.__instrument],len(self.__feed[self.__instrument]),
                                       14,3,0,3,0)
#at last trans the df of the kdj from utils.formular into backtestStrategy
"""

from cnx import dataFramefeed,pyalg_utils
from utils import formular
import pandas as pd
from pyalgotrade import strategy, plotter
from pyalgotrade.technical import ma, cross
from pyalgotrade.stratanalyzer import returns, sharpe

from pyalgotrade.talibext import indicator
from talib import MA_Type
import talib
import numpy as np
from pyalgotrade.technical import macd
class kdj_backtest(strategy.BacktestingStrategy):
    def __init__(self, feed, instrument,param,df):
        strategy.BacktestingStrategy.__init__(self, feed)
        # 自定义日线级别dataseries
        self.__instrument = instrument
        self.__feed = feed
        self.setUseAdjustedValues(False)
        self.__position = None
        self.__param  = param
        self.__kd = df
        self.__count = 0
        self.__prices = self.__feed[self.__instrument].getCloseDataSeries()
        self.__macd = macd.MACD(feed[instrument].getPriceDataSeries(), 12, 26, 9).getHistogram()

        self.__sma = ma.SMA(self.__prices, 5)

        # zhu yi weilai shuju

    def onEnterOk(self, position):
        execInfo = position.getEntryOrder().getExecutionInfo()
        self.info("BUY at ￥%.2f" % (execInfo.getPrice()))

    def onEnterCanceled(self, position):
        self.__position = None

    def onExitOk(self, position):
        execInfo = position.getExitOrder().getExecutionInfo()
        self.info("SELL at ￥%.2f" % (execInfo.getPrice()))
        self.__position = None

    def onExitCanceled(self, position):
        # If the exit was canceled, re-submit it.
        self.__position.exitMarket()
    def checkkdj(self,bars):
        signal = 0
        # this time we can use k[-1]'s data
        ##########################  using talib
        # If a position was not opened, check if we should enter a long position.
        # self.__stoch = indicator.STOCH(self.__feed[self.__instrument],len(self.__feed[self.__instrument]),
        #                               self.__param[0],self.__param[1],self.__param[2],self.__param[3],self.__param[4])
        # self.__k,self.__d = self.__stoch[0],self.__stoch[1]

        ########################## using utils.formular for kdj:this is true
        kd = self.__kd[['KDJ_K', 'KDJ_D']][self.__kd.index <= bars.getDateTime()].tail(2)
        self.__k, self.__d = kd.KDJ_K.values, kd.KDJ_D.values
        if self.__k.__len__() < 2:
            return signal
        #########################
        if cross.cross_above(self.__k, [self.__param[6], self.__param[6]]) > 0 \
            or cross.cross_above(self.__k,   [self.__param[5],self.__param[5]]) > 0:  # 得取其high前一天的值cross 参数为2，所以high中至少应当有3个值
            signal = 1
        elif cross.cross_below(self.__k, [self.__param[6],self.__param[6]]) > 0 \
            or cross.cross_below(self.__k, [self.__param[5],self.__param[5]]) > 0:
            signal = -1

        return signal

    def checkAdx(self,bars):
        signal = 0
        self.__adx = indicator.AROON(self.__feed[self.__instrument],len(self.__feed[self.__instrument]),14)
        self.plus_di = indicator.PLUS_DI(self.__feed[self.__instrument],len(self.__feed[self.__instrument]),14)
        self.minus_di = indicator.MINUS_DI(self.__feed[self.__instrument], len(self.__feed[self.__instrument]), 14)
        if self.__adx is None or self.__macd is None or len(self.__macd) < 2:  # to check the first item is Nan
            return signal
        print self.__macd[-2]
        if self.__macd[-2]<0 and self.__macd[-1]>0 and self.__adx[-1] > self.__adx[-2] \
                and self.plus_di[-1] > self.minus_di[-1]:
            signal = 1
        elif self.__macd[-2]>0 and self.__macd[-1]<0 and self.__adx[-1] < self.__adx[-2] \
                and self.plus_di[-1] < self.minus_di[-1]:
            signal = -1

        return signal
    def checkAroon(self,bars):
        signal = 0
        self.__aroondown,self.__aroonup = indicator.Adx(self.__feed[self.__instrument],len(self.__feed[self.__instrument]),20)
        self.__aroon = self.__aroonup[-2:] - self.__aroondown[-2:]

        if self.__aroon is None or np.isnan(self.__aroon[0]):  # to check the first item is Nan
            return signal

        if cross.cross_above(self.__aroon,[15,15]):
            signal = 1
        elif cross.cross_below(self.__aroon,[15,15]):
            signal = -1

        return signal
    def onBars(self, bars):

        self.__count += 1
        signal = self.checkkdj(bars)
        #if self.__count > 2530 :
        #    print bars.getDateTime(), self.__k[-1], self.__d[-1], bars[self.__instrument].getClose()


        if self.__position is None or not self.__position.isOpen():
            if signal == 1:
                shares = 100 * (int(self.getBroker().getCash() * 0.7 / bars[self.__instrument].getPrice()) / 100)

                self.__position = self.enterLong(self.__instrument, shares, True)
                #print "BUY:", self.__prices[-1], self.getBroker().getShares(self.__instrument), shares, self.__prices[-1] * shares / self.getBroker().getCash(), self.getBroker().getCash()

        elif not self.__position.exitActive():
            if signal == -1:
                 self.__position.exitMarket()
                #print "SELL: ", self.__prices[-1], self.getBroker().getShares(self.__instrument), self.getBroker().getCash()


def kdj(param = [14,3,0,3,0,70,30]):
    #dat = ts.get_k_data("000001", start='2006-07-01', end='2017-01-05', index=True)
    #dat.to_csv("000002.csv",encoding='gbk',index=False)
    dat = pd.read_csv("../../api/stock/csv/000007.csv",encoding='gbk',parse_dates=[0],index_col=0)

    dat = dat.fillna(method='pad')
    dat['Adj Close'] = dat['close']
    dat.index.name = 'date'
    dat = dat[['open','close','high','low','volume','Adj Close']]  # the index catch high<open in 2010-02-01
    def handle_data(x):
        if x[2] <x[0]:
            x[2] = x[0]
        if x[3] > x[0]:
            x[3] = x[0]
        return x
    dat = dat.apply(handle_data,axis=1)
    #print dat.head()

    feed = dataFramefeed.Feed()
    feed.addBarsFromDataFrame("orcl", dat)

    myStrategy = kdj_backtest(feed, 'orcl',param = param,df=formular.KDJ(dat,14,3,3))  #set the param of STOCH and crossover
    sharpeRatioAnalyzer = sharpe.SharpeRatio()
    myStrategy.attachAnalyzer(sharpeRatioAnalyzer)

    returnsAnalyzer = returns.Returns()
    myStrategy.attachAnalyzer(returnsAnalyzer)
    plt = plotter.StrategyPlotter(myStrategy, True, True, True)
    plt.getOrCreateSubplot("returns").addDataSeries("Simple returns", returnsAnalyzer.getReturns())
    ds = pyalg_utils.dataSet(myStrategy)  # 抽取交易数据集语句，若使用系统自带画图功能则不需要该项
    myStrategy.run()
    #plt.plot()

    #slowk,slowd = talib.STOCH(dat.high.values,dat.low.values,dat.close.values,14,3,0,3,0)
    #print slowk[-1],slowd[-1]
    print u'drawndown：\t%f\t tradingCount：\t%d\t profitCount：\t%d\n' % (ds.getMaxDrawDown(), ds.getCount(), ds.getProfitableCount())
    print u'culmutiveReturn：\t%f\t sharpRatio：\t%f\t' % (returnsAnalyzer.getCumulativeReturns()[-1], ds.getSharpeRatio())

if __name__ == '__main__':
    # ENE_trans_data()
    over = [70]
    blew = [30]
    day = [14]
    for i in over:
        for k in day:
            param = [k,3,0,3,0,i,blew[over.index(i)]]
            print '%d day %d over %d blew'%(k,i,blew[over.index(i)])
            kdj(param)