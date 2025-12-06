
// ProductQuery3Dlg.h: 头文件（通用对话框应用程序 - 实验八题目三）
#pragma once

// CProductQuery3Dlg 对话框类
class CProductQuery3Dlg : public CDialogEx
{
public:
	CProductQuery3Dlg(CWnd* pParent = nullptr); // 标准构造函数

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRODUCTQUERY3_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 支持

protected:
	HICON m_hIcon;

	// 按钮事件处理函数
	afx_msg void OnBtnOpenFile();    // 打开文件
	afx_msg void OnBtnSaveFile();    // 保存文件
	afx_msg void OnBtnChooseColor(); // 选择颜色
	afx_msg void OnBtnChooseFont();  // 选择字体
	afx_msg void OnBtnExit();        // 退出

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
