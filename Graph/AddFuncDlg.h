#pragma once


// CAddFuncDlg dialog

class CAddFuncDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddFuncDlg)

public:
	CAddFuncDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAddFuncDlg();

// Dialog Data
	enum { IDD = IDD_ADDFUNC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double x1;
	double x2;
	int N;
	CString y;
};
