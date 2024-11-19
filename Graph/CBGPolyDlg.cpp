// CBGPolyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CBGPolyDlg.h"

//extern void GetLinearSystemRoot(double* A, int N, double* x, double* b);
//extern void SwapStrings(double* A, int i, int j, int N);
void SwapStrings(long double* A, int i, int j, int N)
{
	long double t;
	for (int k = 0; k < N; k++)
	{
		t = A[i * N + k];
		A[i * N + k] = A[j * N + k];
		A[j * N + k] = t;
	}
}
void GetLinearSystemRoot(long double* A, int N, long double* x, long double* b)
{
	int i, j, k; long double max;
	int maxj;
	long double sumb;
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
// CBGPolyDlg dialog

IMPLEMENT_DYNAMIC(CBGPolyDlg, CDialogEx)

CBGPolyDlg::CBGPolyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BGPOLY, pParent)
	, n(0)
	, iter(0)
{

}

CBGPolyDlg::~CBGPolyDlg()
{
}

void CBGPolyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n);
	DDV_MinMaxInt(pDX, n, 0, 9);
	DDX_Control(pDX, IDC_EDIT1, N_app_ed);
	DDX_Text(pDX, IDC_EDIT2, iter);
	DDX_Control(pDX, IDC_EDIT2, iter_ed);
}


