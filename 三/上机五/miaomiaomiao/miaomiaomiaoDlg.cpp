
// miaomiaomiaoDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "miaomiaomiao.h"
#include "miaomiaomiaoDlg.h"
#include "afxdialogex.h"
#include <cmath>  // 用于sqrt函数

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmiaomiaomiaoDlg 对话框

CmiaomiaomiaoDlg::CmiaomiaomiaoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MIAOMIAOMIAO_DIALOG, pParent),
	  m_nSide1(0),
	  m_nSide2(0),
	  m_nSide3(0),
	  m_dArea(0.0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

// 数据交换函数 - 关联控件变量
void CmiaomiaomiaoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	// 关联控件和变量
	DDX_Text(pDX, IDC_EDIT_SIDE1, m_nSide1);
	DDX_Text(pDX, IDC_EDIT_SIDE2, m_nSide2);
	DDX_Text(pDX, IDC_EDIT_SIDE3, m_nSide3);
	DDX_Text(pDX, IDC_EDIT_AREA, m_dArea);
}

BEGIN_MESSAGE_MAP(CmiaomiaomiaoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	// 按钮消息映射
	ON_BN_CLICKED(IDC_BTN_CALC, &CmiaomiaomiaoDlg::OnBtnCalc)
	ON_BN_CLICKED(IDC_BTN_EXIT, &CmiaomiaomiaoDlg::OnBtnExit)
END_MESSAGE_MAP()


// CmiaomiaomiaoDlg 消息处理程序

BOOL CmiaomiaomiaoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置对话框标题
	SetWindowText(_T("计算三角形的面积"));

	// 将“关于...”菜单项添加到系统菜单中
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, _T("关于..."));
	}

	// 设置对话框图标
	SetIcon(m_hIcon, TRUE);				// 设置大图标
	SetIcon(m_hIcon, FALSE);				// 设置小图标

	// 设置面积编辑框为只读
	CEdit* pEditArea = (CEdit*)GetDlgItem(IDC_EDIT_AREA);
	if (pEditArea != nullptr)
	{
		pEditArea->SetReadOnly(TRUE);
		// 只读编辑框默认背景色已合适，无需额外设置
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmiaomiaomiaoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// 不处理关于对话框命令
	if ((nID & 0xFFF0) != IDM_ABOUTBOX)
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmiaomiaomiaoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmiaomiaomiaoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 计算面积按钮处理函数
void CmiaomiaomiaoDlg::OnBtnCalc()
{
	// 更新数据（从控件到变量）
	UpdateData(TRUE);

	// 验证三角形是否合法（任意两边之和大于第三边）
	if (m_nSide1 + m_nSide2 <= m_nSide3 || 
	    m_nSide1 + m_nSide3 <= m_nSide2 || 
	    m_nSide2 + m_nSide3 <= m_nSide1)
	{
		// 显示错误消息
		MessageBox(_T("三角形两边之和大于第三边！"), _T("警告"), MB_OK | MB_ICONWARNING);
		// 清空面积
		m_dArea = 0.0;
	}
	else
	{
		// 使用海伦公式计算三角形面积
		double s = (m_nSide1 + m_nSide2 + m_nSide3) / 2.0;
		m_dArea = sqrt(s * (s - m_nSide1) * (s - m_nSide2) * (s - m_nSide3));
	}

	// 更新数据（从变量到控件）
	UpdateData(FALSE);
}

// 退出按钮处理函数
void CmiaomiaomiaoDlg::OnBtnExit()
{
	// 关闭对话框
	OnOK();
}

