#pragma once
#include "afxdialogex.h"


// CSplineDlg dialog

class CSplineDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSplineDlg)

public:
	CSplineDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSplineDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPLINE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int order;
	int iter;
};
