//
// Created by kyle on 17-5-18.
//

#ifndef PYCTP_CTPTD_H
#define PYCTP_CTPTD_H

#include "base.h"
#include "ThostFtdcTraderApi.h"

#define ON_FRONT_CONNECTED 1
#define ON_FRONT_DISCONNECTED 2
#define ON_HEART_BEAT_WARNING 3
#define ON_RSP_AUTHENTICATE 4
#define ON_RSP_USER_LOGIN 5
#define ON_RSP_USER_LOGOUT 6
#define ON_RSP_USER_PASSWORD_UPDATE 7
#define ON_RSP_TRADING_ACCOUNT_PASSWORD_UPDATE 8
#define ON_RSP_ORDER_INSERT 9
#define ON_RSP_PARKED_ORDER_INSERT 10
#define ON_RSP_PARKED_ORDER_ACTION 11
#define ON_RSP_ORDER_ACTION 12
#define ON_RSP_QUERY_MAX_ORDER_VOLUME 13
#define ON_RSP_SETTLEMENT_INFO_CONFIRM 14
#define ON_RSP_REMOVE_PARKED_ORDER 15
#define ON_RSP_REMOVE_PARKED_ORDER_ACTION 16
#define ON_RSP_EXEC_ORDER_INSERT 17
#define ON_RSP_EXEC_ORDER_ACTION 18
#define ON_RSP_FOR_QUOTE_INSERT 19
#define ON_RSP_QUOTE_INSERT 20
#define ON_RSP_QUOTE_ACTION 21
#define ON_RSP_BATCH_ORDER_ACTION 22
#define ON_RSP_COMB_ACTION_INSERT 23
#define ON_RSP_QRY_ORDER 24
#define ON_RSP_QRY_TRADE 25
#define ON_RSP_QRY_INVESTOR_POSITION 26
#define ON_RSP_QRY_TRADING_ACCOUNT 27
#define ON_RSP_QRY_INVESTOR 28
#define ON_RSP_QRY_TRADING_CODE 29
#define ON_RSP_QRY_INSTRUMENT_MARGIN_RATE 30
#define ON_RSP_QRY_INSTRUMENT_COMMISSION_RATE 31
#define ON_RSP_QRY_EXCHANGE 32
#define ON_RSP_QRY_PRODUCT 33
#define ON_RSP_QRY_INSTRUMENT 34
#define ON_RSP_QRY_DEPTH_MARKET_DATA 35
#define ON_RSP_QRY_SETTLEMENT_INFO 36
#define ON_RSP_QRY_TRANSFER_BANK 37
#define ON_RSP_QRY_INVESTOR_POSITION_DETAIL 38
#define ON_RSP_QRY_NOTICE 39
#define ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM 40
#define ON_RSP_QRY_INVESTOR_POSITION_COMBINE_DETAIL 41
#define ON_RSP_QRY_C_F_M_M_C_TRADING_ACCOUNT_KEY 42
#define ON_RSP_QRY_E_WARRANT_OFFSET 43
#define ON_RSP_QRY_INVESTOR_PRODUCT_GROUP_MARGIN 44
#define ON_RSP_QRY_EXCHANGE_MARGIN_RATE 45
#define ON_RSP_QRY_EXCHANGE_MARGIN_RATE_ADJUST 46
#define ON_RSP_QRY_EXCHANGE_RATE 47
#define ON_RSP_QRY_SEC_AGENT_A_C_I_D_MAP 48
#define ON_RSP_QRY_PRODUCT_EXCH_RATE 49
#define ON_RSP_QRY_PRODUCT_GROUP 50
#define ON_RSP_QRY_M_M_INSTRUMENT_COMMISSION_RATE 51
#define ON_RSP_QRY_M_M_OPTION_INSTR_COMM_RATE 52
#define ON_RSP_QRY_INSTRUMENT_ORDER_COMM_RATE 53
#define ON_RSP_QRY_OPTION_INSTR_TRADE_COST 54
#define ON_RSP_QRY_OPTION_INSTR_COMM_RATE 55
#define ON_RSP_QRY_EXEC_ORDER 56
#define ON_RSP_QRY_FOR_QUOTE 57
#define ON_RSP_QRY_QUOTE 58
#define ON_RSP_QRY_COMB_INSTRUMENT_GUARD 59
#define ON_RSP_QRY_COMB_ACTION 60
#define ON_RSP_QRY_TRANSFER_SERIAL 61
#define ON_RSP_QRY_ACCOUNTREGISTER 62
#define ON_RSP_ERROR 63
#define ON_RTN_ORDER 64
#define ON_RTN_TRADE 65
#define ON_ERR_RTN_ORDER_INSERT 66
#define ON_ERR_RTN_ORDER_ACTION 67
#define ON_RTN_INSTRUMENT_STATUS 68
#define ON_RTN_BULLETIN 69
#define ON_RTN_TRADING_NOTICE 70
#define ON_RTN_ERROR_CONDITIONAL_ORDER 71
#define ON_RTN_EXEC_ORDER 72
#define ON_ERR_RTN_EXEC_ORDER_INSERT 73
#define ON_ERR_RTN_EXEC_ORDER_ACTION 74
#define ON_ERR_RTN_FOR_QUOTE_INSERT 75
#define ON_RTN_QUOTE 76
#define ON_ERR_RTN_QUOTE_INSERT 77
#define ON_ERR_RTN_QUOTE_ACTION 78
#define ON_RTN_FOR_QUOTE_RSP 79
#define ON_RTN_C_F_M_M_C_TRADING_ACCOUNT_TOKEN 80
#define ON_ERR_RTN_BATCH_ORDER_ACTION 81
#define ON_RTN_COMB_ACTION 82
#define ON_ERR_RTN_COMB_ACTION_INSERT 83
#define ON_RSP_QRY_CONTRACT_BANK 84
#define ON_RSP_QRY_PARKED_ORDER 85
#define ON_RSP_QRY_PARKED_ORDER_ACTION 86
#define ON_RSP_QRY_TRADING_NOTICE 87
#define ON_RSP_QRY_BROKER_TRADING_PARAMS 88
#define ON_RSP_QRY_BROKER_TRADING_ALGOS 89
#define ON_RSP_QUERY_C_F_M_M_C_TRADING_ACCOUNT_TOKEN 90
#define ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK 91
#define ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK 92
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK 93
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK 94
#define ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE 95
#define ON_RTN_FROM_FUTURE_TO_BANK_BY_FUTURE 96
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL 97
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL 98
#define ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE 99
#define ON_ERR_RTN_BANK_TO_FUTURE_BY_FUTURE 100
#define ON_ERR_RTN_FUTURE_TO_BANK_BY_FUTURE 101
#define ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL 102
#define ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL 103
#define ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE 104
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE 105
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE 106
#define ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE 107
#define ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE 108
#define ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE 109
#define ON_RTN_OPEN_ACCOUNT_BY_BANK 110
#define ON_RTN_CANCEL_ACCOUNT_BY_BANK 111
#define ON_RTN_CHANGE_ACCOUNT_BY_BANK 112

using namespace boost::python;
using namespace boost;

class CtpTd : public CThostFtdcTraderSpi {
private:
    boost::thread * task_thread; //回调函数的执行线程
    ConcurrentQueue<Task *> task_queue; //任务队列
    CThostFtdcTraderApi* api; //API对象
    void processTask();

public:
    CtpTd(const std::string &szFlowPath = "");
    ~CtpTd();

    ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
    virtual void OnFrontConnected();
    virtual void onFrontConnected() {};

    ///        0x2003 收到错误报文
    virtual void OnFrontDisconnected(int nReason);
    virtual void onFrontDisconnected(int reasonCode) {};

    ///@param nTimeLapse 距离上次接收报文的时间
    virtual void OnHeartBeatWarning(int nTimeLapse);
    virtual void onHeartBeatWarning(int lapsedTime) {};

    ///客户端认证响应
    virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspAuthenticate(object &rspAuthenticateField, object &rspInfoField, int requestId, bool final) {};

    ///登录请求响应
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUserLogin(object &rspUserLoginField, object &rspInfoField, int requestId, bool final) {};

    ///登出请求响应
    virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUserLogout(object &userLogoutField, object &rspInfoField, int requestId, bool final) {};

    ///用户口令更新请求响应
    virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUserPasswordUpdate(object &userPasswordUpdateField, object &rspInfoField, int requestId, bool final) {};

    ///资金账户口令更新请求响应
    virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspTradingAccountPasswordUpdate(object &tradingAccountPasswordUpdateField, object &rspInfoField, int requestId, bool final) {};

    ///报单录入请求响应
    virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspOrderInsert(object &inputOrderField, object &rspInfoField, int requestId, bool final) {};

    ///预埋单录入请求响应
    virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspParkedOrderInsert(object &parkedOrderField, object &rspInfoField, int requestId, bool final) {};

    ///预埋撤单录入请求响应
    virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspParkedOrderAction(object &parkedOrderActionField, object &rspInfoField, int requestId, bool final) {};

    ///报单操作请求响应
    virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspOrderAction(object &inputOrderActionField, object &rspInfoField, int requestId, bool final) {};

    ///查询最大报单数量响应
    virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQueryMaxOrderVolume(object &queryMaxOrderVolumeField, object &rspInfoField, int requestId, bool final) {};

    ///投资者结算结果确认响应
    virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspSettlementInfoConfirm(object &settlementInfoConfirmField, object &rspInfoField, int requestId, bool final) {};

    ///删除预埋单响应
    virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspRemoveParkedOrder(object &removeParkedOrderField, object &rspInfoField, int requestId, bool final) {};

    ///删除预埋撤单响应
    virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspRemoveParkedOrderAction(object &removeParkedOrderActionField, object &rspInfoField, int requestId, bool final) {};

    ///执行宣告录入请求响应
    virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspExecOrderInsert(object &inputExecOrderField, object &rspInfoField, int requestId, bool final) {};

    ///执行宣告操作请求响应
    virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspExecOrderAction(object &inputExecOrderActionField, object &rspInfoField, int requestId, bool final) {};

    ///询价录入请求响应
    virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspForQuoteInsert(object &inputForQuoteField, object &rspInfoField, int requestId, bool final) {};

    ///报价录入请求响应
    virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQuoteInsert(object &inputQuoteField, object &rspInfoField, int requestId, bool final) {};

    ///报价操作请求响应
    virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQuoteAction(object &inputQuoteActionField, object &rspInfoField, int requestId, bool final) {};

    ///批量报单操作请求响应
    virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspBatchOrderAction(object &inputBatchOrderActionField, object &rspInfoField, int requestId, bool final) {};

