#-*- coding: UTF-8 -*-
"""
Created on 2016/03/22
@author: guoyuqi
@group : AshareQuant
@contact: guoyuqi0554@aliyun.com
略鸡肋，最多显示10条，翻页问题临时搞不定
"""

from wencai_parser import get_wencai_stockcode
import time
from json import dumps

def run(url, name):
    codes = get_wencai_stockcode(url, max_num= 5)
    now_date = time.strftime('%Y-%m-%d',time.localtime(time.time()))

    if codes and len(codes) > 0:
        return (True, "%s %s choose %s" % (now_date, name, ",".join(codes)))
    else:
        return (False, "%s %s choose no stock" % (now_date, name))


if __name__ == '__main__':
    retCode, retMsg = run("http://www.iwencai.com/stockpick/search?typed=1&preParams=&ts=1&f=1&qs=1&selfsectsn=&querytype=&searchfilter=&tid=stockpick&w=%E5%B8%82%E5%80%BC%E5%B0%8F%E4%BA%8E70%E4%BA%BF%2C%E6%80%BB%E8%82%A1%E6%9C%AC%E5%B0%8F%E4%BA%8E2%E4%BA%BF%EF%BC%8C%E9%9D%9E%E6%9C%BA%E6%A2%B0%E8%AE%BE%E5%A4%87%EF%BC%8C%E9%9D%9E%E6%9C%89%E8%89%B2%E9%87%91%E5%B1%9E%EF%BC%8C%E9%9D%9E%E5%8C%96%E5%B7%A5%EF%BC%8C%E9%9D%9E%E5%BB%BA%E7%AD%91%E8%A3%85%E9%A5%B0%EF%BC%8C%E9%9D%9E%E7%8E%AF%E4%BF%9D%EF%BC%8C%E6%80%BB%E5%B8%82%E5%80%BC%E4%BB%8E%E5%B0%8F%E5%88%B0%E5%A4%A7%E6%8E%92%E5%88%97%EF%BC%8C%E5%8C%97%E4%BA%AC%E6%88%96%E6%B7%B1%E5%9C%B3%E6%88%96%E4%B8%8A%E6%B5%B7%EF%BC%8C%E4%B8%8A%E5%B8%82%E6%97%B6%E9%97%B4%E5%A4%A7%E4%BA%8E2014%E5%B9%B46%E6%9C%881%E6%97%A5", "成长股")
    print retMsg