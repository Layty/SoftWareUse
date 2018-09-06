/******************************************************************************************
    Source Insight 内部macro 函数声明
    声明在头文件，可以实现自动提示功能，但不会影响macro的运行
    内部函数全部使用字母大小开头(大驼峰)
******************************************************************************************/
#ifndef __DOXY_HELP_H__
#define __DOXY_HELP_H__

/*


//********************Doxygen**********************************
------------------------------------------------------------------------------
Doxygen 文档范例参考
------------------------------------------------------------------------------
http://www.icu-project.org/apiref/icu4c/index.html
http://www.vtk.org/doc/nightly/html/index.html
https://api.kde.org/

------------------------------------------------------------------------------
编译和构建
------------------------------------------------------------------------------
git clone https://github.com/doxygen/doxygen.git
cd doxygen
After that you can use
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
make install

------------------------------------------------------------------------------
编译和构建
------------------------------------------------------------------------------
便于代码和文档保持同步。
可以对文档做版本管理。

使用Doxygen生成文档，主要是两件事：

写一个配置文件（Doxyfile）。一般用Doxywizard生成后，再手工修改。
按照Doxygen的约定，将代码“文档化”。
然后只要执行命令：

doxygen Doxyfile
就可以了。输入文件、输出目录、参数等都是在Doxyfile中配置的。

Doxygen的配置文件


------------------------------------------------------------------------------
Graphviz 支持
------------------------------------------------------------------------------
http://www.graphviz.org/




------------------------------------------------------------------------------
Latex 的支持
------------------------------------------------------------------------------
http://www.latex-project.org/
一、原理解释
　　doxygen本身并不能直接输出pdf文件，而是生成了latex目录，其中有一个 makefile 文件。若系统中装好了pdflatex，可在latex目录中运行“make”命令来生成pdf文件。
　　怎样才能装好pdflatex呢？mac平台可安装MacTeX，windows平台可安装CTeX。

　　环境装好之后，当在latex目录中运行“make”命令来生成pdf文件时会发现——纯英文文档能顺利生成pdf；而含有中文时，不能顺利生成pdf文件。

　　对于latex排版，doxygen其实已经做了很多准备，比如——源文件是UTF-8编码，并默认使用了utf8 package。理论上是支持多国语言的。
　　可对于中文来说，还需要加载 CJKutf8 package，并配置好CJK环境。这才能顺利的使用中文。





------------------------------------------------------------------------------
文档注释
------------------------------------------------------------------------------
格式支持
可以在注释中加一些Doxygen支持的指令，主要作用是控制输出文档的排版格式，使用这些指令时需要在前面加上“\”或者“@”（JavaDoc风格）符号，告诉Doxygen这些是一些特殊的指令，通过加入这些指令以及配备相应的文字，可以生成更加丰富的文档，下面对比较常用的指令做一下简单介绍。
@file            档案的批注说明。
@author          作者的信息
@brief           用于class或function的简易说明eg：@brief本函数负责打印错误信息
@param           主要用于函数说明中，后面接参数的
@return          描述该函数的返回值情况 eg: @return?本函数返回执行结果 
@retval          描述返回值类型eg:@retval NULL?空字符串。@retval !NULL?非空字符串。
@note            注解
@attention       注意
@warning         警告信息
@enum            引用了某个枚举，Doxygen会在该枚 eg：@enum CTest::MyEnum
@var             引用了某个变量，Doxygen会在该枚 eg：@var CTest::m_FileKey
@class           引用某个类，格式：@class <name> [<header-file>] [<header-name>]eg: @class CTest "inc/class.h"
@exception       可能产生的异常描述eg:@exception?本函数执行可能会 

文件头注释
函数注释
宏注释  上方 \/** Description of the macro *\/,右方 ///< Description of the macro.
变量注释
类型注释
*/
/**
 * The brief description.
 * The detail description.
 */
 /*
http://www.stack.nl/~dimitri/doxygen/manual/preprocessing.html
------------------------------------------------------------------------------
Markdown 文档的支持
------------------------------------------------------------------------------
*/

/**
Doxygen  
Special Commands Introduction
All commands in the documentation start with a backslash (\) or an at-sign (@). If you prefer you can replace all commands starting with a backslash below by their counterparts that start with an at-sign.

Some commands have one or more arguments. Each argument has a certain range: 

?If <sharp> braces are used the argument is a single word. 
?If (round) braces are used the argument extends until the end of the line on which the command was found. 
?If {curly} braces are used the argument extends until the next paragraph. Paragraphs are delimited by a blank line or by a section indicator. 
If in addition to the above argument specifiers [square] brackets are used the argument is optional.
*/
/******************************************************************************************
    文件注释
******************************************************************************************/
/**
* @file  CommonType.h  
* @brief 常见类型定义
* @author       Vincent
* @date     2015-5-24 
* @version  A001 
* @copyright Vincent                                                              
*/

/******************************************************************************************
    函数注释
******************************************************************************************/
/** 
 * 读取文件
 * @param[in]    fileNameLen    文件名长度
 * @param[in]   fileName    文件名
 * @param[in]    dataLen        数据长度
 * @param[out]  fileData    输出数据
 * @return        0，执行成功，非0，失败，详见
 * @ref            RetCode.h
 * @see
 * @note
 */ 
UINT ReadFile(UINT fileNameLen, BYTE *fileName, UINT dataLen, BYTE *fileData);

/******************************************************************************************
    枚举结构注释
******************************************************************************************/
/**  枚举类型*/  
enum COLOR{
    RED=0,    ///<  红色 
    GREEN=1,///<  绿色 
    YELLOW=2///<  黄色 
};
/*

@attention  注意
@author  作者
@bug 缺陷  链接到所有缺陷汇总的缺陷列表
@brief 简要注释
@code 代码块开始，与“nendcode”成对使用
@details 详细注释
@date 日期
@endcode 代码块结束，与“ncode”成对使用
@file < 文件名> 文件参考 用在文件注释中
@param 参数 用在函数注释中
@return 返回 用在函数注释中
@todo
TODO链接到所有TODO 汇总的TODO 列表
@version 版本
@warning 警告
*/
@file 档案的批注说明。
@author 作者的信息
@brief 用于class 或function的简易说明
@param 主要用于函数说明中，后面接参数的名字，然后再接关于该参数的说明
@return 描述该函数的返回值情况
@retval 描述返回值类型
@note 注解
@attention 注意
@warning 警告信息
@enum引用了某个枚举，Doxygen会在该枚举处产生一个链接
@var 引用了某个变量，Doxygen会在该枚举处产生一个链接

@class 引用某个类，
格式：@class <name> [<header-file>] [<header-name>]

@exception 可能产生的异常描述



/******************************************************************************************
    Const
******************************************************************************************/



 

/******************************************************************************************
    String Function
******************************************************************************************/


class doxy
{
	
?\a
?\addindex
?\addtogroup
?\anchor
?\arg
?\attention
?\author
?\authors
?\b
?\brief
?\bug
?\c
?\callergraph
?\callgraph
?\category
?\cite
?\class
?\code
?\cond
?\copybrief
?\copydetails
?\copydoc
?\copyright
?\date
?\def
?\defgroup
?\deprecated
?\details
?\diafile
?\dir
?\docbookonly
?\dontinclude
?\dot
?\dotfile
?\e
?\else
?\elseif
?\em
?\endcode
?\endcond
?\enddocbookonly
?\enddot
?\endhtmlonly
?\endif
?\endinternal
?\endlatexonly
?\endlink
?\endmanonly
?\endmsc
?\endparblock
?\endrtfonly
?\endsecreflist
?\endverbatim
?\enduml
?\endxmlonly
?\enum
?\example
?\exception
?\extends
?\f$
?\f[
?\f]
?\f{
?\f}
?\file
?\fn
?\headerfile
?\hidecallergraph
?\hidecallgraph
?\hideinitializer
?\htmlinclude
?\htmlonly
?\idlexcept 
?\if
?\ifnot
?\image
?\implements
?\include
?\includedoc
?\includelineno
?\ingroup
?\internal
?\invariant
?\interface
?\latexinclude
?\latexonly
?\li
?\line
?\link
?\mainpage
?\manonly
?\memberof
?\msc
?\mscfile
?\n
?\name
?\namespace
?\nosubgrouping
?\note
?\overload
?\p
?\package
?\page
?\par
?\paragraph
?\param
?\parblock
?\post
?\pre
?\private
?\privatesection
?\property
?\protected
?\protectedsection
?\protocol
?\public
?\publicsection
?\pure
?\ref
?\refitem
?\related
?\relates
?\relatedalso
?\relatesalso
?\remark
?\remarks
?\result
?\return
?\returns
?\retval
?\rtfonly
?\sa
?\secreflist
?\section
?\see
?\short
?\showinitializer
?\since
?\skip
?\skipline
?\snippet
?\snippetdoc
?\snippetlineno
?\startuml
?\struct
?\subpage
?\subsection
?\subsubsection
?\tableofcontents
?\test
?\throw
?\throws
?\todo
?\tparam
?\typedef
?\union
?\until
?\var
?\verbatim
?\verbinclude
?\version
?\vhdlflow
?\warning
?\weakgroup
?\xmlonly
?\xrefitem

	class common
	{

	
	};

	
	class file
	{
	
	};

	
	class function
	{
	
	};

	
	class paragraph
	{
	
	};

	class format
	{
	
	};

	class html
	{
	
	};
	
	
	
};



\addtogroup <name> [(title)]
Defines a group just like \defgroup, but in contrast to that command using the same <name> more than once will not result in a warning, but rather one group with a merged documentation and the first title found in any of the commands.

The title is optional, so this command can also be used to add a number of entities to an existing group using @{ and @} like this:

  /*! \addtogroup mygrp
   *  Additional documentation for group 'mygrp'
   *  @{
   */

  /*!
   *  A function
   */
  void func1()
  {
  }

  /*! Another function */
  void func2()
  {
  }

  /*! @} */
See also
page Grouping, sections \defgroup, \ingroup, and \weakgroup.

--------------------------------------------------------------------------------

\callgraph
When this command is put in a comment block of a function or method and HAVE_DOT is set to YES, then doxygen will generate a call graph for that function (provided the implementation of the function or method calls other documented functions). The call graph will be generated regardless of the value of CALL_GRAPH. 

Note
The completeness (and correctness) of the call graph depends on the doxygen code parser which is not perfect.
See also
section \callergraph, section \hidecallgraph, section \hidecallergraph and option CALL_GRAPH

