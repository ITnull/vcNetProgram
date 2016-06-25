// P2PÍøÂç²¥·ÅÆ÷Doc.cpp : implementation of the CP2PDoc class
//

#include "stdafx.h"
#include "P2PÍøÂç²¥·ÅÆ÷.h"

#include "P2PÍøÂç²¥·ÅÆ÷Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CP2PDoc

IMPLEMENT_DYNCREATE(CP2PDoc, CDocument)

BEGIN_MESSAGE_MAP(CP2PDoc, CDocument)
	//{{AFX_MSG_MAP(CP2PDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CP2PDoc construction/destruction

CP2PDoc::CP2PDoc()
{
	// TODO: add one-time construction code here

}

CP2PDoc::~CP2PDoc()
{
}

BOOL CP2PDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CP2PDoc serialization

void CP2PDoc::Serialize(CArchive& ar)
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
// CP2PDoc diagnostics

#ifdef _DEBUG
void CP2PDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CP2PDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CP2PDoc commands
