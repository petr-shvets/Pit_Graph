#pragma once
#include "afxdialogex.h"


// CPaetteDlg dialog

class CPaetteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPaetteDlg)

public:
	CPaetteDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPaetteDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PALETTEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double p[5];
	int r[5], g[5], b[5];
};
