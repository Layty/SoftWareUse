/******************************************************************************************
    Source Insight 内部macro 函数声明
    声明在头文件，可以实现自动提示功能，但不会影响macro的运行
    内部函数全部使用字母大小开头(大驼峰)
******************************************************************************************/
#ifndef __SI_MACRO_HINT_H
#define __SI_MACRO_HINT_H

/*
#0-编码规范
	0.1>所有的变量必须先声明再使用，Record 记录变量不声明
	0.2>所有的常量大写  
	0.3>内部函数 使用双下划线开始__xx_xxx,不允许外部单独调用
	0.4>外部函数大驼峰命名法则 for example:IsLower                   ToNumber
	0.5>外部和内部函数都必须添加函数说明和 for exampele: 说明如何调用
    
#1-语言帮助信息
    if/for/while 快速提示，关键字提示
    
#2-关键字智能提示

#3-库函数智能提示

#4-库函数说明

#5-关键字着色
*/



/*
s and sz    a string
ch          single character string. If more than one character is in a string, only the first character is used.
ich         zero-based index to a character in a string or character in a line
ichFirst    first index in a range of characters
ichLast     last index in a range of characters (inclusively)
ichLim      limit index - one past the last index in a range
cch         count of characters
fThing      “f” means flag or boolean. fThing means “Thing” is True.
TRUE        a non-zero value, e.g. “1”
FALSE       a zero value, i.e. “0”
ln          zero-based line number 
lnFirst     first line number in a range
lnLast      last line number in a range (inclusively)
lnLim       limit - one past the last line number in a range
hbuf        handle to a file buffer
hwnd        handle to a window
hprj        handle to a project
hsyml       Handle to a symbol list
other names general string variables
 */

/******************************************************************************************
    Const
******************************************************************************************/
#define True        1
#define False       0 
#define Nil         ""
#define hNil        0
#define Invalid     -1

/******************************************************************************************
    Type && Struct 
******************************************************************************************/
typedef   char* string;
typedef   int   handle;


 

/******************************************************************************************
    String Function
******************************************************************************************/
string Cat(string a, string b);

bool IsLower (string ch);

bool IsNumber (string s);

bool IsUpper (string s);

int StrLen (string s);

string StrMid (string s, int ichFirst, int ichLim);

string StrTrunc (string s, int cch);

string ToLower(string s);

string ToUpper(string s);

char AsciiFromChar(char ch);

char CharFromAscii (char ascii_code);


class Str
{
public:
    string Cat(string a, string b);

    bool IsLower (string ch);

    bool IsNumber (string s);

    bool IsUpper (string s);

    int StrLen (string s);

    string StrMid (string s, int ichFirst, int ichLim);

    string StrTrunc (string s, int cch);

    string ToLower(string s);

    string ToUpper(string s);

    char AsciiFromChar(char ch);

    char CharFromAscii (char ascii_code);
};

/******************************************************************************************
    User Input and Output Functions
******************************************************************************************/
class SYSTIME
{
public:
    string time;
    string date ;
    int Year ;
    int Month ;
    int DayOfWeek ;  //Sunday is 0, Monday is 1,
    int Day ; 
    int Hour ;
    int Minute ;
    int Second ;
    int Milliseconds ;
};

void Ask(string prompt_string);
void Msg(string s);
void StartMsg(string s);
void EndMsg();
void AssignKeyToCmd(int key_code, string cmd_name);
void Beep();
int CharFromKey(int key_code);
string CmdFromKey(int key_code); 
int FuncFromKey (int key_code);
char GetChar();
int GetKey();
SYSTIME GetSysTime(bool fLocalTime) ;
bool IsAltKeyDown(int key_code);
bool IsCtrlKeyDown(int key_code);
bool IsFuncKey(int key_code);
int KeyFromChar(string key, bool fCtrl, bool fShift, bool fAlt);

class Io
{
public:
    /*请求用户输入文字，界面包含OK和cancel 按钮，点击cancel取消当前macro 运行*/
    void Ask(string prompt_string);

