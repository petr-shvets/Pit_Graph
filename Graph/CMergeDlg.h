#pragma once
#include "afxdialogex.h"


// CMergeDlg dialog

class CMergeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMergeDlg)

public:
	CMergeDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMergeDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MERGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString rule;
};
