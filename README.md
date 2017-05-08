# *写在前面* #
>- Too Long to refresh.很久没有更新。开放共享，共同进步。
>- *技术问题需要讨论的请直接加群QQ群： 300349971，策略研究实践不吝赐教、讨论或需要技术支持的请加QQ：657959571*
## 新上传文件功能 ##
- 开发环境改为linux系统
- dao目录添加mongodb支持，配置文件位于constant，已实现财报、日线等启动时自动更新功能，嫌过慢或卡顿请在源码中调节线程数或注释掉
- util文件formula中添加针对DataFrame的技术指标计算，使得即时不用ta-lib和pyalgotrade也能应用
- 添加ta-lib 以及ta-lib-pyalgotrade 两个版本的技术指标示例，位于strategy/kdj_new 中，其中kdj 的ta-lib不准
- 添加一使用布朗运动计算大盘牛熊线的应用，名称bbcurve，书籍请看丁鹏量化技术研究，具体参数请自行调节，目测不错
- 后面把ctp和a股模拟实盘的例子加进来
- 使用事件驱动方式，开发中
- 准备测试多因子，开发中
# *以前内容* #
>简版code包含4个py文件，data、constant、pyalg2，pyalgo_test
## 1.下载数据：data.py ##
  > - 调用tushare财经数据包接口，详细内容请读文档：[http://pythonhosted.org/tushare/index.html#id2]
  > - 调用constant.py文件，存储部分下载时间的参数
 
###  sava_data()（需运行） ###
- 下载全部tushare数据至d:/data/目录，格式为0004.csv
- code.csv为全部代码
- code_inuse.csv为过滤数据项较全的代码，可忽略，
- 示例csv在根目录，如果提示出错找不到，就把源文件那块的路径改成当前目录
### refresh_data() ###
- 每次下载以往数据设定了某一天，若需更新至当日，调用此方法
### plt_macd() ###
- 算出macd并作图的示例
### change_type_to_yahoo()(需运行） ###
- 下载完成后需调用此方法转换为pyalotrade可识别的类型，存储于d:/data2/,格式为0019.csv 
- **此处使用的为inuse数据，可以更改为code.csv**
### get_beta() ###
- 算beta示例

## 2.进行测试：pyalg_2.py ##
>- 根目录运行这个文件，其他的pyalgo_test.py，pyalg_util.py 不运行
- 调用pyalgotrade方法进行回测，详细内容请读文档：[http://gbeced.github.io/pyalgotrade/docs/v0.17/html/tutorial.html]
- 调用pyalgo_test.py文件
- 调用pyalg_util.py文件
### 方法 
- 提供两个测试方法： turtle_test():和vwap(plot):，底部有调用
- turrle_test 提供三种数据加载方式：csv，dataFrame，sql(未完成直接方式，暂由dataFrame为桥)
- dataFrame方式调用同目录util文件夹下的dataFrameBarfeed.py 和dataFramefeed.py
- sql方式数据来自data.sql_py**
## 3.回测主体pyalgo_test.py
>- 主体位于onbar()方法，可使用self.__position和self.marketOrder(element, 100)两种方式，效果一样。
>- 注意onbar（）是一条条更新，故__init__()中的数据也是随着onbar的滚动而增加。
>- 如highlow.Low()最后一参数为存储数据个数，[-1]为当前运行结果，[-2]为上一次，用以调节窗口
### 方法 ###
- 1.SMACrossOver():示例方法
- 2.VWAPMomentum():两只股票组合示例
- 3.turtle(): 海龟交易法示例  
## 4.最新版本已上传：pyalg_util.py ##
>- 添加运行时数据信息，格式为dic格式，包含retur、sharpratio、tradeInfo等
>- 调用方法见pyalg_2.py
>- 调用pyalgo_test.py文件
>- 需在pyalgo_test.py中添加addInfo信息，具体内容有注释
>
***注意：此方法只为监测数据并返回array，json等格式自己作图用。pyalgotrade本身已带作图方法及基础的信息。若不需要可删除调用部分：pyalg_util.py，pyalgo_test.py中的addInfo 方法，调用部分、getDateTimeSeries方法部分。***
## 5.目前支持同tushare中获取数据并存入数据库中 data_sql.py ##
> 数据库为postgress（已经支持pandas_dataFrame为桥进行pyalgotrade回测，代码见pyalg_2，直接读取功能开发中）
- 调用constant.py,数据库连接等设置在此处，其他数据库也一样
### 方法 ###
- 支持对h_data、hist_data、realtime_quotes等的get、set方法，其中set为获取数据并存入数据库中，get为获取数据库数据
- 详见方法内注释