    ///申请组合录入请求响应
    virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspCombActionInsert(object &inputCombActionField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询报单响应
    virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryOrder(object &orderField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询成交响应
    virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTrade(object &tradeField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询投资者持仓响应
    virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInvestorPosition(object &investorPositionField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询资金账户响应
    virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTradingAccount(object &tradingAccountField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询投资者响应
    virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInvestor(object &investorField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询交易编码响应
    virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTradingCode(object &tradingCodeField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询合约保证金率响应
    virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInstrumentMarginRate(object &instrumentMarginRateField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询合约手续费率响应
    virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInstrumentCommissionRate(object &instrumentCommissionRateField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询交易所响应
    virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryExchange(object &exchangeField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询产品响应
    virtual void OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryProduct(object &productField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询合约响应
    virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInstrument(object &instrumentField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询行情响应
    virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryDepthMarketData(object &depthMarketDataField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询投资者结算结果响应
    virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQrySettlementInfo(object &settlementInfoField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询转帐银行响应
    virtual void OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTransferBank(object &transferBankField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询投资者持仓明细响应
    virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInvestorPositionDetail(object &investorPositionDetailField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询客户通知响应
    virtual void OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryNotice(object &noticeField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询结算信息确认响应
    virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQrySettlementInfoConfirm(object &settlementInfoConfirmField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询投资者持仓明细响应
    virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInvestorPositionCombineDetail(object &investorPositionCombineDetailField, object &rspInfoField, int requestId, bool final) {};

    ///查询保证金监管系统经纪公司资金账户密钥响应
    virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryCFMMCTradingAccountKey(object &cFMMCTradingAccountKeyField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询仓单折抵信息响应
    virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryEWarrantOffset(object &eWarrantOffsetField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询投资者品种/跨品种保证金响应
    virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInvestorProductGroupMargin(object &investorProductGroupMarginField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询交易所保证金率响应
    virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryExchangeMarginRate(object &exchangeMarginRateField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询交易所调整保证金率响应
    virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryExchangeMarginRateAdjust(object &exchangeMarginRateAdjustField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询汇率响应
    virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryExchangeRate(object &exchangeRateField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询二级代理操作员银期权限响应
    virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQrySecAgentACIDMap(object &secAgentACIDMapField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询产品报价汇率
    virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryProductExchRate(object &productExchRateField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询产品组
    virtual void OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryProductGroup(object &productGroupField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询做市商合约手续费率响应
    virtual void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryMMInstrumentCommissionRate(object &mMInstrumentCommissionRateField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询做市商期权合约手续费响应
    virtual void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryMMOptionInstrCommRate(object &mMOptionInstrCommRateField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询报单手续费响应
    virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInstrumentOrderCommRate(object &instrumentOrderCommRateField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询期权交易成本响应
    virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryOptionInstrTradeCost(object &optionInstrTradeCostField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询期权合约手续费响应
    virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryOptionInstrCommRate(object &optionInstrCommRateField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询执行宣告响应
    virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryExecOrder(object &execOrderField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询询价响应
    virtual void OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryForQuote(object &forQuoteField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询报价响应
    virtual void OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryQuote(object &quoteField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询组合合约安全系数响应
    virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryCombInstrumentGuard(object &combInstrumentGuardField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询申请组合响应
    virtual void OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryCombAction(object &combActionField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询转帐流水响应
    virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTransferSerial(object &transferSerialField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询银期签约关系响应
    virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryAccountregister(object &accountregisterField, object &rspInfoField, int requestId, bool final) {};

    ///错误应答
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspError(object &rspInfoField, int requestId, bool final) {};

    ///报单通知
    virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);
    virtual void onRtnOrder(object &orderField) {};

    ///成交通知
    virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);
    virtual void onRtnTrade(object &tradeField) {};

    ///报单录入错误回报
    virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnOrderInsert(object &inputOrderField, object &rspInfoField) {};

    ///报单操作错误回报
    virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnOrderAction(object &orderActionField, object &rspInfoField) {};

    ///合约交易状态通知
    virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);
    virtual void onRtnInstrumentStatus(object &instrumentStatusField) {};

    ///交易所公告通知
    virtual void OnRtnBulletin(CThostFtdcBulletinField *pBulletin);
    virtual void onRtnBulletin(object &bulletinField) {};

    ///交易通知
    virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);
    virtual void onRtnTradingNotice(object &tradingNoticeInfoField) {};

    ///提示条件单校验错误
    virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);
    virtual void onRtnErrorConditionalOrder(object &errorConditionalOrderField) {};

    ///执行宣告通知
    virtual void OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder);
    virtual void onRtnExecOrder(object &execOrderField) {};

    ///执行宣告录入错误回报
    virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnExecOrderInsert(object &inputExecOrderField, object &rspInfoField) {};

    ///执行宣告操作错误回报
    virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnExecOrderAction(object &execOrderActionField, object &rspInfoField) {};

    ///询价录入错误回报
    virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnForQuoteInsert(object &inputForQuoteField, object &rspInfoField) {};

    ///报价通知
    virtual void OnRtnQuote(CThostFtdcQuoteField *pQuote);
    virtual void onRtnQuote(object &quoteField) {};

    ///报价录入错误回报
    virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnQuoteInsert(object &inputQuoteField, object &rspInfoField) {};

    ///报价操作错误回报
    virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnQuoteAction(object &quoteActionField, object &rspInfoField) {};

    ///询价通知
    virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);
    virtual void onRtnForQuoteRsp(object &forQuoteRspField) {};

    ///保证金监控中心用户令牌
    virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken);
    virtual void onRtnCFMMCTradingAccountToken(object &cFMMCTradingAccountTokenField) {};

    ///批量报单操作错误回报
    virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnBatchOrderAction(object &batchOrderActionField, object &rspInfoField) {};

    ///申请组合通知
    virtual void OnRtnCombAction(CThostFtdcCombActionField *pCombAction);
    virtual void onRtnCombAction(object &combActionField) {};

    ///申请组合录入错误回报
    virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnCombActionInsert(object &inputCombActionField, object &rspInfoField) {};

    ///请求查询签约银行响应
    virtual void OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryContractBank(object &contractBankField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询预埋单响应
    virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryParkedOrder(object &parkedOrderField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询预埋撤单响应
    virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryParkedOrderAction(object &parkedOrderActionField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询交易通知响应
    virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTradingNotice(object &tradingNoticeField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询经纪公司交易参数响应
    virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryBrokerTradingParams(object &brokerTradingParamsField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询经纪公司交易算法响应
    virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryBrokerTradingAlgos(object &brokerTradingAlgosField, object &rspInfoField, int requestId, bool final) {};

    ///请求查询监控中心用户令牌
    virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQueryCFMMCTradingAccountToken(object &queryCFMMCTradingAccountTokenField, object &rspInfoField, int requestId, bool final) {};

    ///银行发起银行资金转期货通知
    virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer);
    virtual void onRtnFromBankToFutureByBank(object &rspTransferField) {};

    ///银行发起期货资金转银行通知
    virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer);
    virtual void onRtnFromFutureToBankByBank(object &rspTransferField) {};

    ///银行发起冲正银行转期货通知
    virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromBankToFutureByBank(object &rspRepealField) {};

    ///银行发起冲正期货转银行通知
    virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromFutureToBankByBank(object &rspRepealField) {};

    ///期货发起银行资金转期货通知
    virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);
    virtual void onRtnFromBankToFutureByFuture(object &rspTransferField) {};

    ///期货发起期货资金转银行通知
    virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);
    virtual void onRtnFromFutureToBankByFuture(object &rspTransferField) {};

    ///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
    virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromBankToFutureByFutureManual(object &rspRepealField) {};

    ///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
    virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromFutureToBankByFutureManual(object &rspRepealField) {};

    ///期货发起查询银行余额通知
    virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);
    virtual void onRtnQueryBankBalanceByFuture(object &notifyQueryAccountField) {};

    ///期货发起银行资金转期货错误回报
    virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnBankToFutureByFuture(object &reqTransferField, object &rspInfoField) {};

    ///期货发起期货资金转银行错误回报
    virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnFutureToBankByFuture(object &reqTransferField, object &rspInfoField) {};

    ///系统运行时期货端手工发起冲正银行转期货错误回报
    virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnRepealBankToFutureByFutureManual(object &reqRepealField, object &rspInfoField) {};

    ///系统运行时期货端手工发起冲正期货转银行错误回报
    virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnRepealFutureToBankByFutureManual(object &reqRepealField, object &rspInfoField) {};

    ///期货发起查询银行余额错误回报
    virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnQueryBankBalanceByFuture(object &reqQueryAccountField, object &rspInfoField) {};

    ///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
    virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromBankToFutureByFuture(object &rspRepealField) {};

    ///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
    virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromFutureToBankByFuture(object &rspRepealField) {};

    ///期货发起银行资金转期货应答
    virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspFromBankToFutureByFuture(object &reqTransferField, object &rspInfoField, int requestId, bool final) {};

    ///期货发起期货资金转银行应答
    virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspFromFutureToBankByFuture(object &reqTransferField, object &rspInfoField, int requestId, bool final) {};

    ///期货发起查询银行余额应答
    virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQueryBankAccountMoneyByFuture(object &reqQueryAccountField, object &rspInfoField, int requestId, bool final) {};

    ///银行发起银期开户通知
    virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount);
    virtual void onRtnOpenAccountByBank(object &openAccountField) {};

    ///银行发起银期销户通知
    virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount);
    virtual void onRtnCancelAccountByBank(object &cancelAccountField) {};

    ///银行发起变更银行账号通知
    virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount);
    virtual void onRtnChangeAccountByBank(object &changeAccountField) {};

    const char *getApiVersion();

    void release();

    void init();

    int join();

    const char *getTradingDay();

    void registerFront(const std::string &szFrontAddress);

    void registerNameServer(const std::string &szNsAddress);

    void registerFensUserInfo(object &fensUserInfoField);

    void registerSpi();

    void subscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType);

    void subscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType);

    int reqAuthenticate(object &reqAuthenticateField, int requestId);

    int reqUserLogin(object &reqUserLoginField, int requestId);

    int reqUserLogout(object &userLogoutField, int requestId);

    int reqUserPasswordUpdate(object &userPasswordUpdateField, int requestId);

    int reqTradingAccountPasswordUpdate(object &tradingAccountPasswordUpdateField, int requestId);

    int reqOrderInsert(object &inputOrderField, int requestId);

    int reqParkedOrderInsert(object &parkedOrderField, int requestId);

    int reqParkedOrderAction(object &parkedOrderActionField, int requestId);

    int reqOrderAction(object &inputOrderActionField, int requestId);

    int reqQueryMaxOrderVolume(object &queryMaxOrderVolumeField, int requestId);

    int reqSettlementInfoConfirm(object &settlementInfoConfirmField, int requestId);

    int reqRemoveParkedOrder(object &removeParkedOrderField, int requestId);

    int reqRemoveParkedOrderAction(object &removeParkedOrderActionField, int requestId);

    int reqExecOrderInsert(object &inputExecOrderField, int requestId);

    int reqExecOrderAction(object &inputExecOrderActionField, int requestId);

    int reqForQuoteInsert(object &inputForQuoteField, int requestId);

    int reqQuoteInsert(object &inputQuoteField, int requestId);

    int reqQuoteAction(object &inputQuoteActionField, int requestId);

    int reqBatchOrderAction(object &inputBatchOrderActionField, int requestId);

    int reqCombActionInsert(object &inputCombActionField, int requestId);

    int reqQryOrder(object &qryOrderField, int requestId);

    int reqQryTrade(object &qryTradeField, int requestId);

    int reqQryInvestorPosition(object &qryInvestorPositionField, int requestId);

    int reqQryTradingAccount(object &qryTradingAccountField, int requestId);

    int reqQryInvestor(object &qryInvestorField, int requestId);

    int reqQryTradingCode(object &qryTradingCodeField, int requestId);

    int reqQryInstrumentMarginRate(object &qryInstrumentMarginRateField, int requestId);

    int reqQryInstrumentCommissionRate(object &qryInstrumentCommissionRateField, int requestId);

    int reqQryExchange(object &qryExchangeField, int requestId);

    int reqQryProduct(object &qryProductField, int requestId);

    int reqQryInstrument(object &qryInstrumentField, int requestId);

    int reqQryDepthMarketData(object &qryDepthMarketDataField, int requestId);

    int reqQrySettlementInfo(object &qrySettlementInfoField, int requestId);

    int reqQryTransferBank(object &qryTransferBankField, int requestId);

    int reqQryInvestorPositionDetail(object &qryInvestorPositionDetailField, int requestId);

    int reqQryNotice(object &qryNoticeField, int requestId);

    int reqQrySettlementInfoConfirm(object &qrySettlementInfoConfirmField, int requestId);

    int reqQryInvestorPositionCombineDetail(object &qryInvestorPositionCombineDetailField, int requestId);

    int reqQryCFMMCTradingAccountKey(object &qryCFMMCTradingAccountKeyField, int requestId);

    int reqQryEWarrantOffset(object &qryEWarrantOffsetField, int requestId);

    int reqQryInvestorProductGroupMargin(object &qryInvestorProductGroupMarginField, int requestId);

    int reqQryExchangeMarginRate(object &qryExchangeMarginRateField, int requestId);

    int reqQryExchangeMarginRateAdjust(object &qryExchangeMarginRateAdjustField, int requestId);

    int reqQryExchangeRate(object &qryExchangeRateField, int requestId);

    int reqQrySecAgentACIDMap(object &qrySecAgentACIDMapField, int requestId);

    int reqQryProductExchRate(object &qryProductExchRateField, int requestId);

    int reqQryProductGroup(object &qryProductGroupField, int requestId);

    int reqQryMMInstrumentCommissionRate(object &qryMMInstrumentCommissionRateField, int requestId);

    int reqQryMMOptionInstrCommRate(object &qryMMOptionInstrCommRateField, int requestId);

    int reqQryInstrumentOrderCommRate(object &qryInstrumentOrderCommRateField, int requestId);

    int reqQryOptionInstrTradeCost(object &qryOptionInstrTradeCostField, int requestId);

    int reqQryOptionInstrCommRate(object &qryOptionInstrCommRateField, int requestId);

    int reqQryExecOrder(object &qryExecOrderField, int requestId);

    int reqQryForQuote(object &qryForQuoteField, int requestId);

    int reqQryQuote(object &qryQuoteField, int requestId);

    int reqQryCombInstrumentGuard(object &qryCombInstrumentGuardField, int requestId);

    int reqQryCombAction(object &qryCombActionField, int requestId);

    int reqQryTransferSerial(object &qryTransferSerialField, int requestId);

    int reqQryAccountregister(object &qryAccountregisterField, int requestId);

    int reqQryContractBank(object &qryContractBankField, int requestId);

    int reqQryParkedOrder(object &qryParkedOrderField, int requestId);

    int reqQryParkedOrderAction(object &qryParkedOrderActionField, int requestId);

    int reqQryTradingNotice(object &qryTradingNoticeField, int requestId);

    int reqQryBrokerTradingParams(object &qryBrokerTradingParamsField, int requestId);

    int reqQryBrokerTradingAlgos(object &qryBrokerTradingAlgosField, int requestId);

    int reqQueryCFMMCTradingAccountToken(object &queryCFMMCTradingAccountTokenField, int requestId);

    int reqFromBankToFutureByFuture(object &reqTransferField, int requestId);

    int reqFromFutureToBankByFuture(object &reqTransferField, int requestId);

    int reqQueryBankAccountMoneyByFuture(object &reqQueryAccountField, int requestId);
};

struct ReqUserLoginField: CThostFtdcReqUserLoginField {

    ReqUserLoginField() {
        std::memset(this, 0, sizeof(ReqUserLoginField));
    }

    ReqUserLoginField(const CThostFtdcReqUserLoginField& f): CThostFtdcReqUserLoginField(f){}

    ReqUserLoginField& operator=(const CThostFtdcReqUserLoginField& f) {
        CThostFtdcReqUserLoginField::operator=(f);
        return *this;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->Password);
        this->Password[v.size()] = '\0';
    }
    const char* getPassword() {
        return this->Password;
    }

    void setUserProductInfo(std::string v) {
        std::copy(v.begin(), v.end(), this->UserProductInfo);
        this->UserProductInfo[v.size()] = '\0';
    }
    const char* getUserProductInfo() {
        return this->UserProductInfo;
    }

    void setInterfaceProductInfo(std::string v) {
        std::copy(v.begin(), v.end(), this->InterfaceProductInfo);
        this->InterfaceProductInfo[v.size()] = '\0';
    }
    const char* getInterfaceProductInfo() {
        return this->InterfaceProductInfo;
    }

    void setProtocolInfo(std::string v) {
        std::copy(v.begin(), v.end(), this->ProtocolInfo);
        this->ProtocolInfo[v.size()] = '\0';
    }
    const char* getProtocolInfo() {
        return this->ProtocolInfo;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }

    void setOneTimePassword(std::string v) {
        std::copy(v.begin(), v.end(), this->OneTimePassword);
        this->OneTimePassword[v.size()] = '\0';
    }
    const char* getOneTimePassword() {
        return this->OneTimePassword;
    }

    void setClientIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientIPAddress);
        this->ClientIPAddress[v.size()] = '\0';
    }
    const char* getClientIPAddress() {
        return this->ClientIPAddress;
    }

    void setLoginRemark(std::string v) {
        std::copy(v.begin(), v.end(), this->LoginRemark);
        this->LoginRemark[v.size()] = '\0';
    }
    const char* getLoginRemark() {
        return this->LoginRemark;
    }
};

struct RspUserLoginField: CThostFtdcRspUserLoginField {

    RspUserLoginField() {
        std::memset(this, 0, sizeof(RspUserLoginField));
    }

    RspUserLoginField(const CThostFtdcRspUserLoginField& f): CThostFtdcRspUserLoginField(f){}

    RspUserLoginField& operator=(const CThostFtdcRspUserLoginField& f) {
        CThostFtdcRspUserLoginField::operator=(f);
        return *this;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setLoginTime(std::string v) {
        std::copy(v.begin(), v.end(), this->LoginTime);
        this->LoginTime[v.size()] = '\0';
    }
    const char* getLoginTime() {
        return this->LoginTime;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setSystemName(std::string v) {
        std::copy(v.begin(), v.end(), this->SystemName);
        this->SystemName[v.size()] = '\0';
    }
    const char* getSystemName() {
        return this->SystemName;
    }

    void setMaxOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->MaxOrderRef);
        this->MaxOrderRef[v.size()] = '\0';
    }
    const char* getMaxOrderRef() {
        return this->MaxOrderRef;
    }

    void setSHFETime(std::string v) {
        std::copy(v.begin(), v.end(), this->SHFETime);
        this->SHFETime[v.size()] = '\0';
    }
    const char* getSHFETime() {
        return this->SHFETime;
    }

    void setDCETime(std::string v) {
        std::copy(v.begin(), v.end(), this->DCETime);
        this->DCETime[v.size()] = '\0';
    }
    const char* getDCETime() {
        return this->DCETime;
    }

    void setCZCETime(std::string v) {
        std::copy(v.begin(), v.end(), this->CZCETime);
        this->CZCETime[v.size()] = '\0';
    }
    const char* getCZCETime() {
        return this->CZCETime;
    }

    void setFFEXTime(std::string v) {
        std::copy(v.begin(), v.end(), this->FFEXTime);
        this->FFEXTime[v.size()] = '\0';
    }
    const char* getFFEXTime() {
        return this->FFEXTime;
    }

    void setINETime(std::string v) {
        std::copy(v.begin(), v.end(), this->INETime);
        this->INETime[v.size()] = '\0';
    }
    const char* getINETime() {
        return this->INETime;
    }
};

struct UserLogoutField: CThostFtdcUserLogoutField {

    UserLogoutField() {
        std::memset(this, 0, sizeof(UserLogoutField));
    }

    UserLogoutField(const CThostFtdcUserLogoutField& f): CThostFtdcUserLogoutField(f){}

    UserLogoutField& operator=(const CThostFtdcUserLogoutField& f) {
        CThostFtdcUserLogoutField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }
};

struct ReqAuthenticateField: CThostFtdcReqAuthenticateField {

    ReqAuthenticateField() {
        std::memset(this, 0, sizeof(ReqAuthenticateField));
    }

    ReqAuthenticateField(const CThostFtdcReqAuthenticateField& f): CThostFtdcReqAuthenticateField(f){}

    ReqAuthenticateField& operator=(const CThostFtdcReqAuthenticateField& f) {
        CThostFtdcReqAuthenticateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setUserProductInfo(std::string v) {
        std::copy(v.begin(), v.end(), this->UserProductInfo);
        this->UserProductInfo[v.size()] = '\0';
    }
    const char* getUserProductInfo() {
        return this->UserProductInfo;
    }

    void setAuthCode(std::string v) {
        std::copy(v.begin(), v.end(), this->AuthCode);
        this->AuthCode[v.size()] = '\0';
    }
    const char* getAuthCode() {
        return this->AuthCode;
    }
};

struct RspAuthenticateField: CThostFtdcRspAuthenticateField {

    RspAuthenticateField() {
        std::memset(this, 0, sizeof(RspAuthenticateField));
    }

    RspAuthenticateField(const CThostFtdcRspAuthenticateField& f): CThostFtdcRspAuthenticateField(f){}

    RspAuthenticateField& operator=(const CThostFtdcRspAuthenticateField& f) {
        CThostFtdcRspAuthenticateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setUserProductInfo(std::string v) {
        std::copy(v.begin(), v.end(), this->UserProductInfo);
        this->UserProductInfo[v.size()] = '\0';
    }
    const char* getUserProductInfo() {
        return this->UserProductInfo;
    }
};

struct RspInfoField: CThostFtdcRspInfoField {

    RspInfoField() {
        std::memset(this, 0, sizeof(RspInfoField));
    }

    RspInfoField(const CThostFtdcRspInfoField& f): CThostFtdcRspInfoField(f){}

    RspInfoField& operator=(const CThostFtdcRspInfoField& f) {
        CThostFtdcRspInfoField::operator=(f);
        return *this;
    }

    void setErrorMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->ErrorMsg);
        this->ErrorMsg[v.size()] = '\0';
    }
    const char* getErrorMsg() {
        return this->ErrorMsg;
    }
};

struct ExchangeField: CThostFtdcExchangeField {

    ExchangeField() {
        std::memset(this, 0, sizeof(ExchangeField));
    }

    ExchangeField(const CThostFtdcExchangeField& f): CThostFtdcExchangeField(f){}

    ExchangeField& operator=(const CThostFtdcExchangeField& f) {
        CThostFtdcExchangeField::operator=(f);
        return *this;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setExchangeName(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeName);
        this->ExchangeName[v.size()] = '\0';
    }
    const char* getExchangeName() {
        return this->ExchangeName;
    }
};

struct ProductField: CThostFtdcProductField {

    ProductField() {
        std::memset(this, 0, sizeof(ProductField));
    }

    ProductField(const CThostFtdcProductField& f): CThostFtdcProductField(f){}

    ProductField& operator=(const CThostFtdcProductField& f) {
        CThostFtdcProductField::operator=(f);
        return *this;
    }

    void setProductID(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductID);
        this->ProductID[v.size()] = '\0';
    }
    const char* getProductID() {
        return this->ProductID;
    }

    void setProductName(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductName);
        this->ProductName[v.size()] = '\0';
    }
    const char* getProductName() {
        return this->ProductName;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setTradeCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeCurrencyID);
        this->TradeCurrencyID[v.size()] = '\0';
    }
    const char* getTradeCurrencyID() {
        return this->TradeCurrencyID;
    }

    void setExchangeProductID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeProductID);
        this->ExchangeProductID[v.size()] = '\0';
    }
    const char* getExchangeProductID() {
        return this->ExchangeProductID;
    }
};

struct InstrumentField: CThostFtdcInstrumentField {

    InstrumentField() {
        std::memset(this, 0, sizeof(InstrumentField));
    }

    InstrumentField(const CThostFtdcInstrumentField& f): CThostFtdcInstrumentField(f){}

    InstrumentField& operator=(const CThostFtdcInstrumentField& f) {
        CThostFtdcInstrumentField::operator=(f);
        return *this;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setInstrumentName(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentName);
        this->InstrumentName[v.size()] = '\0';
    }
    const char* getInstrumentName() {
        return this->InstrumentName;
    }

    void setExchangeInstID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeInstID);
        this->ExchangeInstID[v.size()] = '\0';
    }
    const char* getExchangeInstID() {
        return this->ExchangeInstID;
    }

    void setProductID(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductID);
        this->ProductID[v.size()] = '\0';
    }
    const char* getProductID() {
        return this->ProductID;
    }

    void setCreateDate(std::string v) {
        std::copy(v.begin(), v.end(), this->CreateDate);
        this->CreateDate[v.size()] = '\0';
    }
    const char* getCreateDate() {
        return this->CreateDate;
    }

    void setOpenDate(std::string v) {
        std::copy(v.begin(), v.end(), this->OpenDate);
        this->OpenDate[v.size()] = '\0';
    }
    const char* getOpenDate() {
        return this->OpenDate;
    }

    void setExpireDate(std::string v) {
        std::copy(v.begin(), v.end(), this->ExpireDate);
        this->ExpireDate[v.size()] = '\0';
    }
    const char* getExpireDate() {
        return this->ExpireDate;
    }

    void setStartDelivDate(std::string v) {
        std::copy(v.begin(), v.end(), this->StartDelivDate);
        this->StartDelivDate[v.size()] = '\0';
    }
    const char* getStartDelivDate() {
        return this->StartDelivDate;
    }

    void setEndDelivDate(std::string v) {
        std::copy(v.begin(), v.end(), this->EndDelivDate);
        this->EndDelivDate[v.size()] = '\0';
    }
    const char* getEndDelivDate() {
        return this->EndDelivDate;
    }

    void setUnderlyingInstrID(std::string v) {
        std::copy(v.begin(), v.end(), this->UnderlyingInstrID);
        this->UnderlyingInstrID[v.size()] = '\0';
    }
    const char* getUnderlyingInstrID() {
        return this->UnderlyingInstrID;
    }
};

struct InvestorField: CThostFtdcInvestorField {

    InvestorField() {
        std::memset(this, 0, sizeof(InvestorField));
    }

    InvestorField(const CThostFtdcInvestorField& f): CThostFtdcInvestorField(f){}

    InvestorField& operator=(const CThostFtdcInvestorField& f) {
        CThostFtdcInvestorField::operator=(f);
        return *this;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorGroupID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorGroupID);
        this->InvestorGroupID[v.size()] = '\0';
    }
    const char* getInvestorGroupID() {
        return this->InvestorGroupID;
    }

    void setInvestorName(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorName);
        this->InvestorName[v.size()] = '\0';
    }
    const char* getInvestorName() {
        return this->InvestorName;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setTelephone(std::string v) {
        std::copy(v.begin(), v.end(), this->Telephone);
        this->Telephone[v.size()] = '\0';
    }
    const char* getTelephone() {
        return this->Telephone;
    }

    void setAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->Address);
        this->Address[v.size()] = '\0';
    }
    const char* getAddress() {
        return this->Address;
    }

    void setOpenDate(std::string v) {
        std::copy(v.begin(), v.end(), this->OpenDate);
        this->OpenDate[v.size()] = '\0';
    }
    const char* getOpenDate() {
        return this->OpenDate;
    }

    void setMobile(std::string v) {
        std::copy(v.begin(), v.end(), this->Mobile);
        this->Mobile[v.size()] = '\0';
    }
    const char* getMobile() {
        return this->Mobile;
    }

    void setCommModelID(std::string v) {
        std::copy(v.begin(), v.end(), this->CommModelID);
        this->CommModelID[v.size()] = '\0';
    }
    const char* getCommModelID() {
        return this->CommModelID;
    }

    void setMarginModelID(std::string v) {
        std::copy(v.begin(), v.end(), this->MarginModelID);
        this->MarginModelID[v.size()] = '\0';
    }
    const char* getMarginModelID() {
        return this->MarginModelID;
    }
};

struct TradingCodeField: CThostFtdcTradingCodeField {

    TradingCodeField() {
        std::memset(this, 0, sizeof(TradingCodeField));
    }

    TradingCodeField(const CThostFtdcTradingCodeField& f): CThostFtdcTradingCodeField(f){}

    TradingCodeField& operator=(const CThostFtdcTradingCodeField& f) {
        CThostFtdcTradingCodeField::operator=(f);
        return *this;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }
};

struct TradingAccountField: CThostFtdcTradingAccountField {

    TradingAccountField() {
        std::memset(this, 0, sizeof(TradingAccountField));
    }

    TradingAccountField(const CThostFtdcTradingAccountField& f): CThostFtdcTradingAccountField(f){}

    TradingAccountField& operator=(const CThostFtdcTradingAccountField& f) {
        CThostFtdcTradingAccountField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }
};

struct InvestorPositionField: CThostFtdcInvestorPositionField {

    InvestorPositionField() {
        std::memset(this, 0, sizeof(InvestorPositionField));
    }

    InvestorPositionField(const CThostFtdcInvestorPositionField& f): CThostFtdcInvestorPositionField(f){}

    InvestorPositionField& operator=(const CThostFtdcInvestorPositionField& f) {
        CThostFtdcInvestorPositionField::operator=(f);
        return *this;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }
};

struct InstrumentMarginRateField: CThostFtdcInstrumentMarginRateField {

    InstrumentMarginRateField() {
        std::memset(this, 0, sizeof(InstrumentMarginRateField));
    }

    InstrumentMarginRateField(const CThostFtdcInstrumentMarginRateField& f): CThostFtdcInstrumentMarginRateField(f){}

    InstrumentMarginRateField& operator=(const CThostFtdcInstrumentMarginRateField& f) {
        CThostFtdcInstrumentMarginRateField::operator=(f);
        return *this;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }
};

struct InstrumentCommissionRateField: CThostFtdcInstrumentCommissionRateField {

    InstrumentCommissionRateField() {
        std::memset(this, 0, sizeof(InstrumentCommissionRateField));
    }

    InstrumentCommissionRateField(const CThostFtdcInstrumentCommissionRateField& f): CThostFtdcInstrumentCommissionRateField(f){}

    InstrumentCommissionRateField& operator=(const CThostFtdcInstrumentCommissionRateField& f) {
        CThostFtdcInstrumentCommissionRateField::operator=(f);
        return *this;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }
};

struct DepthMarketDataField: CThostFtdcDepthMarketDataField {

    DepthMarketDataField() {
        std::memset(this, 0, sizeof(DepthMarketDataField));
    }

    DepthMarketDataField(const CThostFtdcDepthMarketDataField& f): CThostFtdcDepthMarketDataField(f){}

    DepthMarketDataField& operator=(const CThostFtdcDepthMarketDataField& f) {
        CThostFtdcDepthMarketDataField::operator=(f);
        return *this;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setExchangeInstID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeInstID);
        this->ExchangeInstID[v.size()] = '\0';
    }
    const char* getExchangeInstID() {
        return this->ExchangeInstID;
    }

    void setUpdateTime(std::string v) {
        std::copy(v.begin(), v.end(), this->UpdateTime);
        this->UpdateTime[v.size()] = '\0';
    }
    const char* getUpdateTime() {
        return this->UpdateTime;
    }

    void setActionDay(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionDay);
        this->ActionDay[v.size()] = '\0';
    }
    const char* getActionDay() {
        return this->ActionDay;
    }
};

struct SettlementInfoField: CThostFtdcSettlementInfoField {

    SettlementInfoField() {
        std::memset(this, 0, sizeof(SettlementInfoField));
    }

    SettlementInfoField(const CThostFtdcSettlementInfoField& f): CThostFtdcSettlementInfoField(f){}

    SettlementInfoField& operator=(const CThostFtdcSettlementInfoField& f) {
        CThostFtdcSettlementInfoField::operator=(f);
        return *this;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setContent(std::string v) {
        std::copy(v.begin(), v.end(), this->Content);
        this->Content[v.size()] = '\0';
    }
    const char* getContent() {
        return this->Content;
    }
};

struct ExchangeMarginRateField: CThostFtdcExchangeMarginRateField {

    ExchangeMarginRateField() {
        std::memset(this, 0, sizeof(ExchangeMarginRateField));
    }

    ExchangeMarginRateField(const CThostFtdcExchangeMarginRateField& f): CThostFtdcExchangeMarginRateField(f){}

    ExchangeMarginRateField& operator=(const CThostFtdcExchangeMarginRateField& f) {
        CThostFtdcExchangeMarginRateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct ExchangeMarginRateAdjustField: CThostFtdcExchangeMarginRateAdjustField {

    ExchangeMarginRateAdjustField() {
        std::memset(this, 0, sizeof(ExchangeMarginRateAdjustField));
    }

    ExchangeMarginRateAdjustField(const CThostFtdcExchangeMarginRateAdjustField& f): CThostFtdcExchangeMarginRateAdjustField(f){}

    ExchangeMarginRateAdjustField& operator=(const CThostFtdcExchangeMarginRateAdjustField& f) {
        CThostFtdcExchangeMarginRateAdjustField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct ExchangeRateField: CThostFtdcExchangeRateField {

    ExchangeRateField() {
        std::memset(this, 0, sizeof(ExchangeRateField));
    }

    ExchangeRateField(const CThostFtdcExchangeRateField& f): CThostFtdcExchangeRateField(f){}

    ExchangeRateField& operator=(const CThostFtdcExchangeRateField& f) {
        CThostFtdcExchangeRateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setFromCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->FromCurrencyID);
        this->FromCurrencyID[v.size()] = '\0';
    }
    const char* getFromCurrencyID() {
        return this->FromCurrencyID;
    }

    void setToCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->ToCurrencyID);
        this->ToCurrencyID[v.size()] = '\0';
    }
    const char* getToCurrencyID() {
        return this->ToCurrencyID;
    }
};

struct UserPasswordUpdateField: CThostFtdcUserPasswordUpdateField {

    UserPasswordUpdateField() {
        std::memset(this, 0, sizeof(UserPasswordUpdateField));
    }

    UserPasswordUpdateField(const CThostFtdcUserPasswordUpdateField& f): CThostFtdcUserPasswordUpdateField(f){}

    UserPasswordUpdateField& operator=(const CThostFtdcUserPasswordUpdateField& f) {
        CThostFtdcUserPasswordUpdateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setOldPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->OldPassword);
        this->OldPassword[v.size()] = '\0';
    }
    const char* getOldPassword() {
        return this->OldPassword;
    }

    void setNewPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->NewPassword);
        this->NewPassword[v.size()] = '\0';
    }
    const char* getNewPassword() {
        return this->NewPassword;
    }
};

struct InputOrderField: CThostFtdcInputOrderField {

    InputOrderField() {
        std::memset(this, 0, sizeof(InputOrderField));
    }

    InputOrderField(const CThostFtdcInputOrderField& f): CThostFtdcInputOrderField(f){}

    InputOrderField& operator=(const CThostFtdcInputOrderField& f) {
        CThostFtdcInputOrderField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderRef);
        this->OrderRef[v.size()] = '\0';
    }
    const char* getOrderRef() {
        return this->OrderRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setCombOffsetFlag(std::string v) {
        std::copy(v.begin(), v.end(), this->CombOffsetFlag);
        this->CombOffsetFlag[v.size()] = '\0';
    }
    const char* getCombOffsetFlag() {
        return this->CombOffsetFlag;
    }

    void setCombHedgeFlag(std::string v) {
        std::copy(v.begin(), v.end(), this->CombHedgeFlag);
        this->CombHedgeFlag[v.size()] = '\0';
    }
    const char* getCombHedgeFlag() {
        return this->CombHedgeFlag;
    }

    void setGTDDate(std::string v) {
        std::copy(v.begin(), v.end(), this->GTDDate);
        this->GTDDate[v.size()] = '\0';
    }
    const char* getGTDDate() {
        return this->GTDDate;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct OrderField: CThostFtdcOrderField {

    OrderField() {
        std::memset(this, 0, sizeof(OrderField));
    }

    OrderField(const CThostFtdcOrderField& f): CThostFtdcOrderField(f){}

    OrderField& operator=(const CThostFtdcOrderField& f) {
        CThostFtdcOrderField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderRef);
        this->OrderRef[v.size()] = '\0';
    }
    const char* getOrderRef() {
        return this->OrderRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setCombOffsetFlag(std::string v) {
        std::copy(v.begin(), v.end(), this->CombOffsetFlag);
        this->CombOffsetFlag[v.size()] = '\0';
    }
    const char* getCombOffsetFlag() {
        return this->CombOffsetFlag;
    }

    void setCombHedgeFlag(std::string v) {
        std::copy(v.begin(), v.end(), this->CombHedgeFlag);
        this->CombHedgeFlag[v.size()] = '\0';
    }
    const char* getCombHedgeFlag() {
        return this->CombHedgeFlag;
    }

    void setGTDDate(std::string v) {
        std::copy(v.begin(), v.end(), this->GTDDate);
        this->GTDDate[v.size()] = '\0';
    }
    const char* getGTDDate() {
        return this->GTDDate;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setOrderLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderLocalID);
        this->OrderLocalID[v.size()] = '\0';
    }
    const char* getOrderLocalID() {
        return this->OrderLocalID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setExchangeInstID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeInstID);
        this->ExchangeInstID[v.size()] = '\0';
    }
    const char* getExchangeInstID() {
        return this->ExchangeInstID;
    }

    void setTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->TraderID);
        this->TraderID[v.size()] = '\0';
    }
    const char* getTraderID() {
        return this->TraderID;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderSysID);
        this->OrderSysID[v.size()] = '\0';
    }
    const char* getOrderSysID() {
        return this->OrderSysID;
    }

    void setInsertDate(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertDate);
        this->InsertDate[v.size()] = '\0';
    }
    const char* getInsertDate() {
        return this->InsertDate;
    }

    void setInsertTime(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTime);
        this->InsertTime[v.size()] = '\0';
    }
    const char* getInsertTime() {
        return this->InsertTime;
    }

    void setActiveTime(std::string v) {
        std::copy(v.begin(), v.end(), this->ActiveTime);
        this->ActiveTime[v.size()] = '\0';
    }
    const char* getActiveTime() {
        return this->ActiveTime;
    }

    void setSuspendTime(std::string v) {
        std::copy(v.begin(), v.end(), this->SuspendTime);
        this->SuspendTime[v.size()] = '\0';
    }
    const char* getSuspendTime() {
        return this->SuspendTime;
    }

    void setUpdateTime(std::string v) {
        std::copy(v.begin(), v.end(), this->UpdateTime);
        this->UpdateTime[v.size()] = '\0';
    }
    const char* getUpdateTime() {
        return this->UpdateTime;
    }

    void setCancelTime(std::string v) {
        std::copy(v.begin(), v.end(), this->CancelTime);
        this->CancelTime[v.size()] = '\0';
    }
    const char* getCancelTime() {
        return this->CancelTime;
    }

    void setActiveTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActiveTraderID);
        this->ActiveTraderID[v.size()] = '\0';
    }
    const char* getActiveTraderID() {
        return this->ActiveTraderID;
    }

    void setClearingPartID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClearingPartID);
        this->ClearingPartID[v.size()] = '\0';
    }
    const char* getClearingPartID() {
        return this->ClearingPartID;
    }

    void setUserProductInfo(std::string v) {
        std::copy(v.begin(), v.end(), this->UserProductInfo);
        this->UserProductInfo[v.size()] = '\0';
    }
    const char* getUserProductInfo() {
        return this->UserProductInfo;
    }

    void setStatusMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->StatusMsg);
        this->StatusMsg[v.size()] = '\0';
    }
    const char* getStatusMsg() {
        return this->StatusMsg;
    }

    void setActiveUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActiveUserID);
        this->ActiveUserID[v.size()] = '\0';
    }
    const char* getActiveUserID() {
        return this->ActiveUserID;
    }

    void setRelativeOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->RelativeOrderSysID);
        this->RelativeOrderSysID[v.size()] = '\0';
    }
    const char* getRelativeOrderSysID() {
        return this->RelativeOrderSysID;
    }

    void setBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BranchID);
        this->BranchID[v.size()] = '\0';
    }
    const char* getBranchID() {
        return this->BranchID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct InputOrderActionField: CThostFtdcInputOrderActionField {

    InputOrderActionField() {
        std::memset(this, 0, sizeof(InputOrderActionField));
    }

    InputOrderActionField(const CThostFtdcInputOrderActionField& f): CThostFtdcInputOrderActionField(f){}

    InputOrderActionField& operator=(const CThostFtdcInputOrderActionField& f) {
        CThostFtdcInputOrderActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderRef);
        this->OrderRef[v.size()] = '\0';
    }
    const char* getOrderRef() {
        return this->OrderRef;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderSysID);
        this->OrderSysID[v.size()] = '\0';
    }
    const char* getOrderSysID() {
        return this->OrderSysID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct OrderActionField: CThostFtdcOrderActionField {

    OrderActionField() {
        std::memset(this, 0, sizeof(OrderActionField));
    }

    OrderActionField(const CThostFtdcOrderActionField& f): CThostFtdcOrderActionField(f){}

    OrderActionField& operator=(const CThostFtdcOrderActionField& f) {
        CThostFtdcOrderActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderRef);
        this->OrderRef[v.size()] = '\0';
    }
    const char* getOrderRef() {
        return this->OrderRef;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderSysID);
        this->OrderSysID[v.size()] = '\0';
    }
    const char* getOrderSysID() {
        return this->OrderSysID;
    }

    void setActionDate(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionDate);
        this->ActionDate[v.size()] = '\0';
    }
    const char* getActionDate() {
        return this->ActionDate;
    }

    void setActionTime(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionTime);
        this->ActionTime[v.size()] = '\0';
    }
    const char* getActionTime() {
        return this->ActionTime;
    }

    void setTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->TraderID);
        this->TraderID[v.size()] = '\0';
    }
    const char* getTraderID() {
        return this->TraderID;
    }

    void setOrderLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderLocalID);
        this->OrderLocalID[v.size()] = '\0';
    }
    const char* getOrderLocalID() {
        return this->OrderLocalID;
    }

    void setActionLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionLocalID);
        this->ActionLocalID[v.size()] = '\0';
    }
    const char* getActionLocalID() {
        return this->ActionLocalID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setStatusMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->StatusMsg);
        this->StatusMsg[v.size()] = '\0';
    }
    const char* getStatusMsg() {
        return this->StatusMsg;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BranchID);
        this->BranchID[v.size()] = '\0';
    }
    const char* getBranchID() {
        return this->BranchID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct TradeField: CThostFtdcTradeField {

    TradeField() {
        std::memset(this, 0, sizeof(TradeField));
    }

    TradeField(const CThostFtdcTradeField& f): CThostFtdcTradeField(f){}

    TradeField& operator=(const CThostFtdcTradeField& f) {
        CThostFtdcTradeField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderRef);
        this->OrderRef[v.size()] = '\0';
    }
    const char* getOrderRef() {
        return this->OrderRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setTradeID(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeID);
        this->TradeID[v.size()] = '\0';
    }
    const char* getTradeID() {
        return this->TradeID;
    }

    void setOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderSysID);
        this->OrderSysID[v.size()] = '\0';
    }
    const char* getOrderSysID() {
        return this->OrderSysID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setExchangeInstID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeInstID);
        this->ExchangeInstID[v.size()] = '\0';
    }
    const char* getExchangeInstID() {
        return this->ExchangeInstID;
    }

    void setTradeDate(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDate);
        this->TradeDate[v.size()] = '\0';
    }
    const char* getTradeDate() {
        return this->TradeDate;
    }

    void setTradeTime(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTime);
        this->TradeTime[v.size()] = '\0';
    }
    const char* getTradeTime() {
        return this->TradeTime;
    }

    void setTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->TraderID);
        this->TraderID[v.size()] = '\0';
    }
    const char* getTraderID() {
        return this->TraderID;
    }

    void setOrderLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderLocalID);
        this->OrderLocalID[v.size()] = '\0';
    }
    const char* getOrderLocalID() {
        return this->OrderLocalID;
    }

    void setClearingPartID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClearingPartID);
        this->ClearingPartID[v.size()] = '\0';
    }
    const char* getClearingPartID() {
        return this->ClearingPartID;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }
};

