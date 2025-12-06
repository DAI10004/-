// CommonDialog.h : 主头文件，包含应用程序类声明

#if !defined(AFX_COMMONDIALOG_H__INCLUDED_)
#define AFX_COMMONDIALOG_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // 资源头文件

/////////////////////////////////////////////////////////////////////////////
// CCommonDialogApp 应用程序类

class CCommonDialogApp : public CWinApp
{
public:
	CCommonDialogApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

// 应用程序全局对象
extern CCommonDialogApp theApp;

#endif // !defined(AFX_COMMONDIALOG_H__INCLUDED_)
