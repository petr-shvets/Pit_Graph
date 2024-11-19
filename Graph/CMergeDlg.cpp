// CMergeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CMergeDlg.h"


// CMergeDlg dialog

IMPLEMENT_DYNAMIC(CMergeDlg, CDialogEx)

CMergeDlg::CMergeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MERGE, pParent)
	, rule(_T(""))
{

}

CMergeDlg::~CMergeDlg()
{
}

void CMergeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, rule);
}


BEGIN_MESSAGE_MAP(CMergeDlg, CDialogEx)
END_MESSAGE_MAP()


// CMergeDlg message handlers
