// CShapeCorrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CShapeCorrDlg.h"


// CShapeCorrDlg dialog

IMPLEMENT_DYNAMIC(CShapeCorrDlg, CDialogEx)

CShapeCorrDlg::CShapeCorrDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BGSHAPEDLG, pParent)
	, dx(0)
	, dy(0)
	, iter(0)
	, show(FALSE)
{

}

CShapeCorrDlg::~CShapeCorrDlg()
{
}

void CShapeCorrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, dx);
	DDX_Text(pDX, IDC_EDIT2, dy);
	DDX_Text(pDX, IDC_EDIT3, iter);
	DDX_Check(pDX, IDC_CHECK1, show);
}


BEGIN_MESSAGE_MAP(CShapeCorrDlg, CDialogEx)
END_MESSAGE_MAP()


// CShapeCorrDlg message handlers
