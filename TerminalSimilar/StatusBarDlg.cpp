// StatusBarDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TerminalSimilar.h"
#include "StatusBarDlg.h"


// CStatusBarDlg 对话框

IMPLEMENT_DYNAMIC(CStatusBarDlg, CDialog)

CStatusBarDlg::CStatusBarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStatusBarDlg::IDD, pParent)
{

}

CStatusBarDlg::~CStatusBarDlg()
{
	TRACE("CStatusBarDlg::~CStatusBarDlg\n");
}

void CStatusBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStatusBarDlg, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CStatusBarDlg 消息处理程序

BOOL CStatusBarDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rcClient;
	GetClientRect(&rcClient);

	pDC->FillRect(rcClient,&CBrush(RGB(230, 210 ,254)));	//RGB(237, 245 ,254)

	return TRUE;
	return CDialog::OnEraseBkgnd(pDC);
}

HBRUSH CStatusBarDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	UINT CurID = pWnd->GetDlgCtrlID();
	if (CurID == IDC_STATIC | CurID == IDC_BTN_MAX)
	{
		HBRUSH   hMYbr   =   ::CreateSolidBrush(RGB(230, 210 ,254)); 
//		pDC-> SetTextColor(RGB(255,255,255)); 
		pDC->SetBkColor(RGB(230, 210 ,254));
		pDC-> SetBkMode(TRANSPARENT); 
		return hMYbr;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

BOOL CStatusBarDlg::PreTranslateMessage( MSG* pMsg )
{
	if(pMsg->message==WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
		{
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
