# -*- coding: utf-8 -*-
"""
Created on Mon 2.12  21:43:35 2017
to calulate the Bull and the Bear line of the SZ000001 based on Brownian Movement
used -T day as S0,and [-n*t-t,-t]as sample to simulyse day 0
@author: msi
"""
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import scipy.stats as ss


def getShData():
    dat = pd.read_csv("../../api/stock/csv/000001.csv",encoding='gbk', parse_dates=[0], index_col=0)
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
    return dat


def BBcurve(data=getShData()[2000:2330], T=5, n=20, alpha=0.4, resample=False,plot=True):
    """
    T = 5                        # 采样的间隔交易日
    n = 20                       # 采样点数
    alpha = 0.4                  # 落入牛熊价格区间的置信度为(1-alpha)
    resample =true means as T to calulate the line else calculate everyday
    """
    a = ss.t.ppf(1 - alpha / 2, n)  # (1-alpha)置信度对应的区间上限

    close = data.close
    t = close.index.values[n * T:]  # 至少第n*T个交易日才有第1个牛熊计算值
    # 对数日收益率序列
    logreturns = np.diff(np.log(close))
    # 计算mu
    _mean = lambda i: np.mean(logreturns[i - n * T + 1:i + 1])  # calculate range[0,n*T] as mean[0]
    _mean = np.frompyfunc(_mean, 1, 1)
    mu = _mean(np.arange(n * T - 1, len(logreturns)))  # len(data)-n*T 's mu

    # 计算sigma
    _var = lambda i: np.var(logreturns[i - n * T + 1:i + 1])  # len(data)-n*T 's sigma
    _var = np.frompyfunc(_var, 1, 1)
    sigma = _var(np.arange(n * T - 1, len(logreturns)))
    sigma = np.sqrt(sigma.astype(float))

    if resample:
        # 对close,mu,sigma进行同步采样
        t_T = close.index.values[n * T::T]  # from n*T
        close_T = close.values[n * T::T]
        mu_T = mu[::T]
        sigma_T = sigma[::T]

        bull_c = np.log(close_T) + T * mu_T + np.sqrt(T) * sigma_T * a  # starts from n*T,which the list count from 0
        bull_c = np.exp(bull_c.astype(float))  # it calculated the n*T+T day's bull_c
        # uses 'n*T''s close and [0,n*T](not contain 'n*T')'s mu
        bear_c = np.log(close_T) + T * mu_T - np.sqrt(T) * sigma_T * a
        bear_c = np.exp(bear_c.astype(float))

        bb_c = np.log(close_T) + T * mu_T
        bb_c = np.exp(bb_c.astype(float))
        if t_T[-1] != t[-1]:  # the last value may calculated more than the day t[-1],but also can be use
            t_T = np.append(t_T, t[-1:])
            bb = pd.DataFrame({'bull': bull_c, 'bear': bear_c, 'bb': bb_c}, index=t_T[1:])
        else:
            bb = pd.DataFrame({'bull': bull_c[:-1], 'bear': bear_c[:-1], 'bb': bb_c[:-1]}, index=t_T[1:])

        bb = bb.resample('1D').bfill()

    else:
        bull_c = np.log(close.values[n * T:]) + T * mu + np.sqrt(T) * sigma * a
        bull_c = np.exp(bull_c.astype(float))
        bear_c = np.log(close.values[n * T:]) + T * mu - np.sqrt(T) * sigma * a
        bear_c = np.exp(bear_c.astype(float))
        bb_c = np.log(close.values[n * T:]) + T * mu
        bb_c = np.exp(bb_c.astype(float))

        bb = pd.DataFrame({'bull': bull_c[:-T], 'bear': bear_c[:-T], 'bb': bb_c[:-T]}, index=t[T:])
        bb['means'] = bb['bull'].rolling(window=5, center=False).mean()
    plt.figure(figsize=(16, 8))
    plt.plot(t, close[t], 'k', label="$CLOSE$", linewidth=1)
    plt.plot(bb.index.values, bb.bull.values, color='r', label="$Bull$",
             linewidth=2)  # the first one is n*T+T,and the bull_c is for n*T+T
    plt.plot(bb.index.values, bb.bear.values, color='g', label="$Bear$", linewidth=2)
    # plt.plot(bb.index.values, bb.means.values, color='g', label="$BB$", linewidth=2)
    plt.title("Bull and Bear")
    plt.legend()
    plt.grid()
    if plot:
        plt.show()
    return bb


if __name__ == '__main__':
    # pd.read_csv('000002.csv')
    BBcurve(resample=False)
