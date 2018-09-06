
/**********************************************************************************
**SI ͨ�ð�����Ϣ����ݼ�ӳ��
**********************************************************************************/

//��ʾASCII ���
macro HelpShowAsciiTable()
{
    var path;
    var hFile;

	path = __common_get_help_path("ascii_table.h");
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}

//Notepad++ ������Ϣ
macro HelpShowNotepadInfo()
{
    var path;
    var hFile;

	path = __common_get_help_path("notepad_plus_help.h");
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}

//SI ������Ϣ
macro HelpShowSIInfo()
{
    var path;
    var hFile;

	path = __common_get_help_path("si_help.h");
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}

//SI ������Ϣ
macro HelpShowSIFun()
{
    var path;
    var hFile;

	path = __common_get_help_path("si_auto_complete.h");
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}

//BASH ������Ϣ
macro HelpShowBashInfo()
{
    var path;
    var hFile;

	path = __common_get_help_path("bash_help.h");
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}

//C/C++ ������Ϣ
macro HelpShowISOCInfo()
{
    var path;
    var hFile;

	path = __common_get_help_path("iso_c89_help.h");
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}
//Doxygen ������Ϣ
macro HelpShowDoxyInfo()
{
    var path;
    var hFile;

	path = __common_get_help_path("doxy_help.h");
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}



//LUA ������Ϣ
macro HelpShowLUAInfo()
{
    var path;
    var hFile;

	path = __common_get_help_path("lua_help.h");
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}

//Python ������Ϣ
macro HelpShowPythonInfo()
{
    var path;
    var hFile;

	path = __common_get_help_path("python_help.h");
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}


// My Project Data



// My Porject Env
macro HelpShowProjectEnv()
{
    var path;
    var hFile;
    var sDir;

	sDir = __common_get_help_path(nil);
	path = "@sDir@\\project\\project_env.h";
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}

// My Porject Repo
macro HelpShowProjectRepo()
{
    var path;
    var hFile;
    var sDir;
    
	sDir = __common_get_help_path(nil);
	path = "@sDir@\\project\\project_repo.h";
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}

// My Porject Task
macro HelpShowProjectTask()
{
    var path;
    var hFile;
    var sDir;
    
	sDir = __common_get_help_path(nil);
	path = "@sDir@\\project\\project_task.h";
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}




// My Porject Tips
macro HelpShowProjectTips()
{
    var path;
    var hFile;
    var sDir;
	sDir = __common_get_help_path(nil);
	path = "@sDir@\\project\\project_tips.h";
	hFile = OpenBuf(path);


    if(hFile == hNil)
    {
    	stop;
    }

   	SetCurrentBuf(hFile);
}
