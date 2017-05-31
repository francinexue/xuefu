# -*- coding: utf-8 -*-
import time
import platform
if platform.architecture()[1] == "ELF":
    from ctp.linux import ctptd as td
elif platform.architecture()[0] == "64bit":
    from ctp.win64 import ctptd as td
else:
    from ctp.win32 import ctptd as td


class CtpTd(td.CtpTd):
    def __init__(self, szFlowPath=""):
        super(CtpTd, self).__init__(szFlowPath)
        self._requestId = 0

    def onFrontConnected(self):
        """当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。"""
        print("login in @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
        reqLoginField = td.ReqUserLoginField()
        reqLoginField.userID = "090285"
        reqLoginField.password = "ABCabc"
        reqLoginField.brokerID = "9999"
        self.reqUserLogin(reqLoginField, self._requestId)
        self._requestId += 1

    def onFrontDisconnected(self, reasonCode):
        """0x2003 收到错误报文"""
        pass

    def onHeartBeatWarning(self, lapsedTime):
        """@param lapsedTime 距离上次接收报文的时间"""
        pass

    def onRspAuthenticate(self, RspAuthenticateField, RspInfoField, requestId, final):
        """客户端认证响应"""
        pass

    def onRspUserLogin(self, RspUserLoginField, RspInfoField, requestId, final):
        """登录请求响应"""
        print("-------------login requestId ----------")
        print(RspInfoField.errorMsg)
        print(RspInfoField.errorID)
        print(RspUserLoginField.brokerID)
        print(RspUserLoginField.userID)
        print(RspUserLoginField.loginTime)
        print(requestId)

    def onRspUserLogout(self, UserLogoutField, RspInfoField, requestId, final):
        """登出请求响应"""
        print("----------------------+++++++++++++++++++++")
        # pass

    def onRspUserPasswordUpdate(self, UserPasswordUpdateField, RspInfoField, requestId, final):
        """用户口令更新请求响应"""
        pass

    def onRspTradingAccountPasswordUpdate(self, TradingAccountPasswordUpdateField, RspInfoField, requestId, final):
        """资金账户口令更新请求响应"""
        pass

    def onRspOrderInsert(self, InputOrderField, RspInfoField, requestId, final):
        """报单录入请求响应"""
        pass

    def onRspParkedOrderInsert(self, ParkedOrderField, RspInfoField, requestId, final):
        """预埋单录入请求响应"""
        pass

    def onRspParkedOrderAction(self, ParkedOrderActionField, RspInfoField, requestId, final):
        """预埋撤单录入请求响应"""
        pass

    def onRspOrderAction(self, InputOrderActionField, RspInfoField, requestId, final):
        """报单操作请求响应"""
        pass

    def onRspQueryMaxOrderVolume(self, QueryMaxOrderVolumeField, RspInfoField, requestId, final):
        """查询最大报单数量响应"""
        pass

    def onRspSettlementInfoConfirm(self, SettlementInfoConfirmField, RspInfoField, requestId, final):
        """投资者结算结果确认响应"""
        pass

    def onRspRemoveParkedOrder(self, RemoveParkedOrderField, RspInfoField, requestId, final):
        """删除预埋单响应"""
        pass

    def onRspRemoveParkedOrderAction(self, RemoveParkedOrderActionField, RspInfoField, requestId, final):
        """删除预埋撤单响应"""
        pass

    def onRspExecOrderInsert(self, InputExecOrderField, RspInfoField, requestId, final):
        """执行宣告录入请求响应"""
        pass

    def onRspExecOrderAction(self, InputExecOrderActionField, RspInfoField, requestId, final):
        """执行宣告操作请求响应"""
        pass

    def onRspForQuoteInsert(self, InputForQuoteField, RspInfoField, requestId, final):
        """询价录入请求响应"""
        pass

    def onRspQuoteInsert(self, InputQuoteField, RspInfoField, requestId, final):
        """报价录入请求响应"""
        pass

    def onRspQuoteAction(self, InputQuoteActionField, RspInfoField, requestId, final):
        """报价操作请求响应"""
        pass

    def onRspBatchOrderAction(self, InputBatchOrderActionField, RspInfoField, requestId, final):
        """批量报单操作请求响应"""
        pass

    def onRspCombActionInsert(self, InputCombActionField, RspInfoField, requestId, final):
        """申请组合录入请求响应"""
        pass

    def onRspQryOrder(self, OrderField, RspInfoField, requestId, final):
        """请求查询报单响应"""
        pass

    def onRspQryTrade(self, TradeField, RspInfoField, requestId, final):
        """请求查询成交响应"""
        pass

    def onRspQryInvestorPosition(self, InvestorPositionField, RspInfoField, requestId, final):
        """请求查询投资者持仓响应"""
        pass

    def onRspQryTradingAccount(self, TradingAccountField, RspInfoField, requestId, final):
        """请求查询资金账户响应"""
        pass

    def onRspQryInvestor(self, InvestorField, RspInfoField, requestId, final):
        """请求查询投资者响应"""
        pass

    def onRspQryTradingCode(self, TradingCodeField, RspInfoField, requestId, final):
        """请求查询交易编码响应"""
        pass

    def onRspQryInstrumentMarginRate(self, InstrumentMarginRateField, RspInfoField, requestId, final):
        """请求查询合约保证金率响应"""
        pass

    def onRspQryInstrumentCommissionRate(self, InstrumentCommissionRateField, RspInfoField, requestId, final):
        """请求查询合约手续费率响应"""
        pass

    def onRspQryExchange(self, ExchangeField, RspInfoField, requestId, final):
        """请求查询交易所响应"""
        pass

    def onRspQryProduct(self, ProductField, RspInfoField, requestId, final):
        """请求查询产品响应"""
        pass

    def onRspQryInstrument(self, InstrumentField, RspInfoField, requestId, final):
        """请求查询合约响应"""
        pass

    def onRspQryDepthMarketData(self, DepthMarketDataField, RspInfoField, requestId, final):
        """请求查询行情响应"""
        pass

    def onRspQrySettlementInfo(self, SettlementInfoField, RspInfoField, requestId, final):
        """请求查询投资者结算结果响应"""
        pass

    def onRspQryTransferBank(self, TransferBankField, RspInfoField, requestId, final):
        """请求查询转帐银行响应"""
        pass

    def onRspQryInvestorPositionDetail(self, InvestorPositionDetailField, RspInfoField, requestId, final):
        """请求查询投资者持仓明细响应"""
        pass

    def onRspQryNotice(self, NoticeField, RspInfoField, requestId, final):
        """请求查询客户通知响应"""
        pass

    def onRspQrySettlementInfoConfirm(self, SettlementInfoConfirmField, RspInfoField, requestId, final):
        """请求查询结算信息确认响应"""
        pass

    def onRspQryInvestorPositionCombineDetail(self, InvestorPositionCombineDetailField, RspInfoField, requestId, final):
        """请求查询投资者持仓明细响应"""
        pass

    def onRspQryCFMMCTradingAccountKey(self, CFMMCTradingAccountKeyField, RspInfoField, requestId, final):
        """查询保证金监管系统经纪公司资金账户密钥响应"""
        pass

    def onRspQryEWarrantOffset(self, EWarrantOffsetField, RspInfoField, requestId, final):
        """请求查询仓单折抵信息响应"""
        pass

    def onRspQryInvestorProductGroupMargin(self, InvestorProductGroupMarginField, RspInfoField, requestId, final):
        """请求查询投资者品种/跨品种保证金响应"""
        pass

    def onRspQryExchangeMarginRate(self, ExchangeMarginRateField, RspInfoField, requestId, final):
        """请求查询交易所保证金率响应"""
        pass

    def onRspQryExchangeMarginRateAdjust(self, ExchangeMarginRateAdjustField, RspInfoField, requestId, final):
        """请求查询交易所调整保证金率响应"""
        pass

    def onRspQryExchangeRate(self, ExchangeRateField, RspInfoField, requestId, final):
        """请求查询汇率响应"""
        pass

    def onRspQrySecAgentACIDMap(self, SecAgentACIDMapField, RspInfoField, requestId, final):
        """请求查询二级代理操作员银期权限响应"""
        pass

    def onRspQryProductExchRate(self, ProductExchRateField, RspInfoField, requestId, final):
        """请求查询产品报价汇率"""
        pass

    def onRspQryProductGroup(self, ProductGroupField, RspInfoField, requestId, final):
        """请求查询产品组"""
        pass

    def onRspQryMMInstrumentCommissionRate(self, MMInstrumentCommissionRateField, RspInfoField, requestId, final):
        """请求查询做市商合约手续费率响应"""
        pass

    def onRspQryMMOptionInstrCommRate(self, MMOptionInstrCommRateField, RspInfoField, requestId, final):
        """请求查询做市商期权合约手续费响应"""
        pass

    def onRspQryInstrumentOrderCommRate(self, InstrumentOrderCommRateField, RspInfoField, requestId, final):
        """请求查询报单手续费响应"""
        pass

    def onRspQryOptionInstrTradeCost(self, OptionInstrTradeCostField, RspInfoField, requestId, final):
        """请求查询期权交易成本响应"""
        pass

    def onRspQryOptionInstrCommRate(self, OptionInstrCommRateField, RspInfoField, requestId, final):
        """请求查询期权合约手续费响应"""
        pass

    def onRspQryExecOrder(self, ExecOrderField, RspInfoField, requestId, final):
        """请求查询执行宣告响应"""
        pass

    def onRspQryForQuote(self, ForQuoteField, RspInfoField, requestId, final):
        """请求查询询价响应"""
        pass

    def onRspQryQuote(self, QuoteField, RspInfoField, requestId, final):
        """请求查询报价响应"""
        pass

    def onRspQryCombInstrumentGuard(self, CombInstrumentGuardField, RspInfoField, requestId, final):
        """请求查询组合合约安全系数响应"""
        pass

    def onRspQryCombAction(self, CombActionField, RspInfoField, requestId, final):
        """请求查询申请组合响应"""
        pass

    def onRspQryTransferSerial(self, TransferSerialField, RspInfoField, requestId, final):
        """请求查询转帐流水响应"""
        pass

    def onRspQryAccountregister(self, AccountregisterField, RspInfoField, requestId, final):
        """请求查询银期签约关系响应"""
        pass

    def onRspError(self, RspInfoField, requestId, final):
        """错误应答"""
        print("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$")
        # pass

    def onRtnOrder(self, OrderField):
        """报单通知"""
        pass

    def onRtnTrade(self, TradeField):
        """成交通知"""
        pass

    def onErrRtnOrderInsert(self, InputOrderField, RspInfoField):
        """报单录入错误回报"""
        pass

    def onErrRtnOrderAction(self, OrderActionField, RspInfoField):
        """报单操作错误回报"""
        pass

    def onRtnInstrumentStatus(self, InstrumentStatusField):
        """合约交易状态通知"""
        pass

    def onRtnBulletin(self, BulletinField):
        """交易所公告通知"""
        pass

    def onRtnTradingNotice(self, TradingNoticeInfoField):
        """交易通知"""
        pass

    def onRtnErrorConditionalOrder(self, ErrorConditionalOrderField):
        """提示条件单校验错误"""
        pass

    def onRtnExecOrder(self, ExecOrderField):
        """执行宣告通知"""
        pass

    def onErrRtnExecOrderInsert(self, InputExecOrderField, RspInfoField):
        """执行宣告录入错误回报"""
        pass

    def onErrRtnExecOrderAction(self, ExecOrderActionField, RspInfoField):
        """执行宣告操作错误回报"""
        pass

    def onErrRtnForQuoteInsert(self, InputForQuoteField, RspInfoField):
        """询价录入错误回报"""
        pass

    def onRtnQuote(self, QuoteField):
        """报价通知"""
        pass

    def onErrRtnQuoteInsert(self, InputQuoteField, RspInfoField):
        """报价录入错误回报"""
        pass

    def onErrRtnQuoteAction(self, QuoteActionField, RspInfoField):
        """报价操作错误回报"""
        pass

    def onRtnForQuoteRsp(self, ForQuoteRspField):
        """询价通知"""
        pass

    def onRtnCFMMCTradingAccountToken(self, CFMMCTradingAccountTokenField):
        """保证金监控中心用户令牌"""
        pass

    def onErrRtnBatchOrderAction(self, BatchOrderActionField, RspInfoField):
        """批量报单操作错误回报"""
        pass

    def onRtnCombAction(self, CombActionField):
        """申请组合通知"""
        pass

    def onErrRtnCombActionInsert(self, InputCombActionField, RspInfoField):
        """申请组合录入错误回报"""
        pass

    def onRspQryContractBank(self, ContractBankField, RspInfoField, requestId, final):
        """请求查询签约银行响应"""
        pass

    def onRspQryParkedOrder(self, ParkedOrderField, RspInfoField, requestId, final):
        """请求查询预埋单响应"""
        pass

    def onRspQryParkedOrderAction(self, ParkedOrderActionField, RspInfoField, requestId, final):
        """请求查询预埋撤单响应"""
        pass

    def onRspQryTradingNotice(self, TradingNoticeField, RspInfoField, requestId, final):
        """请求查询交易通知响应"""
        pass

    def onRspQryBrokerTradingParams(self, BrokerTradingParamsField, RspInfoField, requestId, final):
        """请求查询经纪公司交易参数响应"""
        pass

    def onRspQryBrokerTradingAlgos(self, BrokerTradingAlgosField, RspInfoField, requestId, final):
        """请求查询经纪公司交易算法响应"""
        pass

    def onRspQueryCFMMCTradingAccountToken(self, QueryCFMMCTradingAccountTokenField, RspInfoField, requestId, final):
        """请求查询监控中心用户令牌"""
        pass

    def onRtnFromBankToFutureByBank(self, RspTransferField):
        """银行发起银行资金转期货通知"""
        pass

    def onRtnFromFutureToBankByBank(self, RspTransferField):
        """银行发起期货资金转银行通知"""
        pass

    def onRtnRepealFromBankToFutureByBank(self, RspRepealField):
        """银行发起冲正银行转期货通知"""
        pass

    def onRtnRepealFromFutureToBankByBank(self, RspRepealField):
        """银行发起冲正期货转银行通知"""
        pass

    def onRtnFromBankToFutureByFuture(self, RspTransferField):
        """期货发起银行资金转期货通知"""
        pass

    def onRtnFromFutureToBankByFuture(self, RspTransferField):
        """期货发起期货资金转银行通知"""
        pass

    def onRtnRepealFromBankToFutureByFutureManual(self, RspRepealField):
        """系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知"""
        pass

    def onRtnRepealFromFutureToBankByFutureManual(self, RspRepealField):
        """系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知"""
        pass

    def onRtnQueryBankBalanceByFuture(self, NotifyQueryAccountField):
        """期货发起查询银行余额通知"""
        pass

    def onErrRtnBankToFutureByFuture(self, ReqTransferField, RspInfoField):
        """期货发起银行资金转期货错误回报"""
        pass

    def onErrRtnFutureToBankByFuture(self, ReqTransferField, RspInfoField):
        """期货发起期货资金转银行错误回报"""
        pass

    def onErrRtnRepealBankToFutureByFutureManual(self, ReqRepealField, RspInfoField):
        """系统运行时期货端手工发起冲正银行转期货错误回报"""
        pass

    def onErrRtnRepealFutureToBankByFutureManual(self, ReqRepealField, RspInfoField):
        """系统运行时期货端手工发起冲正期货转银行错误回报"""
        pass

    def onErrRtnQueryBankBalanceByFuture(self, ReqQueryAccountField, RspInfoField):
        """期货发起查询银行余额错误回报"""
        pass

    def onRtnRepealFromBankToFutureByFuture(self, RspRepealField):
        """期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知"""
        pass

    def onRtnRepealFromFutureToBankByFuture(self, RspRepealField):
        """期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知"""
        pass

    def onRspFromBankToFutureByFuture(self, ReqTransferField, RspInfoField, requestId, final):
        """期货发起银行资金转期货应答"""
        pass

    def onRspFromFutureToBankByFuture(self, ReqTransferField, RspInfoField, requestId, final):
        """期货发起期货资金转银行应答"""
        pass

    def onRspQueryBankAccountMoneyByFuture(self, ReqQueryAccountField, RspInfoField, requestId, final):
        """期货发起查询银行余额应答"""
        pass

    def onRtnOpenAccountByBank(self, OpenAccountField):
        """银行发起银期开户通知"""
        pass

    def onRtnCancelAccountByBank(self, CancelAccountField):
        """银行发起银期销户通知"""
        pass

    def onRtnChangeAccountByBank(self, ChangeAccountField):
        """银行发起变更银行账号通知"""
        pass


ctpTd = CtpTd("tdconn/")
print(ctpTd.getApiVersion())
ctpTd.registerSpi()
ctpTd.init()

address = "tcp://218.202.237.33:10002";
# address = "tcp://180.168.146.187:10030"
ctpTd.registerFront(address)
print("33333333333333333333333333333")

# while True:
#     time.sleep(5)

time.sleep(60)
userLogoutField = td.UserLogoutField()
userLogoutField.userID = "090285"
userLogoutField.brokerID = "9999"
ctpTd.reqUserLogout(userLogoutField, 1)
time.sleep(20)

print("################SSSSSSSSSSSSSS")
# ctpTd.release()
print("###############aaaaaaaaa")
ctpTd.join()
