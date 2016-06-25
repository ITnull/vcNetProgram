// HTML1.h : main header file for the HTML1 application
//

#if !defined(AFX_HTML1_H__46085E78_CEFE_4CA4_8470_7B5594A9C4F8__INCLUDED_)
#define AFX_HTML1_H__46085E78_CEFE_4CA4_8470_7B5594A9C4F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "HTML1_i.h"

/////////////////////////////////////////////////////////////////////////////
// CHTML1App:
// See HTML1.cpp for the implementation of this class
//

class CHTML1App : public CWinApp
{
public:
	CHTML1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHTML1App)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHTML1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTML1_H__46085E78_CEFE_4CA4_8470_7B5594A9C4F8__INCLUDED_)
