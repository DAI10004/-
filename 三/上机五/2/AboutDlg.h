// AboutDlg.h : 关于对话框头文件

#if !defined(AFX_ABOUTDLG_H__INCLUDED_)
#define AFX_ABOUTDLG_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// 类向导生成的虚函数
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	//}}AFX_VIRTUAL

// 实现
protected:
	// 生成的消息映射函数
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ 编译器生成的添加位置

#endif // !defined(AFX_ABOUTDLG_H__INCLUDED_)
