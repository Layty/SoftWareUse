#ifndef __CMAKE_HINT_H__
#define __CMAKE_HINT_H__


/******************************************************************************************
    1. cmake ����
******************************************************************************************/
/*

1.1 ��ÿ��Դ��Ŀ¼�¶���һ�� CMakeLists.txt.
1.2 ����CMakeLists.txt�ļ�����Ŀ��Ŀ��һ������Ŀ¼�п�ָ����������Ŀ¼��
1.3 ����ĿCMakeLists.txt��ʹ��projectָ����Ŀ���ƣ�add_subdirectory�����Ŀ¼
1.4 ��Ŀ¼CMakeLists.txt���Ӹ�Ŀ¼CMakeLists.txt�̳����ã�TBD��������?1.5 CMake ��䲻���ִ�Сд�� һ��һ�У����н������ţ�ע����#
1.6 CMake ʵ��Ҳ��һ�ֱ�����ԡ� CMake ���� CMakeLists.txt �Զ����� Makefile.

1.7 ����ʹ��${}��ʽȡֵ�������� IF �������ֱ��ʹ�ñ�����ȡֵ
    MESSAGE(STATUS ��This is bin dir�� $(PROJECT_BINARY_DIR))
    MESSAGE(STATUS ��This is bin dir $(PROJECT_BINARY_DIR)��)
    ���������Ч��
1.8 ָ����� 1 ���� 2 ���� ,����֮���ÿո��ֺŸ�����
    SET( SRC_LIST main.cpp hello.cpp)
    SET(SRC_LIST ��main.cpp�� ��hello.cpp��)
    SET(SRC_LIST ��main.cpp��;��hello.cpp��)
1.9 �ڲ��������ⲿ���������ĸ�Ŀ¼��ִ�� cmake ����,�����ĸ�Ŀ¼����
    In-source����������ļ���Դ���ļ���ͬһĿ¼����(�ڹ���Ŀ¼�� cmake)
    Out-of-sourc:������Ŀ¼��Դ��Ŀ¼�ָ(�ڷǹ���Ŀ¼�� cmake)��

1.10 ������ʹ��set������ʽ���弰��ֵ���ڷ�if����У�ʹ��${}���ã�
     if��ֱ��ʹ�ñ��������ã�������set������������ԭ����ֵ��
1.11 command (args ...)  #����ִ�Сд������ʹ�ÿո�ָ���ʹ��˫������������пո�
1.12 set(var a;b;c) <=> set(var a b c)  #�������var����ֵΪa;b;c����һ��string list
1.13 Add_executable(${var}) <=> Add_executable(a b c)   #����ʹ��${xxx}����

1.14 ������䣺
    if(var) #var ��empty 0 N No OFF FALSE... #������ʹ��NOT
    ...
    else()
    ...
    elseif()
    ...
    endif(var)
    
1.15 ѭ�����
    set(var a b c)
    ...
    foreach(f ${var})
    ...
    endforeach(f)

1.16 ѭ�����
    while()
    �� 
    endwhile()
    
1.17 �������� ������Ϊ����ʹ��
    function(<name> [arg1 [arg2 [arg3 ...]]])
        COMMAND1(ARGS ...)
        COMMAND2(ARGS ...)
        ...  
    endfunction(<name>)
    
1.18 �궨��
     macro(<name> [arg1 [arg2 [arg3 ...]]])    
         COMMAND1(ARGS ...)    
         COMMAND2(ARGS ...)    
         ...  
     endmacro(<name>)

*/


