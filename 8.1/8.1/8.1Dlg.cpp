
// 8.1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "8.1.h"
#include "8.1Dlg.h"
#include "afxdialogex.h"

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


// CMy81Dlg 对话框



CMy81Dlg::CMy81Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY81_DIALOG, pParent)
	, a1(0)
	, a2(0)
	, a3(0)
	, b1(0)
	, b2(0)
	, c1(0)
	, S(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy81Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, a1);
	DDX_Text(pDX, IDC_EDIT3, a2);
	DDX_Text(pDX, IDC_EDIT1, a3);
	DDX_Text(pDX, IDC_EDIT7, b1);
	DDX_Text(pDX, IDC_EDIT6, b2);
	DDX_Text(pDX, IDC_EDIT4, c1);
	DDX_Text(pDX, IDC_EDIT5, S);
}

BEGIN_MESSAGE_MAP(CMy81Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMy81Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy81Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy81Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy81Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy81Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy81Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CMy81Dlg 消息处理程序

BOOL CMy81Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy81Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy81Dlg::OnPaint()
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
HCURSOR CMy81Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy81Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	a3 = a1 + a2;
	UpdateData(false);
}


void CMy81Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	a3 = a1 - a2;
	UpdateData(false);
}


void CMy81Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	a3 = a1 * a2;
	UpdateData(false);
}


void CMy81Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	a3 = a1 / a2;
	UpdateData(false);
}


void CMy81Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	b2 = sqrt(b1);
	UpdateData(false);
}


void CMy81Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CString s;
	if (c1 < 0) {
		S= "-1/";
		c1 = -c1;
		s.Format(_T("%d"), c1);
		S = S + s;
	}
	else if (c1> 0) {
		S = "1/";
		s.Format(_T("%d"), c1);
		S = S + s;
	}
	else
	{
		S = "不能为0！";
	}
	UpdateData(false);
}