    /*显示Messagebox 有cancel按钮，点击cancel 取消单前macro运行*/
    void Msg(string s);

    /*开始显示消息，知道调用EndMsg 结束*/
    void StartMsg(string s);

    void EndMsg();

    void AssignKeyToCmd(int key_code, string cmd_name);

    void Beep();

    /*非字符按键 返回0*/
    int CharFromKey(int key_code);

    /*
    根据按键 找到命令对应名称
    sample:
        key = GetKey();
        cmd_name = CmdFromKey(key);
        msg(“That key will invoke the @cmd@ command.”);
    */
    string CmdFromKey(int key_code); 

    /*返回功能键 F1~F12 对应的数字编号  非功能键 返回0*/
    int FuncFromKey (int key_code);

    /*等待用户按下字符按键 并返回字符*/
    char GetChar();

    /*等待用户按下按键 并返回键值*/
    int GetKey();


    /*If fLocalTime is non-zero, then the local time is returned, otherwise the system time (expressed in Coordinated Universal Time (UTC)) is returned.*/
    SYSTIME GetSysTime(bool fLocalTime) ;

    bool IsAltKeyDown(int key_code);

    bool IsCtrlKeyDown(int key_code);

    bool IsFuncKey(int key_code);


    /*
    创建按键组合 键值
    a-z          Simple alpha characters
    Fx           Function Key number x; e.g. F10
    Nx           Numeric keypad character x; e.g. N+ for "+" key
    Arrow keys   Up, Down, Left, Right
    Other keys   Page Up, Page Down Insert, Delete,Home, End,Tab, Enter
     
    sample:
    assign F9 to Close Project command:
    key = KeyFromChar(“F9”, 0, 0, 1);  // Alt+F9 
    AssignKeyToCmd(key, “Close Project”);
    */
    int KeyFromChar(string key, bool fCtrl, bool fShift, bool fAlt);
};

/******************************************************************************************
    File Buffer Function
******************************************************************************************/
class Bufprop
{
public:
    string Name;        ///> The buffer name (i.e. file name)
    handle fNew;        ///> True if buffer is a new, unsaved buffer.
    bool fDirty;        ///> True if the buffer has been edited since it was saved or opened.
    bool fReadOnly;     ///> True if the buffer is read-only.
    bool fClip;         ///>True if the buffer is a clip that appears in the Clip Window.
    bool fMacro;        ///>True if the buffer is a macro file.
    bool fRunningMacro;///>True if the buffer is a currently running macro file. 
    bool fCaptureResults;///>True if the buffer contains captured custom command output.
    bool fSearchResults;///>True if the buffer contains search results.
    bool fProtected;    ///>True if the buffer protected and reserved for internal use.
    int lnCount;        ///>The line count of the buffer.
    string Language;    ///>The programming language of the buffer. The language is determined by the file’s document type.
    string DocumentType;///>The document type of the buffer.
};

void AppendBufLine(handle hbuf, string s);

void ClearBuf (handle hbuf);

void CloseBuf (handle hbuf);

void CopyBufLine (handle hbuf, int ln);

void DelBufLine (handle hbuf, int ln);

handle GetBufHandle (string filename);

string GetBufLine (handle hbuf, int ln);//从0 开始的

int GetBufLineCount (handle hbuf);

int GetBufLineLength (handle hbuf, int ln);

int GetBufLnCur (handle hbuf);

string GetBufName (handle hbuf);

Bufprop GetBufProps (handle hbuf);

string GetBufSelText (handle hbuf);

handle GetCurrentBuf ();

void InsBufLine (handle hbuf, int ln, string s);

bool IsBufDirty (handle hbuf);

bool IsBufRW (handle hbuf);

handle MakeBufClip (handle hbuf, bool fClip);

handle NewBuf (string name);

handle OpenBuf (string filename);

bool OpenMiscFile (string filename);    ///> just for .CF3 extension  .PR extension

void PasteBufLine (handle hbuf, int ln);

void PrintBuf (handle hbuf, bool fUseDialogBox);

void PutBufLine (handle hbuf, int ln, s);    ///>Replaces the line of text for line number 

