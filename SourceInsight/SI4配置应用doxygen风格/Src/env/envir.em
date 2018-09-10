

///
///	@brief 设置环境变量,中英文共用
///
macro SetRegPrompt(Tips_CN,Tips_EN,RegName_EN)
{
    SetRegPrompt2(Tips_EN,Tips_CN,RegName_EN,Nil)
}

/// @brief 设置环境变量
/// @注意    中文的环境变量只有公司名和作者名,其他环境变量均为英文的
///		   其他环境变量设置应该调用SetRegPrompt 去设置,RegName_CN=Nil
///*Tips_EN  英文提示信息
///*Tips_CN  中文提示信息
///*RegName_EN  英文属性名称
///*RegName_CN  中文属性名称，可以为Nil，如果只有一个变量名称
macro SetRegPrompt2(Tips_EN,Tips_CN,RegName_EN,RegName_CN)
{
    language = GetReg(LANGUAGE);

    if(RegName_EN == Nil)
    {
        return -1;
    }
    if(Tips_EN == Nil || Tips_CN == Nil)
    {
        Msg("Tips Msg Couldn't be empty.");
        return -1;
    }

    if(language == 0)
    {
        value = GetReg(RegName_EN);
        Prompt_Tips_EN = "@RegName_EN@ = @value@ (0:Keep  1:Modify)";
    }
    else
    {
        if(RegName_CN == Nil)
        {
            value = GetReg(RegName_EN);
            Prompt_Tips_CN = "@RegName_EN@ = @value@ (0:保留 1:修改)";
        }else
        {
            value = GetReg(RegName_CN);
            Prompt_Tips_CN = "@RegName_CN@ = @value@ (0:保留 1:修改)";
        }
    }

    if(language == 0)
    {
        choice = ASK(Prompt_Tips_EN);
    }
    else
    {
        choice = ASK(Prompt_Tips_CN);
    }

    //继续修改
    if(choice == 1)
    {
        if(language == 0)
        {
            value = ASK(Tips_EN);
            SetReg(RegName_EN,value);
        }
        else
        {
            value = ASK(Tips_CN);

            if(RegName_CN == Nil)
            {
                SetReg(RegName_EN,value);
            }
            else{
                SetReg(RegName_CN,value);
            }
        }
    }
}


/*
*  重构出的通用接口 获取环境变量并在失败的时候提示用户输入
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
