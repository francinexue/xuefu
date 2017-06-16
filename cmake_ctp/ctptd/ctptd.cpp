//
// Created by kyle on 17-5-18.
//
#include "ctptd.h"

CtpTd::CtpTd(const std::string &szFlowPath) {
    this->api = CThostFtdcTraderApi::CreateFtdcTraderApi(szFlowPath.c_str());
    boost::function0<void> f = boost::bind(&CtpTd::processTask, this);
    this->task_thread = new boost::thread(f);
}

CtpTd::~CtpTd() {
    task_thread->interrupt();
    task_thread->join();
    delete task_thread;
    this->api->Release();
}

void CtpTd::OnFrontConnected() {
    Task *task = new Task();
    task->name = ON_FRONT_CONNECTED;
    this->task_queue.push(task);
}

void CtpTd::OnFrontDisconnected(int nReason) {
    Task *task = new Task();
    task->name = ON_FRONT_DISCONNECTED;
    task->num = nReason;
    this->task_queue.push(task);
}

void CtpTd::OnHeartBeatWarning(int nTimeLapse) {
    Task *task = new Task();
    task->name = ON_HEART_BEAT_WARNING;
    task->num = nTimeLapse;
    this->task_queue.push(task);
}

void CtpTd::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_AUTHENTICATE;
    if (pRspAuthenticateField)
        task->payload = RspAuthenticateField(*pRspAuthenticateField);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_USER_LOGIN;
    if (pRspUserLogin)
        task->payload = RspUserLoginField(*pRspUserLogin);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_USER_LOGOUT;
    if (pUserLogout)
        task->payload = UserLogoutField(*pUserLogout);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_USER_PASSWORD_UPDATE;
    if (pUserPasswordUpdate)
        task->payload = UserPasswordUpdateField(*pUserPasswordUpdate);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_TRADING_ACCOUNT_PASSWORD_UPDATE;
    if (pTradingAccountPasswordUpdate)
        task->payload = TradingAccountPasswordUpdateField(*pTradingAccountPasswordUpdate);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_ORDER_INSERT;
    if (pInputOrder)
        task->payload = InputOrderField(*pInputOrder);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_PARKED_ORDER_INSERT;
    if (pParkedOrder)
        task->payload = ParkedOrderField(*pParkedOrder);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_PARKED_ORDER_ACTION;
    if (pParkedOrderAction)
        task->payload = ParkedOrderActionField(*pParkedOrderAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_ORDER_ACTION;
    if (pInputOrderAction)
        task->payload = InputOrderActionField(*pInputOrderAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QUERY_MAX_ORDER_VOLUME;
    if (pQueryMaxOrderVolume)
        task->payload = QueryMaxOrderVolumeField(*pQueryMaxOrderVolume);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_SETTLEMENT_INFO_CONFIRM;
    if (pSettlementInfoConfirm)
        task->payload = SettlementInfoConfirmField(*pSettlementInfoConfirm);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_REMOVE_PARKED_ORDER;
    if (pRemoveParkedOrder)
        task->payload = RemoveParkedOrderField(*pRemoveParkedOrder);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_REMOVE_PARKED_ORDER_ACTION;
    if (pRemoveParkedOrderAction)
        task->payload = RemoveParkedOrderActionField(*pRemoveParkedOrderAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_EXEC_ORDER_INSERT;
    if (pInputExecOrder)
        task->payload = InputExecOrderField(*pInputExecOrder);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_EXEC_ORDER_ACTION;
    if (pInputExecOrderAction)
        task->payload = InputExecOrderActionField(*pInputExecOrderAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_FOR_QUOTE_INSERT;
    if (pInputForQuote)
        task->payload = InputForQuoteField(*pInputForQuote);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QUOTE_INSERT;
    if (pInputQuote)
        task->payload = InputQuoteField(*pInputQuote);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QUOTE_ACTION;
    if (pInputQuoteAction)
        task->payload = InputQuoteActionField(*pInputQuoteAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_BATCH_ORDER_ACTION;
    if (pInputBatchOrderAction)
        task->payload = InputBatchOrderActionField(*pInputBatchOrderAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_COMB_ACTION_INSERT;
    if (pInputCombAction)
        task->payload = InputCombActionField(*pInputCombAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_ORDER;
    if (pOrder)
        task->payload = OrderField(*pOrder);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_TRADE;
    if (pTrade)
        task->payload = TradeField(*pTrade);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_INVESTOR_POSITION;
    if (pInvestorPosition)
        task->payload = InvestorPositionField(*pInvestorPosition);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_TRADING_ACCOUNT;
    if (pTradingAccount)
        task->payload = TradingAccountField(*pTradingAccount);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_INVESTOR;
    if (pInvestor)
        task->payload = InvestorField(*pInvestor);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_TRADING_CODE;
    if (pTradingCode)
        task->payload = TradingCodeField(*pTradingCode);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_INSTRUMENT_MARGIN_RATE;
    if (pInstrumentMarginRate)
        task->payload = InstrumentMarginRateField(*pInstrumentMarginRate);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_INSTRUMENT_COMMISSION_RATE;
    if (pInstrumentCommissionRate)
        task->payload = InstrumentCommissionRateField(*pInstrumentCommissionRate);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_EXCHANGE;
    if (pExchange)
        task->payload = ExchangeField(*pExchange);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_PRODUCT;
    if (pProduct)
        task->payload = ProductField(*pProduct);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_INSTRUMENT;
    if (pInstrument)
        task->payload = InstrumentField(*pInstrument);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_DEPTH_MARKET_DATA;
    if (pDepthMarketData)
        task->payload = DepthMarketDataField(*pDepthMarketData);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_SETTLEMENT_INFO;
    if (pSettlementInfo)
        task->payload = SettlementInfoField(*pSettlementInfo);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_TRANSFER_BANK;
    if (pTransferBank)
        task->payload = TransferBankField(*pTransferBank);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_INVESTOR_POSITION_DETAIL;
    if (pInvestorPositionDetail)
        task->payload = InvestorPositionDetailField(*pInvestorPositionDetail);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_NOTICE;
    if (pNotice)
        task->payload = NoticeField(*pNotice);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM;
    if (pSettlementInfoConfirm)
        task->payload = SettlementInfoConfirmField(*pSettlementInfoConfirm);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_INVESTOR_POSITION_COMBINE_DETAIL;
    if (pInvestorPositionCombineDetail)
        task->payload = InvestorPositionCombineDetailField(*pInvestorPositionCombineDetail);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_C_F_M_M_C_TRADING_ACCOUNT_KEY;
    if (pCFMMCTradingAccountKey)
        task->payload = CFMMCTradingAccountKeyField(*pCFMMCTradingAccountKey);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_E_WARRANT_OFFSET;
    if (pEWarrantOffset)
        task->payload = EWarrantOffsetField(*pEWarrantOffset);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_INVESTOR_PRODUCT_GROUP_MARGIN;
    if (pInvestorProductGroupMargin)
        task->payload = InvestorProductGroupMarginField(*pInvestorProductGroupMargin);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_EXCHANGE_MARGIN_RATE;
    if (pExchangeMarginRate)
        task->payload = ExchangeMarginRateField(*pExchangeMarginRate);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_EXCHANGE_MARGIN_RATE_ADJUST;
    if (pExchangeMarginRateAdjust)
        task->payload = ExchangeMarginRateAdjustField(*pExchangeMarginRateAdjust);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_EXCHANGE_RATE;
    if (pExchangeRate)
        task->payload = ExchangeRateField(*pExchangeRate);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_SEC_AGENT_A_C_I_D_MAP;
    if (pSecAgentACIDMap)
        task->payload = SecAgentACIDMapField(*pSecAgentACIDMap);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_PRODUCT_EXCH_RATE;
    if (pProductExchRate)
        task->payload = ProductExchRateField(*pProductExchRate);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_PRODUCT_GROUP;
    if (pProductGroup)
        task->payload = ProductGroupField(*pProductGroup);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_M_M_INSTRUMENT_COMMISSION_RATE;
    if (pMMInstrumentCommissionRate)
        task->payload = MMInstrumentCommissionRateField(*pMMInstrumentCommissionRate);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_M_M_OPTION_INSTR_COMM_RATE;
    if (pMMOptionInstrCommRate)
        task->payload = MMOptionInstrCommRateField(*pMMOptionInstrCommRate);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_INSTRUMENT_ORDER_COMM_RATE;
    if (pInstrumentOrderCommRate)
        task->payload = InstrumentOrderCommRateField(*pInstrumentOrderCommRate);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_OPTION_INSTR_TRADE_COST;
    if (pOptionInstrTradeCost)
        task->payload = OptionInstrTradeCostField(*pOptionInstrTradeCost);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_OPTION_INSTR_COMM_RATE;
    if (pOptionInstrCommRate)
        task->payload = OptionInstrCommRateField(*pOptionInstrCommRate);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_EXEC_ORDER;
    if (pExecOrder)
        task->payload = ExecOrderField(*pExecOrder);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_FOR_QUOTE;
    if (pForQuote)
        task->payload = ForQuoteField(*pForQuote);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_QUOTE;
    if (pQuote)
        task->payload = QuoteField(*pQuote);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_COMB_INSTRUMENT_GUARD;
    if (pCombInstrumentGuard)
        task->payload = CombInstrumentGuardField(*pCombInstrumentGuard);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_COMB_ACTION;
    if (pCombAction)
        task->payload = CombActionField(*pCombAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_TRANSFER_SERIAL;
    if (pTransferSerial)
        task->payload = TransferSerialField(*pTransferSerial);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_ACCOUNTREGISTER;
    if (pAccountregister)
        task->payload = AccountregisterField(*pAccountregister);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_ERROR;
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRtnOrder(CThostFtdcOrderField *pOrder) {
    Task *task = new Task();
    task->name = ON_RTN_ORDER;
    if (pOrder)
        task->payload = OrderField(*pOrder);
    this->task_queue.push(task);
}

void CtpTd::OnRtnTrade(CThostFtdcTradeField *pTrade) {
    Task *task = new Task();
    task->name = ON_RTN_TRADE;
    if (pTrade)
        task->payload = TradeField(*pTrade);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_ORDER_INSERT;
    if (pInputOrder)
        task->payload = InputOrderField(*pInputOrder);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_ORDER_ACTION;
    if (pOrderAction)
        task->payload = OrderActionField(*pOrderAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) {
    Task *task = new Task();
    task->name = ON_RTN_INSTRUMENT_STATUS;
    if (pInstrumentStatus)
        task->payload = InstrumentStatusField(*pInstrumentStatus);
    this->task_queue.push(task);
}

void CtpTd::OnRtnBulletin(CThostFtdcBulletinField *pBulletin) {
    Task *task = new Task();
    task->name = ON_RTN_BULLETIN;
    if (pBulletin)
        task->payload = BulletinField(*pBulletin);
    this->task_queue.push(task);
}

void CtpTd::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) {
    Task *task = new Task();
    task->name = ON_RTN_TRADING_NOTICE;
    if (pTradingNoticeInfo)
        task->payload = TradingNoticeInfoField(*pTradingNoticeInfo);
    this->task_queue.push(task);
}

void CtpTd::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) {
    Task *task = new Task();
    task->name = ON_RTN_ERROR_CONDITIONAL_ORDER;
    if (pErrorConditionalOrder)
        task->payload = ErrorConditionalOrderField(*pErrorConditionalOrder);
    this->task_queue.push(task);
}

void CtpTd::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder) {
    Task *task = new Task();
    task->name = ON_RTN_EXEC_ORDER;
    if (pExecOrder)
        task->payload = ExecOrderField(*pExecOrder);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_EXEC_ORDER_INSERT;
    if (pInputExecOrder)
        task->payload = InputExecOrderField(*pInputExecOrder);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_EXEC_ORDER_ACTION;
    if (pExecOrderAction)
        task->payload = ExecOrderActionField(*pExecOrderAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_FOR_QUOTE_INSERT;
    if (pInputForQuote)
        task->payload = InputForQuoteField(*pInputForQuote);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnRtnQuote(CThostFtdcQuoteField *pQuote) {
    Task *task = new Task();
    task->name = ON_RTN_QUOTE;
    if (pQuote)
        task->payload = QuoteField(*pQuote);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_QUOTE_INSERT;
    if (pInputQuote)
        task->payload = InputQuoteField(*pInputQuote);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_QUOTE_ACTION;
    if (pQuoteAction)
        task->payload = QuoteActionField(*pQuoteAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) {
    Task *task = new Task();
    task->name = ON_RTN_FOR_QUOTE_RSP;
    if (pForQuoteRsp)
        task->payload = ForQuoteRspField(*pForQuoteRsp);
    this->task_queue.push(task);
}

void CtpTd::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken) {
    Task *task = new Task();
    task->name = ON_RTN_C_F_M_M_C_TRADING_ACCOUNT_TOKEN;
    if (pCFMMCTradingAccountToken)
        task->payload = CFMMCTradingAccountTokenField(*pCFMMCTradingAccountToken);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_BATCH_ORDER_ACTION;
    if (pBatchOrderAction)
        task->payload = BatchOrderActionField(*pBatchOrderAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnRtnCombAction(CThostFtdcCombActionField *pCombAction) {
    Task *task = new Task();
    task->name = ON_RTN_COMB_ACTION;
    if (pCombAction)
        task->payload = CombActionField(*pCombAction);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_COMB_ACTION_INSERT;
    if (pInputCombAction)
        task->payload = InputCombActionField(*pInputCombAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_CONTRACT_BANK;
    if (pContractBank)
        task->payload = ContractBankField(*pContractBank);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_PARKED_ORDER;
    if (pParkedOrder)
        task->payload = ParkedOrderField(*pParkedOrder);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_PARKED_ORDER_ACTION;
    if (pParkedOrderAction)
        task->payload = ParkedOrderActionField(*pParkedOrderAction);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_TRADING_NOTICE;
    if (pTradingNotice)
        task->payload = TradingNoticeField(*pTradingNotice);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_BROKER_TRADING_PARAMS;
    if (pBrokerTradingParams)
        task->payload = BrokerTradingParamsField(*pBrokerTradingParams);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QRY_BROKER_TRADING_ALGOS;
    if (pBrokerTradingAlgos)
        task->payload = BrokerTradingAlgosField(*pBrokerTradingAlgos);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QUERY_C_F_M_M_C_TRADING_ACCOUNT_TOKEN;
    if (pQueryCFMMCTradingAccountToken)
        task->payload = QueryCFMMCTradingAccountTokenField(*pQueryCFMMCTradingAccountToken);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) {
    Task *task = new Task();
    task->name = ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK;
    if (pRspTransfer)
        task->payload = RspTransferField(*pRspTransfer);
    this->task_queue.push(task);
}

void CtpTd::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) {
    Task *task = new Task();
    task->name = ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK;
    if (pRspTransfer)
        task->payload = RspTransferField(*pRspTransfer);
    this->task_queue.push(task);
}

void CtpTd::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) {
    Task *task = new Task();
    task->name = ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK;
    if (pRspRepeal)
        task->payload = RspRepealField(*pRspRepeal);
    this->task_queue.push(task);
}

void CtpTd::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) {
    Task *task = new Task();
    task->name = ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK;
    if (pRspRepeal)
        task->payload = RspRepealField(*pRspRepeal);
    this->task_queue.push(task);
}

void CtpTd::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer) {
    Task *task = new Task();
    task->name = ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE;
    if (pRspTransfer)
        task->payload = RspTransferField(*pRspTransfer);
    this->task_queue.push(task);
}

void CtpTd::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer) {
    Task *task = new Task();
    task->name = ON_RTN_FROM_FUTURE_TO_BANK_BY_FUTURE;
    if (pRspTransfer)
        task->payload = RspTransferField(*pRspTransfer);
    this->task_queue.push(task);
}

void CtpTd::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
    Task *task = new Task();
    task->name = ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL;
    if (pRspRepeal)
        task->payload = RspRepealField(*pRspRepeal);
    this->task_queue.push(task);
}

void CtpTd::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
    Task *task = new Task();
    task->name = ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL;
    if (pRspRepeal)
        task->payload = RspRepealField(*pRspRepeal);
    this->task_queue.push(task);
}

void CtpTd::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) {
    Task *task = new Task();
    task->name = ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE;
    if (pNotifyQueryAccount)
        task->payload = NotifyQueryAccountField(*pNotifyQueryAccount);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_BANK_TO_FUTURE_BY_FUTURE;
    if (pReqTransfer)
        task->payload = ReqTransferField(*pReqTransfer);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_FUTURE_TO_BANK_BY_FUTURE;
    if (pReqTransfer)
        task->payload = ReqTransferField(*pReqTransfer);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL;
    if (pReqRepeal)
        task->payload = ReqRepealField(*pReqRepeal);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL;
    if (pReqRepeal)
        task->payload = ReqRepealField(*pReqRepeal);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) {
    Task *task = new Task();
    task->name = ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE;
    if (pReqQueryAccount)
        task->payload = ReqQueryAccountField(*pReqQueryAccount);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    this->task_queue.push(task);
}

void CtpTd::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) {
    Task *task = new Task();
    task->name = ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE;
    if (pRspRepeal)
        task->payload = RspRepealField(*pRspRepeal);
    this->task_queue.push(task);
}

void CtpTd::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) {
    Task *task = new Task();
    task->name = ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE;
    if (pRspRepeal)
        task->payload = RspRepealField(*pRspRepeal);
    this->task_queue.push(task);
}

void CtpTd::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE;
    if (pReqTransfer)
        task->payload = ReqTransferField(*pReqTransfer);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE;
    if (pReqTransfer)
        task->payload = ReqTransferField(*pReqTransfer);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE;
    if (pReqQueryAccount)
        task->payload = ReqQueryAccountField(*pReqQueryAccount);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpTd::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount) {
    Task *task = new Task();
    task->name = ON_RTN_OPEN_ACCOUNT_BY_BANK;
    if (pOpenAccount)
        task->payload = OpenAccountField(*pOpenAccount);
    this->task_queue.push(task);
}

void CtpTd::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount) {
    Task *task = new Task();
    task->name = ON_RTN_CANCEL_ACCOUNT_BY_BANK;
    if (pCancelAccount)
        task->payload = CancelAccountField(*pCancelAccount);
    this->task_queue.push(task);
}

void CtpTd::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount) {
    Task *task = new Task();
    task->name = ON_RTN_CHANGE_ACCOUNT_BY_BANK;
    if (pChangeAccount)
        task->payload = ChangeAccountField(*pChangeAccount);
    this->task_queue.push(task);
}

