
// Graph.h : main header file for the Graph application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGraphApp:
// See Graph.cpp for the implementation of this class
//

class CGraphApp : public CWinApp
{
public:
	CGraphApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGraphApp theApp;
