// CTL_app.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CTL_app.h"

// CTL_app dialog

IMPLEMENT_DYNAMIC(CTL_app, CDialogEx)

CTL_app::CTL_app(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, d(0)
	, Eg(0)
	, eps_inf(0)
	, A(0)
	, E0(0)
	, C(0)
	, d_min(0)
	, d_max(0)
	, d_step(0)
	, Eg_min(0)
	, Eg_max(0)
	, Eg_step(0)
	, eps_inf_min(0)
	, eps_inf_max(0)
	, eps_inf_step(0)
	, A_min(0)
	, A_max(0)
	, A_step(0)
	, E0_min(0)
	, E0_max(0)
	, E0_step(0)
	, C_min(0)
	, C_max(0)
	, C_step(0)
	, delta(0)
	, iter(0)
	, phi(0)
	, rough(0)
{
	
}

CTL_app::~CTL_app()
{
}

void CTL_app::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, d);
	DDX_Text(pDX, IDC_EDIT2, Eg);
	DDX_Text(pDX, IDC_EDIT3, eps_inf);
	DDX_Text(pDX, IDC_EDIT4, A);
	DDX_Text(pDX, IDC_EDIT5, E0);
	DDX_Text(pDX, IDC_EDIT6, C);
	DDX_Text(pDX, IDC_EDIT7, d_min);
	DDX_Text(pDX, IDC_EDIT8, d_max);
	DDX_Text(pDX, IDC_EDIT9, d_step);
	DDX_Text(pDX, IDC_EDIT10, Eg_min);
	DDX_Text(pDX, IDC_EDIT11, Eg_max);
	DDX_Text(pDX, IDC_EDIT12, Eg_step);
	DDX_Text(pDX, IDC_EDIT13, eps_inf_min);
	DDX_Text(pDX, IDC_EDIT14, eps_inf_max);
	DDX_Text(pDX, IDC_EDIT15, eps_inf_step);
	DDX_Text(pDX, IDC_EDIT16, A_min);
	DDX_Text(pDX, IDC_EDIT17, A_max);
	DDX_Text(pDX, IDC_EDIT18, A_step);
	DDX_Text(pDX, IDC_EDIT19, E0_min);
	DDX_Text(pDX, IDC_EDIT20, E0_max);
	DDX_Text(pDX, IDC_EDIT21, E0_step);
	DDX_Text(pDX, IDC_EDIT22, C_min);
	DDX_Text(pDX, IDC_EDIT23, C_max);
	DDX_Text(pDX, IDC_EDIT24, C_step);
	DDX_Text(pDX, IDC_EDIT25, delta);
	DDX_Text(pDX, IDC_EDIT26, iter);
	DDX_Control(pDX, IDC_EDIT1, d_ed);
	DDX_Control(pDX, IDC_EDIT2, Eg_ed);
	DDX_Control(pDX, IDC_EDIT3, eps_inf_ed);
	DDX_Control(pDX, IDC_EDIT4, A_ed);
	DDX_Control(pDX, IDC_EDIT5, E0_ed);
	DDX_Control(pDX, IDC_EDIT6, C_ed);
	DDX_Control(pDX, IDC_EDIT25, delta_ed);
	DDX_Control(pDX, IDC_EDIT26, iter_ed);
	DDX_Control(pDX, IDC_EDIT7, d_min_ed);
	DDX_Control(pDX, IDC_EDIT8, d_max_ed);
	DDX_Control(pDX, IDC_EDIT9, d_step_ed);
	DDX_Control(pDX, IDC_EDIT10, Eg_min_ed);
	DDX_Control(pDX, IDC_EDIT11, Eg_max_ed);
	DDX_Control(pDX, IDC_EDIT12, Eg_step_ed);
	DDX_Control(pDX, IDC_EDIT13, eps_inf_min_ed);
	DDX_Control(pDX, IDC_EDIT14, eps_inf_max_ed);
	DDX_Control(pDX, IDC_EDIT15, eps_inf_step_ed);
	DDX_Control(pDX, IDC_EDIT16, A_min_ed);
	DDX_Control(pDX, IDC_EDIT17, A_max_ed);
	DDX_Control(pDX, IDC_EDIT18, A_step_ed);
	DDX_Control(pDX, IDC_EDIT19, E0_min_ed);
	DDX_Control(pDX, IDC_EDIT20, E0_max_ed);
	DDX_Control(pDX, IDC_EDIT21, E0_step_ed);
	DDX_Control(pDX, IDC_EDIT22, C_min_ed);
	DDX_Control(pDX, IDC_EDIT23, C_max_ed);
	DDX_Control(pDX, IDC_EDIT24, C_step_ed);
	DDX_Control(pDX, IDC_CHECK1, d_ch);
	DDX_Control(pDX, IDC_CHECK2, Eg_c);
	DDX_Control(pDX, IDC_CHECK3, eps_inf_ch);
	DDX_Control(pDX, IDC_CHECK4, A_ch);
	DDX_Control(pDX, IDC_CHECK5, E0_ch);
	DDX_Control(pDX, IDC_CHECK6, C_ch);
	DDX_Control(pDX, IDC_EDIT34, phi_ed);
	DDX_Text(pDX, IDC_EDIT34, phi);
	DDX_Control(pDX, IDC_EDIT30, rough_ed);
	DDX_Text(pDX, IDC_EDIT30, rough);
	DDX_Control(pDX, IDC_EDIT33, phi_min_ed);
	DDX_Control(pDX, IDC_EDIT32, phi_max_ed);
	DDX_Control(pDX, IDC_EDIT31, phi_step_ed);
	DDX_Control(pDX, IDC_CHECK7, phi_ch);
	DDX_Control(pDX, IDC_CHECK8, rough_ch);
	DDX_Control(pDX, IDC_EDIT27, rough_min_ed);
	DDX_Control(pDX, IDC_EDIT28, rough_max_ed);
	DDX_Control(pDX, IDC_EDIT29, rough_step_ed);
}


