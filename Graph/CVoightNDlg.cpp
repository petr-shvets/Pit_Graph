// CVoightNDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CVoightNDlg.h"

extern double GetDigitalFromString(char* buf, char separ);
extern int GetLengthDigital(char* buf, char separ);
// CVoightNDlg dialog

IMPLEMENT_DYNAMIC(CVoightNDlg, CDialogEx)

CVoightNDlg::CVoightNDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VOIGHTNDLG, pParent)
	, n_iter(0)
{
	for (int i = 0; i < Nmax; i++)
	{
		H[i] = 0;
		FWHM[i] = 0;
		n[i] = 0;
		x[i] = 0;
	}
	batch_analyze = false;
}

CVoightNDlg::~CVoightNDlg()
{
}

void CVoightNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT1, H_ed[0]);
	DDX_Control(pDX, IDC_EDIT5, H_ed[1]);
	DDX_Control(pDX, IDC_EDIT10, H_ed[2]);
	DDX_Control(pDX, IDC_EDIT11, H_ed[3]);
	DDX_Control(pDX, IDC_EDIT12, H_ed[4]);
	DDX_Control(pDX, IDC_EDIT13, H_ed[5]);
	DDX_Control(pDX, IDC_EDIT14, H_ed[6]);

	DDX_Control(pDX, IDC_EDIT2, FWHM_ed[0]);
	DDX_Control(pDX, IDC_EDIT7, FWHM_ed[1]);
	DDX_Control(pDX, IDC_EDIT15, FWHM_ed[2]);
	DDX_Control(pDX, IDC_EDIT16, FWHM_ed[3]);
	DDX_Control(pDX, IDC_EDIT17, FWHM_ed[4]);
	DDX_Control(pDX, IDC_EDIT18, FWHM_ed[5]);
	DDX_Control(pDX, IDC_EDIT19, FWHM_ed[6]);

	DDX_Control(pDX, IDC_EDIT3, x_ed[0]);
	DDX_Control(pDX, IDC_EDIT8, x_ed[1]);
	DDX_Control(pDX, IDC_EDIT20, x_ed[2]);
	DDX_Control(pDX, IDC_EDIT21, x_ed[3]);
	DDX_Control(pDX, IDC_EDIT22, x_ed[4]);
	DDX_Control(pDX, IDC_EDIT23, x_ed[5]);
	DDX_Control(pDX, IDC_EDIT24, x_ed[6]);

	DDX_Control(pDX, IDC_EDIT4, n_ed[0]);
	DDX_Control(pDX, IDC_EDIT9, n_ed[1]);
	DDX_Control(pDX, IDC_EDIT25, n_ed[2]);
	DDX_Control(pDX, IDC_EDIT26, n_ed[3]);
	DDX_Control(pDX, IDC_EDIT27, n_ed[4]);
	DDX_Control(pDX, IDC_EDIT28, n_ed[5]);
	DDX_Control(pDX, IDC_EDIT29, n_ed[6]);

	DDX_Control(pDX, IDC_EDIT30, H_min_ed);
	DDX_Control(pDX, IDC_EDIT38, H_max_ed);
	DDX_Control(pDX, IDC_EDIT31, H_step_ed);
	DDX_Control(pDX, IDC_EDIT32, FWHM_min_ed);
	DDX_Control(pDX, IDC_EDIT33, FWHM_step_ed);
	DDX_Control(pDX, IDC_EDIT39, FWHM_max_ed);
	DDX_Control(pDX, IDC_EDIT34, x_min_ed);
	DDX_Control(pDX, IDC_EDIT35, x_step_ed);
	DDX_Control(pDX, IDC_EDIT40, x_max_ed);
	DDX_Control(pDX, IDC_EDIT36, n_min_ed);
	DDX_Control(pDX, IDC_EDIT37, n_step_ed);
	DDX_Control(pDX, IDC_EDIT41, n_max_ed);

	DDX_Control(pDX, IDC_EDIT6, int_ed[0]);
	DDX_Control(pDX, IDC_EDIT42, int_ed[1]);
	DDX_Control(pDX, IDC_EDIT43, int_ed[2]);
	DDX_Control(pDX, IDC_EDIT44, int_ed[3]);
	DDX_Control(pDX, IDC_EDIT45, int_ed[4]);
	DDX_Control(pDX, IDC_EDIT46, int_ed[5]);
	DDX_Control(pDX, IDC_EDIT47, int_ed[6]);
	DDX_Text(pDX, IDC_EDIT48, n_iter);
	DDX_Control(pDX, IDC_EDIT48, n_iter_ed);
	DDX_Control(pDX, IDC_EDIT49, iter_cur_ed);
}


