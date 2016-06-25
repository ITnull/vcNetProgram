#if !defined(AFX_RECV_H__41606ECF_E7B0_4D3F_96A1_8BB05B54A04C__INCLUDED_)
#define AFX_RECV_H__41606ECF_E7B0_4D3F_96A1_8BB05B54A04C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Recv.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecv dialog

class CRecv : public CDialog
{
// Construction
public:
	CRecv(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRecv)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecv)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRecv)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECV_H__41606ECF_E7B0_4D3F_96A1_8BB05B54A04C__INCLUDED_)
