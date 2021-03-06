#ifndef __CMAKE_HINT_H__
#define __CMAKE_HINT_H__


/******************************************************************************************
    1. cmake 规则
******************************************************************************************/
/*

1.1 在每个源码目录下都有一个 CMakeLists.txt.
1.2 依赖CMakeLists.txt文件，项目主目标一个，主目录中可指定包含的子目录；
1.3 在项目CMakeLists.txt中使用project指定项目名称，add_subdirectory添加子目录
1.4 子目录CMakeLists.txt将从父目录CMakeLists.txt继承设置（TBD，待检验?1.5 CMake 语句不区分大小写。 一句一行，无行结束符号，注释用#
1.6 CMake 实际也是一种编程语言。 CMake 根据 CMakeLists.txt 自动生成 Makefile.

1.7 变量使用${}方式取值，但是在 IF 语句中是直接使用变量名取值
    MESSAGE(STATUS “This is bin dir” $(PROJECT_BINARY_DIR))
    MESSAGE(STATUS “This is bin dir $(PROJECT_BINARY_DIR)”)
    上面两句等效。
1.8 指令（参数 1 参数 2 …） ,参数之间用空格或分号隔开。
    SET( SRC_LIST main.cpp hello.cpp)
    SET(SRC_LIST “main.cpp” “hello.cpp”)
    SET(SRC_LIST “main.cpp”;“hello.cpp”)
1.9 内部构建和外部构建：在哪个目录下执行 cmake 命令,则在哪个目录构建
    In-source：编译过程文件和源码文件在同一目录下面(在工程目录下 cmake)
    Out-of-sourc:将编译目录和源码目录分割开(在非工程目录下 cmake)。

1.10 变量：使用set命令显式定义及赋值，在非if语句中，使用${}引用，
     if中直接使用变量名引用；后续的set命令会清理变量原来的值；
1.11 command (args ...)  #命令不分大小写，参数使用空格分隔，使用双引号引起参数中空格
1.12 set(var a;b;c) <=> set(var a b c)  #定义变量var并赋值为a;b;c这样一个string list
1.13 Add_executable(${var}) <=> Add_executable(a b c)   #变量使用${xxx}引用

1.14 条件语句：
    if(var) #var 非empty 0 N No OFF FALSE... #非运算使用NOT
    ...
    else()
    ...
    elseif()
    ...
    endif(var)
    
1.15 循环语句
    set(var a b c)
    ...
    foreach(f ${var})
    ...
    endforeach(f)

1.16 循环语句
    while()
    … 
    endwhile()
    
1.17 函数定义 后续作为命令使用
    function(<name> [arg1 [arg2 [arg3 ...]]])
        COMMAND1(ARGS ...)
        COMMAND2(ARGS ...)
        ...  
    endfunction(<name>)
    
1.18 宏定义
     macro(<name> [arg1 [arg2 [arg3 ...]]])    
         COMMAND1(ARGS ...)    
         COMMAND2(ARGS ...)    
         ...  
     endmacro(<name>)

*/


