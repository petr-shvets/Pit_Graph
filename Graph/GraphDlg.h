#pragma once
#include "afxwin.h"
#include "GraphDoc.h"
#include "CGraph.h"

// CGraphDlg dialog

class CGraphDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGraphDlg)

public:
	CGraphDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGraphDlg();

// Dialog Data
	enum { IDD = IDD_GRAPHDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit name;
	CEdit w;
	CEdit r;
	CEdit g;
	CEdit b;
	CGraph *graph;
	CGraphDoc* pDoc;
	int gr_cur;
	int marker_type;
	bool first_event;
	virtual BOOL OnInitDialog();
	void DrawColor(COLORREF col);
	void CGraphDlg::DrawArrows();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	void Init();
	afx_msg void OnBnClickedRadio6();
	CListBox gr_list;
	CButton but_up;
	CButton but_down;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	void SwapGraphs(int i, int j);

	CBrush br_black;
	CRgn ar_rgn1, ar_rgn2;
};
