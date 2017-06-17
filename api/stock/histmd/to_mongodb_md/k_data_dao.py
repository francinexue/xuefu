# -*- coding:utf-8 -*-
"""
created on Dec 2016
@author xuefu
想了想，还是要哪块的数据写哪块的方法比较好，同类的就归到一类里面
k线日线数据存储,不含指数，指数另存
"""
import pandas as pd
import datetime
import json
import eventlet as et
from quant import constant as ct
import k_index_dao
from quant.utils.wapper_interface import tushare as ts
from pymongo import MongoClient
from datetime import datetime
from datetime import timedelta
et.monkey_patch(os=False)  # 否则会阻塞验证码读写IO
class KdataDbCache():
    _cache_method_list = []

    def __init__(self):
        #
        self.ts = ts()
        self.pool = et.GreenPool(20)


    def get_k_data(self,*args,**kwargs):
        """
        :param args: args 第一项肯定为code
        :param kwargs: ktype,startdate等肯定包含在kwargs中
        :return: 先读cache,如果最近时间大于请求时间，则返回，否则调用更新算法，更新数据库；
        默认为日线数据，月线和周线数据可以resample得到，分钟线数据另写，应当一个文件一存，要不太大
        """
        if kwargs.has_key('index') and kwargs['index'] == True:
            return k_index_dao().get_k_data(*args,**kwargs)
        collection_name = 'k_data'
        code = args[0]
        start = ct._START_
        end = ct._TODAY_
        if kwargs.has_key('start'):
            start = kwargs['start']
        if kwargs.has_key('end'):
            end = kwargs['end']

        df = self._read_cache(collection_name, code,start,end)
        if df is None or df['date'].values[-1]< end:  #可能需要更新數據，更新數據的时候注意重新判定end的日期，因为有可能不是交易日
            print 'may need update cache'
            #self._update_cache()
            data = self.ts.get_k_data(*args,**kwargs)  #新版的get_k_data方法仍需要指明是否为index
            if isinstance(data, pd.DataFrame) and not data.empty:
                df = data

        return df


    def _update_cache(self):
        """

        :return: 此处涉及到ct._start_的问题，并发问题
        """
        date_fmt = '%Y-%m-%d'
        today = ct._TODAY_
        stock_list = self.ts.get_stock_basics()
        client = MongoClient(ct._MONGODB_ENGIN_)
        if isinstance(stock_list, pd.DataFrame) and not stock_list.empty:
            client[ct._MONGODB_DATABASE_]["stock_list"].remove()
            client[ct._MONGODB_DATABASE_]["stock_list"].insert(json.loads(stock_list.to_json(orient='records')))
        '''逐个代码检查'''
        def update_one_code(code):
            cursor = client[ct._MONGODB_DATABASE_]["k_data"].find({"code": code}).sort([("date", -1)]).limit(1)
            if cursor.count() <= 0:
                print("%s is not in the db" % (code))
                '''重新采集数据灌进去'''
                start_date = ct._START_
                end_date = today
                if start_date is None or start_date == end_date:
                    return
                df = self.ts.get_k_data(code, start_date, end_date)
            else:
                print ("%s have data in the db" % (code))
                tomorrow = datetime.strptime(cursor[0]['date'], date_fmt) + timedelta(days=1)
                start_date = datetime.strftime(tomorrow, date_fmt)
                end_date = today
                df = self.ts.get_k_data(code, start_date, end_date)

            if isinstance(df, pd.DataFrame) and not df.empty:
                #print df.head()
                print("insert data to db of code:%s\n" % (code))
                # print json.loads(df.to_json(orient='records'))
                client[ct._MONGODB_DATABASE_]["k_data"].insert(json.loads(df.to_json(orient='records')))

        for code in stock_list.index:
            self.pool.spawn_n(update_one_code, **{'code': code})
        self.pool.waitall()
        print 'all is donetop'

    def _read_cache(self, collectionName, code,start,end):
        try:
            client = MongoClient(ct._MONGODB_ENGIN_)
            cursor = client[ct._MONGODB_DATABASE_][collectionName].\
                find({"code":code,"date":{"$gte":start,"$lte":end}}).sort([("date",1)])
            # check if data table exist
            if cursor.count() == 0:
                return None
            df = pd.DataFrame(list(cursor))
            if df.empty:
                return None

            # Delete the _id
            del df['_id']
            return df
        except Exception as e:
            print(e)

if __name__ == '__main__':
    w = KdataDbCache()
    #data = w._read_cache('k_data','300426',start='2015-02-05',end='2015-02-19')
    data = w.get_k_data('300426',start='2015-02-05',end='2015-02-19')
    print data