BEGIN_MESSAGE_MAP(CTL_app, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTL_app::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTL_app::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTL_app::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTL_app::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTL_app::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CTL_app::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CTL_app::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CTL_app::OnBnClickedButton7)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON9, &CTL_app::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CTL_app::OnBnClickedButton10)
END_MESSAGE_MAP()


// CTL_app message handlers


void CTL_app::OnBnClickedButton1()
{//fit_d
	// TODO: Add your control notification handler code here
	char buf[100];
	
	d_min_ed.GetLine(0, buf, d_min_ed.LineLength());
	buf[d_min_ed.LineLength()] = 0;
	d_min = atof(buf);

	d_max_ed.GetLine(0, buf, d_max_ed.LineLength());
	buf[d_max_ed.LineLength()] = 0;
	d_max = atof(buf);

	d_step_ed.GetLine(0, buf, d_step_ed.LineLength());
	buf[d_step_ed.LineLength()] = 0;
	d_step = atof(buf);

	double d_min_err = d;
	double min_err = GetErr();
	double err = 0;
	for (double dd = d_min; dd <= d_max && d_step>0; dd += d_step)
	{
		d = dd;
		UpdateFit();
		err= GetErr();
		if (err < min_err)
		{
			min_err = err;
			d_min_err = d;
		}
	}
	d = d_min_err;

	sprintf(buf, "%g", d);
	d_ed.SetWindowText(buf);
}


void CTL_app::OnBnClickedButton2()
{//fit_Eg
	// TODO: Add your control notification handler code here
	char buf[100];

	Eg_min_ed.GetLine(0, buf, Eg_min_ed.LineLength());
	buf[Eg_min_ed.LineLength()] = 0;
	Eg_min = atof(buf);

	Eg_max_ed.GetLine(0, buf, Eg_max_ed.LineLength());
	buf[Eg_max_ed.LineLength()] = 0;
	Eg_max = atof(buf);

	Eg_step_ed.GetLine(0, buf, Eg_step_ed.LineLength());
	buf[Eg_step_ed.LineLength()] = 0;
	Eg_step = atof(buf);

	double Eg_min_err = Eg;
	double min_err = GetErr();
	double err = 0;
	for (double dd = Eg_min; dd <= Eg_max && Eg_step > 0; dd += Eg_step)
	{
		Eg = dd;
		UpdateFit();
		err = GetErr();
		if (err < min_err)
		{
			min_err = err;
			Eg_min_err = Eg;
		}
	}
	Eg = Eg_min_err;

	sprintf(buf, "%g", Eg);
	Eg_ed.SetWindowText(buf);
}