void RenameBuf (handle hbuf, string szNewName);

void SaveBuf (handle hbuf);

void SaveBufAs (handle hbuf, string filename);

void SetBufDirty (handle hbuf, bool fDirty);

void SetBufIns (handle hbuf, int ln, int ich); ///>Sets the cursor position line && column number

void SetBufSelText (handle hbuf, string s);

void SetCurrentBuf (handle hbuf);

class Buffer
{
public:
    void AppendBufLine(handle hbuf, string s);

    void ClearBuf (handle hbuf);

    void CloseBuf (handle hbuf);

    void CopyBufLine (handle hbuf, int ln);

    void DelBufLine (handle hbuf, int ln);

    handle GetBufHandle (string filename);

    string GetBufLine (handle hbuf, int ln);

    int GetBufLineCount (handle hbuf);

    int GetBufLineLength (handle hbuf, int ln);

    int GetBufLnCur (handle hbuf);

    string GetBufName (handle hbuf);

    Bufprop GetBufProps (handle hbuf);

    string GetBufSelText (handle hbuf);

    handle GetCurrentBuf ();

    void InsBufLine (handle hbuf, int ln, string s);

    bool IsBufDirty (handle hbuf);

    bool IsBufRW (handle hbuf);

    handle MakeBufClip (handle hbuf, bool fClip);

    handle NewBuf (string name);

    handle OpenBuf (string filename);

    bool OpenMiscFile (string filename);    ///> just for .CF3 extension  .PR extension

    void PasteBufLine (handle hbuf, int ln);

    void PrintBuf (handle hbuf, bool fUseDialogBox);

    void PutBufLine (handle hbuf, int ln, s);    ///>Replaces the line of text for line number 

    void RenameBuf (handle hbuf, string szNewName);

    void SaveBuf (handle hbuf);

    void SaveBufAs (handle hbuf, string filename);

    void SetBufDirty (handle hbuf, bool fDirty);

    void SetBufIns (handle hbuf, int ln, int ich); ///>Sets the cursor position line && column number

    void SetBufSelText (handle hbuf, string s);

    void SetCurrentBuf (handle hbuf);
};

/******************************************************************************************
   Window Function
******************************************************************************************/
class Rect
{
     int   Left;  ///>The left pixel coordinate of the rectangle
     int   Top;   ///>The top pixel coordinate of the rectangle
     int   Right; ///>The right pixel coordinate of the rectangle
     int   Bottom;///>The bottom pixel coordinate of the rectangle
};
class DIM
{
    int Cxp;///>Count of X-pixels (horizontal size);
    int Cyp;///> Count of Y-pixels (vertical size)
};

class Selection
{
    int lnFirst;    ///> the first line number
    int ichFirst;   ///> the index of the first character on the line lnFirst
    int lnLast ;    ///> the last line number
    int ichLim ;    ///> the limit index (one past the last) of the last character on the line given in lnLast
    bool fExtended ;///> TRUE if the selection is extended to include more than one character.
                    ///> FALSE if the selection is a simple insertion point.
                    ///> this is the same as the following expression:
                    ///> (sel.fRect || sel.lnFirst != sel.lnLast || sel.ichFirst != sel.ichLim)
     
    bool fRect ;///> TRUE if selection is rectangular (block style)
                ///> FALSE if the selection is a linear range of characters.
                ///> The following fields only apply if fRect is TRUE:
     
    int xLeft ; ///> the left pixel position of the rectangle in window coordinates.
    int xRight ;///> the pixel position of the right edge of the rectangle in window coordinates.
};

void CloseWnd (handle hwnd);

handle GetApplicationWnd ();

handle GetCurrentWnd ();

handle GetNextWnd (handle hwnd);

handle GetWndBuf (handle hwnd);

Rect GetWndClientRect (handle hwnd);

DIM GetWndDim (handle hwnd);

handle GetWndHandle (handle hbuf);

int GetWndHorizScroll (handle hwnd); 

