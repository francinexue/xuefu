# -*- coding: utf-8 -*-
"""
Created on Tue Oct 06 11:13:33 2015
vwanp 提供组合管理示例
@author: lenovo
"""

import pandas as pd
from matplotlib.pyplot import plot
from pyalgotrade import plotter
from pyalgotrade.barfeed import yahoofeed
from pyalgotrade.stratanalyzer import returns, sharpe

import pandasDemo_run as pdr
from cnx import pyalg_utils, dataFramefeed


def vwap(plot):
    """
    组合管理示例
    :param plot:
    :return:
    """
    instrument = ["lenovo", "mi"]
    vwapWindowSize = 5
    threshold = 0.01
    # Download the bars.
    feed = yahoofeed.Feed()
    feed.addBarsFromCSV("lenovo", "../../api/stock/csv/600847.csv")
    feed.addBarsFromCSV("mi","../../api/stock/csv/600848.csv")

    strat = pdr.VWAPMomentum(feed, instrument, vwapWindowSize, threshold)
    sharpeRatioAnalyzer = sharpe.SharpeRatio()
    strat.attachAnalyzer(sharpeRatioAnalyzer)

    if plot:
        plt = plotter.StrategyPlotter(strat, True, True, True)
        # plt.getPortfolioSubplot().addDataSeries("vwap", strat.getVWAP()[instrument[-1]])
    ds = pyalg_utils.dataSet(strat)  # 抽取交易数据集语句，若使用系统自带画图功能则不需要该项
    strat.run()
    print "Sharpe ratio: %.2f" % sharpeRatioAnalyzer.getSharpeRatio(0.05)

    if plot:
        plt.plot()

    rs = ds.getReturns()  # 获取默认的交易信息，dic格式,可忽略
    # for items in rs:
    # print items[0],items[1]


if __name__ == '__main__':
    vwap(True)
