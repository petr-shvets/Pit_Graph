#pragma once
#include "afxdialogex.h"


// CShapeCorrDlg dialog

class CShapeCorrDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShapeCorrDlg)

public:
	CShapeCorrDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CShapeCorrDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BGSHAPEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double dx;
	double dy;
	int iter;
	BOOL show;
};
