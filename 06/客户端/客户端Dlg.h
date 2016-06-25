// ¿Í»§¶ËDlg.h : header file
//

#if !defined(AFX_DLG_H__CA55AE47_F2DA_4E6F_9004_0E36EAC30F6A__INCLUDED_)
#define AFX_DLG_H__CA55AE47_F2DA_4E6F_9004_0E36EAC30F6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog
#include "d1.h"
#include <winsock2.h>
#define WM_SOCKT WM_USER+1
#pragma comment(lib,"WS2_32.lib")
class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor
	CString ip;
   SOCKET s;
int port;

HFILE hfile;

		char buff[100];
		CString str;
		char str12[100];
		HWND h;
// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
sockaddr_in addr;
WSADATA data;
int i;
int n;
	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void Onsockt1(WPARAM wParam,LPARAM lParam);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__CA55AE47_F2DA_4E6F_9004_0E36EAC30F6A__INCLUDED_)