void CtpTd::processTask() {
    while (true) {
        Task* task = this->task_queue.wait_and_pop();
        WithdrawGIL lock;
        switch (task->name) {
            case ON_FRONT_CONNECTED: {
                this->onFrontConnected();
                break;
            }
            case ON_FRONT_DISCONNECTED: {
                this->onFrontDisconnected(task->num);
                break;
            }
            case ON_HEART_BEAT_WARNING: {
                this->onHeartBeatWarning(task->num);
                break;
            }
            case ON_RSP_AUTHENTICATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspAuthenticateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspAuthenticate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_USER_LOGIN: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspUserLoginField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspUserLogin(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_USER_LOGOUT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<UserLogoutField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspUserLogout(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_USER_PASSWORD_UPDATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<UserPasswordUpdateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspUserPasswordUpdate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_TRADING_ACCOUNT_PASSWORD_UPDATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<TradingAccountPasswordUpdateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspTradingAccountPasswordUpdate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_ORDER_INSERT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputOrderField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspOrderInsert(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_PARKED_ORDER_INSERT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ParkedOrderField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspParkedOrderInsert(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_PARKED_ORDER_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ParkedOrderActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspParkedOrderAction(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_ORDER_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputOrderActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspOrderAction(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QUERY_MAX_ORDER_VOLUME: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<QueryMaxOrderVolumeField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQueryMaxOrderVolume(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_SETTLEMENT_INFO_CONFIRM: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<SettlementInfoConfirmField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspSettlementInfoConfirm(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_REMOVE_PARKED_ORDER: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RemoveParkedOrderField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspRemoveParkedOrder(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_REMOVE_PARKED_ORDER_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RemoveParkedOrderActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspRemoveParkedOrderAction(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_EXEC_ORDER_INSERT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputExecOrderField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspExecOrderInsert(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_EXEC_ORDER_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputExecOrderActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspExecOrderAction(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_FOR_QUOTE_INSERT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputForQuoteField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspForQuoteInsert(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QUOTE_INSERT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputQuoteField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQuoteInsert(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QUOTE_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputQuoteActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQuoteAction(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_BATCH_ORDER_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputBatchOrderActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspBatchOrderAction(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_COMB_ACTION_INSERT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputCombActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspCombActionInsert(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_ORDER: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<OrderField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryOrder(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_TRADE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<TradeField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryTrade(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_INVESTOR_POSITION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InvestorPositionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryInvestorPosition(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_TRADING_ACCOUNT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<TradingAccountField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryTradingAccount(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_INVESTOR: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InvestorField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryInvestor(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_TRADING_CODE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<TradingCodeField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryTradingCode(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_INSTRUMENT_MARGIN_RATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InstrumentMarginRateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryInstrumentMarginRate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_INSTRUMENT_COMMISSION_RATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InstrumentCommissionRateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryInstrumentCommissionRate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_EXCHANGE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ExchangeField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryExchange(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_PRODUCT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ProductField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryProduct(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_INSTRUMENT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InstrumentField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryInstrument(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_DEPTH_MARKET_DATA: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<DepthMarketDataField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryDepthMarketData(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_SETTLEMENT_INFO: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<SettlementInfoField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQrySettlementInfo(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_TRANSFER_BANK: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<TransferBankField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryTransferBank(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_INVESTOR_POSITION_DETAIL: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InvestorPositionDetailField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryInvestorPositionDetail(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_NOTICE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<NoticeField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryNotice(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<SettlementInfoConfirmField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQrySettlementInfoConfirm(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_INVESTOR_POSITION_COMBINE_DETAIL: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InvestorPositionCombineDetailField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryInvestorPositionCombineDetail(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_C_F_M_M_C_TRADING_ACCOUNT_KEY: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<CFMMCTradingAccountKeyField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryCFMMCTradingAccountKey(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_E_WARRANT_OFFSET: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<EWarrantOffsetField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryEWarrantOffset(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_INVESTOR_PRODUCT_GROUP_MARGIN: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InvestorProductGroupMarginField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryInvestorProductGroupMargin(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_EXCHANGE_MARGIN_RATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ExchangeMarginRateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryExchangeMarginRate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_EXCHANGE_MARGIN_RATE_ADJUST: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ExchangeMarginRateAdjustField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryExchangeMarginRateAdjust(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_EXCHANGE_RATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ExchangeRateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryExchangeRate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_SEC_AGENT_A_C_I_D_MAP: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<SecAgentACIDMapField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQrySecAgentACIDMap(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_PRODUCT_EXCH_RATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ProductExchRateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryProductExchRate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_PRODUCT_GROUP: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ProductGroupField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryProductGroup(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_M_M_INSTRUMENT_COMMISSION_RATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<MMInstrumentCommissionRateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryMMInstrumentCommissionRate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_M_M_OPTION_INSTR_COMM_RATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<MMOptionInstrCommRateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryMMOptionInstrCommRate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_INSTRUMENT_ORDER_COMM_RATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InstrumentOrderCommRateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryInstrumentOrderCommRate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_OPTION_INSTR_TRADE_COST: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<OptionInstrTradeCostField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryOptionInstrTradeCost(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_OPTION_INSTR_COMM_RATE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<OptionInstrCommRateField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryOptionInstrCommRate(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_EXEC_ORDER: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ExecOrderField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryExecOrder(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_FOR_QUOTE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ForQuoteField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryForQuote(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_QUOTE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<QuoteField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryQuote(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_COMB_INSTRUMENT_GUARD: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<CombInstrumentGuardField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryCombInstrumentGuard(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_COMB_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<CombActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryCombAction(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_TRANSFER_SERIAL: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<TransferSerialField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryTransferSerial(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_ACCOUNTREGISTER: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<AccountregisterField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryAccountregister(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_ERROR: {
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspError(const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RTN_ORDER: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<OrderField &>(task->payload));
                this->onRtnOrder(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_TRADE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<TradeField &>(task->payload));
                this->onRtnTrade(const_cast<object &>(payload));
                break;
            }
            case ON_ERR_RTN_ORDER_INSERT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputOrderField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnOrderInsert(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_ERR_RTN_ORDER_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<OrderActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnOrderAction(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_RTN_INSTRUMENT_STATUS: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InstrumentStatusField &>(task->payload));
                this->onRtnInstrumentStatus(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_BULLETIN: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<BulletinField &>(task->payload));
                this->onRtnBulletin(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_TRADING_NOTICE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<TradingNoticeInfoField &>(task->payload));
                this->onRtnTradingNotice(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_ERROR_CONDITIONAL_ORDER: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ErrorConditionalOrderField &>(task->payload));
                this->onRtnErrorConditionalOrder(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_EXEC_ORDER: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ExecOrderField &>(task->payload));
                this->onRtnExecOrder(const_cast<object &>(payload));
                break;
            }
            case ON_ERR_RTN_EXEC_ORDER_INSERT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputExecOrderField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnExecOrderInsert(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_ERR_RTN_EXEC_ORDER_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ExecOrderActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnExecOrderAction(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_ERR_RTN_FOR_QUOTE_INSERT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputForQuoteField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnForQuoteInsert(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_RTN_QUOTE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<QuoteField &>(task->payload));
                this->onRtnQuote(const_cast<object &>(payload));
                break;
            }
            case ON_ERR_RTN_QUOTE_INSERT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputQuoteField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnQuoteInsert(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_ERR_RTN_QUOTE_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<QuoteActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnQuoteAction(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_RTN_FOR_QUOTE_RSP: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ForQuoteRspField &>(task->payload));
                this->onRtnForQuoteRsp(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_C_F_M_M_C_TRADING_ACCOUNT_TOKEN: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<CFMMCTradingAccountTokenField &>(task->payload));
                this->onRtnCFMMCTradingAccountToken(const_cast<object &>(payload));
                break;
            }
            case ON_ERR_RTN_BATCH_ORDER_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<BatchOrderActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnBatchOrderAction(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_RTN_COMB_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<CombActionField &>(task->payload));
                this->onRtnCombAction(const_cast<object &>(payload));
                break;
            }
            case ON_ERR_RTN_COMB_ACTION_INSERT: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<InputCombActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnCombActionInsert(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_RSP_QRY_CONTRACT_BANK: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ContractBankField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryContractBank(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_PARKED_ORDER: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ParkedOrderField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryParkedOrder(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_PARKED_ORDER_ACTION: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ParkedOrderActionField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryParkedOrderAction(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_TRADING_NOTICE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<TradingNoticeField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryTradingNotice(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_BROKER_TRADING_PARAMS: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<BrokerTradingParamsField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryBrokerTradingParams(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QRY_BROKER_TRADING_ALGOS: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<BrokerTradingAlgosField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQryBrokerTradingAlgos(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QUERY_C_F_M_M_C_TRADING_ACCOUNT_TOKEN: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<QueryCFMMCTradingAccountTokenField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQueryCFMMCTradingAccountToken(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspTransferField &>(task->payload));
                this->onRtnFromBankToFutureByBank(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspTransferField &>(task->payload));
                this->onRtnFromFutureToBankByBank(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspRepealField &>(task->payload));
                this->onRtnRepealFromBankToFutureByBank(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspRepealField &>(task->payload));
                this->onRtnRepealFromFutureToBankByBank(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspTransferField &>(task->payload));
                this->onRtnFromBankToFutureByFuture(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_FROM_FUTURE_TO_BANK_BY_FUTURE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspTransferField &>(task->payload));
                this->onRtnFromFutureToBankByFuture(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspRepealField &>(task->payload));
                this->onRtnRepealFromBankToFutureByFutureManual(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspRepealField &>(task->payload));
                this->onRtnRepealFromFutureToBankByFutureManual(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<NotifyQueryAccountField &>(task->payload));
                this->onRtnQueryBankBalanceByFuture(const_cast<object &>(payload));
                break;
            }
            case ON_ERR_RTN_BANK_TO_FUTURE_BY_FUTURE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ReqTransferField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnBankToFutureByFuture(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_ERR_RTN_FUTURE_TO_BANK_BY_FUTURE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ReqTransferField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnFutureToBankByFuture(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ReqRepealField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnRepealBankToFutureByFutureManual(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ReqRepealField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnRepealFutureToBankByFutureManual(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ReqQueryAccountField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onErrRtnQueryBankBalanceByFuture(const_cast<object &>(payload), const_cast<object &>(resp));
                break;
            }
            case ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspRepealField &>(task->payload));
                this->onRtnRepealFromBankToFutureByFuture(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<RspRepealField &>(task->payload));
                this->onRtnRepealFromFutureToBankByFuture(const_cast<object &>(payload));
                break;
            }
            case ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ReqTransferField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspFromBankToFutureByFuture(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ReqTransferField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspFromFutureToBankByFuture(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ReqQueryAccountField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspQueryBankAccountMoneyByFuture(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RTN_OPEN_ACCOUNT_BY_BANK: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<OpenAccountField &>(task->payload));
                this->onRtnOpenAccountByBank(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_CANCEL_ACCOUNT_BY_BANK: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<CancelAccountField &>(task->payload));
                this->onRtnCancelAccountByBank(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_CHANGE_ACCOUNT_BY_BANK: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ChangeAccountField &>(task->payload));
                this->onRtnChangeAccountByBank(const_cast<object &>(payload));
                break;
            }
        }
        delete task;
    }
}

const char *CtpTd::getApiVersion() {
    return  CThostFtdcTraderApi::GetApiVersion();
}

void CtpTd::release() {
    DepositGIL unlocker;
    this->api->Release();
}

void CtpTd::init() {
    DepositGIL unlocker;
    this->api->Init();
}

int CtpTd::join() {
    DepositGIL unlocker;
    return this->api->Join();
}

const char *CtpTd::getTradingDay() {
    return this->api->GetTradingDay();
}

void CtpTd::registerFront(const std::string &szFrontAddress) {
    this->api->RegisterFront(const_cast<char *>(szFrontAddress.c_str()));
}

void CtpTd::registerNameServer(const std::string &szNsAddress) {
    this->api->RegisterNameServer(const_cast<char *>(szNsAddress.c_str()));
}

void CtpTd::registerFensUserInfo(object &fensUserInfoField) {
    FensUserInfoField *p1 = extract<FensUserInfoField *>(fensUserInfoField);
    this->api->RegisterFensUserInfo(p1);
}

void CtpTd::registerSpi() {
    this->api->RegisterSpi(this);
}

void CtpTd::subscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType) {
    this->api->SubscribePrivateTopic(nResumeType);
}

void CtpTd::subscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType) {
    this->api->SubscribePublicTopic(nResumeType);
}

int CtpTd::reqAuthenticate(object &reqAuthenticateField, int requestId) {
    ReqAuthenticateField *p1 = extract<ReqAuthenticateField *>(reqAuthenticateField);
    return this->api->ReqAuthenticate(p1, requestId);
}

int CtpTd::reqUserLogin(object &reqUserLoginField, int requestId) {
    ReqUserLoginField *p1 = extract<ReqUserLoginField *>(reqUserLoginField);
    return this->api->ReqUserLogin(p1, requestId);
}

int CtpTd::reqUserLogout(object &userLogoutField, int requestId) {
    UserLogoutField *p1 = extract<UserLogoutField *>(userLogoutField);
    return this->api->ReqUserLogout(p1, requestId);
}

int CtpTd::reqUserPasswordUpdate(object &userPasswordUpdateField, int requestId) {
    UserPasswordUpdateField *p1 = extract<UserPasswordUpdateField *>(userPasswordUpdateField);
    return this->api->ReqUserPasswordUpdate(p1, requestId);
}

int CtpTd::reqTradingAccountPasswordUpdate(object &tradingAccountPasswordUpdateField, int requestId) {
    TradingAccountPasswordUpdateField *p1 = extract<TradingAccountPasswordUpdateField *>(tradingAccountPasswordUpdateField);
    return this->api->ReqTradingAccountPasswordUpdate(p1, requestId);
}

int CtpTd::reqOrderInsert(object &inputOrderField, int requestId) {
    InputOrderField *p1 = extract<InputOrderField *>(inputOrderField);
    return this->api->ReqOrderInsert(p1, requestId);
}

int CtpTd::reqParkedOrderInsert(object &parkedOrderField, int requestId) {
    ParkedOrderField *p1 = extract<ParkedOrderField *>(parkedOrderField);
    return this->api->ReqParkedOrderInsert(p1, requestId);
}

int CtpTd::reqParkedOrderAction(object &parkedOrderActionField, int requestId) {
    ParkedOrderActionField *p1 = extract<ParkedOrderActionField *>(parkedOrderActionField);
    return this->api->ReqParkedOrderAction(p1, requestId);
}

int CtpTd::reqOrderAction(object &inputOrderActionField, int requestId) {
    InputOrderActionField *p1 = extract<InputOrderActionField *>(inputOrderActionField);
    return this->api->ReqOrderAction(p1, requestId);
}

int CtpTd::reqQueryMaxOrderVolume(object &queryMaxOrderVolumeField, int requestId) {
    QueryMaxOrderVolumeField *p1 = extract<QueryMaxOrderVolumeField *>(queryMaxOrderVolumeField);
    return this->api->ReqQueryMaxOrderVolume(p1, requestId);
}

int CtpTd::reqSettlementInfoConfirm(object &settlementInfoConfirmField, int requestId) {
    SettlementInfoConfirmField *p1 = extract<SettlementInfoConfirmField *>(settlementInfoConfirmField);
    return this->api->ReqSettlementInfoConfirm(p1, requestId);
}

int CtpTd::reqRemoveParkedOrder(object &removeParkedOrderField, int requestId) {
    RemoveParkedOrderField *p1 = extract<RemoveParkedOrderField *>(removeParkedOrderField);
    return this->api->ReqRemoveParkedOrder(p1, requestId);
}

int CtpTd::reqRemoveParkedOrderAction(object &removeParkedOrderActionField, int requestId) {
    RemoveParkedOrderActionField *p1 = extract<RemoveParkedOrderActionField *>(removeParkedOrderActionField);
    return this->api->ReqRemoveParkedOrderAction(p1, requestId);
}

int CtpTd::reqExecOrderInsert(object &inputExecOrderField, int requestId) {
    InputExecOrderField *p1 = extract<InputExecOrderField *>(inputExecOrderField);
    return this->api->ReqExecOrderInsert(p1, requestId);
}

int CtpTd::reqExecOrderAction(object &inputExecOrderActionField, int requestId) {
    InputExecOrderActionField *p1 = extract<InputExecOrderActionField *>(inputExecOrderActionField);
    return this->api->ReqExecOrderAction(p1, requestId);
}

int CtpTd::reqForQuoteInsert(object &inputForQuoteField, int requestId) {
    InputForQuoteField *p1 = extract<InputForQuoteField *>(inputForQuoteField);
    return this->api->ReqForQuoteInsert(p1, requestId);
}

int CtpTd::reqQuoteInsert(object &inputQuoteField, int requestId) {
    InputQuoteField *p1 = extract<InputQuoteField *>(inputQuoteField);
    return this->api->ReqQuoteInsert(p1, requestId);
}

int CtpTd::reqQuoteAction(object &inputQuoteActionField, int requestId) {
    InputQuoteActionField *p1 = extract<InputQuoteActionField *>(inputQuoteActionField);
    return this->api->ReqQuoteAction(p1, requestId);
}

int CtpTd::reqBatchOrderAction(object &inputBatchOrderActionField, int requestId) {
    InputBatchOrderActionField *p1 = extract<InputBatchOrderActionField *>(inputBatchOrderActionField);
    return this->api->ReqBatchOrderAction(p1, requestId);
}

int CtpTd::reqCombActionInsert(object &inputCombActionField, int requestId) {
    InputCombActionField *p1 = extract<InputCombActionField *>(inputCombActionField);
    return this->api->ReqCombActionInsert(p1, requestId);
}

int CtpTd::reqQryOrder(object &qryOrderField, int requestId) {
    QryOrderField *p1 = extract<QryOrderField *>(qryOrderField);
    return this->api->ReqQryOrder(p1, requestId);
}

int CtpTd::reqQryTrade(object &qryTradeField, int requestId) {
    QryTradeField *p1 = extract<QryTradeField *>(qryTradeField);
    return this->api->ReqQryTrade(p1, requestId);
}

int CtpTd::reqQryInvestorPosition(object &qryInvestorPositionField, int requestId) {
    QryInvestorPositionField *p1 = extract<QryInvestorPositionField *>(qryInvestorPositionField);
    return this->api->ReqQryInvestorPosition(p1, requestId);
}

int CtpTd::reqQryTradingAccount(object &qryTradingAccountField, int requestId) {
    QryTradingAccountField *p1 = extract<QryTradingAccountField *>(qryTradingAccountField);
    return this->api->ReqQryTradingAccount(p1, requestId);
}

int CtpTd::reqQryInvestor(object &qryInvestorField, int requestId) {
    QryInvestorField *p1 = extract<QryInvestorField *>(qryInvestorField);
    return this->api->ReqQryInvestor(p1, requestId);
}

int CtpTd::reqQryTradingCode(object &qryTradingCodeField, int requestId) {
    QryTradingCodeField *p1 = extract<QryTradingCodeField *>(qryTradingCodeField);
    return this->api->ReqQryTradingCode(p1, requestId);
}

int CtpTd::reqQryInstrumentMarginRate(object &qryInstrumentMarginRateField, int requestId) {
    QryInstrumentMarginRateField *p1 = extract<QryInstrumentMarginRateField *>(qryInstrumentMarginRateField);
    return this->api->ReqQryInstrumentMarginRate(p1, requestId);
}

int CtpTd::reqQryInstrumentCommissionRate(object &qryInstrumentCommissionRateField, int requestId) {
    QryInstrumentCommissionRateField *p1 = extract<QryInstrumentCommissionRateField *>(qryInstrumentCommissionRateField);
    return this->api->ReqQryInstrumentCommissionRate(p1, requestId);
}

int CtpTd::reqQryExchange(object &qryExchangeField, int requestId) {
    QryExchangeField *p1 = extract<QryExchangeField *>(qryExchangeField);
    return this->api->ReqQryExchange(p1, requestId);
}

int CtpTd::reqQryProduct(object &qryProductField, int requestId) {
    QryProductField *p1 = extract<QryProductField *>(qryProductField);
    return this->api->ReqQryProduct(p1, requestId);
}

int CtpTd::reqQryInstrument(object &qryInstrumentField, int requestId) {
    QryInstrumentField *p1 = extract<QryInstrumentField *>(qryInstrumentField);
    return this->api->ReqQryInstrument(p1, requestId);
}

int CtpTd::reqQryDepthMarketData(object &qryDepthMarketDataField, int requestId) {
    QryDepthMarketDataField *p1 = extract<QryDepthMarketDataField *>(qryDepthMarketDataField);
    return this->api->ReqQryDepthMarketData(p1, requestId);
}

int CtpTd::reqQrySettlementInfo(object &qrySettlementInfoField, int requestId) {
    QrySettlementInfoField *p1 = extract<QrySettlementInfoField *>(qrySettlementInfoField);
    return this->api->ReqQrySettlementInfo(p1, requestId);
}

int CtpTd::reqQryTransferBank(object &qryTransferBankField, int requestId) {
    QryTransferBankField *p1 = extract<QryTransferBankField *>(qryTransferBankField);
    return this->api->ReqQryTransferBank(p1, requestId);
}

int CtpTd::reqQryInvestorPositionDetail(object &qryInvestorPositionDetailField, int requestId) {
    QryInvestorPositionDetailField *p1 = extract<QryInvestorPositionDetailField *>(qryInvestorPositionDetailField);
    return this->api->ReqQryInvestorPositionDetail(p1, requestId);
}

int CtpTd::reqQryNotice(object &qryNoticeField, int requestId) {
    QryNoticeField *p1 = extract<QryNoticeField *>(qryNoticeField);
    return this->api->ReqQryNotice(p1, requestId);
}

int CtpTd::reqQrySettlementInfoConfirm(object &qrySettlementInfoConfirmField, int requestId) {
    QrySettlementInfoConfirmField *p1 = extract<QrySettlementInfoConfirmField *>(qrySettlementInfoConfirmField);
    return this->api->ReqQrySettlementInfoConfirm(p1, requestId);
}

int CtpTd::reqQryInvestorPositionCombineDetail(object &qryInvestorPositionCombineDetailField, int requestId) {
    QryInvestorPositionCombineDetailField *p1 = extract<QryInvestorPositionCombineDetailField *>(qryInvestorPositionCombineDetailField);
    return this->api->ReqQryInvestorPositionCombineDetail(p1, requestId);
}

int CtpTd::reqQryCFMMCTradingAccountKey(object &qryCFMMCTradingAccountKeyField, int requestId) {
    QryCFMMCTradingAccountKeyField *p1 = extract<QryCFMMCTradingAccountKeyField *>(qryCFMMCTradingAccountKeyField);
    return this->api->ReqQryCFMMCTradingAccountKey(p1, requestId);
}

int CtpTd::reqQryEWarrantOffset(object &qryEWarrantOffsetField, int requestId) {
    QryEWarrantOffsetField *p1 = extract<QryEWarrantOffsetField *>(qryEWarrantOffsetField);
    return this->api->ReqQryEWarrantOffset(p1, requestId);
}

int CtpTd::reqQryInvestorProductGroupMargin(object &qryInvestorProductGroupMarginField, int requestId) {
    QryInvestorProductGroupMarginField *p1 = extract<QryInvestorProductGroupMarginField *>(qryInvestorProductGroupMarginField);
    return this->api->ReqQryInvestorProductGroupMargin(p1, requestId);
}

int CtpTd::reqQryExchangeMarginRate(object &qryExchangeMarginRateField, int requestId) {
    QryExchangeMarginRateField *p1 = extract<QryExchangeMarginRateField *>(qryExchangeMarginRateField);
    return this->api->ReqQryExchangeMarginRate(p1, requestId);
}

int CtpTd::reqQryExchangeMarginRateAdjust(object &qryExchangeMarginRateAdjustField, int requestId) {
    QryExchangeMarginRateAdjustField *p1 = extract<QryExchangeMarginRateAdjustField *>(qryExchangeMarginRateAdjustField);
    return this->api->ReqQryExchangeMarginRateAdjust(p1, requestId);
}

int CtpTd::reqQryExchangeRate(object &qryExchangeRateField, int requestId) {
    QryExchangeRateField *p1 = extract<QryExchangeRateField *>(qryExchangeRateField);
    return this->api->ReqQryExchangeRate(p1, requestId);
}

int CtpTd::reqQrySecAgentACIDMap(object &qrySecAgentACIDMapField, int requestId) {
    QrySecAgentACIDMapField *p1 = extract<QrySecAgentACIDMapField *>(qrySecAgentACIDMapField);
    return this->api->ReqQrySecAgentACIDMap(p1, requestId);
}

int CtpTd::reqQryProductExchRate(object &qryProductExchRateField, int requestId) {
    QryProductExchRateField *p1 = extract<QryProductExchRateField *>(qryProductExchRateField);
    return this->api->ReqQryProductExchRate(p1, requestId);
}

int CtpTd::reqQryProductGroup(object &qryProductGroupField, int requestId) {
    QryProductGroupField *p1 = extract<QryProductGroupField *>(qryProductGroupField);
    return this->api->ReqQryProductGroup(p1, requestId);
}

int CtpTd::reqQryMMInstrumentCommissionRate(object &qryMMInstrumentCommissionRateField, int requestId) {
    QryMMInstrumentCommissionRateField *p1 = extract<QryMMInstrumentCommissionRateField *>(qryMMInstrumentCommissionRateField);
    return this->api->ReqQryMMInstrumentCommissionRate(p1, requestId);
}

int CtpTd::reqQryMMOptionInstrCommRate(object &qryMMOptionInstrCommRateField, int requestId) {
    QryMMOptionInstrCommRateField *p1 = extract<QryMMOptionInstrCommRateField *>(qryMMOptionInstrCommRateField);
    return this->api->ReqQryMMOptionInstrCommRate(p1, requestId);
}

int CtpTd::reqQryInstrumentOrderCommRate(object &qryInstrumentOrderCommRateField, int requestId) {
    QryInstrumentOrderCommRateField *p1 = extract<QryInstrumentOrderCommRateField *>(qryInstrumentOrderCommRateField);
    return this->api->ReqQryInstrumentOrderCommRate(p1, requestId);
}

int CtpTd::reqQryOptionInstrTradeCost(object &qryOptionInstrTradeCostField, int requestId) {
    QryOptionInstrTradeCostField *p1 = extract<QryOptionInstrTradeCostField *>(qryOptionInstrTradeCostField);
    return this->api->ReqQryOptionInstrTradeCost(p1, requestId);
}

int CtpTd::reqQryOptionInstrCommRate(object &qryOptionInstrCommRateField, int requestId) {
    QryOptionInstrCommRateField *p1 = extract<QryOptionInstrCommRateField *>(qryOptionInstrCommRateField);
    return this->api->ReqQryOptionInstrCommRate(p1, requestId);
}

int CtpTd::reqQryExecOrder(object &qryExecOrderField, int requestId) {
    QryExecOrderField *p1 = extract<QryExecOrderField *>(qryExecOrderField);
    return this->api->ReqQryExecOrder(p1, requestId);
}

int CtpTd::reqQryForQuote(object &qryForQuoteField, int requestId) {
    QryForQuoteField *p1 = extract<QryForQuoteField *>(qryForQuoteField);
    return this->api->ReqQryForQuote(p1, requestId);
}

int CtpTd::reqQryQuote(object &qryQuoteField, int requestId) {
    QryQuoteField *p1 = extract<QryQuoteField *>(qryQuoteField);
    return this->api->ReqQryQuote(p1, requestId);
}

int CtpTd::reqQryCombInstrumentGuard(object &qryCombInstrumentGuardField, int requestId) {
    QryCombInstrumentGuardField *p1 = extract<QryCombInstrumentGuardField *>(qryCombInstrumentGuardField);
    return this->api->ReqQryCombInstrumentGuard(p1, requestId);
}

int CtpTd::reqQryCombAction(object &qryCombActionField, int requestId) {
    QryCombActionField *p1 = extract<QryCombActionField *>(qryCombActionField);
    return this->api->ReqQryCombAction(p1, requestId);
}

int CtpTd::reqQryTransferSerial(object &qryTransferSerialField, int requestId) {
    QryTransferSerialField *p1 = extract<QryTransferSerialField *>(qryTransferSerialField);
    return this->api->ReqQryTransferSerial(p1, requestId);
}

int CtpTd::reqQryAccountregister(object &qryAccountregisterField, int requestId) {
    QryAccountregisterField *p1 = extract<QryAccountregisterField *>(qryAccountregisterField);
    return this->api->ReqQryAccountregister(p1, requestId);
}

int CtpTd::reqQryContractBank(object &qryContractBankField, int requestId) {
    QryContractBankField *p1 = extract<QryContractBankField *>(qryContractBankField);
    return this->api->ReqQryContractBank(p1, requestId);
}

int CtpTd::reqQryParkedOrder(object &qryParkedOrderField, int requestId) {
    QryParkedOrderField *p1 = extract<QryParkedOrderField *>(qryParkedOrderField);
    return this->api->ReqQryParkedOrder(p1, requestId);
}

int CtpTd::reqQryParkedOrderAction(object &qryParkedOrderActionField, int requestId) {
    QryParkedOrderActionField *p1 = extract<QryParkedOrderActionField *>(qryParkedOrderActionField);
    return this->api->ReqQryParkedOrderAction(p1, requestId);
}

int CtpTd::reqQryTradingNotice(object &qryTradingNoticeField, int requestId) {
    QryTradingNoticeField *p1 = extract<QryTradingNoticeField *>(qryTradingNoticeField);
    return this->api->ReqQryTradingNotice(p1, requestId);
}

int CtpTd::reqQryBrokerTradingParams(object &qryBrokerTradingParamsField, int requestId) {
    QryBrokerTradingParamsField *p1 = extract<QryBrokerTradingParamsField *>(qryBrokerTradingParamsField);
    return this->api->ReqQryBrokerTradingParams(p1, requestId);
}

int CtpTd::reqQryBrokerTradingAlgos(object &qryBrokerTradingAlgosField, int requestId) {
    QryBrokerTradingAlgosField *p1 = extract<QryBrokerTradingAlgosField *>(qryBrokerTradingAlgosField);
    return this->api->ReqQryBrokerTradingAlgos(p1, requestId);
}

int CtpTd::reqQueryCFMMCTradingAccountToken(object &queryCFMMCTradingAccountTokenField, int requestId) {
    QueryCFMMCTradingAccountTokenField *p1 = extract<QueryCFMMCTradingAccountTokenField *>(queryCFMMCTradingAccountTokenField);
    return this->api->ReqQueryCFMMCTradingAccountToken(p1, requestId);
}

int CtpTd::reqFromBankToFutureByFuture(object &reqTransferField, int requestId) {
    ReqTransferField *p1 = extract<ReqTransferField *>(reqTransferField);
    return this->api->ReqFromBankToFutureByFuture(p1, requestId);
}

int CtpTd::reqFromFutureToBankByFuture(object &reqTransferField, int requestId) {
    ReqTransferField *p1 = extract<ReqTransferField *>(reqTransferField);
    return this->api->ReqFromFutureToBankByFuture(p1, requestId);
}

int CtpTd::reqQueryBankAccountMoneyByFuture(object &reqQueryAccountField, int requestId) {
    ReqQueryAccountField *p1 = extract<ReqQueryAccountField *>(reqQueryAccountField);
    return this->api->ReqQueryBankAccountMoneyByFuture(p1, requestId);
}

struct CtpTdWrap : CtpTd, wrapper<CtpTd> {

    CtpTdWrap(const std::string &szFlowPath = "")
            : CtpTd(szFlowPath) {}

    virtual void onFrontConnected() {
        try {
            this->get_override("onFrontConnected")();
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onFrontDisconnected(int reasonCode) {
        try {
            this->get_override("onFrontDisconnected")(reasonCode);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onHeartBeatWarning(int lapsedTime) {
        try {
            this->get_override("onHeartBeatWarning")(lapsedTime);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspAuthenticate(object &rspAuthenticateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspAuthenticate")(rspAuthenticateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspUserLogin(object &rspUserLoginField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspUserLogin")(rspUserLoginField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspUserLogout(object &userLogoutField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspUserLogout")(userLogoutField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspUserPasswordUpdate(object &userPasswordUpdateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspUserPasswordUpdate")(userPasswordUpdateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspTradingAccountPasswordUpdate(object &tradingAccountPasswordUpdateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspTradingAccountPasswordUpdate")(tradingAccountPasswordUpdateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspOrderInsert(object &inputOrderField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspOrderInsert")(inputOrderField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspParkedOrderInsert(object &parkedOrderField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspParkedOrderInsert")(parkedOrderField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspParkedOrderAction(object &parkedOrderActionField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspParkedOrderAction")(parkedOrderActionField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspOrderAction(object &inputOrderActionField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspOrderAction")(inputOrderActionField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQueryMaxOrderVolume(object &queryMaxOrderVolumeField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQueryMaxOrderVolume")(queryMaxOrderVolumeField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspSettlementInfoConfirm(object &settlementInfoConfirmField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspSettlementInfoConfirm")(settlementInfoConfirmField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspRemoveParkedOrder(object &removeParkedOrderField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspRemoveParkedOrder")(removeParkedOrderField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspRemoveParkedOrderAction(object &removeParkedOrderActionField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspRemoveParkedOrderAction")(removeParkedOrderActionField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspExecOrderInsert(object &inputExecOrderField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspExecOrderInsert")(inputExecOrderField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspExecOrderAction(object &inputExecOrderActionField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspExecOrderAction")(inputExecOrderActionField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspForQuoteInsert(object &inputForQuoteField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspForQuoteInsert")(inputForQuoteField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQuoteInsert(object &inputQuoteField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQuoteInsert")(inputQuoteField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQuoteAction(object &inputQuoteActionField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQuoteAction")(inputQuoteActionField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspBatchOrderAction(object &inputBatchOrderActionField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspBatchOrderAction")(inputBatchOrderActionField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspCombActionInsert(object &inputCombActionField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspCombActionInsert")(inputCombActionField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryOrder(object &orderField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryOrder")(orderField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryTrade(object &tradeField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryTrade")(tradeField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryInvestorPosition(object &investorPositionField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryInvestorPosition")(investorPositionField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryTradingAccount(object &tradingAccountField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryTradingAccount")(tradingAccountField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryInvestor(object &investorField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryInvestor")(investorField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryTradingCode(object &tradingCodeField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryTradingCode")(tradingCodeField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryInstrumentMarginRate(object &instrumentMarginRateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryInstrumentMarginRate")(instrumentMarginRateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryInstrumentCommissionRate(object &instrumentCommissionRateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryInstrumentCommissionRate")(instrumentCommissionRateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryExchange(object &exchangeField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryExchange")(exchangeField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryProduct(object &productField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryProduct")(productField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryInstrument(object &instrumentField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryInstrument")(instrumentField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryDepthMarketData(object &depthMarketDataField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryDepthMarketData")(depthMarketDataField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQrySettlementInfo(object &settlementInfoField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQrySettlementInfo")(settlementInfoField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryTransferBank(object &transferBankField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryTransferBank")(transferBankField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryInvestorPositionDetail(object &investorPositionDetailField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryInvestorPositionDetail")(investorPositionDetailField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryNotice(object &noticeField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryNotice")(noticeField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQrySettlementInfoConfirm(object &settlementInfoConfirmField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQrySettlementInfoConfirm")(settlementInfoConfirmField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryInvestorPositionCombineDetail(object &investorPositionCombineDetailField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryInvestorPositionCombineDetail")(investorPositionCombineDetailField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryCFMMCTradingAccountKey(object &cFMMCTradingAccountKeyField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryCFMMCTradingAccountKey")(cFMMCTradingAccountKeyField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryEWarrantOffset(object &eWarrantOffsetField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryEWarrantOffset")(eWarrantOffsetField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryInvestorProductGroupMargin(object &investorProductGroupMarginField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryInvestorProductGroupMargin")(investorProductGroupMarginField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryExchangeMarginRate(object &exchangeMarginRateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryExchangeMarginRate")(exchangeMarginRateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryExchangeMarginRateAdjust(object &exchangeMarginRateAdjustField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryExchangeMarginRateAdjust")(exchangeMarginRateAdjustField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryExchangeRate(object &exchangeRateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryExchangeRate")(exchangeRateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQrySecAgentACIDMap(object &secAgentACIDMapField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQrySecAgentACIDMap")(secAgentACIDMapField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryProductExchRate(object &productExchRateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryProductExchRate")(productExchRateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryProductGroup(object &productGroupField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryProductGroup")(productGroupField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryMMInstrumentCommissionRate(object &mMInstrumentCommissionRateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryMMInstrumentCommissionRate")(mMInstrumentCommissionRateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryMMOptionInstrCommRate(object &mMOptionInstrCommRateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryMMOptionInstrCommRate")(mMOptionInstrCommRateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryInstrumentOrderCommRate(object &instrumentOrderCommRateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryInstrumentOrderCommRate")(instrumentOrderCommRateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryOptionInstrTradeCost(object &optionInstrTradeCostField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryOptionInstrTradeCost")(optionInstrTradeCostField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryOptionInstrCommRate(object &optionInstrCommRateField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryOptionInstrCommRate")(optionInstrCommRateField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryExecOrder(object &execOrderField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryExecOrder")(execOrderField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryForQuote(object &forQuoteField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryForQuote")(forQuoteField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryQuote(object &quoteField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryQuote")(quoteField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryCombInstrumentGuard(object &combInstrumentGuardField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryCombInstrumentGuard")(combInstrumentGuardField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryCombAction(object &combActionField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryCombAction")(combActionField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryTransferSerial(object &transferSerialField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryTransferSerial")(transferSerialField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryAccountregister(object &accountregisterField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryAccountregister")(accountregisterField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspError(object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspError")(rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnOrder(object &orderField) {
        try {
            this->get_override("onRtnOrder")(orderField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnTrade(object &tradeField) {
        try {
            this->get_override("onRtnTrade")(tradeField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnOrderInsert(object &inputOrderField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnOrderInsert")(inputOrderField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnOrderAction(object &orderActionField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnOrderAction")(orderActionField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnInstrumentStatus(object &instrumentStatusField) {
        try {
            this->get_override("onRtnInstrumentStatus")(instrumentStatusField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnBulletin(object &bulletinField) {
        try {
            this->get_override("onRtnBulletin")(bulletinField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnTradingNotice(object &tradingNoticeInfoField) {
        try {
            this->get_override("onRtnTradingNotice")(tradingNoticeInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnErrorConditionalOrder(object &errorConditionalOrderField) {
        try {
            this->get_override("onRtnErrorConditionalOrder")(errorConditionalOrderField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnExecOrder(object &execOrderField) {
        try {
            this->get_override("onRtnExecOrder")(execOrderField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnExecOrderInsert(object &inputExecOrderField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnExecOrderInsert")(inputExecOrderField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnExecOrderAction(object &execOrderActionField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnExecOrderAction")(execOrderActionField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnForQuoteInsert(object &inputForQuoteField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnForQuoteInsert")(inputForQuoteField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnQuote(object &quoteField) {
        try {
            this->get_override("onRtnQuote")(quoteField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnQuoteInsert(object &inputQuoteField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnQuoteInsert")(inputQuoteField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnQuoteAction(object &quoteActionField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnQuoteAction")(quoteActionField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnForQuoteRsp(object &forQuoteRspField) {
        try {
            this->get_override("onRtnForQuoteRsp")(forQuoteRspField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnCFMMCTradingAccountToken(object &cFMMCTradingAccountTokenField) {
        try {
            this->get_override("onRtnCFMMCTradingAccountToken")(cFMMCTradingAccountTokenField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnBatchOrderAction(object &batchOrderActionField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnBatchOrderAction")(batchOrderActionField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnCombAction(object &combActionField) {
        try {
            this->get_override("onRtnCombAction")(combActionField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnCombActionInsert(object &inputCombActionField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnCombActionInsert")(inputCombActionField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryContractBank(object &contractBankField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryContractBank")(contractBankField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryParkedOrder(object &parkedOrderField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryParkedOrder")(parkedOrderField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryParkedOrderAction(object &parkedOrderActionField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryParkedOrderAction")(parkedOrderActionField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryTradingNotice(object &tradingNoticeField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryTradingNotice")(tradingNoticeField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryBrokerTradingParams(object &brokerTradingParamsField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryBrokerTradingParams")(brokerTradingParamsField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQryBrokerTradingAlgos(object &brokerTradingAlgosField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQryBrokerTradingAlgos")(brokerTradingAlgosField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQueryCFMMCTradingAccountToken(object &queryCFMMCTradingAccountTokenField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQueryCFMMCTradingAccountToken")(queryCFMMCTradingAccountTokenField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnFromBankToFutureByBank(object &rspTransferField) {
        try {
            this->get_override("onRtnFromBankToFutureByBank")(rspTransferField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnFromFutureToBankByBank(object &rspTransferField) {
        try {
            this->get_override("onRtnFromFutureToBankByBank")(rspTransferField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnRepealFromBankToFutureByBank(object &rspRepealField) {
        try {
            this->get_override("onRtnRepealFromBankToFutureByBank")(rspRepealField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnRepealFromFutureToBankByBank(object &rspRepealField) {
        try {
            this->get_override("onRtnRepealFromFutureToBankByBank")(rspRepealField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnFromBankToFutureByFuture(object &rspTransferField) {
        try {
            this->get_override("onRtnFromBankToFutureByFuture")(rspTransferField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnFromFutureToBankByFuture(object &rspTransferField) {
        try {
            this->get_override("onRtnFromFutureToBankByFuture")(rspTransferField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnRepealFromBankToFutureByFutureManual(object &rspRepealField) {
        try {
            this->get_override("onRtnRepealFromBankToFutureByFutureManual")(rspRepealField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnRepealFromFutureToBankByFutureManual(object &rspRepealField) {
        try {
            this->get_override("onRtnRepealFromFutureToBankByFutureManual")(rspRepealField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnQueryBankBalanceByFuture(object &notifyQueryAccountField) {
        try {
            this->get_override("onRtnQueryBankBalanceByFuture")(notifyQueryAccountField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnBankToFutureByFuture(object &reqTransferField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnBankToFutureByFuture")(reqTransferField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnFutureToBankByFuture(object &reqTransferField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnFutureToBankByFuture")(reqTransferField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnRepealBankToFutureByFutureManual(object &reqRepealField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnRepealBankToFutureByFutureManual")(reqRepealField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnRepealFutureToBankByFutureManual(object &reqRepealField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnRepealFutureToBankByFutureManual")(reqRepealField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onErrRtnQueryBankBalanceByFuture(object &reqQueryAccountField, object &rspInfoField) {
        try {
            this->get_override("onErrRtnQueryBankBalanceByFuture")(reqQueryAccountField, rspInfoField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnRepealFromBankToFutureByFuture(object &rspRepealField) {
        try {
            this->get_override("onRtnRepealFromBankToFutureByFuture")(rspRepealField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnRepealFromFutureToBankByFuture(object &rspRepealField) {
        try {
            this->get_override("onRtnRepealFromFutureToBankByFuture")(rspRepealField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspFromBankToFutureByFuture(object &reqTransferField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspFromBankToFutureByFuture")(reqTransferField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspFromFutureToBankByFuture(object &reqTransferField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspFromFutureToBankByFuture")(reqTransferField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspQueryBankAccountMoneyByFuture(object &reqQueryAccountField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspQueryBankAccountMoneyByFuture")(reqQueryAccountField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnOpenAccountByBank(object &openAccountField) {
        try {
            this->get_override("onRtnOpenAccountByBank")(openAccountField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnCancelAccountByBank(object &cancelAccountField) {
        try {
            this->get_override("onRtnCancelAccountByBank")(cancelAccountField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnChangeAccountByBank(object &changeAccountField) {
        try {
            this->get_override("onRtnChangeAccountByBank")(changeAccountField);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };
};



BOOST_PYTHON_MODULE(ctptd) {
    if (!PyEval_ThreadsInitialized())
        PyEval_InitThreads();	//导入时运行，保证先创建GIL

    class_<CtpTdWrap, boost::noncopyable>("CtpTd", init<const std::string &>())
            .def("onFrontConnected", pure_virtual(&CtpTdWrap::onFrontConnected))
            .def("onFrontDisconnected", pure_virtual(&CtpTdWrap::onFrontDisconnected))
            .def("onHeartBeatWarning", pure_virtual(&CtpTdWrap::onHeartBeatWarning))
            .def("onRspAuthenticate", pure_virtual(&CtpTdWrap::onRspAuthenticate))
            .def("onRspUserLogin", pure_virtual(&CtpTdWrap::onRspUserLogin))
            .def("onRspUserLogout", pure_virtual(&CtpTdWrap::onRspUserLogout))
            .def("onRspUserPasswordUpdate", pure_virtual(&CtpTdWrap::onRspUserPasswordUpdate))
            .def("onRspTradingAccountPasswordUpdate", pure_virtual(&CtpTdWrap::onRspTradingAccountPasswordUpdate))
            .def("onRspOrderInsert", pure_virtual(&CtpTdWrap::onRspOrderInsert))
            .def("onRspParkedOrderInsert", pure_virtual(&CtpTdWrap::onRspParkedOrderInsert))
            .def("onRspParkedOrderAction", pure_virtual(&CtpTdWrap::onRspParkedOrderAction))
            .def("onRspOrderAction", pure_virtual(&CtpTdWrap::onRspOrderAction))
            .def("onRspQueryMaxOrderVolume", pure_virtual(&CtpTdWrap::onRspQueryMaxOrderVolume))
            .def("onRspSettlementInfoConfirm", pure_virtual(&CtpTdWrap::onRspSettlementInfoConfirm))
            .def("onRspRemoveParkedOrder", pure_virtual(&CtpTdWrap::onRspRemoveParkedOrder))
            .def("onRspRemoveParkedOrderAction", pure_virtual(&CtpTdWrap::onRspRemoveParkedOrderAction))
            .def("onRspExecOrderInsert", pure_virtual(&CtpTdWrap::onRspExecOrderInsert))
            .def("onRspExecOrderAction", pure_virtual(&CtpTdWrap::onRspExecOrderAction))
            .def("onRspForQuoteInsert", pure_virtual(&CtpTdWrap::onRspForQuoteInsert))
            .def("onRspQuoteInsert", pure_virtual(&CtpTdWrap::onRspQuoteInsert))
            .def("onRspQuoteAction", pure_virtual(&CtpTdWrap::onRspQuoteAction))
            .def("onRspBatchOrderAction", pure_virtual(&CtpTdWrap::onRspBatchOrderAction))
            .def("onRspCombActionInsert", pure_virtual(&CtpTdWrap::onRspCombActionInsert))
            .def("onRspQryOrder", pure_virtual(&CtpTdWrap::onRspQryOrder))
            .def("onRspQryTrade", pure_virtual(&CtpTdWrap::onRspQryTrade))
            .def("onRspQryInvestorPosition", pure_virtual(&CtpTdWrap::onRspQryInvestorPosition))
            .def("onRspQryTradingAccount", pure_virtual(&CtpTdWrap::onRspQryTradingAccount))
            .def("onRspQryInvestor", pure_virtual(&CtpTdWrap::onRspQryInvestor))
            .def("onRspQryTradingCode", pure_virtual(&CtpTdWrap::onRspQryTradingCode))
            .def("onRspQryInstrumentMarginRate", pure_virtual(&CtpTdWrap::onRspQryInstrumentMarginRate))
            .def("onRspQryInstrumentCommissionRate", pure_virtual(&CtpTdWrap::onRspQryInstrumentCommissionRate))
            .def("onRspQryExchange", pure_virtual(&CtpTdWrap::onRspQryExchange))
            .def("onRspQryProduct", pure_virtual(&CtpTdWrap::onRspQryProduct))
            .def("onRspQryInstrument", pure_virtual(&CtpTdWrap::onRspQryInstrument))
            .def("onRspQryDepthMarketData", pure_virtual(&CtpTdWrap::onRspQryDepthMarketData))
            .def("onRspQrySettlementInfo", pure_virtual(&CtpTdWrap::onRspQrySettlementInfo))
            .def("onRspQryTransferBank", pure_virtual(&CtpTdWrap::onRspQryTransferBank))
            .def("onRspQryInvestorPositionDetail", pure_virtual(&CtpTdWrap::onRspQryInvestorPositionDetail))
            .def("onRspQryNotice", pure_virtual(&CtpTdWrap::onRspQryNotice))
            .def("onRspQrySettlementInfoConfirm", pure_virtual(&CtpTdWrap::onRspQrySettlementInfoConfirm))
            .def("onRspQryInvestorPositionCombineDetail", pure_virtual(&CtpTdWrap::onRspQryInvestorPositionCombineDetail))
            .def("onRspQryCFMMCTradingAccountKey", pure_virtual(&CtpTdWrap::onRspQryCFMMCTradingAccountKey))
            .def("onRspQryEWarrantOffset", pure_virtual(&CtpTdWrap::onRspQryEWarrantOffset))
            .def("onRspQryInvestorProductGroupMargin", pure_virtual(&CtpTdWrap::onRspQryInvestorProductGroupMargin))
            .def("onRspQryExchangeMarginRate", pure_virtual(&CtpTdWrap::onRspQryExchangeMarginRate))
            .def("onRspQryExchangeMarginRateAdjust", pure_virtual(&CtpTdWrap::onRspQryExchangeMarginRateAdjust))
            .def("onRspQryExchangeRate", pure_virtual(&CtpTdWrap::onRspQryExchangeRate))
            .def("onRspQrySecAgentACIDMap", pure_virtual(&CtpTdWrap::onRspQrySecAgentACIDMap))
            .def("onRspQryProductExchRate", pure_virtual(&CtpTdWrap::onRspQryProductExchRate))
            .def("onRspQryProductGroup", pure_virtual(&CtpTdWrap::onRspQryProductGroup))
            .def("onRspQryMMInstrumentCommissionRate", pure_virtual(&CtpTdWrap::onRspQryMMInstrumentCommissionRate))
            .def("onRspQryMMOptionInstrCommRate", pure_virtual(&CtpTdWrap::onRspQryMMOptionInstrCommRate))
            .def("onRspQryInstrumentOrderCommRate", pure_virtual(&CtpTdWrap::onRspQryInstrumentOrderCommRate))
            .def("onRspQryOptionInstrTradeCost", pure_virtual(&CtpTdWrap::onRspQryOptionInstrTradeCost))
            .def("onRspQryOptionInstrCommRate", pure_virtual(&CtpTdWrap::onRspQryOptionInstrCommRate))
            .def("onRspQryExecOrder", pure_virtual(&CtpTdWrap::onRspQryExecOrder))
            .def("onRspQryForQuote", pure_virtual(&CtpTdWrap::onRspQryForQuote))
            .def("onRspQryQuote", pure_virtual(&CtpTdWrap::onRspQryQuote))
            .def("onRspQryCombInstrumentGuard", pure_virtual(&CtpTdWrap::onRspQryCombInstrumentGuard))
            .def("onRspQryCombAction", pure_virtual(&CtpTdWrap::onRspQryCombAction))
            .def("onRspQryTransferSerial", pure_virtual(&CtpTdWrap::onRspQryTransferSerial))
            .def("onRspQryAccountregister", pure_virtual(&CtpTdWrap::onRspQryAccountregister))
            .def("onRspError", pure_virtual(&CtpTdWrap::onRspError))
            .def("onRtnOrder", pure_virtual(&CtpTdWrap::onRtnOrder))
            .def("onRtnTrade", pure_virtual(&CtpTdWrap::onRtnTrade))
            .def("onErrRtnOrderInsert", pure_virtual(&CtpTdWrap::onErrRtnOrderInsert))
            .def("onErrRtnOrderAction", pure_virtual(&CtpTdWrap::onErrRtnOrderAction))
            .def("onRtnInstrumentStatus", pure_virtual(&CtpTdWrap::onRtnInstrumentStatus))
            .def("onRtnBulletin", pure_virtual(&CtpTdWrap::onRtnBulletin))
            .def("onRtnTradingNotice", pure_virtual(&CtpTdWrap::onRtnTradingNotice))
            .def("onRtnErrorConditionalOrder", pure_virtual(&CtpTdWrap::onRtnErrorConditionalOrder))
            .def("onRtnExecOrder", pure_virtual(&CtpTdWrap::onRtnExecOrder))
            .def("onErrRtnExecOrderInsert", pure_virtual(&CtpTdWrap::onErrRtnExecOrderInsert))
            .def("onErrRtnExecOrderAction", pure_virtual(&CtpTdWrap::onErrRtnExecOrderAction))
            .def("onErrRtnForQuoteInsert", pure_virtual(&CtpTdWrap::onErrRtnForQuoteInsert))
            .def("onRtnQuote", pure_virtual(&CtpTdWrap::onRtnQuote))
            .def("onErrRtnQuoteInsert", pure_virtual(&CtpTdWrap::onErrRtnQuoteInsert))
            .def("onErrRtnQuoteAction", pure_virtual(&CtpTdWrap::onErrRtnQuoteAction))
            .def("onRtnForQuoteRsp", pure_virtual(&CtpTdWrap::onRtnForQuoteRsp))
            .def("onRtnCFMMCTradingAccountToken", pure_virtual(&CtpTdWrap::onRtnCFMMCTradingAccountToken))
            .def("onErrRtnBatchOrderAction", pure_virtual(&CtpTdWrap::onErrRtnBatchOrderAction))
            .def("onRtnCombAction", pure_virtual(&CtpTdWrap::onRtnCombAction))
            .def("onErrRtnCombActionInsert", pure_virtual(&CtpTdWrap::onErrRtnCombActionInsert))
            .def("onRspQryContractBank", pure_virtual(&CtpTdWrap::onRspQryContractBank))
            .def("onRspQryParkedOrder", pure_virtual(&CtpTdWrap::onRspQryParkedOrder))
            .def("onRspQryParkedOrderAction", pure_virtual(&CtpTdWrap::onRspQryParkedOrderAction))
            .def("onRspQryTradingNotice", pure_virtual(&CtpTdWrap::onRspQryTradingNotice))
            .def("onRspQryBrokerTradingParams", pure_virtual(&CtpTdWrap::onRspQryBrokerTradingParams))
            .def("onRspQryBrokerTradingAlgos", pure_virtual(&CtpTdWrap::onRspQryBrokerTradingAlgos))
            .def("onRspQueryCFMMCTradingAccountToken", pure_virtual(&CtpTdWrap::onRspQueryCFMMCTradingAccountToken))
            .def("onRtnFromBankToFutureByBank", pure_virtual(&CtpTdWrap::onRtnFromBankToFutureByBank))
            .def("onRtnFromFutureToBankByBank", pure_virtual(&CtpTdWrap::onRtnFromFutureToBankByBank))
            .def("onRtnRepealFromBankToFutureByBank", pure_virtual(&CtpTdWrap::onRtnRepealFromBankToFutureByBank))
            .def("onRtnRepealFromFutureToBankByBank", pure_virtual(&CtpTdWrap::onRtnRepealFromFutureToBankByBank))
            .def("onRtnFromBankToFutureByFuture", pure_virtual(&CtpTdWrap::onRtnFromBankToFutureByFuture))
            .def("onRtnFromFutureToBankByFuture", pure_virtual(&CtpTdWrap::onRtnFromFutureToBankByFuture))
            .def("onRtnRepealFromBankToFutureByFutureManual", pure_virtual(&CtpTdWrap::onRtnRepealFromBankToFutureByFutureManual))
            .def("onRtnRepealFromFutureToBankByFutureManual", pure_virtual(&CtpTdWrap::onRtnRepealFromFutureToBankByFutureManual))
            .def("onRtnQueryBankBalanceByFuture", pure_virtual(&CtpTdWrap::onRtnQueryBankBalanceByFuture))
            .def("onErrRtnBankToFutureByFuture", pure_virtual(&CtpTdWrap::onErrRtnBankToFutureByFuture))
            .def("onErrRtnFutureToBankByFuture", pure_virtual(&CtpTdWrap::onErrRtnFutureToBankByFuture))
            .def("onErrRtnRepealBankToFutureByFutureManual", pure_virtual(&CtpTdWrap::onErrRtnRepealBankToFutureByFutureManual))
            .def("onErrRtnRepealFutureToBankByFutureManual", pure_virtual(&CtpTdWrap::onErrRtnRepealFutureToBankByFutureManual))
            .def("onErrRtnQueryBankBalanceByFuture", pure_virtual(&CtpTdWrap::onErrRtnQueryBankBalanceByFuture))
            .def("onRtnRepealFromBankToFutureByFuture", pure_virtual(&CtpTdWrap::onRtnRepealFromBankToFutureByFuture))
            .def("onRtnRepealFromFutureToBankByFuture", pure_virtual(&CtpTdWrap::onRtnRepealFromFutureToBankByFuture))
            .def("onRspFromBankToFutureByFuture", pure_virtual(&CtpTdWrap::onRspFromBankToFutureByFuture))
            .def("onRspFromFutureToBankByFuture", pure_virtual(&CtpTdWrap::onRspFromFutureToBankByFuture))
            .def("onRspQueryBankAccountMoneyByFuture", pure_virtual(&CtpTdWrap::onRspQueryBankAccountMoneyByFuture))
            .def("onRtnOpenAccountByBank", pure_virtual(&CtpTdWrap::onRtnOpenAccountByBank))
            .def("onRtnCancelAccountByBank", pure_virtual(&CtpTdWrap::onRtnCancelAccountByBank))
            .def("onRtnChangeAccountByBank", pure_virtual(&CtpTdWrap::onRtnChangeAccountByBank))
            .def("getApiVersion", &CtpTdWrap::getApiVersion)
            .def("release", &CtpTdWrap::release)
            .def("init", &CtpTdWrap::init)
            .def("join", &CtpTdWrap::join)
            .def("getTradingDay", &CtpTdWrap::getTradingDay)
            .def("registerFront", &CtpTdWrap::registerFront)
            .def("registerNameServer", &CtpTdWrap::registerNameServer)
            .def("registerFensUserInfo", &CtpTdWrap::registerFensUserInfo)
            .def("registerSpi", &CtpTdWrap::registerSpi)
            .def("subscribePrivateTopic", &CtpTdWrap::subscribePrivateTopic)
            .def("subscribePublicTopic", &CtpTdWrap::subscribePublicTopic)
            .def("reqAuthenticate", &CtpTdWrap::reqAuthenticate)
            .def("reqUserLogin", &CtpTdWrap::reqUserLogin)
            .def("reqUserLogout", &CtpTdWrap::reqUserLogout)
            .def("reqUserPasswordUpdate", &CtpTdWrap::reqUserPasswordUpdate)
            .def("reqTradingAccountPasswordUpdate", &CtpTdWrap::reqTradingAccountPasswordUpdate)
            .def("reqOrderInsert", &CtpTdWrap::reqOrderInsert)
            .def("reqParkedOrderInsert", &CtpTdWrap::reqParkedOrderInsert)
            .def("reqParkedOrderAction", &CtpTdWrap::reqParkedOrderAction)
            .def("reqOrderAction", &CtpTdWrap::reqOrderAction)
            .def("reqQueryMaxOrderVolume", &CtpTdWrap::reqQueryMaxOrderVolume)
            .def("reqSettlementInfoConfirm", &CtpTdWrap::reqSettlementInfoConfirm)
            .def("reqRemoveParkedOrder", &CtpTdWrap::reqRemoveParkedOrder)
            .def("reqRemoveParkedOrderAction", &CtpTdWrap::reqRemoveParkedOrderAction)
            .def("reqExecOrderInsert", &CtpTdWrap::reqExecOrderInsert)
            .def("reqExecOrderAction", &CtpTdWrap::reqExecOrderAction)
            .def("reqForQuoteInsert", &CtpTdWrap::reqForQuoteInsert)
            .def("reqQuoteInsert", &CtpTdWrap::reqQuoteInsert)
            .def("reqQuoteAction", &CtpTdWrap::reqQuoteAction)
            .def("reqBatchOrderAction", &CtpTdWrap::reqBatchOrderAction)
            .def("reqCombActionInsert", &CtpTdWrap::reqCombActionInsert)
            .def("reqQryOrder", &CtpTdWrap::reqQryOrder)
            .def("reqQryTrade", &CtpTdWrap::reqQryTrade)
            .def("reqQryInvestorPosition", &CtpTdWrap::reqQryInvestorPosition)
            .def("reqQryTradingAccount", &CtpTdWrap::reqQryTradingAccount)
            .def("reqQryInvestor", &CtpTdWrap::reqQryInvestor)
            .def("reqQryTradingCode", &CtpTdWrap::reqQryTradingCode)
            .def("reqQryInstrumentMarginRate", &CtpTdWrap::reqQryInstrumentMarginRate)
            .def("reqQryInstrumentCommissionRate", &CtpTdWrap::reqQryInstrumentCommissionRate)
            .def("reqQryExchange", &CtpTdWrap::reqQryExchange)
            .def("reqQryProduct", &CtpTdWrap::reqQryProduct)
            .def("reqQryInstrument", &CtpTdWrap::reqQryInstrument)
            .def("reqQryDepthMarketData", &CtpTdWrap::reqQryDepthMarketData)
            .def("reqQrySettlementInfo", &CtpTdWrap::reqQrySettlementInfo)
            .def("reqQryTransferBank", &CtpTdWrap::reqQryTransferBank)
            .def("reqQryInvestorPositionDetail", &CtpTdWrap::reqQryInvestorPositionDetail)
            .def("reqQryNotice", &CtpTdWrap::reqQryNotice)
            .def("reqQrySettlementInfoConfirm", &CtpTdWrap::reqQrySettlementInfoConfirm)
            .def("reqQryInvestorPositionCombineDetail", &CtpTdWrap::reqQryInvestorPositionCombineDetail)
            .def("reqQryCFMMCTradingAccountKey", &CtpTdWrap::reqQryCFMMCTradingAccountKey)
            .def("reqQryEWarrantOffset", &CtpTdWrap::reqQryEWarrantOffset)
            .def("reqQryInvestorProductGroupMargin", &CtpTdWrap::reqQryInvestorProductGroupMargin)
            .def("reqQryExchangeMarginRate", &CtpTdWrap::reqQryExchangeMarginRate)
            .def("reqQryExchangeMarginRateAdjust", &CtpTdWrap::reqQryExchangeMarginRateAdjust)
            .def("reqQryExchangeRate", &CtpTdWrap::reqQryExchangeRate)
            .def("reqQrySecAgentACIDMap", &CtpTdWrap::reqQrySecAgentACIDMap)
            .def("reqQryProductExchRate", &CtpTdWrap::reqQryProductExchRate)
            .def("reqQryProductGroup", &CtpTdWrap::reqQryProductGroup)
            .def("reqQryMMInstrumentCommissionRate", &CtpTdWrap::reqQryMMInstrumentCommissionRate)
            .def("reqQryMMOptionInstrCommRate", &CtpTdWrap::reqQryMMOptionInstrCommRate)
            .def("reqQryInstrumentOrderCommRate", &CtpTdWrap::reqQryInstrumentOrderCommRate)
            .def("reqQryOptionInstrTradeCost", &CtpTdWrap::reqQryOptionInstrTradeCost)
            .def("reqQryOptionInstrCommRate", &CtpTdWrap::reqQryOptionInstrCommRate)
            .def("reqQryExecOrder", &CtpTdWrap::reqQryExecOrder)
            .def("reqQryForQuote", &CtpTdWrap::reqQryForQuote)
            .def("reqQryQuote", &CtpTdWrap::reqQryQuote)
            .def("reqQryCombInstrumentGuard", &CtpTdWrap::reqQryCombInstrumentGuard)
            .def("reqQryCombAction", &CtpTdWrap::reqQryCombAction)
            .def("reqQryTransferSerial", &CtpTdWrap::reqQryTransferSerial)
            .def("reqQryAccountregister", &CtpTdWrap::reqQryAccountregister)
            .def("reqQryContractBank", &CtpTdWrap::reqQryContractBank)
            .def("reqQryParkedOrder", &CtpTdWrap::reqQryParkedOrder)
            .def("reqQryParkedOrderAction", &CtpTdWrap::reqQryParkedOrderAction)
            .def("reqQryTradingNotice", &CtpTdWrap::reqQryTradingNotice)
            .def("reqQryBrokerTradingParams", &CtpTdWrap::reqQryBrokerTradingParams)
            .def("reqQryBrokerTradingAlgos", &CtpTdWrap::reqQryBrokerTradingAlgos)
            .def("reqQueryCFMMCTradingAccountToken", &CtpTdWrap::reqQueryCFMMCTradingAccountToken)
            .def("reqFromBankToFutureByFuture", &CtpTdWrap::reqFromBankToFutureByFuture)
            .def("reqFromFutureToBankByFuture", &CtpTdWrap::reqFromFutureToBankByFuture)
            .def("reqQueryBankAccountMoneyByFuture", &CtpTdWrap::reqQueryBankAccountMoneyByFuture);

    enum_<THOST_TE_RESUME_TYPE>("tert")
        .value("restart", THOST_TERT_RESTART)
        .value("resume", THOST_TERT_RESUME)
        .value("quick", THOST_TERT_QUICK);

    class_<ReqUserLoginField>("ReqUserLoginField")
            .add_property("tradingDay", &ReqUserLoginField::getTradingDay, &ReqUserLoginField::setTradingDay)
            .add_property("brokerID", &ReqUserLoginField::getBrokerID, &ReqUserLoginField::setBrokerID)
            .add_property("userID", &ReqUserLoginField::getUserID, &ReqUserLoginField::setUserID)
            .add_property("password", &ReqUserLoginField::getPassword, &ReqUserLoginField::setPassword)
            .add_property("userProductInfo", &ReqUserLoginField::getUserProductInfo, &ReqUserLoginField::setUserProductInfo)
            .add_property("interfaceProductInfo", &ReqUserLoginField::getInterfaceProductInfo, &ReqUserLoginField::setInterfaceProductInfo)
            .add_property("protocolInfo", &ReqUserLoginField::getProtocolInfo, &ReqUserLoginField::setProtocolInfo)
            .add_property("macAddress", &ReqUserLoginField::getMacAddress, &ReqUserLoginField::setMacAddress)
            .add_property("oneTimePassword", &ReqUserLoginField::getOneTimePassword, &ReqUserLoginField::setOneTimePassword)
            .add_property("clientIPAddress", &ReqUserLoginField::getClientIPAddress, &ReqUserLoginField::setClientIPAddress)
            .add_property("loginRemark", &ReqUserLoginField::getLoginRemark, &ReqUserLoginField::setLoginRemark);

    class_<RspUserLoginField>("RspUserLoginField")
            .add_property("tradingDay", &RspUserLoginField::getTradingDay, &RspUserLoginField::setTradingDay)
            .add_property("loginTime", &RspUserLoginField::getLoginTime, &RspUserLoginField::setLoginTime)
            .add_property("brokerID", &RspUserLoginField::getBrokerID, &RspUserLoginField::setBrokerID)
            .add_property("userID", &RspUserLoginField::getUserID, &RspUserLoginField::setUserID)
            .add_property("systemName", &RspUserLoginField::getSystemName, &RspUserLoginField::setSystemName)
            .def_readwrite("frontID", &RspUserLoginField::FrontID)
            .def_readwrite("sessionID", &RspUserLoginField::SessionID)
            .add_property("maxOrderRef", &RspUserLoginField::getMaxOrderRef, &RspUserLoginField::setMaxOrderRef)
            .add_property("SHFETime", &RspUserLoginField::getSHFETime, &RspUserLoginField::setSHFETime)
            .add_property("DCETime", &RspUserLoginField::getDCETime, &RspUserLoginField::setDCETime)
            .add_property("CZCETime", &RspUserLoginField::getCZCETime, &RspUserLoginField::setCZCETime)
            .add_property("FFEXTime", &RspUserLoginField::getFFEXTime, &RspUserLoginField::setFFEXTime)
            .add_property("INETime", &RspUserLoginField::getINETime, &RspUserLoginField::setINETime);

    class_<UserLogoutField>("UserLogoutField")
            .add_property("brokerID", &UserLogoutField::getBrokerID, &UserLogoutField::setBrokerID)
            .add_property("userID", &UserLogoutField::getUserID, &UserLogoutField::setUserID);

    class_<ReqAuthenticateField>("ReqAuthenticateField")
            .add_property("brokerID", &ReqAuthenticateField::getBrokerID, &ReqAuthenticateField::setBrokerID)
            .add_property("userID", &ReqAuthenticateField::getUserID, &ReqAuthenticateField::setUserID)
            .add_property("userProductInfo", &ReqAuthenticateField::getUserProductInfo, &ReqAuthenticateField::setUserProductInfo)
            .add_property("authCode", &ReqAuthenticateField::getAuthCode, &ReqAuthenticateField::setAuthCode);

    class_<RspAuthenticateField>("RspAuthenticateField")
            .add_property("brokerID", &RspAuthenticateField::getBrokerID, &RspAuthenticateField::setBrokerID)
            .add_property("userID", &RspAuthenticateField::getUserID, &RspAuthenticateField::setUserID)
            .add_property("userProductInfo", &RspAuthenticateField::getUserProductInfo, &RspAuthenticateField::setUserProductInfo);

    class_<RspInfoField>("RspInfoField")
            .def_readwrite("errorID", &RspInfoField::ErrorID)
            .add_property("errorMsg", &RspInfoField::getErrorMsg, &RspInfoField::setErrorMsg);

    class_<ExchangeField>("ExchangeField")
            .add_property("exchangeID", &ExchangeField::getExchangeID, &ExchangeField::setExchangeID)
            .add_property("exchangeName", &ExchangeField::getExchangeName, &ExchangeField::setExchangeName)
            .def_readwrite("exchangeProperty", &ExchangeField::ExchangeProperty);

    class_<ProductField>("ProductField")
            .add_property("productID", &ProductField::getProductID, &ProductField::setProductID)
            .add_property("productName", &ProductField::getProductName, &ProductField::setProductName)
            .add_property("exchangeID", &ProductField::getExchangeID, &ProductField::setExchangeID)
            .def_readwrite("productClass", &ProductField::ProductClass)
            .def_readwrite("volumeMultiple", &ProductField::VolumeMultiple)
            .def_readwrite("priceTick", &ProductField::PriceTick)
            .def_readwrite("maxMarketOrderVolume", &ProductField::MaxMarketOrderVolume)
            .def_readwrite("minMarketOrderVolume", &ProductField::MinMarketOrderVolume)
            .def_readwrite("maxLimitOrderVolume", &ProductField::MaxLimitOrderVolume)
            .def_readwrite("minLimitOrderVolume", &ProductField::MinLimitOrderVolume)
            .def_readwrite("positionType", &ProductField::PositionType)
            .def_readwrite("positionDateType", &ProductField::PositionDateType)
            .def_readwrite("closeDealType", &ProductField::CloseDealType)
            .add_property("tradeCurrencyID", &ProductField::getTradeCurrencyID, &ProductField::setTradeCurrencyID)
            .def_readwrite("mortgageFundUseRange", &ProductField::MortgageFundUseRange)
            .add_property("exchangeProductID", &ProductField::getExchangeProductID, &ProductField::setExchangeProductID)
            .def_readwrite("underlyingMultiple", &ProductField::UnderlyingMultiple);

    class_<InstrumentField>("InstrumentField")
            .add_property("instrumentID", &InstrumentField::getInstrumentID, &InstrumentField::setInstrumentID)
            .add_property("exchangeID", &InstrumentField::getExchangeID, &InstrumentField::setExchangeID)
            .add_property("instrumentName", &InstrumentField::getInstrumentName, &InstrumentField::setInstrumentName)
            .add_property("exchangeInstID", &InstrumentField::getExchangeInstID, &InstrumentField::setExchangeInstID)
            .add_property("productID", &InstrumentField::getProductID, &InstrumentField::setProductID)
            .def_readwrite("productClass", &InstrumentField::ProductClass)
            .def_readwrite("deliveryYear", &InstrumentField::DeliveryYear)
            .def_readwrite("deliveryMonth", &InstrumentField::DeliveryMonth)
            .def_readwrite("maxMarketOrderVolume", &InstrumentField::MaxMarketOrderVolume)
            .def_readwrite("minMarketOrderVolume", &InstrumentField::MinMarketOrderVolume)
            .def_readwrite("maxLimitOrderVolume", &InstrumentField::MaxLimitOrderVolume)
            .def_readwrite("minLimitOrderVolume", &InstrumentField::MinLimitOrderVolume)
            .def_readwrite("volumeMultiple", &InstrumentField::VolumeMultiple)
            .def_readwrite("priceTick", &InstrumentField::PriceTick)
            .add_property("createDate", &InstrumentField::getCreateDate, &InstrumentField::setCreateDate)
            .add_property("openDate", &InstrumentField::getOpenDate, &InstrumentField::setOpenDate)
            .add_property("expireDate", &InstrumentField::getExpireDate, &InstrumentField::setExpireDate)
            .add_property("startDelivDate", &InstrumentField::getStartDelivDate, &InstrumentField::setStartDelivDate)
            .add_property("endDelivDate", &InstrumentField::getEndDelivDate, &InstrumentField::setEndDelivDate)
            .def_readwrite("instLifePhase", &InstrumentField::InstLifePhase)
            .def_readwrite("isTrading", &InstrumentField::IsTrading)
            .def_readwrite("positionType", &InstrumentField::PositionType)
            .def_readwrite("positionDateType", &InstrumentField::PositionDateType)
            .def_readwrite("longMarginRatio", &InstrumentField::LongMarginRatio)
            .def_readwrite("shortMarginRatio", &InstrumentField::ShortMarginRatio)
            .def_readwrite("maxMarginSideAlgorithm", &InstrumentField::MaxMarginSideAlgorithm)
            .add_property("underlyingInstrID", &InstrumentField::getUnderlyingInstrID, &InstrumentField::setUnderlyingInstrID)
            .def_readwrite("strikePrice", &InstrumentField::StrikePrice)
            .def_readwrite("optionsType", &InstrumentField::OptionsType)
            .def_readwrite("underlyingMultiple", &InstrumentField::UnderlyingMultiple)
            .def_readwrite("combinationType", &InstrumentField::CombinationType);

    class_<InvestorField>("InvestorField")
            .add_property("investorID", &InvestorField::getInvestorID, &InvestorField::setInvestorID)
            .add_property("brokerID", &InvestorField::getBrokerID, &InvestorField::setBrokerID)
            .add_property("investorGroupID", &InvestorField::getInvestorGroupID, &InvestorField::setInvestorGroupID)
            .add_property("investorName", &InvestorField::getInvestorName, &InvestorField::setInvestorName)
            .def_readwrite("identifiedCardType", &InvestorField::IdentifiedCardType)
            .add_property("identifiedCardNo", &InvestorField::getIdentifiedCardNo, &InvestorField::setIdentifiedCardNo)
            .def_readwrite("isActive", &InvestorField::IsActive)
            .add_property("telephone", &InvestorField::getTelephone, &InvestorField::setTelephone)
            .add_property("address", &InvestorField::getAddress, &InvestorField::setAddress)
            .add_property("openDate", &InvestorField::getOpenDate, &InvestorField::setOpenDate)
            .add_property("mobile", &InvestorField::getMobile, &InvestorField::setMobile)
            .add_property("commModelID", &InvestorField::getCommModelID, &InvestorField::setCommModelID)
            .add_property("marginModelID", &InvestorField::getMarginModelID, &InvestorField::setMarginModelID);

    class_<TradingCodeField>("TradingCodeField")
            .add_property("investorID", &TradingCodeField::getInvestorID, &TradingCodeField::setInvestorID)
            .add_property("brokerID", &TradingCodeField::getBrokerID, &TradingCodeField::setBrokerID)
            .add_property("exchangeID", &TradingCodeField::getExchangeID, &TradingCodeField::setExchangeID)
            .add_property("clientID", &TradingCodeField::getClientID, &TradingCodeField::setClientID)
            .def_readwrite("isActive", &TradingCodeField::IsActive)
            .def_readwrite("clientIDType", &TradingCodeField::ClientIDType);

    class_<TradingAccountField>("TradingAccountField")
            .add_property("brokerID", &TradingAccountField::getBrokerID, &TradingAccountField::setBrokerID)
            .add_property("accountID", &TradingAccountField::getAccountID, &TradingAccountField::setAccountID)
            .def_readwrite("preMortgage", &TradingAccountField::PreMortgage)
            .def_readwrite("preCredit", &TradingAccountField::PreCredit)
            .def_readwrite("preDeposit", &TradingAccountField::PreDeposit)
            .def_readwrite("preBalance", &TradingAccountField::PreBalance)
            .def_readwrite("preMargin", &TradingAccountField::PreMargin)
            .def_readwrite("interestBase", &TradingAccountField::InterestBase)
            .def_readwrite("interest", &TradingAccountField::Interest)
            .def_readwrite("deposit", &TradingAccountField::Deposit)
            .def_readwrite("withdraw", &TradingAccountField::Withdraw)
            .def_readwrite("frozenMargin", &TradingAccountField::FrozenMargin)
            .def_readwrite("frozenCash", &TradingAccountField::FrozenCash)
            .def_readwrite("frozenCommission", &TradingAccountField::FrozenCommission)
            .def_readwrite("currMargin", &TradingAccountField::CurrMargin)
            .def_readwrite("cashIn", &TradingAccountField::CashIn)
            .def_readwrite("commission", &TradingAccountField::Commission)
            .def_readwrite("closeProfit", &TradingAccountField::CloseProfit)
            .def_readwrite("positionProfit", &TradingAccountField::PositionProfit)
            .def_readwrite("balance", &TradingAccountField::Balance)
            .def_readwrite("available", &TradingAccountField::Available)
            .def_readwrite("withdrawQuota", &TradingAccountField::WithdrawQuota)
            .def_readwrite("reserve", &TradingAccountField::Reserve)
            .add_property("tradingDay", &TradingAccountField::getTradingDay, &TradingAccountField::setTradingDay)
            .def_readwrite("settlementID", &TradingAccountField::SettlementID)
            .def_readwrite("credit", &TradingAccountField::Credit)
            .def_readwrite("mortgage", &TradingAccountField::Mortgage)
            .def_readwrite("exchangeMargin", &TradingAccountField::ExchangeMargin)
            .def_readwrite("deliveryMargin", &TradingAccountField::DeliveryMargin)
            .def_readwrite("exchangeDeliveryMargin", &TradingAccountField::ExchangeDeliveryMargin)
            .def_readwrite("reserveBalance", &TradingAccountField::ReserveBalance)
            .add_property("currencyID", &TradingAccountField::getCurrencyID, &TradingAccountField::setCurrencyID)
            .def_readwrite("preFundMortgageIn", &TradingAccountField::PreFundMortgageIn)
            .def_readwrite("preFundMortgageOut", &TradingAccountField::PreFundMortgageOut)
            .def_readwrite("fundMortgageIn", &TradingAccountField::FundMortgageIn)
            .def_readwrite("fundMortgageOut", &TradingAccountField::FundMortgageOut)
            .def_readwrite("fundMortgageAvailable", &TradingAccountField::FundMortgageAvailable)
            .def_readwrite("mortgageableFund", &TradingAccountField::MortgageableFund)
            .def_readwrite("specProductMargin", &TradingAccountField::SpecProductMargin)
            .def_readwrite("specProductFrozenMargin", &TradingAccountField::SpecProductFrozenMargin)
            .def_readwrite("specProductCommission", &TradingAccountField::SpecProductCommission)
            .def_readwrite("specProductFrozenCommission", &TradingAccountField::SpecProductFrozenCommission)
            .def_readwrite("specProductPositionProfit", &TradingAccountField::SpecProductPositionProfit)
            .def_readwrite("specProductCloseProfit", &TradingAccountField::SpecProductCloseProfit)
            .def_readwrite("specProductPositionProfitByAlg", &TradingAccountField::SpecProductPositionProfitByAlg)
            .def_readwrite("specProductExchangeMargin", &TradingAccountField::SpecProductExchangeMargin);

    class_<InvestorPositionField>("InvestorPositionField")
            .add_property("instrumentID", &InvestorPositionField::getInstrumentID, &InvestorPositionField::setInstrumentID)
            .add_property("brokerID", &InvestorPositionField::getBrokerID, &InvestorPositionField::setBrokerID)
            .add_property("investorID", &InvestorPositionField::getInvestorID, &InvestorPositionField::setInvestorID)
            .def_readwrite("posiDirection", &InvestorPositionField::PosiDirection)
            .def_readwrite("hedgeFlag", &InvestorPositionField::HedgeFlag)
            .def_readwrite("positionDate", &InvestorPositionField::PositionDate)
            .def_readwrite("ydPosition", &InvestorPositionField::YdPosition)
            .def_readwrite("position", &InvestorPositionField::Position)
            .def_readwrite("longFrozen", &InvestorPositionField::LongFrozen)
            .def_readwrite("shortFrozen", &InvestorPositionField::ShortFrozen)
            .def_readwrite("longFrozenAmount", &InvestorPositionField::LongFrozenAmount)
            .def_readwrite("shortFrozenAmount", &InvestorPositionField::ShortFrozenAmount)
            .def_readwrite("openVolume", &InvestorPositionField::OpenVolume)
            .def_readwrite("closeVolume", &InvestorPositionField::CloseVolume)
            .def_readwrite("openAmount", &InvestorPositionField::OpenAmount)
            .def_readwrite("closeAmount", &InvestorPositionField::CloseAmount)
            .def_readwrite("positionCost", &InvestorPositionField::PositionCost)
            .def_readwrite("preMargin", &InvestorPositionField::PreMargin)
            .def_readwrite("useMargin", &InvestorPositionField::UseMargin)
            .def_readwrite("frozenMargin", &InvestorPositionField::FrozenMargin)
            .def_readwrite("frozenCash", &InvestorPositionField::FrozenCash)
            .def_readwrite("frozenCommission", &InvestorPositionField::FrozenCommission)
            .def_readwrite("cashIn", &InvestorPositionField::CashIn)
            .def_readwrite("commission", &InvestorPositionField::Commission)
            .def_readwrite("closeProfit", &InvestorPositionField::CloseProfit)
            .def_readwrite("positionProfit", &InvestorPositionField::PositionProfit)
            .def_readwrite("preSettlementPrice", &InvestorPositionField::PreSettlementPrice)
            .def_readwrite("settlementPrice", &InvestorPositionField::SettlementPrice)
            .add_property("tradingDay", &InvestorPositionField::getTradingDay, &InvestorPositionField::setTradingDay)
            .def_readwrite("settlementID", &InvestorPositionField::SettlementID)
            .def_readwrite("openCost", &InvestorPositionField::OpenCost)
            .def_readwrite("exchangeMargin", &InvestorPositionField::ExchangeMargin)
            .def_readwrite("combPosition", &InvestorPositionField::CombPosition)
            .def_readwrite("combLongFrozen", &InvestorPositionField::CombLongFrozen)
            .def_readwrite("combShortFrozen", &InvestorPositionField::CombShortFrozen)
            .def_readwrite("closeProfitByDate", &InvestorPositionField::CloseProfitByDate)
            .def_readwrite("closeProfitByTrade", &InvestorPositionField::CloseProfitByTrade)
            .def_readwrite("todayPosition", &InvestorPositionField::TodayPosition)
            .def_readwrite("marginRateByMoney", &InvestorPositionField::MarginRateByMoney)
            .def_readwrite("marginRateByVolume", &InvestorPositionField::MarginRateByVolume)
            .def_readwrite("strikeFrozen", &InvestorPositionField::StrikeFrozen)
            .def_readwrite("strikeFrozenAmount", &InvestorPositionField::StrikeFrozenAmount)
            .def_readwrite("abandonFrozen", &InvestorPositionField::AbandonFrozen);

    class_<InstrumentMarginRateField>("InstrumentMarginRateField")
            .add_property("instrumentID", &InstrumentMarginRateField::getInstrumentID, &InstrumentMarginRateField::setInstrumentID)
            .def_readwrite("investorRange", &InstrumentMarginRateField::InvestorRange)
            .add_property("brokerID", &InstrumentMarginRateField::getBrokerID, &InstrumentMarginRateField::setBrokerID)
            .add_property("investorID", &InstrumentMarginRateField::getInvestorID, &InstrumentMarginRateField::setInvestorID)
            .def_readwrite("hedgeFlag", &InstrumentMarginRateField::HedgeFlag)
            .def_readwrite("longMarginRatioByMoney", &InstrumentMarginRateField::LongMarginRatioByMoney)
            .def_readwrite("longMarginRatioByVolume", &InstrumentMarginRateField::LongMarginRatioByVolume)
            .def_readwrite("shortMarginRatioByMoney", &InstrumentMarginRateField::ShortMarginRatioByMoney)
            .def_readwrite("shortMarginRatioByVolume", &InstrumentMarginRateField::ShortMarginRatioByVolume)
            .def_readwrite("isRelative", &InstrumentMarginRateField::IsRelative);

    class_<InstrumentCommissionRateField>("InstrumentCommissionRateField")
            .add_property("instrumentID", &InstrumentCommissionRateField::getInstrumentID, &InstrumentCommissionRateField::setInstrumentID)
            .def_readwrite("investorRange", &InstrumentCommissionRateField::InvestorRange)
            .add_property("brokerID", &InstrumentCommissionRateField::getBrokerID, &InstrumentCommissionRateField::setBrokerID)
            .add_property("investorID", &InstrumentCommissionRateField::getInvestorID, &InstrumentCommissionRateField::setInvestorID)
            .def_readwrite("openRatioByMoney", &InstrumentCommissionRateField::OpenRatioByMoney)
            .def_readwrite("openRatioByVolume", &InstrumentCommissionRateField::OpenRatioByVolume)
            .def_readwrite("closeRatioByMoney", &InstrumentCommissionRateField::CloseRatioByMoney)
            .def_readwrite("closeRatioByVolume", &InstrumentCommissionRateField::CloseRatioByVolume)
            .def_readwrite("closeTodayRatioByMoney", &InstrumentCommissionRateField::CloseTodayRatioByMoney)
            .def_readwrite("closeTodayRatioByVolume", &InstrumentCommissionRateField::CloseTodayRatioByVolume);

    class_<DepthMarketDataField>("DepthMarketDataField")
            .add_property("tradingDay", &DepthMarketDataField::getTradingDay, &DepthMarketDataField::setTradingDay)
            .add_property("instrumentID", &DepthMarketDataField::getInstrumentID, &DepthMarketDataField::setInstrumentID)
            .add_property("exchangeID", &DepthMarketDataField::getExchangeID, &DepthMarketDataField::setExchangeID)
            .add_property("exchangeInstID", &DepthMarketDataField::getExchangeInstID, &DepthMarketDataField::setExchangeInstID)
            .def_readwrite("lastPrice", &DepthMarketDataField::LastPrice)
            .def_readwrite("preSettlementPrice", &DepthMarketDataField::PreSettlementPrice)
            .def_readwrite("preClosePrice", &DepthMarketDataField::PreClosePrice)
            .def_readwrite("preOpenInterest", &DepthMarketDataField::PreOpenInterest)
            .def_readwrite("openPrice", &DepthMarketDataField::OpenPrice)
            .def_readwrite("highestPrice", &DepthMarketDataField::HighestPrice)
            .def_readwrite("lowestPrice", &DepthMarketDataField::LowestPrice)
            .def_readwrite("volume", &DepthMarketDataField::Volume)
            .def_readwrite("turnover", &DepthMarketDataField::Turnover)
            .def_readwrite("openInterest", &DepthMarketDataField::OpenInterest)
            .def_readwrite("closePrice", &DepthMarketDataField::ClosePrice)
            .def_readwrite("settlementPrice", &DepthMarketDataField::SettlementPrice)
            .def_readwrite("upperLimitPrice", &DepthMarketDataField::UpperLimitPrice)
            .def_readwrite("lowerLimitPrice", &DepthMarketDataField::LowerLimitPrice)
            .def_readwrite("preDelta", &DepthMarketDataField::PreDelta)
            .def_readwrite("currDelta", &DepthMarketDataField::CurrDelta)
            .add_property("updateTime", &DepthMarketDataField::getUpdateTime, &DepthMarketDataField::setUpdateTime)
            .def_readwrite("updateMillisec", &DepthMarketDataField::UpdateMillisec)
            .def_readwrite("bidPrice1", &DepthMarketDataField::BidPrice1)
            .def_readwrite("bidVolume1", &DepthMarketDataField::BidVolume1)
            .def_readwrite("askPrice1", &DepthMarketDataField::AskPrice1)
            .def_readwrite("askVolume1", &DepthMarketDataField::AskVolume1)
            .def_readwrite("bidPrice2", &DepthMarketDataField::BidPrice2)
            .def_readwrite("bidVolume2", &DepthMarketDataField::BidVolume2)
            .def_readwrite("askPrice2", &DepthMarketDataField::AskPrice2)
            .def_readwrite("askVolume2", &DepthMarketDataField::AskVolume2)
            .def_readwrite("bidPrice3", &DepthMarketDataField::BidPrice3)
            .def_readwrite("bidVolume3", &DepthMarketDataField::BidVolume3)
            .def_readwrite("askPrice3", &DepthMarketDataField::AskPrice3)
            .def_readwrite("askVolume3", &DepthMarketDataField::AskVolume3)
            .def_readwrite("bidPrice4", &DepthMarketDataField::BidPrice4)
            .def_readwrite("bidVolume4", &DepthMarketDataField::BidVolume4)
            .def_readwrite("askPrice4", &DepthMarketDataField::AskPrice4)
            .def_readwrite("askVolume4", &DepthMarketDataField::AskVolume4)
            .def_readwrite("bidPrice5", &DepthMarketDataField::BidPrice5)
            .def_readwrite("bidVolume5", &DepthMarketDataField::BidVolume5)
            .def_readwrite("askPrice5", &DepthMarketDataField::AskPrice5)
            .def_readwrite("askVolume5", &DepthMarketDataField::AskVolume5)
            .def_readwrite("averagePrice", &DepthMarketDataField::AveragePrice)
            .add_property("actionDay", &DepthMarketDataField::getActionDay, &DepthMarketDataField::setActionDay);

    class_<SettlementInfoField>("SettlementInfoField")
            .add_property("tradingDay", &SettlementInfoField::getTradingDay, &SettlementInfoField::setTradingDay)
            .def_readwrite("settlementID", &SettlementInfoField::SettlementID)
            .add_property("brokerID", &SettlementInfoField::getBrokerID, &SettlementInfoField::setBrokerID)
            .add_property("investorID", &SettlementInfoField::getInvestorID, &SettlementInfoField::setInvestorID)
            .def_readwrite("sequenceNo", &SettlementInfoField::SequenceNo)
            .add_property("content", &SettlementInfoField::getContent, &SettlementInfoField::setContent);

    class_<ExchangeMarginRateField>("ExchangeMarginRateField")
            .add_property("brokerID", &ExchangeMarginRateField::getBrokerID, &ExchangeMarginRateField::setBrokerID)
            .add_property("instrumentID", &ExchangeMarginRateField::getInstrumentID, &ExchangeMarginRateField::setInstrumentID)
            .def_readwrite("hedgeFlag", &ExchangeMarginRateField::HedgeFlag)
            .def_readwrite("longMarginRatioByMoney", &ExchangeMarginRateField::LongMarginRatioByMoney)
            .def_readwrite("longMarginRatioByVolume", &ExchangeMarginRateField::LongMarginRatioByVolume)
            .def_readwrite("shortMarginRatioByMoney", &ExchangeMarginRateField::ShortMarginRatioByMoney)
            .def_readwrite("shortMarginRatioByVolume", &ExchangeMarginRateField::ShortMarginRatioByVolume);

    class_<ExchangeMarginRateAdjustField>("ExchangeMarginRateAdjustField")
            .add_property("brokerID", &ExchangeMarginRateAdjustField::getBrokerID, &ExchangeMarginRateAdjustField::setBrokerID)
            .add_property("instrumentID", &ExchangeMarginRateAdjustField::getInstrumentID, &ExchangeMarginRateAdjustField::setInstrumentID)
            .def_readwrite("hedgeFlag", &ExchangeMarginRateAdjustField::HedgeFlag)
            .def_readwrite("longMarginRatioByMoney", &ExchangeMarginRateAdjustField::LongMarginRatioByMoney)
            .def_readwrite("longMarginRatioByVolume", &ExchangeMarginRateAdjustField::LongMarginRatioByVolume)
            .def_readwrite("shortMarginRatioByMoney", &ExchangeMarginRateAdjustField::ShortMarginRatioByMoney)
            .def_readwrite("shortMarginRatioByVolume", &ExchangeMarginRateAdjustField::ShortMarginRatioByVolume)
            .def_readwrite("exchLongMarginRatioByMoney", &ExchangeMarginRateAdjustField::ExchLongMarginRatioByMoney)
            .def_readwrite("exchLongMarginRatioByVolume", &ExchangeMarginRateAdjustField::ExchLongMarginRatioByVolume)
            .def_readwrite("exchShortMarginRatioByMoney", &ExchangeMarginRateAdjustField::ExchShortMarginRatioByMoney)
            .def_readwrite("exchShortMarginRatioByVolume", &ExchangeMarginRateAdjustField::ExchShortMarginRatioByVolume)
            .def_readwrite("noLongMarginRatioByMoney", &ExchangeMarginRateAdjustField::NoLongMarginRatioByMoney)
            .def_readwrite("noLongMarginRatioByVolume", &ExchangeMarginRateAdjustField::NoLongMarginRatioByVolume)
            .def_readwrite("noShortMarginRatioByMoney", &ExchangeMarginRateAdjustField::NoShortMarginRatioByMoney)
            .def_readwrite("noShortMarginRatioByVolume", &ExchangeMarginRateAdjustField::NoShortMarginRatioByVolume);

    class_<ExchangeRateField>("ExchangeRateField")
            .add_property("brokerID", &ExchangeRateField::getBrokerID, &ExchangeRateField::setBrokerID)
            .add_property("fromCurrencyID", &ExchangeRateField::getFromCurrencyID, &ExchangeRateField::setFromCurrencyID)
            .def_readwrite("fromCurrencyUnit", &ExchangeRateField::FromCurrencyUnit)
            .add_property("toCurrencyID", &ExchangeRateField::getToCurrencyID, &ExchangeRateField::setToCurrencyID)
            .def_readwrite("exchangeRate", &ExchangeRateField::ExchangeRate);

    class_<UserPasswordUpdateField>("UserPasswordUpdateField")
            .add_property("brokerID", &UserPasswordUpdateField::getBrokerID, &UserPasswordUpdateField::setBrokerID)
            .add_property("userID", &UserPasswordUpdateField::getUserID, &UserPasswordUpdateField::setUserID)
            .add_property("oldPassword", &UserPasswordUpdateField::getOldPassword, &UserPasswordUpdateField::setOldPassword)
            .add_property("newPassword", &UserPasswordUpdateField::getNewPassword, &UserPasswordUpdateField::setNewPassword);

    class_<InputOrderField>("InputOrderField")
            .add_property("brokerID", &InputOrderField::getBrokerID, &InputOrderField::setBrokerID)
            .add_property("investorID", &InputOrderField::getInvestorID, &InputOrderField::setInvestorID)
            .add_property("instrumentID", &InputOrderField::getInstrumentID, &InputOrderField::setInstrumentID)
            .add_property("orderRef", &InputOrderField::getOrderRef, &InputOrderField::setOrderRef)
            .add_property("userID", &InputOrderField::getUserID, &InputOrderField::setUserID)
            .def_readwrite("orderPriceType", &InputOrderField::OrderPriceType)
            .def_readwrite("direction", &InputOrderField::Direction)
            .add_property("combOffsetFlag", &InputOrderField::getCombOffsetFlag, &InputOrderField::setCombOffsetFlag)
            .add_property("combHedgeFlag", &InputOrderField::getCombHedgeFlag, &InputOrderField::setCombHedgeFlag)
            .def_readwrite("limitPrice", &InputOrderField::LimitPrice)
            .def_readwrite("volumeTotalOriginal", &InputOrderField::VolumeTotalOriginal)
            .def_readwrite("timeCondition", &InputOrderField::TimeCondition)
            .add_property("GTDDate", &InputOrderField::getGTDDate, &InputOrderField::setGTDDate)
            .def_readwrite("volumeCondition", &InputOrderField::VolumeCondition)
            .def_readwrite("minVolume", &InputOrderField::MinVolume)
            .def_readwrite("contingentCondition", &InputOrderField::ContingentCondition)
            .def_readwrite("stopPrice", &InputOrderField::StopPrice)
            .def_readwrite("forceCloseReason", &InputOrderField::ForceCloseReason)
            .def_readwrite("isAutoSuspend", &InputOrderField::IsAutoSuspend)
            .add_property("businessUnit", &InputOrderField::getBusinessUnit, &InputOrderField::setBusinessUnit)
            .def_readwrite("requestID", &InputOrderField::RequestID)
            .def_readwrite("userForceClose", &InputOrderField::UserForceClose)
            .def_readwrite("isSwapOrder", &InputOrderField::IsSwapOrder)
            .add_property("exchangeID", &InputOrderField::getExchangeID, &InputOrderField::setExchangeID)
            .add_property("investUnitID", &InputOrderField::getInvestUnitID, &InputOrderField::setInvestUnitID)
            .add_property("accountID", &InputOrderField::getAccountID, &InputOrderField::setAccountID)
            .add_property("currencyID", &InputOrderField::getCurrencyID, &InputOrderField::setCurrencyID)
            .add_property("clientID", &InputOrderField::getClientID, &InputOrderField::setClientID)
            .add_property("IPAddress", &InputOrderField::getIPAddress, &InputOrderField::setIPAddress)
            .add_property("macAddress", &InputOrderField::getMacAddress, &InputOrderField::setMacAddress);

    class_<OrderField>("OrderField")
            .add_property("brokerID", &OrderField::getBrokerID, &OrderField::setBrokerID)
            .add_property("investorID", &OrderField::getInvestorID, &OrderField::setInvestorID)
            .add_property("instrumentID", &OrderField::getInstrumentID, &OrderField::setInstrumentID)
            .add_property("orderRef", &OrderField::getOrderRef, &OrderField::setOrderRef)
            .add_property("userID", &OrderField::getUserID, &OrderField::setUserID)
            .def_readwrite("orderPriceType", &OrderField::OrderPriceType)
            .def_readwrite("direction", &OrderField::Direction)
            .add_property("combOffsetFlag", &OrderField::getCombOffsetFlag, &OrderField::setCombOffsetFlag)
            .add_property("combHedgeFlag", &OrderField::getCombHedgeFlag, &OrderField::setCombHedgeFlag)
            .def_readwrite("limitPrice", &OrderField::LimitPrice)
            .def_readwrite("volumeTotalOriginal", &OrderField::VolumeTotalOriginal)
            .def_readwrite("timeCondition", &OrderField::TimeCondition)
            .add_property("GTDDate", &OrderField::getGTDDate, &OrderField::setGTDDate)
            .def_readwrite("volumeCondition", &OrderField::VolumeCondition)
            .def_readwrite("minVolume", &OrderField::MinVolume)
            .def_readwrite("contingentCondition", &OrderField::ContingentCondition)
            .def_readwrite("stopPrice", &OrderField::StopPrice)
            .def_readwrite("forceCloseReason", &OrderField::ForceCloseReason)
            .def_readwrite("isAutoSuspend", &OrderField::IsAutoSuspend)
            .add_property("businessUnit", &OrderField::getBusinessUnit, &OrderField::setBusinessUnit)
            .def_readwrite("requestID", &OrderField::RequestID)
            .add_property("orderLocalID", &OrderField::getOrderLocalID, &OrderField::setOrderLocalID)
            .add_property("exchangeID", &OrderField::getExchangeID, &OrderField::setExchangeID)
            .add_property("participantID", &OrderField::getParticipantID, &OrderField::setParticipantID)
            .add_property("clientID", &OrderField::getClientID, &OrderField::setClientID)
            .add_property("exchangeInstID", &OrderField::getExchangeInstID, &OrderField::setExchangeInstID)
            .add_property("traderID", &OrderField::getTraderID, &OrderField::setTraderID)
            .def_readwrite("installID", &OrderField::InstallID)
            .def_readwrite("orderSubmitStatus", &OrderField::OrderSubmitStatus)
            .def_readwrite("notifySequence", &OrderField::NotifySequence)
            .add_property("tradingDay", &OrderField::getTradingDay, &OrderField::setTradingDay)
            .def_readwrite("settlementID", &OrderField::SettlementID)
            .add_property("orderSysID", &OrderField::getOrderSysID, &OrderField::setOrderSysID)
            .def_readwrite("orderSource", &OrderField::OrderSource)
            .def_readwrite("orderStatus", &OrderField::OrderStatus)
            .def_readwrite("orderType", &OrderField::OrderType)
            .def_readwrite("volumeTraded", &OrderField::VolumeTraded)
            .def_readwrite("volumeTotal", &OrderField::VolumeTotal)
            .add_property("insertDate", &OrderField::getInsertDate, &OrderField::setInsertDate)
            .add_property("insertTime", &OrderField::getInsertTime, &OrderField::setInsertTime)
            .add_property("activeTime", &OrderField::getActiveTime, &OrderField::setActiveTime)
            .add_property("suspendTime", &OrderField::getSuspendTime, &OrderField::setSuspendTime)
            .add_property("updateTime", &OrderField::getUpdateTime, &OrderField::setUpdateTime)
            .add_property("cancelTime", &OrderField::getCancelTime, &OrderField::setCancelTime)
            .add_property("activeTraderID", &OrderField::getActiveTraderID, &OrderField::setActiveTraderID)
            .add_property("clearingPartID", &OrderField::getClearingPartID, &OrderField::setClearingPartID)
            .def_readwrite("sequenceNo", &OrderField::SequenceNo)
            .def_readwrite("frontID", &OrderField::FrontID)
            .def_readwrite("sessionID", &OrderField::SessionID)
            .add_property("userProductInfo", &OrderField::getUserProductInfo, &OrderField::setUserProductInfo)
            .add_property("statusMsg", &OrderField::getStatusMsg, &OrderField::setStatusMsg)
            .def_readwrite("userForceClose", &OrderField::UserForceClose)
            .add_property("activeUserID", &OrderField::getActiveUserID, &OrderField::setActiveUserID)
            .def_readwrite("brokerOrderSeq", &OrderField::BrokerOrderSeq)
            .add_property("relativeOrderSysID", &OrderField::getRelativeOrderSysID, &OrderField::setRelativeOrderSysID)
            .def_readwrite("ZCETotalTradedVolume", &OrderField::ZCETotalTradedVolume)
            .def_readwrite("isSwapOrder", &OrderField::IsSwapOrder)
            .add_property("branchID", &OrderField::getBranchID, &OrderField::setBranchID)
            .add_property("investUnitID", &OrderField::getInvestUnitID, &OrderField::setInvestUnitID)
            .add_property("accountID", &OrderField::getAccountID, &OrderField::setAccountID)
            .add_property("currencyID", &OrderField::getCurrencyID, &OrderField::setCurrencyID)
            .add_property("IPAddress", &OrderField::getIPAddress, &OrderField::setIPAddress)
            .add_property("macAddress", &OrderField::getMacAddress, &OrderField::setMacAddress);

    class_<InputOrderActionField>("InputOrderActionField")
            .add_property("brokerID", &InputOrderActionField::getBrokerID, &InputOrderActionField::setBrokerID)
            .add_property("investorID", &InputOrderActionField::getInvestorID, &InputOrderActionField::setInvestorID)
            .def_readwrite("orderActionRef", &InputOrderActionField::OrderActionRef)
            .add_property("orderRef", &InputOrderActionField::getOrderRef, &InputOrderActionField::setOrderRef)
            .def_readwrite("requestID", &InputOrderActionField::RequestID)
            .def_readwrite("frontID", &InputOrderActionField::FrontID)
            .def_readwrite("sessionID", &InputOrderActionField::SessionID)
            .add_property("exchangeID", &InputOrderActionField::getExchangeID, &InputOrderActionField::setExchangeID)
            .add_property("orderSysID", &InputOrderActionField::getOrderSysID, &InputOrderActionField::setOrderSysID)
            .def_readwrite("actionFlag", &InputOrderActionField::ActionFlag)
            .def_readwrite("limitPrice", &InputOrderActionField::LimitPrice)
            .def_readwrite("volumeChange", &InputOrderActionField::VolumeChange)
            .add_property("userID", &InputOrderActionField::getUserID, &InputOrderActionField::setUserID)
            .add_property("instrumentID", &InputOrderActionField::getInstrumentID, &InputOrderActionField::setInstrumentID)
            .add_property("investUnitID", &InputOrderActionField::getInvestUnitID, &InputOrderActionField::setInvestUnitID)
            .add_property("IPAddress", &InputOrderActionField::getIPAddress, &InputOrderActionField::setIPAddress)
            .add_property("macAddress", &InputOrderActionField::getMacAddress, &InputOrderActionField::setMacAddress);

    class_<OrderActionField>("OrderActionField")
            .add_property("brokerID", &OrderActionField::getBrokerID, &OrderActionField::setBrokerID)
            .add_property("investorID", &OrderActionField::getInvestorID, &OrderActionField::setInvestorID)
            .def_readwrite("orderActionRef", &OrderActionField::OrderActionRef)
            .add_property("orderRef", &OrderActionField::getOrderRef, &OrderActionField::setOrderRef)
            .def_readwrite("requestID", &OrderActionField::RequestID)
            .def_readwrite("frontID", &OrderActionField::FrontID)
            .def_readwrite("sessionID", &OrderActionField::SessionID)
            .add_property("exchangeID", &OrderActionField::getExchangeID, &OrderActionField::setExchangeID)
            .add_property("orderSysID", &OrderActionField::getOrderSysID, &OrderActionField::setOrderSysID)
            .def_readwrite("actionFlag", &OrderActionField::ActionFlag)
            .def_readwrite("limitPrice", &OrderActionField::LimitPrice)
            .def_readwrite("volumeChange", &OrderActionField::VolumeChange)
            .add_property("actionDate", &OrderActionField::getActionDate, &OrderActionField::setActionDate)
            .add_property("actionTime", &OrderActionField::getActionTime, &OrderActionField::setActionTime)
            .add_property("traderID", &OrderActionField::getTraderID, &OrderActionField::setTraderID)
            .def_readwrite("installID", &OrderActionField::InstallID)
            .add_property("orderLocalID", &OrderActionField::getOrderLocalID, &OrderActionField::setOrderLocalID)
            .add_property("actionLocalID", &OrderActionField::getActionLocalID, &OrderActionField::setActionLocalID)
            .add_property("participantID", &OrderActionField::getParticipantID, &OrderActionField::setParticipantID)
            .add_property("clientID", &OrderActionField::getClientID, &OrderActionField::setClientID)
            .add_property("businessUnit", &OrderActionField::getBusinessUnit, &OrderActionField::setBusinessUnit)
            .def_readwrite("orderActionStatus", &OrderActionField::OrderActionStatus)
            .add_property("userID", &OrderActionField::getUserID, &OrderActionField::setUserID)
            .add_property("statusMsg", &OrderActionField::getStatusMsg, &OrderActionField::setStatusMsg)
            .add_property("instrumentID", &OrderActionField::getInstrumentID, &OrderActionField::setInstrumentID)
            .add_property("branchID", &OrderActionField::getBranchID, &OrderActionField::setBranchID)
            .add_property("investUnitID", &OrderActionField::getInvestUnitID, &OrderActionField::setInvestUnitID)
            .add_property("IPAddress", &OrderActionField::getIPAddress, &OrderActionField::setIPAddress)
            .add_property("macAddress", &OrderActionField::getMacAddress, &OrderActionField::setMacAddress);

    class_<TradeField>("TradeField")
            .add_property("brokerID", &TradeField::getBrokerID, &TradeField::setBrokerID)
            .add_property("investorID", &TradeField::getInvestorID, &TradeField::setInvestorID)
            .add_property("instrumentID", &TradeField::getInstrumentID, &TradeField::setInstrumentID)
            .add_property("orderRef", &TradeField::getOrderRef, &TradeField::setOrderRef)
            .add_property("userID", &TradeField::getUserID, &TradeField::setUserID)
            .add_property("exchangeID", &TradeField::getExchangeID, &TradeField::setExchangeID)
            .add_property("tradeID", &TradeField::getTradeID, &TradeField::setTradeID)
            .def_readwrite("direction", &TradeField::Direction)
            .add_property("orderSysID", &TradeField::getOrderSysID, &TradeField::setOrderSysID)
            .add_property("participantID", &TradeField::getParticipantID, &TradeField::setParticipantID)
            .add_property("clientID", &TradeField::getClientID, &TradeField::setClientID)
            .def_readwrite("tradingRole", &TradeField::TradingRole)
            .add_property("exchangeInstID", &TradeField::getExchangeInstID, &TradeField::setExchangeInstID)
            .def_readwrite("offsetFlag", &TradeField::OffsetFlag)
            .def_readwrite("hedgeFlag", &TradeField::HedgeFlag)
            .def_readwrite("price", &TradeField::Price)
            .def_readwrite("volume", &TradeField::Volume)
            .add_property("tradeDate", &TradeField::getTradeDate, &TradeField::setTradeDate)
            .add_property("tradeTime", &TradeField::getTradeTime, &TradeField::setTradeTime)
            .def_readwrite("tradeType", &TradeField::TradeType)
            .def_readwrite("priceSource", &TradeField::PriceSource)
            .add_property("traderID", &TradeField::getTraderID, &TradeField::setTraderID)
            .add_property("orderLocalID", &TradeField::getOrderLocalID, &TradeField::setOrderLocalID)
            .add_property("clearingPartID", &TradeField::getClearingPartID, &TradeField::setClearingPartID)
            .add_property("businessUnit", &TradeField::getBusinessUnit, &TradeField::setBusinessUnit)
            .def_readwrite("sequenceNo", &TradeField::SequenceNo)
            .add_property("tradingDay", &TradeField::getTradingDay, &TradeField::setTradingDay)
            .def_readwrite("settlementID", &TradeField::SettlementID)
            .def_readwrite("brokerOrderSeq", &TradeField::BrokerOrderSeq)
            .def_readwrite("tradeSource", &TradeField::TradeSource);

    class_<QueryMaxOrderVolumeField>("QueryMaxOrderVolumeField")
            .add_property("brokerID", &QueryMaxOrderVolumeField::getBrokerID, &QueryMaxOrderVolumeField::setBrokerID)
            .add_property("investorID", &QueryMaxOrderVolumeField::getInvestorID, &QueryMaxOrderVolumeField::setInvestorID)
            .add_property("instrumentID", &QueryMaxOrderVolumeField::getInstrumentID, &QueryMaxOrderVolumeField::setInstrumentID)
            .def_readwrite("direction", &QueryMaxOrderVolumeField::Direction)
            .def_readwrite("offsetFlag", &QueryMaxOrderVolumeField::OffsetFlag)
            .def_readwrite("hedgeFlag", &QueryMaxOrderVolumeField::HedgeFlag)
            .def_readwrite("maxVolume", &QueryMaxOrderVolumeField::MaxVolume);

    class_<SettlementInfoConfirmField>("SettlementInfoConfirmField")
            .add_property("brokerID", &SettlementInfoConfirmField::getBrokerID, &SettlementInfoConfirmField::setBrokerID)
            .add_property("investorID", &SettlementInfoConfirmField::getInvestorID, &SettlementInfoConfirmField::setInvestorID)
            .add_property("confirmDate", &SettlementInfoConfirmField::getConfirmDate, &SettlementInfoConfirmField::setConfirmDate)
            .add_property("confirmTime", &SettlementInfoConfirmField::getConfirmTime, &SettlementInfoConfirmField::setConfirmTime);

    class_<QryOrderField>("QryOrderField")
            .add_property("brokerID", &QryOrderField::getBrokerID, &QryOrderField::setBrokerID)
            .add_property("investorID", &QryOrderField::getInvestorID, &QryOrderField::setInvestorID)
            .add_property("instrumentID", &QryOrderField::getInstrumentID, &QryOrderField::setInstrumentID)
            .add_property("exchangeID", &QryOrderField::getExchangeID, &QryOrderField::setExchangeID)
            .add_property("orderSysID", &QryOrderField::getOrderSysID, &QryOrderField::setOrderSysID)
            .add_property("insertTimeStart", &QryOrderField::getInsertTimeStart, &QryOrderField::setInsertTimeStart)
            .add_property("insertTimeEnd", &QryOrderField::getInsertTimeEnd, &QryOrderField::setInsertTimeEnd);

    class_<QryTradeField>("QryTradeField")
            .add_property("brokerID", &QryTradeField::getBrokerID, &QryTradeField::setBrokerID)
            .add_property("investorID", &QryTradeField::getInvestorID, &QryTradeField::setInvestorID)
            .add_property("instrumentID", &QryTradeField::getInstrumentID, &QryTradeField::setInstrumentID)
            .add_property("exchangeID", &QryTradeField::getExchangeID, &QryTradeField::setExchangeID)
            .add_property("tradeID", &QryTradeField::getTradeID, &QryTradeField::setTradeID)
            .add_property("tradeTimeStart", &QryTradeField::getTradeTimeStart, &QryTradeField::setTradeTimeStart)
            .add_property("tradeTimeEnd", &QryTradeField::getTradeTimeEnd, &QryTradeField::setTradeTimeEnd);

    class_<QryInvestorPositionField>("QryInvestorPositionField")
            .add_property("brokerID", &QryInvestorPositionField::getBrokerID, &QryInvestorPositionField::setBrokerID)
            .add_property("investorID", &QryInvestorPositionField::getInvestorID, &QryInvestorPositionField::setInvestorID)
            .add_property("instrumentID", &QryInvestorPositionField::getInstrumentID, &QryInvestorPositionField::setInstrumentID);

    class_<QryTradingAccountField>("QryTradingAccountField")
            .add_property("brokerID", &QryTradingAccountField::getBrokerID, &QryTradingAccountField::setBrokerID)
            .add_property("investorID", &QryTradingAccountField::getInvestorID, &QryTradingAccountField::setInvestorID)
            .add_property("currencyID", &QryTradingAccountField::getCurrencyID, &QryTradingAccountField::setCurrencyID);

    class_<QryInvestorField>("QryInvestorField")
            .add_property("brokerID", &QryInvestorField::getBrokerID, &QryInvestorField::setBrokerID)
            .add_property("investorID", &QryInvestorField::getInvestorID, &QryInvestorField::setInvestorID);

    class_<QryTradingCodeField>("QryTradingCodeField")
            .add_property("brokerID", &QryTradingCodeField::getBrokerID, &QryTradingCodeField::setBrokerID)
            .add_property("investorID", &QryTradingCodeField::getInvestorID, &QryTradingCodeField::setInvestorID)
            .add_property("exchangeID", &QryTradingCodeField::getExchangeID, &QryTradingCodeField::setExchangeID)
            .add_property("clientID", &QryTradingCodeField::getClientID, &QryTradingCodeField::setClientID)
            .def_readwrite("clientIDType", &QryTradingCodeField::ClientIDType);

    class_<QryInstrumentMarginRateField>("QryInstrumentMarginRateField")
            .add_property("brokerID", &QryInstrumentMarginRateField::getBrokerID, &QryInstrumentMarginRateField::setBrokerID)
            .add_property("investorID", &QryInstrumentMarginRateField::getInvestorID, &QryInstrumentMarginRateField::setInvestorID)
            .add_property("instrumentID", &QryInstrumentMarginRateField::getInstrumentID, &QryInstrumentMarginRateField::setInstrumentID)
            .def_readwrite("hedgeFlag", &QryInstrumentMarginRateField::HedgeFlag);

    class_<QryInstrumentCommissionRateField>("QryInstrumentCommissionRateField")
            .add_property("brokerID", &QryInstrumentCommissionRateField::getBrokerID, &QryInstrumentCommissionRateField::setBrokerID)
            .add_property("investorID", &QryInstrumentCommissionRateField::getInvestorID, &QryInstrumentCommissionRateField::setInvestorID)
            .add_property("instrumentID", &QryInstrumentCommissionRateField::getInstrumentID, &QryInstrumentCommissionRateField::setInstrumentID);

    class_<QryExchangeField>("QryExchangeField")
            .add_property("exchangeID", &QryExchangeField::getExchangeID, &QryExchangeField::setExchangeID);

    class_<QryProductField>("QryProductField")
            .add_property("productID", &QryProductField::getProductID, &QryProductField::setProductID)
            .def_readwrite("productClass", &QryProductField::ProductClass);

    class_<QryInstrumentField>("QryInstrumentField")
            .add_property("instrumentID", &QryInstrumentField::getInstrumentID, &QryInstrumentField::setInstrumentID)
            .add_property("exchangeID", &QryInstrumentField::getExchangeID, &QryInstrumentField::setExchangeID)
            .add_property("exchangeInstID", &QryInstrumentField::getExchangeInstID, &QryInstrumentField::setExchangeInstID)
            .add_property("productID", &QryInstrumentField::getProductID, &QryInstrumentField::setProductID);

    class_<QryDepthMarketDataField>("QryDepthMarketDataField")
            .add_property("instrumentID", &QryDepthMarketDataField::getInstrumentID, &QryDepthMarketDataField::setInstrumentID);

    class_<QrySettlementInfoField>("QrySettlementInfoField")
            .add_property("brokerID", &QrySettlementInfoField::getBrokerID, &QrySettlementInfoField::setBrokerID)
            .add_property("investorID", &QrySettlementInfoField::getInvestorID, &QrySettlementInfoField::setInvestorID)
            .add_property("tradingDay", &QrySettlementInfoField::getTradingDay, &QrySettlementInfoField::setTradingDay);

    class_<QryExchangeMarginRateField>("QryExchangeMarginRateField")
            .add_property("brokerID", &QryExchangeMarginRateField::getBrokerID, &QryExchangeMarginRateField::setBrokerID)
            .add_property("instrumentID", &QryExchangeMarginRateField::getInstrumentID, &QryExchangeMarginRateField::setInstrumentID)
            .def_readwrite("hedgeFlag", &QryExchangeMarginRateField::HedgeFlag);

    class_<QryExchangeMarginRateAdjustField>("QryExchangeMarginRateAdjustField")
            .add_property("brokerID", &QryExchangeMarginRateAdjustField::getBrokerID, &QryExchangeMarginRateAdjustField::setBrokerID)
            .add_property("instrumentID", &QryExchangeMarginRateAdjustField::getInstrumentID, &QryExchangeMarginRateAdjustField::setInstrumentID)
            .def_readwrite("hedgeFlag", &QryExchangeMarginRateAdjustField::HedgeFlag);

    class_<QryExchangeRateField>("QryExchangeRateField")
            .add_property("brokerID", &QryExchangeRateField::getBrokerID, &QryExchangeRateField::setBrokerID)
            .add_property("fromCurrencyID", &QryExchangeRateField::getFromCurrencyID, &QryExchangeRateField::setFromCurrencyID)
            .add_property("toCurrencyID", &QryExchangeRateField::getToCurrencyID, &QryExchangeRateField::setToCurrencyID);

    class_<OptionInstrCommRateField>("OptionInstrCommRateField")
            .add_property("instrumentID", &OptionInstrCommRateField::getInstrumentID, &OptionInstrCommRateField::setInstrumentID)
            .def_readwrite("investorRange", &OptionInstrCommRateField::InvestorRange)
            .add_property("brokerID", &OptionInstrCommRateField::getBrokerID, &OptionInstrCommRateField::setBrokerID)
            .add_property("investorID", &OptionInstrCommRateField::getInvestorID, &OptionInstrCommRateField::setInvestorID)
            .def_readwrite("openRatioByMoney", &OptionInstrCommRateField::OpenRatioByMoney)
            .def_readwrite("openRatioByVolume", &OptionInstrCommRateField::OpenRatioByVolume)
            .def_readwrite("closeRatioByMoney", &OptionInstrCommRateField::CloseRatioByMoney)
            .def_readwrite("closeRatioByVolume", &OptionInstrCommRateField::CloseRatioByVolume)
            .def_readwrite("closeTodayRatioByMoney", &OptionInstrCommRateField::CloseTodayRatioByMoney)
            .def_readwrite("closeTodayRatioByVolume", &OptionInstrCommRateField::CloseTodayRatioByVolume)
            .def_readwrite("strikeRatioByMoney", &OptionInstrCommRateField::StrikeRatioByMoney)
            .def_readwrite("strikeRatioByVolume", &OptionInstrCommRateField::StrikeRatioByVolume);

    class_<OptionInstrTradeCostField>("OptionInstrTradeCostField")
            .add_property("brokerID", &OptionInstrTradeCostField::getBrokerID, &OptionInstrTradeCostField::setBrokerID)
            .add_property("investorID", &OptionInstrTradeCostField::getInvestorID, &OptionInstrTradeCostField::setInvestorID)
            .add_property("instrumentID", &OptionInstrTradeCostField::getInstrumentID, &OptionInstrTradeCostField::setInstrumentID)
            .def_readwrite("hedgeFlag", &OptionInstrTradeCostField::HedgeFlag)
            .def_readwrite("fixedMargin", &OptionInstrTradeCostField::FixedMargin)
            .def_readwrite("miniMargin", &OptionInstrTradeCostField::MiniMargin)
            .def_readwrite("royalty", &OptionInstrTradeCostField::Royalty)
            .def_readwrite("exchFixedMargin", &OptionInstrTradeCostField::ExchFixedMargin)
            .def_readwrite("exchMiniMargin", &OptionInstrTradeCostField::ExchMiniMargin);

    class_<QryOptionInstrTradeCostField>("QryOptionInstrTradeCostField")
            .add_property("brokerID", &QryOptionInstrTradeCostField::getBrokerID, &QryOptionInstrTradeCostField::setBrokerID)
            .add_property("investorID", &QryOptionInstrTradeCostField::getInvestorID, &QryOptionInstrTradeCostField::setInvestorID)
            .add_property("instrumentID", &QryOptionInstrTradeCostField::getInstrumentID, &QryOptionInstrTradeCostField::setInstrumentID)
            .def_readwrite("hedgeFlag", &QryOptionInstrTradeCostField::HedgeFlag)
            .def_readwrite("inputPrice", &QryOptionInstrTradeCostField::InputPrice)
            .def_readwrite("underlyingPrice", &QryOptionInstrTradeCostField::UnderlyingPrice);

    class_<QryOptionInstrCommRateField>("QryOptionInstrCommRateField")
            .add_property("brokerID", &QryOptionInstrCommRateField::getBrokerID, &QryOptionInstrCommRateField::setBrokerID)
            .add_property("investorID", &QryOptionInstrCommRateField::getInvestorID, &QryOptionInstrCommRateField::setInvestorID)
            .add_property("instrumentID", &QryOptionInstrCommRateField::getInstrumentID, &QryOptionInstrCommRateField::setInstrumentID);

    class_<InputExecOrderField>("InputExecOrderField")
            .add_property("brokerID", &InputExecOrderField::getBrokerID, &InputExecOrderField::setBrokerID)
            .add_property("investorID", &InputExecOrderField::getInvestorID, &InputExecOrderField::setInvestorID)
            .add_property("instrumentID", &InputExecOrderField::getInstrumentID, &InputExecOrderField::setInstrumentID)
            .add_property("execOrderRef", &InputExecOrderField::getExecOrderRef, &InputExecOrderField::setExecOrderRef)
            .add_property("userID", &InputExecOrderField::getUserID, &InputExecOrderField::setUserID)
            .def_readwrite("volume", &InputExecOrderField::Volume)
            .def_readwrite("requestID", &InputExecOrderField::RequestID)
            .add_property("businessUnit", &InputExecOrderField::getBusinessUnit, &InputExecOrderField::setBusinessUnit)
            .def_readwrite("offsetFlag", &InputExecOrderField::OffsetFlag)
            .def_readwrite("hedgeFlag", &InputExecOrderField::HedgeFlag)
            .def_readwrite("actionType", &InputExecOrderField::ActionType)
            .def_readwrite("posiDirection", &InputExecOrderField::PosiDirection)
            .def_readwrite("reservePositionFlag", &InputExecOrderField::ReservePositionFlag)
            .def_readwrite("closeFlag", &InputExecOrderField::CloseFlag)
            .add_property("exchangeID", &InputExecOrderField::getExchangeID, &InputExecOrderField::setExchangeID)
            .add_property("investUnitID", &InputExecOrderField::getInvestUnitID, &InputExecOrderField::setInvestUnitID)
            .add_property("accountID", &InputExecOrderField::getAccountID, &InputExecOrderField::setAccountID)
            .add_property("currencyID", &InputExecOrderField::getCurrencyID, &InputExecOrderField::setCurrencyID)
            .add_property("clientID", &InputExecOrderField::getClientID, &InputExecOrderField::setClientID)
            .add_property("IPAddress", &InputExecOrderField::getIPAddress, &InputExecOrderField::setIPAddress)
            .add_property("macAddress", &InputExecOrderField::getMacAddress, &InputExecOrderField::setMacAddress);

    class_<InputExecOrderActionField>("InputExecOrderActionField")
            .add_property("brokerID", &InputExecOrderActionField::getBrokerID, &InputExecOrderActionField::setBrokerID)
            .add_property("investorID", &InputExecOrderActionField::getInvestorID, &InputExecOrderActionField::setInvestorID)
            .def_readwrite("execOrderActionRef", &InputExecOrderActionField::ExecOrderActionRef)
            .add_property("execOrderRef", &InputExecOrderActionField::getExecOrderRef, &InputExecOrderActionField::setExecOrderRef)
            .def_readwrite("requestID", &InputExecOrderActionField::RequestID)
            .def_readwrite("frontID", &InputExecOrderActionField::FrontID)
            .def_readwrite("sessionID", &InputExecOrderActionField::SessionID)
            .add_property("exchangeID", &InputExecOrderActionField::getExchangeID, &InputExecOrderActionField::setExchangeID)
            .add_property("execOrderSysID", &InputExecOrderActionField::getExecOrderSysID, &InputExecOrderActionField::setExecOrderSysID)
            .def_readwrite("actionFlag", &InputExecOrderActionField::ActionFlag)
            .add_property("userID", &InputExecOrderActionField::getUserID, &InputExecOrderActionField::setUserID)
            .add_property("instrumentID", &InputExecOrderActionField::getInstrumentID, &InputExecOrderActionField::setInstrumentID)
            .add_property("investUnitID", &InputExecOrderActionField::getInvestUnitID, &InputExecOrderActionField::setInvestUnitID)
            .add_property("IPAddress", &InputExecOrderActionField::getIPAddress, &InputExecOrderActionField::setIPAddress)
            .add_property("macAddress", &InputExecOrderActionField::getMacAddress, &InputExecOrderActionField::setMacAddress);

    class_<ExecOrderField>("ExecOrderField")
            .add_property("brokerID", &ExecOrderField::getBrokerID, &ExecOrderField::setBrokerID)
            .add_property("investorID", &ExecOrderField::getInvestorID, &ExecOrderField::setInvestorID)
            .add_property("instrumentID", &ExecOrderField::getInstrumentID, &ExecOrderField::setInstrumentID)
            .add_property("execOrderRef", &ExecOrderField::getExecOrderRef, &ExecOrderField::setExecOrderRef)
            .add_property("userID", &ExecOrderField::getUserID, &ExecOrderField::setUserID)
            .def_readwrite("volume", &ExecOrderField::Volume)
            .def_readwrite("requestID", &ExecOrderField::RequestID)
            .add_property("businessUnit", &ExecOrderField::getBusinessUnit, &ExecOrderField::setBusinessUnit)
            .def_readwrite("offsetFlag", &ExecOrderField::OffsetFlag)
            .def_readwrite("hedgeFlag", &ExecOrderField::HedgeFlag)
            .def_readwrite("actionType", &ExecOrderField::ActionType)
            .def_readwrite("posiDirection", &ExecOrderField::PosiDirection)
            .def_readwrite("reservePositionFlag", &ExecOrderField::ReservePositionFlag)
            .def_readwrite("closeFlag", &ExecOrderField::CloseFlag)
            .add_property("execOrderLocalID", &ExecOrderField::getExecOrderLocalID, &ExecOrderField::setExecOrderLocalID)
            .add_property("exchangeID", &ExecOrderField::getExchangeID, &ExecOrderField::setExchangeID)
            .add_property("participantID", &ExecOrderField::getParticipantID, &ExecOrderField::setParticipantID)
            .add_property("clientID", &ExecOrderField::getClientID, &ExecOrderField::setClientID)
            .add_property("exchangeInstID", &ExecOrderField::getExchangeInstID, &ExecOrderField::setExchangeInstID)
            .add_property("traderID", &ExecOrderField::getTraderID, &ExecOrderField::setTraderID)
            .def_readwrite("installID", &ExecOrderField::InstallID)
            .def_readwrite("orderSubmitStatus", &ExecOrderField::OrderSubmitStatus)
            .def_readwrite("notifySequence", &ExecOrderField::NotifySequence)
            .add_property("tradingDay", &ExecOrderField::getTradingDay, &ExecOrderField::setTradingDay)
            .def_readwrite("settlementID", &ExecOrderField::SettlementID)
            .add_property("execOrderSysID", &ExecOrderField::getExecOrderSysID, &ExecOrderField::setExecOrderSysID)
            .add_property("insertDate", &ExecOrderField::getInsertDate, &ExecOrderField::setInsertDate)
            .add_property("insertTime", &ExecOrderField::getInsertTime, &ExecOrderField::setInsertTime)
            .add_property("cancelTime", &ExecOrderField::getCancelTime, &ExecOrderField::setCancelTime)
            .def_readwrite("execResult", &ExecOrderField::ExecResult)
            .add_property("clearingPartID", &ExecOrderField::getClearingPartID, &ExecOrderField::setClearingPartID)
            .def_readwrite("sequenceNo", &ExecOrderField::SequenceNo)
            .def_readwrite("frontID", &ExecOrderField::FrontID)
            .def_readwrite("sessionID", &ExecOrderField::SessionID)
            .add_property("userProductInfo", &ExecOrderField::getUserProductInfo, &ExecOrderField::setUserProductInfo)
            .add_property("statusMsg", &ExecOrderField::getStatusMsg, &ExecOrderField::setStatusMsg)
            .add_property("activeUserID", &ExecOrderField::getActiveUserID, &ExecOrderField::setActiveUserID)
            .def_readwrite("brokerExecOrderSeq", &ExecOrderField::BrokerExecOrderSeq)
            .add_property("branchID", &ExecOrderField::getBranchID, &ExecOrderField::setBranchID)
            .add_property("investUnitID", &ExecOrderField::getInvestUnitID, &ExecOrderField::setInvestUnitID)
            .add_property("accountID", &ExecOrderField::getAccountID, &ExecOrderField::setAccountID)
            .add_property("currencyID", &ExecOrderField::getCurrencyID, &ExecOrderField::setCurrencyID)
            .add_property("IPAddress", &ExecOrderField::getIPAddress, &ExecOrderField::setIPAddress)
            .add_property("macAddress", &ExecOrderField::getMacAddress, &ExecOrderField::setMacAddress);

    class_<ExecOrderActionField>("ExecOrderActionField")
            .add_property("brokerID", &ExecOrderActionField::getBrokerID, &ExecOrderActionField::setBrokerID)
            .add_property("investorID", &ExecOrderActionField::getInvestorID, &ExecOrderActionField::setInvestorID)
            .def_readwrite("execOrderActionRef", &ExecOrderActionField::ExecOrderActionRef)
            .add_property("execOrderRef", &ExecOrderActionField::getExecOrderRef, &ExecOrderActionField::setExecOrderRef)
            .def_readwrite("requestID", &ExecOrderActionField::RequestID)
            .def_readwrite("frontID", &ExecOrderActionField::FrontID)
            .def_readwrite("sessionID", &ExecOrderActionField::SessionID)
            .add_property("exchangeID", &ExecOrderActionField::getExchangeID, &ExecOrderActionField::setExchangeID)
            .add_property("execOrderSysID", &ExecOrderActionField::getExecOrderSysID, &ExecOrderActionField::setExecOrderSysID)
            .def_readwrite("actionFlag", &ExecOrderActionField::ActionFlag)
            .add_property("actionDate", &ExecOrderActionField::getActionDate, &ExecOrderActionField::setActionDate)
            .add_property("actionTime", &ExecOrderActionField::getActionTime, &ExecOrderActionField::setActionTime)
            .add_property("traderID", &ExecOrderActionField::getTraderID, &ExecOrderActionField::setTraderID)
            .def_readwrite("installID", &ExecOrderActionField::InstallID)
            .add_property("execOrderLocalID", &ExecOrderActionField::getExecOrderLocalID, &ExecOrderActionField::setExecOrderLocalID)
            .add_property("actionLocalID", &ExecOrderActionField::getActionLocalID, &ExecOrderActionField::setActionLocalID)
            .add_property("participantID", &ExecOrderActionField::getParticipantID, &ExecOrderActionField::setParticipantID)
            .add_property("clientID", &ExecOrderActionField::getClientID, &ExecOrderActionField::setClientID)
            .add_property("businessUnit", &ExecOrderActionField::getBusinessUnit, &ExecOrderActionField::setBusinessUnit)
            .def_readwrite("orderActionStatus", &ExecOrderActionField::OrderActionStatus)
            .add_property("userID", &ExecOrderActionField::getUserID, &ExecOrderActionField::setUserID)
            .def_readwrite("actionType", &ExecOrderActionField::ActionType)
            .add_property("statusMsg", &ExecOrderActionField::getStatusMsg, &ExecOrderActionField::setStatusMsg)
            .add_property("instrumentID", &ExecOrderActionField::getInstrumentID, &ExecOrderActionField::setInstrumentID)
            .add_property("branchID", &ExecOrderActionField::getBranchID, &ExecOrderActionField::setBranchID)
            .add_property("investUnitID", &ExecOrderActionField::getInvestUnitID, &ExecOrderActionField::setInvestUnitID)
            .add_property("IPAddress", &ExecOrderActionField::getIPAddress, &ExecOrderActionField::setIPAddress)
            .add_property("macAddress", &ExecOrderActionField::getMacAddress, &ExecOrderActionField::setMacAddress);

    class_<QryExecOrderField>("QryExecOrderField")
            .add_property("brokerID", &QryExecOrderField::getBrokerID, &QryExecOrderField::setBrokerID)
            .add_property("investorID", &QryExecOrderField::getInvestorID, &QryExecOrderField::setInvestorID)
            .add_property("instrumentID", &QryExecOrderField::getInstrumentID, &QryExecOrderField::setInstrumentID)
            .add_property("exchangeID", &QryExecOrderField::getExchangeID, &QryExecOrderField::setExchangeID)
            .add_property("execOrderSysID", &QryExecOrderField::getExecOrderSysID, &QryExecOrderField::setExecOrderSysID)
            .add_property("insertTimeStart", &QryExecOrderField::getInsertTimeStart, &QryExecOrderField::setInsertTimeStart)
            .add_property("insertTimeEnd", &QryExecOrderField::getInsertTimeEnd, &QryExecOrderField::setInsertTimeEnd);

    class_<InputForQuoteField>("InputForQuoteField")
            .add_property("brokerID", &InputForQuoteField::getBrokerID, &InputForQuoteField::setBrokerID)
            .add_property("investorID", &InputForQuoteField::getInvestorID, &InputForQuoteField::setInvestorID)
            .add_property("instrumentID", &InputForQuoteField::getInstrumentID, &InputForQuoteField::setInstrumentID)
            .add_property("forQuoteRef", &InputForQuoteField::getForQuoteRef, &InputForQuoteField::setForQuoteRef)
            .add_property("userID", &InputForQuoteField::getUserID, &InputForQuoteField::setUserID)
            .add_property("exchangeID", &InputForQuoteField::getExchangeID, &InputForQuoteField::setExchangeID)
            .add_property("investUnitID", &InputForQuoteField::getInvestUnitID, &InputForQuoteField::setInvestUnitID)
            .add_property("IPAddress", &InputForQuoteField::getIPAddress, &InputForQuoteField::setIPAddress)
            .add_property("macAddress", &InputForQuoteField::getMacAddress, &InputForQuoteField::setMacAddress);

    class_<ForQuoteField>("ForQuoteField")
            .add_property("brokerID", &ForQuoteField::getBrokerID, &ForQuoteField::setBrokerID)
            .add_property("investorID", &ForQuoteField::getInvestorID, &ForQuoteField::setInvestorID)
            .add_property("instrumentID", &ForQuoteField::getInstrumentID, &ForQuoteField::setInstrumentID)
            .add_property("forQuoteRef", &ForQuoteField::getForQuoteRef, &ForQuoteField::setForQuoteRef)
            .add_property("userID", &ForQuoteField::getUserID, &ForQuoteField::setUserID)
            .add_property("forQuoteLocalID", &ForQuoteField::getForQuoteLocalID, &ForQuoteField::setForQuoteLocalID)
            .add_property("exchangeID", &ForQuoteField::getExchangeID, &ForQuoteField::setExchangeID)
            .add_property("participantID", &ForQuoteField::getParticipantID, &ForQuoteField::setParticipantID)
            .add_property("clientID", &ForQuoteField::getClientID, &ForQuoteField::setClientID)
            .add_property("exchangeInstID", &ForQuoteField::getExchangeInstID, &ForQuoteField::setExchangeInstID)
            .add_property("traderID", &ForQuoteField::getTraderID, &ForQuoteField::setTraderID)
            .def_readwrite("installID", &ForQuoteField::InstallID)
            .add_property("insertDate", &ForQuoteField::getInsertDate, &ForQuoteField::setInsertDate)
            .add_property("insertTime", &ForQuoteField::getInsertTime, &ForQuoteField::setInsertTime)
            .def_readwrite("forQuoteStatus", &ForQuoteField::ForQuoteStatus)
            .def_readwrite("frontID", &ForQuoteField::FrontID)
            .def_readwrite("sessionID", &ForQuoteField::SessionID)
            .add_property("statusMsg", &ForQuoteField::getStatusMsg, &ForQuoteField::setStatusMsg)
            .add_property("activeUserID", &ForQuoteField::getActiveUserID, &ForQuoteField::setActiveUserID)
            .def_readwrite("brokerForQutoSeq", &ForQuoteField::BrokerForQutoSeq)
            .add_property("investUnitID", &ForQuoteField::getInvestUnitID, &ForQuoteField::setInvestUnitID)
            .add_property("IPAddress", &ForQuoteField::getIPAddress, &ForQuoteField::setIPAddress)
            .add_property("macAddress", &ForQuoteField::getMacAddress, &ForQuoteField::setMacAddress);

    class_<QryForQuoteField>("QryForQuoteField")
            .add_property("brokerID", &QryForQuoteField::getBrokerID, &QryForQuoteField::setBrokerID)
            .add_property("investorID", &QryForQuoteField::getInvestorID, &QryForQuoteField::setInvestorID)
            .add_property("instrumentID", &QryForQuoteField::getInstrumentID, &QryForQuoteField::setInstrumentID)
            .add_property("exchangeID", &QryForQuoteField::getExchangeID, &QryForQuoteField::setExchangeID)
            .add_property("insertTimeStart", &QryForQuoteField::getInsertTimeStart, &QryForQuoteField::setInsertTimeStart)
            .add_property("insertTimeEnd", &QryForQuoteField::getInsertTimeEnd, &QryForQuoteField::setInsertTimeEnd);

    class_<InputQuoteField>("InputQuoteField")
            .add_property("brokerID", &InputQuoteField::getBrokerID, &InputQuoteField::setBrokerID)
            .add_property("investorID", &InputQuoteField::getInvestorID, &InputQuoteField::setInvestorID)
            .add_property("instrumentID", &InputQuoteField::getInstrumentID, &InputQuoteField::setInstrumentID)
            .add_property("quoteRef", &InputQuoteField::getQuoteRef, &InputQuoteField::setQuoteRef)
            .add_property("userID", &InputQuoteField::getUserID, &InputQuoteField::setUserID)
            .def_readwrite("askPrice", &InputQuoteField::AskPrice)
            .def_readwrite("bidPrice", &InputQuoteField::BidPrice)
            .def_readwrite("askVolume", &InputQuoteField::AskVolume)
            .def_readwrite("bidVolume", &InputQuoteField::BidVolume)
            .def_readwrite("requestID", &InputQuoteField::RequestID)
            .add_property("businessUnit", &InputQuoteField::getBusinessUnit, &InputQuoteField::setBusinessUnit)
            .def_readwrite("askOffsetFlag", &InputQuoteField::AskOffsetFlag)
            .def_readwrite("bidOffsetFlag", &InputQuoteField::BidOffsetFlag)
            .def_readwrite("askHedgeFlag", &InputQuoteField::AskHedgeFlag)
            .def_readwrite("bidHedgeFlag", &InputQuoteField::BidHedgeFlag)
            .add_property("askOrderRef", &InputQuoteField::getAskOrderRef, &InputQuoteField::setAskOrderRef)
            .add_property("bidOrderRef", &InputQuoteField::getBidOrderRef, &InputQuoteField::setBidOrderRef)
            .add_property("forQuoteSysID", &InputQuoteField::getForQuoteSysID, &InputQuoteField::setForQuoteSysID)
            .add_property("exchangeID", &InputQuoteField::getExchangeID, &InputQuoteField::setExchangeID)
            .add_property("investUnitID", &InputQuoteField::getInvestUnitID, &InputQuoteField::setInvestUnitID)
            .add_property("clientID", &InputQuoteField::getClientID, &InputQuoteField::setClientID)
            .add_property("IPAddress", &InputQuoteField::getIPAddress, &InputQuoteField::setIPAddress)
            .add_property("macAddress", &InputQuoteField::getMacAddress, &InputQuoteField::setMacAddress);

    class_<InputQuoteActionField>("InputQuoteActionField")
            .add_property("brokerID", &InputQuoteActionField::getBrokerID, &InputQuoteActionField::setBrokerID)
            .add_property("investorID", &InputQuoteActionField::getInvestorID, &InputQuoteActionField::setInvestorID)
            .def_readwrite("quoteActionRef", &InputQuoteActionField::QuoteActionRef)
            .add_property("quoteRef", &InputQuoteActionField::getQuoteRef, &InputQuoteActionField::setQuoteRef)
            .def_readwrite("requestID", &InputQuoteActionField::RequestID)
            .def_readwrite("frontID", &InputQuoteActionField::FrontID)
            .def_readwrite("sessionID", &InputQuoteActionField::SessionID)
            .add_property("exchangeID", &InputQuoteActionField::getExchangeID, &InputQuoteActionField::setExchangeID)
            .add_property("quoteSysID", &InputQuoteActionField::getQuoteSysID, &InputQuoteActionField::setQuoteSysID)
            .def_readwrite("actionFlag", &InputQuoteActionField::ActionFlag)
            .add_property("userID", &InputQuoteActionField::getUserID, &InputQuoteActionField::setUserID)
            .add_property("instrumentID", &InputQuoteActionField::getInstrumentID, &InputQuoteActionField::setInstrumentID)
            .add_property("investUnitID", &InputQuoteActionField::getInvestUnitID, &InputQuoteActionField::setInvestUnitID)
            .add_property("clientID", &InputQuoteActionField::getClientID, &InputQuoteActionField::setClientID)
            .add_property("IPAddress", &InputQuoteActionField::getIPAddress, &InputQuoteActionField::setIPAddress)
            .add_property("macAddress", &InputQuoteActionField::getMacAddress, &InputQuoteActionField::setMacAddress);

    class_<QuoteField>("QuoteField")
            .add_property("brokerID", &QuoteField::getBrokerID, &QuoteField::setBrokerID)
            .add_property("investorID", &QuoteField::getInvestorID, &QuoteField::setInvestorID)
            .add_property("instrumentID", &QuoteField::getInstrumentID, &QuoteField::setInstrumentID)
            .add_property("quoteRef", &QuoteField::getQuoteRef, &QuoteField::setQuoteRef)
            .add_property("userID", &QuoteField::getUserID, &QuoteField::setUserID)
            .def_readwrite("askPrice", &QuoteField::AskPrice)
            .def_readwrite("bidPrice", &QuoteField::BidPrice)
            .def_readwrite("askVolume", &QuoteField::AskVolume)
            .def_readwrite("bidVolume", &QuoteField::BidVolume)
            .def_readwrite("requestID", &QuoteField::RequestID)
            .add_property("businessUnit", &QuoteField::getBusinessUnit, &QuoteField::setBusinessUnit)
            .def_readwrite("askOffsetFlag", &QuoteField::AskOffsetFlag)
            .def_readwrite("bidOffsetFlag", &QuoteField::BidOffsetFlag)
            .def_readwrite("askHedgeFlag", &QuoteField::AskHedgeFlag)
            .def_readwrite("bidHedgeFlag", &QuoteField::BidHedgeFlag)
            .add_property("quoteLocalID", &QuoteField::getQuoteLocalID, &QuoteField::setQuoteLocalID)
            .add_property("exchangeID", &QuoteField::getExchangeID, &QuoteField::setExchangeID)
            .add_property("participantID", &QuoteField::getParticipantID, &QuoteField::setParticipantID)
            .add_property("clientID", &QuoteField::getClientID, &QuoteField::setClientID)
            .add_property("exchangeInstID", &QuoteField::getExchangeInstID, &QuoteField::setExchangeInstID)
            .add_property("traderID", &QuoteField::getTraderID, &QuoteField::setTraderID)
            .def_readwrite("installID", &QuoteField::InstallID)
            .def_readwrite("notifySequence", &QuoteField::NotifySequence)
            .def_readwrite("orderSubmitStatus", &QuoteField::OrderSubmitStatus)
            .add_property("tradingDay", &QuoteField::getTradingDay, &QuoteField::setTradingDay)
            .def_readwrite("settlementID", &QuoteField::SettlementID)
            .add_property("quoteSysID", &QuoteField::getQuoteSysID, &QuoteField::setQuoteSysID)
            .add_property("insertDate", &QuoteField::getInsertDate, &QuoteField::setInsertDate)
            .add_property("insertTime", &QuoteField::getInsertTime, &QuoteField::setInsertTime)
            .add_property("cancelTime", &QuoteField::getCancelTime, &QuoteField::setCancelTime)
            .def_readwrite("quoteStatus", &QuoteField::QuoteStatus)
            .add_property("clearingPartID", &QuoteField::getClearingPartID, &QuoteField::setClearingPartID)
            .def_readwrite("sequenceNo", &QuoteField::SequenceNo)
            .add_property("askOrderSysID", &QuoteField::getAskOrderSysID, &QuoteField::setAskOrderSysID)
            .add_property("bidOrderSysID", &QuoteField::getBidOrderSysID, &QuoteField::setBidOrderSysID)
            .def_readwrite("frontID", &QuoteField::FrontID)
            .def_readwrite("sessionID", &QuoteField::SessionID)
            .add_property("userProductInfo", &QuoteField::getUserProductInfo, &QuoteField::setUserProductInfo)
            .add_property("statusMsg", &QuoteField::getStatusMsg, &QuoteField::setStatusMsg)
            .add_property("activeUserID", &QuoteField::getActiveUserID, &QuoteField::setActiveUserID)
            .def_readwrite("brokerQuoteSeq", &QuoteField::BrokerQuoteSeq)
            .add_property("askOrderRef", &QuoteField::getAskOrderRef, &QuoteField::setAskOrderRef)
            .add_property("bidOrderRef", &QuoteField::getBidOrderRef, &QuoteField::setBidOrderRef)
            .add_property("forQuoteSysID", &QuoteField::getForQuoteSysID, &QuoteField::setForQuoteSysID)
            .add_property("branchID", &QuoteField::getBranchID, &QuoteField::setBranchID)
            .add_property("investUnitID", &QuoteField::getInvestUnitID, &QuoteField::setInvestUnitID)
            .add_property("accountID", &QuoteField::getAccountID, &QuoteField::setAccountID)
            .add_property("currencyID", &QuoteField::getCurrencyID, &QuoteField::setCurrencyID)
            .add_property("IPAddress", &QuoteField::getIPAddress, &QuoteField::setIPAddress)
            .add_property("macAddress", &QuoteField::getMacAddress, &QuoteField::setMacAddress);

    class_<QuoteActionField>("QuoteActionField")
            .add_property("brokerID", &QuoteActionField::getBrokerID, &QuoteActionField::setBrokerID)
            .add_property("investorID", &QuoteActionField::getInvestorID, &QuoteActionField::setInvestorID)
            .def_readwrite("quoteActionRef", &QuoteActionField::QuoteActionRef)
            .add_property("quoteRef", &QuoteActionField::getQuoteRef, &QuoteActionField::setQuoteRef)
            .def_readwrite("requestID", &QuoteActionField::RequestID)
            .def_readwrite("frontID", &QuoteActionField::FrontID)
            .def_readwrite("sessionID", &QuoteActionField::SessionID)
            .add_property("exchangeID", &QuoteActionField::getExchangeID, &QuoteActionField::setExchangeID)
            .add_property("quoteSysID", &QuoteActionField::getQuoteSysID, &QuoteActionField::setQuoteSysID)
            .def_readwrite("actionFlag", &QuoteActionField::ActionFlag)
            .add_property("actionDate", &QuoteActionField::getActionDate, &QuoteActionField::setActionDate)
            .add_property("actionTime", &QuoteActionField::getActionTime, &QuoteActionField::setActionTime)
            .add_property("traderID", &QuoteActionField::getTraderID, &QuoteActionField::setTraderID)
            .def_readwrite("installID", &QuoteActionField::InstallID)
            .add_property("quoteLocalID", &QuoteActionField::getQuoteLocalID, &QuoteActionField::setQuoteLocalID)
            .add_property("actionLocalID", &QuoteActionField::getActionLocalID, &QuoteActionField::setActionLocalID)
            .add_property("participantID", &QuoteActionField::getParticipantID, &QuoteActionField::setParticipantID)
            .add_property("clientID", &QuoteActionField::getClientID, &QuoteActionField::setClientID)
            .add_property("businessUnit", &QuoteActionField::getBusinessUnit, &QuoteActionField::setBusinessUnit)
            .def_readwrite("orderActionStatus", &QuoteActionField::OrderActionStatus)
            .add_property("userID", &QuoteActionField::getUserID, &QuoteActionField::setUserID)
            .add_property("statusMsg", &QuoteActionField::getStatusMsg, &QuoteActionField::setStatusMsg)
            .add_property("instrumentID", &QuoteActionField::getInstrumentID, &QuoteActionField::setInstrumentID)
            .add_property("branchID", &QuoteActionField::getBranchID, &QuoteActionField::setBranchID)
            .add_property("investUnitID", &QuoteActionField::getInvestUnitID, &QuoteActionField::setInvestUnitID)
            .add_property("IPAddress", &QuoteActionField::getIPAddress, &QuoteActionField::setIPAddress)
            .add_property("macAddress", &QuoteActionField::getMacAddress, &QuoteActionField::setMacAddress);

    class_<QryQuoteField>("QryQuoteField")
            .add_property("brokerID", &QryQuoteField::getBrokerID, &QryQuoteField::setBrokerID)
            .add_property("investorID", &QryQuoteField::getInvestorID, &QryQuoteField::setInvestorID)
            .add_property("instrumentID", &QryQuoteField::getInstrumentID, &QryQuoteField::setInstrumentID)
            .add_property("exchangeID", &QryQuoteField::getExchangeID, &QryQuoteField::setExchangeID)
            .add_property("quoteSysID", &QryQuoteField::getQuoteSysID, &QryQuoteField::setQuoteSysID)
            .add_property("insertTimeStart", &QryQuoteField::getInsertTimeStart, &QryQuoteField::setInsertTimeStart)
            .add_property("insertTimeEnd", &QryQuoteField::getInsertTimeEnd, &QryQuoteField::setInsertTimeEnd);

    class_<ForQuoteRspField>("ForQuoteRspField")
            .add_property("tradingDay", &ForQuoteRspField::getTradingDay, &ForQuoteRspField::setTradingDay)
            .add_property("instrumentID", &ForQuoteRspField::getInstrumentID, &ForQuoteRspField::setInstrumentID)
            .add_property("forQuoteSysID", &ForQuoteRspField::getForQuoteSysID, &ForQuoteRspField::setForQuoteSysID)
            .add_property("forQuoteTime", &ForQuoteRspField::getForQuoteTime, &ForQuoteRspField::setForQuoteTime)
            .add_property("actionDay", &ForQuoteRspField::getActionDay, &ForQuoteRspField::setActionDay)
            .add_property("exchangeID", &ForQuoteRspField::getExchangeID, &ForQuoteRspField::setExchangeID);

    class_<InputBatchOrderActionField>("InputBatchOrderActionField")
            .add_property("brokerID", &InputBatchOrderActionField::getBrokerID, &InputBatchOrderActionField::setBrokerID)
            .add_property("investorID", &InputBatchOrderActionField::getInvestorID, &InputBatchOrderActionField::setInvestorID)
            .def_readwrite("orderActionRef", &InputBatchOrderActionField::OrderActionRef)
            .def_readwrite("requestID", &InputBatchOrderActionField::RequestID)
            .def_readwrite("frontID", &InputBatchOrderActionField::FrontID)
            .def_readwrite("sessionID", &InputBatchOrderActionField::SessionID)
            .add_property("exchangeID", &InputBatchOrderActionField::getExchangeID, &InputBatchOrderActionField::setExchangeID)
            .add_property("userID", &InputBatchOrderActionField::getUserID, &InputBatchOrderActionField::setUserID)
            .add_property("investUnitID", &InputBatchOrderActionField::getInvestUnitID, &InputBatchOrderActionField::setInvestUnitID)
            .add_property("IPAddress", &InputBatchOrderActionField::getIPAddress, &InputBatchOrderActionField::setIPAddress)
            .add_property("macAddress", &InputBatchOrderActionField::getMacAddress, &InputBatchOrderActionField::setMacAddress);

    class_<BatchOrderActionField>("BatchOrderActionField")
            .add_property("brokerID", &BatchOrderActionField::getBrokerID, &BatchOrderActionField::setBrokerID)
            .add_property("investorID", &BatchOrderActionField::getInvestorID, &BatchOrderActionField::setInvestorID)
            .def_readwrite("orderActionRef", &BatchOrderActionField::OrderActionRef)
            .def_readwrite("requestID", &BatchOrderActionField::RequestID)
            .def_readwrite("frontID", &BatchOrderActionField::FrontID)
            .def_readwrite("sessionID", &BatchOrderActionField::SessionID)
            .add_property("exchangeID", &BatchOrderActionField::getExchangeID, &BatchOrderActionField::setExchangeID)
            .add_property("actionDate", &BatchOrderActionField::getActionDate, &BatchOrderActionField::setActionDate)
            .add_property("actionTime", &BatchOrderActionField::getActionTime, &BatchOrderActionField::setActionTime)
            .add_property("traderID", &BatchOrderActionField::getTraderID, &BatchOrderActionField::setTraderID)
            .def_readwrite("installID", &BatchOrderActionField::InstallID)
            .add_property("actionLocalID", &BatchOrderActionField::getActionLocalID, &BatchOrderActionField::setActionLocalID)
            .add_property("participantID", &BatchOrderActionField::getParticipantID, &BatchOrderActionField::setParticipantID)
            .add_property("clientID", &BatchOrderActionField::getClientID, &BatchOrderActionField::setClientID)
            .add_property("businessUnit", &BatchOrderActionField::getBusinessUnit, &BatchOrderActionField::setBusinessUnit)
            .def_readwrite("orderActionStatus", &BatchOrderActionField::OrderActionStatus)
            .add_property("userID", &BatchOrderActionField::getUserID, &BatchOrderActionField::setUserID)
            .add_property("statusMsg", &BatchOrderActionField::getStatusMsg, &BatchOrderActionField::setStatusMsg)
            .add_property("investUnitID", &BatchOrderActionField::getInvestUnitID, &BatchOrderActionField::setInvestUnitID)
            .add_property("IPAddress", &BatchOrderActionField::getIPAddress, &BatchOrderActionField::setIPAddress)
            .add_property("macAddress", &BatchOrderActionField::getMacAddress, &BatchOrderActionField::setMacAddress);

    class_<CombInstrumentGuardField>("CombInstrumentGuardField")
            .add_property("brokerID", &CombInstrumentGuardField::getBrokerID, &CombInstrumentGuardField::setBrokerID)
            .add_property("instrumentID", &CombInstrumentGuardField::getInstrumentID, &CombInstrumentGuardField::setInstrumentID)
            .def_readwrite("guarantRatio", &CombInstrumentGuardField::GuarantRatio);

    class_<QryCombInstrumentGuardField>("QryCombInstrumentGuardField")
            .add_property("brokerID", &QryCombInstrumentGuardField::getBrokerID, &QryCombInstrumentGuardField::setBrokerID)
            .add_property("instrumentID", &QryCombInstrumentGuardField::getInstrumentID, &QryCombInstrumentGuardField::setInstrumentID);

    class_<InputCombActionField>("InputCombActionField")
            .add_property("brokerID", &InputCombActionField::getBrokerID, &InputCombActionField::setBrokerID)
            .add_property("investorID", &InputCombActionField::getInvestorID, &InputCombActionField::setInvestorID)
            .add_property("instrumentID", &InputCombActionField::getInstrumentID, &InputCombActionField::setInstrumentID)
            .add_property("combActionRef", &InputCombActionField::getCombActionRef, &InputCombActionField::setCombActionRef)
            .add_property("userID", &InputCombActionField::getUserID, &InputCombActionField::setUserID)
            .def_readwrite("direction", &InputCombActionField::Direction)
            .def_readwrite("volume", &InputCombActionField::Volume)
            .def_readwrite("combDirection", &InputCombActionField::CombDirection)
            .def_readwrite("hedgeFlag", &InputCombActionField::HedgeFlag)
            .add_property("exchangeID", &InputCombActionField::getExchangeID, &InputCombActionField::setExchangeID)
            .add_property("IPAddress", &InputCombActionField::getIPAddress, &InputCombActionField::setIPAddress)
            .add_property("macAddress", &InputCombActionField::getMacAddress, &InputCombActionField::setMacAddress);

    class_<CombActionField>("CombActionField")
            .add_property("brokerID", &CombActionField::getBrokerID, &CombActionField::setBrokerID)
            .add_property("investorID", &CombActionField::getInvestorID, &CombActionField::setInvestorID)
            .add_property("instrumentID", &CombActionField::getInstrumentID, &CombActionField::setInstrumentID)
            .add_property("combActionRef", &CombActionField::getCombActionRef, &CombActionField::setCombActionRef)
            .add_property("userID", &CombActionField::getUserID, &CombActionField::setUserID)
            .def_readwrite("direction", &CombActionField::Direction)
            .def_readwrite("volume", &CombActionField::Volume)
            .def_readwrite("combDirection", &CombActionField::CombDirection)
            .def_readwrite("hedgeFlag", &CombActionField::HedgeFlag)
            .add_property("actionLocalID", &CombActionField::getActionLocalID, &CombActionField::setActionLocalID)
            .add_property("exchangeID", &CombActionField::getExchangeID, &CombActionField::setExchangeID)
            .add_property("participantID", &CombActionField::getParticipantID, &CombActionField::setParticipantID)
            .add_property("clientID", &CombActionField::getClientID, &CombActionField::setClientID)
            .add_property("exchangeInstID", &CombActionField::getExchangeInstID, &CombActionField::setExchangeInstID)
            .add_property("traderID", &CombActionField::getTraderID, &CombActionField::setTraderID)
            .def_readwrite("installID", &CombActionField::InstallID)
            .def_readwrite("actionStatus", &CombActionField::ActionStatus)
            .def_readwrite("notifySequence", &CombActionField::NotifySequence)
            .add_property("tradingDay", &CombActionField::getTradingDay, &CombActionField::setTradingDay)
            .def_readwrite("settlementID", &CombActionField::SettlementID)
            .def_readwrite("sequenceNo", &CombActionField::SequenceNo)
            .def_readwrite("frontID", &CombActionField::FrontID)
            .def_readwrite("sessionID", &CombActionField::SessionID)
            .add_property("userProductInfo", &CombActionField::getUserProductInfo, &CombActionField::setUserProductInfo)
            .add_property("statusMsg", &CombActionField::getStatusMsg, &CombActionField::setStatusMsg)
            .add_property("IPAddress", &CombActionField::getIPAddress, &CombActionField::setIPAddress)
            .add_property("macAddress", &CombActionField::getMacAddress, &CombActionField::setMacAddress);

    class_<QryCombActionField>("QryCombActionField")
            .add_property("brokerID", &QryCombActionField::getBrokerID, &QryCombActionField::setBrokerID)
            .add_property("investorID", &QryCombActionField::getInvestorID, &QryCombActionField::setInvestorID)
            .add_property("instrumentID", &QryCombActionField::getInstrumentID, &QryCombActionField::setInstrumentID)
            .add_property("exchangeID", &QryCombActionField::getExchangeID, &QryCombActionField::setExchangeID);

    class_<ProductExchRateField>("ProductExchRateField")
            .add_property("productID", &ProductExchRateField::getProductID, &ProductExchRateField::setProductID)
            .add_property("quoteCurrencyID", &ProductExchRateField::getQuoteCurrencyID, &ProductExchRateField::setQuoteCurrencyID)
            .def_readwrite("exchangeRate", &ProductExchRateField::ExchangeRate);

    class_<QryProductExchRateField>("QryProductExchRateField")
            .add_property("productID", &QryProductExchRateField::getProductID, &QryProductExchRateField::setProductID);

    class_<MMOptionInstrCommRateField>("MMOptionInstrCommRateField")
            .add_property("instrumentID", &MMOptionInstrCommRateField::getInstrumentID, &MMOptionInstrCommRateField::setInstrumentID)
            .def_readwrite("investorRange", &MMOptionInstrCommRateField::InvestorRange)
            .add_property("brokerID", &MMOptionInstrCommRateField::getBrokerID, &MMOptionInstrCommRateField::setBrokerID)
            .add_property("investorID", &MMOptionInstrCommRateField::getInvestorID, &MMOptionInstrCommRateField::setInvestorID)
            .def_readwrite("openRatioByMoney", &MMOptionInstrCommRateField::OpenRatioByMoney)
            .def_readwrite("openRatioByVolume", &MMOptionInstrCommRateField::OpenRatioByVolume)
            .def_readwrite("closeRatioByMoney", &MMOptionInstrCommRateField::CloseRatioByMoney)
            .def_readwrite("closeRatioByVolume", &MMOptionInstrCommRateField::CloseRatioByVolume)
            .def_readwrite("closeTodayRatioByMoney", &MMOptionInstrCommRateField::CloseTodayRatioByMoney)
            .def_readwrite("closeTodayRatioByVolume", &MMOptionInstrCommRateField::CloseTodayRatioByVolume)
            .def_readwrite("strikeRatioByMoney", &MMOptionInstrCommRateField::StrikeRatioByMoney)
            .def_readwrite("strikeRatioByVolume", &MMOptionInstrCommRateField::StrikeRatioByVolume);

    class_<QryMMOptionInstrCommRateField>("QryMMOptionInstrCommRateField")
            .add_property("brokerID", &QryMMOptionInstrCommRateField::getBrokerID, &QryMMOptionInstrCommRateField::setBrokerID)
            .add_property("investorID", &QryMMOptionInstrCommRateField::getInvestorID, &QryMMOptionInstrCommRateField::setInvestorID)
            .add_property("instrumentID", &QryMMOptionInstrCommRateField::getInstrumentID, &QryMMOptionInstrCommRateField::setInstrumentID);

    class_<MMInstrumentCommissionRateField>("MMInstrumentCommissionRateField")
            .add_property("instrumentID", &MMInstrumentCommissionRateField::getInstrumentID, &MMInstrumentCommissionRateField::setInstrumentID)
            .def_readwrite("investorRange", &MMInstrumentCommissionRateField::InvestorRange)
            .add_property("brokerID", &MMInstrumentCommissionRateField::getBrokerID, &MMInstrumentCommissionRateField::setBrokerID)
            .add_property("investorID", &MMInstrumentCommissionRateField::getInvestorID, &MMInstrumentCommissionRateField::setInvestorID)
            .def_readwrite("openRatioByMoney", &MMInstrumentCommissionRateField::OpenRatioByMoney)
            .def_readwrite("openRatioByVolume", &MMInstrumentCommissionRateField::OpenRatioByVolume)
            .def_readwrite("closeRatioByMoney", &MMInstrumentCommissionRateField::CloseRatioByMoney)
            .def_readwrite("closeRatioByVolume", &MMInstrumentCommissionRateField::CloseRatioByVolume)
            .def_readwrite("closeTodayRatioByMoney", &MMInstrumentCommissionRateField::CloseTodayRatioByMoney)
            .def_readwrite("closeTodayRatioByVolume", &MMInstrumentCommissionRateField::CloseTodayRatioByVolume);

    class_<QryMMInstrumentCommissionRateField>("QryMMInstrumentCommissionRateField")
            .add_property("brokerID", &QryMMInstrumentCommissionRateField::getBrokerID, &QryMMInstrumentCommissionRateField::setBrokerID)
            .add_property("investorID", &QryMMInstrumentCommissionRateField::getInvestorID, &QryMMInstrumentCommissionRateField::setInvestorID)
            .add_property("instrumentID", &QryMMInstrumentCommissionRateField::getInstrumentID, &QryMMInstrumentCommissionRateField::setInstrumentID);

    class_<InstrumentOrderCommRateField>("InstrumentOrderCommRateField")
            .add_property("instrumentID", &InstrumentOrderCommRateField::getInstrumentID, &InstrumentOrderCommRateField::setInstrumentID)
            .def_readwrite("investorRange", &InstrumentOrderCommRateField::InvestorRange)
            .add_property("brokerID", &InstrumentOrderCommRateField::getBrokerID, &InstrumentOrderCommRateField::setBrokerID)
            .add_property("investorID", &InstrumentOrderCommRateField::getInvestorID, &InstrumentOrderCommRateField::setInvestorID)
            .def_readwrite("hedgeFlag", &InstrumentOrderCommRateField::HedgeFlag)
            .def_readwrite("orderCommByVolume", &InstrumentOrderCommRateField::OrderCommByVolume)
            .def_readwrite("orderActionCommByVolume", &InstrumentOrderCommRateField::OrderActionCommByVolume);

    class_<QryInstrumentOrderCommRateField>("QryInstrumentOrderCommRateField")
            .add_property("brokerID", &QryInstrumentOrderCommRateField::getBrokerID, &QryInstrumentOrderCommRateField::setBrokerID)
            .add_property("investorID", &QryInstrumentOrderCommRateField::getInvestorID, &QryInstrumentOrderCommRateField::setInvestorID)
            .add_property("instrumentID", &QryInstrumentOrderCommRateField::getInstrumentID, &QryInstrumentOrderCommRateField::setInstrumentID);

    class_<InstrumentStatusField>("InstrumentStatusField")
            .add_property("exchangeID", &InstrumentStatusField::getExchangeID, &InstrumentStatusField::setExchangeID)
            .add_property("exchangeInstID", &InstrumentStatusField::getExchangeInstID, &InstrumentStatusField::setExchangeInstID)
            .add_property("settlementGroupID", &InstrumentStatusField::getSettlementGroupID, &InstrumentStatusField::setSettlementGroupID)
            .add_property("instrumentID", &InstrumentStatusField::getInstrumentID, &InstrumentStatusField::setInstrumentID)
            .def_readwrite("instrumentStatus", &InstrumentStatusField::InstrumentStatus)
            .def_readwrite("tradingSegmentSN", &InstrumentStatusField::TradingSegmentSN)
            .add_property("enterTime", &InstrumentStatusField::getEnterTime, &InstrumentStatusField::setEnterTime)
            .def_readwrite("enterReason", &InstrumentStatusField::EnterReason);

    class_<QryTransferBankField>("QryTransferBankField")
            .add_property("bankID", &QryTransferBankField::getBankID, &QryTransferBankField::setBankID)
            .add_property("bankBrchID", &QryTransferBankField::getBankBrchID, &QryTransferBankField::setBankBrchID);

    class_<TransferBankField>("TransferBankField")
            .add_property("bankID", &TransferBankField::getBankID, &TransferBankField::setBankID)
            .add_property("bankBrchID", &TransferBankField::getBankBrchID, &TransferBankField::setBankBrchID)
            .add_property("bankName", &TransferBankField::getBankName, &TransferBankField::setBankName)
            .def_readwrite("isActive", &TransferBankField::IsActive);

    class_<QryInvestorPositionDetailField>("QryInvestorPositionDetailField")
            .add_property("brokerID", &QryInvestorPositionDetailField::getBrokerID, &QryInvestorPositionDetailField::setBrokerID)
            .add_property("investorID", &QryInvestorPositionDetailField::getInvestorID, &QryInvestorPositionDetailField::setInvestorID)
            .add_property("instrumentID", &QryInvestorPositionDetailField::getInstrumentID, &QryInvestorPositionDetailField::setInstrumentID);

    class_<InvestorPositionDetailField>("InvestorPositionDetailField")
            .add_property("instrumentID", &InvestorPositionDetailField::getInstrumentID, &InvestorPositionDetailField::setInstrumentID)
            .add_property("brokerID", &InvestorPositionDetailField::getBrokerID, &InvestorPositionDetailField::setBrokerID)
            .add_property("investorID", &InvestorPositionDetailField::getInvestorID, &InvestorPositionDetailField::setInvestorID)
            .def_readwrite("hedgeFlag", &InvestorPositionDetailField::HedgeFlag)
            .def_readwrite("direction", &InvestorPositionDetailField::Direction)
            .add_property("openDate", &InvestorPositionDetailField::getOpenDate, &InvestorPositionDetailField::setOpenDate)
            .add_property("tradeID", &InvestorPositionDetailField::getTradeID, &InvestorPositionDetailField::setTradeID)
            .def_readwrite("volume", &InvestorPositionDetailField::Volume)
            .def_readwrite("openPrice", &InvestorPositionDetailField::OpenPrice)
            .add_property("tradingDay", &InvestorPositionDetailField::getTradingDay, &InvestorPositionDetailField::setTradingDay)
            .def_readwrite("settlementID", &InvestorPositionDetailField::SettlementID)
            .def_readwrite("tradeType", &InvestorPositionDetailField::TradeType)
            .add_property("combInstrumentID", &InvestorPositionDetailField::getCombInstrumentID, &InvestorPositionDetailField::setCombInstrumentID)
            .add_property("exchangeID", &InvestorPositionDetailField::getExchangeID, &InvestorPositionDetailField::setExchangeID)
            .def_readwrite("closeProfitByDate", &InvestorPositionDetailField::CloseProfitByDate)
            .def_readwrite("closeProfitByTrade", &InvestorPositionDetailField::CloseProfitByTrade)
            .def_readwrite("positionProfitByDate", &InvestorPositionDetailField::PositionProfitByDate)
            .def_readwrite("positionProfitByTrade", &InvestorPositionDetailField::PositionProfitByTrade)
            .def_readwrite("margin", &InvestorPositionDetailField::Margin)
            .def_readwrite("exchMargin", &InvestorPositionDetailField::ExchMargin)
            .def_readwrite("marginRateByMoney", &InvestorPositionDetailField::MarginRateByMoney)
            .def_readwrite("marginRateByVolume", &InvestorPositionDetailField::MarginRateByVolume)
            .def_readwrite("lastSettlementPrice", &InvestorPositionDetailField::LastSettlementPrice)
            .def_readwrite("settlementPrice", &InvestorPositionDetailField::SettlementPrice)
            .def_readwrite("closeVolume", &InvestorPositionDetailField::CloseVolume)
            .def_readwrite("closeAmount", &InvestorPositionDetailField::CloseAmount);

    class_<QryNoticeField>("QryNoticeField")
            .add_property("brokerID", &QryNoticeField::getBrokerID, &QryNoticeField::setBrokerID);

    class_<NoticeField>("NoticeField")
            .add_property("brokerID", &NoticeField::getBrokerID, &NoticeField::setBrokerID)
            .add_property("content", &NoticeField::getContent, &NoticeField::setContent)
            .add_property("sequenceLabel", &NoticeField::getSequenceLabel, &NoticeField::setSequenceLabel);

    class_<QrySettlementInfoConfirmField>("QrySettlementInfoConfirmField")
            .add_property("brokerID", &QrySettlementInfoConfirmField::getBrokerID, &QrySettlementInfoConfirmField::setBrokerID)
            .add_property("investorID", &QrySettlementInfoConfirmField::getInvestorID, &QrySettlementInfoConfirmField::setInvestorID);

    class_<TradingAccountPasswordUpdateField>("TradingAccountPasswordUpdateField")
            .add_property("brokerID", &TradingAccountPasswordUpdateField::getBrokerID, &TradingAccountPasswordUpdateField::setBrokerID)
            .add_property("accountID", &TradingAccountPasswordUpdateField::getAccountID, &TradingAccountPasswordUpdateField::setAccountID)
            .add_property("oldPassword", &TradingAccountPasswordUpdateField::getOldPassword, &TradingAccountPasswordUpdateField::setOldPassword)
            .add_property("newPassword", &TradingAccountPasswordUpdateField::getNewPassword, &TradingAccountPasswordUpdateField::setNewPassword)
            .add_property("currencyID", &TradingAccountPasswordUpdateField::getCurrencyID, &TradingAccountPasswordUpdateField::setCurrencyID);

    class_<QryContractBankField>("QryContractBankField")
            .add_property("brokerID", &QryContractBankField::getBrokerID, &QryContractBankField::setBrokerID)
            .add_property("bankID", &QryContractBankField::getBankID, &QryContractBankField::setBankID)
            .add_property("bankBrchID", &QryContractBankField::getBankBrchID, &QryContractBankField::setBankBrchID);

    class_<ContractBankField>("ContractBankField")
            .add_property("brokerID", &ContractBankField::getBrokerID, &ContractBankField::setBrokerID)
            .add_property("bankID", &ContractBankField::getBankID, &ContractBankField::setBankID)
            .add_property("bankBrchID", &ContractBankField::getBankBrchID, &ContractBankField::setBankBrchID)
            .add_property("bankName", &ContractBankField::getBankName, &ContractBankField::setBankName);

    class_<InvestorPositionCombineDetailField>("InvestorPositionCombineDetailField")
            .add_property("tradingDay", &InvestorPositionCombineDetailField::getTradingDay, &InvestorPositionCombineDetailField::setTradingDay)
            .add_property("openDate", &InvestorPositionCombineDetailField::getOpenDate, &InvestorPositionCombineDetailField::setOpenDate)
            .add_property("exchangeID", &InvestorPositionCombineDetailField::getExchangeID, &InvestorPositionCombineDetailField::setExchangeID)
            .def_readwrite("settlementID", &InvestorPositionCombineDetailField::SettlementID)
            .add_property("brokerID", &InvestorPositionCombineDetailField::getBrokerID, &InvestorPositionCombineDetailField::setBrokerID)
            .add_property("investorID", &InvestorPositionCombineDetailField::getInvestorID, &InvestorPositionCombineDetailField::setInvestorID)
            .add_property("comTradeID", &InvestorPositionCombineDetailField::getComTradeID, &InvestorPositionCombineDetailField::setComTradeID)
            .add_property("tradeID", &InvestorPositionCombineDetailField::getTradeID, &InvestorPositionCombineDetailField::setTradeID)
            .add_property("instrumentID", &InvestorPositionCombineDetailField::getInstrumentID, &InvestorPositionCombineDetailField::setInstrumentID)
            .def_readwrite("hedgeFlag", &InvestorPositionCombineDetailField::HedgeFlag)
            .def_readwrite("direction", &InvestorPositionCombineDetailField::Direction)
            .def_readwrite("totalAmt", &InvestorPositionCombineDetailField::TotalAmt)
            .def_readwrite("margin", &InvestorPositionCombineDetailField::Margin)
            .def_readwrite("exchMargin", &InvestorPositionCombineDetailField::ExchMargin)
            .def_readwrite("marginRateByMoney", &InvestorPositionCombineDetailField::MarginRateByMoney)
            .def_readwrite("marginRateByVolume", &InvestorPositionCombineDetailField::MarginRateByVolume)
            .def_readwrite("legID", &InvestorPositionCombineDetailField::LegID)
            .def_readwrite("legMultiple", &InvestorPositionCombineDetailField::LegMultiple)
            .add_property("combInstrumentID", &InvestorPositionCombineDetailField::getCombInstrumentID, &InvestorPositionCombineDetailField::setCombInstrumentID)
            .def_readwrite("tradeGroupID", &InvestorPositionCombineDetailField::TradeGroupID);

    class_<ParkedOrderField>("ParkedOrderField")
            .add_property("brokerID", &ParkedOrderField::getBrokerID, &ParkedOrderField::setBrokerID)
            .add_property("investorID", &ParkedOrderField::getInvestorID, &ParkedOrderField::setInvestorID)
            .add_property("instrumentID", &ParkedOrderField::getInstrumentID, &ParkedOrderField::setInstrumentID)
            .add_property("orderRef", &ParkedOrderField::getOrderRef, &ParkedOrderField::setOrderRef)
            .add_property("userID", &ParkedOrderField::getUserID, &ParkedOrderField::setUserID)
            .def_readwrite("orderPriceType", &ParkedOrderField::OrderPriceType)
            .def_readwrite("direction", &ParkedOrderField::Direction)
            .add_property("combOffsetFlag", &ParkedOrderField::getCombOffsetFlag, &ParkedOrderField::setCombOffsetFlag)
            .add_property("combHedgeFlag", &ParkedOrderField::getCombHedgeFlag, &ParkedOrderField::setCombHedgeFlag)
            .def_readwrite("limitPrice", &ParkedOrderField::LimitPrice)
            .def_readwrite("volumeTotalOriginal", &ParkedOrderField::VolumeTotalOriginal)
            .def_readwrite("timeCondition", &ParkedOrderField::TimeCondition)
            .add_property("GTDDate", &ParkedOrderField::getGTDDate, &ParkedOrderField::setGTDDate)
            .def_readwrite("volumeCondition", &ParkedOrderField::VolumeCondition)
            .def_readwrite("minVolume", &ParkedOrderField::MinVolume)
            .def_readwrite("contingentCondition", &ParkedOrderField::ContingentCondition)
            .def_readwrite("stopPrice", &ParkedOrderField::StopPrice)
            .def_readwrite("forceCloseReason", &ParkedOrderField::ForceCloseReason)
            .def_readwrite("isAutoSuspend", &ParkedOrderField::IsAutoSuspend)
            .add_property("businessUnit", &ParkedOrderField::getBusinessUnit, &ParkedOrderField::setBusinessUnit)
            .def_readwrite("requestID", &ParkedOrderField::RequestID)
            .def_readwrite("userForceClose", &ParkedOrderField::UserForceClose)
            .add_property("exchangeID", &ParkedOrderField::getExchangeID, &ParkedOrderField::setExchangeID)
            .add_property("parkedOrderID", &ParkedOrderField::getParkedOrderID, &ParkedOrderField::setParkedOrderID)
            .def_readwrite("userType", &ParkedOrderField::UserType)
            .def_readwrite("status", &ParkedOrderField::Status)
            .def_readwrite("errorID", &ParkedOrderField::ErrorID)
            .add_property("errorMsg", &ParkedOrderField::getErrorMsg, &ParkedOrderField::setErrorMsg)
            .def_readwrite("isSwapOrder", &ParkedOrderField::IsSwapOrder)
            .add_property("accountID", &ParkedOrderField::getAccountID, &ParkedOrderField::setAccountID)
            .add_property("currencyID", &ParkedOrderField::getCurrencyID, &ParkedOrderField::setCurrencyID)
            .add_property("clientID", &ParkedOrderField::getClientID, &ParkedOrderField::setClientID)
            .add_property("investUnitID", &ParkedOrderField::getInvestUnitID, &ParkedOrderField::setInvestUnitID)
            .add_property("IPAddress", &ParkedOrderField::getIPAddress, &ParkedOrderField::setIPAddress)
            .add_property("macAddress", &ParkedOrderField::getMacAddress, &ParkedOrderField::setMacAddress);

    class_<ParkedOrderActionField>("ParkedOrderActionField")
            .add_property("brokerID", &ParkedOrderActionField::getBrokerID, &ParkedOrderActionField::setBrokerID)
            .add_property("investorID", &ParkedOrderActionField::getInvestorID, &ParkedOrderActionField::setInvestorID)
            .def_readwrite("orderActionRef", &ParkedOrderActionField::OrderActionRef)
            .add_property("orderRef", &ParkedOrderActionField::getOrderRef, &ParkedOrderActionField::setOrderRef)
            .def_readwrite("requestID", &ParkedOrderActionField::RequestID)
            .def_readwrite("frontID", &ParkedOrderActionField::FrontID)
            .def_readwrite("sessionID", &ParkedOrderActionField::SessionID)
            .add_property("exchangeID", &ParkedOrderActionField::getExchangeID, &ParkedOrderActionField::setExchangeID)
            .add_property("orderSysID", &ParkedOrderActionField::getOrderSysID, &ParkedOrderActionField::setOrderSysID)
            .def_readwrite("actionFlag", &ParkedOrderActionField::ActionFlag)
            .def_readwrite("limitPrice", &ParkedOrderActionField::LimitPrice)
            .def_readwrite("volumeChange", &ParkedOrderActionField::VolumeChange)
            .add_property("userID", &ParkedOrderActionField::getUserID, &ParkedOrderActionField::setUserID)
            .add_property("instrumentID", &ParkedOrderActionField::getInstrumentID, &ParkedOrderActionField::setInstrumentID)
            .add_property("parkedOrderActionID", &ParkedOrderActionField::getParkedOrderActionID, &ParkedOrderActionField::setParkedOrderActionID)
            .def_readwrite("userType", &ParkedOrderActionField::UserType)
            .def_readwrite("status", &ParkedOrderActionField::Status)
            .def_readwrite("errorID", &ParkedOrderActionField::ErrorID)
            .add_property("errorMsg", &ParkedOrderActionField::getErrorMsg, &ParkedOrderActionField::setErrorMsg)
            .add_property("investUnitID", &ParkedOrderActionField::getInvestUnitID, &ParkedOrderActionField::setInvestUnitID)
            .add_property("IPAddress", &ParkedOrderActionField::getIPAddress, &ParkedOrderActionField::setIPAddress)
            .add_property("macAddress", &ParkedOrderActionField::getMacAddress, &ParkedOrderActionField::setMacAddress);

    class_<QryParkedOrderField>("QryParkedOrderField")
            .add_property("brokerID", &QryParkedOrderField::getBrokerID, &QryParkedOrderField::setBrokerID)
            .add_property("investorID", &QryParkedOrderField::getInvestorID, &QryParkedOrderField::setInvestorID)
            .add_property("instrumentID", &QryParkedOrderField::getInstrumentID, &QryParkedOrderField::setInstrumentID)
            .add_property("exchangeID", &QryParkedOrderField::getExchangeID, &QryParkedOrderField::setExchangeID);

    class_<QryParkedOrderActionField>("QryParkedOrderActionField")
            .add_property("brokerID", &QryParkedOrderActionField::getBrokerID, &QryParkedOrderActionField::setBrokerID)
            .add_property("investorID", &QryParkedOrderActionField::getInvestorID, &QryParkedOrderActionField::setInvestorID)
            .add_property("instrumentID", &QryParkedOrderActionField::getInstrumentID, &QryParkedOrderActionField::setInstrumentID)
            .add_property("exchangeID", &QryParkedOrderActionField::getExchangeID, &QryParkedOrderActionField::setExchangeID);

    class_<RemoveParkedOrderField>("RemoveParkedOrderField")
            .add_property("brokerID", &RemoveParkedOrderField::getBrokerID, &RemoveParkedOrderField::setBrokerID)
            .add_property("investorID", &RemoveParkedOrderField::getInvestorID, &RemoveParkedOrderField::setInvestorID)
            .add_property("parkedOrderID", &RemoveParkedOrderField::getParkedOrderID, &RemoveParkedOrderField::setParkedOrderID);

    class_<RemoveParkedOrderActionField>("RemoveParkedOrderActionField")
            .add_property("brokerID", &RemoveParkedOrderActionField::getBrokerID, &RemoveParkedOrderActionField::setBrokerID)
            .add_property("investorID", &RemoveParkedOrderActionField::getInvestorID, &RemoveParkedOrderActionField::setInvestorID)
            .add_property("parkedOrderActionID", &RemoveParkedOrderActionField::getParkedOrderActionID, &RemoveParkedOrderActionField::setParkedOrderActionID);

    class_<QryInvestorPositionCombineDetailField>("QryInvestorPositionCombineDetailField")
            .add_property("brokerID", &QryInvestorPositionCombineDetailField::getBrokerID, &QryInvestorPositionCombineDetailField::setBrokerID)
            .add_property("investorID", &QryInvestorPositionCombineDetailField::getInvestorID, &QryInvestorPositionCombineDetailField::setInvestorID)
            .add_property("combInstrumentID", &QryInvestorPositionCombineDetailField::getCombInstrumentID, &QryInvestorPositionCombineDetailField::setCombInstrumentID);

    class_<TradingNoticeInfoField>("TradingNoticeInfoField")
            .add_property("brokerID", &TradingNoticeInfoField::getBrokerID, &TradingNoticeInfoField::setBrokerID)
            .add_property("investorID", &TradingNoticeInfoField::getInvestorID, &TradingNoticeInfoField::setInvestorID)
            .add_property("sendTime", &TradingNoticeInfoField::getSendTime, &TradingNoticeInfoField::setSendTime)
            .add_property("fieldContent", &TradingNoticeInfoField::getFieldContent, &TradingNoticeInfoField::setFieldContent)
            .def_readwrite("sequenceSeries", &TradingNoticeInfoField::SequenceSeries)
            .def_readwrite("sequenceNo", &TradingNoticeInfoField::SequenceNo);

    class_<TradingNoticeField>("TradingNoticeField")
            .add_property("brokerID", &TradingNoticeField::getBrokerID, &TradingNoticeField::setBrokerID)
            .def_readwrite("investorRange", &TradingNoticeField::InvestorRange)
            .add_property("investorID", &TradingNoticeField::getInvestorID, &TradingNoticeField::setInvestorID)
            .def_readwrite("sequenceSeries", &TradingNoticeField::SequenceSeries)
            .add_property("userID", &TradingNoticeField::getUserID, &TradingNoticeField::setUserID)
            .add_property("sendTime", &TradingNoticeField::getSendTime, &TradingNoticeField::setSendTime)
            .def_readwrite("sequenceNo", &TradingNoticeField::SequenceNo)
            .add_property("fieldContent", &TradingNoticeField::getFieldContent, &TradingNoticeField::setFieldContent);

    class_<QryTradingNoticeField>("QryTradingNoticeField")
            .add_property("brokerID", &QryTradingNoticeField::getBrokerID, &QryTradingNoticeField::setBrokerID)
            .add_property("investorID", &QryTradingNoticeField::getInvestorID, &QryTradingNoticeField::setInvestorID);

    class_<ErrorConditionalOrderField>("ErrorConditionalOrderField")
            .add_property("brokerID", &ErrorConditionalOrderField::getBrokerID, &ErrorConditionalOrderField::setBrokerID)
            .add_property("investorID", &ErrorConditionalOrderField::getInvestorID, &ErrorConditionalOrderField::setInvestorID)
            .add_property("instrumentID", &ErrorConditionalOrderField::getInstrumentID, &ErrorConditionalOrderField::setInstrumentID)
            .add_property("orderRef", &ErrorConditionalOrderField::getOrderRef, &ErrorConditionalOrderField::setOrderRef)
            .add_property("userID", &ErrorConditionalOrderField::getUserID, &ErrorConditionalOrderField::setUserID)
            .def_readwrite("orderPriceType", &ErrorConditionalOrderField::OrderPriceType)
            .def_readwrite("direction", &ErrorConditionalOrderField::Direction)
            .add_property("combOffsetFlag", &ErrorConditionalOrderField::getCombOffsetFlag, &ErrorConditionalOrderField::setCombOffsetFlag)
            .add_property("combHedgeFlag", &ErrorConditionalOrderField::getCombHedgeFlag, &ErrorConditionalOrderField::setCombHedgeFlag)
            .def_readwrite("limitPrice", &ErrorConditionalOrderField::LimitPrice)
            .def_readwrite("volumeTotalOriginal", &ErrorConditionalOrderField::VolumeTotalOriginal)
            .def_readwrite("timeCondition", &ErrorConditionalOrderField::TimeCondition)
            .add_property("GTDDate", &ErrorConditionalOrderField::getGTDDate, &ErrorConditionalOrderField::setGTDDate)
            .def_readwrite("volumeCondition", &ErrorConditionalOrderField::VolumeCondition)
            .def_readwrite("minVolume", &ErrorConditionalOrderField::MinVolume)
            .def_readwrite("contingentCondition", &ErrorConditionalOrderField::ContingentCondition)
            .def_readwrite("stopPrice", &ErrorConditionalOrderField::StopPrice)
            .def_readwrite("forceCloseReason", &ErrorConditionalOrderField::ForceCloseReason)
            .def_readwrite("isAutoSuspend", &ErrorConditionalOrderField::IsAutoSuspend)
            .add_property("businessUnit", &ErrorConditionalOrderField::getBusinessUnit, &ErrorConditionalOrderField::setBusinessUnit)
            .def_readwrite("requestID", &ErrorConditionalOrderField::RequestID)
            .add_property("orderLocalID", &ErrorConditionalOrderField::getOrderLocalID, &ErrorConditionalOrderField::setOrderLocalID)
            .add_property("exchangeID", &ErrorConditionalOrderField::getExchangeID, &ErrorConditionalOrderField::setExchangeID)
            .add_property("participantID", &ErrorConditionalOrderField::getParticipantID, &ErrorConditionalOrderField::setParticipantID)
            .add_property("clientID", &ErrorConditionalOrderField::getClientID, &ErrorConditionalOrderField::setClientID)
            .add_property("exchangeInstID", &ErrorConditionalOrderField::getExchangeInstID, &ErrorConditionalOrderField::setExchangeInstID)
            .add_property("traderID", &ErrorConditionalOrderField::getTraderID, &ErrorConditionalOrderField::setTraderID)
            .def_readwrite("installID", &ErrorConditionalOrderField::InstallID)
            .def_readwrite("orderSubmitStatus", &ErrorConditionalOrderField::OrderSubmitStatus)
            .def_readwrite("notifySequence", &ErrorConditionalOrderField::NotifySequence)
            .add_property("tradingDay", &ErrorConditionalOrderField::getTradingDay, &ErrorConditionalOrderField::setTradingDay)
            .def_readwrite("settlementID", &ErrorConditionalOrderField::SettlementID)
            .add_property("orderSysID", &ErrorConditionalOrderField::getOrderSysID, &ErrorConditionalOrderField::setOrderSysID)
            .def_readwrite("orderSource", &ErrorConditionalOrderField::OrderSource)
            .def_readwrite("orderStatus", &ErrorConditionalOrderField::OrderStatus)
            .def_readwrite("orderType", &ErrorConditionalOrderField::OrderType)
            .def_readwrite("volumeTraded", &ErrorConditionalOrderField::VolumeTraded)
            .def_readwrite("volumeTotal", &ErrorConditionalOrderField::VolumeTotal)
            .add_property("insertDate", &ErrorConditionalOrderField::getInsertDate, &ErrorConditionalOrderField::setInsertDate)
            .add_property("insertTime", &ErrorConditionalOrderField::getInsertTime, &ErrorConditionalOrderField::setInsertTime)
            .add_property("activeTime", &ErrorConditionalOrderField::getActiveTime, &ErrorConditionalOrderField::setActiveTime)
            .add_property("suspendTime", &ErrorConditionalOrderField::getSuspendTime, &ErrorConditionalOrderField::setSuspendTime)
            .add_property("updateTime", &ErrorConditionalOrderField::getUpdateTime, &ErrorConditionalOrderField::setUpdateTime)
            .add_property("cancelTime", &ErrorConditionalOrderField::getCancelTime, &ErrorConditionalOrderField::setCancelTime)
            .add_property("activeTraderID", &ErrorConditionalOrderField::getActiveTraderID, &ErrorConditionalOrderField::setActiveTraderID)
            .add_property("clearingPartID", &ErrorConditionalOrderField::getClearingPartID, &ErrorConditionalOrderField::setClearingPartID)
            .def_readwrite("sequenceNo", &ErrorConditionalOrderField::SequenceNo)
            .def_readwrite("frontID", &ErrorConditionalOrderField::FrontID)
            .def_readwrite("sessionID", &ErrorConditionalOrderField::SessionID)
            .add_property("userProductInfo", &ErrorConditionalOrderField::getUserProductInfo, &ErrorConditionalOrderField::setUserProductInfo)
            .add_property("statusMsg", &ErrorConditionalOrderField::getStatusMsg, &ErrorConditionalOrderField::setStatusMsg)
            .def_readwrite("userForceClose", &ErrorConditionalOrderField::UserForceClose)
            .add_property("activeUserID", &ErrorConditionalOrderField::getActiveUserID, &ErrorConditionalOrderField::setActiveUserID)
            .def_readwrite("brokerOrderSeq", &ErrorConditionalOrderField::BrokerOrderSeq)
            .add_property("relativeOrderSysID", &ErrorConditionalOrderField::getRelativeOrderSysID, &ErrorConditionalOrderField::setRelativeOrderSysID)
            .def_readwrite("ZCETotalTradedVolume", &ErrorConditionalOrderField::ZCETotalTradedVolume)
            .def_readwrite("errorID", &ErrorConditionalOrderField::ErrorID)
            .add_property("errorMsg", &ErrorConditionalOrderField::getErrorMsg, &ErrorConditionalOrderField::setErrorMsg)
            .def_readwrite("isSwapOrder", &ErrorConditionalOrderField::IsSwapOrder)
            .add_property("branchID", &ErrorConditionalOrderField::getBranchID, &ErrorConditionalOrderField::setBranchID)
            .add_property("investUnitID", &ErrorConditionalOrderField::getInvestUnitID, &ErrorConditionalOrderField::setInvestUnitID)
            .add_property("accountID", &ErrorConditionalOrderField::getAccountID, &ErrorConditionalOrderField::setAccountID)
            .add_property("currencyID", &ErrorConditionalOrderField::getCurrencyID, &ErrorConditionalOrderField::setCurrencyID)
            .add_property("IPAddress", &ErrorConditionalOrderField::getIPAddress, &ErrorConditionalOrderField::setIPAddress)
            .add_property("macAddress", &ErrorConditionalOrderField::getMacAddress, &ErrorConditionalOrderField::setMacAddress);

    class_<QryBrokerTradingParamsField>("QryBrokerTradingParamsField")
            .add_property("brokerID", &QryBrokerTradingParamsField::getBrokerID, &QryBrokerTradingParamsField::setBrokerID)
            .add_property("investorID", &QryBrokerTradingParamsField::getInvestorID, &QryBrokerTradingParamsField::setInvestorID)
            .add_property("currencyID", &QryBrokerTradingParamsField::getCurrencyID, &QryBrokerTradingParamsField::setCurrencyID);

    class_<BrokerTradingParamsField>("BrokerTradingParamsField")
            .add_property("brokerID", &BrokerTradingParamsField::getBrokerID, &BrokerTradingParamsField::setBrokerID)
            .add_property("investorID", &BrokerTradingParamsField::getInvestorID, &BrokerTradingParamsField::setInvestorID)
            .def_readwrite("marginPriceType", &BrokerTradingParamsField::MarginPriceType)
            .def_readwrite("algorithm", &BrokerTradingParamsField::Algorithm)
            .def_readwrite("availIncludeCloseProfit", &BrokerTradingParamsField::AvailIncludeCloseProfit)
            .add_property("currencyID", &BrokerTradingParamsField::getCurrencyID, &BrokerTradingParamsField::setCurrencyID)
            .def_readwrite("optionRoyaltyPriceType", &BrokerTradingParamsField::OptionRoyaltyPriceType);

    class_<QryBrokerTradingAlgosField>("QryBrokerTradingAlgosField")
            .add_property("brokerID", &QryBrokerTradingAlgosField::getBrokerID, &QryBrokerTradingAlgosField::setBrokerID)
            .add_property("exchangeID", &QryBrokerTradingAlgosField::getExchangeID, &QryBrokerTradingAlgosField::setExchangeID)
            .add_property("instrumentID", &QryBrokerTradingAlgosField::getInstrumentID, &QryBrokerTradingAlgosField::setInstrumentID);

    class_<BrokerTradingAlgosField>("BrokerTradingAlgosField")
            .add_property("brokerID", &BrokerTradingAlgosField::getBrokerID, &BrokerTradingAlgosField::setBrokerID)
            .add_property("exchangeID", &BrokerTradingAlgosField::getExchangeID, &BrokerTradingAlgosField::setExchangeID)
            .add_property("instrumentID", &BrokerTradingAlgosField::getInstrumentID, &BrokerTradingAlgosField::setInstrumentID)
            .def_readwrite("handlePositionAlgoID", &BrokerTradingAlgosField::HandlePositionAlgoID)
            .def_readwrite("findMarginRateAlgoID", &BrokerTradingAlgosField::FindMarginRateAlgoID)
            .def_readwrite("handleTradingAccountAlgoID", &BrokerTradingAlgosField::HandleTradingAccountAlgoID);

    class_<CFMMCTradingAccountKeyField>("CFMMCTradingAccountKeyField")
            .add_property("brokerID", &CFMMCTradingAccountKeyField::getBrokerID, &CFMMCTradingAccountKeyField::setBrokerID)
            .add_property("participantID", &CFMMCTradingAccountKeyField::getParticipantID, &CFMMCTradingAccountKeyField::setParticipantID)
            .add_property("accountID", &CFMMCTradingAccountKeyField::getAccountID, &CFMMCTradingAccountKeyField::setAccountID)
            .def_readwrite("keyID", &CFMMCTradingAccountKeyField::KeyID)
            .add_property("currentKey", &CFMMCTradingAccountKeyField::getCurrentKey, &CFMMCTradingAccountKeyField::setCurrentKey);

    class_<QryCFMMCTradingAccountKeyField>("QryCFMMCTradingAccountKeyField")
            .add_property("brokerID", &QryCFMMCTradingAccountKeyField::getBrokerID, &QryCFMMCTradingAccountKeyField::setBrokerID)
            .add_property("investorID", &QryCFMMCTradingAccountKeyField::getInvestorID, &QryCFMMCTradingAccountKeyField::setInvestorID);

    class_<EWarrantOffsetField>("EWarrantOffsetField")
            .add_property("tradingDay", &EWarrantOffsetField::getTradingDay, &EWarrantOffsetField::setTradingDay)
            .add_property("brokerID", &EWarrantOffsetField::getBrokerID, &EWarrantOffsetField::setBrokerID)
            .add_property("investorID", &EWarrantOffsetField::getInvestorID, &EWarrantOffsetField::setInvestorID)
            .add_property("exchangeID", &EWarrantOffsetField::getExchangeID, &EWarrantOffsetField::setExchangeID)
            .add_property("instrumentID", &EWarrantOffsetField::getInstrumentID, &EWarrantOffsetField::setInstrumentID)
            .def_readwrite("direction", &EWarrantOffsetField::Direction)
            .def_readwrite("hedgeFlag", &EWarrantOffsetField::HedgeFlag)
            .def_readwrite("volume", &EWarrantOffsetField::Volume);

    class_<QryEWarrantOffsetField>("QryEWarrantOffsetField")
            .add_property("brokerID", &QryEWarrantOffsetField::getBrokerID, &QryEWarrantOffsetField::setBrokerID)
            .add_property("investorID", &QryEWarrantOffsetField::getInvestorID, &QryEWarrantOffsetField::setInvestorID)
            .add_property("exchangeID", &QryEWarrantOffsetField::getExchangeID, &QryEWarrantOffsetField::setExchangeID)
            .add_property("instrumentID", &QryEWarrantOffsetField::getInstrumentID, &QryEWarrantOffsetField::setInstrumentID);

    class_<QryInvestorProductGroupMarginField>("QryInvestorProductGroupMarginField")
            .add_property("brokerID", &QryInvestorProductGroupMarginField::getBrokerID, &QryInvestorProductGroupMarginField::setBrokerID)
            .add_property("investorID", &QryInvestorProductGroupMarginField::getInvestorID, &QryInvestorProductGroupMarginField::setInvestorID)
            .add_property("productGroupID", &QryInvestorProductGroupMarginField::getProductGroupID, &QryInvestorProductGroupMarginField::setProductGroupID)
            .def_readwrite("hedgeFlag", &QryInvestorProductGroupMarginField::HedgeFlag);

    class_<InvestorProductGroupMarginField>("InvestorProductGroupMarginField")
            .add_property("productGroupID", &InvestorProductGroupMarginField::getProductGroupID, &InvestorProductGroupMarginField::setProductGroupID)
            .add_property("brokerID", &InvestorProductGroupMarginField::getBrokerID, &InvestorProductGroupMarginField::setBrokerID)
            .add_property("investorID", &InvestorProductGroupMarginField::getInvestorID, &InvestorProductGroupMarginField::setInvestorID)
            .add_property("tradingDay", &InvestorProductGroupMarginField::getTradingDay, &InvestorProductGroupMarginField::setTradingDay)
            .def_readwrite("settlementID", &InvestorProductGroupMarginField::SettlementID)
            .def_readwrite("frozenMargin", &InvestorProductGroupMarginField::FrozenMargin)
            .def_readwrite("longFrozenMargin", &InvestorProductGroupMarginField::LongFrozenMargin)
            .def_readwrite("shortFrozenMargin", &InvestorProductGroupMarginField::ShortFrozenMargin)
            .def_readwrite("useMargin", &InvestorProductGroupMarginField::UseMargin)
            .def_readwrite("longUseMargin", &InvestorProductGroupMarginField::LongUseMargin)
            .def_readwrite("shortUseMargin", &InvestorProductGroupMarginField::ShortUseMargin)
            .def_readwrite("exchMargin", &InvestorProductGroupMarginField::ExchMargin)
            .def_readwrite("longExchMargin", &InvestorProductGroupMarginField::LongExchMargin)
            .def_readwrite("shortExchMargin", &InvestorProductGroupMarginField::ShortExchMargin)
            .def_readwrite("closeProfit", &InvestorProductGroupMarginField::CloseProfit)
            .def_readwrite("frozenCommission", &InvestorProductGroupMarginField::FrozenCommission)
            .def_readwrite("commission", &InvestorProductGroupMarginField::Commission)
            .def_readwrite("frozenCash", &InvestorProductGroupMarginField::FrozenCash)
            .def_readwrite("cashIn", &InvestorProductGroupMarginField::CashIn)
            .def_readwrite("positionProfit", &InvestorProductGroupMarginField::PositionProfit)
            .def_readwrite("offsetAmount", &InvestorProductGroupMarginField::OffsetAmount)
            .def_readwrite("longOffsetAmount", &InvestorProductGroupMarginField::LongOffsetAmount)
            .def_readwrite("shortOffsetAmount", &InvestorProductGroupMarginField::ShortOffsetAmount)
            .def_readwrite("exchOffsetAmount", &InvestorProductGroupMarginField::ExchOffsetAmount)
            .def_readwrite("longExchOffsetAmount", &InvestorProductGroupMarginField::LongExchOffsetAmount)
            .def_readwrite("shortExchOffsetAmount", &InvestorProductGroupMarginField::ShortExchOffsetAmount)
            .def_readwrite("hedgeFlag", &InvestorProductGroupMarginField::HedgeFlag);

    class_<QueryCFMMCTradingAccountTokenField>("QueryCFMMCTradingAccountTokenField")
            .add_property("brokerID", &QueryCFMMCTradingAccountTokenField::getBrokerID, &QueryCFMMCTradingAccountTokenField::setBrokerID)
            .add_property("investorID", &QueryCFMMCTradingAccountTokenField::getInvestorID, &QueryCFMMCTradingAccountTokenField::setInvestorID);

    class_<CFMMCTradingAccountTokenField>("CFMMCTradingAccountTokenField")
            .add_property("brokerID", &CFMMCTradingAccountTokenField::getBrokerID, &CFMMCTradingAccountTokenField::setBrokerID)
            .add_property("participantID", &CFMMCTradingAccountTokenField::getParticipantID, &CFMMCTradingAccountTokenField::setParticipantID)
            .add_property("accountID", &CFMMCTradingAccountTokenField::getAccountID, &CFMMCTradingAccountTokenField::setAccountID)
            .def_readwrite("keyID", &CFMMCTradingAccountTokenField::KeyID)
            .add_property("token", &CFMMCTradingAccountTokenField::getToken, &CFMMCTradingAccountTokenField::setToken);

    class_<QryProductGroupField>("QryProductGroupField")
            .add_property("productID", &QryProductGroupField::getProductID, &QryProductGroupField::setProductID)
            .add_property("exchangeID", &QryProductGroupField::getExchangeID, &QryProductGroupField::setExchangeID);

    class_<ProductGroupField>("ProductGroupField")
            .add_property("productID", &ProductGroupField::getProductID, &ProductGroupField::setProductID)
            .add_property("exchangeID", &ProductGroupField::getExchangeID, &ProductGroupField::setExchangeID)
            .add_property("productGroupID", &ProductGroupField::getProductGroupID, &ProductGroupField::setProductGroupID);

    class_<BulletinField>("BulletinField")
            .add_property("exchangeID", &BulletinField::getExchangeID, &BulletinField::setExchangeID)
            .add_property("tradingDay", &BulletinField::getTradingDay, &BulletinField::setTradingDay)
            .def_readwrite("bulletinID", &BulletinField::BulletinID)
            .def_readwrite("sequenceNo", &BulletinField::SequenceNo)
            .add_property("newsType", &BulletinField::getNewsType, &BulletinField::setNewsType)
            .def_readwrite("newsUrgency", &BulletinField::NewsUrgency)
            .add_property("sendTime", &BulletinField::getSendTime, &BulletinField::setSendTime)
            .add_property("abstract", &BulletinField::getAbstract, &BulletinField::setAbstract)
            .add_property("comeFrom", &BulletinField::getComeFrom, &BulletinField::setComeFrom)
            .add_property("content", &BulletinField::getContent, &BulletinField::setContent)
            .add_property("URLLink", &BulletinField::getURLLink, &BulletinField::setURLLink)
            .add_property("marketID", &BulletinField::getMarketID, &BulletinField::setMarketID);

    class_<ReqTransferField>("ReqTransferField")
            .add_property("tradeCode", &ReqTransferField::getTradeCode, &ReqTransferField::setTradeCode)
            .add_property("bankID", &ReqTransferField::getBankID, &ReqTransferField::setBankID)
            .add_property("bankBranchID", &ReqTransferField::getBankBranchID, &ReqTransferField::setBankBranchID)
            .add_property("brokerID", &ReqTransferField::getBrokerID, &ReqTransferField::setBrokerID)
            .add_property("brokerBranchID", &ReqTransferField::getBrokerBranchID, &ReqTransferField::setBrokerBranchID)
            .add_property("tradeDate", &ReqTransferField::getTradeDate, &ReqTransferField::setTradeDate)
            .add_property("tradeTime", &ReqTransferField::getTradeTime, &ReqTransferField::setTradeTime)
            .add_property("bankSerial", &ReqTransferField::getBankSerial, &ReqTransferField::setBankSerial)
            .add_property("tradingDay", &ReqTransferField::getTradingDay, &ReqTransferField::setTradingDay)
            .def_readwrite("plateSerial", &ReqTransferField::PlateSerial)
            .def_readwrite("lastFragment", &ReqTransferField::LastFragment)
            .def_readwrite("sessionID", &ReqTransferField::SessionID)
            .add_property("customerName", &ReqTransferField::getCustomerName, &ReqTransferField::setCustomerName)
            .def_readwrite("idCardType", &ReqTransferField::IdCardType)
            .add_property("identifiedCardNo", &ReqTransferField::getIdentifiedCardNo, &ReqTransferField::setIdentifiedCardNo)
            .def_readwrite("custType", &ReqTransferField::CustType)
            .add_property("bankAccount", &ReqTransferField::getBankAccount, &ReqTransferField::setBankAccount)
            .add_property("bankPassWord", &ReqTransferField::getBankPassWord, &ReqTransferField::setBankPassWord)
            .add_property("accountID", &ReqTransferField::getAccountID, &ReqTransferField::setAccountID)
            .add_property("password", &ReqTransferField::getPassword, &ReqTransferField::setPassword)
            .def_readwrite("installID", &ReqTransferField::InstallID)
            .def_readwrite("futureSerial", &ReqTransferField::FutureSerial)
            .add_property("userID", &ReqTransferField::getUserID, &ReqTransferField::setUserID)
            .def_readwrite("verifyCertNoFlag", &ReqTransferField::VerifyCertNoFlag)
            .add_property("currencyID", &ReqTransferField::getCurrencyID, &ReqTransferField::setCurrencyID)
            .def_readwrite("tradeAmount", &ReqTransferField::TradeAmount)
            .def_readwrite("futureFetchAmount", &ReqTransferField::FutureFetchAmount)
            .def_readwrite("feePayFlag", &ReqTransferField::FeePayFlag)
            .def_readwrite("custFee", &ReqTransferField::CustFee)
            .def_readwrite("brokerFee", &ReqTransferField::BrokerFee)
            .add_property("message", &ReqTransferField::getMessage, &ReqTransferField::setMessage)
            .add_property("digest", &ReqTransferField::getDigest, &ReqTransferField::setDigest)
            .def_readwrite("bankAccType", &ReqTransferField::BankAccType)
            .add_property("deviceID", &ReqTransferField::getDeviceID, &ReqTransferField::setDeviceID)
            .def_readwrite("bankSecuAccType", &ReqTransferField::BankSecuAccType)
            .add_property("brokerIDByBank", &ReqTransferField::getBrokerIDByBank, &ReqTransferField::setBrokerIDByBank)
            .add_property("bankSecuAcc", &ReqTransferField::getBankSecuAcc, &ReqTransferField::setBankSecuAcc)
            .def_readwrite("bankPwdFlag", &ReqTransferField::BankPwdFlag)
            .def_readwrite("secuPwdFlag", &ReqTransferField::SecuPwdFlag)
            .add_property("operNo", &ReqTransferField::getOperNo, &ReqTransferField::setOperNo)
            .def_readwrite("requestID", &ReqTransferField::RequestID)
            .def_readwrite("TID", &ReqTransferField::TID)
            .def_readwrite("transferStatus", &ReqTransferField::TransferStatus)
            .add_property("longCustomerName", &ReqTransferField::getLongCustomerName, &ReqTransferField::setLongCustomerName);

    class_<RspTransferField>("RspTransferField")
            .add_property("tradeCode", &RspTransferField::getTradeCode, &RspTransferField::setTradeCode)
            .add_property("bankID", &RspTransferField::getBankID, &RspTransferField::setBankID)
            .add_property("bankBranchID", &RspTransferField::getBankBranchID, &RspTransferField::setBankBranchID)
            .add_property("brokerID", &RspTransferField::getBrokerID, &RspTransferField::setBrokerID)
            .add_property("brokerBranchID", &RspTransferField::getBrokerBranchID, &RspTransferField::setBrokerBranchID)
            .add_property("tradeDate", &RspTransferField::getTradeDate, &RspTransferField::setTradeDate)
            .add_property("tradeTime", &RspTransferField::getTradeTime, &RspTransferField::setTradeTime)
            .add_property("bankSerial", &RspTransferField::getBankSerial, &RspTransferField::setBankSerial)
            .add_property("tradingDay", &RspTransferField::getTradingDay, &RspTransferField::setTradingDay)
            .def_readwrite("plateSerial", &RspTransferField::PlateSerial)
            .def_readwrite("lastFragment", &RspTransferField::LastFragment)
            .def_readwrite("sessionID", &RspTransferField::SessionID)
            .add_property("customerName", &RspTransferField::getCustomerName, &RspTransferField::setCustomerName)
            .def_readwrite("idCardType", &RspTransferField::IdCardType)
            .add_property("identifiedCardNo", &RspTransferField::getIdentifiedCardNo, &RspTransferField::setIdentifiedCardNo)
            .def_readwrite("custType", &RspTransferField::CustType)
            .add_property("bankAccount", &RspTransferField::getBankAccount, &RspTransferField::setBankAccount)
            .add_property("bankPassWord", &RspTransferField::getBankPassWord, &RspTransferField::setBankPassWord)
            .add_property("accountID", &RspTransferField::getAccountID, &RspTransferField::setAccountID)
            .add_property("password", &RspTransferField::getPassword, &RspTransferField::setPassword)
            .def_readwrite("installID", &RspTransferField::InstallID)
            .def_readwrite("futureSerial", &RspTransferField::FutureSerial)
            .add_property("userID", &RspTransferField::getUserID, &RspTransferField::setUserID)
            .def_readwrite("verifyCertNoFlag", &RspTransferField::VerifyCertNoFlag)
            .add_property("currencyID", &RspTransferField::getCurrencyID, &RspTransferField::setCurrencyID)
            .def_readwrite("tradeAmount", &RspTransferField::TradeAmount)
            .def_readwrite("futureFetchAmount", &RspTransferField::FutureFetchAmount)
            .def_readwrite("feePayFlag", &RspTransferField::FeePayFlag)
            .def_readwrite("custFee", &RspTransferField::CustFee)
            .def_readwrite("brokerFee", &RspTransferField::BrokerFee)
            .add_property("message", &RspTransferField::getMessage, &RspTransferField::setMessage)
            .add_property("digest", &RspTransferField::getDigest, &RspTransferField::setDigest)
            .def_readwrite("bankAccType", &RspTransferField::BankAccType)
            .add_property("deviceID", &RspTransferField::getDeviceID, &RspTransferField::setDeviceID)
            .def_readwrite("bankSecuAccType", &RspTransferField::BankSecuAccType)
            .add_property("brokerIDByBank", &RspTransferField::getBrokerIDByBank, &RspTransferField::setBrokerIDByBank)
            .add_property("bankSecuAcc", &RspTransferField::getBankSecuAcc, &RspTransferField::setBankSecuAcc)
            .def_readwrite("bankPwdFlag", &RspTransferField::BankPwdFlag)
            .def_readwrite("secuPwdFlag", &RspTransferField::SecuPwdFlag)
            .add_property("operNo", &RspTransferField::getOperNo, &RspTransferField::setOperNo)
            .def_readwrite("requestID", &RspTransferField::RequestID)
            .def_readwrite("TID", &RspTransferField::TID)
            .def_readwrite("transferStatus", &RspTransferField::TransferStatus)
            .def_readwrite("errorID", &RspTransferField::ErrorID)
            .add_property("errorMsg", &RspTransferField::getErrorMsg, &RspTransferField::setErrorMsg)
            .add_property("longCustomerName", &RspTransferField::getLongCustomerName, &RspTransferField::setLongCustomerName);

    class_<ReqRepealField>("ReqRepealField")
            .def_readwrite("repealTimeInterval", &ReqRepealField::RepealTimeInterval)
            .def_readwrite("repealedTimes", &ReqRepealField::RepealedTimes)
            .def_readwrite("bankRepealFlag", &ReqRepealField::BankRepealFlag)
            .def_readwrite("brokerRepealFlag", &ReqRepealField::BrokerRepealFlag)
            .def_readwrite("plateRepealSerial", &ReqRepealField::PlateRepealSerial)
            .add_property("bankRepealSerial", &ReqRepealField::getBankRepealSerial, &ReqRepealField::setBankRepealSerial)
            .def_readwrite("futureRepealSerial", &ReqRepealField::FutureRepealSerial)
            .add_property("tradeCode", &ReqRepealField::getTradeCode, &ReqRepealField::setTradeCode)
            .add_property("bankID", &ReqRepealField::getBankID, &ReqRepealField::setBankID)
            .add_property("bankBranchID", &ReqRepealField::getBankBranchID, &ReqRepealField::setBankBranchID)
            .add_property("brokerID", &ReqRepealField::getBrokerID, &ReqRepealField::setBrokerID)
            .add_property("brokerBranchID", &ReqRepealField::getBrokerBranchID, &ReqRepealField::setBrokerBranchID)
            .add_property("tradeDate", &ReqRepealField::getTradeDate, &ReqRepealField::setTradeDate)
            .add_property("tradeTime", &ReqRepealField::getTradeTime, &ReqRepealField::setTradeTime)
            .add_property("bankSerial", &ReqRepealField::getBankSerial, &ReqRepealField::setBankSerial)
            .add_property("tradingDay", &ReqRepealField::getTradingDay, &ReqRepealField::setTradingDay)
            .def_readwrite("plateSerial", &ReqRepealField::PlateSerial)
            .def_readwrite("lastFragment", &ReqRepealField::LastFragment)
            .def_readwrite("sessionID", &ReqRepealField::SessionID)
            .add_property("customerName", &ReqRepealField::getCustomerName, &ReqRepealField::setCustomerName)
            .def_readwrite("idCardType", &ReqRepealField::IdCardType)
            .add_property("identifiedCardNo", &ReqRepealField::getIdentifiedCardNo, &ReqRepealField::setIdentifiedCardNo)
            .def_readwrite("custType", &ReqRepealField::CustType)
            .add_property("bankAccount", &ReqRepealField::getBankAccount, &ReqRepealField::setBankAccount)
            .add_property("bankPassWord", &ReqRepealField::getBankPassWord, &ReqRepealField::setBankPassWord)
            .add_property("accountID", &ReqRepealField::getAccountID, &ReqRepealField::setAccountID)
            .add_property("password", &ReqRepealField::getPassword, &ReqRepealField::setPassword)
            .def_readwrite("installID", &ReqRepealField::InstallID)
            .def_readwrite("futureSerial", &ReqRepealField::FutureSerial)
            .add_property("userID", &ReqRepealField::getUserID, &ReqRepealField::setUserID)
            .def_readwrite("verifyCertNoFlag", &ReqRepealField::VerifyCertNoFlag)
            .add_property("currencyID", &ReqRepealField::getCurrencyID, &ReqRepealField::setCurrencyID)
            .def_readwrite("tradeAmount", &ReqRepealField::TradeAmount)
            .def_readwrite("futureFetchAmount", &ReqRepealField::FutureFetchAmount)
            .def_readwrite("feePayFlag", &ReqRepealField::FeePayFlag)
            .def_readwrite("custFee", &ReqRepealField::CustFee)
            .def_readwrite("brokerFee", &ReqRepealField::BrokerFee)
            .add_property("message", &ReqRepealField::getMessage, &ReqRepealField::setMessage)
            .add_property("digest", &ReqRepealField::getDigest, &ReqRepealField::setDigest)
            .def_readwrite("bankAccType", &ReqRepealField::BankAccType)
            .add_property("deviceID", &ReqRepealField::getDeviceID, &ReqRepealField::setDeviceID)
            .def_readwrite("bankSecuAccType", &ReqRepealField::BankSecuAccType)
            .add_property("brokerIDByBank", &ReqRepealField::getBrokerIDByBank, &ReqRepealField::setBrokerIDByBank)
            .add_property("bankSecuAcc", &ReqRepealField::getBankSecuAcc, &ReqRepealField::setBankSecuAcc)
            .def_readwrite("bankPwdFlag", &ReqRepealField::BankPwdFlag)
            .def_readwrite("secuPwdFlag", &ReqRepealField::SecuPwdFlag)
            .add_property("operNo", &ReqRepealField::getOperNo, &ReqRepealField::setOperNo)
            .def_readwrite("requestID", &ReqRepealField::RequestID)
            .def_readwrite("TID", &ReqRepealField::TID)
            .def_readwrite("transferStatus", &ReqRepealField::TransferStatus)
            .add_property("longCustomerName", &ReqRepealField::getLongCustomerName, &ReqRepealField::setLongCustomerName);

    class_<RspRepealField>("RspRepealField")
            .def_readwrite("repealTimeInterval", &RspRepealField::RepealTimeInterval)
            .def_readwrite("repealedTimes", &RspRepealField::RepealedTimes)
            .def_readwrite("bankRepealFlag", &RspRepealField::BankRepealFlag)
            .def_readwrite("brokerRepealFlag", &RspRepealField::BrokerRepealFlag)
            .def_readwrite("plateRepealSerial", &RspRepealField::PlateRepealSerial)
            .add_property("bankRepealSerial", &RspRepealField::getBankRepealSerial, &RspRepealField::setBankRepealSerial)
            .def_readwrite("futureRepealSerial", &RspRepealField::FutureRepealSerial)
            .add_property("tradeCode", &RspRepealField::getTradeCode, &RspRepealField::setTradeCode)
            .add_property("bankID", &RspRepealField::getBankID, &RspRepealField::setBankID)
            .add_property("bankBranchID", &RspRepealField::getBankBranchID, &RspRepealField::setBankBranchID)
            .add_property("brokerID", &RspRepealField::getBrokerID, &RspRepealField::setBrokerID)
            .add_property("brokerBranchID", &RspRepealField::getBrokerBranchID, &RspRepealField::setBrokerBranchID)
            .add_property("tradeDate", &RspRepealField::getTradeDate, &RspRepealField::setTradeDate)
            .add_property("tradeTime", &RspRepealField::getTradeTime, &RspRepealField::setTradeTime)
            .add_property("bankSerial", &RspRepealField::getBankSerial, &RspRepealField::setBankSerial)
            .add_property("tradingDay", &RspRepealField::getTradingDay, &RspRepealField::setTradingDay)
            .def_readwrite("plateSerial", &RspRepealField::PlateSerial)
            .def_readwrite("lastFragment", &RspRepealField::LastFragment)
            .def_readwrite("sessionID", &RspRepealField::SessionID)
            .add_property("customerName", &RspRepealField::getCustomerName, &RspRepealField::setCustomerName)
            .def_readwrite("idCardType", &RspRepealField::IdCardType)
            .add_property("identifiedCardNo", &RspRepealField::getIdentifiedCardNo, &RspRepealField::setIdentifiedCardNo)
            .def_readwrite("custType", &RspRepealField::CustType)
            .add_property("bankAccount", &RspRepealField::getBankAccount, &RspRepealField::setBankAccount)
            .add_property("bankPassWord", &RspRepealField::getBankPassWord, &RspRepealField::setBankPassWord)
            .add_property("accountID", &RspRepealField::getAccountID, &RspRepealField::setAccountID)
            .add_property("password", &RspRepealField::getPassword, &RspRepealField::setPassword)
            .def_readwrite("installID", &RspRepealField::InstallID)
            .def_readwrite("futureSerial", &RspRepealField::FutureSerial)
            .add_property("userID", &RspRepealField::getUserID, &RspRepealField::setUserID)
            .def_readwrite("verifyCertNoFlag", &RspRepealField::VerifyCertNoFlag)
            .add_property("currencyID", &RspRepealField::getCurrencyID, &RspRepealField::setCurrencyID)
            .def_readwrite("tradeAmount", &RspRepealField::TradeAmount)
            .def_readwrite("futureFetchAmount", &RspRepealField::FutureFetchAmount)
            .def_readwrite("feePayFlag", &RspRepealField::FeePayFlag)
            .def_readwrite("custFee", &RspRepealField::CustFee)
            .def_readwrite("brokerFee", &RspRepealField::BrokerFee)
            .add_property("message", &RspRepealField::getMessage, &RspRepealField::setMessage)
            .add_property("digest", &RspRepealField::getDigest, &RspRepealField::setDigest)
            .def_readwrite("bankAccType", &RspRepealField::BankAccType)
            .add_property("deviceID", &RspRepealField::getDeviceID, &RspRepealField::setDeviceID)
            .def_readwrite("bankSecuAccType", &RspRepealField::BankSecuAccType)
            .add_property("brokerIDByBank", &RspRepealField::getBrokerIDByBank, &RspRepealField::setBrokerIDByBank)
            .add_property("bankSecuAcc", &RspRepealField::getBankSecuAcc, &RspRepealField::setBankSecuAcc)
            .def_readwrite("bankPwdFlag", &RspRepealField::BankPwdFlag)
            .def_readwrite("secuPwdFlag", &RspRepealField::SecuPwdFlag)
            .add_property("operNo", &RspRepealField::getOperNo, &RspRepealField::setOperNo)
            .def_readwrite("requestID", &RspRepealField::RequestID)
            .def_readwrite("TID", &RspRepealField::TID)
            .def_readwrite("transferStatus", &RspRepealField::TransferStatus)
            .def_readwrite("errorID", &RspRepealField::ErrorID)
            .add_property("errorMsg", &RspRepealField::getErrorMsg, &RspRepealField::setErrorMsg)
            .add_property("longCustomerName", &RspRepealField::getLongCustomerName, &RspRepealField::setLongCustomerName);

    class_<ReqQueryAccountField>("ReqQueryAccountField")
            .add_property("tradeCode", &ReqQueryAccountField::getTradeCode, &ReqQueryAccountField::setTradeCode)
            .add_property("bankID", &ReqQueryAccountField::getBankID, &ReqQueryAccountField::setBankID)
            .add_property("bankBranchID", &ReqQueryAccountField::getBankBranchID, &ReqQueryAccountField::setBankBranchID)
            .add_property("brokerID", &ReqQueryAccountField::getBrokerID, &ReqQueryAccountField::setBrokerID)
            .add_property("brokerBranchID", &ReqQueryAccountField::getBrokerBranchID, &ReqQueryAccountField::setBrokerBranchID)
            .add_property("tradeDate", &ReqQueryAccountField::getTradeDate, &ReqQueryAccountField::setTradeDate)
            .add_property("tradeTime", &ReqQueryAccountField::getTradeTime, &ReqQueryAccountField::setTradeTime)
            .add_property("bankSerial", &ReqQueryAccountField::getBankSerial, &ReqQueryAccountField::setBankSerial)
            .add_property("tradingDay", &ReqQueryAccountField::getTradingDay, &ReqQueryAccountField::setTradingDay)
            .def_readwrite("plateSerial", &ReqQueryAccountField::PlateSerial)
            .def_readwrite("lastFragment", &ReqQueryAccountField::LastFragment)
            .def_readwrite("sessionID", &ReqQueryAccountField::SessionID)
            .add_property("customerName", &ReqQueryAccountField::getCustomerName, &ReqQueryAccountField::setCustomerName)
            .def_readwrite("idCardType", &ReqQueryAccountField::IdCardType)
            .add_property("identifiedCardNo", &ReqQueryAccountField::getIdentifiedCardNo, &ReqQueryAccountField::setIdentifiedCardNo)
            .def_readwrite("custType", &ReqQueryAccountField::CustType)
            .add_property("bankAccount", &ReqQueryAccountField::getBankAccount, &ReqQueryAccountField::setBankAccount)
            .add_property("bankPassWord", &ReqQueryAccountField::getBankPassWord, &ReqQueryAccountField::setBankPassWord)
            .add_property("accountID", &ReqQueryAccountField::getAccountID, &ReqQueryAccountField::setAccountID)
            .add_property("password", &ReqQueryAccountField::getPassword, &ReqQueryAccountField::setPassword)
            .def_readwrite("futureSerial", &ReqQueryAccountField::FutureSerial)
            .def_readwrite("installID", &ReqQueryAccountField::InstallID)
            .add_property("userID", &ReqQueryAccountField::getUserID, &ReqQueryAccountField::setUserID)
            .def_readwrite("verifyCertNoFlag", &ReqQueryAccountField::VerifyCertNoFlag)
            .add_property("currencyID", &ReqQueryAccountField::getCurrencyID, &ReqQueryAccountField::setCurrencyID)
            .add_property("digest", &ReqQueryAccountField::getDigest, &ReqQueryAccountField::setDigest)
            .def_readwrite("bankAccType", &ReqQueryAccountField::BankAccType)
            .add_property("deviceID", &ReqQueryAccountField::getDeviceID, &ReqQueryAccountField::setDeviceID)
            .def_readwrite("bankSecuAccType", &ReqQueryAccountField::BankSecuAccType)
            .add_property("brokerIDByBank", &ReqQueryAccountField::getBrokerIDByBank, &ReqQueryAccountField::setBrokerIDByBank)
            .add_property("bankSecuAcc", &ReqQueryAccountField::getBankSecuAcc, &ReqQueryAccountField::setBankSecuAcc)
            .def_readwrite("bankPwdFlag", &ReqQueryAccountField::BankPwdFlag)
            .def_readwrite("secuPwdFlag", &ReqQueryAccountField::SecuPwdFlag)
            .add_property("operNo", &ReqQueryAccountField::getOperNo, &ReqQueryAccountField::setOperNo)
            .def_readwrite("requestID", &ReqQueryAccountField::RequestID)
            .def_readwrite("TID", &ReqQueryAccountField::TID)
            .add_property("longCustomerName", &ReqQueryAccountField::getLongCustomerName, &ReqQueryAccountField::setLongCustomerName);

    class_<NotifyQueryAccountField>("NotifyQueryAccountField")
            .add_property("tradeCode", &NotifyQueryAccountField::getTradeCode, &NotifyQueryAccountField::setTradeCode)
            .add_property("bankID", &NotifyQueryAccountField::getBankID, &NotifyQueryAccountField::setBankID)
            .add_property("bankBranchID", &NotifyQueryAccountField::getBankBranchID, &NotifyQueryAccountField::setBankBranchID)
            .add_property("brokerID", &NotifyQueryAccountField::getBrokerID, &NotifyQueryAccountField::setBrokerID)
            .add_property("brokerBranchID", &NotifyQueryAccountField::getBrokerBranchID, &NotifyQueryAccountField::setBrokerBranchID)
            .add_property("tradeDate", &NotifyQueryAccountField::getTradeDate, &NotifyQueryAccountField::setTradeDate)
            .add_property("tradeTime", &NotifyQueryAccountField::getTradeTime, &NotifyQueryAccountField::setTradeTime)
            .add_property("bankSerial", &NotifyQueryAccountField::getBankSerial, &NotifyQueryAccountField::setBankSerial)
            .add_property("tradingDay", &NotifyQueryAccountField::getTradingDay, &NotifyQueryAccountField::setTradingDay)
            .def_readwrite("plateSerial", &NotifyQueryAccountField::PlateSerial)
            .def_readwrite("lastFragment", &NotifyQueryAccountField::LastFragment)
            .def_readwrite("sessionID", &NotifyQueryAccountField::SessionID)
            .add_property("customerName", &NotifyQueryAccountField::getCustomerName, &NotifyQueryAccountField::setCustomerName)
            .def_readwrite("idCardType", &NotifyQueryAccountField::IdCardType)
            .add_property("identifiedCardNo", &NotifyQueryAccountField::getIdentifiedCardNo, &NotifyQueryAccountField::setIdentifiedCardNo)
            .def_readwrite("custType", &NotifyQueryAccountField::CustType)
            .add_property("bankAccount", &NotifyQueryAccountField::getBankAccount, &NotifyQueryAccountField::setBankAccount)
            .add_property("bankPassWord", &NotifyQueryAccountField::getBankPassWord, &NotifyQueryAccountField::setBankPassWord)
            .add_property("accountID", &NotifyQueryAccountField::getAccountID, &NotifyQueryAccountField::setAccountID)
            .add_property("password", &NotifyQueryAccountField::getPassword, &NotifyQueryAccountField::setPassword)
            .def_readwrite("futureSerial", &NotifyQueryAccountField::FutureSerial)
            .def_readwrite("installID", &NotifyQueryAccountField::InstallID)
            .add_property("userID", &NotifyQueryAccountField::getUserID, &NotifyQueryAccountField::setUserID)
            .def_readwrite("verifyCertNoFlag", &NotifyQueryAccountField::VerifyCertNoFlag)
            .add_property("currencyID", &NotifyQueryAccountField::getCurrencyID, &NotifyQueryAccountField::setCurrencyID)
            .add_property("digest", &NotifyQueryAccountField::getDigest, &NotifyQueryAccountField::setDigest)
            .def_readwrite("bankAccType", &NotifyQueryAccountField::BankAccType)
            .add_property("deviceID", &NotifyQueryAccountField::getDeviceID, &NotifyQueryAccountField::setDeviceID)
            .def_readwrite("bankSecuAccType", &NotifyQueryAccountField::BankSecuAccType)
            .add_property("brokerIDByBank", &NotifyQueryAccountField::getBrokerIDByBank, &NotifyQueryAccountField::setBrokerIDByBank)
            .add_property("bankSecuAcc", &NotifyQueryAccountField::getBankSecuAcc, &NotifyQueryAccountField::setBankSecuAcc)
            .def_readwrite("bankPwdFlag", &NotifyQueryAccountField::BankPwdFlag)
            .def_readwrite("secuPwdFlag", &NotifyQueryAccountField::SecuPwdFlag)
            .add_property("operNo", &NotifyQueryAccountField::getOperNo, &NotifyQueryAccountField::setOperNo)
            .def_readwrite("requestID", &NotifyQueryAccountField::RequestID)
            .def_readwrite("TID", &NotifyQueryAccountField::TID)
            .def_readwrite("bankUseAmount", &NotifyQueryAccountField::BankUseAmount)
            .def_readwrite("bankFetchAmount", &NotifyQueryAccountField::BankFetchAmount)
            .def_readwrite("errorID", &NotifyQueryAccountField::ErrorID)
            .add_property("errorMsg", &NotifyQueryAccountField::getErrorMsg, &NotifyQueryAccountField::setErrorMsg)
            .add_property("longCustomerName", &NotifyQueryAccountField::getLongCustomerName, &NotifyQueryAccountField::setLongCustomerName);

    class_<TransferSerialField>("TransferSerialField")
            .def_readwrite("plateSerial", &TransferSerialField::PlateSerial)
            .add_property("tradeDate", &TransferSerialField::getTradeDate, &TransferSerialField::setTradeDate)
            .add_property("tradingDay", &TransferSerialField::getTradingDay, &TransferSerialField::setTradingDay)
            .add_property("tradeTime", &TransferSerialField::getTradeTime, &TransferSerialField::setTradeTime)
            .add_property("tradeCode", &TransferSerialField::getTradeCode, &TransferSerialField::setTradeCode)
            .def_readwrite("sessionID", &TransferSerialField::SessionID)
            .add_property("bankID", &TransferSerialField::getBankID, &TransferSerialField::setBankID)
            .add_property("bankBranchID", &TransferSerialField::getBankBranchID, &TransferSerialField::setBankBranchID)
            .def_readwrite("bankAccType", &TransferSerialField::BankAccType)
            .add_property("bankAccount", &TransferSerialField::getBankAccount, &TransferSerialField::setBankAccount)
            .add_property("bankSerial", &TransferSerialField::getBankSerial, &TransferSerialField::setBankSerial)
            .add_property("brokerID", &TransferSerialField::getBrokerID, &TransferSerialField::setBrokerID)
            .add_property("brokerBranchID", &TransferSerialField::getBrokerBranchID, &TransferSerialField::setBrokerBranchID)
            .def_readwrite("futureAccType", &TransferSerialField::FutureAccType)
            .add_property("accountID", &TransferSerialField::getAccountID, &TransferSerialField::setAccountID)
            .add_property("investorID", &TransferSerialField::getInvestorID, &TransferSerialField::setInvestorID)
            .def_readwrite("futureSerial", &TransferSerialField::FutureSerial)
            .def_readwrite("idCardType", &TransferSerialField::IdCardType)
            .add_property("identifiedCardNo", &TransferSerialField::getIdentifiedCardNo, &TransferSerialField::setIdentifiedCardNo)
            .add_property("currencyID", &TransferSerialField::getCurrencyID, &TransferSerialField::setCurrencyID)
            .def_readwrite("tradeAmount", &TransferSerialField::TradeAmount)
            .def_readwrite("custFee", &TransferSerialField::CustFee)
            .def_readwrite("brokerFee", &TransferSerialField::BrokerFee)
            .def_readwrite("availabilityFlag", &TransferSerialField::AvailabilityFlag)
            .add_property("operatorCode", &TransferSerialField::getOperatorCode, &TransferSerialField::setOperatorCode)
            .add_property("bankNewAccount", &TransferSerialField::getBankNewAccount, &TransferSerialField::setBankNewAccount)
            .def_readwrite("errorID", &TransferSerialField::ErrorID)
            .add_property("errorMsg", &TransferSerialField::getErrorMsg, &TransferSerialField::setErrorMsg);

    class_<QryTransferSerialField>("QryTransferSerialField")
            .add_property("brokerID", &QryTransferSerialField::getBrokerID, &QryTransferSerialField::setBrokerID)
            .add_property("accountID", &QryTransferSerialField::getAccountID, &QryTransferSerialField::setAccountID)
            .add_property("bankID", &QryTransferSerialField::getBankID, &QryTransferSerialField::setBankID)
            .add_property("currencyID", &QryTransferSerialField::getCurrencyID, &QryTransferSerialField::setCurrencyID);

    class_<QryAccountregisterField>("QryAccountregisterField")
            .add_property("brokerID", &QryAccountregisterField::getBrokerID, &QryAccountregisterField::setBrokerID)
            .add_property("accountID", &QryAccountregisterField::getAccountID, &QryAccountregisterField::setAccountID)
            .add_property("bankID", &QryAccountregisterField::getBankID, &QryAccountregisterField::setBankID)
            .add_property("bankBranchID", &QryAccountregisterField::getBankBranchID, &QryAccountregisterField::setBankBranchID)
            .add_property("currencyID", &QryAccountregisterField::getCurrencyID, &QryAccountregisterField::setCurrencyID);

    class_<AccountregisterField>("AccountregisterField")
            .add_property("tradeDay", &AccountregisterField::getTradeDay, &AccountregisterField::setTradeDay)
            .add_property("bankID", &AccountregisterField::getBankID, &AccountregisterField::setBankID)
            .add_property("bankBranchID", &AccountregisterField::getBankBranchID, &AccountregisterField::setBankBranchID)
            .add_property("bankAccount", &AccountregisterField::getBankAccount, &AccountregisterField::setBankAccount)
            .add_property("brokerID", &AccountregisterField::getBrokerID, &AccountregisterField::setBrokerID)
            .add_property("brokerBranchID", &AccountregisterField::getBrokerBranchID, &AccountregisterField::setBrokerBranchID)
            .add_property("accountID", &AccountregisterField::getAccountID, &AccountregisterField::setAccountID)
            .def_readwrite("idCardType", &AccountregisterField::IdCardType)
            .add_property("identifiedCardNo", &AccountregisterField::getIdentifiedCardNo, &AccountregisterField::setIdentifiedCardNo)
            .add_property("customerName", &AccountregisterField::getCustomerName, &AccountregisterField::setCustomerName)
            .add_property("currencyID", &AccountregisterField::getCurrencyID, &AccountregisterField::setCurrencyID)
            .def_readwrite("openOrDestroy", &AccountregisterField::OpenOrDestroy)
            .add_property("regDate", &AccountregisterField::getRegDate, &AccountregisterField::setRegDate)
            .add_property("outDate", &AccountregisterField::getOutDate, &AccountregisterField::setOutDate)
            .def_readwrite("TID", &AccountregisterField::TID)
            .def_readwrite("custType", &AccountregisterField::CustType)
            .def_readwrite("bankAccType", &AccountregisterField::BankAccType)
            .add_property("longCustomerName", &AccountregisterField::getLongCustomerName, &AccountregisterField::setLongCustomerName);

    class_<OpenAccountField>("OpenAccountField")
            .add_property("tradeCode", &OpenAccountField::getTradeCode, &OpenAccountField::setTradeCode)
            .add_property("bankID", &OpenAccountField::getBankID, &OpenAccountField::setBankID)
            .add_property("bankBranchID", &OpenAccountField::getBankBranchID, &OpenAccountField::setBankBranchID)
            .add_property("brokerID", &OpenAccountField::getBrokerID, &OpenAccountField::setBrokerID)
            .add_property("brokerBranchID", &OpenAccountField::getBrokerBranchID, &OpenAccountField::setBrokerBranchID)
            .add_property("tradeDate", &OpenAccountField::getTradeDate, &OpenAccountField::setTradeDate)
            .add_property("tradeTime", &OpenAccountField::getTradeTime, &OpenAccountField::setTradeTime)
            .add_property("bankSerial", &OpenAccountField::getBankSerial, &OpenAccountField::setBankSerial)
            .add_property("tradingDay", &OpenAccountField::getTradingDay, &OpenAccountField::setTradingDay)
            .def_readwrite("plateSerial", &OpenAccountField::PlateSerial)
            .def_readwrite("lastFragment", &OpenAccountField::LastFragment)
            .def_readwrite("sessionID", &OpenAccountField::SessionID)
            .add_property("customerName", &OpenAccountField::getCustomerName, &OpenAccountField::setCustomerName)
            .def_readwrite("idCardType", &OpenAccountField::IdCardType)
            .add_property("identifiedCardNo", &OpenAccountField::getIdentifiedCardNo, &OpenAccountField::setIdentifiedCardNo)
            .def_readwrite("gender", &OpenAccountField::Gender)
            .add_property("countryCode", &OpenAccountField::getCountryCode, &OpenAccountField::setCountryCode)
            .def_readwrite("custType", &OpenAccountField::CustType)
            .add_property("address", &OpenAccountField::getAddress, &OpenAccountField::setAddress)
            .add_property("zipCode", &OpenAccountField::getZipCode, &OpenAccountField::setZipCode)
            .add_property("telephone", &OpenAccountField::getTelephone, &OpenAccountField::setTelephone)
            .add_property("mobilePhone", &OpenAccountField::getMobilePhone, &OpenAccountField::setMobilePhone)
            .add_property("fax", &OpenAccountField::getFax, &OpenAccountField::setFax)
            .add_property("EMail", &OpenAccountField::getEMail, &OpenAccountField::setEMail)
            .def_readwrite("moneyAccountStatus", &OpenAccountField::MoneyAccountStatus)
            .add_property("bankAccount", &OpenAccountField::getBankAccount, &OpenAccountField::setBankAccount)
            .add_property("bankPassWord", &OpenAccountField::getBankPassWord, &OpenAccountField::setBankPassWord)
            .add_property("accountID", &OpenAccountField::getAccountID, &OpenAccountField::setAccountID)
            .add_property("password", &OpenAccountField::getPassword, &OpenAccountField::setPassword)
            .def_readwrite("installID", &OpenAccountField::InstallID)
            .def_readwrite("verifyCertNoFlag", &OpenAccountField::VerifyCertNoFlag)
            .add_property("currencyID", &OpenAccountField::getCurrencyID, &OpenAccountField::setCurrencyID)
            .def_readwrite("cashExchangeCode", &OpenAccountField::CashExchangeCode)
            .add_property("digest", &OpenAccountField::getDigest, &OpenAccountField::setDigest)
            .def_readwrite("bankAccType", &OpenAccountField::BankAccType)
            .add_property("deviceID", &OpenAccountField::getDeviceID, &OpenAccountField::setDeviceID)
            .def_readwrite("bankSecuAccType", &OpenAccountField::BankSecuAccType)
            .add_property("brokerIDByBank", &OpenAccountField::getBrokerIDByBank, &OpenAccountField::setBrokerIDByBank)
            .add_property("bankSecuAcc", &OpenAccountField::getBankSecuAcc, &OpenAccountField::setBankSecuAcc)
            .def_readwrite("bankPwdFlag", &OpenAccountField::BankPwdFlag)
            .def_readwrite("secuPwdFlag", &OpenAccountField::SecuPwdFlag)
            .add_property("operNo", &OpenAccountField::getOperNo, &OpenAccountField::setOperNo)
            .def_readwrite("TID", &OpenAccountField::TID)
            .add_property("userID", &OpenAccountField::getUserID, &OpenAccountField::setUserID)
            .def_readwrite("errorID", &OpenAccountField::ErrorID)
            .add_property("errorMsg", &OpenAccountField::getErrorMsg, &OpenAccountField::setErrorMsg)
            .add_property("longCustomerName", &OpenAccountField::getLongCustomerName, &OpenAccountField::setLongCustomerName);

    class_<CancelAccountField>("CancelAccountField")
            .add_property("tradeCode", &CancelAccountField::getTradeCode, &CancelAccountField::setTradeCode)
            .add_property("bankID", &CancelAccountField::getBankID, &CancelAccountField::setBankID)
            .add_property("bankBranchID", &CancelAccountField::getBankBranchID, &CancelAccountField::setBankBranchID)
            .add_property("brokerID", &CancelAccountField::getBrokerID, &CancelAccountField::setBrokerID)
            .add_property("brokerBranchID", &CancelAccountField::getBrokerBranchID, &CancelAccountField::setBrokerBranchID)
            .add_property("tradeDate", &CancelAccountField::getTradeDate, &CancelAccountField::setTradeDate)
            .add_property("tradeTime", &CancelAccountField::getTradeTime, &CancelAccountField::setTradeTime)
            .add_property("bankSerial", &CancelAccountField::getBankSerial, &CancelAccountField::setBankSerial)
            .add_property("tradingDay", &CancelAccountField::getTradingDay, &CancelAccountField::setTradingDay)
            .def_readwrite("plateSerial", &CancelAccountField::PlateSerial)
            .def_readwrite("lastFragment", &CancelAccountField::LastFragment)
            .def_readwrite("sessionID", &CancelAccountField::SessionID)
            .add_property("customerName", &CancelAccountField::getCustomerName, &CancelAccountField::setCustomerName)
            .def_readwrite("idCardType", &CancelAccountField::IdCardType)
            .add_property("identifiedCardNo", &CancelAccountField::getIdentifiedCardNo, &CancelAccountField::setIdentifiedCardNo)
            .def_readwrite("gender", &CancelAccountField::Gender)
            .add_property("countryCode", &CancelAccountField::getCountryCode, &CancelAccountField::setCountryCode)
            .def_readwrite("custType", &CancelAccountField::CustType)
            .add_property("address", &CancelAccountField::getAddress, &CancelAccountField::setAddress)
            .add_property("zipCode", &CancelAccountField::getZipCode, &CancelAccountField::setZipCode)
            .add_property("telephone", &CancelAccountField::getTelephone, &CancelAccountField::setTelephone)
            .add_property("mobilePhone", &CancelAccountField::getMobilePhone, &CancelAccountField::setMobilePhone)
            .add_property("fax", &CancelAccountField::getFax, &CancelAccountField::setFax)
            .add_property("EMail", &CancelAccountField::getEMail, &CancelAccountField::setEMail)
            .def_readwrite("moneyAccountStatus", &CancelAccountField::MoneyAccountStatus)
            .add_property("bankAccount", &CancelAccountField::getBankAccount, &CancelAccountField::setBankAccount)
            .add_property("bankPassWord", &CancelAccountField::getBankPassWord, &CancelAccountField::setBankPassWord)
            .add_property("accountID", &CancelAccountField::getAccountID, &CancelAccountField::setAccountID)
            .add_property("password", &CancelAccountField::getPassword, &CancelAccountField::setPassword)
            .def_readwrite("installID", &CancelAccountField::InstallID)
            .def_readwrite("verifyCertNoFlag", &CancelAccountField::VerifyCertNoFlag)
            .add_property("currencyID", &CancelAccountField::getCurrencyID, &CancelAccountField::setCurrencyID)
            .def_readwrite("cashExchangeCode", &CancelAccountField::CashExchangeCode)
            .add_property("digest", &CancelAccountField::getDigest, &CancelAccountField::setDigest)
            .def_readwrite("bankAccType", &CancelAccountField::BankAccType)
            .add_property("deviceID", &CancelAccountField::getDeviceID, &CancelAccountField::setDeviceID)
            .def_readwrite("bankSecuAccType", &CancelAccountField::BankSecuAccType)
            .add_property("brokerIDByBank", &CancelAccountField::getBrokerIDByBank, &CancelAccountField::setBrokerIDByBank)
            .add_property("bankSecuAcc", &CancelAccountField::getBankSecuAcc, &CancelAccountField::setBankSecuAcc)
            .def_readwrite("bankPwdFlag", &CancelAccountField::BankPwdFlag)
            .def_readwrite("secuPwdFlag", &CancelAccountField::SecuPwdFlag)
            .add_property("operNo", &CancelAccountField::getOperNo, &CancelAccountField::setOperNo)
            .def_readwrite("TID", &CancelAccountField::TID)
            .add_property("userID", &CancelAccountField::getUserID, &CancelAccountField::setUserID)
            .def_readwrite("errorID", &CancelAccountField::ErrorID)
            .add_property("errorMsg", &CancelAccountField::getErrorMsg, &CancelAccountField::setErrorMsg)
            .add_property("longCustomerName", &CancelAccountField::getLongCustomerName, &CancelAccountField::setLongCustomerName);

    class_<ChangeAccountField>("ChangeAccountField")
            .add_property("tradeCode", &ChangeAccountField::getTradeCode, &ChangeAccountField::setTradeCode)
            .add_property("bankID", &ChangeAccountField::getBankID, &ChangeAccountField::setBankID)
            .add_property("bankBranchID", &ChangeAccountField::getBankBranchID, &ChangeAccountField::setBankBranchID)
            .add_property("brokerID", &ChangeAccountField::getBrokerID, &ChangeAccountField::setBrokerID)
            .add_property("brokerBranchID", &ChangeAccountField::getBrokerBranchID, &ChangeAccountField::setBrokerBranchID)
            .add_property("tradeDate", &ChangeAccountField::getTradeDate, &ChangeAccountField::setTradeDate)
            .add_property("tradeTime", &ChangeAccountField::getTradeTime, &ChangeAccountField::setTradeTime)
            .add_property("bankSerial", &ChangeAccountField::getBankSerial, &ChangeAccountField::setBankSerial)
            .add_property("tradingDay", &ChangeAccountField::getTradingDay, &ChangeAccountField::setTradingDay)
            .def_readwrite("plateSerial", &ChangeAccountField::PlateSerial)
            .def_readwrite("lastFragment", &ChangeAccountField::LastFragment)
            .def_readwrite("sessionID", &ChangeAccountField::SessionID)
            .add_property("customerName", &ChangeAccountField::getCustomerName, &ChangeAccountField::setCustomerName)
            .def_readwrite("idCardType", &ChangeAccountField::IdCardType)
            .add_property("identifiedCardNo", &ChangeAccountField::getIdentifiedCardNo, &ChangeAccountField::setIdentifiedCardNo)
            .def_readwrite("gender", &ChangeAccountField::Gender)
            .add_property("countryCode", &ChangeAccountField::getCountryCode, &ChangeAccountField::setCountryCode)
            .def_readwrite("custType", &ChangeAccountField::CustType)
            .add_property("address", &ChangeAccountField::getAddress, &ChangeAccountField::setAddress)
            .add_property("zipCode", &ChangeAccountField::getZipCode, &ChangeAccountField::setZipCode)
            .add_property("telephone", &ChangeAccountField::getTelephone, &ChangeAccountField::setTelephone)
            .add_property("mobilePhone", &ChangeAccountField::getMobilePhone, &ChangeAccountField::setMobilePhone)
            .add_property("fax", &ChangeAccountField::getFax, &ChangeAccountField::setFax)
            .add_property("EMail", &ChangeAccountField::getEMail, &ChangeAccountField::setEMail)
            .def_readwrite("moneyAccountStatus", &ChangeAccountField::MoneyAccountStatus)
            .add_property("bankAccount", &ChangeAccountField::getBankAccount, &ChangeAccountField::setBankAccount)
            .add_property("bankPassWord", &ChangeAccountField::getBankPassWord, &ChangeAccountField::setBankPassWord)
            .add_property("newBankAccount", &ChangeAccountField::getNewBankAccount, &ChangeAccountField::setNewBankAccount)
            .add_property("newBankPassWord", &ChangeAccountField::getNewBankPassWord, &ChangeAccountField::setNewBankPassWord)
            .add_property("accountID", &ChangeAccountField::getAccountID, &ChangeAccountField::setAccountID)
            .add_property("password", &ChangeAccountField::getPassword, &ChangeAccountField::setPassword)
            .def_readwrite("bankAccType", &ChangeAccountField::BankAccType)
            .def_readwrite("installID", &ChangeAccountField::InstallID)
            .def_readwrite("verifyCertNoFlag", &ChangeAccountField::VerifyCertNoFlag)
            .add_property("currencyID", &ChangeAccountField::getCurrencyID, &ChangeAccountField::setCurrencyID)
            .add_property("brokerIDByBank", &ChangeAccountField::getBrokerIDByBank, &ChangeAccountField::setBrokerIDByBank)
            .def_readwrite("bankPwdFlag", &ChangeAccountField::BankPwdFlag)
            .def_readwrite("secuPwdFlag", &ChangeAccountField::SecuPwdFlag)
            .def_readwrite("TID", &ChangeAccountField::TID)
            .add_property("digest", &ChangeAccountField::getDigest, &ChangeAccountField::setDigest)
            .def_readwrite("errorID", &ChangeAccountField::ErrorID)
            .add_property("errorMsg", &ChangeAccountField::getErrorMsg, &ChangeAccountField::setErrorMsg)
            .add_property("longCustomerName", &ChangeAccountField::getLongCustomerName, &ChangeAccountField::setLongCustomerName);

    class_<SecAgentACIDMapField>("SecAgentACIDMapField")
            .add_property("brokerID", &SecAgentACIDMapField::getBrokerID, &SecAgentACIDMapField::setBrokerID)
            .add_property("userID", &SecAgentACIDMapField::getUserID, &SecAgentACIDMapField::setUserID)
            .add_property("accountID", &SecAgentACIDMapField::getAccountID, &SecAgentACIDMapField::setAccountID)
            .add_property("currencyID", &SecAgentACIDMapField::getCurrencyID, &SecAgentACIDMapField::setCurrencyID)
            .add_property("brokerSecAgentID", &SecAgentACIDMapField::getBrokerSecAgentID, &SecAgentACIDMapField::setBrokerSecAgentID);

    class_<QrySecAgentACIDMapField>("QrySecAgentACIDMapField")
            .add_property("brokerID", &QrySecAgentACIDMapField::getBrokerID, &QrySecAgentACIDMapField::setBrokerID)
            .add_property("userID", &QrySecAgentACIDMapField::getUserID, &QrySecAgentACIDMapField::setUserID)
            .add_property("accountID", &QrySecAgentACIDMapField::getAccountID, &QrySecAgentACIDMapField::setAccountID)
            .add_property("currencyID", &QrySecAgentACIDMapField::getCurrencyID, &QrySecAgentACIDMapField::setCurrencyID);

    class_<FensUserInfoField>("FensUserInfoField")
            .add_property("brokerID", &FensUserInfoField::getBrokerID, &FensUserInfoField::setBrokerID)
            .add_property("userID", &FensUserInfoField::getUserID, &FensUserInfoField::setUserID)
            .def_readwrite("loginMode", &FensUserInfoField::LoginMode);
};


