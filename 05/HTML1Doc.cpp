// HTML1Doc.cpp : implementation of the CHTML1Doc class
//

#include "stdafx.h"
#include "HTML1.h"

#include "HTML1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHTML1Doc

IMPLEMENT_DYNCREATE(CHTML1Doc, CDocument)

BEGIN_MESSAGE_MAP(CHTML1Doc, CDocument)
	//{{AFX_MSG_MAP(CHTML1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHTML1Doc construction/destruction

CHTML1Doc::CHTML1Doc()
{
	// TODO: add one-time construction code here

}

CHTML1Doc::~CHTML1Doc()
{
}

BOOL CHTML1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHTML1Doc serialization

void CHTML1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHTML1Doc diagnostics

#ifdef _DEBUG
void CHTML1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHTML1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHTML1Doc commands
