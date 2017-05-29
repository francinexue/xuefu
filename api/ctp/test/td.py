# -*- coding: utf-8 -*-
from ctptd import CtpTd
import ctptd
import time


class Td(CtpTd):
    def __init__(self, szFlowPath=""):
        super(Td, self).__init__(szFlowPath)

    def onFrontConnected(self):
        print("AAAAAAAAAAAAAAAAAAAABBBBBBBBBBB")
        reqLoginField = ctptd.ReqUserLoginField()
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

td = Td("tdconn/")
print(td.getApiVersion())
td.registerSpi()
td.init()

# address = "tcp://180.168.146.187:10010"
address = "tcp://180.168.146.187:10031"
td.registerFront(address)
print("33333333333333333333333333333")

# while True:
#     time.sleep(5)

time.sleep(10)
userLogoutField = ctptd.UserLogoutField()
# userLogoutField.userID = "090285"
# userLogoutField.brokerID = "9999"
userLogoutField.userID = ""
userLogoutField.brokerID = ""
td.reqUserLogout(userLogoutField, 1)
# time.sleep(20)
print("################SSSSSSSSSSSSSS")
# td.release()
print("###############aaaaaaaaa")
td.join()