/******************************************************************************************
    2. cmake 规范
******************************************************************************************/
/*
2.1 命令全部使用小写
2.2 内置变量 全部使用大写
2.3 内置常量 全部使用大写
*/
/******************************************************************************************
    3. cmake 变量
******************************************************************************************/
/*
PROJECT_BINARY_DIR                      工程bin文件目录
PROJECT_SOURCE_DIR                      工程src文件目录
<project name>_BINARY_DIR               最好不要用
<project name>_SOURCE_DIR               最好不要用

CMAKE_BINARY_DIR
CMAKE_SOURCE_DIR
CMAKE_CURRENT_BINARY_DIR
CMAKE_CURRENT_SOURCE_DIR
CMAKE_CURRENT_LIST_FILE
CMAKE_CURRENT_LIST_LINE

LIBRARY_OUTPUT_PATH                     库文件路径
CMAKE_BUILD_TYPE                        build 类型(Debug, Release, ...)，CMAKE_BUILD_TYPE=Debug
BUILD_SHARED_LIBS                       Switch between shared and static libraries
EXECUTABLE_OUTPUT_PATH                  可执行文件生成目录
LIBRARY_OUT_PATH                        库文件生成目录
CMAKE_INSTALL_PREFIX
CMAKE_MODULE_PATH                       定义自己的 CMake 模块所在路径
PROJECT_NAME
CMAKE_INCLUDE_CURRENT_DIR
CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE

CMAKE_SYSTEM                            系统名称，如 Linux-2.6.26
CMAKE_SYSTEM_NAME                       例如 Linux
CMAKE_SYSTEM_VERSION                    例如 2.6.26
CMAKE_SYSTEM_PROCESSOR                  例如 I386
CMAKE_MAJOR_VERSION                     CMake 主版本号， 2.4.6 中的 2
CMAKE_MINOR_VERSION                     CMake 次版本号， 2.4.6 中的 4
CMAKE_PATCH_VERSION                     CMake 的补丁等级， 2.4.6 中的 6


CMAKE_C_COMPILER：指定C编译器
CMAKE_CXX_COMPILER：
CMAKE_C_FLAGS：编译C文件时的选项，如-g；也可以通过add_definitions添加编译选项

*/

/******************************************************************************************
    4. CMake 语法及指令([]表示可选参数)
******************************************************************************************/
/*
include_directories             指定头文件路径；
link_directories                指定库文件路径；
aux_source_directory            将当前目录（.）中的所有文件名赋值给APP_SRC；
set(EXECUTABLE_OUTPUT_PATH      生成的可执行文件的路径，


cmake命令中使用，如cmake -DBUILD_SHARED_LIBS=OFF

六、命令
project (HELLO)   
	#指定项目名称，生成的VC项目的名称；
	#使用${HELLO_SOURCE_DIR}表示项目根目录
include_directories		
	指定头文件的搜索路径，相当于指定gcc的-I参数

include_directories 
(${HELLO_SOURCE_DIR}/Hello)  #增加Hello为include目录

link_directories：
	动态链接库或静态链接库的搜索路径，相当于gcc的-L参数

link_directories 
	(${HELLO_BINARY_DIR}/Hello)     #增加Hello为link目录

add_subdirectory
	包含子目录
add_subdirectory 

add_executable：
	编译可执行程序，指定编译，好像也可以添加.o文件
add_executable 
(helloDemo demo.cxx demo_b.cxx)   #将cxx编译成可执行文件——
add_definitions：添加编译参数
add_definitions(-DDEBUG)将在gcc命令行添加DEBUG宏定义；
add_definitions( “-Wall -ansi –pedantic –g”)
target_link_libraries：添加链接库,相同于指定-l参数
target_link_libraries(demo Hello) #将可执行文件与Hello连接成最终文件demo
add_library:
add_library(Hello hello.cxx)  #将hello.cxx编译成静态库如libHello.a
add_custom_target:
message( status|fatal_error, “message”):
set_target_properties( ... ): lots of properties... OUTPUT_NAME, VERSION, ....
link_libraries( lib1 lib2 ...): All targets link with the same set of libs


/******************************************************************************************
    5. CMake FAQ
******************************************************************************************/
/*

5.1 怎样获得一个目录下的所有源文件
aux_source_directory(<dir> <variable>)
将dir中所有源文件（不包括头文件）保存到变量variable中，
然后可以add_executable (ss7gw ${variable})这样使用。

5.2 怎样指定项目编译目标
project命令指定

5.3 怎样添加动态库和静态库
target_link_libraries命令添加即可

5.4 怎样在执行CMAKE时打印消息
message([SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ...)


5.5 怎样指定头文件与库文件路径
include_directories与link_directories
可以多次调用以设置多个路径
link_directories仅对其后面的targets起作用

5.6 怎样区分debug、release版本

建立debug/release两目录，分别在其中执行cmake -DCMAKE_BUILD_TYPE=Debug（或Release），
需要编译不同版本时进入不同目录执行make即可；
Debug版会使用参数-g；Release版使用-O3 –DNDEBUG
另一种设置方法——例如DEBUG版设置编译参数DDEBUG

IF(DEBUG_mode)
    add_definitions(-DDEBUG)
ENDIF()
在执行cmake时增加参数即可，例如cmake -D DEBUG_mode=ON

5.7 怎样设置条件编译

例如debug版设置编译选项DEBUG，并且更改不应改变CMakelist.txt
使用option command，eg：

option(DEBUG_mode "ON for debug or OFF for release" ON)

IF(DEBUG_mode)
    add_definitions(-DDEBUG)
ENDIF()

5.8 怎样添加编译宏定义
	使用add_definitions命令，见命令部分说明
5.9怎样添加编译依赖项
	用于确保编译目标项目前依赖项必须先构建好
	add_dependencies

5.10 怎样指定目标文件目录
建立一个新的目录，在该目录中执行cmake生成Makefile文件，
这样编译结果会保存在该目录——类似
SET_TARGET_PROPERTIES(ss7gw PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")

5.11 很多文件夹，难道需要把每个文件夹编译成一个库文件？
 可以不在子目录中使用CMakeList.txt，直接在上层目录中指定子目录
5.12 怎样设定依赖的cmake版本
cmake_minimum_required(VERSION 2.6)
5.13 相对路径怎么指定
${projectname_SOURCE_DIR}表示根源文件目录，${ projectname _BINARY_DIR}表示根二进制文件目录？
5.14 怎样设置编译中间文件的目录
5.15 怎样在IF语句中使用字串或数字比较
数字比较LESS、GREATER、EQUAL，字串比STRLESS、STRGREATER、STREQUAL，
 Eg：
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)
set(AAA abc)
IF(AAA STREQUAL abc)
    message(STATUS "true")   #应该打印true
ENDIF()


5.17 机器上安装了VC7和VC8，CMAKE会自动搜索编译器，但是怎样指定某个版本？
5.18 怎样根据OS指定编译选项
    IF( APPLE ); IF( UNIX ); IF( WIN32 )
5.19 怎样打印make的输出
	 make VERBOSE=1

*/

