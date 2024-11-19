// VoightDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "VoightDlg.h"
#include <cmath>

extern double GetDigitalFromString(char *buf, char separ);
extern int GetLengthDigital(char *buf, char separ);

// CVoightDlg dialog

IMPLEMENT_DYNAMIC(CVoightDlg, CDialog)

CVoightDlg::CVoightDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVoightDlg::IDD, pParent)
	, H1(0)
	, H2(0)
	, H3(0)
	, H4(0)
	, H5(0)
	, H6(0)
	, H7(0)
	, F1(0)
	, F2(0)
	, F3(0)
	, F4(0)
	, F5(0)
	, F6(0)
	, F7(0)
	, x1(0)
	, x2(0)
	, x3(0)
	, x4(0)
	, x5(0)
	, x6(0)
	, x7(0)
	, n1(0)
	, n2(0)
	, n3(0)
	, n4(0)
	, n5(0)
	, n6(0)
	, n7(0)
	, H8(0)
	, F8(0)
	, x8(0)
	, n8(0)
	, H9(0)
	, H10(0)
	, H11(0)
	, H12(0)
	, H13(0)
	, H14(0)
	, H15(0)
	, H16(0)
	, H17(0)
	, H18(0)
	, H19(0)
	, H20(0)
	, H21(0)
	, F9(0)
	, F10(0)
	, F11(0)
	, F12(0)
	, F13(0)
	, F14(0)
	, F15(0)
	, F16(0)
	, F17(0)
	, F18(0)
	, F19(0)
	, F20(0)
	, F21(0)
	, x9(0)
	, x10(0)
	, x11(0)
	, x12(0)
	, x13(0)
	, x14(0)
	, x15(0)
	, x16(0)
	, x17(0)
	, x18(0)
	, x19(0)
	, x20(0)
	, x21(0)
	, n9(0)
	, n10(0)
	, n11(0)
	, n12(0)
	, n13(0)
	, n14(0)
	, n15(0)
	, n16(0)
	, n17(0)
	, n18(0)
	, n19(0)
	, n20(0)
	, n21(0)
{
	separ = '.';
}

CVoightDlg::~CVoightDlg()
{
}

void CVoightDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, H1e);
	DDX_Control(pDX, IDC_EDIT6, H2e);
	DDX_Control(pDX, IDC_EDIT9, H3e);
	DDX_Control(pDX, IDC_EDIT12, H4e);
	DDX_Control(pDX, IDC_EDIT15, H5e);
	DDX_Control(pDX, IDC_EDIT18, H6e);
	DDX_Control(pDX, IDC_EDIT21, H7e);
	DDX_Control(pDX, IDC_EDIT2, F1e);
	DDX_Control(pDX, IDC_EDIT7, F2e);
	DDX_Control(pDX, IDC_EDIT10, F3e);
	DDX_Control(pDX, IDC_EDIT13, F4e);
	DDX_Control(pDX, IDC_EDIT16, F5e);
	DDX_Control(pDX, IDC_EDIT19, F6e);
	DDX_Control(pDX, IDC_EDIT22, F7e);
	DDX_Control(pDX, IDC_EDIT3, x1e);
	DDX_Control(pDX, IDC_EDIT8, x2e);
	DDX_Control(pDX, IDC_EDIT11, x3e);
	DDX_Control(pDX, IDC_EDIT14, x4e);
	DDX_Control(pDX, IDC_EDIT17, x5e);
	DDX_Control(pDX, IDC_EDIT20, x6e);
	DDX_Control(pDX, IDC_EDIT23, x7e);
	DDX_Control(pDX, IDC_EDIT24, n1e);
	DDX_Control(pDX, IDC_EDIT25, n2e);
	DDX_Control(pDX, IDC_EDIT26, n3e);
	DDX_Control(pDX, IDC_EDIT27, n4e);
	DDX_Control(pDX, IDC_EDIT28, n5e);
	DDX_Control(pDX, IDC_EDIT29, n6e);
	DDX_Control(pDX, IDC_EDIT30, n7e);
	DDX_Text(pDX, IDC_EDIT1, H1);
	DDX_Text(pDX, IDC_EDIT6, H2);
	DDX_Text(pDX, IDC_EDIT9, H3);
	DDX_Text(pDX, IDC_EDIT12, H4);
	DDX_Text(pDX, IDC_EDIT15, H5);
	DDX_Text(pDX, IDC_EDIT18, H6);
	DDX_Text(pDX, IDC_EDIT21, H7);
	DDX_Text(pDX, IDC_EDIT2, F1);
	DDX_Text(pDX, IDC_EDIT7, F2);
	DDX_Text(pDX, IDC_EDIT10, F3);
	DDX_Text(pDX, IDC_EDIT13, F4);
	DDX_Text(pDX, IDC_EDIT16, F5);
	DDX_Text(pDX, IDC_EDIT19, F6);
	DDX_Text(pDX, IDC_EDIT22, F7);
	DDX_Text(pDX, IDC_EDIT3, x1);
	DDX_Text(pDX, IDC_EDIT8, x2);
	DDX_Text(pDX, IDC_EDIT11, x3);
	DDX_Text(pDX, IDC_EDIT14, x4);
	DDX_Text(pDX, IDC_EDIT17, x5);
	DDX_Text(pDX, IDC_EDIT20, x6);
	DDX_Text(pDX, IDC_EDIT23, x7);
	DDX_Text(pDX, IDC_EDIT24, n1);
	DDX_Text(pDX, IDC_EDIT25, n2);
	DDX_Text(pDX, IDC_EDIT26, n3);
	DDX_Text(pDX, IDC_EDIT27, n4);
	DDX_Text(pDX, IDC_EDIT28, n5);
	DDX_Text(pDX, IDC_EDIT29, n6);
	DDX_Text(pDX, IDC_EDIT30, n7);
	DDX_Control(pDX, IDC_EDIT31, I1);
	DDX_Control(pDX, IDC_EDIT32, I2);
	DDX_Control(pDX, IDC_EDIT33, I3);
	DDX_Control(pDX, IDC_EDIT34, I4);
	DDX_Control(pDX, IDC_EDIT35, I5);
	DDX_Control(pDX, IDC_EDIT36, I6);
	DDX_Control(pDX, IDC_EDIT37, I7);
	DDX_Control(pDX, IDC_EDIT38, H8e);
	DDX_Text(pDX, IDC_EDIT38, H8);
	DDX_Control(pDX, IDC_EDIT39, F8e);
	DDX_Text(pDX, IDC_EDIT39, F8);
	DDX_Control(pDX, IDC_EDIT40, x8e);
	DDX_Text(pDX, IDC_EDIT40, x8);
	DDX_Control(pDX, IDC_EDIT41, n8e);
	DDX_Text(pDX, IDC_EDIT41, n8);
	DDX_Control(pDX, IDC_EDIT42, I8);
	DDX_Control(pDX, IDC_EDIT43, H9e);
	DDX_Text(pDX, IDC_EDIT43, H9);
	DDX_Control(pDX, IDC_EDIT44, H10e);
	DDX_Text(pDX, IDC_EDIT44, H10);
	DDX_Text(pDX, IDC_EDIT45, H11);
	DDX_Control(pDX, IDC_EDIT45, H11e);
	DDX_Control(pDX, IDC_EDIT46, H12e);
	DDX_Text(pDX, IDC_EDIT46, H12);
	DDX_Control(pDX, IDC_EDIT47, H13e);
	DDX_Text(pDX, IDC_EDIT47, H13);
	DDX_Text(pDX, IDC_EDIT48, H14);
	DDX_Control(pDX, IDC_EDIT48, H14e);
	DDX_Text(pDX, IDC_EDIT49, H15);
	DDX_Control(pDX, IDC_EDIT49, H15e);
	DDX_Control(pDX, IDC_EDIT50, H16e);
	DDX_Text(pDX, IDC_EDIT50, H16);
	DDX_Control(pDX, IDC_EDIT51, H17e);
	DDX_Text(pDX, IDC_EDIT51, H17);
	DDX_Text(pDX, IDC_EDIT52, H18);
	DDX_Control(pDX, IDC_EDIT52, H18e);
	DDX_Text(pDX, IDC_EDIT53, H19);
	DDX_Text(pDX, IDC_EDIT54, H20);
	DDX_Control(pDX, IDC_EDIT54, H20e);
	DDX_Control(pDX, IDC_EDIT53, H19e);
	DDX_Control(pDX, IDC_EDIT55, H21e);
	DDX_Text(pDX, IDC_EDIT55, H21);
	DDX_Control(pDX, IDC_EDIT56, F9e);
	DDX_Text(pDX, IDC_EDIT56, F9);
	DDX_Text(pDX, IDC_EDIT57, F10);
	DDX_Control(pDX, IDC_EDIT57, F10e);
	DDX_Control(pDX, IDC_EDIT58, F11e);
	DDX_Text(pDX, IDC_EDIT58, F11);
	DDX_Control(pDX, IDC_EDIT59, F12e);
	DDX_Text(pDX, IDC_EDIT59, F12);
	DDX_Control(pDX, IDC_EDIT60, F13e);
	DDX_Text(pDX, IDC_EDIT60, F13);
	DDX_Control(pDX, IDC_EDIT61, F14e);
	DDX_Text(pDX, IDC_EDIT61, F14);
	DDX_Control(pDX, IDC_EDIT62, F15e);
	DDX_Text(pDX, IDC_EDIT62, F15);
	DDX_Control(pDX, IDC_EDIT63, F16e);
	DDX_Text(pDX, IDC_EDIT63, F16);
	DDX_Control(pDX, IDC_EDIT64, F17e);
	DDX_Text(pDX, IDC_EDIT64, F17);
	DDX_Text(pDX, IDC_EDIT65, F18);
	DDX_Control(pDX, IDC_EDIT65, F18e);
	DDX_Control(pDX, IDC_EDIT66, F19e);
	DDX_Text(pDX, IDC_EDIT66, F19);
	DDX_Control(pDX, IDC_EDIT67, F20e);
	DDX_Text(pDX, IDC_EDIT67, F20);
	DDX_Control(pDX, IDC_EDIT68, F21e);
	DDX_Text(pDX, IDC_EDIT68, F21);
	DDX_Control(pDX, IDC_EDIT69, x9e);
	DDX_Text(pDX, IDC_EDIT69, x9);
	DDX_Control(pDX, IDC_EDIT70, x10e);
	DDX_Text(pDX, IDC_EDIT70, x10);
	DDX_Control(pDX, IDC_EDIT71, x11e);
	DDX_Text(pDX, IDC_EDIT71, x11);
	DDX_Control(pDX, IDC_EDIT72, x12e);
	DDX_Text(pDX, IDC_EDIT72, x12);
	DDX_Control(pDX, IDC_EDIT73, x13e);
	DDX_Text(pDX, IDC_EDIT73, x13);
	DDX_Control(pDX, IDC_EDIT74, x14e);
	DDX_Text(pDX, IDC_EDIT74, x14);
	DDX_Control(pDX, IDC_EDIT75, x15e);
	DDX_Text(pDX, IDC_EDIT75, x15);
	DDX_Control(pDX, IDC_EDIT76, x16e);
	DDX_Text(pDX, IDC_EDIT76, x16);
	DDX_Control(pDX, IDC_EDIT77, x17e);
	DDX_Text(pDX, IDC_EDIT77, x17);
	DDX_Control(pDX, IDC_EDIT78, x18e);
	DDX_Text(pDX, IDC_EDIT78, x18);
	DDX_Control(pDX, IDC_EDIT79, x19e);
	DDX_Text(pDX, IDC_EDIT79, x19);
	DDX_Text(pDX, IDC_EDIT80, x20);
	DDX_Control(pDX, IDC_EDIT80, x20e);
	DDX_Control(pDX, IDC_EDIT81, x21e);
	DDX_Text(pDX, IDC_EDIT81, x21);
	DDX_Control(pDX, IDC_EDIT82, n9e);
	DDX_Text(pDX, IDC_EDIT82, n9);
	DDX_Control(pDX, IDC_EDIT83, n10e);
	DDX_Text(pDX, IDC_EDIT83, n10);
	DDX_Control(pDX, IDC_EDIT84, n11e);
	DDX_Text(pDX, IDC_EDIT84, n11);
	DDX_Text(pDX, IDC_EDIT85, n12);
	DDX_Control(pDX, IDC_EDIT85, n12e);
	DDX_Control(pDX, IDC_EDIT86, n13e);
	DDX_Text(pDX, IDC_EDIT86, n13);
	DDX_Control(pDX, IDC_EDIT87, n14e);
	DDX_Text(pDX, IDC_EDIT87, n14);
	DDX_Text(pDX, IDC_EDIT88, n15);
	DDX_Control(pDX, IDC_EDIT88, n15e);
	DDX_Control(pDX, IDC_EDIT89, n16e);
	DDX_Text(pDX, IDC_EDIT89, n16);
	DDX_Control(pDX, IDC_EDIT90, n17e);
	DDX_Text(pDX, IDC_EDIT90, n17);
	DDX_Control(pDX, IDC_EDIT91, n18e);
	DDX_Text(pDX, IDC_EDIT91, n18);
	DDX_Text(pDX, IDC_EDIT92, n19);
	DDX_Control(pDX, IDC_EDIT92, n19e);
	DDX_Control(pDX, IDC_EDIT93, n20e);
	DDX_Text(pDX, IDC_EDIT93, n20);
	DDX_Control(pDX, IDC_EDIT94, n21e);
	DDX_Text(pDX, IDC_EDIT94, n21);
	DDX_Control(pDX, IDC_EDIT95, I9);
	DDX_Control(pDX, IDC_EDIT96, I10);
	DDX_Control(pDX, IDC_EDIT97, I11);
	DDX_Control(pDX, IDC_EDIT98, I12);
	DDX_Control(pDX, IDC_EDIT99, I13);
	DDX_Control(pDX, IDC_EDIT100, I14);
	DDX_Control(pDX, IDC_EDIT101, I15);
	DDX_Control(pDX, IDC_EDIT102, I16);
	DDX_Control(pDX, IDC_EDIT103, I17);
	DDX_Control(pDX, IDC_EDIT104, I18);
	DDX_Control(pDX, IDC_EDIT105, I19);
	DDX_Control(pDX, IDC_EDIT106, I20);
	DDX_Control(pDX, IDC_EDIT107, I21);
	DDX_Control(pDX, IDC_CHECK5, ch1);
	DDX_Control(pDX, IDC_CHECK6, ch2);
	DDX_Control(pDX, IDC_CHECK7, ch3);
	DDX_Control(pDX, IDC_CHECK8, ch4);
	DDX_Control(pDX, IDC_CHECK9, ch5);
	DDX_Control(pDX, IDC_CHECK10, ch6);
	DDX_Control(pDX, IDC_CHECK11, ch7);
	DDX_Control(pDX, IDC_CHECK12, ch8);
	DDX_Control(pDX, IDC_CHECK13, ch9);
	DDX_Control(pDX, IDC_CHECK14, ch10);
	DDX_Control(pDX, IDC_CHECK15, ch11);
	DDX_Control(pDX, IDC_CHECK16, ch12);
	DDX_Control(pDX, IDC_CHECK17, ch13);
	DDX_Control(pDX, IDC_CHECK18, ch14);
	DDX_Control(pDX, IDC_CHECK19, ch15);
	DDX_Control(pDX, IDC_CHECK20, ch16);
	DDX_Control(pDX, IDC_CHECK21, ch17);
	DDX_Control(pDX, IDC_CHECK22, ch18);
	DDX_Control(pDX, IDC_CHECK23, ch19);
	DDX_Control(pDX, IDC_CHECK24, ch20);
	DDX_Control(pDX, IDC_CHECK25, ch21);
}