--------------------------------------------------------------------------------

\hidecallgraph
When this command is put in a comment block of a function or method and then doxygen will not generate a call graph for that function. The call graph will not be generated regardless of the value of CALL_GRAPH. 

Note
The completeness (and correctness) of the call graph depends on the doxygen code parser which is not perfect.
See also
section \callergraph, section \callgraph, section \hidecallergraph and option CALL_GRAPH

--------------------------------------------------------------------------------

\callergraph
When this command is put in a comment block of a function or method and HAVE_DOT is set to YES, then doxygen will generate a caller graph for that function (provided the implementation of the function or method calls other documented functions). The caller graph will be generated regardless of the value of CALLER_GRAPH. 

Note
The completeness (and correctness) of the caller graph depends on the doxygen code parser which is not perfect.
See also
section \callgraph, section \hidecallgraph, section \hidecallergraph and option CALLER_GRAPH

--------------------------------------------------------------------------------

\hidecallergraph
When this command is put in a comment block of a function or method and then doxygen will not generate a caller graph for that function. The caller graph will not be generated regardless of the value of CALLER_GRAPH. 

Note
The completeness (and correctness) of the caller graph depends on the doxygen code parser which is not perfect.
See also
section \callergraph, section \callgraph, section \hidecallgraph and option CALLER_GRAPH

--------------------------------------------------------------------------------

\category <name> [<header-file>] [<header-name>]
For Objective-C only: Indicates that a comment block contains documentation for a class category with name <name>. The arguments are equal to the \class command.

See also
section \class.

--------------------------------------------------------------------------------

\class <name> [<header-file>] [<header-name>]
Indicates that a comment block contains documentation for a class with name <name>. Optionally a header file and a header name can be specified. If the header-file is specified, a link to a verbatim copy of the header will be included in the HTML documentation. The <header-name> argument can be used to overwrite the name of the link that is used in the class documentation to something other than <header-file>. This can be useful if the include name is not located on the default include path (like <X11/X.h>). With the <header-name> argument you can also specify how the include statement should look like, by adding either quotes or sharp brackets around the name. Sharp brackets are used if just the name is given. Note that the last two arguments can also be specified using the \headerfile command.

Example:
/* A dummy class */

class Test
{
};

/*! \class Test class.h "inc/class.h"
 *  \brief This is a test class.
 *
 * Some details about the Test class.
 */
Click here for the corresponding HTML documentation that is generated by doxygen. 

--------------------------------------------------------------------------------

\def <name>
Indicates that a comment block contains documentation for a #define macro.

Example:
/*! \file define.h
    \brief testing defines
    
    This is to test the documentation of defines.
*/

/*!
  \def MAX(x,y)
  Computes the maximum of \a x and \a y.
*/

/*! 
   Computes the absolute value of its argument \a x.
*/
#define ABS(x) (((x)>0)?(x):-(x))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)>(y)?(y):(x)) 
        /*!< Computes the minimum of \a x and \a y. */
Click here for the corresponding HTML documentation that is generated by doxygen. 

--------------------------------------------------------------------------------

\defgroup <name> (group title)
Indicates that a comment block contains documentation for a group of classes, files or namespaces. This can be used to categorize classes, files or namespaces, and document those categories. You can also use groups as members of other groups, thus building a hierarchy of groups.

The <name> argument should be a single-word identifier.

See also
page Grouping, sections \ingroup, \addtogroup, and \weakgroup.

--------------------------------------------------------------------------------

\dir [<path fragment>]
Indicates that a comment block contains documentation for a directory. The "path fragment" argument should include the directory name and enough of the path to be unique with respect to the other directories in the project. The STRIP_FROM_PATH option determines what is stripped from the full path before it appears in the output.


--------------------------------------------------------------------------------

\enum <name>
Indicates that a comment block contains documentation for an enumeration, with name <name>. If the enum is a member of a class and the documentation block is located outside the class definition, the scope of the class should be specified as well. If a comment block is located directly in front of an enum declaration, the \enum comment may be omitted.

Note:
The type of an anonymous enum cannot be documented, but the values of an anonymous enum can.
Example:
class Enum_Test
{
  public:
    enum TEnum { Val1, Val2 };

    /*! Another enum, with inline docs */
    enum AnotherEnum 
    { 
      V1, /*!< value 1 */
      V2  /*!< value 2 */
    };
};

/*! \class Enum_Test
 * The class description.
 */

/*! \enum Enum_Test::TEnum
 * A description of the enum type.
 */

/*! \var Enum_Test::TEnum Enum_Test::Val1
 * The description of the first enum value.
 */
Click here for the corresponding HTML documentation that is generated by doxygen. 

--------------------------------------------------------------------------------

\example <file-name>
Indicates that a comment block contains documentation for a source code example. The name of the source file is <file-name>. The text of this file will be included in the documentation, just after the documentation contained in the comment block. All examples are placed in a list. The source code is scanned for documented members and classes. If any are found, the names are cross-referenced with the documentation. Source files or directories can be specified using the EXAMPLE_PATH tag of doxygen's configuration file.

If <file-name> itself is not unique for the set of example files specified by the EXAMPLE_PATH tag, you can include part of the absolute path to disambiguate it.

If more than one source file is needed for the example, the \include command can be used.

Example:
/** A Example_Test class.
 *  More details about this class.
 */

class Example_Test
{
  public:
    /** An example member function.
     *  More details about this function.
     */
    void example();
};

void Example_Test::example() {}

/** \example example_test.cpp
 * This is an example of how to use the Example_Test class.
 * More details about this example.
 */
Where the example file example_test.cpp looks as follows: 
void main()
{
  Example_Test t;
  t.example();
}
Click here for the corresponding HTML documentation that is generated by doxygen. 
See also
section \include.

--------------------------------------------------------------------------------

\endinternal
This command ends a documentation fragment that was started with a \internal command. The text between \internal and \endinternal will only be visible if INTERNAL_DOCS is set to YES.


--------------------------------------------------------------------------------

\extends <name>
This command can be used to manually indicate an inheritance relation, when the programming language does not support this concept natively (e.g. C).

The file manual.c in the example directory shows how to use this command.

Click here for the corresponding HTML documentation that is generated by doxygen. 

See also
section \implements and section \memberof

--------------------------------------------------------------------------------

\file [<name>]
Indicates that a comment block contains documentation for a source or header file with name <name>. The file name may include (part of) the path if the file-name alone is not unique. If the file name is omitted (i.e. the line after \file is left blank) then the documentation block that contains the \file command will belong to the file it is located in.

Important:
The documentation of global functions, variables, typedefs, and enums will only be included in the output if the file they are in is documented as well.
Example:
/** \file file.h
 * A brief file description.
 * A more elaborated file description.
 */

/**
 * A global integer value.
 * More details about this value.
 */
extern int globalValue;
Click here for the corresponding HTML documentation that is generated by doxygen. 
Note
In the above example JAVADOC_AUTOBRIEF has been set to YES in the configuration file.

--------------------------------------------------------------------------------

\fn (function declaration)
Indicates that a comment block contains documentation for a function (either global or as a member of a class). This command is only needed if a comment block is not placed in front (or behind) the function declaration or definition.

If your comment block is in front of the function declaration or definition this command can (and to avoid redundancy should) be omitted.

A full function declaration including arguments should be specified after the \fn command on a single line, since the argument ends at the end of the line!

This command is equivalent to \var, \typedef, and \property.

Warning
Do not use this command if it is not absolutely needed, since it will lead to duplication of information and thus to errors.
Example:
class Fn_Test
{
  public:
    const char *member(char,int) throw(std::out_of_range);
};

const char *Fn_Test::member(char c,int n) throw(std::out_of_range) {}

/*! \class Fn_Test
 * \brief Fn_Test class.
 *
 * Details about Fn_Test.
 */

/*! \fn const char *Fn_Test::member(char c,int n) 
 *  \brief A member function.
 *  \param c a character.
 *  \param n an integer.
 *  \exception std::out_of_range parameter is out of range.
 *  \return a character pointer.
 */
Click here for the corresponding HTML documentation that is generated by doxygen. 
See also
sections \var, \property, and \typedef.

--------------------------------------------------------------------------------

\headerfile <header-file> [<header-name>]
Intended to be used for class, struct, or union documentation, where the documentation is in front of the definition. The arguments of this command are the same as the second and third argument of \class. The <header-file> name refers to the file that should be included by the application to obtain the definition of the class, struct, or union. The <header-name> argument can be used to overwrite the name of the link that is used in the class documentation to something other than <header-file>. This can be useful if the include name is not located on the default include path (like <X11/X.h>).

With the <header-name> argument you can also specify how the include statement should look like, by adding either double quotes or sharp brackets around the name. By default sharp brackets are used if just the name is given.

If a pair of double quotes is given for either the <header-file> or <header-name> argument, the current file (in which the command was found) will be used but with quotes. So for a comment block with a \headerfile command inside a file test.h, the following three commands are equivalent: 

  \headerfile test.h "test.h"
  \headerfile test.h ""
  \headerfile "" To get sharp brackets you do not need to specify anything, but if you want to be explicit you could use any of the following: 

  \headerfile test.h <test.h>
  \headerfile test.h <>
  \headerfile <> To globally reverse the default include representation to local includes you can set FORCE_LOCAL_INCLUDES to YES.

To disable the include information altogether set SHOW_INCLUDE_FILES to NO.


--------------------------------------------------------------------------------

\hideinitializer
By default the value of a define and the initializer of a variable are displayed unless they are longer than 30 lines. By putting this command in a comment block of a define or variable, the initializer is always hidden. The maximum number of initialization lines can be changed by means of the configuration parameter MAX_INITIALIZER_LINES, the default value is 30.

See also
section \showinitializer.

--------------------------------------------------------------------------------

\idlexcept <name>

Indicates that a comment block contains documentation for a IDL exception with name <name>.


--------------------------------------------------------------------------------

\implements <name>
This command can be used to manually indicate an inheritance relation, when the programming language does not support this concept natively (e.g. C).

The file manual.c in the example directory shows how to use this command.

Click here for the corresponding HTML documentation that is generated by doxygen. 

See also
section \extends and section \memberof

--------------------------------------------------------------------------------

\ingroup (<groupname> [<groupname> <groupname>])
If the \ingroup command is placed in a comment block of a class, file or namespace, then it will be added to the group or groups identified by <groupname>.

See also
page Grouping, sections \defgroup, \addtogroup, and \weakgroup

