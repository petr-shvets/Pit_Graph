#pragma once
#include "afxdialogex.h"


// CSplitDlg dialog

class CSplitDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSplitDlg)

public:
	CSplitDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSplitDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPLITDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double x;
};
