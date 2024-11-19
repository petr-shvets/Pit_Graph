// CTextDlg.cpp : implementation file
//
#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CTextDlg.h"


// CTextDlg dialog

IMPLEMENT_DYNAMIC(CTextDlg, CDialogEx)

CTextDlg::CTextDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEXTDLG, pParent)
	, txt(_T(""))
	, r(0)
	, g(0)
	, b(0)
	, size(0)
	, alpha(0)
{
	outl = false;
}

CTextDlg::~CTextDlg()
{
}

void CTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, txt);
	DDX_Text(pDX, IDC_EDIT3, r);
	DDV_MinMaxInt(pDX, r, 0, 255);
	DDX_Text(pDX, IDC_EDIT4, g);
	DDV_MinMaxInt(pDX, g, 0, 255);
	DDX_Text(pDX, IDC_EDIT5, b);
	DDV_MinMaxInt(pDX, b, 0, 255);
	DDX_Text(pDX, IDC_EDIT6, size);
	DDX_Control(pDX, IDC_CHECK1, outline);
	DDX_Text(pDX, IDC_EDIT1, alpha);
	DDX_Control(pDX, IDC_EDIT2, text_ed);
}


BEGIN_MESSAGE_MAP(CTextDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &CTextDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CTextDlg message handlers


void CTextDlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	outl = !outl;
	outline.SetCheck(outl);
}


BOOL CTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	outline.SetCheck(outl);
	text_ed.SetFocus();
	text_ed.SetSel(0, text_ed.GetWindowTextLength());

	return FALSE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
