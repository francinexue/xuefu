# *基于pyalgotrade的股票&期货回测、模拟、交易框架（未完待续）* #
>- Too Long to refresh.很久没有更新。开放共享，共同进步。
>- 框架目标为使用pyalgotrade一揽子搞定股票和期货以及其他交易品种的交易、回测等内容，保证策略的复用性，通过修改参数即从回测切换至时盘
>- *技术问题需要讨论的请直接加群QQ群： 300349971，策略研究实践不吝赐教、讨论或需要技术支持的请加QQ：657959571*
>- 新版本即将更新，会有极大改动

## 新上传文件功能 ##
- ctp支持win32,64,linux64,并兼容vnpy代码，已编译通过，最近几天上传
- 添加docker环境配置，近期上传
- 开发环境改为linux系统
- dao目录添加mongodb支持，配置文件位于constant，已实现财报、日线等启动时自动更新功能，嫌过慢或卡顿请在源码中调节线程数或注释掉
- util文件formula中添加针对DataFrame的技术指标计算，使得即时不用ta-lib和pyalgotrade也能应用
- 添加ta-lib 以及ta-lib-pyalgotrade 两个版本的技术指标示例，位于strategy/kdj_new 中，其中kdj 的ta-lib不准
- 添加一使用布朗运动计算大盘牛熊线的应用，名称bbcurve，书籍请看丁鹏量化技术研究，具体参数请自行调节，目测不错
- 后面把ctp和a股模拟实盘的例子加进来
- 使用事件驱动方式，开发中
- 准备测试多因子，开发中
# *以前内容* #
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