struct QueryMaxOrderVolumeField: CThostFtdcQueryMaxOrderVolumeField {

    QueryMaxOrderVolumeField() {
        std::memset(this, 0, sizeof(QueryMaxOrderVolumeField));
    }

    QueryMaxOrderVolumeField(const CThostFtdcQueryMaxOrderVolumeField& f): CThostFtdcQueryMaxOrderVolumeField(f){}

    QueryMaxOrderVolumeField& operator=(const CThostFtdcQueryMaxOrderVolumeField& f) {
        CThostFtdcQueryMaxOrderVolumeField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct SettlementInfoConfirmField: CThostFtdcSettlementInfoConfirmField {

    SettlementInfoConfirmField() {
        std::memset(this, 0, sizeof(SettlementInfoConfirmField));
    }

    SettlementInfoConfirmField(const CThostFtdcSettlementInfoConfirmField& f): CThostFtdcSettlementInfoConfirmField(f){}

    SettlementInfoConfirmField& operator=(const CThostFtdcSettlementInfoConfirmField& f) {
        CThostFtdcSettlementInfoConfirmField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setConfirmDate(std::string v) {
        std::copy(v.begin(), v.end(), this->ConfirmDate);
        this->ConfirmDate[v.size()] = '\0';
    }
    const char* getConfirmDate() {
        return this->ConfirmDate;
    }

    void setConfirmTime(std::string v) {
        std::copy(v.begin(), v.end(), this->ConfirmTime);
        this->ConfirmTime[v.size()] = '\0';
    }
    const char* getConfirmTime() {
        return this->ConfirmTime;
    }
};

struct QryOrderField: CThostFtdcQryOrderField {

    QryOrderField() {
        std::memset(this, 0, sizeof(QryOrderField));
    }

    QryOrderField(const CThostFtdcQryOrderField& f): CThostFtdcQryOrderField(f){}

    QryOrderField& operator=(const CThostFtdcQryOrderField& f) {
        CThostFtdcQryOrderField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderSysID);
        this->OrderSysID[v.size()] = '\0';
    }
    const char* getOrderSysID() {
        return this->OrderSysID;
    }

    void setInsertTimeStart(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTimeStart);
        this->InsertTimeStart[v.size()] = '\0';
    }
    const char* getInsertTimeStart() {
        return this->InsertTimeStart;
    }

    void setInsertTimeEnd(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTimeEnd);
        this->InsertTimeEnd[v.size()] = '\0';
    }
    const char* getInsertTimeEnd() {
        return this->InsertTimeEnd;
    }
};

struct QryTradeField: CThostFtdcQryTradeField {

    QryTradeField() {
        std::memset(this, 0, sizeof(QryTradeField));
    }

    QryTradeField(const CThostFtdcQryTradeField& f): CThostFtdcQryTradeField(f){}

    QryTradeField& operator=(const CThostFtdcQryTradeField& f) {
        CThostFtdcQryTradeField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setTradeID(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeID);
        this->TradeID[v.size()] = '\0';
    }
    const char* getTradeID() {
        return this->TradeID;
    }

    void setTradeTimeStart(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTimeStart);
        this->TradeTimeStart[v.size()] = '\0';
    }
    const char* getTradeTimeStart() {
        return this->TradeTimeStart;
    }

    void setTradeTimeEnd(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTimeEnd);
        this->TradeTimeEnd[v.size()] = '\0';
    }
    const char* getTradeTimeEnd() {
        return this->TradeTimeEnd;
    }
};

struct QryInvestorPositionField: CThostFtdcQryInvestorPositionField {

    QryInvestorPositionField() {
        std::memset(this, 0, sizeof(QryInvestorPositionField));
    }

    QryInvestorPositionField(const CThostFtdcQryInvestorPositionField& f): CThostFtdcQryInvestorPositionField(f){}

