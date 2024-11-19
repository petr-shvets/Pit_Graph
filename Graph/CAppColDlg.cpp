// CAppColDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CAppColDlg.h"


// CAppColDlg dialog

IMPLEMENT_DYNAMIC(CAppColDlg, CDialogEx)

CAppColDlg::CAppColDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_APPCOLDLG, pParent)
{

}

CAppColDlg::~CAppColDlg()
{
}

void CAppColDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, name);
	DDX_Control(pDX, IDC_EDIT2, w1);
	DDX_Control(pDX, IDC_EDIT6, w2);
	DDX_Control(pDX, IDC_EDIT108, w3);
	DDX_Control(pDX, IDC_EDIT12, w4);
	DDX_Control(pDX, IDC_EDIT3, r1);
	DDX_Control(pDX, IDC_EDIT7, r2);
	DDX_Control(pDX, IDC_EDIT109, r3);
	DDX_Control(pDX, IDC_EDIT111, r4);
	DDX_Control(pDX, IDC_EDIT4, g1);
	DDX_Control(pDX, IDC_EDIT8, g2);
	DDX_Control(pDX, IDC_EDIT110, g3);
	DDX_Control(pDX, IDC_EDIT13, g4);
	DDX_Control(pDX, IDC_EDIT5, b1);
	DDX_Control(pDX, IDC_EDIT9, b2);
	DDX_Control(pDX, IDC_EDIT11, b3);
	DDX_Control(pDX, IDC_EDIT112, b4);
}


