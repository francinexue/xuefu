# -*- coding: utf-8 -*-
"""
Created on 2017-07-20
1.这个demo包含两部分，主要演示动态计算指标，如日线的macd，其实在当日的过程中他的数据是不断变化的，macd 12,26这个指标使用的是前N-1日的
数据再加上当日该5分钟的close数据合并出来12，16日数据，当当日结束的时候，5分钟计算出来的数据和日线级别使用当日收盘价计算出的结果相等。
2.这里的例子使用布林带，使用的方法为原始的talib指标
3.pyalgotrade里面的dataSeries中获取数据list 代码为self.day_feed[instrument].getCloseDataSeries()._SequenceDataSeries__values.data()
4.里面附带写了下ATR通道计算例子。
5.本指标为分钟线和日线混合例子
测试bolling线
"""
import pandas as pd
import dynamicIndicatorDemo_run as mdd
from cnx import pyalg_utils
from cnx import dataFramefeed

from pyalgotrade import plotter, bar
from pyalgotrade.tools import resample
from pyalgotrade.stratanalyzer import returns, sharpe


def bolling_trans_data():
    dat = pd.read_csv("../../api/stock/csv/600281SH_min.csv", index_col=['datetime'], encoding='gbk')

    feed = dataFramefeed.Feed(frequency=bar.Frequency.MINUTE)
    feed.addBarsFromDataFrame("orcl", dat)

    resample.resample_to_csv(feed, bar.Frequency.MINUTE * 5,"../../api/stock/csv/600281SH_5min.csv")  # 这样resample的数据是对的




def bolling(code='600281'):
    try:
        dat = pd.read_csv("../../api/stock/csv/%sSH_5min.csv" % code, encoding='gbk')
        dat = dat.fillna(method='pad')
        dat['Adj Close'] = dat['Close']
        dat = dat.rename(columns={'Open': 'open', 'High': 'high', 'Volume': 'volume', 'Close': 'close', 'Low': 'low'})
        dat.index = dat['Date Time']
        dat.index.name = 'date'
    except:
        from api.stock.lib import gm_api as gm
        dat = gm.gm_api().get_hist_data(code, '2015-01-01', ktype='5')
        print dat
        dat['Adj Close'] = dat['close']

    # dat = dat.ix[17000:18000,:]
    feed = dataFramefeed.Feed(frequency=bar.Frequency.MINUTE)
    feed.addBarsFromDataFrame("orcl", dat)

    myStrategy = mdd.bolling_backtest(feed, 'orcl')
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
    #bolling_trans_data()
    bolling('600281')
