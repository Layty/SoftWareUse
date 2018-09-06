/******************************************************************************************
    测试代码，临时性的想法
******************************************************************************************/

macro RunCustomTest()
{
	var cmd;
	cmd = public_get_cmd_path();
	cmd = "python"
	
	var cmd_line;

	cmd_line = "python D:\\platform\\custom\\Source_Insight4.0\\Projects\\Base\\cache\\test.py";
	

	ret = RunCmdLine(cmd_line, Nil, 0);
	Msg(ret)

}

macro run_test1()
{
    /*
     PutEnv("TRACE_NAME","DebugTrace");
     szEnv = GetEnv("TRACE_NAME");
     cmd = "hello"
     msg = "@cmd@:Please select Preference language: 0 Chinese ,1 English"

     szLanguage = ASK(msg);
     Msg(szLanguage);
    
     //Msg(__common_get_cache_path())


	hbuf = NewBuf("xxxx.h")
	rec = "name=\"Joe Smith\";age=\"34\";experience=\"guru\""

	AppendBufLine(hbuf, rec)
	rec = "name=\"Mary\";age=\"31\";experience=\"intern\""
	AppendBufLine(hbuf, rec)

	rec = GetBufLine(hbuf, 0) // retrieve 0th element
	Msg(rec)
	//CloseBuf(hbuf) */

 	ProgInfo = GetProgramEnvironmentInfo() 

    PrjPath = ProgInfo.ProjectDirectoryFile
    Path = __common_get_parrent_dir(PrjPath)
    ProgInfo = __common_get_parrent_dir(Path)
    Path = "@ProgInfo@\\main.exe"

     hbuf = GetCurrentBuf()
     if(hNil == hbuf)
     {
        stop
     }
     name = GetBufName(hbuf)

	cmdline = "@Path@ @name@"
	msg(cmdline);

     ret = RunCmdLine(cmdline,"@Path@",1)
     Msg("ret=@ret@");
	return;
	var hbuf;
	var sFilePath;
	var sExt;
	var STBPrjPath;
	var bmp;
	var full_path;
	var ln;

	Msg(__common_get_root_path());
	return;
	
	 hbuf = getcurrentbuf();
     if(hNil == hbuf)
     {
        stop;
     }
    sFilePath = GetBufName(hbuf);
    //Msg(sFilePath);

	sExt = tolower(public_get_file_ext(sFilePath));
	if(sExt !="bat")
	{
		//stop;
	}

	//RunCmd("Command");
	
	//nRet = RunCmdLine("c:\\windows\\system32\\cmd.exe /k @sFilePath@",Nil,False);
	//Msg("E:\\Archive\\wiznote\\Data\\suifeng.jxnu@163.com\\1-经验总结\\购买申请VPN帐号.ziw");

	ShellExecute("edit", "d:\\国外出差饮食技巧.md.ziw", "", "", 1);


	

	
	


}

macro open_win32_bitmap()
{
	 hbuf = getcurrentbuf();
     if(hNil == hbuf)
     {
        stop;
     }
     sFilePath = GetBufName(hbuf);

	sExt = tolower(public_get_file_ext(sFilePath));
	if(sExt !="rc")
	{
		//stop;
	}
	

	STBPrjPath = "E:\\0-Project\\Chile_N8776B_Conax\\Chile_N8776B_Conax6_S2"
	bmp = "res\\res_hd\\audioselect\\audioselecton_left_unfoucs.bmp"
	
	full_path = "@STBPrjPath@\\integration\\ui\\cth\\resource\\app\\@bmp@"
	//Msg(full_path);
	ShellExecute("open", full_path, Nil, Nil, 0);
	 

	
	//ln= GetBufLnCur (hbuf);

	//SymbolRecord = GetSymbolLocationFromLn (hbuf, ln);
	//Msg(SymbolRecord.Symbol);
}




