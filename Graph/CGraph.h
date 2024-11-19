#pragma once
#include "tinyexpr.h"
#include "CreEPS.hpp"
#define pi 3.14159265358979323846
extern void GetLinearSystemRoot(double* A, int N, double* x, double* b);
extern void SwapStrings(double* A, int i, int j, int N);

inline void MoveToG(double xx, double yy, CDC* pDC, int marker, int line_width)
{
	int x = (int)(xx + 0.5);
	int y = (int)(yy + 0.5);
	if (marker == 1)
	{
		pDC->Arc(x - 5 - line_width, y - 5 - line_width, x + 5 + line_width, y + 5 + line_width, -1, -1, -1, -1);
	}
	if (marker == 2)
	{
		pDC->MoveTo(x - 6, y - 6);
		pDC->LineTo(x + 6, y + 6);
		pDC->MoveTo(x + 6, y - 6);
		pDC->LineTo(x - 6, y + 6);
	}
	if (marker == 3)
	{
		pDC->MoveTo(x - 6, y - 6);
		pDC->LineTo(x + 6, y - 6);
		pDC->LineTo(x + 6, y + 6);
		pDC->LineTo(x - 6, y + 6);
		pDC->LineTo(x - 6, y - 6);
	}
	if (marker == 4)
	{
		pDC->Arc(x - 7, y - 7, x + 7, y + 7, -1, -1, -1, -1);
	}
	pDC->MoveTo(x, y);
}
inline CPoint LineToG(double xx, double yy, double xx_pr, double yy_pr, CDC* pDC, int marker, int line_width, CBrush *br, bool first)
{
	int x, y, x_pr, y_pr;
	
	if (xx >= 0) x = (int)(xx + 0.5);
	if (xx < 0) x = (int)(xx - 0.5);
	if (yy >= 0) y = (int)(yy + 0.5);
	if (yy < 0) y = (int)(yy - 0.5);
	
	if (xx_pr >= 0) x_pr = (int)(xx_pr + 0.5);
	if (xx_pr < 0) x_pr = (int)(xx_pr - 0.5);
	if (yy_pr >= 0) y_pr = (int)(yy_pr + 0.5);
	if (yy_pr < 0) y_pr = (int)(yy_pr - 0.5);

	bool ffirst = first;

	if (marker != 4 && marker != 5)
	{
		pDC->LineTo(x, y);
	}
	else
	{
		if (marker == 4)
		{
			pDC->Arc(x - 7, y - 7, x + 7, y + 7, -1, -1, -1, -1);
		}
		if (marker == 5)
		{
			while (1)
			{
				if (ffirst)
				{
					CRgn rgn;
					rgn.CreateEllipticRgn(x_pr - line_width, y_pr - line_width, x_pr + line_width, y_pr + line_width);
					pDC->FillRgn(&rgn, br);
					DeleteObject(rgn);
					ffirst = false;
				}
				double l_tot = sqrt((xx - x_pr) * (xx - x_pr) + (yy - y_pr) * (yy - y_pr));
				if (l_tot < 2.5 * line_width)
				{
					return CPoint(x_pr, y_pr);
				}
				else
				{
					int cx = x_pr + 2.5 * line_width * (xx - x_pr) / l_tot;
					int cy = y_pr + 2.5 * line_width * (yy - y_pr) / l_tot;
					CRgn rgn;
					rgn.CreateEllipticRgn(cx - line_width, cy - line_width, cx + line_width, cy + line_width);
					pDC->FillRgn(&rgn, br);
					DeleteObject(rgn);
					x_pr = cx;
					y_pr = cy;
				}
			}
		}
	}
	if (marker == 1)
	{
		pDC->Arc(x - 5 - line_width, y - 5 - line_width, x + 5 + line_width, y + 5 + line_width, -1, -1, -1, -1);
	}
	if (marker == 2)
	{
		pDC->MoveTo(x - 6, y - 6);
		pDC->LineTo(x + 6, y + 6);
		pDC->MoveTo(x + 6, y - 6);
		pDC->LineTo(x - 6, y + 6);
	}
	if (marker == 3)
	{
		pDC->MoveTo(x - 6, y - 6);
		pDC->LineTo(x + 6, y - 6);
		pDC->LineTo(x + 6, y + 6);
		pDC->LineTo(x - 6, y + 6);
		pDC->LineTo(x - 6, y - 6);
	}
	return CPoint(0, 0);
}
inline void Draw_Graph(CDC* pDC, CRect r_client, double x_min, double x_max, double y_min, double y_max, double *X, double *Y, int line_width, COLORREF col, unsigned int length, int marker, bool save_eps, ns_creeps::CreEPS* eps, int bot_mar)
{
	CPen* oldpen = 0;
	CPen pen; CBrush br;
	if (!save_eps)
	{
		pen.CreatePen(PS_SOLID, line_width, col);
		br.CreateSolidBrush(col);
		oldpen = pDC->SelectObject(&pen);
	}

	double xminc = 0, xmaxc = 0, yminc = 0, ymaxc = 0;
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	double mx = 0, my = 0, lx = 0, ly = 0;
	double xc1 = 0, xc2 = 0, yc1 = 0, yc2 = 0; BOOL def1c;
	double t1 = 0, t2 = 0;

	double cl_lm = r_client.left;
	double cl_W = r_client.right - r_client.left;
	double cl_bm = r_client.bottom;
	double cl_H = r_client.bottom - r_client.top;

	double x_move=0, y_move=0, x_line=0, y_line=0;

	bool path_start = false; bool marker_start = false;

	CPoint P_last(0, 0);
	bool first = true;

	for (unsigned int i = 0; i<length - 1; i++)
	{
		//segment out of window
		if ((X[i] > x_max && X[i + 1] > x_max) || (X[i] < x_min && X[i + 1] < x_min) ||
			(Y[i] > y_max && Y[i + 1] > y_max) || (Y[i] < y_min && Y[i + 1] < y_min))
		{
			if (save_eps && path_start)
			{
				eps->endPath(ns_creeps::CreEPS::STROKE);
				path_start = false;
			}
		}
		else
		{
			//segment in window
			if (Y[i] <= y_max && Y[i] >= y_min && X[i] >= x_min && X[i] <= x_max &&
				Y[i + 1] <= y_max && Y[i + 1] >= y_min && X[i + 1] >= x_min && X[i + 1] <= x_max)
			{
				if (x_max == x_min)
				{
					x_move = cl_lm + cl_W / 2;
					x_line = cl_lm + cl_W / 2;
				}
				else
				{
					x_move = cl_lm + (X[i] - x_min) * cl_W / (x_max - x_min);
					x_line = cl_lm + (X[i + 1] - x_min) * cl_W / (x_max - x_min);
				}
				if (y_max == y_min)
				{
					y_move = cl_bm - cl_H / 2;
					y_line = cl_bm - cl_H / 2;
				}
				else
				{
					y_move = cl_bm - (Y[i] - y_min) * cl_H / (y_max - y_min);
					y_line = cl_bm - (Y[i + 1] - y_min) * cl_H / (y_max - y_min);
				}
			}
			else//horizontal segment
			if (Y[i] == Y[i + 1])
			{

				if (X[i] <= X[i + 1])
				{
					x1 = X[i]; x2 = X[i + 1];
					y1 = Y[i]; y2 = Y[i + 1];
				}
				else
				{
					x1 = X[i + 1]; x2 = X[i];
					y1 = Y[i + 1]; y2 = Y[i];
				}

				if (Y[i] > y_max || Y[i] < y_min){}
				else
				{
					if (x2<x_min || x1>x_max){}
					else
					{
						if (x1 <= x_min)
						{
							x_move = cl_lm;
							if (y_max == y_min)
							{
								y_move = cl_bm - cl_H / 2;
							}
							else
							{
								y_move = cl_bm - (Y[i] - y_min) * cl_H / (y_max - y_min);
							}
						}
						else
						{
							if (x_max == x_min)
							{
								x_move = cl_lm + cl_W / 2;
							}
							else
							{
								x_move = cl_lm + (x1 - x_min) * cl_W / (x_max - x_min);
							}
							if (y_max == y_min)
							{
								y_move = cl_bm - cl_H / 2;
							}
							else
							{
								y_move = cl_bm - (Y[i] - y_min) * cl_H / (y_max - y_min);
							}
						}

						if (x2 >= x_max)
						{
							x_line = cl_lm + cl_W;
							if (y_max == y_min)
							{
								y_line = cl_bm - cl_H / 2;
							}
							else
							{
								y_line = cl_bm - (Y[i + 1] - y_min) * cl_H / (y_max - y_min);
							}
						}
						else
						{
							if (x_max == x_min)
							{
								x_line = cl_lm + cl_W / 2;
							}
							else
							{
								x_line = cl_lm + (x2 - x_min) * cl_W / (x_max - x_min);
							}
							if (y_max == y_min)
							{
								y_line = cl_bm - cl_H / 2;
							}
							else
							{
								y_line = cl_bm - (Y[i + 1] - y_min) * cl_H / (y_max - y_min);
							}
						}
					}
				}
			}
			else//vertical segment
			if (X[i] == X[i + 1])
			{
				if (Y[i] <= Y[i + 1])
				{
					x1 = X[i]; x2 = X[i + 1];
					y1 = Y[i]; y2 = Y[i + 1];
				}
				else
				{
					x1 = X[i + 1]; x2 = X[i];
					y1 = Y[i + 1]; y2 = Y[i];
				}

				if (X[i] > x_max || X[i] < x_min){}
				else
				{
					if (y2<y_min || y1>y_max){}
					else
					{
						if (y1 <= y_min)
						{
							if (x_max == x_min)
							{
								x_move = cl_lm + cl_W / 2;
							}
							else
							{
								x_move = cl_lm + (X[i] - x_min) * cl_W / (x_max - x_min);
							}
							y_move = cl_bm;
						}
						else
						{
							if (x_max == x_min)
							{
								x_move = cl_lm + cl_W / 2;
							}
							else
							{
								x_move = cl_lm + (X[i] - x_min) * cl_W / (x_max - x_min);
							}
							if (y_max == y_min)
							{
								y_move = cl_bm - cl_H / 2;
							}
							else
							{
								y_move = cl_bm - (y1 - y_min) * cl_H / (y_max - y_min);
							}
						}
						if (y2 >= y_max)
						{
							if (x_max == x_min)
							{
								x_line = cl_lm + cl_W / 2;
							}
							else
							{
								x_line = cl_lm + (X[i] - x_min) * cl_W / (x_max - x_min);
							}
							y_line = r_client.top;
						}
						else
						{
							if (x_max == x_min)
							{
								x_line = cl_lm + cl_W / 2;
							}
							else
							{
								x_line = cl_lm + (X[i + 1] - x_min) * cl_W / (x_max - x_min);
							}
							if (y_max == y_min)
							{
								y_line = cl_bm - cl_H / 2;
							}
							else
							{
								y_line = cl_bm - (y2 - y_min) * cl_H / (y_max - y_min);
							}
						}
					}
				}
			}
			else//not vertical or horizontal segment
			{
				xminc = X[i] + (X[i] - X[i + 1])*(y_min - Y[i]) / (Y[i] - Y[i + 1]);
				xmaxc = X[i] + (X[i] - X[i + 1])*(y_max - Y[i]) / (Y[i] - Y[i + 1]);
				yminc = Y[i] + (Y[i] - Y[i + 1])*(x_min - X[i]) / (X[i] - X[i + 1]);
				ymaxc = Y[i] + (Y[i] - Y[i + 1])*(x_max - X[i]) / (X[i] - X[i + 1]);
				//xminc - coordinate where line(x[i], x[i+1]) crosses the line y=ymin
				//xmaxc - coordinate where line(x[i], x[i+1]) crosses the line y=ymax
				//yminc - coordinate where line(x[i], x[i+1]) crosses the line x=xmin
				//ymaxc - coordinate where line(x[i], x[i+1]) crosses the line x=xmax
				if ((xminc<x_min || xminc>x_max) && (xmaxc<x_min || xmaxc>x_max) &&
					(yminc<y_min || yminc>y_max) && (ymaxc<y_min || ymaxc>y_max))
				{
				}
				else
				{
					def1c = FALSE;
					if (xminc <= x_max&&xminc >= x_min)
					{
						xc1 = xminc;
						yc1 = y_min;
						def1c = TRUE;
					}
					if (xmaxc <= x_max&&xmaxc >= x_min)
					{
						if (def1c)
						{
							xc2 = xmaxc;
							yc2 = y_max;
						}
						else
						{
							xc1 = xmaxc;
							yc1 = y_max;
							def1c = TRUE;
						}
					}
					if (ymaxc <= y_max&&ymaxc >= y_min)
					{
						if (def1c)
						{
							xc2 = x_max;
							yc2 = ymaxc;
						}
						else
						{
							xc1 = x_max;
							yc1 = ymaxc;
							def1c = TRUE;
						}
					}
					if (yminc <= y_max&&yminc >= y_min)
					{
						if (def1c)
						{
							xc2 = x_min;
							yc2 = yminc;
						}
						else
						{
							xc1 = x_min;
							yc1 = yminc;
							def1c = TRUE;
						}
					}
					//(xc1, yc1), (xc2, yc2) - points where line(x[i], x[i+1]) crosses
					//rectangle(xmin, xmax, ymin, ymax)

					if (xc1 > xc2)
					{
						t1 = xc1; t2 = yc1;
						xc1 = xc2; yc1 = yc2;
						xc2 = t1; yc2 = t2;
					}

					if (X[i] <= X[i + 1])
					{
						x1 = X[i]; x2 = X[i + 1];
						y1 = Y[i]; y2 = Y[i + 1];
					}
					else
					{
						x1 = X[i + 1]; x2 = X[i];
						y1 = Y[i + 1]; y2 = Y[i];
					}

					if (x1 >= x_min&&y1 >= y_min&&y1 <= y_max&&x1 <= x_max)
					{
						mx = x1; my = y1;
					}
					else
					{
						mx = xc1; my = yc1;
					}

					if (x2 >= x_min&&y2 >= y_min&&y2 <= y_max&&x2 <= x_max)
					{
						lx = x2; ly = y2;
					}
					else
					{
						lx = xc2; ly = yc2;
					}
					x_move = cl_lm + (mx - x_min)*cl_W / (x_max - x_min);
					y_move = cl_bm - (my - y_min)*cl_H / (y_max - y_min);
					x_line = cl_lm + (lx - x_min)*cl_W / (x_max - x_min);
					y_line = cl_bm - (ly - y_min)*cl_H / (y_max - y_min);
				}
			}
			if (!save_eps)
			{
				if (!((int)(x_move + 0.5) == (int)(x_line + 0.5) && (int)(y_move + 0.5) == (int)(y_line + 0.5)))
				{
					MoveToG(x_move, y_move, pDC, marker, line_width);
					if (first)
					{
						P_last = LineToG(x_line, y_line, x_move, y_move, pDC, marker, line_width, &br, true);
						first = false;
					}
					else
					{
						P_last = LineToG(x_line, y_line, P_last.x, P_last.y, pDC, marker, line_width, &br, false);
					}
				}
			}
			else
			{
				if (marker == 0 || marker == 5)
				{
					if (!path_start)
					{
						if(marker==0)
							eps->setAttributes(ns_creeps::CAtLineThickness(line_width) | ns_creeps::CAtColor(GetRValue(col) / 255.0, GetGValue(col) / 255.0, GetBValue(col) / 255.0) | ns_creeps::CAtLineJoin(ns_creeps::CAt::LJ_ROUND));
						if(marker==5)
							eps->setAttributes(ns_creeps::CAtLineThickness(line_width*1.5) | ns_creeps::CAtColor(GetRValue(col) / 255.0, GetGValue(col) / 255.0, GetBValue(col) / 255.0) | ns_creeps::CAtLineJoin(ns_creeps::CAt::LJ_ROUND) | ns_creeps::CAtLineCap(ns_creeps::CAt::LC_ROUND) | ns_creeps::CAtLineDash(ns_creeps::CAt::DOT, 0));
						eps->startPath(x_move, bot_mar + cl_bm - y_move);
						path_start = true;
					}
					eps->addLine(x_line, bot_mar + cl_bm - y_line);
				}
				else
				{
					if (!marker_start)
					{
						eps->setAttributes(ns_creeps::CAtLineThickness(line_width) | ns_creeps::CAtColor(GetRValue(col) / 255.0, GetGValue(col) / 255.0, GetBValue(col) / 255.0) | ns_creeps::CAtLineJoin(ns_creeps::CAt::LJ_ROUND));
					}
					int xx1 = (int)(x_move + 0.5); int xx2 = (int)(x_line + 0.5);
					int yy1 = (int)(bot_mar + cl_bm - y_move + 0.5);
					int yy2 = (int)(bot_mar + cl_bm - y_line + 0.5);
					if (marker == 1)
					{
						if (!marker_start)
						{
							eps->circle(xx1, yy1, 6);
						}
						eps->circle(xx2, yy2, 6);
					}
					if (marker == 2)
					{
						if (!marker_start)
						{
							eps->line(xx1 - 6, yy1 - 6, xx1 + 6, yy1 + 6);
							eps->line(xx1 + 6, yy1 - 6, xx1 - 6, yy1 + 6);
						}
						eps->line(xx2 - 6, yy2 - 6, xx2 + 6, yy2 + 6);
						eps->line(xx2 + 6, yy2 - 6, xx2 - 6, yy2 + 6);
					}
					if (marker == 3)
					{
						if (!marker_start)
						{
							eps->startPath(xx1 - 6, yy1 - 6);
							eps->addLine(xx1 + 6, yy1 - 6);
							eps->addLine(xx1 + 6, yy1 + 6);
							eps->addLine(xx1 - 6, yy1 + 6);
							eps->addLine(xx1 - 6, yy1 - 6);
							eps->endPath(ns_creeps::CreEPS::STROKE);
						}
						eps->startPath(xx2 - 6, yy2 - 6);
						eps->addLine(xx2 + 6, yy2 - 6);
						eps->addLine(xx2 + 6, yy2 + 6);
						eps->addLine(xx2 - 6, yy2 + 6);
						eps->addLine(xx2 - 6, yy2 - 6);
						eps->endPath(ns_creeps::CreEPS::STROKE);
					}
					if (marker == 4)
					{
						if (!marker_start)
						{
							eps->circle(xx1, yy1, 7);
						}
						eps->circle(xx2, yy2, 7);
					}
					if (marker != 4)
					{
						eps->line(xx1, yy1, xx2, yy2);
					}

					if (!marker_start)
					{
						marker_start = true;
					}
				}
			}
		}
		if (save_eps && i == length - 2&& path_start)
		{
			eps->endPath(ns_creeps::CreEPS::STROKE);
		}
	}
	if (!save_eps)
	{
		pDC->SelectObject(oldpen);
		DeleteObject(pen);
		DeleteObject(br);
	}
	if (save_eps && marker == 5)
	{
		eps->setAttributes(ns_creeps::CAtLineDash(ns_creeps::CAt::SOLID, 0));
	}
}

