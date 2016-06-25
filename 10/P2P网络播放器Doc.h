// P2PÍøÂç²¥·ÅÆ÷Doc.h : interface of the CP2PDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2PDOC_H__17362C13_E041_48FF_8F75_849AD3333BCC__INCLUDED_)
#define AFX_P2PDOC_H__17362C13_E041_48FF_8F75_849AD3333BCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CP2PDoc : public CDocument
{
protected: // create from serialization only
	CP2PDoc();
	DECLARE_DYNCREATE(CP2PDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CP2PDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CP2PDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CP2PDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_P2PDOC_H__17362C13_E041_48FF_8F75_849AD3333BCC__INCLUDED_)