/******************************************************************************************
    2. cmake �淶
******************************************************************************************/
/*
2.1 ����ȫ��ʹ��Сд
2.2 ���ñ��� ȫ��ʹ�ô�д
2.3 ���ó��� ȫ��ʹ�ô�д
*/
/******************************************************************************************
    3. cmake ����
******************************************************************************************/
/*
PROJECT_BINARY_DIR                      ����bin�ļ�Ŀ¼
PROJECT_SOURCE_DIR                      ����src�ļ�Ŀ¼
<project name>_BINARY_DIR               ��ò�Ҫ��
<project name>_SOURCE_DIR               ��ò�Ҫ��

CMAKE_BINARY_DIR
CMAKE_SOURCE_DIR
CMAKE_CURRENT_BINARY_DIR
CMAKE_CURRENT_SOURCE_DIR
CMAKE_CURRENT_LIST_FILE
CMAKE_CURRENT_LIST_LINE

LIBRARY_OUTPUT_PATH                     ���ļ�·��
CMAKE_BUILD_TYPE                        build ����(Debug, Release, ...)��CMAKE_BUILD_TYPE=Debug
BUILD_SHARED_LIBS                       Switch between shared and static libraries
EXECUTABLE_OUTPUT_PATH                  ��ִ���ļ�����Ŀ¼
LIBRARY_OUT_PATH                        ���ļ�����Ŀ¼
CMAKE_INSTALL_PREFIX
CMAKE_MODULE_PATH                       �����Լ��� CMake ģ������·��
PROJECT_NAME
CMAKE_INCLUDE_CURRENT_DIR
CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE

CMAKE_SYSTEM                            ϵͳ���ƣ��� Linux-2.6.26
CMAKE_SYSTEM_NAME                       ���� Linux
CMAKE_SYSTEM_VERSION                    ���� 2.6.26
CMAKE_SYSTEM_PROCESSOR                  ���� I386
CMAKE_MAJOR_VERSION                     CMake ���汾�ţ� 2.4.6 �е� 2
CMAKE_MINOR_VERSION                     CMake �ΰ汾�ţ� 2.4.6 �е� 4
CMAKE_PATCH_VERSION                     CMake �Ĳ����ȼ��� 2.4.6 �е� 6


CMAKE_C_COMPILER��ָ��C������
CMAKE_CXX_COMPILER��
CMAKE_C_FLAGS������C�ļ�ʱ��ѡ���-g��Ҳ����ͨ��add_definitions��ӱ���ѡ��

*/

