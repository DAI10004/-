// EditCtrlDlg.cpp : 实现文件
// 编辑框控件对话框应用程序实现

#include "stdafx.h"
#include "EditCtrl.h"
#include "EditCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditCtrlDlg 对话框

CEditCtrlDlg::CEditCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditCtrlDlg)
	//}}AFX_DATA_INIT
	// 设置对话框图标
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

// 数据交换函数 - 关联控件变量
void CEditCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditCtrlDlg)
	DDX_Control(pDX, IDC_EDIT1, m_edit1);	// 关联左侧编辑框
	DDX_Control(pDX, IDC_EDIT2, m_edit2);	// 关联右侧编辑框
	//}}AFX_DATA_MAP
}

// 消息映射表
BEGIN_MESSAGE_MAP(CEditCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CEditCtrlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	// 按钮消息映射
	ON_BN_CLICKED(IDC_BTN_SHOW1, OnBtnShow1)	// 显示1按钮
	ON_BN_CLICKED(IDC_BTN_CLEAR1, OnBtnClear1)	// 清除1按钮
	ON_BN_CLICKED(IDC_BTN_SHOW2, OnBtnShow2)	// 显示2按钮
	ON_BN_CLICKED(IDC_BTN_CLEAR2, OnBtnClear2)	// 清除2按钮
	ON_BN_CLICKED(IDC_BTN_COPY, OnBtnCopy)	// 复制按钮(→)
	ON_BN_CLICKED(IDC_BTN_EXIT, OnBtnExit)	// 退出按钮
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditCtrlDlg 消息处理函数

// 对话框初始化函数
BOOL CEditCtrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 添加系统菜单命令
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置对话框标题
	SetWindowText(_T("编辑框控件"));
	// 设置对话框图标
	SetIcon(m_hIcon, TRUE);			// 大图标
	SetIcon(m_hIcon, FALSE);			// 小图标

	return TRUE;  // 除了拖动控件外，返回TRUE
}

// 系统命令处理函数
void CEditCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 绘制对话框
void CEditCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);

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
HCURSOR CEditCtrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// 显示1按钮 - 在左侧编辑框显示文本
void CEditCtrlDlg::OnBtnShow1()
{
	// 在左侧编辑框显示自定义字符串
	m_edit1.SetWindowText(_T("左侧编辑框内容"));
}

// 清除1按钮 - 清除左侧编辑框内容
void CEditCtrlDlg::OnBtnClear1()
{
	// 清除左侧编辑框内容
	m_edit1.SetWindowText(_T(""));
}

// 显示2按钮 - 在右侧编辑框显示文本
void CEditCtrlDlg::OnBtnShow2()
{
	// 在右侧编辑框显示自定义字符串
	m_edit2.SetWindowText(_T("右侧编辑框内容"));
}

// 清除2按钮 - 清除右侧编辑框内容
void CEditCtrlDlg::OnBtnClear2()
{
	// 清除右侧编辑框内容
	m_edit2.SetWindowText(_T(""));
}

// 复制按钮(→) - 将左侧编辑框内容复制到右侧
void CEditCtrlDlg::OnBtnCopy()
{
	CString strText;	// 用于存储编辑框内容
	// 获取左侧编辑框内容
	m_edit1.GetWindowText(strText);
	// 将内容设置到右侧编辑框
	m_edit2.SetWindowText(strText);
}

// 退出按钮 - 关闭对话框
void CEditCtrlDlg::OnBtnExit()
{
	// 关闭对话框
	OnOK();
}
