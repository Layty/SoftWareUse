/**
配置SI

**/

/**********************************************************************************
**SI 全局快捷按键绑定
**以注册的方式 绑定快捷，同时可以打印所有的配置的快键
**********************************************************************************/
macro __global_key_binding()
{

    var sz_cache_path;
    var sz_path;
    var hbuf;
    var hbuf_current;
    var ln;
    var key;

    sz_cache_path = __common_get_cache_path(Nil);

    sz_path = "@sz_cache_path@\\keybing.txt"


//  hbuf = OpenBuf(sz_path);
//  if(hbuf == hNil)
//  {
//      hbuf = NewBuf(sz_path);
//      if(hbuf == hNil)
//      {
//          stop;
//      }
//  }
//
//  hbuf_current = GetCurrentBuf();

    var key;


    //run_test----> CTRL+ALT+T
    __register_quick_key(TRUE,FALSE,TRUE,"T","run_test")
    key = KeyFromChar("T",TRUE,FALSE,TRUE);
    AssignKeyToCmd(key, "run_test");

    //run cmd----> CTRL+ALT+R
    key = KeyFromChar("R",TRUE,FALSE,TRUE);
    AssignKeyToCmd(key, "extern_open_cmd");


    //EntryConfig----> CTRL+ALT+M
    key = KeyFromChar("M",TRUE,FALSE,TRUE);
    AssignKeyToCmd(key, "EntryConfig");

    //EntryAutoExpand ---->CTRL+ENTER
    key = KeyFromChar("Enter",TRUE,FALSE,FALSE);
    AssignKeyToCmd(key, "EntryAutoExpand");

    //EntryExternTools --> CTRL+ALT+O
    key = KeyFromChar("O",TRUE,FALSE,TRUE);
    AssignKeyToCmd(key, "EntryExternTools");

    //EntrySmartEdit --> CTRL+ALT+Z
    key = KeyFromChar("Z",TRUE,FALSE,TRUE);
    AssignKeyToCmd(key, "EntrySmartEdit");


    //============================================
    //EM_backspace --> CTRL+B
    key = KeyFromChar("B",TRUE,FALSE,FALSE);
    AssignKeyToCmd(key, "EM_backspace");
    
    //"Delete Line" --> CTRL+D  快速删除行
    key = KeyFromChar("D",TRUE,FALSE,FALSE);
    AssignKeyToCmd(key, "Delete Line");

    //"Cursor Left" --> CTRL+,
//    key = KeyFromChar(",",TRUE,FALSE,FALSE);
//    AssignKeyToCmd(key, "Cursor Left");

    //"Cursor Right" --> CTRL+.
//    key = KeyFromChar(".",TRUE,FALSE,FALSE);
//    AssignKeyToCmd(key, "Cursor Right");
    //============================================

    //常规设置
    //"Select All" --> CTRL+A  全选
    key = KeyFromChar("A",TRUE,FALSE,FALSE);
    AssignKeyToCmd(key, "Select All");

    //"Lowercase" --> CTRL+SHIFT+L   单词转换为小写
    key = KeyFromChar("L",TRUE,TRUE,FALSE);
    AssignKeyToCmd(key, "Lowercase");

    //"Uppercase" -->CTRL+SHIFT+U 单词转换为大写
    key = KeyFromChar("U",TRUE,TRUE,FALSE);
    AssignKeyToCmd(key, "Uppercase");

    //"Tabs To Spaces" --> CTRL+SHIFT+T  Tab转空格
    key = KeyFromChar("T",TRUE,TRUE,FALSE);
    AssignKeyToCmd(key, "Tabs To Spaces");

    //"selection_comment_uncomment" --> CTRL+Q 代码块注释和取消注释快捷键
    key = KeyFromChar("Q",TRUE,FALSE,FALSE);
    AssignKeyToCmd(key, "CommentSelection");

    //"PluginAstyle4Linux" --> CTRL + ALT + L astyle linux风格
    key = KeyFromChar("L",TRUE,TRUE,FALSE);
    AssignKeyToCmd(key, "PluginAstyle4Linux");

    //"PluginAstyle4Windows" --> CTRL+ ALT + W astyle windows风格
    key = KeyFromChar("W",TRUE,TRUE,FALSE);
    AssignKeyToCmd(key, "PluginAstyle4Windows");



}


