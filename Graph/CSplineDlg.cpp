// CSplineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CSplineDlg.h"


// CSplineDlg dialog

IMPLEMENT_DYNAMIC(CSplineDlg, CDialogEx)

CSplineDlg::CSplineDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SPLINE, pParent)
	, order(0)
	, iter(0)
{

}

CSplineDlg::~CSplineDlg()
{
}

void CSplineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, order);
	DDX_Text(pDX, IDC_EDIT2, iter);
}


BEGIN_MESSAGE_MAP(CSplineDlg, CDialogEx)
END_MESSAGE_MAP()


// CSplineDlg message handlers