--------------------------------------------------------------------------------

\interface <name> [<header-file>] [<header-name>]
Indicates that a comment block contains documentation for an interface with name <name>. The arguments are equal to the arguments of the \class command.

See also
section \class.

--------------------------------------------------------------------------------

\internal
This command starts a documentation fragment that is meant for internal use only. The fragment naturally ends at the end of the comment block. You can also force the internal section to end earlier by using the \endinternal command.

If the \internal command is put inside a section (see for example \section) all subsections after the command are considered to be internal as well. Only a new section at the same level will end the fragment that is considered internal.

You can use INTERNAL_DOCS in the config file to show (YES) or hide (NO) the internal documentation.

See also
section \endinternal.

--------------------------------------------------------------------------------

\mainpage [(title)]

If the \mainpage command is placed in a comment block the block is used to customize the index page (in HTML) or the first chapter (in ).

The title argument is optional and replaces the default title that doxygen normally generates. If you do not want any title you can specify notitle as the argument of \mainpage.

Here is an example: 

/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */
You can refer to the main page using: \ref index.

See also
section \section, section \subsection, and section \page.

--------------------------------------------------------------------------------

\memberof <name>
This command makes a function a member of a class in a similar way as \relates does, only with this command the function is represented as a real member of the class. This can be useful when the programming language does not support the concept of member functions natively (e.g. C).

It is also possible to use this command together with \public, \protected or \private.

The file manual.c in the example directory shows how to use this command.

Click here for the corresponding HTML documentation that is generated by doxygen. 

See also
sections \extends, \implements, \public, \protected and \private.

--------------------------------------------------------------------------------

\name [(header)]

This command turns a comment block into a header definition of a member group. The comment block should be followed by a //@{ ... //@} block containing the members of the group.

See section Member Groups for an example.


--------------------------------------------------------------------------------

\namespace <name>
Indicates that a comment block contains documentation for a namespace with name <name>.


--------------------------------------------------------------------------------

\nosubgrouping
This command can be put in the documentation of a class. It can be used in combination with member grouping to avoid that doxygen puts a member group as a subgroup of a Public/Protected/Private/... section.

See also
sections \publicsection, \protectedsection and \privatesection.

--------------------------------------------------------------------------------

\overload [(function declaration)]
This command can be used to generate the following standard text for an overloaded member function:

This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts. 

If the documentation for the overloaded member function is not located in front of the function declaration or definition, the optional argument should be used to specify the correct function.

Any other documentation that is inside the documentation block will by appended after the generated message.

Note 1:
You are responsible that there is indeed an earlier documented member that is overloaded by this one. To prevent that document reorders the documentation you should set SORT_MEMBER_DOCS to NO in this case. 
Note 2:
The \overload command does not work inside a one-line comment. 
Example:
class Overload_Test 
{
  public:
    void drawRect(int,int,int,int);
    void drawRect(const Rect &r);
};

void Overload_Test::drawRect(int x,int y,int w,int h) {}
void Overload_Test::drawRect(const Rect &r) {}

/*! \class Overload_Test
 *  \brief A short description.
 *   
 *  More text.
 */

/*! \fn void Overload_Test::drawRect(int x,int y,int w,int h)
 * This command draws a rectangle with a left upper corner at ( \a x , \a y ),
 * width \a w and height \a h. 
 */

/*!
 * \overload void Overload_Test::drawRect(const Rect &r)
 */

Click here for the corresponding HTML documentation that is generated by doxygen. 

--------------------------------------------------------------------------------

\package <name>
Indicates that a comment block contains documentation for a Java package with name <name>.


--------------------------------------------------------------------------------

\page <name> (title)
Indicates that a comment block contains a piece of documentation that is not directly related to one specific class, file or member. The HTML generator creates a page containing the documentation. The  generator starts a new section in the chapter 'Page documentation'.

Example:
/*! \page page1 A documentation page
  \tableofcontents
  Leading text.
  \section sec An example section
  This page contains the subsections \ref subsection1 and \ref subsection2.
  For more info see page \ref page2.
  \subsection subsection1 The first subsection
  Text.
  \subsection subsection2 The second subsection
  More text.
*/

/*! \page page2 Another page
  Even more info.
*/
Click here for the corresponding HTML documentation that is generated by doxygen. 
Note:
The <name> argument consists of a combination of letters and number digits. If you wish to use upper case letters (e.g. MYPAGE1), or mixed case letters (e.g. MyPage1) in the <name> argument, you should set CASE_SENSE_NAMES to YES. However, this is advisable only if your file system is case sensitive. Otherwise (and for better portability) you should use all lower case letters (e.g. mypage1) for <name> in all references to the page.
See also
section \section, section \subsection, and section \ref.

--------------------------------------------------------------------------------

\private
Indicates that the member documented by the comment block is private, i.e., should only be accessed by other members in the same class.

Note that doxygen automatically detects the protection level of members in object-oriented languages. This command is intended for use only when the language does not support the concept of protection level natively (e.g. C, PHP 4).

For starting a section of private members, in a way similar to the "private:" class marker in C++, use \privatesection.

See also
sections \memberof, \public, \protected and \privatesection.

--------------------------------------------------------------------------------

\privatesection
Starting a section of private members, in a way similar to the "private:" class marker in C++. Indicates that the member documented by the comment block is private, i.e., should only be accessed by other members in the same class.

See also
sections \memberof, \public, \protected and \private.

--------------------------------------------------------------------------------

\property (qualified property name)
Indicates that a comment block contains documentation for a property (either global or as a member of a class). This command is equivalent to \fn, \typedef, and \var.

See also
sections \fn, \typedef, and \var.

--------------------------------------------------------------------------------

\protected
Indicates that the member documented by the comment block is protected, i.e., should only be accessed by other members in the same or derived classes.

Note that doxygen automatically detects the protection level of members in object-oriented languages. This command is intended for use only when the language does not support the concept of protection level natively (e.g. C, PHP 4).

For starting a section of protected members, in a way similar to the "protected:" class marker in C++, use \protectedsection.

See also
sections \memberof, \public, \private and \protectedsection.

--------------------------------------------------------------------------------

\protectedsection
Starting a section of protected members, in a way similar to the "protected:" class marker in C++. Indicates that the member documented by the comment block is protected, i.e., should only be accessed by other members in the same or derived classes.

See also
sections \memberof, \public, \private and \protected.

--------------------------------------------------------------------------------

\protocol <name> [<header-file>] [<header-name>]
Indicates that a comment block contains documentation for a protocol in Objective-C with name <name>. The arguments are equal to the \class command.

See also
section \class.

--------------------------------------------------------------------------------

\public
Indicates that the member documented by the comment block is public, i.e., can be accessed by any other class or function.

Note that doxygen automatically detects the protection level of members in object-oriented languages. This command is intended for use only when the language does not support the concept of protection level natively (e.g. C, PHP 4).

For starting a section of public members, in a way similar to the "public:" class marker in C++, use \publicsection.

See also
sections \memberof, \protected, \private and \publicsection.

--------------------------------------------------------------------------------

\publicsection
Starting a section of public members, in a way similar to the "public:" class marker in C++. Indicates that the member documented by the comment block is public, i.e., can be accessed by any other class or function.

See also
sections \memberof, \protected, \private and \public.

--------------------------------------------------------------------------------

\pure
Indicates that the member documented by the comment block is pure virtual, i.e., it is abstract and has no implementation associated with it.

This command is intended for use only when the language does not support the concept of pure virtual methods natively (e.g. C, PHP 4).


--------------------------------------------------------------------------------

\relates <name>
This command can be used in the documentation of a non-member function <name>. It puts the function inside the 'related function' section of the class documentation. This command is useful for documenting non-friend functions that are nevertheless strongly coupled to a certain class. It prevents the need of having to document a file, but only works for functions.

Example:
/*! 
 * A String class.
 */ 
  
class String
{
  friend int strcmp(const String &,const String &);
};

/*! 
 * Compares two strings.
 */

int strcmp(const String &s1,const String &s2)
{
}

/*! \relates String
 * A string debug function.
 */
void stringDebug()
{
}
Click here for the corresponding HTML documentation that is generated by doxygen. 

--------------------------------------------------------------------------------

\related <name>
Equivalent to \relates


--------------------------------------------------------------------------------

\relatesalso <name>
This command can be used in the documentation of a non-member function <name>. It puts the function both inside the 'related function' section of the class documentation as well as leaving it at its normal file documentation location. This command is useful for documenting non-friend functions that are nevertheless strongly coupled to a certain class. It only works for functions.


--------------------------------------------------------------------------------

\relatedalso <name>
Equivalent to \relatesalso


--------------------------------------------------------------------------------

\showinitializer
By default the value of a define and the initializer of a variable are only displayed if they are less than 30 lines long. By putting this command in a comment block of a define or variable, the initializer is shown unconditionally. The maximum number of initialization lines can be changed by means of the configuration parameter MAX_INITIALIZER_LINES, the default value is 30.

See also
section \hideinitializer.

--------------------------------------------------------------------------------

\static
Indicates that the member documented by the comment block is static, i.e., it works on a class, instead of on an instance of the class.

This command is intended for use only when the language does not support the concept of static methods natively (e.g. C).


--------------------------------------------------------------------------------

\struct <name> [<header-file>] [<header-name>]
Indicates that a comment block contains documentation for a struct with name <name>. The arguments are equal to the arguments of the \class command.

See also
section \class.

--------------------------------------------------------------------------------

\typedef (typedef declaration)
Indicates that a comment block contains documentation for a typedef (either global or as a member of a class). This command is equivalent to \fn, \property, and \var.

See also
section \fn, \property, and \var.

--------------------------------------------------------------------------------

\union <name> [<header-file>] [<header-name>]
Indicates that a comment block contains documentation for a union with name <name>. The arguments are equal to the arguments of the \class command.

See also
section \class.

--------------------------------------------------------------------------------

\var (variable declaration)
Indicates that a comment block contains documentation for a variable or enum value (either global or as a member of a class). This command is equivalent to \fn, \property, and \typedef.

See also
section \fn, \property, and \typedef.

--------------------------------------------------------------------------------

\vhdlflow [(title for the flow chart)]
This is a VHDL specific command, which can be put in the documentation of a process to produce a flow chart of the logic in the process. Optionally a title for the flow chart can be given. 

Note
Currently the flow chart will only appear in the HTML output.

--------------------------------------------------------------------------------

