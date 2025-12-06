// ProductQuery2Dlg.cpp: 实现文件（编辑框控件应用程序 - 实验八题目二）
#include "pch.h"
#include "framework.h"
#include "ProductQuery2.h"
#include "ProductQuery2Dlg.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CProductQuery2Dlg 对话框
CProductQuery2Dlg::CProductQuery2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PRODUCTQUERY2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CProductQuery2Dlg::~CProductQuery2Dlg()
{
	// 析构函数
}

// 数据交换函数 - 关联控件变量
void CProductQuery2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1); // 左侧编辑框
	DDX_Control(pDX, IDC_EDIT2, m_edit2); // 右侧编辑框
}

// 消息映射表
BEGIN_MESSAGE_MAP(CProductQuery2Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SHOW1, OnBtnShow1)   // 显示1按钮
	ON_BN_CLICKED(IDC_BTN_CLEAR1, OnBtnClear1) // 清除1按钮
	ON_BN_CLICKED(IDC_BTN_SHOW2, OnBtnShow2)   // 显示2按钮
	ON_BN_CLICKED(IDC_BTN_CLEAR2, OnBtnClear2) // 清除2按钮
	ON_BN_CLICKED(IDC_BTN_COPY, OnBtnCopy)     // 复制按钮(→)
	ON_BN_CLICKED(IDC_BTN_EXIT, OnBtnExit)     // 退出按钮
END_MESSAGE_MAP()

// 对话框初始化函数
BOOL CProductQuery2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetWindowText(_T("编辑框控件"));
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	return TRUE;
}

void CProductQuery2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialog::OnSysCommand(nID, lParam);
}

void CProductQuery2Dlg::OnPaint()
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

HCURSOR CProductQuery2Dlg::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}

// 显示1按钮 - 在左侧编辑框显示当前时间
void CProductQuery2Dlg::OnBtnShow1()
{
	CTime currentTime = CTime::GetCurrentTime();
	CString strTime = currentTime.Format(_T("左侧编辑框 - 当前时间：%Y-%m-%d %H:%M:%S"));
	m_edit1.SetWindowText(strTime);
}

// 清除1按钮 - 清除左侧编辑框内容
void CProductQuery2Dlg::OnBtnClear1()
{
	m_edit1.SetWindowText(_T(""));
}

// 显示2按钮 - 在右侧编辑框显示当前时间
void CProductQuery2Dlg::OnBtnShow2()
{
	CTime currentTime = CTime::GetCurrentTime();
	CString strTime = currentTime.Format(_T("右侧编辑框 - 当前时间：%Y-%m-%d %H:%M:%S"));
	m_edit2.SetWindowText(strTime);
}

// 清除2按钮 - 清除右侧编辑框内容
void CProductQuery2Dlg::OnBtnClear2()
{
	m_edit2.SetWindowText(_T(""));
}

// 复制按钮(→) - 将左侧编辑框内容复制到右侧
void CProductQuery2Dlg::OnBtnCopy()
{
	CString strText;
	m_edit1.GetWindowText(strText);
	m_edit2.SetWindowText(strText);
}

// 退出按钮 - 关闭对话框
void CProductQuery2Dlg::OnBtnExit()
{
	OnOK();
}