/******************************************************************************************
    4. CMake �﷨��ָ��([]��ʾ��ѡ����)
******************************************************************************************/
/*
include_directories             ָ��ͷ�ļ�·����
link_directories                ָ�����ļ�·����
aux_source_directory            ����ǰĿ¼��.���е������ļ�����ֵ��APP_SRC��
set(EXECUTABLE_OUTPUT_PATH      ���ɵĿ�ִ���ļ���·����


cmake������ʹ�ã���cmake -DBUILD_SHARED_LIBS=OFF

��������
project (HELLO)   
	#ָ����Ŀ���ƣ����ɵ�VC��Ŀ�����ƣ�
	#ʹ��${HELLO_SOURCE_DIR}��ʾ��Ŀ��Ŀ¼
include_directories		
	ָ��ͷ�ļ�������·�����൱��ָ��gcc��-I����

include_directories 
(${HELLO_SOURCE_DIR}/Hello)  #����HelloΪincludeĿ¼

link_directories��
	��̬���ӿ��̬���ӿ������·�����൱��gcc��-L����

link_directories 
	(${HELLO_BINARY_DIR}/Hello)     #����HelloΪlinkĿ¼

add_subdirectory
	������Ŀ¼
add_subdirectory 

add_executable��
	�����ִ�г���ָ�����룬����Ҳ�������.o�ļ�
add_executable 
(helloDemo demo.cxx demo_b.cxx)   #��cxx����ɿ�ִ���ļ�����
add_definitions����ӱ������
add_definitions(-DDEBUG)����gcc���������DEBUG�궨�壻
add_definitions( ��-Wall -ansi �Cpedantic �Cg��)
target_link_libraries��������ӿ�,��ͬ��ָ��-l����
target_link_libraries(demo Hello) #����ִ���ļ���Hello���ӳ������ļ�demo
add_library:
add_library(Hello hello.cxx)  #��hello.cxx����ɾ�̬����libHello.a
add_custom_target:
message( status|fatal_error, ��message��):
set_target_properties( ... ): lots of properties... OUTPUT_NAME, VERSION, ....
link_libraries( lib1 lib2 ...): All targets link with the same set of libs


/******************************************************************************************
    5. CMake FAQ
******************************************************************************************/
/*

5.1 �������һ��Ŀ¼�µ�����Դ�ļ�
aux_source_directory(<dir> <variable>)
��dir������Դ�ļ���������ͷ�ļ������浽����variable�У�
Ȼ�����add_executable (ss7gw ${variable})����ʹ�á�

5.2 ����ָ����Ŀ����Ŀ��
project����ָ��

5.3 ������Ӷ�̬��;�̬��
target_link_libraries������Ӽ���

5.4 ������ִ��CMAKEʱ��ӡ��Ϣ
message([SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ...)


5.5 ����ָ��ͷ�ļ�����ļ�·��
include_directories��link_directories
���Զ�ε��������ö��·��
link_directories����������targets������

5.6 ��������debug��release�汾

����debug/release��Ŀ¼���ֱ�������ִ��cmake -DCMAKE_BUILD_TYPE=Debug����Release����
��Ҫ���벻ͬ�汾ʱ���벻ͬĿ¼ִ��make���ɣ�
Debug���ʹ�ò���-g��Release��ʹ��-O3 �CDNDEBUG
��һ�����÷�����������DEBUG�����ñ������DDEBUG

IF(DEBUG_mode)
    add_definitions(-DDEBUG)
ENDIF()
��ִ��cmakeʱ���Ӳ������ɣ�����cmake -D DEBUG_mode=ON

5.7 ����������������

����debug�����ñ���ѡ��DEBUG�����Ҹ��Ĳ�Ӧ�ı�CMakelist.txt
ʹ��option command��eg��

option(DEBUG_mode "ON for debug or OFF for release" ON)

IF(DEBUG_mode)
    add_definitions(-DDEBUG)
ENDIF()

5.8 ������ӱ���궨��
	ʹ��add_definitions����������˵��
5.9������ӱ���������
	����ȷ������Ŀ����Ŀǰ����������ȹ�����
	add_dependencies

5.10 ����ָ��Ŀ���ļ�Ŀ¼
����һ���µ�Ŀ¼���ڸ�Ŀ¼��ִ��cmake����Makefile�ļ���
�����������ᱣ���ڸ�Ŀ¼��������
SET_TARGET_PROPERTIES(ss7gw PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")

5.11 �ܶ��ļ��У��ѵ���Ҫ��ÿ���ļ��б����һ�����ļ���
 ���Բ�����Ŀ¼��ʹ��CMakeList.txt��ֱ�����ϲ�Ŀ¼��ָ����Ŀ¼
5.12 �����趨������cmake�汾
cmake_minimum_required(VERSION 2.6)
5.13 ���·����ôָ��
${projectname_SOURCE_DIR}��ʾ��Դ�ļ�Ŀ¼��${ projectname _BINARY_DIR}��ʾ���������ļ�Ŀ¼��
5.14 �������ñ����м��ļ���Ŀ¼
5.15 ������IF�����ʹ���ִ������ֱȽ�
���ֱȽ�LESS��GREATER��EQUAL���ִ���STRLESS��STRGREATER��STREQUAL��
 Eg��
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)
set(AAA abc)
IF(AAA STREQUAL abc)
    message(STATUS "true")   #Ӧ�ô�ӡtrue
ENDIF()


5.17 �����ϰ�װ��VC7��VC8��CMAKE���Զ���������������������ָ��ĳ���汾��
5.18 ��������OSָ������ѡ��
    IF( APPLE ); IF( UNIX ); IF( WIN32 )
5.19 ������ӡmake�����
	 make VERBOSE=1

*/

/*
Task
1 ������ɫ���ؼ�����ɫ����������ɫ
2 �ڲ������Զ���ʾ ����˵��������
3 ���ٲ����
4��Sample �½�

�ű�ִ�У���������
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
    cmake �ڲ�����
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
    cmake ����
******************************************************************************************/
/** 
 * ���ù��̶�cmakeҪ�����Ͱ汾
 * @param  version �汾 VERSION 2.8
 * @note  cmake_minimum_required(VERSION 2.8)
 * @see "cmake_minimum_required(VERSION major[.minor[.patch[.tweak]]]"
 */
void cmake_minimum_required(var version);

/** 
 * ���幤������(�����������ɵ�Ŀ���ļ�������û���κι�ϵ��)
 * @param  projectname ��������
 * @param  �������� [��ѡ����]
 * @note ����ָ���������������� <projectname>_BINARY_DIR <projectname>_SOURCE_DIR
 * @see "project(<projectname> [CXX|C|Java])"
 */ 
void project(var projectname);

/** 
 * �Զ������ָ��
 * @param  level ��Ϣ����ȡֵΪ ([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR]
 * @param  var_name  ��������
 * @param  var_value  �ַ�������
 * @note set( SRC_LIST main.cpp hello.cpp)
 * @see "set(var [value] [cache type docstring[force]])"
 */ 
