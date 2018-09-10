////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///													总入口
///														配置
///														自动扩展
///														智能编辑
///														生成一个帮助模版
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///
///	LANGUAGE
///	MYNAME_EN
///	MYNAME_CN
///	MYCOMPANY_EN
/// MYCOMPANY_CN
///


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///													配置入口
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
macro EntryConfig()
{
    Tips_CN = "SI设置 M:个人信息 E:工具路径 K:按键绑定";
    Tips_EN = "SI configuration is activated，M:Global Setting D:Trace Setting  E:External Tools Setting";  

    StartMsg(Tips_CN);
    key = GetKey()
    EndMsg();
    ch = CharFromKey(key)
    ch = ToUpper(ch)
    
    if (IsCtrlKeyDown(key)) // 组合Alt 键的情形，暂时预留
    {
    
    }
    else
    {
        if (ch == "M") 		//配置 主要
        {
            ConfigSystem();
        }
        else if (ch == "D")	//配置 Trace 语句
        {
        }
        else if(ch == "E")	//配置外部工具
        {
            ConfigToolPath();
        }
        else if (ch == "V") //查看配置信息
        {
            ViewConfig();//绑定按键
        }
        else if(ch== "K")
        {
            StartMsg("binging key ... please wait");
            ConfigKey();
            EndMsg();
            Msg("Finish global key binding for Source insight!");
        }
    
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///													快速扩展,CTRL+ENTER
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
macro EntryAutoExpand()
{

     hbuf = getcurrentbuf()
     if(hNil == hbuf)
     {
        stop;
     }
    FilePath = GetBufName(hbuf)

    Ext = tolower(public_get_file_ext(FilePath));

    
    if(Ext == "c" || Ext == "h" || Ext == "cpp" || Ext == "hpp" || Ext == "cxx"|| Ext == "hxx")
    {
    	AutoExpand()
    }
    else if(Ext == "java")
    {
    }
    else if(Ext == "py" || Ext == "python")
    {
    }
    else if(Ext == "lua")
    {
    }
    else if(Ext == "sh")
    {
        __auto_expand_bash();
    }
    else if(Ext == "ruby")
    {
        
    }
    else if(Ext == "d")
    {
    }
    else if(Ext == "cmake")
    {
    }
    else if(Ext == "doxy")
    {
    }
    else if(Ext == "gradle")
    {
    }
    else if(Ext == "xml")
    {
    }
    else if(Ext == "json")
    {
    }
    else if(Ext == "sql")
    {
    
    }
    else
    {
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///													文字智能编辑,CTRL+ALT+Z 
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
macro EntrySmartEdit()
{
    Tips_CN = "智能编辑";
    Tips_EN = "SmartEdit";  
    StartMsg(Tips_CN);
    key = GetKey()
    EndMsg();
    ch = CharFromKey(key)
    ch = ToUpper(ch)
    
    if (IsCtrlKeyDown(key))  
    {
    
    }
    else
    {
        if (ch == "D") //删除当前行或者选择的部分
        {
            
        }
        else if(ch == "U")//选择文字转换为大写
        {
           
        }
        else if(ch == "L")//选择文字转换为小写
        {
        
        }
        else if(ch == "P") //获取路径到剪贴板
        {
            CopyFilePath();
        }
    }

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///													调用外部工具,CTRL+ALT+O 
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
macro EntryExternTools()
{
   
    var szName
    var hbuf
    var szPluginPath
    var cmd_line
    var cmd
    var ret 
    hbuf = GetCurrentBuf();
     if(hNil != hbuf)
     {
        szName = GetBufName(hbuf);
     }
     szPluginPath = __common_get_plugin_path()
     //cmd = "python @szPluginPath@\\Python\\LaunchTools.py"
     //cmd="python"
     //__common_get_parrent_dir(szName)
	 //cmd_line = "cmd /k @cmd@ @szName@"     
     //ret = RunCmdLine(cmd_line, Nil, 0);
     msg("暂时还没有做好python脚本")
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///											生成一个简单的项目帮助文档 ,CTRL+ALT+P
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
macro EntryProjectHelp()
{
    var sz_cache_path;
    var sz_path;
    var hbuf;
    var hbuf_current;
    var ln;
    var key;
    var hbuf_info;

    sz_cache_path = __common_get_cache_path(Nil);

    sz_path = "@sz_cache_path@\\tmp.txt"

    hbuf = OpenBuf(sz_path);
    CloseBuf(hbuf);

    hbuf = OpenBuf(sz_path);
    if(hbuf == hNil)
    {
        hbuf = NewBuf(sz_path);
    }
    
    if(hbuf == hNil)
    {
        stop;
    }
    hbuf_current = GetCurrentBuf();

    SetCurrentBuf(hbuf);
    ClearBuf(hbuf);
    //SaveBuf(hbuf);
    ln = 0;
    InsBufLine(hbuf, ln++, "/*---------<1>----------------------(工作环境) project env-------------------------------*/");
    InsBufLine(hbuf, ln++, "/*---------<2>----------------------(项目    ) project repo------------------------------*/");
    InsBufLine(hbuf, ln++, "/*---------<3>----------------------(项目任务) project task------------------------------*/");
    InsBufLine(hbuf, ln++, "/*---------<4>----------------------(项目经验) project tips------------------------------*/");
    SaveBuf(hbuf);

    

    StartMsg("请输入数字选择:1,2,3  ...");
    
    while(True)
    {
        var ch;
        key = GetKey();
        ch = ToLower(CharFromKey(key));
        if(ch == "q")
        {
            break; //quit
        }
        else if(ch  == 1)
        {
            sz_path = __common_get_project_path();
            sz_path = "@sz_path@\\Base\\project\\project_env.h"
            break;
        }
        else if(ch  == 2)
        {
            sz_path = __common_get_project_path();
            sz_path = "@sz_path@\\Base\\project\\project_repo.h"
            break;
        }
        else if(ch  == 3)
        {
            sz_path = __common_get_project_path();
            sz_path = "@sz_path@\\Base\\project\\project_task.h"
            
            break;
        }
        else if(ch  == 4)
        {
            sz_path = __common_get_project_path();
            sz_path = "@sz_path@\\Base\\project\\project_tips.h"
            
            break;
        }
    }
    EndMsg();

    

    if(sz_path != Nil)
    {
        hbuf_info = OpenBuf(sz_path);
        if(hbuf_info == hNil)
        {
            CloseBuf(hbuf);
            stop;
        }
        SetCurrentBuf( hbuf_info);
    }

    CloseBuf(hbuf);
}

