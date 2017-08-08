# -*- coding: utf-8 -*-
"""
Created on Sat Sep 17 16:54:50 2016
日线和分钟线混合回测的例子，即本来使用5分钟线进行测试，但是中间还应用日线的各种指标，比如突破NN 日均线等
****np.array(self.day_closeDataList.append(bar.getClose()))  这样写是错误的
self.day_closeDataList.append(bar.getClose() 返回的是None，https://stackoverflow.com/questions/20016802/why-the-list-append-return-none
他本身已经添加到了List中，而不会返回，append是一个破坏性的方法
****
@author: msi
"""

import sys

sys.path.append("..")
import talib as ta
import numpy as np
from datetime import datetime, timedelta

from pyalgotrade import strategy, bar
from pyalgotrade.technical import ma
from pyalgotrade.talibext import indicator

class bolling_backtest(strategy.BacktestingStrategy):
    def __init__(self, feed, instrument):
        strategy.BacktestingStrategy.__init__(self, feed)
        # 自定义日线级别dataseries
        self.__instrument = instrument
        self.__feed = feed
        self.setUseAdjustedValues(False)
        self.__position = None
        self.__bolling = None

        self.day_feed = self.resampleBarFeed(frequency=bar.Frequency.DAY, callback=self.resample_callback)
        self.day_closeDataList = self.day_feed[instrument].getCloseDataSeries()._SequenceDataSeries__values.data()
        self.day_ma60 = ma.EMA(self.day_feed[instrument].getCloseDataSeries(), 60)
        self.day_ma30 = ma.EMA(self.day_feed[instrument].getCloseDataSeries(), 30)
        self.day_ma20 = ma.EMA(self.day_feed[instrument].getCloseDataSeries(), 30)


        ##############各种信号量########
        self.initState = False  # 开头的几个过滤掉
        self.buyWaitSignal = False  # 买入等待信号
        self.sellWaitSignal = False  # 卖出等待信号
        self.holdDay = datetime.min  # 持有的日期

        self.min_ma5 = ma.EMA(self.__feed[instrument].getCloseDataSeries(), 5)  # 5分线5均
        self.min_ma10 = ma.EMA(self.__feed[instrument].getCloseDataSeries(), 10)  # 5分线5均
        self.min_ma20 = ma.EMA(self.__feed[instrument].getCloseDataSeries(), 20)  # 5分线5均
        self.min_ma30 = ma.EMA(self.__feed[instrument].getCloseDataSeries(), 30)  # 5分线5均
        self.min_ma60 = ma.EMA(self.__feed[instrument].getCloseDataSeries(), 60)  # 5分线5均

        self.__count = 0

    def resample_callback(self, some_number, bars):
        if 1 > 2:
            print type(bars), type(self.getFeed()[self.__instrument])

    def onEnterOk(self, position):
        execInfo = position.getEntryOrder().getExecutionInfo()
        self.info(u"BUY at ￥%.2f" % (execInfo.getPrice()))
        self.holdDay = self.__position.getEntryOrder().getSubmitDateTime().replace(hour=9,minute=15,second=0)

    def onEnterCanceled(self, position):
        self.__position = None

    def onExitOk(self, position):
        execInfo = position.getExitOrder().getExecutionInfo()
        self.info(u"SELL at ￥%.2f" % (execInfo.getPrice()))
        self.__position = None
        self.holdDay = None
    def onExitCanceled(self, position):
        # If the exit was canceled, re-submit it.
        self.__position.exitMarket()

    def updateParams(self,bar):
        self.day_closeDataList.append(bar.getClose())
        closeDataArray = np.array(self.day_closeDataList)
        self.day_closeDataList.pop(-1)
        self.UPPER,self.MIDDLE,self.LOWER = ta.BBANDS(closeDataArray.astype('float'),20,2,2,0)
        #self.checkATR()
    def checkATR(self):
        _ = indicator.ATR(self.day_feed[self.__instrument],len(self.day_feed[self.__instrument]), 20)

    def checkValueAtRisk(self,bar):
        #检查系统性风险
        return True

    def checkEnterSignal(self,bar):

        price = bar.getClose()
        if not self.buyWaitSignal:   #check buywait
            if (self.UPPER[-1] / self.MIDDLE[-1] - 1) < 0.05:
                pass
            elif price < self.LOWER[-1]:
                self.buyWaitSignal = True
                print bar.getDateTime(), '--------buy wait'
        elif self.buyWaitSignal and self.checkMinCondition() == 'UP':
            self.buyWaitSignal = False
            return True

        return False

    def checkExitSignal(self,bar):
        price = bar.getClose()

        if (bar.getDateTime() - self.holdDay) < timedelta(days=1):  # 持有期大于一天
            return

        if not self.sellWaitSignal:   #check sellwait
            if bar.getDateTime().strftime('%Y-%m-%d') == '2016-09-07':
                print bar.getDateTime(),'---',price,'---',self.UPPER[-1]
            if price > self.UPPER[-1]:
                self.sellWaitSignal = True
                print bar.getDateTime(),'--------sell wait'

        elif self.sellWaitSignal and self.checkMinCondition() == 'DOWN':
            self.sellWaitSignal = False
            return True

        return False

    def checkMinCondition(self):
        if self.min_ma5[-1] > self.min_ma10[-1] > self.min_ma20[-1] > self.min_ma30[-1] > self.min_ma60[-1]:  # 多头排列
            return 'UP'
        if self.min_ma5[-1] < self.min_ma10[-1] < self.min_ma20[-1] < self.min_ma30[-1] < self.min_ma60[-1]:  # 空头排列
            return 'DOWN'

        return 'UN_FLUNE'  # 多空不明


    def onBars(self, bars):

        if not self.initState:  # 如果MA均线有数值了才开始计算
            if self.day_ma60.__len__() == 0:
                return
            if self.day_ma60[-1] is None:
                return
            else:
                self.initState = True


        bar = bars[self.__instrument]
        self.updateParams(bar)


        if not self.checkValueAtRisk(bar):
            if self.__position != None and not self.__position.exitActive():
                if (bar.getDateTime() - self.holdDay) < timedelta(days=1):  # 持有期大于一天
                    pass
                else:
                    print 'position is not none,---exit market'
                    self.__position.exitMarket()
            return

        if self.__position is None or not self.__position.isOpen():
            if self.checkEnterSignal(bar):
                shares = 100 * (int(self.getBroker().getCash() * 0.7 / bars[self.__instrument].getPrice()) / 100)
                self.__position = self.enterLong(self.__instrument, shares, True)

        elif self.__position is not None and not self.__position.exitActive():
            if self.checkExitSignal(bar):
                self.__position.exitMarket()



