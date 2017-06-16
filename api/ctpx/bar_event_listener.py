from abc import ABCMeta, abstractmethod


class BarEventListener(object):
    __metaclass__ = ABCMeta

    @abstractmethod
    def onBarEvent(self, data):
        pass
    @abstractmethod
    def onRtnOrderEvent(self,OrderField):
        pass

    @abstractmethod
    def onRspOrderAction(self,InputOrderActionField,RspInfoField):
        pass
    @abstractmethod
    def onRspOrderInsert(self,InputOrderField,RspInfoField):
        pass

    @abstractmethod
    def onRspQryInvestorPositionDetail(self,InvestorPositionDetailField_dic,requestId):
        pass
    @abstractmethod
    def onRspUserLogin(self,RspUserLoginField):
        pass
    @abstractmethod
    def onRtnTradeEvent(self, TradeField):
        pass
    @abstractmethod
    def onRspQryOrder(self, OrderFieldDic,requestId):
        pass