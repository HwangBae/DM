//-------------------------------------------------------
// Copyright (c) DuiMagic
// All rights reserved.
// 
// File Name: DMBase.h 
// File Des: ����ע����Ļ���
// File Summary: 
// Cur Version: 1.0
// Author:
// Create Data:
// History:
// 		<Author>	<Time>		<Version>	  <Des>
//      guoyou		2015-1-14	1.0		
//-------------------------------------------------------
#pragma once

namespace DM
{
	/// <summary>
	///		xml������Ļ��࣬��������������ʹ��XML������
	/// </summary>
	class DM_EXPORT DMDataBase:public DMRefNum
	{
	public:
		virtual DMCode InitDMData(DMXmlNode &XmlNode);															///<���ء�����XML����
		virtual DMCode OnAttributeStart(LPCWSTR pszAttribute,LPCWSTR pszValue,bool bLoadXml);					///<����XML����������ǰ����
		virtual DMCode SetAttribute(LPCWSTR pszAttribute,LPCWSTR pszValue,bool bLoadXml);						///<����XML����������
		virtual DMCode OnAttributeFinished(LPCWSTR pszAttribute,LPCWSTR pszValue,bool bLoadXml,DMCode iErr);    ///<������һ��XML���Ժ󴥷�
		virtual DMCode DefAttributeProc(LPCWSTR pszAttribute, LPCWSTR pszValue, bool bLoadXml);					///<Ĭ�Ͻ���XML����������
		virtual DMCode OnFinished(DMXmlNode &XmlNode);															///<����ȫ�����������
		virtual DMCode SendExpandInfo(WPARAM wp, LPARAM lp){return DM_ECODE_NOTIMPL;}							///<��չ�ӿ�
	};

	/// <summary>
	///		����ע���ࡢDUI��Ļ���
	/// </summary>
	class DM_EXPORT DMBase:public DMDataBase
	{
	public:
		static LPCWSTR GetClassName();			///<ȡ��ע������
		virtual LPCWSTR V_GetClassName();       ///<ȡ��ע������, �����麯��
		static LPCWSTR GetBaseClassName();		///<ȡ��ע���ุ����
		virtual bool IsClass(LPCWSTR lpszName);	///<�Ƿ����ڴ˴�����������
		static int GetClassType();              ///<ȡ�ô�������
		virtual int V_GetClassType();			///<ȡ�ô������ͣ���GetClassTypeһ���������Ǹ��麯�������ڻ�ָ��ָ������ʱ��̬����
	};

	/// <summary>
	///		��ע�����classtype
	/// </summary>
	/// <remarks>
	///		����ע�������Modeules�����ڲ�ʵ��,�����ο�
	/// </remarks>
	enum DMREGTYPE
	{
		DMREG_Unknown                           = 0,	///<�����ͽ����ڲ�ʹ��
		DMREG_Skin								= 1,    ///<Ƥ����,ָ����ͼƬ�Ļ��Ʒ�ʽ,��ƽ�̡����졢9����
		DMREG_Style                             = 2,	///<��ʽ��
		DMREG_Attribute                         = 3,	///<XML������
		DMREG_Window                            = 4,    ///<DUI������
		DMREG_Layout                            = 5,    ///<ê�㲼����
		DMREG_ImgDecoder                        = 6,    ///<������
		DMREG_Res		                        = 7,    ///<��Դ�����
		DMREG_Render                            = 8,    ///<��Ⱦ��
		DMREG_Draw                              = 9,    ///<������
		DMREG_Log	                            = 10,    ///<LOG��
		DMREG_FlowLayout                        = 11,   ///<��ʽ������,����DUIWindowʵ��
		DMREG_ToolTip                           = 12,   ///<tooltip��
		DMREG_Animate                           = 13,   ///<����ע����
		DMREG_Script                            = 14,   ///<�ű���
		DMREG_MAX, 
	};

/// ���л���DMBase��������붨��˺�,ǰ����static,������������������classtypeֻ����ʹ��DMREGTYPE�е�����
#define DMDECLARE_CLASS_NAME(theclass, classname, classtype) \
public: \
	static LPCWSTR GetClassName() \
	{ \
		return classname; \
	} \
	virtual LPCWSTR V_GetClassName() \
	{ \
		return classname; \
	} \
	static LPCWSTR GetBaseClassName() \
	{ \
		return __super::GetClassName(); \
	} \
	virtual bool IsClass(LPCWSTR lpszName) \
	{ \
		if (0 == _wcsicmp(GetClassName(), lpszName)) \
			return true; \
		return __super::IsClass(lpszName);\
	} \
	static int GetClassType() \
	{ \
		return classtype; \
	}\
	virtual int V_GetClassType()\
	{\
		return classtype;\
	}
	




}//namespace DM