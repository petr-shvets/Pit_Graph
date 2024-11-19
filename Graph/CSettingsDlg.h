#pragma once
#include "afxdialogex.h"


// CSettingsDlg dialog

class CSettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingsDlg)

public:
	CSettingsDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSettingsDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int max_n_format;
	int f_mode;
	bool point_sep;
	bool deg;
	bool view_mode;
	
	double def_dH, def_H_st;
	double def_dF, def_F_st;
	double def_dx, def_x_st;
	double def_n_min, def_n_max, def_n_step;

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	void SetRadioButtons();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	double EPS;
	double move_scale;
	afx_msg void OnBnClickedButton1();

	int meas_text_size, meas_line_w;
	COLORREF meas_text_col, meas_line_col;
	afx_msg void OnBnClickedButton2();
};
