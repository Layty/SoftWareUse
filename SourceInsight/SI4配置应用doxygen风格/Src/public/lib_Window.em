/******************************************************************************************
    针对窗口,按键的操作
******************************************************************************************/

///
///	@brief 绑定快捷键
///
macro __register_quick_key(bCtrl,bShift,bAlt,sChar,sFunc,sDes)
{
    var key;

    key = KeyFromChar(sChar,bCtrl,bShift,bAlt);
    AssignKeyToCmd(key, sFunc);

}

///
/// @brief 关闭所有未修改的窗口
///
macro WindowsCloseAlll()
{
	hwnd = GetCurrentWnd()
	while (hwnd != 0)
	{
	hwndNext = GetNextWnd(hwnd)
	
	hbuf = GetWndBuf(hwnd)
	if (!IsBufDirty(hbuf))
		CloseBuf(hbuf)
	
	hwnd = hwndNext
	}
}


///
/// @brief 关闭除当前窗口外的其他窗口
///
macro WindowsCloseOthers()
{
	hCur = GetCurrentWnd();
	hNext = GetNextWnd(hCur);
	while (hNext != 0 && hCur != hNext)
	{
		hT = GetNextWnd(hNext);
		hbuf = GetWndBuf(hNext);
		if (!IsBufDirty(hbuf))
			CloseBuf(hbuf)
		hNext = hT;
	}
}
