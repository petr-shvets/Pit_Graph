// CPolyAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CPolyAppDlg.h"


// CPolyAppDlg dialog

IMPLEMENT_DYNAMIC(CPolyAppDlg, CDialogEx)

CPolyAppDlg::CPolyAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_POLY_APP, pParent)
{
	
}

CPolyAppDlg::~CPolyAppDlg()
{
}

void CPolyAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, N_app_ed);
}


BEGIN_MESSAGE_MAP(CPolyAppDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPolyAppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPolyAppDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CPolyAppDlg message handlers
void SwapStrings(double * A, int i, int j, int N)
{
	long double t;
	for (int k = 0; k < N; k++)
	{
		t = A[i * N + k];
		A[i * N + k] = A[j * N + k];
		A[j * N + k] = t;
	}
}
void GetLinearSystemRoot(double* A, int N, double* x, double* b)
{
	int i, j, k; double max;
	int maxj;
	double sumb;
	for (i = 0; i < N - 1; i++)
	{
		max = A[i * (N + 1)];
		maxj = i;
		for (j = i + 1; j < N; j++)
		{
			if (fabs(A[i + j * N]) > fabs(max))
			{
				max = A[i + j * N];
				maxj = j;
			}
		}
		SwapStrings(A, i, maxj, N);
		SwapStrings(b, i, maxj, 1);
		for (j = i + 1; j < N; j++)
		{
			for (k = i + 1; k < N; k++)
			{
				A[k + j * N] = -(A[i + j * N] / A[i + i * N]) * A[k + i * N] + A[k + j * N];
			}
			b[j] = b[j] - (A[i + j * N] / A[i + i * N]) * b[i];
			A[i + j * N] = 0;
		}
	}
	for (j = N - 1; j >= 0; j--)
	{
		sumb = 0;
		for (k = N - 1; k > j; k--)
		{
			sumb += -x[k] * A[k + j * N];
		}
		x[j] = (b[j] + sumb) / A[j + j * N];
	}
}

void CPolyAppDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString str;
	N_app_ed.GetWindowText(str);
	n_app = atoi(str);
	if (n_app < 0 || n_app>9)
	{
		::MessageBox(0, "N must be in the range of 0 ... 9!", 0, MB_OK);
		return;
	}

	double xs = 0, ys = 0;
	double xys = 0, x2ys = 0, x3ys = 0, x4ys = 0, x5ys = 0, x6ys = 0, x7ys = 0, x8ys = 0, x9ys = 0;
	double x2s = 0, x3s = 0, x4s = 0, x5s = 0, x6s = 0, x7s = 0, x8s = 0, x9s = 0, x10s = 0;
	double x11s = 0, x12s = 0, x13s = 0, x14s = 0, x15s = 0, x16s = 0, x17s = 0, x18s = 0;
	double X, Y;

	c_app[0] = 0;
	c_app[1] = 0;
	c_app[2] = 0;
	c_app[3] = 0;
	c_app[4] = 0;
	c_app[5] = 0;
	c_app[6] = 0;
	c_app[7] = 0;
	c_app[8] = 0;
	c_app[9] = 0;

	for (int i = 0; i < n; i++)
	{
		X = x[i];
		Y = y[i];

		ys += Y;
		xys += X * Y;
		x2ys += X * X * Y;
		x3ys += X * X * X * Y;
		x4ys += X * X * X * X * Y;
		x5ys += X * X * X * X * X * Y;
		x6ys += X * X * X * X * X * X * Y;
		x7ys += X * X * X * X * X * X * X * Y;
		x8ys += X * X * X * X * X * X * X * X * Y;
		x9ys += X * X * X * X * X * X * X * X * X * Y;

		xs += X;
		x2s += X * X;
		x3s += X * X * X;
		x4s += X * X * X * X;
		x5s += X * X * X * X * X;
		x6s += X * X * X * X * X * X;
		x7s += X * X * X * X * X * X * X;
		x8s += X * X * X * X * X * X * X * X;
		x9s += X * X * X * X * X * X * X * X * X;
		x10s += X * X * X * X * X * X * X * X * X * X;
		x11s += X * X * X * X * X * X * X * X * X * X * X;
		x12s += X * X * X * X * X * X * X * X * X * X * X * X;
		x13s += X * X * X * X * X * X * X * X * X * X * X * X * X;
		x14s += X * X * X * X * X * X * X * X * X * X * X * X * X * X;
		x15s += X * X * X * X * X * X * X * X * X * X * X * X * X * X * X;
		x16s += X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X;
		x17s += X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X;
		x18s += X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X;

	}
	
	if (n_app == 0)
	{
		c_app[0] = ys / n;
	}

	if (n_app == 1)
	{
		c_app[1] = (n*xys - xs * ys) / (n*x2s - xs * xs);
		c_app[0] = (ys * x2s - xys * xs) / (n*x2s - xs * xs);
	}
	if (n_app == 2)
	{
		double A[9];
		A[0] = x4s; A[1] = x3s; A[2] = x2s;
		A[3] = x3s; A[4] = x2s; A[5] = xs;
		A[6] = x2s; A[7] = xs;  A[8] = n;
		double B[3];
		B[0] = x2ys; B[1] = xys; B[2] = ys;
		double solution[3];
		GetLinearSystemRoot(A, 3, solution, B);
		c_app[2] = solution[0];
		c_app[1] = solution[1];
		c_app[0] = solution[2];
	}
	if (n_app == 3)
	{
		double A[16];
		A[0] = x6s; A[1] = x5s; A[2] = x4s; A[3] = x3s;
		A[4] = x5s; A[5] = x4s; A[6] = x3s; A[7] = x2s;
		A[8] = x4s; A[9] = x3s; A[10] = x2s; A[11] = xs;
		A[12] = x3s; A[13] = x2s; A[14] = xs; A[15] = n;
		double B[4];
		B[0] = x3ys; B[1] = x2ys; B[2] = xys; B[3] = ys;
		double solution[4];
		GetLinearSystemRoot(A, 4, solution, B);
		c_app[3] = solution[0];
		c_app[2] = solution[1];
		c_app[1] = solution[2];
		c_app[0] = solution[3];
	}
	if (n_app == 4)
	{
		double A[25];
		A[0] = x8s; A[1] = x7s; A[2] = x6s; A[3] = x5s; A[4] = x4s;
		A[5] = x7s; A[6] = x6s; A[7] = x5s; A[8] = x4s; A[9] = x3s;
		A[10] = x6s; A[11] = x5s; A[12] = x4s; A[13] = x3s; A[14] = x2s;
		A[15] = x5s; A[16] = x4s; A[17] = x3s; A[18] = x2s; A[19] = xs;
		A[20] = x4s; A[21] = x3s; A[22] = x2s; A[23] = xs; A[24] = n;
		double B[5];
		B[0] = x4ys; B[1] = x3ys; B[2] = x2ys; B[3] = xys; B[4] = ys;
		double solution[5];
		GetLinearSystemRoot(A, 5, solution, B);
		c_app[4] = solution[0];
		c_app[3] = solution[1];
		c_app[2] = solution[2];
		c_app[1] = solution[3];
		c_app[0] = solution[4];
	}
	if (n_app == 5)
	{
		double A[36];
		A[0] = x10s; A[1] = x9s; A[2] = x8s; A[3] = x7s; A[4] = x6s; A[5] = x5s;
		A[6] = x9s; A[7] = x8s; A[8] = x7s; A[9] = x6s; A[10] = x5s; A[11] = x4s;
		A[12] = x8s; A[13] = x7s; A[14] = x6s; A[15] = x5s; A[16] = x4s; A[17] = x3s;
		A[18] = x7s; A[19] = x6s; A[20] = x5s; A[21] = x4s; A[22] = x3s; A[23] = x2s;
		A[24] = x6s; A[25] = x5s; A[26] = x4s; A[27] = x3s; A[28] = x2s; A[29] = xs;
		A[30] = x5s; A[31] = x4s; A[32] = x3s; A[33] = x2s; A[34] = xs; A[35] = n;
		double B[6];
		B[0] = x5ys; B[1] = x4ys; B[2] = x3ys; B[3] = x2ys; B[4] = xys; B[5] = ys;
		double solution[6];
		GetLinearSystemRoot(A, 6, solution, B);
		c_app[5] = solution[0];
		c_app[4] = solution[1];
		c_app[3] = solution[2];
		c_app[2] = solution[3];
		c_app[1] = solution[4];
		c_app[0] = solution[5];
	}
	if (n_app == 6)
	{
		double A[49];
		A[0] = x12s; A[1] = x11s; A[2] = x10s; A[3] = x9s; A[4] = x8s; A[5] = x7s; A[6] = x6s;
		A[7] = x11s; A[8] = x10s; A[9] = x9s; A[10] = x8s; A[11] = x7s; A[12] = x6s; A[13] = x5s;
		A[14] = x10s; A[15] = x9s; A[16] = x8s; A[17] = x7s; A[18] = x6s; A[19] = x5s; A[20] = x4s;
		A[21] = x9s; A[22] = x8s; A[23] = x7s; A[24] = x6s; A[25] = x5s; A[26] = x4s; A[27] = x3s;
		A[28] = x8s; A[29] = x7s; A[30] = x6s; A[31] = x5s; A[32] = x4s; A[33] = x3s; A[34] = x2s;
		A[35] = x7s; A[36] = x6s; A[37] = x5s; A[38] = x4s; A[39] = x3s; A[40] = x2s; A[41] = xs;
		A[42] = x6s; A[43] = x5s; A[44] = x4s; A[45] = x3s; A[46] = x2s; A[47] = xs; A[48] = n;
		double B[7];
		B[0] = x6ys; B[1] = x5ys; B[2] = x4ys; B[3] = x3ys; B[4] = x2ys; B[5] = xys; B[6] = ys;
		double solution[7];
		GetLinearSystemRoot(A, 7, solution, B);
		c_app[6] = solution[0];
		c_app[5] = solution[1];
		c_app[4] = solution[2];
		c_app[3] = solution[3];
		c_app[2] = solution[4];
		c_app[1] = solution[5];
		c_app[0] = solution[6];
	}
	if (n_app == 7)
	{
		double A[64];
		A[0] = x14s; A[1] = x13s; A[2] = x12s; A[3] = x11s; A[4] = x10s; A[5] = x9s; A[6] = x8s; A[7] = x7s;
		A[8] = x13s; A[9] = x12s; A[10] = x11s; A[11] = x10s; A[12] = x9s; A[13] = x8s; A[14] = x7s; A[15] = x6s;
		A[16] = x12s; A[17] = x11s; A[18] = x10s; A[19] = x9s; A[20] = x8s; A[21] = x7s; A[22] = x6s; A[23] = x5s;
		A[24] = x11s; A[25] = x10s; A[26] = x9s; A[27] = x8s; A[28] = x7s; A[29] = x6s; A[30] = x5s; A[31] = x4s;
		A[32] = x10s; A[33] = x9s; A[34] = x8s; A[35] = x7s; A[36] = x6s; A[37] = x5s; A[38] = x4s; A[39] = x3s;
		A[40] = x9s; A[41] = x8s; A[42] = x7s; A[43] = x6s; A[44] = x5s; A[45] = x4s; A[46] = x3s; A[47] = x2s;
		A[48] = x8s; A[49] = x7s; A[50] = x6s; A[51] = x5s; A[52] = x4s; A[53] = x3s; A[54] = x2s; A[55] = xs;
		A[56] = x7s; A[57] = x6s; A[58] = x5s; A[59] = x4s; A[60] = x3s; A[61] = x2s; A[62] = xs; A[63] = n;
		double B[8];
		B[0] = x7ys; B[1] = x6ys; B[2] = x5ys; B[3] = x4ys; B[4] = x3ys; B[5] = x2ys; B[6] = xys; B[7] = ys;
		double solution[8];
		GetLinearSystemRoot(A, 8, solution, B);
		c_app[7] = solution[0];
		c_app[6] = solution[1];
		c_app[5] = solution[2];
		c_app[4] = solution[3];
		c_app[3] = solution[4];
		c_app[2] = solution[5];
		c_app[1] = solution[6];
		c_app[0] = solution[7];
	}
	if (n_app == 8)
	{
		double A[81];
		A[0] = x16s; A[1] = x15s; A[2] = x14s; A[3] = x13s; A[4] = x12s; A[5] = x11s; A[6] = x10s; A[7] = x9s; A[8] = x8s;
		A[9] = x15s; A[10] = x14s; A[11] = x13s; A[12] = x12s; A[13] = x11s; A[14] = x10s; A[15] = x9s; A[16] = x8s; A[17] = x7s;
		A[18] = x14s; A[19] = x13s; A[20] = x12s; A[21] = x11s; A[22] = x10s; A[23] = x9s; A[24] = x8s; A[25] = x7s; A[26] = x6s;
		A[27] = x13s; A[28] = x12s; A[29] = x11s; A[30] = x10s; A[31] = x9s; A[32] = x8s; A[33] = x7s; A[34] = x6s; A[35] = x5s;
		A[36] = x12s; A[37] = x11s; A[38] = x10s; A[39] = x9s; A[40] = x8s; A[41] = x7s; A[42] = x6s; A[43] = x5s; A[44] = x4s;
		A[45] = x11s; A[46] = x10s; A[47] = x9s; A[48] = x8s; A[49] = x7s; A[50] = x6s; A[51] = x5s; A[52] = x4s; A[53] = x3s;
		A[54] = x10s; A[55] = x9s; A[56] = x8s; A[57] = x7s; A[58] = x6s; A[59] = x5s; A[60] = x4s; A[61] = x3s; A[62] = x2s;
		A[63] = x9s; A[64] = x8s; A[65] = x7s; A[66] = x6s; A[67] = x5s; A[68] = x4s; A[69] = x3s; A[70] = x2s; A[71] = xs;
		A[72] = x8s; A[73] = x7s; A[74] = x6s; A[75] = x5s; A[76] = x4s; A[77] = x3s; A[78] = x2s; A[79] = xs; A[80] = n;
		double B[9];
		B[0] = x8ys; B[1] = x7ys; B[2] = x6ys; B[3] = x5ys; B[4] = x4ys; B[5] = x3ys; B[6] = x2ys; B[7] = xys; B[8] = ys;
		double solution[9];
		GetLinearSystemRoot(A, 9, solution, B);
		c_app[8] = solution[0];
		c_app[7] = solution[1];
		c_app[6] = solution[2];
		c_app[5] = solution[3];
		c_app[4] = solution[4];
		c_app[3] = solution[5];
		c_app[2] = solution[6];
		c_app[1] = solution[7];
		c_app[0] = solution[8];
	}
	if (n_app == 9)
	{
		double A[100];
		A[0] = x18s; A[1] = x17s; A[2] = x16s; A[3] = x15s; A[4] = x14s; A[5] = x13s; A[6] = x12s; A[7] = x11s; A[8] = x10s; A[9] = x9s;
		A[10] = x17s; A[11] = x16s; A[12] = x15s; A[13] = x14s; A[14] = x13s; A[15] = x12s; A[16] = x11s; A[17] = x10s; A[18] = x9s; A[19] = x8s;
		A[20] = x16s; A[21] = x15s; A[22] = x14s; A[23] = x13s; A[24] = x12s; A[25] = x11s; A[26] = x10s; A[27] = x9s; A[28] = x8s; A[29] = x7s;
		A[30] = x15s; A[31] = x14s; A[32] = x13s; A[33] = x12s; A[34] = x11s; A[35] = x10s; A[36] = x9s; A[37] = x8s; A[38] = x7s; A[39] = x6s;
		A[40] = x14s; A[41] = x13s; A[42] = x12s; A[43] = x11s; A[44] = x10s; A[45] = x9s; A[46] = x8s; A[47] = x7s; A[48] = x6s; A[49] = x5s;
		A[50] = x13s; A[51] = x12s; A[52] = x11s; A[53] = x10s; A[54] = x9s; A[55] = x8s; A[56] = x7s; A[57] = x6s; A[58] = x5s; A[59] = x4s;
		A[60] = x12s; A[61] = x11s; A[62] = x10s; A[63] = x9s; A[64] = x8s; A[65] = x7s; A[66] = x6s; A[67] = x5s; A[68] = x4s; A[69] = x3s;
		A[70] = x11s; A[71] = x10s; A[72] = x9s; A[73] = x8s; A[74] = x7s; A[75] = x6s; A[76] = x5s; A[77] = x4s; A[78] = x3s; A[79] = x2s;
		A[80] = x10s; A[81] = x9s; A[82] = x8s; A[83] = x7s; A[84] = x6s; A[85] = x5s; A[86] = x4s; A[87] = x3s; A[88] = x2s; A[89] = xs;
		A[90] = x9s; A[91] = x8s; A[92] = x7s; A[93] = x6s; A[94] = x5s; A[95] = x4s; A[96] = x3s; A[97] = x2s; A[98] = xs; A[99] = n;
		double B[10];
		B[0] = x9ys; B[1] = x8ys; B[2] = x7ys; B[3] = x6ys; B[4] = x5ys; B[5] = x4ys; B[6] = x3ys; B[7] = x2ys; B[8] = xys; B[9] = ys;
		double solution[10];
		GetLinearSystemRoot(A, 10, solution, B);
		c_app[9] = solution[0];
		c_app[8] = solution[1];
		c_app[7] = solution[2];
		c_app[6] = solution[3];
		c_app[5] = solution[4];
		c_app[4] = solution[5];
		c_app[3] = solution[6];
		c_app[2] = solution[7];
		c_app[1] = solution[8];
		c_app[0] = solution[9];
	}
	char buf[255];
	char sign[10];
	for (int i = 0; i < 10; i++)
	{
		if (c_app[i] < 0) sign[i] = '-';
		else sign[i] = '+';
	}
	sprintf(buf, "y = %g %c %g*x %c\r\n%g*x^2 %c %g*x^3 %c\r\n%g*x^4 %c %g*x^5 %c\r\n%g*x^6 %c %g*x^7 %c\r\n%g*x^8 %c %g*x^9", c_app[0], sign[1], abs(c_app[1]), sign[2], abs(c_app[2]), sign[3], abs(c_app[3]), sign[4], abs(c_app[4]), sign[5], abs(c_app[5]), sign[6], abs(c_app[6]), sign[7], abs(c_app[7]), sign[8], abs(c_app[8]), sign[9], abs(c_app[9]));
	CWnd* wnd=GetDlgItem(IDC_EXPR);
	wnd->SetWindowTextA(buf);

	for (int i = 0; i < 10; i++)
	{
		graph[0][gr_cur]->poly_fit[i] = c_app[i];
	}
	pDoc->UpdateAllViews(0);
}


