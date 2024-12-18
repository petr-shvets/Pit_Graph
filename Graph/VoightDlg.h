#pragma once
#include "afxwin.h"
#include "GraphDoc.h"

// CVoightDlg dialog

class CVoightDlg : public CDialog
{
	DECLARE_DYNAMIC(CVoightDlg)

public:
	CVoightDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CVoightDlg();

// Dialog Data
	enum { IDD = IDD_VOIGHTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	char separ;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	CEdit H1e;
	CEdit H2e;
	CEdit H3e;
	CEdit H4e;
	CEdit H5e;
	CEdit H6e;
	CEdit H7e;
	CEdit F1e;
	CEdit F2e;
	CEdit F3e;
	CEdit F4e;
	CEdit F5e;
	CEdit F6e;
	CEdit F7e;
	CEdit x1e;
	CEdit x2e;
	CEdit x3e;
	CEdit x4e;
	CEdit x5e;
	CEdit x6e;
	CEdit x7e;
	CEdit n1e;
	CEdit n2e;
	CEdit n3e;
	CEdit n4e;
	CEdit n5e;
	CEdit n6e;
	CEdit n7e;
	double H1;
	double H2;
	double H3;
	double H4;
	double H5;
	double H6;
	double H7;
	double F1;
	double F2;
	double F3;
	double F4;
	double F5;
	double F6;
	double F7;
	double x1;
	double x2;
	double x3;
	double x4;
	double x5;
	double x6;
	double x7;
	double n1;
	double n2;
	double n3;
	double n4;
	double n5;
	double n6;
	double n7;
	bool fine;
	virtual BOOL OnInitDialog();
	double *x_exp, *y_exp;
	int N_exp;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	double GetError(void);
	CEdit I1;
	CEdit I2;
	CEdit I3;
	CEdit I4;
	CEdit I5;
	CEdit I6;
	CEdit I7;
	/*afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit9();
	afx_msg void OnEnChangeEdit12();
	afx_msg void OnEnChangeEdit15();
	afx_msg void OnEnChangeEdit18();
	afx_msg void OnEnChangeEdit21();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit10();
	afx_msg void OnEnChangeEdit13();
	afx_msg void OnEnChangeEdit16();
	afx_msg void OnEnChangeEdit19();
	afx_msg void OnEnChangeEdit22();
	afx_msg void OnEnChangeEdit24();
	afx_msg void OnEnChangeEdit25();
	afx_msg void OnEnChangeEdit26();
	afx_msg void OnEnChangeEdit27();
	afx_msg void OnEnChangeEdit28();
	afx_msg void OnEnChangeEdit29();
	afx_msg void OnEnChangeEdit30();*/
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	CEdit H8e;
	double H8;
	CEdit F8e;
	double F8;
	CEdit x8e;
	double x8;
	CEdit n8e;
	double n8;
	afx_msg void OnBnClickedButton12();
	CEdit I8;
	CEdit H9e;
	double H9;
	CEdit H10e;
	double H10;
	double H11;
	CEdit H11e;
	CEdit H12e;
	double H12;
	CEdit H13e;
	double H13;
	double H14;
	CEdit H14e;
	double H15;
	CEdit H15e;
	CEdit H16e;
	double H16;
	CEdit H17e;
	double H17;
	double H18;
	CEdit H18e;
	double H19;
	double H20;
	CEdit H20e;
	CEdit H19e;
	CEdit H21e;
	double H21;
	CEdit F9e;
	double F9;
	double F10;
	CEdit F10e;
	CEdit F11e;
	double F11;
	CEdit F12e;
	double F12;
	CEdit F13e;
	double F13;
	CEdit F14e;
	double F14;
	CEdit F15e;
	double F15;
	CEdit F16e;
	double F16;
	CEdit F17e;
	double F17;
	double F18;
	CEdit F18e;
	CEdit F19e;
	double F19;
	CEdit F20e;
	double F20;
	CEdit F21e;
	double F21;
	CEdit x9e;
	double x9;
	CEdit x10e;
	double x10;
	CEdit x11e;
	double x11;
	CEdit x12e;
	double x12;
	CEdit x13e;
	double x13;
	CEdit x14e;
	double x14;
	CEdit x15e;
	double x15;
	CEdit x16e;
	double x16;
	CEdit x17e;
	double x17;
	CEdit x18e;
	double x18;
	CEdit x19e;
	double x19;
	double x20;
	CEdit x20e;
	CEdit x21e;
	double x21;
	CEdit n9e;
	double n9;
	CEdit n10e;
	double n10;
	CEdit n11e;
	double n11;
	double n12;
	CEdit n12e;
	CEdit n13e;
	double n13;
	CEdit n14e;
	double n14;
	double n15;
	CEdit n15e;
	CEdit n16e;
	double n16;
	CEdit n17e;
	double n17;
	CEdit n18e;
	double n18;
	double n19;
	CEdit n19e;
	CEdit n20e;
	double n20;
	CEdit n21e;
	double n21;
	CEdit I9;
	CEdit I10;
	CEdit I11;
	CEdit I12;
	CEdit I13;
	CEdit I14;
	CEdit I15;
	CEdit I16;
	CEdit I17;
	CEdit I18;
	CEdit I19;
	CEdit I20;
	CEdit I21;
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton25();
	CButton ch1;
	CButton ch2;
	CButton ch3;
	CButton ch4;
	CButton ch5;
	CButton ch6;
	CButton ch7;
	CButton ch8;
	CButton ch9;
	CButton ch10;
	CButton ch11;
	CButton ch12;
	CButton ch13;
	CButton ch14;
	CButton ch15;
	CButton ch16;
	CButton ch17;
	CButton ch18;
	CButton ch19;
	CButton ch20;
	CButton ch21;
	bool check[21];
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck12();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedCheck14();
	afx_msg void OnBnClickedCheck15();
	afx_msg void OnBnClickedCheck16();
	afx_msg void OnBnClickedCheck17();
	afx_msg void OnBnClickedCheck18();
	afx_msg void OnBnClickedCheck19();
	afx_msg void OnBnClickedCheck20();
	afx_msg void OnBnClickedCheck21();
	afx_msg void OnBnClickedCheck22();
	afx_msg void OnBnClickedCheck23();
	afx_msg void OnBnClickedCheck24();
	afx_msg void OnBnClickedCheck25();
	CGraphDoc* pDoc;
};
