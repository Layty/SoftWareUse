#ifndef __BASH_HELP_H__
#define __BASH_HELP_H__

/*
#0-����淶
#1-���԰�����Ϣ
#2-�ؼ���������ʾ
#3-�⺯��������ʾ
#4-�⺯��˵��
#5-�ؼ�����ɫ
*/

/******************************************************************************************
 2.0  ���ͺ�ֵ
******************************************************************************************/
/*
--------------------------------------------------------------------
#����     ����                 ����
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
#����        ����                       ����
--------------------------------------------------------------------
array_var[index]= value        (index = 0 ..)
array_name=(value_1 .. value_n)
${array_name[*]}                ��������Ԫ��
${array_name[@]}                ��������Ԫ��

���������(�������a=10,����b=20)
--------------------------------------------------------------------
#�����      ����                       ����
--------------------------------------------------------------------
+            �ӷ�                       `expr $a + $b` will give 30
-            ����                       `expr $a - $b` will give -10
*            �˷�                       `expr $a * $b` will give 200
/            ����                       `expr $b / $a` will give 2
%            ģ(ȡ��)                    `expr $b % $a` will give 0
=            ��ֵ                        a=$b would assign value of b into a
==           ����                        [ $a == $b ] would return false.
!=           ������                      [ $a != $b ] would return true.


#��ϵ�����(�������a=10,����b=20)
--------------------------------------------------------------------
�����       ����                        ʾ��
--------------------------------------------------------------------
-eq          �Ƚ������������            [ $a -eq $b ] is not true.
-ne          �Ƚ��������������          [ $a -ne $b ] is true.
-gt          ����                        [ $a -gt $b ] is not true.
-lt          С��                        [ $a -lt $b ] is true.
-ge          ���ڵ���                    [ $a -ge $b ] is not true.
-le          С�ڵ���                    [ $a -le $b ] is true.

#���������
--------------------------------------------------------------------
�����       ����                       ʾ��
--------------------------------------------------------------------
!            �߼���                      [ ! false ] is true.
-o           �߼���                      [ $a -lt 20 -o $b -gt 100 ] is true.
-a           �߼���                      [ $a -lt 20 -a $b -gt 100 ] is fa


#�ַ��������(�������a="abc" �ͱ���b="efg"
--------------------------------------------------------------------
�����       ����                        ʾ��
--------------------------------------------------------------------
=            �ַ����Ƿ����              [ $a = $b ] is not true.
!=           �ַ����Ƿ����            [ $a != $b ] is true.
-z           �ַ��������Ƿ�Ϊ0           [ -z $a ] is not true.
-n           �ַ��������Ƿ��0           [ -z $a ] is not false.
str          �ַ���Ϊ�ǿ�                [ $a ] is not false.


#�ļ����Բ���
--------------------------------------------------------------------
������       ����                        ʾ��
--------------------------------------------------------------------
-b           �ļ��Ƿ�Ϊ���豸�ļ�        [ -b $file ] is false.
-c           �ļ��Ƿ�Ϊ�ַ��豸�ļ�      [ -b $file ] is false.
-d           �ļ��Ƿ�ΪĿ¼              [ -d $file ] is not true.
-f           �ļ��Ƿ�Ϊһ����ͨ�ļ�      [ -f $file ] is true.
-g           �ļ��Ƿ�����SGID��־        [ -g $file ] is false.
-k           �ļ��Ƿ�����sticky��־      [ -k $file ] is false.
-p           �ļ��Ƿ�Ϊ�����ܵ��ļ�      [ -p $file ] is false.
-t           �ļ��Ƿ��Ƿ���ն˹���      [ -t $file ] is false.
-u           �ļ��Ƿ�����SUID��־        [ -u $file ] is false.
-r           �ļ��Ƿ�ɶ�                [ -r $file ] is true.
-w           �ļ��Ƿ��д                [ -w $file ] is true.
-x           �ļ��Ƿ��ִ��              [ -x $file ] is true.
-s           �ļ�size�Ƿ����0           [ -s $file ] is true.
-e           �ļ��Ƿ����                [ -e $file ] is true.

#����
function_name () {
   list of commands
}




command < filename                         �ѱ�׼�����ض���filename�ļ���
command 0< filename                       �ѱ�׼�����ض���filename�ļ���

command > filename                         �ѱ�׼����ض���filename�ļ���(����)
command 1> fielname                       �ѱ�׼����ض���filename�ļ���(����)

command >> filename                       �ѱ�׼����ض���filename�ļ���(׷��)
command 1>> filename                     �ѱ�׼����ض���filename�ļ���(׷��)

command 2> filename                       �ѱ�׼�����ض���filename�ļ���(����)
command 2>> filename                     �ѱ�׼����ض���filename�ļ���(׷��)

command > filename 2>&1               �ѱ�׼����ͱ�׼����һ���ض���filename�ļ���(����)
command >> filename 2>&1             �ѱ�׼����ͱ�׼����һ���ض���filename�ļ���(׷��)

command < filename >filename2        �ѱ�׼�����ض���filename�ļ��У��ѱ�׼����ض���

                                                        ��filename2�ļ���
command 0< filename 1> filename2   �ѱ�׼�����ض���filename�ļ��У��ѱ�׼����ض���

                                                        ��filename2�ļ���


#����ض���
command>file       �ض����µ��ļ�
command>>file      �ض���׷�ӵ����е��ļ�

Here �ĵ�
command << delimiter
document
delimiter
#�������
command > /dev/null

�ض������
--------------------------------------------------------------------
����            ����
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

#��Ҫע������ļ�������
0 ��������׼���루STDIN����
1 �Ǳ�׼�����STDOUT����
2 ��׼���������STDERR����



�������
--------------------------------------------------------------------
����            ����
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


case ֵ in
ģʽ1)
    command1
    command2
    ...
    commandN
    ;;
ģʽ2)
    command1
    command2
    ...
    commandN
    ;;
esac


������ʽ
--------------------------------------------------------------------
����            ����
--------------------------------------------------------------------
*/

typedef const char *Command;
typedef const char *KeyType;


///<������bash�ı����ؼ��֣�����������ʶ��
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

///��Щ���������㴴����Ŀ¼�ʹ����ļ���
///--------------------------------------------------------------------
///����        ����
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


///���ԱȽϸı��ļ������ݣ�������������
///--------------------------------------------------------------------
///����        ����
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


///ѹ���ļ���
///�ļ����ܱ�ѹ���Խ�ʡ�ռ䡣ѹ���ļ������Դ����ͼ�飺
///--------------------------------------------------------------------
///����     ����
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

///��ȡ��Ϣ��
///����UNIX�ֲ���ĵ����ߡ������ Shell �����������Ϣ��
///--------------------------------------------------------------------
///����     ����
///--------------------------------------------------------------------
class help
{
  Command apropos;    ///< Locate commands by keyword lookup
  Command info;       ///< Displays command information pages online
  Command man;        ///< Displays manual pages online
  Command whatis;     ///< Search the whatis database for complete words.
  Command yelp;       ///< GNOME help viewer
};


///����ͨ�ţ�
///��Щ�������������ͺͽ����ļ���ȫ�����Զ������������UNIX������
///--------------------------------------------------------------------
///����     ����
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



///��̹��ߣ�
///����ı�����Ժ͹��߶��ǻ������Ѿ���װ�����Unix��
///--------------------------------------------------------------------
///����        ����
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


///��Щ�����г���ı��й�ϵͳ����Ϣ��
///--------------------------------------------------------------------
///����        ����
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
