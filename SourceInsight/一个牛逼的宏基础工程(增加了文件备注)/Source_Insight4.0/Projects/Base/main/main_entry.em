/**********************************************************************************
**SI ��չ Macro �����
**********************************************************************************/




/**********************************************************************************
**��������� �˺�ӳ���ݼ� CTRL+ALT+.   �״�ʹ�� ���������
**********************************************************************************/
macro EntryConfig()
{
    Tips_CN = "SI���û�Ѽ����������Ӽ�, M:ȫ������ D:Trace ����  E:�ⲿ��������";
    Tips_EN = "SI configuration is activated��please continue press key, M:Global Setting D:Trace Setting  E:External Tools Setting";  

    StartMsg(Tips_CN);
    key = GetKey()
    EndMsg();
    ch = CharFromKey(key)
    ch = ToUpper(ch)

    if (IsCtrlKeyDown(key)) // ���Alt �������Σ���ʱԤ��
    {
    
    }
    else
    {
        if (ch == "M") //���� ��Ҫ
        {
            ConfigureSystem();
        }
        else if (ch == "D") //���� Trace ���
        {
            //ConfigureTrace();
        }
        else if(ch == "E")//�����ⲿ����
        {
            ExternalTools();
        }
        else if (ch == "V") //�鿴������Ϣ
        {
            ViewConfigure();
        }
        else if(ch== "K")
        {
            StartMsg("binging key ... please wait");
            
            __global_key_binding();
            Beep()
            EndMsg();
            Msg("Finish global key binding for Source insight!");

        }
    
    }

}
/**********************************************************************************
**������չ����� �˺�ӳ���ݼ� CTRL+ENTER   
**********************************************************************************/
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
        //ansi c/c++
        smart_expand_c();
    }
    else if(Ext == "java")
    {
         smart_expand_c();
    }
    else if(Ext == "py" || Ext == "python")
    {
         //smart_expand_c();
    }
    else if(Ext == "lua")
    {
        //smart_expand_c();
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
        // smart_expand_c();
    }
    else if(Ext == "cmake")
    {
        //smart_expand_c();
    }
    else if(Ext == "doxy")
    {
        //smart_expand_c();
    }
    else if(Ext == "gradle")
    {
        // smart_expand_c();
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
        //��������չ�����ļ�������makefile Makefile
    }

    
}

/**********************************************************************************
    ���ֱ༭��չ���� �˺�ӳ���ݼ� CTRL+ALT+Z 
**********************************************************************************/
macro EntrySmartEdit()
{
    Tips_CN = "SI����༭�Ѽ�����������, D:  E:";
    Tips_EN = "SI���û�Ѽ�����������, D:  E:";  

    StartMsg(Tips_CN);
    key = GetKey()
    EndMsg();
    ch = CharFromKey(key)
    ch = ToUpper(ch)
    
    if (IsCtrlKeyDown(key)) // 
    {
    
    }
    else
    {
        if (ch == "D") //ɾ����ǰ�л���ѡ��Ĳ���
        {
            
        }
        else if(ch == "U")//ѡ������ת��Ϊ��д
        {
           
        }
        else if(ch == "L")//ѡ������ת��ΪСд
        {
        
        }
        else if(ch == "P") //��ȡ·����������
        {
            CopyFilePath();
        }

    
    }

}

/**********************************************************************************
    �Զ������ʾ �˺�ӳ���ݼ� CTRL+TABLE 
    TODO: ��ʵ��
**********************************************************************************/
macro EntryAutoComplete()
{

}







/**********************************************************************************
**�����ⲿ���ߵ��� �˺�ӳ���ݼ� CTRL+ALT+O 
**********************************************************************************/
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
     cmd = "python @szPluginPath@\\Python\\LaunchTools.py"
     __common_get_parrent_dir(szName)
	 cmd_line = "cmd /k @cmd@ @szName@"     
     ret = RunCmdLine(cmd_line, Nil, 0);   
}

/**********************************************************************************
    ��Ŀ�����ĵ� �˺�ӳ���ݼ� CTRL+ALT+P ��ʾ�˵�
**********************************************************************************/
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
    InsBufLine(hbuf, ln++, "/*---------<1>----------------------(��������) project env-------------------------------*/");
    InsBufLine(hbuf, ln++, "/*---------<2>----------------------(��Ŀ    ) project repo------------------------------*/");
    InsBufLine(hbuf, ln++, "/*---------<3>----------------------(��Ŀ����) project task------------------------------*/");
    InsBufLine(hbuf, ln++, "/*---------<4>----------------------(��Ŀ����) project tips------------------------------*/");
    SaveBuf(hbuf);

    

    StartMsg("����������ѡ��:1,2,3  ...");
    
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

