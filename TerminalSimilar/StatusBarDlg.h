#pragma once


// CStatusBarDlg �Ի���

class CStatusBarDlg : public CDialog
{
	DECLARE_DYNAMIC(CStatusBarDlg)

public:
	CStatusBarDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStatusBarDlg();

// �Ի�������
	enum { IDD = IDD_DLG_STATUSBAR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
