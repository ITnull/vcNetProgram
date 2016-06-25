// ToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HTML1.h"
#include "ToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolDlg dialog


CToolDlg::CToolDlg(CWnd* pParent /*=NULL*/)
: CDialog(CToolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CToolDlg)
	//}}AFX_DATA_INIT
//	GetDlgItem(ID_COM)->SetWindowText("faasdsd");
}


void CToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToolDlg)
	//}}AFX_DATA_MAP
	
}


BEGIN_MESSAGE_MAP(CToolDlg, CDialog)
	//{{AFX_MSG_MAP(CToolDlg)
	ON_BN_CLICKED(IDC_BUTTON, OnButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolDlg message handlers

//DEL void CToolDlg::OnBu1() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL  	CString str;								//定义字符串变量
//DEL  GetDlgItem(IDC_COM1)->GetWindowText(str);	//获得地址栏输入的字符串



void CToolDlg::OnButton() 
{
	// TODO: Add your control notification handler code here
CString str;
GetDlgItem(IDC_COM)->GetWindowText(str);
	web.Navigate(str,NULL,NULL,NULL,NULL);
}

