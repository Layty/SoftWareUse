
/*
*  �ع�����ͨ�ýӿ� ��ȡ������������ʧ�ܵ�ʱ����ʾ�û�����
*/
macro PromptRegName(Tips_EN,Tips_CN,EnvName_EN,EnvName_CN)
{
	if(Tips_EN == Nil || Tips_CN == Nil || EnvName_EN == Nil)
	{
		return Nil;
	}
	lang = 1;
	if(lang == 0)
	{
		 szValue = GetReg(EnvName_EN);
		if(strlen( szValue ) == 0)
		{
			szValue = Ask(Tips_EN);
			SetReg(EnvName_EN, szValue);
		}
	}
	else
	{
		szValue = GetReg(EnvName_CN);
		if(strlen( szValue ) == 0)
		{
			szValue = Ask(Tips_CN);
			SetReg(EnvName_CN, szValue);
		}
	}
	
	return "@szValue@";
}
