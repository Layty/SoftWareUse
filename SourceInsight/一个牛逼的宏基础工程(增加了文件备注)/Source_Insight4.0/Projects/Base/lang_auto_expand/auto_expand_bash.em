//对关键字进行快速扩展

macro __auto_expand_bash()
{
    //配置信息
    // get window, sel, and buffer handles
    hwnd = GetCurrentWnd();
    if (hwnd == 0)
    {
    	stop
    }
    
        
    sel = GetWndSel(hwnd)
    if(sel.lnFirst != sel.lnLast) 
    {
        /*块命令处理*/
        //BlockCommandProc();
    }
    if (sel.ichFirst == 0)
        stop
    hbuf = GetWndBuf(hwnd)
	
    nVer = 0
    nVer = GetVersion()

    // get line the selection (insertion point) is on
    szLine = GetBufLine(hbuf, sel.lnFirst);
    // parse word just to the left of the insertion point
    wordinfo = GetWordLeftOfIch(sel.ichFirst, szLine)
    ln = sel.lnFirst;
    chTab = CharFromAscii(9)
        
    // prepare a new indented blank line to be inserted.
    // keep white space on left and add a tab to indent.
    // this preserves the indentation level.
    chSpace = CharFromAscii(32);
    ich = 0
    while (szLine[ich] == chSpace || szLine[ich] == chTab)
    {
        ich = ich + 1
    }
    szLine1 = strmid(szLine,0,ich)
    szLine = strmid(szLine, 0, ich) # "    "
    
    sel.lnFirst = sel.lnLast
    sel.ichFirst = wordinfo.ich
    sel.ichLim = wordinfo.ich

    /*自动完成简化命令的匹配显示*/
    wordinfo.szWord = RestoreCommand(hbuf,wordinfo.szWord)
    
    sel = GetWndSel(hwnd)
  
   
    __key_word_expand_bash(wordinfo,szLine,szLine1,nVer,ln,sel);
    
}

