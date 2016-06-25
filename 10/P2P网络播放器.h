// P2PÍøÂç²¥·ÅÆ÷.h : main header file for the P2PÍøÂç²¥·ÅÆ÷ application
//

#if !defined(AFX_P2P_H__07DC1C3F_5363_4E99_B76D_926265B48D85__INCLUDED_)
#define AFX_P2P_H__07DC1C3F_5363_4E99_B76D_926265B48D85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CP2PApp:
// See P2PÍøÂç²¥·ÅÆ÷.cpp for the implementation of this class
//

class CP2PApp : public CWinApp
{
public:
	CP2PApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CP2PApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CP2PApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_P2P_H__07DC1C3F_5363_4E99_B76D_926265B48D85__INCLUDED_)
