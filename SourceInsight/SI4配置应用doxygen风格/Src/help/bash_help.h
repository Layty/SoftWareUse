#ifndef __BASH_HELP_H__
#define __BASH_HELP_H__

/*
#0-编码规范
#1-语言帮助信息
#2-关键字智能提示
#3-库函数智能提示
#4-库函数说明
#5-关键字着色
*/

/******************************************************************************************
 2.0  类型和值
******************************************************************************************/
/*
--------------------------------------------------------------------
#变量     描述                 例子
--------------------------------------------------------------------
$0           The filename of the current script.
$n           These variables correspond to the arguments with which a script was invoked.
             Here n is a positive decimal number corresponding to the position of an argument
             (the first argument is $1, the second argument is $2, and so on).
$#           The number of arguments supplied to a script.
$*           All the arguments are double quoted. If a script receives two arguments,
             $* is equivalent to $1 $2.
$@           All the arguments are individually double quoted.
             If a script receives two arguments, $@ is equivalent to $1 $2.
$?           The exit status of the last command executed.
$$           The process number of the current shell. For shell scripts,
             this is the process ID under which they are executing.
$!           The process number of the last background command.

--------------------------------------------------------------------
#数组        描述                       例子
--------------------------------------------------------------------
array_var[index]= value        (index = 0 ..)
array_name=(value_1 .. value_n)
${array_name[*]}                访问所有元素
${array_name[@]}                访问所有元素

算术运算符(假设变量a=10,变量b=20)
--------------------------------------------------------------------
#运算符      描述                       例子
--------------------------------------------------------------------
+            加法                       `expr $a + $b` will give 30
-            减法                       `expr $a - $b` will give -10
*            乘法                       `expr $a * $b` will give 200
/            除法                       `expr $b / $a` will give 2
%            模(取余)                    `expr $b % $a` will give 0
=            赋值                        a=$b would assign value of b into a
==           等于                        [ $a == $b ] would return false.
!=           不等于                      [ $a != $b ] would return true.


#关系运算符(假设变量a=10,变量b=20)
--------------------------------------------------------------------
运算符       描述                        示例
--------------------------------------------------------------------
-eq          比较两个变量相等            [ $a -eq $b ] is not true.
-ne          比较两个变量不相等          [ $a -ne $b ] is true.
-gt          大于                        [ $a -gt $b ] is not true.
-lt          小于                        [ $a -lt $b ] is true.
-ge          大于等于                    [ $a -ge $b ] is not true.
-le          小于等于                    [ $a -le $b ] is true.

#布尔运算符
--------------------------------------------------------------------
运算符       描述                       示例
--------------------------------------------------------------------
!            逻辑非                      [ ! false ] is true.
-o           逻辑或                      [ $a -lt 20 -o $b -gt 100 ] is true.
-a           逻辑与                      [ $a -lt 20 -a $b -gt 100 ] is fa


#字符串运算符(假设变量a="abc" 和变量b="efg"
--------------------------------------------------------------------
运算符       描述                        示例
--------------------------------------------------------------------
=            字符串是否相等              [ $a = $b ] is not true.
!=           字符串是否不相等            [ $a != $b ] is true.
-z           字符串长度是否为0           [ -z $a ] is not true.
-n           字符串长度是否非0           [ -z $a ] is not false.
str          字符串为非空                [ $a ] is not false.


#文件测试操作
--------------------------------------------------------------------
操作符       描述                        示例
--------------------------------------------------------------------
-b           文件是否为块设备文件        [ -b $file ] is false.
-c           文件是否为字符设备文件      [ -b $file ] is false.
-d           文件是否为目录              [ -d $file ] is not true.
-f           文件是否为一个普通文件      [ -f $file ] is true.
-g           文件是否设置SGID标志        [ -g $file ] is false.
-k           文件是否设置sticky标志      [ -k $file ] is false.
-p           文件是否为命名管道文件      [ -p $file ] is false.
-t           文件是否是否和终端关联      [ -t $file ] is false.
-u           文件是否设置SUID标志        [ -u $file ] is false.
-r           文件是否可读                [ -r $file ] is true.
-w           文件是否可写                [ -w $file ] is true.
-x           文件是否可执行              [ -x $file ] is true.
-s           文件size是否大于0           [ -s $file ] is true.
-e           文件是否存在                [ -e $file ] is true.

#函数
function_name () {
   list of commands
}




command < filename                         把标准输入重定向到filename文件中
command 0< filename                       把标准输入重定向到filename文件中

command > filename                         把标准输出重定向到filename文件中(覆盖)
command 1> fielname                       把标准输出重定向到filename文件中(覆盖)

command >> filename                       把标准输出重定向到filename文件中(追加)
command 1>> filename                     把标准输出重定向到filename文件中(追加)

command 2> filename                       把标准错误重定向到filename文件中(覆盖)
command 2>> filename                     把标准输出重定向到filename文件中(追加)

command > filename 2>&1               把标准输出和标准错误一起重定向到filename文件中(覆盖)
command >> filename 2>&1             把标准输出和标准错误一起重定向到filename文件中(追加)

command < filename >filename2        把标准输入重定向到filename文件中，把标准输出重定向

                                                        到filename2文件中
command 0< filename 1> filename2   把标准输入重定向到filename文件中，把标准输出重定向

                                                        到filename2文件中


#输出重定向
command>file       重定向到新的文件
command>>file      重定向追加到现有的文件

Here 文档
command << delimiter
document
delimiter
#丢弃输出
command > /dev/null

重定向命令：
--------------------------------------------------------------------
命令            描述
--------------------------------------------------------------------
pgm > file      Output of pgm is redirected to file
pgm < file      Program pgm reads its input from file.
pgm >> file     Output of pgm is appended to file.
n > file        Output from stream with descriptor n redirected to file.
n >> file       Output from stream with descriptor n appended to file.
n >& m          Merge output from stream n with stream m.
n <& m          Merge input from stream n with stream m.
<< tag          Standard input comes from here through next tag at start of line.
|               Takes output from one program, or process, and sends it to another.

#需要注意的是文件描述符
0 是正常标准输入（STDIN），
1 是标准输出（STDOUT），
2 标准错误输出（STDERR）。



控制语句
--------------------------------------------------------------------
命令            描述
--------------------------------------------------------------------
for loop in 1 2 3 4 5
do
    echo "The value is: $loop"
done

while(( $int<=5 ))
do
    echo $int
    let "int++"
done


for var in item1 item2 ... itemN
do
    command1
    command2
    ...
    commandN
done


case 值 in
模式1)
    command1
    command2
    ...
    commandN
    ;;
模式2)
    command1
    command2
    ...
    commandN
    ;;
esac


正则表达式
--------------------------------------------------------------------
命令            描述
--------------------------------------------------------------------
*/

