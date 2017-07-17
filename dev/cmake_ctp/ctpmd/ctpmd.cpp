//
// Created by kyle on 17-5-18.
//
#include "ctpmd.h"

CtpMd::CtpMd(const std::string &szFlowPath, bool usingUdp, bool multicast) {
    this->api = CThostFtdcMdApi::CreateFtdcMdApi(szFlowPath.c_str(), usingUdp, multicast);
    boost::function0<void> f = boost::bind(&CtpMd::processTask, this);
    this->task_thread = new boost::thread(f);
}

CtpMd::~CtpMd() {
    task_thread->interrupt();
    task_thread->join();
    delete task_thread;
    this->api->Release();
}

void CtpMd::OnFrontConnected() {
    Task *task = new Task();
    task->name = ON_FRONT_CONNECTED;
    this->task_queue.push(task);
}

void CtpMd::OnFrontDisconnected(int nReason) {
    Task *task = new Task();
    task->name = ON_FRONT_DISCONNECTED;
    task->num = nReason;
    this->task_queue.push(task);
}

void CtpMd::OnHeartBeatWarning(int nTimeLapse) {
    Task *task = new Task();
    task->name = ON_HEART_BEAT_WARNING;
    task->num = nTimeLapse;
    this->task_queue.push(task);
}

void CtpMd::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
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

void CtpMd::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
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

void CtpMd::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_ERROR;
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpMd::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_SUB_MARKET_DATA;
    if (pSpecificInstrument)
        task->payload = SpecificInstrumentField(*pSpecificInstrument);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpMd::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_UN_SUB_MARKET_DATA;
    if (pSpecificInstrument)
        task->payload = SpecificInstrumentField(*pSpecificInstrument);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpMd::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_SUB_FOR_QUOTE_RSP;
    if (pSpecificInstrument)
        task->payload = SpecificInstrumentField(*pSpecificInstrument);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpMd::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    Task *task = new Task();
    task->name = ON_RSP_UN_SUB_FOR_QUOTE_RSP;
    if (pSpecificInstrument)
        task->payload = SpecificInstrumentField(*pSpecificInstrument);
    if (pRspInfo)
        task->resp = RspInfoField(*pRspInfo);
    task->num = nRequestID;
    task->final = bIsLast;
    this->task_queue.push(task);
}

void CtpMd::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) {
    Task *task = new Task();
    task->name = ON_RTN_DEPTH_MARKET_DATA;
    if (pDepthMarketData)
        task->payload = DepthMarketDataField(*pDepthMarketData);
    this->task_queue.push(task);
}

void CtpMd::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) {
    Task *task = new Task();
    task->name = ON_RTN_FOR_QUOTE_RSP;
    if (pForQuoteRsp)
        task->payload = ForQuoteRspField(*pForQuoteRsp);
    this->task_queue.push(task);
}

void CtpMd::processTask() {
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
            case ON_RSP_ERROR: {
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspError(const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_SUB_MARKET_DATA: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<SpecificInstrumentField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspSubMarketData(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_UN_SUB_MARKET_DATA: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<SpecificInstrumentField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspUnSubMarketData(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_SUB_FOR_QUOTE_RSP: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<SpecificInstrumentField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspSubForQuoteRsp(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RSP_UN_SUB_FOR_QUOTE_RSP: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<SpecificInstrumentField &>(task->payload));
                const object &resp = task->resp.empty() ? object() : object(any_cast<RspInfoField &>(task->resp));
                this->onRspUnSubForQuoteRsp(const_cast<object &>(payload), const_cast<object &>(resp), task->num, task->final);
                break;
            }
            case ON_RTN_DEPTH_MARKET_DATA: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<DepthMarketDataField &>(task->payload));
                this->onRtnDepthMarketData(const_cast<object &>(payload));
                break;
            }
            case ON_RTN_FOR_QUOTE_RSP: {
                const object &payload = task->payload.empty() ? object() : object(any_cast<ForQuoteRspField &>(task->payload));
                this->onRtnForQuoteRsp(const_cast<object &>(payload));
                break;
            }
        }
        delete task;
    }
}

const char *CtpMd::getApiVersion() {
    return  CThostFtdcMdApi::GetApiVersion();
}

