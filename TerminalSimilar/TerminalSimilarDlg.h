// TerminalSimilarDlg.h : ͷ�ļ�
//

#pragma once

#include "TitleDlg.h"
#include "TreeDlg.h"
#include "StatusBarDlg.h"


#define CLIENT_WIDTH	1024
#define CLIENT_HIGHT	768
#define TITLE_HIGHT		150
#define TREE_WIDTH		150
#define STATUSBAR_HIGHT 50		//����״̬���ĸ�
#define BOTTON_INTERVAL 3

// CTerminalSimilarDlg �Ի���
class CTerminalSimilarDlg : public CDialog
{
// ����
public:
	CTerminalSimilarDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CTerminalSimilarDlg();

// �Ի�������
	enum { IDD = IDD_TERMINALSIMILAR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	CTitleDlg		*m_pTitleDlg;
	CTreeDlg		*m_pTreeDlg;
	CStatusBarDlg	*m_pStatusBarDlg;


	void UIInit();
	void MoveDlg();
	void MoveFullDlg();

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
};
