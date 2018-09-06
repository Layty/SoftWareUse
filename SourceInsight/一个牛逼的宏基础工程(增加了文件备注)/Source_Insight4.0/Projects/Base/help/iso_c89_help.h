#ifndef __ISO_C89_HINT_H__
#define __ISO_C89_HINT_H__


/**
C89中标准的头文件
　　<assert.h> 定义宏assert()
　　<ctype.h>  字符处理
　　<errno.h>  错误报告
　　<float.h>  定义与实现相关的浮点值勤
　　<limits.h> 定义与实现相关的各种极限值
　　<locale.h> 支持函数setlocale()
　　<math.h>   数学函数库使用的各种定义
　　<setjmp.h> 支持非局部跳转
　　<signal.h> 定义信号值
　　<stdarg.h> 支持可变长度的变元列表
　　<stddef.h> 定义常用常数
　　<stdio.h>  支持文件输入和输出
　　<stdlib.h> 其他各种声明
　　<string.h> 支持串函数
　　<time.h> 支持系统时间函数

C99中标准的头文件
　　<assert.h> 定义宏assert()
　　<ctype.h> 字符处理
　　<errno.h> 错误报告
　　<float.h> 定义与实现相关的浮点值勤
　　<limits.h> 定义与实现相关的各种极限值
　　<locale.h> 支持函数setlocale()
　　<math.h> 数学函数库使用的各种定义
　　<setjmp.h> 支持非局部跳转
　　<signal.h> 定义信号值
　　<stdarg.h> 支持可变长度的变元列表
　　<stddef.h> 定义常用常数
　　<stdio.h> 支持文件输入和输出
　　<stdlib.h> 其他各种声明
　　<string.h> 支持字符串函数
　　<time.h> 支持系统时间函数

　　C99新增的头文件和库
　　<complex.h> 支持复数算法
　　<fenv.h> 给出对浮点状态标记和浮点环境的其他方面的访问
　　<inttypes.h> 定义标准的、可移植的整型类型集合。也支持处理最大宽度整数的函数
　　<iso646.h> 首先在此1995年第一次修订时引进，用于定义对应各种运算符的宏
　　<stdbool.h> 支持布尔数据类型类型。定义宏bool，以便兼容于C++
　　<stdint.h> 定义标准的、可移植的整型类型集合。该文件包含在<inttypes.h>中
　　<tgmath.h> 定义一般类型的浮点宏
　　<wchar.h> 首先在1995年第一次修订时引进，用于支持多字节和宽字节函数
　　<wctype.h> 首先在1995年第一次修订时引进，用于支持多字节和宽字节分类函数


 （1）对数组的增强

  可变长数组
    C99中,程序员声明数组时,数组的维数可以由任一有效的整型表达式确定,
    包括只在运行时才能确定
    其值的表达式,这类数组就叫做可变长数组,但是只有局部数组才可以是变长的.
    可变长数组的维数在数组生存期内是不变的,也就是说,可变长数组不是动态的.
    可以变化的只是数组的大小.
    可以使用*来定义不确定长的可变长数组。

  数组声明中的类型修饰符
　在C99中，如果需要使用数组作为函数变元，可以在数组声明的方括号内使用static关键?
这相当于告诉编译程序，变元所指向的数组将至少包含指定的元素个数。也可以在数组声明的?
括号内使用
restrict,volatile,
const关键字，但只用于函数变元。如果使用restrict，指针是初始访问该对象的惟一途
径。如果使用const，指针始终指向同一个数组。使用volatile没有任何意义。

 （2）单行注释
     引入了单行注释标记 "//" , 可以象C++一样使用这种注释了。
 （3）分散代码与声明
　　    预处理程序的修改
 （4）for语句内的变量声明　　
　　C99中，程序员可以在for语句的初始化部分定义一个或多个变量，这些变量的作用域仅?
?本for语
句所控制的循环体内。比如：
代码:
for(int i=0; i<10; i++){
    // do someting ...
}

   （5）复合赋值

C99中，复合赋值中，可以指定对象类型的数组、结构或联合表达式。当使用复合赋值时，?
?在括弧
内指定类型，后跟由花括号围起来的初始化列表；若类型为数组，则不能指定数组的大小?
?建成的对象是
未命名的。
　　例： double *fp = (double[]) {1.1, 2.2, 3.3};
　　该语句用于建立一个指向double的指针fp，且该指针指向这个3元素数组的第一个元素。
在文件
域内建立的复合赋值只在程序的整个生存期内有效。在模块内建立的复合赋值是局部对象?
?在退出模块后
不再存在。

   (6)指定的初始化符

C99中，该特性对经常使用稀疏数组的程序员十分有用。指定的初始化符通常有两种用法：?
?于数组，
以及用于结构和联合。用于数组的格式：[index] = vol;
其中，index表示数组的下标，vol表示本数组
元素的初始化值。
　　例如： int x[10] = {[0] = 10, [5] = 30}; 其中只有x[0]和x[5]得到了初始化．用于结构或联
合的格式如下：
　　member-name(成员名称)
　　对结构进行指定的初始化时，允许采用简单的方法对结构中的指定成员进行初始化。
　　例如： struct example{ int k, m, n; } object = {m = 10,n = 200};
　　其中，没有初始化k。对结构成员进行初始化的顺序没有限制。

     (7)printf()和scanf()函数系列的增强

  C99中printf()和scanf()函数系列引进了处理long long int和unsigned long long int数据类型
的特性。long long int 类型的格式修饰符是ll。在printf()和scanf()函数中，ll适用于d, i, o, u 和x
格式说明符。另外，C99还引进了hh修饰符。当使用d, i, o, u和x格式说明符时，hh用于指定char
型变元。ll和hh修饰符均可以用于n说明符。
　　格式修饰符a和A用在printf()函数中时，结果将会输出十六进制的浮点数。格式如下：[-]
0xh, hhhhp
+ d 使用A格式修饰符时，x和p必须是大写。A和a格式修饰符也可以用在scanf()
函数中，用于读取
浮点数。调用printf()函数时，允许在%f说明符前加上l修饰符，即%lf，但不起作用。

      (10)__func__预定义标识符
　　用于指出__func__所存放的函数名，类似于字符串赋值。

     (11)

       其它特性的改动
　　放宽的转换限制
　
　　　　限制　　　　　　　　　　　　　C89标准　　C99标准
　　　　数据块的嵌套层数　　　　　　　15　　　　　127
　　　　条件语句的嵌套层数　　　　　　8　　　　　 63
　　　　内部标识符中的有效字符个数　　31　　　　　63
　　　　外部标识符中的有效字符个数　　6　　　　　　31
　　　　结构或联合中的成员个数　　　　127　　　　1023
　　　　函数调用中的参数个数　　　　　31　　　　　127



　　不再支持隐含式的int规则
　　删除了隐含式函数声明
　　对返回值的约束
　　　　C99中,非空类型函数必须使用带返回值的return语句.
　　扩展的整数类型
　　　　扩展类型 含义
　　　　int16_t 整数长度为精确16位
　　　　int_least16_t 整数长度为至少16位
　　　　int_fast32_t 最稳固的整数类型,其长度为至少32位
　　　　intmax_t 最大整数类型
　　　　uintmax_t 最大无符号整数类型
　　对整数类型提升规则的改进
　　　　C89中,表达式中类型为char,short int或int的值可以提升为int或unsigned int类型.
　　　　C99中,每种整数类型都有一个级别.例如:long long int 的级别高于int, int的级别高于char
等.在表达式中,其级别低于int或unsigned int的任何整数类型均可被替换成int或unsigned int类型.



(12)新增数据类型　
　　_Bool　
　　值是0或1。C99中增加了用来定义bool、true以及false宏的头文件夹<stdbool.h>，以便程序
员能够编写同时兼容于C与C++的应用程序。在编写新的应用程序时，应该使用
<stdbool.h>头文件中的bool宏。
　　_Complex and _Imaginary
　C99标准中定义的复数类型如下：float_Complex; float_Imaginary; double_Complex;
double_Imaginary; long double_Complex; long double_Imaginary.
<complex.h>头文件中定义了complex和imaginary宏,并将它们扩展为_Complex和_Imaginary,
因此在编写新的应用程序时,应该使用<stdbool.h>头文件中的complex和imaginary宏。
　　long long int
　　C99标准中引进了long long int（-(2e63 - 1)至2e63 - 1）和unsigned long long int（0 - 2e64
- 1）。long long int能够支持的整数长度为64位。

### C语言技巧

当然宏定义非常重要的，它可以帮助我们防止出错，提高代码的可移植性和可读性等。
下面列举一些成熟软件中常用得宏定义

1，防止一个头文件被重复包含
#ifndef COMDEF_H
#define COMDEF_H

//头文件内容 …
#endif

2，重新定义一些类型，防止由于各种平台和编译器的不同，而产生的类型字节数差异，方便移植。
typedef  unsigned long int  uint32;      ///< Unsigned 32 bit value

3，得到指定地址上的一个字节或字
#define  MEM_B( x )  ( *( (byte *) (x) ) )
#define  MEM_W( x )  ( *( (word *) (x) ) )

4，求最大值和最小值
#define  MAX( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define  MIN( x, y )  ( ((x) < (y)) ? (x) : (y) )

5，得到一个field在结构体(struct)中的偏移量
#define FPOS( type, field )   ( (dword) &(( type *) 0)-> field )

6,得到一个结构体中field所占用的字节数
#define FSIZ( type, field ) sizeof( ((type *) 0)->field )

7，按照LSB格式把两个字节转化为一个word
#define  FLIPW( ray ) ( (((word) (ray)[0]) * 256) + (ray)[1] )

8，按照LSB格式把一个word转化为两个字节
#define  FLOPW( ray, val )
(ray)[0] = ((val) / 256);
(ray)[1] = ((val) & 0xFF)

9，得到一个变量的地址（word宽度）
#define  B_PTR( var )  ( (byte *) (void *) &(var) )
#define  W_PTR( var )  ( (word *) (void *) &(var) )

10，得到一个字的高位和低位字节
#define  WORD_LO(xxx)  ((byte) ((word)(var) & 255))
#define  WORD_HI(xxx)  ((byte) ((word)(var) >> 8))

11，返回一个比X大的最接近的8的倍数
#define RND8( x )       ((((x) + 7) / 8 ) * 8 )

12，将一个字母转换为大写
#define  UPCASE( c ) ( ((c) >= ’a' && (c) <= ’z') ? ((c) - 0×20) : (c) )

13，判断字符是不是10进值的数字
#define  DECCHK( c ) ((c) >= ’0′ && (c) <= ’9′)

14，判断字符是不是16进值的数字
#define  HEXCHK( c ) ( ((c) >= ’0′ && (c) <= ’9′) ||
((c) >= ’A' && (c) <= ’F') ||
((c) >= ’a' && (c) <= ’f') )

15，防止溢出的一个方法
#define  INC_SAT( val )  (val = ((val)+1 > (val)) ? (val)+1 : (val))

16，返回数组元素的个数
#define  ARR_SIZE( a )  ( sizeof( (a) ) / sizeof( (a[0]) ) )

17，对于IO空间映射在存储空间的结构，输入输出处理
#define inp(port)         (*((volatile byte *) (port)))
#define inpw(port)        (*((volatile word *) (port)))
#define inpdw(port)       (*((volatile dword *)(port)))

#define outp(port, val)   (*((volatile byte *) (port)) = ((byte) (val)))
#define outpw(port, val)  (*((volatile word *) (port)) = ((word) (val)))
#define outpdw(port, val) (*((volatile dword *) (port)) = ((dword) (val)))

18，使用一些宏跟踪调试
ANSI标准说明了五个预定义的宏名。它们是：
__LINE__
__FILE__
__DATE__
__TIME__
__STDC__

如果编译不是标准的，则可能仅支持以上宏名中的几个，或根本不支持。
记住编译程序 也许还提供其它预定义的宏名。
是行连接符，会将下一行和前一行连接成为一行，即将物理上的两行连接成逻辑上的一行
__FILE__ 是内置宏 代表源文件的文件名
__LINE__ 是内置宏，代表该行代码的所在行号
__DATE__宏指令含有形式为月/日/年的串，表示源文件被翻译到代码时的日期。
源代码翻译到目标代码的时间作为串包含在__TIME__ 中。串形式为时：分：秒。
如果实现是标准的，则宏__STDC__含有十进制常量1。如果它含有任何其它数，则实现是非标准的。

可以定义宏，例如:
当定义了_DEBUG，输出数据信息和所在文件所在行

#ifdef _DEBUG
#define DEBUGMSG(msg,date) printf(msg);printf(“%d%d%d”,date,_LINE_,_FILE_)
#else
#define DEBUGMSG(msg,date)
#endif

19，宏定义防止使用是错误
用小括号包含。
例如：#define ADD(a,b) （a+b）

用do{}while(0)语句包含多语句防止错误

例如：#define DO(a,b) a+b;
a++;
应用时：if(….)
DO(a,b); //产生错误
else
解决方法: 
#difne DO(a,b) do{a+b;a++;}while(0)

为什么需要do{…}while(0)形式?
总结了以下几个原因：

1)，空的宏定义避免warning:
#define foo() do{}while(0)
2)，存在一个独立的block，可以用来进行变量定义，进行比较复杂的实现。
3)，如果出现在判断语句过后的宏，这样可以保证作为一个整体来是实现：
#define foo(x)
action1();
action2();
在以下情况下：
if(NULL == pPointer)
    foo();
就会出现action2必然被执行的情况，而这显然不是程序设计的目的。


4)，以上的第3种情况用单独的{}也可以实现，但是为什么一定要一个do{}while(0)呢，看以下代码：
#define switch(x,y) {int tmp; tmp=x;x=y;y=tmp;}
if(x>y)
   switch(x,y);
else        //error, parse error before else
   otheraction();


在把宏引入代码中，会多出一个分号，从而会报错。
使用do{….}while(0) 把它包裹起来，成为一个独立的语法单元，从而不会与上下文发生混淆。同时因为绝大多数的编译器都能够识别do{…}while(0)这种无用的循环并进行优化，所以使用这种方法也不会导致程序的性能降低。

为什么很多linux内核中宏#defines用do { … } while(0)？
有很多原因：
（Dave Miller的说法）：
编译器对于空语句会给出告警，这是为什么#define FOO do{ }while(0);
给定一个基本块（局部可视域），定义很多局部变量；

（Ben Collins的说法）：
在条件代码中，允许定义复杂的宏。可以想像有很多行宏，如下代码

#define FOO(x)
printf(“arg is %sn”, x);
do_something_useful(x);
现在，想像下面的应用:
if (blah == 2)
FOO(blah);
展开后代码为:
if (blah == 2)
printf(“arg is %sn”, blah);
do_something_useful(blah);;
就像你看到的，if仅仅包含了printf（），而do_something_useful()调用是无条件调用。因此，如果用do { … } while(0)，结果是：
if (blah == 2)
do {
	printf(“arg is %sn”, blah);
	do_something_useful(blah);
} while (0);
这才是所期望的结果。
（Per Persson的说法）：
像 Miller and Collins指出的那样，需要一个块语句包含多个代码行和声明局部变量。但是，本质如下面例子代码：
#define exch(x,y) { int tmp; tmp=x; x=y; y=tmp; }
上面代码在有些时候却不能有效工作，下面代码是一个有两个分支的if语句：
if (x > y)
exch(x,y);               // Branch 1
else
do_something();      // Branch 2
展开后代码如下：
if (x > y)
{                // Single-branch if-statement!!!
	int tmp;            // The one and only branch consists
	tmp = x;           // of the block.
	x = y;
	y = tmp;
}
;                // empty statement
else                             // ERROR!!! “parse error before else”
do_something();
问题是分号（；）出现在块后面。解决这个问题可以用do{}while（0）：
if (x > y)
do {
int tmp;
tmp = x;
x = y;
y = tmp;
} while(0);
else
do_something();
（ Bart Trojanowski的说法）：
Gcc加入了语句解释，它提供了一个替代do-while-0块的方法。对于上面的解决方法如下，并且更加符合常理
#define FOO(arg) ({
typeof(arg) lcl;
lcl = bar(arg);
lcl;
})
这是一个奇怪的循环，它根本就只会运行一次，为什么不去掉外面的do{..}while结构呢？我曾一度在心里把它叫做“怪圈”。原来这也是非常巧妙的技巧。在工程中可能经常会引起麻烦，而上面的定义能够保证这些麻烦不会出现。下面是解释：
假设有这样一个宏定义
#define macro(condition)
if(condition) dosomething()
现在在程序中这样使用这个宏：
if(temp)
macro(i);
else
doanotherthing();
一切看起来很正常，但是仔细想想。这个宏会展开成：
if(temp)
if(condition) dosomething();
else
doanotherthing();
这时的else不是与第一个if语句匹配，而是错误的与第二个if语句进行了匹配，编译通过了，但是运行的结果一定是错误的。
为了避免这个错误，我们使用do{….}while(0) 把它包裹起来，成为一个独立的语法单元，从而不会与上下文发生混淆。同时因为绝大多数的编译器都能够识别do{…}while(0)这种无用的循环并进行优化，所以使用这种方法也不会导致程序的性能降低。



另一个讲解
这是为了含多条语句的宏的通用性
因为默认规则是宏定义最后是不能加分号的，分号是在引用的时候加上的
比如定义了一个宏fw(a,b)，那么在c文件里一定是这样引用
fw(a,b);
如果不用do…while，那么fw就得定义成:
#define fw(a,b) {read((a));write((b));}
那这样fw(a,b);展开后就成了:
{read(a);write(b);};
最后就多了个分号，这是语法错误
而定义成do…while的话，展开后就是:
do{read(a);write(b);}while(0);    完全正确
所以要写一个包含多条语句的宏的话，不用do…while是不可能的



宏中#和##的用法
一、一般用法
我们使用#把宏参数变为一个字符串,用##把两个宏参数贴合在一起.
用法:
＃include<cstdio>
＃include<climits>
using namespace std;

#define STR(s)     #s
#define CONS(a,b)  int(a##e##b)

int main()
{
	printf(STR(vck));        // 输出字符串vck
	printf(%dn, CONS(2,3));  // 2e3 输出:2000
	return 0;
}

二、当宏参数是另一个宏的时候
需要注意的是凡宏定义里有用’#'或’##’的地方宏参数是不会再展开.

1, 非’#'和’##’的情况
#define TOW      (2)
#define MUL(a,b) (a*b)

printf(%d*%d=%dn, TOW, TOW, MUL(TOW,TOW));
这行的宏会被展开为：
printf(%d*%d=%dn, (2), (2), ((2)*(2)));
MUL里的参数TOW会被展开为(2).

2, 当有’#'或’##’的时候
#define A          (2)
#define STR(s)     #s
#define CONS(a,b)  int(a##e##b)

printf(“int max: %sn”,  STR(INT_MAX));    // INT_MAX ＃include<climits>
这行会被展开为：
printf(“int max: %sn”, #INT_MAX);

printf(%sn, CONS(A, A));               // compile error
这一行则是：
printf(%sn, int(AeA));

INT_MAX和A都不会再被展开, 然而解决这个问题的方法很简单. 加多一层中间转换宏.
加这层宏的用意是把所有宏的参数在这层里全部展开, 那么在转换宏里的那一个宏(_STR)就能得到正确的宏参数.

#define A           (2)
#define _STR(s)     #s
#define STR(s)      _STR(s)                 // 转换宏
#define _CONS(a,b)  int(a##e##b)
#define CONS(a,b)   _CONS(a,b)       // 转换宏

printf(int max: %sn, STR(INT_MAX));          // INT_MAX，int型的最大值，为一个变量 ＃include<climits>
输出为: int max: 0x7fffffff
STR(INT_MAX) –>  _STR(0x7fffffff) 然后再转换成字符串；

printf(%dn, CONS(A, A));
输出为：200
CONS(A, A)  –>  _CONS((2), (2))  –> int((2)e(2))

三、’#'和’##’的一些应用特例
1、合并匿名变量名
#define  __ANONYMOUS1(type, var, line)  type  var##line
#define  _ANONYMOUS0(type, line)  __ANONYMOUS1(type, _anonymous, line)
#define  ANONYMOUS(type)  _ANONYMOUS0(type, __LINE__)
例：ANONYMOUS(static int);  即: static int _anonymous70;  70表示该行行号；
第一层：ANONYMOUS(static int);  –>  __ANONYMOUS0(static int, __LINE__);
第二层：–>  ___ANONYMOUS1(static int, _anonymous, 70);
第三层：–>  static int  _anonymous70;
即每次只能解开当前层的宏，所以__LINE__在第二层才能被解开；

2、填充结构
#define  FILL(a)   {a, #a}

enum IDD{OPEN, CLOSE};
typedef struct MSG{
IDD id;
const char * msg;
}MSG;

MSG _msg[] = {FILL(OPEN), FILL(CLOSE)};
相当于：
MSG _msg[] = {{OPEN, “OPEN”},
{CLOSE, ”CLOSE“}};

3、记录文件名
#define  _GET_FILE_NAME(f)   #f
#define  GET_FILE_NAME(f)    _GET_FILE_NAME(f)
static char  FILE_NAME[] = GET_FILE_NAME(__FILE__);

4、得到一个数值类型所对应的字符串缓冲大小
#define  _TYPE_BUF_SIZE(type)  sizeof #type
#define  TYPE_BUF_SIZE(type)   _TYPE_BUF_SIZE(type)
char  buf[TYPE_BUF_SIZE(INT_MAX)];
–>  char  buf[_TYPE_BUF_SIZE(0x7fffffff)];
–>  char  buf[sizeof 0x7fffffff];
这里相当于：
char  buf[11];

*/
/********************************************************************************
                                global definition
********************************************************************************/
#define NULL (void*)(0)
typedef long size_t;