void CtpMd::release() {
    DepositGIL unlocker;
    this->api->Release();
}

void CtpMd::init() {
    DepositGIL unlocker;
    this->api->Init();
}

int CtpMd::join() {
    DepositGIL unlocker;
    return this->api->Join();
}

const char *CtpMd::getTradingDay() {
    return this->api->GetTradingDay();
}

void CtpMd::registerFront(const std::string &szFrontAddress) {
    this->api->RegisterFront(const_cast<char *>(szFrontAddress.c_str()));
}

void CtpMd::registerNameServer(const std::string &szNsAddress) {
    this->api->RegisterNameServer(const_cast<char *>(szNsAddress.c_str()));
}

void CtpMd::registerFensUserInfo(object &fensUserInfoField) {
    FensUserInfoField *p1 = extract<FensUserInfoField *>(fensUserInfoField);
    this->api->RegisterFensUserInfo(p1);
}

void CtpMd::registerSpi() {
    this->api->RegisterSpi(this);
}

int CtpMd::subscribeMarketData(list &instrumentIDs) {
    int length = len(instrumentIDs);
    char **array = new char*[length];
    for (int i = 0; i < length; i++) {
        *(array + i) = const_cast<char *>(extract<const char *>(instrumentIDs[i])());
    };
    int result = this->api->SubscribeMarketData(array, length);
    delete array;
    return result;
}

int CtpMd::unSubscribeMarketData(list &instrumentIDs) {
    int length = len(instrumentIDs);
    char **array = new char*[length];
    for (int i = 0; i < length; i++) {
        *(array + i) = const_cast<char *>(extract<const char *>(instrumentIDs[i])());
    };
    int result = this->api->UnSubscribeMarketData(array, length);
    delete array;
    return result;
}

int CtpMd::subscribeForQuoteRsp(list &instrumentIDs) {
    int length = len(instrumentIDs);
    char **array = new char*[length];
    for (int i = 0; i < length; i++) {
        *(array + i) = const_cast<char *>(extract<const char *>(instrumentIDs[i])());
    };
    int result = this->api->SubscribeForQuoteRsp(array, length);
    delete array;
    return result;
}

int CtpMd::unSubscribeForQuoteRsp(list &instrumentIDs) {
    int length = len(instrumentIDs);
    char **array = new char*[length];
    for (int i = 0; i < length; i++) {
        *(array + i) = const_cast<char *>(extract<const char *>(instrumentIDs[i])());
    };
    int result = this->api->UnSubscribeForQuoteRsp(array, length);
    delete array;
    return result;
}

int CtpMd::reqUserLogin(object &reqUserLoginField, int requestId) {
    ReqUserLoginField *p1 = extract<ReqUserLoginField *>(reqUserLoginField);
    return this->api->ReqUserLogin(p1, requestId);
}

int CtpMd::reqUserLogout(object &userLogoutField, int requestId) {
    UserLogoutField *p1 = extract<UserLogoutField *>(userLogoutField);
    return this->api->ReqUserLogout(p1, requestId);
}

struct CtpMdWrap : CtpMd, wrapper<CtpMd> {

    CtpMdWrap(const std::string &szFlowPath = "", bool usingUdp=false, bool multicast=false)
            : CtpMd(szFlowPath, usingUdp, multicast) {}

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

