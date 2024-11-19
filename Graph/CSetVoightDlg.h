#pragma once
#include "afxdialogex.h"


// CSetVoightDlg dialog

class CSetVoightDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetVoightDlg)

public:
	CSetVoightDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSetVoightDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETVOIGHTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double dH;
	double H_st;
	double dF;
	double F_st;
	double dx;
	double x_st;
	double n_min;
	double n_max;
	double n_st;
};