\weakgroup <name> [(title)]
Can be used exactly like \addtogroup, but has a lower priority when it comes to resolving conflicting grouping definitions.

See also
page Grouping and section \addtogroup.

--------------------------------------------------------------------------------



--- Section indicators --- 



--------------------------------------------------------------------------------

\attention { attention text }
Starts a paragraph where a message that needs attention may be entered. The paragraph will be indented. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \attention commands will be joined into a single paragraph. The \attention command ends when a blank line or some other sectioning command is encountered.


--------------------------------------------------------------------------------

\author { list of authors }
Starts a paragraph where one or more author names may be entered. The paragraph will be indented. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \author commands will be joined into a single paragraph. Each author description will start a new line. Alternatively, one \author command may mention several authors. The \author command ends when a blank line or some other sectioning command is encountered.

Example:
/*! 
 *  \brief     Pretty nice class.
 *  \details   This class is used to demonstrate a number of section commands.
 *  \author    John Doe
 *  \author    Jan Doe
 *  \version   4.1a
 *  \date      1990-2011
 *  \pre       First initialize the system.
 *  \bug       Not all memory is freed when deleting an object of this class.
 *  \warning   Improper use can crash your application
 *  \copyright GNU Public License.
 */
class SomeNiceClass {};
Click here for the corresponding HTML documentation that is generated by doxygen. 

--------------------------------------------------------------------------------

\authors { list of authors }
Equivalent to \author.


--------------------------------------------------------------------------------

\brief { brief description }
Starts a paragraph that serves as a brief description. For classes and files the brief description will be used in lists and at the start of the documentation page. For class and file members, the brief description will be placed at the declaration of the member and prepended to the detailed description. A brief description may span several lines (although it is advised to keep it brief!). A brief description ends when a blank line or another sectioning command is encountered. If multiple \brief commands are present they will be joined. See section \author for an example.

Synonymous to \short.


--------------------------------------------------------------------------------

\bug { bug description }
Starts a paragraph where one or more bugs may be reported. The paragraph will be indented. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \bug commands will be joined into a single paragraph. Each bug description will start on a new line. Alternatively, one \bug command may mention several bugs. The \bug command ends when a blank line or some other sectioning command is encountered. See section \author for an example.


--------------------------------------------------------------------------------

\cond [(section-label)]
Starts a conditional section that ends with a corresponding \endcond command, which is typically found in another comment block. The main purpose of this pair of commands is to (conditionally) exclude part of a file from processing (in older version of doxygen this could only be achieved using C preprocessor commands).

The section between \cond and \endcond can be included by adding its section label to the ENABLED_SECTIONS configuration option. If the section label is omitted, the section will be excluded from processing unconditionally. The section label can be a logical expression build of section labels, round brackets, && (AND), || (OR) and ! (NOT). If you use an expression you need to wrap it in round brackets, i.e \cond (!LABEL1 && LABEL2).

For conditional sections within a comment block one should use a \if ... \endif block.

Conditional sections can be nested. In this case a nested section will only be shown if it and its containing section are included.

Here is an example showing the commands in action:

/** An interface */
class Intf
{
  public:
    /** A method */
    virtual void func() = 0;

    /// @cond TEST

    /** A method used for testing */
    virtual void test() = 0;

    /// @endcond
};

/// @cond DEV
/*
 *  The implementation of the interface
 */
class Implementation : public Intf
{
  public:
    void func();

    /// @cond TEST
    void test();
    /// @endcond

    /// @cond
    /** This method is obsolete and does
     *  not show up in the documentation.
     */
    void obsolete();
    /// @endcond
};

/// @endcond
The output will be different depending on whether or not ENABLED_SECTIONS contains TEST, or DEV 

See also
sections \endcond and ENABLED_SECTIONS.

--------------------------------------------------------------------------------

\copyright { copyright description }
Starts a paragraph where the copyright of an entity can be described. This paragraph will be indented. The text of the paragraph has no special internal structure. See section \author for an example.


--------------------------------------------------------------------------------

\date { date description }
Starts a paragraph where one or more dates may be entered. The paragraph will be indented. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \date commands will be joined into a single paragraph. Each date description will start on a new line. Alternatively, one \date command may mention several dates. The \date command ends when a blank line or some other sectioning command is encountered. See section \author for an example.


--------------------------------------------------------------------------------

\deprecated { description }
Starts a paragraph indicating that this documentation block belongs to a deprecated entity. Can be used to describe alternatives, expected life span, etc.


--------------------------------------------------------------------------------

\details { detailed description }
Just like \brief starts a brief description, \details starts the detailed description. You can also start a new paragraph (blank line) then the \details command is not needed.


--------------------------------------------------------------------------------

\else
Starts a conditional section if the previous conditional section was not enabled. The previous section should have been started with a \if, \ifnot, or \elseif command.

See also
\if, \ifnot, \elseif, \endif.

--------------------------------------------------------------------------------

\elseif (section-label)
Starts a conditional documentation section if the previous section was not enabled. A conditional section is disabled by default. To enable it you must put the section-label after the ENABLED_SECTIONS tag in the configuration file. The section label can be a logical expression build of section names, round brackets, && (AND), || (OR) and ! (NOT). Conditional blocks can be nested. A nested section is only enabled if all enclosing sections are enabled as well.

See also
sections \endif, \ifnot, \else, and \elseif.

--------------------------------------------------------------------------------

\endcond
Ends a conditional section that was started by \cond.

See also
section \cond.

--------------------------------------------------------------------------------

\endif
Ends a conditional section that was started by \if or \ifnot For each \if or \ifnot one and only one matching \endif must follow.

See also
sections \if and \ifnot.

--------------------------------------------------------------------------------

\exception <exception-object> { exception description }
Starts an exception description for an exception object with name <exception-object>. Followed by a description of the exception. The existence of the exception object is not checked. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \exception commands will be joined into a single paragraph. Each exception description will start on a new line. The \exception description ends when a blank line or some other sectioning command is encountered. See section \fn for an example.


--------------------------------------------------------------------------------

\if (section-label)
Starts a conditional documentation section. The section ends with a matching \endif command. A conditional section is disabled by default. To enable it you must put the section-label after the ENABLED_SECTIONS tag in the configuration file.

The section label can be a logical expression build of section names, round brackets, && (AND), || (OR) and ! (NOT). If you use an expression you need to wrap it in round brackets, i.e \cond (!LABEL1 && LABEL2).

Conditional blocks can be nested. A nested section is only enabled if all enclosing sections are enabled as well.

Example:
  /*! Unconditionally shown documentation.
   *  \if Cond1
   *    Only included if Cond1 is set.
   *  \endif
   *  \if Cond2
   *    Only included if Cond2 is set.
   *    \if Cond3
   *      Only included if Cond2 and Cond3 are set.
   *    \endif
   *    More text.
   *  \endif
   *  Unconditional text.
   */
You can also use conditional commands inside aliases. To document a class in two languages you could for instance use:

Example 2:
/*! \english
 *  This is English.
 *  \endenglish
 *  \dutch
 *  Dit is Nederlands.
 *  \enddutch
 */
class Example
{
};
Where the following aliases are defined in the configuration file:

ALIASES  = "english=\if english" \
           "endenglish=\endif" \
           "dutch=\if dutch" \
           "enddutch=\endif"
and ENABLED_SECTIONS can be used to enable either english or dutch.

See also
sections \endif, \ifnot, \else, \elseif, and ENABLED_SECTIONS.

--------------------------------------------------------------------------------

\ifnot (section-label)
Starts a conditional documentation section. The section ends with a matching \endif command. This conditional section is enabled by default. To disable it you must put the section-label after the ENABLED_SECTIONS tag in the configuration file. The section label can be a logical expression build of section names, round brackets, && (AND), || (OR) and ! (NOT).

See also
sections \endif, \if, \else, and \elseif, and ENABLED_SECTIONS.

--------------------------------------------------------------------------------

\invariant { description of invariant }
Starts a paragraph where the invariant of an entity can be described. The paragraph will be indented. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \invariant commands will be joined into a single paragraph. Each invariant description will start on a new line. Alternatively, one \invariant command may mention several invariants. The \invariant command ends when a blank line or some other sectioning command is encountered.


--------------------------------------------------------------------------------

\note { text }
Starts a paragraph where a note can be entered. The paragraph will be indented. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \note commands will be joined into a single paragraph. Each note description will start on a new line. Alternatively, one \note command may mention several notes. The \note command ends when a blank line or some other sectioning command is encountered. See section \par for an example.


--------------------------------------------------------------------------------

\par [(paragraph title)] { paragraph }
If a paragraph title is given this command starts a paragraph with a user defined heading. The heading extends until the end of the line. The paragraph following the command will be indented.

If no paragraph title is given this command will start a new paragraph. This will also work inside other paragraph commands (like \param or \warning) without ending that command.

The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. The \par command ends when a blank line or some other sectioning command is encountered.

Example:
/*! \class Par_Test
 * Normal text.
 *
 * \par User defined paragraph:
 * Contents of the paragraph.
 *
 * \par
 * New paragraph under the same heading.
 *
 * \note
 * This note consists of two paragraphs.
 * This is the first paragraph.
 *
 * \par
 * And this is the second paragraph.
 *
 * More normal text. 
 */
  
class Par_Test {};
Click here for the corresponding HTML documentation that is generated by doxygen. 

--------------------------------------------------------------------------------

\param [(dir)] <parameter-name> { parameter description }
Starts a parameter description for a function parameter with name <parameter-name>, followed by a description of the parameter. The existence of the parameter is checked and a warning is given if the documentation of this (or any other) parameter is missing or not present in the function declaration or definition.

The \param command has an optional attribute, (dir), specifying the direction of the parameter. Possible values are "[in]", "[in,out]", and "[out]", note the [square] brackets in this description. When a parameter is both input and output, [in,out] is used as attribute. Here is an example for the function memcpy: 

/*!
 * Copies bytes from a source memory area to a destination memory area,
 * where both areas may not overlap.
 * @param[out] dest The memory area to copy to.
 * @param[in]  src  The memory area to copy from.
 * @param[in]  n    The number of bytes to copy
 */
void memcpy(void *dest, const void *src, size_t n);
The parameter description is a paragraph with no special internal structure. All visual enhancement commands may be used inside the paragraph.

Multiple adjacent \param commands will be joined into a single paragraph. Each parameter description will start on a new line. The \param description ends when a blank line or some other sectioning command is encountered. See section \fn for an example.

