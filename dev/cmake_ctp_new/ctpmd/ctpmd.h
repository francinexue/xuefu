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

class CtpMd : public CThostFtdcMdSpi {
private:
    boost::thread* task_thread; 
    ConcurrentQueue<Task *> task_queue; 
	CThostFtdcMdApi *api; 
    void processTask();
public:
    CtpMd(const std::string &szFlowPath = "", bool usingUdp=false, bool multicast=false);
    ~CtpMd();

    
    virtual void OnFrontConnected();
    virtual void onFrontConnected() {};

    
    virtual void OnFrontDisconnected(int nReason);
    virtual void onFrontDisconnected(int reasonCode) {};

    ///@param nTimeLapse 
    virtual void OnHeartBeatWarning(int nTimeLapse);
    virtual void onHeartBeatWarning(int lapsedTime) {};

    
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUserLogin(boost::python::object &rspUserLoginField, boost::python::object &rspInfoField, int requestId, bool final) {};

    
    virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUserLogout(boost::python::object &userLogoutField, boost::python::object &rspInfoField, int requestId, bool final) {};

    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspError(boost::python::object &rspInfoField, int requestId, bool final) {};

    virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspSubMarketData(boost::python::object &specificInstrumentField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUnSubMarketData(boost::python::object &specificInstrumentField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspSubForQuoteRsp(boost::python::object &specificInstrumentField, boost::python::object &rspInfoField, int requestId, bool final) {};

    virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void onRspUnSubForQuoteRsp(boost::python::object &specificInstrumentField, boost::python::object &rspInfoField, int requestId, bool final) {};


    virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
    virtual void onRtnDepthMarketData(boost::python::object &depthMarketDataField) {};

   
    virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);
    virtual void onRtnForQuoteRsp(boost::python::object &forQuoteRspField) {};

    const char *getApiVersion();

    void release();

    void init();

    int join();

    const char *getTradingDay();

    void registerFront(const std::string &szFrontAddress);

    void registerNameServer(const std::string &szNsAddress);

    void registerFensUserInfo(boost::python::object &fensUserInfoField);

    void registerSpi();

    int subscribeMarketData(boost::python::list &instrumentIDs);

    int unSubscribeMarketData(boost::python::list &instrumentIDs);

    int subscribeForQuoteRsp(boost::python::list &instrumentIDs);

    int unSubscribeForQuoteRsp(boost::python::list &instrumentIDs);

    int reqUserLogin(boost::python::object &reqUserLoginField, int requestId);

    int reqUserLogout(boost::python::object &userLogoutField, int requestId);

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

struct SpecificInstrumentField: CThostFtdcSpecificInstrumentField {

    SpecificInstrumentField() {
        std::memset(this, 0, sizeof(SpecificInstrumentField));
    }

    SpecificInstrumentField(const CThostFtdcSpecificInstrumentField& f): CThostFtdcSpecificInstrumentField(f){}

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

#endif //PYCTP_CTPMD_H
