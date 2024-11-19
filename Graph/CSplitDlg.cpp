// CSplitDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CSplitDlg.h"


// CSplitDlg dialog

IMPLEMENT_DYNAMIC(CSplitDlg, CDialogEx)

CSplitDlg::CSplitDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SPLITDLG, pParent)
	, x(0)
{

}

CSplitDlg::~CSplitDlg()
{
}

void CSplitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
}


BEGIN_MESSAGE_MAP(CSplitDlg, CDialogEx)
END_MESSAGE_MAP()


// CSplitDlg message handlers
