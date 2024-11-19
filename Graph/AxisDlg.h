#pragma once


// CAxisDlg dialog

class CAxisDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAxisDlg)

public:
	CAxisDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAxisDlg();

// Dialog Data
	enum { IDD = IDD_AXISDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_l;
	int m_r;
	int m_t;
	int m_b;
	int y_sh;
	CString Xname;
	CString Yname;
	int nam_size;
	int num_size;
	int nxm;
	int nym;
	int tol_x;
	int tol_y;
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck3();
	bool x_exp, y_exp, hide_y;
	virtual BOOL OnInitDialog();
	bool hide_sel;
	bool hide_net;
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
};
