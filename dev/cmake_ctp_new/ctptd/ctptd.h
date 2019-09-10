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
#define ON_RSP_USER_AUTH_METHOD 9
#define ON_RSP_GEN_USER_CAPTCHA 10
#define ON_RSP_GEN_USER_TEXT 11
#define ON_RSP_ORDER_INSERT 12
#define ON_RSP_PARKED_ORDER_INSERT 13
#define ON_RSP_PARKED_ORDER_ACTION 14
#define ON_RSP_ORDER_ACTION 15
#define ON_RSP_QUERY_MAX_ORDER_VOLUME 16
#define ON_RSP_SETTLEMENT_INFO_CONFIRM 17
#define ON_RSP_REMOVE_PARKED_ORDER 18
#define ON_RSP_REMOVE_PARKED_ORDER_ACTION 19
#define ON_RSP_EXEC_ORDER_INSERT 20
#define ON_RSP_EXEC_ORDER_ACTION 21
#define ON_RSP_FOR_QUOTE_INSERT 22
#define ON_RSP_QUOTE_INSERT 23
#define ON_RSP_QUOTE_ACTION 24
#define ON_RSP_BATCH_ORDER_ACTION 25
#define ON_RSP_OPTION_SELF_CLOSE_INSERT 26
#define ON_RSP_OPTION_SELF_CLOSE_ACTION 27
#define ON_RSP_COMB_ACTION_INSERT 28
#define ON_RSP_QRY_ORDER 29
#define ON_RSP_QRY_TRADE 30
#define ON_RSP_QRY_INVESTOR_POSITION 31
#define ON_RSP_QRY_TRADING_ACCOUNT 32
#define ON_RSP_QRY_INVESTOR 33
#define ON_RSP_QRY_TRADING_CODE 34
#define ON_RSP_QRY_INSTRUMENT_MARGIN_RATE 35
#define ON_RSP_QRY_INSTRUMENT_COMMISSION_RATE 36
#define ON_RSP_QRY_EXCHANGE 37
#define ON_RSP_QRY_PRODUCT 38
#define ON_RSP_QRY_INSTRUMENT 39
#define ON_RSP_QRY_DEPTH_MARKET_DATA 40
#define ON_RSP_QRY_SETTLEMENT_INFO 41
#define ON_RSP_QRY_TRANSFER_BANK 42
#define ON_RSP_QRY_INVESTOR_POSITION_DETAIL 43
#define ON_RSP_QRY_NOTICE 44
#define ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM 45
#define ON_RSP_QRY_INVESTOR_POSITION_COMBINE_DETAIL 46
#define ON_RSP_QRY_C_F_M_M_C_TRADING_ACCOUNT_KEY 47
#define ON_RSP_QRY_E_WARRANT_OFFSET 48
#define ON_RSP_QRY_INVESTOR_PRODUCT_GROUP_MARGIN 49
#define ON_RSP_QRY_EXCHANGE_MARGIN_RATE 50
#define ON_RSP_QRY_EXCHANGE_MARGIN_RATE_ADJUST 51
#define ON_RSP_QRY_EXCHANGE_RATE 52
#define ON_RSP_QRY_SEC_AGENT_A_C_I_D_MAP 53
#define ON_RSP_QRY_PRODUCT_EXCH_RATE 54
#define ON_RSP_QRY_PRODUCT_GROUP 55
#define ON_RSP_QRY_M_M_INSTRUMENT_COMMISSION_RATE 56
#define ON_RSP_QRY_M_M_OPTION_INSTR_COMM_RATE 57
#define ON_RSP_QRY_INSTRUMENT_ORDER_COMM_RATE 58
#define ON_RSP_QRY_SEC_AGENT_TRADING_ACCOUNT 59
#define ON_RSP_QRY_SEC_AGENT_CHECK_MODE 60
#define ON_RSP_QRY_SEC_AGENT_TRADE_INFO 61
#define ON_RSP_QRY_OPTION_INSTR_TRADE_COST 62
#define ON_RSP_QRY_OPTION_INSTR_COMM_RATE 63
#define ON_RSP_QRY_EXEC_ORDER 64
#define ON_RSP_QRY_FOR_QUOTE 65
#define ON_RSP_QRY_QUOTE 66
#define ON_RSP_QRY_OPTION_SELF_CLOSE 67
#define ON_RSP_QRY_INVEST_UNIT 68
#define ON_RSP_QRY_COMB_INSTRUMENT_GUARD 69
#define ON_RSP_QRY_COMB_ACTION 70
#define ON_RSP_QRY_TRANSFER_SERIAL 71
#define ON_RSP_QRY_ACCOUNTREGISTER 72
#define ON_RSP_ERROR 73
#define ON_RTN_ORDER 74
#define ON_RTN_TRADE 75
#define ON_ERR_RTN_ORDER_INSERT 76
#define ON_ERR_RTN_ORDER_ACTION 77
#define ON_RTN_INSTRUMENT_STATUS 78
#define ON_RTN_BULLETIN 79
#define ON_RTN_TRADING_NOTICE 80
#define ON_RTN_ERROR_CONDITIONAL_ORDER 81
#define ON_RTN_EXEC_ORDER 82
#define ON_ERR_RTN_EXEC_ORDER_INSERT 83
#define ON_ERR_RTN_EXEC_ORDER_ACTION 84
#define ON_ERR_RTN_FOR_QUOTE_INSERT 85
#define ON_RTN_QUOTE 86
#define ON_ERR_RTN_QUOTE_INSERT 87
#define ON_ERR_RTN_QUOTE_ACTION 88
#define ON_RTN_FOR_QUOTE_RSP 89
#define ON_RTN_C_F_M_M_C_TRADING_ACCOUNT_TOKEN 90
#define ON_ERR_RTN_BATCH_ORDER_ACTION 91
#define ON_RTN_OPTION_SELF_CLOSE 92
#define ON_ERR_RTN_OPTION_SELF_CLOSE_INSERT 93
#define ON_ERR_RTN_OPTION_SELF_CLOSE_ACTION 94
#define ON_RTN_COMB_ACTION 95
#define ON_ERR_RTN_COMB_ACTION_INSERT 96
#define ON_RSP_QRY_CONTRACT_BANK 97
#define ON_RSP_QRY_PARKED_ORDER 98
#define ON_RSP_QRY_PARKED_ORDER_ACTION 99
#define ON_RSP_QRY_TRADING_NOTICE 100
#define ON_RSP_QRY_BROKER_TRADING_PARAMS 101
#define ON_RSP_QRY_BROKER_TRADING_ALGOS 102
#define ON_RSP_QUERY_C_F_M_M_C_TRADING_ACCOUNT_TOKEN 103
#define ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK 104
#define ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK 105
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK 106
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK 107
#define ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE 108
#define ON_RTN_FROM_FUTURE_TO_BANK_BY_FUTURE 109
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL 110
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL 111
#define ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE 112
#define ON_ERR_RTN_BANK_TO_FUTURE_BY_FUTURE 113
#define ON_ERR_RTN_FUTURE_TO_BANK_BY_FUTURE 114
#define ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL 115
#define ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL 116
#define ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE 117
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE 118
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE 119
#define ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE 120
#define ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE 121
#define ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE 122
#define ON_RTN_OPEN_ACCOUNT_BY_BANK 123
#define ON_RTN_CANCEL_ACCOUNT_BY_BANK 124
#define ON_RTN_CHANGE_ACCOUNT_BY_BANK 125

class CtpTd : public CThostFtdcTraderSpi {
private:
    boost::thread * task_thread; 
    ConcurrentQueue<Task *> task_queue; 
    CThostFtdcTraderApi* api; 
 	void processTask();

public:
    CtpTd(const std::string &szFlowPath = "");
    ~CtpTd();


    virtual void OnFrontConnected();
    virtual void onFrontConnected() {};

    virtual void OnFrontDisconnected(int nReason);
    virtual void onFrontDisconnected(int reasonCode) {};

    ///@param nTimeLapse 
    virtual void OnHeartBeatWarning(int nTimeLapse);
    virtual void onHeartBeatWarning(int lapsedTime) {};


    virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspAuthenticate(boost::python::object &rspAuthenticateField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUserLogin(boost::python::object &rspUserLoginField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUserLogout(boost::python::object &userLogoutField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUserPasswordUpdate(boost::python::object &userPasswordUpdateField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspTradingAccountPasswordUpdate(boost::python::object &tradingAccountPasswordUpdateField, boost::python::object &rspInfoField, int requestId, bool final) {};

	virtual void OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField *pRspUserAuthMethod, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void onRspUserAuthMethod(boost::python::object &rspUserAuthMethodField, boost::python::object &rspInfoField, int requestId, bool final) {};

	virtual void OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField *pRspGenUserCaptcha, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void onRspGenUserCaptcha(boost::python::object &rspGenUserCaptchaField, boost::python::object &rspInfoField, int requestId, bool final) {};
	virtual void OnRspGenUserText(CThostFtdcRspGenUserTextField *pRspGenUserText, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void onRspGenUserText(boost::python::object &rspGenUserTextField, boost::python::object &rspInfoField, int requestId, bool final) {};
    virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspOrderInsert(boost::python::object &inputOrderField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspParkedOrderInsert(boost::python::object &parkedOrderField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspParkedOrderAction(boost::python::object &parkedOrderActionField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspOrderAction(boost::python::object &inputOrderActionField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQueryMaxOrderVolume(boost::python::object &queryMaxOrderVolumeField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspSettlementInfoConfirm(boost::python::object &settlementInfoConfirmField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspRemoveParkedOrder(boost::python::object &removeParkedOrderField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspRemoveParkedOrderAction(boost::python::object &removeParkedOrderActionField, boost::python::object &rspInfoField, int requestId, bool final) {};

 
    virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspExecOrderInsert(boost::python::object &inputExecOrderField, boost::python::object &rspInfoField, int requestId, bool final) {};

 
    virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspExecOrderAction(boost::python::object &inputExecOrderActionField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspForQuoteInsert(boost::python::object &inputForQuoteField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQuoteInsert(boost::python::object &inputQuoteField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQuoteAction(boost::python::object &inputQuoteActionField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspBatchOrderAction(boost::python::object &inputBatchOrderActionField, boost::python::object &rspInfoField, int requestId, bool final) {};

	virtual void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void onRspOptionSelfCloseInsert(boost::python::object &inputOptionSelfCloseField, boost::python::object &rspInfoField, int requestId, bool final) {};
 
	virtual void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void onRspOptionSelfCloseAction(boost::python::object &inputOptionSelfCloseActionField, boost::python::object &rspInfoField, int requestId, bool final) {};
    virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspCombActionInsert(boost::python::object &inputCombActionField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryOrder(boost::python::object &orderField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTrade(boost::python::object &tradeField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInvestorPosition(boost::python::object &investorPositionField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTradingAccount(boost::python::object &tradingAccountField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInvestor(boost::python::object &investorField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTradingCode(boost::python::object &tradingCodeField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInstrumentMarginRate(boost::python::object &instrumentMarginRateField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInstrumentCommissionRate(boost::python::object &instrumentCommissionRateField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryExchange(boost::python::object &exchangeField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryProduct(boost::python::object &productField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInstrument(boost::python::object &instrumentField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryDepthMarketData(boost::python::object &depthMarketDataField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQrySettlementInfo(boost::python::object &settlementInfoField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTransferBank(boost::python::object &transferBankField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInvestorPositionDetail(boost::python::object &investorPositionDetailField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryNotice(boost::python::object &noticeField, boost::python::object &rspInfoField, int requestId, bool final) {};

    virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQrySettlementInfoConfirm(boost::python::object &settlementInfoConfirmField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInvestorPositionCombineDetail(boost::python::object &investorPositionCombineDetailField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryCFMMCTradingAccountKey(boost::python::object &cFMMCTradingAccountKeyField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryEWarrantOffset(boost::python::object &eWarrantOffsetField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInvestorProductGroupMargin(boost::python::object &investorProductGroupMarginField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryExchangeMarginRate(boost::python::object &exchangeMarginRateField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryExchangeMarginRateAdjust(boost::python::object &exchangeMarginRateAdjustField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryExchangeRate(boost::python::object &exchangeRateField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQrySecAgentACIDMap(boost::python::object &secAgentACIDMapField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryProductExchRate(boost::python::object &productExchRateField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryProductGroup(boost::python::object &productGroupField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryMMInstrumentCommissionRate(boost::python::object &mMInstrumentCommissionRateField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryMMOptionInstrCommRate(boost::python::object &mMOptionInstrCommRateField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryInstrumentOrderCommRate(boost::python::object &instrumentOrderCommRateField, boost::python::object &rspInfoField, int requestId, bool final) {};

	virtual void OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void onRspQrySecAgentTradingAccount(boost::python::object &tradingAccountField, boost::python::object &rspInfoField, int requestId, bool final) {};

	virtual void OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField *pSecAgentCheckMode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void onRspQrySecAgentCheckMode(boost::python::object &secAgentCheckModeField, boost::python::object &rspInfoField, int requestId, bool final) {};
	virtual void OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField *pSecAgentTradeInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void onRspQrySecAgentTradeInfo(boost::python::object &secAgentTradeInfoField, boost::python::object &rspInfoField, int requestId, bool final) {};
    virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryOptionInstrTradeCost(boost::python::object &optionInstrTradeCostField, boost::python::object &rspInfoField, int requestId, bool final) {};

 
    virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryOptionInstrCommRate(boost::python::object &optionInstrCommRateField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryExecOrder(boost::python::object &execOrderField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryForQuote(boost::python::object &forQuoteField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryQuote(boost::python::object &quoteField, boost::python::object &rspInfoField, int requestId, bool final) {};

	virtual void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void onRspQryOptionSelfClose(boost::python::object &optionSelfCloseField, boost::python::object &rspInfoField, int requestId, bool final) {};

	virtual void OnRspQryInvestUnit(CThostFtdcInvestUnitField *pInvestUnit, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void onRspQryInvestUnit(boost::python::object &investUnitField, boost::python::object &rspInfoField, int requestId, bool final) {};
    virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryCombInstrumentGuard(boost::python::object &combInstrumentGuardField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryCombAction(boost::python::object &combActionField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTransferSerial(boost::python::object &transferSerialField, boost::python::object &rspInfoField, int requestId, bool final) {};

    virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryAccountregister(boost::python::object &accountregisterField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspError(boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);
    virtual void onRtnOrder(boost::python::object &orderField) {};


    virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);
    virtual void onRtnTrade(boost::python::object &tradeField) {};


    virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnOrderInsert(boost::python::object &inputOrderField, boost::python::object &rspInfoField) {};


    virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnOrderAction(boost::python::object &orderActionField, boost::python::object &rspInfoField) {};


    virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);
    virtual void onRtnInstrumentStatus(boost::python::object &instrumentStatusField) {};

    virtual void OnRtnBulletin(CThostFtdcBulletinField *pBulletin);
    virtual void onRtnBulletin(boost::python::object &bulletinField) {};


    virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);
    virtual void onRtnTradingNotice(boost::python::object &tradingNoticeInfoField) {};

 
    virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);
    virtual void onRtnErrorConditionalOrder(boost::python::object &errorConditionalOrderField) {};


    virtual void OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder);
    virtual void onRtnExecOrder(boost::python::object &execOrderField) {};


    virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnExecOrderInsert(boost::python::object &inputExecOrderField, boost::python::object &rspInfoField) {};


    virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnExecOrderAction(boost::python::object &execOrderActionField, boost::python::object &rspInfoField) {};


    virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnForQuoteInsert(boost::python::object &inputForQuoteField, boost::python::object &rspInfoField) {};


    virtual void OnRtnQuote(CThostFtdcQuoteField *pQuote);
    virtual void onRtnQuote(boost::python::object &quoteField) {};


    virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnQuoteInsert(boost::python::object &inputQuoteField, boost::python::object &rspInfoField) {};


    virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnQuoteAction(boost::python::object &quoteActionField, boost::python::object &rspInfoField) {};


    virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);
    virtual void onRtnForQuoteRsp(boost::python::object &forQuoteRspField) {};


    virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken);
    virtual void onRtnCFMMCTradingAccountToken(boost::python::object &cFMMCTradingAccountTokenField) {};


    virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnBatchOrderAction(boost::python::object &batchOrderActionField, boost::python::object &rspInfoField) {};

	virtual void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose);
	virtual void onRtnOptionSelfClose(boost::python::object &optionSelfCloseField) {};

	virtual void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo);
	virtual void onErrRtnOptionSelfCloseInsert(boost::python::object &inputOptionSelfCloseField, boost::python::object &rspInfoField) {};
	virtual void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo);
	virtual void onErrRtnOptionSelfCloseAction(boost::python::object &optionSelfCloseActionField, boost::python::object &rspInfoField) {};
    virtual void OnRtnCombAction(CThostFtdcCombActionField *pCombAction);
    virtual void onRtnCombAction(boost::python::object &combActionField) {};


    virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnCombActionInsert(boost::python::object &inputCombActionField, boost::python::object &rspInfoField) {};


    virtual void OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryContractBank(boost::python::object &contractBankField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryParkedOrder(boost::python::object &parkedOrderField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryParkedOrderAction(boost::python::object &parkedOrderActionField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryTradingNotice(boost::python::object &tradingNoticeField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryBrokerTradingParams(boost::python::object &brokerTradingParamsField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQryBrokerTradingAlgos(boost::python::object &brokerTradingAlgosField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQueryCFMMCTradingAccountToken(boost::python::object &queryCFMMCTradingAccountTokenField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer);
    virtual void onRtnFromBankToFutureByBank(boost::python::object &rspTransferField) {};

 
    virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer);
    virtual void onRtnFromFutureToBankByBank(boost::python::object &rspTransferField) {};


    virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromBankToFutureByBank(boost::python::object &rspRepealField) {};


    virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromFutureToBankByBank(boost::python::object &rspRepealField) {};


    virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);
    virtual void onRtnFromBankToFutureByFuture(boost::python::object &rspTransferField) {};


    virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);
    virtual void onRtnFromFutureToBankByFuture(boost::python::object &rspTransferField) {};


    virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromBankToFutureByFutureManual(boost::python::object &rspRepealField) {};


    virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromFutureToBankByFutureManual(boost::python::object &rspRepealField) {};


    virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);
    virtual void onRtnQueryBankBalanceByFuture(boost::python::object &notifyQueryAccountField) {};

  
    virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnBankToFutureByFuture(boost::python::object &reqTransferField, boost::python::object &rspInfoField) {};

 
    virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnFutureToBankByFuture(boost::python::object &reqTransferField, boost::python::object &rspInfoField) {};


    virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnRepealBankToFutureByFutureManual(boost::python::object &reqRepealField, boost::python::object &rspInfoField) {};


    virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnRepealFutureToBankByFutureManual(boost::python::object &reqRepealField, boost::python::object &rspInfoField) {};

 
    virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);
    virtual void onErrRtnQueryBankBalanceByFuture(boost::python::object &reqQueryAccountField, boost::python::object &rspInfoField) {};

 
    virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromBankToFutureByFuture(boost::python::object &rspRepealField) {};


    virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal);
    virtual void onRtnRepealFromFutureToBankByFuture(boost::python::object &rspRepealField) {};


    virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspFromBankToFutureByFuture(boost::python::object &reqTransferField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspFromFutureToBankByFuture(boost::python::object &reqTransferField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspQueryBankAccountMoneyByFuture(boost::python::object &reqQueryAccountField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount);
    virtual void onRtnOpenAccountByBank(boost::python::object &openAccountField) {};


    virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount);
    virtual void onRtnCancelAccountByBank(boost::python::object &cancelAccountField) {};

    virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount);
    virtual void onRtnChangeAccountByBank(boost::python::object &changeAccountField) {};

    const char *getApiVersion();

    void release();

    void init();

    int join();

    const char *getTradingDay();

    void registerFront(const std::string &szFrontAddress);

    void registerNameServer(const std::string &szNsAddress);

    void registerFensUserInfo(boost::python::object &fensUserInfoField);

void registerSpi();

    void subscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType);

    void subscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType);

    int reqAuthenticate(boost::python::object &reqAuthenticateField, int requestId);

int registerUserSystemInfo(boost::python::object &userSystemInfoField);

int submitUserSystemInfo(boost::python::object &userSystemInfoField);

int reqUserLogin(boost::python::object &reqUserLoginField, int requestId);

    int reqUserLogout(boost::python::object &userLogoutField, int requestId);

    int reqUserPasswordUpdate(boost::python::object &userPasswordUpdateField, int requestId);

int reqTradingAccountPasswordUpdate(boost::python::object &tradingAccountPasswordUpdateField, int requestId);

int reqUserAuthMethod(boost::python::object &reqUserAuthMethodField, int requestId);

int reqGenUserCaptcha(boost::python::object &reqGenUserCaptchaField, int requestId);

int reqGenUserText(boost::python::object &reqGenUserTextField, int requestId);

int reqUserLoginWithCaptcha(boost::python::object &reqUserLoginWithCaptchaField, int requestId);

int reqUserLoginWithText(boost::python::object &reqUserLoginWithTextField, int requestId);

int reqUserLoginWithOTP(boost::python::object &reqUserLoginWithOTPField, int requestId);

    int reqOrderInsert(boost::python::object &inputOrderField, int requestId);

    int reqParkedOrderInsert(boost::python::object &parkedOrderField, int requestId);

    int reqParkedOrderAction(boost::python::object &parkedOrderActionField, int requestId);

    int reqOrderAction(boost::python::object &inputOrderActionField, int requestId);

    int reqQueryMaxOrderVolume(boost::python::object &queryMaxOrderVolumeField, int requestId);

    int reqSettlementInfoConfirm(boost::python::object &settlementInfoConfirmField, int requestId);

    int reqRemoveParkedOrder(boost::python::object &removeParkedOrderField, int requestId);

    int reqRemoveParkedOrderAction(boost::python::object &removeParkedOrderActionField, int requestId);

    int reqExecOrderInsert(boost::python::object &inputExecOrderField, int requestId);

    int reqExecOrderAction(boost::python::object &inputExecOrderActionField, int requestId);

    int reqForQuoteInsert(boost::python::object &inputForQuoteField, int requestId);

    int reqQuoteInsert(boost::python::object &inputQuoteField, int requestId);

    int reqQuoteAction(boost::python::object &inputQuoteActionField, int requestId);

int reqBatchOrderAction(boost::python::object &inputBatchOrderActionField, int requestId);

int reqOptionSelfCloseInsert(boost::python::object &inputOptionSelfCloseField, int requestId);

int reqOptionSelfCloseAction(boost::python::object &inputOptionSelfCloseActionField, int requestId);

    int reqCombActionInsert(boost::python::object &inputCombActionField, int requestId);

    int reqQryOrder(boost::python::object &qryOrderField, int requestId);

    int reqQryTrade(boost::python::object &qryTradeField, int requestId);

    int reqQryInvestorPosition(boost::python::object &qryInvestorPositionField, int requestId);

    int reqQryTradingAccount(boost::python::object &qryTradingAccountField, int requestId);

    int reqQryInvestor(boost::python::object &qryInvestorField, int requestId);

    int reqQryTradingCode(boost::python::object &qryTradingCodeField, int requestId);

    int reqQryInstrumentMarginRate(boost::python::object &qryInstrumentMarginRateField, int requestId);

    int reqQryInstrumentCommissionRate(boost::python::object &qryInstrumentCommissionRateField, int requestId);

    int reqQryExchange(boost::python::object &qryExchangeField, int requestId);

    int reqQryProduct(boost::python::object &qryProductField, int requestId);

    int reqQryInstrument(boost::python::object &qryInstrumentField, int requestId);

    int reqQryDepthMarketData(boost::python::object &qryDepthMarketDataField, int requestId);

    int reqQrySettlementInfo(boost::python::object &qrySettlementInfoField, int requestId);

    int reqQryTransferBank(boost::python::object &qryTransferBankField, int requestId);

    int reqQryInvestorPositionDetail(boost::python::object &qryInvestorPositionDetailField, int requestId);

    int reqQryNotice(boost::python::object &qryNoticeField, int requestId);

    int reqQrySettlementInfoConfirm(boost::python::object &qrySettlementInfoConfirmField, int requestId);

    int reqQryInvestorPositionCombineDetail(boost::python::object &qryInvestorPositionCombineDetailField, int requestId);

    int reqQryCFMMCTradingAccountKey(boost::python::object &qryCFMMCTradingAccountKeyField, int requestId);

    int reqQryEWarrantOffset(boost::python::object &qryEWarrantOffsetField, int requestId);

    int reqQryInvestorProductGroupMargin(boost::python::object &qryInvestorProductGroupMarginField, int requestId);

    int reqQryExchangeMarginRate(boost::python::object &qryExchangeMarginRateField, int requestId);

    int reqQryExchangeMarginRateAdjust(boost::python::object &qryExchangeMarginRateAdjustField, int requestId);

    int reqQryExchangeRate(boost::python::object &qryExchangeRateField, int requestId);

    int reqQrySecAgentACIDMap(boost::python::object &qrySecAgentACIDMapField, int requestId);

    int reqQryProductExchRate(boost::python::object &qryProductExchRateField, int requestId);

    int reqQryProductGroup(boost::python::object &qryProductGroupField, int requestId);

    int reqQryMMInstrumentCommissionRate(boost::python::object &qryMMInstrumentCommissionRateField, int requestId);

    int reqQryMMOptionInstrCommRate(boost::python::object &qryMMOptionInstrCommRateField, int requestId);

    int reqQryInstrumentOrderCommRate(boost::python::object &qryInstrumentOrderCommRateField, int requestId);

int reqQrySecAgentTradingAccount(boost::python::object &qryTradingAccountField, int requestId);

int reqQrySecAgentCheckMode(boost::python::object &qrySecAgentCheckModeField, int requestId);

int reqQrySecAgentTradeInfo(boost::python::object &qrySecAgentTradeInfoField, int requestId);

int reqQryOptionInstrTradeCost(boost::python::object &qryOptionInstrTradeCostField, int requestId);

    int reqQryOptionInstrCommRate(boost::python::object &qryOptionInstrCommRateField, int requestId);

    int reqQryExecOrder(boost::python::object &qryExecOrderField, int requestId);

    int reqQryForQuote(boost::python::object &qryForQuoteField, int requestId);

int reqQryQuote(boost::python::object &qryQuoteField, int requestId);

int reqQryOptionSelfClose(boost::python::object &qryOptionSelfCloseField, int requestId);

int reqQryInvestUnit(boost::python::object &qryInvestUnitField, int requestId);

    int reqQryCombInstrumentGuard(boost::python::object &qryCombInstrumentGuardField, int requestId);

    int reqQryCombAction(boost::python::object &qryCombActionField, int requestId);

    int reqQryTransferSerial(boost::python::object &qryTransferSerialField, int requestId);

    int reqQryAccountregister(boost::python::object &qryAccountregisterField, int requestId);

    int reqQryContractBank(boost::python::object &qryContractBankField, int requestId);

    int reqQryParkedOrder(boost::python::object &qryParkedOrderField, int requestId);

    int reqQryParkedOrderAction(boost::python::object &qryParkedOrderActionField, int requestId);

    int reqQryTradingNotice(boost::python::object &qryTradingNoticeField, int requestId);

    int reqQryBrokerTradingParams(boost::python::object &qryBrokerTradingParamsField, int requestId);

    int reqQryBrokerTradingAlgos(boost::python::object &qryBrokerTradingAlgosField, int requestId);

    int reqQueryCFMMCTradingAccountToken(boost::python::object &queryCFMMCTradingAccountTokenField, int requestId);

    int reqFromBankToFutureByFuture(boost::python::object &reqTransferField, int requestId);

    int reqFromFutureToBankByFuture(boost::python::object &reqTransferField, int requestId);

    int reqQueryBankAccountMoneyByFuture(boost::python::object &reqQueryAccountField, int requestId);
};

struct ReqUserLoginField: CThostFtdcReqUserLoginField {

    ReqUserLoginField() {
        std::memset(this, 0, sizeof(ReqUserLoginField));
    }

    ReqUserLoginField(const CThostFtdcReqUserLoginField& f): CThostFtdcReqUserLoginField(f){}

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Password);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInterfaceProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InterfaceProductInfo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InterfaceProductInfo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInterfaceProductInfo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InterfaceProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InterfaceProductInfo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setProtocolInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProtocolInfo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProtocolInfo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProtocolInfo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProtocolInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProtocolInfo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOneTimePassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OneTimePassword,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OneTimePassword,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOneTimePassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OneTimePassword);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OneTimePassword);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientIPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientIPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientIPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientIPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLoginRemark(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LoginRemark,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LoginRemark,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLoginRemark() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LoginRemark);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LoginRemark);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct RspUserLoginField: CThostFtdcRspUserLoginField {

    RspUserLoginField() {
        std::memset(this, 0, sizeof(RspUserLoginField));
    }

    RspUserLoginField(const CThostFtdcRspUserLoginField& f): CThostFtdcRspUserLoginField(f){}

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLoginTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LoginTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LoginTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLoginTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LoginTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LoginTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setSystemName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->SystemName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->SystemName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getSystemName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->SystemName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->SystemName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMaxOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MaxOrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MaxOrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMaxOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MaxOrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MaxOrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setSHFETime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->SHFETime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->SHFETime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getSHFETime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->SHFETime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->SHFETime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDCETime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->DCETime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->DCETime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDCETime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->DCETime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->DCETime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCZCETime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CZCETime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CZCETime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCZCETime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CZCETime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CZCETime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setFFEXTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->FFEXTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->FFEXTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getFFEXTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->FFEXTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->FFEXTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setINETime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->INETime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->INETime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getINETime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->INETime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->INETime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct UserLogoutField: CThostFtdcUserLogoutField {

    UserLogoutField() {
        std::memset(this, 0, sizeof(UserLogoutField));
    }

    UserLogoutField(const CThostFtdcUserLogoutField& f): CThostFtdcUserLogoutField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ReqAuthenticateField: CThostFtdcReqAuthenticateField {

    ReqAuthenticateField() {
        std::memset(this, 0, sizeof(ReqAuthenticateField));
    }

    ReqAuthenticateField(const CThostFtdcReqAuthenticateField& f): CThostFtdcReqAuthenticateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAuthCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AuthCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AuthCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAuthCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AuthCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AuthCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setAppID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AppID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AppID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAppID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AppID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AppID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct RspAuthenticateField: CThostFtdcRspAuthenticateField {

    RspAuthenticateField() {
        std::memset(this, 0, sizeof(RspAuthenticateField));
    }

    RspAuthenticateField(const CThostFtdcRspAuthenticateField& f): CThostFtdcRspAuthenticateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setAppID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AppID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AppID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAppID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AppID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AppID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct RspInfoField: CThostFtdcRspInfoField {

    RspInfoField() {
        std::memset(this, 0, sizeof(RspInfoField));
    }

    RspInfoField(const CThostFtdcRspInfoField& f): CThostFtdcRspInfoField(f){}

    void setErrorMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ErrorMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ErrorMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getErrorMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ErrorMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ErrorMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ExchangeField: CThostFtdcExchangeField {

    ExchangeField() {
        std::memset(this, 0, sizeof(ExchangeField));
    }

    ExchangeField(const CThostFtdcExchangeField& f): CThostFtdcExchangeField(f){}

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ProductField: CThostFtdcProductField {

    ProductField() {
        std::memset(this, 0, sizeof(ProductField));
    }

    ProductField(const CThostFtdcProductField& f): CThostFtdcProductField(f){}

    void setProductID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setProductName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeCurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeCurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeCurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeCurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeProductID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeProductID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeProductID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeProductID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeProductID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeProductID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InstrumentField: CThostFtdcInstrumentField {

    InstrumentField() {
        std::memset(this, 0, sizeof(InstrumentField));
    }

    InstrumentField(const CThostFtdcInstrumentField& f): CThostFtdcInstrumentField(f){}

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setProductID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCreateDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CreateDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CreateDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCreateDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CreateDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CreateDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOpenDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OpenDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OpenDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOpenDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OpenDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OpenDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExpireDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExpireDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExpireDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExpireDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExpireDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExpireDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setStartDelivDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StartDelivDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->StartDelivDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getStartDelivDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->StartDelivDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->StartDelivDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setEndDelivDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->EndDelivDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->EndDelivDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getEndDelivDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->EndDelivDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->EndDelivDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUnderlyingInstrID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UnderlyingInstrID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UnderlyingInstrID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUnderlyingInstrID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UnderlyingInstrID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UnderlyingInstrID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InvestorField: CThostFtdcInvestorField {

    InvestorField() {
        std::memset(this, 0, sizeof(InvestorField));
    }

    InvestorField(const CThostFtdcInvestorField& f): CThostFtdcInvestorField(f){}

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorGroupID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorGroupID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorGroupID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorGroupID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorGroupID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorGroupID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTelephone(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Telephone,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Telephone,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTelephone() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Telephone);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Telephone);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Address,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Address,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Address);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Address);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOpenDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OpenDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OpenDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOpenDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OpenDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OpenDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMobile(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Mobile,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Mobile,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMobile() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Mobile);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Mobile);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCommModelID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CommModelID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CommModelID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCommModelID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CommModelID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CommModelID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMarginModelID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MarginModelID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MarginModelID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMarginModelID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MarginModelID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MarginModelID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct TradingCodeField: CThostFtdcTradingCodeField {

    TradingCodeField() {
        std::memset(this, 0, sizeof(TradingCodeField));
    }

    TradingCodeField(const CThostFtdcTradingCodeField& f): CThostFtdcTradingCodeField(f){}

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BranchID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BranchID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBranchID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BranchID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct TradingAccountField: CThostFtdcTradingAccountField {

    TradingAccountField() {
        std::memset(this, 0, sizeof(TradingAccountField));
    }

    TradingAccountField(const CThostFtdcTradingAccountField& f): CThostFtdcTradingAccountField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InvestorPositionField: CThostFtdcInvestorPositionField {

    InvestorPositionField() {
        std::memset(this, 0, sizeof(InvestorPositionField));
    }

    InvestorPositionField(const CThostFtdcInvestorPositionField& f): CThostFtdcInvestorPositionField(f){}

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct InstrumentMarginRateField: CThostFtdcInstrumentMarginRateField {

    InstrumentMarginRateField() {
        std::memset(this, 0, sizeof(InstrumentMarginRateField));
    }

    InstrumentMarginRateField(const CThostFtdcInstrumentMarginRateField& f): CThostFtdcInstrumentMarginRateField(f){}

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct InstrumentCommissionRateField: CThostFtdcInstrumentCommissionRateField {

    InstrumentCommissionRateField() {
        std::memset(this, 0, sizeof(InstrumentCommissionRateField));
    }

    InstrumentCommissionRateField(const CThostFtdcInstrumentCommissionRateField& f): CThostFtdcInstrumentCommissionRateField(f){}

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct DepthMarketDataField: CThostFtdcDepthMarketDataField {

    DepthMarketDataField() {
        std::memset(this, 0, sizeof(DepthMarketDataField));
    }

    DepthMarketDataField(const CThostFtdcDepthMarketDataField& f): CThostFtdcDepthMarketDataField(f){}

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUpdateTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UpdateTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UpdateTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUpdateTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UpdateTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UpdateTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct SettlementInfoField: CThostFtdcSettlementInfoField {

    SettlementInfoField() {
        std::memset(this, 0, sizeof(SettlementInfoField));
    }

    SettlementInfoField(const CThostFtdcSettlementInfoField& f): CThostFtdcSettlementInfoField(f){}

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setContent(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Content,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Content,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getContent() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Content);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Content);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AccountID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->CurrencyID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct ExchangeMarginRateField: CThostFtdcExchangeMarginRateField {

    ExchangeMarginRateField() {
        std::memset(this, 0, sizeof(ExchangeMarginRateField));
    }

    ExchangeMarginRateField(const CThostFtdcExchangeMarginRateField& f): CThostFtdcExchangeMarginRateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ExchangeMarginRateAdjustField: CThostFtdcExchangeMarginRateAdjustField {

    ExchangeMarginRateAdjustField() {
        std::memset(this, 0, sizeof(ExchangeMarginRateAdjustField));
    }

    ExchangeMarginRateAdjustField(const CThostFtdcExchangeMarginRateAdjustField& f): CThostFtdcExchangeMarginRateAdjustField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ExchangeRateField: CThostFtdcExchangeRateField {

    ExchangeRateField() {
        std::memset(this, 0, sizeof(ExchangeRateField));
    }

    ExchangeRateField(const CThostFtdcExchangeRateField& f): CThostFtdcExchangeRateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setFromCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->FromCurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->FromCurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getFromCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->FromCurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->FromCurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setToCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ToCurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ToCurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getToCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ToCurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ToCurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct UserPasswordUpdateField: CThostFtdcUserPasswordUpdateField {

    UserPasswordUpdateField() {
        std::memset(this, 0, sizeof(UserPasswordUpdateField));
    }

    UserPasswordUpdateField(const CThostFtdcUserPasswordUpdateField& f): CThostFtdcUserPasswordUpdateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOldPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OldPassword,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OldPassword,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOldPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OldPassword);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OldPassword);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setNewPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->NewPassword,PyBytes_AsString(bytes));
#else
        std::strcpy(this->NewPassword,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getNewPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->NewPassword);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->NewPassword);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InputOrderField: CThostFtdcInputOrderField {

    InputOrderField() {
        std::memset(this, 0, sizeof(InputOrderField));
    }

    InputOrderField(const CThostFtdcInputOrderField& f): CThostFtdcInputOrderField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombOffsetFlag(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombOffsetFlag,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombOffsetFlag,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombOffsetFlag() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombOffsetFlag);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombOffsetFlag);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombHedgeFlag(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombHedgeFlag,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombHedgeFlag,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombHedgeFlag() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombHedgeFlag);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombHedgeFlag);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setGTDDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->GTDDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->GTDDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getGTDDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->GTDDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->GTDDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct OrderField: CThostFtdcOrderField {

    OrderField() {
        std::memset(this, 0, sizeof(OrderField));
    }

    OrderField(const CThostFtdcOrderField& f): CThostFtdcOrderField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombOffsetFlag(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombOffsetFlag,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombOffsetFlag,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombOffsetFlag() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombOffsetFlag);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombOffsetFlag);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombHedgeFlag(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombHedgeFlag,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombHedgeFlag,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombHedgeFlag() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombHedgeFlag);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombHedgeFlag);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setGTDDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->GTDDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->GTDDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getGTDDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->GTDDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->GTDDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActiveTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActiveTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActiveTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActiveTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActiveTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActiveTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setSuspendTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->SuspendTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->SuspendTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getSuspendTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->SuspendTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->SuspendTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUpdateTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UpdateTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UpdateTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUpdateTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UpdateTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UpdateTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCancelTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CancelTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CancelTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCancelTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CancelTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CancelTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActiveTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActiveTraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActiveTraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActiveTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActiveTraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActiveTraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClearingPartID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClearingPartID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClearingPartID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClearingPartID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClearingPartID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClearingPartID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->StatusMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActiveUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActiveUserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActiveUserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActiveUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActiveUserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActiveUserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setRelativeOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->RelativeOrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->RelativeOrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getRelativeOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->RelativeOrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->RelativeOrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InputOrderActionField: CThostFtdcInputOrderActionField {

    InputOrderActionField() {
        std::memset(this, 0, sizeof(InputOrderActionField));
    }

    InputOrderActionField(const CThostFtdcInputOrderActionField& f): CThostFtdcInputOrderActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct OrderActionField: CThostFtdcOrderActionField {

    OrderActionField() {
        std::memset(this, 0, sizeof(OrderActionField));
    }

    OrderActionField(const CThostFtdcOrderActionField& f): CThostFtdcOrderActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->StatusMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct TradeField: CThostFtdcTradeField {

    TradeField() {
        std::memset(this, 0, sizeof(TradeField));
    }

    TradeField(const CThostFtdcTradeField& f): CThostFtdcTradeField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClearingPartID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClearingPartID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClearingPartID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClearingPartID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClearingPartID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClearingPartID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QueryMaxOrderVolumeField: CThostFtdcQueryMaxOrderVolumeField {

    QueryMaxOrderVolumeField() {
        std::memset(this, 0, sizeof(QueryMaxOrderVolumeField));
    }

    QueryMaxOrderVolumeField(const CThostFtdcQueryMaxOrderVolumeField& f): CThostFtdcQueryMaxOrderVolumeField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct SettlementInfoConfirmField: CThostFtdcSettlementInfoConfirmField {

    SettlementInfoConfirmField() {
        std::memset(this, 0, sizeof(SettlementInfoConfirmField));
    }

    SettlementInfoConfirmField(const CThostFtdcSettlementInfoConfirmField& f): CThostFtdcSettlementInfoConfirmField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setConfirmDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ConfirmDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ConfirmDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getConfirmDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ConfirmDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ConfirmDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setConfirmTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ConfirmTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ConfirmTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getConfirmTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ConfirmTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ConfirmTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AccountID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->CurrencyID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryOrderField: CThostFtdcQryOrderField {

    QryOrderField() {
        std::memset(this, 0, sizeof(QryOrderField));
    }

    QryOrderField(const CThostFtdcQryOrderField& f): CThostFtdcQryOrderField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTimeStart(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTimeStart,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTimeStart,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTimeStart() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTimeStart);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTimeStart);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTimeEnd(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTimeEnd,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTimeEnd,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTimeEnd() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTimeEnd);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTimeEnd);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryTradeField: CThostFtdcQryTradeField {

    QryTradeField() {
        std::memset(this, 0, sizeof(QryTradeField));
    }

    QryTradeField(const CThostFtdcQryTradeField& f): CThostFtdcQryTradeField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTimeStart(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTimeStart,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTimeStart,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTimeStart() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTimeStart);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTimeStart);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTimeEnd(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTimeEnd,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTimeEnd,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTimeEnd() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTimeEnd);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTimeEnd);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryInvestorPositionField: CThostFtdcQryInvestorPositionField {

    QryInvestorPositionField() {
        std::memset(this, 0, sizeof(QryInvestorPositionField));
    }

    QryInvestorPositionField(const CThostFtdcQryInvestorPositionField& f): CThostFtdcQryInvestorPositionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryTradingAccountField: CThostFtdcQryTradingAccountField {

    QryTradingAccountField() {
        std::memset(this, 0, sizeof(QryTradingAccountField));
    }

    QryTradingAccountField(const CThostFtdcQryTradingAccountField& f): CThostFtdcQryTradingAccountField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryInvestorField: CThostFtdcQryInvestorField {

    QryInvestorField() {
        std::memset(this, 0, sizeof(QryInvestorField));
    }

    QryInvestorField(const CThostFtdcQryInvestorField& f): CThostFtdcQryInvestorField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryTradingCodeField: CThostFtdcQryTradingCodeField {

    QryTradingCodeField() {
        std::memset(this, 0, sizeof(QryTradingCodeField));
    }

    QryTradingCodeField(const CThostFtdcQryTradingCodeField& f): CThostFtdcQryTradingCodeField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryInstrumentMarginRateField: CThostFtdcQryInstrumentMarginRateField {

    QryInstrumentMarginRateField() {
        std::memset(this, 0, sizeof(QryInstrumentMarginRateField));
    }

    QryInstrumentMarginRateField(const CThostFtdcQryInstrumentMarginRateField& f): CThostFtdcQryInstrumentMarginRateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryInstrumentCommissionRateField: CThostFtdcQryInstrumentCommissionRateField {

    QryInstrumentCommissionRateField() {
        std::memset(this, 0, sizeof(QryInstrumentCommissionRateField));
    }

    QryInstrumentCommissionRateField(const CThostFtdcQryInstrumentCommissionRateField& f): CThostFtdcQryInstrumentCommissionRateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryExchangeField: CThostFtdcQryExchangeField {

    QryExchangeField() {
        std::memset(this, 0, sizeof(QryExchangeField));
    }

    QryExchangeField(const CThostFtdcQryExchangeField& f): CThostFtdcQryExchangeField(f){}

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryProductField: CThostFtdcQryProductField {

    QryProductField() {
        std::memset(this, 0, sizeof(QryProductField));
    }

    QryProductField(const CThostFtdcQryProductField& f): CThostFtdcQryProductField(f){}

    void setProductID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryInstrumentField: CThostFtdcQryInstrumentField {

    QryInstrumentField() {
        std::memset(this, 0, sizeof(QryInstrumentField));
    }

    QryInstrumentField(const CThostFtdcQryInstrumentField& f): CThostFtdcQryInstrumentField(f){}

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setProductID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryDepthMarketDataField: CThostFtdcQryDepthMarketDataField {

    QryDepthMarketDataField() {
        std::memset(this, 0, sizeof(QryDepthMarketDataField));
    }

    QryDepthMarketDataField(const CThostFtdcQryDepthMarketDataField& f): CThostFtdcQryDepthMarketDataField(f){}

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QrySettlementInfoField: CThostFtdcQrySettlementInfoField {

    QrySettlementInfoField() {
        std::memset(this, 0, sizeof(QrySettlementInfoField));
    }

    QrySettlementInfoField(const CThostFtdcQrySettlementInfoField& f): CThostFtdcQrySettlementInfoField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AccountID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->CurrencyID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryExchangeMarginRateField: CThostFtdcQryExchangeMarginRateField {

    QryExchangeMarginRateField() {
        std::memset(this, 0, sizeof(QryExchangeMarginRateField));
    }

    QryExchangeMarginRateField(const CThostFtdcQryExchangeMarginRateField& f): CThostFtdcQryExchangeMarginRateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryExchangeMarginRateAdjustField: CThostFtdcQryExchangeMarginRateAdjustField {

    QryExchangeMarginRateAdjustField() {
        std::memset(this, 0, sizeof(QryExchangeMarginRateAdjustField));
    }

    QryExchangeMarginRateAdjustField(const CThostFtdcQryExchangeMarginRateAdjustField& f): CThostFtdcQryExchangeMarginRateAdjustField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryExchangeRateField: CThostFtdcQryExchangeRateField {

    QryExchangeRateField() {
        std::memset(this, 0, sizeof(QryExchangeRateField));
    }

    QryExchangeRateField(const CThostFtdcQryExchangeRateField& f): CThostFtdcQryExchangeRateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setFromCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->FromCurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->FromCurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getFromCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->FromCurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->FromCurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setToCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ToCurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ToCurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getToCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ToCurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ToCurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct OptionInstrCommRateField: CThostFtdcOptionInstrCommRateField {

    OptionInstrCommRateField() {
        std::memset(this, 0, sizeof(OptionInstrCommRateField));
    }

    OptionInstrCommRateField(const CThostFtdcOptionInstrCommRateField& f): CThostFtdcOptionInstrCommRateField(f){}

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct OptionInstrTradeCostField: CThostFtdcOptionInstrTradeCostField {

    OptionInstrTradeCostField() {
        std::memset(this, 0, sizeof(OptionInstrTradeCostField));
    }

    OptionInstrTradeCostField(const CThostFtdcOptionInstrTradeCostField& f): CThostFtdcOptionInstrTradeCostField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryOptionInstrTradeCostField: CThostFtdcQryOptionInstrTradeCostField {

    QryOptionInstrTradeCostField() {
        std::memset(this, 0, sizeof(QryOptionInstrTradeCostField));
    }

    QryOptionInstrTradeCostField(const CThostFtdcQryOptionInstrTradeCostField& f): CThostFtdcQryOptionInstrTradeCostField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryOptionInstrCommRateField: CThostFtdcQryOptionInstrCommRateField {

    QryOptionInstrCommRateField() {
        std::memset(this, 0, sizeof(QryOptionInstrCommRateField));
    }

    QryOptionInstrCommRateField(const CThostFtdcQryOptionInstrCommRateField& f): CThostFtdcQryOptionInstrCommRateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InputExecOrderField: CThostFtdcInputExecOrderField {

    InputExecOrderField() {
        std::memset(this, 0, sizeof(InputExecOrderField));
    }

    InputExecOrderField(const CThostFtdcInputExecOrderField& f): CThostFtdcInputExecOrderField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExecOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExecOrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExecOrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExecOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExecOrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExecOrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InputExecOrderActionField: CThostFtdcInputExecOrderActionField {

    InputExecOrderActionField() {
        std::memset(this, 0, sizeof(InputExecOrderActionField));
    }

    InputExecOrderActionField(const CThostFtdcInputExecOrderActionField& f): CThostFtdcInputExecOrderActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExecOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExecOrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExecOrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExecOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExecOrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExecOrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExecOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExecOrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExecOrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExecOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExecOrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExecOrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ExecOrderField: CThostFtdcExecOrderField {

    ExecOrderField() {
        std::memset(this, 0, sizeof(ExecOrderField));
    }

    ExecOrderField(const CThostFtdcExecOrderField& f): CThostFtdcExecOrderField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExecOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExecOrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExecOrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExecOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExecOrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExecOrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExecOrderLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExecOrderLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExecOrderLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExecOrderLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExecOrderLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExecOrderLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExecOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExecOrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExecOrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExecOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExecOrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExecOrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCancelTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CancelTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CancelTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCancelTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CancelTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CancelTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClearingPartID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClearingPartID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClearingPartID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClearingPartID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClearingPartID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClearingPartID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->StatusMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActiveUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActiveUserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActiveUserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActiveUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActiveUserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActiveUserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ExecOrderActionField: CThostFtdcExecOrderActionField {

    ExecOrderActionField() {
        std::memset(this, 0, sizeof(ExecOrderActionField));
    }

    ExecOrderActionField(const CThostFtdcExecOrderActionField& f): CThostFtdcExecOrderActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExecOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExecOrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExecOrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExecOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExecOrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExecOrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExecOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExecOrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExecOrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExecOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExecOrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExecOrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExecOrderLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExecOrderLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExecOrderLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExecOrderLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExecOrderLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExecOrderLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->StatusMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryExecOrderField: CThostFtdcQryExecOrderField {

    QryExecOrderField() {
        std::memset(this, 0, sizeof(QryExecOrderField));
    }

    QryExecOrderField(const CThostFtdcQryExecOrderField& f): CThostFtdcQryExecOrderField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExecOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExecOrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExecOrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExecOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExecOrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExecOrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTimeStart(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTimeStart,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTimeStart,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTimeStart() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTimeStart);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTimeStart);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTimeEnd(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTimeEnd,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTimeEnd,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTimeEnd() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTimeEnd);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTimeEnd);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InputForQuoteField: CThostFtdcInputForQuoteField {

    InputForQuoteField() {
        std::memset(this, 0, sizeof(InputForQuoteField));
    }

    InputForQuoteField(const CThostFtdcInputForQuoteField& f): CThostFtdcInputForQuoteField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setForQuoteRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ForQuoteRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ForQuoteRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getForQuoteRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ForQuoteRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ForQuoteRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ForQuoteField: CThostFtdcForQuoteField {

    ForQuoteField() {
        std::memset(this, 0, sizeof(ForQuoteField));
    }

    ForQuoteField(const CThostFtdcForQuoteField& f): CThostFtdcForQuoteField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setForQuoteRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ForQuoteRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ForQuoteRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getForQuoteRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ForQuoteRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ForQuoteRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setForQuoteLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ForQuoteLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ForQuoteLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getForQuoteLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ForQuoteLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ForQuoteLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->StatusMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActiveUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActiveUserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActiveUserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActiveUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActiveUserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActiveUserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryForQuoteField: CThostFtdcQryForQuoteField {

    QryForQuoteField() {
        std::memset(this, 0, sizeof(QryForQuoteField));
    }

    QryForQuoteField(const CThostFtdcQryForQuoteField& f): CThostFtdcQryForQuoteField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTimeStart(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTimeStart,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTimeStart,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTimeStart() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTimeStart);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTimeStart);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTimeEnd(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTimeEnd,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTimeEnd,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTimeEnd() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTimeEnd);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTimeEnd);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct InputQuoteField: CThostFtdcInputQuoteField {

    InputQuoteField() {
        std::memset(this, 0, sizeof(InputQuoteField));
    }

    InputQuoteField(const CThostFtdcInputQuoteField& f): CThostFtdcInputQuoteField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setQuoteRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->QuoteRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->QuoteRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getQuoteRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->QuoteRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->QuoteRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAskOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AskOrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AskOrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAskOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AskOrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AskOrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBidOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BidOrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BidOrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBidOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BidOrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BidOrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setForQuoteSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ForQuoteSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ForQuoteSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getForQuoteSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ForQuoteSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ForQuoteSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InputQuoteActionField: CThostFtdcInputQuoteActionField {

    InputQuoteActionField() {
        std::memset(this, 0, sizeof(InputQuoteActionField));
    }

    InputQuoteActionField(const CThostFtdcInputQuoteActionField& f): CThostFtdcInputQuoteActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setQuoteRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->QuoteRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->QuoteRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getQuoteRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->QuoteRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->QuoteRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setQuoteSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->QuoteSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->QuoteSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getQuoteSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->QuoteSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->QuoteSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QuoteField: CThostFtdcQuoteField {

    QuoteField() {
        std::memset(this, 0, sizeof(QuoteField));
    }

    QuoteField(const CThostFtdcQuoteField& f): CThostFtdcQuoteField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setQuoteRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->QuoteRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->QuoteRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getQuoteRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->QuoteRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->QuoteRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setQuoteLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->QuoteLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->QuoteLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getQuoteLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->QuoteLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->QuoteLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setQuoteSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->QuoteSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->QuoteSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getQuoteSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->QuoteSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->QuoteSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCancelTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CancelTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CancelTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCancelTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CancelTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CancelTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClearingPartID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClearingPartID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClearingPartID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClearingPartID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClearingPartID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClearingPartID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAskOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AskOrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AskOrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAskOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AskOrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AskOrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBidOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BidOrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BidOrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBidOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BidOrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BidOrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->StatusMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActiveUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActiveUserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActiveUserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActiveUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActiveUserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActiveUserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAskOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AskOrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AskOrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAskOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AskOrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AskOrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBidOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BidOrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BidOrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBidOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BidOrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BidOrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setForQuoteSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ForQuoteSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ForQuoteSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getForQuoteSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ForQuoteSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ForQuoteSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QuoteActionField: CThostFtdcQuoteActionField {

    QuoteActionField() {
        std::memset(this, 0, sizeof(QuoteActionField));
    }

    QuoteActionField(const CThostFtdcQuoteActionField& f): CThostFtdcQuoteActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setQuoteRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->QuoteRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->QuoteRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getQuoteRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->QuoteRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->QuoteRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setQuoteSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->QuoteSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->QuoteSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getQuoteSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->QuoteSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->QuoteSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setQuoteLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->QuoteLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->QuoteLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getQuoteLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->QuoteLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->QuoteLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->StatusMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryQuoteField: CThostFtdcQryQuoteField {

    QryQuoteField() {
        std::memset(this, 0, sizeof(QryQuoteField));
    }

    QryQuoteField(const CThostFtdcQryQuoteField& f): CThostFtdcQryQuoteField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setQuoteSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->QuoteSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->QuoteSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getQuoteSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->QuoteSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->QuoteSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTimeStart(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTimeStart,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTimeStart,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTimeStart() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTimeStart);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTimeStart);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTimeEnd(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTimeEnd,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTimeEnd,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTimeEnd() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTimeEnd);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTimeEnd);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct ForQuoteRspField: CThostFtdcForQuoteRspField {

    ForQuoteRspField() {
        std::memset(this, 0, sizeof(ForQuoteRspField));
    }

    ForQuoteRspField(const CThostFtdcForQuoteRspField& f): CThostFtdcForQuoteRspField(f){}

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setForQuoteSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ForQuoteSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ForQuoteSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getForQuoteSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ForQuoteSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ForQuoteSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setForQuoteTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ForQuoteTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ForQuoteTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getForQuoteTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ForQuoteTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ForQuoteTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InputBatchOrderActionField: CThostFtdcInputBatchOrderActionField {

    InputBatchOrderActionField() {
        std::memset(this, 0, sizeof(InputBatchOrderActionField));
    }

    InputBatchOrderActionField(const CThostFtdcInputBatchOrderActionField& f): CThostFtdcInputBatchOrderActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct BatchOrderActionField: CThostFtdcBatchOrderActionField {

    BatchOrderActionField() {
        std::memset(this, 0, sizeof(BatchOrderActionField));
    }

    BatchOrderActionField(const CThostFtdcBatchOrderActionField& f): CThostFtdcBatchOrderActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->StatusMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct CombInstrumentGuardField: CThostFtdcCombInstrumentGuardField {

    CombInstrumentGuardField() {
        std::memset(this, 0, sizeof(CombInstrumentGuardField));
    }

    CombInstrumentGuardField(const CThostFtdcCombInstrumentGuardField& f): CThostFtdcCombInstrumentGuardField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
    ///
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryCombInstrumentGuardField: CThostFtdcQryCombInstrumentGuardField {

    QryCombInstrumentGuardField() {
        std::memset(this, 0, sizeof(QryCombInstrumentGuardField));
    }

    QryCombInstrumentGuardField(const CThostFtdcQryCombInstrumentGuardField& f): CThostFtdcQryCombInstrumentGuardField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InputCombActionField: CThostFtdcInputCombActionField {

    InputCombActionField() {
        std::memset(this, 0, sizeof(InputCombActionField));
    }

    InputCombActionField(const CThostFtdcInputCombActionField& f): CThostFtdcInputCombActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombActionRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombActionRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombActionRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombActionRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombActionRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombActionRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct CombActionField: CThostFtdcCombActionField {

    CombActionField() {
        std::memset(this, 0, sizeof(CombActionField));
    }

    CombActionField(const CThostFtdcCombActionField& f): CThostFtdcCombActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombActionRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombActionRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombActionRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombActionRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombActionRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombActionRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActionLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActionLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActionLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActionLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActionLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->StatusMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setComTradeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ComTradeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ComTradeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getComTradeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ComTradeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ComTradeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BranchID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BranchID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBranchID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BranchID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryCombActionField: CThostFtdcQryCombActionField {

    QryCombActionField() {
        std::memset(this, 0, sizeof(QryCombActionField));
    }

    QryCombActionField(const CThostFtdcQryCombActionField& f): CThostFtdcQryCombActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct ProductExchRateField: CThostFtdcProductExchRateField {

    ProductExchRateField() {
        std::memset(this, 0, sizeof(ProductExchRateField));
    }

    ProductExchRateField(const CThostFtdcProductExchRateField& f): CThostFtdcProductExchRateField(f){}

    void setProductID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setQuoteCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->QuoteCurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->QuoteCurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getQuoteCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->QuoteCurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->QuoteCurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryProductExchRateField: CThostFtdcQryProductExchRateField {

    QryProductExchRateField() {
        std::memset(this, 0, sizeof(QryProductExchRateField));
    }

    QryProductExchRateField(const CThostFtdcQryProductExchRateField& f): CThostFtdcQryProductExchRateField(f){}

    void setProductID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct MMOptionInstrCommRateField: CThostFtdcMMOptionInstrCommRateField {

    MMOptionInstrCommRateField() {
        std::memset(this, 0, sizeof(MMOptionInstrCommRateField));
    }

    MMOptionInstrCommRateField(const CThostFtdcMMOptionInstrCommRateField& f): CThostFtdcMMOptionInstrCommRateField(f){}

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryMMOptionInstrCommRateField: CThostFtdcQryMMOptionInstrCommRateField {

    QryMMOptionInstrCommRateField() {
        std::memset(this, 0, sizeof(QryMMOptionInstrCommRateField));
    }

    QryMMOptionInstrCommRateField(const CThostFtdcQryMMOptionInstrCommRateField& f): CThostFtdcQryMMOptionInstrCommRateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct MMInstrumentCommissionRateField: CThostFtdcMMInstrumentCommissionRateField {

    MMInstrumentCommissionRateField() {
        std::memset(this, 0, sizeof(MMInstrumentCommissionRateField));
    }

    MMInstrumentCommissionRateField(const CThostFtdcMMInstrumentCommissionRateField& f): CThostFtdcMMInstrumentCommissionRateField(f){}

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryMMInstrumentCommissionRateField: CThostFtdcQryMMInstrumentCommissionRateField {

    QryMMInstrumentCommissionRateField() {
        std::memset(this, 0, sizeof(QryMMInstrumentCommissionRateField));
    }

    QryMMInstrumentCommissionRateField(const CThostFtdcQryMMInstrumentCommissionRateField& f): CThostFtdcQryMMInstrumentCommissionRateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InstrumentOrderCommRateField: CThostFtdcInstrumentOrderCommRateField {

    InstrumentOrderCommRateField() {
        std::memset(this, 0, sizeof(InstrumentOrderCommRateField));
    }

    InstrumentOrderCommRateField(const CThostFtdcInstrumentOrderCommRateField& f): CThostFtdcInstrumentOrderCommRateField(f){}

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryInstrumentOrderCommRateField: CThostFtdcQryInstrumentOrderCommRateField {

    QryInstrumentOrderCommRateField() {
        std::memset(this, 0, sizeof(QryInstrumentOrderCommRateField));
    }

    QryInstrumentOrderCommRateField(const CThostFtdcQryInstrumentOrderCommRateField& f): CThostFtdcQryInstrumentOrderCommRateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct InputOptionSelfCloseField: CThostFtdcInputOptionSelfCloseField {

	InputOptionSelfCloseField() {
		std::memset(this, 0, sizeof(InputOptionSelfCloseField));
	}

	InputOptionSelfCloseField(const CThostFtdcInputOptionSelfCloseField& f): CThostFtdcInputOptionSelfCloseField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setOptionSelfCloseRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OptionSelfCloseRef,PyBytes_AsString(bytes));
#else
		std::strcpy(this->OptionSelfCloseRef,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getOptionSelfCloseRef() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->OptionSelfCloseRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->OptionSelfCloseRef);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AccountID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->CurrencyID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ClientID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->IPAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->MacAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct InputOptionSelfCloseActionField: CThostFtdcInputOptionSelfCloseActionField {

	InputOptionSelfCloseActionField() {
		std::memset(this, 0, sizeof(InputOptionSelfCloseActionField));
	}

	InputOptionSelfCloseActionField(const CThostFtdcInputOptionSelfCloseActionField& f): CThostFtdcInputOptionSelfCloseActionField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setOptionSelfCloseRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OptionSelfCloseRef,PyBytes_AsString(bytes));
#else
		std::strcpy(this->OptionSelfCloseRef,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getOptionSelfCloseRef() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->OptionSelfCloseRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->OptionSelfCloseRef);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setOptionSelfCloseSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OptionSelfCloseSysID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->OptionSelfCloseSysID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getOptionSelfCloseSysID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->OptionSelfCloseSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->OptionSelfCloseSysID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->IPAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->MacAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct OptionSelfCloseField: CThostFtdcOptionSelfCloseField {

	OptionSelfCloseField() {
		std::memset(this, 0, sizeof(OptionSelfCloseField));
	}

	OptionSelfCloseField(const CThostFtdcOptionSelfCloseField& f): CThostFtdcOptionSelfCloseField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setOptionSelfCloseRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OptionSelfCloseRef,PyBytes_AsString(bytes));
#else
		std::strcpy(this->OptionSelfCloseRef,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getOptionSelfCloseRef() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->OptionSelfCloseRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->OptionSelfCloseRef);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setOptionSelfCloseLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OptionSelfCloseLocalID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->OptionSelfCloseLocalID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getOptionSelfCloseLocalID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->OptionSelfCloseLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->OptionSelfCloseLocalID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ParticipantID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ClientID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->TraderID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
		std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->TradingDay);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setOptionSelfCloseSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OptionSelfCloseSysID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->OptionSelfCloseSysID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getOptionSelfCloseSysID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->OptionSelfCloseSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->OptionSelfCloseSysID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInsertDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertDate,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InsertDate,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInsertDate() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InsertDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InsertDate);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInsertTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTime,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InsertTime,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInsertTime() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InsertTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InsertTime);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCancelTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CancelTime,PyBytes_AsString(bytes));
#else
		std::strcpy(this->CancelTime,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCancelTime() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->CancelTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->CancelTime);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setClearingPartID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClearingPartID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ClearingPartID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getClearingPartID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ClearingPartID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ClearingPartID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
		std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->StatusMsg);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setActiveUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActiveUserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ActiveUserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getActiveUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ActiveUserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ActiveUserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BranchID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BranchID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBranchID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BranchID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AccountID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->CurrencyID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->IPAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->MacAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct OptionSelfCloseActionField: CThostFtdcOptionSelfCloseActionField {

	OptionSelfCloseActionField() {
		std::memset(this, 0, sizeof(OptionSelfCloseActionField));
	}

	OptionSelfCloseActionField(const CThostFtdcOptionSelfCloseActionField& f): CThostFtdcOptionSelfCloseActionField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setOptionSelfCloseRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OptionSelfCloseRef,PyBytes_AsString(bytes));
#else
		std::strcpy(this->OptionSelfCloseRef,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getOptionSelfCloseRef() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->OptionSelfCloseRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->OptionSelfCloseRef);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setOptionSelfCloseSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OptionSelfCloseSysID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->OptionSelfCloseSysID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getOptionSelfCloseSysID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->OptionSelfCloseSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->OptionSelfCloseSysID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setActionDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionDate,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ActionDate,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getActionDate() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ActionDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ActionDate);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setActionTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionTime,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ActionTime,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getActionTime() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ActionTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ActionTime);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->TraderID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setOptionSelfCloseLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OptionSelfCloseLocalID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->OptionSelfCloseLocalID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getOptionSelfCloseLocalID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->OptionSelfCloseLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->OptionSelfCloseLocalID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setActionLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActionLocalID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ActionLocalID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getActionLocalID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ActionLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ActionLocalID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ParticipantID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ClientID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
		std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->StatusMsg);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BranchID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BranchID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBranchID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BranchID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->IPAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->MacAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryOptionSelfCloseField: CThostFtdcQryOptionSelfCloseField {

	QryOptionSelfCloseField() {
		std::memset(this, 0, sizeof(QryOptionSelfCloseField));
	}

	QryOptionSelfCloseField(const CThostFtdcQryOptionSelfCloseField& f): CThostFtdcQryOptionSelfCloseField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setOptionSelfCloseSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OptionSelfCloseSysID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->OptionSelfCloseSysID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getOptionSelfCloseSysID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->OptionSelfCloseSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->OptionSelfCloseSysID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInsertTimeStart(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTimeStart,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InsertTimeStart,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInsertTimeStart() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InsertTimeStart);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InsertTimeStart);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInsertTimeEnd(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTimeEnd,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InsertTimeEnd,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInsertTimeEnd() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InsertTimeEnd);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InsertTimeEnd);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct InvestUnitField: CThostFtdcInvestUnitField {

	InvestUnitField() {
		std::memset(this, 0, sizeof(InvestUnitField));
	}

	InvestUnitField(const CThostFtdcInvestUnitField& f): CThostFtdcInvestUnitField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestorUnitName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorUnitName,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorUnitName,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorUnitName() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorUnitName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorUnitName);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestorGroupID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorGroupID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorGroupID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorGroupID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorGroupID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorGroupID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCommModelID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CommModelID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->CommModelID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCommModelID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->CommModelID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->CommModelID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setMarginModelID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MarginModelID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->MarginModelID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getMarginModelID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->MarginModelID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->MarginModelID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AccountID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->CurrencyID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryInvestUnitField: CThostFtdcQryInvestUnitField {

	QryInvestUnitField() {
		std::memset(this, 0, sizeof(QryInvestUnitField));
	}

	QryInvestUnitField(const CThostFtdcQryInvestUnitField& f): CThostFtdcQryInvestUnitField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct SecAgentCheckModeField: CThostFtdcSecAgentCheckModeField {

	SecAgentCheckModeField() {
		std::memset(this, 0, sizeof(SecAgentCheckModeField));
	}

	SecAgentCheckModeField(const CThostFtdcSecAgentCheckModeField& f): CThostFtdcSecAgentCheckModeField(f){}

	void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->CurrencyID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBrokerSecAgentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerSecAgentID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerSecAgentID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerSecAgentID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerSecAgentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerSecAgentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct SecAgentTradeInfoField: CThostFtdcSecAgentTradeInfoField {

	SecAgentTradeInfoField() {
		std::memset(this, 0, sizeof(SecAgentTradeInfoField));
	}

	SecAgentTradeInfoField(const CThostFtdcSecAgentTradeInfoField& f): CThostFtdcSecAgentTradeInfoField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBrokerSecAgentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerSecAgentID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerSecAgentID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerSecAgentID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerSecAgentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerSecAgentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setLongCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LongCustomerName,PyBytes_AsString(bytes));
#else
		std::strcpy(this->LongCustomerName,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getLongCustomerName() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->LongCustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->LongCustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InstrumentStatusField: CThostFtdcInstrumentStatusField {

    InstrumentStatusField() {
        std::memset(this, 0, sizeof(InstrumentStatusField));
    }

    InstrumentStatusField(const CThostFtdcInstrumentStatusField& f): CThostFtdcInstrumentStatusField(f){}

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setSettlementGroupID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->SettlementGroupID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->SettlementGroupID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getSettlementGroupID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->SettlementGroupID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->SettlementGroupID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setEnterTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->EnterTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->EnterTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getEnterTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->EnterTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->EnterTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryTransferBankField: CThostFtdcQryTransferBankField {

    QryTransferBankField() {
        std::memset(this, 0, sizeof(QryTransferBankField));
    }

    QryTransferBankField(const CThostFtdcQryTransferBankField& f): CThostFtdcQryTransferBankField(f){}

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBrchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBrchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBrchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBrchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBrchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBrchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct TransferBankField: CThostFtdcTransferBankField {

    TransferBankField() {
        std::memset(this, 0, sizeof(TransferBankField));
    }

    TransferBankField(const CThostFtdcTransferBankField& f): CThostFtdcTransferBankField(f){}

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBrchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBrchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBrchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBrchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBrchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBrchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryInvestorPositionDetailField: CThostFtdcQryInvestorPositionDetailField {

    QryInvestorPositionDetailField() {
        std::memset(this, 0, sizeof(QryInvestorPositionDetailField));
    }

    QryInvestorPositionDetailField(const CThostFtdcQryInvestorPositionDetailField& f): CThostFtdcQryInvestorPositionDetailField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct InvestorPositionDetailField: CThostFtdcInvestorPositionDetailField {

    InvestorPositionDetailField() {
        std::memset(this, 0, sizeof(InvestorPositionDetailField));
    }

    InvestorPositionDetailField(const CThostFtdcInvestorPositionDetailField& f): CThostFtdcInvestorPositionDetailField(f){}

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOpenDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OpenDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OpenDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOpenDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OpenDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OpenDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombInstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombInstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombInstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombInstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryNoticeField: CThostFtdcQryNoticeField {

    QryNoticeField() {
        std::memset(this, 0, sizeof(QryNoticeField));
    }

    QryNoticeField(const CThostFtdcQryNoticeField& f): CThostFtdcQryNoticeField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct NoticeField: CThostFtdcNoticeField {

    NoticeField() {
        std::memset(this, 0, sizeof(NoticeField));
    }

    NoticeField(const CThostFtdcNoticeField& f): CThostFtdcNoticeField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setContent(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Content,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Content,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getContent() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Content);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Content);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setSequenceLabel(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->SequenceLabel,PyBytes_AsString(bytes));
#else
        std::strcpy(this->SequenceLabel,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getSequenceLabel() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->SequenceLabel);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->SequenceLabel);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QrySettlementInfoConfirmField: CThostFtdcQrySettlementInfoConfirmField {

    QrySettlementInfoConfirmField() {
        std::memset(this, 0, sizeof(QrySettlementInfoConfirmField));
    }

    QrySettlementInfoConfirmField(const CThostFtdcQrySettlementInfoConfirmField& f): CThostFtdcQrySettlementInfoConfirmField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AccountID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->CurrencyID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct TradingAccountPasswordUpdateField: CThostFtdcTradingAccountPasswordUpdateField {

    TradingAccountPasswordUpdateField() {
        std::memset(this, 0, sizeof(TradingAccountPasswordUpdateField));
    }

    TradingAccountPasswordUpdateField(const CThostFtdcTradingAccountPasswordUpdateField& f): CThostFtdcTradingAccountPasswordUpdateField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOldPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OldPassword,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OldPassword,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOldPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OldPassword);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OldPassword);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setNewPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->NewPassword,PyBytes_AsString(bytes));
#else
        std::strcpy(this->NewPassword,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getNewPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->NewPassword);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->NewPassword);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryContractBankField: CThostFtdcQryContractBankField {

    QryContractBankField() {
        std::memset(this, 0, sizeof(QryContractBankField));
    }

    QryContractBankField(const CThostFtdcQryContractBankField& f): CThostFtdcQryContractBankField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBrchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBrchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBrchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBrchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBrchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBrchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ContractBankField: CThostFtdcContractBankField {

    ContractBankField() {
        std::memset(this, 0, sizeof(ContractBankField));
    }

    ContractBankField(const CThostFtdcContractBankField& f): CThostFtdcContractBankField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBrchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBrchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBrchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBrchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBrchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBrchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InvestorPositionCombineDetailField: CThostFtdcInvestorPositionCombineDetailField {

    InvestorPositionCombineDetailField() {
        std::memset(this, 0, sizeof(InvestorPositionCombineDetailField));
    }

    InvestorPositionCombineDetailField(const CThostFtdcInvestorPositionCombineDetailField& f): CThostFtdcInvestorPositionCombineDetailField(f){}

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOpenDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OpenDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OpenDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOpenDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OpenDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OpenDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setComTradeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ComTradeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ComTradeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getComTradeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ComTradeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ComTradeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombInstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombInstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombInstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombInstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct ParkedOrderField: CThostFtdcParkedOrderField {

    ParkedOrderField() {
        std::memset(this, 0, sizeof(ParkedOrderField));
    }

    ParkedOrderField(const CThostFtdcParkedOrderField& f): CThostFtdcParkedOrderField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombOffsetFlag(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombOffsetFlag,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombOffsetFlag,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombOffsetFlag() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombOffsetFlag);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombOffsetFlag);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombHedgeFlag(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombHedgeFlag,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombHedgeFlag,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombHedgeFlag() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombHedgeFlag);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombHedgeFlag);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setGTDDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->GTDDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->GTDDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getGTDDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->GTDDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->GTDDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParkedOrderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParkedOrderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParkedOrderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParkedOrderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParkedOrderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParkedOrderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setErrorMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ErrorMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ErrorMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getErrorMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ErrorMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ErrorMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ParkedOrderActionField: CThostFtdcParkedOrderActionField {

    ParkedOrderActionField() {
        std::memset(this, 0, sizeof(ParkedOrderActionField));
    }

    ParkedOrderActionField(const CThostFtdcParkedOrderActionField& f): CThostFtdcParkedOrderActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParkedOrderActionID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParkedOrderActionID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParkedOrderActionID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParkedOrderActionID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParkedOrderActionID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParkedOrderActionID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setErrorMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ErrorMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ErrorMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getErrorMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ErrorMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ErrorMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryParkedOrderField: CThostFtdcQryParkedOrderField {

    QryParkedOrderField() {
        std::memset(this, 0, sizeof(QryParkedOrderField));
    }

    QryParkedOrderField(const CThostFtdcQryParkedOrderField& f): CThostFtdcQryParkedOrderField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryParkedOrderActionField: CThostFtdcQryParkedOrderActionField {

    QryParkedOrderActionField() {
        std::memset(this, 0, sizeof(QryParkedOrderActionField));
    }

    QryParkedOrderActionField(const CThostFtdcQryParkedOrderActionField& f): CThostFtdcQryParkedOrderActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct RemoveParkedOrderField: CThostFtdcRemoveParkedOrderField {

    RemoveParkedOrderField() {
        std::memset(this, 0, sizeof(RemoveParkedOrderField));
    }

    RemoveParkedOrderField(const CThostFtdcRemoveParkedOrderField& f): CThostFtdcRemoveParkedOrderField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParkedOrderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParkedOrderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParkedOrderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParkedOrderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParkedOrderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParkedOrderID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct RemoveParkedOrderActionField: CThostFtdcRemoveParkedOrderActionField {

    RemoveParkedOrderActionField() {
        std::memset(this, 0, sizeof(RemoveParkedOrderActionField));
    }

    RemoveParkedOrderActionField(const CThostFtdcRemoveParkedOrderActionField& f): CThostFtdcRemoveParkedOrderActionField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParkedOrderActionID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParkedOrderActionID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParkedOrderActionID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParkedOrderActionID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParkedOrderActionID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParkedOrderActionID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryInvestorPositionCombineDetailField: CThostFtdcQryInvestorPositionCombineDetailField {

    QryInvestorPositionCombineDetailField() {
        std::memset(this, 0, sizeof(QryInvestorPositionCombineDetailField));
    }

    QryInvestorPositionCombineDetailField(const CThostFtdcQryInvestorPositionCombineDetailField& f): CThostFtdcQryInvestorPositionCombineDetailField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombInstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombInstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombInstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombInstrumentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct TradingNoticeInfoField: CThostFtdcTradingNoticeInfoField {

    TradingNoticeInfoField() {
        std::memset(this, 0, sizeof(TradingNoticeInfoField));
    }

    TradingNoticeInfoField(const CThostFtdcTradingNoticeInfoField& f): CThostFtdcTradingNoticeInfoField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setSendTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->SendTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->SendTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getSendTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->SendTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->SendTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setFieldContent(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->FieldContent,PyBytes_AsString(bytes));
#else
        std::strcpy(this->FieldContent,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getFieldContent() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->FieldContent);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->FieldContent);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct TradingNoticeField: CThostFtdcTradingNoticeField {

    TradingNoticeField() {
        std::memset(this, 0, sizeof(TradingNoticeField));
    }

    TradingNoticeField(const CThostFtdcTradingNoticeField& f): CThostFtdcTradingNoticeField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setSendTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->SendTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->SendTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getSendTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->SendTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->SendTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setFieldContent(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->FieldContent,PyBytes_AsString(bytes));
#else
        std::strcpy(this->FieldContent,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getFieldContent() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->FieldContent);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->FieldContent);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryTradingNoticeField: CThostFtdcQryTradingNoticeField {

    QryTradingNoticeField() {
        std::memset(this, 0, sizeof(QryTradingNoticeField));
    }

    QryTradingNoticeField(const CThostFtdcQryTradingNoticeField& f): CThostFtdcQryTradingNoticeField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ErrorConditionalOrderField: CThostFtdcErrorConditionalOrderField {

    ErrorConditionalOrderField() {
        std::memset(this, 0, sizeof(ErrorConditionalOrderField));
    }

    ErrorConditionalOrderField(const CThostFtdcErrorConditionalOrderField& f): CThostFtdcErrorConditionalOrderField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderRef(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderRef,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderRef,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderRef() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderRef);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderRef);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombOffsetFlag(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombOffsetFlag,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombOffsetFlag,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombOffsetFlag() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombOffsetFlag);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombOffsetFlag);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCombHedgeFlag(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CombHedgeFlag,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CombHedgeFlag,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCombHedgeFlag() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CombHedgeFlag);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CombHedgeFlag);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setGTDDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->GTDDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->GTDDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getGTDDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->GTDDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->GTDDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBusinessUnit(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BusinessUnit,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BusinessUnit,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBusinessUnit() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BusinessUnit);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BusinessUnit);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderLocalID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderLocalID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderLocalID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderLocalID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderLocalID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderLocalID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClientID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClientID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClientID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClientID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClientID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeInstID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeInstID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeInstID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeInstID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeInstID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeInstID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInsertTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InsertTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InsertTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInsertTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InsertTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InsertTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActiveTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActiveTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActiveTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActiveTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActiveTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActiveTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setSuspendTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->SuspendTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->SuspendTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getSuspendTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->SuspendTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->SuspendTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUpdateTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UpdateTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UpdateTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUpdateTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UpdateTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UpdateTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCancelTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CancelTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CancelTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCancelTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CancelTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CancelTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActiveTraderID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActiveTraderID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActiveTraderID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActiveTraderID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActiveTraderID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActiveTraderID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setClearingPartID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClearingPartID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ClearingPartID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getClearingPartID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ClearingPartID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ClearingPartID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setStatusMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->StatusMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->StatusMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getStatusMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->StatusMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->StatusMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setActiveUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ActiveUserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ActiveUserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getActiveUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ActiveUserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ActiveUserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setRelativeOrderSysID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->RelativeOrderSysID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->RelativeOrderSysID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getRelativeOrderSysID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->RelativeOrderSysID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->RelativeOrderSysID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setErrorMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ErrorMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ErrorMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getErrorMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ErrorMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ErrorMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IPAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IPAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIPAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IPAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MacAddress);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryBrokerTradingParamsField: CThostFtdcQryBrokerTradingParamsField {

    QryBrokerTradingParamsField() {
        std::memset(this, 0, sizeof(QryBrokerTradingParamsField));
    }

    QryBrokerTradingParamsField(const CThostFtdcQryBrokerTradingParamsField& f): CThostFtdcQryBrokerTradingParamsField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AccountID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct BrokerTradingParamsField: CThostFtdcBrokerTradingParamsField {

    BrokerTradingParamsField() {
        std::memset(this, 0, sizeof(BrokerTradingParamsField));
    }

    BrokerTradingParamsField(const CThostFtdcBrokerTradingParamsField& f): CThostFtdcBrokerTradingParamsField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryBrokerTradingAlgosField: CThostFtdcQryBrokerTradingAlgosField {

    QryBrokerTradingAlgosField() {
        std::memset(this, 0, sizeof(QryBrokerTradingAlgosField));
    }

    QryBrokerTradingAlgosField(const CThostFtdcQryBrokerTradingAlgosField& f): CThostFtdcQryBrokerTradingAlgosField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct BrokerTradingAlgosField: CThostFtdcBrokerTradingAlgosField {

    BrokerTradingAlgosField() {
        std::memset(this, 0, sizeof(BrokerTradingAlgosField));
    }

    BrokerTradingAlgosField(const CThostFtdcBrokerTradingAlgosField& f): CThostFtdcBrokerTradingAlgosField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct CFMMCTradingAccountKeyField: CThostFtdcCFMMCTradingAccountKeyField {

    CFMMCTradingAccountKeyField() {
        std::memset(this, 0, sizeof(CFMMCTradingAccountKeyField));
    }

    CFMMCTradingAccountKeyField(const CThostFtdcCFMMCTradingAccountKeyField& f): CThostFtdcCFMMCTradingAccountKeyField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrentKey(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrentKey,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrentKey,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrentKey() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrentKey);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrentKey);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryCFMMCTradingAccountKeyField: CThostFtdcQryCFMMCTradingAccountKeyField {

    QryCFMMCTradingAccountKeyField() {
        std::memset(this, 0, sizeof(QryCFMMCTradingAccountKeyField));
    }

    QryCFMMCTradingAccountKeyField(const CThostFtdcQryCFMMCTradingAccountKeyField& f): CThostFtdcQryCFMMCTradingAccountKeyField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct EWarrantOffsetField: CThostFtdcEWarrantOffsetField {

    EWarrantOffsetField() {
        std::memset(this, 0, sizeof(EWarrantOffsetField));
    }

    EWarrantOffsetField(const CThostFtdcEWarrantOffsetField& f): CThostFtdcEWarrantOffsetField(f){}

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryEWarrantOffsetField: CThostFtdcQryEWarrantOffsetField {

    QryEWarrantOffsetField() {
        std::memset(this, 0, sizeof(QryEWarrantOffsetField));
    }

    QryEWarrantOffsetField(const CThostFtdcQryEWarrantOffsetField& f): CThostFtdcQryEWarrantOffsetField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInstrumentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InstrumentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InstrumentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInstrumentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InstrumentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InstrumentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QryInvestorProductGroupMarginField: CThostFtdcQryInvestorProductGroupMarginField {

    QryInvestorProductGroupMarginField() {
        std::memset(this, 0, sizeof(QryInvestorProductGroupMarginField));
    }

    QryInvestorProductGroupMarginField(const CThostFtdcQryInvestorProductGroupMarginField& f): CThostFtdcQryInvestorProductGroupMarginField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setProductGroupID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductGroupID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductGroupID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductGroupID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductGroupID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductGroupID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct InvestorProductGroupMarginField: CThostFtdcInvestorProductGroupMarginField {

    InvestorProductGroupMarginField() {
        std::memset(this, 0, sizeof(InvestorProductGroupMarginField));
    }

    InvestorProductGroupMarginField(const CThostFtdcInvestorProductGroupMarginField& f): CThostFtdcInvestorProductGroupMarginField(f){}

    void setProductGroupID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductGroupID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductGroupID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductGroupID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductGroupID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductGroupID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
	void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ExchangeID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QueryCFMMCTradingAccountTokenField: CThostFtdcQueryCFMMCTradingAccountTokenField {

    QueryCFMMCTradingAccountTokenField() {
        std::memset(this, 0, sizeof(QueryCFMMCTradingAccountTokenField));
    }

    QueryCFMMCTradingAccountTokenField(const CThostFtdcQueryCFMMCTradingAccountTokenField& f): CThostFtdcQueryCFMMCTradingAccountTokenField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestUnitID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestUnitID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestUnitID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestUnitID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestUnitID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestUnitID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct CFMMCTradingAccountTokenField: CThostFtdcCFMMCTradingAccountTokenField {

    CFMMCTradingAccountTokenField() {
        std::memset(this, 0, sizeof(CFMMCTradingAccountTokenField));
    }

    CFMMCTradingAccountTokenField(const CThostFtdcCFMMCTradingAccountTokenField& f): CThostFtdcCFMMCTradingAccountTokenField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setParticipantID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ParticipantID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ParticipantID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getParticipantID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ParticipantID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ParticipantID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setToken(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Token,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Token,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getToken() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Token);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Token);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryProductGroupField: CThostFtdcQryProductGroupField {

    QryProductGroupField() {
        std::memset(this, 0, sizeof(QryProductGroupField));
    }

    QryProductGroupField(const CThostFtdcQryProductGroupField& f): CThostFtdcQryProductGroupField(f){}

    void setProductID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ProductGroupField: CThostFtdcProductGroupField {

    ProductGroupField() {
        std::memset(this, 0, sizeof(ProductGroupField));
    }

    ProductGroupField(const CThostFtdcProductGroupField& f): CThostFtdcProductGroupField(f){}

    void setProductID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setProductGroupID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProductGroupID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ProductGroupID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getProductGroupID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ProductGroupID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ProductGroupID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct BulletinField: CThostFtdcBulletinField {

    BulletinField() {
        std::memset(this, 0, sizeof(BulletinField));
    }

    BulletinField(const CThostFtdcBulletinField& f): CThostFtdcBulletinField(f){}

    void setExchangeID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ExchangeID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ExchangeID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getExchangeID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ExchangeID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ExchangeID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setNewsType(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->NewsType,PyBytes_AsString(bytes));
#else
        std::strcpy(this->NewsType,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getNewsType() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->NewsType);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->NewsType);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setSendTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->SendTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->SendTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getSendTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->SendTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->SendTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAbstract(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Abstract,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Abstract,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAbstract() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Abstract);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Abstract);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setComeFrom(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ComeFrom,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ComeFrom,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getComeFrom() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ComeFrom);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ComeFrom);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setContent(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Content,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Content,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getContent() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Content);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Content);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setURLLink(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->URLLink,PyBytes_AsString(bytes));
#else
        std::strcpy(this->URLLink,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getURLLink() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->URLLink);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->URLLink);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMarketID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MarketID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MarketID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMarketID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MarketID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MarketID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ReqTransferField: CThostFtdcReqTransferField {

    ReqTransferField() {
        std::memset(this, 0, sizeof(ReqTransferField));
    }

    ReqTransferField(const CThostFtdcReqTransferField& f): CThostFtdcReqTransferField(f){}

    void setTradeCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankPassWord(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankPassWord,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankPassWord,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankPassWord() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankPassWord);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankPassWord);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Password);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMessage(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Message,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Message,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMessage() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Message);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Message);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDigest(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Digest,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Digest,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDigest() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Digest);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Digest);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDeviceID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->DeviceID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->DeviceID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDeviceID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->DeviceID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->DeviceID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerIDByBank(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerIDByBank,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerIDByBank,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerIDByBank() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerIDByBank);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerIDByBank);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSecuAcc(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSecuAcc,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSecuAcc,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSecuAcc() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSecuAcc);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSecuAcc);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOperNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OperNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OperNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOperNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OperNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OperNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLongCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LongCustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LongCustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLongCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LongCustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LongCustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct RspTransferField: CThostFtdcRspTransferField {

    RspTransferField() {
        std::memset(this, 0, sizeof(RspTransferField));
    }

    RspTransferField(const CThostFtdcRspTransferField& f): CThostFtdcRspTransferField(f){}

    void setTradeCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankPassWord(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankPassWord,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankPassWord,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankPassWord() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankPassWord);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankPassWord);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Password);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMessage(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Message,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Message,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMessage() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Message);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Message);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDigest(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Digest,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Digest,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDigest() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Digest);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Digest);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDeviceID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->DeviceID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->DeviceID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDeviceID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->DeviceID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->DeviceID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerIDByBank(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerIDByBank,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerIDByBank,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerIDByBank() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerIDByBank);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerIDByBank);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSecuAcc(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSecuAcc,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSecuAcc,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSecuAcc() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSecuAcc);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSecuAcc);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOperNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OperNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OperNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOperNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OperNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OperNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setErrorMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ErrorMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ErrorMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getErrorMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ErrorMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ErrorMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLongCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LongCustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LongCustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLongCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LongCustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LongCustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ReqRepealField: CThostFtdcReqRepealField {

    ReqRepealField() {
        std::memset(this, 0, sizeof(ReqRepealField));
    }

    ReqRepealField(const CThostFtdcReqRepealField& f): CThostFtdcReqRepealField(f){}

    void setBankRepealSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankRepealSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankRepealSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankRepealSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankRepealSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankRepealSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankPassWord(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankPassWord,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankPassWord,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankPassWord() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankPassWord);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankPassWord);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Password);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMessage(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Message,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Message,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMessage() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Message);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Message);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDigest(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Digest,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Digest,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDigest() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Digest);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Digest);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDeviceID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->DeviceID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->DeviceID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDeviceID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->DeviceID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->DeviceID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerIDByBank(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerIDByBank,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerIDByBank,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerIDByBank() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerIDByBank);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerIDByBank);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSecuAcc(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSecuAcc,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSecuAcc,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSecuAcc() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSecuAcc);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSecuAcc);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOperNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OperNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OperNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOperNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OperNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OperNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLongCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LongCustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LongCustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLongCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LongCustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LongCustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct RspRepealField: CThostFtdcRspRepealField {

    RspRepealField() {
        std::memset(this, 0, sizeof(RspRepealField));
    }

    RspRepealField(const CThostFtdcRspRepealField& f): CThostFtdcRspRepealField(f){}

    void setBankRepealSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankRepealSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankRepealSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankRepealSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankRepealSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankRepealSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankPassWord(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankPassWord,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankPassWord,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankPassWord() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankPassWord);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankPassWord);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Password);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMessage(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Message,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Message,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMessage() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Message);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Message);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDigest(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Digest,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Digest,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDigest() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Digest);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Digest);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDeviceID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->DeviceID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->DeviceID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDeviceID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->DeviceID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->DeviceID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerIDByBank(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerIDByBank,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerIDByBank,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerIDByBank() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerIDByBank);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerIDByBank);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSecuAcc(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSecuAcc,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSecuAcc,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSecuAcc() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSecuAcc);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSecuAcc);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOperNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OperNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OperNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOperNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OperNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OperNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setErrorMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ErrorMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ErrorMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getErrorMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ErrorMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ErrorMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLongCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LongCustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LongCustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLongCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LongCustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LongCustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ReqQueryAccountField: CThostFtdcReqQueryAccountField {

    ReqQueryAccountField() {
        std::memset(this, 0, sizeof(ReqQueryAccountField));
    }

    ReqQueryAccountField(const CThostFtdcReqQueryAccountField& f): CThostFtdcReqQueryAccountField(f){}

    void setTradeCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankPassWord(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankPassWord,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankPassWord,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankPassWord() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankPassWord);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankPassWord);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Password);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDigest(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Digest,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Digest,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDigest() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Digest);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Digest);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDeviceID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->DeviceID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->DeviceID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDeviceID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->DeviceID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->DeviceID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerIDByBank(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerIDByBank,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerIDByBank,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerIDByBank() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerIDByBank);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerIDByBank);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSecuAcc(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSecuAcc,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSecuAcc,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSecuAcc() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSecuAcc);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSecuAcc);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOperNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OperNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OperNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOperNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OperNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OperNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLongCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LongCustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LongCustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLongCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LongCustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LongCustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct NotifyQueryAccountField: CThostFtdcNotifyQueryAccountField {

    NotifyQueryAccountField() {
        std::memset(this, 0, sizeof(NotifyQueryAccountField));
    }

    NotifyQueryAccountField(const CThostFtdcNotifyQueryAccountField& f): CThostFtdcNotifyQueryAccountField(f){}

    void setTradeCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankPassWord(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankPassWord,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankPassWord,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankPassWord() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankPassWord);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankPassWord);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Password);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDigest(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Digest,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Digest,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDigest() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Digest);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Digest);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDeviceID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->DeviceID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->DeviceID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDeviceID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->DeviceID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->DeviceID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerIDByBank(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerIDByBank,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerIDByBank,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerIDByBank() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerIDByBank);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerIDByBank);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSecuAcc(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSecuAcc,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSecuAcc,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSecuAcc() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSecuAcc);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSecuAcc);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOperNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OperNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OperNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOperNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OperNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OperNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setErrorMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ErrorMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ErrorMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getErrorMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ErrorMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ErrorMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLongCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LongCustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LongCustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLongCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LongCustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LongCustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct TransferSerialField: CThostFtdcTransferSerialField {

    TransferSerialField() {
        std::memset(this, 0, sizeof(TransferSerialField));
    }

    TransferSerialField(const CThostFtdcTransferSerialField& f): CThostFtdcTransferSerialField(f){}

    void setTradeDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->InvestorID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOperatorCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OperatorCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OperatorCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOperatorCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OperatorCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OperatorCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankNewAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankNewAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankNewAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankNewAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankNewAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankNewAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setErrorMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ErrorMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ErrorMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getErrorMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ErrorMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ErrorMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryTransferSerialField: CThostFtdcQryTransferSerialField {

    QryTransferSerialField() {
        std::memset(this, 0, sizeof(QryTransferSerialField));
    }

    QryTransferSerialField(const CThostFtdcQryTransferSerialField& f): CThostFtdcQryTransferSerialField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QryAccountregisterField: CThostFtdcQryAccountregisterField {

    QryAccountregisterField() {
        std::memset(this, 0, sizeof(QryAccountregisterField));
    }

    QryAccountregisterField(const CThostFtdcQryAccountregisterField& f): CThostFtdcQryAccountregisterField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct AccountregisterField: CThostFtdcAccountregisterField {

    AccountregisterField() {
        std::memset(this, 0, sizeof(AccountregisterField));
    }

    AccountregisterField(const CThostFtdcAccountregisterField& f): CThostFtdcAccountregisterField(f){}

    void setTradeDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setRegDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->RegDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->RegDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getRegDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->RegDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->RegDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOutDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OutDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OutDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOutDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OutDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OutDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLongCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LongCustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LongCustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLongCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LongCustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LongCustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct OpenAccountField: CThostFtdcOpenAccountField {

    OpenAccountField() {
        std::memset(this, 0, sizeof(OpenAccountField));
    }

    OpenAccountField(const CThostFtdcOpenAccountField& f): CThostFtdcOpenAccountField(f){}

    void setTradeCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCountryCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CountryCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CountryCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCountryCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CountryCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CountryCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Address,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Address,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Address);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Address);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setZipCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ZipCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ZipCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getZipCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ZipCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ZipCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTelephone(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Telephone,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Telephone,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTelephone() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Telephone);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Telephone);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMobilePhone(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MobilePhone,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MobilePhone,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMobilePhone() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MobilePhone);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MobilePhone);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setFax(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Fax,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Fax,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getFax() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Fax);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Fax);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setEMail(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->EMail,PyBytes_AsString(bytes));
#else
        std::strcpy(this->EMail,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getEMail() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->EMail);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->EMail);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankPassWord(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankPassWord,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankPassWord,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankPassWord() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankPassWord);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankPassWord);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Password);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDigest(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Digest,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Digest,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDigest() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Digest);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Digest);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDeviceID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->DeviceID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->DeviceID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDeviceID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->DeviceID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->DeviceID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerIDByBank(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerIDByBank,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerIDByBank,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerIDByBank() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerIDByBank);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerIDByBank);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSecuAcc(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSecuAcc,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSecuAcc,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSecuAcc() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSecuAcc);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSecuAcc);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOperNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OperNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OperNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOperNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OperNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OperNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setErrorMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ErrorMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ErrorMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getErrorMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ErrorMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ErrorMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLongCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LongCustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LongCustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLongCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LongCustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LongCustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct CancelAccountField: CThostFtdcCancelAccountField {

    CancelAccountField() {
        std::memset(this, 0, sizeof(CancelAccountField));
    }

    CancelAccountField(const CThostFtdcCancelAccountField& f): CThostFtdcCancelAccountField(f){}

    void setTradeCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCountryCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CountryCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CountryCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCountryCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CountryCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CountryCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Address,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Address,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Address);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Address);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setZipCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ZipCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ZipCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getZipCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ZipCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ZipCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTelephone(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Telephone,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Telephone,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTelephone() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Telephone);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Telephone);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMobilePhone(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MobilePhone,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MobilePhone,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMobilePhone() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MobilePhone);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MobilePhone);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setFax(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Fax,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Fax,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getFax() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Fax);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Fax);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setEMail(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->EMail,PyBytes_AsString(bytes));
#else
        std::strcpy(this->EMail,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getEMail() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->EMail);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->EMail);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankPassWord(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankPassWord,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankPassWord,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankPassWord() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankPassWord);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankPassWord);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Password);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDigest(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Digest,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Digest,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDigest() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Digest);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Digest);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDeviceID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->DeviceID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->DeviceID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDeviceID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->DeviceID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->DeviceID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerIDByBank(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerIDByBank,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerIDByBank,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerIDByBank() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerIDByBank);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerIDByBank);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSecuAcc(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSecuAcc,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSecuAcc,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSecuAcc() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSecuAcc);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSecuAcc);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setOperNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OperNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->OperNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getOperNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->OperNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->OperNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setErrorMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ErrorMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ErrorMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getErrorMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ErrorMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ErrorMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLongCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LongCustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LongCustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLongCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LongCustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LongCustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct ChangeAccountField: CThostFtdcChangeAccountField {

    ChangeAccountField() {
        std::memset(this, 0, sizeof(ChangeAccountField));
    }

    ChangeAccountField(const CThostFtdcChangeAccountField& f): CThostFtdcChangeAccountField(f){}

    void setTradeCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerBranchID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerBranchID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerBranchID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerBranchID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerBranchID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerBranchID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeDate(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeDate,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeDate,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeDate() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeDate);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeDate);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradeTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradeTime,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradeTime,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradeTime() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradeTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradeTime);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankSerial(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankSerial,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankSerial,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankSerial() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankSerial);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankSerial);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
        std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->TradingDay);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setIdentifiedCardNo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->IdentifiedCardNo,PyBytes_AsString(bytes));
#else
        std::strcpy(this->IdentifiedCardNo,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getIdentifiedCardNo() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->IdentifiedCardNo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->IdentifiedCardNo);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCountryCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CountryCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CountryCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCountryCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CountryCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CountryCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Address,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Address,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAddress() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Address);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Address);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setZipCode(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ZipCode,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ZipCode,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getZipCode() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ZipCode);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ZipCode);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setTelephone(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Telephone,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Telephone,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getTelephone() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Telephone);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Telephone);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setMobilePhone(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MobilePhone,PyBytes_AsString(bytes));
#else
        std::strcpy(this->MobilePhone,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getMobilePhone() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->MobilePhone);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->MobilePhone);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setFax(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Fax,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Fax,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getFax() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Fax);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Fax);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setEMail(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->EMail,PyBytes_AsString(bytes));
#else
        std::strcpy(this->EMail,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getEMail() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->EMail);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->EMail);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBankPassWord(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BankPassWord,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BankPassWord,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBankPassWord() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BankPassWord);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BankPassWord);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setNewBankAccount(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->NewBankAccount,PyBytes_AsString(bytes));
#else
        std::strcpy(this->NewBankAccount,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getNewBankAccount() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->NewBankAccount);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->NewBankAccount);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setNewBankPassWord(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->NewBankPassWord,PyBytes_AsString(bytes));
#else
        std::strcpy(this->NewBankPassWord,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getNewBankPassWord() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->NewBankPassWord);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->NewBankPassWord);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Password);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerIDByBank(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerIDByBank,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerIDByBank,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerIDByBank() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerIDByBank);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerIDByBank);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setDigest(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Digest,PyBytes_AsString(bytes));
#else
        std::strcpy(this->Digest,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getDigest() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->Digest);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->Digest);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setErrorMsg(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ErrorMsg,PyBytes_AsString(bytes));
#else
        std::strcpy(this->ErrorMsg,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getErrorMsg() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->ErrorMsg);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->ErrorMsg);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setLongCustomerName(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LongCustomerName,PyBytes_AsString(bytes));
#else
        std::strcpy(this->LongCustomerName,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getLongCustomerName() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->LongCustomerName);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->LongCustomerName);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct SecAgentACIDMapField: CThostFtdcSecAgentACIDMapField {

    SecAgentACIDMapField() {
        std::memset(this, 0, sizeof(SecAgentACIDMapField));
    }

    SecAgentACIDMapField(const CThostFtdcSecAgentACIDMapField& f): CThostFtdcSecAgentACIDMapField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setBrokerSecAgentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerSecAgentID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerSecAgentID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerSecAgentID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerSecAgentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerSecAgentID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QrySecAgentACIDMapField: CThostFtdcQrySecAgentACIDMapField {

    QrySecAgentACIDMapField() {
        std::memset(this, 0, sizeof(QrySecAgentACIDMapField));
    }

    QrySecAgentACIDMapField(const CThostFtdcQrySecAgentACIDMapField& f): CThostFtdcQrySecAgentACIDMapField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setAccountID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->AccountID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->AccountID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getAccountID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->AccountID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->AccountID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setCurrencyID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CurrencyID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->CurrencyID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getCurrencyID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->CurrencyID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->CurrencyID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct FensUserInfoField: CThostFtdcFensUserInfoField {

    FensUserInfoField() {
        std::memset(this, 0, sizeof(FensUserInfoField));
    }

    FensUserInfoField(const CThostFtdcFensUserInfoField& f): CThostFtdcFensUserInfoField(f){}

    void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->BrokerID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }

    void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
        std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
    }
    boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
        PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
        PyObject *str = PyString_FromString(this->UserID);
#endif
        return boost::python::object(boost::python::handle<>(str));
    }
};

struct QrySecAgentCheckModeField: CThostFtdcQrySecAgentCheckModeField {

	QrySecAgentCheckModeField() {
		std::memset(this, 0, sizeof(QrySecAgentCheckModeField));
	}

	QrySecAgentCheckModeField(const CThostFtdcQrySecAgentCheckModeField& f): CThostFtdcQrySecAgentCheckModeField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInvestorID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InvestorID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InvestorID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInvestorID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InvestorID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InvestorID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct QrySecAgentTradeInfoField: CThostFtdcQrySecAgentTradeInfoField {

	QrySecAgentTradeInfoField() {
		std::memset(this, 0, sizeof(QrySecAgentTradeInfoField));
	}

	QrySecAgentTradeInfoField(const CThostFtdcQrySecAgentTradeInfoField& f): CThostFtdcQrySecAgentTradeInfoField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBrokerSecAgentID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerSecAgentID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerSecAgentID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerSecAgentID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerSecAgentID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerSecAgentID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct UserSystemInfoField: CThostFtdcUserSystemInfoField {

	UserSystemInfoField() {
		std::memset(this, 0, sizeof(UserSystemInfoField));
	}

	UserSystemInfoField(const CThostFtdcUserSystemInfoField& f): CThostFtdcUserSystemInfoField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setClientSystemInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientSystemInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ClientSystemInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getClientSystemInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ClientSystemInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ClientSystemInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setClientPublicIP(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientPublicIP,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ClientPublicIP,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getClientPublicIP() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ClientPublicIP);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ClientPublicIP);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setClientLoginTime(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientLoginTime,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ClientLoginTime,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getClientLoginTime() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ClientLoginTime);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ClientLoginTime);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setClientAppID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientAppID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ClientAppID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getClientAppID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ClientAppID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ClientAppID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct ReqUserAuthMethodField: CThostFtdcReqUserAuthMethodField {

	ReqUserAuthMethodField() {
		std::memset(this, 0, sizeof(ReqUserAuthMethodField));
	}

	ReqUserAuthMethodField(const CThostFtdcReqUserAuthMethodField& f): CThostFtdcReqUserAuthMethodField(f){}

	void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
		std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->TradingDay);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct RspUserAuthMethodField: CThostFtdcRspUserAuthMethodField {

	RspUserAuthMethodField() {
		std::memset(this, 0, sizeof(RspUserAuthMethodField));
	}

	RspUserAuthMethodField(const CThostFtdcRspUserAuthMethodField& f): CThostFtdcRspUserAuthMethodField(f){}
};

struct ReqGenUserCaptchaField: CThostFtdcReqGenUserCaptchaField {

	ReqGenUserCaptchaField() {
		std::memset(this, 0, sizeof(ReqGenUserCaptchaField));
	}

	ReqGenUserCaptchaField(const CThostFtdcReqGenUserCaptchaField& f): CThostFtdcReqGenUserCaptchaField(f){}

	void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
		std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->TradingDay);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct RspGenUserCaptchaField: CThostFtdcRspGenUserCaptchaField {

	RspGenUserCaptchaField() {
		std::memset(this, 0, sizeof(RspGenUserCaptchaField));
	}

	RspGenUserCaptchaField(const CThostFtdcRspGenUserCaptchaField& f): CThostFtdcRspGenUserCaptchaField(f){}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCaptchaInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->CaptchaInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->CaptchaInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCaptchaInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->CaptchaInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->CaptchaInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct ReqGenUserTextField: CThostFtdcReqGenUserTextField {

	ReqGenUserTextField() {
		std::memset(this, 0, sizeof(ReqGenUserTextField));
	}

	ReqGenUserTextField(const CThostFtdcReqGenUserTextField& f): CThostFtdcReqGenUserTextField(f){}

	void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
		std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->TradingDay);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct RspGenUserTextField: CThostFtdcRspGenUserTextField {

	RspGenUserTextField() {
		std::memset(this, 0, sizeof(RspGenUserTextField));
	}

	RspGenUserTextField(const CThostFtdcRspGenUserTextField& f): CThostFtdcRspGenUserTextField(f){}
};

struct ReqUserLoginWithCaptchaField: CThostFtdcReqUserLoginWithCaptchaField {

	ReqUserLoginWithCaptchaField() {
		std::memset(this, 0, sizeof(ReqUserLoginWithCaptchaField));
	}

	ReqUserLoginWithCaptchaField(const CThostFtdcReqUserLoginWithCaptchaField& f): CThostFtdcReqUserLoginWithCaptchaField(f){}

	void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
		std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->TradingDay);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
		std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->Password);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInterfaceProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InterfaceProductInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InterfaceProductInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInterfaceProductInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InterfaceProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InterfaceProductInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setProtocolInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProtocolInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ProtocolInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getProtocolInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ProtocolInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ProtocolInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->MacAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setClientIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientIPAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ClientIPAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getClientIPAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ClientIPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ClientIPAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setLoginRemark(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LoginRemark,PyBytes_AsString(bytes));
#else
		std::strcpy(this->LoginRemark,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getLoginRemark() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->LoginRemark);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->LoginRemark);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setCaptcha(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Captcha,PyBytes_AsString(bytes));
#else
		std::strcpy(this->Captcha,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getCaptcha() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->Captcha);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->Captcha);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct ReqUserLoginWithTextField: CThostFtdcReqUserLoginWithTextField {

	ReqUserLoginWithTextField() {
		std::memset(this, 0, sizeof(ReqUserLoginWithTextField));
	}

	ReqUserLoginWithTextField(const CThostFtdcReqUserLoginWithTextField& f): CThostFtdcReqUserLoginWithTextField(f){}

	void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
		std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->TradingDay);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
		std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->Password);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInterfaceProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InterfaceProductInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InterfaceProductInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInterfaceProductInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InterfaceProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InterfaceProductInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setProtocolInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProtocolInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ProtocolInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getProtocolInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ProtocolInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ProtocolInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->MacAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setClientIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientIPAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ClientIPAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getClientIPAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ClientIPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ClientIPAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setLoginRemark(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LoginRemark,PyBytes_AsString(bytes));
#else
		std::strcpy(this->LoginRemark,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getLoginRemark() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->LoginRemark);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->LoginRemark);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setText(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Text,PyBytes_AsString(bytes));
#else
		std::strcpy(this->Text,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getText() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->Text);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->Text);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

struct ReqUserLoginWithOTPField: CThostFtdcReqUserLoginWithOTPField {

	ReqUserLoginWithOTPField() {
		std::memset(this, 0, sizeof(ReqUserLoginWithOTPField));
	}

	ReqUserLoginWithOTPField(const CThostFtdcReqUserLoginWithOTPField& f): CThostFtdcReqUserLoginWithOTPField(f){}

	void setTradingDay(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->TradingDay,PyBytes_AsString(bytes));
#else
		std::strcpy(this->TradingDay,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getTradingDay() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->TradingDay);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->TradingDay);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setBrokerID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->BrokerID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->BrokerID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getBrokerID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->BrokerID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->BrokerID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserID(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserID,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserID,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserID() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserID);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserID);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->Password,PyBytes_AsString(bytes));
#else
		std::strcpy(this->Password,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getPassword() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->Password);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->Password);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setUserProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->UserProductInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->UserProductInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getUserProductInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->UserProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->UserProductInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setInterfaceProductInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->InterfaceProductInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->InterfaceProductInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getInterfaceProductInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->InterfaceProductInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->InterfaceProductInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setProtocolInfo(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ProtocolInfo,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ProtocolInfo,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getProtocolInfo() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ProtocolInfo);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ProtocolInfo);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setMacAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->MacAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->MacAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getMacAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->MacAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->MacAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setClientIPAddress(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->ClientIPAddress,PyBytes_AsString(bytes));
#else
		std::strcpy(this->ClientIPAddress,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getClientIPAddress() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->ClientIPAddress);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->ClientIPAddress);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setLoginRemark(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->LoginRemark,PyBytes_AsString(bytes));
#else
		std::strcpy(this->LoginRemark,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getLoginRemark() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->LoginRemark);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->LoginRemark);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}

	void setOTPPassword(boost::python::str& v) {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyUnicode_AsASCIIString(v.ptr());
		std::strcpy(this->OTPPassword,PyBytes_AsString(bytes));
#else
		std::strcpy(this->OTPPassword,PyString_AsString(v.ptr()));
#endif
	}
	boost::python::object getOTPPassword() {
#if PY_MAJOR_VERSION >= 3
		PyObject *bytes = PyBytes_FromString(this->OTPPassword);
		PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
#else
		PyObject *str = PyString_FromString(this->OTPPassword);
#endif
		return boost::python::object(boost::python::handle<>(str));
	}
};

#endif //PYCTP_CTPTD_H
