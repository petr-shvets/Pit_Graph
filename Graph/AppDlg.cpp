// AppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "AppDlg.h"
#include "afxdialogex.h"
#include "tinyexpr.h"


// CAppDlg dialog

IMPLEMENT_DYNAMIC(CAppDlg, CDialogEx)

CAppDlg::CAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAppDlg::IDD, pParent)
	, equation(_T(""))
	, iter(0)
{
	batch_analyze = false;
}

CAppDlg::~CAppDlg()
{
}

void CAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, equation);
	DDX_Control(pDX, IDC_EDIT1, equation_ed);

	DDX_Text(pDX, IDC_EDIT2, var_min[0]);
	DDX_Control(pDX, IDC_EDIT2, var_min_ed[0]);
	DDX_Text(pDX, IDC_EDIT3, var_max[0]);
	DDX_Control(pDX, IDC_EDIT3, var_max_ed[0]);
	DDX_Text(pDX, IDC_EDIT4, var_N[0]);
	DDX_Control(pDX, IDC_EDIT4, var_N_ed[0]);
	DDX_Control(pDX, IDC_EDIT8, var_ed[0]);

	DDX_Text(pDX, IDC_EDIT5, var_min[1]);
	DDX_Control(pDX, IDC_EDIT5, var_min_ed[1]);
	DDX_Text(pDX, IDC_EDIT6, var_max[1]);
	DDX_Control(pDX, IDC_EDIT6, var_max_ed[1]);
	DDX_Text(pDX, IDC_EDIT7, var_N[1]);
	DDX_Control(pDX, IDC_EDIT7, var_N_ed[1]);
	DDX_Control(pDX, IDC_EDIT9, var_ed[1]);

	DDX_Text(pDX, IDC_EDIT10, var_min[2]);
	DDX_Control(pDX, IDC_EDIT10, var_min_ed[2]);
	DDX_Text(pDX, IDC_EDIT11, var_max[2]);
	DDX_Control(pDX, IDC_EDIT11, var_max_ed[2]);
	DDX_Text(pDX, IDC_EDIT12, var_N[2]);
	DDX_Control(pDX, IDC_EDIT12, var_N_ed[2]);
	DDX_Control(pDX, IDC_EDIT13, var_ed[2]);

	DDX_Text(pDX, IDC_EDIT14, var_min[3]);
	DDX_Control(pDX, IDC_EDIT14, var_min_ed[3]);
	DDX_Text(pDX, IDC_EDIT15, var_max[3]);
	DDX_Control(pDX, IDC_EDIT15, var_max_ed[3]);
	DDX_Text(pDX, IDC_EDIT16, var_N[3]);
	DDX_Control(pDX, IDC_EDIT16, var_N_ed[3]);
	DDX_Control(pDX, IDC_EDIT17, var_ed[3]);

	DDX_Text(pDX, IDC_EDIT18, var_min[4]);
	DDX_Control(pDX, IDC_EDIT18, var_min_ed[4]);
	DDX_Text(pDX, IDC_EDIT19, var_max[4]);
	DDX_Control(pDX, IDC_EDIT19, var_max_ed[4]);
	DDX_Text(pDX, IDC_EDIT20, var_N[4]);
	DDX_Control(pDX, IDC_EDIT20, var_N_ed[4]);
	DDX_Control(pDX, IDC_EDIT21, var_ed[4]);

	DDX_Text(pDX, IDC_EDIT22, iter);
	DDX_Control(pDX, IDC_EDIT22, iter_ed);
	
}


BEGIN_MESSAGE_MAP(CAppDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAppDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAppDlg message handlers


void CAppDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	//fit
	if (!batch_analyze)
	{
		UpdateData();
		char buf[100];

		double x; int err_N;
		double y_var[5];
		te_variable vars[] = { { "x", &x }, { "A", &var_val[0] }, { "B", &var_val[1] }, { "C", &var_val[2] }, { "D", &var_val[3] }, { "E", &var_val[4] }, { "y1", &y_var[0]}, {"y2", &y_var[1]}, {"y3", &y_var[2]}, {"y4", &y_var[3]}, {"y5", &y_var[4]} };
		te_expr* expr_y = te_compile(equation, vars, 11, &err_N);
		if (!expr_y)
		{
			sprintf_s(buf, "Parse error at y expression at symbol %d", err_N);
			::MessageBox(0, buf, 0, MB_OK);
			return;
		}

		double* y_app = new double[gr_N];
		double err; double min_err;
		for (int i = 0; i < iter; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				min_err = -1; int min_jj = 0;
				for (int jj = 0; jj < var_N[j]; jj++)
				{
					if (var_N[j] > 1)
						var_val[j] = var_min[j] + jj * (var_max[j] - var_min[j]) / (var_N[j] - 1);
					else var_val[j] = 0.5 * (var_min[j] + var_max[j]);

					for (unsigned int k = 0; k < gr_N; k++)
					{
						x = gr_x[k];

						for (int kkk = 0; kkk < 5; kkk++)
						{
							if (kkk >= graph[0][0]->GetNLast())
							{
								y_var[kkk] = 0;
							}
							else
							{
								y_var[kkk] = graph[0][kkk + 1]->GetY(x);
							}
						}
					
						y_app[k] = te_eval(expr_y);
					}
					err = 0;
					for (unsigned int k = 0; k < gr_N; k++)
					{
						err += (gr_y[k] - y_app[k]) * (gr_y[k] - y_app[k]);
						//stick to ends
						/*if (k == 0 || k == gr_N - 1)
						{
							err += 100*(gr_y[k] - y_app[k])*(gr_y[k] - y_app[k]);
						}*/
					}
					if (err < min_err || min_err == -1)
					{
						min_err = err;
						min_jj = jj;
					}
				}
				if (var_N[j] > 1)
					var_val[j] = var_min[j] + min_jj * (var_max[j] - var_min[j]) / (var_N[j] - 1);
				else var_val[j] = 0.5 * (var_min[j] + var_max[j]);
			}
		}

		for (int i = 0; i < 5; i++)
		{
			sprintf_s(buf, "%g", var_val[i]);
			var_ed[i].SetWindowTextA(buf);
		}

		for (int i = 0; i < 5; i++)
		{
			graph[0][gr_cur]->app_var_val[i] = var_val[i];
		}
		graph[0][gr_cur]->app_eq = equation;
		graph[0][gr_cur]->draw_app = true;

		pDoc->UpdateAllViews(0);

		te_free(expr_y);
		delete[] y_app;
	}
}


BOOL CAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	char buf[100];
	for (int i = 0; i < 5; i++)
	{
		sprintf(buf, "%g", var_val[i]);
		var_ed[i].SetWindowTextA(buf);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CAppDlg::UpdateData()
{
	equation_ed.GetWindowTextA(equation);
	CString temp;
	for (int i = 0; i < 5; i++)
	{
		var_min_ed[i].GetWindowTextA(temp);
		var_min[i] = atof(temp);
		var_max_ed[i].GetWindowTextA(temp);
		var_max[i] = atof(temp);
		var_N_ed[i].GetWindowTextA(temp);
		var_N[i] = (int)atof(temp);
	}
	iter_ed.GetWindowTextA(temp);
	iter = (int)atof(temp);
}