Note that you can also document multiple parameters with a single \param command using a comma separated list. Here is an example:

/** Sets the position.
 *  @param x,y,z Coordinates of the position in 3D space.
 */
void setPosition(double x,double y,double z,double t)
{
}
Note that for PHP one can also specify the type (or types if you separate them with a pipe symbol) which are allowed for a parameter (as this is not part of the definition). The syntax is the same as for phpDocumentor, i.e. 

@param  datatype1|datatype2 $paramname description

--------------------------------------------------------------------------------

\parblock
For commands that expect a single paragraph as argument (such as \par, \param and \warning), the \parblock command allows to start a description that covers multiple paragraphs, which then ends with \endparblock.

Example: 

/** Example of a param command with a description consisting of two paragraphs
 *  \param p 
 *  \parblock
 *  First paragraph of the param description.
 *
 *  Second paragraph of the param description.
 *  \endparblock
 *  Rest of the comment block continues.
 */
Note that the \parblock command may also appear directly after \param's first argument.


--------------------------------------------------------------------------------

\endparblock
This ends a block of paragraphs started with \parblock.


--------------------------------------------------------------------------------

\tparam <template-parameter-name> { description }
Starts a template parameter for a class or function template parameter with name <template-parameter-name>, followed by a description of the template parameter.

Otherwise similar to \param.


--------------------------------------------------------------------------------

\post { description of the postcondition }
Starts a paragraph where the postcondition of an entity can be described. The paragraph will be indented. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \post commands will be joined into a single paragraph. Each postcondition will start on a new line. Alternatively, one \post command may mention several postconditions. The \post command ends when a blank line or some other sectioning command is encountered.


--------------------------------------------------------------------------------

\pre { description of the precondition }
Starts a paragraph where the precondition of an entity can be described. The paragraph will be indented. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \pre commands will be joined into a single paragraph. Each precondition will start on a new line. Alternatively, one \pre command may mention several preconditions. The \pre command ends when a blank line or some other sectioning command is encountered.


--------------------------------------------------------------------------------

\remark { remark text }
Starts a paragraph where one or more remarks may be entered. The paragraph will be indented. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \remark commands will be joined into a single paragraph. Each remark will start on a new line. Alternatively, one \remark command may mention several remarks. The \remark command ends when a blank line or some other sectioning command is encountered.


--------------------------------------------------------------------------------

\remarks { remark text }
Equivalent to \remark.


--------------------------------------------------------------------------------

\result { description of the result value }
Equivalent to \return.


--------------------------------------------------------------------------------

\return { description of the return value }
Starts a return value description for a function. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \return commands will be joined into a single paragraph. The \return description ends when a blank line or some other sectioning command is encountered. See section \fn for an example.


--------------------------------------------------------------------------------

\returns { description of the return value }
Equivalent to \return.


--------------------------------------------------------------------------------

\retval <return value> { description }
Starts a description for a function's return value with name <return value>, followed by a description of the return value. The text of the paragraph that forms the description has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \retval commands will be joined into a single paragraph. Each return value description will start on a new line. The \retval description ends when a blank line or some other sectioning command is encountered.


--------------------------------------------------------------------------------

\sa { references }
Starts a paragraph where one or more cross-references to classes, functions, methods, variables, files or URL may be specified. Two names joined by either :: or # are understood as referring to a class and one of its members. One of several overloaded methods or constructors may be selected by including a parenthesized list of argument types after the method name.

Synonymous to \see.

See also
section autolink for information on how to create links to objects.

--------------------------------------------------------------------------------

\see { references }
Equivalent to \sa. Introduced for compatibility with Javadoc.


--------------------------------------------------------------------------------

\short { short description }
Equivalent to \brief.


--------------------------------------------------------------------------------

\since { text }
This command can be used to specify since when (version or time) an entity is available. The paragraph that follows \since does not have any special internal structure. All visual enhancement commands may be used inside the paragraph. The \since description ends when a blank line or some other sectioning command is encountered.


--------------------------------------------------------------------------------

\test { paragraph describing a test case }
Starts a paragraph where a test case can be described. The description will also add the test case to a separate test list. The two instances of the description will be cross-referenced. Each test case in the test list will be preceded by a header that indicates the origin of the test case.


--------------------------------------------------------------------------------

\throw <exception-object> { exception description }
Synonymous \exception.

Note:
the command \throws is a synonym for this command.
See also
section \exception

--------------------------------------------------------------------------------

\throws <exception-object> { exception description }
Equivalent to \throw.


--------------------------------------------------------------------------------

\todo { paragraph describing what is to be done }
Starts a paragraph where a TODO item is described. The description will also add an item to a separate TODO list. The two instances of the description will be cross-referenced. Each item in the TODO list will be preceded by a header that indicates the origin of the item.


--------------------------------------------------------------------------------

\version { version number }
Starts a paragraph where one or more version strings may be entered. The paragraph will be indented. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \version commands will be joined into a single paragraph. Each version description will start on a new line. Alternatively, one \version command may mention several version strings. The \version command ends when a blank line or some other sectioning command is encountered. See section \author for an example.


--------------------------------------------------------------------------------

\warning { warning message }
Starts a paragraph where one or more warning messages may be entered. The paragraph will be indented. The text of the paragraph has no special internal structure. All visual enhancement commands may be used inside the paragraph. Multiple adjacent \warning commands will be joined into a single paragraph. Each warning description will start on a new line. Alternatively, one \warning command may mention several warnings. The \warning command ends when a blank line or some other sectioning command is encountered. See section \author for an example.


--------------------------------------------------------------------------------

\xrefitem <key> "(heading)" "(list title)" { text }
This command is a generalization of commands such as \todo and \bug. It can be used to create user-defined text sections which are automatically cross-referenced between the place of occurrence and a related page, which will be generated. On the related page all sections of the same type will be collected.

The first argument <key> is an identifier uniquely representing the type of the section. The second argument is a quoted string representing the heading of the section under which text passed as the fourth argument is put. The third argument (list title) is used as the title for the related page containing all items with the same key. The keys "todo", "test", "bug" and "deprecated" are predefined.

To get an idea on how to use the \xrefitem command and what its effect is, consider the todo list, which (for English output) can be seen an alias for the command 

\xrefitem todo "Todo" "Todo List" Since it is very tedious and error-prone to repeat the first three parameters of the command for each section, the command is meant to be used in combination with the ALIASES option in the configuration file. To define a new command \reminder, for instance, one should add the following line to the configuration file: 

ALIASES += "reminder=\xrefitem reminders \"Reminder\" \"Reminders\"" Note the use of escaped quotes for the second and third argument of the \xrefitem command.

In case parameter "(heading)" is the empty string no heading is generated. This can be useful when used in combination with the \page command e.g. 

/** @page my_errors My Errors
 *  @brief Errors page
 *
 *  Errors page contents.
 */

/** \error ERROR 101: in case a file can not be opened.
    Check about file system read/write access. */
#define MY_ERR_CANNOT_OPEN_FILE                   101

/** \error ERROR 102: in case a file can not be closed.
    Check about file system read/write access. */
#define MY_ERR_CANNOT_CLOSE_FILE                  102
with \error defined as 

ALIASES += "error=\xrefitem my_errors \"\" \"\"" 
--------------------------------------------------------------------------------



--- Commands to create links --- 



--------------------------------------------------------------------------------

\addindex (text)
This command adds (text) to the  index.


--------------------------------------------------------------------------------

\anchor <word>
This command places an invisible, named anchor into the documentation to which you can refer with the \ref command.

Note
Anchors can currently only be put into a comment block that is marked as a page (using \page) or mainpage (\mainpage).
See also
section \ref.

--------------------------------------------------------------------------------

\cite <label>
Adds a bibliographic reference in the text and in the list of bibliographic references. The <label> must be a valid BibTeX label that can be found in one of the .bib files listed in CITE_BIB_FILES. For the  output the formatting of the reference in the text can be configured with LATEX_BIB_STYLE. For other output formats a fixed representation is used. Note that using this command requires the bibtex tool to be present in the search path.


--------------------------------------------------------------------------------

\endlink
This command ends a link that is started with the \link command.

See also
section \link.

--------------------------------------------------------------------------------

\link <link-object>
The links that are automatically generated by doxygen always have the name of the object they point to as link-text.

The \link command can be used to create a link to an object (a file, class, or member) with a user specified link-text. The link command should end with an \endlink command. All text between the \link and \endlink commands serves as text for a link to the <link-object> specified as the first argument of \link.

See also
Section autolink for more information on automatically generated links and valid link-objects.

--------------------------------------------------------------------------------

\ref <name> ["(text)"]
Creates a reference to a named section, subsection, page or anchor. For HTML documentation the reference command will generate a link to the section. For a section or subsection the title of the section will be used as the text of the link. For an anchor the optional text between quotes will be used or <name> if no text is specified. For  documentation the reference command will generate a section number for sections or the text followed by a page number if <name> refers to an anchor.

See also
Section \page for an example of the \ref command.

--------------------------------------------------------------------------------

\refitem <name>
Just like the \ref command, this command creates a reference to a named section, but this reference appears in a list that is started by \secreflist and ends with \endsecreflist. An example of such a list can be seen at the top of the page.


--------------------------------------------------------------------------------

\secreflist
Starts an index list of item, created with \refitem that each link to a named section.


--------------------------------------------------------------------------------

\endsecreflist
End an index list started with \secreflist.


--------------------------------------------------------------------------------

\subpage <name> ["(text)"]
This command can be used to create a hierarchy of pages. The same structure can be made using the \defgroup and \ingroup commands, but for pages the \subpage command is often more convenient. The main page (see \mainpage) is typically the root of hierarchy.

This command behaves similar as \ref in the sense that it creates a reference to a page labeled <name> with the optional link text as specified in the second argument.

It differs from the \ref command in that it only works for pages, and creates a parent-child relation between pages, where the child page (or sub page) is identified by label <name>.

See the \section and \subsection commands if you want to add structure without creating multiple pages.

Note
Each page can be the sub page of only one other page and no cyclic relations are allowed, i.e. the page hierarchy must have a tree structure.
Here is an example: 

/*! \mainpage A simple manual

Some general info.

This manual is divided in the following sections:
- \subpage intro
- \subpage advanced "Advanced usage"
*/

//-----------------------------------------------------------

/*! \page intro Introduction
This page introduces the user to the topic.
Now you can proceed to the \ref advanced "advanced section".
*/

//-----------------------------------------------------------

