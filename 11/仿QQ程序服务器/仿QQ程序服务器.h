// 仿QQ程序服务器.h : main header file for the 仿QQ程序服务器 application
//

#if !defined(AFX_QQ_H__8B11DF92_2AE6_40BC_8F3B_44489A3631B5__INCLUDED_)
#define AFX_QQ_H__8B11DF92_2AE6_40BC_8F3B_44489A3631B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQQApp:
// See 仿QQ程序服务器.cpp for the implementation of this class
//

class CQQApp : public CWinApp
{
public:
	CQQApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQQApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQ_H__8B11DF92_2AE6_40BC_8F3B_44489A3631B5__INCLUDED_)
