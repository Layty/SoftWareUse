/******************************************************************************************
	��Ŀ�����ܽ�
******************************************************************************************/

/***
1.ST Connect �������IP,Ҫ�㴮�ڲ�����Ϊ9600bps,Jtag ͷҲ��Ҫע���ͺ�,

2.unsigned long long  64bit���ݴ�ӡ ��Ҫʹ�� %lld


C�е�λ�����С�����⣨�������������ϣ�
�ֽ���Ҳ���д�С�����⣬���ֽ��еĴ�С�����ƣ�
1��little endian�е�λӦ���������У� 
01234567 
������ǰ����ǵ�λ����ˣ��ȷ���least significant bits 
2������Big endian�У�λӦ���������У� 
76543210 
������ǰ����Ǹ�λ����ˣ��ȷ���most significant bits��

�ڶ�struct�еĳ�Ա���з����ʱ��"������˳����䣬�ȷ�������ǰ���" 

1��big endian�Ӹ�λ���λ���䣬 
a. ���ֽڣ����ȷ���͵�ַ���ֽڣ��ٷ���ߵ�ַ���ֽڡ� 
b. ��λ���ȷ���most significant bits���ٷ���least significant bits�� 
1��little endian�ӵ�λ���λ���䣬 
a. ���ֽڣ����ȷ���͵�ַ���ֽڣ��ٷ���ߵ�ַ���ֽڡ� 
b. ��λ���ȷ���least significant bits���ٷ���most significant bits�� 

���ڶ������µĽṹ��:
struct yaabou_com{
int a:1;
int b:2;
int c:3;
int d:4;
int e:5;
int f:6;
int g:11;
};
��ˣ�
��ַ��[00000000][00000001][00000002][00000003]
���ݣ�|abbcccdd||ddeeeeef||fffffggg||gggggggg|
С�ˣ�
��ַ��[00000000][00000001][00000002][00000003]
���ݣ�|ddcccbba||feeeeedd||gggfffff||gggggggg|



3��Secure CRT  ��ӡʱ���
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

