////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// 								配置快捷键,环境变量,外部工具路径,显示相关配置
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///										绑定全局的快捷键
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
macro ConfigKey()
{
    var key;


    //"Select All" --> CTRL+A  全选
    key = KeyFromChar("A",TRUE,FALSE,FALSE);
    AssignKeyToCmd(key, "Select All");




	//EntryAutoExpand ---->CTRL+ENTER
    key = KeyFromChar("Enter",TRUE,FALSE,FALSE);
    AssignKeyToCmd(key, "EntryAutoExpand");




    
    
    //run_test----> CTRL+ALT+T
    __register_quick_key(TRUE,FALSE,TRUE,"T","run_test")
    key = KeyFromChar("T",TRUE,FALSE,TRUE);
    AssignKeyToCmd(key, "run_test");

    //run cmd----> CTRL+ALT+R
    //key = KeyFromChar("R",TRUE,FALSE,TRUE);
    //AssignKeyToCmd(key, "extern_open_cmd");


    //EntryConfig----> CTRL+ALT+M
    //key = KeyFromChar("M",TRUE,FALSE,TRUE);
    //AssignKeyToCmd(key, "EntryConfig");

    //EntryExternTools --> CTRL+ALT+O
    //key = KeyFromChar("O",TRUE,FALSE,TRUE);
    //AssignKeyToCmd(key, "EntryExternTools");

    //EntrySmartEdit --> CTRL+ALT+Z
    //key = KeyFromChar("Z",TRUE,FALSE,TRUE);
    //AssignKeyToCmd(key, "EntrySmartEdit");


    //============================================
    //EM_backspace --> CTRL+B
    //key = KeyFromChar("B",TRUE,FALSE,FALSE);
    //AssignKeyToCmd(key, "EM_backspace");
    
    //"Delete Line" --> CTRL+D  快速删除行
    //key = KeyFromChar("D",TRUE,FALSE,FALSE);
    //AssignKeyToCmd(key, "Delete Line");

    //"Cursor Left" --> CTRL+,
//    key = KeyFromChar(",",TRUE,FALSE,FALSE);
//    AssignKeyToCmd(key, "Cursor Left");

    //"Cursor Right" --> CTRL+.
//    key = KeyFromChar(".",TRUE,FALSE,FALSE);
//    AssignKeyToCmd(key, "Cursor Right");
    //============================================

    //常规设置


    //"Lowercase" --> CTRL+SHIFT+L   单词转换为小写
    //key = KeyFromChar("L",TRUE,TRUE,FALSE);
    //AssignKeyToCmd(key, "Lowercase");

    //"Uppercase" -->CTRL+SHIFT+U 单词转换为大写
    //key = KeyFromChar("U",TRUE,TRUE,FALSE);
    //AssignKeyToCmd(key, "Uppercase");

    //"Tabs To Spaces" --> CTRL+SHIFT+T  Tab转空格
    //key = KeyFromChar("T",TRUE,TRUE,FALSE);
    //AssignKeyToCmd(key, "Tabs To Spaces");

    //"selection_comment_uncomment" --> CTRL+Q 代码块注释和取消注释快捷键
    //key = KeyFromChar("Q",TRUE,FALSE,FALSE);
    //AssignKeyToCmd(key, "CommentSelection");

    //"PluginAstyle4Linux" --> CTRL + ALT + L astyle linux风格
    //key = KeyFromChar("L",TRUE,TRUE,FALSE);
    //AssignKeyToCmd(key, "PluginAstyle4Linux");

    //"PluginAstyle4Windows" --> CTRL+ ALT + W astyle windows风格
    //key = KeyFromChar("W",TRUE,TRUE,FALSE);
    //AssignKeyToCmd(key, "PluginAstyle4Windows");
    msg("按键已经绑定了")
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///										配置组织和作者名称
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
macro ConfigSystem()
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
    
    Tips_EN="Please input your name"
    Tips_CN="请输入作者姓名"
    SetRegPrompt2(Tips_EN,Tips_CN,"MYNAME_EN","MYNAME_CN");

    Tips_EN = "Please input company name"
    Tips_CN = "请输入公司的名称";
    SetRegPrompt2(Tips_EN,Tips_CN,"MYCOMPANY_EN","MYCOMPANY_CN");

    ViewConfig();

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///										配置外部工具路径
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

macro ConfigToolPath()
{
    {
        Tips_EN = "Please input Notepad++ installed path.";
        Tips_CN = "请输入 Notepad++ 安装路径.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_NotepadPlus");
    }
    {
        Tips_EN = "Please input Python installed path.";
        Tips_CN = "请输入 Python 安装路径.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_Python");
    }
    ViewConfig();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///										配置Trace语句
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
macro ConfigureTrace()
{
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



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///										显示配置的环境变量
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
macro ViewConfig()
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


    path = GetReg("EXTERN_NotepadPlus");
    InsBufLine(hnewbuf, ln++, "* EXTERN_NotepadPlus*********************@path@")

    path = GetReg("EXTERN_Python");
    InsBufLine(hnewbuf, ln++, "* EXTERN_Python**************************@path@")

    InsBufLine(hnewbuf, ln++, "")
    InsBufLine(hnewbuf, ln++, " ******************************end of file***********************************/")
}
