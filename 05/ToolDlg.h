#if !defined(AFX_TOOLDLG_H__FFE65168_F36F_44B9_9215_B31AAB560600__INCLUDED_)
#define AFX_TOOLDLG_H__FFE65168_F36F_44B9_9215_B31AAB560600__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ToolDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CToolDlg dialog
#include "webbrowser2.h"
class CToolDlg : public CDialog
{
// Construction
public:
	CToolDlg(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CToolDlg)
	enum { IDD = ID_DILOG };
	//}}AFX_DATA
	
	CWebBrowser2 web;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CToolDlg)
	afx_msg void OnButton();
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLDLG_H__FFE65168_F36F_44B9_9215_B31AAB560600__INCLUDED_)