class Base
{
public:
    const long NULL  = (void*)(0);

};



/********************************************************************************
                                <assert.h>
********************************************************************************/

// The assert header is used for debugging purposes.
// Macros:
// assert();
// External References:
// NDEBUG


// The assert macro allows diagnostic information to be written to the standard error file.
// If expression evaluates to 0 (false), then the expression, sourcecode filename, and line number are sent
// to the standard error, and then calls the abort function. If the identifier NDEBUG ("no debug") is defined
// with #define NDEBUG then the macro assert does nothing.
// Common error outputting is in the form:
// Assertion failed: expression, file filename, line line-number
/*
Example:
    #include<assert.h>
    void open_record(char *record_name)
    {
        assert(record_name!=NULL);
    // Rest of code
    }
    int main(void)
    {
        open_record(NULL);
    }
*/
void assert(int expression);
class h_assert:Base
{
public:
    void assert(int expression);
};



/********************************************************************************
                                <ctype.h>
********************************************************************************/


/*
The ctype header is used for testing and converting characters. A control character refers to a character
that is not part of the normal printing set. In the ASCII character set, the control characters are the
characters from 0 (NUL) through 0x1F (US), and the character 0x7F (DEL). Printable characters are
those from 0x20 (space) to 0x7E (tilde).


2.2.1 is... Functions

The is... functions test the given character and return a nonzero (true) result if it satisfies the following
conditions. If not, then 0 (false) is returned.
Conditions:
isalnum a letter (A to Z or a to z) or a digit (0 to 9)
isalpha a letter (A to Z or a to z)
iscntrl any control character (0x00 to 0x1F or 0x7F)
isdigit a digit (0 to 9)
isgraph any printing character except for the space character (0x21 to 0x7E)
islower a lowercase letter (a to z)
isprint any printing character (0x20 to 0x7E)
ispunct any punctuation character (any printing character except for space character or isalnum)
isspace a whitespace character (space, tab, carriage return, new line, vertical tab, or formfeed)
isupper an uppercase letter (A to Z)
isxdigit a hexadecimal digit (0 to 9, A to F, or a to f)
*/

int isalnum(int character);
int isalpha(int character);
int iscntrl(int character);
int isdigit(int character);
int isgraph(int character);
int islower(int character);
int isprint(int character);
int ispunct(int character);
int isspace(int character);
int isupper(int character);
int isxdigit(int character);



/*
///2.2.2 to... Functions

Example:
#include<ctype.h>
#include<stdio.h>
#include<string.h>
int main(void)
{
    int loop;
    char string[]="THIS IS A TEST";
    for(loop=0;loop<strlen(string);loop++)
    string[loop]=tolower(string[loop]);
    printf("%s\n",string);
    return 0;
}*/

// The to... functions provide a means to convert a single character. If the character matches the appropriate
// condition, then it is converted. Otherwise the character is returned unchanged.
// Conditions:
// tolower If the character is an uppercase character (A to Z), then it is converted to lowercase (a to z)
// toupper If the character is a lowercase character (a to z), then it is converted to uppercase (A to Z)
int tolower(int character);
int toupper(int character);


class h_ctype:Base
{
public:
    int isalnum(int character);
    int isalpha(int character);
    int iscntrl(int character);
    int isdigit(int character);
    int isgraph(int character);
    int islower(int character);
    int isprint(int character);
    int ispunct(int character);
    int isspace(int character);
    int isupper(int character);
    int isxdigit(int character);
    int tolower(int character);
    int toupper(int character);
};



/********************************************************************************
                                <errno.h>
********************************************************************************/
// The errno header is used as a general error handler.
// Macros:
// EDOM
// ERANGE
// Variables:
// errno

// EDOM is an identifier macro declared with #define. Its value represents a domain error which is
// returned by some math functions when a domain error occurs.
#define EDOM (0)


// ERANGE is an identifier macro declared with #define. Its value represents a range error which is
// returned by some math functions when a range error occurs.
#define ERANGE (1)

// The errno variable has a value of zero at the beginning of the program. If an error occurs, then this
// variable is given the value of the error number.
extern int errno;

class h_errno:Base
{
public:
    const int EDOM = EDOM;
    const int ERANGE = ERANGE;
    int errno;
};



/********************************************************************************
                                <float.h>
********************************************************************************/
/**
// A floating-point number is defined in the following manner:
 sign value E exponent
 Where sign is plus or minus, 
 value is the value of the number, 
 and exponent is the value of the exponent.
 The following values are defined with the #define directive. 
 These values are implementationspecific, but may not be any lower than what is given here.
 Note that in all instances 
 FLT refers to typefloat, 
 DBL refers to double, 
 LDBL refers to long double.
 
C 标准库的 float.h 头文件包含了一组与浮点值相关的依赖于平台的常量。
这些常量是由 ANSI C 提出的，这让程序更具有可移植性。在讲解这些常量之前，
最好先弄清楚浮点数是由下面四个元素组成的：
组件  组件描述
S   符号 ( +/- )
b   指数表示的基数，2 表示二进制，10 表示十进制，16 表示十六进制，等等...
e   指数，一个介于最小值 emin 和最大值 emax 之间的整数。
p   精度，基数 b 的有效位数

基于以上 4 个组成部分，一个浮点数的值如下：
floating-point = ( S ) p x be
或
floating-point = (+/-) precision x baseexponent

下面的值是特定实现的，且是通过 #define 指令来定义的，这些值都不得低于下边所给出的值。
请注意，所有的实例 
FLT 是指类型 float，
DBL 是指类型 double，
LDBL 是指类型 long double。
sample:
#include <stdio.h>
#include <float.h>

int main () {
  printf("float:\n" );
    printf("FLT_DIG = %d\n",FLT_DIG );
    printf("FLT_EPSILON = %.10e\n",FLT_EPSILON );
    printf("FLT_MANT_DIG = %.10e\n",FLT_MANT_DIG );
    // printf("FLT_RADIX = %d\n",FLT_RADIX );
    // printf("FLT_ROUNDS = %d\n",FLT_ROUNDS );
    printf("FLT_MAX = %.10e\n",FLT_MAX );
    printf("FLT_MIN = %.10e\n",FLT_MIN );
    printf("FLT_MAX_10_EXP = %.10e\n",FLT_MAX_10_EXP );
    printf("FLT_MIN_10_EXP = %.10e\n",FLT_MIN_10_EXP );
    printf("FLT_MAX_EXP = %.10e\n",FLT_MAX_EXP );
    printf("FLT_MIN_EXP = %.10e\n",FLT_MIN_EXP );
  
    printf("double:\n" );
    printf("DBL_DIG = %d\n",DBL_DIG );
    printf("DBL_EPSILON = %.10e\n",DBL_EPSILON );
    printf("DBL_MANT_DIG = %.10e\n",DBL_MANT_DIG );
    printf("DBL_MAX = %.10e\n",DBL_MAX );
    printf("DBL_MIN = %.10e\n",DBL_MIN );
    printf("DBL_MAX_10_EXP = %.10e\n",DBL_MAX_10_EXP );
    printf("DBL_MIN_10_EXP = %.10e\n",DBL_MIN_10_EXP );
    printf("DBL_MAX_EXP = %.10e\n",DBL_MAX_EXP );
    printf("DBL_MIN_EXP = %.10e\n",DBL_MIN_EXP );
  
    printf("long double:\n" );
    printf("LDBL_DIG = %d\n",LDBL_DIG );
    printf("LDBL_EPSILON = %.10e\n",LDBL_EPSILON );
    printf("LDBL_MANT_DIG = %.10e\n",LDBL_MANT_DIG );
    printf("LDBL_MAX = %.e\n",LDBL_MAX );
    printf("LDBL_MIN = %.e\n",LDBL_MIN );
    printf("LDBL_MAX_10_EXP = %.10e\n",LDBL_MAX_10_EXP );
    printf("LDBL_MIN_10_EXP = %.10e\n",LDBL_MIN_10_EXP );
    printf("LDBL_MAX_EXP = %.10e\n",LDBL_MAX_EXP );
    printf("LDBL_MIN_EXP = %.10e\n",LDBL_MIN_EXP );
    
    return 0;
}


**/

