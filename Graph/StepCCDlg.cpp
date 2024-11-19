// StepCCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "StepCCDlg.h"


// StepCCDlg dialog

IMPLEMENT_DYNAMIC(StepCCDlg, CDialogEx)

StepCCDlg::StepCCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STEPCC, pParent)
	, dx(0)
	, N(0)
	, iter(0)
{

}

StepCCDlg::~StepCCDlg()
{
}

void StepCCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, dx);
	DDX_Text(pDX, IDC_EDIT2, N);
	DDX_Text(pDX, IDC_EDIT3, iter);
}


BEGIN_MESSAGE_MAP(StepCCDlg, CDialogEx)
END_MESSAGE_MAP()


// StepCCDlg message handlers
