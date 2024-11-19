#pragma once
#include "afxdialogex.h"


// CAnalyzeInt dialog

class CAnalyzeInt : public CDialogEx
{
	DECLARE_DYNAMIC(CAnalyzeInt)

public:
	CAnalyzeInt(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAnalyzeInt();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANALYZEINT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double x_min;
	double x_max;
};