BEGIN_MESSAGE_MAP(CVoightDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &CVoightDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CVoightDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CVoightDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CVoightDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CVoightDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CVoightDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CVoightDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CVoightDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_RADIO1, &CVoightDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CVoightDlg::OnBnClickedRadio2)
	/*ON_EN_CHANGE(IDC_EDIT1, &CVoightDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT6, &CVoightDlg::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT9, &CVoightDlg::OnEnChangeEdit9)
	ON_EN_CHANGE(IDC_EDIT12, &CVoightDlg::OnEnChangeEdit12)
	ON_EN_CHANGE(IDC_EDIT15, &CVoightDlg::OnEnChangeEdit15)
	ON_EN_CHANGE(IDC_EDIT18, &CVoightDlg::OnEnChangeEdit18)
	ON_EN_CHANGE(IDC_EDIT21, &CVoightDlg::OnEnChangeEdit21)
	ON_EN_CHANGE(IDC_EDIT2, &CVoightDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT7, &CVoightDlg::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT10, &CVoightDlg::OnEnChangeEdit10)
	ON_EN_CHANGE(IDC_EDIT13, &CVoightDlg::OnEnChangeEdit13)
	ON_EN_CHANGE(IDC_EDIT16, &CVoightDlg::OnEnChangeEdit16)
	ON_EN_CHANGE(IDC_EDIT19, &CVoightDlg::OnEnChangeEdit19)
	ON_EN_CHANGE(IDC_EDIT22, &CVoightDlg::OnEnChangeEdit22)
	ON_EN_CHANGE(IDC_EDIT24, &CVoightDlg::OnEnChangeEdit24)
	ON_EN_CHANGE(IDC_EDIT25, &CVoightDlg::OnEnChangeEdit25)
	ON_EN_CHANGE(IDC_EDIT26, &CVoightDlg::OnEnChangeEdit26)
	ON_EN_CHANGE(IDC_EDIT27, &CVoightDlg::OnEnChangeEdit27)
	ON_EN_CHANGE(IDC_EDIT28, &CVoightDlg::OnEnChangeEdit28)
	ON_EN_CHANGE(IDC_EDIT29, &CVoightDlg::OnEnChangeEdit29)
	ON_EN_CHANGE(IDC_EDIT30, &CVoightDlg::OnEnChangeEdit30)*/
	ON_BN_CLICKED(IDC_BUTTON10, &CVoightDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CVoightDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CVoightDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CVoightDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CVoightDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CVoightDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CVoightDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CVoightDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CVoightDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CVoightDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CVoightDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CVoightDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CVoightDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CVoightDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CVoightDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CVoightDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_CHECK5, &CVoightDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &CVoightDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &CVoightDlg::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CVoightDlg::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &CVoightDlg::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &CVoightDlg::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &CVoightDlg::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK12, &CVoightDlg::OnBnClickedCheck12)
	ON_BN_CLICKED(IDC_CHECK13, &CVoightDlg::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_CHECK14, &CVoightDlg::OnBnClickedCheck14)
	ON_BN_CLICKED(IDC_CHECK15, &CVoightDlg::OnBnClickedCheck15)
	ON_BN_CLICKED(IDC_CHECK16, &CVoightDlg::OnBnClickedCheck16)
	ON_BN_CLICKED(IDC_CHECK17, &CVoightDlg::OnBnClickedCheck17)
	ON_BN_CLICKED(IDC_CHECK18, &CVoightDlg::OnBnClickedCheck18)
	ON_BN_CLICKED(IDC_CHECK19, &CVoightDlg::OnBnClickedCheck19)
	ON_BN_CLICKED(IDC_CHECK20, &CVoightDlg::OnBnClickedCheck20)
	ON_BN_CLICKED(IDC_CHECK21, &CVoightDlg::OnBnClickedCheck21)
	ON_BN_CLICKED(IDC_CHECK22, &CVoightDlg::OnBnClickedCheck22)
	ON_BN_CLICKED(IDC_CHECK23, &CVoightDlg::OnBnClickedCheck23)
	ON_BN_CLICKED(IDC_CHECK24, &CVoightDlg::OnBnClickedCheck24)
	ON_BN_CLICKED(IDC_CHECK25, &CVoightDlg::OnBnClickedCheck25)
END_MESSAGE_MAP()


// CVoightDlg message handlers

void CVoightDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	double err=GetError();
	char buf[100];
	double min_err=err;
	

	double min_p=x1;
	double p_0=x1;
	int N_c=100;

	if (!check[0])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x1 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x1;
			}
		}
		x1 = min_p;
	}

	p_0=H1;
	min_p=H1;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			H1=p_0+(i-0.5*N_c)*1;
		else
			H1=p_0+(i-0.5*N_c)*10;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=H1;
		}
	}
	H1=min_p;

	if (!check[0])
	{
		p_0 = F1;
		min_p = F1;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				F1 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			else
				F1 = p_0 + (i - 0.5*N_c) * 10 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = F1;
			}
		}
		F1 = min_p;


		p_0 = n1;
		min_p = n1;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n1 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n1 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n1 >= 0 && n1 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n1;
				}
			}
		}
		n1 = min_p;
	}

	sprintf_s(buf, "%g", H1);
	H1e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F1);
	F1e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x1);
	x1e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n1);
	n1e.SetWindowTextA(buf);
}

void CVoightDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	double err=GetError();
	char buf[100];
	double min_err=err;
	
	double min_p=x2;
	double p_0=x2;
	int N_c=100;
	if (!check[1])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x2 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x2;
			}
		}
		x2 = min_p;
	}

	p_0=H2;
	min_p=H2;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			H2=p_0+(i-0.5*N_c)*1;
		else
			H2=p_0+(i-0.5*N_c)*10;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=H2;
		}
	}
	H2=min_p;

	if (!check[1])
	{
		p_0 = F2;
		min_p = F2;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				F2 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			else
				F2 = p_0 + (i - 0.5*N_c) * 10 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = F2;
			}
		}
		F2 = min_p;


		p_0 = n2;
		min_p = n2;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n2 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n2 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n2 >= 0 && n2 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n2;
				}
			}
		}
		n2 = min_p;
	}

	sprintf_s(buf, "%g", H2);
	H2e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F2);
	F2e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x2);
	x2e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n2);
	n2e.SetWindowTextA(buf);

}

void CVoightDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	double err=GetError();
	char buf[100];
	double min_err=err;
	
	double min_p=x3;
	double p_0=x3;
	int N_c=100;
	if (!check[2])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x3 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x3;
			}
		}
		x3 = min_p;
	}

	p_0=H3;
	min_p=H3;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			H3=p_0+(i-0.5*N_c)*1;
		else
			H3=p_0+(i-0.5*N_c)*10;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=H3;
		}
	}
	H3=min_p;

	if (!check[2])
	{
	p_0=F3;
	min_p=F3;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			F3=p_0+(i-0.5*N_c)*1.0/N_c;
		else
			F3=p_0+(i-0.5*N_c)*10/N_c;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=F3;
		}
	}
	F3=min_p;

	
		p_0 = n3;
		min_p = n3;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n3 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n3 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n3 >= 0 && n3 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n3;
				}
			}
		}
		n3 = min_p;
	}

	sprintf_s(buf, "%g", H3);
	H3e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F3);
	F3e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x3);
	x3e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n3);
	n3e.SetWindowTextA(buf);
}

void CVoightDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	double err=GetError();
	char buf[100];
	double min_err=err;
	
	double min_p=x4;
	double p_0=x4;
	int N_c=100;
	if (!check[3])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x4 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x4;
			}
		}
		x4 = min_p;
	}

	p_0=H4;
	min_p=H4;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			H4=p_0+(i-0.5*N_c)*1;
		else
			H4=p_0+(i-0.5*N_c)*10;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=H4;
		}
	}
	H4=min_p;

	if (!check[3])
	{
	p_0=F4;
	min_p=F4;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			F4=p_0+(i-0.5*N_c)*1.0/N_c;
		else
			F4=p_0+(i-0.5*N_c)*10/N_c;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=F4;
		}
	}
	F4=min_p;

	
		p_0 = n4;
		min_p = n4;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n4 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n4 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n4 >= 0 && n4 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n4;
				}
			}
		}
		n4 = min_p;
	}

	sprintf_s(buf, "%g", H4);
	H4e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F4);
	F4e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x4);
	x4e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n4);
	n4e.SetWindowTextA(buf);
}

void CVoightDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	double err=GetError();
	char buf[100];
	double min_err=err;
	
	double min_p=x5;
	double p_0=x5;
	int N_c=100;
	if (!check[4])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x5 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x5;
			}
		}
		x5 = min_p;
	}

	p_0=H5;
	min_p=H5;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			H5=p_0+(i-0.5*N_c)*1;
		else
			H5=p_0+(i-0.5*N_c)*10;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=H5;
		}
	}
	H5=min_p;

	if (!check[4])
	{
	p_0=F5;
	min_p=F5;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			F5=p_0+(i-0.5*N_c)*1.0/N_c;
		else
			F5=p_0+(i-0.5*N_c)*10/N_c;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=F5;
		}
	}
	F5=min_p;

	
		p_0 = n5;
		min_p = n5;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n5 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n5 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n5 >= 0 && n5 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n5;
				}
			}
		}
		n5 = min_p;
	}

	sprintf_s(buf, "%g", H5);
	H5e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F5);
	F5e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x5);
	x5e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n5);
	n5e.SetWindowTextA(buf);
}

void CVoightDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	double err=GetError();
	char buf[100];
	double min_err=err;
	
	double min_p=x6;
	double p_0=x6;
	int N_c=100;
	if (!check[5])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x6 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x6;
			}
		}
		x6 = min_p;
	}

	p_0=H6;
	min_p=H6;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			H6=p_0+(i-0.5*N_c)*1;
		else
			H6=p_0+(i-0.5*N_c)*10;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=H6;
		}
	}
	H6=min_p;

	if (!check[5])
	{
	p_0=F6;
	min_p=F6;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			F6=p_0+(i-0.5*N_c)*1.0/N_c;
		else
			F6=p_0+(i-0.5*N_c)*10/N_c;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=F6;
		}
	}
	F6=min_p;

	
		p_0 = n6;
		min_p = n6;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n6 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n6 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n6 >= 0 && n6 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n6;
				}
			}
		}
		n6 = min_p;
	}

	sprintf_s(buf, "%g", H6);
	H6e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F6);
	F6e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x6);
	x6e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n6);
	n6e.SetWindowTextA(buf);
}

void CVoightDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	double err=GetError();
	char buf[100];
	double min_err=err;
	
	double min_p=x7;
	double p_0=x7;
	int N_c=100;
	if (!check[6])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x7 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x7;
			}
		}
		x7 = min_p;
	}

	p_0=H7;
	min_p=H7;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			H7=p_0+(i-0.5*N_c)*1;
		else
			H7=p_0+(i-0.5*N_c)*10;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=H7;
		}
	}
	H7=min_p;

	if (!check[6])
	{
	p_0=F7;
	min_p=F7;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			F7=p_0+(i-0.5*N_c)*1.0/N_c;
		else
			F7=p_0+(i-0.5*N_c)*10/N_c;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=F7;
		}
	}
	F7=min_p;

	
		p_0 = n7;
		min_p = n7;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n7 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n7 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n7 >= 0 && n7 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n7;
				}
			}
		}
		n7 = min_p;
	}

	sprintf_s(buf, "%g", H7);
	H7e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F7);
	F7e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x7);
	x7e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n7);
	n7e.SetWindowTextA(buf);
}

void CVoightDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	OnBnClickedButton2();
	OnBnClickedButton3();
	OnBnClickedButton4();
	OnBnClickedButton5();
	OnBnClickedButton6();
	OnBnClickedButton7();
	OnBnClickedButton8();
	OnBnClickedButton12();
	OnBnClickedButton13();
	OnBnClickedButton14();
	OnBnClickedButton15();
	OnBnClickedButton16();
	OnBnClickedButton17();
	OnBnClickedButton18();
	OnBnClickedButton19();
	OnBnClickedButton20();
	OnBnClickedButton21();
	OnBnClickedButton22();
	OnBnClickedButton23();
	OnBnClickedButton24();
	OnBnClickedButton25();
}

BOOL CVoightDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	CButton *rad;
	rad=(CButton*)GetDlgItem(IDC_RADIO1);
	if(fine)
		rad->SetCheck(1);
	else rad->SetCheck(0);

	CButton *rad2;
	rad2=(CButton*)GetDlgItem(IDC_RADIO2);
	if(fine)
		rad2->SetCheck(0);
	else rad2->SetCheck(1);

	char buf[100];
	double I=H1*F1*(1.571-0.508*n1);
	sprintf_s(buf, "%0.0f", I);
	I1.SetWindowTextA(buf);

	I=H2*F2*(1.571-0.508*n2);
	sprintf_s(buf, "%0.0f", I);
	I2.SetWindowTextA(buf);

	I=H3*F3*(1.571-0.508*n3);
	sprintf_s(buf, "%0.0f", I);
	I3.SetWindowTextA(buf);

	I=H4*F4*(1.571-0.508*n4);
	sprintf_s(buf, "%0.0f", I);
	I4.SetWindowTextA(buf);

	I=H5*F5*(1.571-0.508*n5);
	sprintf_s(buf, "%0.0f", I);
	I5.SetWindowTextA(buf);

	I=H6*F6*(1.571-0.508*n6);
	sprintf_s(buf, "%0.0f", I);
	I6.SetWindowTextA(buf);

	I=H7*F7*(1.571-0.508*n7);
	sprintf_s(buf, "%0.0f", I);
	I7.SetWindowTextA(buf);

	I=H8*F8*(1.571-0.508*n8);
	sprintf_s(buf, "%0.0f", I);
	I8.SetWindowTextA(buf);

	I = H9*F9*(1.571 - 0.508*n9);
	sprintf_s(buf, "%0.0f", I);
	I9.SetWindowTextA(buf);

	I = H10*F10*(1.571 - 0.508*n10);
	sprintf_s(buf, "%0.0f", I);
	I10.SetWindowTextA(buf);

	I = H11*F11*(1.571 - 0.508*n11);
	sprintf_s(buf, "%0.0f", I);
	I11.SetWindowTextA(buf);

	I = H12*F12*(1.571 - 0.508*n12);
	sprintf_s(buf, "%0.0f", I);
	I12.SetWindowTextA(buf);

	I = H13*F13*(1.571 - 0.508*n13);
	sprintf_s(buf, "%0.0f", I);
	I13.SetWindowTextA(buf);

	I = H14*F14*(1.571 - 0.508*n14);
	sprintf_s(buf, "%0.0f", I);
	I14.SetWindowTextA(buf);

	I = H15*F15*(1.571 - 0.508*n15);
	sprintf_s(buf, "%0.0f", I);
	I15.SetWindowTextA(buf);

	I = H16*F16*(1.571 - 0.508*n16);
	sprintf_s(buf, "%0.0f", I);
	I16.SetWindowTextA(buf);

	I = H17*F17*(1.571 - 0.508*n17);
	sprintf_s(buf, "%0.0f", I);
	I17.SetWindowTextA(buf);

	I = H18*F18*(1.571 - 0.508*n18);
	sprintf_s(buf, "%0.0f", I);
	I18.SetWindowTextA(buf);

	I = H19*F19*(1.571 - 0.508*n19);
	sprintf_s(buf, "%0.0f", I);
	I19.SetWindowTextA(buf);

	I = H20*F20*(1.571 - 0.508*n20);
	sprintf_s(buf, "%0.0f", I);
	I20.SetWindowTextA(buf);

	I = H21*F21*(1.571 - 0.508*n21);
	sprintf_s(buf, "%0.0f", I);
	I21.SetWindowTextA(buf);

	ch1.SetCheck(check[0]);
	ch2.SetCheck(check[1]);
	ch3.SetCheck(check[2]);
	ch4.SetCheck(check[3]);
	ch5.SetCheck(check[4]);
	ch6.SetCheck(check[5]);
	ch7.SetCheck(check[6]);
	ch8.SetCheck(check[7]);
	ch9.SetCheck(check[8]);
	ch10.SetCheck(check[9]);
	ch11.SetCheck(check[10]);
	ch12.SetCheck(check[11]);
	ch13.SetCheck(check[12]);
	ch14.SetCheck(check[13]);
	ch15.SetCheck(check[14]);
	ch16.SetCheck(check[15]);
	ch17.SetCheck(check[16]);
	ch18.SetCheck(check[17]);
	ch19.SetCheck(check[18]);
	ch20.SetCheck(check[19]);
	ch21.SetCheck(check[20]);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CVoightDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	fine=true;
}

void CVoightDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	fine=false;
}

