# -*- coding: utf-8 -*-
import time,os
import platform
from utils import logger_factory

logger = logger_factory.getLogger(__name__)

if platform.architecture()[1] == "ELF":
    from ctp.linux import ctptd as td
elif platform.architecture()[0] == "64bit":
    from ctp.win64 import ctptd as td
else:
    from ctp.win32 import ctptd as td

path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'tdconn/')
logger.debug(path)
if not os.path.exists(path):
    os.makedirs(path)

class CtpTd(td.CtpTd):
    def __init__(self, szFlowPath=path):
        super(CtpTd, self).__init__(szFlowPath)
        self._requestId = 0
        self._userID = ''
        self._password = ''
        self._brokerID = ''

        self._orderRef = 0
        self.frontID = None #前置编号
        self.sessionID = None #会话编号
        self._barEventListeners = set()
        self.__rspQryOrder_dic = {}  #委托单暂存
        self.__rspQryInvestorPositionDetaild_dic = {} #持仓明细暂存
    def onFrontConnected(self):
        """当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。"""
        reqLoginField = td.ReqUserLoginField()
        reqLoginField.userID = self._userID
        reqLoginField.password = self._password
        reqLoginField.brokerID = self._brokerID
        self._requestId += 1
        self.reqUserLogin(reqLoginField, self._requestId)

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
        logger.debug("sessionID:{}".format(RspUserLoginField.sessionID))
        if RspInfoField.errorID == 0:
            self.frontID = RspUserLoginField.frontID
            self.sessionID = RspUserLoginField.sessionID
            logger.debug("orderRef: {}".format(RspUserLoginField.maxOrderRef))
            self._orderRef = (int)(RspUserLoginField.maxOrderRef)
            log = u'交易服务器登陆成功'
            settlementInfoConfirmField = td.SettlementInfoConfirmField()
            settlementInfoConfirmField.brokerID = self._brokerID
            settlementInfoConfirmField.investorID = self._userID
            self._requestId += 1
            self.reqSettlementInfoConfirm(settlementInfoConfirmField, self._requestId)
            for listener in self._barEventListeners:
                listener.onRspUserLogin(RspUserLoginField)
        else:
            log = u'交易服务登陆失败，错误码:{0}, 错误信息：{1}'.format(
                RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk'))
        logger.debug(log)

    def onRspUserLogout(self, UserLogoutField, RspInfoField, requestId, final):
        """登出请求响应"""
        if RspInfoField.errorID == 0:
            log = u'交易服务器登出成功'
        else:
            log = u'交易服务登出失败，错误码:[{0}], 错误信息:[{1}]'.format(
                RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk'))
        logger.debug(log)

    def onRspUserPasswordUpdate(self, UserPasswordUpdateField, RspInfoField, requestId, final):
        """用户口令更新请求响应"""
        pass

    def onRspTradingAccountPasswordUpdate(self, TradingAccountPasswordUpdateField, RspInfoField, requestId, final):
        """资金账户口令更新请求响应"""
        pass

    def onRspOrderInsert(self, InputOrderField, RspInfoField, requestId, final):
        """报单录入请求响应"""
        # print(u"onRspOrderInsert --- brokerID:{0}, orderRef:{1}, price:{2}, volume:{3}, orderPriceType:{4},"
        #       u"direction: {5}, combOffsetFlag: {6}, combHedgeFlag:{7}, contingentCondition: {8}, forceCloseReason: {9},"
        #       u"isAutoSuspend: {10}, timeCondition: {11}, volumeCondition:{12}, minVolume: {13}, instrumentID: {14}"
        #     .format(InputOrderField.brokerID, InputOrderField.orderRef, InputOrderField.limitPrice,
        #     InputOrderField.volumeTotalOriginal, InputOrderField.orderPriceType, InputOrderField.direction,
        #             InputOrderField.combOffsetFlag, InputOrderField.combHedgeFlag, InputOrderField.contingentCondition,
        #             InputOrderField.forceCloseReason, InputOrderField.isAutoSuspend, InputOrderField.timeCondition,
        #             InputOrderField.volumeCondition, InputOrderField.minVolume, InputOrderField.instrumentID))
        # print(u"onRspOrderInsert --- errorCode:{0}, errorMsg:{1}.".format(
        #     RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk')))
        for listener in self._barEventListeners:
            listener.onRspOrderInsert(InputOrderField,RspInfoField)

    def onRspParkedOrderInsert(self, ParkedOrderField, RspInfoField, requestId, final):
        """预埋单录入请求响应"""
        pass

    def onRspParkedOrderAction(self, ParkedOrderActionField, RspInfoField, requestId, final):
        """预埋撤单录入请求响应"""
        pass

    def onRspOrderAction(self, InputOrderActionField, RspInfoField, requestId, final):
        """报单操作请求响应"""
        # print u"onRspOrderAction --- sessionId: {0}, frontID: {1}, orderRef: {2}".format(InputOrderActionField.sessionID,
        #         InputOrderActionField.frontID, InputOrderActionField.orderRef)
        # print(u"onRspOrderAction --- errorCode:{0}, errorMsg:{1}.".format(
        #     RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk')))
        for listener in self._barEventListeners:
            listener.onRspOrderInsert(InputOrderActionField, RspInfoField)
    def onRspQueryMaxOrderVolume(self, QueryMaxOrderVolumeField, RspInfoField, requestId, final):
        """查询最大报单数量响应"""
        pass

    def onRspSettlementInfoConfirm(self, SettlementInfoConfirmField, RspInfoField, requestId, final):
        """投资者结算结果确认响应"""
        logger.debug(u"onRspSettlementInfoConfirm --- brokerID:{0}, investorID:{1}，confirmDate:{2}，confirmTime:{3}.".format(
            SettlementInfoConfirmField.brokerID, SettlementInfoConfirmField.investorID,
            SettlementInfoConfirmField.confirmDate, SettlementInfoConfirmField.confirmTime))
        logger.debug(u"onRspSettlementInfoConfirm --- errorCode:{0}，errorMsg:{1}.".format(
            RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk')))

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
        if OrderField: #这个字段也可能为空
            logger.debug(u"onRspQryOrder --- brokerID:{0}, orderRef:{1}, limitPrice:{2}, volume:{3}, orderPriceType:{4},"
                  u"direction: {5}, combOffsetFlag: {6}, combHedgeFlag:{7}, contingentCondition: {8}, forceCloseReason: {9},"
                  u"isAutoSuspend: {10}, timeCondition: {11}, volumeCondition:{12}, minVolume: {13}, instrumentID: {14}"
                .format(OrderField.brokerID, OrderField.orderRef, OrderField.limitPrice, OrderField.volumeTotalOriginal,
                        OrderField.orderPriceType, OrderField.direction, OrderField.combOffsetFlag, OrderField.combHedgeFlag,
                        OrderField.contingentCondition, OrderField.forceCloseReason, OrderField.isAutoSuspend, OrderField.timeCondition,
                        OrderField.volumeCondition, OrderField.minVolume, OrderField.instrumentID))
            self.__rspQryOrder_dic[OrderField.orderRef] = OrderField
        if final:
             for listener in self._barEventListeners:
                listener.onRspQryOrder(self.__rspQryOrder_dic,requestId)
             self.__rspQryOrder_dic = {}
        if RspInfoField: #这个字段竟然能能返回为空
            logger.debug(u"onRspQryOrder --- errorCode: {0}, errorMsg:{1}.".format(
                RspInfoField.errorID, RspInfoField.errorMsg.decode("gbk")))

    def onRspQryTrade(self, TradeField, RspInfoField, requestId, final):
        """请求查询成交响应"""
        pass

    def onRspQryInvestorPosition(self, InvestorPositionField, RspInfoField, requestId, final):
        """请求查询投资者持仓响应"""
        logger.debug(u"onRspQryInvestorPosition -- instrumentID:{0}, brokerID:{1}, investorID:{2}, posiDirection:{3},"
              u"positionDate: {4}, position: {5}".format(InvestorPositionField.instrumentID, InvestorPositionField.brokerID,
             InvestorPositionField.investorID, InvestorPositionField.posiDirection, InvestorPositionField.positionDate,
             InvestorPositionField.position))
        if RspInfoField: #这个字段竟然能能返回为空
            logger.debug(u"onRspQryInvestorPosition -- errorCode: {0}, errorMsg:{1}.".format(
                RspInfoField.errorID, RspInfoField.errorMsg.decode("gbk")))

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
        log = u'交易服务响应错误，错误码:[{0}], 错误信息:[{1}]'.format(
            RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk'))
        logger.debug(log)


    def onRtnTrade(self, TradeField):
        # """成交通知"""
        # print u"成交通知，limitPrice:{0}, orderRef: {1}, sessionID: {2}, frontID: {3}" \
        #     .format(TradeField.limitPrice, TradeField.orderRef, TradeField.sessionID, TradeField.frontID)
        for listener in self._barEventListeners:
            listener.onRtnTradeEvent(TradeField)
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

    def login(self, szFrontAddress, userID, password, brokerID):
        self.__address = szFrontAddress
        self._userID = userID
        self._password = password
        self._brokerID = brokerID
        self.registerSpi()
        # 数据重传模式设为从本日开始
        # tert.restart, tert.resume, tert.quick
        self.subscribePrivateTopic(td.tert.resume)
        self.subscribePublicTopic(td.tert.resume)

        self.init()
        self.registerFront(szFrontAddress)

    def logout(self):
        userLogoutField = td.UserLogoutField()
        userLogoutField.userID = self._userID
        userLogoutField.brokerID = self._brokerID
        self._requestId += 1
        ctpTd.reqUserLogout(userLogoutField, self._requestId)

    # ----------------------------------------------------------------------
    def qryPosition(self):
        """查询持仓"""
        qryInvestorPositionField = td.QryInvestorPositionField()
        qryInvestorPositionField.brokerID = self._brokerID
        qryInvestorPositionField.investorID = self._userID
        # qryInvestorPositionField.instrumentID = ""
        self._requestId += 1
        self.reqQryInvestorPosition(qryInvestorPositionField, self._requestId)
        return self._requestId

    def onRspQryInvestorPositionDetail(self, InvestorPositionDetailField, RspInfoField, requestId, final):
        """请求查询投资者持仓明细响应"""
        # print(u"onRspQryInvestorPositionDetail -- instrumentID:{0}, brokerID:{1}, investorID:{2}, Direction:{3},"
        #       u"tradingDay: {4}, tradeID: {5},openPrice:{6},volume:{7}".format(InvestorPositionDetailField.instrumentID, InvestorPositionDetailField.brokerID,
        #                                                  InvestorPositionDetailField.investorID, InvestorPositionDetailField.direction,
        #                                                  InvestorPositionDetailField.tradingDay, InvestorPositionDetailField.positionProfitByTrade,
        #                                                  InvestorPositionDetailField.openPrice,InvestorPositionDetailField.volume))

        self.__rspQryInvestorPositionDetaild_dic[InvestorPositionDetailField.tradeID] = InvestorPositionDetailField
        if final:
            for listener in self._barEventListeners:
                listener.onRspQryInvestorPositionDetail(self.__rspQryInvestorPositionDetaild_dic,requestId)
            self.__rspQryInvestorPositionDetaild_dic = {}
        if RspInfoField: #这个字段竟然能能返回为空
            logger.debug(u"onRspQryInvestorPositionDetail -- errorCode: {0}, errorMsg:{1}.".format(
                RspInfoField.errorID, RspInfoField.errorMsg.decode("gbk")))


    # ----------------------------------------------------------------------
    def qryPositionDetail(self):
        """查询持仓详情"""
        qryInvestorPositionDetailField = td.QryInvestorPositionDetailField()
        qryInvestorPositionDetailField.brokerID = self._brokerID
        qryInvestorPositionDetailField.investorID = self._userID
        # qryInvestorPositionDetailField.instrumentID = ""
        self._requestId += 1
        self.reqQryInvestorPositionDetail(qryInvestorPositionDetailField, self._requestId)
        return self._requestId

    def reqQryOrder(self):
        """查询委托"""
        qryOrderField = td.QryOrderField()
        qryOrderField.brokerID = self._brokerID
        qryOrderField.investorID = self._userID
        # qryOrderField.instrumentID = ""
        self._requestId += 1
        super(CtpTd, self).reqQryOrder(qryOrderField, self._requestId)
        return self._requestId

    # ----------------------------------------------------------------------
    def sendOrder(self, instrumentID, direction, orderPriceType, offsetFlag, price, volume):
        """发单
        :param symbol: 合约号
        :param direction: 买卖方向
            - 买 THOST_FTDC_D_Buy '0'
            - 卖 THOST_FTDC_D_Sell '1'
        :param orderPriceType: 报单价格条件   #只支持限价，部分支持市价
            - 任意价 THOST_FTDC_OPT_AnyPrice '1'
            - 限价 THOST_FTDC_OPT_LimitPrice '2'
            - 最优价 THOST_FTDC_OPT_BestPrice '3'
            - 最新价 THOST_FTDC_OPT_LastPrice '4'
            - 最新价浮动上浮1个ticks THOST_FTDC_OPT_LastPricePlusOneTicks '5'
            - 最新价浮动上浮2个ticks THOST_FTDC_OPT_LastPricePlusTwoTicks '6'
            - 最新价浮动上浮3个ticks THOST_FTDC_OPT_LastPricePlusThreeTicks '7'
            - 卖一价 THOST_FTDC_OPT_AskPrice1 '8'
            - 卖一价浮动上浮1个ticks THOST_FTDC_OPT_AskPrice1PlusOneTicks '9'
            - 卖一价浮动上浮2个ticks THOST_FTDC_OPT_AskPrice1PlusTwoTicks 'A'
            - 卖一价浮动上浮3个ticks THOST_FTDC_OPT_AskPrice1PlusThreeTicks 'B'
            - 买一价 THOST_FTDC_OPT_BidPrice1 'C'
            - 买一价浮动上浮1个ticks THOST_FTDC_OPT_BidPrice1PlusOneTicks 'D'
            - 买一价浮动上浮2个ticks THOST_FTDC_OPT_BidPrice1PlusTwoTicks 'E'
            - 买一价浮动上浮3个ticks THOST_FTDC_OPT_BidPrice1PlusThreeTicks 'F'
            - 五档价 THOST_FTDC_OPT_FiveLevelPrice 'G'
        :param offsetFlag: 组合开平标志
            - 开仓 THOST_FTDC_OF_Open '0'
            - 平仓 THOST_FTDC_OF_Close '1'
            - 强平 THOST_FTDC_OF_ForceClose '2'
            - 平今 THOST_FTDC_OF_CloseToday '3'
            - 平昨 THOST_FTDC_OF_CloseYesterday '4'
            - 强减 THOST_FTDC_OF_ForceOff '5'
            - 本地强平 THOST_FTDC_OF_LocalForceClose '6'
        :param price: 价格
        :param volume: 数量

        :enum combHedgeFlag: 组合投机套保标志
            - 投机: THOST_FTDC_HF_Speculation '1'
            - 套利：THOST_FTDC_HF_Arbitrage '2'
            - 套保：THOST_FTDC_HF_Hedge '3'
            - 做市商：THOST_FTDC_HF_MarketMaker '5'

        :enum contingentCondition: 触发条件
            - 立即 THOST_FTDC_CC_Immediately '1'
            - 止损 THOST_FTDC_CC_Touch '2'
            - 止赢 THOST_FTDC_CC_TouchProfit '3'
            - 预埋单 THOST_FTDC_CC_ParkedOrder '4'
            - 最新价大于条件价 THOST_FTDC_CC_LastPriceGreaterThanStopPrice '5'
            - 最新价大于等于条件价 THOST_FTDC_CC_LastPriceGreaterEqualStopPrice '6'
            - 最新价小于条件价 THOST_FTDC_CC_LastPriceLesserThanStopPrice '7'
            - 最新价小于等于条件价 THOST_FTDC_CC_LastPriceLesserEqualStopPrice '8'
            - 卖一价大于条件价 THOST_FTDC_CC_AskPriceGreaterThanStopPrice '9'
            - 卖一价大于等于条件价 THOST_FTDC_CC_AskPriceGreaterEqualStopPrice 'A'
            - 卖一价小于条件价 THOST_FTDC_CC_AskPriceLesserThanStopPrice 'B'
            - 卖一价小于等于条件价 THOST_FTDC_CC_AskPriceLesserEqualStopPrice 'C'
            - 买一价大于条件价 THOST_FTDC_CC_BidPriceGreaterThanStopPrice 'D'
            - 买一价大于等于条件价 THOST_FTDC_CC_BidPriceGreaterEqualStopPrice 'E'
            - 买一价小于条件价 THOST_FTDC_CC_BidPriceLesserThanStopPrice 'F'
            - 买一价小于等于条件价 THOST_FTDC_CC_BidPriceLesserEqualStopPrice 'H'
        :enum forceCloseReason: 强平原因
            - 非强平 THOST_FTDC_FCC_NotForceClose '0'
            - 资金不足 THOST_FTDC_FCC_LackDeposit '1'
            - 客户超仓 THOST_FTDC_FCC_ClientOverPositionLimit '2'
            - 会员超仓 THOST_FTDC_FCC_MemberOverPositionLimit '3'
            - 持仓非整数倍 THOST_FTDC_FCC_NotMultiple '4'
            - 违规 THOST_FTDC_FCC_Violation '5'
            - 其它 THOST_FTDC_FCC_Other '6'
            - 自然人临近交割 THOST_FTDC_FCC_PersonDeliv '7'
        :enum timeCondition: 有效期类型
            - 立即完成，否则撤销 THOST_FTDC_TC_IOC '1'
            - 本节有效 THOST_FTDC_TC_GFS '2'
            - 当日有效 THOST_FTDC_TC_GFD '3'
            - 指定日期前有效 THOST_FTDC_TC_GTD '4'
            - 撤销前有效 THOST_FTDC_TC_GTC '5'
            - 集合竞价有效 THOST_FTDC_TC_GFA '6'
        :enum volumeCondition: 成交量类型
            - 任何数量 THOST_FTDC_VC_AV '1'
            - 最小数量 THOST_FTDC_VC_MV '2'
            - 全部数量 THOST_FTDC_VC_CV '3'
        """
        self._orderRef += 1

        inputOrderField = td.InputOrderField()
        inputOrderField.brokerID = self._brokerID
        inputOrderField.investorID = self._userID
        inputOrderField.userID = self._userID
        inputOrderField.orderRef = str(self._orderRef)

        inputOrderField.instrumentID = instrumentID
        inputOrderField.limitPrice = price
        inputOrderField.volumeTotalOriginal = volume

        inputOrderField.orderPriceType = orderPriceType
        inputOrderField.direction = direction
        inputOrderField.combOffsetFlag = offsetFlag

        inputOrderField.combHedgeFlag = '1'  # 投机单
        inputOrderField.contingentCondition = '1' # 立即发单
        inputOrderField.forceCloseReason = '0'  # 非强平
        inputOrderField.isAutoSuspend = 0  # 非自动挂起
        inputOrderField.timeCondition = '3'  # 今日有效
        inputOrderField.volumeCondition = '1'  # 任意成交量
        inputOrderField.minVolume = 1  # 最小成交量为1
        # inputOrderField.GTDDate = ""
        # inputOrderField.stopPrice = 0

        self._requestId += 1
        self.reqOrderInsert(inputOrderField, self._requestId)

        return str(self._orderRef)

    # ----------------------------------------------------------------------
    def cancelOrder(self, instrumentID, orderID, frontID, sessionID):
        """撤单
        :param instrumentID: 合约号
        :param orderID: 订单号
        :param frontID: 前置机号
        :param sessionID: 会话ID

        :enum actionFlag: 操作标志
            - 删除 THOST_FTDC_AF_Delete '0'
            - 修改 THOST_FTDC_AF_Modify '3'
        """

        # 使用 frontID, sessionID, orderID三元组
        inputOrderActionField = td.InputOrderActionField()
        inputOrderActionField.brokerID = self._brokerID
        inputOrderActionField.investorID = self._userID
        inputOrderActionField.actionFlag = '0'
        inputOrderActionField.instrumentID = instrumentID
        inputOrderActionField.orderRef = orderID
        inputOrderActionField.frontID = frontID
        inputOrderActionField.sessionID = sessionID
        self._requestId += 1
        self.reqOrderAction(inputOrderActionField, self._requestId)

    def onRtnOrder(self, OrderField):
        """报单通知"""
        # #如果委托成功，OrderSubmitStatus先是0（不用管），则OrderSubmitStatus = 3，且orderStatus = 3，等待排队.
        #               紧接着成交则OrderSubmitStatus = 3，且orderStatus = 0-1
        ## 如果撤单成功，OrderSubmitStatus先是1（不用管），则OrderSubmitStatus = 3，且orderStatus = *.等待撤单
        #               紧接着成交则OrderSubmitStatus = 3，且orderStatus = 5 ？？
        for listener in self._barEventListeners:
            listener.onRtnOrderEvent(OrderField)

        # print u"报单通知，limitPrice:{0}, orderRef: {1}, sessionID: {2}, frontID: {3}, notifySequence: {4}, " \
        #       u"orderStatus: {5}, orderSubmitStatus: {6}".format(OrderField.limitPrice, OrderField.orderRef,
        #     OrderField.sessionID, OrderField.frontID, OrderField.notifySequence, OrderField.orderStatus,
        #     OrderField.orderSubmitStatus)
    def onRspOrderAction(self, InputOrderActionField, RspInfoField, requestId, final):
        """报单操作请求响应"""
        logger.debug(u"onRspOrderAction --- sessionId: {0}, frontID: {1}, orderRef: {2}".format(InputOrderActionField.sessionID,
                InputOrderActionField.frontID, InputOrderActionField.orderRef))
        logger.debug(u"onRspOrderAction --- errorCode:{0}, errorMsg:{1}.".format(
            RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk')))
        for listener in self._barEventListeners:
            listener.onRspOrderAction( InputOrderActionField, RspInfoField)

    def addBarEventListener(self, BarEventListener):
        if BarEventListener and BarEventListener not in self._barEventListeners:
            self._barEventListeners.add(BarEventListener)

    def removeBarEventListener(self, BarEventListener):
        if BarEventListener and BarEventListener in self._barEventListeners:
            self._barEventListeners.remove(BarEventListener)

if __name__ == "__main__":
    """
    :enum orderSubmitStatus: 报单提交状态
        - 已经提交 THOST_FTDC_OSS_InsertSubmitted '0'
        - 撤单已经提交 THOST_FTDC_OSS_CancelSubmitted '1'
        - 修改已经提交 THOST_FTDC_OSS_ModifySubmitted '2'
        - 已经接受 THOST_FTDC_OSS_Accepted '3'
        - 报单已经被拒绝 THOST_FTDC_OSS_InsertRejected '4'
        - 撤单已经被拒绝 THOST_FTDC_OSS_CancelRejected '5'
        - 改单已经被拒绝 THOST_FTDC_OSS_ModifyRejected '6'
        
    :enum orderStatus: 报单状态
        - 全部成交 THOST_FTDC_OST_AllTraded '0'
        - 部分成交还在队列中 THOST_FTDC_OST_PartTradedQueueing '1'
        - 部分成交不在队列中 THOST_FTDC_OST_PartTradedNotQueueing '2'
        - 未成交还在队列中 THOST_FTDC_OST_NoTradeQueueing '3'
        - 未成交不在队列中 THOST_FTDC_OST_NoTradeNotQueueing '4'
        - 撤单 THOST_FTDC_OST_Canceled '5'
        - 未知 THOST_FTDC_OST_Unknown 'a'
        - 尚未触发 THOST_FTDC_OST_NotTouched 'b'
        - 已触发 THOST_FTDC_OST_Touched 'c'
    """
    ctpTd = CtpTd("tdconn/")
    print(ctpTd.getApiVersion())

    #address = "tcp://180.168.146.187:10000"
    address = "tcp://218.202.237.33:10002"
    # address = "tcp://180.168.146.187:10030"
    ctpTd.login(address, "090285", "ABCabc", "9999")

    #time.sleep(10)
    # ctpTd.logout()
    orderRef = ctpTd.sendOrder("cu1707", "0", "2", "0", 2000, 1)
    time.sleep(5)
    # ctpTd.qryPositionDetail()
    ctpTd.reqQryOrder()
    # ctpTd.cancelOrder("cu1707", '3', 1, -878161081)
    # for i in range(100):
    #     print 'test'
    #     time.sleep(0.5)
    #ctpTd.cancelOrder("cu1707", orderRef, ctpTd.frontID, ctpTd.sessionID)
    # ctpTd.release()
    ctpTd.join()
