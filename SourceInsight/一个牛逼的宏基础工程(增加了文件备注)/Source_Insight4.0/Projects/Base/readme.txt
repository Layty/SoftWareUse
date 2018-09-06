Source Insight 宏功能
TODO:
1、google coding style 翻译(c,c++,java,python,shell) https://google.github.io/styleguide/
2、参考 eclipse的代码规范(注释规范，自动格式化代码，代码片段)

说明：
1、v3.5版本，全部em源代码使用ansi编码格式，v4.0 em 源代码全部使用UTF8 编码格式
2、代码风格自动格式化，自动代码检查风格(shell,python,c,cpp,java)


通用菜单的实现

目录及文件说明：
main.em						主入口
main_event_handler.em		事件触发钩子  需要SI开启事件触发
common_utils.em				通用接口
external_tool.em			外部工具接口
global_config.em			全局设置(author,mail,快捷键设置)
plugin.em					SISetting/Plguins 目录中工具使用
private_utils.em			自己实现的macro工具接口
public.em					通用的macro接口
public_help.em				SI 帮助信息
quick_nchar.em				删除文字，半个汉字问题 --ok
run_me.em					单个源代码的运行


目录:
language	           		目录是语言解析配置文件存储备份
basic	               		macro sample 仅供参考，不直接加入Base工程
cache	               		临时文件生成目录，仅help.txt,help.c,tmp.c,tmp.txt 空文件 加入版本控制
help	               		SI help	,Ascii table,Regular express,
project	               		项目相关的经验文档，工程
lang_ansi_c
lang_bash
lang_bat
lang_cmake
lang_cpp
lang_d
lang_doxy	           		@ 和\ 自动提示doxy 命令
lang_gradle
lang_java
lang_json
lang_lua
lang_makefile
lang_si_macro
lang_sql
lang_xml

========================================================================

每种语言目录包含，语言帮助，库函数帮助，代码片段，自动完成，
例如c/c++语言，
语言帮助----关键字 变量 运算符 字符串
库函数帮助
sample 帮助
关键字自动完成
代码片段
文件头，函数头自动生成
调试信息的插入
代码走读
静态代码审查


glibc
　　glibc是gnu发布的libc库，也即c运行库。
　　glibc是Linux系统中最底层的api（应用程序开发接口），
　　几乎其它任何的运行库都会依赖于glibc。
　　glibc除了封装linux操作系统所提供的系统服务外，
　　它本身也提供了许多其它一些必要功能服务的实现，主要的如下：
　　（1）string，字符串处理
　　（2）signal，信号处理
　　（3）dlfcn，管理共享库的动态加载
　　（4）direct，文件目录操作
　　（5）elf，共享库的动态加载器，也即interpreter
　　（6）iconv，不同字符集的编码转换
　　（7）inet，socket接口的实现
　　（8）intl，国际化，也即gettext的实现
　　（9）io
　　（10）linuxthreads
　　（11）locale，本地化
　　（12）login，虚拟终端设备的管理，及系统的安全访问
　　（13）malloc，动态内存的分配与管理
　　（14）nis
　　（15）stdlib，其它基本功能


Sourceinsight4.0对3.5的主要更新点在于:

1. 支持代码片段
2. 代码可折叠
3. 旁边有代码缩略图
4. 支持主题
5. 带文件和目录比较功能
6. 格式化代码
7. 导出成html
8. 更强的文件备份
9. 窗口有标签
10. 支持Unicode
11. 点击单词自动高亮相同单词
12.  配置保存格式为XML

以上加粗的是我认为非常重要的功能,本来3.5版本已经非常强悍,但配置是二进制格式,没有标签,不能识别UTF-8是我最大的痛点.

目前终于把痛点都解决了,4.0憋这么久果然还是有货的.

但是4.0目前仍旧没有解决输入法跟随, 最主要是目前版本居然不能使用QQ拼音输入法打字(微软的输入法倒是可以)
另外UTF-8是支持了, 但GBK却变成乱码不支持了.
推荐3.5和4.0一起使用, GBK就使用3.5, UTF-8就使用4.0.
PS: 代码应尽量使用UTF-8保存, UTF-8可兼容于IAR, VS, SI4, Linux, Sublime, Xcode等主流IDE或编辑器,可省去很多麻烦.

https://github.com/google/styleguide
eclipse http://eclipse-cs.sourceforge.net/update/


## 全局快捷键配置：
CTRL + ENTER     代码片段插入
ALT +  ENTER     关键字及单词智能补全
CTRL + ALT + O
CTRL + ALT + H   帮助信息菜单
CTRL + ALT + R   运行脚本(根据扩展名.sh,.py,.bat,.cmd,.c,.java,)
CTRL + ALT + T   测试macro

## SI 配置

## 帮助信息
* Source_Insight4.0\Projects\Base\help 常用的表格及帮助信息

## 工程信息
* 智能提示和补全
* Source_Insight4.0\Projects\Base\lang_auto_complete，利用.h头文件，增加智能提示的符号
项目打开的时候添加一个智能提示辅助文件，并同步
调用python查找和匹配完成


## 代码编辑
c/c++:
CTRL + Q  被选择代码 // 注释,扩展名识别差异
CTRL + 0  被选择代码 #if 0 ....#endif
CTRL + 1  被选择代码 #if 1 ....#endif