double CVoightDlg::GetError(void)
{
	double sum=0;
	for(int i=0; i<N_exp; i++)
	{
		double SS[21], SSS[21];
		SS[0] = 4 * (x_exp[i] - x1)*(x_exp[i] - x1) + F1*F1;
		SS[1] = 4 * (x_exp[i] - x2)*(x_exp[i] - x2) + F2*F2;
		SS[2] = 4 * (x_exp[i] - x3)*(x_exp[i] - x3) + F3*F3;
		SS[3] = 4 * (x_exp[i] - x4)*(x_exp[i] - x4) + F4*F4;
		SS[4] = 4 * (x_exp[i] - x5)*(x_exp[i] - x5) + F5*F5;
		SS[5] = 4 * (x_exp[i] - x6)*(x_exp[i] - x6) + F6*F6;
		SS[6] = 4 * (x_exp[i] - x7)*(x_exp[i] - x7) + F7*F7;
		SS[7] = 4 * (x_exp[i] - x8)*(x_exp[i] - x8) + F8*F8;
		SS[8] = 4 * (x_exp[i] - x9)*(x_exp[i] - x9) + F9*F9;
		SS[9] = 4 * (x_exp[i] - x10)*(x_exp[i] - x10) + F10*F10;
		SS[10] = 4 * (x_exp[i] - x11)*(x_exp[i] - x11) + F11*F11;
		SS[11] = 4 * (x_exp[i] - x12)*(x_exp[i] - x12) + F12*F12;
		SS[12] = 4 * (x_exp[i] - x13)*(x_exp[i] - x13) + F13*F13;
		SS[13] = 4 * (x_exp[i] - x14)*(x_exp[i] - x14) + F14*F14;
		SS[14] = 4 * (x_exp[i] - x15)*(x_exp[i] - x15) + F15*F15;
		SS[15] = 4 * (x_exp[i] - x16)*(x_exp[i] - x16) + F16*F16;
		SS[16] = 4 * (x_exp[i] - x17)*(x_exp[i] - x17) + F17*F17;
		SS[17] = 4 * (x_exp[i] - x18)*(x_exp[i] - x18) + F18*F18;
		SS[18] = 4 * (x_exp[i] - x19)*(x_exp[i] - x19) + F19*F19;
		SS[19] = 4 * (x_exp[i] - x20)*(x_exp[i] - x20) + F20*F20;
		SS[20] = 4 * (x_exp[i] - x21)*(x_exp[i] - x21) + F21*F21;
		SSS[0] = F1*F1;
		SSS[1] = F2*F2;
		SSS[2] = F3*F3;
		SSS[3] = F4*F4;
		SSS[4] = F5*F5;
		SSS[5] = F6*F6;
		SSS[6] = F7*F7;
		SSS[7] = F8*F8;
		SSS[8] = F9*F9;
		SSS[9] = F10*F10;
		SSS[10] = F11*F11;
		SSS[11] = F12*F12;
		SSS[12] = F13*F13;
		SSS[13] = F14*F14;
		SSS[14] = F15*F15;
		SSS[15] = F16*F16;
		SSS[16] = F17*F17;
		SSS[17] = F18*F18;
		SSS[18] = F19*F19;
		SSS[19] = F20*F20;
		SSS[20] = F21*F21;
		for(int o=0; o<21; o++)
		{
			if(SS[o]==0) SS[o]=1;
			if(SSS[o]==0) SSS[o]=1;
		}

		double y_G;
		y_G = n1*H1*exp(-2.7726*(x_exp[i] - x1)*(x_exp[i] - x1) / (SSS[0])) +
			n2*H2*exp(-2.7726*(x_exp[i] - x2)*(x_exp[i] - x2) / (SSS[1])) +
			n3*H3*exp(-2.7726*(x_exp[i] - x3)*(x_exp[i] - x3) / (SSS[2])) +
			n4*H4*exp(-2.7726*(x_exp[i] - x4)*(x_exp[i] - x4) / (SSS[3])) +
			n5*H5*exp(-2.7726*(x_exp[i] - x5)*(x_exp[i] - x5) / (SSS[4])) +
			n6*H6*exp(-2.7726*(x_exp[i] - x6)*(x_exp[i] - x6) / (SSS[5])) +
			n7*H7*exp(-2.7726*(x_exp[i] - x7)*(x_exp[i] - x7) / (SSS[6])) +
			n8*H8*exp(-2.7726*(x_exp[i] - x8)*(x_exp[i] - x8) / (SSS[7])) +
			n9*H9*exp(-2.7726*(x_exp[i] - x9)*(x_exp[i] - x9) / (SSS[8])) +
			n10*H10*exp(-2.7726*(x_exp[i] - x10)*(x_exp[i] - x10) / (SSS[9])) +
			n11*H11*exp(-2.7726*(x_exp[i] - x11)*(x_exp[i] - x11) / (SSS[10])) +
			n12*H12*exp(-2.7726*(x_exp[i] - x12)*(x_exp[i] - x12) / (SSS[11])) +
			n13*H13*exp(-2.7726*(x_exp[i] - x13)*(x_exp[i] - x13) / (SSS[12])) +
			n14*H14*exp(-2.7726*(x_exp[i] - x14)*(x_exp[i] - x14) / (SSS[13])) +
			n15*H15*exp(-2.7726*(x_exp[i] - x15)*(x_exp[i] - x15) / (SSS[14])) +
			n16*H16*exp(-2.7726*(x_exp[i] - x16)*(x_exp[i] - x16) / (SSS[15])) +
			n17*H17*exp(-2.7726*(x_exp[i] - x17)*(x_exp[i] - x17) / (SSS[16])) +
			n18*H18*exp(-2.7726*(x_exp[i] - x18)*(x_exp[i] - x18) / (SSS[17])) +
			n19*H19*exp(-2.7726*(x_exp[i] - x19)*(x_exp[i] - x19) / (SSS[18])) +
			n20*H20*exp(-2.7726*(x_exp[i] - x20)*(x_exp[i] - x20) / (SSS[19])) +
			n21*H21*exp(-2.7726*(x_exp[i] - x21)*(x_exp[i] - x21) / (SSS[20])) +
			(1 - n1)*H1*F1*F1 / (SS[0]) +
			(1 - n2)*H2*F2*F2 / (SS[1]) +
			(1 - n3)*H3*F3*F3 / (SS[2]) +
			(1 - n4)*H4*F4*F4 / (SS[3]) +
			(1 - n5)*H5*F5*F5 / (SS[4]) +
			(1 - n6)*H6*F6*F6 / (SS[5]) +
			(1 - n7)*H7*F7*F7 / (SS[6]) +
			(1 - n8)*H8*F8*F8 / (SS[7]) + 
			(1 - n9)*H9*F9*F9 / (SS[8]) + 
			(1 - n10)*H10*F10*F10 / (SS[9]) + 
			(1 - n11)*H11*F11*F11 / (SS[10]) + 
			(1 - n12)*H12*F12*F12 / (SS[11]) + 
			(1 - n13)*H13*F13*F13 / (SS[12]) + 
			(1 - n14)*H14*F14*F14 / (SS[13]) + 
			(1 - n15)*H15*F15*F15 / (SS[14]) + 
			(1 - n16)*H16*F16*F16 / (SS[15]) + 
			(1 - n17)*H17*F17*F17 / (SS[16]) + 
			(1 - n18)*H18*F18*F18 / (SS[17]) + 
			(1 - n19)*H19*F19*F19 / (SS[18]) + 
			(1 - n20)*H20*F20*F20 / (SS[19]) + 
			(1 - n21)*H21*F21*F21 / (SS[20]);
		sum+=(y_G-y_exp[i])*(y_G-y_exp[i]);
	}
	return sum;
}
/*
void CVoightDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	H1e.GetWindowTextA(buf, H1e.GetWindowTextLengthA());
	double H=atof(buf);
	H1=H;
	double I=H1*F1*(1.571-0.508*n1);
	sprintf_s(buf, "%0.0f", I);
	I1.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	H2e.GetWindowTextA(buf, H2e.GetWindowTextLengthA());
	double H=atof(buf);
	H2=H;
	double I=H2*F2*(1.571-0.508*n2);
	sprintf_s(buf, "%0.0f", I);
	I2.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit9()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	H3e.GetWindowTextA(buf, H3e.GetWindowTextLengthA());
	double H=atof(buf);
	H3=H;
	double I=H3*F3*(1.571-0.508*n3);
	sprintf_s(buf, "%0.0f", I);
	I3.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	H4e.GetWindowTextA(buf, H4e.GetWindowTextLengthA());
	double H=atof(buf);
	H4=H;
	double I=H4*F4*(1.571-0.508*n4);
	sprintf_s(buf, "%0.0f", I);
	I4.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit15()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	H5e.GetWindowTextA(buf, H5e.GetWindowTextLengthA());
	double H=atof(buf);
	H5=H;
	double I=H5*F5*(1.571-0.508*n5);
	sprintf_s(buf, "%0.0f", I);
	I5.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit18()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	H6e.GetWindowTextA(buf, H6e.GetWindowTextLengthA());
	double H=atof(buf);
	H6=H;
	double I=H6*F6*(1.571-0.508*n6);
	sprintf_s(buf, "%0.0f", I);
	I6.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit21()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	H7e.GetWindowTextA(buf, H7e.GetWindowTextLengthA());
	double H=atof(buf);
	H7=H;
	double I=H7*F7*(1.571-0.508*n7);
	sprintf_s(buf, "%0.0f", I);
	I7.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	F1e.GetWindowTextA(buf, F1e.GetWindowTextLengthA());
	double F=atof(buf);
	F1=F;
	double I=H1*F1*(1.571-0.508*n1);
	sprintf_s(buf, "%0.0f", I);
	I1.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	F2e.GetWindowTextA(buf, F2e.GetWindowTextLengthA());
	double F=atof(buf);
	F2=F;
	double I=H2*F2*(1.571-0.508*n2);
	sprintf_s(buf, "%0.0f", I);
	I2.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit10()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	F3e.GetWindowTextA(buf, F3e.GetWindowTextLengthA());
	double F=atof(buf);
	F3=F;
	double I=H3*F3*(1.571-0.508*n3);
	sprintf_s(buf, "%0.0f", I);
	I3.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	F4e.GetWindowTextA(buf, F4e.GetWindowTextLengthA());
	double F=atof(buf);
	F4=F;
	double I=H4*F4*(1.571-0.508*n4);
	sprintf_s(buf, "%0.0f", I);
	I4.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit16()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	F5e.GetWindowTextA(buf, F5e.GetWindowTextLengthA());
	double F=atof(buf);
	F5=F;
	double I=H5*F5*(1.571-0.508*n5);
	sprintf_s(buf, "%0.0f", I);
	I5.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit19()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	F6e.GetWindowTextA(buf, F6e.GetWindowTextLengthA());
	double F=atof(buf);
	F6=F;
	double I=H6*F6*(1.571-0.508*n6);
	sprintf_s(buf, "%0.0f", I);
	I6.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit22()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	F7e.GetWindowTextA(buf, F7e.GetWindowTextLengthA());
	double F=atof(buf);
	F7=F;
	double I=H7*F7*(1.571-0.508*n7);
	sprintf_s(buf, "%0.0f", I);
	I7.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit24()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	n1e.GetWindowTextA(buf, n1e.GetWindowTextLengthA());
	double n=atof(buf);
	n1=n;
	double I=H1*F1*(1.571-0.508*n1);
	sprintf_s(buf, "%0.0f", I);
	I1.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit25()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	n2e.GetWindowTextA(buf, n2e.GetWindowTextLengthA());
	double n=atof(buf);
	n2=n;
	double I=H2*F2*(1.571-0.508*n2);
	sprintf_s(buf, "%0.0f", I);
	I2.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit26()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	n3e.GetWindowTextA(buf, n3e.GetWindowTextLengthA());
	double n=atof(buf);
	n3=n;
	double I=H3*F3*(1.571-0.508*n3);
	sprintf_s(buf, "%0.0f", I);
	I3.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit27()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	n4e.GetWindowTextA(buf, n4e.GetWindowTextLengthA());
	double n=atof(buf);
	n4=n;
	double I=H4*F4*(1.571-0.508*n4);
	sprintf_s(buf, "%0.0f", I);
	I4.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit28()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	n5e.GetWindowTextA(buf, n5e.GetWindowTextLengthA());
	double n=atof(buf);
	n5=n;
	double I=H5*F5*(1.571-0.508*n5);
	sprintf_s(buf, "%0.0f", I);
	I5.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit29()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	n6e.GetWindowTextA(buf, n6e.GetWindowTextLengthA());
	double n=atof(buf);
	n6=n;
	double I=H6*F6*(1.571-0.508*n6);
	sprintf_s(buf, "%0.0f", I);
	I6.SetWindowTextA(buf);
}

void CVoightDlg::OnEnChangeEdit30()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	char buf[100];
	n7e.GetWindowTextA(buf, n7e.GetWindowTextLengthA());
	double n=atof(buf);
	n7=n;
	double I=H7*F7*(1.571-0.508*n7);
	sprintf_s(buf, "%0.0f", I);
	I7.SetWindowTextA(buf);
}
*/
void CVoightDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	CFileDialog f(FALSE,"txt",NULL,OFN_FILEMUSTEXIST|OFN_LONGNAMES|OFN_OVERWRITEPROMPT,
		"Files (*.txt)|*.txt||", NULL);
	if(f.DoModal()==IDOK)
	{
		CFile cf;
		CFileException ex;
		if(!cf.Open(f.m_ofn.lpstrFile,CFile::modeCreate|CFile::modeWrite,&ex))
		{
			char buf[256];
			sprintf(buf,"Can't open file %s ,error = %u\n",
				f.m_ofn.lpstrFile,ex.m_cause);
			::MessageBox(NULL, buf, NULL, MB_OK);
		}
		else
		{
			CWaitCursor wait;
			char buf[100]; int aaa;
		
			aaa=sprintf_s(buf, "%g %g %g %g", H1, F1, x1, n1);
			cf.Write(buf, aaa);
			buf[0]=13; buf[1]=10;
			cf.Write(buf, 2);

			aaa=sprintf_s(buf, "%g %g %g %g", H2, F2, x2, n2);
			cf.Write(buf, aaa);
			buf[0]=13; buf[1]=10;
			cf.Write(buf, 2);

			aaa=sprintf_s(buf, "%g %g %g %g", H3, F3, x3, n3);
			cf.Write(buf, aaa);
			buf[0]=13; buf[1]=10;
			cf.Write(buf, 2);

			aaa=sprintf_s(buf, "%g %g %g %g", H4, F4, x4, n4);
			cf.Write(buf, aaa);
			buf[0]=13; buf[1]=10;
			cf.Write(buf, 2);

			aaa=sprintf_s(buf, "%g %g %g %g", H5, F5, x5, n5);
			cf.Write(buf, aaa);
			buf[0]=13; buf[1]=10;
			cf.Write(buf, 2);

			aaa=sprintf_s(buf, "%g %g %g %g", H6, F6, x6, n6);
			cf.Write(buf, aaa);
			buf[0]=13; buf[1]=10;
			cf.Write(buf, 2);

			aaa=sprintf_s(buf, "%g %g %g %g", H7, F7, x7, n7);
			cf.Write(buf, aaa);
			buf[0]=13; buf[1]=10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H8, F8, x8, n8);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H9, F9, x9, n9);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H10, F10, x10, n10);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H11, F11, x11, n11);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H12, F12, x12, n12);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H13, F13, x13, n13);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H14, F14, x14, n14);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H15, F15, x15, n15);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H16, F16, x16, n16);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H17, F17, x17, n17);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H18, F18, x18, n18);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H19, F19, x19, n19);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa = sprintf_s(buf, "%g %g %g %g", H20, F20, x20, n20);
			cf.Write(buf, aaa);
			buf[0] = 13; buf[1] = 10;
			cf.Write(buf, 2);

			aaa=sprintf_s(buf, "%g %g %g %g", H21, F21, x21, n21);
			cf.Write(buf, aaa);
			
			wait.Restore();
			cf.Close();
		}
	}
}

void CVoightDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	
	CFileDialog f(TRUE,NULL,NULL,OFN_FILEMUSTEXIST|OFN_LONGNAMES,
		"Graph (*.txt)|*.txt|Dektak (*.csv)|*.csv|SGR Raman (*.csv)|*.csv|SGR L900 (*.sp)|*.sp|AFM (*.txt)|*.txt|Rel Test (*.txt)|*.txt|Rel Test (*.csv)|*.csv|Rel Test Kal (*.txt)|*.txt|Threshold Test (*.txt)|*.txt|", NULL);
	if(f.DoModal()==IDOK)
	{
		CFile cf;
		CFileException ex;
		if(!cf.Open(f.m_ofn.lpstrFile,CFile::modeRead,&ex))
		{
			char buf[256];
			sprintf(buf,"Can't open file %s ,error = %u\n",
				f.m_ofn.lpstrFile,ex.m_cause);
			::MessageBox(NULL, buf, NULL, MB_OK);
		}
		else
		{
			CWaitCursor wait;
			int size=cf.GetLength();
			char *buf=new char[size+1];
			cf.Read(buf,size);
			cf.Close();

			double data[4*21];
			int k=0;
			for(int i=0; i<4*21; i++)
			{
				if(buf[k]==0)
				{
					wait.Restore();
					return;
				}
				data[i]=GetDigitalFromString(&buf[k], separ);
				k+=GetLengthDigital(&buf[k], separ);
			}
			H1 = data[0]; F1 = data[1]; x1 = data[2]; n1 = data[3];
			H2 = data[4]; F2 = data[5]; x2 = data[6]; n2 = data[7];
			H3 = data[8]; F3 = data[9]; x3 = data[10]; n3 = data[11];
			H4 = data[12]; F4 = data[13]; x4 = data[14]; n4 = data[15];
			H5 = data[16]; F5 = data[17]; x5 = data[18]; n5 = data[19];
			H6 = data[20]; F6 = data[21]; x6 = data[22]; n6 = data[23];
			H7 = data[24]; F7 = data[25]; x7 = data[26]; n7 = data[27];
			H8 = data[28]; F8 = data[29]; x8 = data[30]; n8 = data[31];
			H9 = data[32]; F9 = data[33]; x9 = data[34]; n9 = data[35];
			H10 = data[36]; F10 = data[37]; x10 = data[38]; n10 = data[39];
			H11 = data[40]; F11 = data[41]; x11 = data[42]; n11 = data[43];
			H12 = data[44]; F12 = data[45]; x12 = data[46]; n12 = data[47];
			H13 = data[48]; F13 = data[49]; x13 = data[50]; n13 = data[51];
			H14 = data[52]; F14 = data[53]; x14 = data[54]; n14 = data[55];
			H15 = data[56]; F15 = data[57]; x15 = data[58]; n15 = data[59];
			H16 = data[60]; F16 = data[61]; x16 = data[62]; n16 = data[63];
			H17 = data[64]; F17 = data[65]; x17 = data[66]; n17 = data[67];
			H18 = data[68]; F18 = data[69]; x18 = data[70]; n18 = data[71];
			H19 = data[72]; F19 = data[73]; x19 = data[74]; n19 = data[75];
			H20 = data[76]; F20 = data[77]; x20 = data[78]; n20 = data[79];
			H21 = data[80]; F21 = data[81]; x21 = data[82]; n21 = data[83];

			char buuf[100];
			sprintf_s(buuf, "%g", H1);   H1e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H2);   H2e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H3);   H3e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H4);   H4e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H5);   H5e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H6);   H6e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H7);   H7e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H8);   H8e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H9);   H9e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H10);   H10e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H11);   H11e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H12);   H12e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H13);   H13e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H14);   H14e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H15);   H15e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H16);   H16e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H17);   H17e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H18);   H18e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H19);   H19e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H20);   H20e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", H21);   H21e.SetWindowTextA(buuf);

			sprintf_s(buuf, "%g", F1);   F1e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F2);   F2e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F3);   F3e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F4);   F4e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F5);   F5e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F6);   F6e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F7);   F7e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F8);   F8e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F9);   F9e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F10);   F10e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F11);   F11e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F12);   F12e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F13);   F13e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F14);   F14e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F15);   F15e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F16);   F16e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F17);   F17e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F18);   F18e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F19);   F19e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F20);   F20e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", F21);   F21e.SetWindowTextA(buuf);

			sprintf_s(buuf, "%g", x1);   x1e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x2);   x2e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x3);   x3e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x4);   x4e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x5);   x5e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x6);   x6e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x7);   x7e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x8);   x8e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x9);   x9e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x10);   x10e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x11);   x11e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x12);   x12e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x13);   x13e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x14);   x14e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x15);   x15e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x16);   x16e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x17);   x17e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x18);   x18e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x19);   x19e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x20);   x20e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", x21);   x21e.SetWindowTextA(buuf);

			sprintf_s(buuf, "%g", n1);   n1e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n2);   n2e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n3);   n3e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n4);   n4e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n5);   n5e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n6);   n6e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n7);   n7e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n8);   n8e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n9);   n9e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n10);   n10e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n11);   n11e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n12);   n12e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n13);   n13e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n14);   n14e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n15);   n15e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n16);   n16e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n17);   n17e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n18);   n18e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n19);   n19e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n20);   n20e.SetWindowTextA(buuf);
			sprintf_s(buuf, "%g", n21);   n21e.SetWindowTextA(buuf);

			delete [] buf;
			wait.Restore();
		}
	}
}

