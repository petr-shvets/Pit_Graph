// CSetVoightDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CSetVoightDlg.h"


// CSetVoightDlg dialog

IMPLEMENT_DYNAMIC(CSetVoightDlg, CDialogEx)

CSetVoightDlg::CSetVoightDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETVOIGHTDLG, pParent)
	, dH(0)
	, H_st(0)
	, dF(0)
	, F_st(0)
	, dx(0)
	, x_st(0)
	, n_min(0)
	, n_max(0)
	, n_st(0)
{

}

CSetVoightDlg::~CSetVoightDlg()
{
}

void CSetVoightDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, dH);
	DDX_Text(pDX, IDC_EDIT2, H_st);
	DDX_Text(pDX, IDC_EDIT5, dF);
	DDX_Text(pDX, IDC_EDIT6, F_st);
	DDX_Text(pDX, IDC_EDIT3, dx);
	DDX_Text(pDX, IDC_EDIT4, x_st);
	DDX_Text(pDX, IDC_EDIT7, n_min);
	DDX_Text(pDX, IDC_EDIT8, n_max);
	DDX_Text(pDX, IDC_EDIT9, n_st);
}


BEGIN_MESSAGE_MAP(CSetVoightDlg, CDialogEx)
END_MESSAGE_MAP()


// CSetVoightDlg message handlers
