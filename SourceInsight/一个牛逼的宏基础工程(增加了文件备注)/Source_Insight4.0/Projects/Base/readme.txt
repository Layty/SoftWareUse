Source Insight �깦��
TODO:
1��google coding style ����(c,c++,java,python,shell) https://google.github.io/styleguide/
2���ο� eclipse�Ĵ���淶(ע�͹淶���Զ���ʽ�����룬����Ƭ��)

˵����
1��v3.5�汾��ȫ��emԴ����ʹ��ansi�����ʽ��v4.0 em Դ����ȫ��ʹ��UTF8 �����ʽ
2���������Զ���ʽ�����Զ���������(shell,python,c,cpp,java)


ͨ�ò˵���ʵ��

Ŀ¼���ļ�˵����
main.em						�����
main_event_handler.em		�¼���������  ��ҪSI�����¼�����
common_utils.em				ͨ�ýӿ�
external_tool.em			�ⲿ���߽ӿ�
global_config.em			ȫ������(author,mail,��ݼ�����)
plugin.em					SISetting/Plguins Ŀ¼�й���ʹ��
private_utils.em			�Լ�ʵ�ֵ�macro���߽ӿ�
public.em					ͨ�õ�macro�ӿ�
public_help.em				SI ������Ϣ
quick_nchar.em				ɾ�����֣������������ --ok
run_me.em					����Դ���������


Ŀ¼:
language	           		Ŀ¼�����Խ��������ļ��洢����
basic	               		macro sample �����ο�����ֱ�Ӽ���Base����
cache	               		��ʱ�ļ�����Ŀ¼����help.txt,help.c,tmp.c,tmp.txt ���ļ� ����汾����
help	               		SI help	,Ascii table,Regular express,
project	               		��Ŀ��صľ����ĵ�������
lang_ansi_c
lang_bash
lang_bat
lang_cmake
lang_cpp
lang_d
lang_doxy	           		@ ��\ �Զ���ʾdoxy ����
lang_gradle
lang_java
lang_json
lang_lua
lang_makefile
lang_si_macro
lang_sql
lang_xml

========================================================================

ÿ������Ŀ¼���������԰������⺯������������Ƭ�Σ��Զ���ɣ�
����c/c++���ԣ�
���԰���----�ؼ��� ���� ����� �ַ���
�⺯������
sample ����
�ؼ����Զ����
����Ƭ��
�ļ�ͷ������ͷ�Զ�����
������Ϣ�Ĳ���
�����߶�
��̬�������


glibc
����glibc��gnu������libc�⣬Ҳ��c���п⡣
����glibc��Linuxϵͳ����ײ��api��Ӧ�ó��򿪷��ӿڣ���
�������������κε����пⶼ��������glibc��
����glibc���˷�װlinux����ϵͳ���ṩ��ϵͳ�����⣬
����������Ҳ�ṩ���������һЩ��Ҫ���ܷ����ʵ�֣���Ҫ�����£�
������1��string���ַ�������
������2��signal���źŴ���
������3��dlfcn���������Ķ�̬����
������4��direct���ļ�Ŀ¼����
������5��elf�������Ķ�̬��������Ҳ��interpreter
������6��iconv����ͬ�ַ����ı���ת��
������7��inet��socket�ӿڵ�ʵ��
������8��intl�����ʻ���Ҳ��gettext��ʵ��
������9��io
������10��linuxthreads
������11��locale�����ػ�
������12��login�������ն��豸�Ĺ�����ϵͳ�İ�ȫ����
������13��malloc����̬�ڴ�ķ��������
������14��nis
������15��stdlib��������������


Sourceinsight4.0��3.5����Ҫ���µ�����:

1. ֧�ִ���Ƭ��
2. ������۵�
3. �Ա��д�������ͼ
4. ֧������
5. ���ļ���Ŀ¼�ȽϹ���
6. ��ʽ������
7. ������html
8. ��ǿ���ļ�����
9. �����б�ǩ
10. ֧��Unicode
11. ��������Զ�������ͬ����
12.  ���ñ����ʽΪXML

���ϼӴֵ�������Ϊ�ǳ���Ҫ�Ĺ���,����3.5�汾�Ѿ��ǳ�ǿ��,�������Ƕ����Ƹ�ʽ,û�б�ǩ,����ʶ��UTF-8��������ʹ��.

Ŀǰ���ڰ�ʹ�㶼�����,4.0����ô�ù�Ȼ�����л���.

����4.0Ŀǰ�Ծ�û�н�����뷨����, ����Ҫ��Ŀǰ�汾��Ȼ����ʹ��QQƴ�����뷨����(΢������뷨���ǿ���)
����UTF-8��֧����, ��GBKȴ������벻֧����.
�Ƽ�3.5��4.0һ��ʹ��, GBK��ʹ��3.5, UTF-8��ʹ��4.0.
PS: ����Ӧ����ʹ��UTF-8����, UTF-8�ɼ�����IAR, VS, SI4, Linux, Sublime, Xcode������IDE��༭��,��ʡȥ�ܶ��鷳.

https://github.com/google/styleguide
eclipse http://eclipse-cs.sourceforge.net/update/


## ȫ�ֿ�ݼ����ã�
CTRL + ENTER     ����Ƭ�β���
ALT +  ENTER     �ؼ��ּ��������ܲ�ȫ
CTRL + ALT + O
CTRL + ALT + H   ������Ϣ�˵�
CTRL + ALT + R   ���нű�(������չ��.sh,.py,.bat,.cmd,.c,.java,)
CTRL + ALT + T   ����macro

## SI ����

## ������Ϣ
* Source_Insight4.0\Projects\Base\help ���õı�񼰰�����Ϣ

## ������Ϣ
* ������ʾ�Ͳ�ȫ
* Source_Insight4.0\Projects\Base\lang_auto_complete������.hͷ�ļ�������������ʾ�ķ���
��Ŀ�򿪵�ʱ�����һ��������ʾ�����ļ�����ͬ��
����python���Һ�ƥ�����


## ����༭
c/c++:
CTRL + Q  ��ѡ����� // ע��,��չ��ʶ�����
CTRL + 0  ��ѡ����� #if 0 ....#endif
CTRL + 1  ��ѡ����� #if 1 ....#endif
