# -*- coding: utf-8 -*-
"""
Created on Mon Dec 07 21:37:31 2015
重写marketOrder，改为判定是否使用对价交易，对于tick级别的策略来说，限价单及其他品种的单子是没有意义的，要么
是用当前的价格进，要么是用对价进，没有中间价，理论上应该不给用户设置价格的地方，只能二选一
@author: xuefu
"""
import abc
import logging

import pyalgotrade.broker
from pyalgotrade.broker import backtesting
from pyalgotrade import observer
from pyalgotrade import dispatcher
import quant.cnx.strategy.tickPosition
from pyalgotrade import logger
from pyalgotrade.barfeed import resampled
from pyalgotrade.strategy import BaseStrategy
class BacktestingStrategy(BaseStrategy):
    """Base class for backtesting strategies.

    :param barFeed: The bar feed to use to backtest the strategy.
    :type barFeed: :class:`pyalgotrade.barfeed.BaseBarFeed`.
    :param cash_or_brk: The starting capital or a broker instance.
    :type cash_or_brk: int/float or :class:`pyalgotrade.broker.Broker`.

    .. note::
        This is a base class and should not be used directly.
    """

    def __init__(self, barFeed, cash_or_brk=1000000):
        # The broker should subscribe to barFeed events before the strategy.
        # This is to avoid executing orders submitted in the current tick.

        if isinstance(cash_or_brk, pyalgotrade.broker.Broker):
            broker = cash_or_brk
        else:
            broker = backtesting.Broker(cash_or_brk, barFeed)

        BaseStrategy.__init__(self, barFeed, broker)
        self.__useAdjustedValues = False
        self.setUseEventDateTimeInLogs(True)
        self.setDebugMode(True)

    def setDebugMode(self, debugOn):
        """Enable/disable debug level messages in the strategy and backtesting broker.
        This is enabled by default."""
        level = logging.DEBUG if debugOn else logging.INFO
        self.getLogger().setLevel(level)
        self.getBroker().getLogger().setLevel(level)

    def enterLong(self, instrument, quantity,goodTillCanceled=False, allOrNone=False,onOpposite=False):
        """Generates a buy :class:`pyalgotrade.broker.MarketOrder` to enter a long position.

        :param instrument: Instrument identifier.
        :type instrument: string.
        :param quantity: Entry order quantity.
        :type quantity: int.
        :param goodTillCanceled: True if the entry order is good till canceled. If False then the order gets automatically canceled when the session closes.
        :type goodTillCanceled: boolean.
        :param allOrNone: True if the orders should be completely filled or not at all.
        :type allOrNone: boolean.
        :rtype: The :class:`pyalgotrade.strategy.position.Position` entered.
        """

        return quant.cnx.strategy.tickPosition.LongPosition(self, instrument, None, None, quantity, goodTillCanceled, allOrNone,onOpposite)

    def enterShort(self, instrument, quantity, goodTillCanceled=False, allOrNone=False,onOpposite=False):
        """Generates a sell short :class:`pyalgotrade.broker.MarketOrder` to enter a short position.

        :param instrument: Instrument identifier.
        :type instrument: string.
        :param quantity: Entry order quantity.
        :type quantity: int.
        :param goodTillCanceled: True if the entry order is good till canceled. If False then the order gets automatically canceled when the session closes.
        :type goodTillCanceled: boolean.
        :param allOrNone: True if the orders should be completely filled or not at all.
        :type allOrNone: boolean.
        :rtype: The :class:`pyalgotrade.strategy.position.Position` entered.
        """

        return quant.cnx.strategy.tickPosition.ShortPosition(self, instrument, None, None, quantity, goodTillCanceled, allOrNone,onOpposite)

    def marketOrder(self, instrument, quantity, onOpposite=False, goodTillCanceled=False, allOrNone=False):
        """Submits a market order.

        :param instrument: Instrument identifier.
        :type instrument: string.
        :param quantity: The amount of shares. Positive means buy, negative means sell.
        :type quantity: int/float.
        :param onClose: True if the order should be filled as close to the closing price as possible (Market-On-Close order). Default is False.
        :type onClose: boolean.
        :param goodTillCanceled: True if the order is good till canceled. If False then the order gets automatically canceled when the session closes.
        :type goodTillCanceled: boolean.
        :param allOrNone: True if the order should be completely filled or not at all.
        :type allOrNone: boolean.
        :rtype: The :class:`pyalgotrade.broker.MarketOrder` submitted.
        onOpposite：对价交易，做多的时候使用ap1，空的时候使用bp1
        """


        ret = None
        if quantity > 0:
            ret = self.getBroker().createMarketOrder(pyalgotrade.broker.Order.Action.BUY, instrument, quantity, onOpposite)
        elif quantity < 0:
            ret = self.getBroker().createMarketOrder(pyalgotrade.broker.Order.Action.SELL, instrument, quantity*-1, onOpposite)
        if ret:
            ret.setGoodTillCanceled(goodTillCanceled)
            ret.setAllOrNone(allOrNone)
            self.getBroker().submitOrder(ret)
        return ret