typedef const char *Command;
typedef const char *KeyType;


///<以下是bash的保留关键字，不能用作标识符
typedef struct keyword
{
public;
  KeyType if;
  KeyType else;
  KeyType elif;
  KeyType fi;
  KeyType while;
  KeyType for;
  KeyType until;
  KeyType case;
  KeyType esac;
  KeyType break;
  KeyType continue;
  KeyType return;
  KeyType function;
  KeyType select;
};

///这些命令允许你创建的目录和处理文件。
///--------------------------------------------------------------------
///命令        描述
///--------------------------------------------------------------------
class file
{
  int cat;             ///< Display File Contents
  Command cd;          ///< Changes Directory to dirname
  Command chgrp;       ///< change file group
  Command chmod;       ///< Changing Permissions
  Command cp;          ///< Copy source file into destination
  Command file;        ///< Determine file type
  Command find;        ///< Find files
  Command grep;        ///< Search files for regular expressions.
  Command head;        ///< Display first few lines of a file
  Command ln;          ///< Create softlink on oldname
  Command ls;          ///< Display information about file type.
  Command mkdir;       ///< Create a new directory dirname
  Command more;        ///< Display data in paginated form.
  Command mv;          ///< Move (Rename) a oldname to newname.
  Command pwd;         ///< Print current working directory.
  Command rm;          ///< Remove (Delete) filename
  Command rmdir;       ///< Delete an existing directory provided it is empty.
  Command tail;        ///< Prints last few lines in a file.
  Command touch;       ///< Update access and modification time of a file.
};
file cfile;


///可以比较改变文件的内容，并用下面的命令。
///--------------------------------------------------------------------
///命令        描述
///--------------------------------------------------------------------
class text
{
  Command awk;         ///<Pattern scanning and processing language
  Command cmp;         ///<Compare the contents of two files
  Command comm;        ///<Compare sorted data
  Command cut;         ///<Cut out selected fields of each line of a file
  Command diff;        ///<Differential file comparator
  Command expand;      ///<Expand tabs to spaces
  Command join;        ///<Join files on some common field
  Command perl;        ///<Data manipulation language
  Command sed ;        ///<Stream text editor
  Command sort;        ///<Sort file data
  Command split;       ///<Split file into smaller files
  Command tr;          ///<Translate characters
  Command uniq;        ///<Report repeated lines in a file
  Command wc;          ///<Count words, lines, and characters
  Command vi;          ///<Opens vi text editor
  Command vim;         ///<Opens vim text editor
  Command fmt;         ///<Simple text formatter
  Command spell;       ///<Check text for spelling error
  Command ispell;      ///<Check text for spelling error
  Command ispell;      ///<Check text for spelling error
  Command emacs;       ///<GNU project Emacs
  Command edit ;       ///<Line editor
  Command emacs;       ///<GNU project Emacs
};


