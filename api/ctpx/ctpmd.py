# -*- coding: utf-8 -*-
import time
import platform
if platform.architecture()[1] == "ELF":
    from ctp.linux import ctpmd as md
elif platform.architecture()[0] == "64bit":
    from ctp.win64 import ctpmd as md
else:
    from ctp.win32 import ctpmd as md


class CtpMd(md.CtpMd):
    def __init__(self, szFlowPath="", usingUdp=False, multicast=False):
        super(CtpMd, self).__init__(szFlowPath, usingUdp, multicast)
        self._requestId = 0

    def onFrontConnected(self):
        """当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。"""
        reqLoginField = md.ReqUserLoginField()
        reqLoginField.userID = "090285"
        reqLoginField.password = "ABCabc"
        reqLoginField.brokerID = "9999"
        self.reqUserLogin(reqLoginField, self._requestId)
        self._requestId += 1

    def onFrontDisconnected(self, reasonCode):
        """0x2003 收到错误报文"""
        pass

    def onHeartBeatWarning(self, lapsedTime):
        """@:param lapsedTime 距离上次接收报文的时间"""
        pass

    def onRspUserLogin(self, RspUserLoginField, RspInfoField, requestId, final):
        """登录请求响应"""
        # pass
        print("-------------login requestId ----------")
        print(RspInfoField.errorMsg)
        print(RspInfoField.errorID)
        print(RspUserLoginField.brokerID)
        print(RspUserLoginField.userID)
        print(RspUserLoginField.loginTime)
        print(requestId)

    def onRspUserLogout(self, UserLogoutField, RspInfoField, requestId, final):
        """登出请求响应"""
        # pass
        print("##########000000000000000000000000")

    def onRspError(self, RspInfoField, requestId, final):
        """错误应答"""
        # pass
        print("SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs")
        self.release()
        errorMsg = RspInfoField.errorMsg
        f = open("file", "wb")
        f.write(errorMsg)
        f.close()
        print (requestId)
        print (final)
        print (errorMsg)
        print (RspInfoField.errorID)

    def onRspSubMarketData(self, SpecificInstrumentField, RspInfoField, requestId, final):
        """订阅行情应答"""
        pass

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
        pass

    def onRtnForQuoteRsp(self, ForQuoteRspField):
        """询价通知"""
        pass

ctpMd = CtpMd("mdconn/")
print(ctpMd.getApiVersion())
ctpMd.registerSpi()
ctpMd.init()

address = "tcp://218.202.237.33:10012"
# address = "tcp://180.168.146.187:10031"
ctpMd.registerFront(address)
print("33333333333333333333333333333")

# while True:
#     time.sleep(5)

time.sleep(10)
userLogoutField = md.UserLogoutField()
# userLogoutField.userID = "090285"
# userLogoutField.brokerID = "9999"
userLogoutField.userID = ""
userLogoutField.brokerID = ""
ctpMd.reqUserLogout(userLogoutField, 1)
# time.sleep(20)
print("################SSSSSSSSSSSSSS")
# ctpMd.release()
print("###############aaaaaaaaa")
ctpMd.join()