BEGIN_MESSAGE_MAP(CVoightNDlg, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON10, &CVoightNDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_RADIO1, &CVoightNDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CVoightNDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CVoightNDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CVoightNDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CVoightNDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO7, &CVoightNDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CVoightNDlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_BUTTON1, &CVoightNDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CVoightNDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CVoightNDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CVoightNDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CVoightNDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CVoightNDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CVoightNDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CVoightNDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CVoightNDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON11, &CVoightNDlg::OnBnClickedButton11)
END_MESSAGE_MAP()


// CVoightNDlg message handlers


BOOL CVoightNDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	SetTimer(1, 500, NULL);

	CButton* rad;
	rad = (CButton*)GetDlgItem(IDC_RADIO1);
	rad->SetCheck(1);

	
	for (int i = 0; i < Nmax; i++)
	{
		FillParam(i);
	}

	cur_min_max = 0;
	FillMinMax(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CVoightNDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1)
	{
		char buf[100];
		static double prev_H[Nmax] = {H[0], H[1], H[2], H[3], H[4], H[5], H[6]};
		static double prev_FWHM[Nmax] = { FWHM[0], FWHM[1], FWHM[2], FWHM[3], FWHM[4], FWHM[5], FWHM[6] };
		static double prev_x[Nmax] = { x[0], x[1], x[2], x[3], x[4], x[5], x[6] };
		static double prev_n[Nmax] = { n[0], n[1], n[2], n[3], n[4], n[5], n[6] };

		for (int i = 0; i < Nmax; i++)
		{
			H_ed[i].GetLine(0, buf, H_ed[i].LineLength());
			buf[H_ed[i].LineLength()] = 0;
			H[i] = atof(buf);

			FWHM_ed[i].GetLine(0, buf, FWHM_ed[i].LineLength());
			buf[FWHM_ed[i].LineLength()] = 0;
			FWHM[i] = atof(buf);

			x_ed[i].GetLine(0, buf, x_ed[i].LineLength());
			buf[x_ed[i].LineLength()] = 0;
			x[i] = atof(buf);

			n_ed[i].GetLine(0, buf, n_ed[i].LineLength());
			buf[n_ed[i].LineLength()] = 0;
			n[i] = atof(buf);
		}

		UpdateMinMax();
		
		bool changed = false;
		for (int i = 0; i < Nmax; i++)
		{
			if (prev_H[i] != H[i] || prev_FWHM[i] != FWHM[i] || prev_x[i] != x[i] || prev_n[i] != n[i])
			{
				changed = true;
			}
		}
		if (changed)
		{
			UpdateIntegrals();
			if (!batch_analyze)
			{
				UpdateFit();
				pDoc->UpdateAllViews(0);
			}
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CVoightNDlg::UpdateFit()
{
	// TODO: Add your implementation code here.
	if (batch_analyze) return;

	double SS[Nmax], SSS[Nmax];
	for (int i = 0; i < graph[0][1]->length; i++)
	{

		for (int ii = 0; ii < Nmax; ii++)
		{
			SS[ii] = 4 * (graph[0][1]->X[i] - x[ii]) * (graph[0][1]->X[i] - x[ii]) + FWHM[ii] * FWHM[ii];
			SSS[ii] = FWHM[ii] * FWHM[ii];
		}
		for (int o = 0; o < Nmax; o++)
		{
			if (SS[o] == 0) SS[o] = 1;
			if (SSS[o] == 0) SSS[o] = 1;
		}

		graph[0][1]->Y[i] = 0;
		for (int ii = 0; ii < Nmax; ii++)
		{
			graph[0][1]->Y[i] += n[ii] * H[ii] * exp(-2.7726 * (graph[0][1]->X[i] - x[ii]) * (graph[0][1]->X[i] - x[ii]) / (SSS[ii])) +
				(1 - n[ii]) * H[ii] * FWHM[ii] * FWHM[ii] / (SS[ii]);
		}
	}
}


void CVoightNDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	//default
	Hmin[cur_min_max] = H[cur_min_max] * (1 - def_dH);
	Hmax[cur_min_max] = H[cur_min_max] * (1 + def_dH);
	Hstep[cur_min_max] = (Hmax[cur_min_max] - Hmin[cur_min_max]) * def_H_st;

	FWHMmin[cur_min_max] = max(0, FWHM[cur_min_max] - def_dF);
	FWHMmax[cur_min_max] = FWHM[cur_min_max] + def_dF;
	FWHMstep[cur_min_max] = def_F_st;

	xmin[cur_min_max] = x[cur_min_max] - def_dx;
	xmax[cur_min_max] = x[cur_min_max] + def_dx;
	xstep[cur_min_max] = def_x_st;

	nmin[cur_min_max] = def_n_min;
	nmax[cur_min_max] = def_n_max;
	nstep[cur_min_max] = def_n_step;

	FillMinMax(cur_min_max);
}


void CVoightNDlg::FillMinMax(int index)
{
	// TODO: Add your implementation code here.
	char buf[100];

	sprintf_s(buf, "%g", Hmin[index]);
	H_min_ed.SetWindowTextA(buf);
	sprintf_s(buf, "%g", Hmax[index]);
	H_max_ed.SetWindowTextA(buf);
	sprintf_s(buf, "%g", Hstep[index]);
	H_step_ed.SetWindowTextA(buf);

	sprintf_s(buf, "%g", FWHMmin[index]);
	FWHM_min_ed.SetWindowTextA(buf);
	sprintf_s(buf, "%g", FWHMmax[index]);
	FWHM_max_ed.SetWindowTextA(buf);
	sprintf_s(buf, "%g", FWHMstep[index]);
	FWHM_step_ed.SetWindowTextA(buf);

	sprintf_s(buf, "%g", xmin[index]);
	x_min_ed.SetWindowTextA(buf);
	sprintf_s(buf, "%g", xmax[index]);
	x_max_ed.SetWindowTextA(buf);
	sprintf_s(buf, "%g", xstep[index]);
	x_step_ed.SetWindowTextA(buf);

	sprintf_s(buf, "%g", nmin[index]);
	n_min_ed.SetWindowTextA(buf);
	sprintf_s(buf, "%g", nmax[index]);
	n_max_ed.SetWindowTextA(buf);
	sprintf_s(buf, "%g", nstep[index]);
	n_step_ed.SetWindowTextA(buf);
}


void CVoightNDlg::UpdateMinMax()
{
	// TODO: Add your implementation code here.
	char buf[100];

	H_min_ed.GetLine(0, buf, H_min_ed.LineLength());
	buf[H_min_ed.LineLength()] = 0;
	Hmin[cur_min_max] = atof(buf);

	H_max_ed.GetLine(0, buf, H_max_ed.LineLength());
	buf[H_max_ed.LineLength()] = 0;
	Hmax[cur_min_max] = atof(buf);

	H_step_ed.GetLine(0, buf, H_step_ed.LineLength());
	buf[H_step_ed.LineLength()] = 0;
	Hstep[cur_min_max] = atof(buf);


	FWHM_min_ed.GetLine(0, buf, FWHM_min_ed.LineLength());
	buf[FWHM_min_ed.LineLength()] = 0;
	FWHMmin[cur_min_max] = atof(buf);

	FWHM_max_ed.GetLine(0, buf, FWHM_max_ed.LineLength());
	buf[FWHM_max_ed.LineLength()] = 0;
	FWHMmax[cur_min_max] = atof(buf);

	FWHM_step_ed.GetLine(0, buf, FWHM_step_ed.LineLength());
	buf[FWHM_step_ed.LineLength()] = 0;
	FWHMstep[cur_min_max] = atof(buf);


	x_min_ed.GetLine(0, buf, x_min_ed.LineLength());
	buf[x_min_ed.LineLength()] = 0;
	xmin[cur_min_max] = atof(buf);

	x_max_ed.GetLine(0, buf, x_max_ed.LineLength());
	buf[x_max_ed.LineLength()] = 0;
	xmax[cur_min_max] = atof(buf);

	x_step_ed.GetLine(0, buf, x_step_ed.LineLength());
	buf[x_step_ed.LineLength()] = 0;
	xstep[cur_min_max] = atof(buf);


	n_min_ed.GetLine(0, buf, n_min_ed.LineLength());
	buf[n_min_ed.LineLength()] = 0;
	nmin[cur_min_max] = atof(buf);

	n_max_ed.GetLine(0, buf, n_max_ed.LineLength());
	buf[n_max_ed.LineLength()] = 0;
	nmax[cur_min_max] = atof(buf);

	n_step_ed.GetLine(0, buf, n_step_ed.LineLength());
	buf[n_step_ed.LineLength()] = 0;
	nstep[cur_min_max] = atof(buf);
}


void CVoightNDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	UpdateMinMax();
	cur_min_max = 0;
	FillMinMax(cur_min_max);
}


void CVoightNDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	UpdateMinMax();
	cur_min_max = 1;
	FillMinMax(cur_min_max);
}


void CVoightNDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	UpdateMinMax();
	cur_min_max = 2;
	FillMinMax(cur_min_max);
}


void CVoightNDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	UpdateMinMax();
	cur_min_max = 3;
	FillMinMax(cur_min_max);
}


void CVoightNDlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	UpdateMinMax();
	cur_min_max = 4;
	FillMinMax(cur_min_max);
}


void CVoightNDlg::OnBnClickedRadio7()
{
	// TODO: Add your control notification handler code here
	UpdateMinMax();
	cur_min_max = 5;
	FillMinMax(cur_min_max);
}


void CVoightNDlg::OnBnClickedRadio8()
{
	// TODO: Add your control notification handler code here
	UpdateMinMax();
	cur_min_max = 6;
	FillMinMax(cur_min_max);
}


void CVoightNDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	FindFit(0);
}


double CVoightNDlg::GetError()
{
	// TODO: Add your implementation code here.
	double sum = 0;
	for (int i = 0; i < N_exp; i++)
	{
		double SS[Nmax], SSS[Nmax];
		for (int ii = 0; ii < Nmax; ii++)
		{
			SSS[ii] = FWHM[ii] * FWHM[ii];
			SS[ii] = 4 * (x_exp[i] - x[ii]) * (x_exp[i] - x[ii]) + FWHM[ii] * FWHM[ii];
		}
		
		for (int o = 0; o < Nmax; o++)
		{
			if (SS[o] == 0) SS[o] = 1;
			if (SSS[o] == 0) SSS[o] = 1;
		}

		double y_G = 0;
		for (int ii = 0; ii < Nmax; ii++)
		{
			y_G += n[ii] * H[ii] * exp(-2.7726 * (x_exp[i] - x[ii]) * (x_exp[i] - x[ii]) / (SSS[ii]));
			y_G += (1 - n[ii]) * H[ii] * SSS[ii] / (SS[ii]);
		}

		sum += (y_G - y_exp[i]) * (y_G - y_exp[i]);
	}
	return sum;
}


