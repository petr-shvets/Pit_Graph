
// GraphView.cpp : implementation of the CGraphView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Graph.h"
#endif

#include "GraphDoc.h"
#include "GraphView.h"
#include "MainFrm.h"
#include "CreEPS.hpp"
#include "CTL_app.h"

#pragma comment(lib, "corona.lib")

#include "corona.h"
#include "AxisDlg.h"
#include "WndSizeDlg.h"
#include "GraphDlg.h"
#include "SizeDlg.h"
#include "TransformDlg.h"
#include "AddFuncDlg.h"
#include "AppDlg.h"
#include "CItoGDlg.h"
#include "CPolyAppDlg.h"
#include <algorithm>
#include "CSettingsDlg.h"
#include "CCombineDlg.h"
#include "CSplitDlg.h"
#include "CRemovePointsDlg.h"
#include "CCropDlg.h"
#include "CShapeCorrDlg.h"
#include "CBGPolyDlg.h"
#include "CAveParamDlg.h"
#include "CSplineDlg.h"
#include "CMergeDlg.h"
#include "CBatchAnalyzeDlg.h"
#include "CBatchTransformDlg.h"
#include "CTextDlg.h"
#include "VoightDlg.h"
#include "CVoightNDlg.h"
#include "CAppColDlg.h"
#include "CReclorDlg.h"
#include "StepCCDlg.h"

#include "tinyexpr.h"

extern void GetLinearSystemRoot(double* A, int N, double* x, double* b);
extern void SwapStrings(double* A, int i, int j, int N);

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CStatusBar* statb = NULL;

// CGraphView

IMPLEMENT_DYNCREATE(CGraphView, CView)

BEGIN_MESSAGE_MAP(CGraphView, CView)
	ON_COMMAND(ID_FILE_ADDGRAPH, &CGraphView::OnFileAddgraph)
	ON_UPDATE_COMMAND_UI(ID_FILE_ADDGRAPH, &CGraphView::OnUpdateFileAddgraph)
	ON_COMMAND(ID_VIEW_AXIS, &CGraphView::OnViewAxis)
	ON_UPDATE_COMMAND_UI(ID_VIEW_AXIS, &CGraphView::OnUpdateViewAxis)
	ON_COMMAND(ID_VIEW_WINDOWSIZE, &CGraphView::OnViewWindowsize)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WINDOWSIZE, &CGraphView::OnUpdateViewWindowsize)
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_EDIT_REMOVECURRENT, &CGraphView::OnEditRemovecurrent)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REMOVECURRENT, &CGraphView::OnUpdateEditRemovecurrent)
	ON_COMMAND(ID_DEFAULTSIZE, &CGraphView::OnDefaultsize)
	ON_UPDATE_COMMAND_UI(ID_DEFAULTSIZE, &CGraphView::OnUpdateDefaultsize)
	ON_COMMAND(ID_VIEW_GRAPH, &CGraphView::OnViewGraph)
	ON_UPDATE_COMMAND_UI(ID_VIEW_GRAPH, &CGraphView::OnUpdateViewGraph)
	ON_COMMAND(ID_VIEW_SIZE, &CGraphView::OnViewSize)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SIZE, &CGraphView::OnUpdateViewSize)
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_EDIT_TRANSFORM, &CGraphView::OnEditTransform)
	ON_UPDATE_COMMAND_UI(ID_EDIT_TRANSFORM, &CGraphView::OnUpdateEditTransform)
	ON_UPDATE_COMMAND_UI(ID_FILE_ADDFUNCTION, &CGraphView::OnUpdateFileAddfunction)
	ON_COMMAND(ID_FILE_ADDFUNCTION, &CGraphView::OnFileAddfunction)
	ON_COMMAND(ID_EDIT_APPROXIMATION, &CGraphView::OnEditApproximation)
	ON_UPDATE_COMMAND_UI(ID_EDIT_APPROXIMATION, &CGraphView::OnUpdateEditApproximation)
	ON_COMMAND(ID_FILE_EXPORTDATA, &CGraphView::OnFileExportdata)
	ON_UPDATE_COMMAND_UI(ID_FILE_EXPORTDATA, &CGraphView::OnUpdateFileExportdata)
	ON_COMMAND(ID_EDIT_REMOVEALL, &CGraphView::OnEditRemoveall)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REMOVEALL, &CGraphView::OnUpdateEditRemoveall)
	ON_COMMAND(ID_FILE_IMAGETODATA, &CGraphView::OnFileImagetodata)
	ON_UPDATE_COMMAND_UI(ID_FILE_IMAGETODATA, &CGraphView::OnUpdateFileImagetodata)
	ON_COMMAND(ID_SMOOTHING_REMOVESPIKES, &CGraphView::OnSmoothingRemovespikes)
	ON_UPDATE_COMMAND_UI(ID_SMOOTHING_REMOVESPIKES, &CGraphView::OnUpdateSmoothingRemovespikes)
	ON_COMMAND(ID_EDIT_COPY, &CGraphView::OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, &CGraphView::OnUpdateEditCopy)
	ON_COMMAND(ID_APPROXIMATION_CUSTOM, &CGraphView::OnApproximationCustom)
	ON_UPDATE_COMMAND_UI(ID_APPROXIMATION_CUSTOM, &CGraphView::OnUpdateApproximationCustom)
	ON_COMMAND(ID_APPROXIMATION_POLYNOMIAL, &CGraphView::OnApproximationPolynomial)
	ON_UPDATE_COMMAND_UI(ID_APPROXIMATION_POLYNOMIAL, &CGraphView::OnUpdateApproximationPolynomial)
	ON_UPDATE_COMMAND_UI(ID_EDIT_AVERAGE, &CGraphView::OnUpdateEditAverage)
	ON_COMMAND(ID_EDIT_AVERAGE, &CGraphView::OnEditAverage)
	ON_COMMAND(ID_FILE_SETTINGS, &CGraphView::OnFileSettings)
	ON_UPDATE_COMMAND_UI(ID_FILE_SETTINGS, &CGraphView::OnUpdateFileSettings)
	ON_COMMAND(ID_SMOOTHING_SIMPLESPLINE, &CGraphView::OnSmoothingSimplespline)
	ON_UPDATE_COMMAND_UI(ID_SMOOTHING_SIMPLESPLINE, &CGraphView::OnUpdateSmoothingSimplespline)
	ON_UPDATE_COMMAND_UI(ID_VIEW_POLAR, &CGraphView::OnUpdateViewPolar)
	ON_COMMAND(ID_VIEW_POLAR, &CGraphView::OnViewPolar)
	ON_COMMAND(ID_INTEGRAL, &CGraphView::OnIntegral)
	ON_UPDATE_COMMAND_UI(ID_INTEGRAL, &CGraphView::OnUpdateIntegral)
	ON_COMMAND(ID_EDIT_COMBINE, &CGraphView::OnEditCombine)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COMBINE, &CGraphView::OnUpdateEditCombine)
	ON_UPDATE_COMMAND_UI(ID_REMOVE_REMOVEALLBUTCURRENT, &CGraphView::OnUpdateRemoveRemoveallbutcurrent)
	ON_COMMAND(ID_REMOVE_REMOVEALLBUTCURRENT, &CGraphView::OnRemoveRemoveallbutcurrent)
	ON_COMMAND(ID_EDIT_SPLIT, &CGraphView::OnEditSplit)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SPLIT, &CGraphView::OnUpdateEditSplit)
	ON_COMMAND(ID_FILE_EXPORTCURRENT, &CGraphView::OnFileExportcurrent)
	ON_UPDATE_COMMAND_UI(ID_FILE_EXPORTCURRENT, &CGraphView::OnUpdateFileExportcurrent)
	ON_COMMAND(ID_REMOVE_POINTS, &CGraphView::OnRemovePoints)
	ON_UPDATE_COMMAND_UI(ID_REMOVE_POINTS, &CGraphView::OnUpdateRemovePoints)
	ON_COMMAND(ID_LEFTBTN, &CGraphView::OnLeftbtn)
	ON_UPDATE_COMMAND_UI(ID_LEFTBTN, &CGraphView::OnUpdateLeftbtn)
	ON_COMMAND(ID_RIGHTBTN, &CGraphView::OnRightbtn)
	ON_UPDATE_COMMAND_UI(ID_RIGHTBTN, &CGraphView::OnUpdateRightbtn)
	ON_COMMAND(ID_UPBTN, &CGraphView::OnUpbtn)
	ON_UPDATE_COMMAND_UI(ID_UPBTN, &CGraphView::OnUpdateUpbtn)
	ON_COMMAND(ID_DOWNBTN, &CGraphView::OnDownbtn)
	ON_UPDATE_COMMAND_UI(ID_DOWNBTN, &CGraphView::OnUpdateDownbtn)
	ON_COMMAND(ID_GRAPHDRAW, &CGraphView::OnGraphdraw)
	ON_UPDATE_COMMAND_UI(ID_GRAPHDRAW, &CGraphView::OnUpdateGraphdraw)
	ON_WM_RBUTTONUP()
	ON_UPDATE_COMMAND_UI(ID_EDIT_CROP, &CGraphView::OnUpdateEditCrop)
	ON_COMMAND(ID_EDIT_CROP, &CGraphView::OnEditCrop)
	ON_COMMAND(ID_BACKGROUNDCORRECTION_SHIRLEY, &CGraphView::OnBackgroundcorrectionShirley)
	ON_UPDATE_COMMAND_UI(ID_BACKGROUNDCORRECTION_SHIRLEY, &CGraphView::OnUpdateBackgroundcorrectionShirley)
	ON_COMMAND(ID_BACKGROUNDCORRECTION_SHAPE, &CGraphView::OnBackgroundcorrectionShape)
	ON_UPDATE_COMMAND_UI(ID_BACKGROUNDCORRECTION_SHAPE, &CGraphView::OnUpdateBackgroundcorrectionShape)
	ON_COMMAND(ID_BACKGROUNDCORRECTION_POLYNOMIAL, &CGraphView::OnBackgroundcorrectionPolynomial)
	ON_UPDATE_COMMAND_UI(ID_BACKGROUNDCORRECTION_POLYNOMIAL, &CGraphView::OnUpdateBackgroundcorrectionPolynomial)
	ON_COMMAND(ID_EDIT_MERGE, &CGraphView::OnEditMerge)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MERGE, &CGraphView::OnUpdateEditMerge)
	ON_COMMAND(ID_BATCHOPERATION_ANALYZE, &CGraphView::OnBatchoperationAnalyze)
	ON_UPDATE_COMMAND_UI(ID_BATCHOPERATION_ANALYZE, &CGraphView::OnUpdateBatchoperationAnalyze)
	ON_COMMAND(ID_BATCHOPERATION_TRANSFORM, &CGraphView::OnBatchoperationTransform)
	ON_UPDATE_COMMAND_UI(ID_BATCHOPERATION_TRANSFORM, &CGraphView::OnUpdateBatchoperationTransform)
	ON_COMMAND(ID_FILE_SAVEASEPS, &CGraphView::OnFileSaveaseps)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVEASEPS, &CGraphView::OnUpdateFileSaveaseps)
	ON_COMMAND(ID_BUTTON32816, &CGraphView::OnButton32816)
	ON_UPDATE_COMMAND_UI(ID_BUTTON32816, &CGraphView::OnUpdateButton32816)
	ON_COMMAND(ID_BUTTON32817, &CGraphView::OnButton32817)
	ON_UPDATE_COMMAND_UI(ID_BUTTON32817, &CGraphView::OnUpdateButton32817)
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_REMOVE_TEXTS, &CGraphView::OnRemoveTexts)
	ON_UPDATE_COMMAND_UI(ID_REMOVE_TEXTS, &CGraphView::OnUpdateRemoveTexts)
	ON_COMMAND(ID_BUTTON32819, &CGraphView::OnButton32819)
	ON_UPDATE_COMMAND_UI(ID_BUTTON32819, &CGraphView::OnUpdateButton32819)
	ON_COMMAND(ID_APPROXIMATION_VOIGHT, &CGraphView::OnApproximationVoight)
	ON_UPDATE_COMMAND_UI(ID_APPROXIMATION_VOIGHT, &CGraphView::OnUpdateApproximationVoight)
	ON_COMMAND(ID_APPROXIMATION_HIDE, &CGraphView::OnApproximationHide)
	ON_UPDATE_COMMAND_UI(ID_APPROXIMATION_HIDE, &CGraphView::OnUpdateApproximationHide)
	ON_UPDATE_COMMAND_UI(ID_VIEW_APPROXIMATION, &CGraphView::OnUpdateViewApproximation)
	ON_COMMAND(ID_VIEW_APPROXIMATION, &CGraphView::OnViewApproximation)
	ON_COMMAND(ID_BUTTON32825, &CGraphView::OnButton32825)
	ON_UPDATE_COMMAND_UI(ID_BUTTON32825, &CGraphView::OnUpdateButton32825)
	ON_COMMAND(ID_VIEW_RECOLORGRAPHS, &CGraphView::OnViewRecolorgraphs)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RECOLORGRAPHS, &CGraphView::OnUpdateViewRecolorgraphs)
	ON_COMMAND(ID_EDIT_RESTORE, &CGraphView::OnEditRestore)
	ON_UPDATE_COMMAND_UI(ID_EDIT_RESTORE, &CGraphView::OnUpdateEditRestore)
	ON_COMMAND(ID_EDIT_UNDO32830, &CGraphView::OnEditUndo32830)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO32830, &CGraphView::OnUpdateEditUndo32830)
	ON_COMMAND(ID_SMOOTHING_STEPCROSS, &CGraphView::OnSmoothingStepcross)
	ON_UPDATE_COMMAND_UI(ID_SMOOTHING_STEPCROSS, &CGraphView::OnUpdateSmoothingStepcross)
END_MESSAGE_MAP()

// CGraphView construction/destruction

CGraphView::CGraphView()
{
	// TODO: add construction code here
	graphs.Init(0);
	cur_undo_n = 0;
	//------------------------------------------//
	x_axis = "X";
	y_axis = "Intensity";
	axe_fontN = 36; axe_fontA = 40;
	Nx_mark = 11; Ny_mark = 8;
	tol_x = 0; tol_y = 1;
	e_x = false; e_y = false; hide_y = false;
	y_shift = 0;
	//------------------------------------------//

	//------------------------------------------//
	x_min = 0; x_max = 1000;
	y_min = 0; y_max = 1000;
	//------------------------------------------//

	//------------------------------------------//
	margin_left = 142; margin_right = 34; margin_top = 20; margin_bottom = 83;
	//------------------------------------------//

	//------------------------------------------//
	cur_gr_N = 0;
	show_marker = true;
	show_net = true;
	//------------------------------------------//
	mouse_flag = 0;
	//0 - free, 1 - scale
	//------------------------------------------//
	trans_x = "x";
	trans_y = "y";
	trans_def_size = true;
	addf_x1 = 0; addf_x2 = 1;
	addf_N = 500;
	addf_y = "sin(x)";
	combine_str = "y1-y2";
	//------------------------------------------//
	for (int i = 0; i < 5; i++)
	{
		def_app_var_min[i] = 0; def_app_var_max[i] = 1;
		def_app_var_val[i] = 0;
		def_app_var_N[i] = 1;;
	}
	def_app_eq="A*x+B";
	def_app_iter = 1;
	for (int i = 0; i < 10; i++)
	{
		def_poly_app[i] = 0;
	}
	hide_app = false;
	//------------------------------------------// Image to Graph dialog
	Ix1 = 0, Ix2 = 100, Iy1 = 0, Iy2 = 100;
	sensitivity = 500;
	//------------------------------------------//
	poly_app_n = 1;
	split_x = 500;
	//------------------------------------------//
	file_mode = 1;
	dec_separator = '.';
	polar_deg = true;
	view_mode = false; //true - directX, false - default
	polar_view = false;
	eps_scale = 2.5;
	move_scale = 1.0 / 200;
	//------------------------------------------//
	calc_integral = false; calc_integral_line = false;
	calc_integral_x_last = 0;
	calc_integral_x_first = 0;
	//------------------------------------------//
	edit_graph = false;
	edit_graph_rbtn = false;
	edit_graph_prevX = 0; edit_graph_prevY = 0;
	//------------------------------------------//
	crop_min = 0;
	crop_max = 500;
	crop_y_min = 0;
	crop_y_max = 0;
	//------------------------------------------//
	shape_dx = 100;
	shape_dy = 10;
	shape_iter = 1;
	shape_show = true;
	BG_poly_n = 1;
	BG_poly_iter = 1000;
	//------------------------------------------//
	ave_sigma_N = 1.5;
	//------------------------------------------//
	spline_order = 5; spline_iter = 1;
	stepCC_N = 500; stepCC_iter = 3; stepCC_dx = 10;
	//------------------------------------------//
	merge_rule = "0"; batch_trans_operN = 0;
	//------------------------------------------//
	NumText = 0;
	MaxText = 25;
	texts = new text[MaxText];
	moveText = false;
	i_text_move = -1; i_text_last = -1;
	text_move_dx = 0; text_move_dy = 0;
	addText = false;
	//------------------------------------------//
	for (int i = 0; i < 21; i++)
	{
		v_A[i] = 0;
		v_B[i] = 0;
		v_x[i] = 0;
		v_n[i] = 0;
		v_ch[i] = false;

		v_Amax[i] = 0; v_Amin[i] = 0; v_Astep[i] = 0;
		v_Bmax[i] = 0; v_Bmin[i] = 0; v_Bstep[i] = 0;
		v_xmax[i] = 0; v_xmin[i] = 0; v_xstep[i] = 0;
		v_nmax[i] = 0; v_nmin[i] = 0; v_nstep[i] = 0;
	}
	v_fine = false;
	graphs_Voight.Init(0);
	v_col_1 = RGB(255, 0, 255);
	v_col_2 = RGB(0, 255, 255);
	v_thick_1 = 2;
	v_thick_2 = 1;

	v_def_dH = 0.2; v_def_H_st=0.01;
	v_def_dF = 5; v_def_F_st = 0.01;
	v_def_dx = 5; v_def_x_st = 0.01;
	v_def_n_min = 0; v_def_n_max = 1; v_def_n_step = 0.01;

	v_n_iter = 1;
	//------------------------------------------//
	meas_text_size = 20; meas_line_w = 2; sel_line_w = 2;
	meas_text_col = RGB(0, 0, 100); meas_line_col = RGB(0, 0, 100); sel_line_col = RGB(0, 255, 255);
	//------------------------------------------//
	batch_app_int_x_min = 0;
	batch_app_int_x_max = 1000;
	//------------------------------------------//
	palette_number = 1;
	palette_pts[0] = 0; palette_pts[1] = 0.25; palette_pts[2] = 0.5; palette_pts[3] = 0.75; palette_pts[4] = 1;
	palette_red[0] = 0; palette_red[1] = 127; palette_red[2] = 160; palette_red[3] = 0; palette_red[4] = 127;
	palette_green[0] = 0; palette_green[1] = 127; palette_green[2] = 160; palette_green[3] = 127; palette_green[4] = 0;
	palette_blue[0] = 127; palette_blue[1] = 0; palette_blue[2] = 160; palette_blue[3] = 127; palette_blue[4] = 0;
	//------------------------------------------//
	TL_d = 50;
	TL_A = 142.6;
	TL_C = 1.91;
	TL_Eg = 2.03;
	TL_E0 = 3.84;
	TL_eps_inf = 1.69;
	TL_phi = 70;
	TL_rough = 5;
}

CGraphView::~CGraphView()
{
	graphs.DeleteAll();
	for (int i = 0; i < formats_N; i++)
	{
		for (int j = 0; j < formats[i].number_N; j++)
		{
			delete[] formats[i].graph_index[j];
		}
		delete[] formats[i].graph_index;
		delete[] formats[i].graph_N;
		delete[] formats[i].number_type;
	}
	if (NumText > 0) delete[] texts;
	delete[] formats;

	CFile cf;
	if (cf.Open("settings.txt", CFile::modeCreate|CFile::modeWrite))
	{
		char buf[100];
		int a = sprintf(buf, "f_mode: %d\r\n", file_mode);
		cf.Write(buf, a);
		int val = 0;
		if (dec_separator == '.') val = 0;
		if (dec_separator == ',') val = 1;
		a = sprintf(buf, "separator: %d\r\n", val);
		cf.Write(buf, a);
		a = sprintf(buf, "polar units: %d\r\n", polar_deg);
		cf.Write(buf, a);
		a = sprintf(buf, "view mode: %d\r\n", view_mode);
		cf.Write(buf, a);
		a = sprintf(buf, "EPS scale: %g\r\n", eps_scale);
		cf.Write(buf, a);
		a = sprintf(buf, "move scale: %g\r\n", move_scale);
		cf.Write(buf, a);
		a = sprintf(buf, "measurement line width: %d\r\n", meas_line_w);
		cf.Write(buf, a);
		a = sprintf(buf, "measurement line color: %d\r\n", GetRValue(meas_line_col) * 256 * 256 + GetGValue(meas_line_col) * 256 + GetBValue(meas_line_col));
		cf.Write(buf, a);
		a = sprintf(buf, "measurement text size: %d\r\n", meas_text_size);
		cf.Write(buf, a);
		a = sprintf(buf, "measurement text color: %d\r\n", GetRValue(meas_text_col) * 256 * 256 + GetGValue(meas_text_col) * 256 + GetBValue(meas_text_col));
		cf.Write(buf, a);
		a = sprintf(buf, "Voight parameters\r\ndH: %g, H_step: %g\r\n", v_def_dH, v_def_H_st);
		cf.Write(buf, a);
		a = sprintf(buf, "dFWHM: %g, FWHM_step: %g\r\n", v_def_dF, v_def_F_st);
		cf.Write(buf, a);
		a = sprintf(buf, "dx: %g, x_step: %g\r\n", v_def_dx, v_def_x_st);
		cf.Write(buf, a);
		a = sprintf(buf, "n_min: %g, n_step: %g, n_max: %g\r\n", v_def_n_min, v_def_n_step, v_def_n_max);
		cf.Write(buf, a);
		a = sprintf(buf, "Colormap R: %d : %d : %d : %d : %d\r\n", palette_red[0], palette_red[1], palette_red[2], palette_red[3], palette_red[4]);
		cf.Write(buf, a);
		a = sprintf(buf, "Colormap G: %d : %d : %d : %d : %d\r\n", palette_green[0], palette_green[1], palette_green[2], palette_green[3], palette_green[4]);
		cf.Write(buf, a);
		a = sprintf(buf, "Colormap B: %d : %d : %d : %d : %d\r\n", palette_blue[0], palette_blue[1], palette_blue[2], palette_blue[3], palette_blue[4]);
		cf.Write(buf, a);
		a = sprintf(buf, "Colormap P: %g : %g : %g : %g : %g\r\n", palette_pts[0], palette_pts[1], palette_pts[2], palette_pts[3], palette_pts[4]);
		cf.Write(buf, a);
		a = sprintf(buf, "Colormap N: %d", palette_number);
		cf.Write(buf, a);
		cf.Close();
	}
}

