#pragma once
#include "afxdialogex.h"
#include "CGraph.h"
#include "GraphDoc.h"

// CBGPolyDlg dialog

class CBGPolyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBGPolyDlg)

public:
	CBGPolyDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CBGPolyDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BGPOLY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int n;
	afx_msg void OnBnClickedButton1();
	CGraphDoc* pDoc;
	CGraph* graph;
	int gr_cur;
	double* y_BG;
	virtual BOOL OnInitDialog();
	CEdit N_app_ed;
	bool gr_added;
	int iter;
	CEdit iter_ed;
};
