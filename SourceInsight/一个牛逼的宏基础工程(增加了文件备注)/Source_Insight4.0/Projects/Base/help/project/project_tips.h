/******************************************************************************************
	项目经验总结
******************************************************************************************/

/***
1.ST Connect 如何设置IP,要点串口波特率为9600bps,Jtag 头也需要注意型号,

2.unsigned long long  64bit数据打印 需要使用 %lld


C中的位域与大小端问题（整理自网上资料）
字节内也是有大小端问题，与字节中的大小端类似：
1）little endian中的位应该这样排列： 
01234567 
即排在前面的是低位。因此，先分配least significant bits 
2）而在Big endian中，位应该这样排列： 
76543210 
即排在前面的是高位。因此，先分配most significant bits。

在对struct中的成员进行分配的时候，"按排列顺序分配，先分配排在前面的" 

1）big endian从高位向低位分配， 
a. 对字节，是先分配低地址的字节，再分配高地址的字节。 
b. 对位域，先分配most significant bits，再分配least significant bits。 
1）little endian从低位向高位分配， 
a. 对字节，是先分配低地址的字节，再分配高地址的字节。 
b. 对位域，先分配least significant bits，再分配most significant bits。 

对于定义如下的结构体:
struct yaabou_com{
int a:1;
int b:2;
int c:3;
int d:4;
int e:5;
int f:6;
int g:11;
};
大端：
地址：[00000000][00000001][00000002][00000003]
数据：|abbcccdd||ddeeeeef||fffffggg||gggggggg|
小端：
地址：[00000000][00000001][00000002][00000003]
数据：|ddcccbba||feeeeedd||gggfffff||gggggggg|



3、Secure CRT  打印时间戳
%H - hostname
%S - session name
%Y - four-digit year
%y - two-digit year
%M - two-digit month
%D - two-digit day of the month
%P - port
%h - two-digit hour
%m - two-digit minute
%s - two-digit seconds
%t - three-digit milliseconds
%% - percent (%)
%envvar% - environment variable
***/


/**

**/

