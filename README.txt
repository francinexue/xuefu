简版code包含4个py文件，data、constant、pyalg2，pyalgo_test
1.下载数据：data.py
  调用tushare财经数据包接口，详细内容请读文档：http://pythonhosted.org/tushare/index.html#id2
  调用constant.py文件，存储部分下载时间的参数
  方法：
      1.sava_data():（需运行）
        下载全部tushare数据至d:/data/目录，格式为0004.csv
        code.csv为全部代码
        code_inuse.csv为过滤数据项较全的代码，可忽略
      2.refresh_data():
         每次下载以往数据设定了某一天，若需更新至当日，调用此方法
      3.plt_macd()
         算出macd并作图的示例
      4.change_type_to_yahoo():（需运行）
         下载完成后需调用此方法转换为pyalotrade可识别的类型，存储于d:/data2/,格式为0019.csv
         此处使用的为inuse数据，可以更改为code.csv
      5.get_beta():
        算beta示例
2.进行测试：pyalg_2.py
  调用pyalgotrade方法进行回测，详细内容请读文档：http://gbeced.github.io/pyalgotrade/docs/v0.17/html/tutorial.html
  调用pyalgo_test.py文件
  方法：
      1.提供两个测试方法： turtle_test():和vwap(plot):，底部有调用
3.回测主体pyalgo_test.py，
    主体位于onbar()方法，可使用self.__position和self.marketOrder(element, 100)两种方式，效果一样。
    注意onbar（）是一条条更新，故__init__()中的数据也是随着onbar的滚动而增加。
    如highlow.Low()最后一参数为存储数据个数，[-1]为当前运行结果，[-2]为上一次，用以调节窗口
  方法：
      1.SMACrossOver():
        示例方法
      2.VWAPMomentum():
        两只股票组合示例
      3.turtle():
        海龟交易法示例  
      
