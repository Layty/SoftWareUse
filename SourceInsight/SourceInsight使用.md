---
title: SourceInsight使用
tags: 
categories: 
typora-root-url: ..
typora-copy-images-to: ..\img\root
date: 2018-09-04 17:20:36
---
# SourceInsight使用

> 本文大部分为摘录整理以及官方help摘录

## Todo

- [ ] souce link 用于编译器信息上的使用

## 常规设置

- 函数名黑体Options->Preferences>SyntaxFormatting >Useonly color formatting 
- 不同类型文件符号连接 Options->Preferences>Symbol Lookups 勾选“Findsymbols across different language types”，这样就可以在*.h、*.c、*.s间统一查找符号。.

### 缩进与TAB

**File Type Option** > **Auto Indenting**> **Smart Indent Option** 中设置大括号,个人习惯不勾选.

```
//都不勾选
if (x)
{

}
//都勾选
if (x)
   {

   }
//不勾选下面的
if (x) {

}
```

**File Type Option** > **Auto Indenting**>**Auto Indent Type**设置代码快的缩进,

- Simple   将自动缩进文本以与前一行或后一行对齐。
- Smart    插入新行时，将自动增加或减少缩进级别,比如`if`里面会自动有一个`TAB`,开启这个模式的时候,会自on个识别`;`,没有`;`的时候会再缩进.所以注意下宏语句,多写个`;`.

**PreferencesTyping**中设置TAB的按键

- Typing tab indents line，regardless of selection  删除空行中的tab
- Typing tab replaces current selection  勾选后按Tab会清除所选的文字

**Options**>**Document Options**设置tab为4个空格

### 小键盘恢复

恢复小键盘的“+，-，*，/”功能
**Options**>**Key assignments**>
Scroll 找到Scroll Half Page Up，取消小键盘/
Scroll 找到Scroll Half Page Down取消小键盘*
Function找到Function Up，取消小键盘-
Function找到Function down，取消小键盘+。
save 找到save all，更改为ctrl+shift+a，
select找到select all，更改为ctrl +a

### 替换,重命名

Smart Rename命令,快捷键是Ctrl+’.

- 如果你在命名成员变量、或本地变量（），Old Name框中会显示完全标记名、即上层容器名+标记名。例如，框中的“DocDraw.paintStruc”代表DocDraw是函数名，paintStruc是函数的本地成员变量。
- New Name填新名称。只填标记名，不填上层容器名
- Output Search Results如果勾选，搜索替换结果日志会被输出到Search Results窗口中。可以通过Windows菜单来切换，或ctrl+tab切换察看。并且每一条记录旁会有SourceLink链接到替换发生地文件。



## 自定义命令

自定义命令类似于命令行批处理文件。SIS允许自定义命令在后台运行；并可以捕捉自定义命令的输出、放置于文件中、或粘贴入当前光标插入点。分别利用上面SIS对输出信息的处理方式，自定义命令对集成编译器相当有用，可以捕捉编译器输出并创建SourceLink寻错；自定义命令对于文本过滤也相当有用，可选中待过滤区块、运行Sort自定义命令、粘贴回选定区块、即完成文本过滤。

**Options**>**Custom Command**

- Run框、填入待执行命令行，可含有特殊元字符，见后面的元字符表 Dir框、执行命令行时应处的目录，如不填，以源代码文件所在目录为命令执行目录
- 勾选Output框的Capture Output、输出被捕捉，如果勾选Paste Output，输出被粘贴
- 勾选Control Group框中的Save Files First、SIS会在运行命令前先检查文件是否保存
- 勾选Control Group框中的Pause When Done、SIS会在命令结束后暂停、方便检查
- 勾选Source Links in Output框中的Parse Source Links

## 编译开关 Conditions

有些时候Si无法正确识别你的宏是否被正确定义,可以手动定义宏的开关条件,分为全局设置和工程设置

- 全局 Options > Preferences > Language > Global Conditions
- 工程 Options > Preferences > Language> Project Specific Conditions
- 也可以直接在代码框的地方右键 Edit condition

## Source Link

SourceLink根据特定的搜索模式，把当前文件中满足模式的行、链接到由该行指定的其他源文件中。所谓特定的搜索模式，共有两种“File, then line”和“Line, then file”，其中前后两部分依靠正则表达式的组的概念来予以分割。如果当前文件具有匹配行，比如“Error d:tcsrcq5.c 18: Lvalue required in function jsSort”，那么SourceInsight在该行创建SourceLink、把该行链接到由该行指定的文件中（即d:tcsrcq5.c，第18行）。

