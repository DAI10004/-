// CommonDialog.cpp : 定义应用程序的类行为

#include "stdafx.h"
#include "CommonDialog.h"
#include "CommonDialogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommonDialogApp

BEGIN_MESSAGE_MAP(CCommonDialogApp, CWinApp)
	//{{AFX_MSG_MAP(CCommonDialogApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommonDialogApp 构造函数

CCommonDialogApp::CCommonDialogApp()
{
	// 应用程序构造函数
	// 初始化应用程序状态
}

/////////////////////////////////////////////////////////////////////////////
// 唯一的 CCommonDialogApp 对象

CCommonDialogApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCommonDialogApp 初始化

BOOL CCommonDialogApp::InitInstance()
{
	// 初始化 MFC 应用程序
	AfxEnableControlContainer();

	// 标准初始化
	// 如果这些功能使用了太多内存，可以考虑移除
	#ifdef _AFXDLL
		Enable3dControls();		// 在共享 DLL 中使用 3D 控件
	#else
		Enable3dControlsStatic();	// 在静态链接 DLL 中使用 3D 控件
	#endif

	// 创建对话框
	CCommonDialogDlg dlg;
	m_pMainWnd = &dlg;	// 设置主窗口
	int nResponse = dlg.DoModal();	// 显示模态对话框
	if (nResponse == IDOK)
	{
		// 如果用户点击了 OK 按钮
		// TODO: 这里可以添加额外的处理代码
	}
	else if (nResponse == IDCANCEL)
	{
		// 如果用户点击了 Cancel 按钮
		// TODO: 这里可以添加额外的处理代码
	}

	// 由于对话框已关闭，返回 FALSE 以退出应用程序
	return FALSE;
}