void CTL_app::OnBnClickedButton3()
{//fit_eps_inf
	// TODO: Add your control notification handler code here
	char buf[100];

	eps_inf_min_ed.GetLine(0, buf, eps_inf_min_ed.LineLength());
	buf[eps_inf_min_ed.LineLength()] = 0;
	eps_inf_min = atof(buf);

	eps_inf_max_ed.GetLine(0, buf, eps_inf_max_ed.LineLength());
	buf[eps_inf_max_ed.LineLength()] = 0;
	eps_inf_max = atof(buf);

	eps_inf_step_ed.GetLine(0, buf, eps_inf_step_ed.LineLength());
	buf[eps_inf_step_ed.LineLength()] = 0;
	eps_inf_step = atof(buf);

	double eps_inf_min_err = eps_inf;
	double min_err = GetErr();
	double err = 0;
	for (double dd = eps_inf_min; dd <= eps_inf_max && eps_inf_step > 0; dd += eps_inf_step)
	{
		eps_inf = dd;
		UpdateFit();
		err = GetErr();
		if (err < min_err)
		{
			min_err = err;
			eps_inf_min_err = eps_inf;
		}
	}
	eps_inf = eps_inf_min_err;

	sprintf(buf, "%g", eps_inf);
	eps_inf_ed.SetWindowText(buf);
}


void CTL_app::OnBnClickedButton4()
{//fit_A
	// TODO: Add your control notification handler code here
	char buf[100];

	A_min_ed.GetLine(0, buf, A_min_ed.LineLength());
	buf[A_min_ed.LineLength()] = 0;
	A_min = atof(buf);

	A_max_ed.GetLine(0, buf, A_max_ed.LineLength());
	buf[A_max_ed.LineLength()] = 0;
	A_max = atof(buf);

	A_step_ed.GetLine(0, buf, A_step_ed.LineLength());
	buf[A_step_ed.LineLength()] = 0;
	A_step = atof(buf);

	double A_min_err = A;
	double min_err = GetErr();
	double err = 0;
	for (double dd = A_min; dd <= A_max && A_step > 0; dd += A_step)
	{
		A = dd;
		UpdateFit();
		err = GetErr();
		if (err < min_err)
		{
			min_err = err;
			A_min_err = A;
		}
	}
	A = A_min_err;

	sprintf(buf, "%g", A);
	A_ed.SetWindowText(buf);
}


void CTL_app::OnBnClickedButton5()
{//fit_E0
	// TODO: Add your control notification handler code here
	char buf[100];

	E0_min_ed.GetLine(0, buf, E0_min_ed.LineLength());
	buf[E0_min_ed.LineLength()] = 0;
	E0_min = atof(buf);

	E0_max_ed.GetLine(0, buf, E0_max_ed.LineLength());
	buf[E0_max_ed.LineLength()] = 0;
	E0_max = atof(buf);

	E0_step_ed.GetLine(0, buf, E0_step_ed.LineLength());
	buf[E0_step_ed.LineLength()] = 0;
	E0_step = atof(buf);

	double E0_min_err = E0;
	double min_err = GetErr();
	double err = 0;
	for (double dd = E0_min; dd <= E0_max && E0_step > 0; dd += E0_step)
	{
		E0 = dd;
		UpdateFit();
		err = GetErr();
		if (err < min_err)
		{
			min_err = err;
			E0_min_err = E0;
		}
	}
	E0 = E0_min_err;

	sprintf(buf, "%g", E0);
	E0_ed.SetWindowText(buf);
}


void CTL_app::OnBnClickedButton6()
{//fit_C
	// TODO: Add your control notification handler code here
	char buf[100];

	C_min_ed.GetLine(0, buf, C_min_ed.LineLength());
	buf[C_min_ed.LineLength()] = 0;
	C_min = atof(buf);

	C_max_ed.GetLine(0, buf, C_max_ed.LineLength());
	buf[C_max_ed.LineLength()] = 0;
	C_max = atof(buf);

	C_step_ed.GetLine(0, buf, C_step_ed.LineLength());
	buf[C_step_ed.LineLength()] = 0;
	C_step = atof(buf);

	double C_min_err = C;
	double min_err = GetErr();
	double err = 0;
	for (double dd = C_min; dd <= C_max && C_step > 0; dd += C_step)
	{
		C = dd;
		UpdateFit();
		err = GetErr();
		if (err < min_err)
		{
			min_err = err;
			C_min_err = C;
		}
	}
	C = C_min_err;

	sprintf(buf, "%g", C);
	C_ed.SetWindowText(buf);
}


