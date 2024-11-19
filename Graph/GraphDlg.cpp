// GraphDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "GraphDlg.h"
#include "afxdialogex.h"


// CGraphDlg dialog

IMPLEMENT_DYNAMIC(CGraphDlg, CDialogEx)

CGraphDlg::CGraphDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGraphDlg::IDD, pParent)
{
	br_black.CreateSolidBrush(RGB(0, 0, 0));
	CPoint pt[3];
	pt[0] = CPoint(8, 4);
	pt[1] = CPoint(14, 14);
	pt[2] = CPoint(2, 14);
	ar_rgn1.CreatePolygonRgn(pt, 3, ALTERNATE);

	pt[0] = CPoint(8, 15);
	pt[1] = CPoint(14, 6);
	pt[2] = CPoint(3, 6);
	ar_rgn2.CreatePolygonRgn(pt, 3, ALTERNATE);
}

CGraphDlg::~CGraphDlg()
{
	DeleteObject(br_black);
	DeleteObject(ar_rgn1);
	DeleteObject(ar_rgn2);
}

void CGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, name);
	DDX_Control(pDX, IDC_EDIT2, w);
	DDX_Control(pDX, IDC_EDIT3, r);
	DDX_Control(pDX, IDC_EDIT4, g);
	DDX_Control(pDX, IDC_EDIT5, b);
	DDX_Control(pDX, IDC_LIST1, gr_list);
	DDX_Control(pDX, IDC_BUTTON6, but_up);
	DDX_Control(pDX, IDC_BUTTON7, but_down);
}


BEGIN_MESSAGE_MAP(CGraphDlg, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RADIO1, &CGraphDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CGraphDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CGraphDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CGraphDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CGraphDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_BUTTON2, &CGraphDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CGraphDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RADIO6, &CGraphDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON6, &CGraphDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CGraphDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CGraphDlg message handlers


BOOL CGraphDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	SetTimer(1, 300, NULL);
	first_event = true;
	for (int i = 1; i <= graph[0][0]->GetNLast(); i++)
	{
		gr_list.AddString(graph[0][i]->name);
	}
	Init();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CGraphDlg::DrawColor(COLORREF col)
{
	CWnd *wn = GetDlgItem(IDC_BUTTON1);
	RECT rec;
	wn->GetClientRect(&rec);
	CDC *pDC = wn->GetDC();

	CBrush br;
	br.CreateSolidBrush(col);
	CRgn rgn;
	rgn.CreateRectRgn(rec.left, rec.top, rec.right, rec.bottom);
	pDC->FillRgn(&rgn, &br);

	DeleteObject(br);
	DeleteObject(rgn);
	ReleaseDC(pDC);
}

void CGraphDlg::DrawArrows()
{
	CDC* pDC = but_up.GetDC();
	
	pDC->FillRgn(&ar_rgn1, &br_black);
	
	ReleaseDC(pDC);

	CDC* pDC2 = but_down.GetDC();
	
	pDC->FillRgn(&ar_rgn2, &br_black);

	ReleaseDC(pDC2);
}


void CGraphDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1)
	{
		DrawArrows();
		int aa = gr_list.GetCurSel();
		if (aa != gr_cur - 1)
		{
			gr_cur = aa + 1;
			Init();
		}

		char buf[100];
		int R, G, B;
		r.GetLine(0, buf, r.LineLength());
		buf[r.LineLength()] = 0;
		R = atoi(buf);
		g.GetLine(0, buf, g.LineLength());
		buf[g.LineLength()] = 0;
		G = atoi(buf);
		b.GetLine(0, buf, b.LineLength());
		buf[b.LineLength()] = 0;
		B = atoi(buf);

		static COLORREF prev_col = RGB(R, G, B);
		COLORREF cur_col = RGB(R, G, B);

		w.GetLine(0, buf, w.LineLength());
		buf[w.LineLength()] = 0;
		int cur_w = atoi(buf);
		static int prev_w = cur_w;

		CString cur_name;
		name.GetWindowText(cur_name);
		static CString prev_name = cur_name;

		if (first_event)
		{
			first_event = false;
			DrawColor(prev_col);
			DrawArrows();
		}
		else
		{
			bool update = false;
			if (prev_col != cur_col)
			{
				DrawColor(cur_col);
				prev_col = cur_col;
				graph[0][gr_cur]->col = cur_col;
				update = true;
			}
			if (prev_w != cur_w)
			{
				prev_w = cur_w;
				graph[0][gr_cur]->line_width = cur_w;
				update = true;
			}
			if (prev_name != cur_name)
			{
				prev_name = cur_name;
				graph[0][gr_cur]->name = cur_name;
				pDoc->SetTitle(cur_name);
				gr_list.DeleteString(gr_cur - 1);
				gr_list.InsertString(gr_cur - 1, cur_name);
				gr_list.SetCurSel(gr_cur - 1);
			}
			if (update)
			{
				pDoc->UpdateAllViews(0);
			}
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CGraphDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	graph[0][gr_cur]->marker = 0;
	pDoc->UpdateAllViews(0);
}


void CGraphDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	graph[0][gr_cur]->marker = 1;
	pDoc->UpdateAllViews(0);
}


void CGraphDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	graph[0][gr_cur]->marker = 2;
	pDoc->UpdateAllViews(0);
}


void CGraphDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	graph[0][gr_cur]->marker = 3;
	pDoc->UpdateAllViews(0);
}


void CGraphDlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	graph[0][gr_cur]->marker = 4;
	pDoc->UpdateAllViews(0);
}


void CGraphDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	//+
	if (graph[0][gr_cur]->next != 0)
	{
		gr_cur++;
		Init();
		DrawColor(graph[0][gr_cur]->col);
	}
}


void CGraphDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	//-
	if (gr_cur > 1)
	{
		gr_cur--;
		Init();
		DrawColor(graph[0][gr_cur]->col);
	}
}


void CGraphDlg::Init()
{
	name.SetWindowTextA(graph[0][gr_cur]->name);

	COLORREF col = graph[0][gr_cur]->col;
	char buf[100];
	int ccc = GetRValue(col);
	int a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	r.SetWindowTextA(buf);
	ccc = GetGValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	g.SetWindowTextA(buf);
	ccc = GetBValue(col);
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	b.SetWindowTextA(buf);

	ccc = graph[0][gr_cur]->line_width;
	a = sprintf_s(buf, "%d", ccc);
	buf[a] = 0;
	w.SetWindowTextA(buf);

	ccc = graph[0][gr_cur]->marker;
	
	CButton *but[6];
	but[0] = (CButton*)GetDlgItem(IDC_RADIO1);
	but[1] = (CButton*)GetDlgItem(IDC_RADIO2);
	but[2] = (CButton*)GetDlgItem(IDC_RADIO3);
	but[3] = (CButton*)GetDlgItem(IDC_RADIO4);
	but[4] = (CButton*)GetDlgItem(IDC_RADIO5);
	but[5] = (CButton*)GetDlgItem(IDC_RADIO6);
	for (int i = 0; i < 6; i++)
	{
		but[i]->SetCheck(0);
		if (ccc == i)
		{
			but[i]->SetCheck(1);
		}
	}
	
	gr_list.SetCurSel(gr_cur - 1);
}


void CGraphDlg::OnBnClickedRadio6()
{
	// TODO: Add your control notification handler code here
	graph[0][gr_cur]->marker = 5;
	pDoc->UpdateAllViews(0);
}


void CGraphDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	//up
	DrawArrows();

	int aa = gr_list.GetCurSel();
	if (aa <= 0) return;

	SwapGraphs(aa, aa + 1);

	gr_list.ResetContent();

	for (int i = 1; i <= graph[0][0]->GetNLast(); i++)
	{
		gr_list.AddString(graph[0][i]->name);
	}
	gr_list.SetCurSel(aa - 1);
}


void CGraphDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	//down
	DrawArrows();

	int aa = gr_list.GetCurSel();
	if (aa >= graph[0][0]->GetNLast() - 1) return;

	SwapGraphs(aa + 1, aa + 2);

	gr_list.ResetContent();

	for (int i = 1; i <= graph[0][0]->GetNLast(); i++)
	{
		gr_list.AddString(graph[0][i]->name);
	}
	gr_list.SetCurSel(aa + 1);
}

void CGraphDlg::SwapGraphs(int i, int j)
{
	if (i == j) return;
	if (i > graph[0].GetNLast() || j > graph[0].GetNLast()) return;
	if (i <= 0 || j <= 0) return;

	double* t_d;
	t_d = graph[0][i]->X;
	graph[0][i]->X = graph[0][j]->X;
	graph[0][j]->X = t_d;

	t_d = graph[0][i]->Y;
	graph[0][i]->Y = graph[0][j]->Y;
	graph[0][j]->Y = t_d;

	unsigned int t_ui;
	t_ui = graph[0][i]->length;
	graph[0][i]->length = graph[0][j]->length;
	graph[0][j]->length = t_ui;

	COLORREF t_col;
	t_col = graph[0][i]->col;
	graph[0][i]->col = graph[0][j]->col;
	graph[0][j]->col = t_col;

	int t_i;
	t_i = graph[0][i]->line_width;
	graph[0][i]->line_width = graph[0][j]->line_width;
	graph[0][j]->line_width = t_i;

	t_i = graph[0][i]->marker;
	graph[0][i]->marker = graph[0][j]->marker;
	graph[0][j]->marker = t_i;
	
	t_i = graph[0][i]->index;
	graph[0][i]->index = graph[0][j]->index;
	graph[0][j]->index = t_i;

	double t_dd;
	for (int k = 0; k < 5; k++)
	{
		t_dd = graph[0][i]->app_var_min[k];
		graph[0][i]->app_var_min[k] = graph[0][j]->app_var_min[k];
		graph[0][j]->app_var_min[k] = t_dd;

		t_dd = graph[0][i]->app_var_max[k];
		graph[0][i]->app_var_max[k] = graph[0][j]->app_var_max[k];
		graph[0][j]->app_var_max[k] = t_dd;

		t_dd = graph[0][i]->app_var_val[k];
		graph[0][i]->app_var_val[k] = graph[0][j]->app_var_val[k];
		graph[0][j]->app_var_val[k] = t_dd;

		t_i = graph[0][i]->app_var_N[k];
		graph[0][i]->app_var_N[k] = graph[0][j]->app_var_N[k];
		graph[0][j]->app_var_N[k] = t_i;
	}
	for (int k = 0; k < 10; k++)
	{
		t_dd = graph[0][i]->poly_fit[k];
		graph[0][i]->poly_fit[k] = graph[0][j]->poly_fit[k];
		graph[0][j]->poly_fit[k] = t_dd;
	}

	for (int k = 0; k < 2; k++)
	{
		t_col = graph[0][i]->app_col[k];
		graph[0][i]->app_col[k] = graph[0][j]->app_col[k];
		graph[0][j]->app_col[k] = t_col;

		t_i = graph[0][i]->app_line_width[k];
		graph[0][i]->app_line_width[k] = graph[0][j]->app_line_width[k];
		graph[0][j]->app_line_width[k] = t_i;
	}

	CString t_str;
	t_str = graph[0][i]->name;
	graph[0][i]->name = graph[0][j]->name;
	graph[0][j]->name = t_str;

	t_str = graph[0][i]->app_eq;
	graph[0][i]->app_eq = graph[0][j]->app_eq;
	graph[0][j]->app_eq = t_str;
	
	/*CGraph* t_gr1, * t_gr2;

	t_gr1 = graph[0][i - 1]->next;
	t_gr2 = graph[0][j - 1]->next;
	if (i > j)
	{
		graph[0][i - 1]->next = t_gr2;
		graph[0][j - 1]->next = t_gr1;
	}
	else
	{
		graph[0][j - 1]->next = t_gr1;
		graph[0][i - 1]->next = t_gr2;
	}*/
}