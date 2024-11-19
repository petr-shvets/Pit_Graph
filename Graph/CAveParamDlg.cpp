// CAveParamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CAveParamDlg.h"


// CAveParamDlg dialog

IMPLEMENT_DYNAMIC(CAveParamDlg, CDialogEx)

CAveParamDlg::CAveParamDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AVEPARAM, pParent)
	, Nsigma(1.5)
{

}

CAveParamDlg::~CAveParamDlg()
{
}

void CAveParamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Nsigma);
}


BEGIN_MESSAGE_MAP(CAveParamDlg, CDialogEx)
END_MESSAGE_MAP()


// CAveParamDlg message handlers
