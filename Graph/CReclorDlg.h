#pragma once
#include "afxdialogex.h"


// CReclorDlg dialog

class CReclorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CReclorDlg)

public:
	CReclorDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CReclorDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECOLOR_GR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CBitmap palette1;
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	COLORREF CReclorDlg::ValueToColor(double min, double max, double val, int pallete);
	double p[5];
	int r[6], g[5], b[5];
	int pal_n;
	bool start;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedButton6();
};
