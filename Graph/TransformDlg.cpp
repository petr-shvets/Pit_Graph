// TransformDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "TransformDlg.h"
#include "afxdialogex.h"


// CTransformDlg dialog

IMPLEMENT_DYNAMIC(CTransformDlg, CDialogEx)

CTransformDlg::CTransformDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTransformDlg::IDD, pParent)
	, x(_T(""))
	, y(_T(""))
	, def_size(FALSE)
{

}

CTransformDlg::~CTransformDlg()
{
}

void CTransformDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Check(pDX, IDC_CHECK1, def_size);
}


BEGIN_MESSAGE_MAP(CTransformDlg, CDialogEx)
END_MESSAGE_MAP()


// CTransformDlg message handlers
