// CItoGDlg.cpp : implementation file
//
#include "stdafx.h"
//#include "pch.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CItoGDlg.h"


// CItoGDlg dialog

IMPLEMENT_DYNAMIC(CItoGDlg, CDialogEx)

CItoGDlg::CItoGDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IMGTOGRDLG, pParent)
	, x1(0)
	, x2(0)
	, y1(0)
	, y2(0)
	, sens(0)
{

}

CItoGDlg::~CItoGDlg()
{
}

void CItoGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x1);
	DDX_Text(pDX, IDC_EDIT2, x2);
	DDX_Text(pDX, IDC_EDIT3, y1);
	DDX_Text(pDX, IDC_EDIT4, y2);
	DDX_Text(pDX, IDC_EDIT5, sens);
	DDV_MinMaxInt(pDX, sens, 0, 765);
}


BEGIN_MESSAGE_MAP(CItoGDlg, CDialogEx)
END_MESSAGE_MAP()


// CItoGDlg message handlers
