#if !defined(AFX_SET_H__605590EA_D5BB_4742_9D7D_D3B136940A55__INCLUDED_)
#define AFX_SET_H__605590EA_D5BB_4742_9D7D_D3B136940A55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Set.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSet dialog

class CSet : public CDialog
{
// Construction
public:
	CSet(CWnd* pParent = NULL);   // standard constructor
	CBitmap m_bit1;
	HDC dc1;
// Dialog Data
	//{{AFX_DATA(CSet)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSet)
	afx_msg void OnPaint();
	afx_msg void OnOK();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SET_H__605590EA_D5BB_4742_9D7D_D3B136940A55__INCLUDED_)
