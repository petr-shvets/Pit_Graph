#pragma once
#include "afxdialogex.h"


// CRemovePointsDlg dialog

class CRemovePointsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRemovePointsDlg)

public:
	CRemovePointsDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CRemovePointsDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REMOVEPOINTSDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int perc;
};
