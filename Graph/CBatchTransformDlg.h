#pragma once
#include "afxdialogex.h"


// CBatchTransformDlg dialog

class CBatchTransformDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBatchTransformDlg)

public:
	CBatchTransformDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CBatchTransformDlg();
	double crop_x_min, crop_x_max, crop_y_max, crop_y_min;
	CString trans_x, trans_y;
	CString combine_str;
	int operationN;
	double shape_dx, shape_dy; int shape_iter;
	int poly_order;
	int spline_order, spline_iter;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BATCHTRANSFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	CComboBox comb;
	afx_msg void OnCbnSelchangeCombo1();
};
