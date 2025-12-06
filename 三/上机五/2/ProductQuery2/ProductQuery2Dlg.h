
// ProductQuery2Dlg.h: 头文件
// 编辑框控件应用程序（实验八题目二）

#pragma once

// CProductQuery2Dlg 对话框
class CProductQuery2Dlg : public CDialog
{
// 构造
public:
	CProductQuery2Dlg(CWnd* pParent = nullptr);	// 标准构造函数
	~CProductQuery2Dlg();	// 析构函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRODUCTQUERY2_DIALOG };
#endif

	// 控件关联变量
	CEdit m_edit1;  // 左侧编辑框
	CEdit m_edit2;  // 右侧编辑框

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
	// 按钮消息处理函数
	afx_msg void OnBtnShow1();     // 显示1按钮
	afx_msg void OnBtnClear1();    // 清除1按钮
	afx_msg void OnBtnShow2();     // 显示2按钮
	afx_msg void OnBtnClear2();    // 清除2按钮
	afx_msg void OnBtnCopy();      // 复制按钮(→)
	afx_msg void OnBtnExit();      // 退出按钮
	
	DECLARE_MESSAGE_MAP()
};
