/**********************************************************************************
**SI ������Ϣ
**********************************************************************************/


/**********************************************************************************
**SI ��ѡ������Ϣ
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

	InsBufLine(hnewbuf, ln++, " ***********************Source Insight ������òο� *****************************")


	InsBufLine(hnewbuf, ln++, " ���� ������ ���� ��С12")

	//��׼ͷ������
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " ������ɫRGB 210 220 230 ������ɫRGB 192 192 192")

	InsBufLine(hnewbuf, ln++, " ǰ��ɫ �Զ�")
	InsBufLine(hnewbuf, ln++, " �����Ƽ������� Curier New  ������ 10")

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

	InsBufLine(hnewbuf, ln++, " **************************SI���õĿ�ݼ��ٲ�*********************************")

	InsBufLine(hnewbuf, ln++, " CTRL + D ------------------����ɾ����")
	InsBufLine(hnewbuf, ln++, " CTRL + ' ------------------����������")
	InsBufLine(hnewbuf, ln++, " CTRL + = ------------------��ת������")

	InsBufLine(hnewbuf, ln++, " CTRL + G �� F5  ------------------������ָ����")

	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " SHIFT+ F8       ------------------������ʾָ���ı�ʶ��")

	InsBufLine(hnewbuf, ln++, " CTRL + ������ ------------------��ת������")
	InsBufLine(hnewbuf, ln++, " CTRL + F        ------------------����")
	InsBufLine(hnewbuf, ln++, " CTRL + SHIFT+ F ------------------ȫ�ֲ���")
	InsBufLine(hnewbuf, ln++, " CTRL + H        ------------------�滻")
	InsBufLine(hnewbuf, ln++, " CTRL + SHIFT +H ------------------ȫ���滻")
	//�����Զ���չʹ��ָ��
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " F3 		--------------------------��ǰ����")

	InsBufLine(hnewbuf, ln++, " F4 		--------------------------������")
	InsBufLine(hnewbuf, ln++, " F7 		--------------------------�����Ŀ����")
	InsBufLine(hnewbuf, ln++, " F8 		--------------------------����ֲ�����")
	InsBufLine(hnewbuf, ln++, " CTRL + M	----------------------������ǩ")
	InsBufLine(hnewbuf, ln++, " ALT  + F8	----------------------���Ŵ���ʾ/���� ����ALT + S")
	InsBufLine(hnewbuf, ln++, " ALT  + F12	----------------------�ַ����һ��(�����ַ���Ȳ�ͬʱʹ��)")
	InsBufLine(hnewbuf, ln++, " ALT  + T	----------------------���� ")
	InsBufLine(hnewbuf, ln++, " ALT  + E	----------------------������ ")


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
	//����Source Insight ��
	InsBufLine(hnewbuf, ln++, " * ���¼�����֧���Զ����ɿ���估�����׼ͷ:");
	InsBufLine(hnewbuf, ln++, " * �ٶ����Ѿ�������AutoExpand ��Ŀ�ݼ�Ϊ CRTL+ENTER ");
	InsBufLine(hnewbuf, ln++, " * Usage: Keyword + [CRTL+ENTER] ");
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " ****************************���ú�(�Զ���չ)*********************************");

	InsBufLine(hnewbuf, ln++, " * config ----------------------------------------�������Ժ��������Ƽ���˾����");

	//��׼ͷ������
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " ***********************��׼ͷ�Զ�����(�Զ���չ)******************************")

	InsBufLine(hnewbuf, ln++, " * file ------------------------------------------------�Զ����ɱ�׼�ļ�ͷ��Ϣ")
	InsBufLine(hnewbuf, ln++, " * func ------------------------------------------------�Զ����ɱ�׼����ͷ��Ϣ")
	InsBufLine(hnewbuf, ln++, " * hi ----------------------------------------------------���һ���޸���ʷ��¼")
	InsBufLine(hnewbuf, ln++, " * hd ------------------------------------------------------�Զ����ɺ���ͷ�ļ�")
	InsBufLine(hnewbuf, ln++, " * hdn -----------------------------------------------------�Զ����ɺ���ͷ�ļ�")
	//�����Զ���չʹ��ָ��
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " *************************�����Զ�����(�Զ���չ)****************************")

	InsBufLine(hnewbuf, ln++, " * {}-----------------------------------------------------------�Զ���������")
	InsBufLine(hnewbuf, ln++, " * while---------------------------------------------------�Զ����while����")
	InsBufLine(hnewbuf, ln++, " * if---------------------------------------------------------�Զ����if����")
	InsBufLine(hnewbuf, ln++, " * for-------------------------------------------------------�Զ����for����")
	InsBufLine(hnewbuf, ln++, " * do while---------------------------------------------�Զ����do while����")
	InsBufLine(hnewbuf, ln++, " * switch-------------------------------------------------�Զ����switch����")
	InsBufLine(hnewbuf, ln++, " * case-----------------------------------------------------�Զ����case����")
	InsBufLine(hnewbuf, ln++, " * struct-------------------------------------------------�Զ����struct����")
	InsBufLine(hnewbuf, ln++, " * enum-----------------------------------------------------�Զ����enum����")
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " *************************����޸�ע��(�Զ���չ)******************************")

	InsBufLine(hnewbuf, ln++, " * #ifd---------------------------------------------------�Զ����#ifdef����")
	InsBufLine(hnewbuf, ln++, " * #ifn--------------------------------------------------�Զ����#ifndef����")
	InsBufLine(hnewbuf, ln++, " * #if-------------------------------------------------------�Զ����#if����")
	InsBufLine(hnewbuf, ln++, " * cpp----------------------------------------------�Զ����extern \"C\"����")
	InsBufLine(hnewbuf, ln++, " * ap---------------------------------------------------------���һ�����ⵥ��")
	InsBufLine(hnewbuf, ln++, " * ab-----------------------------------------------------------���--ע�Ϳ�ʼ")
	InsBufLine(hnewbuf, ln++, " * ae-----------------------------------------------------------���--ע�ͽ���")
	InsBufLine(hnewbuf, ln++, " * db------------------------------------------------------------ɾ��-ע�Ϳ�ʼ")
	InsBufLine(hnewbuf, ln++, " * de------------------------------------------------------------ɾ��-ע�ͽ���")
	InsBufLine(hnewbuf, ln++, " * mb------------------------------------------------------------�޸�-ע�Ϳ�ʼ")
	InsBufLine(hnewbuf, ln++, " * me------------------------------------------------------------�޸�-ע�ͽ���")
	InsBufLine(hnewbuf, ln++, " * abg--------------------------------------------------������ӿ�ʼ�ͽ���˵��")
	InsBufLine(hnewbuf, ln++, " * dbg--------------------------------------------------����ɾ����ʼ�ͽ���˵��")
	//ͷ�ļ� ��غ�
	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " ************************�����Զ�����(�˵����ݼ�)*************************")

	InsBufLine(hnewbuf, ln++, " * ComentCPPtoC----------------------------------��ѡ��������//ע�͸�ΪC++���")
	InsBufLine(hnewbuf, ln++, " * ReplaceBufTab-------------------------------------����ǰ�ļ���TAB�滻Ϊ�ո�")
	InsBufLine(hnewbuf, ln++, " * ReplaceTabInProj----------------------------------����ǰ��Ŀ��TAB�滻Ϊ�ո�")
	InsBufLine(hnewbuf, ln++, " * InsertFuncName --------------------------------------���뵱ǰ���ڵĺ�������")
	InsBufLine(hnewbuf, ln++, " * FormatLine-----------------------------------------------�Զ����и�ʽ������")
	InsBufLine(hnewbuf, ln++, " * UpdateFunctionList---------------------------------------�Զ����ɺ���ͷ��Ϣ")
	InsBufLine(hnewbuf, ln++, " * DelCompoundStatement-------------------------------------������������ɾ��")
	InsBufLine(hnewbuf, ln++, " * FunctionHeaderCreate ------------------------------------------����ͷ�Ĵ���")
	InsBufLine(hnewbuf, ln++, " * HeaderFileCreate ------------------------------------���뵱ǰ���ڵĺ�������")

	InsBufLine(hnewbuf, ln++, " ")
	InsBufLine(hnewbuf, ln++, " ***********************������Կ����(�˵����ݼ�)**************************")

	InsBufLine(hnewbuf, ln++, " * InsertTraceInfo--------------------------------------��ǰ����������������")
	InsBufLine(hnewbuf, ln++, " * AutoInsertTraceInfoInBuf-------------------------------��ǰ�ļ�����������")
	InsBufLine(hnewbuf, ln++, " * AutoInsertTraceInfoInPrj-------------------------------��ǰ���̲���������")
	InsBufLine(hnewbuf, ln++, " * RemoveTraceInfo----------------------------------------ɾ����ǰ�����������")
	InsBufLine(hnewbuf, ln++, " * RemoveCurBufTraceInfo----------------------------------ɾ����ǰ�ļ��������")
	InsBufLine(hnewbuf, ln++, " * RemovePrjTraceInfo-------------------------------------ɾ����ǰ���̵������")

	InsBufLine(hnewbuf, ln++, " *****************************************************************************")


	//���ذ���ʹ��ָ��
	InsBufLine(hnewbuf, ln++, " *****************************************************************************")
	InsBufLine(hnewbuf, ln++, "")
	InsBufLine(hnewbuf, ln++, " * ���¼��������ض�Ӧ�ļ���������֧�ֺ���:")
	InsBufLine(hnewbuf, ln++, " * ���ع�ϵ����:")
	InsBufLine(hnewbuf, ln++, "")
	InsBufLine(hnewbuf, ln++, " * EM_delete: -------------------------------------------------------- DELETE")
	InsBufLine(hnewbuf, ln++, " * EM_backspace:----------------------------------------------------BACKSPACE")
	InsBufLine(hnewbuf, ln++, " * EM_CursorUp:------------------------------------------------�����Ϸ������")
	InsBufLine(hnewbuf, ln++, " * EM_CursorDown:--------------------------------------------- �����·������")
	InsBufLine(hnewbuf, ln++, " * EM_CursorLeft:--------------------------------------------- �����������")
	InsBufLine(hnewbuf, ln++, " * EM_CursorRight:-------------------------------------------- �����ҷ������")
	InsBufLine(hnewbuf, ln++, " * EM_SelectWordLeft:----------------------------------------------Shift + ��")
	InsBufLine(hnewbuf, ln++, " * EM_SelectWordRight:---------------------------------------------Shift + ��")
	InsBufLine(hnewbuf, ln++, " * EM_SelectLineUp: -----------------------------------------------Shift + ��")
	InsBufLine(hnewbuf, ln++, " * EM_SelectLineUp: ---------------------------------------------- Shift + ��")


	InsBufLine(hnewbuf, ln++, " *****************************************************************************")


	InsBufLine(hnewbuf, ln++, "")
	InsBufLine(hnewbuf, ln++, " ******************************end of file***********************************/")


}

