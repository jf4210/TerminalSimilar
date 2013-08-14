#pragma once

#define ID_MENU_TEST1	1
#define ID_MENU_TEST2	2
#define ID_MENU_TEST3	3
#define ID_MENU_TEST4	4
#define ID_MENU_TEST5	5
#define ID_MENU_TEST6	6

// CTitleDlg 对话框

class CTitleDlg : public CDialog
{
	DECLARE_DYNAMIC(CTitleDlg)

public:
	CTitleDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTitleDlg();

// 对话框数据
	enum { IDD = IDD_DLG_TITLE };

private:
	BOOL bFlag;
	CMenu m_menu;
	CMenu *pMenu;

public:
	void InitUI();
	void SubMenuItem1();
	void SubMenuItem2();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnMax();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedBtnMenu();
	afx_msg void OnBnClickedBtnExit();
};
