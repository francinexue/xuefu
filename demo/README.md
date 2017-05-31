## *示例集合* ##
>- 以可能进行测试所需要的功能点划分，根据编写策略可能出现的编程难点一一作示例
>- 每个示例里面的策略内容不是重点，当然也可以参考，15年写的版本比较粗糙

# *Demo* #
>- 展示了使用pyalgotrade获取历史数据进行回测、获取实时数据进行模拟、实盘测试的各类demo，现已有10多个，后期陆续添加，
   基本覆盖了pyalgotrade所有的方法示例,原作者没有Tick级的内容，现在已更新
### backtest文件夹 ###
>- 回测示例
- csvDemo:从csv读取数据并进行回测，策略为一不完善的海龟交易法
- pandasDemo:**使pyalgotrade支持pandas的示例，并包含从tushare直接读取数据和从csv读入到pandas两种方式**
  >- 提供两种数据调取方式，一种为系统自带画图，另一种提供array方式回测结果的各数据的接口，详见cn.lib.pyalg_utils.py,
  >- 注意：此方法只为监测数据并返回array，json等格式自己作图用。pyalgotrade本身已带作图方法及基础的信息。若不需要可删除调用部分：pyalg_util.py，pyalgo_test.py中的addInfo 方法，调用部分、getDateTimeSeries方法部分。
- sqlDemo:从数据库 postgres中读取或mongodb中读取两个示例
- porfolioDemo:多股票或合约回测策略，示例代码为简单的动量策略
- indexBBcurveDemo:指数择时策略示例，根据丁鹏-<量化投资策略与技术>书中描述的依据布朗运动计算牛熊线，判断大盘指数，并作为择时操作的依据，牛市、熊市、震荡市策略各有不同
此处择时买卖策略仅是简单的超过牛线则买入，跌破熊线则卖出
- minuWithDayDemo:日线和分钟线混合回测的例子，即本来使用5分钟线进行测试，但是中间还应用日线的各种指标，比如突破NN 日均线等
本例子是通过计算ENE轨道，对每日k线突破上轨，中轨，下轨等不同情形进行运算
- talibDemo:ta-lib示例，示例包含使用原生talib,pyalgotrade自带talib，调用自己写的util.formular中的公式,策略代码包含kdj aroon adx 3套策略示例
- tickDemo:tick级别回测示例，数据须包含至少ap1，av1,bp1,bv1,datetime五个数据
### live文件夹
>- 实时数据模拟测试示例，策略书写和回测一样
- tushareDemo:从tushare中接收5分钟，10,20,30,60，日线，周线等级别的实时数据并加载到pyalgotrade中进行模拟测试
- tushareTickDemo:从tushare中接收Tick级别的实时数据并加载到pyalgotrade中进行模拟测试