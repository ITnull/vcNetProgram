#if !defined(AFX_SSET_H__9A20C40D_E3C2_45F6_8EBA_0E50D0ECA0B1__INCLUDED_)
#define AFX_SSET_H__9A20C40D_E3C2_45F6_8EBA_0E50D0ECA0B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSSet dialog

class CSSet : public CDialog
{
// Construction
public:
	CSSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSSet)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSSet)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSET_H__9A20C40D_E3C2_45F6_8EBA_0E50D0ECA0B1__INCLUDED_)
