// FTP.h : main header file for the FTP application
//

#if !defined(AFX_FTP_H__63E0180E_7D03_4022_A75F_DB25638AB352__INCLUDED_)
#define AFX_FTP_H__63E0180E_7D03_4022_A75F_DB25638AB352__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFTPApp:
// See FTP.cpp for the implementation of this class
//

class CFTPApp : public CWinApp
{
public:
	CFTPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFTPApp)
	afx_msg void OnMen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTP_H__63E0180E_7D03_4022_A75F_DB25638AB352__INCLUDED_)
