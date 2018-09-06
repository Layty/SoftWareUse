/******************************************************************************************
    ���ѡ�����Ĳ���
    ѡ���������е�ע�ͺͷ�ע��
    ѡ���������ʽ��
    �ж���
******************************************************************************************/



/******************************************************************************************
    ӳ�䰴��CTRL+Q(��notepad++һ��) ��ݼ����־������
    ע���뷴ע�ͣ���չ������ʶ��ע������
******************************************************************************************/
macro CommentSelection()
{
    var hbuf;
    var hwnd;

    hbuf = GetCurrentBuf();
    if(hbuf== hNil)
    {
        stop;
    }
    hwnd = GetCurrentWnd();
    if(hwnd == hNil)
    {
        stop;
    }
    var sFilePath;
    var sExt;
    //��鵱ǰ��ѡ����ı��Ƿ�Ϊע�ͣ���ʲô����ע��
    sFilePath = GetBufName(hbuf)
	sExt = tolower(public_get_file_ext(sFilePath));

	var sCommentPrefix;

	if( sExt == "c" || sExt == "h" 
		|| sExt == "cpp" || sExt == "hpp" 
		|| sExt == "cxx"|| sExt == "hxx" 
		|| sExt == "java" || sExt == "em"
	  )
	{ 
		sCommentPrefix = "//";
	}
	else if(sExt == "py" || sExt == "python")
	{
		sCommentPrefix = "##"; 
	}
	else if(sExt == "lua")
	{
	 	sCommentPrefix = "--";
	}
	else if(sExt == "sh" ||sExt == "bash")
	{
	 	sCommentPrefix = "##";
	}
	else if(sExt == "ruby")
	{
		sCommentPrefix = "##";	
	}
	else if(sExt == "d")
	{
		sCommentPrefix = "//";
	}
	else if(sExt == "cmake")
	{
	 	sCommentPrefix = "##";
	}
	else if(sExt == "doxy")
	{
	 	sCommentPrefix = "##";
	}
	else if(sExt == "gradle")
	{
		
	}
	else if(sExt == "xml")
	{
	
	}
	else if(sExt == "json")
	{
	
	}
	else if(sExt == "sql")
	{
	
	}
	else
	{
		//��������չ�����ļ�������makefile Makefile

		
	}

	if(StrLen(sCommentPrefix) <=0)
	{
		stop;
	}
	
	if( _is_first_line_comment(hwnd,hbuf,sCommentPrefix))
	{
		_uncomment_with_prefix(hwnd,hbuf,sCommentPrefix);
	}
	else
	{
		_comment_with_prefix(hwnd,hbuf,sCommentPrefix);
	}
	
}


//��ѡ����ı���һ���ж� �����ı�ע�ͻ���ȡ��ע�Ͳ���
macro _is_first_line_comment(hwnd,hbuf,sPrefix)
{
	var nIndex;
	var szTrimLine;
	var szLine;
	var iLine;
	var nCount;

	if(hwnd== hNil || hbuf == hNil)
	{
		stop;
	}
	
	sel = GetWndSel(hwnd);
	
	iLine = sel.lnFirst;
	nCount = StrLen(sPrefix);
	
	szLine = GetBufLine(hbuf, iLine);
	szTrimLine = TrimString(szLine);
	nIndex = 0;
	while(nIndex<nCount)
	{
		if( szTrimLine[nIndex] != sPrefix[nIndex])
		{
			break;
		}
		nIndex = nIndex + 1;
	}
	if(nIndex>=nCount)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

macro _comment_with_prefix(hwnd,hbuf,sPrefix)
{

	sel = GetWndSel(hwnd);

	iLine = sel.lnFirst;
	
	while (iLine <= sel.lnLast)
	{
		szLine = GetBufLine(hbuf, iLine);
		szLine = cat(sPrefix, szLine);
		PutBufLine(hbuf, iLine, szLine);
		iLine = iLine + 1;
	}

	SetWndSel(hwnd, sel);
}


//
// Undo the CommentBlock for the selected text.
//
macro _uncomment_with_prefix(hwnd,hbuf,sPrefix)
{
	var sLeft;
	var sRight;
	sel = GetWndSel(hwnd);

	iLine = sel.lnFirst;

	tabSize = 0;
	var index;
	while (iLine <= sel.lnLast)
	{
		szLine = GetBufLine(hbuf, iLine);
		len = strlen(szLine);
		index = 0;
		while(index <len)
		{
			if(szLine[index] == CharFromAscii(9) || szLine[index] == CharFromAscii(32))
			{
				index = index +1;
			}
			else
			{
				break;
			}
		}
		
		if (len > 1)
		{

			if (szLine[index] == sPrefix[0] && szLine[index+1] == sPrefix[1])
			{
				if(index >0)
				{
					sLeft = strmid(szLine,0,index-1);
				}
				
				sRight = strmid(szLine,index+2,len);
				if(sLeft != nil)
				{
					sNewLine = Cat(sLeft,sRight)
				}
				else
				{
					sNewLine = Cat("",sRight)
				}
	
				
				
				PutBufLine(hbuf, iLine, sNewLine);
			}
		}
		iLine = iLine + 1;
	}

	szLine = GetBufLine(hbuf, sel.lnLast);
	sel.ichLim= sel.ichLim +2;

	SetWndSel(hwnd, sel);
}



/******************************************************************************************
    
******************************************************************************************/

