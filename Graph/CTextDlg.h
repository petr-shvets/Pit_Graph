#pragma once
#include "afxdialogex.h"


// CTextDlg dialog

class CTextDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextDlg)

public:
	CTextDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTextDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString txt;
	int r;
	int g;
	int b;
	int size;
	CButton outline;
	bool outl;
	double alpha;
	afx_msg void OnBnClickedCheck1();
	virtual BOOL OnInitDialog();
	CEdit text_ed;
};
