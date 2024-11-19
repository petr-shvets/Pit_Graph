// SizeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "SizeDlg.h"
#include "afxdialogex.h"


// CSizeDlg dialog

IMPLEMENT_DYNAMIC(CSizeDlg, CDialogEx)

CSizeDlg::CSizeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSizeDlg::IDD, pParent)
	, x_min(0)
	, x_max(0)
	, y_min(0)
	, y_max(0)
{

}

CSizeDlg::~CSizeDlg()
{
}

void CSizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x_min);
	DDX_Text(pDX, IDC_EDIT2, x_max);
	DDX_Text(pDX, IDC_EDIT3, y_min);
	DDX_Text(pDX, IDC_EDIT4, y_max);
}


BEGIN_MESSAGE_MAP(CSizeDlg, CDialogEx)
END_MESSAGE_MAP()


// CSizeDlg message handlers
