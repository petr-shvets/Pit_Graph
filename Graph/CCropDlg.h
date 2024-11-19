#pragma once
#include "afxdialogex.h"


// CCropDlg dialog

class CCropDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCropDlg)

public:
	CCropDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCropDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CROPDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double x_min;
	double x_max;
	double y_min;
	double y_max;
};
