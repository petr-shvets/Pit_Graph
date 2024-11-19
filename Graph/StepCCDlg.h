#pragma once
#include "afxdialogex.h"


// StepCCDlg dialog

class StepCCDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StepCCDlg)

public:
	StepCCDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~StepCCDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STEPCC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double dx;
	int N;
	int iter;
};