/*
Task
1 语音着色，关键字着色，控制字着色
2 内部函数自动提示 函数说明及帮助
3 快速插入块
4、Sample 新建

脚本执行，参数设置
*/
/******************************************************************************************
    Const
******************************************************************************************/

#define ON        1
#define OFF       0 
/******************************************************************************************
    Type && Struct 
******************************************************************************************/
typedef   void* var;


/******************************************************************************************
    cmake 内部变量
******************************************************************************************/

const var  PROJECT_BINARY_DIR;        ///<              
const var  PROJECT_SOURCE_DIR;          ///<             


const var  CMAKE_BINARY_DIR;///< 
const var  CMAKE_SOURCE_DIR;///< 
const var  CMAKE_CURRENT_BINARY_DIR;///< 
const var  CMAKE_CURRENT_SOURCE_DIR;///< 
const var  CMAKE_CURRENT_LIST_FILE;///< 
const var  CMAKE_CURRENT_LIST_LINE;///< 

const var  LIBRARY_OUTPUT_PATH;     ///<                
const var  CMAKE_BUILD_TYPE;      ///<                  
const var  BUILD_SHARED_LIBS;      ///<                 
const var  EXECUTABLE_OUTPUT_PATH; ///<                 
const var  LIBRARY_OUT_PATH;      ///<                  
const var  CMAKE_INSTALL_PREFIX;///< 
const var  CMAKE_MODULE_PATH;  ///<                     
const var  PROJECT_NAME;///< 
const var  CMAKE_INCLUDE_CURRENT_DIR;///< 

const var  CMAKE_SYSTEM;       ///<                     
const var  CMAKE_SYSTEM_NAME;                      
const var  CMAKE_SYSTEM_VERSION;                   
const var  CMAKE_SYSTEM_PROCESSOR;                 
const var  CMAKE_MAJOR_VERSION;                    
const var  CMAKE_MINOR_VERSION;                    
const var  CMAKE_PATCH_VERSION;

public class var
{
	public:
	const var  PROJECT_BINARY_DIR;        ///<              
	const var  PROJECT_SOURCE_DIR;          ///<             


