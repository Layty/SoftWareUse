/**********************************************************************************
**SI 帮助信息
**********************************************************************************/


/**********************************************************************************
**SI 首选配置信息
**********************************************************************************/
macro preference()
{
    var ln
    hnewbuf = newbuf("Source Insight preference.h")

    if(hnewbuf == hNil)
    {
        Msg("Create a new buf failure!")
        stop
    }
   SetCurrentBuf(hnewbuf)
    ln = 0

	InsBufLine(hnewbuf, ln++, " *****************************************************************************")

	InsBufLine(hnewbuf, ln++, " ***********************Source Insight 最佳配置参考 *****************************")


	InsBufLine(hnewbuf, ln++, " 字体 新宋体 常规 大小12")

	//标准头的生成
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " 背景颜色RGB 210 220 230 背景颜色RGB 192 192 192")

	InsBufLine(hnewbuf, ln++, " 前景色 自动")
	InsBufLine(hnewbuf, ln++, " 其他推荐的字体 Curier New  新宋体 10")

	InsBufLine(hnewbuf, ln++, " *****************************************************************************")


	InsBufLine(hnewbuf, ln++, "")
	InsBufLine(hnewbuf, ln++, " ******************************end of file***********************************/")
}


macro common_key_map_info()
{
    var ln
    hnewbuf = newbuf("Source Insight keyMap.h")

    if(hnewbuf == hNil)
    {
        Msg("Create a new buf failure!")
        stop
    }
    SetCurrentBuf(hnewbuf)
    ln = 0

	InsBufLine(hnewbuf, ln++, " *****************************************************************************")

	InsBufLine(hnewbuf, ln++, " ***********************Source Insight Key Usage *****************************")

	InsBufLine(hnewbuf, ln++, " **************************SI常用的快捷键速查*********************************")

	InsBufLine(hnewbuf, ln++, " CTRL + D ------------------快速删除行")
	InsBufLine(hnewbuf, ln++, " CTRL + ' ------------------智能重命名")
	InsBufLine(hnewbuf, ln++, " CTRL + = ------------------调转到声明")

	InsBufLine(hnewbuf, ln++, " CTRL + G 或 F5  ------------------调整到指定行")

	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " SHIFT+ F8       ------------------高亮显示指定的标识符")

	InsBufLine(hnewbuf, ln++, " CTRL + 鼠标左键 ------------------跳转到声明")
	InsBufLine(hnewbuf, ln++, " CTRL + F        ------------------查找")
	InsBufLine(hnewbuf, ln++, " CTRL + SHIFT+ F ------------------全局查找")
	InsBufLine(hnewbuf, ln++, " CTRL + H        ------------------替换")
	InsBufLine(hnewbuf, ln++, " CTRL + SHIFT +H ------------------全局替换")
	//快速自动扩展使用指南
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " F3 		--------------------------向前查找")

	InsBufLine(hnewbuf, ln++, " F4 		--------------------------向后查找")
	InsBufLine(hnewbuf, ln++, " F7 		--------------------------浏览项目符号")
	InsBufLine(hnewbuf, ln++, " F8 		--------------------------浏览局部符号")
	InsBufLine(hnewbuf, ln++, " CTRL + M	----------------------创建书签")
	InsBufLine(hnewbuf, ln++, " ALT  + F8	----------------------符号窗显示/隐藏 或者ALT + S")
	InsBufLine(hnewbuf, ln++, " ALT  + F12	----------------------字符宽度一致(出现字符宽度不同时使用)")
	InsBufLine(hnewbuf, ln++, " ALT  + T	----------------------下文 ")
	InsBufLine(hnewbuf, ln++, " ALT  + E	----------------------上下文 ")


	InsBufLine(hnewbuf, ln++, " *****************************************************************************")


	InsBufLine(hnewbuf, ln++, "")
	InsBufLine(hnewbuf, ln++, " ******************************end of file***********************************/")


}