void CVoightNDlg::FindFit(int index)
{
	// TODO: Add your implementation code here.
	if (batch_analyze) return;

	double err = GetError();
	char buf[100];
	double min_err = err;


	double min_p = x[index];
	double p_0 = x[index];
	int N_c = 1;
	if (xstep[index] > 0) N_c = (xmax[index] - xmin[index]) / xstep[index];

	for (int i = 0; i < N_c + 1; i++)
	{
		x[index] = xmin[index] + i * xstep[index];
		err = GetError();
		if (err < min_err)
		{
			min_err = err;
			min_p = x[index];
		}
	}
	x[index] = min_p;

	min_p = H[index];
	p_0 = H[index];
	N_c = 1;
	if (Hstep[index] > 0) N_c = (Hmax[index] - Hmin[index]) / Hstep[index];

	for (int i = 0; i < N_c + 1; i++)
	{
		H[index] = Hmin[index] + i * Hstep[index];
		err = GetError();
		if (err < min_err)
		{
			min_err = err;
			min_p = H[index];
		}
	}
	H[index] = min_p;

	min_p = FWHM[index];
	p_0 = FWHM[index];
	N_c = 1;
	if (FWHMstep[index] > 0) N_c = (FWHMmax[index] - FWHMmin[index]) / FWHMstep[index];

	for (int i = 0; i < N_c + 1; i++)
	{
		FWHM[index] = FWHMmin[index] + i * FWHMstep[index];
		err = GetError();
		if (err < min_err)
		{
			min_err = err;
			min_p = FWHM[index];
		}
	}
	FWHM[index] = min_p;

	min_p = n[index];
	p_0 = n[index];
	N_c = 1;
	if (nstep[index] > 0) N_c = (nmax[index] - nmin[index]) / nstep[index];

	for (int i = 0; i < N_c + 1; i++)
	{
		n[index] = nmin[index] + i * nstep[index];
		err = GetError();
		if (err < min_err)
		{
			min_err = err;
			min_p = n[index];
		}
	}
	n[index] = min_p;

	FillParam(index);
}


