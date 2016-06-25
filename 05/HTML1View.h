// HTML1View.h : interface of the CHTML1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HTML1VIEW_H__178D8FF8_0C4A_4E2B_85F4_083B0908AB1B__INCLUDED_)
#define AFX_HTML1VIEW_H__178D8FF8_0C4A_4E2B_85F4_083B0908AB1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHTML1View : public CHtmlView
{
protected: // create from serialization only
	CHTML1View();
	DECLARE_DYNCREATE(CHTML1View);

// Attributes
public:
	CHTML1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHTML1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	void getpage(CString str);
	virtual ~CHTML1View();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHTML1View)
	afx_msg void OnRefrush();
	afx_msg void OnViewmenu();
	afx_msg void OnViewrecord();
	afx_msg void OnPre();
	afx_msg void OnNext();
	afx_msg void OnConnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HTML1View.cpp
inline CHTML1Doc* CHTML1View::GetDocument()
   { return (CHTML1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTML1VIEW_H__178D8FF8_0C4A_4E2B_85F4_083B0908AB1B__INCLUDED_)
