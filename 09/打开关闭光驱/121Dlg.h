// 121Dlg.h : header file
//

#if !defined(AFX_121DLG_H__EC53046A_31FD_454D_83CB_1AC6AFFCA340__INCLUDED_)
#define AFX_121DLG_H__EC53046A_31FD_454D_83CB_1AC6AFFCA340__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy121Dlg dialog
typedef struct mp3_str{		//自定义MP3结构体
char heade[3];   		//"TAG"字符标记
char title[30];			//音乐文件名称
char arti [30]; 		//演唱者
char alb [30];     		//专辑
char year[4];    		//出版年份 
char text[28]; 		//备注内容
} mp3struct;

class CMy121Dlg : public CDialog
{
// Construction
public:
	CMy121Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy121Dlg)
	enum { IDD = IDD_MY121_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy121Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	mp3struct mp3;
	// Generated message map functions
	//{{AFX_MSG(CMy121Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_121DLG_H__EC53046A_31FD_454D_83CB_1AC6AFFCA340__INCLUDED_)
