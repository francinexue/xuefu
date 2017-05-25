# -*- coding:utf-8 -*-
import urllib, urllib2
from lxml import etree
import traceback


def get_wencai_stockcode(url, retry=5, max_num=30):
    """
    Collects a comma-separated set of hosts (host:port) and optionally
    randomize the returned list.
    """
    while retry > 0:
        try:
            req = urllib2.Request(url=url)
            req_data = urllib2.urlopen(req, timeout=30)
            res = req_data.read()

            dom = etree.HTML(res.decode("utf-8", 'ignore'))
            #code_xpath = "//*[@id=\"tableWrap\"]/div[2]/div/div[2]//td[3]/div" #还得自己改，让我还得学lxml和F12
            code_xpath = "//*[@id=\"tableWrap\"]/div[2]/div/div[2]//td[@width=\"66\"]/div"
            code_divs = dom.xpath(code_xpath)

            codes = [code_div.text for code_div in code_divs]
            return codes[:max_num]

        except:
            traceback.print_exc()
            retry -= 1


if __name__ == "__main__":
    codes = get_wencai_stockcode(
        "http://www.iwencai.com/stockpick/search?typed=0&preParams=&ts=1&f=1&qs=index_original&selfsectsn=&querytype=&searchfilter=&tid=stockpick&w=%E9%BE%99%E8%99%8E%E6%A6%9C%E4%B8%8A%E6%A6%9C%E4%B8%AA%E8%82%A1"
    )
    print str(codes)