double GetDigitalFromString(char* buf, char separ)
{
	int i = 0; int minus = -1; double result = 0; double l = 10;
	int emin = -1; int e = 0;
	while (buf[i] == 32 || buf[i] == 13 || buf[i] == 10 || buf[i] == 9)
	{
		i = i + 1;
	}
	if (buf[i] == 45)
	{
		i = i + 1;
		minus = 1;
	}
	else if (buf[i] == '+') i++;
	while (buf[i] > 47 && buf[i] < 58)
	{
		result = result * 10 + buf[i] - 48;
		i = i + 1;
	}
	if (buf[i] != separ)
	{
		if (buf[i] == 69 || buf[i] == 101)
		{
			i = i + 1;
			if (buf[i] == 45)
			{
				i = i + 1;
				emin = 1;
			}
			if (buf[i] == '+') i++;
			while (buf[i] > 47 && buf[i] < 58)
			{
				e = e * 10 + buf[i] - 48;
				i = i + 1;
			}
		}
		if (emin == -1)
			return (-1) * minus * result * pow(10.0, e);
		else
			return (-1) * minus * result / pow(10.0, e);
	}
	else
	{
		i = i + 1;
		while (buf[i] > 47 && buf[i] < 58)
		{
			result = result + (buf[i] - 48) / l;
			i = i + 1;
			l = l * 10;
		}
		if (buf[i] == 69 || buf[i] == 101)
		{
			i = i + 1;
			if (buf[i] == 45)
			{
				i = i + 1;
				emin = 1;
			}
			if (buf[i] == '+') i++;
			while (buf[i] > 47 && buf[i] < 58)
			{
				e = e * 10 + buf[i] - 48;
				i = i + 1;
			}
		}
	}
	if (emin == -1)
		return (-1) * minus * result * pow(10.0, e);
	else
		return (-1) * minus * result / pow(10.0, e);
}
int GetLengthDigital(char* buf, char separ)
{
	int i = 0;
	while (buf[i] == 32 || buf[i] == 13 || buf[i] == 10 || buf[i] == 9)
		i = i + 1;
	if (buf[i] == 45 || buf[i] == '+')
		i = i + 1;
	while (buf[i] > 47 && buf[i] < 58)
		i = i + 1;
	if (buf[i] == separ)
	{
		i = i + 1;
		while (buf[i] > 47 && buf[i] < 58)
			i = i + 1;
	}
	if (buf[i] == 69 || buf[i] == 101)
	{
		i = i + 1;
		if (buf[i] == 45 || buf[i] == '+')
			i = i + 1;
		while (buf[i] > 47 && buf[i] < 58)
			i = i + 1;
	}
	return i;
}

BOOL CGraphView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGraphView drawing

void CGraphView::OnDraw(CDC* pDC)
{
	CGraphDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect r;
	GetClientRect(&r);
	CRect gr_r;
	gr_r.left = r.left + margin_left;
	gr_r.right = r.right - margin_right;
	gr_r.top = r.top + margin_top;
	gr_r.bottom = r.bottom - margin_bottom - axe_fontN / 2;

	static bool start = true;
	if (start)
	{
		start = false;
		dxMgr_.Initialise(m_hWnd);
		SetFileFormats();
		SetSettings();
		//LoadEl();
	}

	if (view_mode)
	{
		HDC& hdc = dxMgr_.BeginPaint(RGB(255, 255, 255));
		CDC* memdc = CDC::FromHandle(hdc);

		graphs.DrawAll(memdc, gr_r, x_min, x_max, y_min, y_max, polar_view, polar_deg, false, 0, 0, hide_app, graphs[0]);
		DrawAxis(memdc, false, 0);
		DrawGraphMarker(memdc);
		Draw_Text(memdc, false, 0);
		if(!hide_app)
			graphs_Voight.DrawAll(memdc, gr_r, x_min, x_max, y_min, y_max, polar_view, polar_deg, false, 0, 0, 0, graphs[0]);

		dxMgr_.EndPaint();
	}
	else
	{
		CDC memdc;
		CBitmap* oldbmp, membmp;
		memdc.CreateCompatibleDC(pDC);
		membmp.CreateCompatibleBitmap(pDC, r.right, r.bottom);
		oldbmp = memdc.SelectObject(&membmp);

		////-----------------------------------------

		CBrush br;
		br.CreateSolidBrush(RGB(255, 255, 255));
		memdc.FillRect(&r, &br);
		DeleteObject(br);

		////-----------------------------------------

		graphs.DrawAll(&memdc, gr_r, x_min, x_max, y_min, y_max, polar_view, polar_deg, false, 0, 0, hide_app, graphs[0]);
		DrawAxis(&memdc, false, 0);
		DrawGraphMarker(&memdc);
		Draw_Text(&memdc, false, 0);
		if (!hide_app)
			graphs_Voight.DrawAll(&memdc, gr_r, x_min, x_max, y_min, y_max, polar_view, polar_deg, false, 0, 0, 0, graphs[0]);

		////-----------------------------------------

		pDC->BitBlt(0, 0, r.right, r.bottom, &memdc, 0, 0, SRCCOPY);

		memdc.SelectObject(oldbmp);
		DeleteObject(membmp);
		DeleteObject(oldbmp);
	}
}

void CGraphView::SetFileFormats()
{
	bool error = false;
	CFile cf;
	if (cf.Open("formats.txt", CFile::modeRead))
	{
		int size = cf.GetLength() + 1;
		char* buf = new char[size];
		cf.Read(buf, size);
		cf.Close();

		formats_N = 0;
		int k = 0;
		while (k < size)
		{
			if (buf[k] == ':' && buf[k + 1] == ':')
			{
				formats_N++;
				k++;
			}
			k++;
		}
		formats = new file_format[formats_N];

		int i = 0;
		k = 0;
		while (k < size)
		{
			if ((buf[k] == ':' && buf[k + 1] == ':') || (buf[k] == ' ' && buf[k + 1] == ':' && buf[k + 2] == ':'))
			{
				formats[i].number_N = 0;
				formats[i].skip = 0;

				while (!(buf[k] == 13 && buf[k + 1] == 10) && k < size)
				{
					if (buf[k] == 's')
					{
						formats[i].skip = GetDigitalFromString(&buf[k + 1], dec_separator);
					}
					if (buf[k] == 'x' || buf[k] == 'y' || buf[k] == 'e' || buf[k] == 'i')
						formats[i].number_N++;
					k++;
				}
				k += 2;
				i++;
			}
			else
			{
				formats[i].name += buf[k];
				k++;
			}
		}
		for (int j = 0; j < formats_N; j++)
		{
			formats[j].number_type = new char[formats[j].number_N];
			formats[j].graph_N = new int[formats[j].number_N];
			formats[j].graph_index = new int* [formats[j].number_N];
		}

		i = 0; k = 0;
		while (k < size)
		{
			if (buf[k] == ':')
			{
				int j = 0;
				while (!(buf[k] == 13 && buf[k + 1] == 10) && k < size)
				{
					if (buf[k] == 'x' || buf[k] == 'y' || buf[k] == 'e' || buf[k] == 'i')
					{
						int k0 = k;
						formats[i].number_type[j] = buf[k];
						formats[i].graph_N[j] = 0;
						if (buf[k] == 'x' || buf[k] == 'y')
						{
							while (buf[k] != ' ' && buf[k] != 13 && k < size)
							{
								if (buf[k] == '_')
								{
									formats[i].graph_N[j]++;
								}
								k++;
							}
						}
						formats[i].graph_N[j] = max(1, formats[i].graph_N[j]);
						formats[i].graph_index[j] = new int[formats[i].graph_N[j]];

						k = k0;
						if (buf[k] == 'x' || buf[k] == 'y')
						{
							int m = 0;
							while (buf[k] != ' ' && buf[k] != 13 && k < size)
							{
								if (buf[k] == '_')
								{
									k++;
									formats[i].graph_index[j][m] = GetDigitalFromString(&buf[k], dec_separator) - 1;
									m++;
								}
								k++;
							}
						}
						else formats[i].graph_index[j][0] = 0;
						j++;
						k = k0;
					}
					k++;
				}
				k += 2;
				i++;
			}
			k++;
		}

		//check
		for (int i = 0; i < formats_N && !error; i++)
		{
			int index_max = 0;
			for (int j = 0; j < formats[i].number_N; j++)
			{
				for (int k = 0; k < formats[i].graph_N[j]; k++)
				{
					if (formats[i].graph_index[j][k] > index_max) index_max = formats[i].graph_index[j][k];
				}
			}

			/*char bbb[100];
			sprintf(bbb, "%d", index_max);
			::MessageBox(0, bbb, 0, MB_OK);*/

			bool* found_x = new bool[index_max+1];
			bool* found_y = new bool[index_max+1];
			for (int j = 0; j < index_max+1; j++)
			{
				found_x[j] = false;
				found_y[j] = false;
			}
			for (int j = 0; j < formats[i].number_N; j++)
			{
				for (int k = 0; k < formats[i].graph_N[j]; k++)
				{
					if (formats[i].number_type[j] == 'x')
					{
						found_x[formats[i].graph_index[j][k]] = true;
					}
					if (formats[i].number_type[j] == 'y')
					{
						found_y[formats[i].graph_index[j][k]] = true;
					}
				}
			}
			for (int j = 0; j < index_max+1; j++)
			{
				if (found_x[j] == false)
				{
					char bbb[250];
					sprintf(bbb, "x_%d is uninitialized in format %d!", j + 1, i + 1);
					::MessageBox(0, bbb, 0, MB_OK);
					error = true;
					break;
				}
				if (found_y[j] == false)
				{
					char bbb[250];
					sprintf(bbb, "y_%d is uninitialized in format %d!", j + 1, i + 1);
					::MessageBox(0, bbb, 0, MB_OK);
					error = true;
					break;
				}
			}
			delete[] found_x;
			delete[] found_y;
		}

		delete[] buf;
	}
	if (!error) return;
	else
	{
		for (int i = 0; i < formats_N; i++)
		{
			for (int j = 0; j < formats[i].number_N; j++)
			{
				delete[] formats[i].graph_index[j];
			}
			delete[] formats[i].graph_index;
			delete[] formats[i].graph_N;
			delete[] formats[i].number_type;
		}
		delete[] formats;
	}

	formats_N = 1;
	formats = new file_format[formats_N];
	formats[0].name = "xy|*.*";
	formats[0].number_N = 2;
	formats[0].number_type = new char[formats[0].number_N];
	formats[0].number_type[0] = 'x';
	formats[0].number_type[1] = 'y';
	formats[0].graph_N = new int[formats[0].number_N];
	formats[0].graph_N[0] = 1;
	formats[0].graph_N[1] = 1;
	formats[0].graph_index = new int* [formats[0].number_N];
	formats[0].graph_index[0] = new int[1];
	formats[0].graph_index[1] = new int[1];
	formats[0].graph_index[0][0] = 0;
	formats[0].graph_index[1][0] = 0;
	formats[0].skip = 0;
}
// CGraphView diagnostics

