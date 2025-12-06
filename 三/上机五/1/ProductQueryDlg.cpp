// ProductQueryDlg.cpp : 实现文件（商品查询对话框应用程序）
#include "stdafx.h"
#include "ProductQuery.h"
#include "ProductQueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 商品数据常量
const CString PRODUCT_NAMES[12] = {
	_T("毛巾"), _T("牙刷"), _T("牙膏"), _T("牙杯"),
	_T("面包"), _T("牛奶"), _T("鸡蛋"), _T("水果"),
	_T("手机"), _T("耳机"), _T("充电器"), _T("数据线")
};

const float PRODUCT_PRICES[12] = {
	5.0f, 3.0f, 8.0f, 4.0f, 6.0f, 5.5f, 10.0f, 8.5f,
	1999.0f, 199.0f, 29.0f, 19.0f
};

// CProductQueryDlg 构造函数
CProductQueryDlg::CProductQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProductQueryDlg::IDD, pParent), m_strPrice(_T("6元")), m_bPurchase(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

// 数据交换函数 - 关联控件变量
void CProductQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CMB_CATEGORY, m_cmbCategory);
	DDX_Control(pDX, IDC_LST_PRODUCTS, m_lstProducts);
	DDX_Text(pDX, IDC_STATIC_PRICE, m_strPrice);
	DDX_Check(pDX, IDC_CHECK_PURCHASE, m_bPurchase);
}

// 消息映射表
BEGIN_MESSAGE_MAP(CProductQueryDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_TOTAL, OnBtnTotal)
	ON_BN_CLICKED(IDC_BTN_EXIT, OnBtnExit)
	ON_CBN_SELCHANGE(IDC_CMB_CATEGORY, OnSelchangeCmbCategory)
	ON_LBN_SELCHANGE(IDC_LST_PRODUCTS, OnSelchangeLstProducts)
END_MESSAGE_MAP()

// 对话框初始化函数
BOOL CProductQueryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetWindowText(_T("购物表单"));
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	// 初始化商品数据
	InitProductData();

	// 初始化类别组合框
	m_categories[0] = _T("日常用品");
	m_categories[1] = _T("食品");
	m_categories[2] = _T("电子产品");
	for (int i = 0; i < 3; i++)
		m_cmbCategory.AddString(m_categories[i]);
	m_cmbCategory.SetCurSel(0);

	// 更新商品列表
	UpdateProductList();
	return TRUE;
}

// 系统命令处理函数
void CProductQueryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialog::OnSysCommand(nID, lParam);
}

// 绘制对话框
void CProductQueryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);
		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 拖拽图标查询函数
HCURSOR CProductQueryDlg::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}

// 初始化商品数据
void CProductQueryDlg::InitProductData()
{
	for (int i = 0; i < 12; i++)
	{
		m_products[i].name = PRODUCT_NAMES[i];
		m_products[i].price = PRODUCT_PRICES[i];
		m_products[i].selected = FALSE;
		if (i < 4)
			m_products[i].category = _T("日常用品");
		else if (i < 8)
			m_products[i].category = _T("食品");
		else
			m_products[i].category = _T("电子产品");
	}
}

// 根据类别更新商品列表
void CProductQueryDlg::UpdateProductList()
{
	m_lstProducts.ResetContent();
	int nCategoryIndex = m_cmbCategory.GetCurSel();
	if (nCategoryIndex == CB_ERR) return;
	CString strCategory = m_categories[nCategoryIndex];

	for (int i = 0; i < 12; i++)
	{
		if (m_products[i].category == strCategory)
			m_lstProducts.AddString(m_products[i].name);
	}

	if (m_lstProducts.GetCount() > 0)
	{
		m_lstProducts.SetCurSel(0);
		OnSelchangeLstProducts();
	}
}

// 商品选择改变 - 更新价格显示
void CProductQueryDlg::OnSelchangeLstProducts()
{
	int nSel = m_lstProducts.GetCurSel();
	if (nSel == LB_ERR) return;
	CString strCategory = m_categories[m_cmbCategory.GetCurSel()];
	CString strProduct;
	m_lstProducts.GetText(nSel, strProduct);

	float fPrice = 0.0f;
	for (int i = 0; i < 12; i++)
	{
		if (m_products[i].category == strCategory && m_products[i].name == strProduct)
		{
			fPrice = m_products[i].price;
			break;
		}
	}

	CString strPrice;
	strPrice.Format(_T("%.1f元"), fPrice);
	m_strPrice = strPrice;
	UpdateData(FALSE);
}

// 计算总价
float CProductQueryDlg::CalculateTotal()
{
	float fTotal = 0.0f;
	if (m_bPurchase)
	{
		int nSel = m_lstProducts.GetCurSel();
		if (nSel != LB_ERR)
		{
			CString strCategory = m_categories[m_cmbCategory.GetCurSel()];
			CString strProduct;
			m_lstProducts.GetText(nSel, strProduct);
			for (int i = 0; i < 12; i++)
			{
				if (m_products[i].category == strCategory && m_products[i].name == strProduct)
				{
					fTotal = m_products[i].price;
					break;
				}
			}
		}
	}
	return fTotal;
}

// 总数按钮 - 计算选中商品的总价
void CProductQueryDlg::OnBtnTotal()
{
	UpdateData(TRUE);
	float fTotal = CalculateTotal();

	int nSel = m_lstProducts.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(_T("请先选择商品！"), MB_OK | MB_ICONWARNING, 0);
		return;
	}

	CString strProduct;
	m_lstProducts.GetText(nSel, strProduct);
	CString strCategory = m_categories[m_cmbCategory.GetCurSel()];

	CString strMsg;
	if (m_bPurchase)
	{
		strMsg.Format(_T("您所购买商品的总价为：%.1f元\n\n商品: %s\n类别: %s\n单价: %s\n购买状态: 已勾选"),
			fTotal, strProduct, strCategory, m_strPrice);
	}
	else
	{
		strMsg.Format(_T("您未勾选购买选项\n\n商品: %s\n类别: %s\n单价: %s\n购买状态: 未勾选"),
			strProduct, strCategory, m_strPrice);
	}
	AfxMessageBox(strMsg, MB_OK | MB_ICONINFORMATION, 0);
}

// 退出按钮 - 关闭对话框
void CProductQueryDlg::OnBtnExit()
{
	OnOK();
}

// 类别选择改变 - 更新商品列表
void CProductQueryDlg::OnSelchangeCmbCategory()
{
	UpdateProductList();
}
