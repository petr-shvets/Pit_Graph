#pragma once


// CWndSizeDlg dialog

class CWndSizeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWndSizeDlg)

public:
	CWndSizeDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CWndSizeDlg();

	// Dialog Data
	enum { IDD = IDD_WNDSIZEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int dx;
	int dy;
};
