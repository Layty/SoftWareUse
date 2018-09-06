#!/usr/bin/python
# -*- coding: gbk -*-

# 启动外部工具

import subprocess
import sys

language = "cn"
Config = [
    {
        "name": "cmd",
        "describe_en": "Open cmd",
        "describe_cn": "打开命令行",
        "cmd": "cmd",
        "args": ""
    },
    {
        "name": "Explorer",
        "describe_en": "Open File Explorer",
        "describe_cn": "打开文件浏览器",
        "cmd": "explorer",
        "args": ""
    },
    {
        "name": "Remote DeskTop",
        "describe_en": "Open Remote DeskTop",
        "describe_cn": "打开远程桌面",
        "cmd": "mstsc",
        "args": ""
    },
    {
        "name": "Calculator",
        "describe_en": "Open Calculator",
        "describe_cn": "打开计算器",
        "cmd": "calc",
        "args": ""
    },

    {
        "name": "IP",
        "describe_en": "View localhost IP",
        "describe_cn": "查看本机IP",
        "cmd": "ipconfig /all",
        "args": ""
    },
    {
        "name": "paint",
        "describe_en": "Open MsPaint",
        "describe_cn": "启动绘图程序",
        "cmd": "mspaint",
        "args": ""
    },
    {
        "name": "notepad++",
        "describe_en": "Open notepad++",
        "describe_cn": "打开Notepad++",
        "cmd": "",
        "args": ""
    },
    {
        "name": "vscode",
        "describe_en": "Open VSCode",
        "describe_cn": "打开VSCode",
        "cmd": r"D:\developIDE\Microsoft VS Code\Code.exe",
        "args": ""
    },
    {
        "name": "atom",
        "describe_en": "Open Atom",
        "describe_cn": "打开Atom",
        "cmd": "",
        "args": ""
    },
    {
        "name": "ultraedit",
        "describe_en": "Open UltraEdit",
        "describe_cn": "打开 UltraEdit",
        "cmd": "",
        "args": ""
    },
    {
        "name": "sublime",
        "describe_en": "Open Sublime",
        "describe_cn": "打开 Sublime",
        "cmd": "",
        "args": ""
    },
    {
        "name": "SoftPad",
        "describe_en": "Open SoftKeypad",
        "describe_cn": "打开软键盘",
        "cmd": "osk",
        "args": ""
    },
    {
        "name": "ZoomTool",
        "describe_en": "Open Zoom Tool",
        "describe_cn": "打开放大器",
        "cmd": "magnify",
        "args": ""
    },
]


def show_menu():
    i = 1

    for m in Config:
        if language == "cn":
            print "[ %2d ] %s" % (i, m["describe_cn"])
        else:
            print "[ %2d ] %s" % (i, m["describe_en"])
        i += 1
    if language == "cn":
        prompt = "请输入数组选择:"
    else:
        prompt = "Please input your choice:"
    ret = input(prompt)
    return ret


"""
Main function
"""
if __name__ == '__main__':
    i = 0
    for arg in sys.argv:
        print "argv[%d]:%s" % (i, arg)
        i += 1
    print "快捷命令如下:"
    choice = show_menu()

    if 0 < choice <= len(Config):
        index = choice - 1
        cmd = Config[index]["cmd"]
        print "Your choice is %d,Starting %s  ..." % (choice, cmd)
        subprocess.Popen(cmd)

    print "finished!"