///压缩文件：
///文件可能被压缩以节省空间。压缩文件，可以创建和检查：
///--------------------------------------------------------------------
///命令     描述
///--------------------------------------------------------------------
class compress
{
  Command compress;     ///< Compress files
  Command gunzip;       ///< Uncompress gzipped files
  Command gzip;         ///< GNU alternative compression method
  Command uncompress;   ///< Uncompress files
  Command unzip;        ///< List, test and extract compressed files in a ZIP archive
  Command zcat;         ///< Cat a compressed file
  Command zcmp;         ///< Compare compressed files
  Command zdiff;        ///< Compare compressed files
  Command zmore;        ///< File perusal filter for crt viewing of compressed text
};

///获取信息：
///各种UNIX手册和文档上线。下面的 Shell 命令给出的信息：
///--------------------------------------------------------------------
///命令     描述
///--------------------------------------------------------------------
class help
{
  Command apropos;    ///< Locate commands by keyword lookup
  Command info;       ///< Displays command information pages online
  Command man;        ///< Displays manual pages online
  Command whatis;     ///< Search the whatis database for complete words.
  Command yelp;       ///< GNOME help viewer
};


///网络通信：
///这些命令是用来发送和接收文件从全球各地远程主机到本地UNIX主机。
///--------------------------------------------------------------------
///命令     描述
///--------------------------------------------------------------------
class transfer
{
  Command ftp;         ///< File transfer program
  Command rcp;         ///< Remote file copy
  Command rlogin;      ///< Remote login to a UNIX host
  Command rsh;         ///< Remote shell
  Command tftp;        ///< Trivial file transfer program
  Command telnet;      ///< Make terminal connection to another host
  Command ssh;         ///< Secure shell terminal or command connection
  Command scp;         ///< Secure shell remote file copy
  Command sftp;        ///< secure shell file transfer program
};



///编程工具：
///下面的编程语言和工具都是基于你已经安装到你的Unix。
///--------------------------------------------------------------------
///命令        描述
///--------------------------------------------------------------------
class program
{
  Command dbx;         ///< Sun debugger
  Command gdb;         ///< GNU debugger
  Command make;        ///< Maintain program groups and compile programs.
  Command nm;          ///< Print program's name list
  Command size;        ///< Print program's sizes
  Command strip;       ///< Remove symbol table and relocation bits
  Command cb;          ///< C program beautifier
  Command cc;          ///< ANSI C compiler for Suns SPARC systems
  Command ctrace;      ///< C program debugger
  Command gcc;         ///< GNU ANSI C Compiler
  Command indent;      ///< Indent and format C program source
  Command bc;          ///< Interactive arithmetic language processor
  Command gcl;         ///< GNU Common Lisp
  Command perl;        ///< General purpose language
  Command php;         ///< Web page embedded language
  Command py;          ///< Python language interpreter
  Command asp;         ///< Web page embedded language
  Command CC;          ///< C++ compiler for Suns SPARC systems
  Command javac;       ///< JAVA compiler
  Command appletvieweir;   ///< JAVA applet viewer
  Command netbeans;    ///< Java integrated development environment on Linux
  Command sqlplus;     ///< Run the Oracle SQL interpreter
  Command sqlldr;      ///< Run the Oracle SQL data loader
  Command mysql;       ///< Run the mysql SQL interpreter
};


///这些命令列出或改变有关系统的信息：
///--------------------------------------------------------------------
///命令        描述
///--------------------------------------------------------------------
class sys
{
  Command chgrp;       ///< Change the group ownership of a file
  Command chown;       ///< Change owner
  Command date;        ///< Print the date
  Command determin;    ///< Automatically find terminal type
  Command du;          ///< Print amount of disk usage
  Command echo;        ///< Echo arguments to the standard options
  Command exit;        ///< Quit the system
  Command groupadd ;   ///< Create a user group
  Command groups;      ///< Show group memberships
  Command iostat;      ///< Report I/O statistics
  Command kill;        ///< Send a signal to a process
  Command last;        ///< Show last logins of users
  Command logout;      ///< log off UNIX
  Command netstat;     ///< Show network status
  Command passwd;      ///< Change your login password
  Command printenv;    ///< Display value of a shell variable
  Command ps ;         ///< Display the status of current processes
  Command reset;       ///< Reset terminal mode
  Command setenv;      ///< Set environment variables
  Command stty ;       ///< Set terminal options
  Command time ;       ///< Time a command
  Command top ;        ///< Display all system processes
  Command tset;        ///< Set terminal mode
  Command tty ;        ///< Print current terminal name
  Command umask;       ///< Show the permissions that are given to view files by default
  Command uname;       ///< Display name of the current system
  Command uptime;      ///< Get the system up time
  Command useradd;     ///< Create a user account
  Command users;       ///< Print names of logged in users
  Command vmstat ;     ///< Report virtual memory statistics
  Command w ;          ///< Show what logged in users are doing
  Command who;         ///< List logged in users
};



/*

Sample

#!/bin/bash

# Author : Zara Ali
# Copyright (c) Tutorialsyiibai.com
# Script follows here:
