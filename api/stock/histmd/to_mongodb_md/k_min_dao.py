# -*- coding:utf-8 -*-
"""
k线分钟线,5,10,60数据存储，不再批量更新
"""

import pandas as pd
import datetime
import json
import eventlet as et
from quant import constant as ct
from quant.utils.wapper_interface import gm_api as gm
from pymongo import MongoClient
from datetime import datetime
from datetime import timedelta
et.monkey_patch(os=False)
class KminDbCache():

    def __init__(self):
        #
        self.gm = gm()
        self.pool = et.GreenPool(10)

    def get_k_data(self,*args,**kwargs):
        """
              :param args: args 第一项肯定为code
              :param kwargs: ktype,startdate等肯定包含在kwargs中
              :return: 先读cache,如果最近时间大于请求时间，则返回，否则调用更新算法，只更新这一个code,更新数据库；
              默认为5分钟线数据，一个文件一存
              """
        collection_name = 'k_data_'
        code = args[0]
        start = "2015-01-01"
        end = ct._TODAY_
        if kwargs.has_key('start'):
            start = kwargs['start']
        if kwargs.has_key('end'):
            end = kwargs['end']
        if kwargs.has_key('ktype'):
            collection_name += kwargs['ktype']
        collection_name += '5'

        df = self._read_cache(collection_name, code, start, end)
        if df is None or df['date'].values[-1] < end:  # 可能需要更新數據，更新數據的时候注意重新判定end的日期，因为有可能不是交易日
            dat = self._update_cache(collection_name,code)
            #df = self._read_cache(collection_name, code, start, end)  立即读取失败，如何commit？
            df = dat.append(dat)
            df = df[(df['date'] >= start) & (df['date'] <=end)]
        return df

    def _update_cache(self,collection_name = 'k_data_5',code=None,ktype='5'):
        """
        :return: 默认更新5分钟线数据，且用一个缓存一个
        start='2015-01-01'
        """
        date_fmt = '%Y-%m-%d %H:%M:%S'
        today = ct._TODAY_
        client = MongoClient(ct._MONGODB_ENGIN_)

        def update_one_code(code,collection_name):
            ktype = collection_name[7:]
            cursor = client[ct._MONGODB_DATABASE_][collection_name].find({"code": code}).sort([("date", -1)]).limit(1) #倒序
            if cursor.count() <= 0:
                print("%s is not in the db" % (code))
                '''重新采集数据灌进去'''
                start_date = '2015-01-01'
                end_date = today
                if start_date is None or start_date == end_date:
                    return
                df = self.gm.get_k_data(code, start_date, end_date,ktype=ktype)
            else:
                print ("%s have data in the db" % (code)), cursor[0]
                start_date = cursor[0]['date']
                end_date = today
                df = self.gm.get_k_data(code, start_date, end_date,ktype=ktype)

            if isinstance(df, pd.DataFrame) and not df.empty:
                print("insert data to db of code:%s\n" % (code))
                # print json.loads(df.to_json(orient='records'))
                client[ct._MONGODB_DATABASE_][collection_name].insert(json.loads(df.to_json(orient='records')))
                return  df

        return update_one_code(code,collection_name)
        print 'update is done'

    def _read_cache(self, collectionName, code, start, end):
        try:
            client = MongoClient(ct._MONGODB_ENGIN_)
            cursor = client[ct._MONGODB_DATABASE_][collectionName]. \
                find({"code": code, "date": {"$gte": start+' 09:00:00', "$lte": end+' 15:00:00'}}).sort([("date", 1)])
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
        w = KminDbCache()
        data = w.get_k_data('300426', start='2016-01-05')
        print data.tail()
