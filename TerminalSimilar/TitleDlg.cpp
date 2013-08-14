// TitleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TerminalSimilar.h"
#include "TitleDlg.h"
#include "TerminalSimilarDlg.h"

#include "global.h"

// CTitleDlg �Ի���

IMPLEMENT_DYNAMIC(CTitleDlg, CDialog)

CTitleDlg::CTitleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTitleDlg::IDD, pParent)
	, bFlag(FALSE)
	, pMenu(NULL)
{

}

CTitleDlg::~CTitleDlg()
{
	TRACE("CTitleDlg::~CTitleDlg\n");
	if(pMenu)
	{
		pMenu->DestroyMenu();
		delete pMenu;
		pMenu = NULL;
	}
}

void CTitleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTitleDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_MAX,	&CTitleDlg::OnBnClickedBtnMax)
	ON_COMMAND(ID_Menu_1,		&CTitleDlg::SubMenuItem1)
	ON_COMMAND(ID_Menu2,		&CTitleDlg::SubMenuItem2)
	ON_COMMAND(ID_MENU_TEST1,	&CTitleDlg::SubMenuItem1)
	ON_COMMAND(ID_MENU_TEST2,	&CTitleDlg::SubMenuItem2)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BTN_MENU, &CTitleDlg::OnBnClickedBtnMenu)
	ON_BN_CLICKED(IDC_BTN_EXIT, &CTitleDlg::OnBnClickedBtnExit)
END_MESSAGE_MAP()


// CTitleDlg ��Ϣ�������

void CTitleDlg::OnBnClickedBtnMax()
{
	bFlag = !bFlag;
	if(bFlag)
		g_MainFrame->MoveFullDlg();
	else
		g_MainFrame->MoveDlg();
}

BOOL CTitleDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rcClient;
	GetClientRect(&rcClient);

	pDC->FillRect(rcClient,&CBrush(RGB(220, 220 ,254)));	//RGB(237, 245 ,254)

	return TRUE;
	return CDialog::OnEraseBkgnd(pDC);
}

HBRUSH CTitleDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	UINT CurID = pWnd->GetDlgCtrlID();
	if (CurID == IDC_STATIC | CurID == IDC_BTN_MAX)
	{
		HBRUSH   hMYbr   =   ::CreateSolidBrush(RGB(220, 220 ,254)); 
//		pDC-> SetTextColor(RGB(255,255,255)); 
		pDC->SetBkColor(RGB(220, 220 ,254));
		pDC-> SetBkMode(TRANSPARENT); 
		return hMYbr;
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

BOOL CTitleDlg::PreTranslateMessage( MSG* pMsg )
{
	if(pMsg->message==WM_KEYDOWN)
	{
// 		if (pMsg->wParam == VK_ESCAPE && g_pMainFrame->m_bFullVideo)
// 		{
// 			g_pMainFrame->FullScreen(0,!g_pMainFrame->m_bFullVideo);
// 		}

		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
		{
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CTitleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_menu.LoadMenu(IDR_MENU1);

	InitUI();

	return TRUE;
}

void CTitleDlg::InitUI()
{
	pMenu = new CMenu();
	pMenu->CreatePopupMenu();     //��̬��������ʽ�˵�����
	pMenu->AppendMenu(MF_STRING,ID_MENU_TEST1," �˵���1");
	pMenu->AppendMenu(MF_STRING,ID_MENU_TEST2," �˵���2");
	pMenu->InsertMenu(2,MF_BYPOSITION|MF_POPUP|MF_STRING, (UINT)m_menu.m_hMenu,"�Ӳ˵�"); //����Ӳ˵�
}

void CTitleDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	CPoint pt;
	GetCursorPos(&pt);
	pMenu->TrackPopupMenu(TPM_RIGHTBUTTON, pt.x, pt.y, this);

	CDialog::OnRButtonUp(nFlags, point);
}

void CTitleDlg::SubMenuItem1()
{
	AfxMessageBox("��һ��");
}

void CTitleDlg::SubMenuItem2()
{
	AfxMessageBox("�ڶ���");
}

void CTitleDlg::OnBnClickedBtnMenu()
{
	CMenu * pMenu = m_menu.GetSubMenu(0);
	CPoint pt;
	CRect rc;
	GetDlgItem(IDC_BTN_MENU)->GetWindowRect(&rc);
	pt.x = rc.left;
	pt.y = rc.top + rc.Height() + 2;

	pMenu->TrackPopupMenu(TPM_RIGHTBUTTON, pt.x, pt.y, this);
}


void CTitleDlg::OnBnClickedBtnExit()
{
	g_MainFrame->PostMessage(WM_DESTROY);
}