	const var  CMAKE_BINARY_DIR;///< 
	const var  CMAKE_SOURCE_DIR;///< 
	const var  CMAKE_CURRENT_BINARY_DIR;///< 
	const var  CMAKE_CURRENT_SOURCE_DIR;///< 
	const var  CMAKE_CURRENT_LIST_FILE;///< 
	const var  CMAKE_CURRENT_LIST_LINE;///< 

	const var  LIBRARY_OUTPUT_PATH;     ///<                
	const var  CMAKE_BUILD_TYPE;      ///<                  
	const var  BUILD_SHARED_LIBS;      ///<                 
	const var  EXECUTABLE_OUTPUT_PATH; ///<                 
	const var  LIBRARY_OUT_PATH;      ///<                  
	const var  CMAKE_INSTALL_PREFIX;///< 
	const var  CMAKE_MODULE_PATH;  ///<                     
	const var  PROJECT_NAME;///< 
	const var  CMAKE_INCLUDE_CURRENT_DIR;///< 

	const var  CMAKE_SYSTEM;       ///<                     
	const var  CMAKE_SYSTEM_NAME;                      
	const var  CMAKE_SYSTEM_VERSION;                   
	const var  CMAKE_SYSTEM_PROCESSOR;                 
	const var  CMAKE_MAJOR_VERSION;                    
	const var  CMAKE_MINOR_VERSION;                    
	const var  CMAKE_PATCH_VERSION;	
};

/******************************************************************************************
    cmake 命令
******************************************************************************************/
/** 
 * 设置工程对cmake要求的最低版本
 * @param  version 版本 VERSION 2.8
 * @note  cmake_minimum_required(VERSION 2.8)
 * @see "cmake_minimum_required(VERSION major[.minor[.patch[.tweak]]]"
 */
void cmake_minimum_required(var version);

/** 
 * 定义工程名称(工程名与生成的目标文件名称是没有任何关系的)
 * @param  projectname 工程名称
 * @param  语言类型 [可选参数]
 * @note 此条指令隐含了两个变量 <projectname>_BINARY_DIR <projectname>_SOURCE_DIR
 * @see "project(<projectname> [CXX|C|Java])"
 */ 
void project(var projectname);

/** 
 * 自定义变量指令
 * @param  level 消息级别取值为 ([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR]
 * @param  var_name  变量名称
 * @param  var_value  字符串内容
 * @note set( SRC_LIST main.cpp hello.cpp)
 * @see "set(var [value] [cache type docstring[force]])"
 */ 
void set(var var_name, var var_value);
void unset(var var_name);

/** 
 * 输出提示信息
 * @param  level 消息级别取值为 ([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR]
 * @param  msg  字符串内容
 * @note END_ERROR:产生错误，生成过程被跳过
         STATUS:输出前缀为---的信息
         FATAL_ERROR:立即终止所有 CMake过程
 * @see MASSEGE([SEND_ERROR|STATUS|FATAL_ERROR]  “massage to display” …)
 */ 
void message(int level,string msg);
 

/** 
 * 增加可执行目标文件 target 由 source_file 生成
 * @param  target 消息级别取值为 ([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR]
 * @param  source_file  字符串内容
 * @note END_ERROR:产生错误，生成过程被跳过
         STATUS:输出前缀为---的信息
         FATAL_ERROR:立即终止所有 CMake过程
 * @see add_executable(target source_file…)
 */ 
void add_executable(var target,var source_file);
 

/** 
 * 添加子目录到构建
 * @param  source_dir 子目录名称
 * @param  binary_dir  可选参数
 * @note (子目录顶层必须包含CMakeLists.txt)
 * @see add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
 */ 
void add_subdirectory(var source_dir); 

/** 
 * 查找目录下所有的源文件 并添加到变量里
 * @param  dir 目录名称
 * @param  var_name  变量名
 * @note 
 * @see  aux_source_directory(<dir> <variable>)
 */ 
void aux_source_directory(var dir,var var_name);

