// TerminalSimilarDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TerminalSimilar.h"
#include "TerminalSimilarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTerminalSimilarDlg 对话框




CTerminalSimilarDlg::CTerminalSimilarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTerminalSimilarDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


CTerminalSimilarDlg::~CTerminalSimilarDlg()
{
	TRACE("CTerminalSimilarDlg::~CTerminalSimilarDlg\n");
	if(m_pTitleDlg)
	{
		delete m_pTitleDlg;
		m_pTitleDlg = NULL;
	}
	
	if(m_pTreeDlg)
	{
		delete m_pTreeDlg;
		m_pTreeDlg = NULL;
	}

	if(m_pStatusBarDlg)
	{
		delete m_pStatusBarDlg;
		m_pStatusBarDlg = NULL;
	}
}


void CTerminalSimilarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTerminalSimilarDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CTerminalSimilarDlg 消息处理程序

BOOL CTerminalSimilarDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	UIInit();

	MoveDlg();
//	MoveFullDlg();


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTerminalSimilarDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTerminalSimilarDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTerminalSimilarDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTerminalSimilarDlg::UIInit()
{
	m_pTitleDlg = new CTitleDlg();
	m_pTitleDlg->Create(IDD_DLG_TITLE, this);
	m_pTitleDlg->ShowWindow(TRUE);

	m_pTreeDlg = new CTreeDlg();
	m_pTreeDlg->Create(IDD_DLG_TREE, this);
	m_pTreeDlg->ShowWindow(TRUE);

	m_pStatusBarDlg = new CStatusBarDlg();
	m_pStatusBarDlg->Create(IDD_DLG_STATUSBAR, this);
	m_pStatusBarDlg->ShowWindow(TRUE);
}

void CTerminalSimilarDlg::MoveDlg()
{
	CRect rc;
	::SystemParametersInfo(SPI_GETWORKAREA, 0, &rc, 0);		//获取桌面空间大小,不包括任务栏
	int ixStart = (rc.Width() - CLIENT_WIDTH)/2;
	int iyStart = (rc.Height() - CLIENT_HIGHT)/2;

	MoveWindow(ixStart, iyStart-5, CLIENT_WIDTH, rc.Height());

	m_pTitleDlg->MoveWindow(0, 0, CLIENT_WIDTH, TITLE_HIGHT);
	m_pTreeDlg->MoveWindow(0, 
							TITLE_HIGHT + 2, 
							TREE_WIDTH, 
							rc.Height() - TITLE_HIGHT - STATUSBAR_HIGHT - BOTTON_INTERVAL - 2);
	m_pStatusBarDlg->MoveWindow(0, rc.Height() - STATUSBAR_HIGHT, CLIENT_WIDTH, STATUSBAR_HIGHT);

	Invalidate();
}

void CTerminalSimilarDlg::MoveFullDlg()
{
	CRect rc;
	::SystemParametersInfo(SPI_GETWORKAREA, 0, &rc, 0);
	int ixStart = 0;
	int iyStart = 0;

	MoveWindow(ixStart, iyStart, rc.Width(), rc.Height());

	m_pTitleDlg->MoveWindow(0, 0, rc.Width(), TITLE_HIGHT);
	m_pTreeDlg->MoveWindow(0, 
							TITLE_HIGHT + 2, 
							TREE_WIDTH, 
							rc.Height() - TITLE_HIGHT - STATUSBAR_HIGHT - BOTTON_INTERVAL - 2);
	m_pStatusBarDlg->MoveWindow(0, rc.Height() - STATUSBAR_HIGHT, rc.Width(), STATUSBAR_HIGHT);


	Invalidate();
}


BOOL CTerminalSimilarDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rcClient;
	GetClientRect(&rcClient);

	pDC->FillRect(rcClient,&CBrush(RGB(237, 230 ,254)));	//RGB(237, 245 ,254)

	return TRUE;
	return CDialog::OnEraseBkgnd(pDC);
}

void CTerminalSimilarDlg::OnDestroy()
{
	CDialog::OnDestroy();
	
	OnCancel();
	// TODO: 在此处添加消息处理程序代码
}
