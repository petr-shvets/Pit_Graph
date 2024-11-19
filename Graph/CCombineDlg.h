#pragma once
#include "afxdialogex.h"


// CCombineDlg dialog

class CCombineDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCombineDlg)

public:
	CCombineDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCombineDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMBINEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString form;
};
