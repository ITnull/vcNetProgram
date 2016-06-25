// FTPDlg.h : header file
//

#if !defined(AFX_FTPDLG_H__EED6A167_C98C_4E17_8F66_33DA18377101__INCLUDED_)
#define AFX_FTPDLG_H__EED6A167_C98C_4E17_8F66_33DA18377101__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFTPDlg dialog

class CFTPDlg : public CDialog
{
// Construction
public:
	CFTPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFTPDlg)
	enum { IDD = IDD_FTP_DIALOG };
	CComboBox	m_c1;
	CComboBox	m_c2;
	CListCtrl	m_2;
	CListCtrl	m_3;
	LVITEM v;
	CString str;

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFTPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnRadio2();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPDLG_H__EED6A167_C98C_4E17_8F66_33DA18377101__INCLUDED_)
