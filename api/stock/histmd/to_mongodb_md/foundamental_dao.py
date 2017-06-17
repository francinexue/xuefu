# -*- coding:utf-8 -*-
"""
想了想，还是要哪块的数据写哪块的方法比较好，同类的就归到一类里面
财务基础数据读写
"""
import pandas as pd
import datetime
import json
from quant import constant as ct
import tushare as ts
from pymongo import MongoClient


class FoundamentalDBcache:
    _cache_method_list = []

    def __init__(self):
        self._cache_method_list = ct._TUSHARE_FOUNDAMENTAL_METHOD_LIST_

    def __getattr__(self, attr):

        if ts.__dict__.has_key(attr) and attr in self._cache_method_list:

            def default_method(*args, **kwargs):
                collection_name = attr[4:]
                year = args[0]
                quarter = args[1]
                data = self._read_cache(collection_name, year, quarter)
                if data is None:
                    data = ts.__dict__[attr](*args, **kwargs)
                    if isinstance(data, pd.DataFrame):
                        self._write_cache(data, collection_name, year, quarter)
                return data

            return default_method

    def _read_cache(self, collectionName, year, quarter):
        try:
            client = MongoClient(ct._MONGODB_ENGIN_)

            cursor = client[ct._MONGODB_DATABASE_][collectionName].find({"year": year, "quarter": quarter})
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

    def _write_cache(self, df, collectionName, year, quarter):
        try:
            client = MongoClient(ct._MONGODB_ENGIN_)

            cursor = client[ct._MONGODB_DATABASE_][collectionName].find({"year": year, "quarter": quarter})
            # 检查是否已经存在了，防止出现重复
            if cursor.count() > 0:
                return
            if isinstance(df, pd.DataFrame):
                df.insert(len(df.columns), "year", year)
                df.insert(len(df.columns), "quarter", quarter)
                client[ct._MONGODB_DATABASE_][collectionName].insert(json.loads(df.to_json(orient='records')))

            else:
                raise RuntimeError('data type is incorrect')

        except Exception as e:
            print(e)

    def check_db_cache(self, start_year=2014, retry_time=4):
        cur = datetime.datetime.now()
        curyear = cur.year
        print("start checking database......")
        for method in self._cache_method_list:
            collection_name = method[4:]
            print("start checking table %s......" % (collection_name))
            for year in range(start_year, curyear + 1):
                for quarter in range(1, 5):
                    data = self._read_cache(collection_name, year, quarter)
                    if data is None:
                        flag = "Fail"
                    else:
                        flag = "Ok"
                    print(
                    "checking table %s's data on year %d quarter %d......%s" % (collection_name, year, quarter, flag))
                    if data is None:
                        for _ in range(0, retry_time):
                            data = ts.__dict__[method](year, quarter)
                            if data is not None:
                                break
                        if isinstance(data, pd.DataFrame) and not data.empty:
                            self._write_cache(data, collection_name, year, quarter)
                            print("\nwriting data to table %s's data on year %d quarter %d......" % (
                            collection_name, year, quarter))

if __name__ == '__main__':
    data = FoundamentalDBcache()
    data.check_db_cache()