/*
* 配置首选使用的语言
* 配置公司英文名称
* 配置公司中文名称
* 配置外部工具路径
* 配置TRACE 语句
*
*/
macro ConfigureSystem()
{
    //设置语言
    szLanguage = ASK("Please input number to select Preference language: 0-English,1-Chinese");
    if(szLanguage == "#")
    {
       SetReg ("LANGUAGE", "0")
    }
    else
    {
       SetReg ("LANGUAGE", szLanguage)
    }

    //设置作者姓名
    Tips_EN="Please input your name"
    Tips_CN="请输入作者姓名"
    SetRegPrompt2(Tips_EN,Tips_CN,"MYNAME_EN","MYNAME_CN");


    Tips_EN = "Please input company name"
    Tips_CN = "请输入公司的名称";
    SetRegPrompt2(Tips_EN,Tips_CN,"MYCOMPANY_EN","MYCOMPANY_CN");



    ViewConfigure();



}


/*配置外部工具
编辑工具：UtraEdit Notepad++  Sublime
脚本工具：Cmake Lua Python  Dmd Base Mingw32
*/
macro ExternalTools()
{
    index = 0;
    types = "UNSCLPD";
    len = strlen(types);

    while(index <len)
    {
        ConfigExternToolsPath(types[index]);
        index = index + 1;
    }

    ViewConfigure();
}

macro ConfigExternToolsPath(type)
{
     Language = GetReg(LANGUAGE);//加载 优先语言

    if(type == "U") //for UltraEdit
    {
        Tips_EN = "Please input UltraEdit installed path.";
        Tips_CN = "请输入UltraEdit 安装路径.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_UltraEdit");
    }
    else if(type == "N")//for Notepad++
    {
        Tips_EN = "Please input Notepad++ installed path.";
        Tips_CN = "请输入 Notepad++ 安装路径.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_NotepadPlus");
    }
    else if(type == "S")//for Sublime
    {
        Tips_EN = "Please input Sublime installed path.";
        Tips_CN = "请输入 Sublime 安装路径.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_Sublime");
    }
    else if(type == "C")//for Cmake
    {
        Tips_EN = "Please input Cmake installed path.";
        Tips_CN = "请输入 Cmake 安装路径.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_Cmake");
    }
    else if(type == "L")//for Lua
    {
        Tips_EN = "Please input Lua installed path.";
        Tips_CN = "请输入 UltraEdit 安装路径.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_Lua");
    }
    else if(type == "P")//for Python
    {
        Tips_EN = "Please input Python installed path.";
        Tips_CN = "请输入 Python 安装路径.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_Python");
    }
    else if(type == "D")//for Dmd
    {
        Tips_EN = "Please input Dmd installed path.";
        Tips_CN = "请输入 Dmd 安装路径.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_Dmd");
    }

}

/*
*  修改环境变量
*Tips_EN  英文提示信息
*Tips_CN  中文提示信息
*RegName_EN  英文属性名称
*RegName_CN  中文属性名称，可以为Nil，如果只有一个变量名称
*/
macro SetRegPrompt2(Tips_EN,Tips_CN,RegName_EN,RegName_CN)
{
    language = GetReg(LANGUAGE);

    if(RegName_EN == Nil)
    {
        return -1;
    }
    if(Tips_EN == Nil || Tips_CN == Nil)
    {
        Msg("Tips Msg Couldn't be empty.");
        return -1;
    }

    if(language == 0)
    {
        value = GetReg(RegName_EN);
        Prompt_Tips_EN = "@RegName_EN@ = @value@ (0:Keep  1:Modify)";
    }
    else
    {
        if(RegName_CN == Nil)
        {
            value = GetReg(RegName_EN);
            Prompt_Tips_CN = "@RegName_EN@ = @value@ (0:保留 1:修改)";
        }else
        {
            value = GetReg(RegName_CN);
            Prompt_Tips_CN = "@RegName_CN@ = @value@ (0:保留 1:修改)";
        }
    }

    if(language == 0)
    {
        choice = ASK(Prompt_Tips_EN);
    }
    else
    {
        choice = ASK(Prompt_Tips_CN);
    }

    //继续修改
    if(choice == 1)
    {
        if(language == 0)
        {
            value = ASK(Tips_EN);
            SetReg(RegName_EN,value);
        }
        else
        {
            value = ASK(Tips_CN);

            if(RegName_CN == Nil)
            {
                SetReg(RegName_EN,value);
            }
            else{
                SetReg(RegName_CN,value);
            }
        }
    }
}

