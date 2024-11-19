#pragma once
#include "afxwin.h"
//#include "stdafx.h"
#include "GraphDoc.h"
#include "CGraph.h"

// CAppDlg dialog

class CAppDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAppDlg)

public:
	CAppDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAppDlg();

// Dialog Data
	enum { IDD = IDD_APPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString equation;
	CEdit equation_ed;
	double var_min[5];
	CEdit var_min_ed[5];
	double var_max[5];
	CEdit var_max_ed[5];
	int var_N[5];
	CEdit var_N_ed[5];
	double var_val[5];
	CEdit var_ed[5];
	int iter;
	CEdit iter_ed;
	double *gr_x, *gr_y; unsigned int gr_N;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	void UpdateData();
	CGraphDoc* pDoc;
	CGraph* graph;
	int gr_cur;
	bool batch_analyze;
};
