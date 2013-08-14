// TerminalSimilarDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TerminalSimilar.h"
#include "TerminalSimilarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CTerminalSimilarDlg �Ի���




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


// CTerminalSimilarDlg ��Ϣ�������

BOOL CTerminalSimilarDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	UIInit();

	MoveDlg();
//	MoveFullDlg();


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTerminalSimilarDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	::SystemParametersInfo(SPI_GETWORKAREA, 0, &rc, 0);		//��ȡ����ռ��С,������������
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ˴������Ϣ����������
}