/** 
 * 添加一个库目标
 * @param  name 子目录名称
 * @param  type  库类型 STATIC|SHARED|MODULE
 * @param  src_list  源文件列表变量
 * @note 
 * @see  add_library(<name> [STATIC|SHARED|MODULE] [EXCLUDE_FROM_ALL] source1 source2 ... sourceN)
 */ 
void add_library(var name,var type,var src_list); 

/** 
 * 在top level之间添加依赖(编译顺序)
 * @param  target_name  目标名称
 * @param  depend_target  前置依赖目标名称
 * @note  A top-level target is one created by ADD_EXECUTABLE, ADD_LIBRARY, or ADD_CUSTOM_TARGET.
 * @see  add_dependencies(target_name depend-target1 depend-target2 ...)
 */ 
void add_dependencies(var target_name,var depend_target);
/** 
 * 添加子目录到构建
 * @param  source_dir 子目录名称
 * @param  binary_dir  可选参数
 * @note 
 * @see add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
 */ 


void include_directories();  
void include_external_msproject();  
void include_regular_expression(); 

void link_directories();  
void target_compile_definitions(); 
void target_compile_options(); 
void target_include_directories();

/** 
 * 给目标链接库
 * @param  target 目标名称
 * @param  item1 item2  库名称
 * @note 
 * @see target_link_libraries(<target> [item1 [item2 [...]]] [[debug|optimized|general] <item>] ...)
 */ 
void target_link_libraries();

/******************************************************************************************
   Utils Command
******************************************************************************************/

/** 
 * Export targets from the build tree for use by outside projects.
 * @param  target 目标名称
 * @param  item1 item2  库名称
 * @note 
 * @see export(TARGETS [target1 [target2 [...]]] [NAMESPACE <namespace>] [APPEND] FILE <filename> [EXPORT_LINK_INTERFACE_LIBRARIES])
 */
void export();  

/** 
 * List 相关操作
 * @param  none
 * @note 
 * @see  list(LENGTH <list> <output variable>)  
		 list(GET <list> <element index> [<element index> ...] <output variable>)  
		 list(APPEND <list> <element> [<element> ...])  
		 list(FIND <list> <value> <output variable>)  
		 list(INSERT <list> <element_index> <element> [<element> ...])  
		 list(REMOVE_ITEM <list> <value> [<value> ...])  
		 list(REMOVE_AT <list> <index> [<index> ...])  
		 list(REMOVE_DUPLICATES <list>)  
		 list(REVERSE <list>)  
		 list(SORT <list>)
 */

/** 
 * String 相关操作
 * @param  none
 * @note 
 * @see string(REGEX MATCH <regular_expression> <output variable> <input> [<input>...])  
		string(REGEX MATCHALL <regular_expression>  <output variable> <input> [<input>...])  
		string(REGEX REPLACE <regular_expression>  <replace_expression> <output variable> <input> [<input>...])  
		string(REPLACE <match_string> <replace_string> <output variable> <input> [<input>...])  
		string(<MD5|SHA1|SHA224|SHA256|SHA384|SHA512>         <output variable> <input>)  
		string(COMPARE EQUAL <string1> <string2> <output variable>)  
		string(COMPARE NOTEQUAL <string1> <string2> <output variable>)  
		string(COMPARE LESS <string1> <string2> <output variable>)  
		string(COMPARE GREATER <string1> <string2> <output variable>)  
		string(ASCII <number> [<number> ...] <output variable>)  
		string(CONFIGURE <string1> <output variable> [@ONLY] [ESCAPE_QUOTES])  
		string(TOUPPER <string1> <output variable>)  
		string(TOLOWER <string1> <output variable>)  
		string(LENGTH <string> <output variable>)  
		string(SUBSTRING <string> <begin> <length> <output variable>)  
		string(STRIP <string> <output variable>)  
		string(RANDOM [LENGTH <length>] [ALPHABET <alphabet>] [RANDOM_SEED <seed>] <output variable>)  
		string(FIND <string> <substring> <output variable> [REVERSE])  
		string(TIMESTAMP <output variable> [<format string>] [UTC])  
		string(MAKE_C_IDENTIFIER <input string> <output variable>)
 */
void string();

void list();


