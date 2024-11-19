#pragma once
#include "afxdialogex.h"
#include "CGraph.h"
#include "GraphDoc.h"

// CAppColDlg dialog

class CAppColDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAppColDlg)

public:
	CAppColDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAppColDlg();

// Dialog Data
	CGraph* graph, * v_graph;
	CGraphDoc* pDoc;
	int gr_cur;
	bool first_event;
	COLORREF* v_col1, * v_col2;
	int* v_w1, * v_w2;
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APPCOLDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void Init();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit name;
	CEdit w1;
	CEdit w2;
	CEdit w3;
	CEdit w4;
	CEdit r1;
	CEdit r2;
	CEdit r3;
	CEdit r4;
	CEdit g1;
	CEdit g2;
	CEdit g3;
	CEdit g4;
	CEdit b1;
	CEdit b2;
	CEdit b3;
	CEdit b4;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	void DrawColor(COLORREF col, int n);
};
