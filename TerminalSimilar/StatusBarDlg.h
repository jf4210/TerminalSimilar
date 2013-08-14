#pragma once


// CStatusBarDlg 对话框

class CStatusBarDlg : public CDialog
{
	DECLARE_DYNAMIC(CStatusBarDlg)

public:
	CStatusBarDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStatusBarDlg();

// 对话框数据
	enum { IDD = IDD_DLG_STATUSBAR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
