// AxisDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "AxisDlg.h"
#include "afxdialogex.h"


// CAxisDlg dialog

IMPLEMENT_DYNAMIC(CAxisDlg, CDialogEx)

CAxisDlg::CAxisDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAxisDlg::IDD, pParent)
	, m_l(0)
	, m_r(0)
	, m_t(0)
	, m_b(0)
	, y_sh(0)
	, Xname(_T(""))
	, Yname(_T(""))
	, nam_size(0)
	, num_size(0)
	, nxm(0)
	, nym(0)
	, tol_x(0)
	, tol_y(0)
{
	x_exp = false;
	y_exp = false;
	hide_y = false;
}

CAxisDlg::~CAxisDlg()
{
}

void CAxisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_l);
	DDX_Text(pDX, IDC_EDIT2, m_r);
	DDX_Text(pDX, IDC_EDIT3, m_t);
	DDX_Text(pDX, IDC_EDIT4, m_b);
	DDX_Text(pDX, IDC_EDIT13, y_sh);
	DDX_Text(pDX, IDC_EDIT5, Xname);
	DDX_Text(pDX, IDC_EDIT6, Yname);
	DDX_Text(pDX, IDC_EDIT7, nam_size);
	DDX_Text(pDX, IDC_EDIT8, num_size);
	DDX_Text(pDX, IDC_EDIT9, nxm);
	DDX_Text(pDX, IDC_EDIT10, nym);
	DDX_Text(pDX, IDC_EDIT11, tol_x);
	DDV_MinMaxInt(pDX, tol_x, 0, 9);
	DDX_Text(pDX, IDC_EDIT12, tol_y);
	DDV_MinMaxInt(pDX, tol_y, 0, 9);
}


BEGIN_MESSAGE_MAP(CAxisDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK2, &CAxisDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK1, &CAxisDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK3, &CAxisDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CAxisDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CAxisDlg::OnBnClickedCheck5)
END_MESSAGE_MAP()


// CAxisDlg message handlers


void CAxisDlg::OnBnClickedCheck2()
{
	// TODO: Add your control notification handler code here
	x_exp = !x_exp;
}


void CAxisDlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	y_exp = !y_exp;
}


void CAxisDlg::OnBnClickedCheck3()
{
	// TODO: Add your control notification handler code here
	hide_y = !hide_y;
}


BOOL CAxisDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CButton *but1 = (CButton*)GetDlgItem(IDC_CHECK2);
	but1->SetCheck(x_exp);

	CButton *but2 = (CButton*)GetDlgItem(IDC_CHECK1);
	but2->SetCheck(y_exp);

	CButton *but3 = (CButton*)GetDlgItem(IDC_CHECK3);
	but3->SetCheck(hide_y);

	CButton* but4 = (CButton*)GetDlgItem(IDC_CHECK4);
	but4->SetCheck(hide_sel);

	CButton* but5 = (CButton*)GetDlgItem(IDC_CHECK5);
	but5->SetCheck(hide_net);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CAxisDlg::OnBnClickedCheck4()
{
	// TODO: Add your control notification handler code here
	hide_sel = !hide_sel;
}


void CAxisDlg::OnBnClickedCheck5()
{
	// TODO: Add your control notification handler code here
	hide_net = !hide_net;
}
