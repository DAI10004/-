// ProductQueryDlg.cpp : 实现文件
// 商品查询对话框应用程序实现（参照例10.3）

#include "pch.h"
#include "framework.h"
#include "ProductQuery.h"
#include "ProductQueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 移除商品数据常量，因为不再需要
// const CString PRODUCT_NAMES[12] = {
//         _T("毛巾"), _T("牙刷"), _T("牙膏"), _T("牙杯"),
//         _T("面包"), _T("牛奶"), _T("鸡蛋"), _T("水果"),
//         _T("手机"), _T("耳机"), _T("充电器"), _T("数据线")
// };
// 
// const float PRODUCT_PRICES[12] = {
//         5.0f, 3.0f, 8.0f, 4.0f,
//         6.0f, 5.5f, 10.0f, 8.5f,
//         1999.0f, 199.0f, 29.0f, 19.0f
// };;

// CProductQueryDlg 对话框

// IMPLEMENT_DYNAMIC(CProductQueryDlg, CDialog)  // 移除这个宏以避免RTTI错误

CProductQueryDlg::CProductQueryDlg(CWnd* pParent /*=nullptr*/)
        : CDialog(IDD_PRODUCTQUERY_DIALOG, pParent)
        , m_nCurrentCategory(0)
        , m_nCurrentProduct(0)
        , m_fCurrentPrice(8.0f)
        , m_bPurchase(TRUE)
        , m_fTotalPrice(0.0f)
        , m_pPriceLabel(nullptr)
        , m_pPriceValue(nullptr)
        , m_pCategoryCombo(nullptr)
        , m_pProductList(nullptr)
        , m_pPurchaseCheck(nullptr)
        , m_pTotalBtn(nullptr)
        , m_pExitBtn(nullptr)
{
        m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CProductQueryDlg::~CProductQueryDlg()
{
        // 清理控件指针，避免内存泄漏
        delete m_pPriceLabel;
        delete m_pPriceValue;
        delete m_pCategoryCombo;
        delete m_pProductList;
        delete m_pPurchaseCheck;
        delete m_pTotalBtn;
        delete m_pExitBtn;
}

// 数据交换函数 - 关联控件变量
void CProductQueryDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        // 移除所有控件绑定，因为资源中没有这些控件
        // DDX_Control(pDX, IDC_CMB_CATEGORY, m_cmbCategory);
        // DDX_Control(pDX, IDC_LST_PRODUCTS, m_lstProducts);
        // DDX_Text(pDX, IDC_STATIC_PRICE, m_strPrice);
        // DDX_Check(pDX, IDC_CHECK_PURCHASE, m_bPurchase);
}

// 消息映射表（参照例10.3的消息映射）
BEGIN_MESSAGE_MAP(CProductQueryDlg, CDialog)
        ON_WM_SYSCOMMAND()
        ON_WM_PAINT()
        ON_WM_QUERYDRAGICON()
        ON_CBN_SELCHANGE(1000, &CProductQueryDlg::OnCbnSelchangeCategory)      // 类别组合框
        ON_LBN_SELCHANGE(1001, &CProductQueryDlg::OnLbnSelchangeProducts)      // 商品列表框
        ON_BN_CLICKED(1003, &CProductQueryDlg::OnBnClickedTotal)              // 总数按钮
        ON_BN_CLICKED(1004, &CProductQueryDlg::OnBnClickedExit)               // 退出按钮
END_MESSAGE_MAP()

// CProductQueryDlg 消息处理函数

