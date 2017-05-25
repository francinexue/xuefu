# -*- coding: utf-8 -*-
"""
Created on Tue Oct 06 11:13:33 2015
从tushare 中在线读取以及使用pandas读取缓存的csv文件
提供两种数据调取方式，一种为系统自带画图，另一种提供array方式各数据的接口，详见cn.lib.pyalg_utils.py
@author: lenovo
"""

import pandas as pd
from matplotlib.pyplot import plot
from pyalgotrade import plotter
from pyalgotrade.stratanalyzer import returns

import pandasDemo_run as pdr
from cn.lib import pyalg_utils, dataFramefeed


def turtle_test(loadtype='tushare', dataString='pyalg'):
    """
    :param dataString:
    :return:
    """
    # 从dataFrame中加载，
    if loadtype == 'tushare':
        import tushare as ts
        dat = ts.get_h_data('600848')
        dat.index.name = 'date'
    else:
        dat = pd.read_csv("../../api/stock/csv/600848.csv", index_col=0, encoding='gbk')
    feed = dataFramefeed.Feed()
    feed.addBarsFromDataFrame("orcl", dat)
    myStrategy = pdr.turtle(feed, "orcl", 20, 10)
    # Attach a returns analyzers to the strategy.
    returnsAnalyzer = returns.Returns()
    myStrategy.attachAnalyzer(returnsAnalyzer)

    # Attach the plotter to the strategy.
    plt = plotter.StrategyPlotter(myStrategy)
    # Plot the simple returns on each bar.
    plt.getOrCreateSubplot("returns").addDataSeries("Simple returns", returnsAnalyzer.getReturns())

    if dataString == 'pyalg_util':
        ds = pyalg_utils.dataSet(myStrategy)  # 抽取交易数据集语句，若使用系统自带画图功能则不需要该项
    myStrategy.run()
    myStrategy.info("Final portfolio value: $%.2f" % myStrategy.getResult())

    if dataString == 'pyalg_util':
        rs = ds.getDefault()  # 获取默认的交易信息，dic格式
        plot(rs["cumulativeReturns"][:, 0], rs["cumulativeReturns"][:, 1])  # 简单作图示例

    plt.plot()


if __name__ == '__main__':
    turtle_test(loadtype='tuxshare')
