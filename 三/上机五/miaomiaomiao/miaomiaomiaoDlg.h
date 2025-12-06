
// miaomiaomiaoDlg.h: 头文件
// 三角形面积计算程序

#pragma once


// CmiaomiaomiaoDlg 对话框
class CmiaomiaomiaoDlg : public CDialogEx
{
// 构造
public:
	CmiaomiaomiaoDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MIAOMIAOMIAO_DIALOG };
#endif

	// 控件关联变量
	int m_nSide1;  // 第一条边长
	int m_nSide2;  // 第二条边长
	int m_nSide3;  // 第三条边长
	double m_dArea;  // 三角形面积

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	// 消息处理函数
	afx_msg void OnBtnCalc();  // 计算面积按钮
	afx_msg void OnBtnExit();  // 退出按钮

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