void CTL_app::OnBnClickedButton8()
{//default
	// TODO: Add your control notification handler code here
	char buf[100];
	delta_ed.GetWindowText(buf, 99);
	double delta = atof(buf);

	d_ed.GetWindowText(buf, 99);
	double d0 = atof(buf);
	sprintf(buf, "%g", d0 * (1 - delta / 100));
	d_min_ed.SetWindowText(buf);
	sprintf(buf, "%g", d0 * (1 + delta / 100));
	d_max_ed.SetWindowText(buf);
	sprintf(buf, "%g", d0 * delta / 2500);
	d_step_ed.SetWindowText(buf);
	
	Eg_ed.GetWindowText(buf, 99);
	double Eg0 = atof(buf);
	sprintf(buf, "%g", Eg0 * (1 - delta / 100));
	Eg_min_ed.SetWindowText(buf);
	sprintf(buf, "%g", Eg0 * (1 + delta / 100));
	Eg_max_ed.SetWindowText(buf);
	sprintf(buf, "%g", Eg0 * delta / 2500);
	Eg_step_ed.SetWindowText(buf);

	eps_inf_ed.GetWindowText(buf, 99);
	double eps_inf0 = atof(buf);
	sprintf(buf, "%g", eps_inf0 * (1 - delta / 100));
	eps_inf_min_ed.SetWindowText(buf);
	sprintf(buf, "%g", eps_inf0 * (1 + delta / 100));
	eps_inf_max_ed.SetWindowText(buf);
	sprintf(buf, "%g", eps_inf0 * delta / 2500);
	eps_inf_step_ed.SetWindowText(buf);

	A_ed.GetWindowText(buf, 99);
	double A0 = atof(buf);
	sprintf(buf, "%g", A0 * (1 - delta / 100));
	A_min_ed.SetWindowText(buf);
	sprintf(buf, "%g", A0 * (1 + delta / 100));
	A_max_ed.SetWindowText(buf);
	sprintf(buf, "%g", A0 * delta / 2500);
	A_step_ed.SetWindowText(buf);

	E0_ed.GetWindowText(buf, 99);
	double E00 = atof(buf);
	sprintf(buf, "%g", E00 * (1 - delta / 100));
	E0_min_ed.SetWindowText(buf);
	sprintf(buf, "%g", E00 * (1 + delta / 100));
	E0_max_ed.SetWindowText(buf);
	sprintf(buf, "%g", E00 * delta / 2500);
	E0_step_ed.SetWindowText(buf);

	C_ed.GetWindowText(buf, 99);
	double C0 = atof(buf);
	sprintf(buf, "%g", C0 * (1 - delta / 100));
	C_min_ed.SetWindowText(buf);
	sprintf(buf, "%g", C0 * (1 + delta / 100));
	C_max_ed.SetWindowText(buf);
	sprintf(buf, "%g", C0 * delta / 2500);
	C_step_ed.SetWindowText(buf);

	phi_ed.GetWindowText(buf, 99);
	double phi0 = atof(buf);
	sprintf(buf, "%g", phi0 * (1 - delta / 100));
	phi_min_ed.SetWindowText(buf);
	sprintf(buf, "%g", phi0 * (1 + delta / 100));
	phi_max_ed.SetWindowText(buf);
	sprintf(buf, "%g", phi0 * delta / 2500);
	phi_step_ed.SetWindowText(buf);

	rough_ed.GetWindowText(buf, 99);
	double rough0 = atof(buf);
	sprintf(buf, "%g", rough0 * (1 - delta / 100));
	rough_min_ed.SetWindowText(buf);
	sprintf(buf, "%g", rough0 * (1 + delta / 100));
	rough_max_ed.SetWindowText(buf);
	sprintf(buf, "%g", rough0 * delta / 2500);
	rough_step_ed.SetWindowText(buf);
}


void CTL_app::OnBnClickedButton7()
{//fit_all
	// TODO: Add your control notification handler code here
	char buf[100];
	iter_ed.GetLine(0, buf, iter_ed.LineLength());
	buf[iter_ed.LineLength()] = 0;
	iter = atof(buf);

	for (int i = 0; i < iter; i++)
	{
		if (d_ch.GetCheck()) OnBnClickedButton1();
		if (Eg_c.GetCheck()) OnBnClickedButton2();
		if (eps_inf_ch.GetCheck()) OnBnClickedButton3();
		if (A_ch.GetCheck()) OnBnClickedButton4();
		if (E0_ch.GetCheck()) OnBnClickedButton5();
		if (C_ch.GetCheck()) OnBnClickedButton6();
		if (phi_ch.GetCheck()) OnBnClickedButton9();
		if (rough_ch.GetCheck()) OnBnClickedButton10();

		OnBnClickedButton8();
	}
}


