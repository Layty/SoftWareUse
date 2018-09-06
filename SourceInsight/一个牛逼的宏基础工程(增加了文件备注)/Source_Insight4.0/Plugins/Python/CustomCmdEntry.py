#!/usr/bin/python
# -*- coding: gbk -*-

# �����ⲿ����

import subprocess
import sys

language = "cn"
Config = [
    {
        "name": "cmd",
        "describe_en": "Open cmd",
        "describe_cn": "��������",
        "cmd": "cmd",
        "args": ""
    },
    {
        "name": "Explorer",
        "describe_en": "Open File Explorer",
        "describe_cn": "���ļ������",
        "cmd": "explorer",
        "args": ""
    },
    {
        "name": "Remote DeskTop",
        "describe_en": "Open Remote DeskTop",
        "describe_cn": "��Զ������",
        "cmd": "mstsc",
        "args": ""
    },
    {
        "name": "Calculator",
        "describe_en": "Open Calculator",
        "describe_cn": "�򿪼�����",
        "cmd": "calc",
        "args": ""
    },

    {
        "name": "IP",
        "describe_en": "View localhost IP",
        "describe_cn": "�鿴����IP",
        "cmd": "ipconfig /all",
        "args": ""
    },
    {
        "name": "paint",
        "describe_en": "Open MsPaint",
        "describe_cn": "������ͼ����",
        "cmd": "mspaint",
        "args": ""
    },
    {
        "name": "notepad++",
        "describe_en": "Open notepad++",
        "describe_cn": "��Notepad++",
        "cmd": "",
        "args": ""
    },
    {
        "name": "vscode",
        "describe_en": "Open VSCode",
        "describe_cn": "��VSCode",
        "cmd": r"D:\developIDE\Microsoft VS Code\Code.exe",
        "args": ""
    },
    {
        "name": "atom",
        "describe_en": "Open Atom",
        "describe_cn": "��Atom",
        "cmd": "",
        "args": ""
    },
    {
        "name": "ultraedit",
        "describe_en": "Open UltraEdit",
        "describe_cn": "�� UltraEdit",
        "cmd": "",
        "args": ""
    },
    {
        "name": "sublime",
        "describe_en": "Open Sublime",
        "describe_cn": "�� Sublime",
        "cmd": "",
        "args": ""
    },
    {
        "name": "SoftPad",
        "describe_en": "Open SoftKeypad",
        "describe_cn": "�������",
        "cmd": "osk",
        "args": ""
    },
    {
        "name": "ZoomTool",
        "describe_en": "Open Zoom Tool",
        "describe_cn": "�򿪷Ŵ���",
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
        prompt = "����������ѡ��:"
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
    print "�����������:"
    choice = show_menu()

    if 0 < choice <= len(Config):
        index = choice - 1
        cmd = Config[index]["cmd"]
        print "Your choice is %d,Starting %s  ..." % (choice, cmd)
        subprocess.Popen(cmd)

    print "finished!"
