#pragma once


// CTreeDlg �Ի���

class CTreeDlg : public CDialog
{
	DECLARE_DYNAMIC(CTreeDlg)

public:
	CTreeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTreeDlg();

// �Ի�������
	enum { IDD = IDD_DLG_TREE };

public:
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