//float

#define FLT_DIG      (6)  //float小数点后面精确的位数
#define FLT_EPSILON  1.19209290E-07F //小的正数,float的0跨度值
#define FLT_MANT_DIG 24 //尾数中的位数
#define FLT_RADIX    (2) //进制基数

//Defines the way floating-point numbers are rounded.
//-1 indeterminable
// 0 toward zero
// 1 to nearest
// 2 toward positive infinity
// 3 toward negative infinity

#define FLT_ROUNDS      //加法舍入
#define FLT_MAX         //最大值
#define FLT_MIN         //最小值
#define FLT_MAX_10_EXP  //最大10进制指数
#define FLT_MIN_10_EXP  //最小10进制指数
#define FLT_MAX_EXP     //最大2进制指数 基于FLT_RADIX
#define FLT_MIN_EXP     //最小2进制指数 基于FLT_RADIX



//double
#define DBL_DIG         //double 小数点后面精确的位数
#define DBL_EPSILON     //小的正数 ,double的0跨度值
#define DBL_MANT_DIG    //尾数中的位数
#define DBL_MAX         //最大值
#define DBL_MAX_10_EXP  //最大10进制指数
#define DBL_MAX_EXP     //最大2进制指数
#define DBL_MIN         //最小值
#define DBL_MIN_10_EXP  //最小10进制指数
#define DBL_MIN_EXP     //最小2进制指数

//long double
#define LDBL_DIG         //long double小数点后面精确的位数
#define LDBL_EPSILON     //小的正数,long double的0跨度值
#define LDBL_MANT_DIG    //尾数中的位数

#define LDBL_MAX         //最大值
#define LDBL_MIN         //最小值
#define LDBL_MAX_10_EXP  //最大10进制指数
#define LDBL_MIN_10_EXP  //最小10进制指数
#define LDBL_MAX_EXP     //最大2进制指数
#define LDBL_MIN_EXP     //最小2进制指数
 
class h_float:Base
{
public:
const int    FLT_RADIX ; 
const int    FLT_ROUNDS; 
const int    FLT_DIG; 
const int    FLT_MANT_DIG; 
const float  FLT_EPSILON;
const float  FLT_MAX;     
const float  FLT_MIN;      
const float  FLT_MAX_10_EXP ;
const float  FLT_MIN_10_EXP;
const float  FLT_MAX_EXP;
const float  FLT_MIN_EXP;
        
//double
const int     DBL_DIG ;
const int     DBL_MANT_DIG;
const double  DBL_EPSILON;
const double  DBL_MAX;
const double  DBL_MAX_10_EXP;
const double  DBL_MAX_EXP;
const double  DBL_MIN;
const double  DBL_MIN_10_EXP;
const double  DBL_MIN_EXP;
    
//long double
const int          LDBL_DIG;
const int          LDBL_MANT_DIG;
const long double  LDBL_EPSILON;

const long double  LDBL_MAX;
const long double  LDBL_MIN ;       
const long double  LDBL_MAX_10_EXP;
const long double  LDBL_MIN_10_EXP;
const long double  LDBL_MAX_EXP;
const long double  LDBL_MIN_EXP;

};

/********************************************************************************
                                <limits.h>
********************************************************************************/
// The limits header defines the characteristics of variable types.

#define CHAR_BIT    8           //定义一个字节的比特数。
#define SCHAR_MIN   -128        //定义一个有符号字符的最小值。
#define SCHAR_MAX   127         //定义一个有符号字符的最大值。
#define UCHAR_MAX   255         //定义一个无符号字符的最大值。
#define CHAR_MIN    0           //定义类型 char 的最小值，如果 char 表示负值，则它的值等于 SCHAR_MIN，否则等于 0。
#define CHAR_MAX    127         //定义类型 char 的最大值，如果 char 表示负值，则它的值等于 SCHAR_MAX，否则等于 UCHAR_MAX。
#define MB_LEN_MAX  1           //定义多字节字符中的最大字节数。
#define SHRT_MIN    -32768      //定义一个短整型的最小值。
#define SHRT_MAX    +32767      //定义一个短整型的最大值。
#define USHRT_MAX   65535       //定义一个无符号短整型的最大值。
#define INT_MIN    -32768       //定义一个整型的最小值。
#define INT_MAX    +32767       //定义一个整型的最大值。
#define UINT_MAX    65535       //定义一个无符号整型的最大值。
#define LONG_MIN    -2147483648 //定义一个长整型的最小值。
#define LONG_MAX    +2147483647 //定义一个长整型的最大值。
#define ULONG_MAX   4294967295  //定义一个无符号长整型的最大值。

class h_limits:Base
{
public:
const int  CHAR_BIT;    
const int  SCHAR_MIN;   
const int  SCHAR_MAX;   
const int  UCHAR_MAX;   
const int  CHAR_MIN ;
const int  CHAR_MAX;    
const int  MB_LEN_MAX;  
const int  SHRT_MIN;    
const int  SHRT_MAX;    
const int  USHRT_MAX;
const int  INT_MIN  ;  
const int  INT_MAX;   
const unsigned int  UINT_MAX;   
const long  LONG_MIN;   
const long  LONG_MAX;   
const unsigned long   ULONG_MAX;
};

/********************************************************************************
                                <locale.h>
********************************************************************************/
// The locale header is useful for setting location specific information.
// Variables:
// struct lconv
// Macros:
// NULL
// LC_ALL
// LC_COLLATE
// LC_CTYPE
// LC_MONETARY
// LC_NUMERIC
// LC_TIME

#define LC_ALL        //设置下面的所有选项。
#define LC_COLLATE    //影响 strcoll 和 strxfrm 函数。
#define LC_CTYPE      //影响所有字符函数。
#define LC_MONETARY   //影响 localeconv 函数提供的货币信息。
#define LC_NUMERIC    //影响 localeconv 函数提供的小数点格式化和信息。
#define LC_TIME       //影响 strftime 函数。



// Functions:
// localeconv();
// setlocale();
// 2.6.1 Variables and Definitions
// The lconv structure contains the following variables in any order. The use of this structure is described
// in 2.6.3 localeconv.
// char *decimal_point;
// char *thousands_sep;
// char *grouping;
// char *int_curr_symbol;
// char *currency_symbol;
// char *mon_decimal_point;
// char *mon_thousands_sep;
// char *mon_grouping;
// char *positive_sign;
// char *negative_sign;
// char int_frac_digits;
// char frac_digits;
// char p_cs_precedes;
// char p_sep_by_space;
// char n_cs_precedes;
// char n_sep_by_space;
// char p_sign_posn;
// char n_sign_posn;
// The LC_ macros are described in 2.6.2 setlocale. NULL is the value of a null pointer constant.
typedef struct {
   char *decimal_point;
   char *thousands_sep;
   char *grouping;    
   char *int_curr_symbol;
   char *currency_symbol;
   char *mon_decimal_point;
   char *mon_thousands_sep;
   char *mon_grouping;
   char *positive_sign;
   char *negative_sign;
   char int_frac_digits;
   char frac_digits;
   char p_cs_precedes;
   char p_sep_by_space;
   char n_cs_precedes;
   char n_sep_by_space;
   char p_sign_posn;
   char n_sign_posn;
} lconv;



// Sets or reads location dependent information.
// category can be one of the following:
// LC_ALL Set everything.
// LC_COLLATE Affects strcoll and strxfrm functions.
// LC_CTYPE Affects all character functions.
// LC_MONETARY Affects the monetary information provided by localeconv function.
// LC_NUMERIC Affects decimal-point formatting and the information provided by function. localeconv
// LC_TIME Affects the strftime function.
// A value of "C" for locale sets the locale to the normal C translation environment settings (default). A
// null value ("") sets the native environment settings. A null pointer (NULL) causes setlocale to return a
// pointer to the string associated with this category for the current settings (no changes occur). All other
// values are implementation-specific.
// After a successful set, setlocale returns a pointer to a string which represents the previous location
// setting. On failure it returns NULL.
/*
Example:
#include<locale.h>
#include<stdio.h>
int main(void)
{
    char *old_locale;
    old_locale=setlocale(LC_ALL,"C");
    printf("The preivous setting was %s.\n",old_locale);
    return 0;
}*/
char *setlocale(int category, const char *locale);


struct lconv *localeconv(void);
/*
Sets the structure lconv to represent the current location settings.
The string pointers in the structure may point to a null string ("") which indicates that the value is not
available. The char types are nonnegative numbers. If the value is CHAR_MAX, then the value is not
available.
lconv variables:
char *decimal_point Decimal point character used for non-monetary values.
char *thousands_sep Thousands place separator character used for non-monetary values.
char *grouping
A string that indicates the size of each group of digits in nonmonetary quantities. Each character represents an integer value
which designates the number of digits in the current group. A value
of 0 means that the previous value is to be used for the rest of the
groups.
char *int_curr_symbol
A string of the international currency symbols used. The first three
characters are those specified by ISO 4217:1987 and the fourth is
the character which separates the currency symbol from the
monetary quantity.
char *currency_symbol The local symbol used for currency.

char *mon_decimal_point The decimal point character used for monetary values.
char *mon_thousands_sep The thousands place grouping character used for monetary values.
char *mon_grouping
A string whose elements define the size of the grouping of digits in
monetary values. Each character represents an integer value which
designates the number of digits in the current group. A value of 0
means that the previous value is to be used for the rest of the groups.
char *positive_sign The character used for positive monetary values.
char *negative_sign The character used for negative monetary values.
char int_frac_digits Number of digits to show after the decimal point in international
monetary values.
char frac_digits Number of digits to show after the decimal point in monetary values.
char p_cs_precedes
If equal to 1, then the currency_symbol appears before a
positive monetary value. If equal to 0, then the
currency_symbol appears after a positive monetary value.
char p_sep_by_space
If equal to 1, then the currency_symbol is separated by a space
from a positive monetary value. If equal to 0, then there is no space
between the currency_symbol and a positive monetary value.
char n_cs_precedes
If equal to 1, then the currency_symbol precedes a negative
monetary value. If equal to 0, then the currency_symbol
succeeds a negative monetary value.
char n_sep_by_space
If equal to 1, then the currency_symbol is separated by a space
from a negative monetary value. If equal to 0, then there is no space
between the currency_symbol and a negative monetary value.
char p_sign_posn Represents the position of the positive_sign in a positive
monetary value.
char n_sign_posn Represents the position of the negative_sign in a negative
monetary value.
The following values are used for p_sign_posn and n_sign_posn:
0 Parentheses encapsulate the value and the currency_symbol.
1 The sign precedes the value and currency_symbol.
2 The sign succeeds the value and currency_symbol.
3 The sign immediately precedes the value and currency_symbol.
4 The sign immediately succeeds the value and currency_symbol.
*/

/*
Example:
#include<locale.h>
#include<stdio.h>
int main(void)
{
    struct lconv locale_structure;
    struct lconv *locale_ptr=&locale_structure;
    locale_ptr=lcoaleconv();
    printf("Decimal point: %s",locale_ptr->decimal_point);
    printf("Thousands Separator: %s",locale_ptr->thousands_sep);
    printf("Grouping: %s",locale_ptr->grouping);
    printf("International Currency Symbol: %s",locale_ptr->int_curr_symbol);
    printf("Currency Symbol: %s",locale_ptr->currency_symbol);
    printf("Monetary Decimal Point: %s",locale_ptr->mon_decimal_point);
    printf("Monetary Thousands Separator: %s",locale_ptr->mon_thousands_sep);
    printf("Monetary Grouping: %s",locale_ptr->mon_grouping);
    printf("Monetary Positive Sign: %s",locale_ptr->positive_sign);
    printf("Monetary Negative Sign: %s",locale_ptr->negative_sign);
    printf("Monetary Intl Decimal Digits: %c",locale_ptr->int_frac_digits);
    printf("Monetary Decimal Digits: %c",locale_ptr->frac_digits);
    printf("Monetary + Precedes: %c",locale_ptr->p_cs_precedes);
    printf("Monetary + Space: %c",locale_ptr->p_sep_by_space);
    printf("Monetary - Precedes: %c",locale_ptr->n_cs_precedes);
    printf("Monetary - Space: %c",locale_ptr->n_sep_by_space);
    printf("Monetary + Sign Posn: %c",locale_ptr->p_sign_posn);
    printf("Monetary - Sign Posn: %c",locale_ptr->n_sign_posn);
}
*/
class h_locale:Base
{
public:
    const int LC_ALL;      
    const int LC_COLLATE;  
    const int LC_CTYPE;    
    const int LC_MONETARY;
    const int LC_NUMERIC;  
    const int LC_TIME;     
    
public:
    char *setlocale(int category, const char *locale);
    struct lconv *localeconv(void);

};


