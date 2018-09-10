

//CTRL+1
//多行使用 "//"注释 
macro MultiLineComment()  
{  
hwnd = GetCurrentWnd()  
 selection = GetWndSel(hwnd)  
    LnFirst = GetWndSelLnFirst(hwnd)      //取首行行号  
   LnLast = GetWndSelLnLast(hwnd)      //取末行行号  
   hbuf = GetCurrentBuf()  

  if(GetBufLine(hbuf, 0) == "//magic-number:tph85666031"){  
        stop  
    }  
   
  Ln = Lnfirst  
   buf = GetBufLine(hbuf, Ln)  
  len = strlen(buf)  
  
 while(Ln <= Lnlast) {  
     buf = GetBufLine(hbuf, Ln)  //取Ln对应的行  
     if(buf == ""){                    //跳过空行  
           Ln = Ln + 1  
           continue  
      }  

       if(StrMid(buf, 0, 1) == "/") {       //需要取消注释,防止只有单字符的行  
           if(StrMid(buf, 1, 2) == "/"){  
              PutBufLine(hbuf, Ln, StrMid(buf, 2, Strlen(buf)))  
          }       }     
        if(StrMid(buf,0,1) != "/"){          //需要添加注释  
           PutBufLine(hbuf, Ln, Cat("//", buf))  
        }  
    Ln = Ln + 1  
  }  

    SetWndSel(hwnd, selection)  
}

//ctrl+2
//使用#if(0)
macro Addif0()
{
    hwnd=GetCurrentWnd()
    sel=GetWndSel(hwnd)
    lnFirst=GetWndSelLnFirst(hwnd)
    lnLast=GetWndSelLnLast(hwnd)
    hbuf=GetCurrentBuf()
  
    if(LnFirst == 0) {
            szIfStart =""
    }else {
            szIfStart = GetBufLine(hbuf, LnFirst-1)
    }
    szIfEnd = GetBufLine(hbuf, lnLast+1)
    if(szIfStart == "#if (0)//\@Lyt"&& szIfEnd == "#endif") {
            DelBufLine(hbuf, lnLast+1)
            DelBufLine(hbuf, lnFirst-1)
            sel.lnFirst = (sel.lnFirst-1) 
            sel.lnLast = (sel.lnLast-1) 
    }else {
            InsBufLine(hbuf, lnFirst,"#if (0)//\@Lyt")
            InsBufLine(hbuf, lnLast+2,"#endif")
            sel.lnFirst = sel.lnFirst + 1
            sel.lnLast = sel.lnLast + 1
    }
  
    SetWndSel( hwnd, sel )
}
//ctrl+3
//将一行中鼠标选中部分注释掉,空的时候添加 /* */
macro CommentSelStr()
{
    hbuf = GetCurrentBuf()
    ln = GetBufLnCur(hbuf)
    str = GetBufSelText(hbuf)
    str = cat("/* ",str)
    str = cat(str,"*/ ")
    SetBufSelText (hbuf, str)
}

//ctrl+4
//把光标显示的行注释掉
macro CommentSingleLine()
{
    hbuf = GetCurrentBuf()
    ln = GetBufLnCur(hbuf)
    str = GetBufLine (hbuf, ln)
    str = cat("/*",str)
    str = cat(str,"*/")
    PutBufLine (hbuf, ln, str)
}

//ctrl+q
macro Insert_1_My_zhu_shi ()
{
hwnd = GetCurrentWnd()
lnLast = GetWndSelLnLast(hwnd)
hbuf = GetCurrentBuf()
//InsBufLine(hbuf,lnLast, "//\@Lyt ")
Ln = lnLast  
buf = GetBufLine(hbuf, Ln)  
len = strlen(buf)  

PutBufLine(hbuf,Ln,Cat(buf,"//\@Lyt "))
SetBufIns(hbuf,Ln,len+7)
}


//CTRL + w
macro Insert_2_hang_zhu_Shi()
{
hwnd = GetCurrentWnd()
lnLast = GetWndSelLnLast(hwnd)
hbuf = GetCurrentBuf()
//InsBufLine(hbuf,lnLast, "//\@Lyt ")
Ln = lnLast  
buf = GetBufLine(hbuf, Ln)  
len = strlen(buf)  

PutBufLine(hbuf,Ln,Cat(buf,"/*  */ "))
SetBufIns(hbuf,Ln,len+3)
}

//CTRL + e
macro Insert_3_help ()
{
hwnd = GetCurrentWnd()
lnLast = GetWndSelLnLast(hwnd)
hbuf = GetCurrentBuf() 
Ln = lnLast  
buf = GetBufLine(hbuf, Ln)  
len = strlen(buf)  

PutBufLine(hbuf,Ln,Cat(buf,"//\?HLP?  "))
SetBufIns(hbuf,Ln,len+8)
}







