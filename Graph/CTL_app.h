#pragma once
#include "afxdialogex.h"
#include "GraphDoc.h"
#include "CGraph.h"
#include <complex>

// CTL_app dialog

class CTL_app : public CDialogEx
{
	DECLARE_DYNAMIC(CTL_app)

public:
	CTL_app(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTL_app();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double d;
	double Eg;
	double eps_inf;
	double A;
	double E0;
	double C;
	double d_min;
	double d_max;
	double d_step;
	double Eg_min;
	double Eg_max;
	double Eg_step;
	double eps_inf_min;
	double eps_inf_max;
	double eps_inf_step;
	double A_min;
	double A_max;
	double A_step;
	double E0_min;
	double E0_max;
	double E0_step;
	double C_min;
	double C_max;
	double C_step;
	double delta;
	int iter;
	CEdit d_ed;
	CEdit Eg_ed;
	CEdit eps_inf_ed;
	CEdit A_ed;
	CEdit E0_ed;
	CEdit C_ed;
	CEdit delta_ed;
	CEdit iter_ed;
	CEdit d_min_ed;
	CEdit d_max_ed;
	CEdit d_step_ed;
	CEdit Eg_min_ed;
	CEdit Eg_max_ed;
	CEdit Eg_step_ed;
	CEdit eps_inf_min_ed;
	CEdit eps_inf_max_ed;
	CEdit eps_inf_step_ed;
	CEdit A_min_ed;
	CEdit A_max_ed;
	CEdit A_step_ed;
	CEdit E0_min_ed;
	CEdit E0_max_ed;
	CEdit E0_step_ed;
	CEdit C_min_ed;
	CEdit C_max_ed;
	CEdit C_step_ed;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton7();

	CGraph* graph;
	CGraphDoc* pDoc;
	bool fit_gr;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	void UpdateFit();
	double GetErr();
	CButton d_ch;
	CButton Eg_c;
	CButton eps_inf_ch;
	CButton A_ch;
	CButton E0_ch;
	CButton C_ch;
	CEdit phi_ed;
	double phi;
	CEdit rough_ed;
	double rough;
	CEdit phi_min_ed;
	CEdit phi_max_ed;
	CEdit phi_step_ed;
	CButton phi_ch;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	CButton rough_ch;
	CEdit rough_min_ed;
	CEdit rough_max_ed;
	CEdit rough_step_ed;
	class Ab_mat
	{
	public:
		std::complex<double> M[2][2];
		Ab_mat operator*(Ab_mat mat_r)
		{
			Ab_mat rez;
			rez.M[0][0] = M[0][0] * mat_r.M[0][0] + M[0][1] * mat_r.M[1][0];
			rez.M[0][1] = M[0][0] * mat_r.M[0][1] + M[0][1] * mat_r.M[1][1];
			rez.M[1][0] = M[1][0] * mat_r.M[0][0] + M[1][1] * mat_r.M[1][0];
			rez.M[1][1] = M[1][0] * mat_r.M[0][1] + M[1][1] * mat_r.M[1][1];
			return rez;
		}
	};
};
