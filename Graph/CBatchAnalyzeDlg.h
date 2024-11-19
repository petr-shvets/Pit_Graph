#pragma once
#include "afxdialogex.h"
#include "CVoightNDlg.h"

// CBatchAnalyzeDlg dialog

class CBatchAnalyzeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBatchAnalyzeDlg)

public:
	CBatchAnalyzeDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CBatchAnalyzeDlg();
	int poly_order; int type;
	double int_x_min, int_x_max;

	CString c_ap_equation;
	double c_ap_var_min[5];
	double c_ap_var_max[5];
	int c_ap_var_N[5];
	int c_ap_iter;

	double v_H[Nmax];
	double v_FWHM[Nmax];
	double v_x[Nmax];
	double v_n[Nmax];

	double v_Hmin[Nmax], v_Hmax[Nmax], v_Hstep[Nmax];
	double v_FWHMmin[Nmax], v_FWHMmax[Nmax], v_FWHMstep[Nmax];
	double v_xmin[Nmax], v_xmax[Nmax], v_xstep[Nmax];
	double v_nmin[Nmax], v_nmax[Nmax], v_nstep[Nmax];
	int v_n_iter;
	double v_def_dH, v_def_H_st;
	double v_def_dF, v_def_F_st;
	double v_def_dx, v_def_x_st;
	double v_def_n_min, v_def_n_max, v_def_n_step;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANALYZE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CComboBox comb;
	virtual BOOL OnInitDialog();
};
