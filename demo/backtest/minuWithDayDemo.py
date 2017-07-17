# -*- coding: utf-8 -*-
"""
Created on Sun Sep 11 11:31:12 2016
日线和分钟线混合回测的例子，即本来使用5分钟线进行测试，但是中间还应用日线的各种指标，比如突破NN 日均线等
本例子是通过计算ENE轨道，对每日k线突破上轨，中轨，下轨等不同情形进行运算
@author: msi
"""

import sys

sys.path.append("..")

import pandas as pd
import minuWithDayDemo_run as mdd
from cnx import pyalg_utils
from cnx import dataFramefeed

from pyalgotrade import plotter, bar
from pyalgotrade.tools import resample
from pyalgotrade.stratanalyzer import returns, sharpe


##读取分钟线       
def ENE_trans_data():
    dat = pd.read_csv("../../api/stock/csv/600281SH_min.csv", index_col=['datetime'], encoding='gbk')

    feed = dataFramefeed.Feed(frequency=bar.Frequency.MINUTE)
    feed.addBarsFromDataFrame("orcl", dat)

    ###暂时不用
    # resampledBarDS_day = resampled.ResampledBarDataSeries(feed["orcl"], bar.Frequency.DAY)
    # resampledBarDS_5min = resampled.ResampledBarDataSeries(feed["orcl"], bar.Frequency.MINUTE*5)
    # feed.addBarsFromSequence("orcl_d",resampledBarDS_day)

    resample.resample_to_csv(feed, bar.Frequency.MINUTE * 5,
                             "../../api/stock/csv/600281SH_5min.csv")  # 这样resample的数据是对的


    # myStrategy = ENE_backtest(feed, 'orcl')

    # sharpeRatioAnalyzer = sharpe.SharpeRatio()
    # myStrategy.attachAnalyzer(sharpeRatioAnalyzer)
    # plt = plotter.StrategyPlotter(myStrategy, True, True, True)
    # myStrategy.run()"../../api/stock/csv/600281SH_min.csv"
    # plt.plot()


def ENE(type='old', code='600281'):
    dat = pd.read_csv("../../api/stock/csv/%sSH_5min.csv" % code, encoding='gbk')
    dat = dat.fillna(method='pad')
    dat['Adj Close'] = dat['Close']
    dat = dat.rename(columns={'Open': 'open', 'High': 'high', 'Volume': 'volume', 'Close': 'close', 'Low': 'low'})
    dat.index = dat['Date Time']
    dat.index.name = 'date'

    # dat = dat.ix[17000:18000,:]
    feed = dataFramefeed.Feed(frequency=bar.Frequency.MINUTE)
    feed.addBarsFromDataFrame("orcl", dat)

    if type == 'macd':
        myStrategy = mdd.ENE_backtest(feed, 'orcl')
    elif type == 'old':
        myStrategy = mdd.ENE_backtest(feed, 'orcl')
    sharpeRatioAnalyzer = sharpe.SharpeRatio()
    myStrategy.attachAnalyzer(sharpeRatioAnalyzer)

    returnsAnalyzer = returns.Returns()
    myStrategy.attachAnalyzer(returnsAnalyzer)
    plt = plotter.StrategyPlotter(myStrategy, True, True, True)
    plt.getOrCreateSubplot("returns").addDataSeries("Simple returns", returnsAnalyzer.getReturns())

    ds = pyalg_utils.dataSet(myStrategy)  # 抽取交易数据集语句，若使用系统自带画图功能则不需要该项
    myStrategy.run()
    plt.plot()

    print u'最大回撤：\t%f\t 交易笔数：\t%d\t 盈利笔数：\t%d\n' % (ds.getMaxDrawDown(), ds.getCount(), ds.getProfitableCount())
    print u'累计收益：\t%f\t 夏普比率：\t%f\t' % (returnsAnalyzer.getCumulativeReturns()[-1], ds.getSharpeRatio())


if __name__ == '__main__':
    # ENE_trans_data()
    ENE('old', '600281')
