// TreeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TerminalSimilar.h"
#include "TreeDlg.h"

#include "global.h"

// CTreeDlg 对话框

IMPLEMENT_DYNAMIC(CTreeDlg, CDialog)

CTreeDlg::CTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeDlg::IDD, pParent)
{

}

CTreeDlg::~CTreeDlg()
{
	TRACE("CTreeDlg::~CTreeDlg\n");
}

void CTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTreeDlg, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

BOOL CTreeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();


	return TRUE;
}


// CTreeDlg 消息处理程序

BOOL CTreeDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rcClient;
	GetClientRect(&rcClient);

	pDC->FillRect(rcClient,&CBrush(RGB(200, 240,240)));
	return TRUE;
	return CDialog::OnEraseBkgnd(pDC);
}

HBRUSH CTreeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	UINT CurID = pWnd->GetDlgCtrlID();
	if (CurID == IDC_STATIC | CurID == IDC_BTN_MAX)
	{
		HBRUSH   hMYbr   =   ::CreateSolidBrush(RGB(200, 240,240)); 
//		pDC-> SetTextColor(RGB(255,255,255)); 
		pDC->SetBkColor(RGB(200, 240,240));
		pDC-> SetBkMode(TRANSPARENT); 
		return hMYbr;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

BOOL CTreeDlg::PreTranslateMessage( MSG* pMsg )
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