macro quick_key_map_info()
{
    var ln;
    hnewbuf = newbuf("Source Insight Help.h");

    if(hnewbuf == hNil)
    {
        Msg("Create a new buf failure!");
        stop;
    }
    setcurrentbuf(hnewbuf);
    ln = 0;

		
	InsBufLine(hnewbuf, ln++, "/*****************************************************************************");

	InsBufLine(hnewbuf, ln++, " ***********************Source Insight Macro Usage ***************************");
	//配置Source Insight 宏
	InsBufLine(hnewbuf, ln++, " * 以下几个宏支持自动生成块语句及插入标准头:");
	InsBufLine(hnewbuf, ln++, " * 假定你已经重载了AutoExpand 宏的快捷键为 CRTL+ENTER ");
	InsBufLine(hnewbuf, ln++, " * Usage: Keyword + [CRTL+ENTER] ");
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " ****************************配置宏(自动扩展)*********************************");

	InsBufLine(hnewbuf, ln++, " * config ----------------------------------------配置语言和作者名称及公司名称");

	//标准头的生成
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " ***********************标准头自动生成(自动扩展)******************************")

	InsBufLine(hnewbuf, ln++, " * file ------------------------------------------------自动生成标准文件头信息")
	InsBufLine(hnewbuf, ln++, " * func ------------------------------------------------自动生成标准函数头信息")
	InsBufLine(hnewbuf, ln++, " * hi ----------------------------------------------------添加一条修改历史记录")
	InsBufLine(hnewbuf, ln++, " * hd ------------------------------------------------------自动生成函数头文件")
	InsBufLine(hnewbuf, ln++, " * hdn -----------------------------------------------------自动生成函数头文件")
	//快速自动扩展使用指南
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " *************************语句块自动生成(自动扩展)****************************")

	InsBufLine(hnewbuf, ln++, " * {}-----------------------------------------------------------自动括号语句块")
	InsBufLine(hnewbuf, ln++, " * while---------------------------------------------------自动完成while语句块")
	InsBufLine(hnewbuf, ln++, " * if---------------------------------------------------------自动完成if语句块")
	InsBufLine(hnewbuf, ln++, " * for-------------------------------------------------------自动完成for语句块")
	InsBufLine(hnewbuf, ln++, " * do while---------------------------------------------自动完成do while语句块")
	InsBufLine(hnewbuf, ln++, " * switch-------------------------------------------------自动完成switch语句块")
	InsBufLine(hnewbuf, ln++, " * case-----------------------------------------------------自动完成case语句块")
	InsBufLine(hnewbuf, ln++, " * struct-------------------------------------------------自动完成struct语句块")
	InsBufLine(hnewbuf, ln++, " * enum-----------------------------------------------------自动完成enum语句块")
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " *************************添加修改注释(自动扩展)******************************")

	InsBufLine(hnewbuf, ln++, " * #ifd---------------------------------------------------自动完成#ifdef语句块")
	InsBufLine(hnewbuf, ln++, " * #ifn--------------------------------------------------自动完成#ifndef语句块")
	InsBufLine(hnewbuf, ln++, " * #if-------------------------------------------------------自动完成#if语句块")
	InsBufLine(hnewbuf, ln++, " * cpp----------------------------------------------自动完成extern \"C\"语句块")
	InsBufLine(hnewbuf, ln++, " * ap---------------------------------------------------------添加一个问题单号")
	InsBufLine(hnewbuf, ln++, " * ab-----------------------------------------------------------添加--注释开始")
	InsBufLine(hnewbuf, ln++, " * ae-----------------------------------------------------------添加--注释结束")
	InsBufLine(hnewbuf, ln++, " * db------------------------------------------------------------删除-注释开始")
	InsBufLine(hnewbuf, ln++, " * de------------------------------------------------------------删除-注释结束")
	InsBufLine(hnewbuf, ln++, " * mb------------------------------------------------------------修改-注释开始")
	InsBufLine(hnewbuf, ln++, " * me------------------------------------------------------------修改-注释结束")
	InsBufLine(hnewbuf, ln++, " * abg--------------------------------------------------插入添加开始和结束说明")
	InsBufLine(hnewbuf, ln++, " * dbg--------------------------------------------------插入删除开始和结束说明")
	//头文件 相关宏
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " ************************语句块自动生成(菜单或快捷键)*************************")

	InsBufLine(hnewbuf, ln++, " * ComentCPPtoC----------------------------------将选中区域内//注释改为C++风格")
	InsBufLine(hnewbuf, ln++, " * ReplaceBufTab-------------------------------------将当前文件的TAB替换为空格")
	InsBufLine(hnewbuf, ln++, " * ReplaceTabInProj----------------------------------将当前项目的TAB替换为空格")
	InsBufLine(hnewbuf, ln++, " * InsertFuncName --------------------------------------插入当前所在的函数名称")
	InsBufLine(hnewbuf, ln++, " * FormatLine-----------------------------------------------自动分行格式化文字")
	InsBufLine(hnewbuf, ln++, " * UpdateFunctionList---------------------------------------自动生成函数头信息")
	InsBufLine(hnewbuf, ln++, " * DelCompoundStatement-------------------------------------符合语句块整个删除")
	InsBufLine(hnewbuf, ln++, " * FunctionHeaderCreate ------------------------------------------函数头的创建")
	InsBufLine(hnewbuf, ln++, " * HeaderFileCreate ------------------------------------插入当前所在的函数名称")

	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " ***********************插入调试块语句(菜单或快捷键)**************************")

	InsBufLine(hnewbuf, ln++, " * InsertTraceInfo--------------------------------------当前函数调插入调试语句")
	InsBufLine(hnewbuf, ln++, " * AutoInsertTraceInfoInBuf-------------------------------当前文件插入调试语句")
	InsBufLine(hnewbuf, ln++, " * AutoInsertTraceInfoInPrj-------------------------------当前工程插入调试语句")
	InsBufLine(hnewbuf, ln++, " * RemoveTraceInfo----------------------------------------删除当前函数调试语句")
	InsBufLine(hnewbuf, ln++, " * RemoveCurBufTraceInfo----------------------------------删除当前文件调试语句")
	InsBufLine(hnewbuf, ln++, " * RemovePrjTraceInfo-------------------------------------删除当前工程调试语句")

	InsBufLine(hnewbuf, ln++, " *****************************************************************************")


	//重载按键使用指南
	InsBufLine(hnewbuf, ln++, " *****************************************************************************")
	InsBufLine(hnewbuf, ln++, "")
	InsBufLine(hnewbuf, ln++, " * 以下几个宏重载对应的键用来部分支持汉字:")
	InsBufLine(hnewbuf, ln++, " * 重载关系如下:")
	InsBufLine(hnewbuf, ln++, "")
	InsBufLine(hnewbuf, ln++, " * EM_delete: -------------------------------------------------------- DELETE")
	InsBufLine(hnewbuf, ln++, " * EM_backspace:----------------------------------------------------BACKSPACE")
	InsBufLine(hnewbuf, ln++, " * EM_CursorUp:------------------------------------------------↑（上方向键）")
	InsBufLine(hnewbuf, ln++, " * EM_CursorDown:--------------------------------------------- ↓（下方向键）")
	InsBufLine(hnewbuf, ln++, " * EM_CursorLeft:--------------------------------------------- ←（左方向键）")
	InsBufLine(hnewbuf, ln++, " * EM_CursorRight:-------------------------------------------- →（右方向键）")
	InsBufLine(hnewbuf, ln++, " * EM_SelectWordLeft:----------------------------------------------Shift + ←")
	InsBufLine(hnewbuf, ln++, " * EM_SelectWordRight:---------------------------------------------Shift + →")
	InsBufLine(hnewbuf, ln++, " * EM_SelectLineUp: -----------------------------------------------Shift + ↑")
	InsBufLine(hnewbuf, ln++, " * EM_SelectLineUp: ---------------------------------------------- Shift + ↓")


	InsBufLine(hnewbuf, ln++, " *****************************************************************************")


	InsBufLine(hnewbuf, ln++, "")
	InsBufLine(hnewbuf, ln++, " ******************************end of file***********************************/")


}

