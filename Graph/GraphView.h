
// GraphView.h : interface of the CGraphView class
//

#pragma once

#include "CGraph.h"
#include "DXSurfaceMgr.h"
#include <complex>

class CGraphView : public CView
{
protected: // create from serialization only
	CGraphView();
	DECLARE_DYNCREATE(CGraphView)

// Attributes
public:
	CGraphDoc* GetDocument() const;
	CGraph graphs, graphs_Voight;

	CString x_axis, y_axis;
	int axe_fontN, axe_fontA;
	int Ny_mark, Nx_mark;
	int tol_x, tol_y;
	bool e_x, e_y; bool hide_y;
	int y_shift;
	
	double x_max, x_min, y_max, y_min;
	int margin_left, margin_right, margin_top, margin_bottom;

	int cur_gr_N;
	bool show_marker;
	bool show_net;

	CDXSurfaceManager_NBP dxMgr_;

	int mouse_flag;
	int px_click, py_click;
	int px_prev, py_prev;

	CString trans_x, trans_y;
	bool trans_def_size;
	CString combine_str;

	double addf_x1, addf_x2;
	int addf_N;
	CString addf_y;

	double def_app_var_min[5], def_app_var_max[5], def_app_var_val[5];
	int def_app_var_N[5];
	CString def_app_eq; int def_app_iter;
	double def_poly_app[10];
	bool hide_app;

	double Ix1, Ix2, Iy1, Iy2;
	int sensitivity;

	int poly_app_n;
	int file_mode;

	char dec_separator;

	bool polar_view; bool polar_deg;
	bool view_mode;
	double move_scale;

	bool calc_integral; bool calc_integral_line;
	int calc_integral_x_last; int calc_integral_x_first;

	double split_x;

	bool edit_graph, edit_graph_rbtn;
	int edit_graph_prevX, edit_graph_prevY;

	double crop_min, crop_max;
	double crop_y_min, crop_y_max;

	double shape_dx, shape_dy; int shape_iter; bool shape_show;
	int BG_poly_n; int BG_poly_iter;

	double ave_sigma_N;
	int spline_order, spline_iter;
	int stepCC_N, stepCC_iter; double stepCC_dx;
	CString merge_rule;

	int batch_trans_operN;
	double eps_scale;

	double v_A[21], v_B[21], v_x[21], v_n[21]; bool v_ch[21];
	bool v_fine;
	double v_Amin[21], v_Amax[21], v_Astep[21];
	double v_Bmin[21], v_Bmax[21], v_Bstep[21];
	double v_xmin[21], v_xmax[21], v_xstep[21];
	double v_nmin[21], v_nmax[21], v_nstep[21];
	double v_def_dH, v_def_H_st;
	double v_def_dF, v_def_F_st;
	double v_def_dx, v_def_x_st;
	double v_def_n_min, v_def_n_max, v_def_n_step;
	int v_n_iter;

	double TL_d, TL_A, TL_C, TL_Eg, TL_E0, TL_eps_inf, TL_phi, TL_rough;

	COLORREF v_col_1, v_col_2;
	int v_thick_1, v_thick_2;

	int meas_text_size, meas_line_w, sel_line_w;
	COLORREF meas_text_col, meas_line_col, sel_line_col;

	double batch_app_int_x_min, batch_app_int_x_max;
	int palette_number; int palette_red[5], palette_green[5], palette_blue[5]; double palette_pts[5];

	int cur_undo_n;
// Operations
public:
	class file_format
	{
	public: 
		CString name;
		char* number_type;
		int number_N;
		int* graph_N;
		int** graph_index;
		int skip;
	};
	file_format* formats;
	int formats_N;