/*! \page advanced Advanced Usage
This page is for advanced users.
Make sure you have first read \ref intro "the introduction".
*/

--------------------------------------------------------------------------------

\tableofcontents
Creates a table of contents at the top of a page, listing all sections and subsections in the page.

Warning
This command only works inside related page documentation and not in other documentation blocks and only has effect in the HTML output!

--------------------------------------------------------------------------------

\section <section-name> (section title)
Creates a section with name <section-name>. The title of the section should be specified as the second argument of the \section command.

Warning
This command only works inside related page documentation and not in other documentation blocks!
See also
Section \page for an example of the \section command.

--------------------------------------------------------------------------------

\subsection <subsection-name> (subsection title)
Creates a subsection with name <subsection-name>. The title of the subsection should be specified as the second argument of the \subsection command.

Warning
This command only works inside a section of a related page documentation block and not in other documentation blocks!
See also
Section \page for an example of the \subsection command.

--------------------------------------------------------------------------------

\subsubsection <subsubsection-name> (subsubsection title)
Creates a subsubsection with name <subsubsection-name>. The title of the subsubsection should be specified as the second argument of the \subsubsection command.

Warning
This command only works inside a subsection of a related page documentation block and not in other documentation blocks!
See also
Section \page for an example of the \section command and \subsection command.

--------------------------------------------------------------------------------

\paragraph <paragraph-name> (paragraph title)
Creates a named paragraph with name <paragraph-name>. The title of the paragraph should be specified as the second argument of the \paragraph command.

Warning
This command only works inside a subsubsection of a related page documentation block and not in other documentation blocks!

--------------------------------------------------------------------------------



--- Commands for displaying examples --- 



--------------------------------------------------------------------------------

\dontinclude <file-name>
This command can be used to parse a source file without actually verbatim including it in the documentation (as the \include command does). This is useful if you want to divide the source file into smaller pieces and add documentation between the pieces. Source files or directories can be specified using the EXAMPLE_PATH tag of doxygen's configuration file.

The class and member declarations and definitions inside the code fragment are 'remembered' during the parsing of the comment block that contained the \dontinclude command.

For line by line descriptions of source files, one or more lines of the example can be displayed using the \line, \skip, \skipline, and \until commands. An internal pointer is used for these commands. The \dontinclude command sets the pointer to the first line of the example.

Example:

/*! A test class. */

class Include_Test
{
  public:
    /// a member function
    void example();
};

/*! \page example
 *  \dontinclude include_test.cpp
 *  Our main function starts like this:
 *  \skip main
 *  \until {
 *  First we create an object \c t of the Include_Test class.
 *  \skipline Include_Test
 *  Then we call the example member function 
 *  \line example
 *  After that our little test routine ends.
 *  \line }
 */
Where the example file example_test.cpp looks as follows: 
void main()
{
  Example_Test t;
  t.example();
}
Click here for the corresponding HTML documentation that is generated by doxygen. 
Alternatively, the \snippet command can be used to include only a fragment of a source file. For this to work the fragment has to be marked.

See also
sections \line, \skip, \skipline, \until, and \include.

--------------------------------------------------------------------------------

\include <file-name>
This command can be used to include a source file as a block of code. The command takes the name of an include file as an argument. Source files or directories can be specified using the EXAMPLE_PATH tag of doxygen's configuration file.

If <file-name> itself is not unique for the set of example files specified by the EXAMPLE_PATH tag, you can include part of the absolute path to disambiguate it.

Using the \include command is equivalent to inserting the file into the documentation block and surrounding it with \code and \endcode commands.

The main purpose of the \include command is to avoid code duplication in case of example blocks that consist of multiple source and header files.

For a line by line description of a source files use the \dontinclude command in combination with the \line, \skip, \skipline, and \until commands.

Alternatively, the \snippet command can be used to include only a fragment of a source file. For this to work the fragment has to be marked.

Note
Doxygen's special commands do not work inside blocks of code. It is allowed to nest C-style comments inside a code block though.
See also
sections \example, \dontinclude, \verbatim and \includedoc.

--------------------------------------------------------------------------------

\includelineno <file-name>
This command works the same way as \include, but will add line numbers to the included file.

See also
sections \include and \snippetlineno.

--------------------------------------------------------------------------------

\includedoc <file-name>
This command works the same way as \include, but it will include the content of the file as if it were at the place where this command is called. The result is that the content is parsed by doxygen and placed in the documentation.

Note
Some commands like \cond and \if don't work with this command due to the moment of parsing.
The included documentation should not have comment signs in it as the will appear in the documentation as well.
See also
section \include.

--------------------------------------------------------------------------------

\line ( pattern )
This command searches line by line through the example that was last included using \include or \dontinclude until it finds a non-blank line. If that line contains the specified pattern, it is written to the output.

The internal pointer that is used to keep track of the current line in the example, is set to the start of the line following the non-blank line that was found (or to the end of the example if no such line could be found).

See section \dontinclude for an example.


--------------------------------------------------------------------------------

\skip ( pattern )
This command searches line by line through the example that was last included using \include or \dontinclude until it finds a line that contains the specified pattern.

The internal pointer that is used to keep track of the current line in the example, is set to the start of the line that contains the specified pattern (or to the end of the example if the pattern could not be found).

See section \dontinclude for an example.


--------------------------------------------------------------------------------

\skipline ( pattern )
This command searches line by line through the example that was last included using \include or \dontinclude until it finds a line that contains the specified pattern. It then writes the line to the output.

The internal pointer that is used to keep track of the current line in the example, is set to the start of the line following the line that is written (or to the end of the example if the pattern could not be found).

Note:
The command: 
\skipline patternis equivalent to: 
\skip pattern
\line patternSee section \dontinclude for an example.


--------------------------------------------------------------------------------

\snippet <file-name> ( block_id )
Where the \include command can be used to include a complete file as source code, this command can be used to quote only a fragment of a source file. In case this is used as <file-name> the current file is taken as file to take the snippet from.

For example, the putting the following command in the documentation, references a snippet in file example.cpp residing in a subdirectory which should be pointed to by EXAMPLE_PATH.

  \snippet snippets/example.cpp Adding a resource
The text following the file name is the unique identifier for the snippet. This is used to delimit the quoted code in the relevant snippet file as shown in the following example that corresponds to the above \snippet command:

    QImage image(64, 64, QImage::Format_RGB32);
    image.fill(qRgb(255, 160, 128));

//! [Adding a resource]
    document->addResource(QTextDocument::ImageResource,
        QUrl("mydata://image.png"), QVariant(image));
//! [Adding a resource]
    ...
Note that the lines containing the block markers will not be included, so the output will be:

document->addResource(QTextDocument::ImageResource,
    QUrl("mydata://image.png"), QVariant(image));
Note also that the [block_id] markers should appear exactly twice in the source file.

see section \dontinclude for an alternative way to include fragments of a source file that does not require markers.

See also
section \snippetdoc and \snippetlineno. 
--------------------------------------------------------------------------------

\snippetlineno <file-name> ( block_id )
This command works the same way as \snippet, but will add line numbers to the included snippet.

See also
sections \snippet and \includelineno.

--------------------------------------------------------------------------------

\snippetdoc <file-name> ( block_id )
This command works the same way as \snippet, but it will include the content of the file between the block-ids as if it were at the place where this command is called. The result is that the content is parsed by doxygen and placed in the documentation.

Note
Some commands like \cond and \if don't work with this command due to the moment of parsing.
The included documentation should not have comment signs in it as the will appear in the documentation as well.
See also
section \snippet and \includedoc.

--------------------------------------------------------------------------------

\until ( pattern )
This command writes all lines of the example that was last included using \include or \dontinclude to the output, until it finds a line containing the specified pattern. The line containing the pattern will be written as well.

The internal pointer that is used to keep track of the current line in the example, is set to the start of the line following last written line (or to the end of the example if the pattern could not be found).

See section \dontinclude for an example.


--------------------------------------------------------------------------------

\verbinclude <file-name>
This command includes the file <file-name> verbatim in the documentation. The command is equivalent to pasting the file in the documentation and placing \verbatim and \endverbatim commands around it.

Files or directories that doxygen should look for can be specified using the EXAMPLE_PATH tag of doxygen's configuration file.


--------------------------------------------------------------------------------

\htmlinclude <file-name>
This command includes the file <file-name> as is in the HTML documentation. The command is equivalent to pasting the file in the documentation and placing \htmlonly and \endhtmlonly commands around it.

Files or directories that doxygen should look for can be specified using the EXAMPLE_PATH tag of doxygen's configuration file.


--------------------------------------------------------------------------------

\latexinclude <file-name>
This command includes the file <file-name> as is in the  documentation. The command is equivalent to pasting the file in the documentation and placing \latexonly and \endlatexonly commands around it.

Files or directories that doxygen should look for can be specified using the EXAMPLE_PATH tag of doxygen's configuration file.


--------------------------------------------------------------------------------



--- Commands for visual enhancements --- 


\a <word>
Displays the argument <word> in italics. Use this command to emphasize words. Use this command to refer to member arguments in the running text.

Example:
  ... the \a x and \a y coordinates are used to ...This will result in the following text:

... the x and y coordinates are used to ...
Equivalent to \e and \em. To emphasize multiple words use <em>multiple words</em>.


--------------------------------------------------------------------------------

\arg { item-description }
This command has one argument that continues until the first blank line or until another \arg is encountered. The command can be used to generate a simple, not nested list of arguments. Each argument should start with a \arg command.

Example:
Typing: 
  \arg \c AlignLeft left alignment.
  \arg \c AlignCenter center alignment.
  \arg \c AlignRight right alignment

  No other types of alignment are supported.will result in the following text:


?AlignLeft left alignment. 
?AlignCenter center alignment. 
?AlignRight right alignment 

No other types of alignment are supported.
Note:
For nested lists, HTML commands should be used.
Equivalent to \li


--------------------------------------------------------------------------------

\b <word>
Displays the argument <word> using a bold font. Equivalent to <b>word</b>. To put multiple words in bold use <b>multiple words</b>.


--------------------------------------------------------------------------------

\c <word>
Displays the argument <word> using a typewriter font. Use this to refer to a word of code. Equivalent to <tt>word</tt>.

Example:
Typing: 
     ... This function returns \c void and not \c int ...will result in the following text:

... This function returns void and not int ...
Equivalent to \p To have multiple words in typewriter font use <tt>multiple words</tt>.


--------------------------------------------------------------------------------

