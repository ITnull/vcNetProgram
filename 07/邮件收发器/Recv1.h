#if !defined(AFX_RECV1_H__C8535DEA_E997_46BB_BF2C_8E8D8766A58F__INCLUDED_)
#define AFX_RECV1_H__C8535DEA_E997_46BB_BF2C_8E8D8766A58F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Recv1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecv dialog

class CRecv : public CDialog
{
// Construction
public:
	void SendCmd();
	CRecv(CWnd* pParent = NULL);   // standard constructor
int i;
CString mailadd,mailtext,name,pass,netadd,port;		//定义发送者邮件地址
HWND stat;
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
	virtual BOOL OnInitDialog();
	afx_msg void OnRecv();
	afx_msg void OnNext();
	afx_msg void OnChangePass();
	afx_msg void OnShang();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECV1_H__C8535DEA_E997_46BB_BF2C_8E8D8766A58F__INCLUDED_)
