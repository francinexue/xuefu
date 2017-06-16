//
// Created by kyle on 17-5-18.
//

#ifndef PYCTP_CTPMD_H
#define PYCTP_CTPMD_H

#include "base.h"
#include "ThostFtdcMdApi.h"

#define ON_FRONT_CONNECTED 1
#define ON_FRONT_DISCONNECTED 2
#define ON_HEART_BEAT_WARNING 3
#define ON_RSP_USER_LOGIN 4
#define ON_RSP_USER_LOGOUT 5
#define ON_RSP_ERROR 6
#define ON_RSP_SUB_MARKET_DATA 7
#define ON_RSP_UN_SUB_MARKET_DATA 8
#define ON_RSP_SUB_FOR_QUOTE_RSP 9
#define ON_RSP_UN_SUB_FOR_QUOTE_RSP 10
#define ON_RTN_DEPTH_MARKET_DATA 11
#define ON_RTN_FOR_QUOTE_RSP 12

using namespace boost::python;
using namespace boost;

class CtpMd : public CThostFtdcMdSpi {
private:
    boost::thread* task_thread; // 回调函数执行线程
    ConcurrentQueue<Task *> task_queue; //任务队列
    CThostFtdcMdApi *api; //API对象
    void processTask();
public:
    CtpMd(const std::string &szFlowPath = "", bool usingUdp=false, bool multicast=false);
    ~CtpMd();

    ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
    virtual void OnFrontConnected();
    virtual void onFrontConnected() {};

    ///        0x2003 收到错误报文
    virtual void OnFrontDisconnected(int nReason);
    virtual void onFrontDisconnected(int reasonCode) {};

    ///@param nTimeLapse 距离上次接收报文的时间
    virtual void OnHeartBeatWarning(int nTimeLapse);
    virtual void onHeartBeatWarning(int lapsedTime) {};

    ///登录请求响应
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUserLogin(object &rspUserLoginField, object &rspInfoField, int requestId, bool final) {};

    ///登出请求响应
    virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUserLogout(object &userLogoutField, object &rspInfoField, int requestId, bool final) {};

    ///错误应答
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspError(object &rspInfoField, int requestId, bool final) {};

    ///订阅行情应答
    virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspSubMarketData(object &specificInstrumentField, object &rspInfoField, int requestId, bool final) {};

    ///取消订阅行情应答
    virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUnSubMarketData(object &specificInstrumentField, object &rspInfoField, int requestId, bool final) {};

    ///订阅询价应答
    virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspSubForQuoteRsp(object &specificInstrumentField, object &rspInfoField, int requestId, bool final) {};

    ///取消订阅询价应答
    virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUnSubForQuoteRsp(object &specificInstrumentField, object &rspInfoField, int requestId, bool final) {};

    ///深度行情通知
    virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
    virtual void onRtnDepthMarketData(object &depthMarketDataField) {};

    ///询价通知
    virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);
    virtual void onRtnForQuoteRsp(object &forQuoteRspField) {};

    const char *getApiVersion();

    void release();

    void init();

    int join();

	const char *getTradingDay();

	void registerFront(const std::string &szFrontAddress);

    void registerNameServer(const std::string &szNsAddress);

    void registerFensUserInfo(object &fensUserInfoField);

    void registerSpi();

    int subscribeMarketData(list &instrumentIDs);

    int unSubscribeMarketData(list &instrumentIDs);

    int subscribeForQuoteRsp(list &instrumentIDs);

    int unSubscribeForQuoteRsp(list &instrumentIDs);

    int reqUserLogin(object &reqUserLoginField, int requestId);

    int reqUserLogout(object &userLogoutField, int requestId);
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

struct SpecificInstrumentField: CThostFtdcSpecificInstrumentField {

    SpecificInstrumentField() {
        std::memset(this, 0, sizeof(SpecificInstrumentField));
    }

    SpecificInstrumentField(const CThostFtdcSpecificInstrumentField& f): CThostFtdcSpecificInstrumentField(f){}

    SpecificInstrumentField& operator=(const CThostFtdcSpecificInstrumentField& f) {
        CThostFtdcSpecificInstrumentField::operator=(f);
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


#endif //PYCTP_CTPMD_H
