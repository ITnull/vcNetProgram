// P2P网络播放器View.h : interface of the CP2PView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2PVIEW_H__54768696_DB64_4AA1_AF6D_FDD4E81C0EC8__INCLUDED_)
#define AFX_P2PVIEW_H__54768696_DB64_4AA1_AF6D_FDD4E81C0EC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "mmsystem.h"
#define WM_SOCK WM_USER+100
typedef struct mp3_str{		//自定义MP3结构体
char heade[3];   		//"TAG"字符标记
char title[30];			//音乐文件名称
char arti [30]; 		//演唱者
char alb [30];     		//专辑
char year[4];    		//出版年份 
char text[28]; 		//备注内容
//CString str;
} mp3struct;

typedef struct mp3_str1{
mp3struct mp3;
char str[50];
}mp3str;
DWORD WINAPI Senddata(
  LPVOID lpParameter   // thread data
);

class CP2PView : public CFormView
{
protected: // create from serialization only
	CP2PView();
	DECLARE_DYNCREATE(CP2PView)

public:
	//{{AFX_DATA(CP2PView)
	enum { IDD = IDD_P2P_FORM };
	CListCtrl	m_list;
	CButton m_radio2;
	CButton m_radio1;
	//}}AFX_DATA

// Attributes
public:
	CP2PDoc* GetDocument();
	mp3str mp;
	MCI_OPEN_PARMS open;
	DWORD err;
	int index;
	int flag,n;
	SOCKET s1,s2;
	SOCKET s[5];
	int i;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CP2PView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnDraw(CDC* pDC);
	
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CP2PView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CP2PView)
	afx_msg void OnFind();
	afx_msg void OnFind2();
	afx_msg void OnKongzhi();
	afx_msg void OnPlay();
	afx_msg void OnStop();
	afx_msg void OnPre();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Onsoc(WPARAM wParam,LPARAM lParam);
	afx_msg void OnLiulan();
	afx_msg void OnNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in P2P网络播放器View.cpp
inline CP2PDoc* CP2PView::GetDocument()
   { return (CP2PDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_P2PVIEW_H__54768696_DB64_4AA1_AF6D_FDD4E81C0EC8__INCLUDED_)
