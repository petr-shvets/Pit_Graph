// CReclorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CReclorDlg.h"
#include "CPaetteDlg.h"

// CReclorDlg dialog

IMPLEMENT_DYNAMIC(CReclorDlg, CDialogEx)

CReclorDlg::CReclorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RECOLOR_GR, pParent)
{
	DeleteObject(palette1);
}

CReclorDlg::~CReclorDlg()
{
}

void CReclorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CReclorDlg, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RADIO1, &CReclorDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CReclorDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CReclorDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CReclorDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CReclorDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_BUTTON6, &CReclorDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CReclorDlg message handlers


BOOL CReclorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	SetTimer(1, 300, 0);
	CButton* rad = (CButton*)GetDlgItem(IDC_RADIO1);
	if (pal_n == 2)
		rad = (CButton*)GetDlgItem(IDC_RADIO2);
	if (pal_n == 3)
		rad = (CButton*)GetDlgItem(IDC_RADIO3);
	if (pal_n == 4)
		rad = (CButton*)GetDlgItem(IDC_RADIO4);
	if (pal_n == 5)
		rad = (CButton*)GetDlgItem(IDC_RADIO5);
	rad->SetCheck(1);
	start = true;
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CReclorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (start)
	{
		CWnd* but[5];
		but[0] = GetDlgItem(IDC_BUTTON1);
		but[1] = GetDlgItem(IDC_BUTTON2);
		but[2] = GetDlgItem(IDC_BUTTON3);
		but[3] = GetDlgItem(IDC_BUTTON4);
		but[4] = GetDlgItem(IDC_BUTTON5);

		CDC* but_pal[5];
		for (int jjj = 0; jjj < 5; jjj++)
		{
			but_pal[jjj] = but[jjj]->GetDC();
			CRect r;
			but[jjj]->GetClientRect(&r);

			for (int i = 0; i < r.right; i++)
			{
				for (int j = 0; j < r.bottom; j++)
				{
					but_pal[jjj]->SetPixel(i, j, ValueToColor(0, r.right, i, jjj+1));
				}
			}

			ReleaseDC(but_pal[0]);
		}
		start = false;
	}

	CDialogEx::OnTimer(nIDEvent);
}
COLORREF CReclorDlg::ValueToColor(double min, double max, double val, int pallete)
{
	if (pallete == 1)
	{
		return RGB(255 * (max - val) / (max - min), 0, 255 * (val - min) / (max - min));
	}
	if (pallete == 2)
	{
		if (val < (max + min) / 2)
			return RGB(255 * ((max + min) / 2 - val) / ((max - min) / 2), 200 * (val - min) / ((max - min) / 2), 0);
		return RGB(0, 200 * (max - val) / ((max - min) / 2), 255 * (val - (max + min) / 2) / ((max - min) / 2));
	}
	if (pallete == 3)
	{
		if (val < (max + 7 * min) / 8) //G-G+B
			return RGB(200 * ((max + 7 * min) / 8 - val) / ((max - min) / 8) + 200 * (val - min) / ((max - min) / 8), 0, 200 * (val - min) / ((max - min) / 8));
		if (val < (max + min) / 2) //G+B-G+R
			return RGB(200 * ((max + min) / 2 - val) / (3 * (max - min) / 8) + 200 * (val - (max + 7 * min) / 8) / (3 * (max - min) / 8), 200 * (val - (max + 7 * min) / 8) / (3 * (max - min) / 8), 200 * ((max + min) / 2 - val) / (3 * (max - min) / 8));
		if (val < (3 * max + min) / 4) //G+R-R+B
			return RGB(200 * ((3 * max + min) / 4 - val) / ((max - min) / 4), 200 * ((3 * max + min) / 4 - val) / ((max - min) / 4) + 200 * (val - (max + min) / 2) / ((max - min) / 4), 200 * (val - (max + min) / 2) / ((max - min) / 4));
		//R+B-R
		return RGB(0, 200 * (max - val) / ((max - min) / 4) + 200 * (val - (3 * max + min) / 4) / ((max - min) / 4), 200 * (max - val) / ((max - min) / 4));
	}
	if (pallete == 4)
	{
		int r[8], g[8], b[8]; double p[8];
		r[0] = 68; r[1] = 70; r[2] = 54; r[3] = 39; r[4] = 31; r[5] = 74; r[6] = 159; r[7] = 253;
		g[0] = 1; g[1] = 50; g[2] = 92; g[3] = 127; g[4] = 161; g[5] = 194; g[6] = 218; g[7] = 231;
		b[0] = 84; b[1] = 127; b[2] = 141; b[3] = 142; b[4] = 135; b[5] = 109; b[6] = 58; b[7] = 37;
		p[0] = 0; p[1] = 0.14; p[2] = 0.29; p[3] = 0.43; p[4] = 0.57; p[5] = 0.71; p[6] = 0.86; p[7] = 1;

		double pval = (val - min) / (max - min);

		for (int i = 0; i < 7; i++)
		{
			if (val <= min + (max - min) * p[i + 1])
				return RGB(r[i] + (r[i + 1] - r[i]) * (pval - p[i]) / (p[i + 1] - p[i]), g[i] + (g[i + 1] - g[i]) * (pval - p[i]) / (p[i + 1] - p[i]), b[i] + (b[i + 1] - b[i]) * (pval - p[i]) / (p[i + 1] - p[i]));
		}
		return 0;
		//Viridis
	}
	if (pallete == 5)
	{
		double pval = (val - min) / (max - min);

		if (val < min + (max - min) * p[1])
			return RGB(r[0] + (r[1] - r[0]) * (pval - p[0]) / (p[1] - p[0]), g[0] + (g[1] - g[0]) * (pval - p[0]) / (p[1] - p[0]), b[0] + (b[1] - b[0]) * (pval - p[0]) / (p[1] - p[0]));
		if (val < min + (max - min) * p[2])
			return RGB(r[1] + (r[2] - r[1]) * (pval - p[1]) / (p[2] - p[1]), g[1] + (g[2] - g[1]) * (pval - p[1]) / (p[2] - p[1]), b[1] + (b[2] - b[1]) * (pval - p[1]) / (p[2] - p[1]));
		if (val < min + (max - min) * p[3])
			return RGB(r[2] + (r[3] - r[2]) * (pval - p[2]) / (p[3] - p[2]), g[2] + (g[3] - g[2]) * (pval - p[2]) / (p[3] - p[2]), b[2] + (b[3] - b[2]) * (pval - p[2]) / (p[3] - p[2]));
		return     RGB(r[3] + (r[4] - r[3]) * (pval - p[3]) / (p[4] - p[3]), g[3] + (g[4] - g[3]) * (pval - p[3]) / (p[4] - p[3]), b[3] + (b[4] - b[3]) * (pval - p[3]) / (p[4] - p[3]));
	}
	return RGB(0, 0, 0);
}

void CReclorDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	pal_n = 1;
}


void CReclorDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	pal_n = 2;
}


void CReclorDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	pal_n = 3;
}


void CReclorDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	pal_n = 4;
}


void CReclorDlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	pal_n = 5;
}


void CReclorDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	CPaetteDlg dlg;
	for (int i = 0; i < 5; i++)
	{
		dlg.p[i] = p[i];
		dlg.r[i] = r[i];
		dlg.g[i] = g[i];
		dlg.b[i] = b[i];
	}
	if (dlg.DoModal() == IDOK)
	{
		for (int i = 0; i < 5; i++)
		{
			p[i] = dlg.p[i];
			r[i] = dlg.r[i];
			g[i] = dlg.g[i];
			b[i] = dlg.b[i];
		}
	}

	CWnd* but;
	but = GetDlgItem(IDC_BUTTON5);

	CDC* but_pal;

	but_pal = but->GetDC();
	CRect r;
	but->GetClientRect(&r);

	for (int i = 0; i < r.right; i++)
	{
		for (int j = 0; j < r.bottom; j++)
		{
			but_pal->SetPixel(i, j, ValueToColor(0, r.right, i, 5));
		}
	}

	ReleaseDC(but_pal);
}