    virtual void onRspError(object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspError")(rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspSubMarketData(object &specificInstrumentField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspSubMarketData")(specificInstrumentField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspUnSubMarketData(object &specificInstrumentField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspUnSubMarketData")(specificInstrumentField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspSubForQuoteRsp(object &specificInstrumentField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspSubForQuoteRsp")(specificInstrumentField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRspUnSubForQuoteRsp(object &specificInstrumentField, object &rspInfoField, int requestId, bool final) {
        try {
            this->get_override("onRspUnSubForQuoteRsp")(specificInstrumentField, rspInfoField, requestId, final);
        } catch (error_already_set const &) {
            PyErr_Print();
        }
    };

    virtual void onRtnDepthMarketData(object &depthMarketDataField) {
        try {
            this->get_override("onRtnDepthMarketData")(depthMarketDataField);
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
};

BOOST_PYTHON_MODULE(ctpmd) {
    if (!PyEval_ThreadsInitialized())
        PyEval_InitThreads();	//导入时运行，保证先创建GIL

    class_<CtpMdWrap, boost::noncopyable>("CtpMd", init<const std::string &, bool, bool>())
            .def("onFrontConnected", pure_virtual(&CtpMdWrap::onFrontConnected))
            .def("onFrontDisconnected", pure_virtual(&CtpMdWrap::onFrontDisconnected))
            .def("onHeartBeatWarning", pure_virtual(&CtpMdWrap::onHeartBeatWarning))
            .def("onRspUserLogin", pure_virtual(&CtpMdWrap::onRspUserLogin))
            .def("onRspUserLogout", pure_virtual(&CtpMdWrap::onRspUserLogout))
            .def("onRspError", pure_virtual(&CtpMdWrap::onRspError))
            .def("onRspSubMarketData", pure_virtual(&CtpMdWrap::onRspSubMarketData))
            .def("onRspUnSubMarketData", pure_virtual(&CtpMdWrap::onRspUnSubMarketData))
            .def("onRspSubForQuoteRsp", pure_virtual(&CtpMdWrap::onRspSubForQuoteRsp))
            .def("onRspUnSubForQuoteRsp", pure_virtual(&CtpMdWrap::onRspUnSubForQuoteRsp))
            .def("onRtnDepthMarketData", pure_virtual(&CtpMdWrap::onRtnDepthMarketData))
            .def("onRtnForQuoteRsp", pure_virtual(&CtpMdWrap::onRtnForQuoteRsp))
            .def("getApiVersion", &CtpMdWrap::getApiVersion)
            .def("release", &CtpMdWrap::release)
            .def("init", &CtpMdWrap::init)
            .def("join", &CtpMdWrap::join)
            .def("getTradingDay", &CtpMdWrap::getTradingDay)
            .def("registerFront", &CtpMdWrap::registerFront)
            .def("registerNameServer", &CtpMdWrap::registerNameServer)
            .def("registerFensUserInfo", &CtpMdWrap::registerFensUserInfo)
            .def("registerSpi", &CtpMdWrap::registerSpi)
            .def("subscribeMarketData", &CtpMdWrap::subscribeMarketData)
            .def("unSubscribeMarketData", &CtpMdWrap::unSubscribeMarketData)
            .def("subscribeForQuoteRsp", &CtpMdWrap::subscribeForQuoteRsp)
            .def("unSubscribeForQuoteRsp", &CtpMdWrap::unSubscribeForQuoteRsp)
            .def("reqUserLogin", &CtpMdWrap::reqUserLogin)
            .def("reqUserLogout", &CtpMdWrap::reqUserLogout);


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

    class_<RspInfoField>("RspInfoField")
            .def_readwrite("errorID", &RspInfoField::ErrorID)
            .add_property("errorMsg", &RspInfoField::getErrorMsg, &RspInfoField::setErrorMsg);

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

    class_<ForQuoteRspField>("ForQuoteRspField")
            .add_property("tradingDay", &ForQuoteRspField::getTradingDay, &ForQuoteRspField::setTradingDay)
            .add_property("instrumentID", &ForQuoteRspField::getInstrumentID, &ForQuoteRspField::setInstrumentID)
            .add_property("forQuoteSysID", &ForQuoteRspField::getForQuoteSysID, &ForQuoteRspField::setForQuoteSysID)
            .add_property("forQuoteTime", &ForQuoteRspField::getForQuoteTime, &ForQuoteRspField::setForQuoteTime)
            .add_property("actionDay", &ForQuoteRspField::getActionDay, &ForQuoteRspField::setActionDay)
            .add_property("exchangeID", &ForQuoteRspField::getExchangeID, &ForQuoteRspField::setExchangeID);

    class_<SpecificInstrumentField>("SpecificInstrumentField")
            .add_property("instrumentID", &SpecificInstrumentField::getInstrumentID, &SpecificInstrumentField::setInstrumentID);

    class_<FensUserInfoField>("FensUserInfoField")
            .add_property("brokerID", &FensUserInfoField::getBrokerID, &FensUserInfoField::setBrokerID)
            .add_property("userID", &FensUserInfoField::getUserID, &FensUserInfoField::setUserID)
            .def_readwrite("loginMode", &FensUserInfoField::LoginMode);

}