\code [ '{'<word>'}']
Starts a block of code. A code block is treated differently from ordinary text. It is interpreted as source code. The names of classes and members and other documented entities are automatically replaced by links to the documentation.

By default the language that is assumed for syntax highlighting is based on the location where the \code block was found. If this part of a Python file for instance, the syntax highlight will be done according to the Python syntax.

If it unclear from the context which language is meant (for instance the comment is in a .txt or .markdown file) then you can also explicitly indicate the language, by putting the file extension typically that doxygen associated with the language in curly brackets after the code block. Here is an example:

  \code{.py}
  class Python:
     pass
  \endcode

  \code{.cpp}
  class Cpp {};
  \endcode
If the contents of the code block are in a language that doxygen cannot parse, doxygen will just show the output as-is. You can make this explicit using .unparsed, or by giving some other extension that doxygen doesn't support, e.g.

  \code{.unparsed}
  Show this as-is please
  \endcode

  \code{.sh}
  echo "This is a shell script"
  \endcode
See also
section \endcode and section \verbatim.

--------------------------------------------------------------------------------

\copydoc <link-object>
Copies a documentation block from the object specified by <link-object> and pastes it at the location of the command. This command can be useful to avoid cases where a documentation block would otherwise have to be duplicated or it can be used to extend the documentation of an inherited member.

The link object can point to a member (of a class, file or group), a class, a namespace, a group, a page, or a file (checked in that order). Note that if the object pointed to is a member (function, variable, typedef, etc), the compound (class, file, or group) containing it should also be documented for the copying to work.

To copy the documentation for a member of a class one can, for instance, put the following in the documentation:

  /*! @copydoc MyClass::myfunction()
   *  More documentation.
   */
if the member is overloaded, you should specify the argument types explicitly (without spaces!), like in the following:

  //! @copydoc MyClass::myfunction(type1,type2)
Qualified names are only needed if the context in which the documentation block is found requires them.

The \copydoc command can be used recursively, but cycles in the \copydoc relation will be broken and flagged as an error.

Note that \copydoc foo() is roughly equivalent to doing: 

  \brief \copybrief foo()
  \details \copydetails foo()
See \copybrief and \copydetails for copying only the brief or detailed part of the comment block.


--------------------------------------------------------------------------------

\copybrief <link-object>
Works in a similar way as \copydoc but will only copy the brief description, not the detailed documentation.


--------------------------------------------------------------------------------

\copydetails <link-object>
Works in a similar way as \copydoc but will only copy the detailed documentation, not the brief description.


--------------------------------------------------------------------------------

\docbookonly
Starts a block of text that will be verbatim included in the generated docbook documentation only. The block ends with a \enddocbookonly command.

See also
section \manonly, \latexonly, \rtfonly, \xmlonly, and \htmlonly.

--------------------------------------------------------------------------------

\dot ["caption"] [<sizeindication>=<size>]
Starts a text fragment which should contain a valid description of a dot graph. The text fragment ends with \enddot. Doxygen will pass the text on to dot and include the resulting image (and image map) into the output.

The first argument is optional and can be used to specify the caption that is displayed below the image. This argument has to be specified between quotes even if it does not contain any spaces. The quotes are stripped before the caption is displayed.

The second argument is also optional and can be used to specify the width or height of the image. For a description of the possibilities see the paragraph Size indication with the \image command.

The nodes of a graph can be made clickable by using the URL attribute. By using the command \ref inside the URL value you can conveniently link to an item inside doxygen. Here is an example: 

/*! class B */
class B {};

/*! class C */
class C {};

/*! \mainpage
  
 *  Class relations expressed via an inline dot graph:
 *  \dot
 *  digraph example {
 *      node [shape=record, fontname=Helvetica, fontsize=10];
 *      b [ label="class B" URL="\ref B"];
 *      c [ label="class C" URL="\ref C"];
 *      b -> c [ arrowhead="open", style="dashed" ];
 *  }
 *  \enddot
 *  Note that the classes in the above graph are clickable
 *  (in the HTML output).
 */

--------------------------------------------------------------------------------

\msc ["caption"] [<sizeindication>=<size>]
Starts a text fragment which should contain a valid description of a message sequence chart. See http://www.mcternan.me.uk/mscgen/ for examples. The text fragment ends with \endmsc.

The first argument is optional and can be used to specify the caption that is displayed below the image. This argument has to be specified between quotes even if it does not contain any spaces. The quotes are stripped before the caption is displayed.

The second argument is also optional and can be used to specify the width or height of the image. For a description of the possibilities see the paragraph Size indication with the \image command.

Note
The text fragment should only include the part of the message sequence chart that is within the msc {...} block. 
You need to install the mscgen tool, if you want to use this command.
Here is an example of the use of the \msc command. 

/** Sender class. Can be used to send a command to the server.
 *  The receiver will acknowledge the command by calling Ack().
 *  \msc
 *    Sender,Receiver;
 *    Sender->Receiver [label="Command()", URL="\ref Receiver::Command()"];
 *    Sender<-Receiver [label="Ack()", URL="\ref Ack()", ID="1"];
 *  \endmsc
 */
class Sender
{
  public:
    /** Acknowledgment from server */
    void Ack(bool ok);
};

/** Receiver class. Can be used to receive and execute commands.
 *  After execution of a command, the receiver will send an acknowledgment
 *  \msc
 *    Receiver,Sender;
 *    Receiver<-Sender [label="Command()", URL="\ref Command()"];
 *    Receiver->Sender [label="Ack()", URL="\ref Sender::Ack()", ID="1"];
 *  \endmsc
 */
class Receiver
{
  public:
    /** Executable a command on the server */
    void Command(int commandId);
};
See also
section \mscfile.

--------------------------------------------------------------------------------

\startuml [{file}] ["caption"] [<sizeindication>=<size>]
Starts a text fragment which should contain a valid description of a PlantUML diagram. See http://plantuml.sourceforge.net/ for examples. The text fragment ends with \enduml. 

Note
You need to install Java and the PlantUML's jar file, if you want to use this command. The location of the jar file should be specified using PLANTUML_JAR_PATH.
The first argument is optional and is for compatibility with running PlantUML as a preprocessing step before running doxygen, you can also add the name of the image file after \startuml and inside curly brackets, i.e. 

  @startuml{myimage.png} "Image Caption" width=5cm
  Alice -> Bob : Hello
  @endumlWhen the name of the image is specified, doxygen will generate an image with that name. Without the name doxygen will choose a name automatically.

The second argument is optional and can be used to specify the caption that is displayed below the image. This argument has to be specified between quotes even if it does not contain any spaces. The quotes are stripped before the caption is displayed.

The third argument is also optional and can be used to specify the width or height of the image. For a description of the possibilities see the paragraph Size indication with the \image command.

Here is an example of the use of the \startuml command. 

/** Sender class. Can be used to send a command to the server.
 *  The receiver will acknowledge the command by calling Ack().
 *  \startuml
 *    Sender->Receiver  : Command()
 *    Sender<--Receiver : Ack()
 *  \enduml
 */
class Sender
{
  public:
    /** Acknowledgment from server */
    void Ack(bool ok);
};

/** Receiver class. Can be used to receive and execute commands.
 *  After execution of a command, the receiver will send an acknowledgment
 *  \startuml
 *    Receiver<-Sender  : Command()
 *    Receiver-->Sender : Ack()
 *  \enduml
 */
class Receiver
{
  public:
    /** Executable a command on the server */
    void Command(int commandId);
};

--------------------------------------------------------------------------------

\dotfile <file> ["caption"] [<sizeindication>=<size>]
Inserts an image generated by dot from <file> into the documentation.

The first argument specifies the file name of the image. doxygen will look for files in the paths (or files) that you specified after the DOTFILE_DIRS tag. If the dot file is found it will be used as an input file to the dot tool. The resulting image will be put into the correct output directory. If the dot file name contains spaces you'll have to put quotes ("...") around it.

The second argument is optional and can be used to specify the caption that is displayed below the image. This argument has to be specified between quotes even if it does not contain any spaces. The quotes are stripped before the caption is displayed.

The third argument is also optional and can be used to specify the width or height of the image. For a description of the possibilities see the paragraph Size indication with the \image command.

See also
section \dot.

--------------------------------------------------------------------------------

\mscfile <file> ["caption"] [<sizeindication>=<size>]
Inserts an image generated by mscgen from <file> into the documentation. See http://www.mcternan.me.uk/mscgen/ for examples.

The first argument specifies the file name of the image. doxygen will look for files in the paths (or files) that you specified after the MSCFILE_DIRS tag. If the msc file is found it will be used as an input file to the mscgen tool. The resulting image will be put into the correct output directory. If the msc file name contains spaces you'll have to put quotes ("...") around it.

The second argument is optional and can be used to specify the caption that is displayed below the image. This argument has to be specified between quotes even if it does not contain any spaces. The quotes are stripped before the caption is displayed.

The third argument is also optional and can be used to specify the width or height of the image. For a description of the possibilities see the paragraph Size indication with the \image command.

See also
section \msc.

--------------------------------------------------------------------------------

\diafile <file> ["caption"] [<sizeindication>=<size>]
Inserts an image made in dia from <file> into the documentation.

The first argument specifies the file name of the image. doxygen will look for files in the paths (or files) that you specified after the DIAFILE_DIRS tag. If the dia file is found it will be used as an input file dia. The resulting image will be put into the correct output directory. If the dia file name contains spaces you'll have to put quotes ("...") around it.

The second argument is optional and can be used to specify the caption that is displayed below the image. This argument has to be specified between quotes even if it does not contain any spaces. The quotes are stripped before the caption is displayed.

The third argument is also optional and can be used to specify the width or height of the image. For a description of the possibilities see the paragraph Size indication with the \image command.


--------------------------------------------------------------------------------

\e <word>
Displays the argument <word> in italics. Use this command to emphasize words.

Example:
Typing: 
  ... this is a \e really good example ...will result in the following text:

... this is a really good example ...
Equivalent to \a and \em. To emphasize multiple words use <em>multiple words</em>.


--------------------------------------------------------------------------------

\em <word>
Displays the argument <word> in italics. Use this command to emphasize words.

Example:
Typing: 
  ... this is a \em really good example ...will result in the following text:

... this is a really good example ...
Equivalent to \a and \e. To emphasize multiple words use <em>multiple words</em>.


--------------------------------------------------------------------------------

\endcode
Ends a block of code. 

See also
section \code