BEGIN_MESSAGE_MAP(CAppColDlg, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON3, &CAppColDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CAppColDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CAppColDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CAppColDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CAppColDlg message handlers


BOOL CAppColDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	SetTimer(1, 300, NULL);
	first_event = true;
	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CAppColDlg::Init()
{
	// TODO: Add your implementation code here.
	name.SetWindowTextA(graph[0][gr_cur]->name);

	COLORREF col = graph[0][gr_cur]->app_col[0];
	char buf[100];
	int ccc = GetRValue(col);
	int a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	r1.SetWindowTextA(buf);
	ccc = GetGValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	g1.SetWindowTextA(buf);
	ccc = GetBValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	b1.SetWindowTextA(buf);

	col = graph[0][gr_cur]->app_col[1];
	ccc = GetRValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	r2.SetWindowTextA(buf);
	ccc = GetGValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	g2.SetWindowTextA(buf);
	ccc = GetBValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	b2.SetWindowTextA(buf);

	ccc = graph[0][gr_cur]->app_line_width[0];
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	w1.SetWindowTextA(buf);

	ccc = graph[0][gr_cur]->app_line_width[1];
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	w2.SetWindowTextA(buf);

	ccc = v_w1[0];
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	w3.SetWindowTextA(buf);

	ccc = v_w2[0];
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	w4.SetWindowTextA(buf);

	col = v_col1[0];
	ccc = GetRValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	r3.SetWindowTextA(buf);
	ccc = GetGValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	g3.SetWindowTextA(buf);
	ccc = GetBValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	b3.SetWindowTextA(buf);

	col = v_col2[0];
	ccc = GetRValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	r4.SetWindowTextA(buf);
	ccc = GetGValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	g4.SetWindowTextA(buf);
	ccc = GetBValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	b4.SetWindowTextA(buf);
}


void CAppColDlg::OnTimer(UINT_PTR nIDEvent)
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

		r3.GetLine(0, buf, r3.LineLength());
		buf[r3.LineLength()] = 0;
		R = atoi(buf);
		g3.GetLine(0, buf, g3.LineLength());
		buf[g3.LineLength()] = 0;
		G = atoi(buf);
		b3.GetLine(0, buf, b3.LineLength());
		buf[b3.LineLength()] = 0;
		B = atoi(buf);
		static COLORREF prev_col3 = RGB(R, G, B);
		COLORREF cur_col3 = RGB(R, G, B);

		r4.GetLine(0, buf, r4.LineLength());
		buf[r4.LineLength()] = 0;
		R = atoi(buf);
		g4.GetLine(0, buf, g4.LineLength());
		buf[g4.LineLength()] = 0;
		G = atoi(buf);
		b4.GetLine(0, buf, b4.LineLength());
		buf[b4.LineLength()] = 0;
		B = atoi(buf);
		static COLORREF prev_col4 = RGB(R, G, B);
		COLORREF cur_col4 = RGB(R, G, B);

		w1.GetLine(0, buf, w1.LineLength());
		buf[w1.LineLength()] = 0;
		int cur_w1 = atoi(buf);
		static int prev_w1 = cur_w1;

		w2.GetLine(0, buf, w2.LineLength());
		buf[w2.LineLength()] = 0;
		int cur_w2 = atoi(buf);
		static int prev_w2 = cur_w2;

		w3.GetLine(0, buf, w3.LineLength());
		buf[w3.LineLength()] = 0;
		int cur_w3 = atoi(buf);
		static int prev_w3 = cur_w3;

		w4.GetLine(0, buf, w4.LineLength());
		buf[w4.LineLength()] = 0;
		int cur_w4 = atoi(buf);
		static int prev_w4 = cur_w4;

		CString cur_name;
		name.GetWindowText(cur_name);
		static CString prev_name = cur_name;

		if (first_event)
		{
			first_event = false;
			DrawColor(prev_col1, 0);
			DrawColor(prev_col2, 1);
			DrawColor(prev_col3, 2);
			DrawColor(prev_col4, 3);
		}
		else
		{
			bool update = false;
			if (prev_col1 != cur_col1)
			{
				DrawColor(cur_col1, 0);
				prev_col1 = cur_col1;
				graph[0][gr_cur]->app_col[0] = cur_col1;
				update = true;
			}
			if (prev_col2 != cur_col2)
			{
				DrawColor(cur_col2, 1);
				prev_col2 = cur_col2;
				graph[0][gr_cur]->app_col[1] = cur_col2;
				update = true;
			}
			int NN = v_graph[0][0]->GetNLast();
			if (prev_col3 != cur_col3)
			{
				DrawColor(cur_col3, 2);
				prev_col3 = cur_col3;
				v_col1[0] = cur_col3;
				if (NN > 0)
				{
					v_graph[0][1]->col = cur_col3;
				}
				update = true;
			}
			if (prev_col4 != cur_col4)
			{
				DrawColor(cur_col4, 3);
				prev_col4 = cur_col4;
				v_col2[0] = cur_col4;
				for (int i = 2; i <= NN; i++)
				{
					v_graph[0][i]->col = cur_col4;
				}
				update = true;
			}
			if (prev_w1 != cur_w1)
			{
				prev_w1 = cur_w1;
				graph[0][gr_cur]->app_line_width[0] = cur_w1;
				update = true;
			}
			if (prev_w2 != cur_w2)
			{
				prev_w2 = cur_w2;
				graph[0][gr_cur]->app_line_width[1] = cur_w2;
				update = true;
			}
			if (prev_w3 != cur_w3)
			{
				prev_w3 = cur_w3;
				v_w1[0] = cur_w3;
				if (NN > 0)
				{
					v_graph[0][1]->line_width = cur_w3;
				}
				update = true;
			}
			if (prev_w4 != cur_w4)
			{
				prev_w4 = cur_w4;
				v_w2[0] = cur_w4;
				for (int i = 2; i <= NN; i++)
				{
					v_graph[0][i]->line_width = cur_w4;
				}
				update = true;
			}
			if (prev_name != cur_name)
			{
				prev_name = cur_name;
				graph[0][gr_cur]->name = cur_name;
				pDoc->SetTitle(cur_name);
			}
			if (update)
			{
				pDoc->UpdateAllViews(0);
			}
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CAppColDlg::OnBnClickedButton3() //minus
{
	// TODO: Add your control notification handler code here
	if (gr_cur > 1)
	{
		gr_cur--;
		Init();
		DrawColor(graph[0][gr_cur]->app_col[0], 0);
		DrawColor(graph[0][gr_cur]->app_col[1], 1);
	}
}


void CAppColDlg::OnBnClickedButton2() //plus
{
	// TODO: Add your control notification handler code here
	if (graph[0][gr_cur]->next != 0)
	{
		gr_cur++;
		Init();
		DrawColor(graph[0][gr_cur]->app_col[0], 0);
		DrawColor(graph[0][gr_cur]->app_col[1], 1);
	}
}


void CAppColDlg::OnBnClickedButton4() //copy to polyn
{
	// TODO: Add your control notification handler code here
}


void CAppColDlg::OnBnClickedButton5() //copy to custom
{
	// TODO: Add your control notification handler code here
}


void CAppColDlg::DrawColor(COLORREF col, int n)
{
	// TODO: Add your implementation code here.
	CWnd* wn = 0;
	if (n == 0)
		wn = GetDlgItem(IDC_BUTTON1);
	if (n == 1)
		wn = GetDlgItem(IDC_BUTTON26);
	if (n == 2)
		wn = GetDlgItem(IDC_BUTTON27);
	if (n == 3)
		wn = GetDlgItem(IDC_BUTTON29);
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
