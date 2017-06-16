#### CTP封装,先git clone ctp 文件夹
本项目利用boost.python对上海期货交易所提供的ctp客户端进行了封装，将api中的结构体封装成python的类，行情API封装成CtpMd和交易API封装成CtpTd。

##### 本项目编译
1. 安装cmake.
1. 系统上需要安装python。
2. 安装boost.python，步骤如下：
    1. 下载boost，并解压缩。
    2. 启动命令行环境。
        - windows：依赖于vcvarsall，请在visual studio命令下查找。
            - 若要针对面向 x64 平台的 64 位命令行生成配置此命令提示符窗口，请在命令提示符处输入：`vcvarsall amd64`。
            - 若要针对面向 x86 平台的 64 位命令行生成配置此命令提示符窗口，请在命令提示符处输入：`vcvarsall amd64_x86`。
            - 若要针对面向 ARM 平台的 64 位命令行生成配置此命令提示符窗口，请在命令提示符处输入：`vcvarsall amd64_arm`。
    2. cd boost_x_xx_x && ./bootstrap.bat --prefix=c:/boost
    3. 需要在bootstrap.bat的输出中指明的配置文件project-config.jam中添加如下一行配置：
        `using python : 2.7 : C:\\Python27 : C:\\Python27\\include : C:\\Python27\\libs ;`
    3. 执行如下命令进行编译,其中如果是64位python则需要address-model=64，32位python则不需要。
        `bjam install --toolset=msvc --with-python  --with-thread link=static threading=multi variant=release,debug runtime-link=static address-model=64`
    


##### 注意
linux下的包需要对这两个文件进行重命名。
- thostmduserapi.so --> libthostmduserapi.so
- thosttraderapi.so --> libthosttraderapi.so