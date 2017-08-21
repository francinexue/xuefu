# -*- coding:utf-8 -*-
import sys
sys.path.append("..")
import tushare as ts
import pandas as pd
from datetime import datetime,timedelta
from gmsdk import md,to_dict
from quant import constant as ct
"""
添加了异常处理
"""
class tushare:
    def __getattr__(self, attr):
        if ts.__dict__.has_key(attr):
            def default_method(*args, **kwargs):
                try:
                    data = ts.__dict__[attr](*args, **kwargs)
                   # if not data.empty and data.index.name is not None:   #有时候存在date 列当作index
                   #     data[data.index.name] = data.index
                except:
                    print 'tushare get data error'
                    data = pd.DataFrame()
                return data
            return default_method


'''
ktype: D=日k线   5=5分钟 15=15分钟 30=30分钟 60=60分钟，默认为D
start:str,'2016-11-1'
'''


class gm_api():
    """
    strendtime为结束时间，bars取值不含start含end
    """
    def __init__(self):
        self.ret = md.init('71468641@qq.com', 'jason123')
        self.k_dic = {'5': 300, '15': 15 * 60, '30': 30 * 60, '60': 60 * 60}
        # -------------------数据需要分好几段截取--------------------

    def get_k_data(self, code=None, start=None, end=ct._TODAY_, ktype='D',isOHLC=True):

        if code[:2] == '60':
            code = 'SHSE.' + code
        else:   #30 or 00
            code = 'SZSE.' + code

        if len(start) == 10:
            start += ' 09:00:00'
        if len(end) == 10:
                end += ' 15:00:00'
        tmp_end = start
        last_end = -1
        dat = pd.DataFrame()
        while (tmp_end < end and tmp_end != last_end):
            if ktype == 'D':
                bars = md.get_dailybars(code, tmp_end, end)
            else:
                bars = md.get_bars(code, self.k_dic[ktype], tmp_end, end)
            if len(bars) == 0:
                break

            rt = []
            for i in bars:
                rt.append(to_dict(i))

            dt = pd.DataFrame(rt)
            if start == tmp_end:
                dat = dt
            else:
                dat = dat.append(dt)
            print '-----', code, dt.iloc[-1, 12][:19]
            last_end = tmp_end
            tmp_end = dt.iloc[-1, 12][:19]
            next_5min = datetime.strptime(tmp_end, '%Y-%m-%dT%H:%M:%S') + timedelta(minutes=int(ktype))
            tmp_end = datetime.strftime(next_5min, '%Y-%m-%d %H:%M:%S')
        if dat.empty:
            return dat
        dat.drop_duplicates(['strendtime'], inplace=True)
        dat['date'] = dat['strendtime'].apply(lambda x:x[:10]+' '+x[11:19])
        dat.insert(len(dat.columns), "code", code[5:])
        #dat.index = dat['strtime'].apply(lambda x: datetime.strptime(x, '%Y-%m-%dT%H:%M:%S+08:00'))
        if isOHLC:
            return dat[['date','high', 'low', 'open', 'close', 'volume','code']]
        return dat
if __name__ == '__main__':
    code = '002858'
    gm = gm_api()
    dat = gm.get_k_data(code,'2015-01-01',ktype='5',isOHLC=False)
    dat.to_csv('../api/stock/csv/%s.csv'%code,encoding='gbk')
    print dat.head()