BOOL CPolyAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	char buf[255];
	sprintf(buf, "%d", n_app);
	N_app_ed.SetWindowTextA(buf);

	sprintf(buf, "y = %g + %g*x +\r\n%g*x^2 + %g*x^3 +\r\n%g*x^4 + %g*x^5 +\r\n%g*x^6 + %g*x^7 +\r\n%g*x^8 + %g*x^9", c_app[0], c_app[1], c_app[2], c_app[3], c_app[4], c_app[5], c_app[6], c_app[7], c_app[8], c_app[9]);
	CWnd* wnd = GetDlgItem(IDC_EXPR);
	wnd->SetWindowTextA(buf);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CPolyAppDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	char buf[255];
	char sign[10];
	for (int i = 0; i < 10; i++)
	{
		if (c_app[i] < 0) sign[i] = '-';
		else sign[i] = '+';
	}
	sprintf(buf, "%g %c %g*x %c %g*x^2 %c %g*x^3 %c %g*x^4 %c %g*x^5 %c %g*x^6 %c %g*x^7 %c %g*x^8 %c %g*x^9", c_app[0], sign[1], abs(c_app[1]), sign[2], abs(c_app[2]), sign[3], abs(c_app[3]), sign[4], abs(c_app[4]), sign[5], abs(c_app[5]), sign[6], abs(c_app[6]), sign[7], abs(c_app[7]), sign[8], abs(c_app[8]), sign[9], abs(c_app[9]));
	
	const size_t len = strlen(buf) + 1;
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), buf, len);
	GlobalUnlock(hMem);
	OpenClipboard();
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
}
