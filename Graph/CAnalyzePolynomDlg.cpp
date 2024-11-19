// CAnalyzePolynomDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CAnalyzePolynomDlg.h"


// CAnalyzePolynomDlg dialog

IMPLEMENT_DYNAMIC(CAnalyzePolynomDlg, CDialogEx)

CAnalyzePolynomDlg::CAnalyzePolynomDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ANALYZEPOLY, pParent)
	, order(0)
{

}

CAnalyzePolynomDlg::~CAnalyzePolynomDlg()
{
}

void CAnalyzePolynomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, order);
	DDV_MinMaxInt(pDX, order, 0, 9);
}


BEGIN_MESSAGE_MAP(CAnalyzePolynomDlg, CDialogEx)
END_MESSAGE_MAP()


// CAnalyzePolynomDlg message handlers