    QryInvestorPositionField& operator=(const CThostFtdcQryInvestorPositionField& f) {
        CThostFtdcQryInvestorPositionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct QryTradingAccountField: CThostFtdcQryTradingAccountField {

    QryTradingAccountField() {
        std::memset(this, 0, sizeof(QryTradingAccountField));
    }

    QryTradingAccountField(const CThostFtdcQryTradingAccountField& f): CThostFtdcQryTradingAccountField(f){}

    QryTradingAccountField& operator=(const CThostFtdcQryTradingAccountField& f) {
        CThostFtdcQryTradingAccountField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }
};

struct QryInvestorField: CThostFtdcQryInvestorField {

    QryInvestorField() {
        std::memset(this, 0, sizeof(QryInvestorField));
    }

    QryInvestorField(const CThostFtdcQryInvestorField& f): CThostFtdcQryInvestorField(f){}

    QryInvestorField& operator=(const CThostFtdcQryInvestorField& f) {
        CThostFtdcQryInvestorField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }
};

struct QryTradingCodeField: CThostFtdcQryTradingCodeField {

    QryTradingCodeField() {
        std::memset(this, 0, sizeof(QryTradingCodeField));
    }

    QryTradingCodeField(const CThostFtdcQryTradingCodeField& f): CThostFtdcQryTradingCodeField(f){}

    QryTradingCodeField& operator=(const CThostFtdcQryTradingCodeField& f) {
        CThostFtdcQryTradingCodeField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }
};

struct QryInstrumentMarginRateField: CThostFtdcQryInstrumentMarginRateField {

    QryInstrumentMarginRateField() {
        std::memset(this, 0, sizeof(QryInstrumentMarginRateField));
    }

    QryInstrumentMarginRateField(const CThostFtdcQryInstrumentMarginRateField& f): CThostFtdcQryInstrumentMarginRateField(f){}

    QryInstrumentMarginRateField& operator=(const CThostFtdcQryInstrumentMarginRateField& f) {
        CThostFtdcQryInstrumentMarginRateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct QryInstrumentCommissionRateField: CThostFtdcQryInstrumentCommissionRateField {

    QryInstrumentCommissionRateField() {
        std::memset(this, 0, sizeof(QryInstrumentCommissionRateField));
    }

    QryInstrumentCommissionRateField(const CThostFtdcQryInstrumentCommissionRateField& f): CThostFtdcQryInstrumentCommissionRateField(f){}

    QryInstrumentCommissionRateField& operator=(const CThostFtdcQryInstrumentCommissionRateField& f) {
        CThostFtdcQryInstrumentCommissionRateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct QryExchangeField: CThostFtdcQryExchangeField {

    QryExchangeField() {
        std::memset(this, 0, sizeof(QryExchangeField));
    }

    QryExchangeField(const CThostFtdcQryExchangeField& f): CThostFtdcQryExchangeField(f){}

    QryExchangeField& operator=(const CThostFtdcQryExchangeField& f) {
        CThostFtdcQryExchangeField::operator=(f);
        return *this;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }
};

struct QryProductField: CThostFtdcQryProductField {

    QryProductField() {
        std::memset(this, 0, sizeof(QryProductField));
    }

    QryProductField(const CThostFtdcQryProductField& f): CThostFtdcQryProductField(f){}

    QryProductField& operator=(const CThostFtdcQryProductField& f) {
        CThostFtdcQryProductField::operator=(f);
        return *this;
    }

    void setProductID(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductID);
        this->ProductID[v.size()] = '\0';
    }
    const char* getProductID() {
        return this->ProductID;
    }
};

struct QryInstrumentField: CThostFtdcQryInstrumentField {

    QryInstrumentField() {
        std::memset(this, 0, sizeof(QryInstrumentField));
    }

    QryInstrumentField(const CThostFtdcQryInstrumentField& f): CThostFtdcQryInstrumentField(f){}

    QryInstrumentField& operator=(const CThostFtdcQryInstrumentField& f) {
        CThostFtdcQryInstrumentField::operator=(f);
        return *this;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setExchangeInstID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeInstID);
        this->ExchangeInstID[v.size()] = '\0';
    }
    const char* getExchangeInstID() {
        return this->ExchangeInstID;
    }

    void setProductID(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductID);
        this->ProductID[v.size()] = '\0';
    }
    const char* getProductID() {
        return this->ProductID;
    }
};

struct QryDepthMarketDataField: CThostFtdcQryDepthMarketDataField {

    QryDepthMarketDataField() {
        std::memset(this, 0, sizeof(QryDepthMarketDataField));
    }

    QryDepthMarketDataField(const CThostFtdcQryDepthMarketDataField& f): CThostFtdcQryDepthMarketDataField(f){}

    QryDepthMarketDataField& operator=(const CThostFtdcQryDepthMarketDataField& f) {
        CThostFtdcQryDepthMarketDataField::operator=(f);
        return *this;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct QrySettlementInfoField: CThostFtdcQrySettlementInfoField {

    QrySettlementInfoField() {
        std::memset(this, 0, sizeof(QrySettlementInfoField));
    }

    QrySettlementInfoField(const CThostFtdcQrySettlementInfoField& f): CThostFtdcQrySettlementInfoField(f){}

    QrySettlementInfoField& operator=(const CThostFtdcQrySettlementInfoField& f) {
        CThostFtdcQrySettlementInfoField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }
};

struct QryExchangeMarginRateField: CThostFtdcQryExchangeMarginRateField {

    QryExchangeMarginRateField() {
        std::memset(this, 0, sizeof(QryExchangeMarginRateField));
    }

    QryExchangeMarginRateField(const CThostFtdcQryExchangeMarginRateField& f): CThostFtdcQryExchangeMarginRateField(f){}

    QryExchangeMarginRateField& operator=(const CThostFtdcQryExchangeMarginRateField& f) {
        CThostFtdcQryExchangeMarginRateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct QryExchangeMarginRateAdjustField: CThostFtdcQryExchangeMarginRateAdjustField {

    QryExchangeMarginRateAdjustField() {
        std::memset(this, 0, sizeof(QryExchangeMarginRateAdjustField));
    }

    QryExchangeMarginRateAdjustField(const CThostFtdcQryExchangeMarginRateAdjustField& f): CThostFtdcQryExchangeMarginRateAdjustField(f){}

    QryExchangeMarginRateAdjustField& operator=(const CThostFtdcQryExchangeMarginRateAdjustField& f) {
        CThostFtdcQryExchangeMarginRateAdjustField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct QryExchangeRateField: CThostFtdcQryExchangeRateField {

    QryExchangeRateField() {
        std::memset(this, 0, sizeof(QryExchangeRateField));
    }

    QryExchangeRateField(const CThostFtdcQryExchangeRateField& f): CThostFtdcQryExchangeRateField(f){}

    QryExchangeRateField& operator=(const CThostFtdcQryExchangeRateField& f) {
        CThostFtdcQryExchangeRateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setFromCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->FromCurrencyID);
        this->FromCurrencyID[v.size()] = '\0';
    }
    const char* getFromCurrencyID() {
        return this->FromCurrencyID;
    }

    void setToCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->ToCurrencyID);
        this->ToCurrencyID[v.size()] = '\0';
    }
    const char* getToCurrencyID() {
        return this->ToCurrencyID;
    }
};

struct OptionInstrCommRateField: CThostFtdcOptionInstrCommRateField {

    OptionInstrCommRateField() {
        std::memset(this, 0, sizeof(OptionInstrCommRateField));
    }

    OptionInstrCommRateField(const CThostFtdcOptionInstrCommRateField& f): CThostFtdcOptionInstrCommRateField(f){}

    OptionInstrCommRateField& operator=(const CThostFtdcOptionInstrCommRateField& f) {
        CThostFtdcOptionInstrCommRateField::operator=(f);
        return *this;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }
};

struct OptionInstrTradeCostField: CThostFtdcOptionInstrTradeCostField {

    OptionInstrTradeCostField() {
        std::memset(this, 0, sizeof(OptionInstrTradeCostField));
    }

    OptionInstrTradeCostField(const CThostFtdcOptionInstrTradeCostField& f): CThostFtdcOptionInstrTradeCostField(f){}

    OptionInstrTradeCostField& operator=(const CThostFtdcOptionInstrTradeCostField& f) {
        CThostFtdcOptionInstrTradeCostField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct QryOptionInstrTradeCostField: CThostFtdcQryOptionInstrTradeCostField {

    QryOptionInstrTradeCostField() {
        std::memset(this, 0, sizeof(QryOptionInstrTradeCostField));
    }

    QryOptionInstrTradeCostField(const CThostFtdcQryOptionInstrTradeCostField& f): CThostFtdcQryOptionInstrTradeCostField(f){}

    QryOptionInstrTradeCostField& operator=(const CThostFtdcQryOptionInstrTradeCostField& f) {
        CThostFtdcQryOptionInstrTradeCostField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct QryOptionInstrCommRateField: CThostFtdcQryOptionInstrCommRateField {

    QryOptionInstrCommRateField() {
        std::memset(this, 0, sizeof(QryOptionInstrCommRateField));
    }

    QryOptionInstrCommRateField(const CThostFtdcQryOptionInstrCommRateField& f): CThostFtdcQryOptionInstrCommRateField(f){}

    QryOptionInstrCommRateField& operator=(const CThostFtdcQryOptionInstrCommRateField& f) {
        CThostFtdcQryOptionInstrCommRateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct InputExecOrderField: CThostFtdcInputExecOrderField {

    InputExecOrderField() {
        std::memset(this, 0, sizeof(InputExecOrderField));
    }

    InputExecOrderField(const CThostFtdcInputExecOrderField& f): CThostFtdcInputExecOrderField(f){}

    InputExecOrderField& operator=(const CThostFtdcInputExecOrderField& f) {
        CThostFtdcInputExecOrderField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExecOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->ExecOrderRef);
        this->ExecOrderRef[v.size()] = '\0';
    }
    const char* getExecOrderRef() {
        return this->ExecOrderRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct InputExecOrderActionField: CThostFtdcInputExecOrderActionField {

    InputExecOrderActionField() {
        std::memset(this, 0, sizeof(InputExecOrderActionField));
    }

    InputExecOrderActionField(const CThostFtdcInputExecOrderActionField& f): CThostFtdcInputExecOrderActionField(f){}

    InputExecOrderActionField& operator=(const CThostFtdcInputExecOrderActionField& f) {
        CThostFtdcInputExecOrderActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setExecOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->ExecOrderRef);
        this->ExecOrderRef[v.size()] = '\0';
    }
    const char* getExecOrderRef() {
        return this->ExecOrderRef;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setExecOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExecOrderSysID);
        this->ExecOrderSysID[v.size()] = '\0';
    }
    const char* getExecOrderSysID() {
        return this->ExecOrderSysID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct ExecOrderField: CThostFtdcExecOrderField {

    ExecOrderField() {
        std::memset(this, 0, sizeof(ExecOrderField));
    }

    ExecOrderField(const CThostFtdcExecOrderField& f): CThostFtdcExecOrderField(f){}

    ExecOrderField& operator=(const CThostFtdcExecOrderField& f) {
        CThostFtdcExecOrderField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExecOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->ExecOrderRef);
        this->ExecOrderRef[v.size()] = '\0';
    }
    const char* getExecOrderRef() {
        return this->ExecOrderRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setExecOrderLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExecOrderLocalID);
        this->ExecOrderLocalID[v.size()] = '\0';
    }
    const char* getExecOrderLocalID() {
        return this->ExecOrderLocalID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setExchangeInstID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeInstID);
        this->ExchangeInstID[v.size()] = '\0';
    }
    const char* getExchangeInstID() {
        return this->ExchangeInstID;
    }

    void setTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->TraderID);
        this->TraderID[v.size()] = '\0';
    }
    const char* getTraderID() {
        return this->TraderID;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setExecOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExecOrderSysID);
        this->ExecOrderSysID[v.size()] = '\0';
    }
    const char* getExecOrderSysID() {
        return this->ExecOrderSysID;
    }

    void setInsertDate(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertDate);
        this->InsertDate[v.size()] = '\0';
    }
    const char* getInsertDate() {
        return this->InsertDate;
    }

    void setInsertTime(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTime);
        this->InsertTime[v.size()] = '\0';
    }
    const char* getInsertTime() {
        return this->InsertTime;
    }

    void setCancelTime(std::string v) {
        std::copy(v.begin(), v.end(), this->CancelTime);
        this->CancelTime[v.size()] = '\0';
    }
    const char* getCancelTime() {
        return this->CancelTime;
    }

    void setClearingPartID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClearingPartID);
        this->ClearingPartID[v.size()] = '\0';
    }
    const char* getClearingPartID() {
        return this->ClearingPartID;
    }

    void setUserProductInfo(std::string v) {
        std::copy(v.begin(), v.end(), this->UserProductInfo);
        this->UserProductInfo[v.size()] = '\0';
    }
    const char* getUserProductInfo() {
        return this->UserProductInfo;
    }

    void setStatusMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->StatusMsg);
        this->StatusMsg[v.size()] = '\0';
    }
    const char* getStatusMsg() {
        return this->StatusMsg;
    }

    void setActiveUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActiveUserID);
        this->ActiveUserID[v.size()] = '\0';
    }
    const char* getActiveUserID() {
        return this->ActiveUserID;
    }

    void setBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BranchID);
        this->BranchID[v.size()] = '\0';
    }
    const char* getBranchID() {
        return this->BranchID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct ExecOrderActionField: CThostFtdcExecOrderActionField {

    ExecOrderActionField() {
        std::memset(this, 0, sizeof(ExecOrderActionField));
    }

    ExecOrderActionField(const CThostFtdcExecOrderActionField& f): CThostFtdcExecOrderActionField(f){}

    ExecOrderActionField& operator=(const CThostFtdcExecOrderActionField& f) {
        CThostFtdcExecOrderActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setExecOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->ExecOrderRef);
        this->ExecOrderRef[v.size()] = '\0';
    }
    const char* getExecOrderRef() {
        return this->ExecOrderRef;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setExecOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExecOrderSysID);
        this->ExecOrderSysID[v.size()] = '\0';
    }
    const char* getExecOrderSysID() {
        return this->ExecOrderSysID;
    }

    void setActionDate(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionDate);
        this->ActionDate[v.size()] = '\0';
    }
    const char* getActionDate() {
        return this->ActionDate;
    }

    void setActionTime(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionTime);
        this->ActionTime[v.size()] = '\0';
    }
    const char* getActionTime() {
        return this->ActionTime;
    }

    void setTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->TraderID);
        this->TraderID[v.size()] = '\0';
    }
    const char* getTraderID() {
        return this->TraderID;
    }

    void setExecOrderLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExecOrderLocalID);
        this->ExecOrderLocalID[v.size()] = '\0';
    }
    const char* getExecOrderLocalID() {
        return this->ExecOrderLocalID;
    }

    void setActionLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionLocalID);
        this->ActionLocalID[v.size()] = '\0';
    }
    const char* getActionLocalID() {
        return this->ActionLocalID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setStatusMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->StatusMsg);
        this->StatusMsg[v.size()] = '\0';
    }
    const char* getStatusMsg() {
        return this->StatusMsg;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BranchID);
        this->BranchID[v.size()] = '\0';
    }
    const char* getBranchID() {
        return this->BranchID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct QryExecOrderField: CThostFtdcQryExecOrderField {

    QryExecOrderField() {
        std::memset(this, 0, sizeof(QryExecOrderField));
    }

    QryExecOrderField(const CThostFtdcQryExecOrderField& f): CThostFtdcQryExecOrderField(f){}

    QryExecOrderField& operator=(const CThostFtdcQryExecOrderField& f) {
        CThostFtdcQryExecOrderField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setExecOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExecOrderSysID);
        this->ExecOrderSysID[v.size()] = '\0';
    }
    const char* getExecOrderSysID() {
        return this->ExecOrderSysID;
    }

    void setInsertTimeStart(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTimeStart);
        this->InsertTimeStart[v.size()] = '\0';
    }
    const char* getInsertTimeStart() {
        return this->InsertTimeStart;
    }

    void setInsertTimeEnd(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTimeEnd);
        this->InsertTimeEnd[v.size()] = '\0';
    }
    const char* getInsertTimeEnd() {
        return this->InsertTimeEnd;
    }
};

struct InputForQuoteField: CThostFtdcInputForQuoteField {

    InputForQuoteField() {
        std::memset(this, 0, sizeof(InputForQuoteField));
    }

    InputForQuoteField(const CThostFtdcInputForQuoteField& f): CThostFtdcInputForQuoteField(f){}

    InputForQuoteField& operator=(const CThostFtdcInputForQuoteField& f) {
        CThostFtdcInputForQuoteField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setForQuoteRef(std::string v) {
        std::copy(v.begin(), v.end(), this->ForQuoteRef);
        this->ForQuoteRef[v.size()] = '\0';
    }
    const char* getForQuoteRef() {
        return this->ForQuoteRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct ForQuoteField: CThostFtdcForQuoteField {

    ForQuoteField() {
        std::memset(this, 0, sizeof(ForQuoteField));
    }

    ForQuoteField(const CThostFtdcForQuoteField& f): CThostFtdcForQuoteField(f){}

    ForQuoteField& operator=(const CThostFtdcForQuoteField& f) {
        CThostFtdcForQuoteField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setForQuoteRef(std::string v) {
        std::copy(v.begin(), v.end(), this->ForQuoteRef);
        this->ForQuoteRef[v.size()] = '\0';
    }
    const char* getForQuoteRef() {
        return this->ForQuoteRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setForQuoteLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->ForQuoteLocalID);
        this->ForQuoteLocalID[v.size()] = '\0';
    }
    const char* getForQuoteLocalID() {
        return this->ForQuoteLocalID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setExchangeInstID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeInstID);
        this->ExchangeInstID[v.size()] = '\0';
    }
    const char* getExchangeInstID() {
        return this->ExchangeInstID;
    }

    void setTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->TraderID);
        this->TraderID[v.size()] = '\0';
    }
    const char* getTraderID() {
        return this->TraderID;
    }

    void setInsertDate(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertDate);
        this->InsertDate[v.size()] = '\0';
    }
    const char* getInsertDate() {
        return this->InsertDate;
    }

    void setInsertTime(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTime);
        this->InsertTime[v.size()] = '\0';
    }
    const char* getInsertTime() {
        return this->InsertTime;
    }

    void setStatusMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->StatusMsg);
        this->StatusMsg[v.size()] = '\0';
    }
    const char* getStatusMsg() {
        return this->StatusMsg;
    }

    void setActiveUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActiveUserID);
        this->ActiveUserID[v.size()] = '\0';
    }
    const char* getActiveUserID() {
        return this->ActiveUserID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct QryForQuoteField: CThostFtdcQryForQuoteField {

    QryForQuoteField() {
        std::memset(this, 0, sizeof(QryForQuoteField));
    }

    QryForQuoteField(const CThostFtdcQryForQuoteField& f): CThostFtdcQryForQuoteField(f){}

    QryForQuoteField& operator=(const CThostFtdcQryForQuoteField& f) {
        CThostFtdcQryForQuoteField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setInsertTimeStart(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTimeStart);
        this->InsertTimeStart[v.size()] = '\0';
    }
    const char* getInsertTimeStart() {
        return this->InsertTimeStart;
    }

    void setInsertTimeEnd(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTimeEnd);
        this->InsertTimeEnd[v.size()] = '\0';
    }
    const char* getInsertTimeEnd() {
        return this->InsertTimeEnd;
    }
};

struct InputQuoteField: CThostFtdcInputQuoteField {

    InputQuoteField() {
        std::memset(this, 0, sizeof(InputQuoteField));
    }

    InputQuoteField(const CThostFtdcInputQuoteField& f): CThostFtdcInputQuoteField(f){}

    InputQuoteField& operator=(const CThostFtdcInputQuoteField& f) {
        CThostFtdcInputQuoteField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setQuoteRef(std::string v) {
        std::copy(v.begin(), v.end(), this->QuoteRef);
        this->QuoteRef[v.size()] = '\0';
    }
    const char* getQuoteRef() {
        return this->QuoteRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setAskOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->AskOrderRef);
        this->AskOrderRef[v.size()] = '\0';
    }
    const char* getAskOrderRef() {
        return this->AskOrderRef;
    }

    void setBidOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->BidOrderRef);
        this->BidOrderRef[v.size()] = '\0';
    }
    const char* getBidOrderRef() {
        return this->BidOrderRef;
    }

    void setForQuoteSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->ForQuoteSysID);
        this->ForQuoteSysID[v.size()] = '\0';
    }
    const char* getForQuoteSysID() {
        return this->ForQuoteSysID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct InputQuoteActionField: CThostFtdcInputQuoteActionField {

    InputQuoteActionField() {
        std::memset(this, 0, sizeof(InputQuoteActionField));
    }

    InputQuoteActionField(const CThostFtdcInputQuoteActionField& f): CThostFtdcInputQuoteActionField(f){}

    InputQuoteActionField& operator=(const CThostFtdcInputQuoteActionField& f) {
        CThostFtdcInputQuoteActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setQuoteRef(std::string v) {
        std::copy(v.begin(), v.end(), this->QuoteRef);
        this->QuoteRef[v.size()] = '\0';
    }
    const char* getQuoteRef() {
        return this->QuoteRef;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setQuoteSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->QuoteSysID);
        this->QuoteSysID[v.size()] = '\0';
    }
    const char* getQuoteSysID() {
        return this->QuoteSysID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct QuoteField: CThostFtdcQuoteField {

    QuoteField() {
        std::memset(this, 0, sizeof(QuoteField));
    }

    QuoteField(const CThostFtdcQuoteField& f): CThostFtdcQuoteField(f){}

    QuoteField& operator=(const CThostFtdcQuoteField& f) {
        CThostFtdcQuoteField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setQuoteRef(std::string v) {
        std::copy(v.begin(), v.end(), this->QuoteRef);
        this->QuoteRef[v.size()] = '\0';
    }
    const char* getQuoteRef() {
        return this->QuoteRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setQuoteLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->QuoteLocalID);
        this->QuoteLocalID[v.size()] = '\0';
    }
    const char* getQuoteLocalID() {
        return this->QuoteLocalID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setExchangeInstID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeInstID);
        this->ExchangeInstID[v.size()] = '\0';
    }
    const char* getExchangeInstID() {
        return this->ExchangeInstID;
    }

    void setTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->TraderID);
        this->TraderID[v.size()] = '\0';
    }
    const char* getTraderID() {
        return this->TraderID;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setQuoteSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->QuoteSysID);
        this->QuoteSysID[v.size()] = '\0';
    }
    const char* getQuoteSysID() {
        return this->QuoteSysID;
    }

    void setInsertDate(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertDate);
        this->InsertDate[v.size()] = '\0';
    }
    const char* getInsertDate() {
        return this->InsertDate;
    }

    void setInsertTime(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTime);
        this->InsertTime[v.size()] = '\0';
    }
    const char* getInsertTime() {
        return this->InsertTime;
    }

    void setCancelTime(std::string v) {
        std::copy(v.begin(), v.end(), this->CancelTime);
        this->CancelTime[v.size()] = '\0';
    }
    const char* getCancelTime() {
        return this->CancelTime;
    }

    void setClearingPartID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClearingPartID);
        this->ClearingPartID[v.size()] = '\0';
    }
    const char* getClearingPartID() {
        return this->ClearingPartID;
    }

    void setAskOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->AskOrderSysID);
        this->AskOrderSysID[v.size()] = '\0';
    }
    const char* getAskOrderSysID() {
        return this->AskOrderSysID;
    }

    void setBidOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->BidOrderSysID);
        this->BidOrderSysID[v.size()] = '\0';
    }
    const char* getBidOrderSysID() {
        return this->BidOrderSysID;
    }

    void setUserProductInfo(std::string v) {
        std::copy(v.begin(), v.end(), this->UserProductInfo);
        this->UserProductInfo[v.size()] = '\0';
    }
    const char* getUserProductInfo() {
        return this->UserProductInfo;
    }

    void setStatusMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->StatusMsg);
        this->StatusMsg[v.size()] = '\0';
    }
    const char* getStatusMsg() {
        return this->StatusMsg;
    }

    void setActiveUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActiveUserID);
        this->ActiveUserID[v.size()] = '\0';
    }
    const char* getActiveUserID() {
        return this->ActiveUserID;
    }

    void setAskOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->AskOrderRef);
        this->AskOrderRef[v.size()] = '\0';
    }
    const char* getAskOrderRef() {
        return this->AskOrderRef;
    }

    void setBidOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->BidOrderRef);
        this->BidOrderRef[v.size()] = '\0';
    }
    const char* getBidOrderRef() {
        return this->BidOrderRef;
    }

    void setForQuoteSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->ForQuoteSysID);
        this->ForQuoteSysID[v.size()] = '\0';
    }
    const char* getForQuoteSysID() {
        return this->ForQuoteSysID;
    }

    void setBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BranchID);
        this->BranchID[v.size()] = '\0';
    }
    const char* getBranchID() {
        return this->BranchID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct QuoteActionField: CThostFtdcQuoteActionField {

    QuoteActionField() {
        std::memset(this, 0, sizeof(QuoteActionField));
    }

    QuoteActionField(const CThostFtdcQuoteActionField& f): CThostFtdcQuoteActionField(f){}

    QuoteActionField& operator=(const CThostFtdcQuoteActionField& f) {
        CThostFtdcQuoteActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setQuoteRef(std::string v) {
        std::copy(v.begin(), v.end(), this->QuoteRef);
        this->QuoteRef[v.size()] = '\0';
    }
    const char* getQuoteRef() {
        return this->QuoteRef;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setQuoteSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->QuoteSysID);
        this->QuoteSysID[v.size()] = '\0';
    }
    const char* getQuoteSysID() {
        return this->QuoteSysID;
    }

    void setActionDate(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionDate);
        this->ActionDate[v.size()] = '\0';
    }
    const char* getActionDate() {
        return this->ActionDate;
    }

    void setActionTime(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionTime);
        this->ActionTime[v.size()] = '\0';
    }
    const char* getActionTime() {
        return this->ActionTime;
    }

    void setTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->TraderID);
        this->TraderID[v.size()] = '\0';
    }
    const char* getTraderID() {
        return this->TraderID;
    }

    void setQuoteLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->QuoteLocalID);
        this->QuoteLocalID[v.size()] = '\0';
    }
    const char* getQuoteLocalID() {
        return this->QuoteLocalID;
    }

    void setActionLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionLocalID);
        this->ActionLocalID[v.size()] = '\0';
    }
    const char* getActionLocalID() {
        return this->ActionLocalID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setStatusMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->StatusMsg);
        this->StatusMsg[v.size()] = '\0';
    }
    const char* getStatusMsg() {
        return this->StatusMsg;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BranchID);
        this->BranchID[v.size()] = '\0';
    }
    const char* getBranchID() {
        return this->BranchID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct QryQuoteField: CThostFtdcQryQuoteField {

    QryQuoteField() {
        std::memset(this, 0, sizeof(QryQuoteField));
    }

    QryQuoteField(const CThostFtdcQryQuoteField& f): CThostFtdcQryQuoteField(f){}

    QryQuoteField& operator=(const CThostFtdcQryQuoteField& f) {
        CThostFtdcQryQuoteField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setQuoteSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->QuoteSysID);
        this->QuoteSysID[v.size()] = '\0';
    }
    const char* getQuoteSysID() {
        return this->QuoteSysID;
    }

    void setInsertTimeStart(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTimeStart);
        this->InsertTimeStart[v.size()] = '\0';
    }
    const char* getInsertTimeStart() {
        return this->InsertTimeStart;
    }

    void setInsertTimeEnd(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTimeEnd);
        this->InsertTimeEnd[v.size()] = '\0';
    }
    const char* getInsertTimeEnd() {
        return this->InsertTimeEnd;
    }
};

struct ForQuoteRspField: CThostFtdcForQuoteRspField {

    ForQuoteRspField() {
        std::memset(this, 0, sizeof(ForQuoteRspField));
    }

    ForQuoteRspField(const CThostFtdcForQuoteRspField& f): CThostFtdcForQuoteRspField(f){}

