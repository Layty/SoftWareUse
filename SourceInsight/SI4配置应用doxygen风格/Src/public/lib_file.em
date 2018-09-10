///
/// @brief 文件目录操作相关的函数
///



///
/// @brief 拷贝文件名
///
macro CopyFileName()
{
     hbuf = GetCurrentBuf();
     if(hNil == hbuf)
     {
        stop;
     }
    name = GetBufName(hbuf);
	
    Msg(name);
}

///
/// @brief 获取文件后缀名
///
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

///
///读取一个文件内容显示在另外一个文件末尾
///
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




///
/// @brief 拷贝文件路径  style: linux or windows
///
macro CopyFilePath()
{
     hbuf = GetCurrentBuf();
     if(hNil == hbuf)
     {
        stop;
     }
    path = GetBufName(hbuf);
	   Msg(path);
	var ln;
    hnewbuf = newbuf("SI configuration");

    if(hnewbuf == hNil)
    {
        Msg("Create a new buf failure!");
        stop;
    }
    SetCurrentBuf(hnewbuf);
    ln = 0;
	InsBufLine(hnewbuf, ln++, "");
	InsBufLine(hnewbuf, ln++, "@path@");
	path2 = __common_get_linux_style_path(path);
	InsBufLine(hnewbuf, ln++, "@path2@");
	InsBufLine(hnewbuf, ln++, "");

    // Msg(path2)
}


///
/// @brief 获取cmd的路径
///
macro public_get_cmd_path()
{
	var sCmd;
	var ProgInfo;
	ProgEnvInfo = GetProgramEnvironmentInfo();
	sCmd = ProgEnvInfo.ShellCommand;
	return sCmd;
}

///
///	@brief 获得当前工程的路径
///
macro public_get_project_path()
{
	var sDir;
	var hprj;
	hprj =  GetCurrentProj();
	sDir =  GetProjDir(hprj);

	return sDir;
}

///
/// @brief 获取父目录
///
macro __common_get_parrent_dir(path)
{
     len = strlen(path);

     if(len == 0)
     {
        return ""；
     }
     i = len -1
     while(i>=0)
     {
        if(path[i] == "\\")
        {
          return strmid(path,0,i)
        }
        i = i-1
     }
}

///
/// @brief 将window路径转成linux格式
///
macro __common_get_linux_style_path(path)
{
     len = strlen(path)
	 
     if(len == 0)
     {
        return ""
     }
     i = len -1
     while(i>=0)
     {
        if(path[i] == "\\")
        {
			path[i] = "\/"
        }
        i = i-1
     }
	 return path;
}


///
/// @brief SI  ROOT 目录
///
macro __common_get_root_path()
{
	var sPrjPath;
	var sDir;
	var sParent;

	ProgEnvInfo = GetProgramEnvironmentInfo(); 
    sPrjPath = ProgEnvInfo.ProjectDirectoryFile;
    sDir = __common_get_parrent_dir(sPrjPath);
    sParent = __common_get_parrent_dir(sDir);
    
    return sParent;
}


///
/// @brief SI Setting 目录
///
macro __common_get_si_setting_path()
{
	var sDir;

    sDir = __common_get_root_path();
    
    return "@sDir@\\Settings";
}


///
/// @brief 获取当前project 目录
///
macro __common_get_project_path()
{
	var sDir;

    sDir = __common_get_root_path();
    
    return "@sDir@\\Projects";
}


///
/// @brief 获取当前cache 目录
///
macro __common_get_cache_path(szName)
{
    var sDir;
    sDir = __common_get_project_path();

    if(szName !=Nil)
    {
        return "@sDir@\\Base\\cache\\@szName@";
    }
    else
    {
        return "@sDir@\\Base\\cache";
    }
}

///
/// @brief 获取当前 help目录
///
macro __common_get_help_path(szName)
{
    var sDir;
    sDir = __common_get_project_path();

    if(szName !=Nil)
    {
        return "@sDir@\\Base\\help\\@szName@";
    }
    else
    {
        return "@sDir@\\Base\\help";
    }
}


///
/// @brief 获取当前plugin 目录
///
macro __common_get_plugin_path()
{
    var sDir;
    sDir = __common_get_root_path();
    
    return "@sDir@\\Plugins";
}


