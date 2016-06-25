// 客户端Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "客户端.h"
#include "客户端Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_MESSAGE(WM_SOCKT,Onsockt1)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_BUTTON3)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON2)->SetWindowText("网络设置");
	GetDlgItem(IDC_BUTTON3)->SetWindowText("连接");
	GetDlgItem(IDC_BUTTON1)->SetWindowText("发送消息");
	GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
    GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	//m_tu.SetBitmap(bit);
    GetDlgItem(IDC_EDIT1)->EnableWindow(false);
	GetDlgItem(IDC_EDIT2)->EnableWindow(false);
    GetDlgItem(IDC_EDIT1)->SetWindowText("所有消息将显示在这里");
	
	this->SetWindowText("通信客户端");
    
	h=::CreateStatusWindow(WS_CHILD|WS_VISIBLE,"欢迎使用本软件!",this->m_hWnd,IDC_123);
	int ll[]={150,-1};
	::SendMessage(h,SB_SETPARTS,2,(long)ll);
	::SendMessage(h,SB_SETTEXT,1,(long)"使用时请先设置再连接!(作者：Liang Wei)");
	::SendMessage(h,SB_SETBKCOLOR,1,RGB(255,48,19));
	//CDC *hdc=::GetDC(h);
	//::SetBkColor(hdc->m_hDC,RGB(210,125,132));
	//::SetTextColor(this->GetDC(),RGB(210,125,132));
	 // return TRUE  unless you set the focus to a control
  DWORD ss=MAKEWORD(2,0);
  ::WSAStartup(ss,&data);
	//CPaintDC *dc=(CPaintDC*)GetDC(this);
//	::SetBkColor(dc->m_hDC,RGB(45,87,48));
  port=80;
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString ss="",sq="";
	char str14[10000];
    GetDlgItem(IDC_EDIT1)->GetWindowText((LPTSTR)str14,10000);
	GetDlgItem(IDC_EDIT2)->GetWindowText(sq);
	ss+=str14;
	ss+="\r\n";
	ss+="您对服务器说：";
	
	ss+=sq;
	GetDlgItem(IDC_EDIT1)->SetWindowText(ss);

    send(s,sq,100,0);
}

void CMyDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	::CreateFile("聊天记录.txt",GENERIC_WRITE,FILE_SHARE_WRITE,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,(void*)hfile);
	Cd1 d1;
d1.m_port=port;
if(d1.DoModal()==IDOK)
{ 
	ip=d1.m_ip;

port=d1.m_port;
}
GetDlgItem(IDC_BUTTON3)->EnableWindow(true);

}

void CMyDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
		::SendMessage(h,SB_SETTEXT,1,(long)"正在连接。。。。。");
	
	addr.sin_family=AF_INET;
	addr.sin_port=htons(80);
	addr.sin_addr.S_un.S_addr=inet_addr(ip);
	s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(connect(s,(sockaddr*)&addr,sizeof(addr))!=-1)
	
	{  GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
	   GetDlgItem(IDC_EDIT2)->EnableWindow(true);
		::WSAAsyncSelect(s,this->m_hWnd,WM_SOCKT,FD_READ|FD_ACCEPT);
	//GetDlgItem(IDC_BUTTON3)->SetWindowText("关闭对话");
	GetDlgItem(IDC_BUTTON3)->EnableWindow(false);
	::SendMessage(h,SB_SETTEXT,1,(long)"已经连接上服务器");
}
}

void CMyDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
		
	if(i<155)
	{i=255;}
	else{
		::SendMessage(h,SB_SETBKCOLOR,0,(long)RGB(i,10,10));}
	i=i-15;
	CDialog::OnTimer(nIDEvent);

}

void CMyDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
		CloseHandle(&hfile);
	CDialog::OnClose();
}
void CMyDlg::Onsockt1(WPARAM wParam,LPARAM lParam)
 { 
	 switch(lParam)
 
 { case FD_READ://设置读取事件
    
	 char s2[100]={0},ssa[20000];
	 CString data="";
	 sockaddr_in add;
			   ::memset(&add,0,sizeof(add));
			   ::getpeername(s,(SOCKADDR*)&add,(int*)sizeof(add));
	recv(s,s2,100,NULL);
    //MessageBox(s2);
	GetDlgItem(IDC_EDIT1)->GetWindowText((LPTSTR)ssa,20000);
     data+=(LPTSTR)ssa;
	 data+="\r\n";
	 data+=::inet_ntoa(add.sin_addr);
	 data+="对您说：";
	 data+=s2;
	GetDlgItem(IDC_EDIT1)->SetWindowText(data);
	unsigned long * a=0;
	::WriteFile(&hfile,s2,100,a,NULL);
		}
 }