#ifdef _DEBUG
void CGraphView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphDoc* CGraphView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphDoc)));
	return (CGraphDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphView message handlers
void CGraphView::AddGraphFromFile(CString path, CString fn, CGraph *graphs, int mode, bool write_undo)
{
	CGraphDoc* pDoc = GetDocument();
	CFile cf;
	CFileException ex;
	if (!cf.Open(path, CFile::modeRead, &ex))
	{
		char buf[256];
		char* bbb = new char[fn.GetLength()];
		for (int i = 0; i < fn.GetLength(); i++) bbb[i] = fn[i];
		sprintf_s(buf, "Can't open file %s ,error = %u\n", bbb, ex.m_cause);
		delete[]bbb;
		::MessageBox(NULL, buf, NULL, MB_OK);
	}
	else
	{
		CString f_name = fn;
		pDoc->SetTitle(f_name);
		int f_mode = mode;

		unsigned long int size = (unsigned long int)cf.GetLength();
		char* buf = new char[size + 1];
		cf.Read(buf, size);
		buf[size] = 0;
		cf.Close();

		unsigned long int kol = 0;
		unsigned long int k0 = 0;
		for (int i = 0; i < formats[f_mode - 1].skip; i++)
		{
			while (!(buf[k0] == 13 && buf[k0 + 1] == 10) && k0 + 1 < size)
			{
				k0++;
			}
			k0 += 2;
		}
		
		if (buf[k0] == '-' || (buf[k0] >= '0' && buf[k0] <= '9') || buf[k0] == '+' || buf[k0] == dec_separator)
		{
		} //no axis names info
		else
		{
			k0 += GetAxisNames(&buf[k0], size);
		}
		for (unsigned long int i = k0; i < size; i++)
		{
			if (buf[i] == dec_separator || (buf[i] >= '0' && buf[i] <= '9'))
			{
				kol++;
				i += GetLengthDigital(&buf[i], dec_separator) - 1;
			}
		}
		int kol_div = formats[f_mode - 1].number_N;
		for (int i = 0; i < formats[f_mode - 1].number_N; i++)
		{
			if (formats[f_mode - 1].number_type[i] == 'e') kol_div--;
		}
		kol /= kol_div;

		double** x, ** y;
		int index_max = 0;
		for (int j = 0; j < formats[f_mode - 1].number_N; j++)
		{
			for (int k = 0; k < formats[f_mode - 1].graph_N[j]; k++)
			{
				if (formats[f_mode - 1].graph_index[j][k] > index_max) index_max = formats[f_mode - 1].graph_index[j][k];
			}
		}
		index_max++;
		x = new double* [index_max];
		y = new double* [index_max];
		for (int i = 0; i < index_max; i++)
		{
			x[i] = new double[kol];
			y[i] = new double[kol];
		}

		unsigned long int k = k0;
		unsigned long int j = 0;
		bool size_read = false;
		int number_cur = 0;
		while (k < size && j < kol)
		{
			if (buf[k] == '-' || buf[k] == dec_separator || (buf[k] >= '0' && buf[k] <= '9'))
			{
				double data = GetDigitalFromString((char*)&buf[k], dec_separator);
				k += GetLengthDigital((char*)&buf[k], dec_separator);
				if (formats[f_mode - 1].number_type[number_cur] == 'x')
				{
					for (int i = 0; i < formats[f_mode - 1].graph_N[number_cur]; i++)
					{
						x[formats[f_mode - 1].graph_index[number_cur][i]][j] = data;
					}
				}
				if (formats[f_mode - 1].number_type[number_cur] == 'y')
				{
					for (int i = 0; i < formats[f_mode - 1].graph_N[number_cur]; i++)
					{
						y[formats[f_mode - 1].graph_index[number_cur][i]][j] = data;
					}
				}
				number_cur++;
				if (number_cur >= formats[f_mode - 1].number_N)
				{
					number_cur = 0;
					j++;
				}
			}
			if (formats[f_mode - 1].number_type[number_cur] == 'e')
			{
				while (buf[k] == ' '||buf[k]=='	') k++;
				double mult = 1;
				if (buf[k] == 'd') mult = 1e-1;
				if (buf[k] == 'c') mult = 1e-2;
				if (buf[k] == 'm') mult = 1e-3;
				if (buf[k] == 'u') mult = 1e-6;
				if (buf[k] == 'n') mult = 1e-9;
				if (buf[k] == 'p') mult = 1e-12;
				if (buf[k] == 'f') mult = 1e-15;
				if (buf[k] == 'a') mult = 1e-18;
				if (buf[k] == 'z') mult = 1e-21;
				if (buf[k] == 'y') mult = 1e-24;
				if (buf[k] == 'h') mult = 1e2;
				if (buf[k] == 'k') mult = 1e3;
				if (buf[k] == 'M') mult = 1e6;
				if (buf[k] == 'G') mult = 1e9;
				if (buf[k] == 'T') mult = 1e12;
				if (buf[k] == 'P') mult = 1e15;
				if (buf[k] == 'E') mult = 1e18;
				if (buf[k] == 'Z') mult = 1e21;
				if (buf[k] == 'Y') mult = 1e24;
				if (number_cur > 0)
				{
					if (formats[f_mode - 1].number_type[number_cur-1] == 'x')
					{
						for (int i = 0; i < formats[f_mode - 1].graph_N[number_cur-1]; i++)
						{
							x[formats[f_mode - 1].graph_index[number_cur - 1][i]][j] *= mult;
						}
					}
					if (formats[f_mode - 1].number_type[number_cur-1] == 'y')
					{
						for (int i = 0; i < formats[f_mode - 1].graph_N[number_cur-1]; i++)
						{
							y[formats[f_mode - 1].graph_index[number_cur - 1][i]][j] *= mult;
						}
					}
				}
				number_cur++;
				if (number_cur >= formats[f_mode - 1].number_N)
				{
					number_cur = 0;
					j++;
				}
			}
			if (k + 5 < size)
			{
				if (buf[k] == '/' && buf[k + 1] == 'E' && buf[k + 2] == 'O' && buf[k + 3] == 'G' && buf[k + 4] == '/')
				{
					k += 6;
					for (int i = 0; i < index_max; i++)
					{
						graphs->AddData(x[i], y[i], j, "aaa");
						graphs[0][graphs->GetNLast()]->SetAppData(def_app_var_min, def_app_var_max, def_app_var_val, def_app_var_N, def_app_eq, def_poly_app);
					}
					j = 0;
					k = ReadGraphData(buf, k, size, index_max, graphs);
				}
			}
			if (k + 5 < size)
			{
				if (buf[k] == '/' && buf[k + 1] == 'A' && buf[k + 2] == 'P' && buf[k + 3] == 'P' && buf[k + 4] == '/') //old verison
				{
					while (!(buf[k] == 13 && buf[k + 1] == 10))
					{
						k++;
					}
					k += 2;
				}
				if (buf[k] == '/' && buf[k + 1] == 'A' && buf[k + 2] == 'P' && buf[k + 3] == 'R' && buf[k + 4] == '/')
				{
					k += 6;
					k = ReadAppData(buf, k, size, graphs);
				}
			}
			if (k + 5 < size)
			{
				if (buf[k] == '/' && buf[k + 1] == 'A' && buf[k + 2] == 'P' && buf[k + 3] == 'L' && buf[k + 4] == '/')
				{
					k += 6;
					k = ReadAplData(buf, k, size, graphs);
				}
			}
			if (k + 3 < size)
			{
				if (buf[k] == '/' && buf[k + 1] == 'S' && buf[k + 2] == '/')
				{
					k += 4;
					k = ReadSizeData(buf, k);
					size_read = true;
				}
			}
			if (k + 4 < size)
			{
				if (buf[k] == '/' && buf[k + 1] == 'W' && buf[k + 2] == 'S' && buf[k + 3] == '/')
				{
					k += 5;
					k = ReadWndSizeData(buf, k);
				}
			}
			if (k + 6 < size)
			{
				if (buf[k] == '/' && buf[k + 1] == 'T' && buf[k + 2] == 'E' && buf[k + 5] == '/')
				{
					k += 8;
					k = ReadTextData(buf, k, size);
				}
			}
			k++;
		}
		if (j > 0)
		{
			for (int i = 0; i < index_max; i++)
			{
				graphs->AddData(x[i], y[i], kol, f_name);
				graphs[0][graphs->GetNLast()]->SetAppData(def_app_var_min, def_app_var_max, def_app_var_val, def_app_var_N, def_app_eq, def_poly_app);
			}
			cur_gr_N = graphs->GetNLast();
		}

		delete[] buf;
		for (int i = 0; i < index_max; i++)
		{
			delete[] x[i];
			delete[] y[i];
		}
		delete[] x; delete[] y;

		if (!size_read)
		{
			x_min = graphs->GetXmin();
			x_max = graphs->GetXmax();
			y_min = graphs->GetYmin();
			y_max = graphs->GetYmax();
		}
		if(write_undo) WriteUndo();
		pDoc->UpdateAllViews(NULL);
	}
}

void CGraphView::OnFileAddgraph()
{
	// TODO: Add your command handler code here
	CString f_f;
	for (int i = 0; i < formats_N; i++)
	{
		f_f += formats[i].name;
		f_f += (char)'|';
	}
	CFileDialog f(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_LONGNAMES, f_f, NULL);
	f.m_pOFN->nFilterIndex = file_mode;
	if (f.DoModal() == IDOK)
	{
		AddGraphFromFile(f.m_ofn.lpstrFile, f.GetFileName(), &graphs, f.m_pOFN->nFilterIndex, true);
	}
}


void CGraphView::OnUpdateFileAddgraph(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}

unsigned int CGraphView::ReadWndSizeData(char* buf, unsigned long int k)
{
	int rx_min = GetDigitalFromString((char*)&buf[k], '.');
	k += GetLengthDigital((char*)&buf[k], '.');
	int rx_max = GetDigitalFromString((char*)&buf[k], '.');
	k += GetLengthDigital((char*)&buf[k], '.');
	int ry_min = GetDigitalFromString((char*)&buf[k], '.');
	k += GetLengthDigital((char*)&buf[k], '.');
	int ry_max = GetDigitalFromString((char*)&buf[k], '.');
	k += GetLengthDigital((char*)&buf[k], '.');
	
	int dx = rx_max - rx_min;
	int dy = ry_max - ry_min;
	
	CRect r;
	GetWindowRect(&r);
	AfxGetMainWnd()->SetWindowPos(0, 0, 0, dx, dy, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	GetWindowRect(&r);
	AfxGetMainWnd()->SetWindowPos(0, 0, 0, dx + dx - (r.right - r.left), dy + dy - (r.bottom - r.top), SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);

	return k;
}
unsigned int CGraphView::ReadSizeData(char* buf, unsigned long int k)
{
	x_min = GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	x_max = GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	y_min = GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	y_max = GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');

	axe_fontN = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	axe_fontA = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	Ny_mark = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	Nx_mark = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');

	tol_x = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	tol_y = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	e_x = GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	e_y = GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');

	hide_y = GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	y_shift = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');

	margin_left = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	margin_right = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	margin_top = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	margin_bottom = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	return k;
}
unsigned int CGraphView::ReadTextData(char* buf, unsigned long int k0, unsigned long int size)
{
	unsigned long int k = k0;
	int text_num = 0;
	while (k + 1 < size)
	{
		if (buf[k] == '|' && buf[k + 1] == '|')
		{
			text_num++;
		}
		k++;
	}
	if (text_num == 0) return k0;
	
	if (NumText + text_num > MaxText)
	{
		text* text_t;
		text_t = new text[NumText];
		for (int i = 0; i < NumText; i++)
		{
			text_t[i] = texts[i];
		}

		delete[] texts;

		texts = new text[(NumText + text_num) * 2];
		MaxText = (NumText + text_num) * 2;

		for (int i = 0; i < NumText; i++)
		{
			texts[i] = text_t[i];
		}
		delete[] text_t;
	}

	k = k0;

	while (k + 1 < size)
	{
		if (buf[k] == '|' && buf[k + 1] == '|')
		{
			k += 2;
			texts[NumText].x = GetDigitalFromString((char*)&buf[k], '.');
			k += GetLengthDigital((char*)&buf[k], '.');
			texts[NumText].y = GetDigitalFromString((char*)&buf[k], '.');
			k += GetLengthDigital((char*)&buf[k], '.');
			texts[NumText].alpha = GetDigitalFromString((char*)&buf[k], '.');
			k += GetLengthDigital((char*)&buf[k], '.');
			texts[NumText].size = GetDigitalFromString((char*)&buf[k], '.');
			k += GetLengthDigital((char*)&buf[k], '.');
			texts[NumText].shade = GetDigitalFromString((char*)&buf[k], '.');
			k += GetLengthDigital((char*)&buf[k], '.');
			int r = GetDigitalFromString((char*)&buf[k], '.');
			k += GetLengthDigital((char*)&buf[k], '.');
			int g = GetDigitalFromString((char*)&buf[k], '.');
			k += GetLengthDigital((char*)&buf[k], '.');
			int b = GetDigitalFromString((char*)&buf[k], '.');
			k += GetLengthDigital((char*)&buf[k], '.');
			texts[NumText].col = RGB(r, g, b);
			NumText++;
			k += 1;
		}
		else texts[NumText].txt += buf[k];
		k++;
	}
	return k;
}
unsigned int CGraphView::ReadAppData(char* buf, unsigned long int k, unsigned long int size, CGraph* graphs)
{
	int col_r, col_g, col_b; COLORREF col1, col2;
	int line_width1, line_width2;
	double var_min[5], var_max[5], var_val[5];
	int var_N[5];
	CString name;

	col_r = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	col_g = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	col_b = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	col1 = RGB(col_r, col_g, col_b);

	line_width1 = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');

	col_r = (int)GetDigitalFromString((char*)&buf[k], '.');
	k += GetLengthDigital((char*)&buf[k], '.');
	col_g = (int)GetDigitalFromString((char*)&buf[k], '.');
	k += GetLengthDigital((char*)&buf[k], '.');
	col_b = (int)GetDigitalFromString((char*)&buf[k], '.');
	k += GetLengthDigital((char*)&buf[k], '.');
	col2 = RGB(col_r, col_g, col_b);

	line_width2 = (int)GetDigitalFromString((char*)&buf[k], '.');
	k += GetLengthDigital((char*)&buf[k], '.');

	for (int i = 0; i < 5; i++)
	{
		var_min[i] = GetDigitalFromString((char *)&buf[k], '.');
		k += GetLengthDigital((char *)&buf[k], '.');
	}
	for (int i = 0; i < 5; i++)
	{
		var_max[i] = GetDigitalFromString((char *)&buf[k], '.');
		k += GetLengthDigital((char *)&buf[k], '.');
	}
	for (int i = 0; i < 5; i++)
	{
		var_val[i] = GetDigitalFromString((char *)&buf[k], '.');
		k += GetLengthDigital((char *)&buf[k], '.');
	}
	for (int i = 0; i < 5; i++)
	{
		var_N[i] = (int)GetDigitalFromString((char *)&buf[k], '.');
		k += GetLengthDigital((char *)&buf[k], '.');
	}

	while (k < size + 1 && !(buf[k] == 13 && buf[k + 1] == 10))
	{
		name += buf[k];
		k++;
	}

	graphs[0][cur_gr_N]->app_col[0] = col1;
	graphs[0][cur_gr_N]->app_col[1] = col2;
	graphs[0][cur_gr_N]->app_line_width[0] = line_width1;
	graphs[0][cur_gr_N]->app_line_width[1] = line_width2;
	
	for (int i = 0; i<5; i++)
	{
		graphs[0][cur_gr_N]->app_var_min[i] = var_min[i];
		graphs[0][cur_gr_N]->app_var_max[i] = var_max[i];
		graphs[0][cur_gr_N]->app_var_val[i] = var_val[i];
		graphs[0][cur_gr_N]->app_var_N[i] = var_N[i];
	}
	graphs[0][cur_gr_N]->app_eq = name;
	return k;
}
unsigned int CGraphView::ReadAplData(char* buf, unsigned long int k, unsigned long int size, CGraph* graphs)
{
	double apl_data[10];

	for (int i = 0; i < 10; i++)
	{
		apl_data[i] = GetDigitalFromString((char*)&buf[k], '.');
		k += GetLengthDigital((char*)&buf[k], '.');
	}
	for (int i = 0; i < 10; i++)
	{
		graphs[0][cur_gr_N]->poly_fit[i] = apl_data[i];
	}
	return k;
}
unsigned int CGraphView::ReadGraphData(char* buf, unsigned long int k, unsigned long int size, int index_max, CGraph* graphs)
{
	int col_r, col_g, col_b;
	COLORREF col;
	int line_width, marker;
	CString name;

	col_r = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	col_g = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	col_b = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	col = RGB(col_r, col_g, col_b);

	line_width = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	marker = (int)GetDigitalFromString((char *)&buf[k], '.');
	k += GetLengthDigital((char *)&buf[k], '.');
	k++;

	while (k < size + 1 && !(buf[k] == 13 && buf[k + 1] == 10))
	{
		name += buf[k];
		k++;
	}

	cur_gr_N = graphs[0].GetNLast();
	/*graphs[cur_gr_N]->col = col;
	graphs[cur_gr_N]->line_width = line_width;
	graphs[cur_gr_N]->marker = marker;
	graphs[cur_gr_N]->name = name;*/
	for (int i = 0; i < index_max; i++)
	{
		graphs[0][cur_gr_N - i]->col = col;
		graphs[0][cur_gr_N - i]->line_width = line_width;
		graphs[0][cur_gr_N - i]->marker = marker;
		graphs[0][cur_gr_N - i]->name = name;
	}
	/*
	if (f_mode == 3)
	{
		graphs[cur_gr_N-2]->col = col;
		graphs[cur_gr_N-2]->line_width = line_width;
		graphs[cur_gr_N-2]->marker = marker;
		graphs[cur_gr_N-2]->name = name;
	}*/
	return k;
}
int CGraphView::GetAxisNames(char* buf, unsigned long int size)
{
	unsigned long int k = 1;
	unsigned int k_sep[6] = { 0, 0, 0, 0, 0, 0 };
	int sep_type[6] = { 0, 0, 0, 0, 0, 0 };
	//0 - not found, 1 - found once, 2 - found mult
	while (k < size - 1 && !(buf[k] == 13 && buf[k + 1] == 10))
	{//look for x / y separator in the first string
		if (buf[k] == '|')
		{
			if (sep_type[0] == 0)
			{
				k_sep[0] = k;
				sep_type[0] = 1;
			}
			else sep_type[0] = 2;
		}
		if (buf[k] == '	')
		{
			if (sep_type[1] == 0)
			{
				k_sep[1] = k;
				sep_type[1] = 1;
			}
			else sep_type[1] = 2;
		}
		if (buf[k] == ';')
		{
			if (sep_type[2] == 0)
			{
				k_sep[2] = k;
				sep_type[2] = 1;
			}
			else sep_type[2] = 2;
		}
		if (buf[k] == '/')
		{
			if (sep_type[3] == 0)
			{
				k_sep[3] = k;
				sep_type[3] = 1;
			}
			else sep_type[3] = 2;
		}
		if (buf[k] == ',')
		{
			if (sep_type[4] == 0)
			{
				k_sep[4] = k;
				sep_type[4] = 1;
			}
			else sep_type[4] = 2;
		}
		if (buf[k] == ' ')
		{
			if (sep_type[5] == 0)
			{
				k_sep[5] = k;
				sep_type[5] = 1;
			}
		}
		k++;
	}
	for (int i = 0; i < 6; i++)
	{
		if (sep_type[i] == 1)
		{
			char* axe_x = new char[k_sep[i] + 1];
			char *axe_y = new char[k - k_sep[i] - 1];
			
			for (unsigned int j = 0; j < k_sep[i]; j++)
			{
				axe_x[j] = buf[j];
			}
			if (axe_x[k_sep[i] - 1] == ' ') axe_x[k_sep[i] - 1] = 0;
			else axe_x[k_sep[i]] = 0;
			x_axis = axe_x;

			int d = 0; if (buf[k_sep[i] + 1] == ' ') d++;
			for (unsigned int j = 0; j < k - k_sep[i] - 1 - d; j++)
			{
				axe_y[j] = buf[k_sep[i] + j + 1 + d];
			}
			axe_y[k - k_sep[i] - 2] = 0;
			y_axis = axe_y;

			delete[] axe_x; delete[] axe_y;

			return k + 2;
		}
	}
	return 0;
}
void CGraphView::Draw_Text(CDC* pDC, bool save_eps, ns_creeps::CreEPS* eps)
{
	CFont *old = 0;
	CRect r; GetClientRect(&r);
	if (!save_eps)
	{
		int oldmode=pDC->SetBkMode(TRANSPARENT);
		int oldal = pDC->SetTextAlign(TA_BASELINE | TA_LEFT);
		for (int i = 0; i < NumText; i++)
		{
			CFont font;
			font.CreateFont(texts[i].size, 0, texts[i].alpha * 10, texts[i].alpha * 10, FW_BOLD, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Times New Roman");
			if (i == 0) old = pDC->SelectObject(&font);
			else pDC->SelectObject(&font);

			if (texts[i].shade)
			{
				pDC->SetTextColor(RGB(255, 255, 255));
				pDC->TextOutA(texts[i].x - 2, texts[i].y, texts[i].txt);
				pDC->TextOutA(texts[i].x + 2, texts[i].y, texts[i].txt);
				pDC->TextOutA(texts[i].x, texts[i].y - 2, texts[i].txt);
				pDC->TextOutA(texts[i].x, texts[i].y + 2, texts[i].txt);
			}
			pDC->SetTextColor(texts[i].col);
			pDC->TextOutA(texts[i].x, texts[i].y, texts[i].txt);
			
			if (i == NumText - 1) pDC->SelectObject(old);
			DeleteObject(font);
		}
		pDC->SetBkMode(oldmode);
		pDC->SetTextAlign(oldal);
	}
	else
	{
		for (int i = 0; i < NumText; i++)
		{
			if (texts[i].shade)
			{
				eps->print(texts[i].x - 1, r.bottom - texts[i].y, texts[i].alpha, texts[i].txt, ns_creeps::CAtTextAlignment(ns_creeps::CAt::LEFT | ns_creeps::CAt::BASELINE) | ns_creeps::CAtFont("Times-Bold", eps_scale * texts[i].size) | ns_creeps::CAtColor(1, 1, 1));
				eps->print(texts[i].x + 1, r.bottom - texts[i].y, texts[i].alpha, texts[i].txt, ns_creeps::CAtTextAlignment(ns_creeps::CAt::LEFT | ns_creeps::CAt::BASELINE) | ns_creeps::CAtFont("Times-Bold", eps_scale * texts[i].size) | ns_creeps::CAtColor(1, 1, 1));
				eps->print(texts[i].x, r.bottom - texts[i].y-1, texts[i].alpha, texts[i].txt, ns_creeps::CAtTextAlignment(ns_creeps::CAt::LEFT | ns_creeps::CAt::BASELINE) | ns_creeps::CAtFont("Times-Bold", eps_scale * texts[i].size) | ns_creeps::CAtColor(1, 1, 1));
				eps->print(texts[i].x, r.bottom - texts[i].y+1, texts[i].alpha, texts[i].txt, ns_creeps::CAtTextAlignment(ns_creeps::CAt::LEFT | ns_creeps::CAt::BASELINE) | ns_creeps::CAtFont("Times-Bold", eps_scale * texts[i].size) | ns_creeps::CAtColor(1, 1, 1));
			}
			eps->print(texts[i].x, r.bottom-texts[i].y, texts[i].alpha, texts[i].txt, ns_creeps::CAtTextAlignment(ns_creeps::CAt::LEFT | ns_creeps::CAt::BASELINE) | ns_creeps::CAtFont("Times-Bold", eps_scale * texts[i].size) | ns_creeps::CAtColor(GetRValue(texts[i].col)/255.0, GetGValue(texts[i].col) / 255.0, GetBValue(texts[i].col) / 255.0));
		}
	}
}
void CGraphView::DrawAxis(CDC *pDC, bool save_eps, ns_creeps::CreEPS* eps)
{
	RECT r; GetClientRect(&r);
	if (!polar_view)
	{
		CFont fontN, * old = 0;
		if (!save_eps)
		{
			//x axis
			pDC->MoveTo(margin_left, r.bottom - margin_bottom);
			pDC->LineTo(r.right - 3 - margin_right + 17, r.bottom - margin_bottom);
			pDC->LineTo(r.right - 7 - margin_right + 17, r.bottom - margin_bottom + 5);
			pDC->MoveTo(r.right - 3 - margin_right + 17, r.bottom - margin_bottom);
			pDC->LineTo(r.right - 7 - margin_right + 17, r.bottom - margin_bottom - 5);
			//y axis
			pDC->MoveTo(margin_left, r.bottom - margin_bottom);
			pDC->LineTo(margin_left, margin_top - 10);
			pDC->LineTo(margin_left - 5, margin_top - 5);
			pDC->MoveTo(margin_left, margin_top - 10);
			pDC->LineTo(margin_left + 5, margin_top - 5);

			fontN.CreateFont(axe_fontN, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Times New Roman");
			old = pDC->SelectObject(&fontN);
		}
		else
		{
			eps->setAttributes(ns_creeps::CAtLineThickness(1) | ns_creeps::CAtColor(0, 0, 0));
			
			eps->line(margin_left, margin_bottom, r.right - 3 - margin_right + 17, margin_bottom);
			eps->line(r.right - 3 - margin_right + 17, margin_bottom, r.right - 7 - margin_right + 17, margin_bottom + 5);
			eps->line(r.right - 3 - margin_right + 17, margin_bottom, r.right - 7 - margin_right + 17, margin_bottom - 5);
			
			eps->line(margin_left, margin_bottom, margin_left, r.bottom - (margin_top - 10));
			eps->line(margin_left, r.bottom - (margin_top - 10), margin_left - 5, r.bottom - (margin_top - 5));
			eps->line(margin_left, r.bottom - (margin_top - 10), margin_left + 5, r.bottom - (margin_top - 5));
		}

		//y axis numbers
		int Nv = Ny_mark;
		double dval = (y_max - y_min) / (Nv - 1);
		int y;
		char buf[50];
		for (int i = 0; i < Nv; i++)
		{
			y = (int)(r.bottom - margin_bottom - axe_fontN * 0.5 - i * (double)(r.bottom - margin_bottom - margin_top - axe_fontN * 0.5) / (Nv - 1));

			if (!hide_y)
			{
				ValToStr(buf, 50, tol_y, e_y, y_min + i * dval);
				CRect rec;
				rec.top = y - axe_fontN / 2;
				rec.bottom = r.bottom;
				rec.left = 0;
				rec.right = margin_left - 8;
				if (!save_eps)
				{
					pDC->DrawText(buf, strlen(buf), rec, DT_RIGHT);
				}
				else
				{
					eps->print(margin_left - axe_fontN/2, r.bottom - y, buf, ns_creeps::CAtTextAlignment(ns_creeps::CAt::RIGHT | ns_creeps::CAt::VCENTER) | ns_creeps::CAtFont("Times-Bold", eps_scale * axe_fontN));
				}
			}
			if (!save_eps)
			{
				pDC->MoveTo(margin_left - 5, y);
				pDC->LineTo(margin_left + 5, y);
			}
			else
			{
				eps->line(margin_left - 5, r.bottom - y, margin_left + 5, r.bottom - y);
			}

			if (show_net)
			{
				if (!save_eps)
				{
					for (int j = 0; j < (r.right - margin_left - margin_right) / 6; j++)
					{
						pDC->MoveTo(margin_left + 8 + j * 6, y);
						pDC->LineTo(margin_left + 11 + j * 6, y);
					}
				}
				else
				{
					eps->setAttributes(ns_creeps::CAtLineDash(ns_creeps::CAt::DASH, 3));
					eps->line(margin_left + 8, r.bottom - y, r.right - margin_right, r.bottom - y);
					eps->setAttributes(ns_creeps::CAtLineDash(ns_creeps::CAt::SOLID, 0));
				}
			}
		}

		//x axis numbers
		Nv = Nx_mark;
		dval = (x_max - x_min) / (Nv - 1);
		int x;
		for (int i = 0; i < Nv; i++)
		{
			x = (int)(margin_left + i * (double)(r.right - margin_left - margin_right) / (Nv - 1));
			ValToStr(buf, 50, tol_x, e_x, x_min + i * dval);
			if (!save_eps)
			{
				pDC->TextOut(x - (axe_fontN * strlen(buf)) / 4 + 2, r.bottom - margin_bottom + 5, buf);
			}
			else
			{
				eps->print(x, margin_bottom - axe_fontN/3, buf, ns_creeps::CAtTextAlignment(ns_creeps::CAt::HCENTER | ns_creeps::CAt::TOP) | ns_creeps::CAtFont("Times-Bold", eps_scale * axe_fontN));
			}

			if (i != 0)
			{
				if (!save_eps)
				{
					pDC->MoveTo(x, r.bottom - margin_bottom + 5);
					pDC->LineTo(x, r.bottom - margin_bottom - 5);
					if (show_net)
					{
						for (int j = 0; j < (r.bottom - margin_top - margin_bottom) / 6; j++)
						{
							pDC->MoveTo(x, r.bottom - margin_bottom - 5 - j * 6);
							pDC->LineTo(x, r.bottom - margin_bottom - 8 - j * 6);
						}
					}
				}
				else
				{
					eps->line(x, margin_bottom + 5, x, margin_bottom - 5);

					eps->setAttributes(ns_creeps::CAtLineDash(ns_creeps::CAt::DASH, 3));
					eps->line(x, margin_bottom + 5, x, r.bottom - margin_top);
					eps->setAttributes(ns_creeps::CAtLineDash(ns_creeps::CAt::SOLID, 0));
				}
			}
		}

		//x axis name
		CRect rec;
		rec.left = margin_left;
		rec.right = r.right - margin_right;
		rec.top = r.bottom - margin_bottom + axe_fontN + 6;
		rec.bottom = r.bottom;
		CFont font;
		if (!save_eps)
		{
			font.CreateFont(axe_fontA, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
				DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Times New Roman");
			pDC->SelectObject(&font);
			pDC->DrawText(x_axis, -1, rec, DT_CENTER | DT_WORDBREAK);
		}
		else
		{
			eps->print(0.5*(r.right - margin_right+margin_left), margin_bottom - axe_fontN-axe_fontA / 4, x_axis, ns_creeps::CAtTextAlignment(ns_creeps::CAt::HCENTER | ns_creeps::CAt::TOP) | ns_creeps::CAtFont("Times-Bold", eps_scale * axe_fontA));
		}
		//y axis name
		rec.left = 7;
		rec.right = r.right;
		rec.top = (int)((r.bottom - margin_bottom + margin_top) / 2 + (3 * 0.05 * axe_fontA) * y_axis.GetLength() - y_shift);
		rec.bottom = r.bottom;
		CFont font1;
		if (!save_eps)
		{
			font1.CreateFont(
				axe_fontA,                 // nHeight
				0,                         // nWidth
				900,                       // nEscapement
				900,                       // nOrientation
				FW_BOLD,                   // nWeight
				FALSE,                     // bItalic
				FALSE,                     // bUnderline
				0,                         // cStrikeOut
				RUSSIAN_CHARSET,           // nCharSet
				OUT_DEFAULT_PRECIS,        // nOutPrecision
				CLIP_DEFAULT_PRECIS,       // nClipPrecision
				DEFAULT_QUALITY,           // nQuality
				DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
				"Times New Roman");
			pDC->SelectObject(&font1);
			pDC->DrawText(y_axis, -1, rec, DT_TOP | DT_NOCLIP);
		}
		else
		{
			eps->print(7, 0.5*(r.bottom + margin_bottom + axe_fontN * 0.5 - margin_top), 90, y_axis, ns_creeps::CAtTextAlignment(ns_creeps::CAt::HCENTER | ns_creeps::CAt::TOP) | ns_creeps::CAtFont("Times-Bold", eps_scale * axe_fontA));
		}
		if (!save_eps)
		{
			font.DeleteObject();
			font1.DeleteObject();
			fontN.DeleteObject();
			pDC->SelectObject(old);
		}
	}
	else
	{
		int pcx = (int)(margin_left - x_min * (r.right - margin_right - margin_left) / (x_max - x_min));
		int pcy = (int)(margin_top + y_max * (r.bottom - margin_top - margin_bottom - axe_fontN * 0.5) / (y_max - y_min));
		if (!save_eps)
		{
			pDC->MoveTo(pcx, r.bottom - margin_bottom - axe_fontN / 2);
			pDC->LineTo(pcx, margin_top);
		}
		else
		{
			eps->setAttributes(ns_creeps::CAtLineThickness(1) | ns_creeps::CAtColor(0, 0, 0));
			eps->line(pcx, margin_bottom + axe_fontN/2, pcx, r.bottom - margin_top);
		}
		if (Nx_mark < 3|| Nx_mark % 2 == 0)
		{
			if (!save_eps)
			{
				pDC->MoveTo(margin_left, pcy);
				pDC->LineTo(r.right - margin_right, pcy);
			}
			else
			{
				eps->line(margin_left, r.bottom - pcy, r.right - margin_right, r.bottom - pcy);
			}
		}

		int max_el_x = max(pcx - margin_left, r.right - margin_right - pcx);
		int max_el_y = max(pcy - margin_top, r.bottom - margin_bottom - axe_fontN/2 - pcy);
		for (int i = 0; i < Ny_mark; i++)
		{
			if (!save_eps)
			{
				pDC->Arc(pcx - max_el_x + (i * max_el_x) / (Ny_mark - 1), pcy - max_el_y + (i * max_el_y) / (Ny_mark - 1),
					pcx + max_el_x - (i * max_el_x) / (Ny_mark - 1), pcy + max_el_y - (i * max_el_y) / (Ny_mark - 1), 0, 0, 0, 0);
			}
			else
			{
				eps->ellipse(pcx, r.bottom - pcy, max_el_x - (i * max_el_x) / (Ny_mark - 1), max_el_y - (i * max_el_y) / (Ny_mark - 1));
			}
		}

		for (int i = 1; i < 1 + Nx_mark/2; i++)
		{
			double dphi = pi / Nx_mark;
			double phi = 0;
			if (Nx_mark % 2 == 0)
			{
				phi = dphi * (i - 1);
			}
			else
			{
				phi = dphi / 2 + dphi * (i - 1);
			}
			double X1 = pcx + sqrt(1.0 / (1.0 / (max_el_x * max_el_x) + tan(phi) * tan(phi) / (max_el_y * max_el_y)));
			double X2 = pcx - sqrt(1.0 / (1.0 / (max_el_x * max_el_x) + tan(phi) * tan(phi) / (max_el_y * max_el_y)));
			double Y1 = pcy + max_el_y * sqrt(abs(1 - (X1 - pcx) * (X1 - pcx) / (max_el_x * max_el_x)));
			double Y2 = pcy - max_el_y * sqrt(abs(1 - (X2 - pcx) * (X2 - pcx) / (max_el_x * max_el_x)));
			if (!save_eps)
			{
				pDC->MoveTo((int)X1, (int)Y1);
				pDC->LineTo((int)X2, (int)Y2);
				pDC->MoveTo((int)X1, (int)Y2);
				pDC->LineTo((int)X2, (int)Y1);
			}
			else
			{
				eps->line(X1, r.bottom - Y1, X2, r.bottom - Y2);
				eps->line(X1, r.bottom - Y2, X2, r.bottom - Y1);
			}
		}
	}
}

int CGraphView::GetPow(double* val)
{
	int pow = 0;
	if (val[0] == 0) return pow;
	if (val[0] > 0)
	{
		while (val[0] >= 10)
		{
			val[0] = val[0] / 10;
			pow++;
		}
		while (val[0] < 1)
		{
			val[0] = val[0] * 10;
			pow--;
		}
		return pow;
	}
	if (val[0] < 0)
	{
		while (val[0] <= -10)
		{
			val[0] = val[0] / 10;
			pow++;
		}
		while (val[0] > -1)
		{
			val[0] = val[0] * 10;
			pow--;
		}
		return pow;
	}
	return 0;
}


void CGraphView::OnViewAxis()
{
	// TODO: Add your command handler code here
	CAxisDlg dlg;
	dlg.m_b = margin_bottom;
	dlg.m_t = margin_top;
	dlg.m_r = margin_right;
	dlg.m_l = margin_left;
	dlg.y_sh = y_shift;
	dlg.Yname = y_axis;
	dlg.Xname = x_axis;
	dlg.nam_size = axe_fontA;
	dlg.num_size = axe_fontN;
	dlg.nxm = Nx_mark;
	dlg.nym = Ny_mark;
	dlg.tol_x = tol_x;
	dlg.tol_y = tol_y;
	dlg.x_exp = e_x;
	dlg.y_exp = e_y;
	dlg.hide_y = hide_y;
	dlg.hide_sel = !show_marker;
	dlg.hide_net = !show_net;
	if (dlg.DoModal() == IDOK)
	{
		margin_bottom = dlg.m_b;
		margin_top = dlg.m_t;
		margin_right = dlg.m_r;
		margin_left = dlg.m_l;
		y_shift = dlg.y_sh;
		y_axis = dlg.Yname;
		x_axis = dlg.Xname;
		axe_fontA = dlg.nam_size;
		axe_fontN = dlg.num_size;
		Nx_mark = dlg.nxm;
		Ny_mark = dlg.nym;
		tol_x = dlg.tol_x;
		tol_y = dlg.tol_y;
		e_x = dlg.x_exp;
		e_y = dlg.y_exp;
		show_marker = !dlg.hide_sel;
		show_net = !dlg.hide_net;
		if (hide_y != dlg.hide_y)
		{
			if (dlg.hide_y)
			{
				margin_left -= axe_fontN * 2;
			}
			else
			{
				margin_left += axe_fontN * 2;
			}
		}
		hide_y = dlg.hide_y;
	}
	WriteUndo();
	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateViewAxis(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}


void CGraphView::OnViewWindowsize()
{
	// TODO: Add your command handler code here
	CRect r;
	GetWindowRect(&r);
	CWndSizeDlg dlg;
	dlg.dx = r.right - r.left;
	dlg.dy = r.bottom - r.top;
	if (dlg.DoModal() == IDOK)
	{
		AfxGetMainWnd()->SetWindowPos(0, 0, 0, dlg.dx, dlg.dy, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
		GetWindowRect(&r);
		AfxGetMainWnd()->SetWindowPos(0, 0, 0, dlg.dx + dlg.dx - (r.right - r.left), dlg.dy + dlg.dy - (r.bottom - r.top), SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	}
}


void CGraphView::OnUpdateViewWindowsize(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}
void CGraphView::DrawGraphMarker(CDC* pDC)
{
	if (cur_gr_N > 0 && show_marker)
	{
		if (graphs[cur_gr_N] == 0) return;

		CRect r; GetClientRect(&r);
		CPen pen, pen1, pen2, *oldpen;
		pen.CreatePen(PS_SOLID, 3, graphs[cur_gr_N]->col);
		pen1.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
		pen2.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		oldpen = pDC->SelectObject(&pen);

		pDC->MoveTo(r.right - 75, 10);
		pDC->LineTo(r.right - 25, 10);

		pDC->SelectObject(&pen1);

		pDC->MoveTo(r.right - 91, 4);
		pDC->LineTo(r.right - 80, 5);
		pDC->LineTo(r.right - 80, 15);
		pDC->LineTo(r.right - 90, 15);
		pDC->LineTo(r.right - 90, 5);

		pDC->MoveTo(r.right - 21, 4);
		pDC->LineTo(r.right - 10, 5);
		pDC->LineTo(r.right - 10, 15);
		pDC->LineTo(r.right - 20, 15);
		pDC->LineTo(r.right - 20, 5);

		pDC->SelectObject(&pen2);

		pDC->MoveTo(r.right - 89, 10);
		pDC->LineTo(r.right - 81, 10);

		pDC->MoveTo(r.right - 19, 10);
		pDC->LineTo(r.right - 11, 10);
		pDC->MoveTo(r.right - 15, 5);
		pDC->LineTo(r.right - 15, 15);

		pDC->SelectObject(oldpen);
		DeleteObject(pen);
		DeleteObject(pen1);
		DeleteObject(pen2);
	}
}

void CGraphView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CGraphDoc* pDoc = GetDocument();
	RECT r; GetClientRect(&r);
	if (addText || moveText)
	{
		CFont* old = 0;
		CClientDC dc(this);
		CSize size;
		CRect rect;

		int i0 = -1;
		for (int i = 0; i < NumText; i++)
		{
			CFont font;
			font.CreateFont(texts[i].size, 0, texts[i].alpha * 10, 0, FW_BOLD, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Times New Roman");
			if (i == 0) old = dc.SelectObject(&font);
			else dc.SelectObject(&font);

			size = dc.GetTextExtent(texts[i].txt, texts[i].txt.GetLength());
			
			double xx = point.x - texts[i].x;
			double yy = -point.y + texts[i].y;
			double xxa = xx * cos(pi * texts[i].alpha / 180.0) + yy * sin(pi * texts[i].alpha / 180.0);
			double yya = yy * cos(pi * texts[i].alpha / 180.0) - xx * sin(pi * texts[i].alpha / 180.0);
			if (xxa > 0 && xxa < size.cx && yya > 0 && yya < size.cy)
			{
				i0 = i;
				text_move_dx = xx;
				text_move_dy = yy;
				dc.SelectObject(old);
				DeleteObject(font);
				break;
			}

			if (i == NumText - 1) dc.SelectObject(old);
			DeleteObject(font);

			/*char buf[100];
			sprintf(buf, "%d  %g, %g    %d, %d   %d  %d", i0, xxa, yya, point.x, point.y, size.cx, size.cy);
			CString ss;
			ss = buf;
			::MessageBox(0, ss, 0, MB_OK);*/
		}

		if (i0 >= 0) i_text_last = i0;

		if (moveText)
		{
			i_text_move = i0;
		}
		if (addText)
		{
			CTextDlg dlg;
			if (i0 >= 0)
			{
				dlg.txt = texts[i0].txt;
				dlg.r = GetRValue(texts[i0].col);
				dlg.g = GetGValue(texts[i0].col);
				dlg.b = GetBValue(texts[i0].col);
				dlg.size = texts[i0].size;
				dlg.outl = texts[i0].shade;
				dlg.alpha = texts[i0].alpha;
			}
			else
			{
				if (NumText > 0)
				{
					dlg.txt = "";
					dlg.r = GetRValue(texts[NumText - 1].col);
					dlg.g = GetGValue(texts[NumText - 1].col);
					dlg.b = GetBValue(texts[NumText - 1].col);
					dlg.size = texts[NumText - 1].size;
					dlg.outl = texts[NumText - 1].shade;
					dlg.alpha = texts[NumText - 1].alpha;
				}
				else
				{
					dlg.txt = "";
					dlg.r = 0;
					dlg.g = 0;
					dlg.b = 0;
					dlg.size = 35;
					dlg.outl = true;
					dlg.alpha = 0;
				}
			}
			if (dlg.DoModal() == IDOK)
			{
				if (NumText == MaxText - 1)
				{
					text* text_t;
					text_t = new text[NumText];
					for (int i = 0; i < NumText; i++)
					{
						text_t[i] = texts[i];
					}

					delete[] texts;

					texts = new text[NumText * 2];
					MaxText = NumText * 2;

					for (int i = 0; i < NumText; i++)
					{
						texts[i] = text_t[i];
					}
					delete[] text_t;
				}
				
				if (i0 >= 0)
				{
					texts[i0].txt = dlg.txt;
					texts[i0].col = RGB(dlg.r, dlg.g, dlg.b);
					texts[i0].alpha = dlg.alpha;
					texts[i0].size = dlg.size;
					texts[i0].shade = dlg.outl;
				}
				else
				{
					texts[NumText].txt = dlg.txt;
					texts[NumText].col = RGB(dlg.r, dlg.g, dlg.b);
					texts[NumText].alpha = dlg.alpha;
					texts[NumText].size = dlg.size;
					texts[NumText].shade = dlg.outl;
					texts[NumText].x = point.x;
					texts[NumText].y = point.y;
					i_text_last = NumText;
					NumText++;
				}
				WriteUndo();
				pDoc->UpdateAllViews(0);
			}
		}
	}
	else
	{
		if (point.x >= r.right - 90 && point.x <= r.right - 80 && point.y >= 5 && point.y <= 15)
		{
			if (cur_gr_N > 1) cur_gr_N--;
			if (graphs[cur_gr_N] != 0) pDoc->SetTitle(graphs[cur_gr_N]->name);
			pDoc->UpdateAllViews(0);
			return;
		}
		if (point.x >= r.right - 20 && point.x <= r.right - 10 && point.y >= 5 && point.y <= 15)
		{
			if (cur_gr_N < graphs.GetNLast()) cur_gr_N++;
			if (graphs[cur_gr_N] != 0) pDoc->SetTitle(graphs[cur_gr_N]->name);
			pDoc->UpdateAllViews(0);
			return;
		}
		if (calc_integral)
		{
			if (!calc_integral_line)
			{
				calc_integral_line = true;
				calc_integral_x_first = point.x;
				DrawIntegralLine(point.x);

				RECT rec;
				rec.right = r.right - margin_right;
				rec.bottom = point.y + 1;
				rec.left = point.x;
				rec.top = point.y;
				ClientToScreen(&rec);
				ClipCursor(&rec);
			}
			else
			{
				calc_integral_line = false;
				DrawIntegralLine(calc_integral_x_first);
			}
		}
		if (mouse_flag == 0)
		{
			if (point.x >= r.right || point.y >= r.bottom) return;

			px_click = point.x; py_click = point.y;
			px_prev = px_click; py_prev = py_click;

			if (!calc_integral_line)
			{
				RECT rec;
				rec.right = r.right;
				rec.bottom = r.bottom;
				rec.left = px_click;
				rec.top = py_click;
				ClientToScreen(&rec);
				ClipCursor(&rec);
			}

			mouse_flag = 1; return;
		}
		if (mouse_flag == 1)
		{
			ClipCursor(NULL);
			DrawClickRect(px_click, py_click, point.x, point.y);
			mouse_flag = 0;
		}
	}
	CView::OnLButtonDown(nFlags, point);
}
void CGraphView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	margin_bottom += axe_fontN / 2;
	RECT r; GetClientRect(&r);
	double x_max00 = (point.x - margin_left) * (x_max - x_min) / (r.right - margin_left - margin_right) + x_min;
	double y_min00 = (margin_top - point.y) * (y_max - y_min) / (r.bottom - margin_bottom - margin_top) + y_max;
	char buf[40];

	CDC* hdc = GetDC();
	COLORREF prevcol;
	//COLORREF color = RGB(0, 0, 250);
	prevcol = hdc->SetTextColor(meas_text_col);
	CFont font, * oldfont;
	int font_H = meas_text_size;//(int)(axe_fontN * 0.6);
	font.CreateFont(font_H, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Times New Roman");
	oldfont = hdc->SelectObject(&font);

	if (mouse_flag == 0)
	{
		if (edit_graph)
		{
			edit_graph_rbtn = true;
			edit_graph_prevX = point.x;
			edit_graph_prevY = point.y;
		}
		else
		{
			CString str = "(";
			ValToStr(buf, 40, tol_x, e_x, x_max00);
			str += buf;
			str += ", ";
			ValToStr(buf, 40, tol_y, e_y, y_min00);
			str += buf;
			str += ")";
			CPen pen, * oldpen;
			//pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 250));
			pen.CreatePen(PS_SOLID, 2, meas_line_col);
			oldpen = hdc->SelectObject(&pen);
			hdc->MoveTo(point.x - 5, point.y - 4);
			hdc->LineTo(point.x + 5, point.y - 4);
			hdc->LineTo(point.x, point.y + 4);
			hdc->LineTo(point.x - 5, point.y - 4);
			hdc->TextOut(point.x + 6, point.y - 12, str);
			hdc->SelectObject(oldpen);
			DeleteObject(pen);
		}
	}
	if (mouse_flag == 1)
	{
		ClipCursor(NULL);
		mouse_flag = 0;

		double x_min00 = (px_click - margin_left) * (x_max - x_min) / (r.right - margin_left - margin_right) + x_min;
		double y_max00 = (margin_top - py_click) * (y_max - y_min) / (r.bottom - margin_bottom - margin_top) + y_max;

		if (!(px_click == point.x || py_click == point.y))
		{
			DrawClickRect(px_click, py_click, point.x, point.y);
			x_min = x_min00; x_max = x_max00;
			y_min = y_min00; y_max = y_max00;
			CGraphDoc* pDoc = GetDocument();
			pDoc->UpdateAllViews(0);
		}
		else
		{
			if (px_click == point.x && py_click != point.y)
			{
				ValToStr(buf, 40, tol_y, e_y, y_max00 - y_min00);
				CRect rec;
				rec.top = (point.y + py_click - font_H) / 2;
				rec.bottom = rec.top + font_H + 10;
				rec.left = point.x + 2;
				rec.right = r.right;
				hdc->DrawText(buf, rec, DT_LEFT);
			}
			if (py_click == point.y && px_click != point.x)
			{
				if (calc_integral_line)
				{
					calc_integral_line = false;
					DrawIntegralLine(point.x);

					double x1int = (calc_integral_x_first - margin_left) * (x_max - x_min) / (r.right - margin_left - margin_right) + x_min;
					double x2int = (point.x - margin_left) * (x_max - x_min) / (r.right - margin_left - margin_right) + x_min;
					double val = GetIntegral(x1int, x2int, cur_gr_N);

					//COLORREF color = RGB(0, 255, 0);
					char buf[40];
					snprintf(buf, 40, "%g", val);
					COLORREF prevcol = hdc->SetTextColor(meas_text_col);
					CRect rec;
					rec.top = point.y - font_H - 2;
					rec.bottom = rec.top + font_H + 10;
					rec.left = calc_integral_x_first;
					rec.right = point.x;
					hdc->DrawText(buf, rec, DT_CENTER);
					hdc->SetTextColor(prevcol);
				}
				else
				{
					ValToStr(buf, 40, tol_x, e_x, x_max00 - x_min00);
					CRect rec;
					rec.top = point.y - font_H - 2;
					rec.bottom = rec.top + font_H + 10;
					rec.left = px_click;
					rec.right = point.x;
					hdc->DrawText(buf, rec, DT_CENTER);
				}
			}
		}
	}

	hdc->SetTextColor(prevcol);
	hdc->SelectObject(oldfont);
	ReleaseDC(hdc);


	margin_bottom -= axe_fontN/2;
	CView::OnRButtonDown(nFlags, point);
}


void CGraphView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (edit_graph_rbtn)
	{
		margin_bottom += axe_fontN/2;

		RECT r; GetClientRect(&r);
		double x_prev = (edit_graph_prevX - margin_left) * (x_max - x_min) / (r.right - margin_left - margin_right) + x_min;
		double y_prev = (margin_top - edit_graph_prevY) * (y_max - y_min) / (r.bottom - margin_bottom - margin_top) + y_max;
		double x_cur = (point.x - margin_left) * (x_max - x_min) / (r.right - margin_left - margin_right) + x_min;
		double y_cur = (margin_top - point.y) * (y_max - y_min) / (r.bottom - margin_bottom - margin_top) + y_max;

		for (unsigned int i = 0; i < graphs[cur_gr_N]->length; i++)
		{
			if (graphs[cur_gr_N]->X[i] >= min(x_prev, x_cur) && graphs[cur_gr_N]->X[i] <= max(x_prev, x_cur))
			{
				graphs[cur_gr_N]->Y[i] = y_prev + (y_cur - y_prev) * (graphs[cur_gr_N]->X[i] - x_prev) / (x_cur - x_prev);
			}
		}

		edit_graph_prevX = point.x;
		edit_graph_prevY = point.y;
		margin_bottom -= axe_fontN/2;
	}
	if (mouse_flag == 1)
	{
		DrawClickRect(px_click, py_click, px_prev, py_prev);
		px_prev = point.x; py_prev = point.y;
		DrawClickRect(px_click, py_click, px_prev, py_prev);
	}
	if (calc_integral)
	{
		if (calc_integral_x_last > 0)
		{
			DrawIntegralLine(calc_integral_x_last);
		}
		calc_integral_x_last = point.x;
		DrawIntegralLine(point.x);
	}

	CView::OnMouseMove(nFlags, point);
}


BOOL CGraphView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	return false;
}


void CGraphView::OnEditRemovecurrent()
{
	// TODO: Add your command handler code here
	graphs.RemoveGraph(cur_gr_N);
	graphs.Renumber(0);
	if (graphs[cur_gr_N] == 0)
	{
		cur_gr_N--;
	}
	CGraphDoc* pDoc = GetDocument();
	if (graphs[cur_gr_N] != 0) pDoc->SetTitle(graphs[cur_gr_N]->name);
	WriteUndo();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateEditRemovecurrent(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnDefaultsize()
{
	// TODO: Add your command handler code here
	if (polar_view)
	{
		double size = graphs.GetPolarSize(polar_deg);
		x_min = -size;
		x_max = size;
		y_min = -size;
		y_max = size;
	}
	else
	{
		x_min = graphs.GetXmin();
		x_max = graphs.GetXmax();
		y_min = graphs.GetYmin();
		y_max = graphs.GetYmax();
	}
	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateDefaultsize(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnViewGraph()
{
	// TODO: Add your command handler code here
	CGraphDlg dlg;
	dlg.graph = &graphs;
	CGraphDoc* pDoc = GetDocument();
	dlg.pDoc = pDoc;
	dlg.gr_cur = cur_gr_N;
	if (dlg.DoModal() == IDOK)
	{
		cur_gr_N = dlg.gr_cur;
	}
	WriteUndo();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateViewGraph(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnViewSize()
{
	// TODO: Add your command handler code here
	CSizeDlg dlg;
	dlg.x_min = x_min;
	dlg.x_max = x_max;
	dlg.y_min = y_min;
	dlg.y_max = y_max;
	if (dlg.DoModal() == IDOK)
	{
		y_max = dlg.y_max;
		y_min = dlg.y_min;
		x_max = dlg.x_max;
		x_min = dlg.x_min;
	}
	WriteUndo();
	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateViewSize(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}

void CGraphView::DrawClickRect(int x_cl, int y_cl, int px, int py)
{
	if (px == x_cl && py == y_cl) return;

	CDC *hdc = GetDC();
	CPen *oldpen;
	COLORREF col = RGB(255 - GetRValue(meas_line_col), 255 - GetGValue(meas_line_col), 255 - GetBValue(meas_line_col));
	CPen pen;
	pen.CreatePen(PS_SOLID, meas_line_w, col);
	oldpen = hdc->SelectObject(&pen);
	int oldmode = hdc->SetROP2(R2_XORPEN);

	if (py == y_cl)
	{
		hdc->MoveTo(px, py);
		hdc->LineTo(x_cl, py);

		hdc->LineTo(x_cl + 5, py + 5);
		hdc->MoveTo(x_cl, py);
		hdc->LineTo(x_cl + 5, py - 5);
		hdc->MoveTo(px, py);
		hdc->LineTo(px - 5, py + 5);
		hdc->MoveTo(px, py);
		hdc->LineTo(px - 5, py - 5);
	}
	if (px == x_cl)
	{
		hdc->MoveTo(px, py);
		hdc->LineTo(px, y_cl);

		hdc->LineTo(px + 5, y_cl + 5);
		hdc->MoveTo(px, y_cl);
		hdc->LineTo(px - 5, y_cl + 5);
		hdc->MoveTo(px, py);
		hdc->LineTo(px - 5, py - 5);
		hdc->MoveTo(px, py);
		hdc->LineTo(px + 5, py - 5);
	}
	if (px != x_cl && py != y_cl)
	{
		hdc->MoveTo(px, py);
		hdc->LineTo(x_cl, py);
		hdc->LineTo(x_cl, y_cl);
		hdc->LineTo(px, y_cl);
		hdc->LineTo(px, py);
	}

	hdc->SetROP2(oldmode);
	hdc->SelectObject(oldpen);
	DeleteObject(pen);
	ReleaseDC(hdc);
}


void CGraphView::GetNFormat(char* Nformat, int tol, bool e_f)
{
	if (e_f)
	{
		Nformat[0] = '%';
		Nformat[1] = '0';
		Nformat[2] = '.';
		Nformat[3] = '0' + tol;
		Nformat[4] = 'f';
		Nformat[5] = 'e';
		Nformat[6] = '%';
		Nformat[7] = 'd';
		Nformat[8] = 0;
	}
	else
	{
		Nformat[0] = '%';
		Nformat[1] = '0';
		Nformat[2] = '.';
		Nformat[3] = '0' + tol;
		Nformat[4] = 'f';
		Nformat[5] = 0;
	}
}


void CGraphView::ValToStr(char* buf, int size_max, int tol, bool e_v, double val)
{
	double vval = val;
	int pow_val = GetPow(&vval);
	char Nformat[9];
	GetNFormat(Nformat, tol, e_v);
	if (e_v) snprintf(buf, size_max, Nformat, vval, pow_val);
	else snprintf(buf, size_max, Nformat, vval*pow(10.0, pow_val));
}


void CGraphView::OnEditTransform()
{
	// TODO: Add your command handler code here
	CTransformDlg dlg;
	dlg.x = trans_x;
	dlg.y = trans_y;
	dlg.def_size = trans_def_size;
	if (dlg.DoModal() == IDOK)
	{
		trans_x = dlg.x;
		trans_y = dlg.y;
		trans_def_size = dlg.def_size;

		graphs[cur_gr_N]->Transform(trans_x, trans_y);

		if (trans_def_size) OnDefaultsize();

		WriteUndo();

		CGraphDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(0);
	}
}


void CGraphView::OnUpdateEditTransform(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}

void CGraphView::OnFileAddfunction()
{
	// TODO: Add your command handler code here
	CAddFuncDlg dlg;
	dlg.x1 = addf_x1;
	dlg.x2 = addf_x2;
	dlg.N = addf_N;
	dlg.y = addf_y;
	if (dlg.DoModal() == IDOK)
	{
		addf_x1 = dlg.x1;
		addf_x2 = dlg.x2;
		addf_N = dlg.N;
		addf_y = dlg.y;

		CGraphDoc* pDoc = GetDocument();
		pDoc->SetTitle(addf_y);

		double *X = new double[addf_N];
		double *Y = new double[addf_N];

		char buf[100];

		double x;
		te_variable vars[] = { { "x", &x } };
		int err_y;
		te_expr *expr_y = te_compile(addf_y, vars, 1, &err_y);
		if (!expr_y)
		{
			sprintf_s(buf, "Parse error at y expression at symbol %d", err_y);
			::MessageBox(0, buf, 0, MB_OK);
			return;
		}

		for (int i = 0; i < addf_N; i++)
		{
			X[i] = addf_x1 + i*(addf_x2 - addf_x1) / (addf_N - 1);
			x = X[i];
			Y[i] = te_eval(expr_y);
		}
		te_free(expr_y);

		graphs.AddData(X, Y, addf_N, addf_y);
		cur_gr_N = graphs.GetNLast();

		delete[] X; delete[] Y;

		x_min = graphs.GetXmin();
		x_max = graphs.GetXmax();
		y_min = graphs.GetYmin();
		y_max = graphs.GetYmax();
		WriteUndo();
		pDoc->UpdateAllViews(NULL);
	}
}
void CGraphView::OnUpdateFileAddfunction(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}

void CGraphView::OnEditApproximation()
{
	// TODO: Add your command handler code here
	CGraphDoc* pDoc = GetDocument();
	CAppDlg dlg;
	dlg.graph = &graphs;
	dlg.pDoc = pDoc;
	dlg.gr_cur = cur_gr_N;
	for (int i = 0; i < 5; i++)
	{
		dlg.var_min[i] = graphs[cur_gr_N]->app_var_min[i];
		dlg.var_max[i] = graphs[cur_gr_N]->app_var_max[i];
		dlg.var_val[i] = graphs[cur_gr_N]->app_var_val[i];
		dlg.var_N[i] = graphs[cur_gr_N]->app_var_N[i];
	}
	dlg.equation = graphs[cur_gr_N]->app_eq;
	dlg.gr_x = graphs[cur_gr_N]->X;
	dlg.gr_y = graphs[cur_gr_N]->Y;
	dlg.gr_N = graphs[cur_gr_N]->length;
	dlg.iter = def_app_iter;
	if (dlg.DoModal() == IDOK)
	{
		for (int i = 0; i < 5; i++)
		{
			graphs[cur_gr_N]->app_var_min[i] = dlg.var_min[i];
			graphs[cur_gr_N]->app_var_max[i] = dlg.var_max[i];
			graphs[cur_gr_N]->app_var_val[i] = dlg.var_val[i];
			graphs[cur_gr_N]->app_var_N[i] = dlg.var_N[i];
		}
		graphs[cur_gr_N]->app_eq = dlg.equation;

		for (int i = 0; i < 5; i++)
		{
			def_app_var_min[i] = graphs[cur_gr_N]->app_var_min[i];
			def_app_var_max[i] = graphs[cur_gr_N]->app_var_max[i];
			def_app_var_val[i] = graphs[cur_gr_N]->app_var_val[i];
			def_app_var_N[i] = graphs[cur_gr_N]->app_var_N[i];
		}
		def_app_eq = graphs[cur_gr_N]->app_eq;
		def_app_iter = dlg.iter;
		graphs[cur_gr_N]->draw_app = true;
		WriteUndo();
		pDoc->UpdateAllViews(NULL);
	}
}


void CGraphView::OnUpdateEditApproximation(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}

void CGraphView::OnExportData(CString path)
{
	CFile cf;
	CFileException ex;
	if (!cf.Open(path, CFile::modeCreate | CFile::modeWrite, &ex))
	{
		char buf[256];
		sprintf(buf, "Can't open file %s ,error = %u\n", path, ex.m_cause);
		::MessageBox(NULL, buf, NULL, MB_OK);
	}
	else
	{
		CWaitCursor wait;
		char buf[1000]; int aaa;
		cf.Write(x_axis, x_axis.GetLength());
		cf.Write(" | ", 3);
		cf.Write(y_axis, y_axis.GetLength());
		cf.Write("\r\n", 2);

		int k = 1;
		while (graphs[k] != 0)
		{
			for (unsigned int i = 0; i < graphs[k]->length; i++)
			{
				aaa = sprintf(buf, "%g %g\r\n", graphs[k]->X[i], graphs[k]->Y[i]);
				cf.Write(buf, aaa);
			}
			aaa = sprintf_s(buf, "/EOG/ %d %d %d %d %d ", GetRValue(graphs[k]->col), GetGValue(graphs[k]->col), GetBValue(graphs[k]->col), graphs[k]->line_width, graphs[k]->marker);
			for (int i = 0; i < graphs[k]->name.GetLength(); i++)
				buf[aaa + i] = graphs[k]->name[i];
			buf[aaa + graphs[k]->name.GetLength()] = '\r';
			buf[aaa + graphs[k]->name.GetLength() + 1] = '\n';
			cf.Write(buf, aaa + graphs[k]->name.GetLength() + 2);
			if (graphs[k]->app_eq != "")
			{
				aaa = sprintf_s(buf, "/APR/ %d %d %d %d %d %d %d %d %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %d %d %d %d %d ",
					GetRValue(graphs[k]->app_col[0]), GetGValue(graphs[k]->app_col[0]), GetBValue(graphs[k]->app_col[0]), graphs[k]->app_line_width[0],
					GetRValue(graphs[k]->app_col[1]), GetGValue(graphs[k]->app_col[1]), GetBValue(graphs[k]->app_col[1]), graphs[k]->app_line_width[1],
					graphs[k]->app_var_min[0], graphs[k]->app_var_min[1], graphs[k]->app_var_min[2], graphs[k]->app_var_min[3], graphs[k]->app_var_min[4],
					graphs[k]->app_var_max[0], graphs[k]->app_var_max[1], graphs[k]->app_var_max[2], graphs[k]->app_var_max[3], graphs[k]->app_var_max[4],
					graphs[k]->app_var_val[0], graphs[k]->app_var_val[1], graphs[k]->app_var_val[2], graphs[k]->app_var_val[3], graphs[k]->app_var_val[4],
					graphs[k]->app_var_N[0], graphs[k]->app_var_N[1], graphs[k]->app_var_N[2], graphs[k]->app_var_N[3], graphs[k]->app_var_N[4]);
				for (int i = 0; i < graphs[k]->app_eq.GetLength(); i++)
					buf[aaa + i] = graphs[k]->app_eq[i];
				buf[aaa + graphs[k]->app_eq.GetLength()] = '\r';
				buf[aaa + graphs[k]->app_eq.GetLength() + 1] = '\n';
				cf.Write(buf, aaa + graphs[k]->app_eq.GetLength() + 2);
			}
			bool pf = false;
			for (int i = 0; i < 10; i++) if (graphs[k]->poly_fit[i] != 0) pf = true;
			if (pf)
			{
				aaa = sprintf_s(buf, "/APL/ %g %g %g %g %g %g %g %g %g %g\r\n",
					graphs[k]->poly_fit[0], graphs[k]->poly_fit[1], graphs[k]->poly_fit[2], graphs[k]->poly_fit[3], graphs[k]->poly_fit[4],
					graphs[k]->poly_fit[5], graphs[k]->poly_fit[6], graphs[k]->poly_fit[7], graphs[k]->poly_fit[8], graphs[k]->poly_fit[9]);
				cf.Write(buf, aaa);
			}
			k++;
		}

		aaa = sprintf_s(buf, "/S/ %g %g %g %g %d %d %d %d %d %d %d %d %d %d %d %d %d %d\r\n", x_min, x_max, y_min, y_max, axe_fontN, axe_fontA, Ny_mark, Nx_mark, tol_x, tol_y, e_x, e_y, hide_y, y_shift, margin_left, margin_right, margin_top, margin_bottom);
		cf.Write(buf, aaa);
		CRect r;
		GetWindowRect(&r);
		aaa = sprintf_s(buf, "/WS/ %d %d %d %d", r.left, r.right, r.top, r.bottom);
		cf.Write(buf, aaa);
		for (int i = 0; i < NumText; i++)
		{
			if (i == 0)
			{
				aaa = sprintf_s(buf, "\r\n/TEXT/");
				cf.Write(buf, aaa);
			}
			aaa = sprintf_s(buf, "\r\n%s|| %g %g %g %d %d %d %d %d", texts[i].txt, texts[i].x, texts[i].y, texts[i].alpha, texts[i].size, texts[i].shade, GetRValue(texts[i].col), GetGValue(texts[i].col), GetBValue(texts[i].col));
			cf.Write(buf, aaa);
		}
		wait.Restore();
		cf.Close();
	}
}

void CGraphView::OnFileExportdata()
{
	// TODO: Add your command handler code here
	CFileDialog f(FALSE, "txt", NULL, OFN_FILEMUSTEXIST | OFN_LONGNAMES | OFN_OVERWRITEPROMPT, "Files (*.txt)|*.txt||", NULL);
	if (f.DoModal() == IDOK)
	{
		OnExportData(f.m_ofn.lpstrFile);
	}
}


void CGraphView::OnUpdateFileExportdata(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnEditRemoveall()
{
	// TODO: Add your command handler code here
	graphs.DeleteAll();
	cur_gr_N = 0;
	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(NULL);
}


void CGraphView::OnUpdateEditRemoveall(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnFileImagetodata()
{
	// TODO: Add your command handler code here
	CString path, name;
	CFileDialog f(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_LONGNAMES, "Image |*.bmp;*.jpg;*.png;*.pcx;*.tga;*.gif|", NULL);
	if (f.DoModal() == IDOK)
	{
		path = f.GetPathName();
		name = f.GetFileName();
	}
	else return;

	corona::Image* image = corona::OpenImage(path, corona::PF_R8G8B8A8);
	if (!image)
	{
		::MessageBox(0, "Something is wrong with this file!", 0, MB_OK);
		return;
	}

	CItoGDlg dlg;
	dlg.x1 = Ix1;
	dlg.x2 = Ix2;
	dlg.y1 = Iy1;
	dlg.y2 = Iy2;
	dlg.sens = sensitivity;
	if (dlg.DoModal() == IDOK)
	{
		Ix1 = dlg.x1;
		Ix2 = dlg.x2;
		Iy1 = dlg.y1;
		Iy2 = dlg.y2;
		sensitivity = dlg.sens;
	}
	else return;

	int width = image->getWidth();
	int height = image->getHeight();

	void* pixels = image->getPixels();
	bool* is_line = new bool[width * height];

	typedef unsigned char byte;
	byte* p = (byte*)pixels;

	for (int i = 0; i < width * height; ++i)
	{
		byte red = *p++;
		byte green = *p++;
		byte blue = *p++;
		byte alpha = *p++;
		if (red + green + blue < sensitivity) is_line[i] = true;
		else is_line[i] = false;
	}

	int NN = 0;
	for (int j = 0; j < height; j++)
	{
		if (is_line[j * width])
		{
			int j0 = j;
			while (is_line[j * width])
			{
				j++;
			}
			NN++;
		}
	}
	if (NN == 0) return;

	double* x = new double[width * NN];
	double* y = new double[width * NN];

	for (int i = 0; i < width; i++)
	{
		for (int k = 0; k < NN; k++)
		{
			x[i + k * width] = Ix1 + (Ix2 - Ix1) * i / (width - 1.0);
			y[i + k * width] = 0;
		}
		int MM = 0;
		for (int j = 0; j < height; j++)
		{
			if (is_line[j * width + i])
			{
				int j0 = j;
				while (is_line[j * width + i])
				{
					j++;
					if (j == height)
					{
						j--;
						break;
					}
				}
				y[i + MM * width] = Iy2 - (Iy2 - Iy1) * (j0 + j) / (2.0 * (height - 1));
				MM++;
				if (MM == NN) break;
			}
		}
		if (MM == 0)
		{
			for (int k = 0; k < NN; k++)
			{
				y[i + k * width] = y[i - 1 + k * width];
			}
		}
		else
		{
			for (int k = MM; k < NN; k++)
			{
				y[i + k * width] = y[i + (MM - 1) * width];
			}
		}
	}
	for (int i = 0; i < NN; i++)
	{
		graphs.AddData(&x[width * i], &y[width * i], width, name);
	}
	cur_gr_N = graphs.GetNLast();

	delete[] is_line;
	CGraphDoc* pDoc = GetDocument();
	pDoc->SetTitle(name);
	WriteUndo();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateFileImagetodata(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}


void CGraphView::OnSmoothingRemovespikes()
{
	// TODO: Add your command handler code here
	int N_iter = 10;
	int OK_min = 10;
	double k_smooth = 10;

	unsigned int curL = graphs[cur_gr_N]->length;
	bool *bad_p = new bool[curL];

	for (unsigned int i = 0; i < curL; i++)
	{
		bad_p[i] = false;
	}

	double diff = 0;
	unsigned int first_ok = 0; int N_ok = 0;

	for (int i_iter = 0; i_iter < N_iter; i_iter++)
	{
		//считаем средний разборс между соседями
		diff = 0;
		for (unsigned int i = 1; i < curL; i++)
		{
			diff += abs(graphs[cur_gr_N]->Y[i] - graphs[cur_gr_N]->Y[i - 1]);
		}
		diff /= curL - 1;
		//убираем плохие точки в начале графика
		first_ok = 0; N_ok = 0;
		for (unsigned int i = 1; i < curL; i++)
		{
			if (abs(graphs[cur_gr_N]->Y[i] - graphs[cur_gr_N]->Y[i - 1]) < k_smooth * diff)
			{
				N_ok++;
			}
			else
			{
				N_ok = 0;
				first_ok = i;
			}
			if (N_ok >= OK_min)
			{
				break;
			}
		}
		for (unsigned int i = 0; i < first_ok; i++)
		{
			graphs[cur_gr_N]->Y[i] = graphs[cur_gr_N]->Y[first_ok];
		}
		//ищем плохие точки
		for (unsigned int i = 1; i < curL-1; i++)
		{
			unsigned int kl = 1;
			while (bad_p[i - kl]) kl++;
			if (abs(graphs[cur_gr_N]->Y[i] - graphs[cur_gr_N]->Y[i - kl]) + abs(graphs[cur_gr_N]->Y[i] - graphs[cur_gr_N]->Y[i + 1]) > 2 * k_smooth * diff)
			{
				bad_p[i] = true;
			}
		}
		//убираем плохие точки справа
		first_ok = 0;
		for (unsigned int i = curL - 1; i >= 0; i--)
		{
			if (!bad_p[i])
			{
				first_ok = i;
				break;
			}
		}
		for (unsigned int i = first_ok + 1; i < curL; i++)
		{
			graphs[cur_gr_N]->Y[i] = graphs[cur_gr_N]->Y[first_ok];
			bad_p[i] = false;
		}
		//убираем плохие точки
		for (unsigned int i = 1; i < curL - 1; i++)
		{
			if (bad_p[i])
			{
				int kl = 1, kr = 1;
				while (bad_p[i - kl]) kl++;
				while (bad_p[i + kr]) kr++;
				graphs[cur_gr_N]->Y[i] = 0.5*(graphs[cur_gr_N]->Y[i - kl] + graphs[cur_gr_N]->Y[i + kr]);
			}
		}
	}
	WriteUndo();
	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateSmoothingRemovespikes(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnEditCopy()
{
	// TODO: Add your command handler code here
	if (show_marker)
	{
		ClearMarker();
	}

	CWnd* pWnd = this->GetWindow(GW_HWNDFIRST);
	CBitmap 	bitmap;
	CClientDC	dc(pWnd);
	CDC 		memDC;
	CRect r;

	memDC.CreateCompatibleDC(&dc);
	GetClientRect(&r);

	bitmap.CreateCompatibleBitmap(&dc, r.Width(), r.Height());

	CBitmap* pOldBitmap = memDC.SelectObject(&bitmap);
	memDC.BitBlt(0, 0, r.Width(), r.Height(), &dc, 0, 0, SRCCOPY);

	pWnd->OpenClipboard();
	EmptyClipboard();
	SetClipboardData(CF_BITMAP, bitmap.GetSafeHandle());
	CloseClipboard();

	memDC.SelectObject(pOldBitmap);
	bitmap.Detach();

	if (show_marker)
	{
		CGraphDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(0);
	}
}


void CGraphView::OnUpdateEditCopy(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0 || NumText > 0);
}


void CGraphView::OnApproximationCustom()
{
	// TODO: Add your command handler code here
	OnEditApproximation();
}


void CGraphView::OnUpdateApproximationCustom(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnApproximationPolynomial()
{
	// TODO: Add your command handler code here
	CGraphDoc* pDoc = GetDocument();
	CPolyAppDlg dlg;
	dlg.n_app = poly_app_n;
	dlg.n = graphs[cur_gr_N]->length;
	dlg.x = graphs[cur_gr_N]->X;
	dlg.y = graphs[cur_gr_N]->Y;
	dlg.graph = &graphs;
	dlg.pDoc = pDoc;
	dlg.gr_cur = cur_gr_N;
	double poly_fit_ini[10];
	for (int i = 0; i < 10; i++)
		poly_fit_ini[i] = graphs[cur_gr_N]->poly_fit[i];
	for (int i = 0; i < 10; i++)
	{
		dlg.c_app[i] = graphs[cur_gr_N]->poly_fit[i];
	}
	if (dlg.DoModal() == IDOK)
	{
		poly_app_n = dlg.n_app;
		for (int i = 0; i < 10; i++)
		{
			graphs[cur_gr_N]->poly_fit[i] = dlg.c_app[i];
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
			graphs[cur_gr_N]->poly_fit[i] = poly_fit_ini[i];
	}
	WriteUndo();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateApproximationPolynomial(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnUpdateEditAverage(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}


void CGraphView::OnEditAverage()
{
	// TODO: Add your command handler code here
	CFolderPickerDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		CAveParamDlg dlg_ave;
		dlg_ave.Nsigma = ave_sigma_N;
		if (dlg_ave.DoModal() == IDOK)
		{
			ave_sigma_N = dlg_ave.Nsigma;
		}
		else
		{
			return;
		}
		CGraph graphs_t;
		graphs_t.Init(0);
		int n_gr = 0;

		CString folder = dlg.GetFolderPath();
		folder += "\\*";
		CFileFind finder;
		BOOL bWorking = finder.FindFile(folder);
		folder.Delete(folder.GetLength() - 1, 1);
		while (bWorking)
		{
			bWorking = finder.FindNextFile();
			// skip . and .. files
			if (!finder.IsDots())
			{
				AddGraphFromFile(folder + finder.GetFileName(), finder.GetFileName(), &graphs_t, file_mode, false);
				//n_gr++;
				//CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
				//pFrame->m_wndStatusBar.SetPaneText(0, folder + finder.GetFileName());
			}
		}
		n_gr = graphs_t.GetNLast();
		//::MessageBox(0, "loaded", 0, MB_OK);
		if (n_gr > 0)
		{
			//sorted array of all X coordinates
			int nx = graphs_t[1]->length;
			double x_min = min(graphs_t[1]->X[0], graphs_t[1]->X[graphs_t[1]->length-1]);
			double x_max = max(graphs_t[1]->X[0], graphs_t[1]->X[graphs_t[1]->length-1]);
			for (int i = 2; i <= n_gr; i++)
			{
				for (unsigned int j = 0; j < graphs_t[i]->length; j++)
				{
					if (graphs_t[i]->X[j] < x_min|| graphs_t[i]->X[j] > x_max)
					{
						nx++;
					}
				}
				x_min = min(x_min, graphs_t[i]->X[0]); x_min = min(x_min, graphs_t[i]->X[graphs_t[i]->length-1]);
				x_max = max(x_max, graphs_t[i]->X[0]); x_max = max(x_max, graphs_t[i]->X[graphs_t[i]->length-1]);
			}
			double* x = new double[nx];

			for (unsigned int j = 0; j < graphs_t[1]->length; j++)
			{
				x[j] = graphs_t[1]->X[j];
			}
			x_min = min(graphs_t[1]->X[0], graphs_t[1]->X[graphs_t[1]->length - 1]);
			x_max = max(graphs_t[1]->X[0], graphs_t[1]->X[graphs_t[1]->length - 1]);
			int cur_col = graphs_t[1]->length;
			for (int i = 2; i <= n_gr; i++)
			{
				for (unsigned int j = 0; j < graphs_t[i]->length; j++)
				{
					if (graphs_t[i]->X[j] < x_min || graphs_t[i]->X[j] > x_max)
					{
						x[cur_col] = graphs_t[i]->X[j];
						cur_col++;
					}
				}
				x_min = min(x_min, graphs_t[i]->X[0]); x_min = min(x_min, graphs_t[i]->X[graphs_t[i]->length - 1]);
				x_max = max(x_max, graphs_t[i]->X[0]); x_max = max(x_max, graphs_t[i]->X[graphs_t[i]->length - 1]);
			}
			std::sort(&x[0], &x[cur_col - 1]);
			//-------------------------
			int ny;
			double* y = new double[nx];
			for (int i = 0; i < nx; i++)
			{
				//for each X point find number of Y values
				ny = 0;
				for (int j = 1; j <= n_gr; j++)
				{
					if (x[i] >= min(graphs_t[j]->X[0], graphs_t[j]->X[graphs_t[j]->length-1]) && x[i] <= max(graphs_t[j]->X[0], graphs_t[j]->X[graphs_t[j]->length-1]))
					{
						ny++;
					}
				}
				//generate y-array
				double* y_t = new double[ny];
				int y_cur = 0;
				for (int j = 1; j <= n_gr; j++)
				{
					if (x[i] >= min(graphs_t[j]->X[0], graphs_t[j]->X[graphs_t[j]->length-1]) && x[i] <= max(graphs_t[j]->X[0], graphs_t[j]->X[graphs_t[j]->length-1]))
					{
						double dx = (graphs_t[j]->X[graphs_t[j]->length - 1] - graphs_t[j]->X[0]) / (graphs_t[j]->length - 1);
						unsigned int k_app = (int)((x[i] - graphs_t[j]->X[0]) / dx);
						int k_ex = -1;
						for (unsigned int k = max(0, k_app-1); k < min(graphs_t[j]->length - 1, k_app + 1) && k_ex==-1; k++)
						{
							if (x[i] >= min(graphs_t[j]->X[k], graphs_t[j]->X[k + 1]) && x[i] <= max(graphs_t[j]->X[k], graphs_t[j]->X[k + 1]))
							{
								k_ex = k;
							}
						}
						for (unsigned int k = max(0, k_app - 5); k < min(k_app + 5, graphs_t[j]->length - 1) && k_ex == -1; k++)
						{
							if (x[i] >= min(graphs_t[j]->X[k], graphs_t[j]->X[k + 1]) && x[i] <= max(graphs_t[j]->X[k], graphs_t[j]->X[k + 1]))
							{
								k_ex = k;
							}
						}
						for (unsigned int k = 0; k < graphs_t[j]->length - 1 && k_ex == -1; k++)
						{
							if (x[i] >= min(graphs_t[j]->X[k], graphs_t[j]->X[k + 1]) && x[i] <= max(graphs_t[j]->X[k], graphs_t[j]->X[k + 1]))
							{
								k_ex = k;
							}
						}
						double x1 = min(graphs_t[j]->X[k_ex], graphs_t[j]->X[k_ex + 1]);
						double x2 = max(graphs_t[j]->X[k_ex], graphs_t[j]->X[k_ex + 1]);
						double y1, y2;
						if (graphs_t[j]->X[k_ex] < graphs_t[j]->X[k_ex + 1])
						{
							y1 = graphs_t[j]->Y[k_ex];
							y2 = graphs_t[j]->Y[k_ex + 1];
						}
						else
						{
							y1 = graphs_t[j]->Y[k_ex + 1];
							y2 = graphs_t[j]->Y[k_ex];
						}
						y_t[y_cur] = y1 + (x[i] - x1) * (y2 - y1) / (x2 - x1);
						y_cur++;
					}
				}
				//remove bad points
				double y_ave = 0;
				bool removed = true;
				while(removed)
				{
					removed = false;
					y_ave = 0;
					for (int j = 0; j < ny; j++)
					{
						y_ave += y_t[j];
					}
					y_ave /= ny;
					double sigma = 0;
					for (int j = 0; j < ny; j++)
					{
						sigma += (y_t[j] - y_ave) * (y_t[j] - y_ave);
					}
					if (ny == 1) sigma = 0;
					else sigma /= ny - 1;
					sigma = sqrt(sigma);
					int j_max = 0;
					for (int j = 1; j < ny; j++)
					{
						if (abs(y_ave - y_t[j]) > abs(y_ave - y_t[j_max])) j_max = j;
					}

					if (abs(y_ave - y_t[j_max]) > ave_sigma_N * sigma)
					{
						y_t[j_max] = y_t[ny - 1];
						ny--;
						removed = true;
					}
				}

				y[i] = y_ave;
				delete[] y_t;
			}
			//-------------------------
			graphs.AddData(x, y, nx, "average");
			graphs[graphs.GetNLast()]->SetAppData(def_app_var_min, def_app_var_max, def_app_var_val, def_app_var_N, def_app_eq, def_poly_app);
			cur_gr_N = graphs.GetNLast();
			OnDefaultsize();

			delete[] x; delete[] y;
		}
		
		graphs_t.DeleteAll();
	}
}


void CGraphView::OnFileSettings()
{
	// TODO: Add your command handler code here
	CSettingsDlg dlg;
	dlg.f_mode = file_mode;
	dlg.deg = polar_deg;
	dlg.view_mode = view_mode;
	dlg.max_n_format = formats_N;
	dlg.EPS = eps_scale;
	dlg.move_scale = move_scale;
	if (dec_separator == '.') dlg.point_sep = true;
	else dlg.point_sep = false;

	dlg.meas_text_col = meas_text_col;
	dlg.meas_text_size = meas_text_size;
	dlg.meas_line_col = meas_line_col;
	dlg.meas_line_w = meas_line_w;

	dlg.def_dH = v_def_dH; dlg.def_H_st = v_def_H_st;
	dlg.def_dF = v_def_dF; dlg.def_F_st = v_def_F_st;
	dlg.def_dx = v_def_dx; dlg.def_x_st = v_def_x_st;
	dlg.def_n_min = v_def_n_min; dlg.def_n_max = v_def_n_max; dlg.def_n_step = v_def_n_step;

	if (dlg.DoModal() == IDOK)
	{
		file_mode = dlg.f_mode;
		if(dlg.point_sep)
			dec_separator = '.';
		else 
			dec_separator = ',';
		polar_deg = dlg.deg;
		view_mode = dlg.view_mode;
		eps_scale = dlg.EPS;
		move_scale = dlg.move_scale;

		meas_text_col = dlg.meas_text_col;
		meas_text_size = dlg.meas_text_size;
		meas_line_col = dlg.meas_line_col;
		meas_line_w = dlg.meas_line_w;

		v_def_dH = dlg.def_dH; v_def_H_st = dlg.def_H_st;
		v_def_dF = dlg.def_dF; v_def_F_st = dlg.def_F_st;
		v_def_dx = dlg.def_dx; v_def_x_st = dlg.def_x_st;
		v_def_n_min = dlg.def_n_min; v_def_n_max = dlg.def_n_max; v_def_n_step = dlg.def_n_step;
		
		CGraphDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(NULL);
	}
}


void CGraphView::OnUpdateFileSettings(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}


void CGraphView::OnSmoothingSimplespline()
{
	// TODO: Add your command handler code here
	CSplineDlg dlg;
	dlg.order = spline_order;
	dlg.iter = spline_iter;
	if (dlg.DoModal() == IDOK)
	{
		spline_iter = max(1, dlg.iter);
		spline_order = max(2, dlg.order);
		
		graphs[cur_gr_N]->Spline(spline_order, spline_iter);
		WriteUndo();
		CGraphDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(NULL);
	}
}


void CGraphView::OnUpdateSmoothingSimplespline(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnUpdateViewPolar(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
	pCmdUI->SetCheck(polar_view);
	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(NULL);
}


void CGraphView::OnViewPolar()
{
	// TODO: Add your command handler code here
	polar_view = !polar_view;
	OnDefaultsize();
}


void CGraphView::OnIntegral()
{
	// TODO: Add your command handler code here
	if (calc_integral)
	{
		DrawIntegralLine(calc_integral_x_last);
		calc_integral_x_last = 0;
	}
	calc_integral = !calc_integral;
}


void CGraphView::OnUpdateIntegral(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
	pCmdUI->SetCheck(calc_integral);
}

void CGraphView::DrawIntegralLine(int x)
{
	// TODO: Add your implementation code here.
	CDC* hdc = GetDC();
	CPen* oldpen;
	COLORREF col = RGB(255 - GetRValue(meas_line_col), 255 - GetGValue(meas_line_col), 255 - GetBValue(meas_line_col));
	CPen pen;
	pen.CreatePen(PS_SOLID, meas_line_w, col);
	oldpen = hdc->SelectObject(&pen);
	int oldmode = hdc->SetROP2(R2_XORPEN);

	RECT r; GetClientRect(&r);

	hdc->MoveTo(x, r.top + margin_top);
	hdc->LineTo(x, r.bottom - margin_bottom);

	hdc->SetROP2(oldmode);
	hdc->SelectObject(oldpen);
	DeleteObject(pen);
	ReleaseDC(hdc);
}


double CGraphView::GetIntegral(double x1int, double x2int, int N_gr)
{
	// TODO: Add your implementation code here.
	double x1, y1, x2, y2; double t;
	double sum = 0;
	for (unsigned int i = 0; i < graphs[N_gr]->length-1; i++)
	{
		x1 = graphs[N_gr]->X[i];
		y1 = graphs[N_gr]->Y[i];
		x2 = graphs[N_gr]->X[i + 1];
		y2 = graphs[N_gr]->Y[i+1];
		if (x1 > x2)
		{
			t = x1; x1 = x2; x2 = t;
			t = y1; y1 = y2; y2 = t;
		}

		if (x1int <= x1 && x2int >= x2)
		{
			sum += (x2 - x1) * 0.5 * (y2 + y1);
		}
		if (x1int > x1 && x2int >= x2 && x1int < x2)
		{
			sum += (x2 - x1int) * 0.5 * (y2 + y2 - (y2 - y1) * (x2 - x1int) / (x2 - x1));
		}
		if (x1int <= x1 && x2int > x1 && x2int < x2)
		{
			sum += (x2int - x1) * 0.5 * (y1 + y2 - (y2 - y1) * (x2 - x2int) / (x2 - x1));
		}
		if (x1int > x1 && x1int<x2 && x2int>x1 && x2int < x2)
		{
			sum += (x2int - x1int) * 0.5 * (y2 - (y2 - y1) * (x2 - x1int) / (x2 - x1) + y2 - (y2 - y1) * (x2 - x2int) / (x2 - x1));
		}
	}
	return sum;
}


void CGraphView::OnEditCombine()
{
	// TODO: Add your command handler code here
	CCombineDlg dlg;
	dlg.form = combine_str;
	if (dlg.DoModal() == IDOK)
	{
		combine_str = dlg.form;

		char buf[100];

		double y[7];
		te_variable vars[] = { { "y1", &y[0]}, {"y2", &y[1]}, {"y3", &y[2]}, {"y4", &y[3]}, {"y5", &y[4]}, {"y6", &y[5]}, {"y7", &y[6]} };
		int err;
		te_expr* expr = te_compile(combine_str, vars, 7, &err);
		
		if (!expr)
		{
			sprintf_s(buf, "Parse error at combine expression at symbol %d", err);
			::MessageBox(0, buf, 0, MB_OK);
			return;
		}
		int min_index = 7;
		for (int i = 0; i < combine_str.GetLength()-1; i++)
		{
			for (int k = 1; k <= 7; k++)
			{
				if (combine_str.GetAt(i) == 'y' && combine_str.GetAt(i + 1) == k + '0')
				{
					if (min_index > k) min_index = k;
				}
			}
		}
		if (graphs[0]->GetNLast() < min_index) min_index = 1;

		int nx = graphs[min_index]->length;
		double* x_arr = new double[nx];
		double* y_arr = new double[nx];

		for (unsigned int i = 0; i < graphs[min_index]->length; i++)
		{
			x_arr[i] = graphs[min_index]->X[i];
			y[0] = graphs[1]->Y[i];
			for (int k = 1; k < 7; k++)
			{
				if (k >= graphs[0]->GetNLast())
				{
					y[k] = 0;
				}
				else
				{
					y[k] = graphs[k + 1]->GetY(x_arr[i]);
				}
			}
			y_arr[i] = te_eval(expr);
		}
		te_free(expr);


		graphs.AddData(x_arr, y_arr, nx, "Combined");
		graphs[graphs.GetNLast()]->SetAppData(def_app_var_min, def_app_var_max, def_app_var_val, def_app_var_N, def_app_eq, def_poly_app);
		cur_gr_N = graphs.GetNLast();
		OnDefaultsize();

		WriteUndo();
		CGraphDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(0);
	}
}


void CGraphView::OnUpdateEditCombine(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(graphs[0]->GetNLast() > 1);
}

void CGraphView::OnRemoveRemoveallbutcurrent()
{
	// TODO: Add your command handler code here
	for (int i = 1; i < graphs[0]->GetNLast() + 1; i++)
	{
		if (i != cur_gr_N)
			graphs.RemoveGraph(i);
	}
	graphs.Renumber(0);
	cur_gr_N = 1;

	WriteUndo();
	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(0);
}

void CGraphView::OnUpdateRemoveRemoveallbutcurrent(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(graphs[0]->GetNLast() > 1);
}

void CGraphView::OnEditSplit()
{
	// TODO: Add your command handler code here
	CSplitDlg dlg;
	dlg.x = split_x;
	if (dlg.DoModal() == IDOK)
	{
		split_x = dlg.x;
		double max_val = graphs[cur_gr_N]->X[0], min_val = graphs[cur_gr_N]->X[0];
		for (unsigned int i = 0; i < graphs[cur_gr_N]->length - 1; i++)
		{
			if (graphs[cur_gr_N]->X[i] > max_val) max_val = graphs[cur_gr_N]->X[i];
			if (graphs[cur_gr_N]->X[i] < min_val) min_val = graphs[cur_gr_N]->X[i];
		}
		if (split_x >= max_val)
		{
			return;
		}
		if (split_x <= min_val)
		{
			return;
		}
		int i0 = 0;
		for (unsigned int i = 0; i < graphs[cur_gr_N]->length - 1; i++)
		{
			if (split_x >= min(graphs[cur_gr_N]->X[i], graphs[cur_gr_N]->X[i + 1]) &&
				split_x <= max(graphs[cur_gr_N]->X[i], graphs[cur_gr_N]->X[i + 1]))
			{
				i0 = i;
				break;
			}
		}
		double* x_arr1 = new double[i0];
		double* y_arr1 = new double[i0];
		for (int i = 0; i < i0; i++)
		{
			x_arr1[i] = graphs[cur_gr_N]->X[i];
			y_arr1[i] = graphs[cur_gr_N]->Y[i];
		}
		double* x_arr2 = new double[graphs[cur_gr_N]->length - i0];
		double* y_arr2 = new double[graphs[cur_gr_N]->length - i0];
		for (unsigned int i = 0; i < graphs[cur_gr_N]->length - i0; i++)
		{
			x_arr2[i] = graphs[cur_gr_N]->X[i0 + i];
			y_arr2[i] = graphs[cur_gr_N]->Y[i0 + i];
		}

		CString tit = graphs[cur_gr_N]->name; tit += "_1";
		graphs.AddData(x_arr1, y_arr1, i0, tit);
		int i_last = graphs.GetNLast();
		graphs[i_last]->col = graphs[cur_gr_N]->col;
		graphs[i_last]->line_width = graphs[cur_gr_N]->line_width;
		graphs[i_last]->marker = graphs[cur_gr_N]->marker;
		graphs[i_last]->app_col[0] = graphs[cur_gr_N]->app_col[0];
		graphs[i_last]->app_col[1] = graphs[cur_gr_N]->app_col[1];
		graphs[i_last]->app_line_width[0] = graphs[cur_gr_N]->app_line_width[0];
		graphs[i_last]->app_line_width[1] = graphs[cur_gr_N]->app_line_width[1];
		graphs[i_last]->SetAppData(graphs[cur_gr_N]->app_var_min, graphs[cur_gr_N]->app_var_max, graphs[cur_gr_N]->app_var_val, graphs[cur_gr_N]->app_var_N, graphs[cur_gr_N]->app_eq, graphs[cur_gr_N]->poly_fit);

		tit = graphs[cur_gr_N]->name; tit += "_2";
		graphs.AddData(x_arr2, y_arr2, graphs[cur_gr_N]->length - i0, tit);
		i_last = graphs.GetNLast();
		int R, G, B;
		if (GetRValue(graphs[cur_gr_N]->col) > 125) R = GetRValue(graphs[cur_gr_N]->col) - 70;
		else R = GetRValue(graphs[cur_gr_N]->col) + 70;
		if (GetGValue(graphs[cur_gr_N]->col) > 125) G = GetGValue(graphs[cur_gr_N]->col) - 70;
		else G = GetGValue(graphs[cur_gr_N]->col) + 70;
		if (GetBValue(graphs[cur_gr_N]->col) > 125) B = GetBValue(graphs[cur_gr_N]->col) - 70;
		else B = GetBValue(graphs[cur_gr_N]->col) + 70;
		graphs[i_last]->col = RGB(R, G, B);
		graphs[i_last]->line_width = graphs[cur_gr_N]->line_width;
		graphs[i_last]->marker = graphs[cur_gr_N]->marker;
		graphs[i_last]->app_col[0] = graphs[cur_gr_N]->app_col[0];
		graphs[i_last]->app_col[1] = graphs[cur_gr_N]->app_col[1];
		graphs[i_last]->app_line_width[0] = graphs[cur_gr_N]->app_line_width[0];
		graphs[i_last]->app_line_width[1] = graphs[cur_gr_N]->app_line_width[1];
		graphs[i_last]->SetAppData(graphs[cur_gr_N]->app_var_min, graphs[cur_gr_N]->app_var_max, graphs[cur_gr_N]->app_var_val, graphs[cur_gr_N]->app_var_N, graphs[cur_gr_N]->app_eq, graphs[cur_gr_N]->poly_fit);
		
		graphs.RemoveGraph(cur_gr_N);
		graphs.Renumber(0);

		cur_gr_N = graphs.GetNLast();
		WriteUndo();
		CGraphDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(0);
	}
}


void CGraphView::OnUpdateEditSplit(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnFileExportcurrent()
{
	// TODO: Add your command handler code here
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
			CWaitCursor wait;
			char buf[1000]; int aaa;
			
			for (unsigned int i = 0; i < graphs[cur_gr_N]->length-1; i++)
			{
				aaa = sprintf(buf, "%g %g\r\n", graphs[cur_gr_N]->X[i], graphs[cur_gr_N]->Y[i]);
				cf.Write(buf, aaa);
			}
			aaa = sprintf(buf, "%g %g", graphs[cur_gr_N]->X[graphs[cur_gr_N]->length - 1], graphs[cur_gr_N]->Y[graphs[cur_gr_N]->length - 1]);
			cf.Write(buf, aaa);
				
			wait.Restore();
			cf.Close();
		}
	}
}


void CGraphView::OnUpdateFileExportcurrent(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnRemovePoints()
{
	// TODO: Add your command handler code here
	CRemovePointsDlg dlg;
	dlg.perc = 50;
	if (dlg.DoModal() == IDOK)
	{
		CGraphDoc* pDoc = GetDocument();
		int k = 1; double P0 = 0;
		for (unsigned int i = 1; i <= graphs[cur_gr_N]->length-1; i++)
		{
			P0 += (100-dlg.perc) / 100.0;
			if (P0 >= 1)
			{
				graphs[cur_gr_N]->X[k] = graphs[cur_gr_N]->X[i];
				graphs[cur_gr_N]->Y[k] = graphs[cur_gr_N]->Y[i];
				k++;
				P0 -= 1;
			}
		}
		graphs[cur_gr_N]->X[k] = graphs[cur_gr_N]->X[graphs[cur_gr_N]->length - 1];
		graphs[cur_gr_N]->Y[k] = graphs[cur_gr_N]->Y[graphs[cur_gr_N]->length - 1];
		graphs[cur_gr_N]->length = k + 1;
		WriteUndo();
		pDoc->UpdateAllViews(0);
	}
}


void CGraphView::OnUpdateRemovePoints(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnLeftbtn()
{
	// TODO: Add your command handler code here
	CGraphDoc* pDoc = GetDocument();
	for (unsigned int i = 0; i < graphs[cur_gr_N]->length; i++)
	{
		graphs[cur_gr_N]->X[i] -= (x_max - x_min) * move_scale;
	}
	pDoc->UpdateAllViews(NULL);
}


void CGraphView::OnUpdateLeftbtn(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnRightbtn()
{
	// TODO: Add your command handler code here
	CGraphDoc* pDoc = GetDocument();
	for (unsigned int i = 0; i < graphs[cur_gr_N]->length; i++)
	{
		graphs[cur_gr_N]->X[i] += (x_max - x_min) * move_scale;
	}
	pDoc->UpdateAllViews(NULL);
}


void CGraphView::OnUpdateRightbtn(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnUpbtn()
{
	// TODO: Add your command handler code here
	CGraphDoc* pDoc = GetDocument();
	for (unsigned int i = 0; i < graphs[cur_gr_N]->length; i++)
	{
		graphs[cur_gr_N]->Y[i] += (y_max - y_min) * move_scale;
	}
	pDoc->UpdateAllViews(NULL);
}


void CGraphView::OnUpdateUpbtn(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnDownbtn()
{
	// TODO: Add your command handler code here
	CGraphDoc* pDoc = GetDocument();
	for (unsigned int i = 0; i < graphs[cur_gr_N]->length; i++)
	{
		graphs[cur_gr_N]->Y[i] -= (y_max - y_min) * move_scale;
	}
	pDoc->UpdateAllViews(NULL);
}


void CGraphView::OnUpdateDownbtn(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnGraphdraw()
{
	// TODO: Add your command handler code here
	edit_graph = !edit_graph;
	edit_graph_rbtn = false;
}


void CGraphView::OnUpdateGraphdraw(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
	pCmdUI->SetCheck(edit_graph);
}


void CGraphView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (edit_graph_rbtn)
	{
		edit_graph_rbtn = false;
		CGraphDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(0);
	}
	CView::OnRButtonUp(nFlags, point);
}


void CGraphView::OnUpdateEditCrop(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnEditCrop()
{
	// TODO: Add your command handler code here
	CCropDlg dlg;
	dlg.x_min = crop_min;
	dlg.x_max = crop_max;
	dlg.y_max = crop_y_max;
	dlg.y_min = crop_y_min;
	if (dlg.DoModal() == IDOK)
	{
		crop_min = dlg.x_min;
		crop_max = dlg.x_max;
		crop_y_max = dlg.y_max;
		crop_y_min = dlg.y_min;

		graphs[cur_gr_N]->Crop(crop_min, crop_max, crop_y_min, crop_y_max);
		if (graphs[cur_gr_N]->length == 0) OnEditRemovecurrent();
	}
	WriteUndo();
	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(NULL);
}


void CGraphView::OnBackgroundcorrectionShirley()
{
	// TODO: Add your command handler code here
	graphs[cur_gr_N]->BGShirleyCorr();
	OnDefaultsize();
	WriteUndo();
	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateBackgroundcorrectionShirley(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnBackgroundcorrectionShape()
{
	// TODO: Add your command handler code here
	CShapeCorrDlg dlg;
	dlg.dx = shape_dx;
	dlg.dy = shape_dy;
	dlg.iter = shape_iter;
	dlg.show = shape_show;
	if (dlg.DoModal() == IDOK)
	{
		shape_dx = dlg.dx;
		shape_dy = dlg.dy;
		shape_iter = dlg.iter;
		shape_show = dlg.show;
		unsigned int N = graphs[cur_gr_N]->length;

		double* Yini = 0;
		if (shape_show)
		{
			Yini = new double[N];
			for (unsigned int i = 0; i < N; i++)
			{
				Yini[i] = graphs[cur_gr_N]->Y[i];
			}
		}

		graphs[cur_gr_N]->BGShapeCorr(shape_dx, shape_dy, shape_iter);

		if (shape_show)
		{
			double* XBG = new double[N];
			double* YBG = new double[N];
			for (unsigned int i = 0; i < N; i++)
			{
				XBG[i] = graphs[cur_gr_N]->X[i];
				YBG[i] = Yini[i]- graphs[cur_gr_N]->Y[i];
			}
			graphs.AddData(XBG, YBG, N, "BG");
			int N_last = graphs.GetNLast();
			graphs[N_last]->col = RGB(0, 0, 0);

			double* Xini = new double[N];
			for (unsigned int i = 0; i < N; i++)
			{
				Xini[i] = graphs[cur_gr_N]->X[i];
			}
			graphs.AddData(Xini, Yini, N, "ini");
			N_last = graphs.GetNLast();
			graphs[N_last]->CopySerData(graphs[cur_gr_N]);
			graphs[N_last]->name += "_ini";
		}
		
		OnDefaultsize();
		WriteUndo();
	}
}


void CGraphView::OnUpdateBackgroundcorrectionShape(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnBackgroundcorrectionPolynomial()
{
	// TODO: Add your command handler code here
	CGraphDoc* pDoc = GetDocument();
	CBGPolyDlg dlg;
	dlg.n = BG_poly_n;
	dlg.iter = BG_poly_iter;
	dlg.graph = &graphs;
	dlg.pDoc = pDoc;
	dlg.gr_cur = cur_gr_N;

	if (dlg.DoModal() == IDOK)
	{
		BG_poly_n = dlg.n;
		BG_poly_iter = dlg.iter;
		for (unsigned int i = 0; i < graphs[cur_gr_N]->length; i++)
		{
			graphs[cur_gr_N]->Y[i] -= dlg.y_BG[i];
		}
		delete[]dlg.y_BG;
	}
	if (dlg.gr_added)
	{
		graphs.RemoveGraph(graphs.GetNLast());
	}
	OnDefaultsize();
	WriteUndo();
}


void CGraphView::OnUpdateBackgroundcorrectionPolynomial(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnEditMerge()
{
	// TODO: Add your command handler code here
	CMergeDlg dlg;
	dlg.rule = merge_rule;
	if (dlg.DoModal() == IDOK)
	{
		merge_rule = dlg.rule;

		int Ngr = graphs[0]->GetNLast();
		bool* to_merge = new bool[Ngr];
		for (int i = 0; i < Ngr; i++)
		{
			to_merge[i] = false;
		}
		char* buf;
		int N = merge_rule.GetLength();
		buf = new char[N + 1];
		buf[N] = 0;
		for (int i = 0; i < N; i++)
		{
			buf[i] = merge_rule[i];
		}

		int k = 0; int l1, l2;
		while (k < N)
		{
			l1 = atoi(&buf[k]);
			if (l1 > Ngr)
			{
				char bb[100];
				sprintf_s(bb, "Error! No graphs with number > %d!", l1);
				::MessageBox(0, bb, 0, MB_OK);
				break;
			}
			if (l1 == 0)
			{
				for (int i = 0; i < Ngr; i++)
				{
					to_merge[i] = true;
				}
				break;
			}
			while (buf[k] >= '0' && buf[k] <= '9') k++;
			while (buf[k] == ' ' || buf[k] == ',') k++;
			if ((buf[k] >= '0' && buf[k] <= '9') || k >= N)
			{
				l2 = -1;
			}
			else
			{
				if (buf[k] == '-')
				{
					k++;
					while (buf[k] == ' ' || buf[k] == ',') k++;
					l2 = atoi(&buf[k]);
					if (l2 > Ngr)
					{
						char bb[100];
						sprintf_s(bb, "Error! No graphs with number > %d!", l1);
						::MessageBox(0, bb, 0, MB_OK);
						break;
					}
					if (l2 == 0)
					{
						for (int i = 0; i < Ngr; i++)
						{
							to_merge[i] = true;
						}
						break;
					}
					while (buf[k] >= '0' && buf[k] <= '9') k++;
					while (buf[k] == ' ' || buf[k] == ',') k++;
				}
				else
				{
					char bb[100];
					sprintf_s(bb, "Error at symbol %d", k);
					::MessageBox(0, bb, 0, MB_OK);
					break;
				}
			}

			if (l2 == -1)
			{
				to_merge[l1-1] = true;
			}
			else
			{
				for (int i = min(l1-1, l2-1); i < max(l1-1, l2-1) + 1; i++)
				{
					to_merge[i] = true;
				}
			}
		}
		delete[] buf;

		unsigned int length_new = 0;
		for (int i = 0; i < Ngr; i++)
		{
			if (to_merge[i])
			{
				length_new += graphs[i + 1]->length;
			}
		}
		double *x = new double[length_new];
		double *y = new double[length_new];
		int cur_N = 0;
		for (int i = 0; i < Ngr; i++)
		{
			if (to_merge[i])
			{
				for (unsigned int j = 0; j < graphs[i + 1]->length; j++)
				{
					x[cur_N] = graphs[i + 1]->X[j];
					y[cur_N] = graphs[i + 1]->Y[j];
					cur_N++;
				}
			}
		}
		int j_min = 0; double t = 0;
		for (unsigned int i = 0; i < length_new; i++)
		{
			j_min = i;
			for (unsigned int j = i; j < length_new; j++)
			{
				if (x[j] < x[j_min]) j_min = j;
			}
			t = x[i];
			x[i] = x[j_min];
			x[j_min] = t;
			t = y[i];
			y[i] = y[j_min];
			y[j_min] = t;
		}

		bool first = true;
		for (int i = 0; i < Ngr; i++)
		{
			if (to_merge[i] && !first)
			{
				graphs.RemoveGraph(i + 1);
			}
			if (to_merge[i] && first)
			{
				first = false;
				delete[] graphs[i + 1]->X;
				delete[] graphs[i + 1]->Y;
				graphs[i + 1]->X = x;
				graphs[i + 1]->Y = y;
				graphs[i + 1]->length = length_new;
				cur_gr_N = i + 1;
			}
		}
		graphs.Renumber(0);
		delete[] to_merge;
		WriteUndo();
		CGraphDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(NULL);
	}
}


void CGraphView::OnUpdateEditMerge(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(graphs[0]->GetNLast() > 1);
}


void CGraphView::OnBatchoperationAnalyze()
{
	// TODO: Add your command handler code here
	CBatchAnalyzeDlg dlgA;
	dlgA.poly_order = poly_app_n;
	dlgA.int_x_max = batch_app_int_x_max;
	dlgA.int_x_min = batch_app_int_x_min;

	dlgA.c_ap_equation = def_app_eq;
	for (int i = 0; i < 5; i++)
	{
		dlgA.c_ap_var_min[i] = def_app_var_min[i];
		dlgA.c_ap_var_max[i] = def_app_var_max[i];
		dlgA.c_ap_var_N[i] = def_app_var_N[i];
	}
	dlgA.c_ap_iter = def_app_iter;

	for (int i = 0; i < Nmax; i++)
	{
		dlgA.v_H[i] = v_A[i];
		dlgA.v_FWHM[i] = v_B[i];
		dlgA.v_x[i] = v_x[i];
		dlgA.v_n[i] = v_n[i];

		dlgA.v_Hmin[i] = v_Amin[i]; dlgA.v_Hmax[i] = v_Amax[i]; dlgA.v_Hstep[i] = v_Astep[i];
		dlgA.v_FWHMmin[i] = v_Bmin[i]; dlgA.v_FWHMmax[i] = v_Bmax[i]; dlgA.v_FWHMstep[i] = v_Bstep[i];
		dlgA.v_xmin[i] = v_xmin[i]; dlgA.v_xmax[i] = v_xmax[i]; dlgA.v_xstep[i] = v_xstep[i];
		dlgA.v_nmin[i] = v_nmin[i]; dlgA.v_nmax[i] = v_nmax[i]; dlgA.v_nstep[i] = v_nstep[i];
	}
	dlgA.v_def_dH = v_def_dH; dlgA.v_def_H_st = v_def_H_st;
	dlgA.v_def_dF = v_def_dF; dlgA.v_def_F_st = v_def_F_st;
	dlgA.v_def_dx = v_def_dx; dlgA.v_def_x_st = v_def_x_st;
	dlgA.v_def_n_min = v_def_n_min; dlgA.v_def_n_max = v_def_n_max; dlgA.v_def_n_step = v_def_n_step;
	
	dlgA.v_n_iter = v_n_iter;

	if (dlgA.DoModal() == IDOK)
	{
		poly_app_n = dlgA.poly_order;
		batch_app_int_x_max = dlgA.int_x_max;
		batch_app_int_x_min = dlgA.int_x_min;
		int batch_type = dlgA.type;

		def_app_eq = dlgA.c_ap_equation;
		def_app_iter = dlgA.c_ap_iter;
		for (int i = 0; i < 5; i++)
		{
			def_app_var_min[i] = dlgA.c_ap_var_min[i];
			def_app_var_max[i] = dlgA.c_ap_var_max[i];
			def_app_var_N[i] = dlgA.c_ap_var_N[i];
		}

		v_n_iter = dlgA.v_n_iter;
		for (int i = 0; i < Nmax; i++)
		{
			v_A[i] = dlgA.v_H[i];
			v_B[i] = dlgA.v_FWHM[i];
			v_x[i] = dlgA.v_x[i];
			v_n[i] = dlgA.v_n[i];

			v_Amin[i] = dlgA.v_Hmin[i]; v_Amax[i] = dlgA.v_Hmax[i]; v_Astep[i] = dlgA.v_Hstep[i];
			v_Bmin[i] = dlgA.v_FWHMmin[i]; v_Bmax[i] = dlgA.v_FWHMmax[i]; v_Bstep[i] = dlgA.v_FWHMstep[i];
			v_xmin[i] = dlgA.v_xmin[i]; v_xmax[i] = dlgA.v_xmax[i]; v_xstep[i] = dlgA.v_xstep[i];
			v_nmin[i] = dlgA.v_nmin[i]; v_nmax[i] = dlgA.v_nmax[i]; v_nstep[i] = dlgA.v_nstep[i];
		}

		CFolderPickerDialog dlg;
		if (dlg.DoModal() == IDOK)
		{
			CGraph graphs_t;
			graphs_t.Init(0);
			int n_gr = 0;

			CString folder = dlg.GetFolderPath();
			folder += "\\*";
			CFileFind finder;
			BOOL bWorking = finder.FindFile(folder);
			folder.Delete(folder.GetLength() - 1, 1);
			while (bWorking)
			{
				bWorking = finder.FindNextFile();
				// skip . and .. files
				if (!finder.IsDots())
				{
					AddGraphFromFile(folder + finder.GetFileName(), finder.GetFileName(), &graphs_t, file_mode, false);
				}
			}
			n_gr = graphs_t.GetNLast();

			folder = dlg.GetFolderPath();
			folder += "\\result.txt";
			CFile cf;
			cf.Open(folder, CFile::modeCreate | CFile::modeWrite);
			char buf[100];
			if (batch_type == 0) //integral
			{
				for (int i = 0; i < n_gr; i++)
				{
					for (int j = 0; j < graphs_t[i + 1]->name.GetLength(); j++)
					{
						if (graphs_t[i + 1]->name[j] == '.')
						{
							graphs_t[i + 1]->name.Delete(j, graphs_t[i + 1]->name.GetLength() - j);
							break;
						}
					}

					double x1, y1, x2, y2; double t;
					double sum = 0;
					double x1int = batch_app_int_x_min; double x2int = batch_app_int_x_max;
					for (unsigned int j = 0; j < graphs_t[i + 1]->length - 1; j++)
					{
						x1 = graphs_t[i + 1]->X[j];
						y1 = graphs_t[i + 1]->Y[j];
						x2 = graphs_t[i + 1]->X[j + 1];
						y2 = graphs_t[i + 1]->Y[j + 1];
						if (x1 > x2)
						{
							t = x1; x1 = x2; x2 = t;
							t = y1; y1 = y2; y2 = t;
						}

						if (x1int <= x1 && x2int >= x2)
						{
							sum += (x2 - x1) * 0.5 * (y2 + y1);
						}
						if (x1int > x1 && x2int >= x2 && x1int < x2)
						{
							sum += (x2 - x1int) * 0.5 * (y2 + y2 - (y2 - y1) * (x2 - x1int) / (x2 - x1));
						}
						if (x1int <= x1 && x2int > x1 && x2int < x2)
						{
							sum += (x2int - x1) * 0.5 * (y1 + y2 - (y2 - y1) * (x2 - x2int) / (x2 - x1));
						}
						if (x1int > x1 && x1int<x2 && x2int>x1 && x2int < x2)
						{
							sum += (x2int - x1int) * 0.5 * (y2 - (y2 - y1) * (x2 - x1int) / (x2 - x1) + y2 - (y2 - y1) * (x2 - x2int) / (x2 - x1));
						}
					}

					int aaa = sprintf(buf, "%s  %g\r\n", graphs_t[i + 1]->name, sum);
					cf.Write(buf, aaa);
				}
			}
			if (batch_type == 2) //custom approximation
			{
				for (int i = 0; i < n_gr; i++)
				{
					for (int j = 0; j < graphs_t[i + 1]->name.GetLength(); j++)
					{
						if (graphs_t[i + 1]->name[j] == '.')
						{
							graphs_t[i + 1]->name.Delete(j, graphs_t[i + 1]->name.GetLength() - j);
							break;
						}
					}
					statb->SetWindowTextA(graphs_t[i + 1]->name);

					char buf[100];
					double x; int err_N;
					double var_val[5];
					te_variable vars[] = { { "x", &x }, { "A", &var_val[0] }, { "B", &var_val[1] }, { "C", &var_val[2] }, { "D", &var_val[3] }, { "E", &var_val[4] } };
					te_expr* expr_y = te_compile(def_app_eq, vars, 6, &err_N);
					if (!expr_y)
					{
						cf.Close();
						graphs_t.DeleteAll();
						cur_gr_N = graphs[0]->GetNLast();
						sprintf_s(buf, "Parse error at y expression at symbol %d", err_N);
						::MessageBox(0, buf, 0, MB_OK);
						return;
					}

					double* y_app = new double[graphs_t[i + 1]->length];
					double err; double min_err;
					for (int iiii = 0; iiii < def_app_iter; iiii++)
					{
						for (int j = 0; j < 5; j++)
						{
							min_err = -1; int min_jj = 0;
							for (int jj = 0; jj < def_app_var_N[j]; jj++)
							{
								if (def_app_var_N[j] > 1)
									var_val[j] = def_app_var_min[j] + jj * (def_app_var_max[j] - def_app_var_min[j]) / (def_app_var_N[j] - 1);
								else var_val[j] = 0.5 * (def_app_var_min[j] + def_app_var_max[j]);

								for (unsigned int k = 0; k < graphs_t[i + 1]->length; k++)
								{
									x = graphs_t[i + 1]->X[k];
									y_app[k] = te_eval(expr_y);
								}
								err = 0;
								for (unsigned int k = 0; k < graphs_t[i + 1]->length; k++)
								{
									err += (graphs_t[i + 1]->Y[k] - y_app[k]) * (graphs_t[i + 1]->Y[k] - y_app[k]);
								}
								if (err < min_err || min_err == -1)
								{
									min_err = err;
									min_jj = jj;
								}
							}
							if (def_app_var_N[j] > 1)
								var_val[j] = def_app_var_min[j] + min_jj * (def_app_var_max[j] - def_app_var_min[j]) / (def_app_var_N[j] - 1);
							else var_val[j] = 0.5 * (def_app_var_min[j] + def_app_var_max[j]);
						}
					}

					te_free(expr_y);
					delete[] y_app;
					
					CString str_app;
					for (int j = 0; j < 5; j++)
					{
						if (def_app_var_N[j] > 1)
						{
							sprintf(buf, "  %g", var_val[j]);
							str_app += buf;
						}
					}
					int aaa = sprintf(buf, "%s%s\r\n", graphs_t[i + 1]->name, str_app);
					cf.Write(buf, aaa);
				}
				statb->SetWindowTextA("Done");
			}
			if (batch_type == 1) //polynomial approximation
			{
				for (int i = 0; i < n_gr; i++)
				{
					for (int j = 0; j < graphs_t[i + 1]->name.GetLength(); j++)
					{
						if (graphs_t[i + 1]->name[j] == '.')
						{
							graphs_t[i + 1]->name.Delete(j, graphs_t[i + 1]->name.GetLength() - j);
							break;
						}
					}

					double c_app[10];
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

					int n_app = poly_app_n;
					int n = graphs_t[i + 1]->length;

					for (unsigned int j = 0; j < n; j++)
					{
						X = graphs_t[i + 1]->X[j];
						Y = graphs_t[i + 1]->Y[j];

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
						c_app[1] = (n * xys - xs * ys) / (n * x2s - xs * xs);
						c_app[0] = (ys * x2s - xys * xs) / (n * x2s - xs * xs);
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

					CString str_app;
					for (int i = 0; i < n_app + 1; i++)
					{
						sprintf(buf, "  %g", c_app[i]);
						str_app += buf;
					}

					int aaa = sprintf(buf, "%s%s\r\n", graphs_t[i + 1]->name, str_app);
					cf.Write(buf, aaa);
				}
			}
			if (batch_type == 3) //Voight approximation
			{
				for (int i = 0; i < n_gr; i++)
				{
					for (int j = 0; j < graphs_t[i + 1]->name.GetLength(); j++)
					{
						if (graphs_t[i + 1]->name[j] == '.')
						{
							graphs_t[i + 1]->name.Delete(j, graphs_t[i + 1]->name.GetLength() - j);
							break;
						}
					}

					char buf[1000];

					double ini_H[Nmax], ini_FWHM[Nmax], ini_x[Nmax], ini_n[Nmax];

					bool changed = true;
					for (int iiii = 0; iiii < v_n_iter; iiii++)
					{
						if (!changed) break;

						sprintf_s(buf, "  Iteration %d", iiii);
						statb->SetWindowTextA(graphs_t[i + 1]->name + buf);

						for (int j = 0; j < Nmax; j++)
						{
							ini_H[j] = v_A[j];
							ini_FWHM[j] = v_B[j];
							ini_n[j] = v_n[j];
							ini_x[j] = v_x[j];
						}

						for (int j = 0; j < Nmax; j++)
						{
							int index = j;
							double err = GetError(graphs_t[i + 1]->length, graphs_t[i + 1]->X, graphs_t[i + 1]->Y, v_B, v_x, v_n, v_A);
							char buf[100];
							double min_err = err;

							double min_p = v_x[index];
							double p_0 = v_x[index];
							int N_c = 1;
							if (v_xstep[index] > 0) N_c = (v_xmax[index] - v_xmin[index]) / v_xstep[index];

							for (int ii = 0; ii < N_c + 1; ii++)
							{
								v_x[index] = v_xmin[index] + ii * v_xstep[index];
								err = GetError(graphs_t[i + 1]->length, graphs_t[i + 1]->X, graphs_t[i + 1]->Y, v_B, v_x, v_n, v_A);
								if (err < min_err)
								{
									min_err = err;
									min_p = v_x[index];
								}
							}
							v_x[index] = min_p;

							min_p = v_A[index];
							p_0 = v_A[index];
							N_c = 1;
							if (v_Astep[index] > 0) N_c = (v_Amax[index] - v_Amin[index]) / v_Astep[index];

							for (int ii = 0; ii < N_c + 1; ii++)
							{
								v_A[index] = v_Amin[index] + ii * v_Astep[index];
								err = GetError(graphs_t[i + 1]->length, graphs_t[i + 1]->X, graphs_t[i + 1]->Y, v_B, v_x, v_n, v_A);
								if (err < min_err)
								{
									min_err = err;
									min_p = v_A[index];
								}
							}
							v_A[index] = min_p;

							min_p = v_B[index];
							p_0 = v_B[index];
							N_c = 1;
							if (v_Bstep[index] > 0) N_c = (v_Bmax[index] - v_Bmin[index]) / v_Bstep[index];

							for (int ii = 0; ii < N_c + 1; ii++)
							{
								v_B[index] = v_Bmin[index] + ii * v_Bstep[index];
								err = GetError(graphs_t[i + 1]->length, graphs_t[i + 1]->X, graphs_t[i + 1]->Y, v_B, v_x, v_n, v_A);
								if (err < min_err)
								{
									min_err = err;
									min_p = v_B[index];
								}
							}
							v_B[index] = min_p;

							min_p = v_n[index];
							p_0 = v_n[index];
							N_c = 1;
							if (v_nstep[index] > 0) N_c = (v_nmax[index] - v_nmin[index]) / v_nstep[index];

							for (int ii = 0; ii < N_c + 1; ii++)
							{
								v_n[index] = v_nmin[index] + ii * v_nstep[index];
								err = GetError(graphs_t[i + 1]->length, graphs_t[i + 1]->X, graphs_t[i + 1]->Y, v_B, v_x, v_n, v_A);
								if (err < min_err)
								{
									min_err = err;
									min_p = v_n[index];
								}
							}
							v_n[index] = min_p;
						}

						changed = false;
						for (int j = 0; j < Nmax; j++)
						{
							if (ini_H[j] != v_A[j] || ini_FWHM[j] != v_B[j] || ini_x[j] != v_x[j] || ini_n[j] != v_n[j])
							{
								changed = true;
							}
						}
					}
					

					CString str_app;
					for (int j = 0; j < Nmax; j++)
					{
						bool write = false;
						if (v_Amin[j] != v_Amax[j])
						{
							sprintf(buf, " %g", v_A[j]);
							str_app += buf;
							write = true;
						}
						if (v_Bmin[j] != v_Bmax[j])
						{
							sprintf(buf, " %g", v_B[j]);
							str_app += buf;
							write = true;
						}
						if (v_xmin[j] != v_xmax[j])
						{
							sprintf(buf, " %g", v_x[j]);
							str_app += buf;
							write = true;
						}
						if (v_nmin[j] != v_nmax[j])
						{
							sprintf(buf, " %g", v_n[j]);
							str_app += buf;
							write = true;
						}
						if (write) str_app += ";";
					}
					int aaa = sprintf(buf, "%s%s\r\n", graphs_t[i + 1]->name, str_app);
					cf.Write(buf, aaa);
				}
				statb->SetWindowTextA("Done");
			}
			cf.Close();

			graphs_t.DeleteAll();
			cur_gr_N = graphs[0]->GetNLast();
		}
	}
}


void CGraphView::OnUpdateBatchoperationAnalyze(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}


void CGraphView::OnBatchoperationTransform()
{
	// TODO: Add your command handler code here
	CBatchTransformDlg dlgT;
	
	dlgT.crop_x_max = crop_max;
	dlgT.crop_x_min = crop_min;
	dlgT.crop_y_max = crop_y_max;
	dlgT.crop_y_min = crop_y_min;

	dlgT.trans_x = trans_x;
	dlgT.trans_y = trans_y;
	dlgT.combine_str = combine_str;
	
	dlgT.shape_dx = shape_dx;
	dlgT.shape_dy = shape_dy;
	dlgT.shape_iter = shape_iter;

	dlgT.poly_order = BG_poly_n;

	dlgT.spline_iter = spline_iter;
	dlgT.spline_order = spline_order;

	dlgT.operationN = batch_trans_operN;
	
	if (dlgT.DoModal() == IDOK)
	{
		crop_max = dlgT.crop_x_max;
		crop_min = dlgT.crop_x_min;
		crop_y_max = dlgT.crop_y_max;
		crop_y_min = dlgT.crop_y_min;

		trans_x = dlgT.trans_x;
		trans_y = dlgT.trans_y;
		combine_str = dlgT.combine_str;

		shape_dx = dlgT.shape_dx;
		shape_dy = dlgT.shape_dy;
		shape_iter = dlgT.shape_iter;

		BG_poly_n = dlgT.poly_order;

		spline_iter = dlgT.spline_iter;
		spline_order = dlgT.spline_order;

		batch_trans_operN = dlgT.operationN;
		
		CFolderPickerDialog dlg;
		if (dlg.DoModal() == IDOK)
		{
			CGraph graphs_t;
			graphs_t.Init(0);
			int n_gr = 0;

			CString folder = dlg.GetFolderPath();
			folder += "\\*";
			CFileFind finder;
			BOOL bWorking = finder.FindFile(folder);
			folder.Delete(folder.GetLength() - 1, 1);
			while (bWorking)
			{
				bWorking = finder.FindNextFile();
				// skip . and .. files
				if (!finder.IsDots())
				{
					AddGraphFromFile(folder + finder.GetFileName(), finder.GetFileName(), &graphs_t, file_mode, false);
				}
			}
			n_gr = graphs_t.GetNLast();
			
			char buf[100]; int aaa = 0;
			for (int i = 0; i < n_gr; i++)
			{
				if (batch_trans_operN == 0)
				{
					graphs_t[i + 1]->Crop(crop_min, crop_max, crop_y_min, crop_y_max);
				}
				if (batch_trans_operN == 1)
				{
					graphs_t[i + 1]->Transform(trans_x, trans_y);
				}
				if (batch_trans_operN == 2)
				{
					graphs_t[i + 1]->BGShapeCorr(shape_dx, shape_dy, shape_iter);
				}
				if (batch_trans_operN == 3)
				{
					graphs_t[i + 1]->BGShirleyCorr();
				}
				if (batch_trans_operN == 4)
				{
					graphs_t[i + 1]->BGPolyCorr(BG_poly_n);
				}
				if (batch_trans_operN == 5)
				{
					graphs_t[i + 1]->Spline(spline_order, spline_iter);
				}
				if (batch_trans_operN == 6)
				{
					graphs_t[i + 1]->Combine(combine_str, &graphs);
				}

				folder = dlg.GetFolderPath();
				folder += "\\ed_";
				folder += graphs_t[i + 1]->name;
				CFile cf;
				cf.Open(folder, CFile::modeCreate | CFile::modeWrite);
			
				for (unsigned int j = 0; j < graphs_t[i + 1]->length; j++)
				{
					aaa = sprintf(buf, "%g  %g\r\n", graphs_t[i + 1]->X[j], graphs_t[i + 1]->Y[j]);
					cf.Write(buf, aaa);
				}
				cf.Close();
			}

			graphs_t.DeleteAll();
			cur_gr_N = graphs[0]->GetNLast();
		}
	}
}


void CGraphView::OnUpdateBatchoperationTransform(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}


void CGraphView::OnFileSaveaseps()
{
	// TODO: Add your command handler code here
	CFileDialog f(FALSE, "eps", NULL, OFN_FILEMUSTEXIST | OFN_LONGNAMES | OFN_OVERWRITEPROMPT, "Files (*.eps)|*.eps||", NULL);
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
			CWaitCursor wait;
			CString path = cf.GetFilePath();
			cf.Close();

			RECT r; GetClientRect(&r);
			CRect gr_r;
			gr_r.left = r.left + margin_left;
			gr_r.right = r.right - margin_right;
			gr_r.top = r.top + margin_top;
			gr_r.bottom = r.bottom - margin_bottom - axe_fontN / 2;

			ns_creeps::CreEPS eps(path, r.left, r.top, r.right, r.bottom);
			
			eps.startPath(r.left, r.top);
			eps.addLine(r.right, r.top);
			eps.addLine(r.right, r.bottom);
			eps.addLine(r.left, r.bottom);
			eps.closeSubpath();
			eps.endPath(ns_creeps::CreEPS::FILL, ns_creeps::CAtColor(1, 1, 1));

			graphs.DrawAll(0, gr_r, x_min, x_max, y_min, y_max, polar_view, polar_deg, true, &eps, margin_bottom + axe_fontN / 2, hide_app, graphs[0]);
			DrawAxis(0, true, &eps);
			Draw_Text(0, true, &eps);

			wait.Restore();
		}
	}

	/*eps.embedEPS("F7R.eps");
	eps.applyTranslation(r.right - 400, r.bottom - 300);
	eps.embedEPS("F7X.eps");
	eps.setAttributes(ns_creeps::CAtLineThickness(1) | ns_creeps::CAtColor(0,0,0) | ns_creeps::CAtLineJoin(ns_creeps::CAt::LJ_ROUND));
	eps.line(r.right - 400, r.bottom - 300, r.right - 400, r.bottom);
	eps.line(r.right - 400, r.bottom, r.right, r.bottom);
	eps.line(r.right, r.bottom, r.right, r.bottom - 300);
	eps.line(r.right, r.bottom - 300, r.right - 400, r.bottom - 300);*/
}


void CGraphView::OnUpdateFileSaveaseps(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code herep
	pCmdUI->Enable();
}


void CGraphView::OnButton32816()
{
	// TODO: Add your command handler code here
	addText = !addText;
	moveText = false;
}


void CGraphView::OnUpdateButton32816(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
	pCmdUI->SetCheck(addText);
}


void CGraphView::OnButton32817()
{
	// TODO: Add your command handler code here
	moveText = !moveText;
	addText = false;
}


void CGraphView::OnUpdateButton32817(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(NumText > 0);
	pCmdUI->SetCheck(moveText);
}


void CGraphView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (i_text_move >= 0)
	{
		i_text_last = i_text_move;
		texts[i_text_move].x = point.x - text_move_dx;
		texts[i_text_move].y = point.y + text_move_dy;
		i_text_move = -1;
		WriteUndo();
		CGraphDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(NULL);
	}
	CView::OnLButtonUp(nFlags, point);
}


void CGraphView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	/*char bbb[10];
	sprintf(bbb, "%d", nChar);
	::MessageBox(0, bbb, 0, MB_OK);*/
	//37 - left, 38 - up, 39 - right, 40 - down
	if (i_text_last < NumText && i_text_last >= 0)
	{
		bool upd = false;
		if (nChar == 37)
		{
			texts[i_text_last].x -= 1;
			upd = true;
		}
		if (nChar == 38)
		{
			texts[i_text_last].y -= 1;
			upd = true;
		}
		if (nChar == 39)
		{
			texts[i_text_last].x += 1;
			upd = true;
		}
		if (nChar == 40)
		{
			texts[i_text_last].y += 1;
			upd = true;
		}
		if (upd)
		{
			CGraphDoc* pDoc = GetDocument();
			pDoc->UpdateAllViews(NULL);
		}
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CGraphView::OnRemoveTexts()
{
	// TODO: Add your command handler code here
	for (int i = 0; i < NumText; i++)
	{
		texts[i].txt.Empty();
	}
	NumText = 0;
	i_text_last = -1;
	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(NULL);
}


void CGraphView::OnUpdateRemoveTexts(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(NumText > 0);
}


void CGraphView::OnButton32819() //New
{
	// TODO: Add your command handler code here
	OnEditRemoveall();
	OnRemoveTexts();
	graphs_Voight.DeleteAll();
	x_axis = "X";
	y_axis = "Intensity";
	WriteUndo();
}


void CGraphView::OnUpdateButton32819(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
}


void CGraphView::OnApproximationVoight()
{
	// TODO: Add your command handler code here
	CVoightNDlg dlg;
	for (int i = 0; i < Nmax; i++)
	{
		dlg.H[i]= v_A[i];
		dlg.FWHM[i] = v_B[i];
		dlg.x[i] = v_x[i];
		dlg.n[i] = v_n[i];

		dlg.Hmax[i] = v_Amax[i]; dlg.Hmin[i] = v_Amin[i]; dlg.Hstep[i] = v_Astep[i];
		dlg.FWHMmax[i] = v_Bmax[i]; dlg.FWHMmin[i] = v_Bmin[i]; dlg.FWHMstep[i] = v_Bstep[i];
		dlg.xmax[i] = v_xmax[i]; dlg.xmin[i] = v_xmin[i]; dlg.xstep[i] = v_xstep[i];
		dlg.nmax[i] = v_nmax[i]; dlg.nmin[i] = v_nmin[i]; dlg.nstep[i] = v_nstep[i];
	}
	dlg.x_exp = graphs[cur_gr_N]->X;
	dlg.y_exp = graphs[cur_gr_N]->Y;
	dlg.N_exp = graphs[cur_gr_N]->length;

	dlg.def_dH = v_def_dH; dlg.def_H_st = v_def_H_st;
	dlg.def_dF = v_def_dF; dlg.def_F_st = v_def_F_st;
	dlg.def_dx = v_def_dx; dlg.def_x_st = v_def_x_st;
	dlg.def_n_min = v_def_n_min; dlg.def_n_max = v_def_n_max; dlg.def_n_step = v_def_n_step;

	dlg.n_iter = v_n_iter;

	CGraphDoc* pDoc = GetDocument();
	dlg.pDoc = pDoc;

	CRect r; GetClientRect(&r);
	int G_N = r.right - margin_right - margin_left;
	
	graphs_Voight.DeleteAll();
	
	double* x_G = new double[G_N]; double* y_G = new double[G_N];

	for (int i = 0; i < G_N; i++)
	{
		x_G[i] = x_min + i * (x_max - x_min) / (G_N - 1);
		y_G[i] = 0;
	}

	graphs_Voight.AddData(x_G, y_G, G_N, "Voight");
	graphs_Voight[graphs_Voight.GetNLast()]->col = v_col_1;
	graphs_Voight[graphs_Voight.GetNLast()]->line_width = v_thick_1;

	dlg.graph = &graphs_Voight;

	delete[] x_G; delete[] y_G;
	
	if (dlg.DoModal() == IDOK)
	{
		for (int i = 0; i < Nmax; i++)
		{
			v_A[i] = dlg.H[i];
			v_B[i] = dlg.FWHM[i];
			v_x[i] = dlg.x[i];
			v_n[i] = dlg.n[i];

			v_Amax[i] = dlg.Hmax[i]; v_Amin[i] = dlg.Hmin[i]; v_Astep[i] = dlg.Hstep[i];
			v_Bmax[i] = dlg.FWHMmax[i]; v_Bmin[i] = dlg.FWHMmin[i]; v_Bstep[i] = dlg.FWHMstep[i];
			v_xmax[i] = dlg.xmax[i]; v_xmin[i] = dlg.xmin[i]; v_xstep[i] = dlg.xstep[i];
			v_nmax[i] = dlg.nmax[i]; v_nmin[i] = dlg.nmin[i]; v_nstep[i] = dlg.nstep[i];
		}
		v_n_iter = dlg.n_iter;
	}

	UpdateVoight();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateApproximationVoight(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::UpdateVoight()
{
	// TODO: Add your implementation code here.
	CRect r; GetClientRect(&r);
	int G_N = r.right - margin_right - margin_left;
	
	graphs_Voight.DeleteAll();
	
	double *x_G = new double[G_N]; double* y_G = new double[G_N];
	double SS[21], SSS[21];
	for (int i = 0; i < G_N; i++)
	{
		x_G[i] = x_min + i * (x_max - x_min) / (G_N - 1);
		for (int ii = 0; ii < 21; ii++)
		{
			SS[ii] = 4 * (x_G[i] - v_x[ii]) * (x_G[i] - v_x[ii]) + v_B[ii] * v_B[ii];
			SSS[ii] = v_B[ii] * v_B[ii];
		}
		for (int o = 0; o < 21; o++)
		{
			if (SS[o] == 0) SS[o] = 1;
			if (SSS[o] == 0) SSS[o] = 1;
		}

		y_G[i] = 0;
		for (int ii = 0; ii < 21; ii++)
		{
			y_G[i] += v_n[ii] * v_A[ii] * exp(-2.7726 * (x_G[i] - v_x[ii]) * (x_G[i] - v_x[ii]) / (SSS[ii])) +
				(1 - v_n[ii]) * v_A[ii] * v_B[ii] * v_B[ii] / (SS[ii]);
		}
	}
	graphs_Voight.AddData(x_G, y_G, G_N, "Voight");
	graphs_Voight[graphs_Voight.GetNLast()]->col = v_col_1;
	graphs_Voight[graphs_Voight.GetNLast()]->line_width = v_thick_1;

	for (int ii = 0; ii < 21; ii++)
	{
		if (v_A[ii] != 0)
		{
			for (int i = 0; i < G_N; i++)
			{
				x_G[i] = x_min + i * (x_max - x_min) / (G_N - 1);
				y_G[i] = v_n[ii] * v_A[ii] * exp(-2.7726 * (x_G[i] - v_x[ii]) * (x_G[i] - v_x[ii]) / (v_B[ii] * v_B[ii])) +
					(1 - v_n[ii]) * v_A[ii] * v_B[ii] * v_B[ii] / (4 * (x_G[i] - v_x[ii]) * (x_G[i] - v_x[ii]) + v_B[ii] * v_B[ii]);
			}
			graphs_Voight.AddData(x_G, y_G, G_N, "Voight");
			graphs_Voight[graphs_Voight.GetNLast()]->col = v_col_2;
			graphs_Voight[graphs_Voight.GetNLast()]->line_width = v_thick_2;
		}
	}

	delete[] x_G; delete[] y_G;
}


void CGraphView::SetSettings()
{
	// TODO: Add your implementation code here
	CFile cf;
	if (cf.Open("settings.txt", CFile::modeRead))
	{
		int size = cf.GetLength() + 1;
		char* buf = new char[size];
		cf.Read(buf, size);
		cf.Close();

		int k = 0;
		int n_param = 0;
		double val = 0;
		while (k < size)
		{
			if (buf[k] == ':')
			{
				k += 1;
				val = GetDigitalFromString(&buf[k], '.');
				if (n_param == 0) file_mode = val;
				if (n_param == 1)
				{
					if (val == 0) dec_separator = '.';
					if (val == 1) dec_separator = ',';
				}
				if (n_param == 2) polar_deg = val;
				if (n_param == 3) view_mode = val;
				if (n_param == 4) eps_scale = val;
				if (n_param == 5) move_scale = val;
				if (n_param == 6) meas_line_w = val;
				if (n_param == 7) meas_line_col = RGB((int)val / (256 * 256), ((int)val / 256) % 256, (int)val % 256);
				if (n_param == 8) meas_text_size = val;
				if (n_param == 9) meas_text_col = RGB((int)val / (256 * 256), ((int)val / 256) % 256, (int)val % 256);
				if (n_param == 10) v_def_dH = val;
				if (n_param == 11) v_def_H_st = val;
				if (n_param == 12) v_def_dF = val;
				if (n_param == 13) v_def_F_st = val;
				if (n_param == 14) v_def_dx = val;
				if (n_param == 15) v_def_x_st = val;
				if (n_param == 16) v_def_n_min = val;
				if (n_param == 17) v_def_n_step = val;
				if (n_param == 18) v_def_n_max = val;
				if (n_param > 18 && n_param < 24) palette_red[n_param - 19] = val;
				if (n_param > 23 && n_param < 29) palette_green[n_param - 24] = val;
				if (n_param > 28 && n_param < 34) palette_blue[n_param - 29] = val;
				if (n_param > 33 && n_param < 39) palette_pts[n_param - 34] = val;
				if (n_param == 39) palette_number = val;
				n_param++;
			}
			k++;
		}
		delete[] buf;
	}
}


void CGraphView::OnApproximationHide()
{
	// TODO: Add your command handler code here
	hide_app = !hide_app;
	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateApproximationHide(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
	pCmdUI->SetCheck(hide_app);
}


void CGraphView::OnUpdateViewApproximation(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0);
}


void CGraphView::OnViewApproximation()
{
	// TODO: Add your command handler code here
	CAppColDlg dlg;
	dlg.graph = &graphs;
	dlg.v_graph = &graphs_Voight;
	CGraphDoc* pDoc = GetDocument();
	dlg.pDoc = pDoc;
	dlg.gr_cur = cur_gr_N;
	dlg.v_col1 = &v_col_1;
	dlg.v_col2 = &v_col_2;
	dlg.v_w1 = &v_thick_1;
	dlg.v_w2 = &v_thick_2;
	if (dlg.DoModal() == IDOK)
	{
		cur_gr_N = dlg.gr_cur;
	}
	pDoc->UpdateAllViews(0);
}


double CGraphView::GetError(int N_exp, double* x_exp, double* y_exp, double* FWHM, double* x, double* n, double* H)
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


void CGraphView::OnButton32825()
{
	// TODO: Add your command handler code here

	y_min = graphs.GetYmin_X(x_min, x_max);
	y_max = graphs.GetYmax_X(x_min, x_max);

	CGraphDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateButton32825(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_gr_N > 0 && !polar_view);
}


void CGraphView::OnViewRecolorgraphs()
{
	// TODO: Add your command handler code here
	CReclorDlg dlg;
	CGraphDoc* pDoc = GetDocument();
	for (int i = 0; i < 5; i++)
	{
		dlg.p[i] = palette_pts[i];
		dlg.r[i] = palette_red[i];
		dlg.g[i] = palette_green[i];
		dlg.b[i] = palette_blue[i];
		dlg.pal_n = palette_number;
	}
	if (dlg.DoModal() == IDOK)
	{
		for (int i = 0; i < 5; i++)
		{
			palette_pts[i] = dlg.p[i];
			palette_red[i] = dlg.r[i];
			palette_green[i] = dlg.g[i];
			palette_blue[i] = dlg.b[i];
			palette_number = dlg.pal_n;
		}

		for (int i = 1; i <= graphs[0]->GetNLast(); i++)
		{
			graphs[i]->col = ValueToColor(1, graphs[0]->GetNLast(), i, palette_number);
		}
	}
	WriteUndo();
	pDoc->UpdateAllViews(0);
}


void CGraphView::OnUpdateViewRecolorgraphs(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(graphs[0]->GetNLast() >= 2);
}

COLORREF CGraphView::ValueToColor(double min, double max, double val, int pallete)
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
			if (val <= min + (max - min) * p[i+1])
				return RGB(r[i] + (r[i+1] - r[i]) * (pval - p[i]) / (p[i+1] - p[i]), g[i] + (g[i+1] - g[i]) * (pval - p[i]) / (p[i+1] - p[i]), b[i] + (b[i+1] - b[i]) * (pval - p[i]) / (p[i+1] - p[i]));
		}
		return 0;
		//Viridis
	}
	if (pallete == 5)
	{
		int r[5], g[5], b[5]; double p[5];
		for (int i = 0; i < 5; i++)
		{
			p[i] = palette_pts[i];
			r[i] = palette_red[i];
			g[i] = palette_green[i];
			b[i] = palette_blue[i];
		}

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

void CGraphView::ClearMarker()
{
	// TODO: Add your implementation code here.
	CDC* hdc = GetDC();
	CRect r, re;
	GetClientRect(&r);

	re.top = 4; re.bottom = 16;
	re.left = r.right - 91; re.right = r.right - 9;

	CBrush br;
	br.CreateSolidBrush(RGB(255, 255, 255));
	hdc->FillRect(re, &br);
	DeleteObject(br);
}

void CGraphView::WriteUndo()
{
	// TODO: Add your implementation code here.
	char buf[100];
	int a=sprintf_s(buf, "undo/undo_%d.txt", cur_undo_n);
	buf[a] = 0;
	CString path = buf;
	OnExportData(path);
	cur_undo_n++;
}


void CGraphView::OnEditRestore()
{
	// TODO: Add your command handler code here
	char buf[100];
	int a = sprintf_s(buf, "undo/undo_%d.txt", cur_undo_n-1);
	buf[a] = 0;
	CString path = buf;

	a = sprintf_s(buf, "undo_%d.txt", cur_undo_n-1);
	buf[a] = 0;
	CString fn = buf;

	OnEditRemoveall();
	AddGraphFromFile(path, fn, &graphs, 1, false);
}


void CGraphView::OnUpdateEditRestore(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_undo_n > 0);
}


void CGraphView::OnEditUndo32830()
{
	// TODO: Add your command handler code here
	char buf[100];
	int a = sprintf_s(buf, "undo/undo_%d.txt", cur_undo_n - 2);
	buf[a] = 0;
	CString path = buf;

	a = sprintf_s(buf, "undo_%d.txt", cur_undo_n - 2);
	buf[a] = 0;
	CString fn = buf;

	OnEditRemoveall();
	cur_undo_n--;
	AddGraphFromFile(path, fn, &graphs, 1, false);
}


void CGraphView::OnUpdateEditUndo32830(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(cur_undo_n > 1);
}


void CGraphView::OnSmoothingStepcross()
{
	// TODO: Add your command handler code here
	StepCCDlg dlg;
	dlg.N = stepCC_N;
	dlg.dx = stepCC_dx;
	dlg.iter = stepCC_iter;
	if (dlg.DoModal() == IDOK)
	{
		stepCC_N = dlg.N;
		stepCC_iter = dlg.iter;
		stepCC_dx = dlg.dx;

		double* x_sm = new double[dlg.N];
		double* y_sm = new double[dlg.N];

		for (int iii = 0; iii < stepCC_iter; iii++)
		{
			x_min = graphs[cur_gr_N]->X[0];
			x_max = graphs[cur_gr_N]->X[0];
			for (int i = 0; i < graphs[cur_gr_N]->length; i++)
			{
				if (x_min > graphs[cur_gr_N]->X[i]) x_min = graphs[cur_gr_N]->X[i];
				if (x_max < graphs[cur_gr_N]->X[i]) x_max = graphs[cur_gr_N]->X[i];
			}

			double dx, x_cur;
			double A = 1.0 / dlg.N;

			for (int i = 0; i < dlg.N; i++)
			{
				x_sm[i] = x_min - dlg.dx + i * ((x_max + dlg.dx) - (x_min - dlg.dx)) / (dlg.N - 1);
				y_sm[i] = 0;

				dx = ((x_max + dlg.dx) - (x_min - dlg.dx)) / (dlg.N - 1);

				for (int j = 0; j < dlg.N; j++)
				{
					x_cur = x_min - dlg.dx + j * ((x_max + dlg.dx) - (x_min - dlg.dx)) / (dlg.N - 1);
					if (-x_sm[i] + x_cur >= -dlg.dx / 2 && -x_sm[i] + x_cur <= dlg.dx / 2)
					{
						if (x_cur >= x_min && x_cur <= x_max)
							y_sm[i] += A * graphs[cur_gr_N]->GetY(x_cur);
					}
				}
			}

			double old_int = GetIntegral(x_min, x_max, cur_gr_N);
			if (iii == 0)
			{
				graphs.AddData(x_sm, y_sm, dlg.N, "smooth");
				cur_gr_N = graphs.GetNLast();
			}
			else
			{
				for (int i = 0; i < graphs[cur_gr_N]->length; i++)
				{
					graphs[cur_gr_N]->Y[i] = y_sm[i];
					graphs[cur_gr_N]->X[i] = x_sm[i];
				}
			}
			double new_int = GetIntegral(graphs[cur_gr_N]->GetXmin(), graphs[cur_gr_N]->GetXmax(), cur_gr_N);
			for (int i = 0; i < graphs[cur_gr_N]->length; i++)
			{
				graphs[cur_gr_N]->Y[i] /= new_int / old_int;
			}
		}

		delete[] x_sm; delete[] y_sm;
		x_min = graphs.GetXmin();
		x_max = graphs.GetXmax();
		y_min = graphs.GetYmin();
		y_max = graphs.GetYmax();
		WriteUndo();
		CGraphDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(NULL);
	}
}


void CGraphView::OnUpdateSmoothingStepcross(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(graphs.GetNLast() >= 1);
}