/********************************************************************************
                                <math.h>
********************************************************************************/
// 2.7 math.h
// The math header defines several mathematic functions.
// Macros:
// HUGE_VAL

// 2.7.1 Error Conditions
// All math.h functions handle errors similarly.
// In the case that the argument passed to the function exceeds the range of that function, then the variable
// errno is set to EDOM. The value that the function returns is implementation specific.
// In the case that the value being returned is too large to be represented in a double, then the function
// returns the macro HUGE_VAL, and sets the variable errno to ERANGE to represent an overflow. If the
// value is too small to be represented in a double, then the function returns zero. In this case whether or
// not errno is set to ERANGE is implementation specific.
// errno, EDOM, and ERANGE are defined in the errno.h header.
// Note that in all cases when it is stated that there is no range limit, it is implied that the value is limited by
// the minimum and maximum values of type double.

//////////////////////////2.7.2 Trigonometric Functions////////////////////////

// Returns the arc cosine of x in radians.
// Range:
// The value x must be within the range of -1 to +1 (inclusive). The returned value is in the
// range of 0 to pi (inclusive).
double acos(double x);


// Returns the arc sine of x in radians.
// Range:
// The value of x must be within the range of -1 to +1 (inclusive). The returned value is in
// the range of -p/2 to +p/2 (inclusive).
double asin(double x);

// Returns the arc tangent of x in radians.
// Range:
// The value of x has no range. The returned value is in the range of -p/2 to +p/2 (inclusive).
double atan(double x);

// Returns the arc tangent in radians of y/x based on the signs of both values to determine the
// correct quadrant.
// Range:
// Both y and x cannot be zero. The returned value is in the range of -p/2 to +p/2 (inclusive).
double atan2(double y, double x);

// Returns the cosine of a radian angle x.
// Range:
// The value of x has no range. The returned value is in the range of -1 to +1 (inclusive).
double cos(double x);

// Returns the hyperbolic cosine of x.
// Range:
// There is no range limit on the argument or return value.
double cosh(double x);

// Returns the sine of a radian angle x.
// Range:
// The value of x has no range. The returned value is in the range of -1 to +1 (inclusive).
double sin(double x);

// Returns the hyperbolic sine of x.
// Range:
// There is no range limit on the argument or return value.
double sinh(double x);

// Returns the tangent of a radian angle x.
// Range:
// There is no range limit on the argument or return value.
double tan(double x);

// Returns the hyperbolic tangent of x.
// Range:
// The value of x has no range. The returned value is in the range of -1 to +1 (inclusive).
// 2.7.3 Exponential, Logarithmic, and Power Functions
double tanh(double x);

// Returns the value of e raised to the xth power.
// Range:
// There is no range limit on the argument or return value.
double exp(double x);

// The floating-point number x is broken up into a mantissa and exponent.
// The returned value is the mantissa and the integer pointed to by exponent is the exponent.
// The resultant value is x=mantissa * 2^exponent.
// Range:
// The mantissa is in the range of .5 (inclusive) to 1 (exclusive).
double frexp(double x, int *exponent);

// Returns x multiplied by 2 raised to the power of exponent.
// x*2^exponent
// Range:
// There is no range limit on the argument or return value.
double ldexp(double x, int exponent);

// Returns the natural logarithm (base-e logarithm) of x.
// Range:
// There is no range limit on the argument or return value.
double log(double x);

// Returns the common logarithm (base-10 logarithm) of x.
// Range:
// There is no range limit on the argument or return value.
double log10(double x);

// Breaks the floating-point number x into integer and fraction components.
// The returned value is the fraction component (part after the decimal), and sets integer to
// the integer component.
// Range:
// There is no range limit on the argument or return value.
double modf(double x, double *integer);

// Returns x raised to the power of y.
// Range:
// x cannot be negative if y is a fractional value. x cannot be zero if y is less than or equal to
// zero.
double pow(double x, double y);

// Returns the square root of x.
// Range:
// The argument cannot be negative. The returned value is always positive.
double sqrt(double x);

//////////////////2.7.4 Other Math Functions//////////////////

// Returns the smallest integer value greater than or equal to x.
// Range:
// There is no range limit on the argument or return value.
double ceil(double x);


// Returns the absolute value of x (a negative value becomes positive, positive value is
// unchanged).
// Range:
// There is no range limit on the argument. The return value is always positive.
double fabs(double x);

// Returns the largest integer value less than or equal to x.
// Range:
// There is no range limit on the argument or return value.
double floor(double x);

// Returns the remainder of x divided by y.
// Range:
// There is no range limit on the return value. If y is zero, then either a range error will occur
// or the function will return zero (implementation-defined).
double fmod(double x, double y);
class h_math:Base
{
public:
    double acos(double x);
    double asin(double x);
    double atan(double x);
    double atan2(double y, double x);

    double cos(double x);
    double cosh(double x);
    double sin(double x);
    double sinh(double x);
    double tan(double x);
    double tanh(double x);
    double exp(double x);
    double frexp(double x, int *exponent);
    double ldexp(double x, int exponent);
    double log(double x);
    double log10(double x);
    double modf(double x, double *integer);
    double pow(double x, double y);
    double sqrt(double x);

    double ceil(double x);
    double fabs(double x);
    double floor(double x);
    double fmod(double x, double y);
};



/********************************************************************************
 // TODO:                               <setjmp.h>
********************************************************************************/
// The setjmp header is used for controlling low-level calls and returns to and from functions.

typedef  char[] jmp_buf;
// Saves the environment into the variable environment. If a non-zero value is returned, then this indicates
// that the point in the sourcecode was reached by a longjmp. Otherwise zero is returned indicating the
// environment has been saved.
int setjmp(jmp_buf environment);

// Causes the environment to be restored from a setjmp call where the environment variable had been
// saved. It causes execution to goto the setjmp location as if setjmp had returned the value of the
// variable value. The variable value cannot be zero. However, if zero is passed, then 1 is replaced. If the
// function where setjmp was called has terminated, then the results are undefined.
void longjmp(jmp_buf environment, int value);


/*
Example:
#include<setjmp.h>
#include<stdio.h>
void some_function(jmp_buf env_buf)
{
    longjmp(env_buf,5);
}
int main(void)
{
    int value;
    jmp_buf environment_buffer;
    value=setjmp(environment_buffer);
    if(value!=0)
    {
        printf("Reached this point from a longjmp with value=%d.
        \n",value);
        exit(0);
    }
    printf("Calling function.\n");
    some_function(environment_buffer);
    return 0;
}

The output from this program should be
Calling function.
Reached this point from a longjmp with value=5.

*/
class h_setjmp:Base
{
public:
    int setjmp(jmp_buf environment);
    void longjmp(jmp_buf environment, int value);
};

/********************************************************************************
                                <signal.h>
********************************************************************************/
// The signal header provides a means to handle signals reported during a program's execution.
// Macros:

#define SIG_DFL //默认的信号处理程序。
#define SIG_ERR //表示一个信号错误。
#define SIG_IGN //忽视信号。

#define SIGABRT //异常终止，如调用abort()。
#define SIGFPE  //算术运算出错，如除数为0或溢出。
#define SIGILL  //非法函数映象，如非法指令。
#define SIGINT  //交互式信号，如中断。
#define SIGSEGV //非法访问存储器，如访问不存在的内存单元。
#define SIGTERM //发送给本程序的终止请求信号。



 typedef int sig_atomic_t;
// The sig_atomic_t type is of type int and is used as a variable in a signal handler. The SIG_
// macros are used with the signal function to define signal functions.

// SIG_DFL Default handler.
// SIG_ERR Represents a signal error.
// SIG_IGN Signal ignore.
// The SIG macros are used to represent a signal number in the following conditions:
// SIGABRT Abnormal termination (generated by the abort function).
// SIGFPE Floating-point error (error caused by division by zero, invalid operation,etc.).
// SIGILL Illegal operation (instruction).
// SIGINT Interactive attention signal (such as ctrl-C).
// SIGSEGV Invalid access to storage (segment violation, memory violation).
// SIGTERM Termination request.


// Controls how a signal is handled. sig represents the signal number compatible with the SIG macros.
// func is the function to be called when the signal occurs. If func is SIG_DFL, then the default handler is
// called. If func is SIG_IGN, then the signal is ignored. If func points to a function, then when a signal is
// detected the default function is called (SIG_DFL), then the function is called. The function must take
// one argument of type int which represents the signal number. The function may terminate with
// return, abort, exit, or longjmp. When the function terminates execution resumes where it was
// interrupted (unless it was a SIGFPE signal in which case the result is undefined).
// If the call to signal is successful, then it returns a pointer to the previous signal handler for the specified
// signal type. If the call fails, then SIG_ERR is returned and errno is set appropriately.
void (*signal(int sig, void (*func)(int)))(int);

// Causes signal sig to be generated. The sig argument is compatible with the SIG macros.
// If the call is successful, zero is returned. Otherwise a nonzero value is returned.
int raise(int sig);
/*
Example:
#include<signal.h>
#include<stdio.h>
void catch_function(int);
int main(void)
{
    if(signal(SIGINT, catch_function)==SIG_ERR)
    {
        printf("An error occured while setting a signal handler.\n");
        exit(0);
    }
    printf("Raising the interactive attention signal.\n");
    if(raise(SIGINT)!=0)
    {
        printf("Error raising the signal.\n");
        exit(0);
    }
    printf("Exiting.\n");
    return 0;
}
void catch_function(int signal)
{
    printf("Interactive attention signal caught.\n");
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
void sighandler(int signum)
{
    printf("Catch a signal num is %d ...\n", signum);
    exit(1);
}

int main()
{
    signal(SIGINT, sighandler);
    signal(SIGINT, sighandler);
    while(1)
    {
        printf("start sleeping!\n");
        sleep(1);//unit is second
    }
    return 0;
}

The output from the program should be (assuming no errors):
Raising the interactive attention signal.
Interactive attention signal caught.
Exiting
*/
class h_signal:Base
{
public:
	const int SIG_DFL;
	const int SIG_ERR;
	const int SIG_IGN;
	const int SIGABRT;
	const int SIGFPE;
	const int SIGILL;
	const int SIGINT;
	const int SIGSEGV;
	const int SIGTERM;

public:
	void (*signal(int sig, void (*func)(int)))(int);
	int raise(int sig);
};


/********************************************************************************
                                <stdarg.h>
********************************************************************************/
// The stdarg header defines several macros used to get the arguments in a function when the number of
// arguments is not known.
// Macros:
// va_start();
// va_arg();
// va_end();

 typedef struct{
 }va_list;
// The va_list type is a type suitable for use in accessing the arguments of a function with the stdarg
// macros.
// A function of variable arguments is defined with the ellipsis (,...) at the end of the parameter list.

//这个宏初始化 ap 变量，它与 va_arg 和 va_end 宏是一起使用的。
//last_arg 是最后一个传递给函数的已知的固定参数，即省略号之前的参数。
void va_start(va_list ap, last_arg);
//这个宏检索函数参数列表中类型为 type 的下一个参数。
type va_arg(va_list ap, type);

//这个宏允许使用了 va_start 宏的带有可变参数的函数返回。
//如果在从函数返回之前没有调用 va_end，则结果为未定义。
void va_end(va_list ap);

/*
Example:
#include<stdarg.h>
#include<stdio.h>
void sum(char *, int, ...);
int main(void)
{
    sum("The sum of 10+15+13 is %d.\n",3,10,15,13);
    return 0;
}
void sum(char *string, int num_args, ...)
{
    int sum=0;
    va_list ap;
    int loop;
    va_start(ap,num_args);
    for(loop=0;loop<num_args;loop++)
        sum+=va_arg(ap,int);

    printf(string,sum);
    va_end(ap);
}
*/
class h_stdarg:Base
{
    void va_start(va_list ap, last_arg);
    type va_arg(va_list ap, type);
    void va_end(va_list ap);

}

/********************************************************************************
                                <stddef.h>
********************************************************************************/
// The stddef header defines several standard definitions. Many of these definitions also appear in other
// headers.
// Macros:
// NULL
// offsetof();
// Variables:
 typedef ptrdiff_t;
 typedef wchar_t;

// ptrdiff_t is the result of subtracting two pointers.
// size_t is the unsigned integer result of the sizeof keyword.
// wchar_t is an integer type of the size of a wide character constant.

//NULL is the value of a null pointer constant.

#define  offsetof(type, member-designator)

// This results in a constant integer of type size_t which is the offset in bytes of a structure member
// from the beginning of the structure. The member is given by member-designator, and the name of the
// structure is given in type.
/*
Example:
#include<stddef.h>
#include<stdio.h>
int main(void)
{
    struct user{
        char name[50];
        char alias[50];
        int level;
    };
    printf("level is the %d byte in the user structure.\n"),
    offsetof(struct user,level));
}

The output should be:
level is the 100 byte in the user structure
*/
class h_stddef:Base
{
public:
	const int offsetof;
	
};


/********************************************************************************
                                <stdio.h>
********************************************************************************/
// The stdio header provides functions for performing input and output.
// Macros:
// NULL
// _IOFBF
// _IOLBF
// _IONBF
// BUFSIZ
// EOF
// FOPEN_MAX
// FILENAME_MAX
// L_tmpnam
// SEEK_CUR
// SEEK_END
// SEEK_SET
// TMP_MAX
// stderr
// stdin
// stdout

// ftell();
// fwrite();
// remove();
// rename();
// rewind();
// setbuf();
// setvbuf();
// tmpfile();
// tmpnam();
// fprintf();
// fscanf();
// printf();
// scanf();
// sprintf();
// sscanf();
// vfprintf();
// vprintf();
// vsprintf();
// fgetc();
// fgets();
// fputc();
// fputs();
// getc();
// getchar();
// gets();
// putc();
// putchar();
// puts();
// ungetc();
// perror();


