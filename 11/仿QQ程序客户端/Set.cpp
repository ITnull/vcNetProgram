// Set.cpp : implementation file
//

#include "stdafx.h"
#include "仿QQ程序.h"
#include "Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSet dialog


CSet::CSet(CWnd* pParent /*=NULL*/)
	: CDialog(CSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSet)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSet, CDialog)
	//{{AFX_MSG_MAP(CSet)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, OnOK)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSet message handlers

void CSet::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
m_bit1.LoadBitmap(IDB_BITMAP2);
dc1=::CreateCompatibleDC(::GetDC(this->m_hWnd));	
::SelectObject(dc1,m_bit1.m_hObject);
::StretchBlt(::GetDC(this->m_hWnd),0,0,500,500,dc1,0,0,30,30,SRCCOPY);
}

void CSet::OnOK() 
{
CString mail,str;
mail+="mailto:";
GetDlgItem(IDC_EDIT1)->GetWindowText(str);
if(str.GetLength()==0)
{
	MessageBox("邮件接收地址不能为空!");
}
else
{
	if(str.Find("@")!=-1)
	{
mail+=str;
::ShellExecute(NULL,NULL,mail,NULL,NULL,SW_SHOW);
::SendMessage(this->m_hWnd,WM_CLOSE,0,0);
	}
	else
	{
		MessageBox("您输入的格式不正确!");
	}
}
}

void CSet::OnButton2() 
{
	// TODO: Add your control notification handler code here
	::SendMessage(this->m_hWnd,WM_CLOSE,0,0);
}
