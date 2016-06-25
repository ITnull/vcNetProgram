// 12Dlg.h : header file
//

#if !defined(AFX_12DLG_H__25E3A3CA_3F65_4887_929E_C295A70BC5F1__INCLUDED_)
#define AFX_12DLG_H__25E3A3CA_3F65_4887_929E_C295A70BC5F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <winsock2.h>
#pragma comment(lib,"WS2_32.lib")
/////////////////////////////////////////////////////////////////////////////
// CMy12Dlg dialog
#define WM_SOCK WM_USER+2
class CMy12Dlg : public CDialog
{
// Construction
public:
	CMy12Dlg(CWnd* pParent = NULL);	// standard constructor
SOCKET s1;
SOCKET s;
sockaddr_in addr;
sockaddr_in addr1;
int i,j,l;
int n;
int n2;
 CString str13,str15,str14;
 HICON hh[2];
 HCURSOR cuser;
 int s11;
 sockaddr_in add;
char *name[15];	
//CSocketFile a;		   
// Dialog Data
	//{{AFX_DATA(CMy12Dlg)
	enum { IDD = IDD_MY12_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy12Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HWND statu;

	// Generated message map functions
	//{{AFX_MSG(CMy12Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void Onsoc(WPARAM wParam,LPARAM lParam);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_12DLG_H__25E3A3CA_3F65_4887_929E_C295A70BC5F1__INCLUDED_)
