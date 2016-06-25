#if !defined(AFX_MESSAGE_H__A117A7EF_BD24_4E62_83B9_9B80F9473B56__INCLUDED_)
#define AFX_MESSAGE_H__A117A7EF_BD24_4E62_83B9_9B80F9473B56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Message.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMessage dialog

class CMessage : public CDialog
{
// Construction
public:
	CMessage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMessage)
	enum { IDD = IDD_DIALOG1 };
	CString		m_ip;
	long		m_num;
	CString	m_text;
	CString	m_text2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMessage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMessage)
	virtual BOOL OnInitDialog();
	afx_msg void OnRelay();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGE_H__A117A7EF_BD24_4E62_83B9_9B80F9473B56__INCLUDED_)
