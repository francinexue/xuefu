# -*- coding: utf-8 -*-
"""
Created on Fri Oct 14 08:46:27 2016
该方法调用掘金的api来获取分钟线数据，基本方法与tushare相同
@author: lenovo
"""
import sys
sys.path.append("..")

from quant import constant as ct
from gmsdk import md,to_dict
import pandas as pd
from datetime import datetime,timedelta

#ret = md.init('71468641@qq.com','jason123', 2,"SHSE.000027.bar.5")
'''
ktype: D=日k线   5=5分钟 15=15分钟 30=30分钟 60=60分钟，默认为D
start:str,'2016-11-1'
'''
class gm_api():
    
    def __init__(self):
        self.ret = md.init('71468641@qq.com','jason123')
        self.k_dic = {'5':300,'15':15*60,'30':30*60,'60':60*60} 
    
    #-------------------数据需要分好几段截取--------------------
    
    def get_hist_data(self,code=None, start=None, end=ct._TODAY_, ktype='D'):
        
           if code[:2] == '60':
              code = 'SHSE.'+code
           else:
              code = 'SZSE.'+code     
           
           tmp_end = start
           last_end = -1
           dat = pd.DataFrame()
           while(tmp_end < end and tmp_end != last_end):
               if ktype == 'D':
                  bars =  md.get_dailybars(code,tmp_end,end)
               else:
                    bars = md.get_bars(code,self.k_dic[ktype], tmp_end +' 09:00:00',end+' 15:00:00')
               
               if len(bars)==0:
                   return pd.DataFrame([],columns=['high','low','open','close','volume'])
                   
               rt = []
               for i in bars:    
                   rt.append(to_dict(i))
               
               dt = pd.DataFrame(rt)    
               if start == tmp_end:
                   dat = dt
               else:
                   dat = dat.append(dt)
               print '-----',code,dt.iloc[-1,12][:10]
               last_end = tmp_end
               tmp_end = dt.iloc[-1,12][:10]
               tomorrow = datetime.strptime(tmp_end, '%Y-%m-%d') + timedelta(days=1)
               tmp_end = datetime.strftime(tomorrow, '%Y-%m-%d')


           dat.drop_duplicates(['strendtime'],inplace=True)
           dat.index = dat['strendtime'].apply(lambda x:datetime.strptime(x,'%Y-%m-%dT%H:%M:%S+08:00'))
           return dat[['high','low','open','close','volume']]



if __name__ == '__main__':
    code = '300426'
    gm = gm_api()
    dat = gm.get_hist_data(code,'2015-01-01','2016-11-05',ktype='5')
    #dat.to_csv('d:/data_5minitue/%s.csv'%code,encoding='gbk')
    print dat
