// TerminalSimilarDlg.h : 头文件
//

#pragma once

#include "TitleDlg.h"
#include "TreeDlg.h"
#include "StatusBarDlg.h"


#define CLIENT_WIDTH	1024
#define CLIENT_HIGHT	768
#define TITLE_HIGHT		150
#define TREE_WIDTH		150
#define STATUSBAR_HIGHT 50		//底下状态栏的高
#define BOTTON_INTERVAL 3

// CTerminalSimilarDlg 对话框
class CTerminalSimilarDlg : public CDialog
{
// 构造
public:
	CTerminalSimilarDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CTerminalSimilarDlg();

// 对话框数据
	enum { IDD = IDD_TERMINALSIMILAR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:
	CTitleDlg		*m_pTitleDlg;
	CTreeDlg		*m_pTreeDlg;
	CStatusBarDlg	*m_pStatusBarDlg;


	void UIInit();
	void MoveDlg();
	void MoveFullDlg();

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
};