void CVoightDlg::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
	double err=GetError();
	char buf[100];
	double min_err=err;
	
	double min_p=x8;
	double p_0=x8;
	int N_c=100;
	if (!check[7])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x8 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x8;
			}
		}
		x8 = min_p;
	}

	p_0=H8;
	min_p=H8;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			H8=p_0+(i-0.5*N_c)*1;
		else
			H8=p_0+(i-0.5*N_c)*10;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=H8;
		}
	}
	H8=min_p;

	if (!check[7])
	{
	p_0=F8;
	min_p=F8;
	for(int i=0; i<N_c+1; i++)
	{
		if(fine)
			F8=p_0+(i-0.5*N_c)*1.0/N_c;
		else
			F8=p_0+(i-0.5*N_c)*10/N_c;
		err=GetError();
		if(err<min_err)
		{
			min_err=err;
			min_p=F8;
		}
	}
	F8=min_p;

	
		p_0 = n8;
		min_p = n8;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n8 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n8 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n8 >= 0 && n8 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n8;
				}
			}
		}
		n8 = min_p;
	}

	sprintf_s(buf, "%g", H8);
	H8e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F8);
	F8e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x8);
	x8e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n8);
	n8e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x9;
	double p_0 = x9;
	int N_c = 100;
	if (!check[8])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x9 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x9;
			}
		}
		x9 = min_p;
	}

	p_0 = H9;
	min_p = H9;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H9 = p_0 + (i - 0.5*N_c) * 1;
		else
			H9 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H9;
		}
	}
	H9 = min_p;

	if (!check[8])
	{
	p_0 = F9;
	min_p = F9;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F9 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F9 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F9;
		}
	}
	F9 = min_p;

	
		p_0 = n9;
		min_p = n9;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n9 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n9 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n9 >= 0 && n9 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n9;
				}
			}
		}
		n9 = min_p;
	}

	sprintf_s(buf, "%g", H9);
	H9e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F9);
	F9e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x9);
	x9e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n9);
	n9e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x10;
	double p_0 = x10;
	int N_c = 100;
	if (!check[9])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x10 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x10;
			}
		}
		x10 = min_p;
	}

	p_0 = H10;
	min_p = H10;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H10 = p_0 + (i - 0.5*N_c) * 1;
		else
			H10 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H10;
		}
	}
	H10 = min_p;

	if (!check[9])
	{
	p_0 = F10;
	min_p = F10;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F10 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F10 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F10;
		}
	}
	F10 = min_p;

	
		p_0 = n10;
		min_p = n10;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n10 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n10 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n10 >= 0 && n10 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n10;
				}
			}
		}
		n10 = min_p;
	}

	sprintf_s(buf, "%g", H10);
	H10e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F10);
	F10e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x10);
	x10e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n10);
	n10e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x11;
	double p_0 = x11;
	int N_c = 100;
	if (!check[10])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x11 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x11;
			}
		}
		x11 = min_p;
	}

	p_0 = H11;
	min_p = H11;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H11 = p_0 + (i - 0.5*N_c) * 1;
		else
			H11 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H11;
		}
	}
	H11 = min_p;

	if (!check[10])
	{
	p_0 = F11;
	min_p = F11;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F11 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F11 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F11;
		}
	}
	F11 = min_p;

	
		p_0 = n11;
		min_p = n11;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n11 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n11 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n11 >= 0 && n11 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n11;
				}
			}
		}
		n11 = min_p;
	}

	sprintf_s(buf, "%g", H11);
	H11e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F11);
	F11e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x11);
	x11e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n11);
	n11e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton16()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x12;
	double p_0 = x12;
	int N_c = 100;
	if (!check[11])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x12 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x12;
			}
		}
		x12 = min_p;
	}

	p_0 = H12;
	min_p = H12;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H12 = p_0 + (i - 0.5*N_c) * 1;
		else
			H12 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H12;
		}
	}
	H12 = min_p;

	if (!check[11])
	{
	p_0 = F12;
	min_p = F12;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F12 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F12 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F12;
		}
	}
	F12 = min_p;

	
		p_0 = n12;
		min_p = n12;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n12 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n12 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n12 >= 0 && n12 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n12;
				}
			}
		}
		n12 = min_p;
	}

	sprintf_s(buf, "%g", H12);
	H12e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F12);
	F12e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x12);
	x12e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n12);
	n12e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x13;
	double p_0 = x13;
	int N_c = 100;
	if (!check[12])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x13 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x13;
			}
		}
		x13 = min_p;
	}

	p_0 = H13;
	min_p = H13;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H13 = p_0 + (i - 0.5*N_c) * 1;
		else
			H13 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H13;
		}
	}
	H13 = min_p;

	if (!check[12])
	{
	p_0 = F13;
	min_p = F13;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F13 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F13 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F13;
		}
	}
	F13 = min_p;

	
		p_0 = n13;
		min_p = n13;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n13 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n13 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n13 >= 0 && n13 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n13;
				}
			}
		}
		n13 = min_p;
	}

	sprintf_s(buf, "%g", H13);
	H13e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F13);
	F13e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x13);
	x13e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n13);
	n13e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x14;
	double p_0 = x14;
	int N_c = 100;
	if (!check[13])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x14 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x14;
			}
		}
		x14 = min_p;
	}

	p_0 = H14;
	min_p = H14;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H14 = p_0 + (i - 0.5*N_c) * 1;
		else
			H14 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H14;
		}
	}
	H14 = min_p;

	if (!check[13])
	{
	p_0 = F14;
	min_p = F14;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F14 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F14 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F14;
		}
	}
	F14 = min_p;

	
		p_0 = n14;
		min_p = n14;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n14 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n14 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n14 >= 0 && n14 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n14;
				}
			}
		}
		n14 = min_p;
	}

	sprintf_s(buf, "%g", H14);
	H14e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F14);
	F14e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x14);
	x14e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n14);
	n14e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton19()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x15;
	double p_0 = x15;
	int N_c = 100;
	if (!check[14])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x15 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x15;
			}
		}
		x15 = min_p;
	}

	p_0 = H15;
	min_p = H15;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H15 = p_0 + (i - 0.5*N_c) * 1;
		else
			H15 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H15;
		}
	}
	H15 = min_p;

	if (!check[14])
	{
	p_0 = F15;
	min_p = F15;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F15 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F15 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F15;
		}
	}
	F15 = min_p;

	
		p_0 = n15;
		min_p = n15;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n15 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n15 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n15 >= 0 && n15 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n15;
				}
			}
		}
		n15 = min_p;
	}

	sprintf_s(buf, "%g", H15);
	H15e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F15);
	F15e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x15);
	x15e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n15);
	n15e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton20()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x16;
	double p_0 = x16;
	int N_c = 100;
	if (!check[15])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x16 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x16;
			}
		}
		x16 = min_p;
	}

	p_0 = H16;
	min_p = H16;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H16 = p_0 + (i - 0.5*N_c) * 1;
		else
			H16 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H16;
		}
	}
	H16 = min_p;

	if (!check[15])
	{
	p_0 = F16;
	min_p = F16;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F16 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F16 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F16;
		}
	}
	F16 = min_p;

	
		p_0 = n16;
		min_p = n16;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n16 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n16 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n16 >= 0 && n16 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n16;
				}
			}
		}
		n16 = min_p;
	}

	sprintf_s(buf, "%g", H16);
	H16e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F16);
	F16e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x16);
	x16e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n16);
	n16e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton21()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x17;
	double p_0 = x17;
	int N_c = 100;
	if (!check[16])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x17 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x17;
			}
		}
		x17 = min_p;
	}

	p_0 = H17;
	min_p = H17;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H17 = p_0 + (i - 0.5*N_c) * 1;
		else
			H17 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H17;
		}
	}
	H17 = min_p;

	if (!check[16])
	{
	p_0 = F17;
	min_p = F17;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F17 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F17 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F17;
		}
	}
	F17 = min_p;

	
		p_0 = n17;
		min_p = n17;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n17 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n17 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n17 >= 0 && n17 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n17;
				}
			}
		}
		n17 = min_p;
	}

	sprintf_s(buf, "%g", H17);
	H17e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F17);
	F17e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x17);
	x17e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n17);
	n17e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton22()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x18;
	double p_0 = x18;
	int N_c = 100;
	if (!check[17])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x18 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x18;
			}
		}
		x18 = min_p;
	}

	p_0 = H18;
	min_p = H18;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H18 = p_0 + (i - 0.5*N_c) * 1;
		else
			H18 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H18;
		}
	}
	H18 = min_p;

	if (!check[17])
	{
	p_0 = F18;
	min_p = F18;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F18 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F18 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F18;
		}
	}
	F18 = min_p;

	
		p_0 = n18;
		min_p = n18;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n18 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n18 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n18 >= 0 && n18 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n18;
				}
			}
		}
		n18 = min_p;
	}

	sprintf_s(buf, "%g", H18);
	H18e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F18);
	F18e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x18);
	x18e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n18);
	n18e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton23()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x19;
	double p_0 = x19;
	int N_c = 100;
	if (!check[18])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x19 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x19;
			}
		}
		x19 = min_p;
	}

	p_0 = H19;
	min_p = H19;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H19 = p_0 + (i - 0.5*N_c) * 1;
		else
			H19 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H19;
		}
	}
	H19 = min_p;

	if (!check[18])
	{
	p_0 = F19;
	min_p = F19;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F19 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F19 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F19;
		}
	}
	F19 = min_p;

	
		p_0 = n19;
		min_p = n19;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n19 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n19 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n19 >= 0 && n19 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n19;
				}
			}
		}
		n19 = min_p;
	}

	sprintf_s(buf, "%g", H19);
	H19e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F19);
	F19e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x19);
	x19e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n19);
	n19e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton24()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x20;
	double p_0 = x20;
	int N_c = 100;
	if (!check[19])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x20 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x20;
			}
		}
		x20 = min_p;
	}

	p_0 = H20;
	min_p = H20;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H20 = p_0 + (i - 0.5*N_c) * 1;
		else
			H20 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H20;
		}
	}
	H20 = min_p;

	if (!check[19])
	{
	p_0 = F20;
	min_p = F20;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F20 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F20 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F20;
		}
	}
	F20 = min_p;

	
		p_0 = n20;
		min_p = n20;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n20 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n20 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n20 >= 0 && n20 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n20;
				}
			}
		}
		n20 = min_p;
	}

	sprintf_s(buf, "%g", H20);
	H20e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F20);
	F20e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x20);
	x20e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n20);
	n20e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedButton25()
{
	// TODO: Add your control notification handler code here
	double err = GetError();
	char buf[100];
	double min_err = err;

	double min_p = x21;
	double p_0 = x21;
	int N_c = 100;
	if (!check[20])
	{
		for (int i = 0; i < N_c + 1; i++)
		{
			x21 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
			err = GetError();
			if (err < min_err)
			{
				min_err = err;
				min_p = x21;
			}
		}
		x21 = min_p;
	}

	p_0 = H21;
	min_p = H21;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			H21 = p_0 + (i - 0.5*N_c) * 1;
		else
			H21 = p_0 + (i - 0.5*N_c) * 10;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = H21;
		}
	}
	H21 = min_p;

	if (!check[20])
	{
	p_0 = F21;
	min_p = F21;
	for (int i = 0; i<N_c + 1; i++)
	{
		if (fine)
			F21 = p_0 + (i - 0.5*N_c)*1.0 / N_c;
		else
			F21 = p_0 + (i - 0.5*N_c) * 10 / N_c;
		err = GetError();
		if (err<min_err)
		{
			min_err = err;
			min_p = F21;
		}
	}
	F21 = min_p;

	
		p_0 = n21;
		min_p = n21;
		for (int i = 0; i < N_c + 1; i++)
		{
			if (fine)
				n21 = p_0 + (i - 0.5*N_c)*0.02 / N_c;
			else
				n21 = p_0 + (i - 0.5*N_c)*0.2 / N_c;
			if (n21 >= 0 && n21 <= 1)
			{
				err = GetError();
				if (err < min_err)
				{
					min_err = err;
					min_p = n21;
				}
			}
		}
		n21 = min_p;
	}

	sprintf_s(buf, "%g", H21);
	H21e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", F21);
	F21e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", x21);
	x21e.SetWindowTextA(buf);
	sprintf_s(buf, "%g", n21);
	n21e.SetWindowTextA(buf);
}


