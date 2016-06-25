// 实用播放器Dlg.h : header file
//

#if !defined(AFX_DLG_H__1CC24152_B1FC_4999_9147_D3EAF25A8594__INCLUDED_)
#define AFX_DLG_H__1CC24152_B1FC_4999_9147_D3EAF25A8594__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "mmsystem.h"
/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog
typedef struct mp3_str{		//自定义MP3结构体
char heade[3];   		//"TAG"字符标记
char title[30];			//音乐文件名称
char arti [30]; 		//演唱者
char alb [30];     		//专辑
char year[4];    		//出版年份 
char text[28]; 			//备注内容
//CString str;
} mp3struct;

typedef struct mp3_str1{
mp3struct mp3;
char str[51];
}mp3str;

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor
HBITMAP bit;
HDC dc1;
HWND statu;	
LVCOLUMN lv,lv1;
mp3str mp;
MCI_OPEN_PARMS open;
int n,m;
//struct MCI_OPEN_PARMS open1;
// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CTabCtrl	m_tab;
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnAdd();
	afx_msg void OnPlay();
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPre();
	afx_msg void OnNext();
	afx_msg void OnZanting();
	afx_msg void OnStop();
	afx_msg void OnSousuomulu();
	afx_msg void OnSousuomulu2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__1CC24152_B1FC_4999_9147_D3EAF25A8594__INCLUDED_)
