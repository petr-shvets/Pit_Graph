#pragma once
#include "afxdialogex.h"
#include "GraphDoc.h"
#include "CGraph.h"
#define Nmax 7

// CVoightNDlg dialog

class CVoightNDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVoightNDlg)

public:
	CVoightNDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CVoightNDlg();

// Dialog Data
	double* x_exp, * y_exp;
	int N_exp;

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VOIGHTNDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double H[Nmax];
	double FWHM[Nmax];
	double x[Nmax];
	double n[Nmax];

	double Hmin[Nmax], Hmax[Nmax], Hstep[Nmax];
	double FWHMmin[Nmax], FWHMmax[Nmax], FWHMstep[Nmax];
	double xmin[Nmax], xmax[Nmax], xstep[Nmax];
	double nmin[Nmax], nmax[Nmax], nstep[Nmax];

	double def_dH, def_H_st;
	double def_dF, def_F_st;
	double def_dx, def_x_st;
	double def_n_min, def_n_max, def_n_step;

	bool batch_analyze;

	virtual BOOL OnInitDialog();

	CEdit H_ed[Nmax];
	CEdit FWHM_ed[Nmax];
	CEdit x_ed[Nmax];
	CEdit n_ed[Nmax];
	CEdit int_ed[Nmax];

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CGraphDoc* pDoc;
	CGraph* graph;
	void UpdateFit();
	CEdit H_min_ed;
	CEdit H_max_ed;
	CEdit H_step_ed;
	CEdit FWHM_min_ed;
	CEdit FWHM_step_ed;
	CEdit FWHM_max_ed;
	CEdit x_min_ed;
	CEdit x_step_ed;
	CEdit x_max_ed;
	CEdit n_min_ed;
	CEdit n_step_ed;
	CEdit n_max_ed;
	afx_msg void OnBnClickedButton10();
	int cur_min_max;
	void FillMinMax(int index);
	void UpdateMinMax();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedButton1();
	double GetError();
	void FindFit(int index);
	void FillParam(int index);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	void UpdateIntegrals();
	int n_iter;
	afx_msg void OnBnClickedButton11();
	CEdit n_iter_ed;
	CEdit iter_cur_ed;
};
