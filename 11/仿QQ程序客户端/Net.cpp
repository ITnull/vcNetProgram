// Net.cpp : implementation file
//

#include "stdafx.h"
#include "仿QQ程序.h"
#include "Net.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNet dialog


CNet::CNet(CWnd* pParent /*=NULL*/)
	: CDialog(CNet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNet)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNet, CDialog)
	//{{AFX_MSG_MAP(CNet)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, OnOK)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNet message handlers

void CNet::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	m_bit1.LoadBitmap(IDB_BITMAP2);
dc1=::CreateCompatibleDC(::GetDC(this->m_hWnd));	
::SelectObject(dc1,m_bit1.m_hObject);
::StretchBlt(::GetDC(this->m_hWnd),0,0,500,500,dc1,0,0,30,30,SRCCOPY);

}

void CNet::OnOK() 
{
CString netadd,str;
GetDlgItem(IDC_EDIT1)->GetWindowText(netadd);
if(netadd.GetLength()==0)
{
	MessageBox("网页地址不能为空!");
}
else
{
	if(netadd.Find("www")!=-1)
	{
	ShellExecute(NULL,"open",netadd,NULL,NULL,SW_SHOW);
	}
	else
	{
		str+="www.";
		str+=netadd;
		ShellExecute(NULL,"open",str,NULL,NULL,SW_SHOW);
	}
::SendMessage(this->m_hWnd,WM_CLOSE,0,0);
}
}

void CNet::OnButton2() 
{
	// TODO: Add your control notification handler code here
	::SendMessage(this->m_hWnd,WM_CLOSE,0,0);
}
