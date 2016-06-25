// Send.cpp : implementation file
//

#include "stdafx.h"
#include "·ÂQQ³ÌÐò.h"
#include "Send.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSend dialog


CSend::CSend(CWnd* pParent /*=NULL*/)
	: CDialog(CSend::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSend)
	m_name = _T("");
	//}}AFX_DATA_INIT
}


void CSend::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSend)
	DDX_Text(pDX, IDC_NAME, m_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSend, CDialog)
	//{{AFX_MSG_MAP(CSend)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSend message handlers

void CSend::OnSend() 
{
	CString str,str1;
GetDlgItem(IDC_EDIT1)->GetWindowText(str);

GetDlgItem(IDC_EDIT2)->GetWindowText(str1);
str1+="\r\n";
str1+=str;
GetDlgItem(IDC_EDIT2)->SetWindowText(str1);	
GetDlgItem(IDC_EDIT2)->EnableWindow(false);

}

int CSend::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	return 0;
}
