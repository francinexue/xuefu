# -*- coding: utf-8 -*-
"""
@author: msi
"""
import datetime
import logging
import time

from api.ctpx.bar_event_listener import BarEventListener
from api.ctpx.ctpmd import CtpMd
from api.ctpx.ctptd import CtpTd
from utils import ListDeque
from utils import logger_factory

logger1 = logger_factory.getLogger("api.ctpx.ctmtd")
logger1.setLevel(logging.DEBUG)

logger2 = logger_factory.getLogger("api.ctpx.ctpmd")
logger2.setLevel(logging.DEBUG)

def time_it(fuc):
    def new_fun(*args, **kwargs):
        a = datetime.datetime.now()
        ret = fuc(*args, **kwargs)
        # print 'each bar fuction cost:%d'%(datetime.datetime.now()-a).microseconds
        return ret

    return new_fun



class CtpTrading(BarEventListener):
    def __init__(self, instruments, tradingObject):
        super(CtpTrading, self).__init__()
        self.__instruments = instruments
        self.__apDataSeries = {}
        self.__bpDataSeries = {}

        self.__ctpTd = tradingObject
        for instrument in instruments:
            self.__apDataSeries[instrument] = ListDeque.ListDeque(2)  # 限定长度为3的list
            self.__bpDataSeries[instrument] = ListDeque.ListDeque(2)

    def update_dataSeries(self, data):
        self.__apDataSeries[data.instrumentID].append(data.askPrice1)
        self.__bpDataSeries[data.instrumentID].append(data.bidPrice1)


    # -------------------------------------------------------------------------------------------------------------------
    def checkEnterSignal(self, instrument):
        return -1


    # -------------------------------------------------------------------------------------------------------------------
    def enterOrder(self, instrument, signal):  # 发起委托

        __enterPrice = self.__apDataSeries[instrument][-1]+50
        __enterArgs = [instrument, str(signal), "2", "0",__enterPrice, 1]
        orderRef = self.__ctpTd.sendOrder(*__enterArgs)
        logger1.info(u"[订单编号] {0} [发送] {1} [开{2}委托] {3}手 [委托价格] {4}".format(orderRef,instrument,signal,__enterArgs[5],__enterArgs[4]))
        pass

    # ----------------------------------------------------------------------
    def CancelOrder(self, instrument):
        pass


    def onRspUserLogin(self,RspUserLoginField):
        """
        :param RspUserLoginField:
        :return:
        """
        self.__sessionId = RspUserLoginField.sessionID
        logger1.info(u'交易服务器登陆成功')
        __requestId = self.__ctpTd.reqQryOrder()


    def onRspQryInvestorPositionDetail(self, InvestorPositionDetailField_dic,requestId):
        """
        查询持仓内容，一次性取完再说,#如果无持仓，居然不返回结果！！！
        :param InvestorPositionDetailField_dic: {tradeID:InvestorPositionDetailField}
        :param requestId:
        :return:
        """

        logger1.info(u"[查询编号] {0} [查看] 持仓明细 {1}单 [来源] {1}".format(requestId,len(InvestorPositionDetailField_dic),'test'))
        for InvestorPositionDetailField in InvestorPositionDetailField_dic.values():
            if InvestorPositionDetailField.volume == 0:   #持仓数为0 ，直接返回，不知为啥会仓位为0
                continue

            logger1.debug(u"[查询持仓明细]  onRspQryInvestorPositionDetail -- instrumentID:{0}, brokerID:{1}, investorID:{2}, Direction:{3},"
                  u"tradingDay: {4}, price: {5}，Volume:{6},tradeID:{7},requestID:{8}".format(InvestorPositionDetailField.instrumentID,
                                                                     InvestorPositionDetailField.brokerID,
                                                                     InvestorPositionDetailField.investorID,
                                                                     InvestorPositionDetailField.direction,
                                                                     InvestorPositionDetailField.tradingDay,
                                                                     InvestorPositionDetailField.openPrice,
                                                                     InvestorPositionDetailField.volume,
                                                                     InvestorPositionDetailField.openPrice,
                                                                     requestId))


    def onRspQryOrder(self, OrderFieldDic,requestId):
        """
        委托查询逻辑
        :param OrderFieldDic: {orderRef:OrderField}
        :param requestId:
        :return:
        """
        logger1.info(u"[查询编号] {0} [查看] 委托明细 {1}单 [来源] {1}".format(requestId,len(OrderFieldDic),'test'))
        for OrderField in OrderFieldDic.values():
            logger1.debug(u"[查询今日委托明细] onRspQryOrder --- brokerID:{0}, orderRef:{1}, limitPrice:{2}, volume:{3}, orderPriceType:{4},"
                  u"direction: {5}, combOffsetFlag: {6}, combHedgeFlag:{7}, contingentCondition: {8}, forceCloseReason: {9},"
                  u"isAutoSuspend: {10}, timeCondition: {11}, volumeCondition:{12}, minVolume: {13}, instrumentID: {14}"
                .format(OrderField.brokerID, OrderField.orderRef, OrderField.limitPrice, OrderField.volumeTotalOriginal,
                        OrderField.orderPriceType, OrderField.direction, OrderField.combOffsetFlag, OrderField.combHedgeFlag,
                        OrderField.contingentCondition, OrderField.forceCloseReason, OrderField.isAutoSuspend, OrderField.timeCondition,
                        OrderField.volumeCondition, OrderField.minVolume, OrderField.instrumentID))
            if OrderField.orderStatus == "0" or OrderField.orderStatus == "5":  #如果全部成交或者已撤单，说明委托无效了
                continue

    # -------------------------------------------------------------------------------------------------------------------
    def onRspOrderInsert(self, InputOrderField, RspInfoField):
        logger1.debug(u"[错误] [onRspOrderInsert]  brokerID:{0}, orderRef:{1}, price:{2}, volume:{3}, orderPriceType:{4},"
                      u"direction: {5}, combOffsetFlag: {6}, combHedgeFlag:{7}, contingentCondition: {8}, forceCloseReason: {9},"
                      u"isAutoSuspend: {10}, timeCondition: {11}, volumeCondition:{12}, minVolume: {13}, instrumentID: {14}"
                      .format(InputOrderField.brokerID, InputOrderField.orderRef, InputOrderField.limitPrice,
                              InputOrderField.volumeTotalOriginal, InputOrderField.orderPriceType,
                              InputOrderField.direction,
                              InputOrderField.combOffsetFlag, InputOrderField.combHedgeFlag,
                              InputOrderField.contingentCondition,
                              InputOrderField.forceCloseReason, InputOrderField.isAutoSuspend,
                              InputOrderField.timeCondition,
                              InputOrderField.volumeCondition, InputOrderField.minVolume, InputOrderField.instrumentID))
        logger1.debug(u"[错误] [onRspOrderInsert]  errorCode:{0}, errorMsg:{1}.".format(
            RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk')))

        if RspInfoField.errorID == 50:  #平今仓位不足
            pass

    def onRspOrderAction(self, InputOrderActionField, RspInfoField):
        logger1.debug(u"[错误] [onRspOrderAction]   sessionId: {0}, frontID: {1}, orderRef: {2},volumeChange:{3}".format(
            InputOrderActionField.sessionID,
            InputOrderActionField.frontID, InputOrderActionField.orderRef,InputOrderActionField.volumeChange))
        logger1.debug(u"[错误] [onRspOrderAction]   errorCode:{0}, errorMsg:{1}.".format(
            RspInfoField.errorID, RspInfoField.errorMsg.decode('gbk')))
        ##多发送撤单会出现 ：error code 26；已成或已撤单


    def onRtnTradeEvent(self, TradeField):
        """
        成交事件处理,该内容会在onRtnORder 里面同时出现一遍，但这个里面有成交价格
        :param TradeField:
        :return:
        """
        logger1.info(u' [订单编号] {0} [已成] {1} [方向] {2} {3}手 [成交价格] {4}'.
                     format(TradeField.orderRef, TradeField.instrumentID, TradeField.direction,
                            TradeField.volume, TradeField.price))
        pass

    # -------------------------------------------------------------------------------------------------------------------
    def onRtnOrderEvent(self, OrderField):  # 委托返回码
        # 注意添加一个状态栏。因为可能同时发送过来两次一样的返回状态，需要给过滤掉一条
        if OrderField.orderSubmitStatus == '4':  # 委托不符合条件
            logger1.debug(u"[订单编号] {0} [拒绝] {1} [委托被拒绝]".format(OrderField.orderRef,OrderField.instrumentID))
            return
        # ----------------------------------------------------------------------
        elif OrderField.orderSubmitStatus == '3' and OrderField.orderStatus == '3':  # 委托成功,一般委托都符合条件，
            pass

        # ----------------------------------------------------------------------
        elif OrderField.orderStatus == '0' or OrderField.orderStatus == '1':  # 成交  #成交委托处理情况均写在onRtnTradeEvent
            pass
        # ----------------------------------------------------------------------
        elif OrderField.orderSubmitStatus == '3' and (OrderField.orderStatus == '5'):  # 撤单
            #注意可能存在部分成交的情况
            pass



    @time_it
    def onBarEvent(self, data):
        bar_time = datetime.datetime(int(data.tradingDay[:4]), int(data.tradingDay[4:6]),
                                     int(data.tradingDay[6:8]), int(data.updateTime[:2]), int(data.updateTime[3:5]),
                                     int(data.updateTime[6:8]), 1000 * int(data.updateMillisec))
        instrument = data.instrumentID  # 合约ID
        logger2.info(u'[合约] {0},[合约时间] {1} [ap1] {2} [bp1] {3} [av1] {4} [bv1] {5}'.format(instrument, bar_time.strftime('%Y-%m-%d %H:%M:%S.%f'),
                                                              data.askPrice1, data.bidPrice1,data.askVolume1, data.bidVolume1))

        self.update_dataSeries(data)
        print 'the current data is',self.__apDataSeries[instrument][-1],self.__bpDataSeries[instrument][-1]
        pass

if __name__ == "__main__":
    ctpMd = CtpMd()
    ctpTd = CtpTd()
    INSTRUMENTS = ['cu1710']
    lsn = CtpTrading(INSTRUMENTS, ctpTd)
    ctpMd.addBarEventListener(lsn)
    ctpTd.addBarEventListener(lsn)
    ctpMd.login("tcp://180.168.146.187:10031", '090285', 'ABCabc', '9999')
    ctpTd.login("tcp://218.202.237.33:10002", '090285', 'ABCabc', '9999')    #行情和交易地址有多个，一个不行则去simnow更换
    time.sleep(5)

    ctpMd.subscribeMarketData(INSTRUMENTS)
    ctpMd.join()
    ctpTd.join()