BEGIN_MESSAGE_MAP(CBGPolyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CBGPolyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CBGPolyDlg message handlers


void CBGPolyDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString str;
	N_app_ed.GetWindowText(str);
	int n_app = atoi(str);
	if (n_app < 0 || n_app>9)
	{
		::MessageBox(0, "N must be in the range of 0 ... 9!", 0, MB_OK);
		return;
	}
	iter_ed.GetWindowText(str);
	iter = atoi(str);

	int n = graph[0][gr_cur]->length;
	double* x = graph[0][gr_cur]->X;
	double* y = graph[0][gr_cur]->Y;

	long double xs = 0, ys = 0;
	long double xys = 0, x2ys = 0, x3ys = 0, x4ys = 0, x5ys = 0, x6ys = 0, x7ys = 0, x8ys = 0, x9ys = 0;
	long double x2s = 0, x3s = 0, x4s = 0, x5s = 0, x6s = 0, x7s = 0, x8s = 0, x9s = 0, x10s = 0;
	long double x11s = 0, x12s = 0, x13s = 0, x14s = 0, x15s = 0, x16s = 0, x17s = 0, x18s = 0;
	long double X, Y, W, N;

	long double c_app[10];
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
	if (n_app > 0)
	{
		for (int ii = 0; ii < iter; ii++)
		{
			N = 0;
			xs = 0; ys = 0;
			xys = 0; x2ys = 0; x3ys = 0; x4ys = 0; x5ys = 0; x6ys = 0; x7ys = 0; x8ys = 0; x9ys = 0;
			x2s = 0; x3s = 0; x4s = 0; x5s = 0; x6s = 0; x7s = 0; x8s = 0; x9s = 0; x10s = 0;
			x11s = 0; x12s = 0; x13s = 0; x14s = 0; x15s = 0; x16s = 0; x17s = 0; x18s = 0;

			for (int i = 0; i < n; i++)
			{
				X = x[i];
				Y = y[i];
				W = 1;
				if (ii > 0)
				{
					Y = min(y[i], c_app[9] * X * X * X * X * X * X * X * X * X +
						c_app[8] * X * X * X * X * X * X * X * X + c_app[7] * X * X * X * X * X * X * X +
						c_app[6] * X * X * X * X * X * X + c_app[5] * X * X * X * X * X +
						c_app[4] * X * X * X * X + c_app[3] * X * X * X + c_app[2] * X * X + c_app[1] * X + c_app[0]);
				}

				ys += W * Y;
				xys += W * X * Y;
				x2ys += W * X * X * Y;
				x3ys += W * X * X * X * Y;
				x4ys += W * X * X * X * X * Y;
				x5ys += W * X * X * X * X * X * Y;
				x6ys += W * X * X * X * X * X * X * Y;
				x7ys += W * X * X * X * X * X * X * X * Y;
				x8ys += W * X * X * X * X * X * X * X * X * Y;
				x9ys += W * X * X * X * X * X * X * X * X * X * Y;

				xs += W * X;
				x2s += W * X * X;
				x3s += W * X * X * X;
				x4s += W * X * X * X * X;
				x5s += W * X * X * X * X * X;
				x6s += W * X * X * X * X * X * X;
				x7s += W * X * X * X * X * X * X * X;
				x8s += W * X * X * X * X * X * X * X * X;
				x9s += W * X * X * X * X * X * X * X * X * X;
				x10s += W * X * X * X * X * X * X * X * X * X * X;
				x11s += W * X * X * X * X * X * X * X * X * X * X * X;
				x12s += W * X * X * X * X * X * X * X * X * X * X * X * X;
				x13s += W * X * X * X * X * X * X * X * X * X * X * X * X * X;
				x14s += W * X * X * X * X * X * X * X * X * X * X * X * X * X * X;
				x15s += W * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X;
				x16s += W * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X;
				x17s += W * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X;
				x18s += W * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X * X;

				N += W;
			}

			if (n_app == 1)
			{
				c_app[1] = (N * xys - xs * ys) / (N * x2s - xs * xs);
				c_app[0] = (ys * x2s - xys * xs) / (N * x2s - xs * xs);
			}
			if (n_app == 2)
			{
				long double A[9];
				A[0] = x4s; A[1] = x3s; A[2] = x2s;
				A[3] = x3s; A[4] = x2s; A[5] = xs;
				A[6] = x2s; A[7] = xs;  A[8] = N;
				long double B[3];
				B[0] = x2ys; B[1] = xys; B[2] = ys;
				long double solution[3];
				GetLinearSystemRoot(A, 3, solution, B);
				c_app[2] = solution[0];
				c_app[1] = solution[1];
				c_app[0] = solution[2];
			}
			if (n_app == 3)
			{
				long double A[16];
				A[0] = x6s; A[1] = x5s; A[2] = x4s; A[3] = x3s;
				A[4] = x5s; A[5] = x4s; A[6] = x3s; A[7] = x2s;
				A[8] = x4s; A[9] = x3s; A[10] = x2s; A[11] = xs;
				A[12] = x3s; A[13] = x2s; A[14] = xs; A[15] = N;
				long double B[4];
				B[0] = x3ys; B[1] = x2ys; B[2] = xys; B[3] = ys;
				long double solution[4];
				GetLinearSystemRoot(A, 4, solution, B);
				c_app[3] = solution[0];
				c_app[2] = solution[1];
				c_app[1] = solution[2];
				c_app[0] = solution[3];
			}
			if (n_app == 4)
			{
				long double A[25];
				A[0] = x8s; A[1] = x7s; A[2] = x6s; A[3] = x5s; A[4] = x4s;
				A[5] = x7s; A[6] = x6s; A[7] = x5s; A[8] = x4s; A[9] = x3s;
				A[10] = x6s; A[11] = x5s; A[12] = x4s; A[13] = x3s; A[14] = x2s;
				A[15] = x5s; A[16] = x4s; A[17] = x3s; A[18] = x2s; A[19] = xs;
				A[20] = x4s; A[21] = x3s; A[22] = x2s; A[23] = xs; A[24] = N;
				long double B[5];
				B[0] = x4ys; B[1] = x3ys; B[2] = x2ys; B[3] = xys; B[4] = ys;
				long double solution[5];
				GetLinearSystemRoot(A, 5, solution, B);
				c_app[4] = solution[0];
				c_app[3] = solution[1];
				c_app[2] = solution[2];
				c_app[1] = solution[3];
				c_app[0] = solution[4];
			}
			if (n_app == 5)
			{
				long double A[36];
				A[0] = x10s; A[1] = x9s; A[2] = x8s; A[3] = x7s; A[4] = x6s; A[5] = x5s;
				A[6] = x9s; A[7] = x8s; A[8] = x7s; A[9] = x6s; A[10] = x5s; A[11] = x4s;
				A[12] = x8s; A[13] = x7s; A[14] = x6s; A[15] = x5s; A[16] = x4s; A[17] = x3s;
				A[18] = x7s; A[19] = x6s; A[20] = x5s; A[21] = x4s; A[22] = x3s; A[23] = x2s;
				A[24] = x6s; A[25] = x5s; A[26] = x4s; A[27] = x3s; A[28] = x2s; A[29] = xs;
				A[30] = x5s; A[31] = x4s; A[32] = x3s; A[33] = x2s; A[34] = xs; A[35] = N;
				long double B[6];
				B[0] = x5ys; B[1] = x4ys; B[2] = x3ys; B[3] = x2ys; B[4] = xys; B[5] = ys;
				long double solution[6];
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
				long double A[49];
				A[0] = x12s; A[1] = x11s; A[2] = x10s; A[3] = x9s; A[4] = x8s; A[5] = x7s; A[6] = x6s;
				A[7] = x11s; A[8] = x10s; A[9] = x9s; A[10] = x8s; A[11] = x7s; A[12] = x6s; A[13] = x5s;
				A[14] = x10s; A[15] = x9s; A[16] = x8s; A[17] = x7s; A[18] = x6s; A[19] = x5s; A[20] = x4s;
				A[21] = x9s; A[22] = x8s; A[23] = x7s; A[24] = x6s; A[25] = x5s; A[26] = x4s; A[27] = x3s;
				A[28] = x8s; A[29] = x7s; A[30] = x6s; A[31] = x5s; A[32] = x4s; A[33] = x3s; A[34] = x2s;
				A[35] = x7s; A[36] = x6s; A[37] = x5s; A[38] = x4s; A[39] = x3s; A[40] = x2s; A[41] = xs;
				A[42] = x6s; A[43] = x5s; A[44] = x4s; A[45] = x3s; A[46] = x2s; A[47] = xs; A[48] = N;
				long double B[7];
				B[0] = x6ys; B[1] = x5ys; B[2] = x4ys; B[3] = x3ys; B[4] = x2ys; B[5] = xys; B[6] = ys;
				long double solution[7];
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
				long double A[64];
				A[0] = x14s; A[1] = x13s; A[2] = x12s; A[3] = x11s; A[4] = x10s; A[5] = x9s; A[6] = x8s; A[7] = x7s;
				A[8] = x13s; A[9] = x12s; A[10] = x11s; A[11] = x10s; A[12] = x9s; A[13] = x8s; A[14] = x7s; A[15] = x6s;
				A[16] = x12s; A[17] = x11s; A[18] = x10s; A[19] = x9s; A[20] = x8s; A[21] = x7s; A[22] = x6s; A[23] = x5s;
				A[24] = x11s; A[25] = x10s; A[26] = x9s; A[27] = x8s; A[28] = x7s; A[29] = x6s; A[30] = x5s; A[31] = x4s;
				A[32] = x10s; A[33] = x9s; A[34] = x8s; A[35] = x7s; A[36] = x6s; A[37] = x5s; A[38] = x4s; A[39] = x3s;
				A[40] = x9s; A[41] = x8s; A[42] = x7s; A[43] = x6s; A[44] = x5s; A[45] = x4s; A[46] = x3s; A[47] = x2s;
				A[48] = x8s; A[49] = x7s; A[50] = x6s; A[51] = x5s; A[52] = x4s; A[53] = x3s; A[54] = x2s; A[55] = xs;
				A[56] = x7s; A[57] = x6s; A[58] = x5s; A[59] = x4s; A[60] = x3s; A[61] = x2s; A[62] = xs; A[63] = N;
				long double B[8];
				B[0] = x7ys; B[1] = x6ys; B[2] = x5ys; B[3] = x4ys; B[4] = x3ys; B[5] = x2ys; B[6] = xys; B[7] = ys;
				long double solution[8];
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
				long double A[81];
				A[0] = x16s; A[1] = x15s; A[2] = x14s; A[3] = x13s; A[4] = x12s; A[5] = x11s; A[6] = x10s; A[7] = x9s; A[8] = x8s;
				A[9] = x15s; A[10] = x14s; A[11] = x13s; A[12] = x12s; A[13] = x11s; A[14] = x10s; A[15] = x9s; A[16] = x8s; A[17] = x7s;
				A[18] = x14s; A[19] = x13s; A[20] = x12s; A[21] = x11s; A[22] = x10s; A[23] = x9s; A[24] = x8s; A[25] = x7s; A[26] = x6s;
				A[27] = x13s; A[28] = x12s; A[29] = x11s; A[30] = x10s; A[31] = x9s; A[32] = x8s; A[33] = x7s; A[34] = x6s; A[35] = x5s;
				A[36] = x12s; A[37] = x11s; A[38] = x10s; A[39] = x9s; A[40] = x8s; A[41] = x7s; A[42] = x6s; A[43] = x5s; A[44] = x4s;
				A[45] = x11s; A[46] = x10s; A[47] = x9s; A[48] = x8s; A[49] = x7s; A[50] = x6s; A[51] = x5s; A[52] = x4s; A[53] = x3s;
				A[54] = x10s; A[55] = x9s; A[56] = x8s; A[57] = x7s; A[58] = x6s; A[59] = x5s; A[60] = x4s; A[61] = x3s; A[62] = x2s;
				A[63] = x9s; A[64] = x8s; A[65] = x7s; A[66] = x6s; A[67] = x5s; A[68] = x4s; A[69] = x3s; A[70] = x2s; A[71] = xs;
				A[72] = x8s; A[73] = x7s; A[74] = x6s; A[75] = x5s; A[76] = x4s; A[77] = x3s; A[78] = x2s; A[79] = xs; A[80] = N;
				long double B[9];
				B[0] = x8ys; B[1] = x7ys; B[2] = x6ys; B[3] = x5ys; B[4] = x4ys; B[5] = x3ys; B[6] = x2ys; B[7] = xys; B[8] = ys;
				long double solution[9];
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
				long double A[100];
				A[0] = x18s; A[1] = x17s; A[2] = x16s; A[3] = x15s; A[4] = x14s; A[5] = x13s; A[6] = x12s; A[7] = x11s; A[8] = x10s; A[9] = x9s;
				A[10] = x17s; A[11] = x16s; A[12] = x15s; A[13] = x14s; A[14] = x13s; A[15] = x12s; A[16] = x11s; A[17] = x10s; A[18] = x9s; A[19] = x8s;
				A[20] = x16s; A[21] = x15s; A[22] = x14s; A[23] = x13s; A[24] = x12s; A[25] = x11s; A[26] = x10s; A[27] = x9s; A[28] = x8s; A[29] = x7s;
				A[30] = x15s; A[31] = x14s; A[32] = x13s; A[33] = x12s; A[34] = x11s; A[35] = x10s; A[36] = x9s; A[37] = x8s; A[38] = x7s; A[39] = x6s;
				A[40] = x14s; A[41] = x13s; A[42] = x12s; A[43] = x11s; A[44] = x10s; A[45] = x9s; A[46] = x8s; A[47] = x7s; A[48] = x6s; A[49] = x5s;
				A[50] = x13s; A[51] = x12s; A[52] = x11s; A[53] = x10s; A[54] = x9s; A[55] = x8s; A[56] = x7s; A[57] = x6s; A[58] = x5s; A[59] = x4s;
				A[60] = x12s; A[61] = x11s; A[62] = x10s; A[63] = x9s; A[64] = x8s; A[65] = x7s; A[66] = x6s; A[67] = x5s; A[68] = x4s; A[69] = x3s;
				A[70] = x11s; A[71] = x10s; A[72] = x9s; A[73] = x8s; A[74] = x7s; A[75] = x6s; A[76] = x5s; A[77] = x4s; A[78] = x3s; A[79] = x2s;
				A[80] = x10s; A[81] = x9s; A[82] = x8s; A[83] = x7s; A[84] = x6s; A[85] = x5s; A[86] = x4s; A[87] = x3s; A[88] = x2s; A[89] = xs;
				A[90] = x9s; A[91] = x8s; A[92] = x7s; A[93] = x6s; A[94] = x5s; A[95] = x4s; A[96] = x3s; A[97] = x2s; A[98] = xs; A[99] = N;
				long double B[10];
				B[0] = x9ys; B[1] = x8ys; B[2] = x7ys; B[3] = x6ys; B[4] = x5ys; B[5] = x4ys; B[6] = x3ys; B[7] = x2ys; B[8] = xys; B[9] = ys;
				long double solution[10];
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
		}
	}
	else
	{
		c_app[0] = y[0];
		for (int i = 1; i < n; i++)
		{
			c_app[0] = min(c_app[0], y[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		y_BG[i] = c_app[9] * x[i] * x[i] * x[i] * x[i] * x[i] * x[i] * x[i] * x[i] * x[i] +
			c_app[8] * x[i] * x[i] * x[i] * x[i] * x[i] * x[i] * x[i] * x[i] +
			c_app[7] * x[i] * x[i] * x[i] * x[i] * x[i] * x[i] * x[i] +
			c_app[6] * x[i] * x[i] * x[i] * x[i] * x[i] * x[i] +
			c_app[5] * x[i] * x[i] * x[i] * x[i] * x[i] +
			c_app[4] * x[i] * x[i] * x[i] * x[i] +
			c_app[3] * x[i] * x[i] * x[i] +
			c_app[2] * x[i] * x[i] +
			c_app[1] * x[i] +
			c_app[0];
	}

	if (gr_added)
	{
		int last = graph[0].GetNLast();
		for (unsigned int i = 0; i < graph[0][last]->length; i++)
		{
			graph[0][last]->Y[i] = y_BG[i];
		}
	}
	else
	{
		double* x_add = new double[n];
		double* y_add = new double[n];
		for (int i = 0; i < n; i++)
		{
			x_add[i] = graph[0][gr_cur]->X[i];
			y_add[i] = y_BG[i];
		}
		graph[0].AddData(x_add, y_add, n, "BG");
		gr_added = true;
	}
	pDoc->UpdateAllViews(0);
	/*double err = 0;
	for (int i = 0; i < n; i++)
	{
		err += (y_BG[i] - y[i]) * (y_BG[i] - y[i]);
	}
	char buf[100];
	sprintf(buf, "%g", err);
	::MessageBox(0, buf, 0, MB_OK);*/
}


BOOL CBGPolyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	y_BG = new double[graph[0][gr_cur]->length];
	for (unsigned int i = 0; i < graph[0][gr_cur]->length; i++)
		y_BG[i] = 0;
	gr_added = false;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
