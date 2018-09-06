/*
//******************************************************************************************
//	Project Task List 待处理--2018
//******************************************************************************************
项目|                           日期|                      任务|                               完成情况|
--------------------------------------------------------------------------------------------
部门
	招聘--简历检索
	招聘--精选笔试题目C/C++ java android linux 综合 业务)   
	代码评审结果公布 --ok
	部门服务器搜索优化--ok
	240 服务器速度优化  ---ok
	BL mmcp 代码优化---ok
	mmcp 自动构建服务器
	neo mixer 破解
	neo mixer 反编译
	码流分析工具 分析DSM-CC 有bug
	技术点收集

原计划未落实的任务：
    码流解析标准化任务
    切台统计CBB推行

===================BootLoader优化任务=====================================
BL MMCP：
1) BootLoader MMCP  代码风格优化  --邹国庆 --ok 集成自动代码格式化脚本
2) BootLoader MMCP  代码修改编译需要clean，编译速度慢  --邹国庆 
2) BootLoader MMCP  -Werror 开启 --- 邹国庆
3) BootLoader  MMCP 自动构建库系统 --邹国庆
4) Loader 界面优化   --邹国庆 ---ok
5) boot 开机进度条调整 模仿安卓  --邹国庆
6) boot 开机动画  --邹国庆
7) bootloader 工程 bin/目录 --邹国庆
8) 静态代码评审自动化

BL TOOLS:
1) libboost 库  --杨晓宇
2) convert 工具 ===> linux --杨晓宇---ok
3) 统计Windows工具转成linux --杨晓宇
4) sysinfo  sysconfig  ===> Linux --杨晓宇


BOOTER 移植CBB 及经验总结：
1) <编译、链接及链接脚本LDS培训>--杨晓宇 ---ok
2) 澜起Uboot 隐患
3) 测试用例报告放到 Proj 目录下
4) 第三方二级boot,芯片boot 不动
5) bootloader 开发版本 (A-13)
6) A5-13 板端加密 优化 

                    
SCV_N6772C_Hisi3716_IrdetoCCA
	死机及现场黑屏问题解决及评估 

N8783C_BCM75845_NAGRA_A9-1
	播放器升级频点的确定--OK
	Loader 测试用例及测试 ---OK
	CSBLGetIMBDestination 接口实现--OK
	DSI DII 机制修改，兼容以前的 ---OK
	可升级多种文件类型App和Loader及Firmware，其中Firmware和Loader 共用IMB类型，bin文件加头以区别--ok
	增加0xB1表的监听---OK
	复用Loader PT 保存PlantID---OK
	复用SysInfo 保存Platform—ID等三个参数---OK
	实现Loader 获取SN       CHIPID ---ok
	USB 升级---OK
	App触发升级,后门界面---ok
	增加按SN 升级  filter type 250，长度8字节
	完善BL说明文档 如何制作升级流 --ok
	IMB 升级界面提示信息---ok
	USB 检测很慢
	Loader 集成RF4CE遥控器，参数修改OTA--普通遥控器 ---ok
	增加TargetVer 设置接口获取接口--ok
    LoaderPT 序列化和反序列化--不修改，提供LoaderPT制作的工具--ok
    界面刷新缓慢，	Loader 界面美化及优化  --- ---ok
    客户要求的Loader 流程图 --- 进行中
    画界面需要在单线程里面 ---ok
    多语言字符串模块 ---ok
    客户化下载界面 ---ok
    客户化错误代码 ---ok
    绘图闪烁问题---ok
    usb 后门界面
    freetype2 
    同源OSD 验证
    指标测试 需要的升级码流 码率不能太高---ok
    多行打印
    
    Loader 指标测试
    发布一般BL 给应用

    第2次提交系统测试要求：
    1.放开打印
    2.需要验证构建的软件 app 能触发和升级 --ok
    多种CRC32 算法 py实现 ---ok

TCCL
	立项及人员安排，Flash裁剪方案选择
	无操作系统，线程移植到无线程      	      C语言跨平台协程  https://www.cnblogs.com/life2refuel/p/5888726.html
	
Nepal_N8774U_Ali3715_Conax
	客户OTA问题及软件释放

A5-14_N8786C
	App 进度跟进

Phonix                       
Ali3721 方案及VAST 认证评估
MMCP Cable Sat 没有区分


跟进问题：
1.KCCL 广告问题修改 5款型号
2.中南美 OTA---ok 
3.A5-11 CTI 广告系统

//******************************************************************************************
//	Owner Task List--2018
//******************************************************************************************
日期|       	任务|                                                      完成情况|
--------------------------------------------------------------------------------------------
2017.05.05 		Win32界面编程Sample   									CSGUIExample.c

2017.05.05 		OTT测试资源整理和测试用例
码流生成工具
1.快速帮助信息(MPEG/PSI/SI/Descriptor)
2.Section 原型使用json配置文件声明

ffmpeg demux pes es
es-->pes-->ts
mux
http://www.ffmpeg.org/documentation.html
https://www.cnblogs.com/lidabo/p/3754139.html
http://www.yeolar.com/note/2013/02/17/coroutines/

//******************************************************************************************
//	Daily Task List --2018
//******************************************************************************************
2018.07.23
升级死机老化验证
2018.07.24
代码评审
2018.07.25

2018.07.26

*/ //end of file 
