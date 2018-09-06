
/**********************************************************************************
**SI 通用帮助信息：快捷键映射
**********************************************************************************/

//显示ASCII 表格
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

//Notepad++ 帮助信息
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

//SI 帮助信息
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

//SI 帮助信息
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

//BASH 帮助信息
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

//C/C++ 帮助信息
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
//Doxygen 帮助信息
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



//LUA 帮助信息
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

//Python 帮助信息
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
