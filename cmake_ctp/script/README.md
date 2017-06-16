#### 代码封装生成器的脚本
在本文件下有7个脚本，主要用于生成boost.python对ctp提供的api的封装代码。本文主要对这七个脚本使用和说明进行一下简要的描述。

- apiDataType.pl < ThostFtdcUserApiDataType.h
这个脚本用于抽取ThostFtdcUserApiDataType.h文件中typedef的新类型与原类型的对应关系。我们需要对char[]需要专门处理，此脚本可以看到需要专门处理的类型名。

- structExporter.pl [ThostFtdcUserApiDataType.h] [ThostFtdcUserApiStruct.h] > exporter.txt
这个脚本用于对ThostFtdcUserApiStruct.h中定义的struct进行去掉"ThostFtdc"的命名和对char[]类型字段提供get／set方法。

- structWrapper.pl [ThostFtdcUserApiDataType.h] [ThostFtdcUserApiStruct.h] > wrapper.txt
这个脚本用于对ThostFtdcUserApiStruct.h中定义的struct对boost.python的提供封装的支持。

- extractType.sh (ThostFtdcMdApi.h | ThostFtdcTraderApi.h) > field.txt
这个脚本用于从ThostFtdcMdApi.h或ThostFtdcTraderApi.h中抽取出使用的struct名称，并将struct名的前缀ThostFtdc去掉。

- extractStructExporter.pl exporter.txt field.txt
从前面生成的exporter.txt中抽取出在field.txt中出现的结构的exporter。

- extractStructWrapper.pl wapper.txt field.txt
从前面生成的wrapper.txt中抽取出在field.txt中出现的结构的wapper。

- generate.pl (ThostFtdcMdApi.h | ThostFtdcTraderApi.h) 子类名 生成的文件们的前缀
需要三个参数，第一个是头文件，第二个是Api封装后的类名，第三个是产生的文件的后缀名，因为会产生多个文件。


#### 注意
有些字段在使用之前需要整个初始化为0，比如CThostFtdcInputOrderField和CThostFtdcInputOrderActionField。目前这两个字段在脚本中已经处理，如果调试运行中发现有不知名的错误，请验证是否也是因为字段需要初始化为0。


