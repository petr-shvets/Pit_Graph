#pragma once


// CSizeDlg dialog

class CSizeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSizeDlg)

public:
	CSizeDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSizeDlg();

// Dialog Data
	enum { IDD = IDD_SIZE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double x_min;
	double x_max;
	double y_min;
	double y_max;
};