void CVoightDlg::OnBnClickedCheck5()
{
	// TODO: Add your control notification handler code here
	check[0] = !check[0];
}


void CVoightDlg::OnBnClickedCheck6()
{
	// TODO: Add your control notification handler code here
	check[1] = !check[1];
}


void CVoightDlg::OnBnClickedCheck7()
{
	// TODO: Add your control notification handler code here
	check[2] = !check[2];
}


void CVoightDlg::OnBnClickedCheck8()
{
	// TODO: Add your control notification handler code here
	check[3] = !check[3];
}


void CVoightDlg::OnBnClickedCheck9()
{
	// TODO: Add your control notification handler code here
	check[4] = !check[4];
}


void CVoightDlg::OnBnClickedCheck10()
{
	// TODO: Add your control notification handler code here
	check[5] = !check[5];
}


void CVoightDlg::OnBnClickedCheck11()
{
	// TODO: Add your control notification handler code here
	check[6] = !check[6];
}


void CVoightDlg::OnBnClickedCheck12()
{
	// TODO: Add your control notification handler code here
	check[7] = !check[7];
}


void CVoightDlg::OnBnClickedCheck13()
{
	// TODO: Add your control notification handler code here
	check[8] = !check[8];
}


void CVoightDlg::OnBnClickedCheck14()
{
	// TODO: Add your control notification handler code here
	check[9] = !check[9];
}


void CVoightDlg::OnBnClickedCheck15()
{
	// TODO: Add your control notification handler code here
	check[10] = !check[10];
}


void CVoightDlg::OnBnClickedCheck16()
{
	// TODO: Add your control notification handler code here
	check[11] = !check[11];
}


void CVoightDlg::OnBnClickedCheck17()
{
	// TODO: Add your control notification handler code here
	check[12] = !check[12];
}


void CVoightDlg::OnBnClickedCheck18()
{
	// TODO: Add your control notification handler code here
	check[13] = !check[13];
}


void CVoightDlg::OnBnClickedCheck19()
{
	// TODO: Add your control notification handler code here
	check[14] = !check[14];
}


void CVoightDlg::OnBnClickedCheck20()
{
	// TODO: Add your control notification handler code here
	check[15] = !check[15];
}


void CVoightDlg::OnBnClickedCheck21()
{
	// TODO: Add your control notification handler code here
	check[16] = !check[16];
}


void CVoightDlg::OnBnClickedCheck22()
{
	// TODO: Add your control notification handler code here
	check[17] = !check[17];
}


void CVoightDlg::OnBnClickedCheck23()
{
	// TODO: Add your control notification handler code here
	check[18] = !check[18];
}


void CVoightDlg::OnBnClickedCheck24()
{
	// TODO: Add your control notification handler code here
	check[19] = !check[19];
}


void CVoightDlg::OnBnClickedCheck25()
{
	// TODO: Add your control notification handler code here
	check[20] = !check[20];
}
