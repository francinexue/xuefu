# -*- coding: utf-8 -*-
from ctpmd import CtpMd
import ctpmd
import time


class Md(CtpMd):
    def __init__(self, szFlowPath="", usingUdp=False, multicast=False):
        super(Md, self).__init__(szFlowPath, usingUdp, multicast)

    def onFrontConnected(self):
        print("AAAAAAAAAAAAAAAAAAAABBBBBBBBBBB")
        reqLoginField = ctpmd.ReqUserLoginField()
        reqLoginField.userID = "090285"
        reqLoginField.password = "ABCabc"
        reqLoginField.brokerID = "9999"
        self.reqUserLogin(reqLoginField, 0)


    def onFrontDisconnected(self, reasonCode):
        print("sssssssssss:")
        print(reasonCode)

    def onHeartBeatWarning(self, lapsedTime):
        print(lapsedTime)

    def onRspUserLogin(self, rspUserLoginField, rspInfoField, requestId, final):
        print("-------------login requestId ----------")
        print(rspInfoField.errorMsg)
        print (rspInfoField.errorID)
        print (rspUserLoginField.brokerID)
        print (rspUserLoginField.userID)
        print (rspUserLoginField.loginTime)
        print(requestId)

    def onRspUserLogout(userLogoutField, rspInfoField, requestId, final):
        print("##########000000000000000000000000")

    def onRspError(self, rspInfoField, requestId, final):
        print("SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs")
        self.release()
        errorMsg = rspInfoField.errorMsg
        f = open("file", "wb")
        f.write(errorMsg)
        f.close()
        print (requestId)
        print (final)
        print (errorMsg)
        print (rspInfoField.errorID)

md = Md("mdconn/")
print(md.getApiVersion())
md.registerSpi()
md.init()

# address = "tcp://180.168.146.187:10010"
address = "tcp://180.168.146.187:10031"
md.registerFront(address)
print("33333333333333333333333333333")

# while True:
#     time.sleep(5)

time.sleep(10)
userLogoutField = ctpmd.UserLogoutField()
# userLogoutField.userID = "090285"
# userLogoutField.brokerID = "9999"
userLogoutField.userID = ""
userLogoutField.brokerID = ""
md.reqUserLogout(userLogoutField, 1)
# time.sleep(20)
print("################SSSSSSSSSSSSSS")
# md.release()
print("###############aaaaaaaaa")
md.join()