macro __key_word_expand_bash(wordinfo,szLine,szLine1,nVer,ln,sel)
{
  
    szCmd = wordinfo.szWord
    hwnd = GetCurrentWnd()
    if (hwnd == 0)
    {
        stop;
    }
    hbuf = GetWndBuf(hwnd)
    /*添加注释注释*/
    if (szCmd == "#")
    {   
        if(wordinfo.ichLim > 70)
        {
            Msg("The right margine is small, Please use a new line")
            stop 
        }
        szCurLine = GetBufLine(hbuf, sel.lnFirst);
        szLeft = strmid(szCurLine,0,wordinfo.ichLim)
        lineLen = strlen(szCurLine)
        kk = 0
        while(wordinfo.ichLim + kk < lineLen)
        {
            if((szCurLine[wordinfo.ichLim + kk] != " ")||(szCurLine[wordinfo.ichLim + kk] != "\t")
            {
                msg("you must insert /* at the end of a line");
                return
            }
            kk = kk + 1
        }
        szContent = Ask("Please input comment")
        DelBufLine(hbuf, ln)
        szLeft = cat( szLeft, " ")
        CommentContent(hbuf,ln,szLeft,szContent,1)            
        return
    }
    else if(szCmd == "{")
    {
        InsBufLine(hbuf, ln + 1, "@szLine@")
        InsBufLine(hbuf, ln + 2, "@szLine1@" # "}");
        SetBufIns (hbuf, ln + 1, strlen(szLine))
        return
    }
    else if (szCmd == "if")
    {
        SetBufSelText(hbuf, " [ $a == $b ];then")
        InsBufLine(hbuf, ln + 1, "@szLine@" # "#expr;");
        InsBufLine(hbuf, ln + 2, "@szLine1@" # "fi");
        return;
    }
    else if( szCmd == "else" )
    {
        InsBufLine(hbuf, ln + 1, "@szLine@" # "#expr;");
        InsBufLine(hbuf, ln + 2, "@szLine1@" # "fi");
        return;
    }
    else if (szCmd == "ef")
    {
        PutBufLine(hbuf, ln, szLine1 # "else if [ $a == $b ];then")
        InsBufLine(hbuf, ln + 1, "@szLine@" # "#expr;");
        InsBufLine(hbuf, ln + 2, "@szLine1@" # "fi");
        return;
    }
    else if (szCmd == "ife")
    {
        PutBufLine(hbuf, ln, szLine1 # "if [ $a == $b ];then")
        InsBufLine(hbuf, ln + 1, "@szLine@" # "#expr;");
        InsBufLine(hbuf, ln + 2, "@szLine1@" # "else");
        InsBufLine(hbuf, ln + 3, "@szLine@" # "#expr;");
        InsBufLine(hbuf, ln + 4, "@szLine1@" # "fi");
        return;
    }
    else if (szCmd == "ifs")
    {
        PutBufLine(hbuf, ln, szLine1 # "if [ $a == $b ];then")
        InsBufLine(hbuf, ln + 1, "@szLine@" # "#expr");
        InsBufLine(hbuf, ln + 2, "@szLine1@" # "elif [ $c == $d ];then");
        InsBufLine(hbuf, ln + 3, "@szLine@" # "#expr;");
        InsBufLine(hbuf, ln + 4, "@szLine1@" # "else");
        InsBufLine(hbuf, ln + 5, "@szLine@" # "#expr;");
        InsBufLine(hbuf, ln + 6, "@szLine1@" # "fi");
        return;
    }
    else if (szCmd == "while" )
    {
        SetBufSelText(hbuf, " [ \"\$a\" -eq \"\$b\" ];do")
        InsBufLine(hbuf, ln + 1, "@szLine@" # "#expr;");
        InsBufLine(hbuf, ln + 2, "@szLine1@" # "done");
        return;
    }
    
    else if (szCmd == "for")
    {
        SetBufSelText(hbuf, " ( # ; # ; # )")
        InsBufLine(hbuf, ln + 1, "@szLine1@" # "{")
        InsBufLine(hbuf, ln + 2, "@szLine@" # "#")
        InsBufLine(hbuf, ln + 3, "@szLine1@" # "}")
        SetWndSel(hwnd, sel)
        SearchForward()
        szVar = ask("Please input loop variable")
        newsel = sel
        newsel.ichLim = GetBufLineLength (hbuf, ln)
        SetWndSel(hwnd, newsel)
        SetBufSelText(hbuf, " ( @szVar@ = # ; @szVar@ # ; @szVar@++ )")
    }
    else if (szCmd == "fo")
    {
        SetBufSelText(hbuf, "r ( ulI = 0; ulI < # ; ulI++ )")
        InsBufLine(hbuf, ln + 1, "@szLine1@" # "{")
        InsBufLine(hbuf, ln + 2, "@szLine@" # "#")
        InsBufLine(hbuf, ln + 3, "@szLine1@" # "}")
        symname =GetCurSymbol ()
        symbol = GetSymbolLocation(symname)
        if(strlen(symbol) > 0)
        {
            nIdx = symbol.lnName + 1;
            while( 1 )
            {
                szCurLine = GetBufLine(hbuf, nIdx);
                nRet = strstr(szCurLine,"{")
                if( nRet != 0xffffffff )
                {
                    break;
                }
                nIdx = nIdx + 1
                if(nIdx > symbol.lnLim)
                {
                    break
                }
             }
             InsBufLine(hbuf, nIdx + 1, "    UINT32_T ulI = 0;");        
         }
    }
    else if (szCmd == "switch" )
    {
        nSwitch = ask("Please input the number of case")
        SetBufSelText(hbuf, " ( # )")
        InsBufLine(hbuf, ln + 1, "@szLine1@" # "{")
        InsertMultiCaseProc(hbuf,szLine1,nSwitch)
    }
    else if (szCmd == "do")
    {
        InsBufLine(hbuf, ln + 1, "@szLine1@" # "{")
        InsBufLine(hbuf, ln + 2, "@szLine@" # "#");
        InsBufLine(hbuf, ln + 3, "@szLine1@" # "} while ( # );")
    }
    else if (szCmd == "case" )
    {
    /*
        SetBufSelText(hbuf, " # :")
        InsBufLine(hbuf, ln + 1, "@szLine@" # "#")
        InsBufLine(hbuf, ln + 2, "@szLine@" # "break;")*/
        
        SetBufSelText(hbuf, " \"\$var\" in")
        InsBufLine(hbuf, ln + 1, "@szLine@" # "\"case1\")")
        InsBufLine(hbuf, ln + 2, "@szLine@" # "#expr")   
        InsBufLine(hbuf, ln + 3, "@szLine@" # ";;")
        InsBufLine(hbuf, ln + 4, "@szLine@" # "\"case2\")")
        InsBufLine(hbuf, ln + 5, "@szLine@" # "#expr")   
        InsBufLine(hbuf, ln + 6, "@szLine@" # ";;")
        InsBufLine(hbuf, ln + 7, "@szLine1@" # "esac")
/*
case "$FRUIT" in
   "apple") echo "Apple pie is quite tasty." 
   ;;
   "banana") echo "I like banana nut bread." 
   ;;
   "kiwi") echo "New Zealand is famous for kiwi." 
   ;;
esac
*/

        
    }

    else if (szCmd == "tab")
    {
        DelBufLine(hbuf, ln)
        ReplaceBufTab()
        return
    }
    else if (szCmd == "file" || szCmd == "fi")
    {
        DelBufLine(hbuf, ln)
        InsertFileHeaderEN( hbuf,0, szMyName,"" )
        return
    }
    else if (szCmd == "func" || szCmd == "fu")
    {
        DelBufLine(hbuf,ln)
        lnMax = GetBufLineCount(hbuf)
        if(ln != lnMax)
        {
            szNextLine = GetBufLine(hbuf,ln)
            if( (strstr(szNextLine,"(") != 0xffffffff) || (nVer != 2))
            {
                symbol = GetCurSymbol()
                if(strlen(symbol) != 0)
                {  
                    FuncHeadCommentEN(hbuf, ln, symbol, szMyName,0)
                    return
                }
            }
        }
        szFuncName = Ask("Please input function name")
        FuncHeadCommentEN(hbuf, ln, szFuncName, szMyName, 1)
    }
    else if (szCmd == "hd")
    {
        DelBufLine(hbuf, ln)
        CreateFunctionDef(hbuf,szMyName,1)
        return
    }
    else if (szCmd == "hdn")
    {
        DelBufLine(hbuf, ln)

        /*生成不要文件名的新头文件*/
        CreateNewHeaderFile()
        return
    }
    else
    {
        SearchForward()
//            ExpandBraceLarge()
        stop
    }
    SetWndSel(hwnd, sel)
    SearchForward()
}