// Variables:
// typedef size_t
// typedef FILE
// typedef fpos_t
/*
size_t is the unsigned integer result of the sizeof keyword.
FILE is a type suitable for storing information for a file stream.
fpos_t is a type suitable for storing any position in a file.
NULL is the value of a null pointer constant.
_IOFBF, _IOLBF, and _IONBF are used in the setvbuf function.
BUFSIZ is an integer which represents the size of the buffer used by the setbuf function.
EOF is a negative integer which indicates an end-of-file has been reached.
FOPEN_MAX is an integer which represents the maximum number of files that the system
can guarantee that can be opened simultaneously.
FILENAME_MAX is an integer which represents the longest length of a char array suitable
for holding the longest possible filename. If the implementation imposes no limit, then
this value should be the recommended maximum value.
L_tmpnam is an integer which represents the longest length of a char array suitable for
holding the longest possible temporary filename created by the tmpnam function.
SEEK_CUR, SEEK_END, and SEEK_SET are used in the fseek function.
TMP_MAX is the maximum number of unique filenames that the function tmpnam can
generate.
stderr, stdin, and stdout are pointers to FILE types which correspond to the
standard error, standard input, and standard output streams.
*/
typedef long FILE;

typedef long int fpos_t;
// fseek 3th arg using
#define SEEK_CUR  (0)
#define SEEK_END  (-1)
#define SEEK_SET  (1)

#define stdin   (FILE*)(0)
#define stdout   (FILE*)(1)
#define stderr   (FILE*)(2)

//2.12.2 Streams and Files
/*
Streams facilitate a way to create a level of abstraction between the program and an input/output device.
This allows a common method of sending and receiving data amongst the various types of devices
available. There are two types of streams: text and binary.
Text streams are composed of lines. Each line has zero or more characters and are terminated by a newline character which is the last character in a line. Conversions may occur on text streams during input
and output. Text streams consist of only printable characters, the tab character, and the new-line
character. Spaces cannot appear before a newline character, although it is implementation-defined
whether or not reading a text stream removes these spaces. An implementation must support lines of up
to at least 254 characters including the new-line character.
Binary streams input and output data in an exactly 1:1 ratio. No conversion exists and all characters may
be transferred.
When a program begins, there are already three available streams: standard input, standard output, and
standard error.
Files are associated with streams and must be opened to be used. The point of I/O within a file is
determined by the file position. When a file is opened, the file position points to the beginning of the file
unless the file is opened for an append operation in which case the position points to the end of the file.
The file position follows read and write operations to indicate where the next operation will occur.
When a file is closed, no more actions can be taken on it until it is opened again. Exiting from the main
function causes all open files to be closed.
*/

// Clears the end-of-file and error indicators for the given stream. As long as the error indicator is set, all
// stream operations will return an error until clearerr or rewind is called.
void clearerr(FILE *stream);

// Closes the stream. All buffers are flushed.
// If successful, it returns zero. On error it returns EOF.
int fclose(FILE *stream);

// Tests the end-of-file indicator for the given stream. If the stream is at the end-of-file, then it returns a
// nonzero value. If it is not at the end of the file, then it returns zero.
int feof(FILE *stream);

// Tests the error indicator for the given stream. If the error indicator is set, then it returns a nonzero value.
// If the error indicator is not set, then it returns zero.
int ferror(FILE *stream);

// Flushes the output buffer of a stream. If stream is a null pointer, then all output buffers are flushed.
// If successful, it returns zero. On error it returns EOF.
int fflush(FILE *stream);

// Gets the current file position of the stream and writes it to pos.
// If successful, it returns zero. On error it returns a nonzero value and stores the error number in the
// variable errno.
int fgetpos(FILE *stream, fpos_t *pos);



// Opens the filename pointed to by filename. The mode argument may be one of the following constant
// strings:
// r read text mode
// w write text mode (truncates file to zero length or creates new file)
// a append text mode for writing (opens or creates file and sets file pointer to the end-of-file)
// rb read binary mode
// wb write binary mode (truncates file to zero length or creates new file)
// ab append binary mode for writing (opens or creates file and sets file pointer to the end-offile)
// r+ read and write text mode
// w+ read and write text mode (truncates file to zero length or creates new file)
// a+ read and write text mode (opens or creates file and sets file pointer to the end-of-file)
// r+b or rb+ read and write binary mode
// w+b or wb+ read and write binary mode (truncates file to zero length or creates new file)
// a+b or ab+ read and write binary mode (opens or creates file and sets file pointer to the end-of-file)
// If the file does not exist and it is opened with read mode (r), then the open fails.
// If the file is opened with append mode (a), then all write operations occur at the end of the file
// regardless of the current file position.
// If the file is opened in the update mode (+), then output cannot be directly followed by input and input
// cannot be directly followed by output without an intervening fseek, fsetpos, rewind, or fflush.
// On success a pointer to the file stream is returned. On failure a null pointer is returned.
FILE *fopen(const char *filename, const char *mode);


// Reads data from the given stream into the array pointed to by ptr. It reads nmemb number of elements of
// size size. The total number of bytes read is (size*nmemb).
// On success the number of elements read is returned. On error or end-of-file the total number of elements
// successfully read (which may be zero) is returned.
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);


// Associates a new filename with the given open stream. The old file in stream is closed. If an error occurs
// while closing the file, the error is ignored. The mode argument is the same as described in the fopen
// command. Normally used for reassociating stdin, stdout, or stderr.
// On success the pointer to the stream is returned. On error a null pointer is returned.
FILE *freopen(const char *filename, const char *mode, FILE *stream);


int fseek(FILE *stream, long int offset, int whence);
// Sets the file position of the stream to the given offset.
// The argument offset signifies the number of bytes
// to seek from the given whence position.
// The argument whence can be:
// SEEK_SET Seeks from the beginning of the file.
// SEEK_CUR Seeks from the current position.
// SEEK_END Seeks from the end of the file.
// On a text stream, whence should be SEEK_SET and offset should be either zero or a value returned from
// ftell.
// The end-of-file indicator is reset. The error indicator is NOT reset.
// On success zero is returned. On error a nonzero value is returned.

int fsetpos(FILE *stream, const fpos_t *pos);
// Sets the file position of the given stream to the given position. The argument pos is a position given by
// the function fgetpos. The end-of-file indicator is cleared.
// On success zero is returned. On error a nonzero value is returned and the variable errno is set.

long int ftell(FILE *stream);
// Returns the current file position of the given stream. If it is a binary stream, then the value is the number
// of bytes from the beginning of the file. If it is a text stream, then the value is a value useable by the fseek
// function to return the file position to the current position.
// On success the current file position is returned. On error a value of -1L is returned and errno is set.

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
// Writes data from the array pointed to by ptr to the given stream. It writes nmemb number of elements of
// size size. The total number of bytes written is (size*nmemb).
// On success the number of elements writen is returned. On error the total number of elements
// successfully writen (which may be zero) is returned.

int remove(const char *filename);
// Deletes the given filename so that it is no longer accessible (unlinks the file). If the file is currently open,
// then the result is implementation-defined.
// On success zero is returned. On failure a nonzero value is returned.

int rename(const char *old_filename, const char *new_filename);
// Causes the filename referred to by old_filename to be changed to new_filename. If the filename pointed
// to by new_filename exists, the result is implementation-defined.
// On success zero is returned. On error a nonzero value is returned and the file is still accessible by its old
// filename.

void rewind(FILE *stream);
// Sets the file position to the beginning of the file of the given stream. The error and end-of-file indicators
// are reset.

void setbuf(FILE *stream, char *buffer);
// Defines how a stream should be buffered. This should be called after the stream has been opened but
// before any operation has been done on the stream. Input and output is fully buffered. The default
// BUFSIZ is the size of the buffer. The argument buffer points to an array to be used as the buffer. If
// buffer is a null pointer, then the stream is unbuffered.

int setvbuf(FILE *stream, char *buffer, int mode, size_t size);
// Defines how a stream should be buffered. This should be called after the stream has been opened but
// before any operation has been done on the stream. The argument mode defines how the stream should be
// buffered as follows:
// _IOFBF Input and output is fully buffered. If the buffer is empty, an input operation attempts to fill the
// buffer. On output the buffer will be completely filled before any information is written to the
// file (or the stream is closed).
// _IOLBF Input and output is line buffered. If the buffer is empty, an input operation attempts to fill the
// buffer. On output the buffer will be flushed whenever a newline character is written.

// _IONBF Input and output is not buffered. No buffering is performed.
// The argument buffer points to an array to be used as the buffer. If buffer is a null pointer, then setvbuf
// uses malloc to create its own buffer.
// The argument size determines the size of the array.
// On success zero is returned. On error a nonzero value is returned.

FILE *tmpfile(void);
// Creates a temporary file in binary update mode (wb+). The tempfile is removed when the program
// terminates or the stream is closed.
// On success a pointer to a file stream is returned. On error a null pointer is returned.

char *tmpnam(char *str);
// Generates and returns a valid temporary filename which does not exist. Up to TMP_MAX different
// filenames can be generated.
// If the argument str is a null pointer, then the function returns a pointer to a valid filename. If the
// argument str is a valid pointer to an array, then the filename is written to the array and a pointer to the
// same array is returned. The filename may be up to L_tmpnam characters long.


// 2.12.4 Formatted I/O Functions
int fprintf(FILE *stream, const char *format, ...);
int printf(const char *format, ...);
int sprintf(char *str, const char *format, ...);
int vfprintf(FILE *stream, const char *format, va_list arg);
int vprintf(const char *format, va_list arg);
int vsprintf(char *str, const char *format, va_list arg);

/*
The ..printf functions provide a means to output formatted information to a stream.
fprintf sends formatted output to a stream
printf sends formatted output to stdout
sprintf sends formatted output to a string
vfprintf sends formatted output to a stream using an argument list
vprintf sends formatted output to stdout using an argument list
vsprintf sends formatted output to a string using an argument list
These functions take the format string specified by the format argument and apply each following
argument to the format specifiers in the string in a left to right fashion. Each character in the format
string is copied to the stream except for conversion characters which specify a format specifier.
The string commands (sprintf and vsprintf) append a null character to the end of the string. This
null character is not counted in the character count.
The argument list commands (vfprintf, vprintf, and vsprintf) use an argument list which is
prepared by va_start. These commands do not call va_end (the caller must call it).
A conversion specifier begins with the % character. After the % character come the following in this
order:
[flags] Control the conversion (optional).
[width] Defines the number of characters to print (optional).
[.precision] Defines the amount of precision to print for a number type (optional).
[modifier] Overrides the size (type) of the argument (optional).
[type] The type of conversion to be applied (required).
Flags:
- Value is left justified (default is right justified). Overrides the 0 flag.

+ Forces the sign (+ or -) to always be shown. Default is to just show the - sign. Overrides the
space flag.
space Causes a positive value to display a space for the sign. Negative values still show the - sign.
# Alternate form:
Conversion Character Result
o Precision is increased to make the first digit a zero.
X or x Nonzero value will have 0x or 0X prefixed to it.
E, e, f, g, or
G Result will always have a decimal point.
G or g Trailing zeros will not be removed.
0 For d, i, o, u, x, X, e, E, f, g, and G leading zeros are used to pad the field width instead of
spaces. This is useful only with a width specifier. Precision overrides this flag.
Width:
The width of the field is specified here with a decimal value. If the value is not large enough to fill the
width, then the rest of the field is padded with spaces (unless the 0 flag is specified). If the value
overflows the width of the field, then the field is expanded to fit the value. If a * is used in place of the
width specifer, then the next argument (which must be an int type) specifies the width of the field.
Note: when using the * with the width and/or precision specifier, the width argument comes first, then
the precision argument, then the value to be converted.
Precision:
The precision begins with a dot (.) to distinguish itself from the width specifier. The precision can be
given as a decimal value or as an asterisk (*). If a * is used, then the next argument (which is an int
type) specifies the precision. Note: when using the * with the width and/or precision specifier, the width
argument comes first, then the precision argument, then the value to be converted. Precision does not
affect the c type.
[.precision] Result
(none) Default precision values:
1 for d, i, o, u, x, X types. The minimum number of digits to appear.
6 for f, e, E types. Specifies the number of digits after the decimal point.
For g or G types all significant digits are shown.
For s type all characters in string are print up to but not including the null character.
. or .0 For d, i, o, u, x, X types the default precis ion value is used unless the value is zero in
which case no characters are printed.
For f, e, E types no decimal point character or digits are printed.
For g or G types the precision is assumed to be 1.

.n For d, i, o, u, x, X types then at least n digits are printed (padding with zeros if necessary).
For f, e, E types specifies the number of digits after the decimal point.
For g or G types specifies the number of significant digits to print.
For s type specifies the maximum number of characters to print.
Modifier:
A modifier changes the way a conversion specifier type is interpreted.
[modifier] [type] Effect
h d, i, o, u, x, X Value is first converted to a short int or unsigned short i nt.
h n Specifies that the pointer points to a short int.
l d, i, o, u, x,
X
Value is first converted to a long int or unsigned long int .
l n Specifies that the pointer points to a long int.
L e, E, f, g, G Value is first converted to a long double.
Conversion specifier type:
The conversion specifier specifies what type the argument is to be treated as.
[type] Output
d, i Type signed int.
o Type unsigned int printed in octal.
u Type unsigned int printed in decimal.
x Type unsigned int printed in hexadecimal as dddd using a, b, c, d, e, f.
X Type unsigned int printed in hexadecimal as dddd using A, B, C, D, E, F.
f Type double printed as [-]ddd.ddd.
e, E Type double printed as [-]d.ddde帽dd where there is one digit printed before the decimal (zero
only if the value is zero). The exponent contains at least two digits. If type is E then the
exponent is printed with a capital E.
g, G Type double printed as type e or E if the exponent is less than -4 or greater than or equal to
the precision. Otherwise printed as type f. Trailing zeros are removed. Decimal point character
appears only if there is a nonzero decimal digit.
c Type char. Single character is printed.
s Type pointer to array. String is printed according to precision (no precision prints entire string).
p Prints the value of a pointer (the memory location it holds).
n The argument must be a pointer to an int. Stores the number of characters printed thus far in
the int. No characters are printed.

% A % sign is printed.
The number of characters printed are returned. If an error occurred, -1 is returned.
*/



// 2.12.4.2 ..scanf Functions

int fscanf(FILE *stream, const char *format, ...);
int scanf(const char *format, ...);
int sscanf(const char *str, const char *format, ...);

