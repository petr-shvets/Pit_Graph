// CCombineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CCombineDlg.h"


// CCombineDlg dialog

IMPLEMENT_DYNAMIC(CCombineDlg, CDialogEx)

CCombineDlg::CCombineDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COMBINEDLG, pParent)
	, form(_T(""))
{

}

CCombineDlg::~CCombineDlg()
{
}

void CCombineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, form);
}


BEGIN_MESSAGE_MAP(CCombineDlg, CDialogEx)
END_MESSAGE_MAP()


// CCombineDlg message handlers