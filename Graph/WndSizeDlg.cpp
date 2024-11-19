// WndSizeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "WndSizeDlg.h"
#include "afxdialogex.h"


// CWndSizeDlg dialog

IMPLEMENT_DYNAMIC(CWndSizeDlg, CDialogEx)

CWndSizeDlg::CWndSizeDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CWndSizeDlg::IDD, pParent)
, dx(0)
, dy(0)
{

}

CWndSizeDlg::~CWndSizeDlg()
{
}

void CWndSizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, 1018, dx);
	DDX_Text(pDX, 1019, dy);
}


BEGIN_MESSAGE_MAP(CWndSizeDlg, CDialogEx)
END_MESSAGE_MAP()


// CWndSizeDlg message handlers
