#pragma once
#include "afxdialogex.h"
#include "CGraph.h"
#include "GraphDoc.h"

// CPolyAppDlg dialog

class CPolyAppDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPolyAppDlg)

public:
	CPolyAppDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPolyAppDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POLY_APP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	double* x, * y;
	int n;
	int n_app;
	double c_app[10];
	CEdit N_app_ed;
	CGraphDoc* pDoc;
	CGraph* graph;
	int gr_cur;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
};