// 对话框初始化函数（参照例10.3的OnInitDialog）
BOOL CProductQueryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置对话框标题
	SetWindowText(_T("购物表单"));
	// 设置对话框图标
	SetIcon(m_hIcon, TRUE);                 // 大图标
	SetIcon(m_hIcon, FALSE);                        // 小图标

        // 初始化商品数据
        InitProductData();

	// 在对话框上动态创建商品列表显示
	// 1. 移除默认的TODO文本
	CWnd* pStatic = GetDlgItem(IDC_STATIC);
	if (pStatic)
	{
		pStatic->ShowWindow(SW_HIDE); // 隐藏默认文本
	}

	// 2. 创建价格显示
	m_pPriceLabel = new CStatic;
	m_pPriceLabel->Create(_T("价格："), WS_CHILD | WS_VISIBLE | SS_LEFT, 
		CRect(50, 50, 100, 65), this);
	
	m_pPriceValue = new CStatic;
	m_pPriceValue->Create(_T("8.0元"), WS_CHILD | WS_VISIBLE | SS_LEFT, 
		CRect(110, 50, 170, 65), this);
	m_pPriceValue->SetFont(&CFont(), FALSE);

	// 3. 创建商品类别下拉框
	m_pCategoryCombo = new CComboBox;
	m_pCategoryCombo->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_VSCROLL, 
		CRect(110, 80, 200, 140), this, 1000);
	// 添加类别选项
	m_pCategoryCombo->AddString(_T("日常用品"));
	m_pCategoryCombo->AddString(_T("食品"));
	m_pCategoryCombo->AddString(_T("电子产品"));
	m_pCategoryCombo->SetCurSel(0); // 默认选择第一个类别

	// 4. 创建类别商品列表
	m_pProductList = new CListBox;
	m_pProductList->Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | LBS_STANDARD, 
		CRect(110, 100, 200, 150), this, 1001);
	// 添加日常用品列表
	m_pProductList->AddString(_T("毛巾"));
	m_pProductList->AddString(_T("牙刷"));
	m_pProductList->AddString(_T("牙膏"));
	m_pProductList->AddString(_T("牙杯"));
	m_pProductList->SetCurSel(0); // 默认选择第一个商品

	// 5. 创建购买复选框
	m_pPurchaseCheck = new CButton;
	m_pPurchaseCheck->Create(_T("购买"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 
		CRect(110, 160, 170, 175), this, 1002);
	m_pPurchaseCheck->SetCheck(BST_CHECKED); // 默认勾选

	// 6. 创建按钮
	m_pTotalBtn = new CButton;
	m_pTotalBtn->Create(_T("总数"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 
		CRect(80, 180, 130, 195), this, 1003);
	
	m_pExitBtn = new CButton;
	m_pExitBtn->Create(_T("退出"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 
		CRect(150, 180, 200, 195), this, 1004);

	// 7. 隐藏默认的确定和取消按钮
	CWnd* pOKBtn = GetDlgItem(IDOK);
	if (pOKBtn)
	{
		pOKBtn->ShowWindow(SW_HIDE);
	}
	
	CWnd* pCancelBtn = GetDlgItem(IDCANCEL);
	if (pCancelBtn)
	{
		pCancelBtn->ShowWindow(SW_HIDE);
	}

	// 不再需要动态调整窗口大小，已在资源文件中设置固定大小
	// SetWindowPos(NULL, 0, 0, 300, 260, SWP_NOMOVE | SWP_NOZORDER);

	return TRUE;  // 除了拖动控件外，返回TRUE
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
                CPaintDC dc(this); // 用于绘制的设备上下文

                SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

                // 居中图标在客户区
                int cxIcon = GetSystemMetrics(SM_CXICON);
                int cyIcon = GetSystemMetrics(SM_CYICON);
                CRect rect;
                GetClientRect(&rect);
                int x = (rect.Width() - cxIcon + 1) / 2;
                int y = (rect.Height() - cyIcon + 1) / 2;

                // 绘制图标
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
        return static_cast<HCURSOR>(m_hIcon);
}

// 商品数据初始化函数
void CProductQueryDlg::InitProductData()
{
        // 初始化商品类别
        m_categories[0] = _T("日常用品");
        m_categories[1] = _T("食品");
        m_categories[2] = _T("电子产品");

        // 初始化商品数据，价格在10上下
        // 日常用品
        m_products[0] = { _T("毛巾"), _T("日常用品"), 12.0f };
        m_products[1] = { _T("牙刷"), _T("日常用品"), 8.0f };
        m_products[2] = { _T("牙膏"), _T("日常用品"), 15.0f };
        m_products[3] = { _T("牙杯"), _T("日常用品"), 6.0f };

        // 食品
        m_products[4] = { _T("面包"), _T("食品"), 9.0f };
        m_products[5] = { _T("牛奶"), _T("食品"), 11.0f };
        m_products[6] = { _T("鸡蛋"), _T("食品"), 12.5f };
        m_products[7] = { _T("水果"), _T("食品"), 18.0f };

        // 电子产品
        m_products[8] = { _T("手机"), _T("电子产品"), 1999.0f };
        m_products[9] = { _T("耳机"), _T("电子产品"), 199.0f };
        m_products[10] = { _T("充电器"), _T("电子产品"), 25.0f };
        m_products[11] = { _T("数据线"), _T("电子产品"), 15.0f };
}

// 根据类别更新商品列表
void CProductQueryDlg::UpdateProductList()
{
        // 清空商品列表
        m_pProductList->ResetContent();

        // 获取当前选中的类别
        CString strCategory = m_categories[m_nCurrentCategory];

        // 添加对应类别的商品到列表
        for (int i = 0; i < 12; i++)
        {
                if (m_products[i].category == strCategory)
                {
                        m_pProductList->AddString(m_products[i].name);
                }
        }

        // 默认选择第一个商品
        if (m_pProductList->GetCount() > 0)
        {
                m_pProductList->SetCurSel(0);
                m_nCurrentProduct = 0;
                UpdatePriceDisplay();
        }
}

// 更新价格显示
void CProductQueryDlg::UpdatePriceDisplay()
{
        // 获取当前选中的类别
        CString strCategory = m_categories[m_nCurrentCategory];
        
        // 获取当前选中的商品名称
        CString strProduct;
        m_pProductList->GetText(m_nCurrentProduct, strProduct);

        // 查找商品价格
        for (int i = 0; i < 12; i++)
        {
                if (m_products[i].category == strCategory && m_products[i].name == strProduct)
                {
                        m_fCurrentPrice = m_products[i].price;
                        break;
                }
        }

        // 更新价格显示
        CString strPrice;
        strPrice.Format(_T("%.1f元"), m_fCurrentPrice);
        m_pPriceValue->SetWindowText(strPrice);
}

// 计算总价
void CProductQueryDlg::CalculateTotal()
{
        // 检查是否勾选购买
        m_bPurchase = (m_pPurchaseCheck->GetCheck() == BST_CHECKED);
        
        if (m_bPurchase)
        {
                m_fTotalPrice += m_fCurrentPrice;
        }
}

// 类别选择改变事件
void CProductQueryDlg::OnCbnSelchangeCategory()
{
        // 获取当前选中的类别索引
        m_nCurrentCategory = m_pCategoryCombo->GetCurSel();
        
        // 更新商品列表
        UpdateProductList();
}

// 商品选择改变事件
void CProductQueryDlg::OnLbnSelchangeProducts()
{
        // 获取当前选中的商品索引
        m_nCurrentProduct = m_pProductList->GetCurSel();
        
        // 更新价格显示
        UpdatePriceDisplay();
}

// 总数按钮点击事件
void CProductQueryDlg::OnBnClickedTotal()
{
        // 计算总价
        CalculateTotal();
        
        // 显示总价信息
        CString strMsg;
        strMsg.Format(_T("当前总价：%.1f元"), m_fTotalPrice);
        AfxMessageBox(strMsg, MB_OK | MB_ICONINFORMATION, 0);
}

// 退出按钮点击事件
void CProductQueryDlg::OnBnClickedExit()
{
        // 清理临时数据
        m_fTotalPrice = 0.0f;
        
        // 关闭对话框
        OnOK();
}