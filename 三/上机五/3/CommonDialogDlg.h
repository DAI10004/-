// CommonDialogDlg.h : 头文件
// 通用对话框应用程序

#if !defined(AFX_COMMONDIALOGDLG_H__INCLUDED_)
#define AFX_COMMONDIALOGDLG_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCommonDialogDlg 对话框

class CCommonDialogDlg : public CDialog
{
// 构造
public:
	CCommonDialogDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	//{{AFX_DATA(CCommonDialogDlg)
	enum { IDD = IDD_COMMONDIALOG_DIALOG };
		// 控件关联变量
	CString m_strFileName;	// 文件名显示文本
	CString m_strColor;		// 颜色显示文本
	CString m_strFont;		// 字体显示文本
	//}}AFX_DATA

	// 类向导生成的虚函数
	//{{AFX_VIRTUAL(CCommonDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	//}}AFX_VIRTUAL

// 实现
protected:
	HICON m_hIcon;	// 图标

	// 生成的消息映射函数
	//{{AFX_MSG(CCommonDialogDlg)
	virtual BOOL OnInitDialog();	// 初始化对话框
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);	// 系统命令处理
	afx_msg void OnPaint();	// 绘制对话框
	afx_msg HCURSOR OnQueryDragIcon();	// 拖拽图标查询
	// 按钮消息处理函数
	afx_msg void OnBtnOpenFile();	// 打开文件按钮
	afx_msg void OnBtnSaveFile();	// 保存文件按钮
	afx_msg void OnBtnChooseColor();	// 选择颜色按钮
	afx_msg void OnBtnChooseFont();	// 选择字体按钮
	afx_msg void OnBtnExit();	// 退出按钮
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ 编译器生成的添加位置

#endif // !defined(AFX_COMMONDIALOGDLG_H__INCLUDED_)
