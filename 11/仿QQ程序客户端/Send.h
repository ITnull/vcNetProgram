#if !defined(AFX_SEND_H__E2FF83BE_4C69_492E_AE39_8F82BC0162C8__INCLUDED_)
#define AFX_SEND_H__E2FF83BE_4C69_492E_AE39_8F82BC0162C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Send.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSend dialog

class CSend : public CDialog
{
public:
	CSend(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSend)
	enum { IDD = IDD_DIALOG1 };
	CString	m_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSend)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSend)
	afx_msg void OnSend();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEND_H__E2FF83BE_4C69_492E_AE39_8F82BC0162C8__INCLUDED_)
