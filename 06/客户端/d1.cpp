// d1.cpp : implementation file
//

#include "stdafx.h"
#include "¿Í»§¶Ë.h"
#include "d1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cd1 dialog


Cd1::Cd1(CWnd* pParent /*=NULL*/)
	: CDialog(Cd1::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cd1)
	m_port = 0;
	m_ip = _T("");
	//}}AFX_DATA_INIT

}


void Cd1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cd1)
	DDX_Text(pDX, IDC_EDIT2, m_port);
	DDX_Text(pDX, IDC_EDIT1, m_ip);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cd1, CDialog)
	//{{AFX_MSG_MAP(Cd1)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cd1 message handlers

int Cd1::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	//	GetDlgItem(IDC_EDIT2)->SetWindowText("80");
	// TODO: Add your specialized creation code here
	
	return 0;
}
