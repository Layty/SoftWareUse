/**********************************************************************************
**SISetting\Plugin Ŀ¼�µ���չ��� ����
**********************************************************************************/
//PCLint

//SPlint


//CheckStyle


//CppCheck

/**********************************************************************************
**���е����ļ��ű�
**********************************************************************************/
macro run_me()
{
	var hbuf;
	var sFilePath;
	var sExt;
	hbuf = getcurrentbuf()
	if(hNil == hbuf)
	{
		stop;
	}
    sFilePath = GetBufName(hbuf)

	sExt = tolower(public_get_file_ext(sFilePath));


	if(sExt == "c"  || sExt == "cpp" || sExt == "cxx")
	{
		//ansi c/c++

	}
	else if(sExt == "java")
	{

	}
	else if(sExt == "py" || sExt == "python")
	{

	}
	else if(sExt == "lua")
	{

	}
	else if(sExt == "sh")
	{

	}
	else if(sExt == "bat"|| sExt == "cmd")
	{

	}
	else if(sExt == "d")
	{

	}
	else if(sExt == "go")
	{

	}
	else
	{

	}

}

//unix ���astyle
macro PluginAstyle4Linux()
{

    ProgInfo = GetProgramEnvironmentInfo()

    PrjPath = ProgInfo.ProjectDirectoryFile
    Path = __common_get_parrent_dir(PrjPath)
    ProgInfo = __common_get_parrent_dir(Path)
    sParm = "--style=linux --lineend=linux -k3 -W1 -s4 -w -Y -S -N -L -m0 -M60 --suffix=none --convert-tabs"
    Path = "@ProgInfo@\\Plugins\\AStyle\\bin\\AStyle.exe"

     hbuf = GetCurrentBuf()
     if(hNil == hbuf)
     {
        stop
     }
     name = GetBufName(hbuf)
     /*
     if(IsContainSpace(Path) == True)
     {
        Msg("Error:Path Contain space @Path@")
        return
     }
     if(IsContainSpace(name) == True)
     {
        Msg("Error:Path Contain space @name@")
        return
     }
     */


    cmdline = "@Path@ @sParm@ @name@"
    //Msg(cmdline)
    ret = RunCmdLine(cmdline,nil,0)


}
//windows ���astyle
macro PluginAstyle4Windows()
{
    ProgInfo = GetProgramEnvironmentInfo()

    PrjPath = ProgInfo.ProjectDirectoryFile
    Path = __common_get_parrent_dir(PrjPath)
    ProgInfo = __common_get_parrent_dir(Path)
    sParm = "--style=allman --lineend=windows -k3 -W1 -s4 -w -Y -S -N -L -m0 -M60 --suffix=none --convert-tabs"
    Path = "@ProgInfo@\\Plugins\\AStyle\\bin\\AStyle.exe"

     hbuf = GetCurrentBuf()
     if(hNil == hbuf)
     {
        stop
     }
     name = GetBufName(hbuf)

    cmdline = "@Path@ @sParm@ @name@"
    //Msg(cmdline)
     ret = RunCmdLine(cmdline,nil,0)

}


//�Զ�����ļ������ʽ
macro plugin_python_chatdet()
{

}
