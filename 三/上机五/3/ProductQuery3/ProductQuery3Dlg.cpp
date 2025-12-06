
// ProductQuery3Dlg.cpp: 实现文件（通用对话框应用程序 - 实验八题目三）
#include "pch.h"
#include "framework.h"
#include "ProductQuery3.h"
#include "ProductQuery3Dlg.h"
#include "resource.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CProductQuery3Dlg 对话框
CProductQuery3Dlg::CProductQuery3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRODUCTQUERY3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProductQuery3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

// 消息映射表
BEGIN_MESSAGE_MAP(CProductQuery3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_OPENFILE, &CProductQuery3Dlg::OnBtnOpenFile)   // 打开文件
	ON_BN_CLICKED(IDC_BTN_SAVEFILE, &CProductQuery3Dlg::OnBtnSaveFile)   // 保存文件
	ON_BN_CLICKED(IDC_BTN_CHOOSECOLOR, &CProductQuery3Dlg::OnBtnChooseColor) // 选择颜色
	ON_BN_CLICKED(IDC_BTN_CHOOSEFONT, &CProductQuery3Dlg::OnBtnChooseFont)  // 选择字体
	ON_BN_CLICKED(IDC_BTN_EXIT, &CProductQuery3Dlg::OnBtnExit)         // 退出
END_MESSAGE_MAP()

// 对话框初始化函数
BOOL CProductQuery3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 设置对话框图标
	SetIcon(m_hIcon, TRUE);  // 大图标
	SetIcon(m_hIcon, FALSE); // 小图标
	return TRUE;
}

void CProductQuery3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

// 绘制对话框
void CProductQuery3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
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
		CDialogEx::OnPaint();
	}
}

// 拖拽图标查询函数
HCURSOR CProductQuery3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 打开文件按钮事件处理函数
void CProductQuery3Dlg::OnBtnOpenFile()
{
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("所有文件 (*.*)|*.*|文本文件 (*.txt)|*.txt|"), this);
	if (dlg.DoModal() == IDOK)
	{
		CString strFileName = dlg.GetPathName();
		MessageBox(strFileName, _T("选择的文件路径"), MB_OK);
	}
}

// 保存文件按钮事件处理函数
void CProductQuery3Dlg::OnBtnSaveFile()
{
	CFileDialog dlg(FALSE, _T("txt"), _T("新建文件.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("文本文件 (*.txt)|*.txt|所有文件 (*.*)|*.*|"), this);
	if (dlg.DoModal() == IDOK)
	{
		CString strFileName = dlg.GetPathName();
		MessageBox(strFileName, _T("保存的文件路径"), MB_OK);
	}
}

// 选择颜色按钮事件处理函数
void CProductQuery3Dlg::OnBtnChooseColor()
{
	CColorDialog dlg(RGB(255, 0, 0), CC_FULLOPEN, this);
	if (dlg.DoModal() == IDOK)
	{
		COLORREF color = dlg.GetColor();
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		CString strColor;
		strColor.Format(_T("RGB(%d, %d, %d)"), r, g, b);
		MessageBox(strColor, _T("选择的颜色"), MB_OK);
	}
}

// 选择字体按钮事件处理函数
void CProductQuery3Dlg::OnBtnChooseFont()
{
	LOGFONT logFont;
	memset(&logFont, 0, sizeof(LOGFONT));
	logFont.lfHeight = 12;
	_tcscpy_s(logFont.lfFaceName, LF_FACESIZE, _T("宋体"));

	CFontDialog dlg(&logFont, CF_EFFECTS | CF_SCREENFONTS, NULL, this);
	if (dlg.DoModal() == IDOK)
	{
		LOGFONT lf;
		dlg.GetCurrentFont(&lf);
		CString strFont;
		strFont.Format(_T("%s, %d磅"), lf.lfFaceName, abs(lf.lfHeight) / 20);
		MessageBox(strFont, _T("选择的字体"), MB_OK);
	}
}

// 退出按钮事件处理函数
void CProductQuery3Dlg::OnBtnExit()
{
	EndDialog(IDOK);
}

