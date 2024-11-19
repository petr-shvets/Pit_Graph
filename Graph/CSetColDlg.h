#pragma once
#include "afxdialogex.h"


// CSetColDlg dialog

class CSetColDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetColDlg)

public:
	CSetColDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSetColDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETCOLDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_l_w;
	int m_t_w;
	int m_l_r;
	int m_l_g;
	int m_l_b;
	int m_t_r;
	int m_t_g;
	int m_t_b;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void DrawColor(COLORREF col, int n);
	virtual BOOL OnInitDialog();
	CEdit r1;
	CEdit g1;
	CEdit b1;
	CEdit r2;
	CEdit g2;
	CEdit b2;
	bool first;
};