int GetWndLineCount (handle hwnd);
int GetWndLineWidth (handle hwnd, int ln, int cch);
handle GetWndParent (handle hwnd); 
Rect GetWndRect (handle hwnd);
Selection GetWndSel (handle hwnd);
int GetWndSelIchFirst (handle hwnd);
int GetWndSelIchLim (handle hwnd);
int GetWndSelLnFirst (handle hwnd);
int GetWndSelLnLast (handle hwnd);
int GetWndVertScroll (handle hwnd);
int IchFromXpos (handle hwnd, int ln, int xp);
bool IsWndMax (handle hwnd);
bool IsWndMin (handle hwnd);
bool IsWndRestored (handle hwnd);
int LineFromYpos (handle hwnd, int ypos);
void MaximizeWnd (handle hwnd);
void MinimizeWnd (handle hwnd);
handle NewWnd (handle hbuf);
void ScrollWndHoriz (handle hwnd, int pixel_count);
void ScrollWndToLine (handle hwnd, int ln);
void ScrollWndVert (handle hwnd, int line_count);
void SetCurrentWnd (handle hwnd);
void SetWndRect (handle hwnd, int left, int top, int right, int bottom); 
void SetWndSel (handle hwnd, int selection_record);
void ToggleWndMax (handle hwnd);
int XposFromIch (handle hwnd, int ln, int ich);
int  YposFromLine (handle hwnd, int ln);
int YdimFromLine (handle hwnd, int ln);

class Window
{
public:
    void CloseWnd (handle hwnd);

    handle GetApplicationWnd ();

    handle GetCurrentWnd ();

    handle GetNextWnd (handle hwnd);

    handle GetWndBuf (handle hwnd);

    Rect GetWndClientRect (handle hwnd);

    DIM GetWndDim (handle hwnd);

    handle GetWndHandle (handle hbuf);

    int GetWndHorizScroll (handle hwnd); ///>Returns the horizontal scroll state of the window hwnd. The horizontal scroll state is the pixel count of the scroll

    int GetWndLineCount (handle hwnd);
    /**************************************************************************************************
    @@brief   Returns the width of a specified line of text in the given window. 
    @param hwnd  The window. 
    @param ln    The line number that contains the text to be measured. If ln is out of range, then –1 is returned.
    @param cch   The count of characters to measure on the line. If cch is set to –1, then the whole line length is measured.
    ***************************************************************************************************/
    int GetWndLineWidth (handle hwnd, int ln, int cch);

    handle GetWndParent (handle hwnd); 

    Rect GetWndRect (handle hwnd);

    Selection GetWndSel (handle hwnd);

    int GetWndSelIchFirst (handle hwnd);

    int GetWndSelIchLim (handle hwnd);

    int GetWndSelLnFirst (handle hwnd);

    int GetWndSelLnLast (handle hwnd);

    int GetWndVertScroll (handle hwnd);

    int IchFromXpos (handle hwnd, int ln, int xp);

    bool IsWndMax (handle hwnd);

    bool IsWndMin (handle hwnd);

    bool IsWndRestored (handle hwnd);

    int LineFromYpos (handle hwnd, int ypos);

    void MaximizeWnd (handle hwnd);

    void MinimizeWnd (handle hwnd);

    handle NewWnd (handle hbuf);

    void ScrollWndHoriz (handle hwnd, int pixel_count);

    void ScrollWndToLine (handle hwnd, int ln);

    void ScrollWndVert (handle hwnd, int line_count);

    void SetCurrentWnd (handle hwnd);

    void SetWndRect (handle hwnd, int left, int top, int right, int bottom); 

    void SetWndSel (handle hwnd, int selection_record);

    void ToggleWndMax (handle hwnd);

    int XposFromIch (handle hwnd, int ln, int ich);

    int  YposFromLine (handle hwnd, int ln);
    /*************************************************************************************************
    @@brief   Returns the pixel y-position of the given line number (ln) in the given window. 
                The y-position is relative to the top edge of the window. If the line number is not
                visible in the window, then -1 is returned
    @param hwnd  The window.
    @param ln    The line number that contains the text to be measured. 
               If ln is out of range in the file, or not visible inthe window, 
               then –1 is returned.
    ***********************************************************************************************/
    int YdimFromLine (handle hwnd, int ln);
};



