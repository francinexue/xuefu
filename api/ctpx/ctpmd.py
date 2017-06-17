# -*- coding: utf-8 -*-
import time
import platform
import os

from utils import logger_factory
logger = logger_factory.getLogger(__name__)

if platform.architecture()[1] == "ELF":
    from ctp.linux import ctpmd as md
elif platform.architecture()[0] == "64bit":
    from ctp.win64 import ctpmd as md
else:
    from ctp.win32 import ctpmd as md

path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'mdconn/')
if not os.path.exists(path):
    os.makedirs(path)

class CtpMd(md.CtpMd):
    def __init__(self, szFlowPath=path, usingUdp=False, multicast=False):
        super(CtpMd, self).__init__(szFlowPath, usingUdp, multicast)
        self._requestId = 0
        self._userID = ''
        self._password = ''
        self._brokerID = ''
        self._marketDataInstrumentIDs = set()
        self._barEventListeners = set()

    def onFrontConnected(self):
        """当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。"""
        reqLoginField = md.ReqUserLoginField()
        reqLoginField.userID = self._userID
        reqLoginField.password = self._password
        reqLoginField.brokerID = self._brokerID
        self._requestId += 1
        self.reqUserLogin(reqLoginField, self._requestId)

    def onFrontDisconnected(self, reasonCode):
        """0x2003 收到错误报文"""
        logger.info(u'行情服务器连接断开，错误码是%d', reasonCode)

    def onHeartBeatWarning(self, lapsedTime):
        """@:param lapsedTime 距离上次接收报文的时间"""
        pass

    def onRspUserLogin(self, RspUserLoginField, RspInfoField, requestId, final):
        """登录请求响应"""
        # pass
        if RspInfoField.errorID == 0:
            log = u'行情服务器登陆成功'
        else:
            log = u'行情服务登陆失败，错误码:{0}, 错误信息：{1}'.format(
                RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk'))
        logger.info(log)
        if self._marketDataInstrumentIDs:
            super(CtpMd, self).subscribeMarketData(list(self._marketDataInstrumentIDs))

    def onRspUserLogout(self, UserLogoutField, RspInfoField, requestId, final):
        """登出请求响应"""
        if RspInfoField.errorID == 0:
            log = u'行情服务器登出成功'
        else:
            log = u'行情服务登出失败，错误码:[{0}], 错误信息:[{1}]'.format(
                RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk'))
        logger.info(log)

    def onRspError(self, RspInfoField, requestId, final):
        """错误应答"""
        log = u'行情服务响应错误，错误码:[{0}], 错误信息:[{1}]'.format(
           RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk'))
        logger.info(log)

    def onRspSubMarketData(self, SpecificInstrumentField, RspInfoField, requestId, final):
        """订阅行情应答"""
        logger.info(u'订阅的instrumentID：{0}，响应结果，错误码：[{1}]，错误信息：【{2}]'.format(
            SpecificInstrumentField.instrumentID, RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk')))

    def onRspUnSubMarketData(self, SpecificInstrumentField, RspInfoField, requestId, final):
        """取消订阅行情应答"""
        pass

    def onRspSubForQuoteRsp(self, SpecificInstrumentField, RspInfoField, requestId, final):
        """订阅询价应答"""
        pass

    def onRspUnSubForQuoteRsp(self, SpecificInstrumentField, RspInfoField, requestId, final):
        """取消订阅询价应答"""
        pass

    def onRtnDepthMarketData(self, DepthMarketDataField):
        """深度行情通知"""
        for listener in self._barEventListeners:
            listener.onBarEvent(DepthMarketDataField)

    def onRtnForQuoteRsp(self, ForQuoteRspField):
        """询价通知"""
        pass

    def login(self, szFrontAddress, userID, password, brokerID):
        self._brokerID = brokerID
        self._userID = userID
        self._password = password
        self.registerSpi()
        self.init()
        self.registerFront(szFrontAddress)

    def logout(self):
        userLogoutField = md.UserLogoutField()
        userLogoutField.userID = self._userID
        userLogoutField.brokerID = self._brokerID
        self._requestId += 1
        self.reqUserLogout(userLogoutField, self._requestId)

    def subscribeMarketData(self, instrumentIDs):
        if instrumentIDs:
            super(CtpMd, self).subscribeMarketData(instrumentIDs)
            self._marketDataInstrumentIDs = self._marketDataInstrumentIDs.union(instrumentIDs)

    def unSubscribeMarketData(self, instrumentIDs):
        if instrumentIDs:
            super(CtpMd, self).unSubscribeMarketData(instrumentIDs)
            self._marketDataInstrumentIDs = self._marketDataInstrumentIDs.difference(instrumentIDs)

    def addBarEventListener(self, BarEventListener):
        if BarEventListener and BarEventListener not in self._barEventListeners:
            self._barEventListeners.add(BarEventListener)

    def removeBarEventListener(self, BarEventListener):
        if BarEventListener and BarEventListener in self._barEventListeners:
            self._barEventListeners.remove(BarEventListener)


if __name__ == "__main__":
    ctpMd = CtpMd("mdconn/")
    # print(ctpMd.getApiVersion())

    # address = "tcp://218.202.237.33:10012"
    # address = "tcp://180.168.146.187:10010"
    # address = "tcp://180.168.146.187:10011"
    address = "tcp://180.168.146.187:10031"
    ctpMd.login(address, "090285", "ABCabc", "9999")
    time.sleep(10)

    ctpMd.subscribeMarketData(['cu1707'])

    # ctpMd.logout()
    # ctpMd.release()
    # while True:
    #     time.sleep(2)

    ctpMd.join()
# tradingDay = data.tradingDay #交易日
# instrumentID = data.instrumentID #合约ID
# exchangeID = data.exchangeID #交易所ID，有可能为空
# exchangeInstID = data.exchangeInstID #合约在交易所中的代码，有可能为空
# lastPrice = data.lastPrice #最新价, 最近成功的上一笔交易的价格
# preSettlementPrice = data.preSettlementPrice #上次结算价
# preClosePrice = data.preClosePrice #上次收盘价
# preOpenInterest = data.preOpenInterest #昨日持仓量
# openPrice = data.openPrice # 今天开盘价
# highestPrice = data.highestPrice #最高价
# lowestPrice = data.lowestPrice #最低价
# volume = data.volume #数量
# turnover = data.turnover #成交金额
# openInterest = data.openInterest #持仓量
# closePrice = data.closePrice #今收盘价, 可能出现Double最大值，表示尚未有值
# settlementPrice = data.settlementPrice #本次结算价
# upperLimitPrice = data.upperLimitPrice #涨停板价
# lowerLimitPrice = data.lowerLimitPrice #跌停板价
# preDelta = data.preDelta #昨虚实度
# currDelta = data.currDelta #今虚实度
# updateTime = data.updateTime #最后修改时间
# updateMillisec = data.updateMillisec #最后修改毫秒
# bidPrice1 = data.bidPrice1 #申买价1
# bidVolume1 = data.bidVolume1 #申买量1
# askPrice1 = data.askPrice1 #申卖价2
# askVolume1 = data.askVolume1 #申卖量2
# bidPrice2 = data.bidPrice2 #申买价2
# bidVolume2 = data.bidVolume2 #申买量2
# askPrice2 = data.askPrice2 #申卖价2
# askVolume2 = data.askVolume2 #申卖量2
# bidPrice3 = data.bidPrice3 #申买价3
# bidVolume3 = data.bidVolume3 #申买量3
# askPrice3 = data.askPrice3 #申卖价3
# askVolume3 = data.askVolume3 #申卖量3
# bidPrice4 = data.bidPrice4 #申买价4
# bidVolume4 = data.bidVolume4 #申买量4
# askPrice4 = data.askPrice4 #申卖价4
# askVolume4 = data.askVolume4 #申卖量4
# bidPrice5 = data.bidPrice5 #申买价5
# bidVolume5 = data.bidVolume5 #申买量5
# askPrice5 = data.askPrice5 #申卖价5
# askVolume5 = data.askVolume5 #申卖量5
# averagePrice = data.averagePrice #昨日均价
# actionDay = data.actionDay #业务日期
