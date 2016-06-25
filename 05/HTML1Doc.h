// HTML1Doc.h : interface of the CHTML1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HTML1DOC_H__11BAB420_9B19_4F2E_97A8_BE6C62E751E8__INCLUDED_)
#define AFX_HTML1DOC_H__11BAB420_9B19_4F2E_97A8_BE6C62E751E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHTML1Doc : public CDocument
{
protected: // create from serialization only
	CHTML1Doc();
	DECLARE_DYNCREATE(CHTML1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHTML1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHTML1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHTML1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTML1DOC_H__11BAB420_9B19_4F2E_97A8_BE6C62E751E8__INCLUDED_)