    ForQuoteRspField& operator=(const CThostFtdcForQuoteRspField& f) {
        CThostFtdcForQuoteRspField::operator=(f);
        return *this;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setForQuoteSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->ForQuoteSysID);
        this->ForQuoteSysID[v.size()] = '\0';
    }
    const char* getForQuoteSysID() {
        return this->ForQuoteSysID;
    }

    void setForQuoteTime(std::string v) {
        std::copy(v.begin(), v.end(), this->ForQuoteTime);
        this->ForQuoteTime[v.size()] = '\0';
    }
    const char* getForQuoteTime() {
        return this->ForQuoteTime;
    }

    void setActionDay(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionDay);
        this->ActionDay[v.size()] = '\0';
    }
    const char* getActionDay() {
        return this->ActionDay;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }
};

struct InputBatchOrderActionField: CThostFtdcInputBatchOrderActionField {

    InputBatchOrderActionField() {
        std::memset(this, 0, sizeof(InputBatchOrderActionField));
    }

    InputBatchOrderActionField(const CThostFtdcInputBatchOrderActionField& f): CThostFtdcInputBatchOrderActionField(f){}

    InputBatchOrderActionField& operator=(const CThostFtdcInputBatchOrderActionField& f) {
        CThostFtdcInputBatchOrderActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct BatchOrderActionField: CThostFtdcBatchOrderActionField {

    BatchOrderActionField() {
        std::memset(this, 0, sizeof(BatchOrderActionField));
    }

    BatchOrderActionField(const CThostFtdcBatchOrderActionField& f): CThostFtdcBatchOrderActionField(f){}

    BatchOrderActionField& operator=(const CThostFtdcBatchOrderActionField& f) {
        CThostFtdcBatchOrderActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setActionDate(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionDate);
        this->ActionDate[v.size()] = '\0';
    }
    const char* getActionDate() {
        return this->ActionDate;
    }

    void setActionTime(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionTime);
        this->ActionTime[v.size()] = '\0';
    }
    const char* getActionTime() {
        return this->ActionTime;
    }

    void setTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->TraderID);
        this->TraderID[v.size()] = '\0';
    }
    const char* getTraderID() {
        return this->TraderID;
    }

    void setActionLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionLocalID);
        this->ActionLocalID[v.size()] = '\0';
    }
    const char* getActionLocalID() {
        return this->ActionLocalID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setStatusMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->StatusMsg);
        this->StatusMsg[v.size()] = '\0';
    }
    const char* getStatusMsg() {
        return this->StatusMsg;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct CombInstrumentGuardField: CThostFtdcCombInstrumentGuardField {

    CombInstrumentGuardField() {
        std::memset(this, 0, sizeof(CombInstrumentGuardField));
    }

    CombInstrumentGuardField(const CThostFtdcCombInstrumentGuardField& f): CThostFtdcCombInstrumentGuardField(f){}

    CombInstrumentGuardField& operator=(const CThostFtdcCombInstrumentGuardField& f) {
        CThostFtdcCombInstrumentGuardField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
    ///
};

struct QryCombInstrumentGuardField: CThostFtdcQryCombInstrumentGuardField {

    QryCombInstrumentGuardField() {
        std::memset(this, 0, sizeof(QryCombInstrumentGuardField));
    }

    QryCombInstrumentGuardField(const CThostFtdcQryCombInstrumentGuardField& f): CThostFtdcQryCombInstrumentGuardField(f){}

    QryCombInstrumentGuardField& operator=(const CThostFtdcQryCombInstrumentGuardField& f) {
        CThostFtdcQryCombInstrumentGuardField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct InputCombActionField: CThostFtdcInputCombActionField {

    InputCombActionField() {
        std::memset(this, 0, sizeof(InputCombActionField));
    }

    InputCombActionField(const CThostFtdcInputCombActionField& f): CThostFtdcInputCombActionField(f){}

    InputCombActionField& operator=(const CThostFtdcInputCombActionField& f) {
        CThostFtdcInputCombActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setCombActionRef(std::string v) {
        std::copy(v.begin(), v.end(), this->CombActionRef);
        this->CombActionRef[v.size()] = '\0';
    }
    const char* getCombActionRef() {
        return this->CombActionRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct CombActionField: CThostFtdcCombActionField {

    CombActionField() {
        std::memset(this, 0, sizeof(CombActionField));
    }

    CombActionField(const CThostFtdcCombActionField& f): CThostFtdcCombActionField(f){}

    CombActionField& operator=(const CThostFtdcCombActionField& f) {
        CThostFtdcCombActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setCombActionRef(std::string v) {
        std::copy(v.begin(), v.end(), this->CombActionRef);
        this->CombActionRef[v.size()] = '\0';
    }
    const char* getCombActionRef() {
        return this->CombActionRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setActionLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActionLocalID);
        this->ActionLocalID[v.size()] = '\0';
    }
    const char* getActionLocalID() {
        return this->ActionLocalID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setExchangeInstID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeInstID);
        this->ExchangeInstID[v.size()] = '\0';
    }
    const char* getExchangeInstID() {
        return this->ExchangeInstID;
    }

    void setTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->TraderID);
        this->TraderID[v.size()] = '\0';
    }
    const char* getTraderID() {
        return this->TraderID;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setUserProductInfo(std::string v) {
        std::copy(v.begin(), v.end(), this->UserProductInfo);
        this->UserProductInfo[v.size()] = '\0';
    }
    const char* getUserProductInfo() {
        return this->UserProductInfo;
    }

    void setStatusMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->StatusMsg);
        this->StatusMsg[v.size()] = '\0';
    }
    const char* getStatusMsg() {
        return this->StatusMsg;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct QryCombActionField: CThostFtdcQryCombActionField {

    QryCombActionField() {
        std::memset(this, 0, sizeof(QryCombActionField));
    }

    QryCombActionField(const CThostFtdcQryCombActionField& f): CThostFtdcQryCombActionField(f){}

    QryCombActionField& operator=(const CThostFtdcQryCombActionField& f) {
        CThostFtdcQryCombActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }
};

struct ProductExchRateField: CThostFtdcProductExchRateField {

    ProductExchRateField() {
        std::memset(this, 0, sizeof(ProductExchRateField));
    }

    ProductExchRateField(const CThostFtdcProductExchRateField& f): CThostFtdcProductExchRateField(f){}

    ProductExchRateField& operator=(const CThostFtdcProductExchRateField& f) {
        CThostFtdcProductExchRateField::operator=(f);
        return *this;
    }

    void setProductID(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductID);
        this->ProductID[v.size()] = '\0';
    }
    const char* getProductID() {
        return this->ProductID;
    }

    void setQuoteCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->QuoteCurrencyID);
        this->QuoteCurrencyID[v.size()] = '\0';
    }
    const char* getQuoteCurrencyID() {
        return this->QuoteCurrencyID;
    }
};

struct QryProductExchRateField: CThostFtdcQryProductExchRateField {

    QryProductExchRateField() {
        std::memset(this, 0, sizeof(QryProductExchRateField));
    }

    QryProductExchRateField(const CThostFtdcQryProductExchRateField& f): CThostFtdcQryProductExchRateField(f){}

    QryProductExchRateField& operator=(const CThostFtdcQryProductExchRateField& f) {
        CThostFtdcQryProductExchRateField::operator=(f);
        return *this;
    }

    void setProductID(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductID);
        this->ProductID[v.size()] = '\0';
    }
    const char* getProductID() {
        return this->ProductID;
    }
};

struct MMOptionInstrCommRateField: CThostFtdcMMOptionInstrCommRateField {

    MMOptionInstrCommRateField() {
        std::memset(this, 0, sizeof(MMOptionInstrCommRateField));
    }

    MMOptionInstrCommRateField(const CThostFtdcMMOptionInstrCommRateField& f): CThostFtdcMMOptionInstrCommRateField(f){}

    MMOptionInstrCommRateField& operator=(const CThostFtdcMMOptionInstrCommRateField& f) {
        CThostFtdcMMOptionInstrCommRateField::operator=(f);
        return *this;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }
};

struct QryMMOptionInstrCommRateField: CThostFtdcQryMMOptionInstrCommRateField {

    QryMMOptionInstrCommRateField() {
        std::memset(this, 0, sizeof(QryMMOptionInstrCommRateField));
    }

    QryMMOptionInstrCommRateField(const CThostFtdcQryMMOptionInstrCommRateField& f): CThostFtdcQryMMOptionInstrCommRateField(f){}

    QryMMOptionInstrCommRateField& operator=(const CThostFtdcQryMMOptionInstrCommRateField& f) {
        CThostFtdcQryMMOptionInstrCommRateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct MMInstrumentCommissionRateField: CThostFtdcMMInstrumentCommissionRateField {

    MMInstrumentCommissionRateField() {
        std::memset(this, 0, sizeof(MMInstrumentCommissionRateField));
    }

    MMInstrumentCommissionRateField(const CThostFtdcMMInstrumentCommissionRateField& f): CThostFtdcMMInstrumentCommissionRateField(f){}

    MMInstrumentCommissionRateField& operator=(const CThostFtdcMMInstrumentCommissionRateField& f) {
        CThostFtdcMMInstrumentCommissionRateField::operator=(f);
        return *this;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }
};

struct QryMMInstrumentCommissionRateField: CThostFtdcQryMMInstrumentCommissionRateField {

    QryMMInstrumentCommissionRateField() {
        std::memset(this, 0, sizeof(QryMMInstrumentCommissionRateField));
    }

    QryMMInstrumentCommissionRateField(const CThostFtdcQryMMInstrumentCommissionRateField& f): CThostFtdcQryMMInstrumentCommissionRateField(f){}

    QryMMInstrumentCommissionRateField& operator=(const CThostFtdcQryMMInstrumentCommissionRateField& f) {
        CThostFtdcQryMMInstrumentCommissionRateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct InstrumentOrderCommRateField: CThostFtdcInstrumentOrderCommRateField {

    InstrumentOrderCommRateField() {
        std::memset(this, 0, sizeof(InstrumentOrderCommRateField));
    }

    InstrumentOrderCommRateField(const CThostFtdcInstrumentOrderCommRateField& f): CThostFtdcInstrumentOrderCommRateField(f){}

    InstrumentOrderCommRateField& operator=(const CThostFtdcInstrumentOrderCommRateField& f) {
        CThostFtdcInstrumentOrderCommRateField::operator=(f);
        return *this;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }
};

struct QryInstrumentOrderCommRateField: CThostFtdcQryInstrumentOrderCommRateField {

    QryInstrumentOrderCommRateField() {
        std::memset(this, 0, sizeof(QryInstrumentOrderCommRateField));
    }

    QryInstrumentOrderCommRateField(const CThostFtdcQryInstrumentOrderCommRateField& f): CThostFtdcQryInstrumentOrderCommRateField(f){}

    QryInstrumentOrderCommRateField& operator=(const CThostFtdcQryInstrumentOrderCommRateField& f) {
        CThostFtdcQryInstrumentOrderCommRateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct InstrumentStatusField: CThostFtdcInstrumentStatusField {

    InstrumentStatusField() {
        std::memset(this, 0, sizeof(InstrumentStatusField));
    }

    InstrumentStatusField(const CThostFtdcInstrumentStatusField& f): CThostFtdcInstrumentStatusField(f){}

    InstrumentStatusField& operator=(const CThostFtdcInstrumentStatusField& f) {
        CThostFtdcInstrumentStatusField::operator=(f);
        return *this;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setExchangeInstID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeInstID);
        this->ExchangeInstID[v.size()] = '\0';
    }
    const char* getExchangeInstID() {
        return this->ExchangeInstID;
    }

    void setSettlementGroupID(std::string v) {
        std::copy(v.begin(), v.end(), this->SettlementGroupID);
        this->SettlementGroupID[v.size()] = '\0';
    }
    const char* getSettlementGroupID() {
        return this->SettlementGroupID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setEnterTime(std::string v) {
        std::copy(v.begin(), v.end(), this->EnterTime);
        this->EnterTime[v.size()] = '\0';
    }
    const char* getEnterTime() {
        return this->EnterTime;
    }
};

struct QryTransferBankField: CThostFtdcQryTransferBankField {

    QryTransferBankField() {
        std::memset(this, 0, sizeof(QryTransferBankField));
    }

    QryTransferBankField(const CThostFtdcQryTransferBankField& f): CThostFtdcQryTransferBankField(f){}

    QryTransferBankField& operator=(const CThostFtdcQryTransferBankField& f) {
        CThostFtdcQryTransferBankField::operator=(f);
        return *this;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBrchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBrchID);
        this->BankBrchID[v.size()] = '\0';
    }
    const char* getBankBrchID() {
        return this->BankBrchID;
    }
};

struct TransferBankField: CThostFtdcTransferBankField {

    TransferBankField() {
        std::memset(this, 0, sizeof(TransferBankField));
    }

    TransferBankField(const CThostFtdcTransferBankField& f): CThostFtdcTransferBankField(f){}

    TransferBankField& operator=(const CThostFtdcTransferBankField& f) {
        CThostFtdcTransferBankField::operator=(f);
        return *this;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBrchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBrchID);
        this->BankBrchID[v.size()] = '\0';
    }
    const char* getBankBrchID() {
        return this->BankBrchID;
    }

    void setBankName(std::string v) {
        std::copy(v.begin(), v.end(), this->BankName);
        this->BankName[v.size()] = '\0';
    }
    const char* getBankName() {
        return this->BankName;
    }
};

struct QryInvestorPositionDetailField: CThostFtdcQryInvestorPositionDetailField {

    QryInvestorPositionDetailField() {
        std::memset(this, 0, sizeof(QryInvestorPositionDetailField));
    }

    QryInvestorPositionDetailField(const CThostFtdcQryInvestorPositionDetailField& f): CThostFtdcQryInvestorPositionDetailField(f){}

    QryInvestorPositionDetailField& operator=(const CThostFtdcQryInvestorPositionDetailField& f) {
        CThostFtdcQryInvestorPositionDetailField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct InvestorPositionDetailField: CThostFtdcInvestorPositionDetailField {

    InvestorPositionDetailField() {
        std::memset(this, 0, sizeof(InvestorPositionDetailField));
    }

    InvestorPositionDetailField(const CThostFtdcInvestorPositionDetailField& f): CThostFtdcInvestorPositionDetailField(f){}

    InvestorPositionDetailField& operator=(const CThostFtdcInvestorPositionDetailField& f) {
        CThostFtdcInvestorPositionDetailField::operator=(f);
        return *this;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setOpenDate(std::string v) {
        std::copy(v.begin(), v.end(), this->OpenDate);
        this->OpenDate[v.size()] = '\0';
    }
    const char* getOpenDate() {
        return this->OpenDate;
    }

    void setTradeID(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeID);
        this->TradeID[v.size()] = '\0';
    }
    const char* getTradeID() {
        return this->TradeID;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setCombInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->CombInstrumentID);
        this->CombInstrumentID[v.size()] = '\0';
    }
    const char* getCombInstrumentID() {
        return this->CombInstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }
};

struct QryNoticeField: CThostFtdcQryNoticeField {

    QryNoticeField() {
        std::memset(this, 0, sizeof(QryNoticeField));
    }

    QryNoticeField(const CThostFtdcQryNoticeField& f): CThostFtdcQryNoticeField(f){}

    QryNoticeField& operator=(const CThostFtdcQryNoticeField& f) {
        CThostFtdcQryNoticeField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }
};

struct NoticeField: CThostFtdcNoticeField {

    NoticeField() {
        std::memset(this, 0, sizeof(NoticeField));
    }

    NoticeField(const CThostFtdcNoticeField& f): CThostFtdcNoticeField(f){}

    NoticeField& operator=(const CThostFtdcNoticeField& f) {
        CThostFtdcNoticeField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setContent(std::string v) {
        std::copy(v.begin(), v.end(), this->Content);
        this->Content[v.size()] = '\0';
    }
    const char* getContent() {
        return this->Content;
    }

    void setSequenceLabel(std::string v) {
        std::copy(v.begin(), v.end(), this->SequenceLabel);
        this->SequenceLabel[v.size()] = '\0';
    }
    const char* getSequenceLabel() {
        return this->SequenceLabel;
    }
};

struct QrySettlementInfoConfirmField: CThostFtdcQrySettlementInfoConfirmField {

    QrySettlementInfoConfirmField() {
        std::memset(this, 0, sizeof(QrySettlementInfoConfirmField));
    }

    QrySettlementInfoConfirmField(const CThostFtdcQrySettlementInfoConfirmField& f): CThostFtdcQrySettlementInfoConfirmField(f){}

    QrySettlementInfoConfirmField& operator=(const CThostFtdcQrySettlementInfoConfirmField& f) {
        CThostFtdcQrySettlementInfoConfirmField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }
};

struct TradingAccountPasswordUpdateField: CThostFtdcTradingAccountPasswordUpdateField {

    TradingAccountPasswordUpdateField() {
        std::memset(this, 0, sizeof(TradingAccountPasswordUpdateField));
    }

    TradingAccountPasswordUpdateField(const CThostFtdcTradingAccountPasswordUpdateField& f): CThostFtdcTradingAccountPasswordUpdateField(f){}

    TradingAccountPasswordUpdateField& operator=(const CThostFtdcTradingAccountPasswordUpdateField& f) {
        CThostFtdcTradingAccountPasswordUpdateField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setOldPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->OldPassword);
        this->OldPassword[v.size()] = '\0';
    }
    const char* getOldPassword() {
        return this->OldPassword;
    }

    void setNewPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->NewPassword);
        this->NewPassword[v.size()] = '\0';
    }
    const char* getNewPassword() {
        return this->NewPassword;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }
};

struct QryContractBankField: CThostFtdcQryContractBankField {

    QryContractBankField() {
        std::memset(this, 0, sizeof(QryContractBankField));
    }

    QryContractBankField(const CThostFtdcQryContractBankField& f): CThostFtdcQryContractBankField(f){}

    QryContractBankField& operator=(const CThostFtdcQryContractBankField& f) {
        CThostFtdcQryContractBankField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBrchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBrchID);
        this->BankBrchID[v.size()] = '\0';
    }
    const char* getBankBrchID() {
        return this->BankBrchID;
    }
};

struct ContractBankField: CThostFtdcContractBankField {

    ContractBankField() {
        std::memset(this, 0, sizeof(ContractBankField));
    }

    ContractBankField(const CThostFtdcContractBankField& f): CThostFtdcContractBankField(f){}

    ContractBankField& operator=(const CThostFtdcContractBankField& f) {
        CThostFtdcContractBankField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBrchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBrchID);
        this->BankBrchID[v.size()] = '\0';
    }
    const char* getBankBrchID() {
        return this->BankBrchID;
    }

    void setBankName(std::string v) {
        std::copy(v.begin(), v.end(), this->BankName);
        this->BankName[v.size()] = '\0';
    }
    const char* getBankName() {
        return this->BankName;
    }
};

struct InvestorPositionCombineDetailField: CThostFtdcInvestorPositionCombineDetailField {

    InvestorPositionCombineDetailField() {
        std::memset(this, 0, sizeof(InvestorPositionCombineDetailField));
    }

    InvestorPositionCombineDetailField(const CThostFtdcInvestorPositionCombineDetailField& f): CThostFtdcInvestorPositionCombineDetailField(f){}

    InvestorPositionCombineDetailField& operator=(const CThostFtdcInvestorPositionCombineDetailField& f) {
        CThostFtdcInvestorPositionCombineDetailField::operator=(f);
        return *this;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setOpenDate(std::string v) {
        std::copy(v.begin(), v.end(), this->OpenDate);
        this->OpenDate[v.size()] = '\0';
    }
    const char* getOpenDate() {
        return this->OpenDate;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setComTradeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ComTradeID);
        this->ComTradeID[v.size()] = '\0';
    }
    const char* getComTradeID() {
        return this->ComTradeID;
    }

    void setTradeID(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeID);
        this->TradeID[v.size()] = '\0';
    }
    const char* getTradeID() {
        return this->TradeID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setCombInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->CombInstrumentID);
        this->CombInstrumentID[v.size()] = '\0';
    }
    const char* getCombInstrumentID() {
        return this->CombInstrumentID;
    }
};

struct ParkedOrderField: CThostFtdcParkedOrderField {

    ParkedOrderField() {
        std::memset(this, 0, sizeof(ParkedOrderField));
    }

    ParkedOrderField(const CThostFtdcParkedOrderField& f): CThostFtdcParkedOrderField(f){}