void set(var var_name, var var_value);
void unset(var var_name);

/** 
 * �����ʾ��Ϣ
 * @param  level ��Ϣ����ȡֵΪ ([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR]
 * @param  msg  �ַ�������
 * @note END_ERROR:�����������ɹ��̱�����
         STATUS:���ǰ׺Ϊ---����Ϣ
         FATAL_ERROR:������ֹ���� CMake����
 * @see MASSEGE([SEND_ERROR|STATUS|FATAL_ERROR]  ��massage to display�� ��)
 */ 
void message(int level,string msg);
 

/** 
 * ���ӿ�ִ��Ŀ���ļ� target �� source_file ����
 * @param  target ��Ϣ����ȡֵΪ ([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR]
 * @param  source_file  �ַ�������
 * @note END_ERROR:�����������ɹ��̱�����
         STATUS:���ǰ׺Ϊ---����Ϣ
         FATAL_ERROR:������ֹ���� CMake����
 * @see add_executable(target source_file��)
 */ 
void add_executable(var target,var source_file);
 

/** 
 * �����Ŀ¼������
 * @param  source_dir ��Ŀ¼����
 * @param  binary_dir  ��ѡ����
 * @note (��Ŀ¼����������CMakeLists.txt)
 * @see add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
 */ 
void add_subdirectory(var source_dir); 

/** 
 * ����Ŀ¼�����е�Դ�ļ� ����ӵ�������
 * @param  dir Ŀ¼����
 * @param  var_name  ������
 * @note 
 * @see  aux_source_directory(<dir> <variable>)
 */ 
void aux_source_directory(var dir,var var_name);

/** 
 * ���һ����Ŀ��
 * @param  name ��Ŀ¼����
 * @param  type  ������ STATIC|SHARED|MODULE
 * @param  src_list  Դ�ļ��б����
 * @note 
 * @see  add_library(<name> [STATIC|SHARED|MODULE] [EXCLUDE_FROM_ALL] source1 source2 ... sourceN)
 */ 
void add_library(var name,var type,var src_list); 

/** 
 * ��top level֮���������(����˳��)
 * @param  target_name  Ŀ������
 * @param  depend_target  ǰ������Ŀ������
 * @note  A top-level target is one created by ADD_EXECUTABLE, ADD_LIBRARY, or ADD_CUSTOM_TARGET.
 * @see  add_dependencies(target_name depend-target1 depend-target2 ...)
 */ 
void add_dependencies(var target_name,var depend_target);
/** 
 * �����Ŀ¼������
 * @param  source_dir ��Ŀ¼����
 * @param  binary_dir  ��ѡ����
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
 * ��Ŀ�����ӿ�
 * @param  target Ŀ������
 * @param  item1 item2  ������
 * @note 
 * @see target_link_libraries(<target> [item1 [item2 [...]]] [[debug|optimized|general] <item>] ...)
 */ 
void target_link_libraries();

/******************************************************************************************
   Utils Command
******************************************************************************************/

/** 
 * Export targets from the build tree for use by outside projects.
 * @param  target Ŀ������
 * @param  item1 item2  ������
 * @note 
 * @see export(TARGETS [target1 [target2 [...]]] [NAMESPACE <namespace>] [APPEND] FILE <filename> [EXPORT_LINK_INTERFACE_LIBRARIES])
 */
void export();  

/** 
 * List ��ز���
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
 * String ��ز���
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
 * �ļ������͹���
 * @param  target Ŀ������
 * @param  item1 item2  ������
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
 * �����Ŀ¼������
 * @param  source_dir ��Ŀ¼����
 * @param  binary_dir  ��ѡ����
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
 * INCLUDE ָ��������� CMakeLists.txt �ļ�
 * @param  source_dir ��Ŀ¼����
 * @param  binary_dir  ��ѡ����
 * @note 
 * @see  include(<file|module> [OPTIONAL] [RESULT_VARIABLE <VAR>] [NO_POLICY_SCOPE])
 */ 
void include();



/** 
 * ���ӱ���ѡ��
 * @param  target ��Ϣ����ȡֵΪ ([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR]
 * @param  source_file  �ַ�������
 * @return  none
 * @note ������
 * @see add_compile_options(target source_file��)
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

