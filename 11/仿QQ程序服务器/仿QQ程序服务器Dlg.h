// ·ÂQQ³ÌÐò·þÎñÆ÷Dlg.h : header file
//

#if !defined(AFX_QQDLG_H__E3F63D61_CB09_4900_BAB3_6CD022D5BF6A__INCLUDED_)
#define AFX_QQDLG_H__E3F63D61_CB09_4900_BAB3_6CD022D5BF6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Message.h"
/////////////////////////////////////////////////////////////////////////////
// CQQDlg dialog

class CQQDlg : public CDialog
{
// Construction
public:
	CQQDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CQQDlg)
	enum { IDD = IDD_QQ_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CMessage msg;
	// Generated message map functions
	//{{AFX_MSG(CQQDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQDLG_H__E3F63D61_CB09_4900_BAB3_6CD022D5BF6A__INCLUDED_)
