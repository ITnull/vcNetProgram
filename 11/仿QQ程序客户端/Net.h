#if !defined(AFX_NET_H__9D087414_CB59_4744_B310_99BCAF67A1AF__INCLUDED_)
#define AFX_NET_H__9D087414_CB59_4744_B310_99BCAF67A1AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Net.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNet dialog

class CNet : public CDialog
{
// Construction
public:
	CNet(CWnd* pParent = NULL);   // standard constructor
	CBitmap m_bit1;
	HDC dc1;
// Dialog Data
	//{{AFX_DATA(CNet)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNet)
	afx_msg void OnPaint();
	afx_msg void OnOK();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NET_H__9D087414_CB59_4744_B310_99BCAF67A1AF__INCLUDED_)