--------------------------------------------------------------------------------

\enddocbookonly
Ends a block of text that was started with a \docbookonly command.

See also
section \docbookonly.

--------------------------------------------------------------------------------

\enddot
Ends a block that was started with \dot.


--------------------------------------------------------------------------------

\endmsc
Ends a block that was started with \msc.


--------------------------------------------------------------------------------

\enduml
Ends a block that was started with \startuml.


--------------------------------------------------------------------------------

\endhtmlonly
Ends a block of text that was started with a \htmlonly command.

See also
section \htmlonly.

--------------------------------------------------------------------------------

\endlatexonly
Ends a block of text that was started with a \latexonly command.

See also
section \latexonly.

--------------------------------------------------------------------------------

\endmanonly
Ends a block of text that was started with a \manonly command.

See also
section \manonly.

--------------------------------------------------------------------------------

\endrtfonly
Ends a block of text that was started with a \rtfonly command.

See also
section \rtfonly.

--------------------------------------------------------------------------------

\endverbatim
Ends a block of text that was started with a \verbatim command.

See also
section \verbatim.

--------------------------------------------------------------------------------

\endxmlonly
Ends a block of text that was started with a \xmlonly command.

See also
section \xmlonly.

--------------------------------------------------------------------------------

\f$

Marks the start and end of an in-text formula. 

See also
section formulas for an example.

--------------------------------------------------------------------------------

\f[

Marks the start of a long formula that is displayed centered on a separate line. 

See also
section \f] and section formulas.

--------------------------------------------------------------------------------

\f]

Marks the end of a long formula that is displayed centered on a separate line. 

See also
section \f[ and section formulas.

--------------------------------------------------------------------------------

\f{environment}{

Marks the start of a formula that is in a specific environment. 

Note
The second { is optional and is only to help editors (such as Vim) to do proper syntax highlighting by making the number of opening and closing braces the same. 
See also
section \f} and section formulas.

--------------------------------------------------------------------------------

\f}

Marks the end of a formula that is in a specific environment. 

See also
section \f{ and section formulas.

--------------------------------------------------------------------------------

\htmlonly ["[block]"]
Starts a block of text that will be verbatim included in the generated HTML documentation only. The block ends with a \endhtmlonly command.

This command can be used to include HTML code that is too complex for doxygen (i.e. applets, java-scripts, and HTML tags that require specific attributes).

Normally the contents between \htmlonly and \endhtmlonly is inserted as-is. When you want to insert a HTML fragment that has block scope like a table or list which should appear outside <p>..</p>, this can lead to invalid HTML. You can use \htmlonly[block] to make doxygen end the current paragraph and restart it after \endhtmlonly.

Note
environment variables (like $(HOME) ) are resolved inside a HTML-only block.
See also
section \manonly, \latexonly, \rtfonly, \xmlonly, and \docbookonly.

--------------------------------------------------------------------------------

\image <format> <file> ["caption"] [<sizeindication>=<size>]
Inserts an image into the documentation. This command is format specific, so if you want to insert an image for more than one format you'll have to repeat this command for each format.

The first argument specifies the output format in which the image should be embedded. Currently, the following values are supported: html, latex, docbook and rtf.

The second argument specifies the file name of the image. doxygen will look for files in the paths (or files) that you specified after the IMAGE_PATH tag. If the image is found it will be copied to the correct output directory. If the image name contains spaces you'll have to put quotes ("...") around the name. You can also specify an absolute URL instead of a file name, but then doxygen does not copy the image nor check its existence.

The third argument is optional and can be used to specify the caption that is displayed below the image. This argument has to be specified on a single line and between quotes even if it does not contain any spaces. The quotes are stripped before the caption is displayed.

The fourth argument is also optional and can be used to specify the width or height of the image. This can be useful for  or docbook output (i.e. format=latex or format=docbook). 
Size indication
The sizeindication can specify the width or height to be used (or a combination). The size specifier in  (for example 10cm or 4in or a symbolic width like \\textwidth).
Here is example of a comment block:

  /*! Here is a snapshot of my new application:
   *  \image html application.jpg
   *  \image latex application.eps "My application" width=10cm
   */
And this is an example of how the relevant part of the configuration file may look:

  IMAGE_PATH     = my_image_dir
Warning
The image format for HTML is limited to what your browser supports. For , the image format must be Encapsulated PostScript (eps). 

Doxygen does not check if the image is in the correct format. So you have to make sure this is the case!

--------------------------------------------------------------------------------

\latexonly
Starts a block of text that will be verbatim included in the generated  documentation only. The block ends with a \endlatexonly command.

This command can be used to include  code that is too complex for doxygen (i.e. images, formulas, special characters). You can use the \htmlonly and \endhtmlonly pair to provide a proper HTML alternative.

Note: environment variables (like $(HOME) ) are resolved inside a -only block.

See also
sections \rtfonly, \xmlonly, \manonly, \htmlonly, and \docbookonly.

--------------------------------------------------------------------------------

\manonly
Starts a block of text that will be verbatim included in the generated MAN documentation only. The block ends with a \endmanonly command.

This command can be used to include groff code directly into MAN pages. You can use the \htmlonly and \endhtmlonly and \latexonly and \endlatexonly pairs to provide proper HTML and  alternatives.

See also
sections \htmlonly, \xmlonly, \rtfonly, \latexonly, and \docbookonly.

--------------------------------------------------------------------------------

\li { item-description }
This command has one argument that continues until the first blank line or until another \li is encountered. The command can be used to generate a simple, not nested list of arguments. Each argument should start with a \li command.

Example:
Typing: 
  \li \c AlignLeft left alignment.
  \li \c AlignCenter center alignment.
  \li \c AlignRight right alignment

  No other types of alignment are supported.will result in the following text:


?AlignLeft left alignment. 
?AlignCenter center alignment. 
?AlignRight right alignment 

No other types of alignment are supported.
Note:
For nested lists, HTML commands should be used.
Equivalent to \arg


--------------------------------------------------------------------------------

\n
Forces a new line. Equivalent to <br> and inspired by the printf function.


--------------------------------------------------------------------------------

\p <word>
Displays the parameter <word> using a typewriter font. You can use this command to refer to member function parameters in the running text.

Example:
  ... the \p x and \p y coordinates are used to ...This will result in the following text:

... the x and y coordinates are used to ...
Equivalent to \c To have multiple words in typewriter font use <tt>multiple words</tt>.


--------------------------------------------------------------------------------

\rtfonly
Starts a block of text that will be verbatim included in the generated RTF documentation only. The block ends with a \endrtfonly command.

This command can be used to include RTF code that is too complex for doxygen.

Note: environment variables (like $(HOME) ) are resolved inside a RTF-only block.

See also
sections \manonly, \xmlonly, \latexonly, \htmlonly, and \docbookonly.

--------------------------------------------------------------------------------

\verbatim
Starts a block of text that will be verbatim included in the documentation. The block should end with a \endverbatim command. All commands are disabled in a verbatim block.

Warning
Make sure you include a \endverbatim command for each \verbatim command or the parser will get confused!
See also
sections \code, \endverbatim and \verbinclude.

--------------------------------------------------------------------------------

\xmlonly
Starts a block of text that will be verbatim included in the generated XML output only. The block ends with a \endxmlonly command.

This command can be used to include custom XML tags.

See also
sections \manonly, \rtfonly, \latexonly, \htmlonly, and \docbookonly.

--------------------------------------------------------------------------------

\\
This command writes a backslash character (\) to the output. The backslash has to be escaped in some cases because doxygen uses it to detect commands.


--------------------------------------------------------------------------------

\@
This command writes an at-sign (@) to the output. The at-sign has to be escaped in some cases because doxygen uses it to detect JavaDoc commands.


--------------------------------------------------------------------------------

\~[LanguageId]
This command enables/disables a language specific filter. This can be used to put documentation for different language into one comment block and use the OUTPUT_LANGUAGE tag to filter out only a specific language. Use \~language_id to enable output for a specific language only and \~ to enable output for all languages (this is also the default mode).

Example: 

/*! \~english This is English \~dutch Dit is Nederlands \~german Dies ist
    Deutsch. \~ output for all languages.
 */

--------------------------------------------------------------------------------

\&
This command writes the & character to the output. This character has to be escaped because it has a special meaning in HTML.


--------------------------------------------------------------------------------

\$
This command writes the $ character to the output. This character has to be escaped in some cases, because it is used to expand environment variables.


--------------------------------------------------------------------------------

\#
This command writes the # character to the output. This character has to be escaped in some cases, because it is used to refer to documented entities.


--------------------------------------------------------------------------------

\<
This command writes the < character to the output. This character has to be escaped because it has a special meaning in HTML.


--------------------------------------------------------------------------------

\>
This command writes the > character to the output. This character has to be escaped because it has a special meaning in HTML.


--------------------------------------------------------------------------------

\%
This command writes the % character to the output. This character has to be escaped in some cases, because it is used to prevent auto-linking to word that is also a documented class or struct.


--------------------------------------------------------------------------------

\"
This command writes the " character to the output. This character has to be escaped in some cases, because it is used in pairs to indicate an unformatted text fragment.


--------------------------------------------------------------------------------

\.
This command writes a dot (.) to the output. This can be useful to prevent ending a brief description when JAVADOC_AUTOBRIEF is enabled or to prevent starting a numbered list when the dot follows a number at the start of a line.


--------------------------------------------------------------------------------

\::
This command writes a double colon (::) to the output. This character sequence has to be escaped in some cases, because it is used to reference to documented entities.


--------------------------------------------------------------------------------

\|
This command writes a pipe symbol (|) to the output. This character has to be escaped in some cases, because it is used for Markdown tables.


--------------------------------------------------------------------------------

\--
This command writes two dashes (--) to the output. This allows writing two consecutive dashes to the output instead of one n-dash character (–).


--------------------------------------------------------------------------------

\---
This command writes three dashes (---) to the output. This allows writing three consecutive dashes to the output instead of one m-dash character (—).


--------------------------------------------------------------------------------



--- Commands included for Qt compatibility --- 


The following commands are supported to remain compatible to the Qt class browser generator. Do not use these commands in your own documentation. 

?\annotatedclasslist 
?\classhierarchy 
?\define 
?\functionindex 
?\header 
?\headerfilelist 
?\inherit 
?\l 
?\postheader 

--------------------------------------------------------------------------------


Go to the next section or return to the index. 

--------------------------------------------------------------------------------

Generated by    1.8.13 





#endif