/** 
 * 文件操作和管理
 * @param  target 目标名称
 * @param  item1 item2  库名称
 * @note 
 * @see 
   file(WRITE filename "message to write"... )  
   file(APPEND filename "message to write"... )  
   file(READ filename variable [LIMIT numBytes] [OFFSET offset] [HEX])  
   file(<MD5|SHA1|SHA224|SHA256|SHA384|SHA512> filename variable)  
   file(STRINGS filename variable [LIMIT_COUNT num] [LIMIT_INPUT numBytes]
                                  [LIMIT_OUTPUT numBytes] [LENGTH_MINIMUM numBytes][LENGTH_MAXIMUM numBytes]
                                  [NEWLINE_CONSUME] [REGEX regex][NO_HEX_CONVERSION])  
   file(GLOB variable [RELATIVE path] [globbing expressions]...)  
   file(GLOB_RECURSE variable [RELATIVE path]        [FOLLOW_SYMLINKS] [globbing expressions]...)  
   file(RENAME <oldname> <newname>)  file(REMOVE [file1 ...])  
   file(REMOVE_RECURSE [file1 ...])  
   file(MAKE_DIRECTORY [directory1 directory2 ...])  
   file(RELATIVE_PATH variable directory file)  
   file(TO_CMAKE_PATH path result)  
   file(TO_NATIVE_PATH path result)  
   file(DOWNLOAD url file [INACTIVITY_TIMEOUT timeout]  
                          [TIMEOUT timeout] [STATUS status] 
                          [LOG log] [SHOW_PROGRESS]       
                          [EXPECTED_HASH ALGO=value] [EXPECTED_MD5 sum]       
                          [TLS_VERIFY on|off] [TLS_CAINFO file])  
   file(UPLOAD filename url [INACTIVITY_TIMEOUT timeout]  [TIMEOUT timeout] 
                            [STATUS status] [LOG log] [SHOW_PROGRESS])  
   file(TIMESTAMP filename variable [<format string>] [UTC])  
   file(GENERATE OUTPUT output_file   <INPUT input_file|CONTENT input_content>  
   									  [CONDITION expression])
 */
void file(); 



void find_file();  
void find_library();  
void find_package();  
void find_path();  
void find_program(); 


/******************************************************************************************
   property Command
******************************************************************************************/
void define_property(); 
/** 
 * 添加子目录到构建
 * @param  source_dir 子目录名称
 * @param  binary_dir  可选参数
 * @note 
 * @see add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
 */ 
void get_cmake_property();

void set_property(); 
void set_directory_properties(); 
void set_source_files_properties(); 
void set_target_properties(); 
void set_tests_properties(); 
   
void get_property(); 
void get_directory_property();  
void get_filename_component();  
void get_source_file_property();  
void get_target_property();  
void get_test_property();  





  
 
void enable_language(); 
void enable_testing();  
 

void execute_process();

 

/** 
 * INCLUDE 指令，用来载入 CMakeLists.txt 文件
 * @param  source_dir 子目录名称
 * @param  binary_dir  可选参数
 * @note 
 * @see  include(<file|module> [OPTIONAL] [RESULT_VARIABLE <VAR>] [NO_POLICY_SCOPE])
 */ 
void include();



/** 
 * 增加编译选项
 * @param  target 消息级别取值为 ([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR]
 * @param  source_file  字符串内容
 * @return  none
 * @note 不常用
 * @see add_compile_options(target source_file…)
 */ 
void add_compile_options();
void add_definitions(); 
void remove_definitions();  
void add_custom_command(); 
void add_custom_target(); 



// void build_command();  
// void cmake_host_system_information();  
// void cmake_policy();  
// void configure_file();  
// void create_test_sourcelist();

// void install();  
// void load_cache();  
// void load_command();  
// void mark_as_advanced();  
 

// void option();  
// void add_test();  
// void separate_arguments(); 

// void site_name(); 
// void source_group(); 

// void try_compile(); 
// void try_run(); 
// void variable_watch();
// void math(); 
// void qt_wrap_cpp();  
// void qt_wrap_ui(); 
// void fltk_wrap_ui(); 


#endif

