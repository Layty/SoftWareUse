#!/usr/bin/python
# -*- coding: utf-8 -*-


import ctypes
import struct
import os
import _winreg

"""
Windows 开发环境
电脑重新安装后，许多开发环境需要重新设置，每次都要网上搜索，
这里将工具的配置环境都记录下来
下次重要安装后，一键配置
原理：

# 调用python 的_winreg 模块，设置临时或者永久的PATH 环境变量
# 系统环境变量
# HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Session Manager\Environment
# User 环境变量
# HKEY_CURRENT_USER\Environment
# D:\platform\node-v6.11.3-win-x86\;D:\platform\Python27\DLLs;D:\platform\Python27\Scripts;D:\platform\Python27\;D:\platfo
# rm\jdk1.8.0_60\lib;D:\platform\jdk1.8.0_60\bin;D:\platform\mingw32\libexec\gcc\i686-w64-mingw32\4.8.2;D:\platform\mingw3
# 2\bin;D:\platform\dmd\windows\lib;D:\platform\dmd\windows\bin;D:\platform\luapower\;D:\platform\doxygen\bin;D:\platform\
# cmake\bin;D:\Android\AndroidStudio\gradle\gradle-2.10\bin;D:\platform\swigwin-3.0.7\;D:\platform\lua\bin;D:\platform\bas
# e\msys2;D:\platform\base\msys;D:\platform\base\gow;D:\platform\base\;D:\Android\adt-bundle-windows-x86-20140702\eclipse\
# ;D:\Qt\4.8.6\bin;D:\platform\android\sdk\platform-tools;D:\platform\android\ndk;D:\platform\android\sdk;C:\Program Files
# \TortoiseSVN\bin;C:\Program Files\Git\bin;C:\Program Files\Git\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;
# C:\Windows\System32\WindowsPowerShell\v1.0;C:\Program Files\Microsoft SQL Server\90\Tools\binn;C:\Program Files (x86)\GN
# U\GnuPGpub



"""
# name     工具的名称
# root     工具的安装路径(绝对)
# env_base 安装路径映射到工作目录后，设置的变量，用于其他环境变量引用
# env_ext  其他扩展的环境变量
#          flag      'create' or 'append' (默认为append)
#          env_name   环境变量名称，可以为任意
#          path       相对路径
GlobalConfig = "SYSTEM"