    ParkedOrderField& operator=(const CThostFtdcParkedOrderField& f) {
        CThostFtdcParkedOrderField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderRef);
        this->OrderRef[v.size()] = '\0';
    }
    const char* getOrderRef() {
        return this->OrderRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setCombOffsetFlag(std::string v) {
        std::copy(v.begin(), v.end(), this->CombOffsetFlag);
        this->CombOffsetFlag[v.size()] = '\0';
    }
    const char* getCombOffsetFlag() {
        return this->CombOffsetFlag;
    }

    void setCombHedgeFlag(std::string v) {
        std::copy(v.begin(), v.end(), this->CombHedgeFlag);
        this->CombHedgeFlag[v.size()] = '\0';
    }
    const char* getCombHedgeFlag() {
        return this->CombHedgeFlag;
    }

    void setGTDDate(std::string v) {
        std::copy(v.begin(), v.end(), this->GTDDate);
        this->GTDDate[v.size()] = '\0';
    }
    const char* getGTDDate() {
        return this->GTDDate;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setParkedOrderID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParkedOrderID);
        this->ParkedOrderID[v.size()] = '\0';
    }
    const char* getParkedOrderID() {
        return this->ParkedOrderID;
    }

    void setErrorMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->ErrorMsg);
        this->ErrorMsg[v.size()] = '\0';
    }
    const char* getErrorMsg() {
        return this->ErrorMsg;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct ParkedOrderActionField: CThostFtdcParkedOrderActionField {

    ParkedOrderActionField() {
        std::memset(this, 0, sizeof(ParkedOrderActionField));
    }

    ParkedOrderActionField(const CThostFtdcParkedOrderActionField& f): CThostFtdcParkedOrderActionField(f){}

    ParkedOrderActionField& operator=(const CThostFtdcParkedOrderActionField& f) {
        CThostFtdcParkedOrderActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderRef);
        this->OrderRef[v.size()] = '\0';
    }
    const char* getOrderRef() {
        return this->OrderRef;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderSysID);
        this->OrderSysID[v.size()] = '\0';
    }
    const char* getOrderSysID() {
        return this->OrderSysID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setParkedOrderActionID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParkedOrderActionID);
        this->ParkedOrderActionID[v.size()] = '\0';
    }
    const char* getParkedOrderActionID() {
        return this->ParkedOrderActionID;
    }

    void setErrorMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->ErrorMsg);
        this->ErrorMsg[v.size()] = '\0';
    }
    const char* getErrorMsg() {
        return this->ErrorMsg;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct QryParkedOrderField: CThostFtdcQryParkedOrderField {

    QryParkedOrderField() {
        std::memset(this, 0, sizeof(QryParkedOrderField));
    }

    QryParkedOrderField(const CThostFtdcQryParkedOrderField& f): CThostFtdcQryParkedOrderField(f){}

    QryParkedOrderField& operator=(const CThostFtdcQryParkedOrderField& f) {
        CThostFtdcQryParkedOrderField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }
};

struct QryParkedOrderActionField: CThostFtdcQryParkedOrderActionField {

    QryParkedOrderActionField() {
        std::memset(this, 0, sizeof(QryParkedOrderActionField));
    }

    QryParkedOrderActionField(const CThostFtdcQryParkedOrderActionField& f): CThostFtdcQryParkedOrderActionField(f){}

    QryParkedOrderActionField& operator=(const CThostFtdcQryParkedOrderActionField& f) {
        CThostFtdcQryParkedOrderActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }
};

struct RemoveParkedOrderField: CThostFtdcRemoveParkedOrderField {

    RemoveParkedOrderField() {
        std::memset(this, 0, sizeof(RemoveParkedOrderField));
    }

    RemoveParkedOrderField(const CThostFtdcRemoveParkedOrderField& f): CThostFtdcRemoveParkedOrderField(f){}

    RemoveParkedOrderField& operator=(const CThostFtdcRemoveParkedOrderField& f) {
        CThostFtdcRemoveParkedOrderField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setParkedOrderID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParkedOrderID);
        this->ParkedOrderID[v.size()] = '\0';
    }
    const char* getParkedOrderID() {
        return this->ParkedOrderID;
    }
};

struct RemoveParkedOrderActionField: CThostFtdcRemoveParkedOrderActionField {

    RemoveParkedOrderActionField() {
        std::memset(this, 0, sizeof(RemoveParkedOrderActionField));
    }

    RemoveParkedOrderActionField(const CThostFtdcRemoveParkedOrderActionField& f): CThostFtdcRemoveParkedOrderActionField(f){}

    RemoveParkedOrderActionField& operator=(const CThostFtdcRemoveParkedOrderActionField& f) {
        CThostFtdcRemoveParkedOrderActionField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setParkedOrderActionID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParkedOrderActionID);
        this->ParkedOrderActionID[v.size()] = '\0';
    }
    const char* getParkedOrderActionID() {
        return this->ParkedOrderActionID;
    }
};

struct QryInvestorPositionCombineDetailField: CThostFtdcQryInvestorPositionCombineDetailField {

    QryInvestorPositionCombineDetailField() {
        std::memset(this, 0, sizeof(QryInvestorPositionCombineDetailField));
    }

    QryInvestorPositionCombineDetailField(const CThostFtdcQryInvestorPositionCombineDetailField& f): CThostFtdcQryInvestorPositionCombineDetailField(f){}

    QryInvestorPositionCombineDetailField& operator=(const CThostFtdcQryInvestorPositionCombineDetailField& f) {
        CThostFtdcQryInvestorPositionCombineDetailField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setCombInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->CombInstrumentID);
        this->CombInstrumentID[v.size()] = '\0';
    }
    const char* getCombInstrumentID() {
        return this->CombInstrumentID;
    }
};

struct TradingNoticeInfoField: CThostFtdcTradingNoticeInfoField {

    TradingNoticeInfoField() {
        std::memset(this, 0, sizeof(TradingNoticeInfoField));
    }

    TradingNoticeInfoField(const CThostFtdcTradingNoticeInfoField& f): CThostFtdcTradingNoticeInfoField(f){}

    TradingNoticeInfoField& operator=(const CThostFtdcTradingNoticeInfoField& f) {
        CThostFtdcTradingNoticeInfoField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setSendTime(std::string v) {
        std::copy(v.begin(), v.end(), this->SendTime);
        this->SendTime[v.size()] = '\0';
    }
    const char* getSendTime() {
        return this->SendTime;
    }

    void setFieldContent(std::string v) {
        std::copy(v.begin(), v.end(), this->FieldContent);
        this->FieldContent[v.size()] = '\0';
    }
    const char* getFieldContent() {
        return this->FieldContent;
    }
};

struct TradingNoticeField: CThostFtdcTradingNoticeField {

    TradingNoticeField() {
        std::memset(this, 0, sizeof(TradingNoticeField));
    }

    TradingNoticeField(const CThostFtdcTradingNoticeField& f): CThostFtdcTradingNoticeField(f){}

    TradingNoticeField& operator=(const CThostFtdcTradingNoticeField& f) {
        CThostFtdcTradingNoticeField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setSendTime(std::string v) {
        std::copy(v.begin(), v.end(), this->SendTime);
        this->SendTime[v.size()] = '\0';
    }
    const char* getSendTime() {
        return this->SendTime;
    }

    void setFieldContent(std::string v) {
        std::copy(v.begin(), v.end(), this->FieldContent);
        this->FieldContent[v.size()] = '\0';
    }
    const char* getFieldContent() {
        return this->FieldContent;
    }
};

struct QryTradingNoticeField: CThostFtdcQryTradingNoticeField {

    QryTradingNoticeField() {
        std::memset(this, 0, sizeof(QryTradingNoticeField));
    }

    QryTradingNoticeField(const CThostFtdcQryTradingNoticeField& f): CThostFtdcQryTradingNoticeField(f){}

    QryTradingNoticeField& operator=(const CThostFtdcQryTradingNoticeField& f) {
        CThostFtdcQryTradingNoticeField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }
};

struct ErrorConditionalOrderField: CThostFtdcErrorConditionalOrderField {

    ErrorConditionalOrderField() {
        std::memset(this, 0, sizeof(ErrorConditionalOrderField));
    }

    ErrorConditionalOrderField(const CThostFtdcErrorConditionalOrderField& f): CThostFtdcErrorConditionalOrderField(f){}

    ErrorConditionalOrderField& operator=(const CThostFtdcErrorConditionalOrderField& f) {
        CThostFtdcErrorConditionalOrderField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }

    void setOrderRef(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderRef);
        this->OrderRef[v.size()] = '\0';
    }
    const char* getOrderRef() {
        return this->OrderRef;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setCombOffsetFlag(std::string v) {
        std::copy(v.begin(), v.end(), this->CombOffsetFlag);
        this->CombOffsetFlag[v.size()] = '\0';
    }
    const char* getCombOffsetFlag() {
        return this->CombOffsetFlag;
    }

    void setCombHedgeFlag(std::string v) {
        std::copy(v.begin(), v.end(), this->CombHedgeFlag);
        this->CombHedgeFlag[v.size()] = '\0';
    }
    const char* getCombHedgeFlag() {
        return this->CombHedgeFlag;
    }

    void setGTDDate(std::string v) {
        std::copy(v.begin(), v.end(), this->GTDDate);
        this->GTDDate[v.size()] = '\0';
    }
    const char* getGTDDate() {
        return this->GTDDate;
    }

    void setBusinessUnit(std::string v) {
        std::copy(v.begin(), v.end(), this->BusinessUnit);
        this->BusinessUnit[v.size()] = '\0';
    }
    const char* getBusinessUnit() {
        return this->BusinessUnit;
    }

    void setOrderLocalID(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderLocalID);
        this->OrderLocalID[v.size()] = '\0';
    }
    const char* getOrderLocalID() {
        return this->OrderLocalID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setClientID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClientID);
        this->ClientID[v.size()] = '\0';
    }
    const char* getClientID() {
        return this->ClientID;
    }

    void setExchangeInstID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeInstID);
        this->ExchangeInstID[v.size()] = '\0';
    }
    const char* getExchangeInstID() {
        return this->ExchangeInstID;
    }

    void setTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->TraderID);
        this->TraderID[v.size()] = '\0';
    }
    const char* getTraderID() {
        return this->TraderID;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->OrderSysID);
        this->OrderSysID[v.size()] = '\0';
    }
    const char* getOrderSysID() {
        return this->OrderSysID;
    }

    void setInsertDate(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertDate);
        this->InsertDate[v.size()] = '\0';
    }
    const char* getInsertDate() {
        return this->InsertDate;
    }

    void setInsertTime(std::string v) {
        std::copy(v.begin(), v.end(), this->InsertTime);
        this->InsertTime[v.size()] = '\0';
    }
    const char* getInsertTime() {
        return this->InsertTime;
    }

    void setActiveTime(std::string v) {
        std::copy(v.begin(), v.end(), this->ActiveTime);
        this->ActiveTime[v.size()] = '\0';
    }
    const char* getActiveTime() {
        return this->ActiveTime;
    }

    void setSuspendTime(std::string v) {
        std::copy(v.begin(), v.end(), this->SuspendTime);
        this->SuspendTime[v.size()] = '\0';
    }
    const char* getSuspendTime() {
        return this->SuspendTime;
    }

    void setUpdateTime(std::string v) {
        std::copy(v.begin(), v.end(), this->UpdateTime);
        this->UpdateTime[v.size()] = '\0';
    }
    const char* getUpdateTime() {
        return this->UpdateTime;
    }

    void setCancelTime(std::string v) {
        std::copy(v.begin(), v.end(), this->CancelTime);
        this->CancelTime[v.size()] = '\0';
    }
    const char* getCancelTime() {
        return this->CancelTime;
    }

    void setActiveTraderID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActiveTraderID);
        this->ActiveTraderID[v.size()] = '\0';
    }
    const char* getActiveTraderID() {
        return this->ActiveTraderID;
    }

    void setClearingPartID(std::string v) {
        std::copy(v.begin(), v.end(), this->ClearingPartID);
        this->ClearingPartID[v.size()] = '\0';
    }
    const char* getClearingPartID() {
        return this->ClearingPartID;
    }

    void setUserProductInfo(std::string v) {
        std::copy(v.begin(), v.end(), this->UserProductInfo);
        this->UserProductInfo[v.size()] = '\0';
    }
    const char* getUserProductInfo() {
        return this->UserProductInfo;
    }

    void setStatusMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->StatusMsg);
        this->StatusMsg[v.size()] = '\0';
    }
    const char* getStatusMsg() {
        return this->StatusMsg;
    }

    void setActiveUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->ActiveUserID);
        this->ActiveUserID[v.size()] = '\0';
    }
    const char* getActiveUserID() {
        return this->ActiveUserID;
    }

    void setRelativeOrderSysID(std::string v) {
        std::copy(v.begin(), v.end(), this->RelativeOrderSysID);
        this->RelativeOrderSysID[v.size()] = '\0';
    }
    const char* getRelativeOrderSysID() {
        return this->RelativeOrderSysID;
    }

    void setErrorMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->ErrorMsg);
        this->ErrorMsg[v.size()] = '\0';
    }
    const char* getErrorMsg() {
        return this->ErrorMsg;
    }

    void setBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BranchID);
        this->BranchID[v.size()] = '\0';
    }
    const char* getBranchID() {
        return this->BranchID;
    }

    void setInvestUnitID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestUnitID);
        this->InvestUnitID[v.size()] = '\0';
    }
    const char* getInvestUnitID() {
        return this->InvestUnitID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setIPAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->IPAddress);
        this->IPAddress[v.size()] = '\0';
    }
    const char* getIPAddress() {
        return this->IPAddress;
    }

    void setMacAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->MacAddress);
        this->MacAddress[v.size()] = '\0';
    }
    const char* getMacAddress() {
        return this->MacAddress;
    }
};

struct QryBrokerTradingParamsField: CThostFtdcQryBrokerTradingParamsField {

    QryBrokerTradingParamsField() {
        std::memset(this, 0, sizeof(QryBrokerTradingParamsField));
    }

    QryBrokerTradingParamsField(const CThostFtdcQryBrokerTradingParamsField& f): CThostFtdcQryBrokerTradingParamsField(f){}

    QryBrokerTradingParamsField& operator=(const CThostFtdcQryBrokerTradingParamsField& f) {
        CThostFtdcQryBrokerTradingParamsField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }
};

struct BrokerTradingParamsField: CThostFtdcBrokerTradingParamsField {

    BrokerTradingParamsField() {
        std::memset(this, 0, sizeof(BrokerTradingParamsField));
    }

    BrokerTradingParamsField(const CThostFtdcBrokerTradingParamsField& f): CThostFtdcBrokerTradingParamsField(f){}

    BrokerTradingParamsField& operator=(const CThostFtdcBrokerTradingParamsField& f) {
        CThostFtdcBrokerTradingParamsField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }
};

struct QryBrokerTradingAlgosField: CThostFtdcQryBrokerTradingAlgosField {

    QryBrokerTradingAlgosField() {
        std::memset(this, 0, sizeof(QryBrokerTradingAlgosField));
    }

    QryBrokerTradingAlgosField(const CThostFtdcQryBrokerTradingAlgosField& f): CThostFtdcQryBrokerTradingAlgosField(f){}

    QryBrokerTradingAlgosField& operator=(const CThostFtdcQryBrokerTradingAlgosField& f) {
        CThostFtdcQryBrokerTradingAlgosField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct BrokerTradingAlgosField: CThostFtdcBrokerTradingAlgosField {

    BrokerTradingAlgosField() {
        std::memset(this, 0, sizeof(BrokerTradingAlgosField));
    }

    BrokerTradingAlgosField(const CThostFtdcBrokerTradingAlgosField& f): CThostFtdcBrokerTradingAlgosField(f){}

    BrokerTradingAlgosField& operator=(const CThostFtdcBrokerTradingAlgosField& f) {
        CThostFtdcBrokerTradingAlgosField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct CFMMCTradingAccountKeyField: CThostFtdcCFMMCTradingAccountKeyField {

    CFMMCTradingAccountKeyField() {
        std::memset(this, 0, sizeof(CFMMCTradingAccountKeyField));
    }

    CFMMCTradingAccountKeyField(const CThostFtdcCFMMCTradingAccountKeyField& f): CThostFtdcCFMMCTradingAccountKeyField(f){}

    CFMMCTradingAccountKeyField& operator=(const CThostFtdcCFMMCTradingAccountKeyField& f) {
        CThostFtdcCFMMCTradingAccountKeyField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setCurrentKey(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrentKey);
        this->CurrentKey[v.size()] = '\0';
    }
    const char* getCurrentKey() {
        return this->CurrentKey;
    }
};

struct QryCFMMCTradingAccountKeyField: CThostFtdcQryCFMMCTradingAccountKeyField {

    QryCFMMCTradingAccountKeyField() {
        std::memset(this, 0, sizeof(QryCFMMCTradingAccountKeyField));
    }

    QryCFMMCTradingAccountKeyField(const CThostFtdcQryCFMMCTradingAccountKeyField& f): CThostFtdcQryCFMMCTradingAccountKeyField(f){}

    QryCFMMCTradingAccountKeyField& operator=(const CThostFtdcQryCFMMCTradingAccountKeyField& f) {
        CThostFtdcQryCFMMCTradingAccountKeyField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }
};

struct EWarrantOffsetField: CThostFtdcEWarrantOffsetField {

    EWarrantOffsetField() {
        std::memset(this, 0, sizeof(EWarrantOffsetField));
    }

    EWarrantOffsetField(const CThostFtdcEWarrantOffsetField& f): CThostFtdcEWarrantOffsetField(f){}

    EWarrantOffsetField& operator=(const CThostFtdcEWarrantOffsetField& f) {
        CThostFtdcEWarrantOffsetField::operator=(f);
        return *this;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct QryEWarrantOffsetField: CThostFtdcQryEWarrantOffsetField {

    QryEWarrantOffsetField() {
        std::memset(this, 0, sizeof(QryEWarrantOffsetField));
    }

    QryEWarrantOffsetField(const CThostFtdcQryEWarrantOffsetField& f): CThostFtdcQryEWarrantOffsetField(f){}

    QryEWarrantOffsetField& operator=(const CThostFtdcQryEWarrantOffsetField& f) {
        CThostFtdcQryEWarrantOffsetField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setInstrumentID(std::string v) {
        std::copy(v.begin(), v.end(), this->InstrumentID);
        this->InstrumentID[v.size()] = '\0';
    }
    const char* getInstrumentID() {
        return this->InstrumentID;
    }
};

struct QryInvestorProductGroupMarginField: CThostFtdcQryInvestorProductGroupMarginField {

    QryInvestorProductGroupMarginField() {
        std::memset(this, 0, sizeof(QryInvestorProductGroupMarginField));
    }

    QryInvestorProductGroupMarginField(const CThostFtdcQryInvestorProductGroupMarginField& f): CThostFtdcQryInvestorProductGroupMarginField(f){}

    QryInvestorProductGroupMarginField& operator=(const CThostFtdcQryInvestorProductGroupMarginField& f) {
        CThostFtdcQryInvestorProductGroupMarginField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setProductGroupID(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductGroupID);
        this->ProductGroupID[v.size()] = '\0';
    }
    const char* getProductGroupID() {
        return this->ProductGroupID;
    }
};

struct InvestorProductGroupMarginField: CThostFtdcInvestorProductGroupMarginField {

    InvestorProductGroupMarginField() {
        std::memset(this, 0, sizeof(InvestorProductGroupMarginField));
    }

    InvestorProductGroupMarginField(const CThostFtdcInvestorProductGroupMarginField& f): CThostFtdcInvestorProductGroupMarginField(f){}

    InvestorProductGroupMarginField& operator=(const CThostFtdcInvestorProductGroupMarginField& f) {
        CThostFtdcInvestorProductGroupMarginField::operator=(f);
        return *this;
    }

    void setProductGroupID(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductGroupID);
        this->ProductGroupID[v.size()] = '\0';
    }
    const char* getProductGroupID() {
        return this->ProductGroupID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }
};

struct QueryCFMMCTradingAccountTokenField: CThostFtdcQueryCFMMCTradingAccountTokenField {

    QueryCFMMCTradingAccountTokenField() {
        std::memset(this, 0, sizeof(QueryCFMMCTradingAccountTokenField));
    }

    QueryCFMMCTradingAccountTokenField(const CThostFtdcQueryCFMMCTradingAccountTokenField& f): CThostFtdcQueryCFMMCTradingAccountTokenField(f){}

    QueryCFMMCTradingAccountTokenField& operator=(const CThostFtdcQueryCFMMCTradingAccountTokenField& f) {
        CThostFtdcQueryCFMMCTradingAccountTokenField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }
};

struct CFMMCTradingAccountTokenField: CThostFtdcCFMMCTradingAccountTokenField {

    CFMMCTradingAccountTokenField() {
        std::memset(this, 0, sizeof(CFMMCTradingAccountTokenField));
    }

    CFMMCTradingAccountTokenField(const CThostFtdcCFMMCTradingAccountTokenField& f): CThostFtdcCFMMCTradingAccountTokenField(f){}

    CFMMCTradingAccountTokenField& operator=(const CThostFtdcCFMMCTradingAccountTokenField& f) {
        CThostFtdcCFMMCTradingAccountTokenField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setParticipantID(std::string v) {
        std::copy(v.begin(), v.end(), this->ParticipantID);
        this->ParticipantID[v.size()] = '\0';
    }
    const char* getParticipantID() {
        return this->ParticipantID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setToken(std::string v) {
        std::copy(v.begin(), v.end(), this->Token);
        this->Token[v.size()] = '\0';
    }
    const char* getToken() {
        return this->Token;
    }
};

struct QryProductGroupField: CThostFtdcQryProductGroupField {

    QryProductGroupField() {
        std::memset(this, 0, sizeof(QryProductGroupField));
    }

    QryProductGroupField(const CThostFtdcQryProductGroupField& f): CThostFtdcQryProductGroupField(f){}

    QryProductGroupField& operator=(const CThostFtdcQryProductGroupField& f) {
        CThostFtdcQryProductGroupField::operator=(f);
        return *this;
    }

    void setProductID(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductID);
        this->ProductID[v.size()] = '\0';
    }
    const char* getProductID() {
        return this->ProductID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }
};

struct ProductGroupField: CThostFtdcProductGroupField {

    ProductGroupField() {
        std::memset(this, 0, sizeof(ProductGroupField));
    }

    ProductGroupField(const CThostFtdcProductGroupField& f): CThostFtdcProductGroupField(f){}

    ProductGroupField& operator=(const CThostFtdcProductGroupField& f) {
        CThostFtdcProductGroupField::operator=(f);
        return *this;
    }

    void setProductID(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductID);
        this->ProductID[v.size()] = '\0';
    }
    const char* getProductID() {
        return this->ProductID;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setProductGroupID(std::string v) {
        std::copy(v.begin(), v.end(), this->ProductGroupID);
        this->ProductGroupID[v.size()] = '\0';
    }
    const char* getProductGroupID() {
        return this->ProductGroupID;
    }
};

struct BulletinField: CThostFtdcBulletinField {

    BulletinField() {
        std::memset(this, 0, sizeof(BulletinField));
    }

    BulletinField(const CThostFtdcBulletinField& f): CThostFtdcBulletinField(f){}

    BulletinField& operator=(const CThostFtdcBulletinField& f) {
        CThostFtdcBulletinField::operator=(f);
        return *this;
    }

    void setExchangeID(std::string v) {
        std::copy(v.begin(), v.end(), this->ExchangeID);
        this->ExchangeID[v.size()] = '\0';
    }
    const char* getExchangeID() {
        return this->ExchangeID;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setNewsType(std::string v) {
        std::copy(v.begin(), v.end(), this->NewsType);
        this->NewsType[v.size()] = '\0';
    }
    const char* getNewsType() {
        return this->NewsType;
    }

    void setSendTime(std::string v) {
        std::copy(v.begin(), v.end(), this->SendTime);
        this->SendTime[v.size()] = '\0';
    }
    const char* getSendTime() {
        return this->SendTime;
    }

    void setAbstract(std::string v) {
        std::copy(v.begin(), v.end(), this->Abstract);
        this->Abstract[v.size()] = '\0';
    }
    const char* getAbstract() {
        return this->Abstract;
    }

    void setComeFrom(std::string v) {
        std::copy(v.begin(), v.end(), this->ComeFrom);
        this->ComeFrom[v.size()] = '\0';
    }
    const char* getComeFrom() {
        return this->ComeFrom;
    }

    void setContent(std::string v) {
        std::copy(v.begin(), v.end(), this->Content);
        this->Content[v.size()] = '\0';
    }
    const char* getContent() {
        return this->Content;
    }

    void setURLLink(std::string v) {
        std::copy(v.begin(), v.end(), this->URLLink);
        this->URLLink[v.size()] = '\0';
    }
    const char* getURLLink() {
        return this->URLLink;
    }

    void setMarketID(std::string v) {
        std::copy(v.begin(), v.end(), this->MarketID);
        this->MarketID[v.size()] = '\0';
    }
    const char* getMarketID() {
        return this->MarketID;
    }
};

struct ReqTransferField: CThostFtdcReqTransferField {

    ReqTransferField() {
        std::memset(this, 0, sizeof(ReqTransferField));
    }

    ReqTransferField(const CThostFtdcReqTransferField& f): CThostFtdcReqTransferField(f){}

    ReqTransferField& operator=(const CThostFtdcReqTransferField& f) {
        CThostFtdcReqTransferField::operator=(f);
        return *this;
    }

    void setTradeCode(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeCode);
        this->TradeCode[v.size()] = '\0';
    }
    const char* getTradeCode() {
        return this->TradeCode;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBrokerBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerBranchID);
        this->BrokerBranchID[v.size()] = '\0';
    }
    const char* getBrokerBranchID() {
        return this->BrokerBranchID;
    }

    void setTradeDate(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDate);
        this->TradeDate[v.size()] = '\0';
    }
    const char* getTradeDate() {
        return this->TradeDate;
    }

    void setTradeTime(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTime);
        this->TradeTime[v.size()] = '\0';
    }
    const char* getTradeTime() {
        return this->TradeTime;
    }

    void setBankSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSerial);
        this->BankSerial[v.size()] = '\0';
    }
    const char* getBankSerial() {
        return this->BankSerial;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->CustomerName);
        this->CustomerName[v.size()] = '\0';
    }
    const char* getCustomerName() {
        return this->CustomerName;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankAccount);
        this->BankAccount[v.size()] = '\0';
    }
    const char* getBankAccount() {
        return this->BankAccount;
    }

