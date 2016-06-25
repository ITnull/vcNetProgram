#if !defined(AFX_D1_H__900162D7_CCE7_49BA_AD85_8E2481DCBE21__INCLUDED_)
#define AFX_D1_H__900162D7_CCE7_49BA_AD85_8E2481DCBE21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// d1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cd1 dialog

class Cd1 : public CDialog
{
// Construction
public:
	Cd1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cd1)
	enum { IDD = IDD_DIALOG1 };
	int		m_port;
	CString	m_ip;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cd1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cd1)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_D1_H__900162D7_CCE7_49BA_AD85_8E2481DCBE21__INCLUDED_)
