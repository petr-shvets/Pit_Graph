// CPaetteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CPaetteDlg.h"


// CPaetteDlg dialog

IMPLEMENT_DYNAMIC(CPaetteDlg, CDialogEx)

CPaetteDlg::CPaetteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PALETTEDLG, pParent)
{

}

CPaetteDlg::~CPaetteDlg()
{
}

void CPaetteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, p[0]);
	DDX_Text(pDX, IDC_EDIT5, p[1]);
	DDX_Text(pDX, IDC_EDIT9, p[2]);
	DDX_Text(pDX, IDC_EDIT11, p[3]);
	DDX_Text(pDX, IDC_EDIT112, p[4]);
	DDX_Text(pDX, IDC_EDIT2, r[0]);
	DDX_Text(pDX, IDC_EDIT6, r[1]);
	DDX_Text(pDX, IDC_EDIT108, r[2]);
	DDX_Text(pDX, IDC_EDIT12, r[3]);
	DDX_Text(pDX, IDC_EDIT114, r[4]);
	DDX_Text(pDX, IDC_EDIT3, g[0]);
	DDX_Text(pDX, IDC_EDIT7, g[1]);
	DDX_Text(pDX, IDC_EDIT109, g[2]);
	DDX_Text(pDX, IDC_EDIT111, g[3]);
	DDX_Text(pDX, IDC_EDIT113, g[4]);
	DDX_Text(pDX, IDC_EDIT4, b[0]);
	DDX_Text(pDX, IDC_EDIT8, b[1]);
	DDX_Text(pDX, IDC_EDIT110, b[2]);
	DDX_Text(pDX, IDC_EDIT13, b[3]);
	DDX_Text(pDX, IDC_EDIT115, b[4]);
}


BEGIN_MESSAGE_MAP(CPaetteDlg, CDialogEx)
END_MESSAGE_MAP()


// CPaetteDlg message handlers