    void setBankPassWord(std::string v) {
        std::copy(v.begin(), v.end(), this->BankPassWord);
        this->BankPassWord[v.size()] = '\0';
    }
    const char* getBankPassWord() {
        return this->BankPassWord;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->Password);
        this->Password[v.size()] = '\0';
    }
    const char* getPassword() {
        return this->Password;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setMessage(std::string v) {
        std::copy(v.begin(), v.end(), this->Message);
        this->Message[v.size()] = '\0';
    }
    const char* getMessage() {
        return this->Message;
    }

    void setDigest(std::string v) {
        std::copy(v.begin(), v.end(), this->Digest);
        this->Digest[v.size()] = '\0';
    }
    const char* getDigest() {
        return this->Digest;
    }

    void setDeviceID(std::string v) {
        std::copy(v.begin(), v.end(), this->DeviceID);
        this->DeviceID[v.size()] = '\0';
    }
    const char* getDeviceID() {
        return this->DeviceID;
    }

    void setBrokerIDByBank(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerIDByBank);
        this->BrokerIDByBank[v.size()] = '\0';
    }
    const char* getBrokerIDByBank() {
        return this->BrokerIDByBank;
    }

    void setBankSecuAcc(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSecuAcc);
        this->BankSecuAcc[v.size()] = '\0';
    }
    const char* getBankSecuAcc() {
        return this->BankSecuAcc;
    }

    void setOperNo(std::string v) {
        std::copy(v.begin(), v.end(), this->OperNo);
        this->OperNo[v.size()] = '\0';
    }
    const char* getOperNo() {
        return this->OperNo;
    }

    void setLongCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->LongCustomerName);
        this->LongCustomerName[v.size()] = '\0';
    }
    const char* getLongCustomerName() {
        return this->LongCustomerName;
    }
};

struct RspTransferField: CThostFtdcRspTransferField {

    RspTransferField() {
        std::memset(this, 0, sizeof(RspTransferField));
    }

    RspTransferField(const CThostFtdcRspTransferField& f): CThostFtdcRspTransferField(f){}

    RspTransferField& operator=(const CThostFtdcRspTransferField& f) {
        CThostFtdcRspTransferField::operator=(f);
        return *this;
    }

    void setTradeCode(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeCode);
        this->TradeCode[v.size()] = '\0';
    }
    const char* getTradeCode() {
        return this->TradeCode;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBrokerBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerBranchID);
        this->BrokerBranchID[v.size()] = '\0';
    }
    const char* getBrokerBranchID() {
        return this->BrokerBranchID;
    }

    void setTradeDate(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDate);
        this->TradeDate[v.size()] = '\0';
    }
    const char* getTradeDate() {
        return this->TradeDate;
    }

    void setTradeTime(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTime);
        this->TradeTime[v.size()] = '\0';
    }
    const char* getTradeTime() {
        return this->TradeTime;
    }

    void setBankSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSerial);
        this->BankSerial[v.size()] = '\0';
    }
    const char* getBankSerial() {
        return this->BankSerial;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->CustomerName);
        this->CustomerName[v.size()] = '\0';
    }
    const char* getCustomerName() {
        return this->CustomerName;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankAccount);
        this->BankAccount[v.size()] = '\0';
    }
    const char* getBankAccount() {
        return this->BankAccount;
    }

    void setBankPassWord(std::string v) {
        std::copy(v.begin(), v.end(), this->BankPassWord);
        this->BankPassWord[v.size()] = '\0';
    }
    const char* getBankPassWord() {
        return this->BankPassWord;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->Password);
        this->Password[v.size()] = '\0';
    }
    const char* getPassword() {
        return this->Password;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setMessage(std::string v) {
        std::copy(v.begin(), v.end(), this->Message);
        this->Message[v.size()] = '\0';
    }
    const char* getMessage() {
        return this->Message;
    }

    void setDigest(std::string v) {
        std::copy(v.begin(), v.end(), this->Digest);
        this->Digest[v.size()] = '\0';
    }
    const char* getDigest() {
        return this->Digest;
    }

    void setDeviceID(std::string v) {
        std::copy(v.begin(), v.end(), this->DeviceID);
        this->DeviceID[v.size()] = '\0';
    }
    const char* getDeviceID() {
        return this->DeviceID;
    }

    void setBrokerIDByBank(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerIDByBank);
        this->BrokerIDByBank[v.size()] = '\0';
    }
    const char* getBrokerIDByBank() {
        return this->BrokerIDByBank;
    }

    void setBankSecuAcc(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSecuAcc);
        this->BankSecuAcc[v.size()] = '\0';
    }
    const char* getBankSecuAcc() {
        return this->BankSecuAcc;
    }

    void setOperNo(std::string v) {
        std::copy(v.begin(), v.end(), this->OperNo);
        this->OperNo[v.size()] = '\0';
    }
    const char* getOperNo() {
        return this->OperNo;
    }

    void setErrorMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->ErrorMsg);
        this->ErrorMsg[v.size()] = '\0';
    }
    const char* getErrorMsg() {
        return this->ErrorMsg;
    }

    void setLongCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->LongCustomerName);
        this->LongCustomerName[v.size()] = '\0';
    }
    const char* getLongCustomerName() {
        return this->LongCustomerName;
    }
};

struct ReqRepealField: CThostFtdcReqRepealField {

    ReqRepealField() {
        std::memset(this, 0, sizeof(ReqRepealField));
    }

    ReqRepealField(const CThostFtdcReqRepealField& f): CThostFtdcReqRepealField(f){}

    ReqRepealField& operator=(const CThostFtdcReqRepealField& f) {
        CThostFtdcReqRepealField::operator=(f);
        return *this;
    }

    void setBankRepealSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankRepealSerial);
        this->BankRepealSerial[v.size()] = '\0';
    }
    const char* getBankRepealSerial() {
        return this->BankRepealSerial;
    }

    void setTradeCode(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeCode);
        this->TradeCode[v.size()] = '\0';
    }
    const char* getTradeCode() {
        return this->TradeCode;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBrokerBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerBranchID);
        this->BrokerBranchID[v.size()] = '\0';
    }
    const char* getBrokerBranchID() {
        return this->BrokerBranchID;
    }

    void setTradeDate(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDate);
        this->TradeDate[v.size()] = '\0';
    }
    const char* getTradeDate() {
        return this->TradeDate;
    }

    void setTradeTime(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTime);
        this->TradeTime[v.size()] = '\0';
    }
    const char* getTradeTime() {
        return this->TradeTime;
    }

    void setBankSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSerial);
        this->BankSerial[v.size()] = '\0';
    }
    const char* getBankSerial() {
        return this->BankSerial;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->CustomerName);
        this->CustomerName[v.size()] = '\0';
    }
    const char* getCustomerName() {
        return this->CustomerName;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankAccount);
        this->BankAccount[v.size()] = '\0';
    }
    const char* getBankAccount() {
        return this->BankAccount;
    }

    void setBankPassWord(std::string v) {
        std::copy(v.begin(), v.end(), this->BankPassWord);
        this->BankPassWord[v.size()] = '\0';
    }
    const char* getBankPassWord() {
        return this->BankPassWord;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->Password);
        this->Password[v.size()] = '\0';
    }
    const char* getPassword() {
        return this->Password;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setMessage(std::string v) {
        std::copy(v.begin(), v.end(), this->Message);
        this->Message[v.size()] = '\0';
    }
    const char* getMessage() {
        return this->Message;
    }

    void setDigest(std::string v) {
        std::copy(v.begin(), v.end(), this->Digest);
        this->Digest[v.size()] = '\0';
    }
    const char* getDigest() {
        return this->Digest;
    }

    void setDeviceID(std::string v) {
        std::copy(v.begin(), v.end(), this->DeviceID);
        this->DeviceID[v.size()] = '\0';
    }
    const char* getDeviceID() {
        return this->DeviceID;
    }

    void setBrokerIDByBank(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerIDByBank);
        this->BrokerIDByBank[v.size()] = '\0';
    }
    const char* getBrokerIDByBank() {
        return this->BrokerIDByBank;
    }

    void setBankSecuAcc(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSecuAcc);
        this->BankSecuAcc[v.size()] = '\0';
    }
    const char* getBankSecuAcc() {
        return this->BankSecuAcc;
    }

    void setOperNo(std::string v) {
        std::copy(v.begin(), v.end(), this->OperNo);
        this->OperNo[v.size()] = '\0';
    }
    const char* getOperNo() {
        return this->OperNo;
    }

    void setLongCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->LongCustomerName);
        this->LongCustomerName[v.size()] = '\0';
    }
    const char* getLongCustomerName() {
        return this->LongCustomerName;
    }
};

struct RspRepealField: CThostFtdcRspRepealField {

    RspRepealField() {
        std::memset(this, 0, sizeof(RspRepealField));
    }

    RspRepealField(const CThostFtdcRspRepealField& f): CThostFtdcRspRepealField(f){}

    RspRepealField& operator=(const CThostFtdcRspRepealField& f) {
        CThostFtdcRspRepealField::operator=(f);
        return *this;
    }

    void setBankRepealSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankRepealSerial);
        this->BankRepealSerial[v.size()] = '\0';
    }
    const char* getBankRepealSerial() {
        return this->BankRepealSerial;
    }

    void setTradeCode(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeCode);
        this->TradeCode[v.size()] = '\0';
    }
    const char* getTradeCode() {
        return this->TradeCode;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBrokerBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerBranchID);
        this->BrokerBranchID[v.size()] = '\0';
    }
    const char* getBrokerBranchID() {
        return this->BrokerBranchID;
    }

    void setTradeDate(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDate);
        this->TradeDate[v.size()] = '\0';
    }
    const char* getTradeDate() {
        return this->TradeDate;
    }

    void setTradeTime(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTime);
        this->TradeTime[v.size()] = '\0';
    }
    const char* getTradeTime() {
        return this->TradeTime;
    }

    void setBankSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSerial);
        this->BankSerial[v.size()] = '\0';
    }
    const char* getBankSerial() {
        return this->BankSerial;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->CustomerName);
        this->CustomerName[v.size()] = '\0';
    }
    const char* getCustomerName() {
        return this->CustomerName;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankAccount);
        this->BankAccount[v.size()] = '\0';
    }
    const char* getBankAccount() {
        return this->BankAccount;
    }

    void setBankPassWord(std::string v) {
        std::copy(v.begin(), v.end(), this->BankPassWord);
        this->BankPassWord[v.size()] = '\0';
    }
    const char* getBankPassWord() {
        return this->BankPassWord;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->Password);
        this->Password[v.size()] = '\0';
    }
    const char* getPassword() {
        return this->Password;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setMessage(std::string v) {
        std::copy(v.begin(), v.end(), this->Message);
        this->Message[v.size()] = '\0';
    }
    const char* getMessage() {
        return this->Message;
    }

    void setDigest(std::string v) {
        std::copy(v.begin(), v.end(), this->Digest);
        this->Digest[v.size()] = '\0';
    }
    const char* getDigest() {
        return this->Digest;
    }

    void setDeviceID(std::string v) {
        std::copy(v.begin(), v.end(), this->DeviceID);
        this->DeviceID[v.size()] = '\0';
    }
    const char* getDeviceID() {
        return this->DeviceID;
    }

    void setBrokerIDByBank(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerIDByBank);
        this->BrokerIDByBank[v.size()] = '\0';
    }
    const char* getBrokerIDByBank() {
        return this->BrokerIDByBank;
    }

    void setBankSecuAcc(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSecuAcc);
        this->BankSecuAcc[v.size()] = '\0';
    }
    const char* getBankSecuAcc() {
        return this->BankSecuAcc;
    }

    void setOperNo(std::string v) {
        std::copy(v.begin(), v.end(), this->OperNo);
        this->OperNo[v.size()] = '\0';
    }
    const char* getOperNo() {
        return this->OperNo;
    }

    void setErrorMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->ErrorMsg);
        this->ErrorMsg[v.size()] = '\0';
    }
    const char* getErrorMsg() {
        return this->ErrorMsg;
    }

    void setLongCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->LongCustomerName);
        this->LongCustomerName[v.size()] = '\0';
    }
    const char* getLongCustomerName() {
        return this->LongCustomerName;
    }
};

struct ReqQueryAccountField: CThostFtdcReqQueryAccountField {

    ReqQueryAccountField() {
        std::memset(this, 0, sizeof(ReqQueryAccountField));
    }

    ReqQueryAccountField(const CThostFtdcReqQueryAccountField& f): CThostFtdcReqQueryAccountField(f){}

    ReqQueryAccountField& operator=(const CThostFtdcReqQueryAccountField& f) {
        CThostFtdcReqQueryAccountField::operator=(f);
        return *this;
    }

    void setTradeCode(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeCode);
        this->TradeCode[v.size()] = '\0';
    }
    const char* getTradeCode() {
        return this->TradeCode;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBrokerBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerBranchID);
        this->BrokerBranchID[v.size()] = '\0';
    }
    const char* getBrokerBranchID() {
        return this->BrokerBranchID;
    }

    void setTradeDate(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDate);
        this->TradeDate[v.size()] = '\0';
    }
    const char* getTradeDate() {
        return this->TradeDate;
    }

    void setTradeTime(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTime);
        this->TradeTime[v.size()] = '\0';
    }
    const char* getTradeTime() {
        return this->TradeTime;
    }

    void setBankSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSerial);
        this->BankSerial[v.size()] = '\0';
    }
    const char* getBankSerial() {
        return this->BankSerial;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->CustomerName);
        this->CustomerName[v.size()] = '\0';
    }
    const char* getCustomerName() {
        return this->CustomerName;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankAccount);
        this->BankAccount[v.size()] = '\0';
    }
    const char* getBankAccount() {
        return this->BankAccount;
    }

    void setBankPassWord(std::string v) {
        std::copy(v.begin(), v.end(), this->BankPassWord);
        this->BankPassWord[v.size()] = '\0';
    }
    const char* getBankPassWord() {
        return this->BankPassWord;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->Password);
        this->Password[v.size()] = '\0';
    }
    const char* getPassword() {
        return this->Password;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setDigest(std::string v) {
        std::copy(v.begin(), v.end(), this->Digest);
        this->Digest[v.size()] = '\0';
    }
    const char* getDigest() {
        return this->Digest;
    }

    void setDeviceID(std::string v) {
        std::copy(v.begin(), v.end(), this->DeviceID);
        this->DeviceID[v.size()] = '\0';
    }
    const char* getDeviceID() {
        return this->DeviceID;
    }

    void setBrokerIDByBank(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerIDByBank);
        this->BrokerIDByBank[v.size()] = '\0';
    }
    const char* getBrokerIDByBank() {
        return this->BrokerIDByBank;
    }

    void setBankSecuAcc(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSecuAcc);
        this->BankSecuAcc[v.size()] = '\0';
    }
    const char* getBankSecuAcc() {
        return this->BankSecuAcc;
    }

    void setOperNo(std::string v) {
        std::copy(v.begin(), v.end(), this->OperNo);
        this->OperNo[v.size()] = '\0';
    }
    const char* getOperNo() {
        return this->OperNo;
    }

    void setLongCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->LongCustomerName);
        this->LongCustomerName[v.size()] = '\0';
    }
    const char* getLongCustomerName() {
        return this->LongCustomerName;
    }
};

struct NotifyQueryAccountField: CThostFtdcNotifyQueryAccountField {

    NotifyQueryAccountField() {
        std::memset(this, 0, sizeof(NotifyQueryAccountField));
    }

    NotifyQueryAccountField(const CThostFtdcNotifyQueryAccountField& f): CThostFtdcNotifyQueryAccountField(f){}

    NotifyQueryAccountField& operator=(const CThostFtdcNotifyQueryAccountField& f) {
        CThostFtdcNotifyQueryAccountField::operator=(f);
        return *this;
    }

    void setTradeCode(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeCode);
        this->TradeCode[v.size()] = '\0';
    }
    const char* getTradeCode() {
        return this->TradeCode;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBrokerBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerBranchID);
        this->BrokerBranchID[v.size()] = '\0';
    }
    const char* getBrokerBranchID() {
        return this->BrokerBranchID;
    }

    void setTradeDate(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDate);
        this->TradeDate[v.size()] = '\0';
    }
    const char* getTradeDate() {
        return this->TradeDate;
    }

    void setTradeTime(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTime);
        this->TradeTime[v.size()] = '\0';
    }
    const char* getTradeTime() {
        return this->TradeTime;
    }

    void setBankSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSerial);
        this->BankSerial[v.size()] = '\0';
    }
    const char* getBankSerial() {
        return this->BankSerial;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->CustomerName);
        this->CustomerName[v.size()] = '\0';
    }
    const char* getCustomerName() {
        return this->CustomerName;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankAccount);
        this->BankAccount[v.size()] = '\0';
    }
    const char* getBankAccount() {
        return this->BankAccount;
    }

    void setBankPassWord(std::string v) {
        std::copy(v.begin(), v.end(), this->BankPassWord);
        this->BankPassWord[v.size()] = '\0';
    }
    const char* getBankPassWord() {
        return this->BankPassWord;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->Password);
        this->Password[v.size()] = '\0';
    }
    const char* getPassword() {
        return this->Password;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setDigest(std::string v) {
        std::copy(v.begin(), v.end(), this->Digest);
        this->Digest[v.size()] = '\0';
    }
    const char* getDigest() {
        return this->Digest;
    }

    void setDeviceID(std::string v) {
        std::copy(v.begin(), v.end(), this->DeviceID);
        this->DeviceID[v.size()] = '\0';
    }
    const char* getDeviceID() {
        return this->DeviceID;
    }

    void setBrokerIDByBank(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerIDByBank);
        this->BrokerIDByBank[v.size()] = '\0';
    }
    const char* getBrokerIDByBank() {
        return this->BrokerIDByBank;
    }

    void setBankSecuAcc(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSecuAcc);
        this->BankSecuAcc[v.size()] = '\0';
    }
    const char* getBankSecuAcc() {
        return this->BankSecuAcc;
    }

    void setOperNo(std::string v) {
        std::copy(v.begin(), v.end(), this->OperNo);
        this->OperNo[v.size()] = '\0';
    }
    const char* getOperNo() {
        return this->OperNo;
    }

    void setErrorMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->ErrorMsg);
        this->ErrorMsg[v.size()] = '\0';
    }
    const char* getErrorMsg() {
        return this->ErrorMsg;
    }

    void setLongCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->LongCustomerName);
        this->LongCustomerName[v.size()] = '\0';
    }
    const char* getLongCustomerName() {
        return this->LongCustomerName;
    }
};

struct TransferSerialField: CThostFtdcTransferSerialField {

    TransferSerialField() {
        std::memset(this, 0, sizeof(TransferSerialField));
    }

    TransferSerialField(const CThostFtdcTransferSerialField& f): CThostFtdcTransferSerialField(f){}

    TransferSerialField& operator=(const CThostFtdcTransferSerialField& f) {
        CThostFtdcTransferSerialField::operator=(f);
        return *this;
    }

