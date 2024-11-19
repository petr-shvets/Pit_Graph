#pragma once
#include "afxdialogex.h"


// CAveParamDlg dialog

class CAveParamDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAveParamDlg)

public:
	CAveParamDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAveParamDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AVEPARAM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double Nsigma;
};
