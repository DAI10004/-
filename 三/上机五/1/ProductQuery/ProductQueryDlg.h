// ProductQueryDlg.h : 头文件
// 商品查询对话框应用程序（参照例10.3）

#pragma once

#include "Resource.h"

// 商品信息结构体
typedef struct tagProductInfo {
	CString name;     // 商品名称
	CString category; // 商品类别
	float price;      // 商品价格
} ProductInfo;

// CProductQueryDlg 对话框
class CProductQueryDlg : public CDialog
{
// 构造
public:
	CProductQueryDlg(CWnd* pParent = nullptr);	// 标准构造函数
	virtual ~CProductQueryDlg();	// 析构函数

// 对话框数据
	#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRODUCTQUERY_DIALOG };
	#endif

// 实现
protected:
	HICON m_hIcon;

	// 数据交换函数
	virtual void DoDataExchange(CDataExchange* pDX);

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCbnSelchangeCategory();      // 类别选择改变
	afx_msg void OnLbnSelchangeProducts();      // 商品选择改变
	afx_msg void OnBnClickedTotal();            // 总数按钮
	afx_msg void OnBnClickedExit();             // 退出按钮
	DECLARE_MESSAGE_MAP()
private:
	// 商品数据
	ProductInfo m_products[12];       // 商品数据库
	CString m_categories[3];          // 类别数组
	
	// 控件指针
	CStatic* m_pPriceLabel;           // 价格标签
	CStatic* m_pPriceValue;           // 价格值显示
	CComboBox* m_pCategoryCombo;      // 商品类别组合框
	CListBox* m_pProductList;         // 商品列表框
	CButton* m_pPurchaseCheck;        // 购买复选框
	CButton* m_pTotalBtn;             // 总数按钮
	CButton* m_pExitBtn;              // 退出按钮
	
	// 状态变量
	int m_nCurrentCategory;           // 当前选中的类别索引
	int m_nCurrentProduct;            // 当前选中的商品索引
	float m_fCurrentPrice;            // 当前商品价格
	BOOL m_bPurchase;                 // 购买状态
	
	// 总数计算
	float m_fTotalPrice;              // 总价
	
	// 功能函数
	void InitProductData();           // 初始化商品数据
	void UpdateProductList();         // 更新商品列表
	void UpdatePriceDisplay();        // 更新价格显示
	void CalculateTotal();            // 计算总价
};

