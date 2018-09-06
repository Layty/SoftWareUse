/******************************************************************************************
    公共接口
******************************************************************************************/




macro public_get_file_ext(sz)
{
    i = 1
    j = 0
    szName = sz
    iLen = strlen(sz)
    if(iLen == 0)
      return ""
    while( i <= iLen)
    {
      if(sz[iLen-i] == ".")
      {
         j = iLen-i 
         szExt = strmid(sz,j + 1,iLen)
         return szExt
      }
      i = i + 1
    }
    return ""
}

//读取一个文件内容显示在另外一个文件末尾
macro public_append_from_to(hbufFrom,hbufTo)
{
	var ncount;
	var line;
	var s;
	
	if(hbufFrom == hNil || hbufTo == hNil)
	{
		return False;
	}
	ncount = GetBufLineCount(hbufFrom);
	line = 0;
	while(ncount>0)
	{
		s = GetBufLine(hbufFrom, line++);
		AppendBufLine(hbufTo, s);
		ncount--;
	}
	return True;
}

macro public_get_cmd_path()
{
	var sCmd;
	var ProgInfo;
	ProgEnvInfo = GetProgramEnvironmentInfo();
	sCmd = ProgEnvInfo.ShellCommand;

	return sCmd;
}

//D:\platform\custom\Source_Insight4.0\Projects
macro public_get_project_path()
{
	var sDir;
	var hprj;
	hprj =  GetCurrentProj();
	sDir =  GetProjDir(hprj);

	return sDir;
}