// 仿QQ程序Dlg.h : header file
//

#if !defined(AFX_QQDLG_H__B89F35A2_3C02_4E78_9265_FA36536DDCD1__INCLUDED_)
#define AFX_QQDLG_H__B89F35A2_3C02_4E78_9265_FA36536DDCD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CQQDlg dialog
#include "Send.h"
#include "Set.h"
#include "Net.h"
typedef struct qq_str{		//自定义QQ数据结构体
char  m_name[50];   		//发送信息客户昵称
char  m_name1[50];		//接收信息客户昵称
int  m_addr;				//客户端IP地址
char  msg[1024];			//客户端与服务器的通信内容
} qqstruct;	
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
	CBitmap m_bit,m_bit1;
	HDC dc1;
	CSend send;	
	CSet set;
	CNet net;
	// Generated message map functions
	//{{AFX_MSG(CQQDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEmail();
	afx_msg void OnNet();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQDLG_H__B89F35A2_3C02_4E78_9265_FA36536DDCD1__INCLUDED_)