/*
The ..scanf functions provide a means to input formatted information from a stream.
fscanf reads formatted input from a stream
scanf reads formatted input from stdin
sscanf reads formatted input from a string
These functions take input in a manner that is specified by the format argument and store each input
field into the following arguments in a left to right fashion.
Each input field is specified in the format string with a conversion specifier which specifies how the
input is to be stored in the appropriate variable. Other characters in the format string specify characters
that must be matched from the input, but are not stored in any of the following arguments. If the input
does not match then the function stops scanning and returns. A whitespace character may match with
any whitespace character (space, tab, carriage return, new line, vertical tab, or formfeed) or the next
incompatible character.
An input field is specified with a conversion specifer which begins with the % character. After the %
character come the following in this order:
[*] Assignment suppressor (optional).
[width] Defines the maximum number of characters to read (optional).
[modifier] Overrides the size (type) of the argument (optional).
[type] The type of conversion to be applied (required).
Assignment suppressor:
Causes the input field to be scanned but not stored in a variable.

Width:
The maximum width of the field is specified here with a decimal value. If the input is smaller than the
width specifier (i.e. it reaches a nonconvertible character), then what was read thus far is converted and
stored in the variable.
Modifier:
A modifier changes the way a conversion specifier type is interpreted.
[modifier] [type] Effect
h d, i, o, u,
x
The argument is a short int or unsigned short int.< /td>
h n Specifies that the pointer points to a short int.
l d, i, o, u,
x
The argument is a long int or unsigned long int .
l n Specifies that the pointer points to a long int.
l e, f, g The argument is a double.
L e, f, g The argument is a long double.
Conversion specifier type:
The conversion specifier specifies what type the argument is. It also controls what a valid convertible
character is (what kind of characters it can read so it can convert to something compatible).
[type] Input
d Type signed int represented in base 10. Digits 0 through 9 and the sign (+ or -).
i Type signed int. The base (radix) is dependent on the first two characters. If the first
character is a digit from 1 to 9, then it is base 10. If the first digit is a zero and the second
digit is a digit from 1 to 7, then it is base 8 (octal). If the first digit is a zero and the
second character is an x or X, then it is base 16 (hexadecimal).
o Type unsigned int. The input must be in base 8 (octal). Digits 0 through 7 only.
u Type unsigned int. The input must be in base 10 (decimal). Digits 0 through 9 only.
x, X Type unsigned int. The input must be in base 16 (hexadecimal). Digits 0 through 9
or A through Z or a through z. The characters 0x or 0X may be optionally prefixed to the
value.
e, E, f, g, G Type float. Begins with an optional sign. Then one or more digits, followed by an
optional decimal-point and decimal value. Finally ended with an optional signed
exponent value designated with an e or E.
s Type character array. Inputs a sequence of non-whitespace characters (space, tab,
carriage return, new line, vertical tab, or formfeed). The array must be large enough to
hold the sequence plus a null character appended to the end.

[...] Type character array. Allows a search set of characters. Allows input of only those
character encapsulated in the brackets (the scanset). If the first character is a carrot (^),
then the scanset is inverted and allows any ASCII character except those specified
between the brackets. On some systems a range can be specified with the dash character
(-). By specifying the beginning character, a dash, and an ending character a range of
characters can be included in the scanset. A null character is appended to the end of the
array.
c Type character array. Inputs the number of characters specified in the width field. If no
width field is specified, then 1 is assumed. No null character is appended to the array.
p Pointer to a pointer. Inputs a memory address in the same fashion of the %p type
produced by the printf function.
n The argument must be a pointer to an int. Stores the number of characters read thus far
in the int. No characters are read from the input stream.
% Requires a matching % sign from the input.
Reading an input field (designated with a conversion specifier) ends when an incompatible character is
met, or the width field is satisfied.
On success the number of input fields converted and stored are returned. If an input failure occurred,
then EOF is returned.
*/


//////////////////////////2.12.5 Character I/O Functions///////////////////////////////////

// Gets the next character (an unsigned char) from the specified stream and advances the position
// indicator for the stream.
// On success the character is returned. If the end-of-file is encountered, then EOF is returned and the endof-file indicator is set. If an error occurs then the error indicator for the stream is set and EOF is returned.
int fgetc(FILE *stream);

// Reads a line from the specified stream and stores it into the string pointed to by str. It stops when either
// (n-1) characters are read, the newline character is read, or the end-of-file is reached, whichever comes
// first. The newline character is copied to the string. A null character is appended to the end of the string.
// On success a pointer to the string is returned. On error a null pointer is returned. If the end-of-file occurs
// before any characters have been read, the string remains unchanged.
char *fgets(char *str, int n, FILE *stream);

// Writes a character (an unsigned char) specified by the argument char to the specified stream and
// advances the position indicator for the stream.
// On success the character is returned. If an error occurs, the error indicator for the stream is set and EOF
// is returned.
int fputc(int char, FILE *stream);

// Writes a string to the specified stream up to but not including the null character.
// On success a nonnegative value is returned. On error EOF is returned.
int fputs(const char *str, FILE *stream);

// Gets the next character (an unsigned char) from the specified stream and advances the position
// indicator for the stream.
// This may be a macro version of fgetc.
// On success the character is returned. If the end-of-file is encountered, then EOF is returned and the endof-file indicator is set. If an error occurs then the error indicator for the stream is set and EOF is returned.
int getc(FILE *stream);

// Gets a character (an unsigned char) from stdin.
// On success the character is returned. If the end-of-file is encountered, then EOF is returned and the endof-file indicator is set. If an error occurs then the error indicator for the stream is set and EOF is returned.
int getchar(void);

// Reads a line from stdin and stores it into the string pointed to by str. It stops when either the newline
// character is read or when the end-of-file is reached, whichever comes first. The newline character is not
// copied to the string. A null character is appended to the end of the string.
// On success a pointer to the string is returned. On error a null pointer is returned. If the end-of-file occurs
// before any characters have been read, the string remains unchanged.
char *gets(char *str);

// Writes a character (an unsigned char) specified by the argument char to the specified stream and
// advances the position indicator for the stream.
// This may be a macro version of fputc.
// On success the character is returned. If an error occurs, the error indicator for the stream is set and EOF
// is returned.
int putc(int char, FILE *stream);

// Writes a character (an unsigned char) specified by the argument char to stdout.
// On success the character is returned. If an error occurs, the error indicator for the stream is set and EOF
// is returned.
int putchar(int char);

// Writes a string to stdout up to but not including the null character. A newline character is appended to
// the output.
// On success a nonnegative value is returned. On error EOF is returned.
int puts(const char *str);

// Pushes the character char (an unsigned char) onto the specified stream so that the this is the next
// character read. The functions fseek, fsetpos, and rewind discard any characters pushed onto the
// stream.
// Multiple characters pushed onto the stream are read in a FIFO manner (first in, first out).
// On success the character pushed is returned. On error EOF is returned.
int ungetc(int char, FILE *stream);

////////////////////////2.12.7 Error Functions////////////////////////////////////

// Prints a descriptive error message to stderr. First the string str is printed followed by a colon then a
// space. Then an error message based on the current setting of the variable errno is printed
void perror(const char *str);

class h_stdio:Base
{
    const int _IOFBF;
    const int _IOLBF;
    const int _IONBF;
    const int BUFSIZ;
    const int EOF;
    const int FOPEN_MAX;
    const int FILENAME_MAX;
    const int L_tmpnam;
    const int SEEK_CUR = 0;
    const int SEEK_END = -1;
    const int SEEK_SET = 1;
    const int TMP_MAX;

    const FILE* stderr = 2;
    const FILE* stdin = 0 ;
    const FILE* stdout = 1;

    long int ftell(FILE *stream);
    size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
    int remove(const char *filename);
    int rename(const char *old_filename, const char *new_filename);
    void rewind(FILE *stream);

    void setbuf(FILE *stream, char *buffer);
    int setvbuf(FILE *stream, char *buffer, int mode, size_t size);
    FILE *tmpfile(void);
    char *tmpnam(char *str);

    int fprintf(FILE *stream, const char *format, ...);
    int fscanf(FILE *stream, const char *format, ...);
    int printf(const char *format, ...);
    int scanf(const char *format, ...);
    int sprintf(char *str, const char *format, ...);
    int sscanf(const char *str, const char *format, ...);
    int vfprintf(FILE *stream, const char *format, va_list arg);
    int vprintf(const char *format, va_list arg);
    int vsprintf(char *str, const char *format, va_list arg);

    int fgetc(FILE *stream);
    char *fgets(char *str, int n, FILE *stream);
    int fputc(int char, FILE *stream);
    int fputs(const char *str, FILE *stream);
    int getc(FILE *stream);
    int getchar(void);
    char *gets(char *str);
    int putc(int char, FILE *stream);
    int putchar(int char);
    int puts(const char *str);
    int ungetc(int char, FILE *stream);
    void perror(const char *str);
};
/********************************************************************************
                                <stdlib.h>
********************************************************************************/
// The stdlib header defines several general operation functions and macros.
// Macros:
// NULL
// EXIT_FAILURE
// EXIT_SUCCESS
// RAND_MAX
// MB_CUR_MAX
// Variables:
// typedef size_t
// typedef wchar_t
// struct div_t
// struct ldiv_t
// Functions:
// abort();
// abs();
// atexit();
// atof();
// atoi();
// atol();
// bsearch();
// calloc();
// div();
// exit();
// free();
// getenv();
// labs();
// ldiv();
// malloc();
// mblen();
// mbstowcs();
// mbtowc();
// qsort();
// rand();
// realloc();
// srand();
// strtod();
// strtol();
// strtoul();
// system();
// wcstombs();
// wctomb();
// 2.13.1 Variables and Definitions
// size_t is the unsigned integer result of the sizeof keyword.
// wchar_t is an integer type of the size of a wide character constant.
// div_t is the structure returned by the div function.
// ldiv_t is the structure returned by the ldiv function.
// NULL is the value of a null pointer constant.
// EXIT_FAILURE and EXIT_SUCCESS are values for the exit function to return termination status.
// RAND_MAX is the maximum value returned by the rand function.
// MB_CUR_MAX is the maximum number of bytes in a multibyte character set which cannot be larger than
// MB_LEN_MAX.


////////////////////////2.13.2 String Functions///////////////////////////
double atof(const char *str);
// The string pointed to by the argument str is converted to a floating-point number (type double). Any
// initial whitespace characters are skipped (space, tab, carriage return, new line, vertical tab, or formfeed).
// The number may consist of an optional sign, a string of digits with an optional decimal character, and an
// optional e or E followed by a optionally signed exponent. Conversion stops when the first unrecognized
// character is reached.
// On success the converted number is returned. If no conversion can be made, zero is returned. If the value
// is out of range of the type double, then HUGE_VAL is returned with the appropriate sign and ERANGE is
// stored in the variable errno. If the value is too small to be returned in the type double, then zero is
// returned and ERANGE is stored in the variable errno.

int atoi(const char *str);
// The string pointed to by the argument str is converted to an integer (type int). Any initial whitespace
// characters are skipped (space, tab, carriage return, new line, vertical tab, or formfeed). The number may
// consist of an optional sign and a string of digits. Conversion stops when the first unrecognized character
// is reached.On success the converted number is returned. If the number cannot be converted, then 0 is returned.

long int atol(const char *str);
// The string pointed to by the argument str is converted to a long integer (type long int). Any initial
// whitespace characters are skipped (space, tab, carriage return, new line, vertical tab, or formfeed). The
// number may consist of an optional sign and a string of digits. Conversion stops when the first
// unrecognized character is reached.
// On success the converted number is returned. If the number cannot be converted, then 0 is returned.

double strtod(const char *str, char **endptr);
// The string pointed to by the argument str is converted to a floating-point number (type double). Any
// initial whitespace characters are skipped (space, tab, carriage return, new line, vertical tab, or formfeed).
// The number may consist of an optional sign, a string of digits with an optional decimal character, and an
// optional e or E followed by a optionally signed exponent. Conversion stops when the first unrecognized
// character is reached.
// The argument endptr is a pointer to a pointer. The address of the character that stopped the scan is stored
// in the pointer that endptr points to.
// On success the converted number is returned. If no conversion can be made, zero is returned. If the value
// is out of range of the type double, then HUGE_VAL is returned with the appropriate sign and ERANGE is
// stored in the variable errno. If the value is too small to be returned in the type double, then zero is
// returned and ERANGE is stored in the variable errno.

long int strtol(const char *str, char **endptr, int base);
// The string pointed to by the argument str is converted to a long integer (type long int). Any initial
// whitespace characters are skipped (space, tab, carriage return, new line, vertical tab, or formfeed). The
// number may consist of an optional sign and a string of digits. Conversion stops when the first
// unrecognized character is reached.
// If the base (radix) argument is zero, then the conversion is dependent on the first two characters. If the
// first character is a digit from 1 to 9, then it is base 10. If the first digit is a zero and the second digit is a
// digit from 1 to 7, then it is base 8 (octal). If the first digit is a zero and the second character is an x or X,
// then it is base 16 (hexadecimal).
// If the base argument is from 2 to 36, then that base (radix) is used and any characters that fall outside of
// that base definition are considered unconvertible. For base 11 to 36, the characters A to Z (or a to z) are
// used. If the base is 16, then the characters 0x or 0X may precede the number.
// The argument endptr is a pointer to a pointer. The address of the character that stopped the scan is stored
// in the pointer that endptr points to.
// On success the converted number is returned. If no conversion can be made, zero is returned. If the value
// is out of the range of the type long int, then LONG_MAX or LONG_MIN is returned with the sign of
// the correct value and ERANGE is stored in the variable errno.

unsigned long int strtoul(const char *str, char **endptr, int base);
// The string pointed to by the argument str is converted to an unsigned long integer (type unsigned
// long int). Any initial whitespace characters are skipped (space, tab, carriage return, new line,
// vertical tab, or formfeed). The number may consist of an optional sign and a string of digits. Conversion
// stops when the first unrecognized character is reached.
// If the base (radix) argument is zero, then the conversion is dependent on the first two characters. If the
// first character is a digit from 1 to 9, then it is base 10. If the first digit is a zero and the second digit is a
// digit from 1 to 7, then it is base 8 (octal). If the first digit is a zero and the second character is an x or X,
// then it is base 16 (hexadecimal).
// If the base argument is from 2 to 36, then that base (radix) is used and any characters that fall outside of
// that base definition are considered unconvertible. For base 11 to 36, the characters A to Z (or a to z) are
// used. If the base is 16, then the characters 0x or 0X may precede the number.
// The argument endptr is a pointer to a pointer. The address of the character that stopped the scan is stored
// in the pointer that endptr points to.
// On success the converted number is returned. If no conversion can be made, zero is returned. If the value
// is out of the range of the type unsigned long int, then ULONG_MAX is returned and ERANGE is
// stored in the variable errno.