/******************************************************************************************
   Symbol Functions(暂时不声明，用的比较少)
******************************************************************************************/
class SymbolRecord
{
    string  Symbol; ///> The full symbol name. A symbol name is actually a path. Every symbol name is 
                    ///> divided into path components, which are separated by dot (.) characters. 
                    ///> a symbol name might be “myclass.member1”. 
                    ///> For example,In this example, “member1” is contained by “myclass”.
    string Type;    ///>The symbol’s type (e.g. “Function”, “Class”, etc.)
    string Project; ///>The full path of the project where the symbol was found
    string File;    ///> The full path of the file where the symbol was found
    int lnFirst;    ///> The first line number of the symbol declaration
    int lnLim;      ///> The limit line number of the symbol declaration
    int lnName;     ///> The line number where the symbol’s name appears in the declaration.
    int ichName;    ///>The character index of the symbol’s name in the declaration at the line lnName.
    int Instance;   ///>The instance number path of the symbol within File. For example, the first 
                    ///>occurrence of a symbol is instance 0, the second is instance 1, and so on.
};

class Symbol
{
    // int GetBufSymCount(handle hbuf);
    // SymbolRecord GetBufSymLocation(handle hbuf, int isym);
    // string GetBufSymName(handle hbuf, int isym);
    // string GetCurSymbol ();
    // int GetSymbolLine (string symbol_name);
    // SymbolRecord GetSymbolLocation (string symbol_name);
    // GetSymbolLocationEx (string symbol_name, handle output_buffer, bool fMatchCase,
                         // LocateFiles,  bool fLocateSymbols);
    // SymbolRecord GetSymbolFromCursor (handle hbuf, int ln, int ich);
    // SymbolRecord GetSymbolLocationFromLn (handle hbuf, int ln);
    // JumpToLocation (SymbolRecord symbol_record);
    // JumpToSymbolDef (string symbol_name);
    // SymbolChildren (SymbolRecord symbol);
    // SymbolContainerName (SymbolRecord symbol);
    // SymbolDeclaredType (SymbolRecord symbol);
    // SymbolLeafName (SymbolRecord symbol);
    // SymbolParent (SymbolRecord symbol);
    // SymbolRootContainer (SymbolRecord symbol);
    // SymbolStructureType (SymbolRecord symbol);
};


/******************************************************************************************
    Env Function
******************************************************************************************/
string GetEnv (string env_name);

string GetReg (string reg_key_name);

bool IsCmdEnabled (string cmd_name);

void PutEnv (string env_name, string value);

void RunCmd (string cmd_name);

void RunCmdLine (string sCmdLine, string sWorkingDirectory, bool fWait);

void SetReg (string reg_key_name, string value);

void ShellExecute (string sVerb, string sFile, string sExtraParams, string sWorkingDirectory, int windowstate);

class Env
{
public:
    string GetEnv (string env_name);

    string GetReg (string reg_key_name);

    bool IsCmdEnabled (string cmd_name);

    void PutEnv (string env_name, string value);

    void RunCmd (string cmd_name);

    void RunCmdLine (string sCmdLine, string sWorkingDirectory, bool fWait);

    void SetReg (string reg_key_name, string value);

    void ShellExecute (string sVerb, string sFile, string sExtraParams, string sWorkingDirectory, int windowstate);
};


/******************************************************************************************
    Buffer List /Window List Function
******************************************************************************************/
class BufferList
{
    // BufListCount ();
    // BufListItem (index);
    // WndListCount ();
    // WndListItem (index);
};
/******************************************************************************************
   Symbol List Functions(暂时不声明，用的比较少)
******************************************************************************************/
class SymbolList
{
    // SymListCount ();
    // SymListFree (hsyml);
    // SymListInsert (hsyml, isym, symbolNew);
    // SymListItem (hsyml, isym);
    // SymListNew ();
    // SymListRemove (hsyml, isym);
};

