// CBatchAnalyzeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CBatchAnalyzeDlg.h"
#include "CAnalyzePolynomDlg.h"
#include "CAnalyzeInt.h"
#include "AppDlg.h"

// CBatchAnalyzeDlg dialog

IMPLEMENT_DYNAMIC(CBatchAnalyzeDlg, CDialogEx)

CBatchAnalyzeDlg::CBatchAnalyzeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ANALYZE, pParent)
{

}

CBatchAnalyzeDlg::~CBatchAnalyzeDlg()
{
}

void CBatchAnalyzeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, comb);
}


BEGIN_MESSAGE_MAP(CBatchAnalyzeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CBatchAnalyzeDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CBatchAnalyzeDlg message handlers


void CBatchAnalyzeDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	type=comb.GetCurSel();
	if (type == 0)
	{
		CAnalyzeInt dlg;
		dlg.x_min = int_x_min;
		dlg.x_max = int_x_max;
		if (dlg.DoModal() == IDOK)
		{
			int_x_min = dlg.x_min;
			int_x_max = dlg.x_max;
		}
	}
	if (type == 1)
	{
		CAnalyzePolynomDlg dlg;
		dlg.order = poly_order;
		if (dlg.DoModal() == IDOK)
		{
			poly_order = dlg.order;
		}
	}
	if (type == 2)
	{
		CAppDlg dlg;
		dlg.batch_analyze = true;
		dlg.equation = c_ap_equation;
		dlg.iter = c_ap_iter;
		for (int i = 0; i < 5; i++)
		{
			dlg.var_min[i] = c_ap_var_min[i];
			dlg.var_max[i] = c_ap_var_max[i];
			dlg.var_N[i] = c_ap_var_N[i];
		}
		
		if (dlg.DoModal() == IDOK)
		{
			c_ap_equation = dlg.equation;
			c_ap_iter = dlg.iter;
			for (int i = 0; i < 5; i++)
			{
				c_ap_var_min[i] = dlg.var_min[i];
				c_ap_var_max[i] = dlg.var_max[i];
				c_ap_var_N[i] = dlg.var_N[i];
			}
		}
	}
	if (type == 3)
	{
		CVoightNDlg dlg;
		for (int i = 0; i < Nmax; i++)
		{
			dlg.H[i] = v_H[i];
			dlg.FWHM[i] = v_FWHM[i];
			dlg.x[i] = v_x[i];
			dlg.n[i] = v_n[i];

			dlg.Hmax[i] = v_Hmax[i]; dlg.Hmin[i] = v_Hmin[i]; dlg.Hstep[i] = v_Hstep[i];
			dlg.FWHMmax[i] = v_FWHMmax[i]; dlg.FWHMmin[i] = v_FWHMmin[i]; dlg.FWHMstep[i] = v_FWHMstep[i];
			dlg.xmax[i] = v_xmax[i]; dlg.xmin[i] = v_xmin[i]; dlg.xstep[i] = v_xstep[i];
			dlg.nmax[i] = v_nmax[i]; dlg.nmin[i] = v_nmin[i]; dlg.nstep[i] = v_nstep[i];
		}

		dlg.def_dH = v_def_dH; dlg.def_H_st = v_def_H_st;
		dlg.def_dF = v_def_dF; dlg.def_F_st = v_def_F_st;
		dlg.def_dx = v_def_dx; dlg.def_x_st = v_def_x_st;
		dlg.def_n_min = v_def_n_min; dlg.def_n_max = v_def_n_max; dlg.def_n_step = v_def_n_step;
		dlg.n_iter = v_n_iter;
		dlg.batch_analyze = true;

		if (dlg.DoModal() == IDOK)
		{
			for (int i = 0; i < Nmax; i++)
			{
				v_H[i] = dlg.H[i];
				v_FWHM[i] = dlg.FWHM[i];
				v_x[i] = dlg.x[i];
				v_n[i] = dlg.n[i];

				v_Hmax[i] = dlg.Hmax[i]; v_Hmin[i] = dlg.Hmin[i]; v_Hstep[i] = dlg.Hstep[i];
				v_FWHMmax[i] = dlg.FWHMmax[i]; v_FWHMmin[i] = dlg.FWHMmin[i]; v_FWHMstep[i] = dlg.FWHMstep[i];
				v_xmax[i] = dlg.xmax[i]; v_xmin[i] = dlg.xmin[i]; v_xstep[i] = dlg.xstep[i];
				v_nmax[i] = dlg.nmax[i]; v_nmin[i] = dlg.nmin[i]; v_nstep[i] = dlg.nstep[i];
			}
			v_n_iter = dlg.n_iter;
		}
	}
}


BOOL CBatchAnalyzeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	comb.AddString("Integral");
	comb.AddString("Polynomial approximation");
	comb.AddString("Custom approximation");
	comb.AddString("Voight approximation");
	comb.SetCurSel(0);
	type = 0;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
