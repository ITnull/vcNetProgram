// 邮件收发器Dlg.h : header file
//

#if !defined(AFX_DLG_H__BDAA3657_47AA_4BA0_836A_2065EF711357__INCLUDED_)
#define AFX_DLG_H__BDAA3657_47AA_4BA0_836A_2065EF711357__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Set.h"
#include "Recv1.h"
/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor
	CFile file;
// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
SOCKET s;
sockaddr_in addr;										//定义网络地址结构对象		
hostent *host;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
HWND statu;
// Implementation
protected:
	HICON m_hIcon;
	CSet set;
	CRecv recvdlg; 
	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	virtual BOOL OnInitDialog();
	afx_msg void OnHelp();
	afx_msg void OnPaint();
	afx_msg void OnPeizhi();
	afx_msg void OnSendmail();
	afx_msg void OnRecvmail();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__BDAA3657_47AA_4BA0_836A_2065EF711357__INCLUDED_)
