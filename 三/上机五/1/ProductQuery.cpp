// ProductQuery.cpp : 定义应用程序的类行为

#include "stdafx.h"
#include "ProductQuery.h"
#include "ProductQueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProductQueryApp

BEGIN_MESSAGE_MAP(CProductQueryApp, CWinApp)
	//{{AFX_MSG_MAP(CProductQueryApp)
	// 移除关于对话框相关的命令映射
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProductQueryApp 构造函数

CProductQueryApp::CProductQueryApp()
{
	// 应用程序构造函数
	// 初始化应用程序状态
}

/////////////////////////////////////////////////////////////////////////////
// 唯一的 CProductQueryApp 对象

CProductQueryApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CProductQueryApp 初始化

BOOL CProductQueryApp::InitInstance()
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

	// 创建主对话框
	CProductQueryDlg dlg;
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