    void setTradeDate(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDate);
        this->TradeDate[v.size()] = '\0';
    }
    const char* getTradeDate() {
        return this->TradeDate;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setTradeTime(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTime);
        this->TradeTime[v.size()] = '\0';
    }
    const char* getTradeTime() {
        return this->TradeTime;
    }

    void setTradeCode(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeCode);
        this->TradeCode[v.size()] = '\0';
    }
    const char* getTradeCode() {
        return this->TradeCode;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankAccount);
        this->BankAccount[v.size()] = '\0';
    }
    const char* getBankAccount() {
        return this->BankAccount;
    }

    void setBankSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSerial);
        this->BankSerial[v.size()] = '\0';
    }
    const char* getBankSerial() {
        return this->BankSerial;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBrokerBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerBranchID);
        this->BrokerBranchID[v.size()] = '\0';
    }
    const char* getBrokerBranchID() {
        return this->BrokerBranchID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setInvestorID(std::string v) {
        std::copy(v.begin(), v.end(), this->InvestorID);
        this->InvestorID[v.size()] = '\0';
    }
    const char* getInvestorID() {
        return this->InvestorID;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setOperatorCode(std::string v) {
        std::copy(v.begin(), v.end(), this->OperatorCode);
        this->OperatorCode[v.size()] = '\0';
    }
    const char* getOperatorCode() {
        return this->OperatorCode;
    }

    void setBankNewAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankNewAccount);
        this->BankNewAccount[v.size()] = '\0';
    }
    const char* getBankNewAccount() {
        return this->BankNewAccount;
    }

    void setErrorMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->ErrorMsg);
        this->ErrorMsg[v.size()] = '\0';
    }
    const char* getErrorMsg() {
        return this->ErrorMsg;
    }
};

struct QryTransferSerialField: CThostFtdcQryTransferSerialField {

    QryTransferSerialField() {
        std::memset(this, 0, sizeof(QryTransferSerialField));
    }

    QryTransferSerialField(const CThostFtdcQryTransferSerialField& f): CThostFtdcQryTransferSerialField(f){}

    QryTransferSerialField& operator=(const CThostFtdcQryTransferSerialField& f) {
        CThostFtdcQryTransferSerialField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }
};

struct QryAccountregisterField: CThostFtdcQryAccountregisterField {

    QryAccountregisterField() {
        std::memset(this, 0, sizeof(QryAccountregisterField));
    }

    QryAccountregisterField(const CThostFtdcQryAccountregisterField& f): CThostFtdcQryAccountregisterField(f){}

    QryAccountregisterField& operator=(const CThostFtdcQryAccountregisterField& f) {
        CThostFtdcQryAccountregisterField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }
};

struct AccountregisterField: CThostFtdcAccountregisterField {

    AccountregisterField() {
        std::memset(this, 0, sizeof(AccountregisterField));
    }

    AccountregisterField(const CThostFtdcAccountregisterField& f): CThostFtdcAccountregisterField(f){}

    AccountregisterField& operator=(const CThostFtdcAccountregisterField& f) {
        CThostFtdcAccountregisterField::operator=(f);
        return *this;
    }

    void setTradeDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDay);
        this->TradeDay[v.size()] = '\0';
    }
    const char* getTradeDay() {
        return this->TradeDay;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankAccount);
        this->BankAccount[v.size()] = '\0';
    }
    const char* getBankAccount() {
        return this->BankAccount;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBrokerBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerBranchID);
        this->BrokerBranchID[v.size()] = '\0';
    }
    const char* getBrokerBranchID() {
        return this->BrokerBranchID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->CustomerName);
        this->CustomerName[v.size()] = '\0';
    }
    const char* getCustomerName() {
        return this->CustomerName;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setRegDate(std::string v) {
        std::copy(v.begin(), v.end(), this->RegDate);
        this->RegDate[v.size()] = '\0';
    }
    const char* getRegDate() {
        return this->RegDate;
    }

    void setOutDate(std::string v) {
        std::copy(v.begin(), v.end(), this->OutDate);
        this->OutDate[v.size()] = '\0';
    }
    const char* getOutDate() {
        return this->OutDate;
    }

    void setLongCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->LongCustomerName);
        this->LongCustomerName[v.size()] = '\0';
    }
    const char* getLongCustomerName() {
        return this->LongCustomerName;
    }
};

struct OpenAccountField: CThostFtdcOpenAccountField {

    OpenAccountField() {
        std::memset(this, 0, sizeof(OpenAccountField));
    }

    OpenAccountField(const CThostFtdcOpenAccountField& f): CThostFtdcOpenAccountField(f){}

    OpenAccountField& operator=(const CThostFtdcOpenAccountField& f) {
        CThostFtdcOpenAccountField::operator=(f);
        return *this;
    }

    void setTradeCode(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeCode);
        this->TradeCode[v.size()] = '\0';
    }
    const char* getTradeCode() {
        return this->TradeCode;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBrokerBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerBranchID);
        this->BrokerBranchID[v.size()] = '\0';
    }
    const char* getBrokerBranchID() {
        return this->BrokerBranchID;
    }

    void setTradeDate(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDate);
        this->TradeDate[v.size()] = '\0';
    }
    const char* getTradeDate() {
        return this->TradeDate;
    }

    void setTradeTime(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTime);
        this->TradeTime[v.size()] = '\0';
    }
    const char* getTradeTime() {
        return this->TradeTime;
    }

    void setBankSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSerial);
        this->BankSerial[v.size()] = '\0';
    }
    const char* getBankSerial() {
        return this->BankSerial;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->CustomerName);
        this->CustomerName[v.size()] = '\0';
    }
    const char* getCustomerName() {
        return this->CustomerName;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setCountryCode(std::string v) {
        std::copy(v.begin(), v.end(), this->CountryCode);
        this->CountryCode[v.size()] = '\0';
    }
    const char* getCountryCode() {
        return this->CountryCode;
    }

    void setAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->Address);
        this->Address[v.size()] = '\0';
    }
    const char* getAddress() {
        return this->Address;
    }

    void setZipCode(std::string v) {
        std::copy(v.begin(), v.end(), this->ZipCode);
        this->ZipCode[v.size()] = '\0';
    }
    const char* getZipCode() {
        return this->ZipCode;
    }

    void setTelephone(std::string v) {
        std::copy(v.begin(), v.end(), this->Telephone);
        this->Telephone[v.size()] = '\0';
    }
    const char* getTelephone() {
        return this->Telephone;
    }

    void setMobilePhone(std::string v) {
        std::copy(v.begin(), v.end(), this->MobilePhone);
        this->MobilePhone[v.size()] = '\0';
    }
    const char* getMobilePhone() {
        return this->MobilePhone;
    }

    void setFax(std::string v) {
        std::copy(v.begin(), v.end(), this->Fax);
        this->Fax[v.size()] = '\0';
    }
    const char* getFax() {
        return this->Fax;
    }

    void setEMail(std::string v) {
        std::copy(v.begin(), v.end(), this->EMail);
        this->EMail[v.size()] = '\0';
    }
    const char* getEMail() {
        return this->EMail;
    }

    void setBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankAccount);
        this->BankAccount[v.size()] = '\0';
    }
    const char* getBankAccount() {
        return this->BankAccount;
    }

    void setBankPassWord(std::string v) {
        std::copy(v.begin(), v.end(), this->BankPassWord);
        this->BankPassWord[v.size()] = '\0';
    }
    const char* getBankPassWord() {
        return this->BankPassWord;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->Password);
        this->Password[v.size()] = '\0';
    }
    const char* getPassword() {
        return this->Password;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setDigest(std::string v) {
        std::copy(v.begin(), v.end(), this->Digest);
        this->Digest[v.size()] = '\0';
    }
    const char* getDigest() {
        return this->Digest;
    }

    void setDeviceID(std::string v) {
        std::copy(v.begin(), v.end(), this->DeviceID);
        this->DeviceID[v.size()] = '\0';
    }
    const char* getDeviceID() {
        return this->DeviceID;
    }

    void setBrokerIDByBank(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerIDByBank);
        this->BrokerIDByBank[v.size()] = '\0';
    }
    const char* getBrokerIDByBank() {
        return this->BrokerIDByBank;
    }

    void setBankSecuAcc(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSecuAcc);
        this->BankSecuAcc[v.size()] = '\0';
    }
    const char* getBankSecuAcc() {
        return this->BankSecuAcc;
    }

    void setOperNo(std::string v) {
        std::copy(v.begin(), v.end(), this->OperNo);
        this->OperNo[v.size()] = '\0';
    }
    const char* getOperNo() {
        return this->OperNo;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setErrorMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->ErrorMsg);
        this->ErrorMsg[v.size()] = '\0';
    }
    const char* getErrorMsg() {
        return this->ErrorMsg;
    }

    void setLongCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->LongCustomerName);
        this->LongCustomerName[v.size()] = '\0';
    }
    const char* getLongCustomerName() {
        return this->LongCustomerName;
    }
};

struct CancelAccountField: CThostFtdcCancelAccountField {

    CancelAccountField() {
        std::memset(this, 0, sizeof(CancelAccountField));
    }

    CancelAccountField(const CThostFtdcCancelAccountField& f): CThostFtdcCancelAccountField(f){}

    CancelAccountField& operator=(const CThostFtdcCancelAccountField& f) {
        CThostFtdcCancelAccountField::operator=(f);
        return *this;
    }

    void setTradeCode(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeCode);
        this->TradeCode[v.size()] = '\0';
    }
    const char* getTradeCode() {
        return this->TradeCode;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBrokerBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerBranchID);
        this->BrokerBranchID[v.size()] = '\0';
    }
    const char* getBrokerBranchID() {
        return this->BrokerBranchID;
    }

    void setTradeDate(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDate);
        this->TradeDate[v.size()] = '\0';
    }
    const char* getTradeDate() {
        return this->TradeDate;
    }

    void setTradeTime(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTime);
        this->TradeTime[v.size()] = '\0';
    }
    const char* getTradeTime() {
        return this->TradeTime;
    }

    void setBankSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSerial);
        this->BankSerial[v.size()] = '\0';
    }
    const char* getBankSerial() {
        return this->BankSerial;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->CustomerName);
        this->CustomerName[v.size()] = '\0';
    }
    const char* getCustomerName() {
        return this->CustomerName;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setCountryCode(std::string v) {
        std::copy(v.begin(), v.end(), this->CountryCode);
        this->CountryCode[v.size()] = '\0';
    }
    const char* getCountryCode() {
        return this->CountryCode;
    }

    void setAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->Address);
        this->Address[v.size()] = '\0';
    }
    const char* getAddress() {
        return this->Address;
    }

    void setZipCode(std::string v) {
        std::copy(v.begin(), v.end(), this->ZipCode);
        this->ZipCode[v.size()] = '\0';
    }
    const char* getZipCode() {
        return this->ZipCode;
    }

    void setTelephone(std::string v) {
        std::copy(v.begin(), v.end(), this->Telephone);
        this->Telephone[v.size()] = '\0';
    }
    const char* getTelephone() {
        return this->Telephone;
    }

    void setMobilePhone(std::string v) {
        std::copy(v.begin(), v.end(), this->MobilePhone);
        this->MobilePhone[v.size()] = '\0';
    }
    const char* getMobilePhone() {
        return this->MobilePhone;
    }

    void setFax(std::string v) {
        std::copy(v.begin(), v.end(), this->Fax);
        this->Fax[v.size()] = '\0';
    }
    const char* getFax() {
        return this->Fax;
    }

    void setEMail(std::string v) {
        std::copy(v.begin(), v.end(), this->EMail);
        this->EMail[v.size()] = '\0';
    }
    const char* getEMail() {
        return this->EMail;
    }

    void setBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankAccount);
        this->BankAccount[v.size()] = '\0';
    }
    const char* getBankAccount() {
        return this->BankAccount;
    }

    void setBankPassWord(std::string v) {
        std::copy(v.begin(), v.end(), this->BankPassWord);
        this->BankPassWord[v.size()] = '\0';
    }
    const char* getBankPassWord() {
        return this->BankPassWord;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->Password);
        this->Password[v.size()] = '\0';
    }
    const char* getPassword() {
        return this->Password;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setDigest(std::string v) {
        std::copy(v.begin(), v.end(), this->Digest);
        this->Digest[v.size()] = '\0';
    }
    const char* getDigest() {
        return this->Digest;
    }

    void setDeviceID(std::string v) {
        std::copy(v.begin(), v.end(), this->DeviceID);
        this->DeviceID[v.size()] = '\0';
    }
    const char* getDeviceID() {
        return this->DeviceID;
    }

    void setBrokerIDByBank(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerIDByBank);
        this->BrokerIDByBank[v.size()] = '\0';
    }
    const char* getBrokerIDByBank() {
        return this->BrokerIDByBank;
    }

    void setBankSecuAcc(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSecuAcc);
        this->BankSecuAcc[v.size()] = '\0';
    }
    const char* getBankSecuAcc() {
        return this->BankSecuAcc;
    }

    void setOperNo(std::string v) {
        std::copy(v.begin(), v.end(), this->OperNo);
        this->OperNo[v.size()] = '\0';
    }
    const char* getOperNo() {
        return this->OperNo;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setErrorMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->ErrorMsg);
        this->ErrorMsg[v.size()] = '\0';
    }
    const char* getErrorMsg() {
        return this->ErrorMsg;
    }

    void setLongCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->LongCustomerName);
        this->LongCustomerName[v.size()] = '\0';
    }
    const char* getLongCustomerName() {
        return this->LongCustomerName;
    }
};

struct ChangeAccountField: CThostFtdcChangeAccountField {

    ChangeAccountField() {
        std::memset(this, 0, sizeof(ChangeAccountField));
    }

    ChangeAccountField(const CThostFtdcChangeAccountField& f): CThostFtdcChangeAccountField(f){}

    ChangeAccountField& operator=(const CThostFtdcChangeAccountField& f) {
        CThostFtdcChangeAccountField::operator=(f);
        return *this;
    }

    void setTradeCode(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeCode);
        this->TradeCode[v.size()] = '\0';
    }
    const char* getTradeCode() {
        return this->TradeCode;
    }

    void setBankID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankID);
        this->BankID[v.size()] = '\0';
    }
    const char* getBankID() {
        return this->BankID;
    }

    void setBankBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BankBranchID);
        this->BankBranchID[v.size()] = '\0';
    }
    const char* getBankBranchID() {
        return this->BankBranchID;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setBrokerBranchID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerBranchID);
        this->BrokerBranchID[v.size()] = '\0';
    }
    const char* getBrokerBranchID() {
        return this->BrokerBranchID;
    }

    void setTradeDate(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeDate);
        this->TradeDate[v.size()] = '\0';
    }
    const char* getTradeDate() {
        return this->TradeDate;
    }

    void setTradeTime(std::string v) {
        std::copy(v.begin(), v.end(), this->TradeTime);
        this->TradeTime[v.size()] = '\0';
    }
    const char* getTradeTime() {
        return this->TradeTime;
    }

    void setBankSerial(std::string v) {
        std::copy(v.begin(), v.end(), this->BankSerial);
        this->BankSerial[v.size()] = '\0';
    }
    const char* getBankSerial() {
        return this->BankSerial;
    }

    void setTradingDay(std::string v) {
        std::copy(v.begin(), v.end(), this->TradingDay);
        this->TradingDay[v.size()] = '\0';
    }
    const char* getTradingDay() {
        return this->TradingDay;
    }

    void setCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->CustomerName);
        this->CustomerName[v.size()] = '\0';
    }
    const char* getCustomerName() {
        return this->CustomerName;
    }

    void setIdentifiedCardNo(std::string v) {
        std::copy(v.begin(), v.end(), this->IdentifiedCardNo);
        this->IdentifiedCardNo[v.size()] = '\0';
    }
    const char* getIdentifiedCardNo() {
        return this->IdentifiedCardNo;
    }

    void setCountryCode(std::string v) {
        std::copy(v.begin(), v.end(), this->CountryCode);
        this->CountryCode[v.size()] = '\0';
    }
    const char* getCountryCode() {
        return this->CountryCode;
    }

    void setAddress(std::string v) {
        std::copy(v.begin(), v.end(), this->Address);
        this->Address[v.size()] = '\0';
    }
    const char* getAddress() {
        return this->Address;
    }

    void setZipCode(std::string v) {
        std::copy(v.begin(), v.end(), this->ZipCode);
        this->ZipCode[v.size()] = '\0';
    }
    const char* getZipCode() {
        return this->ZipCode;
    }

    void setTelephone(std::string v) {
        std::copy(v.begin(), v.end(), this->Telephone);
        this->Telephone[v.size()] = '\0';
    }
    const char* getTelephone() {
        return this->Telephone;
    }

    void setMobilePhone(std::string v) {
        std::copy(v.begin(), v.end(), this->MobilePhone);
        this->MobilePhone[v.size()] = '\0';
    }
    const char* getMobilePhone() {
        return this->MobilePhone;
    }

    void setFax(std::string v) {
        std::copy(v.begin(), v.end(), this->Fax);
        this->Fax[v.size()] = '\0';
    }
    const char* getFax() {
        return this->Fax;
    }

    void setEMail(std::string v) {
        std::copy(v.begin(), v.end(), this->EMail);
        this->EMail[v.size()] = '\0';
    }
    const char* getEMail() {
        return this->EMail;
    }

    void setBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->BankAccount);
        this->BankAccount[v.size()] = '\0';
    }
    const char* getBankAccount() {
        return this->BankAccount;
    }

    void setBankPassWord(std::string v) {
        std::copy(v.begin(), v.end(), this->BankPassWord);
        this->BankPassWord[v.size()] = '\0';
    }
    const char* getBankPassWord() {
        return this->BankPassWord;
    }

    void setNewBankAccount(std::string v) {
        std::copy(v.begin(), v.end(), this->NewBankAccount);
        this->NewBankAccount[v.size()] = '\0';
    }
    const char* getNewBankAccount() {
        return this->NewBankAccount;
    }

    void setNewBankPassWord(std::string v) {
        std::copy(v.begin(), v.end(), this->NewBankPassWord);
        this->NewBankPassWord[v.size()] = '\0';
    }
    const char* getNewBankPassWord() {
        return this->NewBankPassWord;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setPassword(std::string v) {
        std::copy(v.begin(), v.end(), this->Password);
        this->Password[v.size()] = '\0';
    }
    const char* getPassword() {
        return this->Password;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setBrokerIDByBank(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerIDByBank);
        this->BrokerIDByBank[v.size()] = '\0';
    }
    const char* getBrokerIDByBank() {
        return this->BrokerIDByBank;
    }

    void setDigest(std::string v) {
        std::copy(v.begin(), v.end(), this->Digest);
        this->Digest[v.size()] = '\0';
    }
    const char* getDigest() {
        return this->Digest;
    }

    void setErrorMsg(std::string v) {
        std::copy(v.begin(), v.end(), this->ErrorMsg);
        this->ErrorMsg[v.size()] = '\0';
    }
    const char* getErrorMsg() {
        return this->ErrorMsg;
    }

    void setLongCustomerName(std::string v) {
        std::copy(v.begin(), v.end(), this->LongCustomerName);
        this->LongCustomerName[v.size()] = '\0';
    }
    const char* getLongCustomerName() {
        return this->LongCustomerName;
    }
};

struct SecAgentACIDMapField: CThostFtdcSecAgentACIDMapField {

    SecAgentACIDMapField() {
        std::memset(this, 0, sizeof(SecAgentACIDMapField));
    }

    SecAgentACIDMapField(const CThostFtdcSecAgentACIDMapField& f): CThostFtdcSecAgentACIDMapField(f){}

    SecAgentACIDMapField& operator=(const CThostFtdcSecAgentACIDMapField& f) {
        CThostFtdcSecAgentACIDMapField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }

    void setBrokerSecAgentID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerSecAgentID);
        this->BrokerSecAgentID[v.size()] = '\0';
    }
    const char* getBrokerSecAgentID() {
        return this->BrokerSecAgentID;
    }
};

struct QrySecAgentACIDMapField: CThostFtdcQrySecAgentACIDMapField {

    QrySecAgentACIDMapField() {
        std::memset(this, 0, sizeof(QrySecAgentACIDMapField));
    }

    QrySecAgentACIDMapField(const CThostFtdcQrySecAgentACIDMapField& f): CThostFtdcQrySecAgentACIDMapField(f){}

    QrySecAgentACIDMapField& operator=(const CThostFtdcQrySecAgentACIDMapField& f) {
        CThostFtdcQrySecAgentACIDMapField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }

    void setAccountID(std::string v) {
        std::copy(v.begin(), v.end(), this->AccountID);
        this->AccountID[v.size()] = '\0';
    }
    const char* getAccountID() {
        return this->AccountID;
    }

    void setCurrencyID(std::string v) {
        std::copy(v.begin(), v.end(), this->CurrencyID);
        this->CurrencyID[v.size()] = '\0';
    }
    const char* getCurrencyID() {
        return this->CurrencyID;
    }
};

struct FensUserInfoField: CThostFtdcFensUserInfoField {

    FensUserInfoField() {
        std::memset(this, 0, sizeof(FensUserInfoField));
    }

    FensUserInfoField(const CThostFtdcFensUserInfoField& f): CThostFtdcFensUserInfoField(f){}

    FensUserInfoField& operator=(const CThostFtdcFensUserInfoField& f) {
        CThostFtdcFensUserInfoField::operator=(f);
        return *this;
    }

    void setBrokerID(std::string v) {
        std::copy(v.begin(), v.end(), this->BrokerID);
        this->BrokerID[v.size()] = '\0';
    }
    const char* getBrokerID() {
        return this->BrokerID;
    }

    void setUserID(std::string v) {
        std::copy(v.begin(), v.end(), this->UserID);
        this->UserID[v.size()] = '\0';
    }
    const char* getUserID() {
        return this->UserID;
    }
};

#endif //PYCTP_CTPTD_H