class CGraph
{
public:
	double *X; double *Y; unsigned int length; //numeric data
	COLORREF col; int line_width; int marker; //presentation
	CString name;
	int index;
	CGraph* next;
	//approximation data
	double app_var_min[5], app_var_max[5], app_var_val[5];
	int app_var_N[5];
	bool draw_app;
	CString app_eq; COLORREF app_col[2]; int app_line_width[2];
	double poly_fit[10];

	CGraph* operator [] (int a)
	{
		if (index == a)
		{
			return this;
		}
		if (next == 0)
		{
			return 0;
		}
		return next->operator[](a);
	}
	//CGraph[0] contains no data, it is just a start of the list
	bool IsLast()
	{
		return next == 0;
	}
	int GetNLast()
	{
		if (next == 0)
		{
			return index;
		}
		return next->GetNLast();
	}
	void Init(int n)
	{
		index = n;
		next = 0;
		length = 0;
		name = "";
		for (int i = 0; i<5; i++)
		{
			app_var_min[i] = 0; app_var_max[i] = 1; app_var_N[i] = 1; app_var_val[i] = 0;
		}
		app_line_width[0] = 2; app_line_width[1] = 2;
		app_col[0] = RGB(0, 0, 0); app_col[1] = RGB(0, 0, 0);
		app_eq = "";
		for (int i = 0; i < 10; i++)
		{
			poly_fit[i] = 0;
		}
		draw_app = false;
	}
	void AddData(double *x, double *y, unsigned int N, CString str)
	{
		if (length == 0 && index > 0)
		{
			name = str;
			X = new double [N];
			Y = new double [N];
			for (unsigned int i = 0; i < N; i++)
			{
				X[i] = x[i];
				Y[i] = y[i];
			}
			length = N;
			line_width = 2;
			marker = 0;
			COLORREF color;
			switch (index)
			{
			case 0:
				color = RGB(255, 0, 0);
				break;
			case 1:
				color = RGB(0, 0, 255);
				break;
			case 2:
				color = RGB(0, 127, 0);
				break;
			case 3:
				color = RGB(200, 0, 200);
				break;
			case 4:
				color = RGB(200, 200, 0);
				break;
			case 5:
				color = RGB(0, 200, 200);
				break;
			case 6:
				color = RGB(100, 100, 0);
				break;
			case 7:
				color = RGB(0, 100, 100);
				break;
			case 8:
				color = RGB(100, 0, 100);
				break;
			case 9:
				color = RGB(127, 127, 127);
				break;
			default:
				color = RGB(0, 0, 0);
			}
			col = color;
			return;
		}
		if (next == 0)
		{
			next = new CGraph;
			next->Init(index+1);
		}
		next->AddData(x, y, N, str);
	}
	void SetAppData(double *d_app_var_min, double *d_app_var_max, double *d_app_var_val, int *d_app_var_N, CString d_app_eq, double *p_app)
	{
		for (int i = 0; i < 5; i++)
		{
			app_var_min[i] = d_app_var_min[i];
			app_var_max[i] = d_app_var_max[i];
			app_var_val[i] = d_app_var_val[i];
			app_var_N[i] = d_app_var_N[i];
		}
		app_eq = d_app_eq;
		for (int i = 0; i < 10; i++)
		{
			poly_fit[i] = p_app[i];
		}
	}
	void RemoveGraph(int n)
	{
		if (next == 0)
		{
			return;
		}
		if (next->index == n)
		{
			if (next->length > 0)
			{
				delete[] next->X;
				delete[] next->Y;
			}
			CGraph* temp = next->next;
			delete next;
			next = temp;
			return;
		}
		next->RemoveGraph(n);
	}
	void Renumber(int n_cur)
	{
		index = n_cur;
		if (next == 0) return;
		next->Renumber(n_cur + 1);
	}
	double GetXmax()
	{
		if (length == 0 && next == 0)
		{
			return 0;
		}
		if (length == 0)
		{
			return next->GetXmax();
		}
		double x_max = X[0];
		for (unsigned int i = 0; i < length; i++)
		{
			if (X[i]>x_max) x_max = X[i];
		}
		if (next == 0)
		{
			return x_max;
		}
		return max(x_max, next->GetXmax());
	}
	double GetXmin()
	{
		if (length == 0 && next == 0)
		{
			return 0;
		}
		if (length == 0)
		{
			return next->GetXmin();
		}
		double x_min = X[0];
		for (unsigned int i = 0; i < length; i++)
		{
			if (X[i]<x_min) x_min = X[i];
		}
		if (next == 0)
		{
			return x_min;
		}
		return min(x_min, next->GetXmin());
	}
	double GetYmax()
	{
		if (length == 0 && next == 0)
		{
			return 0;
		}
		if (length == 0)
		{
			return next->GetYmax();
		}
		double y_max = Y[0];
		for (unsigned int i = 0; i < length; i++)
		{
			if (Y[i]>y_max) y_max = Y[i];
		}
		if (next == 0)
		{
			return y_max;
		}
		return max(y_max, next->GetYmax());
	}
	double GetYmin()
	{
		if (length == 0 && next == 0)
		{
			return 0;
		}
		if (length == 0)
		{
			return next->GetYmin();
		}
		double y_min = Y[0];
		for (unsigned int i = 0; i < length; i++)
		{
			if (Y[i]<y_min) y_min = Y[i];
		}
		if (next == 0)
		{
			return y_min;
		}
		return min(y_min, next->GetYmin());
	}
	double GetYmin_X(double x1, double x2)
	{
		if (length == 0 && next == 0)
		{
			return 0;
		}
		bool pt_in_range = false;
		double y_min = 0;
		for (unsigned int i = 0; i < length; i++)
		{
			if (X[i] >= x1 && X[i] <= x2)
			{
				pt_in_range = true;
				y_min = Y[i];
				break;
			}
		}
		if (!pt_in_range)
		{
			return next->GetYmin_X(x1, x2);
		}
		for (unsigned int i = 0; i < length; i++)
		{
			if (X[i] >= x1 && X[i] <= x2)
			{
				if (Y[i] < y_min) y_min = Y[i];
			}
		}
		if (next == 0)
		{
			return y_min;
		}
		return min(y_min, next->GetYmin_X(x1, x2));
	}
	double GetYmax_X(double x1, double x2)
	{
		if (length == 0 && next == 0)
		{
			return 0;
		}
		bool pt_in_range = false;
		double y_max = 0;
		for (unsigned int i = 0; i < length; i++)
		{
			if (X[i] >= x1 && X[i] <= x2)
			{
				pt_in_range = true;
				y_max = Y[i];
				break;
			}
		}
		if (!pt_in_range)
		{
			return next->GetYmax_X(x1, x2);
		}
		for (unsigned int i = 0; i < length; i++)
		{
			if (X[i] >= x1 && X[i] <= x2)
			{
				if (Y[i] > y_max) y_max = Y[i];
			}
		}
		if (next == 0)
		{
			return y_max;
		}
		return max(y_max, next->GetYmax_X(x1, x2));
	}
	double GetPolarSize(bool deg)
	{
		if (length == 0 && next == 0)
		{
			return 0;
		}
		if (length == 0)
		{
			return next->GetPolarSize(deg);
		}
		/*double max_size = 0;
		if(deg) max_size = abs(Y[0] * cos(X[0] * pi / 180.0));
		else max_size = abs(Y[0] * cos(X[0]));
		for (unsigned int i = 0; i < length; i++)
		{
			if (deg)
			{
				if (abs(Y[i] * cos(X[i] * pi / 180.0)) > max_size) max_size = abs(Y[i] * cos(X[i] * pi / 180.0));
				if (abs(Y[i] * sin(X[i] * pi / 180.0)) > max_size) max_size = abs(Y[i] * sin(X[i] * pi / 180.0));
			}
			else
			{
				if (abs(Y[i] * cos(X[i])) > max_size) max_size = abs(Y[i] * cos(X[i]));
				if (abs(Y[i] * sin(X[i])) > max_size) max_size = abs(Y[i] * sin(X[i]));
			}
		}*/
		double max_size = abs(Y[0]);
		for (unsigned int i = 0; i < length; i++)
		{
			if (abs(Y[i]) > max_size) max_size = abs(Y[i] );
		}
		if (next == 0)
		{
			return max_size;
		}
		return max(max_size, next->GetPolarSize(deg));
	}
	void DeleteAll()
	{
		if (next != 0)
		{
			while (!next->IsLast())
			{
				RemoveGraph(next->index);
			}
			RemoveGraph(next->index);
		}
	}
	void DrawGraph(CDC* pDC, CRect r_client, double x_min, double x_max, double y_min, double y_max, bool polar, bool polar_deg, bool save_eps, ns_creeps::CreEPS* eps, int bot_mar)
	{
		if (polar)
		{
			double* x_pol = new double[length];
			double* y_pol = new double[length];
			for (unsigned int i = 0; i < length; i++)
			{
				if(polar_deg)
				{ 
					x_pol[i] = Y[i] * cos(X[i]*pi/180.0);
					y_pol[i] = Y[i] * sin(X[i]*pi/180.0);
				}
				else
				{
					x_pol[i] = Y[i] * cos(X[i]);
					y_pol[i] = Y[i] * sin(X[i]);
				}
			}
			Draw_Graph(pDC, r_client, x_min, x_max, y_min, y_max, x_pol, y_pol, line_width, col, length, marker, save_eps, eps, bot_mar);
			delete[] x_pol;
			delete[] y_pol;
		}
		else
		{
			Draw_Graph(pDC, r_client, x_min, x_max, y_min, y_max, X, Y, line_width, col, length, marker, save_eps, eps, bot_mar);
		}
	}
	void DrawApp(CDC* pDC, CRect r_client, double x_min, double x_max, double y_min, double y_max, bool polar, bool polar_deg, bool save_eps, ns_creeps::CreEPS* eps, int bot_mar, CGraph *gr_0)
	{
		bool draw = false;
		for (int i = 0; i < 5; i++)
		{
			if (app_var_val[i] != 0) draw = true;
		}
		if (draw&&draw_app)
		{
			double x;
			double y_var[5];
			te_variable vars[] = { { "x", &x }, { "A", &app_var_val[0] }, { "B", &app_var_val[1] }, { "C", &app_var_val[2] }, { "D", &app_var_val[3] }, { "E", &app_var_val[4] }, { "y1", &y_var[0]}, {"y2", &y_var[1]}, {"y3", &y_var[2]}, {"y4", &y_var[3]}, {"y5", &y_var[4]} };
			int err;
			te_expr* expr_y = te_compile(app_eq, vars, 11, &err);
			if (!expr_y)
			{
				return;
			}
			int Npx = r_client.right - r_client.left;
			double* x_app = new double[Npx];
			double* y_app = new double[Npx];
			double x_min_t = x_min;
			double x_max_t = x_max;
			if (polar)
			{
				x_min_t = X[0];
				x_max_t = X[0];
				for (unsigned int i = 0; i < length; i++)
				{
					if (X[i] < x_min_t) x_min_t = X[i];
					if (X[i] > x_max_t) x_max_t = X[i];
				}
			}
			for (int i = 0; i < Npx; i++)
			{
				x_app[i] = x_min_t + i * (x_max_t - x_min_t) / (Npx - 1);
				x = x_app[i];

				for (int kkk = 0; kkk < 5; kkk++)
				{
					if (kkk >= gr_0[0][0]->GetNLast())
					{
						y_var[kkk] = 0;
					}
					else
					{
						y_var[kkk] = gr_0[0][kkk + 1]->GetY(x);
					}
				}

				y_app[i] = te_eval(expr_y);
			}
			if (polar)
			{
				for (int i = 0; i < Npx; i++)
				{
					double xx = x_app[i];
					double yy = y_app[i];
					if (polar_deg)
					{
						x_app[i] = yy * cos(xx * pi / 180.0);
						y_app[i] = yy * sin(xx * pi / 180.0);
					}
					else
					{
						x_app[i] = yy * cos(xx);
						y_app[i] = yy * sin(xx);
					}
				}
			}
			Draw_Graph(pDC, r_client, x_min, x_max, y_min, y_max, x_app, y_app, app_line_width[0], app_col[0], Npx, 0, save_eps, eps, bot_mar);
			
			te_free(expr_y);
			delete[] x_app;
			delete[] y_app;
		}
		draw = false;
		for (int i = 0; i < 10; i++)
		{
			if (poly_fit[i] != 0) draw = true;
		}
		if (draw)
		{
			double x;
			int Npx = r_client.right - r_client.left;
			double* x_app = new double[Npx];
			double* y_app = new double[Npx];
			double x_min_t = x_min;
			double x_max_t = x_max;
			if (polar)
			{
				x_min_t = X[0];
				x_max_t = X[0];
				for (unsigned int i = 0; i < length; i++)
				{
					if (X[i] < x_min_t) x_min_t = X[i];
					if (X[i] > x_max_t) x_max_t = X[i];
				}
			}
			for (int i = 0; i < Npx; i++)
			{
				x_app[i] = x_min_t + i * (x_max_t - x_min_t) / (Npx - 1);
				x = x_app[i];
				y_app[i] = poly_fit[0] + poly_fit[1] * x + poly_fit[2] * x * x + poly_fit[3] * x * x * x +
					poly_fit[4] * x * x * x * x + poly_fit[5] * x * x * x * x * x + poly_fit[6] * x * x * x * x * x * x +
					poly_fit[7] * x * x * x * x * x * x * x + poly_fit[8] * x * x * x * x * x * x * x * x +
					poly_fit[9] * x * x * x * x * x * x * x * x * x;
			}
			if (polar)
			{
				for (int i = 0; i < Npx; i++)
				{
					double xx = x_app[i];
					double yy = y_app[i];
					if (polar_deg)
					{
						x_app[i] = yy * cos(xx * pi / 180.0);
						y_app[i] = yy * sin(xx * pi / 180.0);
					}
					else
					{
						x_app[i] = yy * cos(xx);
						y_app[i] = yy * sin(xx);
					}
				}
			}
			Draw_Graph(pDC, r_client, x_min, x_max, y_min, y_max, x_app, y_app, app_line_width[1], app_col[1], Npx, 0, save_eps, eps, bot_mar);
			delete[] x_app;
			delete[] y_app;
		}
	}
	void DrawAll(CDC* pDC, CRect r_client, double x_min, double x_max, double y_min, double y_max, bool polar, bool polar_deg, bool save_eps, ns_creeps::CreEPS *eps, int bot_mar, bool hide_app, CGraph*gr_0)
	{
		if (index == 0)
		{
			if (next == 0) return;
			next->DrawAll(pDC, r_client, x_min, x_max, y_min, y_max, polar, polar_deg, save_eps, eps, bot_mar, hide_app, gr_0);
			return;
		}
		if (next == 0)
		{
			DrawGraph(pDC, r_client, x_min, x_max, y_min, y_max, polar, polar_deg, save_eps, eps, bot_mar);
			if(!hide_app)
				DrawApp(pDC, r_client, x_min, x_max, y_min, y_max, polar, polar_deg, save_eps, eps, bot_mar, gr_0);
			return;
		}
		DrawGraph(pDC, r_client, x_min, x_max, y_min, y_max, polar, polar_deg, save_eps, eps, bot_mar);
		if (!hide_app)
			DrawApp(pDC, r_client, x_min, x_max, y_min, y_max, polar, polar_deg, save_eps, eps, bot_mar, gr_0);
		next->DrawAll(pDC, r_client, x_min, x_max, y_min, y_max, polar, polar_deg, save_eps, eps, bot_mar, hide_app, gr_0);
	}
	double GetY(double x)
	{
		if (x <= min(X[0], X[length - 1]))
		{
			if (X[0] < X[length - 1])
				return Y[0];
			else
				return Y[length - 1];
		}
		if (x >= max(X[0], X[length - 1]))
		{
			if (X[0] > X[length - 1])
				return Y[0];
			else
				return Y[length - 1];
		}
		for (unsigned int i = 0; i < length - 1; i++)
		{
			if (x >= min(X[i], X[i + 1]) && x <= max(X[i], X[i + 1]))
			{
				if (X[i] < X[i + 1])
				{
					return Y[i] + (x - X[i]) * (Y[i + 1] - Y[i]) / (X[i + 1] - X[i]);
				}
				else
				{
					return Y[i + 1] + (x - X[i + 1]) * (Y[i] - Y[i + 1]) / (X[i] - X[i + 1]);
				}
			}
		}
		return 0;
	}
	void CopySerData(CGraph* grr)
	{
		col = grr->col;
		line_width = grr->line_width;
		marker = grr->marker;
		name = grr->name;
		for (int i = 0; i < 5; i++)
		{
			app_var_min[i] = grr->app_var_min[i];
			app_var_max[i] = grr->app_var_max[i];
			app_var_val[i] = grr->app_var_val[i];
			app_var_N[i] = grr->app_var_N[i];
		}
		app_eq = grr->app_eq;
		app_col[0] = grr->app_col[0];
		app_col[1] = grr->app_col[1];
		app_line_width[0] = grr->app_line_width[0];
		app_line_width[1] = grr->app_line_width[1];
		for (int i = 0; i < 10; i++)
		{
			poly_fit[i] = grr->poly_fit[i];
		}
	}
	void Crop(double crop_min, double crop_max, double crop_y_min, double crop_y_max)
	{
		int k = 0;
		bool ignore_pt;

		double x_min = X[0]; double x_max = X[0];
		for (int i = 0; i < length; i++)
		{
			if (X[i] < x_min) x_min = X[i];
			if (X[i] > x_max) x_max = X[i];
		}
		bool add_min_pt = false;
		double y_x_min = 0;
		if (crop_min > x_min)
		{
			add_min_pt = true;
			y_x_min = GetY(crop_min);
		}
		bool add_max_pt = false;
		double y_x_max = 0;
		if (crop_max < x_max)
		{
			add_max_pt = true;
			y_x_max = GetY(crop_max);
		}
		
		for (unsigned int j = 0; j < length; j++)
		{
			ignore_pt = false;
			if (crop_min != crop_max && (X[j] > max(crop_min, crop_max) || X[j] < min(crop_min, crop_max)))
			{
				ignore_pt = true;
			}
			if (crop_y_min != crop_y_max && (Y[j] > max(crop_y_min, crop_y_max) || Y[j] < min(crop_y_min, crop_y_max)))
			{
				ignore_pt = true;
			}

			if (!ignore_pt)
			{
				X[k] = X[j];
				Y[k] = Y[j];
				k++;
			}
		}
		length = k;
		if (X[0] < X[length - 1])
		{
			if (add_min_pt && X[0] != x_min)
			{
				for (int i = length; i > 0; i--)
				{
					X[i] = X[i - 1];
					Y[i] = Y[i - 1];
				}
				X[0] = crop_min;
				Y[0] = y_x_min;
				length++;
			}
			if (add_max_pt && X[length - 1] != x_max)
			{
				X[length] = crop_max;
				Y[length] = y_x_max;
				length++;
			}
		}
		else
		{
			if (add_max_pt && X[0] != x_max)
			{
				for (int i = length; i > 0; i--)
				{
					X[i] = X[i - 1];
					Y[i] = Y[i - 1];
				}
				X[0] = crop_max;
				Y[0] = y_x_max;
				length++;
			}
			if (add_min_pt && X[length - 1] != x_min)
			{
				X[length] = crop_min;
				Y[length] = y_x_min;
				length++;
			}
		}
	}
	void Transform(CString trans_x, CString trans_y)
	{
		char buf[100];
		double x, y;
		te_variable vars[] = { { "x", &x }, { "y", &y } };
		int err_x, err_y;
		te_expr* expr_x = te_compile(trans_x, vars, 2, &err_x);
		te_expr* expr_y = te_compile(trans_y, vars, 2, &err_y);
		if (!expr_x)
		{
			sprintf_s(buf, "Parse error at x expression at symbol %d", err_x);
			::MessageBox(0, buf, 0, MB_OK);
			return;
		}
		if (!expr_y)
		{
			sprintf_s(buf, "Parse error at y expression at symbol %d", err_y);
			::MessageBox(0, buf, 0, MB_OK);
			return;
		}

		for (unsigned int i = 0; i < length; i++)
		{
			x = X[i];
			y = Y[i];
			X[i] = te_eval(expr_x);
			Y[i] = te_eval(expr_y);
		}
		te_free(expr_x);
		te_free(expr_y);
	}
	void Combine(CString combine_str, CGraph *graphs)
	{
		char buf[100];

		double y[7];
		te_variable vars[] = { { "y1", &y[0]}, {"y2", &y[1]}, {"y3", &y[2]}, {"y4", &y[3]}, {"y5", &y[4]}, {"y6", &y[5]}, {"y", &y[6]} };
		int err;
		te_expr* expr = te_compile(combine_str, vars, 7, &err);

		if (!expr)
		{
			sprintf_s(buf, "Parse error at combine expression at symbol %d", err);
			::MessageBox(0, buf, 0, MB_OK);
			return;
		}
		int min_index = 7;
		for (int i = 0; i < combine_str.GetLength() - 1; i++)
		{
			for (int k = 1; k <= 7; k++)
			{
				if (combine_str.GetAt(i) == 'y' && combine_str.GetAt(i + 1) == k + '0')
				{
					if (min_index > k) min_index = k;
				}
			}
		}
		if (graphs[0][0]->GetNLast() < min_index) min_index = 1;

		int nx = graphs[0][min_index]->length;
		double* x_arr = new double[nx];
		double* y_arr = new double[nx];

		for (unsigned int i = 0; i < graphs[0][min_index]->length; i++)
		{
			x_arr[i] = graphs[0][min_index]->X[i];
			y[0] = graphs[0][1]->Y[i];
			for (int k = 1; k < 6; k++)
			{
				if (k >= graphs[0][0]->GetNLast())
				{
					y[k] = 0;
				}
				else
				{
					y[k] = graphs[0][k + 1]->GetY(x_arr[i]);
				}
			}
			y[6] = Y[i];
			y_arr[i] = te_eval(expr);
		}
		te_free(expr);

		for (unsigned int i = 0; i < nx; i++)
		{
			X[i] = x_arr[i];
			Y[i] = y_arr[i];
		}
	}
	void BGShapeCorr(double shape_dx, double shape_dy, double shape_iter)
	{
		int circle_remove_N = min(length * shape_dx / abs(X[0] - X[length - 1]), length);

		int i2 = length - 1;
		int i1 = 0;
		double* B = new double[i2 - i1 + 1];
		bool* B_ini = new bool[i2 - i1 + 1];

		for (int NNN = 0; NNN < shape_iter; NNN++)
		{
			for (int i = 0; i < i2 - i1 + 1; i++)
			{
				B[i] = 0;
				B_ini[i] = false;
			}

			for (int i = i1 - circle_remove_N / 2; i < i2 + 1 + circle_remove_N / 2; i++)
			{
				double minD = 0;
				bool minD_ini = false;
				for (int k = i - circle_remove_N / 2; k <= i + circle_remove_N / 2; k++)
				{
					double y_k = shape_dy * sqrt(1 - (k - i) * (k - i) / (0.25 * circle_remove_N * circle_remove_N));
					double D = 0;
					if (k >= i1 && k <= i2)
					{
						D = Y[k] - y_k;
						if (!minD_ini || D < minD)
						{
							minD_ini = true;
							minD = D;
						}
					}
				}

				for (int k = i - circle_remove_N / 2; k <= i + circle_remove_N / 2; k++)
				{
					double y_k = minD + shape_dy * sqrt(1 - (k - i) * (k - i) / (0.25 * circle_remove_N * circle_remove_N));
					if (k >= i1 && k <= i2)
					{
						if (!B_ini[k - i1] || y_k > B[k - i1])
						{
							B[k - i1] = y_k;
							B_ini[k - i1] = true;
						}
					}
				}
			}
			for (int i = i2; i >= i1; i--)
			{
				Y[i] -= B[i - i1];
			}
		}
		delete[] B;
		delete[] B_ini;
	}
	void BGShirleyCorr()
	{
		unsigned int N = length; double integ;
		double* B = new double[N];
		for (unsigned int i = 0; i < N; i++)
			B[i] = 0;
		for (int K = 0; K < 100; K++)
		{
			integ = 0;
			for (int i = N - 2; i >= 0; i--)
			{
				integ += (Y[i] - Y[N - 1] - B[i]) * (X[i] - X[i + 1]);
				B[i] = integ;
			}
			double k = (Y[0] - Y[N - 1]) / B[0];
			for (unsigned int i = 0; i < N; i++)
			{
				B[i] *= k;
			}
		}
		for (unsigned int i = 0; i < N; i++)
		{
			B[i] += Y[N - 1];
		}
		for (int i = N - 1; i >= 0; i--)
		{
			Y[i] -= B[i];
		}
		delete[] B;
	}
	void BGPolyCorr(int BG_poly_n)
	{
		int n_app = BG_poly_n;
		int n = length;

		double xs = 0, ys = 0;
		double xys = 0, x2ys = 0, x3ys = 0, x4ys = 0, x5ys = 0, x6ys = 0, x7ys = 0, x8ys = 0, x9ys = 0;
		double x2s = 0, x3s = 0, x4s = 0, x5s = 0, x6s = 0, x7s = 0, x8s = 0, x9s = 0, x10s = 0;
		double x11s = 0, x12s = 0, x13s = 0, x14s = 0, x15s = 0, x16s = 0, x17s = 0, x18s = 0;
		double x, y, W, N;

		double c_app[10];
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
			for (int ii = 0; ii < 100; ii++)
			{
				N = 0;
				xs = 0; ys = 0;
				xys = 0; x2ys = 0; x3ys = 0; x4ys = 0; x5ys = 0; x6ys = 0; x7ys = 0; x8ys = 0; x9ys = 0;
				x2s = 0; x3s = 0; x4s = 0; x5s = 0; x6s = 0; x7s = 0; x8s = 0; x9s = 0; x10s = 0;
				x11s = 0; x12s = 0; x13s = 0; x14s = 0; x15s = 0; x16s = 0; x17s = 0; x18s = 0;

				for (int i = 0; i < n; i++)
				{
					x = X[i];
					y = Y[i];
					W = 1;
					if (ii > 0)
					{
						y = min(Y[i], c_app[9] * x * x * x * x * x * x * x * x * x +
							c_app[8] * x * x * x * x * x * x * x * x + c_app[7] * x * x * x * x * x * x * x +
							c_app[6] * x * x * x * x * x * x + c_app[5] * x * x * x * x * x +
							c_app[4] * x * x * x * x + c_app[3] * x * x * x + c_app[2] * x * x + c_app[1] * x + c_app[0]);
					}

					ys += W * y;
					xys += W * x * y;
					x2ys += W * x * x * y;
					x3ys += W * x * x * x * y;
					x4ys += W * x * x * x * x * y;
					x5ys += W * x * x * x * x * x * y;
					x6ys += W * x * x * x * x * x * x * y;
					x7ys += W * x * x * x * x * x * x * x * y;
					x8ys += W * x * x * x * x * x * x * x * x * y;
					x9ys += W * x * x * x * x * x * x * x * x * x * y;

					xs += W * x;
					x2s += W * x * x;
					x3s += W * x * x * x;
					x4s += W * x * x * x * x;
					x5s += W * x * x * x * x * x;
					x6s += W * x * x * x * x * x * x;
					x7s += W * x * x * x * x * x * x * x;
					x8s += W * x * x * x * x * x * x * x * x;
					x9s += W * x * x * x * x * x * x * x * x * x;
					x10s += W * x * x * x * x * x * x * x * x * x * x;
					x11s += W * x * x * x * x * x * x * x * x * x * x * x;
					x12s += W * x * x * x * x * x * x * x * x * x * x * x * x;
					x13s += W * x * x * x * x * x * x * x * x * x * x * x * x * x;
					x14s += W * x * x * x * x * x * x * x * x * x * x * x * x * x * x;
					x15s += W * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x;
					x16s += W * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x;
					x17s += W * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x;
					x18s += W * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x;

					N += W;
				}

				if (n_app == 1)
				{
					c_app[1] = (N * xys - xs * ys) / (N * x2s - xs * xs);
					c_app[0] = (ys * x2s - xys * xs) / (N * x2s - xs * xs);
				}
				if (n_app == 2)
				{
					double A[9];
					A[0] = x4s; A[1] = x3s; A[2] = x2s;
					A[3] = x3s; A[4] = x2s; A[5] = xs;
					A[6] = x2s; A[7] = xs;  A[8] = N;
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
					A[12] = x3s; A[13] = x2s; A[14] = xs; A[15] = N;
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
					A[20] = x4s; A[21] = x3s; A[22] = x2s; A[23] = xs; A[24] = N;
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
					A[30] = x5s; A[31] = x4s; A[32] = x3s; A[33] = x2s; A[34] = xs; A[35] = N;
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
					A[42] = x6s; A[43] = x5s; A[44] = x4s; A[45] = x3s; A[46] = x2s; A[47] = xs; A[48] = N;
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
					A[56] = x7s; A[57] = x6s; A[58] = x5s; A[59] = x4s; A[60] = x3s; A[61] = x2s; A[62] = xs; A[63] = N;
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
					A[72] = x8s; A[73] = x7s; A[74] = x6s; A[75] = x5s; A[76] = x4s; A[77] = x3s; A[78] = x2s; A[79] = xs; A[80] = N;
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
					A[90] = x9s; A[91] = x8s; A[92] = x7s; A[93] = x6s; A[94] = x5s; A[95] = x4s; A[96] = x3s; A[97] = x2s; A[98] = xs; A[99] = N;
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
			}
		}
		else
		{
			c_app[0] = Y[0];
			for (int i = 1; i < n; i++)
			{
				c_app[0] = min(c_app[0], Y[i]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			Y[i]-= c_app[9] * X[i] * X[i] * X[i] * X[i] * X[i] * X[i] * X[i] * X[i] * X[i] +
				c_app[8] * X[i] * X[i] * X[i] * X[i] * X[i] * X[i] * X[i] * X[i] +
				c_app[7] * X[i] * X[i] * X[i] * X[i] * X[i] * X[i] * X[i] +
				c_app[6] * X[i] * X[i] * X[i] * X[i] * X[i] * X[i] +
				c_app[5] * X[i] * X[i] * X[i] * X[i] * X[i] +
				c_app[4] * X[i] * X[i] * X[i] * X[i] +
				c_app[3] * X[i] * X[i] * X[i] +
				c_app[2] * X[i] * X[i] +
				c_app[1] * X[i] +
				c_app[0];
		}
	}
	void Spline(int spline_order, int spline_iter)
	{
		double* t = new double[length];
		for (int it = 0; it < spline_iter; it++)
		{
			int k = 0;
			for (unsigned int i = (spline_order - 1) / 2; i < length - spline_order / 2; i++)
			{
				t[k] = 0;
				for (unsigned int j = i - (spline_order - 1) / 2; j <= i + spline_order / 2; j++)
				{
					t[k] += Y[j];
				}
				t[k] = t[k] / spline_order;
				k++;
			}
			k = 0;
			for (unsigned int i = (spline_order - 1) / 2; i < length - spline_order / 2; i++)
			{
				Y[i] = t[k];
				k++;
			}
		}
		delete[] t;
	}
};