/******************************************************************************************
   Bookmark Functions(暂时不声明，用的比较少)
******************************************************************************************/
class BookMark
{
    // BookmarksAdd (name, filename, ln, ich);
    // BookmarksCount ();
    // BookmarksDelete (name);
    // BookmarksItem (index);
    // BookmarksLookupLine (filename, ln);
    // BookmarksLookupName (name);
};



/******************************************************************************************
   Searching Functions(暂时不声明，用的比较少)
******************************************************************************************/

class Search
{
    // GetSourceLink (hbufSource, lnSource);
    // LoadSearchPattern(pattern, fMatchCase, fRegExp, fWholeWordsOnly);
    // ReplaceInBuf(handle hbuf, oldPattern, newPattern, lnStart, lnLim, fMatchCase, fRegExp, fWholeWordsOnly, fConfirm);
    // SearchForRefs (handle hbuf, word, fTouchFiles);
    // SearchInBuf (handle hbuf, pattern, lnStart, ichStart, fMatchCase, fRegExp, fWholeWordsOnly);
    // SetSourceLink (hbufSource, lnSource, target_file, lnTarget);
};

/******************************************************************************************
   Project Functions
******************************************************************************************/




class Project
{
public:
    void AddConditionVariable(handle hprj, string szName, string szValue); 
    void AddFileToProj(handle hprj, string filename);
    void CloseProj (handle hprj);
    void DeleteConditionVariable(handle hprj, string szName); 
    void DeleteProj (string proj_name);
    bool EmptyProj ();
    handle GetCurrentProj ();
    string GetProjDir (handle hprj);
    int GetProjFileCount (handle hprj);
    string GetProjFileName (handle hprj, int ifile);
    string GetProjName (handle hprj);
    int GetProjSymCount (handle hprj);
    SymbolRecord GetProjSymLocation (handle hprj, int isym);
    string GetProjSymName (handle hprj, int isym);
    handle NewProj (string proj_name);
    handle OpenProj (string proj_name);
    void RemoveFileFromProj(handle hprj, string filename);
    void SyncProj (handle hprj);
    void SyncProjEx(handle hprj, bool fAddNewFiles, bool fForceAll, bool fSupressWarnings);
};

/******************************************************************************************
   Miscellaneous Macro Functions
******************************************************************************************/
//typedef struct _ProgEnvInfo
class ProgEnvInfo
 {
public:
    string ProgramDir;            ///<SI 应用程序目录
    string TempDir;               ///<系统临时目录
    string BackupDir;             ///<SI 自动备份目录
    string ClipDir;               ///<SI 剪贴板文件所在位置 用来配置代码片段 
    string ProjectDirectoryFile;  ///<SI 项目目录文件位置
    string ConfigurationFile;     ///<SI 当前活动的配置文件 名称 
    string ShellCommand;          ///<cmd.exe 所在的路径 一般为c:\windows\system32\cmd.exe 
    string UserName;              ///<SI 注册的用户名
    string UserOrganization;      ///<SI 注册的用户组织
    string SerialNumber;          ///<SI 注册的序列号
 };

//SI 运行的版本相关的信息
class ProgInfo
{
public: 
    string ProgramName;  
    string versionMajor;
    string versionMinor;
    string versionBuild;
    string CopyrightMsg;     
    bool   fTrialVersion;  //SI 是否为试用 版本
    bool   fBetaVersion;   //SI 是否Beta 版本
    string ExeFileName;
    
    int cchLineMax;      
    int cchPathMax;      
    int cchSymbolMax;        
    int cchCmdMax;       
    int cchBookmarkMax;
    int cchInputMax;         
    int cchMacroStringMax;       
    int lnMax;       
    int integerMax; //SI 支持的整型最大值    
    int integerMin;//SI 支持的整型最小值
};

void DumpMacroState (handle hbufOutput);
ProgEnvInfo GetProgramEnvironmentInfo ();
ProgInfo GetProgramInfo();

class Debug
{
    void DumpMacroState (handle hbufOutput);
    ProgEnvInfo GetProgramEnvironmentInfo ();
    ProgInfo GetProgramInfo();
};




#endif

