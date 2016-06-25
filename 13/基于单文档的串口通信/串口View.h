// ´®¿ÚView.h : interface of the CMyView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_VIEW_H__980C31D8_C0F4_453E_BD7D_90CE238F0F70__INCLUDED_)
#define AFX_VIEW_H__980C31D8_C0F4_453E_BD7D_90CE238F0F70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyView : public CFormView
{
protected: // create from serialization only
	CMyView();
	DECLARE_DYNCREATE(CMyView)

public:
	//{{AFX_DATA(CMyView)
	enum { IDD = IDD_MY_FORM };
	CComboBox	m_comstop;
	CComboBox	m_comnum;
	CComboBox	m_comjiaoyan;
	CComboBox	m_comdata;
	CComboBox	m_botelv;
	CMSComm	mm;
	//}}AFX_DATA

// Attributes
public:
	CMyDoc* GetDocument();
	CString str,str1;
	 int n;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void InitComm();
	virtual ~CMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyView)
	afx_msg void OnOpencom();
	afx_msg void OnSenddata();
	afx_msg void OnComm();
	afx_msg void OnRecvdata();
	afx_msg void OnSavedata();
	afx_msg void OnClose();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ´®¿ÚView.cpp
inline CMyDoc* CMyView::GetDocument()
   { return (CMyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW_H__980C31D8_C0F4_453E_BD7D_90CE238F0F70__INCLUDED_)
