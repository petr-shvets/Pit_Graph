// CRemovePointsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CRemovePointsDlg.h"


// CRemovePointsDlg dialog

IMPLEMENT_DYNAMIC(CRemovePointsDlg, CDialogEx)

CRemovePointsDlg::CRemovePointsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REMOVEPOINTSDLG, pParent)
	, perc(0)
{

}

CRemovePointsDlg::~CRemovePointsDlg()
{
}

void CRemovePointsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, perc);
}


BEGIN_MESSAGE_MAP(CRemovePointsDlg, CDialogEx)
END_MESSAGE_MAP()


// CRemovePointsDlg message handlers
