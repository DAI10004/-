// CommonDialogDlg.cpp : 实现文件
// 通用对话框应用程序实现

#include "stdafx.h"
#include "CommonDialog.h"
#include "CommonDialogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommonDialogDlg 对话框

CCommonDialogDlg::CCommonDialogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCommonDialogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommonDialogDlg)
	m_strFileName = _T("无");	// 初始文件名
	m_strColor = _T("无");		// 初始颜色
	m_strFont = _T("无");		// 初始字体
	//}}AFX_DATA_INIT
	// 设置对话框图标
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

// 数据交换函数 - 关联控件变量
void CCommonDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommonDialogDlg)
	DDX_Text(pDX, IDC_STATIC_FILENAME, m_strFileName);	// 关联文件名文本
	DDX_Text(pDX, IDC_STATIC_COLOR, m_strColor);		// 关联颜色文本
	DDX_Text(pDX, IDC_STATIC_FONT, m_strFont);		// 关联字体文本
	//}}AFX_DATA_MAP
}

// 消息映射表
BEGIN_MESSAGE_MAP(CCommonDialogDlg, CDialog)
	//{{AFX_MSG_MAP(CCommonDialogDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	// 按钮消息映射
	ON_BN_CLICKED(IDC_BTN_OPENFILE, OnBtnOpenFile)	// 打开文件按钮
	ON_BN_CLICKED(IDC_BTN_SAVEFILE, OnBtnSaveFile)	// 保存文件按钮
	ON_BN_CLICKED(IDC_BTN_CHOOSECOLOR, OnBtnChooseColor)	// 选择颜色按钮
	ON_BN_CLICKED(IDC_BTN_CHOOSEFONT, OnBtnChooseFont)	// 选择字体按钮
	ON_BN_CLICKED(IDC_BTN_EXIT, OnBtnExit)	// 退出按钮
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommonDialogDlg 消息处理函数

// 对话框初始化函数
BOOL CCommonDialogDlg::OnInitDialog()
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
	SetWindowText(_T("通用对话框示例"));
	// 设置对话框图标
	SetIcon(m_hIcon, TRUE);			// 大图标
	SetIcon(m_hIcon, FALSE);			// 小图标

	return TRUE;  // 除了拖动控件外，返回TRUE
}

// 系统命令处理函数
void CCommonDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
void CCommonDialogDlg::OnPaint()
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
HCURSOR CCommonDialogDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// 打开文件按钮 - 使用CFileDialog打开文件
void CCommonDialogDlg::OnBtnOpenFile()
{
	// 创建打开文件对话框
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("所有文件 (*.*)|*.*|文本文件 (*.txt)|*.txt|图片文件 (*.bmp;*.jpg)|*.bmp;*.jpg|"), this);

	// 显示对话框
	if (dlg.DoModal() == IDOK)
	{
		// 获取选择的文件名
		m_strFileName = dlg.GetPathName();
		UpdateData(FALSE); // 将变量值更新到控件

		// 显示选择结果
		AfxMessageBox(_T("已选择文件：") + m_strFileName, MB_OK | MB_ICONINFORMATION, 0);
	}
}

// 保存文件按钮 - 使用CFileDialog保存文件
void CCommonDialogDlg::OnBtnSaveFile()
{
	// 创建保存文件对话框
	CFileDialog dlg(FALSE, _T(".txt"), _T("新建文件"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("文本文件 (*.txt)|*.txt|所有文件 (*.*)|*.*|"), this);

	// 显示对话框
	if (dlg.DoModal() == IDOK)
	{
		// 获取保存的文件名
		CString strFileName = dlg.GetPathName();
		m_strFileName = strFileName;
		UpdateData(FALSE); // 将变量值更新到控件

		// 显示保存结果
		AfxMessageBox(_T("将保存到文件：") + strFileName, MB_OK | MB_ICONINFORMATION, 0);
		
		// 这里可以添加实际的文件保存代码
		// 例如：
		// CFile file;
		// if (file.Open(strFileName, CFile::modeCreate | CFile::modeWrite))
		// {
		//     CString strContent = _T("这是保存的文件内容");
		//     file.Write(strContent, strContent.GetLength() * sizeof(TCHAR));
		//     file.Close();
		// }
	}
}

// 选择颜色按钮 - 使用CColorDialog选择颜色
void CCommonDialogDlg::OnBtnChooseColor()
{
	// 创建颜色对话框
	CColorDialog dlg(RGB(255, 0, 0), CC_FULLOPEN, this);

	// 显示对话框
	if (dlg.DoModal() == IDOK)
	{
		// 获取选择的颜色
		COLORREF color = dlg.GetColor();
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		// 格式化颜色显示文本
		CString strColor;
		strColor.Format(_T("RGB(%d, %d, %d)"), r, g, b);
		m_strColor = strColor;
		UpdateData(FALSE); // 将变量值更新到控件

		// 显示选择结果
		AfxMessageBox(_T("已选择颜色：") + strColor, MB_OK | MB_ICONINFORMATION, 0);
	}
}

// 选择字体按钮 - 使用CFontDialog选择字体
void CCommonDialogDlg::OnBtnChooseFont()
{
	// 设置字体对话框初始参数
	LOGFONT logFont;
	memset(&logFont, 0, sizeof(LOGFONT));
	logFont.lfHeight = 12;
	_tcscpy_s(logFont.lfFaceName, LF_FACESIZE, _T("宋体"));

	// 创建字体对话框
	CFontDialog dlg(&logFont, CF_EFFECTS | CF_SCREENFONTS, NULL, this);

	// 显示对话框
	if (dlg.DoModal() == IDOK)
	{
		// 获取选择的字体信息
		LOGFONT lf;
		dlg.GetCurrentFont(&lf);

		// 格式化字体显示文本
		CString strFont;
		strFont.Format(_T("%s, %dpt, %s, %s"), 
			lf.lfFaceName, 
			abs(lf.lfHeight), 
			(lf.lfWeight > FW_NORMAL) ? _T("粗体") : _T("常规"), 
			(lf.lfItalic) ? _T("斜体") : _T("常规"));
		m_strFont = strFont;
		UpdateData(FALSE); // 将变量值更新到控件

		// 显示选择结果
		AfxMessageBox(_T("已选择字体：") + strFont, MB_OK | MB_ICONINFORMATION, 0);
	}
}

// 退出按钮 - 关闭对话框
void CCommonDialogDlg::OnBtnExit()
{
	// 关闭对话框
	OnOK();
}
