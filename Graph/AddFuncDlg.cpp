// AddFuncDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "AddFuncDlg.h"
#include "afxdialogex.h"


// CAddFuncDlg dialog

IMPLEMENT_DYNAMIC(CAddFuncDlg, CDialogEx)

CAddFuncDlg::CAddFuncDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddFuncDlg::IDD, pParent)
	, x1(0)
	, x2(0)
	, N(0)
	, y(_T(""))
{

}

CAddFuncDlg::~CAddFuncDlg()
{
}

void CAddFuncDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x1);
	DDX_Text(pDX, IDC_EDIT2, x2);
	DDX_Text(pDX, IDC_EDIT3, N);
	DDX_Text(pDX, IDC_EDIT4, y);
}


BEGIN_MESSAGE_MAP(CAddFuncDlg, CDialogEx)
END_MESSAGE_MAP()


// CAddFuncDlg message handlers
