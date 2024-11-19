// CCropDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CCropDlg.h"


// CCropDlg dialog

IMPLEMENT_DYNAMIC(CCropDlg, CDialogEx)

CCropDlg::CCropDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CROPDLG, pParent)
	, x_min(0)
	, x_max(0)
	, y_min(0)
	, y_max(0)
{

}

CCropDlg::~CCropDlg()
{
}

void CCropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x_min);
	DDX_Text(pDX, IDC_EDIT2, x_max);
	DDX_Text(pDX, IDC_EDIT3, y_min);
	DDX_Text(pDX, IDC_EDIT4, y_max);
}


BEGIN_MESSAGE_MAP(CCropDlg, CDialogEx)
END_MESSAGE_MAP()


// CCropDlg message handlers