1. 创建SourceLink
   - 运行Search菜单的Parse Source Links…命令，在弹出的框中、选择搜索模式、并填入相应的正则表达式串，点OK，SIS就会解析当前文件，如果有匹配，就创建SourceLink。

2. 解析日志信息时，使用SourceLink
    - 可以打开日志信息，运行Parse Source Links命令，日志中能够匹配模式的每一行（通常是含有错误信息的行）、就会被设置上一个SourceLink

3. 在解析自定义命令输出时，使用SourceLink
   - 首先勾选Custom Command 中的“Parse Links in Output”，然后选择特定的搜索模式，最后填入合适的正则表达式。这样，Source Insight把输出信息作为当前搜索用文件；并且，如果有匹配行（通常即编译错误信息行），SIS为该行创建SourceLink、并把每一个错误信息中给定的文件（和行号）作为link目的地，这对于我们修改源代码错误非常有帮助。






## 语言解析

官方一些扩展语言解析在[这里](https://www.sourceinsight.com/download/custom-languages/)

1. 先在 **Options > Preferences**>**Languages** 导入下载的语言(.CLF)
2. 点击**File** **Types** 打开文件类型,这里手动添加文件类型的后缀名`*.xxx`
3. 选中新建的文件类型,点击**Parsing**,里面的language选择下载导入的
4. 点击close

## 宏

> 参考链接
> [csdn翻译](https://blog.csdn.net/zxf20063033/article/details/9044967)
> [SI4官方help](https://www.sourceinsight.com/doc/v4/userguide/index.html#t=Manual%2FMacro_Language%2FSetReg_reg_key_name_value.htm)
> [官方的一些简单例子](https://www.sourceinsight.com/download/macro-files/)

```
autoexp.em              Automatically expands C statements like if, for, while, switch, etc..  
closebuf.em             Close all non-dirty file windows  
CloseOldWindows.em      Closes all but the most recently visited windows and files. Any dirty files are kept open.  
comment.em              Comment/Uncomment the selected block of text using single line comments and indent it  
CompleteWord.em         Word completion within a buffer  
eventsample.em          contains example event functions  
home.em                 Extends the selection back to the first non-white space on the current line.   
matchdelim.em           Finds matching scoping delimiters and jumps to them  
multikey.em             Can be used to create a secondary key mapping which maps keys after an initial	key press.  
PrintSelection.em       Prints the currently selected text.   
ProgressiveSearch.em    command that performs a progressive search as the user types.  
replace.em              Replace a list of strings across the whole project.  
ReplaceSpans.em         Replaces patterns that span lines  
siutils.em              Misc utilities  
spacetotab.em           Converts leading spaces to tabs in C or C++ source lines  
stringutils.em          Assorted string utility functions used by some other macro files.  
Tabby.em                Converts spaces to tabs and tabs to spaces.  
TrimSpaces.em           This function trims white spaces from the ends of the selected lines.  
utils.em                Misc utilities.  
wordstar.em             Wordstar Keyboard Emulation
```

宏后缀名为.em, 可以直接添加到当前工程中、任何在Project Symbol 路径下的工程或 base project中，一旦宏文件变成project的一个部分，文件中宏函数就可以在Key Assignments和Menu Assignments 对话框中使用。

- 不区分大小写

- 自动忽略空格

- 语句后不要去`;`,如果有自动忽略

- 宏允许设置一些值到注册表`HKEY_CURRENT_USER\Software\Source Dynamics\Source Insight\4.0`
  ```
    SetReg ("key1", "a")
    Msg(GetReg (key1))
    Stop
  ```

- 小技巧,使用宏当计算器(只能算整数,比较鸡肋哈哈)

```c
a=1+2+3
Msg(a)
stop
```

### 运行

没有参数的宏作为用户级别的命令,可以绑定,带有参数的宏不允许绑定.

1. 使用按键绑定

2. 使用菜单绑定宏

3. **内联宏**,使用命令`Run Macro`来运行当前鼠标位置指向的宏,这样宏可以位于源码的注释中.可以现将`Application: Run Macro`这个命令绑定到一个按键,然后可以调试宏.注意:调试的时候注意鼠标要在第一行

```c
a=Ask("123")////////鼠标放在在这里
Msg(a)
Stop
```

### 函数

```c
macro my_macro()
{
/* 注释*/
.. statements.. // 注释
}
可以向函数传递参数和调用其他函数。也可以返回一个值，像这样 " return n"，这里n就是返回值。
macro add2(n)
{
return n + 2
}
```

### 作用域

作用域是全局的,所有定义在任何打开的文件、保存在工程、或在一个项目符号路径下的工程中的宏都在作用域内。**无需前置声明.**

### 变量

#### 变量定义

变量字母开头,无需定义即可使用,都是字符串的类型,但是也支持做加减乘除.也可以使用`var`来定义.一般使用`nil`作为空变量

```c
var s1="abc" 
var s1=abc
s1=abc
// 以上三者都是等价的

s2=s1 //s2=s1="abc"

s3=nil
s3=""
//以上两者等价
```

#### 变量运算

- 支持整数计算,不支持浮点数的计算.使用`if (IsNumber(x))`判读是否为纯数字
- 可以使用下标索引来提取变量的相关字符`s="012345"`,`s[0]=0`

#### 变量内部拼接

使用`@`相当于C中的宏拼接,具体语法举例如下:这个例子中用变量值替换@usename@

```c
S = “Hey, @username@, don’t break the build again!”
```

要使用@字符，使用\或两个@。`S = “Mail info@@company.com for information.”`

#### 结构变量Record

支持一种聚合的变量,一个record 实际上是分开的“name=value”数值对列表.不需要特定的结构声明,可以在任意地方创建,直接给record赋值的时候注意不能人为的添加空格

```
userinfo = "c=\"1\"
userinfo.a = "a"
userinfo.b = "b"
Msg(userinfo)		//显示c="1";a="a";b="b"
Msg(userinfo.a)		//显示a
Msg(userinfo.b)		//显示b
Msg(userinfo.c)		//显示c

//也可以一次性创建a,b,c,这里不要人为的添加空格
userinfo = "c=\"1\";a=\"a\";b=\"b\" "
Msg(userinfo)
Msg(userinfo.a)
Msg(userinfo.b)
Msg(userinfo.c)

```

- 读取`Filename = slr.file // get file field of slr`
- 写入`userinfo.name = myname; // set “name” field of userinfo*`
- 初始化为空
  ```
  userinfo = nil // make a new empty record
  userinfo.name = “Jeff”
  ```


#### 数组buf

不支持数组变量，但是可以使用文件buffer作为动态数组。buffer中的每一行可以作为数组的一个元素.创建一个record buffer组,这个详细的还没有研究

```
hbuf = NewBuf()
rec = "name=\"Joe Smith\";age=\"34\";experience=\"guru\""
AppendBufLine(hbuf, rec)
rec = "name=\"Mary X"\";age=\"31\";experience=\"intern\""
AppendBufLine(hbuf, rec)
// hbuf now has 2 records in it
...
rec = GetBufLine(hbuf, 0) // retrieve element at index 0
PutBufLine(hbuf, 1, rec)  // store element at index 1
CloseBuf(hbuf)
```

## 文件同步Synchronize 

**Options** > **Preferences>** **Gen­eral**.设置自动后台同步数据库

**Project** > **Synchronize File**

- Force all files to be re-parsed 更新所有文件,否则只更新新文件
- Synchronize the current source file only  更新当前文件
- Add new files automatically 自动新增文件到工程
- Remove missing files from project 勾选后不提示消息,不要勾选

## 视图关系relation

- contains 显示当前标识符的内容,比如结构体变量显示成员变量
- calls  显示调用树,显示该函数调用了哪些函数
- reference 显示被哪些函数调用
- 可以在视图窗口中右键指定的函数展开更多层次的调用`expand special`
- 运行不显示某些符号量的关系树 `call Graph Filter`

**跟踪**Automatic Symbol Tracking,没觉得啥区别

- Track select 自动跟踪光标下的标识
- Track the enclosingfunction 自动显示函数或者结构定义

## 快捷键

需要记忆的

- 跳到对应的`{}`位置 `ALT`+`}`

- 跳到对应的`()`位置 `ALT`+`(`或者`ALT+(`

- 下一个link Ctrl+F9

- 光标前后移动 alt+`,`或者alt+`.`其实也就是`<>`

- View->Draft View 使用等宽视图, `ALT+F12`


```
/*

F8 高亮符号

完成语法                                :Ctrl+E
复制一行                                :Ctrl+K
恰好复制该位置右边的该行的字符          :Ctrl+Shift+K

复制到剪贴板                            :Ctrl+Del
剪切一行                                :Ctrl+U
剪切该位置右边的该行的字符              :Ctrl+;
剪切到剪贴板                            :Ctrl+Shift+X
剪切一个字                              :Ctrl+,

左边缩进                                :F9
右边缩进                                :F10
插入一行                                :Ctrl+I
加入一行                                :Ctrl+J

从剪切板粘贴                            :Ctrl+Ins
粘贴一行                                :Ctrl+P
重复上一个动作                          :Ctrl+Y
重新编号                                :Ctrl+R

重复输入                                :Ctrl+
替换                                    :Ctrl+H
智能重命名                              :Ctrl+''
关闭文件                                :Ctrl+W
关闭所有文件                            :Ctrl+Shift+W
新建                                    :Ctrl+N
转到下一个文件                          :Ctrl+Shift+N
打开                                    :Ctrl+O

重新装载文件                            :Ctrl+Shift+O
另存为                                  :Ctrl+Shift+S
显示文件状态                            :Shift+F10
激活语法窗口                            :Alt+L
回到该行的开始                          :Home
回到选择的开始                          :Ctrl+Alt+[
到块的下面                              :Ctrl+Shift+]
到块的上面                              :Ctrl+Shift+[

书签                                    :Ctrl+M
到选择部分的尾部                        :Ctrl+Alt+]
到下一个函数                            :小键盘 +
上一个函数                              :小键盘 -
后退                                    :Alt+,, Thumb 1 Click
后退到索引                              :Alt+M
向前                                    :Alt+., Thumb 2 Click

转到行                                  :F5, Ctrl+G
转到下一个修改                          :Alt+(KeyPad) +
转到下一个链接                          :Shift+F9,
回到前一个修改                          :Alt+(KeyPad) -
跳到连接(就是语法串口列表的地方)        :Ctrl+L
跳到匹配                                :Alt+]

选择一行                                :Shift+F6
选择句子(直到遇到一个 . 为止)           :Shift+F7, Ctrl+.
从当前位置选择到文件结束                :Ctrl+Shift+End
从当前位置选择到行结束                  :Shift+End
从当前位置选择到行的开始                :Shift+Home
从当前位置选择到文件顶部                :Ctrl+Shift+Home

选择一个单词                            :Shift+F5
选择左边单词                            :Ctrl+Shift+Left
选择右边单词                            : Ctrl+Shift+Right
排列语法窗口(有三种排列方式分别按1,2,3次)   :Alt+F7

移除文件                                :Alt+Shift+R
同步文件                                :Alt+Shift+S
增量搜索(当用Ctrl + F 搜索,然后按F12就会转到下一个匹配)         :F12
替换文件                                :Ctrl+Shift+H

向后搜索                                :F3
在多个文件中搜索                        :Ctrl+Shift+F
向前搜索                                :F4
搜索选择的(比如选择了一个单词,shift+F4将搜索下一个)       : Shift+F4
```
## 正则表达式

表达式中通过`\(`和`\)`来实现分组的目的,分组匹配后的串从1开始计数.举例如下:

```c
//存在以下字符串
abcxyz
//使用正则匹配,\1=abc,\2=xyz
\(abc\)\(xyz\)
//现在使用正则替换
\2\1
//得到新的串
xyzabc
```

一个有用的例子(注释与反注释函数)

```c
//注释函数
printf("hello\r\n");
匹配 ^\(.*\)\(printf\)\(.*\)
替换 \1/*\2\3*/

//恢复函数
/*printf("hello\r\n");*/
匹配 	 ^\(.*\)\(/\*\)\(.*printf.*\)\(\*/\)
替换   \1\3
```

字符匹配

```
1.1 匹配单个任意字符 . (dot)
1.2 行首和行尾 ^ and $
1.3 匹配Tab 和Space
    \t (tab character)
    \s (space character)
    \w (Tab or Space)
1.4 匹配多个字符
    * 多个前面一样字符(>=0 个)
    + 多个前面一样字符(>=1 个)

1.5 匹配一串字符 [ .. ]
    [abc] matches a, b, and c, but not d.
    [^abc] matches d, e, or f, but not a, b, or c.
    [a-z] matches any character in the range a through z, but not A or 1 or 2.  
    [a-zA-Z] matches any alphabetic character.
    [^a-zA-Z0-9] matches any non-alphanumeric character.

1.7 特殊字符匹配(转义字符)
    \ (backslash)
    a\*b matches a*b literally

工具简介
代码    说明
	.   匹配除换行符以外的任意字符
	\w  匹配字母或数字或下划线
	\s  匹配任意的空白符
	\d  匹配数字
	\b  匹配单词的开始或结束
	^   匹配字符串的开始
	$   匹配字符串的结束
	常用限定符
	代码/语法   说明
	*   重复零次或更多次
	+   重复一次或更多次
	?   重复零次或一次
	{n} 重复n次
	{n,}    重复n次或更多次
	{n,m}   重复n到m次
	常用反义词
	代码/语法   说明
	\W  匹配任意不是字母，数字，下划线，汉字的字符
	\S  匹配任意不是空白符的字符
	\D  匹配任意非数字的字符
	\B  匹配不是单词开头或结束的位置
	[^x]    匹配除了x以外的任意字符
	[^aeiou]    匹配除了aeiou这几个字母以外的任意字符

一、校验数字的表达式
	数字：^[0-9]*$
	n位的数字：^\d{n}$
	至少n位的数字：^\d{n,}$
	m-n位的数字：^\d{m,n}$
	零和非零开头的数字：^(0|[1-9][0-9]*)$
	非零开头的最多带两位小数的数字：^([1-9][0-9]*)+(.[0-9]{1,2})?$
	带1-2位小数的正数或负数：^(\-)?\d+(\.\d{1,2})?$
	正数、负数、和小数：^(\-|\+)?\d+(\.\d+)?$
	有两位小数的正实数：^[0-9]+(.[0-9]{2})?$
	有1~3位小数的正实数：^[0-9]+(.[0-9]{1,3})?$
	非零的正整数：^[1-9]\d*$ 或 ^([1-9][0-9]*){1,3}$ 或 ^\+?[1-9][0-9]*$
	非零的负整数：^\-[1-9][]0-9″*$ 或 ^-[1-9]\d*$
	非负整数：^\d+$ 或 ^[1-9]\d*|0$
	非正整数：^-[1-9]\d*|0$ 或 ^((-\d+)|(0+))$
	非负浮点数：^\d+(\.\d+)?$ 或 ^[1-9]\d*\.\d*|0\.\d*[1-9]\d*|0?\.0+|0$
	非正浮点数：^((-\d+(\.\d+)?)|(0+(\.0+)?))$ 或 ^(-([1-9]\d*\.\d*|0\.\d*[1-9]\d*))|0?\.0+|0$
	正浮点数：^[1-9]\d*\.\d*|0\.\d*[1-9]\d*$ 或 ^(([0-9]+\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\.[0-9]+)|([0-9]*[1-9][0-9]*))$
	负浮点数：^-([1-9]\d*\.\d*|0\.\d*[1-9]\d*)$ 或 ^(-(([0-9]+\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\.[0-9]+)|([0-9]*[1-9][0-9]*)))$
	浮点数：^(-?\d+)(\.\d+)?$ 或 ^-?([1-9]\d*\.\d*|0\.\d*[1-9]\d*|0?\.0+|0)$

二、校验字符的表达式
	汉字：^[\u4e00-\u9fa5]{0,}$
	英文和数字：^[A-Za-z0-9]+$ 或 ^[A-Za-z0-9]{4,40}$
	长度为3-20的所有字符：^.{3,20}$
	由26个英文字母组成的字符串：^[A-Za-z]+$
	由26个大写英文字母组成的字符串：^[A-Z]+$
	由26个小写英文字母组成的字符串：^[a-z]+$
	由数字和26个英文字母组成的字符串：^[A-Za-z0-9]+$
	由数字、26个英文字母或者下划线组成的字符串：^\w+$ 或 ^\w{3,20}$
	中文、英文、数字包括下划线：^[\u4E00-\u9FA5A-Za-z0-9_]+$
	中文、英文、数字但不包括下划线等符号：^[\u4E00-\u9FA5A-Za-z0-9]+$ 或 ^[\u4E00-\u9FA5A-Za-z0-9]{2,20}$
	可以输入含有^%&’,;=?$\”等字符：[^%&',;=?$\x22]+
	禁止输入含有~的字符：[^~\x22]+

	用元字符
	.   	匹配除换行符以外的任意字符
	\w  	匹配字母或数字或下划线
	\s  	匹配任意的空白符
	\d  	匹配数字
	\b  	匹配单词的开始或结束
	^   	匹配字符串的开始
	$   	匹配字符串的结束

	常用限定符
	*   	重复零次或更多次
	+   	重复一次或更多次
	?   	重复零次或一次
	{n} 	重复n次
	{n,}    重复n次或更多次
	{n,m}   重复n到m次

	常用反义词
	\W  	匹配任意不是字母，数字，下划线，汉字的字符
	\S  	匹配任意不是空白符的字符
	\D  	匹配任意非数字的字符
	\B  	匹配不是单词开头或结束的位置
	[^x]    匹配除了x以外的任意字符
	[^aeiou]    匹配除了aeiou这几个字母以外的任意字符

	常用模式修正符
	代码 		语法   说明
	i   	表示在进行匹配的时候不区分大小写
	m   	多行识别.即将字符串视为多行,不管是那行都能匹配
	s   	将字符串视为单行,转义回车换行符作为普通字符
	g   	表示全局匹配
	x   	将模式中的空白忽略
	A   	强制从目标字符串开头匹配
	D   	强制尾部无任何内容.若使用$限制结尾字符,则不允许结尾有换行
	U   	禁止贪婪匹配,只匹配最近的一个字符串(不重复匹配)
	e   	配合PHP函数preg_replace()使用,可以把匹配来的字符串当作正则表达式执行


三、特殊需求表达式参考
	Email地址：^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$
	域名：[a-zA-Z0-9][-a-zA-Z0-9]{0,62}(/.[a-zA-Z0-9][-a-zA-Z0-9]{0,62})+/.?
	InternetURL：[a-zA-z]+://[^\s]* 或 ^http://([\w-]+\.)+[\w-]+(/[\w-./?%&=]*)?$
	手机号码：^(13[0-9]|14[5|7]|15[0|1|2|3|5|6|7|8|9]|18[0|1|2|3|5|6|7|8|9])\d{8}$
	电话号码(“XXX-XXXXXXX”、”XXXX-XXXXXXXX”、”XXX-XXXXXXX”、”XXX-XXXXXXXX”、”XXXXXXX”和”XXXXXXXX)：^($$\d{3,4}-)|\d{3.4}-)?\d{7,8}$
	国内电话号码(0511-4405222、021-87888822)：\d{3}-\d{8}|\d{4}-\d{7}
	身份证号(15位、18位数字)：^\d{15}|\d{18}$
	短身份证号码(数字、字母x结尾)：^([0-9]){7,18}(x|X)?$ 或 ^\d{8,18}|[0-9x]{8,18}|[0-9X]{8,18}?$
	帐号是否合法(字母开头，允许5-16字节，允许字母数字下划线)：^[a-zA-Z][a-zA-Z0-9_]{4,15}$
	密码(以字母开头，长度在6~18之间，只能包含字母、数字和下划线)：^[a-zA-Z]\w{5,17}$
	强密码(必须包含大小写字母和数字的组合，不能使用特殊字符，长度在8-10之间)：^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,10}$
	日期格式：^\d{4}-\d{1,2}-\d{1,2}
	一年的12个月(01～09和1～12)：^(0?[1-9]|1[0-2])$
	一个月的31天(01～09和1～31)：^((0?[1-9])|((1|2)[0-9])|30|31)$
	钱的输入格式：
	有四种钱的表示形式我们可以接受:”10000.00″ 和 “10,000.00″, 和没有 “分” 的 “10000″ 和 “10,000″：^[1-9][0-9]*$
	这表示任意一个不以0开头的数字，但是，这也意味着一个字符”0″不通过，所以我们采用下面的形式：^(0|[1-9][0-9]*)$
	一个0或者一个不以0开头的数字.我们还可以允许开头有一个负号：^(0|-?[1-9][0-9]*)$
	这表示一个0或者一个可能为负的开头不为0的数字.让用户以0开头好了.把负号的也去掉，因为钱总不能是负的吧.下面我们要加的是说明可能的小数部分：^[0-9]+(.[0-9]+)?$
	必须说明的是，小数点后面至少应该有1位数，所以”10.”是不通过的，但是 “10″ 和 “10.2″ 是通过的：^[0-9]+(.[0-9]{2})?$
	这样我们规定小数点后面必须有两位，如果你认为太苛刻了，可以这样：^[0-9]+(.[0-9]{1,2})?$
	这样就允许用户只写一位小数。下面我们该考虑数字中的逗号了，我们可以这样：^[0-9]{1,3}(,[0-9]{3})*(.[0-9]{1,2})?$
	1到3个数字，后面跟着任意个 逗号+3个数字，逗号成为可选，而不是必须：^([0-9]+|[0-9]{1,3}(,[0-9]{3})*)(.[0-9]{1,2})?$
	备注：这就是最终结果了，别忘了”+”可以用”*”替代。如果你觉得空字符串也可以接受的话(奇怪，为什么?)最后，别忘了在用函数时去掉去掉那个反斜杠，一般的错误都在这里
	xml文件：^([a-zA-Z]+-?)+[a-zA-Z0-9]+\\.[x|X][m|M][l|L]$
	中文字符的正则表达式：[\u4e00-\u9fa5]
	双字节字符：[^\x00-\xff] (包括汉字在内，可以用来计算字符串的长度(一个双字节字符长度计2，ASCII字符计1))
	空白行的正则表达式：\n\s*\r (可以用来删除空白行)
	HTML标记的正则表达式：<(\S*?)[^>]*>.*?</\1>|<.*? /> (网上流传的版本太糟糕，上面这个也仅仅能部分，对于复杂的嵌套标记依旧无能为力)
	首尾空白字符的正则表达式：^\s*|\s*$或(^\s*)|(\s*$) (可以用来删除行首行尾的空白字符(包括空格、制表符、换页符等等)，非常有用的表达式)
	腾讯QQ号：[1-9][0-9]{4,} (腾讯QQ号从10000开始)
	中国邮政编码：[1-9]\d{5}(?!\d) (中国邮政编码为6位数字)
	IP地址：\d+\.\d+\.\d+\.\d+ (提取IP地址时有用)
	IP地址：((?:(?:25[0-5]|2[0-4]\\d|[01]?\\d?\\d)\\.){3}(?:25[0-5]|2[0-4]\\d|[01]?\\d?\\d)) (由@飞龙三少 提供，感谢共享)
```



## 一个牛逼的宏文件

### 目录结构

```shell
C:\USERS\ADMINISTRATOR\DESKTOP\SOURCE_INSIGHT4.0\PROJECTS\BASE
├─basic                                    //实例,不参与工程
├─help                                    //一些帮助提示,可以加入菜单查看
│  │  ascii_table.h                 
│  │  
│  └─project                              //项目经验的一些总结
│          project_xxx.h
│          
├─lang_auto_expand                        //语言扩展,CTRL+ENTER
│      auto_expand_bash.em                //关键字扩展,c也是调用这个
│      auto_expand_c.em                   //关键字扩展,c也是调用这个去调用auto_expand_bash.em
│      auto_expand_cpp.em
│      auto_expand_default.em
│      simc.em							//simc.em github上厉害的宏
│      
├─lang_code_review                        //语言扩展,CTRL+ENTER
│      code_review.em                     //代码省察的,暂时没看懂不需要
│      quick_code_ansi_c.em               //也是关键字扩展,华为的,包含问题单号的
│      quick_code_common.em               //去除前后空格
│      
└─main                                    //主要宏文件实现
        main_config.em                    //配置按键和环境
        main_entry.em                     //主入口
        main_event_handler.em             //事件句柄
        main_help.em                      //help菜单打开文件
        main_plugin.em                    //插件命令
        private_utils.em                  //环境变量配置接口
        public.em                         //一些公共函数,环境相关
        test.em                           //测试
        utils.em                          //基本例子
        utils_common.em                   //一些公共函数,文件目录操作
        utils_selection_operate.em        //块注释与取消
        utils_window_oprate.em            //关闭窗口操作
```

### 详细内容说明

- 主入口main_entry.em

```
//配置参数
macro EntryConfig()
//自动扩展,CTRL+ENTER 自动根据文件类型处理
macro EntryAutoExpand()
//文字编辑扩展命令 此宏映射快捷键 CTRL+ALT+Z ,没做完整,只做了复制路径到剪切板
macro EntrySmartEdit()
//调用外部工具调用 此宏映射快捷键 CTRL+ALT+O,其实是调用一个py脚本 
macro EntryExternTools()
//项目帮助文档 此宏映射快捷键 CTRL+ALT+P 显示菜单,这里主要放一些公共的信息
macro EntryProjectHelp()//Source_Insight4.0\Projects\Base\help\project 下的help
```

- 配置参数main_config.em

```
//绑定全局按键
macro __global_key_binding()
//全局配置,语言/名字/外部工具/TRACE
macro ConfigureSystem()
//显示配置信息
macro ViewConfigure()
//配置外部工具的路径,用到了字符串拼接@@
macro ExternalTools()
//配置调试输出语句 C/CPP,没做好
macro ConfigureTrace()
```

- 公共函数`utils_common.em`和`public.em`

```
-public.em
//获取后缀名,文件类型
macro public_get_file_ext(sz)
//读取一个文件内容显示在另外一个文件末尾
macro public_append_from_to(hbufFrom,hbufTo)
//获得cmd的路径,返回值是 C:\windows\system32\cmd.exe
macro public_get_cmd_path()
public_get_project_path
//获得当前工程的路径

-utils_common.em		//文件目录操作
//字符串 是否包含空格
macro IsContainSpace(path)
//拷贝文件路径  style: linux or windows
macro CopyFilePath()
//拷贝文件名
CopyFileName()
//重构出的通用接口 获取环境变量并在失败的时候提示用户输入
macro PromptRegName(Tips_EN,Tips_CN,EnvName_EN,EnvName_CN)
//获取父目录
macro __common_get_parrent_dir(path)
//将window路径转成linux格式
macro __common_get_linux_style_path(path)
//获取SI setting ROOT 目录
macro __common_get_root_path()
//获取SI Setting 目录
macro __common_get_si_setting_path()
//获取当前project 目录
macro __common_get_project_path()
//获取当前cache 目录
macro __common_get_cache_path(szName)
//获取当前 help目录
macro __common_get_help_path(szName)
//获取当前plugin 目录
macro __common_get_plugin_path()
```

### 绑定的快捷键

```
//运行外部命令
CTRL+ALT+R
//测试宏
CTRL+ALT+T
//配置文件
CTRL+ALT+M
//扩展关键字
CTRL+ENTER
//外部工具调用,这里是调用LaunchTools.py
CTRL+ALT+O
//特殊编辑器
CTRL+ALT+Z,没干啥
//没做好,应该是操作空格的
CTRL+B
//快速删除行
CTRL+D
//选中单词转换为小写  
CTRL+SHIFT+L  
//单词转换为大写 
CTRL+SHIFT+U 
//Tab转空格
CTRL+SHIFT+T
//代码块注释和取消注释快捷键  
CTRL+Q 
//这两个按键有点冲突
//astyle linux风格
CTRL + ALT + L
//astyle windows风格
CTRL+ ALT + W
```

### Auto Expand关键字

```c
​```
 * config ----------------------------------------配置语言和作者名称及公司名称
 ***********************标准头自动生成(自动扩展)******************************
 * file ------------------------------------------------自动生成标准文件头信息
 * func ------------------------------------------------自动生成标准函数头信息
 * hi --------------------------------------------------添加一条修改历史记录
 * hd ------------------------------------------------------自动生成函数头文件
 * hdn -----------------------------------------------------自动生成函数头文件
 
 *************************语句块自动生成(自动扩展)****************************
 * {}-----------------------------------------------------------自动括号语句块
 * while---------------------------------------------------自动完成while语句块
 * if---------------------------------------------------------自动完成if语句块
 * for-------------------------------------------------------自动完成for语句块
 * do while---------------------------------------------自动完成do while语句块
 * switch-------------------------------------------------自动完成switch语句块
 * case-----------------------------------------------------自动完成case语句块
 * struct-------------------------------------------------自动完成struct语句块
 * enum-----------------------------------------------------自动完成enum语句块
 
 *************************添加修改注释(自动扩展)******************************
 * #ifd---------------------------------------------------自动完成#ifdef语句块
 * #ifn--------------------------------------------------自动完成#ifndef语句块
 * #if-------------------------------------------------------自动完成#if语句块
 * cpp----------------------------------------------自动完成extern "C"语句块
 * ap---------------------------------------------------------添加一个问题单号
 * ab-----------------------------------------------------------添加--注释开始
 * ae-----------------------------------------------------------添加--注释结束
 * db------------------------------------------------------------删除-注释开始
 * de------------------------------------------------------------删除-注释结束
 * mb------------------------------------------------------------修改-注释开始
 * me------------------------------------------------------------修改-注释结束
 * abg--------------------------------------------------插入添加开始和结束说明
 * dbg--------------------------------------------------插入删除开始和结束说明
 
 ************************语句块自动生成(菜单或快捷键)*************************
 * ComentCPPtoC----------------------------------将选中区域内注释改为C++风格
 * ReplaceBufTab-------------------------------------将当前文件的TAB替换为空格
 * ReplaceTabInProj----------------------------------将当前项目的TAB替换为空格
 * InsertFuncName --------------------------------------插入当前所在的函数名称
 * FormatLine-----------------------------------------------自动分行格式化文字
 * UpdateFunctionList---------------------------------------自动生成函数头信息
 * DelCompoundStatement-------------------------------------符合语句块整个删除
 * FunctionHeaderCreate ------------------------------------------函数头的创建
 * HeaderFileCreate ------------------------------------插入当前所在的函数名称
 
 ***********************插入调试块语句(菜单或快捷键)**************************
 * InsertTraceInfo--------------------------------------当前函数调插入调试语句
 * AutoInsertTraceInfoInBuf-------------------------------当前文件插入调试语句
 * AutoInsertTraceInfoInPrj-------------------------------当前工程插入调试语句
 * RemoveTraceInfo----------------------------------------删除当前函数调试语句
 * RemoveCurBufTraceInfo----------------------------------删除当前文件调试语句
 * RemovePrjTraceInfo-------------------------------------删除当前工程调试语句
 *****************************************************************************
​```
```
### 自己的调试代码

```
//打印变量到文件
var ln
hnewbuf = newbuf("SI configuration")
if(hnewbuf == hNil)
{
    Msg("Create a new buf failure!")
    stop
}
ln = 0
InsBufLine(hnewbuf, ln++, sDir)
SetCurrentBuf(hnewbuf)
stop
```



