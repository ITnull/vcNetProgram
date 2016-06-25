// SSet.cpp : implementation file
//

#include "stdafx.h"
#include "¿Í»§¶Ë.h"
#include "SSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSSet dialog


CSSet::CSSet(CWnd* pParent /*=NULL*/)
	: CDialog(CSSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSSet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSSet)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSSet, CDialog)
	//{{AFX_MSG_MAP(CSSet)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSSet message handlers
