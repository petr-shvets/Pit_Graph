#pragma once


// CTransformDlg dialog

class CTransformDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTransformDlg)

public:
	CTransformDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTransformDlg();

// Dialog Data
	enum { IDD = IDD_TRANSFORMDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString x;
	CString y;
	BOOL def_size;
};
