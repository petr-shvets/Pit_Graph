// CSettingsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CSettingsDlg.h"
#include "CSetColDlg.h"
#include "CSetVoightDlg.h"


// CSettingsDlg dialog

IMPLEMENT_DYNAMIC(CSettingsDlg, CDialogEx)

CSettingsDlg::CSettingsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETDLG, pParent)
	, f_mode(0)
	, EPS(0)
{

}

CSettingsDlg::~CSettingsDlg()
{
}

void CSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, f_mode);
	DDV_MinMaxInt(pDX, f_mode, 1, max_n_format);
	DDX_Text(pDX, IDC_EDIT2, EPS);
	DDX_Text(pDX, IDC_EDIT3, move_scale);
}


BEGIN_MESSAGE_MAP(CSettingsDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO2, &CSettingsDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO1, &CSettingsDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &CSettingsDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CSettingsDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CSettingsDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CSettingsDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON1, &CSettingsDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSettingsDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSettingsDlg message handlers


BOOL CSettingsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	SetRadioButtons();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CSettingsDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	point_sep = true;
	SetRadioButtons();
}


void CSettingsDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	point_sep = false;
	SetRadioButtons();
}


void CSettingsDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	deg = true;
	SetRadioButtons();
}


void CSettingsDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	deg = false;
	SetRadioButtons();
}


void CSettingsDlg::SetRadioButtons()
{
	// TODO: Add your implementation code here.
	if (point_sep)
	{
		CButton* but1 = (CButton*)GetDlgItem(IDC_RADIO2);
		but1->SetCheck(1);
	}
	else
	{
		CButton* but1 = (CButton*)GetDlgItem(IDC_RADIO1);
		but1->SetCheck(1);
	}
	if (deg)
	{
		CButton* but1 = (CButton*)GetDlgItem(IDC_RADIO3);
		but1->SetCheck(1);
	}
	else
	{
		CButton* but1 = (CButton*)GetDlgItem(IDC_RADIO4);
		but1->SetCheck(1);
	}
	if (view_mode)
	{
		CButton* but1 = (CButton*)GetDlgItem(IDC_RADIO5);
		but1->SetCheck(1);
	}
	else
	{
		CButton* but1 = (CButton*)GetDlgItem(IDC_RADIO6);
		but1->SetCheck(1);
	}
}


void CSettingsDlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	view_mode = true;
	SetRadioButtons();
}


void CSettingsDlg::OnBnClickedRadio6()
{
	// TODO: Add your control notification handler code here
	view_mode = false;
	SetRadioButtons();
}


void CSettingsDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CSetColDlg dlg;
	dlg.m_l_w = meas_line_w;
	dlg.m_l_r = GetRValue(meas_line_col);
	dlg.m_l_g = GetGValue(meas_line_col);
	dlg.m_l_b = GetBValue(meas_line_col);
	dlg.m_t_w = meas_text_size;
	dlg.m_t_r = GetRValue(meas_text_col);
	dlg.m_t_g = GetGValue(meas_text_col);
	dlg.m_t_b = GetBValue(meas_text_col);
	if (dlg.DoModal() == IDOK)
	{
		meas_line_w = dlg.m_l_w;
		meas_text_size = dlg.m_t_w;
		meas_line_col = RGB(dlg.m_l_r, dlg.m_l_g, dlg.m_l_b);
		meas_text_col = RGB(dlg.m_t_r, dlg.m_t_g, dlg.m_t_b);
	}
}


void CSettingsDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CSetVoightDlg dlg;
	dlg.dH = def_dH * 100; dlg.H_st = def_H_st * 100;
	dlg.dF = def_dF; dlg.F_st = def_F_st;
	dlg.dx = def_dx; dlg.x_st = def_x_st;
	dlg.n_min = def_n_min; dlg.n_max = def_n_max; dlg.n_st = def_n_step;
	if (dlg.DoModal() == IDOK)
	{
		def_dH = dlg.dH * 0.01; def_H_st = dlg.H_st * 0.01;
		def_dF = dlg.dF; def_F_st = dlg.F_st;
		def_dx = dlg.dx; def_x_st = dlg.x_st;
		def_n_min = dlg.n_min; def_n_max = dlg.n_max; def_n_step = dlg.n_st;
	}
}
