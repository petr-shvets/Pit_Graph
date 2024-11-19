// CBatchTransformDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CBatchTransformDlg.h"
#include "CCropDlg.h"
#include "TransformDlg.h"
#include "CShapeCorrDlg.h"
#include "CAnalyzePolynomDlg.h"
#include "CSplineDlg.h"
#include "CCombineDlg.h"

// CBatchTransformDlg dialog

IMPLEMENT_DYNAMIC(CBatchTransformDlg, CDialogEx)

CBatchTransformDlg::CBatchTransformDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BATCHTRANSFORM, pParent)
{
	operationN = 0;
}

CBatchTransformDlg::~CBatchTransformDlg()
{
}

void CBatchTransformDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, comb);
}


BEGIN_MESSAGE_MAP(CBatchTransformDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CBatchTransformDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CBatchTransformDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CBatchTransformDlg message handlers


void CBatchTransformDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	int sel = comb.GetCurSel();
	if (sel == 0)
	{
		CCropDlg dlg;
		dlg.x_min = crop_x_min;
		dlg.x_max = crop_x_max;
		dlg.y_max = crop_y_max;
		dlg.y_min = crop_y_min;
		if (dlg.DoModal() == IDOK)
		{
			crop_x_min = dlg.x_min;
			crop_x_max = dlg.x_max;
			crop_y_max = dlg.y_max;
			crop_y_min = dlg.y_min;
		}
	}
	if (sel == 1)
	{
		CTransformDlg dlg;
		dlg.x = trans_x;
		dlg.y = trans_y;
		if (dlg.DoModal() == IDOK)
		{
			trans_x = dlg.x;
			trans_y = dlg.y;
		}
	}
	if (sel == 2)
	{
		CShapeCorrDlg dlg;
		dlg.dx = shape_dx;
		dlg.dy = shape_dy;
		dlg.iter = shape_iter;
		if (dlg.DoModal() == IDOK)
		{
			shape_dx = dlg.dx;
			shape_dy = dlg.dy;
			shape_iter = dlg.iter;
		}
	}
	if (sel == 3)
	{
	}
	if (sel == 4)
	{
		CAnalyzePolynomDlg dlg;
		dlg.order = poly_order;
		if (dlg.DoModal() == IDOK)
		{
			poly_order = dlg.order;
		}
	}
	if (sel == 5)
	{
		CSplineDlg dlg;
		dlg.order = spline_order;
		dlg.iter = spline_iter;
		if (dlg.DoModal() == IDOK)
		{
			spline_iter = max(1, dlg.iter);
			spline_order = max(2, dlg.order);
		}
	}
	if (sel == 6)
	{
		CCombineDlg dlg;
		dlg.form = combine_str;
		if (dlg.DoModal() == IDOK)
		{
			combine_str = dlg.form;
		}
	}
}


BOOL CBatchTransformDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	comb.AddString("Crop");
	comb.AddString("Transform");
	comb.AddString("BG correction - shape");
	comb.AddString("BG correction - Shirley");
	comb.AddString("BG correction - polynomial");
	comb.AddString("Moving Average");
	comb.AddString("Combine");
	comb.SetCurSel(operationN);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CBatchTransformDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	operationN = comb.GetCurSel();
}
