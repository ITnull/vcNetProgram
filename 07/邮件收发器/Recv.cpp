// Recv.cpp : implementation file
//

#include "stdafx.h"
#include "ÓÊ¼þÊÕ·¢Æ÷.h"
#include "Recv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecv dialog


CRecv::CRecv(CWnd* pParent /*=NULL*/)
	: CDialog(CRecv::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecv)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRecv::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecv)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRecv, CDialog)
	//{{AFX_MSG_MAP(CRecv)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecv message handlers