void CTL_app::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1)
	{
		char buf[100];
		static double prev_d = d;
		static double prev_Eg = Eg;
		static double prev_eps_inf = eps_inf;
		static double prev_E0 = E0;
		static double prev_A = A;
		static double prev_C = C;
		static double prev_phi= phi;
		static double prev_rough = rough;

		d_ed.GetLine(0, buf, d_ed.LineLength());
		buf[d_ed.LineLength()] = 0;
		d = atof(buf);

		Eg_ed.GetLine(0, buf, Eg_ed.LineLength());
		buf[Eg_ed.LineLength()] = 0;
		Eg = atof(buf);

		eps_inf_ed.GetLine(0, buf, eps_inf_ed.LineLength());
		buf[eps_inf_ed.LineLength()] = 0;
		eps_inf = atof(buf);

		E0_ed.GetLine(0, buf, E0_ed.LineLength());
		buf[E0_ed.LineLength()] = 0;
		E0 = atof(buf);

		A_ed.GetLine(0, buf, A_ed.LineLength());
		buf[A_ed.LineLength()] = 0;
		A = atof(buf);

		C_ed.GetLine(0, buf, C_ed.LineLength());
		buf[C_ed.LineLength()] = 0;
		C = atof(buf);

		phi_ed.GetLine(0, buf, phi_ed.LineLength());
		buf[phi_ed.LineLength()] = 0;
		phi = atof(buf);

		rough_ed.GetLine(0, buf, rough_ed.LineLength());
		buf[rough_ed.LineLength()] = 0;
		rough = atof(buf);

		bool changed = false;

		if (prev_d != d || prev_Eg != Eg || prev_eps_inf != eps_inf || prev_E0 != d || prev_A != A || prev_C != C || prev_phi != phi || prev_rough != rough)
		{
			changed = true;
		}

		if (changed)
		{
			UpdateFit();
			pDoc->UpdateAllViews(0);
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}


BOOL CTL_app::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	SetTimer(1, 500, NULL);

	fit_gr = false;
	UpdateFit();
	pDoc->UpdateAllViews(0);
	fit_gr = true;

	d_ch.SetCheck(1);
	A_ch.SetCheck(1);
	Eg_c.SetCheck(1);
	eps_inf_ch.SetCheck(1);
	E0_ch.SetCheck(1);
	C_ch.SetCheck(1);
	phi_ch.SetCheck(1);
	rough_ch.SetCheck(1);

	OnBnClickedButton8();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CTL_app::UpdateFit()
{
	// TODO: Add your implementation code here.
	int N = graph[0][1]->length;
	double* eps1 = new double[N];
	double* eps2 = new double[N];
	double* x_nm = graph[0][1]->X;

	double* n1 = new double[N];
	double* n2 = new double[N];

	double* psi = new double[N];
	double* delta = new double[N];

	double EE = 0; double a_ln = 0;
	double a_atan = 0; double alpha = 0;
	double gamma = 0;
	double zeta4 = 0;

	for (int i = 0; i < N; i++)
	{
		EE = 1.239847 / (x_nm[i] / 1000);
		eps2[i] = (1 / EE) * A * E0 * C * (EE - Eg) * (EE - Eg) / ((EE * EE - E0 * E0) * (EE * EE - E0 * E0) + C * C * EE * EE);
		if (EE < Eg) eps2[i] = 0;

		a_ln = (Eg * Eg - E0 * E0) * EE * EE + Eg * Eg * C * C - E0 * E0 * (E0 * E0 + 3 * Eg * Eg);
		a_atan = (EE * EE - E0 * E0) * (E0 * E0 + Eg * Eg) + Eg * Eg * C * C;
		alpha = sqrt(4 * E0 * E0 - C * C);
		gamma = sqrt(E0 * E0 - C * C * 0.5);
		zeta4 = (EE * EE - gamma * gamma) * (EE * EE - gamma * gamma) + alpha * alpha * C * C / 4.0;

		eps1[i] = eps_inf + (A * C * a_ln / (2 * pi * zeta4 * alpha * E0)) * log((E0 * E0 + Eg * Eg + alpha * Eg) / (E0 * E0 + Eg * Eg - alpha * Eg)) -
			(A * a_atan / (pi * zeta4 * E0)) * (pi - atan((2 * Eg + alpha) / C) + atan((-2 * Eg + alpha) / C)) +
			(4 * A * E0 * Eg * (EE * EE - gamma * gamma) / (pi * zeta4 * alpha)) * (atan((2 * Eg + alpha) / C) + atan((-2 * Eg + alpha) / C)) -
			(A * E0 * C * (EE * EE + Eg * Eg) / (pi * zeta4 * EE)) * log(abs(EE - Eg) / (EE + Eg)) +
			(2 * A * E0 * C * Eg / (pi * zeta4)) * log(abs(EE - Eg) * (EE + Eg) / sqrt((E0 * E0 - Eg * Eg) * (E0 * E0 - Eg * Eg) + Eg * Eg * C * C));
	}

	std::complex<double> cos_phi2, cos_phi3;

	double phi1 = pi * phi / 180.0;
	std::complex<double> r12p; std::complex<double> r12s;
	std::complex<double> r23p; std::complex<double> r23s;

	double n1_gl = 1.44;
	double n1_air = 1;

	std::complex<double> D;
	std::complex<double> ione, one, Rp, Rs, rho, AAA;
	std::complex<double> N0, N1, N2, N3;
	one.real(1); one.imag(0);
	ione.real(0); ione.imag(1);

	/*N1.real(n1_air); N1.imag(0);
	N3.real(n1_gl); N3.imag(0);

	for (int i = 0; i < N; i++)
	{
		n1[i] = sqrt(0.5 * eps1[i] + 0.5 * sqrt(eps1[i] * eps1[i] + eps2[i] * eps2[i]));
		n2[i] = 0.5 * eps2[i] / n1[i];

		N2.real(n1[i]); N2.imag(-n2[i]);

		cos_phi2 = sqrt(one - (sin(phi1) * N1 / N2) * (sin(phi1) * N1 / N2));

		r12p = (N2 * cos(phi1) - N1 * cos_phi2) / (N2 * cos(phi1) + N1 * cos_phi2);
		r12s = (N1 * cos(phi1) - N2 * cos_phi2) / (N1 * cos(phi1) + N2 * cos_phi2);

		cos_phi3 = sqrt(one - (sin(acos(cos_phi2)) * N2 / N3) * (sin(acos(cos_phi2)) * N2 / N3));

		r23p = (N3 * cos_phi2 - N2 * cos_phi3) / (N3 * cos_phi2 + N2 * cos_phi3);
		r23s = (N2 * cos_phi2 - N3 * cos_phi3) / (N2 * cos_phi2 + N3 * cos_phi3);

		D = -ione * 4.0 * pi * N2 * cos_phi2 * d / x_nm[i];

		Rp = (one * r12p + r23p * exp(D)) / (one + r12p * r23p * exp(D));
		Rs = (one * r12s + r23s * exp(D)) / (one + r12s * r23s * exp(D));
		rho = Rp / Rs;

		psi[i] = rho.real();//atan(sqrt(rho.real() * rho.real() + rho.imag() * rho.imag())) * 180 / pi;
		delta[i] = rho.imag();//atan(rho.real() / rho.imag()) * 180 / pi;
	}*/

	/*Ab_mat C1p, C1s, C2p, C2s, C;
	std::complex<double> cos_theta0, cos_theta1, cos_theta2;
	std::complex<double> r1s, r1p, r2s, r2p;
	std::complex<double> delta1;

	N0.real(n1_air); N0.imag(0);
	N2.real(n1_gl); N2.imag(0);

	cos_theta0.real(cos(phi1)); cos_theta0.imag(0.0);
	cos_theta2 = sqrt(one - (sin(phi1) * N0 / N2) * (sin(phi1) * N0 / N2));

	for (int i = 0; i < N; i++)
	{
		n1[i] = sqrt(0.5 * eps1[i] + 0.5 * sqrt(eps1[i] * eps1[i] + eps2[i] * eps2[i]));
		n2[i] = 0.5 * eps2[i] / n1[i];

		N1.real(n1[i]); N1.imag(-n2[i]);
		cos_theta1 = sqrt(one - (sin(phi1) * N0 / N1) * (sin(phi1) * N0 / N1));
		delta1 = -one * 2.0 * pi * N1 * cos_theta1 * d / x_nm[i];

		r1p = -(N0 * cos_theta1 - N1 * cos_theta0) / (N0 * cos_theta1 + N1 * cos_theta0);
		r1s = (N0 * cos_theta0 - N1 * cos_theta1) / (N0 * cos_theta0 + N1 * cos_theta1);

		r2p = -(N1 * cos_theta2 - N2 * cos_theta1) / (N1 * cos_theta2 + N2 * cos_theta1);
		r2s = (N1 * cos_theta1 - N2 * cos_theta2) / (N1 * cos_theta1 + N2 * cos_theta2);

		C1p.M[0][0] = one; C1p.M[0][1] = r1p;
		C1p.M[1][0] = r1p; C1p.M[1][1] = one;

		C2p.M[0][0] = exp(-ione * delta1); C2p.M[0][1] = r2p * exp(-ione * delta1);
		C2p.M[1][0] = r2p * exp(ione * delta1); C2p.M[1][1] = exp(ione * delta1);

		C = C1p * C2p;

		Rp = C.M[1][0] / C.M[0][0];

		C1s.M[0][0] = one; C1s.M[0][1] = r1s;
		C1s.M[1][0] = r1s; C1s.M[1][1] = one;

		C2s.M[0][0] = exp(-ione * delta1); C2s.M[0][1] = r2s * exp(-ione * delta1);
		C2s.M[1][0] = r2s * exp(ione * delta1); C2s.M[1][1] = exp(ione * delta1);

		C = C1s * C2s;

		Rs = C.M[1][0] / C.M[0][0];

		rho = Rp / Rs;

		psi[i] = rho.real();
		delta[i] = rho.imag();
	}*/

	Ab_mat C1p, C1s, C2p, C2s, C3p, C3s, C;
	std::complex<double> cos_theta0, cos_theta1, cos_theta2, cos_theta3;
	std::complex<double> r1s, r1p, r2s, r2p, r3s, r3p;
	std::complex<double> delta1, delta2;
	std::complex<double> eps_air, eps_1, eps_eff, Hb;

	N0.real(n1_air); N0.imag(0);
	eps_air.real(1); eps_air.imag(0);
	N3.real(n1_gl); N3.imag(0);
	double f = 0.5;

	cos_theta0.real(cos(phi1)); cos_theta0.imag(0.0);
	cos_theta3 = sqrt(one - (sin(phi1) * N0 / N3) * (sin(phi1) * N0 / N3));

	for (int i = 0; i < N; i++)
	{
		n1[i] = sqrt(0.5 * eps1[i] + 0.5 * sqrt(eps1[i] * eps1[i] + eps2[i] * eps2[i]));
		n2[i] = 0.5 * eps2[i] / n1[i];

		N2.real(n1[i]); N2.imag(-n2[i]);
		cos_theta2 = sqrt(one - (sin(phi1) * N0 / N2) * (sin(phi1) * N0 / N2));
		delta2 = -one * 2.0 * pi * N2 * cos_theta2 * (d - rough) / x_nm[i];

		eps_1.real(eps1[i]); eps_1.imag(eps2[i]);
		Hb = eps_air * (3 * f - 1) + eps_1 * (2 - 3 * f);
		eps_eff = 0.25 * (Hb + sqrt(Hb * Hb + 8.0 * eps_1 * eps_air));
		if(eps_eff.imag()<0) eps_eff = 0.25 * (Hb - sqrt(Hb * Hb + 8.0 * eps_1 * eps_air));
		N1.real(sqrt(0.5 * eps_eff.real() + 0.5 * sqrt(eps_eff.real() * eps_eff.real() + eps_eff.imag() * eps_eff.imag())));
		N1.imag(-0.5 * eps_eff.imag() / N1.real());

		cos_theta1 = sqrt(one - (sin(phi1) * N0 / N1) * (sin(phi1) * N0 / N1));
		delta1 = -one * 2.0 * pi * N1 * cos_theta1 * (rough) / x_nm[i];

		r1p = -(N0 * cos_theta1 - N1 * cos_theta0) / (N0 * cos_theta1 + N1 * cos_theta0);
		r1s = (N0 * cos_theta0 - N1 * cos_theta1) / (N0 * cos_theta0 + N1 * cos_theta1);

		r2p = -(N1 * cos_theta2 - N2 * cos_theta1) / (N1 * cos_theta2 + N2 * cos_theta1);
		r2s = (N1 * cos_theta1 - N2 * cos_theta2) / (N1 * cos_theta1 + N2 * cos_theta2);

		r3p = -(N2 * cos_theta3 - N3 * cos_theta2) / (N2 * cos_theta3 + N3 * cos_theta2);
		r3s = (N2 * cos_theta2 - N3 * cos_theta3) / (N2 * cos_theta2 + N3 * cos_theta3);

		C1p.M[0][0] = one; C1p.M[0][1] = r1p;
		C1p.M[1][0] = r1p; C1p.M[1][1] = one;

		C2p.M[0][0] = exp(-ione * delta1); C2p.M[0][1] = r2p * exp(-ione * delta1);
		C2p.M[1][0] = r2p * exp(ione * delta1); C2p.M[1][1] = exp(ione * delta1);

		C3p.M[0][0] = exp(-ione * delta2); C3p.M[0][1] = r3p * exp(-ione * delta2);
		C3p.M[1][0] = r3p * exp(ione * delta2); C3p.M[1][1] = exp(ione * delta2);

		C = C1p * C2p * C3p;

		Rp = C.M[1][0] / C.M[0][0];

		C1s.M[0][0] = one; C1s.M[0][1] = r1s;
		C1s.M[1][0] = r1s; C1s.M[1][1] = one;

		C2s.M[0][0] = exp(-ione * delta1); C2s.M[0][1] = r2s * exp(-ione * delta1);
		C2s.M[1][0] = r2s * exp(ione * delta1); C2s.M[1][1] = exp(ione * delta1);

		C3s.M[0][0] = exp(-ione * delta2); C3s.M[0][1] = r3s * exp(-ione * delta2);
		C3s.M[1][0] = r3s * exp(ione * delta2); C3s.M[1][1] = exp(ione * delta2);

		C = C1s * C2s * C3s;

		Rs = C.M[1][0] / C.M[0][0];

		rho = Rp / Rs;

		psi[i] = rho.real();
		delta[i] = rho.imag();
	}

	if (graph[0][graph->GetNLast() - 1]->name=="fit_real"&& graph[0][graph->GetNLast()]->name == "fit_imag")
	{
		for (int i = 0; i < N; i++)
		{
			graph[0][graph->GetNLast() - 1]->Y[i] = psi[i];
			graph[0][graph->GetNLast()]->Y[i] = delta[i];
		}
	}
	else
	{
		graph[0].AddData(x_nm, psi, N, "fit_real");
		graph[0].AddData(x_nm, delta, N, "fit_imag");
	}
	
	delete[]eps1;
	delete[]eps2;
	delete[]n1;
	delete[]n2;
	delete[]psi;
	delete[]delta;
}


double CTL_app::GetErr()
{
	// TODO: Add your implementation code here.
	double err = 0;
	int N1 = graph[0][1]->length;
	int N2 = graph[0][2]->length;
	for (int i = 0; i < min(N1, N2); i++)
	{
		err += (graph[0][1]->Y[i] - graph[0][graph->GetNLast() - 1]->Y[i]) * (graph[0][1]->Y[i] - graph[0][graph->GetNLast() - 1]->Y[i]);
		err += (graph[0][2]->Y[i] - graph[0][graph->GetNLast()]->Y[i]) * (graph[0][2]->Y[i] - graph[0][graph->GetNLast()]->Y[i]);
	}
	return err;
}


void CTL_app::OnBnClickedButton9()
{//phi
	// TODO: Add your control notification handler code here
	char buf[100];

	phi_min_ed.GetLine(0, buf, phi_min_ed.LineLength());
	buf[phi_min_ed.LineLength()] = 0;
	double phi_min = atof(buf);

	phi_max_ed.GetLine(0, buf, phi_max_ed.LineLength());
	buf[phi_max_ed.LineLength()] = 0;
	double phi_max = atof(buf);

	phi_step_ed.GetLine(0, buf, phi_step_ed.LineLength());
	buf[phi_step_ed.LineLength()] = 0;
	double phi_step = atof(buf);

	double phi_min_err = phi;
	double min_err = GetErr();
	double err = 0;
	for (double dd = phi_min; dd <= phi_max && phi_step > 0; dd += phi_step)
	{
		phi = dd;
		UpdateFit();
		err = GetErr();
		if (err < min_err)
		{
			min_err = err;
			phi_min_err = phi;
		}
	}
	phi = phi_min_err;

	sprintf(buf, "%g", phi);
	phi_ed.SetWindowText(buf);
}


void CTL_app::OnBnClickedButton10()
{//rough
	// TODO: Add your control notification handler code here
	char buf[100];

	rough_min_ed.GetLine(0, buf, rough_min_ed.LineLength());
	buf[rough_min_ed.LineLength()] = 0;
	double rough_min = atof(buf);

	rough_max_ed.GetLine(0, buf, rough_max_ed.LineLength());
	buf[rough_max_ed.LineLength()] = 0;
	double rough_max = atof(buf);

	rough_step_ed.GetLine(0, buf, rough_step_ed.LineLength());
	buf[rough_step_ed.LineLength()] = 0;
	double rough_step = atof(buf);

	double rough_min_err = rough;
	double min_err = GetErr();
	double err = 0;
	for (double dd = rough_min; dd <= rough_max && rough_step > 0; dd += rough_step)
	{
		rough = dd;
		UpdateFit();
		err = GetErr();
		if (err < min_err)
		{
			min_err = err;
			rough_min_err = rough;
		}
	}
	rough = rough_min_err;

	sprintf(buf, "%g", rough);
	rough_ed.SetWindowText(buf);
}
