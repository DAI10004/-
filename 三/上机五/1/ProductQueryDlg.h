// ProductQueryDlg.h : 头文件
// 商品查询对话框应用程序（参照例10.3实现）

#if !defined(AFX_PRODUCTQUERYDLG_H__INCLUDED_)
#define AFX_PRODUCTQUERYDLG_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProductQueryDlg 对话框

class CProductQueryDlg : public CDialog
{
// 构造
public:
	CProductQueryDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	//{{AFX_DATA(CProductQueryDlg)
	enum { IDD = IDD_PRODUCTQUERY_DIALOG };
		// 控件关联变量
	CComboBox m_cmbCategory;	// 商品类别组合框
	CListBox m_lstProducts;	// 商品列表框
	CString m_strPrice;		// 价格显示文本
	BOOL m_bPurchase;		// 购买复选框状态
	//}}AFX_DATA

	// 类向导生成的虚函数
	//{{AFX_VIRTUAL(CProductQueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	//}}AFX_VIRTUAL

// 实现
protected:
	HICON m_hIcon;	// 图标

	// 生成的消息映射函数
	//{{AFX_MSG(CProductQueryDlg)
	virtual BOOL OnInitDialog();	// 初始化对话框
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);	// 系统命令处理
	afx_msg void OnPaint();	// 绘制对话框
	afx_msg HCURSOR OnQueryDragIcon();	// 拖拽图标查询
	// 按钮消息处理函数
	afx_msg void OnBtnTotal();	// 计算总价按钮
	afx_msg void OnBtnExit();	// 退出按钮
	// 组合框消息映射
	afx_msg void OnSelchangeCmbCategory();	// 类别选择改变
	// 列表框消息映射
	afx_msg void OnSelchangeLstProducts();	// 商品选择改变
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	// 商品信息结构体（参照例10.3的course结构体）
	struct ProductInfo {
		CString name;     // 商品名称
		CString category; // 商品类别
		float price;      // 商品价格
		BOOL selected;    // 是否选中
	};

	// 商品数据库（参照例10.3的course数组）
	ProductInfo m_products[12];

	// 类别数组
	CString m_categories[3];

	// 初始化商品数据（参照例10.3的初始化方式）
	void InitProductData();

	// 根据类别更新商品列表
	void UpdateProductList();

	// 计算总价
	float CalculateTotal();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ 编译器生成的添加位置

#endif // !defined(AFX_PRODUCTQUERYDLG_H__INCLUDED_)
