// EditCtrlDlg.h : 头文件
// 编辑框控件对话框应用程序

#if !defined(AFX_EDITCTRLDLG_H__INCLUDED_)
#define AFX_EDITCTRLDLG_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEditCtrlDlg 对话框

class CEditCtrlDlg : public CDialog
{
// 构造
public:
	CEditCtrlDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	//{{AFX_DATA(CEditCtrlDlg)
	enum { IDD = IDD_EDITCTRL_DIALOG };
		// 控件关联变量
	CEdit	m_edit1;	// 左侧编辑框
	CEdit	m_edit2;	// 右侧编辑框
	//}}AFX_DATA

	// 类向导生成的虚函数
	//{{AFX_VIRTUAL(CEditCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	//}}AFX_VIRTUAL

// 实现
protected:
	HICON m_hIcon;	// 图标

	// 生成的消息映射函数
	//{{AFX_MSG(CEditCtrlDlg)
	virtual BOOL OnInitDialog();	// 初始化对话框
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);	// 系统命令处理
	afx_msg void OnPaint();	// 绘制对话框
	afx_msg HCURSOR OnQueryDragIcon();	// 拖拽图标查询
	// 按钮消息处理函数
	afx_msg void OnBtnShow1();	// 显示1按钮
	afx_msg void OnBtnClear1();	// 清除1按钮
	afx_msg void OnBtnShow2();	// 显示2按钮
	afx_msg void OnBtnClear2();	// 清除2按钮
	afx_msg void OnBtnCopy();	// 复制按钮(→)
	afx_msg void OnBtnExit();	// 退出按钮
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ 编译器生成的添加位置

#endif // !defined(AFX_EDITCTRLDLG_H__INCLUDED_)
