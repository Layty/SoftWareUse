
/*
* 字符串 是否包含空格
*/
macro IsContainSpace(path)
{
     len = strlen(path);
	 
     if(len == 0)
     {
        return False;
     }
     i = len -1;
     while(i>=0)
     {

    	if(path[i] ==32)
    	{
    	   return TRUE;
    	}
        i = i-1;
     }
	 return False;
}

/*
* 拷贝文件路径  style: linux or windows
*/
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



/*
*  重构出的通用接口 获取环境变量并在失败的时候提示用户输入
*/
macro PromptRegName(Tips_EN,Tips_CN,EnvName_EN,EnvName_CN)
{
	if(Tips_EN == Nil || Tips_CN == Nil || EnvName_EN == Nil)
	{
		return Nil;
	}
	lang = 1;
	if(lang == 0)
	{
		 szValue = GetReg(EnvName_EN);
		if(strlen( szValue ) == 0)
		{
			szValue = Ask(Tips_EN);
			SetReg(EnvName_EN, szValue);
		}
	}
	else
	{
		szValue = GetReg(EnvName_CN);
		if(strlen( szValue ) == 0)
		{
			szValue = Ask(Tips_CN);
			SetReg(EnvName_CN, szValue);
		}
	}
	
	return "@szValue@";
}


/******************************************************************************************
    获取父目录
******************************************************************************************/
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


/******************************************************************************************
    将window路径转成linux格式
******************************************************************************************/
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

/******************************************************************************************
    获取SI setting ROOT 目录
******************************************************************************************/
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

/******************************************************************************************
    获取SI Setting 目录
******************************************************************************************/
macro __common_get_si_setting_path()
{
	var sDir;

    sDir = __common_get_root_path();
    
    return "@sDir@\\Settings";
}


/******************************************************************************************
    获取当前project 目录
******************************************************************************************/
macro __common_get_project_path()
{
	var sDir;

    sDir = __common_get_root_path();
    
    return "@sDir@\\Projects";
}
/******************************************************************************************
    获取当前cache 目录
******************************************************************************************/
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
/******************************************************************************************
    获取当前 help目录
******************************************************************************************/
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

/******************************************************************************************
    获取当前plugin 目录
******************************************************************************************/
macro __common_get_plugin_path()
{
    var sDir;
    sDir = __common_get_root_path();
    
    return "@sDir@\\Plugins";
}

