// HTML1View.cpp : implementation of the CHTML1View class
//

#include "stdafx.h"
#include "HTML1.h"

#include "HTML1Doc.h"
#include "HTML1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHTML1View

IMPLEMENT_DYNCREATE(CHTML1View, CHtmlView)
BEGIN_MESSAGE_MAP(CHTML1View, CHtmlView)
	//{{AFX_MSG_MAP(CHTML1View)
	ON_COMMAND(ID_REFRUSH, OnRefrush)
	ON_COMMAND(ID_VIEWMENU, OnViewmenu)
	ON_COMMAND(ID_VIEWRECORD, OnViewrecord)
	ON_COMMAND(ID_PRE, OnPre)
	ON_COMMAND(ID_NEXT, OnNext)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHTML1View construction/destruction

CHTML1View::CHTML1View()
{
	// TODO: add construction code here

}

CHTML1View::~CHTML1View()
{
}

BOOL CHTML1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHTML1View drawing

void CHTML1View::OnDraw(CDC* pDC)
{
	CHTML1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
//	pDC->SetBkMode(TRANSPARENT);
//	pDC->SetTextColor(RGB(255,0,0));
	// TODO: add draw code for native data here


}

void CHTML1View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
getpage(("http://www.microsoft.com/visualc/"));
}

/////////////////////////////////////////////////////////////////////////////
// CHTML1View printing


/////////////////////////////////////////////////////////////////////////////
// CHTML1View diagnostics

#ifdef _DEBUG
//DEL void CHTML1View::AssertValid() const
//DEL {
//DEL 	CHtmlView::AssertValid();
//DEL }

void CHTML1View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CHTML1Doc* CHTML1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHTML1Doc)));
	return (CHTML1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHTML1View message handlers

//DEL void CHTML1View::OnViewrecord() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CHTML1View::OnRefrush() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CHTML1View::OnPre() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CHTML1View::OnNext() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CHTML1View::OnButton1() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	
//DEL }

//DEL void CHTML1View::OnSelchangeCombo1() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 		

void CHTML1View::getpage(CString str)
{
this->Navigate2(str,NULL,NULL);
}

//DEL void CHTML1View::OnRButtonDown(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	
//DEL 	CHtmlView::OnRButtonDown(nFlags, point);
//DEL }

//DEL void CHTML1View::OnRButtonDblClk(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	MessageBox("sds");
//DEL 	CHtmlView::OnRButtonDblClk(nFlags, point);
//DEL }

void CHTML1View::OnRefrush() 
{
	// TODO: Add your command handler code here
	this->Refresh();
}

void CHTML1View::OnViewmenu() 
{
	// TODO: Add your command handler code here
	
}

void CHTML1View::OnViewrecord() 
{
	// TODO: Add your command handler code here
}

void CHTML1View::OnPre() 
{
	// TODO: Add your command handler code here
this->GoBack();	
}

void CHTML1View::OnNext() 
{
	// TODO: Add your command handler code here
	this->GoForward();
}

void CHTML1View::OnConnect() 
{
	// TODO: Add your control notification handler code here

	this->Navigate2("www.163.com",0,NULL, NULL,NULL,0);
}
