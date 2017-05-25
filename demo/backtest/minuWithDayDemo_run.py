# -*- coding: utf-8 -*-
"""
Created on Sat Sep 17 16:54:50 2016
日线和分钟线混合回测的例子，即本来使用5分钟线进行测试，但是中间还应用日线的各种指标，比如突破NN 日均线等
@author: msi
"""

import sys

sys.path.append("..")

from datetime import datetime, timedelta

from pyalgotrade import strategy, bar
from pyalgotrade.technical import ma


class ENE_backtest(strategy.BacktestingStrategy):
    def __init__(self, feed, instrument):
        strategy.BacktestingStrategy.__init__(self, feed)
        # 自定义日线级别dataseries
        self.__instrument = instrument
        self.__feed = feed
        self.setUseAdjustedValues(False)
        self.__position = None
        self.__ENE = None

        self.__feed_day = self.resampleBarFeed(frequency=bar.Frequency.DAY, callback=self.resample_callback)

        # MA10[-1]包含今天的收盘价内容，所以取过去的10天值再加上当前分钟线的OPEN（也就是上一个bar的close值）值
        # ENE轨道走到某一日的五分钟的时候是变动的，但是判断上升趋势则按日线（11日）的前天和昨天
        self.__MA10 = ma.SMA(self.__feed_day[instrument].getCloseDataSeries(), 10, 2)
        self.__MA11 = ma.SMA(self.__feed_day[instrument].getCloseDataSeries(), 11, 2)
        ##############各种信号量########
        self.initState = False;  # 开头的几个过滤掉
        self.eneUpMode = False;  # ENE 日线向下
        self.buyType = None;  # 买入的类型，“UP”是上升趋势中轨买入，‘DOWN’是下降趋势下轨买入
        self.buyWaitSignal = False;  # 买入等待信号
        self.sellWaitSignal = False;  # 卖出等待信号
        self.holdDay = datetime.min;  # 持有的日期

        self.sellinfo = '';

        self.min_ma5 = ma.SMA(self.__feed[instrument].getCloseDataSeries(), 5)  # 5分线5均
        self.min_ma10 = ma.SMA(self.__feed[instrument].getCloseDataSeries(), 10)  # 5分线5均
        self.min_ma20 = ma.SMA(self.__feed[instrument].getCloseDataSeries(), 20)  # 5分线5均
        self.min_ma30 = ma.SMA(self.__feed[instrument].getCloseDataSeries(), 30)  # 5分线5均
        self.min_ma60 = ma.SMA(self.__feed[instrument].getCloseDataSeries(), 60)  # 5分线5均

        self.__count = 0

    def resample_callback(self, some_number, bars):

        #####################bars为pyalgotrade.bar.Bars，self.getFeed()[self.__instrument]为 <class 'pyalgotrade.dataseries.bards.BarDataSeries'>################
        #####bars = self.getFeed()[self.__instrument]   #若使用这个的话调用的是分钟线，或者需要重写一个Dataserie   
        #####closeSeries = bars.getCloseDataSeries()    
        # print "Resampled", bars.getDateTime(), bars[self.__instrument].getClose()  #另一套可用

        # print "日線",bars.getDateTime(),self.__MA10[-1],self.__MA11[-1]     #当分钟线走到 16号的时候，其ma10[-1]是15号的，也就是日线仍走到15号，但其15号的数据日线收盘价等数据全都有
        # self.eneLastData =
        if 1 > 2:
            print type(bars), type(self.getFeed()[self.__instrument])

    def onEnterOk(self, position):
        execInfo = position.getEntryOrder().getExecutionInfo()
        self.info("BUY at ￥%.2f" % (execInfo.getPrice()))

    def onEnterCanceled(self, position):
        self.__position = None

    def onExitOk(self, position):
        execInfo = position.getExitOrder().getExecutionInfo()
        self.info("SELL at ￥%.2f%s" % (execInfo.getPrice(), self.sellinfo))
        self.__position = None

    def onExitCanceled(self, position):
        # If the exit was canceled, re-submit it.
        self.__position.exitMarket()

        ##检查分钟均线状况

    def checkMinCondition(self):
        if self.min_ma5[-1] > self.min_ma10[-1] > self.min_ma20[-1] > self.min_ma30[-1] > self.min_ma60[-1]:  # 多头排列
            return 'UP';
        if self.min_ma5[-1] < self.min_ma10[-1] < self.min_ma20[-1] < self.min_ma30[-1] < self.min_ma60[-1]:  # 空头排列
            return 'DOWN';

        return 'UN_FLUNE';  # 多空不明

    ##检查ENE轨道状况   
    def checkENECondition(self):
        if self.__ENE > self.__MA11[-1]:  # self.__MA11[-1] > self.__MA11[-2]
            eneSignal = 'UP'
        else:
            eneSignal = 'DOWN'

        return eneSignal;

    def onBars(self, bars):
        # If a position was not opened, check if we should enter a long position.
        self.__count += 1
        # if self.__count>500:
        # return

        if self.initState is False:  # 如果MA均线有数值了才开始计算
            if self.__MA10.__len__() != 2:
                return
            else:
                if self.__MA10[-1] is None:
                    return
                else:
                    self.initState = True;

        if (bars.getDateTime() - self.holdDay) < timedelta(days=1):  # 持有期大于一天
            return

        ma = (self.__MA10[-1] * 10.0 + bars[self.__instrument].getOpen()) / 11.0
        self.__UPPER = float(
            1 + 10.0 / 100) * ma  ##############当分钟线走到第二天的时候，日线仍走到前一天self.__feed_day[self.__instrument].getCloseDataSeries()[-1]仍为前一天的
        self.__LOWER = float(1 - 9.0 / 100) * ma
        self.__ENE = (self.__UPPER + self.__LOWER) / 2

        price = bars[self.__instrument].getOpen()
        # print "分鐘線",bars.getDateTime()
        buySignal = False
        sellSignal = False

        if self.__position is None or not self.__position.isOpen() and self.buyWaitSignal is False:  # 未持有,未下穿过
            if self.checkENECondition() == 'UP':  # 上升通道
                # print '上升通道',bars.getDateTime(),price,self.__UPPER
                if price > self.__ENE:
                    return;
                else:  # 当前价格在中轨之下，可以尝试买入
                    self.buyWaitSignal = True;
                    self.buyType = 'UP';
            else:  # 下降通道
                return
                # print '下降通道',bars.getDateTime(),price,self.__LOWER
                if price > self.__LOWER:
                    return;
                else:  # 穿过下轨
                    self.buyWaitSignal = True;
                    self.buyType = 'DOWN';


                    # if bars.getDateTime().strftime("%Y-%m-%d")>'2015-05-04' and bars.getDateTime().strftime("%Y-%m-%d")<'2015-06-10':
                    #       print bars.getDateTime(),price,self.buyWaitSignal,self.checkMinCondition(),self.__LOWER

        if self.buyWaitSignal is True:  # 出现一次下穿情况，直接等待均线排列好买入
            if self.checkMinCondition() is not 'UP':  # 添加日线死叉条件不买入
                return;
            else:
                buySignal = True;

        if buySignal is True and self.__position == None:  # 买入操作
            shares = 100 * (int(self.getBroker().getCash() * 0.7 / bars[self.__instrument].getPrice()) / 100)
            self.__position = self.enterLong(self.__instrument, shares, True)
            buySignal = False;
            self.buyWaitSignal = False;
            self.holdDay = bars.getDateTime();
            return;

        if not self.__position.exitActive() and self.sellWaitSignal is False:

            if self.buyType == 'UP':  # 上升趋势买入的
                if price < self.__LOWER:  # 下穿下轨（大跌趋势）
                    if self.checkENECondition() == 'DOWN':  # 下降通道
                        self.sellWaitSignal = True
                        self.sellinfo = "上升趋势买入,跌至下轨"
                    else:  # 不予理睬
                        return
                elif price >= self.__UPPER:  # 上穿上轨准备卖出
                    self.sellWaitSignal = True
                    self.sellinfo = "上升趋势买入,上穿上轨"
                else:  # 上轨和下之间不予理睬
                    return

            if self.buyType == 'DOWN':  # 下降趋势买入的
                if price < self.__LOWER:  # 再次刺穿下轨
                    return  # 降低也不管
                    if self.checkENECondition() == 'DOWN':  # 下降通道
                        self.sellWaitSignal = True
                        self.sellinfo = "下降趋势买入,下穿下轨"
                    else:  # 上升通道下穿下轨不予理睬（估计很难出现这种情况）
                        return
                elif price >= self.__ENE:  # 上穿中轨且下降通道准备卖出
                    if self.checkENECondition() == 'DOWN':  # 下降通道
                        self.sellWaitSignal = True
                        self.sellinfo = "下降趋势买入,上穿中轨"
                else:  # 下轨和中轨之间不予理睬
                    return

        if self.sellWaitSignal is True:  # 出现一次下穿情况，直接等待均线排列好买入
            if self.checkMinCondition() is not 'DOWN':
                return;
            else:
                sellSignal = True;

        if sellSignal is True:  # 卖出操作
            self.__position.exitMarket()
            sellSignal = False;
            self.sellWaitSignal = False;
            self.buyType = None;