///////////////////////////////////2.13.3 Memory Functions///////////////////////////////

void *calloc(size_t nitems, size_t size);
// Allocates the requested memory and returns a pointer to it. The requested size is nitems each size bytes
// long (total memory requested is nitems*size). The space is initialized to all zero bits.
// On success a pointer to the requested space is returned. On failure a null pointer is returned.

void free(void *ptr);
// Deallocates the memory previously allocated by a call to calloc, malloc, or realloc. The
// argument ptr points to the space that was previously allocated. If ptr points to a memory block that was
// not allocated with calloc, malloc, or realloc, or is a space that has been deallocated, then the
// result is undefined.
// No value is returned.

void *malloc(size_t size);
// Allocates the requested memory and returns a pointer to it. The requested size is size bytes. The value of
// the space is indeterminate.
// On success a pointer to the requested space is returned. On failure a null pointer is returned.

void *realloc(void *ptr, size_t size);
// Attempts to resize the memory block pointed to by ptr that was previously allocated with a call to
// malloc or calloc. The contents pointed to by ptr are unchanged. If the value of size is greater than
// the previous size of the block, then the additional bytes have an undeterminate value. If the value of size
// is less than the previous size of the block, then the difference of bytes at the end of the block are freed. If
// ptr is null, then it behaves like malloc. If ptr points to a memory block that was not allocated with
// calloc or malloc, or is a space that has been deallocated, then the result is undefined. If the new
// space cannot be allocated, then the contents pointed to by ptr are unchanged. If size is zero, then the
// memory block is completely freed.
// On success a pointer to the memory block is returned (which may be in a different location as before).
// On failure or if size is zero, a null pointer is returned.



/////////////////////////////////2.13.4 Environment Functions//////////////////////////

void abort(void);
// Causes an abnormal program termination. Raises the SIGABRT signal and an unsuccessful termination
// status is returned to the environment. Whether or not open streams are closed is implementation-defined.
// No return is possible.

int atexit(void (*func)(void));
// Causes the specified function to be called when the program terminates normally. At least 32 functions
// can be registered to be called when the program terminates. They are called in a last-in, first-out basis
// (the last function registered is called first).
// On success zero is returned. On failure a nonzero value is returned.

void exit(int status);
// Causes the program to terminate normally. First the functions registered by atexit are called, then all
// open streams are flushed and closed, and all temporary files opened with tmpfile are removed. The value
// of status is returned to the environment. If status is EXIT_SUCCESS, then this signifies a successful
// termination. If status is EXIT_FAILURE, then this signifies an unsuccessful termination. All other
// values are implementation-defined.
// No return is possible.

char *getenv(const char *name);
// Searches for the environment string pointed to by name and returns the associated value to the string.
// This returned value should not be written to.
// If the string is found, then a pointer to the string's associated value is returned. If the string is not found,
// then a null pointer is returned.

int system(const char *string);
// The command specified by string is passed to the host environment to be executed by the command
// processor. A null pointer can be used to inquire whether or not the command processor exists.
// If string is a null pointer and the command processor exists, then zero is returned. All other return values
// are implementation-defined.



////////////////////////////////2.13.5 Searching and Sorting Functions////////////////////////////

void *bsearch(const void *key, const void *base, size_t nitems,
              size_t size, int (*compar)(const void *, const void *));
// Performs a binary search. The beginning of the array is pointed to by base. It searches for an element
// equal to that pointed to by key. The array is nitems long with each element in the array size bytes long.
// The method of comparing is specified by the compar function. This function takes two arguments, the
// first is the key pointer and the second is the current element in the array being compared. This function
// must return less than zero if the compared value is less than the specified key. It must return zero if the
// compared value is equal to the specified key. It must return greater than zero if the compared value is
// greater than the specified key.
// The array must be arranged so that elements that compare less than key are first, elements that equal key
// are next, and elements that are greater than key are last.
// If a match is found, a pointer to this match is returned. Otherwise a null pointer is returned. If multiple
// matching keys are found, which key is returned is unspecified.

//2.13.5.2 qsort

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

// Sorts an array. The beginning of the array is pointed to by base. The array is nitems long with each
// element in the array size bytes long.
// The elements are sorted in ascending order according to the compar function. This function takes two
// arguments. These arguments are two elements being compared. This function must return less than zero
// if the first argument is less than the second. It must return zero if the first argument is equal to the
// second. It must return greater than zero if the first argument is greater than the second.
// If multiple elements are equal, the order they are sorted in the array is unspecified.
// No value is returned.

/*
Example:
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(void)
{
    char string_array[10][50]={"John",
    "Jane",
    "Mary",
    "Rogery",
    "Dave",
    "Paul",

    "Beavis",
    "Astro",
    "George",
    "Elroy"};
    // Sort the list
    qsort(string_array,10,50,strcmp);
    // Search for the item "Elroy" and print it
    printf("%s",bsearch("Elroy",string_array,10,50,strcmp));
    return 0;
}
*/
class h_stdlib:Base
{
    double atof(const char *str);
    int atoi(const char *str);
    long int atol(const char *str);
    double strtod(const char *str, char **endptr);
    long int strtol(const char *str, char **endptr, int base);
    unsigned long int strtoul(const char *str, char **endptr, int base);
    void *calloc(size_t nitems, size_t size);
    void free(void *ptr);
    void *malloc(size_t size);
    void *realloc(void *ptr, size_t size);
    void abort(void);
    int atexit(void (*func)(void));
    void exit(int status);
    char *getenv(const char *name);
    int system(const char *string);
    void *bsearch(const void *key, const void *base, size_t nitems,
                    size_t size, int (*compar)(const void *, const void *));
    void qsort(void *base, size_t nitems, size_t size,
                int (*compar)(const void *, const void *));

};

/********************************************************************************
                                <math.h>
********************************************************************************/
// 2.13.6 Math Functions
int abs(int x);
// Returns the absolute value of x. Note that in two's compliment that the most maximum number cannot
// be represented as a positive number. The result in this case is undefined.
// The absolute value is returned.
div_t div(int numer, int denom);
// Divides numer (numerator) by denom (denominator). The result is stored in the structure div_t which
// has two members:
// int qout;
// int rem;
// Where quot is the quotient and rem is the remainder. In the case of inexact division, quot is rounded
// down to the nearest integer. The value numer is equal to quot * denom + rem.
// The value of the division is returned in the structure.

long int labs(long int x);
// Returns the absolute value of x. Not that in two's compliment that the most maximum number cannot be
// represented as a positive number. The result in this case is undefined.
// The absolute value is returned.

ldiv_t ldiv(long int numer, long int denom);
// Divides numer (numerator) by denom (denominator). The result is stored in the structure ldiv_t which
// has two members:
long int qout;
long int rem;
// Where quot is the quotient and rem is the remainder. In the case of inexact division, quot is rounded
// down to the nearest integer. The value numer is equal to quot * denom + rem.
// The value of the division is returned in the structure.

int rand(void);
// Returns a pseudo-random number in the range of 0 to RAND_MAX.
// The random number is returned.

void srand(unsigned int seed);
// This function seeds the random number generator used by the function rand. Seeding srand with the
// same seed will cause rand to return the same sequence of pseudo-random numbers. If srand is not
// called, rand acts as if srand(1) has been called.
// No value is returned.

// 2.13.7 Multibyte Functions
// The behavior of the multibyte functions are affected by the setting of LC_CTYPE in the location
// settings.

int mblen(const char *str, size_t n);
// Returns the length of a multibyte character pointed to by the argument str. At most n bytes will be
// examined.
// If str is a null pointer, then zero is returned if multibyte characters are not state-dependent (shift state).
// Otherwise a nonzero value is returned if multibyte character are state-dependent.
// If str is not null, then the number of bytes that are contained in the multibyte character pointed to by str
// are returned. Zero is returned if str points to a null character. A value of -1 is returned if str does not
// point to a valid multibyte character.


size_t mbstowcs(schar_t *pwcs, const char *str, size_t n);
// Converts the string of multibyte characters pointed to by the argument str to the array pointed to by
// pwcs. It stores no more than n values into the array. Conversion stops when it reaches the null character
// or n values have been stored. The null character is stored in the array as zero but is not counted in the
// return value.
// If an invalid multibyte character is reached, then the value -1 is returned. Otherwise the number of
// values stored in the array is returned not including the terminating zero character.

int mbtowc(whcar_t *pwc, const char *str, size_t n);
// Examines the multibyte character pointed to by the argument str. The value is converted and stored in
// the argument pwc if pwc is not null. It scans at most n bytes.
// If str is a null pointer, then zero is returned if multibyte characters are not state-dependent (shift state).
// Otherwise a nonzero value is returned if multibyte character are state-dependent.
// If str is not null, then the number of bytes that are contained in the multibyte character pointed to by str
// are returned. Zero is returned if str points to a null character. A value of -1 is returned if str does not
// point to a valid multibyte character.

size_t wcstombs(char *str, const wchar_t *pwcs, size_t n);
// Converts the codes stored in the array pwcs to multibyte characters and stores them in the string str. It
// copies at most n bytes to the string. If a multibyte character overflows the n constriction, then none of
// that multibyte character's bytes are copied. Conversion stops when it reaches the null character or n
// bytes have been written to the string. The null character is stored in the string, but is not counted in the
// return value.
// If an invalid code is reached, the value -1 is returned. Otherwise the number of bytes stored in the string
// is returned not including the terminating null character.


int wctomb(char *str, wchar_t wchar);
// Examines the code which corresponds to a multibyte character given by the argument wchar. The code
// is converted to a multibyte character and stored into the string pointed to by the argument str if str is not
// null.
// If str is a null pointer, then zero is returned if multibyte characters are not state-dependent (shift state).
// Otherwise a nonzero value is returned if multibyte character are state-dependent.
// If str is not null, then the number of bytes that are contained in the multibyte character wchar are
// returned. A value of -1 is returned if wchar is not a valid multibyte character

class math:Base
{
    int abs(int x);
    div_t div(int numer, int denom);
    long int labs(long int x);
    ldiv_t ldiv(long int numer, long int denom);
    long int qout;
    long int rem;
    int rand(void);
    void srand(unsigned int seed);
    int mblen(const char *str, size_t n);
    size_t mbstowcs(schar_t *pwcs, const char *str, size_t n);
    int mbtowc(whcar_t *pwc, const char *str, size_t n);
    size_t wcstombs(char *str, const wchar_t *pwcs, size_t n);
    int wctomb(char *str, wchar_t wchar);
};

/********************************************************************************
                                <string.h>
********************************************************************************/
// The string header provides many functions useful for manipulating strings (character arrays).
// Macros:
// NULL
// Variables:
// size_t;

// Functions:
// memchr();
// memcmp();
// memcpy();
// memmove();
// memset();
// strcat();
// strncat();
// strchr();
// strcmp();
// strncmp();
// strcoll();
// strcpy();
// strncpy();
// strcspn();
// strerror();
// strlen();
// strpbrk();
// strrchr();
// strspn();
// strstr();
// strtok();
// strxfrm();


// Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the
// string pointed to by the argument str.
// Returns a pointer pointing to the first matching character, or null if no match was found.
void *memchr(const void *str, int c, size_t n);

// Compares the first n bytes of str1 and str2. Does not stop comparing even after the null character (it
// always checks n characters).
// Returns zero if the first n bytes of str1 and str2 are equal. Returns less than zero or greater than zero if
// str1 is less than or greater than str2 respectively.
int memcmp(const void *str1, const void *str2, size_t n);

// Copies n characters from str2 to str1. If str1 and str2 overlap the behavior is undefined.
// Returns the argument str1.
void *memcpy(void *str1, const void *str2, size_t n);

// Copies n characters from str2 to str1. If str1 and str2 overlap the information is first completely read
// from str1 and then written to str2 so that the characters are copied correctly.
// Returns the argument str1.
void *memmove(void *str1, const void *str2, size_t n);

// Copies the character c (an unsigned char) to the first n characters of the string pointed to by the
// argument str.
// The argument str is returned.
void *memset(void *str, int c, size_t n);

// Appends the string pointed to by str2 to the end of the string pointed to by str1. The terminating null
// character of str1 is overwritten. Copying stops once the terminating null character of str2 is copied. If
// overlapping occurs, the result is undefined.
// The argument str1 is returned.
char *strcat(char *str1, const char *str2);

// Appends the string pointed to by str2 to the end of the string pointed to by str1 up to n characters long.
// The terminating null character of str1 is overwritten. Copying stops once n characters are copied or the
// terminating null character of str2 is copied. A terminating null character is always appended to str1. If
// overlapping occurs, the result is undefined.
// The argument str1 is returned.
char *strncat(char *str1, const char *str2, size_t n);


// Searches for the first occurrence of the character c (an unsigned char) in the string pointed to by the
// argument str. The terminating null character is considered to be part of the string.
// Returns a pointer pointing to the first matching character, or null if no match was found.
char *strchr(const char *str, int c);


// Compares the string pointed to by str1 to the string pointed to by str2.
// Returns zero if str1 and str2 are equal. Returns less than zero or greater than zero if str1 is less than or
// greater than str2 respectively.
int strcmp(const char *str1, const char *str2);


// Compares at most the first n bytes of str1 and str2. Stops comparing after the null character.
// Returns zero if the first n bytes (or null terminated length) of str1 and str2 are equal. Returns less than
// zero or greater than zero if str1 is less than or greater than str2 respectively.
int strncmp(const char *str1, const char *str2, size_t n);


// Compares string str1 to str2. The result is dependent on the LC_COLLATE setting of the location.
// Returns zero if str1 and str2 are equal. Returns less than zero or greater than zero if str1 is less than or
// greater than str2 respectively.
int strcoll(const char *str1, const char *str2);