void CVoightNDlg::FillParam(int index)
{
	// TODO: Add your implementation code here.
	char buf[100];
	int i = index;
	sprintf_s(buf, "%g", H[i]);
	H_ed[i].SetWindowTextA(buf);
	sprintf_s(buf, "%g", FWHM[i]);
	FWHM_ed[i].SetWindowTextA(buf);
	sprintf_s(buf, "%g", n[i]);
	n_ed[i].SetWindowTextA(buf);
	sprintf_s(buf, "%g", x[i]);
	x_ed[i].SetWindowTextA(buf);
}


void CVoightNDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	FindFit(1);
}


void CVoightNDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	FindFit(2);
}


void CVoightNDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	FindFit(3);
}


void CVoightNDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	FindFit(4);
}


void CVoightNDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	FindFit(5);
}


void CVoightNDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	FindFit(6);
}


void CVoightNDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	CFileDialog f(FALSE, "txt", NULL, OFN_FILEMUSTEXIST | OFN_LONGNAMES | OFN_OVERWRITEPROMPT, "Files (*.txt)|*.txt||", NULL);
	if (f.DoModal() == IDOK)
	{
		CFile cf;
		CFileException ex;
		if (!cf.Open(f.m_ofn.lpstrFile, CFile::modeCreate | CFile::modeWrite, &ex))
		{
			char buf[256];
			sprintf(buf, "Can't open file %s ,error = %u\n", f.m_ofn.lpstrFile, ex.m_cause);
			::MessageBox(NULL, buf, NULL, MB_OK);
		}
		else
		{
			char buf[1000]; int aaa;
			for (int i = 0; i < Nmax; i++)
			{
				aaa = sprintf_s(buf, "%g %g %g %g; %g %g %g; %g %g %g; %g %g %g; %g %g %g\r\n", H[i], FWHM[i], x[i], n[i], Hmin[i], Hstep[i], Hmax[i],
					FWHMmin[i], FWHMstep[i], FWHMmax[i], xmin[i], xstep[i], xmax[i], nmin[i], nstep[i], nmax[i]);
				if(i==Nmax-1) cf.Write(buf, aaa-2);
				else cf.Write(buf, aaa);
			}
			cf.Close();
		}
	}
}


void CVoightNDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	CFileDialog f(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_LONGNAMES, "Fit (*.txt)|*.txt", NULL);
	if (f.DoModal() == IDOK)
	{
		CFile cf;
		CFileException ex;
		if (!cf.Open(f.m_ofn.lpstrFile, CFile::modeRead, &ex))
		{
			char buf[256];
			sprintf(buf, "Can't open file %s ,error = %u\n", f.m_ofn.lpstrFile, ex.m_cause);
			::MessageBox(NULL, buf, NULL, MB_OK);
		}
		else
		{
			int size = cf.GetLength();
			char* buf = new char[size + 1];
			cf.Read(buf, size);
			cf.Close();

			int k = 0;
			for (int i = 0; i < Nmax; i++)
			{
				if (k >= size) return;
				H[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.');
				if (k >= size) return;
				FWHM[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.');
				if (k >= size) return;
				x[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.');
				if(k >= size) return;
				n[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.'); k++;
				if (k >= size) return;

				Hmin[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.');
				if (k >= size) return;
				Hstep[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.');
				if (k >= size) return;
				Hmax[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.'); k++;
				if (k >= size) return;

				FWHMmin[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.');
				if (k >= size) return;
				FWHMstep[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.');
				if (k >= size) return;
				FWHMmax[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.'); k++;
				if (k >= size) return;

				xmin[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.');
				if (k >= size) return;
				xstep[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.');
				if (k >= size) return;
				xmax[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.'); k++;
				if (k >= size) return;

				nmin[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.');
				if (k >= size) return;
				nstep[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.');
				if (k >= size) return;
				nmax[i] = GetDigitalFromString(&buf[k], '.');
				k += GetLengthDigital(&buf[k], '.'); k++;
			}

			for (int i = 0; i < Nmax; i++)
			{
				FillParam(i);
			}
			FillMinMax(cur_min_max);

			delete[] buf;
		}
	}
}


void CVoightNDlg::UpdateIntegrals()
{
	// TODO: Add your implementation code here.
	char buf[100]; double I = 0;
	for (int i = 0; i < Nmax; i++)
	{
		I = H[i] * FWHM[i] * (1.571 - 0.508 * n[i]);
		sprintf_s(buf, "%g", I);
		int_ed[i].SetWindowTextA(buf);
	}
}


void CVoightNDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	if (batch_analyze) return;

	char buf[100];
	n_iter_ed.GetLine(0, buf, n_iter_ed.LineLength());
	buf[n_iter_ed.LineLength()] = 0;
	n_iter = atoi(buf);

	double ini_H[Nmax], ini_FWHM[Nmax], ini_x[Nmax], ini_n[Nmax];

	bool changed = true;
	for (int i = 0; i < n_iter; i++)
	{
		if (!changed) break;

		sprintf_s(buf, "%d", i);
		iter_cur_ed.SetWindowTextA(buf);
		UpdateWindow();

		for (int j = 0; j < Nmax; j++)
		{
			ini_H[j] = H[j];
			ini_FWHM[j] = FWHM[j];
			ini_n[j] = n[j];
			ini_x[j] = x[j];
		}
		
		for (int j = 0; j < Nmax; j++)
		{
			FindFit(j);
		}

		changed = false;
		for (int j = 0; j < Nmax; j++)
		{
			if (ini_H[j] != H[j] || ini_FWHM[j] != FWHM[j] || ini_x[j] != x[j] || ini_n[j] != n[j])
			{
				changed = true;
			}
		}
	}
}
