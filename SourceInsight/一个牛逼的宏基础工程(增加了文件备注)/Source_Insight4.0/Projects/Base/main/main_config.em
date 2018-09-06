/**
����SI

**/

/**********************************************************************************
**SI ȫ�ֿ�ݰ�����
**��ע��ķ�ʽ �󶨿�ݣ�ͬʱ���Դ�ӡ���е����õĿ��
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
    
    //"Delete Line" --> CTRL+D  ����ɾ����
    key = KeyFromChar("D",TRUE,FALSE,FALSE);
    AssignKeyToCmd(key, "Delete Line");

    //"Cursor Left" --> CTRL+,
//    key = KeyFromChar(",",TRUE,FALSE,FALSE);
//    AssignKeyToCmd(key, "Cursor Left");

    //"Cursor Right" --> CTRL+.
//    key = KeyFromChar(".",TRUE,FALSE,FALSE);
//    AssignKeyToCmd(key, "Cursor Right");
    //============================================

    //��������
    //"Select All" --> CTRL+A  ȫѡ
    key = KeyFromChar("A",TRUE,FALSE,FALSE);
    AssignKeyToCmd(key, "Select All");

    //"Lowercase" --> CTRL+SHIFT+L   ����ת��ΪСд
    key = KeyFromChar("L",TRUE,TRUE,FALSE);
    AssignKeyToCmd(key, "Lowercase");

    //"Uppercase" -->CTRL+SHIFT+U ����ת��Ϊ��д
    key = KeyFromChar("U",TRUE,TRUE,FALSE);
    AssignKeyToCmd(key, "Uppercase");

    //"Tabs To Spaces" --> CTRL+SHIFT+T  Tabת�ո�
    key = KeyFromChar("T",TRUE,TRUE,FALSE);
    AssignKeyToCmd(key, "Tabs To Spaces");

    //"selection_comment_uncomment" --> CTRL+Q �����ע�ͺ�ȡ��ע�Ϳ�ݼ�
    key = KeyFromChar("Q",TRUE,FALSE,FALSE);
    AssignKeyToCmd(key, "CommentSelection");

    //"PluginAstyle4Linux" --> CTRL + ALT + L astyle linux���
    key = KeyFromChar("L",TRUE,TRUE,FALSE);
    AssignKeyToCmd(key, "PluginAstyle4Linux");

    //"PluginAstyle4Windows" --> CTRL+ ALT + W astyle windows���
    key = KeyFromChar("W",TRUE,TRUE,FALSE);
    AssignKeyToCmd(key, "PluginAstyle4Windows");



}


/*
* ������ѡʹ�õ�����
* ���ù�˾Ӣ������
* ���ù�˾��������
* �����ⲿ����·��
* ����TRACE ���
*
*/
macro ConfigureSystem()
{
    //��������
    szLanguage = ASK("Please input number to select Preference language: 0-English,1-Chinese");
    if(szLanguage == "#")
    {
       SetReg ("LANGUAGE", "0")
    }
    else
    {
       SetReg ("LANGUAGE", szLanguage)
    }

    //������������
    Tips_EN="Please input your name"
    Tips_CN="��������������"
    SetRegPrompt2(Tips_EN,Tips_CN,"MYNAME_EN","MYNAME_CN");


    Tips_EN = "Please input company name"
    Tips_CN = "�����빫˾������";
    SetRegPrompt2(Tips_EN,Tips_CN,"MYCOMPANY_EN","MYCOMPANY_CN");



    ViewConfigure();



}


/*�����ⲿ����
�༭���ߣ�UtraEdit Notepad++  Sublime
�ű����ߣ�Cmake Lua Python  Dmd Base Mingw32
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
     Language = GetReg(LANGUAGE);//���� ��������

    if(type == "U") //for UltraEdit
    {
        Tips_EN = "Please input UltraEdit installed path.";
        Tips_CN = "������UltraEdit ��װ·��.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_UltraEdit");
    }
    else if(type == "N")//for Notepad++
    {
        Tips_EN = "Please input Notepad++ installed path.";
        Tips_CN = "������ Notepad++ ��װ·��.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_NotepadPlus");
    }
    else if(type == "S")//for Sublime
    {
        Tips_EN = "Please input Sublime installed path.";
        Tips_CN = "������ Sublime ��װ·��.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_Sublime");
    }
    else if(type == "C")//for Cmake
    {
        Tips_EN = "Please input Cmake installed path.";
        Tips_CN = "������ Cmake ��װ·��.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_Cmake");
    }
    else if(type == "L")//for Lua
    {
        Tips_EN = "Please input Lua installed path.";
        Tips_CN = "������ UltraEdit ��װ·��.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_Lua");
    }
    else if(type == "P")//for Python
    {
        Tips_EN = "Please input Python installed path.";
        Tips_CN = "������ Python ��װ·��.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_Python");
    }
    else if(type == "D")//for Dmd
    {
        Tips_EN = "Please input Dmd installed path.";
        Tips_CN = "������ Dmd ��װ·��.";
        SetRegPrompt(Tips_CN,Tips_EN,"EXTERN_Dmd");
    }

}

/*
*  �޸Ļ�������
*Tips_EN  Ӣ����ʾ��Ϣ
*Tips_CN  ������ʾ��Ϣ
*RegName_EN  Ӣ����������
*RegName_CN  �����������ƣ�����ΪNil�����ֻ��һ����������
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
            Prompt_Tips_CN = "@RegName_EN@ = @value@ (0:���� 1:�޸�)";
        }else
        {
            value = GetReg(RegName_CN);
            Prompt_Tips_CN = "@RegName_CN@ = @value@ (0:���� 1:�޸�)";
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

    //�����޸�
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
* ���õ��������� C/CPP  Java Python  Lua etc...
*/
macro ConfigureTrace()
{
    //�����������ֱ�����Ե�Trace���
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
* �鿴������Ϣ �������� �������� ��˾���Ƶ�
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