// Copies the string pointed to by str2 to str1. Copies up to and including the null character of str2. If str1
// and str2 overlap the behavior is undefined.
// Returns the argument str1.
char *strcpy(char *str1, const char *str2);


// Copies up to n characters from the string pointed to by str2 to str1. Copying stops when n characters are
// copied or the terminating null character in str2 is reached. If the null character is reached, the null
// characters are continually copied to str1 until n characters have been copied.
// Returns the argument str1.
char *strncpy(char *str1, const char *str2, size_t n);

// Finds the first sequence of characters in the string str1 that does not contain any character specified in str2.
// Returns the length of this first sequence of characters found that do not match with str2.
size_t strcspn(const char *str1, const char *str2);


// Searches an internal array for the error number errnum and returns a pointer to an error message string.
// Returns a pointer to an error message string.
char *strerror(int errnum);


// Computes the length of the string str up to but not including the terminating null character.
// Returns the number of characters in the string.
size_t strlen(const char *str);


// Finds the first character in the string str1 that matches any character specified in str2.
// A pointer to the location of this character is returned. A null pointer is returned if no character in str2
// exists in str1.
/*
Example:
#include<string.h>
#include<stdio.h>
int main(void)
{
    char string[]="Hi there, Chip!";
    char *string_ptr;
    while((string_ptr=strpbrk(string," "))!=NULL)
    *string_ptr='-';
    printf("New string is \"%s\".\n",string);
    return 0;
}
The output should result in every space in the string being converted to a dash (-).
*/
char *strpbrk(const char *str1, const char *str2);


// Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the
// argument str. The terminating null character is considered to be part of the string.
// Returns a pointer pointing to the last matching character, or null if no match was found.
char *strrchr(const char *str, int c);


// Finds the first sequence of characters in the string str1 that contains any character specified in str2.
// Returns the length of this first sequence of characters found that match with str2.
/*
Example:
#include<string.h>
#include<stdio.h>

int main(void)
{
    char string[]="7803 Elm St.";
    printf("The number length is %d.\n",strspn
    (string,"1234567890"));
    return 0;
}
The output should be: The number length is 4.
*/
size_t strspn(const char *str1, const char *str2);


// Finds the first occurrence of the entire string str2 (not including the terminating null character) which
// appears in the string str1.
// Returns a pointer to the first occurrence of str2 in str1. If no match was found, then a null pointer is
// returned. If str2 points to a string of zero length, then the argument str1 is returned.
char *strstr(const char *str1, const char *str2);


// Breaks string str1 into a series of tokens. If str1 and str2 are not null, then the following search sequence
// begins. The first character in str1 that does not occur in str2 is found. If str1 consists entirely of
// characters specified in str2, then no tokens exist and a null pointer is returned. If this character is found,
// then this marks the beginning of the first token. It then begins searching for the next character after that
// which is contained in str2. If this character is not found, then the current token extends to the end of str1.
// If the character is found, then it is overwritten by a null character, which terminates the current token.
// The function then saves the following position internally and returns.
// Subsequent calls with a null pointer for str1 will cause the previous position saved to be restored and
// begins searching from that point. Subsequent calls may use a different value for str2 each time.
// Returns a pointer to the first token in str1. If no token is found then a null pointer is returned.
/*
Example:
#include<string.h>
#include<stdio.h>
int main(void)
{
    char search_string[]="Woody Norm Cliff";
    char *array[50];
    int loop;
    array[0]=strtok(search_string," ");
    if(array[0]==NULL)
    {
        printf("No test to search.\n");
        exit(0);
    }
    for(loop=1;loop<50;loop++)
    {
        array[loop]=strtok(NULL," ");
        if(array[loop]==NULL)
            break;
    }
    for(loop=0;loop<50;loop++)
    {
        if(array[loop]==NULL)
            break;
        printf("Item #%d is %s.\n",loop,array[loop]);
    }
    return 0;
}
This program replaces each space into a null character and stores a pointer to each substring into the
array. It then prints out each item.
*/
char *strtok(char *str1, const char *str2);



// Transforms the string str2 and places the result into str1. It copies at most n characters into str1
// including the null terminating character. The transformation occurs such that strcmp applied to two
// separate converted strings returns the same value as strcoll applied to the same two strings. If
// overlapping occurs, the result is undefined.
// Returns the length of the transformed string (not including the null character)
size_t strxfrm(char *str1, const char *str2, size_t n);

class h_string:Base
{
    void *memchr(const void *str, int c, size_t n);
    int   memcmp(const void *str1, const void *str2, size_t n);
    void *memcpy(void *str1, const void *str2, size_t n);
    void *memmove(void *str1, const void *str2, size_t n);
    void *memset(void *str, int c, size_t n);
    char *strcat(char *str1, const char *str2);
    char *strncat(char *str1, const char *str2, size_t n);
    char *strchr(const char *str, int c);
    int   strcmp(const char *str1, const char *str2);
    int   strncmp(const char *str1, const char *str2, size_t n);
    int   strcoll(const char *str1, const char *str2);
    char *strcpy(char *str1, const char *str2);
    char *strncpy(char *str1, const char *str2, size_t n);
    size_t strcspn(const char *str1, const char *str2);
    char *strerror(int errnum);
    size_t strlen(const char *str);
    char *strpbrk(const char *str1, const char *str2);
    char *strrchr(const char *str, int c);
    size_t strspn(const char *str1, const char *str2);
    char *strstr(const char *str1, const char *str2);
    char *strtok(char *str1, const char *str2);
    size_t strxfrm(char *str1, const char *str2, size_t n);
};

/********************************************************************************
                                <time.h>
********************************************************************************/
// The time header provides several functions useful for reading and converting the current time and date.
// Some functions behavior is defined by the LC_TIME category of the location setting.
// Macros:
// NULL
// CLOCKS_PER_SEC
// Variables:
// typedef size_t
// typedef clock_t
// typedef size_t
// struct tm

// Functions:
// asctime();
// clock();
// ctime();
// difftime();
// gmtime();
// localtime();
// mktime();
// strftime();
// time();


// CLOCKS_PER_SEC is the number of processor clocks per second.
#define CLOCKS_PER_SEC  (0)

// size_t is the unsigned integer result of the sizeof keyword.
//typedef long size_t;

// clock_t is a type suitable for storing the processor time.
typedef int clock_t; //类型标识


// time_t is a type suitable for storing the calendar time.
typedef int time_t; //类型标识

struct tm
{
    int tm_sec; /* seconds after the minute (0 to 61) */
    int tm_min; /* minutes after the hour (0 to 59) */
    int tm_hour; /* hours since midnight (0 to 23) */
    int tm_mday; /* day of the month (1 to 31) */
    int tm_mon; /* months since January (0 to 11) */
    int tm_year; /* years since 1900 */
    int tm_wday; /* days since Sunday (0 to 6 Sunday=0)*/
    int tm_yday; /* days since January 1 (0 to 365) */
    int tm_isdst; /* Daylight Savings Time */
};
// struct tm is a structure used to hold the time and date. Its members are as follows:
// int tm_sec; /* seconds after the minute (0 to 61) */
// int tm_min; /* minutes after the hour (0 to 59) */
// int tm_hour; /* hours since midnight (0 to 23) */
// int tm_mday; /* day of the month (1 to 31) */
// int tm_mon; /* months since January (0 to 11) */
// int tm_year; /* years since 1900 */
// int tm_wday; /* days since Sunday (0 to 6 Sunday=0)*/
// int tm_yday; /* days since January 1 (0 to 365) */
// int tm_isdst; /* Daylight Savings Time */
// If tm_isdst is zero, then Daylight Savings Time is not in effect. If it is a positive value, then Daylight
// Savings Time is in effect. If it is negative, then the function using it is requested to attempt to calculate
// whether or not Daylight Savings Time is in effect for the given time.
// Note that tm_sec may go as high as 61 to allow for up to two leap seconds.


// Returns a pointer to a string which represents the day and time of the structure timeptr. The string is in
// the following format:
// DDD MMM dd hh:mm:ss YYYY
// DDD Day of the week (Sun, Mon, Tue, Wed, Thu, Fri, Sat)
// MMM Month of the year (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec)
// dd Day of the month (1,...,31)
// hh Hour (0,...,23)
// mm Minute (0,...,59)
// ss Second (0,...,59)
// YYYY Year

// The string is terminated with a newline character and a null character. The string is always 26 characters
// long (including the terminating newline and null characters).
// A pointer to the string is returned.
/*
Example:
#include<time.h>
#include<stdio.h>
int main(void)
{
    time_t timer;
    timer=time(NULL);
    printf("The current time is %s.\n",asctime(localtime
    (&timer)));
    return 0;
}*/
char *asctime(const struct tm *timeptr);



// Returns the processor clock time used since the beginning of an implementation-defined era (normally
// the beginning of the program). The returned value divided by CLOCKS_PER_SEC results in the number
// of seconds. If the value is unavailable, then -1 is returned.
clock_t clock(void);
/*
Example:
#include<time.h>
#include<stdio.h>
int main(void)
{
    clock_t ticks1, ticks2;
    ticks1=clock();
    ticks2=ticks1;
    while((ticks2/CLOCKS_PER_SEC-ticks1/CLOCKS_PER_SEC)<1)
    ticks2=clock();
    printf("Took %ld ticks to wait one second.\n",ticks2-ticks1);
    printf("This value should be the same as CLOCKS_PER_SEC which is %ld.\n",CLOCKS_PER_SEC);
    return 0;
}*/


// Returns a string representing the localtime based on the argument timer. This is equivalent to:
// asctime(locatime(timer));
// The returned string is in the following format:
// DDD MMM dd hh:mm:ss YYYY
// DDD Day of the week (Sun, Mon, Tue, Wed, Thu, Fri, Sat)
// MMM Month of the year (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec)
// dd Day of the month (1,...,31)
// hh Hour (0,...,23)
// mm Minute (0,...,59)
// ss Second (0,...,59)
// YYYY Year
// The string is terminated with a newline character and a null character. The string is always 26 characters
// long (including the terminating newline and null characters).
// A pointer to the string is returned.
char *ctime(const time_t *timer);

// Calculates the difference of seconds between time1 and time2 (time1-time2).
// Returns the number of seconds.
double difftime(time_t time1, time_t time2);

// The value of timer is broken up into the structure tm and expressed in Coordinated Universal Time
// (UTC) also known as Greenwich Mean Time (GMT).
// A pointer to the structure is returned. A null pointer is returned if UTC is not available.
struct tm *gmtime(const time_t *timer);

// The value of timer is broken up into the structure tm and expressed in the local time zone.
// A pointer to the structure is returned.
/*
Example:
#include<time.h>
#include<stdio.h>
int main(void)
{
    time_t timer;
    timer=time(NULL);
    printf("The current time is %s.\n",asctime(localtime
    (&timer)));
    return 0;
}*/
struct tm *localtime(const time_t *timer);


// Converts the structure pointed to by timeptr into a time_t value according to the local time zone. The
// values in the structure are not limited to their constraints. If they exceed their bounds, then they are
// adjusted accordingly so that they fit within their bounds. The original values of tm_wday (day of the
// week) and tm_yday (day of the year) are ignored, but are set correctly after the other values have been
// constrained. tm_mday (day of the month) is not corrected until after tm_mon and tm_year are
// corrected.
// After adjustment the structure still represents the same time.
// The encoded time_t value is returned. If the calendar time cannot be represented, then -1 is returned.
/*
Example:
#include<time.h>
#include<stdio.h>
//find out what day of the week is January 1, 2001(first day of the 21st century)
int main(void)
{
    struct tm time_struct;
    char days[7][4]={"Sun", "Mon", "Tue", "Wed", "Thu","Fri", "Sat"};
    time_struct.tm_year=2001-1900;
    time_struct.tm_mon=0;
    time_struct.tm_mday=1;
    time_struct.tm_sec=0;
    time_struct.tm_min=0;
    time_struct.tm_hour=0;
    time_struct.tm_isdst=-1;
    if(mktime(&time_struct)==-1)
    {
        printf("Error getting time.\n");
        exit(0);
    }
    printf("January 1, 2001 is a %s.\n",days[time_struct.tm_wday]);
    return 0;
}
*/
time_t mktime(struct tm *timeptr);



// Formats the time represented in the structure timeptr according to the formatting rules defined in format
// and stored into str. No more than maxsize characters are stored into str (including the terminating null
// character).
// All characters in the format string are copied to the str string, including the terminating null character,
// except for conversion characters. A conversion character begins with the % sign and is followed by
// another character which defines a special value that it is to be replaced by.
// Conversion
// Character What it is replaced by
// %a abbreviated weekday name
// %A full weekday name
// %b abbreviated month name
// %B full month name
// %c appropriate date and time representation
// %d day of the month (01-31)
// %H hour of the day (00-23)
// %I hour of the day (01-12)
// %j day of the year (001-366)
// %m month of the year (01-12)
// %M minute of the hour (00-59)
// %p AM/PM designator
// %S second of the minute (00-61)
// %U week number of the year where Sunday is the first day of week 1 (00-53)
// %w weekday where Sunday is day 0 (0-6)
// %W week number of the year where Monday is the first day of week 1 (00-53)
// %x appropriate date representation
// %X appropriate time representation
// %y year without century (00-99)
// %Y year with century
// %Z time zone (possibly abbreviated) or no characters if time zone isunavailable
// %% %
// Returns the number of characters stored into str not including the terminating null character. On error
// zero is returned.
size_t strftime(char *str, size_t maxsize, const char *format,const struct tm *timeptr);


// Calculates the current calender time and encodes it into time_t format.
// The time_t value is returned. If timer is not a null pointer, then the value is also stored into the object
// it points to. If the time is unavailable, then -1 is returned
time_t time(time_t *timer);

class h_time:Base
{
public:
    const int CLOCKS_PER_SEC;

public:
    char *asctime(const struct tm *timeptr);
    clock_t clock(void);
    char *ctime(const time_t *timer);
    double difftime(time_t time1, time_t time2);
    struct tm *gmtime(const time_t *timer);
    struct tm *localtime(const time_t *timer);
    time_t mktime(struct tm *timeptr);
    size_t strftime(char *str, size_t maxsize, const char *format,const struct tm *timeptr);
    time_t time(time_t *timer);
};

#endif


//end of file
