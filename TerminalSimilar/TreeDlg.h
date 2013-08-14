#pragma once


// CTreeDlg 对话框

class CTreeDlg : public CDialog
{
	DECLARE_DYNAMIC(CTreeDlg)

public:
	CTreeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTreeDlg();

// 对话框数据
	enum { IDD = IDD_DLG_TREE };

public:
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