	class text
	{
	public:
		double x, y;
		int size;
		CString txt;
		bool shade;
		double alpha;
		COLORREF col;
		void operator = (text t)
		{
			x = t.x;
			y = t.y;
			size = t.size;
			txt = t.txt;
			shade = t.shade;
			alpha = t.alpha;
			col = t.col;
		}
	};
	text* texts;
	int NumText;
	int MaxText;
	bool moveText;
	int i_text_move, i_text_last;
	double text_move_dx, text_move_dy;
	bool addText;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CGraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileAddgraph();
	afx_msg void OnUpdateFileAddgraph(CCmdUI *pCmdUI);
	int GetAxisNames(char* buf, unsigned long int size);
	//double GetDigitalFromString(char *buf, char separ);
	//int GetLengthDigital(char *buf, char separ);
	void DrawAxis(CDC *pDC, bool save_eps, ns_creeps::CreEPS* eps);
	void Draw_Text(CDC* pDC, bool save_eps, ns_creeps::CreEPS* eps);
	void DrawGraphMarker(CDC* pDC);
	int GetPow(double* val);
	afx_msg void OnViewAxis();
	afx_msg void OnUpdateViewAxis(CCmdUI *pCmdUI);
	afx_msg void OnViewWindowsize();
	afx_msg void OnUpdateViewWindowsize(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnEditRemovecurrent();
	afx_msg void OnUpdateEditRemovecurrent(CCmdUI *pCmdUI);
	afx_msg void OnDefaultsize();
	afx_msg void OnUpdateDefaultsize(CCmdUI *pCmdUI);
	afx_msg void OnViewGraph();
	afx_msg void OnUpdateViewGraph(CCmdUI *pCmdUI);
	afx_msg void OnViewSize();
	afx_msg void OnUpdateViewSize(CCmdUI *pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void DrawClickRect(int x_cl, int y_cl, int px, int py);
	void GetNFormat(char* Nformat, int tol, bool e_f);
	void ValToStr(char* buf, int size_max, int tol, bool e_v, double val);
	afx_msg void OnEditTransform();
	afx_msg void OnUpdateEditTransform(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFileAddfunction(CCmdUI *pCmdUI);
	afx_msg void OnFileAddfunction();
	afx_msg void OnEditApproximation();
	afx_msg void OnUpdateEditApproximation(CCmdUI *pCmdUI);
	afx_msg void OnFileExportdata();
	void OnExportData(CString path = "");
	afx_msg void OnUpdateFileExportdata(CCmdUI *pCmdUI);
	unsigned int ReadSizeData(char* buf, unsigned long int k);
	unsigned int ReadWndSizeData(char* buf, unsigned long int k);
	unsigned int ReadAppData(char* buf, unsigned long int k, unsigned long int size, CGraph* graphs);
	unsigned int ReadAplData(char* buf, unsigned long int k, unsigned long int size, CGraph* graphs);
	unsigned int ReadGraphData(char* buf, unsigned long int k, unsigned long int size, int f_mode, CGraph* graphs);
	unsigned int ReadTextData(char* buf, unsigned long int k, unsigned long int size);
	void SetFileFormats();
	afx_msg void OnEditRemoveall();
	afx_msg void OnUpdateEditRemoveall(CCmdUI *pCmdUI);
	afx_msg void OnFileImagetodata();
	afx_msg void OnUpdateFileImagetodata(CCmdUI *pCmdUI);
	afx_msg void OnSmoothingRemovespikes();
	afx_msg void OnUpdateSmoothingRemovespikes(CCmdUI *pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnApproximationCustom();
	afx_msg void OnUpdateApproximationCustom(CCmdUI* pCmdUI);
	afx_msg void OnApproximationPolynomial();
	afx_msg void OnUpdateApproximationPolynomial(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditAverage(CCmdUI* pCmdUI);
	afx_msg void OnEditAverage();
	void AddGraphFromFile(CString path, CString fn, CGraph *graphs,  int mode, bool write_undo);
	afx_msg void OnFileSettings();
	afx_msg void OnUpdateFileSettings(CCmdUI* pCmdUI);
	afx_msg void OnSmoothingSimplespline();
	afx_msg void OnUpdateSmoothingSimplespline(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewPolar(CCmdUI* pCmdUI);
	afx_msg void OnViewPolar();
	afx_msg void OnIntegral();
	afx_msg void OnUpdateIntegral(CCmdUI* pCmdUI);
	void DrawIntegralLine(int x);
	double GetIntegral(double x1int, double x2int, int N_gr);
	afx_msg void OnEditCombine();
	afx_msg void OnUpdateEditCombine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRemoveRemoveallbutcurrent(CCmdUI* pCmdUI);
	afx_msg void OnRemoveRemoveallbutcurrent();
	afx_msg void OnEditSplit();
	afx_msg void OnUpdateEditSplit(CCmdUI* pCmdUI);
	afx_msg void OnFileExportcurrent();
	afx_msg void OnUpdateFileExportcurrent(CCmdUI* pCmdUI);
	afx_msg void OnRemovePoints();
	afx_msg void OnUpdateRemovePoints(CCmdUI* pCmdUI);
	afx_msg void OnLeftbtn();
	afx_msg void OnUpdateLeftbtn(CCmdUI* pCmdUI);
	afx_msg void OnRightbtn();
	afx_msg void OnUpdateRightbtn(CCmdUI* pCmdUI);
	afx_msg void OnUpbtn();
	afx_msg void OnUpdateUpbtn(CCmdUI* pCmdUI);
	afx_msg void OnDownbtn();
	afx_msg void OnUpdateDownbtn(CCmdUI* pCmdUI);
	afx_msg void OnGraphdraw();
	afx_msg void OnUpdateGraphdraw(CCmdUI* pCmdUI);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnUpdateEditCrop(CCmdUI* pCmdUI);
	afx_msg void OnEditCrop();
	afx_msg void OnBackgroundcorrectionShirley();
	afx_msg void OnUpdateBackgroundcorrectionShirley(CCmdUI* pCmdUI);
	afx_msg void OnBackgroundcorrectionShape();
	afx_msg void OnUpdateBackgroundcorrectionShape(CCmdUI* pCmdUI);
	afx_msg void OnBackgroundcorrectionPolynomial();
	afx_msg void OnUpdateBackgroundcorrectionPolynomial(CCmdUI* pCmdUI);
	afx_msg void OnEditMerge();
	afx_msg void OnUpdateEditMerge(CCmdUI* pCmdUI);
	afx_msg void OnBatchoperationAnalyze();
	afx_msg void OnUpdateBatchoperationAnalyze(CCmdUI* pCmdUI);
	afx_msg void OnBatchoperationTransform();
	afx_msg void OnUpdateBatchoperationTransform(CCmdUI* pCmdUI);
	afx_msg void OnFileSaveaseps();
	afx_msg void OnUpdateFileSaveaseps(CCmdUI* pCmdUI);
	afx_msg void OnButton32816();
	afx_msg void OnUpdateButton32816(CCmdUI* pCmdUI);
	afx_msg void OnButton32817();
	afx_msg void OnUpdateButton32817(CCmdUI* pCmdUI);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRemoveTexts();
	afx_msg void OnUpdateRemoveTexts(CCmdUI* pCmdUI);
	afx_msg void OnButton32819();
	afx_msg void OnUpdateButton32819(CCmdUI* pCmdUI);
	afx_msg void OnApproximationVoight();
	afx_msg void OnUpdateApproximationVoight(CCmdUI* pCmdUI);
	void UpdateVoight();
	void SetSettings();
	afx_msg void OnApproximationHide();
	afx_msg void OnUpdateApproximationHide(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewApproximation(CCmdUI* pCmdUI);
	afx_msg void OnViewApproximation();
	double GetError(int n_exp, double* x_exp, double* y_exp, double* FWHM, double* x, double* n, double* H);
	afx_msg void OnButton32825();
	afx_msg void OnUpdateButton32825(CCmdUI* pCmdUI);
	afx_msg void OnViewRecolorgraphs();
	afx_msg void OnUpdateViewRecolorgraphs(CCmdUI* pCmdUI);
	COLORREF CGraphView::ValueToColor(double min, double max, double val, int pallete);
	void ClearMarker();
	void WriteUndo();
	afx_msg void OnEditRestore();
	afx_msg void OnUpdateEditRestore(CCmdUI* pCmdUI);
	afx_msg void OnEditUndo32830();
	afx_msg void OnUpdateEditUndo32830(CCmdUI* pCmdUI);
	afx_msg void OnSmoothingStepcross();
	afx_msg void OnUpdateSmoothingStepcross(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // debug version in GraphView.cpp
inline CGraphDoc* CGraphView::GetDocument() const
   { return reinterpret_cast<CGraphDoc*>(m_pDocument); }
#endif

