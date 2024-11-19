// CSetColDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CSetColDlg.h"


// CSetColDlg dialog

IMPLEMENT_DYNAMIC(CSetColDlg, CDialogEx)

CSetColDlg::CSetColDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETCOLDLG, pParent)
	, m_l_w(0)
	, m_t_w(0)
	, m_l_r(0)
	, m_l_g(0)
	, m_l_b(0)
	, m_t_r(0)
	, m_t_g(0)
	, m_t_b(0)
{

}

CSetColDlg::~CSetColDlg()
{
}

void CSetColDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_l_w);
	DDX_Text(pDX, IDC_EDIT9, m_t_w);
	DDX_Text(pDX, IDC_EDIT3, m_l_r);
	DDX_Text(pDX, IDC_EDIT4, m_l_g);
	DDX_Text(pDX, IDC_EDIT5, m_l_b);
	DDX_Text(pDX, IDC_EDIT6, m_t_r);
	DDX_Text(pDX, IDC_EDIT7, m_t_g);
	DDX_Text(pDX, IDC_EDIT8, m_t_b);
	DDX_Control(pDX, IDC_EDIT3, r1);
	DDX_Control(pDX, IDC_EDIT4, g1);
	DDX_Control(pDX, IDC_EDIT5, b1);
	DDX_Control(pDX, IDC_EDIT6, r2);
	DDX_Control(pDX, IDC_EDIT7, g2);
	DDX_Control(pDX, IDC_EDIT8, b2);
}


BEGIN_MESSAGE_MAP(CSetColDlg, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CSetColDlg message handlers


void CSetColDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1)
	{
		char buf[100];
		int R, G, B;

		r1.GetLine(0, buf, r1.LineLength());
		buf[r1.LineLength()] = 0;
		R = atoi(buf);
		g1.GetLine(0, buf, g1.LineLength());
		buf[g1.LineLength()] = 0;
		G = atoi(buf);
		b1.GetLine(0, buf, b1.LineLength());
		buf[b1.LineLength()] = 0;
		B = atoi(buf);
		static COLORREF prev_col1 = RGB(R, G, B);
		COLORREF cur_col1 = RGB(R, G, B);

		r2.GetLine(0, buf, r2.LineLength());
		buf[r2.LineLength()] = 0;
		R = atoi(buf);
		g2.GetLine(0, buf, g2.LineLength());
		buf[g2.LineLength()] = 0;
		G = atoi(buf);
		b2.GetLine(0, buf, b2.LineLength());
		buf[b2.LineLength()] = 0;
		B = atoi(buf);
		static COLORREF prev_col2 = RGB(R, G, B);
		COLORREF cur_col2 = RGB(R, G, B);

		if (prev_col1 != cur_col1 || first)
		{
			DrawColor(cur_col1, 0);
			prev_col1 = cur_col1;
		}
		if (prev_col2 != cur_col2 || first)
		{
			DrawColor(cur_col2, 1);
			prev_col2 = cur_col2;
		}
		first = false;
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CSetColDlg::DrawColor(COLORREF col, int n)
{
	// TODO: Add your implementation code here.
	CWnd* wn = 0;
	if (n == 0)
		wn = GetDlgItem(IDC_BUTTON1);
	if (n == 1)
		wn = GetDlgItem(IDC_BUTTON2);
	
	RECT rec;
	wn->GetClientRect(&rec);
	CDC* pDC = wn->GetDC();

	CBrush br;
	br.CreateSolidBrush(col);
	CRgn rgn;
	rgn.CreateRectRgn(rec.left, rec.top, rec.right, rec.bottom);
	pDC->FillRgn(&rgn, &br);

	DeleteObject(br);
	DeleteObject(rgn);
	ReleaseDC(pDC);
}

BOOL CSetColDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	SetTimer(1, 300, NULL);
	first = true;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
