#pragma once
#include "afxdialogex.h"


// CItoGDlg dialog

class CItoGDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CItoGDlg)

public:
	CItoGDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CItoGDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMGTOGRDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double x1;
	double x2;
	double y1;
	double y2;
	int sens;
};