Config = [
    dict(
        name="git",
        homepage=ur"https://tortoisegit.org/",
        description=ur"TortoiseGit 是 Git Windows 客户端",
        root=ur'C:\Program Files\Git',
        env_list=[
            dict(operate="append", env_name="PATH", env_value="bin")
        ]
    ),
    dict(
        name='svn',
        homepage=ur"https://tortoisesvn.net/",
        description=ur"TortoiseSVN 是 SVN Windows 客户端",
        root=ur'C:\\Program Files\\TortoiseSVN',
        env_list=[
            dict(operate='append', env_name="PATH", env_value='bin'),
        ]
    ),
    dict(
        name='eclipse',
        homepage=ur"www.baidu.com",
        description=ur"www.baidu.com",
        root=ur'D:\Android\adt-bundle-windows-x86-20140702\eclipse',
        env_ext=[
            dict(flag='append', env_name="PATH", env_value=''),
        ]
    ),
    dict(
        name='android',
        homepage="www.baidu.com",
        description="Android sdk and nkd directory  adb tools etc",
        root=ur"D:\platform\android",
        env_list=
        [
            dict(operate="append", env_name="PATH", env_value="sdk"),
            dict(operate='append', env_name="PATH", env_value="ndk"),
            dict(operate='append', env_name="PATH", env_value=ur"sdk\platform-tools"),
        ]
    ),
    dict(
        name='qt',
        homepage="www.baidu.com",
        description="www.baidu.com",
        root=ur'D:\Qt',
        env_base="QTDIR",
        env_ext=
        [
            dict(flag='create', env_name="QTDIR", env_value=''),
            dict(flag='append', env_name="PATH", env_value=ur'4.8.6\bin'),
            dict(flag='create', env_name="QMAKESPEC", env_value=ur'4.8.6\mkspecs\win32-g++')
        ]
    ),

    dict(
        name='base',  # ----include lua premake4 etc
        homepage=ur"www.baidu.com",
        description=ur"www.baidu.com",
        root=ur'D:\platform\base',
        env_base="BASE_HOME",
        env_ext=
        [
            dict(flag='append', env_name="PATH", env_value=''),
            dict(flag='append', env_name="PATH", env_value='gow'),
            dict(flag='append', env_name="PATH", env_value='msys'),
            dict(flag='append', env_name="PATH", env_value='msys2')
        ]
    ),
    dict(
        name='lua',
        homepage=ur"www.baidu.com",
        description=ur"www.baidu.com",
        root=ur'D:\platform\lua',
        env_base="LUA_HOME",
        env_ext=
        [
            dict(flag='append', env_name="PATH", env_value='bin'),
            dict(flag='append', env_name="LIBRARY_PATH", env_value='lib'),
            dict(flag='append', env_name="C_INCLUDE_PATH", env_value='include')
        ]
    ),

    dict(
        name='swig',
        homepage=ur"www.baidu.com",
        description=ur"www.baidu.com",
        root=ur'D:\platform\swigwin-3.0.7',
        env_ext=
        [
            dict(flag='append', env_name="PATH", env_value=''),
        ]
    ),
    dict(
        name='gradle',
        homepage=ur"www.baidu.com",
        description=ur"www.baidu.com",
        root=ur'D:\Android\AndroidStudio\gradle\gradle-2.10',
        env_ext=
        [
            dict(flag='append', env_name="PATH", env_value='bin'),
        ]
    ),

    dict(
        name='cmake',
        homepage=ur"www.baidu.com",
        description=ur"www.baidu.com",
        root=ur'D:\platform\cmake',
        env_ext=
        [
            dict(flag='append', env_name="PATH", env_value='bin'),
        ]
    ),

    dict(
        name='doxy',
        homepage=ur"www.baidu.com",
        description=ur"www.baidu.com",
        root=ur'D:\platform\doxygen',
        env_ext=
        [
            dict(flag='append', env_name="PATH", env_value='bin'),
        ]
    ),
    dict(
        name='luapower',
        homepage=ur"www.baidu.com",
        description=ur"www.baidu.com",
        root=ur'D:\platform\luapower',
        env_ext=
        [
            dict(flag='append', env_name="PATH", env_value=''),
        ]
    ),

    dict(
        name='dmd',
        homepage="www.baidu.com",
        description="www.baidu.com",
        root=ur'D:\platform\dmd',
        env_ext=
        [
            dict(flag='append', env_name="PATH", env_value=ur'windows\bin'),
            dict(flag='append', env_name="PATH", env_value=ur'windows\lib'),
        ]
    ),

    dict(
        name='mingw32',
        homepage="www.baidu.com",
        description="www.baidu.com",
        root=ur'D:\platform\mingw32',
        env_ext=
        [
            dict(flag='append', env_name="PATH", env_value='bin'),
            dict(flag='append', env_name="PATH", env_value=ur'libexec\gcc\i686-w64-mingw32\4.8.2'),
            dict(flag='append', env_name="LIBRARY_PATH", env_value='lib'),
            dict(flag='append', env_name="LIBRARY_PATH", env_value=ur'lib\gcc\i686-w64-mingw32\4.8.2'),
            dict(flag='append', env_name="C_INCLUDE_PATH", env_value='include'),
            dict(flag='append', env_name="C_INCLUDE_PATH", env_value=ur'lib\gcc\i686-w64-mingw32\4.8.2\\include'),
            dict(flag='append', env_name="CPLUS_INCLUDE_PATH", env_value=ur'i686-w64-mingw32\include'),
            dict(flag='append', env_name="CPLUS_INCLUDE_PATH", env_value=ur'i686-w64-mingw32\include\c++'),
            dict(flag='append', env_name="CPLUS_INCLUDE_PATH", env_value=ur'i686-w64-mingw32\include\c++\backward'),

        ]
    ),

    dict(
        name='java',
        homepage="www.baidu.com",
        description="www.baidu.com",
        root=ur'D:\platform\jdk1.8.0_60',
        env_base="JAVA_HOME",
        env_ext=
        [
            dict(flag='append', env_name="PATH", env_value='bin'),
            dict(flag='append', env_name="PATH", env_value='lib'),
            dict(flag='append', env_name="C_INCLUDE_PATH", env_value='include'),
            dict(flag='append', env_name="C_INCLUDE_PATH", env_value=ur'include\win32'),
            dict(flag='append', env_name="CPLUS_INCLUDE_PATH", env_value='include'),
            dict(flag='append', env_name="CPLUS_INCLUDE_PATH", env_value=ur'include\win32'),
        ]
    ),

    dict(
        name='python',
        homepage=ur"www.baidu.com",
        description=ur"www.baidu.com",
        root=ur'D:\platform\Python27',
        env_base='PYTHONPATH',
        env_ext=
        [
            dict(flag='default', env_name="PATH", env_value=''),
            dict(flag='default', env_name="PATH", env_value='Scripts'),
            dict(flag='default', env_name="PATH", env_value='DLLs'),
            # dict(flag='default',env_name = "PATH",env_value ='Lib\\site-packages\\PyQt4'),
            dict(flag='append', env_name="C_INCLUDE_PATH", env_value='include'),
            dict(flag='append', env_name="CPLUS_INCLUDE_PATH", env_value='include'),
            dict(flag='default', env_name="LIBRARY_PATH", env_value='libs'),
            dict(flag='default', env_name="LD_LIBRARY_PATH", env_value='libs'),

        ]
    ),
    dict(
        name='npm',
        homepage=ur"www.baidu.com",
        description=ur"www.baidu.com",
        root=ur'D:\platform\node-v6.11.3-win-x86',
        env_ext=[
            dict(
                flag='default', env_name="PATH", env_value=''),
        ]
    ),

]

def show_one_item():



"""
Main function
"""


if __name__ == '__main__':

