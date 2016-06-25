// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "HTML1.h"
//#include "HTML1View.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_CBN_SELCHANGE(IDC_COM, OnSelchangeCom)
	ON_COMMAND(ID_ADDNETADDRES, OnAddnetaddres)
	ON_COMMAND(ID_VIEWMENU, OnViewmenu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here

}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, 
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("Failed to create dialogbar\n");
		return -1;		// fail to create
	}

	if (!m_wndReBar.Create(this) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("Failed to create rebar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
//if(dlg.m_hWnd!=NULL)
//	RECT rect;
//m_wndStatusBar.GetWindowRect(&rect);
//	dlg.Create(ID_DILOG,this);
//	m_wndReBar.AddBar(&dlg);
//}
this->SetTitle("                        第五章:网页浏览器示例程序");

//m_wndToolBar.GetDlgItem(ID_COM)->SetWindowText("safsf");
//.SetButtonInfo(8,ID_LIULANJILU,TBBS_BUTTON,0);
//m_wndToolBar.SetButtonText(8,"要不得");

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers




//DEL void CMainFrame::OnNext() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CMainFrame::OnPre() 
//DEL {
//DEL 	
//DEL 	//CHTML1View::GoBack();
//DEL 	//(CHTML1View)::GetActiveView()->
//DEL }

//DEL void CMainFrame::OnRefrush() 
//DEL {
//DEL 	
//DEL 	
//DEL }


//DEL void CMainFrame::OnSelchangeCom1() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	
//DEL }

//DEL void CMainFrame::OnBu1() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	CString str;								//定义字符串变量
//DEL GetDlgItem(IDC_COM1)->GetWindowText(str);	//获得地址栏输入的字符串
//DEL 
//DEL }

//DEL void CMainFrame::OnButton() 
//DEL {   
//DEL //	CByteArray a;
//DEL //	web.Navigate2("127.0.0.1",0,&a,NULL,NULL);
//DEL      //pview->getpage("127.0.0.1");
//DEL 	
//DEL 
//DEL }

void CMainFrame::OnSelchangeCom() 
{
	// TODO: Add your control notification handler code here

}




void CMainFrame::OnAddnetaddres() 
{//CString str;
	//=(CMenu *)::GetSubMenu((HMENU)::GetDlgItem(this->m_hWnd,IDR_MAINFRAME),3);
//	m->GetMenuString(3,str,NULL);
//MessageBox(str);
//m=this->GetSystemMenu(true);
//m=(CMenu *)::GetSubMenu((HMENU)::GetDlgItem(this->m_hWnd,IDR_MAINFRAME),0);
//int i=m->GetMenuItemCount();::GetMenuI
//m->GetMenuString(0,str,NULL);
//	GetDlgItem(IDR_MAINFRAME).
//(CHTML1View)this->GetActiveView()->
}



void CMainFrame::OnViewmenu() 
{
	
}

//DEL void CMainFrame::OnRButtonDblClk(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	
//DEL 	CFrameWnd::OnRButtonDblClk(nFlags, point);
//DEL }

//DEL void CMainFrame::OnRButtonDblClk(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	
//DEL 	CFrameWnd::OnRButtonDblClk(nFlags, point);
//DEL }

//DEL void CMainFrame::OnLButtonDblClk(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	MessageBox("sds");
//DEL 	CFrameWnd::OnLButtonDblClk(nFlags, point);
//DEL }
