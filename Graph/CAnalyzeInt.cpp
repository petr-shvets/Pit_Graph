// CAnalyzeInt.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CAnalyzeInt.h"


// CAnalyzeInt dialog

IMPLEMENT_DYNAMIC(CAnalyzeInt, CDialogEx)

CAnalyzeInt::CAnalyzeInt(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ANALYZEINT, pParent)
	, x_min(0)
	, x_max(0)
{

}

CAnalyzeInt::~CAnalyzeInt()
{
}

void CAnalyzeInt::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x_min);
	DDX_Text(pDX, IDC_EDIT2, x_max);
}


BEGIN_MESSAGE_MAP(CAnalyzeInt, CDialogEx)
END_MESSAGE_MAP()


// CAnalyzeInt message handlers