macro SetRegPrompt(Tips_CN,Tips_EN,RegName_EN)
{
    SetRegPrompt2(Tips_EN,Tips_CN,RegName_EN,Nil)
}


/*
* 配置调试输出语句 C/CPP  Java Python  Lua etc...
*/
macro ConfigureTrace()
{
    //设置配置哪种编程语言的Trace语句
    szLanguage = ASK("Please input number to select program language: 0-C,1-Java,2-Python,3-Lua");
    if(szLanguage == "#" || szLanguage == 0)
    {
        ConfigureTrace_C();
    }else if(szLanguage == 1)
    {
        ConfigureTrace_Java();
    }else if(szLanguage == 2)
    {
        ConfigureTrace_Python();
    }else if(szLanguage == 3)
    {
        ConfigureTrace_Lua();
    }

}



/*
* 查看配置信息 语言设置 作者名称 公司名称等
*/
macro ViewConfigure()
{
    var ln
    hnewbuf = newbuf("SI configuration")

    if(hnewbuf == hNil)
    {
        Msg("Create a new buf failure!")
        stop
    }
    SetCurrentBuf(hnewbuf)
    ln = 0
    InsBufLine(hnewbuf, ln++, "/*****************************************************************************")

    InsBufLine(hnewbuf, ln++, "***********************Source Insight Configuration *************************")

    InsBufLine(hnewbuf, ln++, "*****************************************************************************")
    InsBufLine(hnewbuf, ln++, "")
    language = GetReg("LANGUAGE");
    if(language == 0)
    {
        InsBufLine(hnewbuf, ln++, "* LANGUAGE************************************0:English")
    }
    else
    {
        InsBufLine(hnewbuf, ln++, "* LANGUAGE***********************************1:Chinese")
    }

    name = GetReg("MYNAME_EN");
    InsBufLine(hnewbuf, ln++, "* MYNAME_EN**********************************@name@")
    name = GetReg("MYNAME_CN");
    InsBufLine(hnewbuf, ln++, "* MYNAME_CN**********************************@name@")

    company = GetReg("MYCOMPANY_EN");
    InsBufLine(hnewbuf, ln++, "* MYCOMPANY_EN******************************@company@")
    company = GetReg("MYCOMPANY_CN");
    InsBufLine(hnewbuf, ln++, "* MYCOMPANY_CN******************************@company@")


    path = GetReg("EXTERN_UltraEdit");
    InsBufLine(hnewbuf, ln++, "* EXTERN_UltraEdit***********************@path@")

    path = GetReg("EXTERN_NotepadPlus");
    InsBufLine(hnewbuf, ln++, "* EXTERN_NotepadPlus*********************@path@")

    path = GetReg("EXTERN_Sublime");
    InsBufLine(hnewbuf, ln++, "* EXTERN_Sublime*************************@path@")

    path = GetReg("EXTERN_Cmake");
    InsBufLine(hnewbuf, ln++, "* EXTERN_Cmake***************************@path@")

    path = GetReg("EXTERN_Lua");
    InsBufLine(hnewbuf, ln++, "* EXTERN_Lua*****************************@path@")

    path = GetReg("EXTERN_Python");
    InsBufLine(hnewbuf, ln++, "* EXTERN_Python**************************@path@")

    path = GetReg("EXTERN_Dmd");
    InsBufLine(hnewbuf, ln++, "* EXTERN_Dmd*****************************@path@")

    InsBufLine(hnewbuf, ln++, "")
    InsBufLine(hnewbuf, ln++, " ******************************end of file***********************************/")
}



/**********************************************************************************
** Internal macro function
*@
**********************************************************************************/
macro __register_quick_key(bCtrl,bShift,bAlt,sChar,sFunc,sDes)
{
    var key;

    key = KeyFromChar(sChar,bCtrl,bShift,bAlt);
    AssignKeyToCmd(key, sFunc);

}
