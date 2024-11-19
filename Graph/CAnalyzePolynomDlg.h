#pragma once
#include "afxdialogex.h"



// CAnalyzePolynomDlg dialog

class CAnalyzePolynomDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAnalyzePolynomDlg)

public:
	CAnalyzePolynomDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAnalyzePolynomDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANALYZEPOLY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int order;
};
