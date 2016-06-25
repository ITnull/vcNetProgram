// 12Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "12.h"
#include "12Dlg.h"

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

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	public:
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//DEL CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
//DEL {
//DEL 	//{{AFX_DATA_INIT(CAboutDlg)
//DEL 	//}}AFX_DATA_INIT
//DEL }

//DEL void CAboutDlg::DoDataExchange(CDataExchange* pDX)
//DEL {
//DEL 	CDialog::DoDataExchange(pDX);
//DEL 	//{{AFX_DATA_MAP(CAboutDlg)
//DEL 	//}}AFX_DATA_MAP
//DEL }

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy12Dlg dialog

CMy12Dlg::CMy12Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy12Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy12Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	n=0;
	l=0;
	str13="";
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	i=15;
	j=0;
	n2=0;
	s11=0;
	::memset(&add,0,sizeof(add));
		
//	cuser=::LoadCursor(AfxGetApp()->m_hInstance,(char *)IDC_CURSOR1);
	
}

void CMy12Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy12Dlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy12Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy12Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_MESSAGE(WM_SOCK,Onsoc)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy12Dlg message handlers

BOOL CMy12Dlg::OnInitDialog()
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
	SetIcon(m_hIcon, true);		// Set small icon
	
	// TODO: Add extra initialization here
	this->SetWindowText("������(Liang Wei)");
	 WSADATA data;
	DWORD ss=MAKEWORD(2,0);//��ʼ��SOCKET��
   ::WSAStartup(ss,&data);
   s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	hh[0]=::LoadIcon(AfxGetApp()->m_hInstance,(char *)IDI_ICON1);
	hh[1]=::LoadIcon(AfxGetApp()->m_hInstance,(char *)IDI_ICON2);
	//::SetClassLong(m_hWnd,GCL_HCURSOR,(long)cuser);
	::gethostname((char*)&name,(int)sizeof(name));//�����������
	hostent *p=::gethostbyname((char*)&name);
	 in_addr *a=(in_addr*)*p->h_addr_list;// ��ñ���IP��ַ
	 str14=::inet_ntoa(a[0]);
	 str15+="����IP��ַ��";/////��Ҫ�޸ģ����IP��ַ
	 str15+=str14;
	GetDlgItem(IDC_STATIC2)->SetWindowText(str15);
//	::WSAAsyncSelect(s,this->m_hWnd,WM_SOCK, 
	 ::SendMessage(m_hWnd,WM_SETICON,0,(long)hh[0]/*(long)RGB(45,45,45)*/);
	 statu=::CreateStatusWindow(WS_CHILD|WS_VISIBLE,"��ӭʹ�ñ�����ķ�������(���ߣ�Liangwei)",this->m_hWnd,IDC_123);
::SendMessage(statu,SB_SETBKCOLOR,0,(long)RGB(255,0,0)/*(long)RGB(45,45,45)*/);
   
   addr.sin_family=AF_INET;
	addr.sin_port=htons(80);
	addr.sin_addr.S_un.S_addr=inet_addr(str14);
	::bind(s,(sockaddr*)&addr,sizeof(addr));
	::listen(s,1);
	SetTimer(1,1000,NULL);
//	SetTimer(2,500,NULL);
WSAAsyncSelect(s,this->m_hWnd,WM_SOCK,FD_ACCEPT|FD_READ);
GetDlgItem(IDC_EDIT1)->EnableWindow(true);/*_hWnd,WS_CHILD|WS_VISIBLE,ID_1234,3,::AfxGetApp()->m_hInstance,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);*\

CTime time;					//����CTime�����
CString str,str1;				//�����ַ���
time=CTime::GetCurrentTime();	//��ȡ��ǰϵͳʱ��
str=time.Format("%S");			//��ʽ�����ʱ���ַ���
str1="�������е�ʱ���ǣ�";		//Ϊ�ַ�����ֵ
str1+=str;					//���������ַ���
MessageBox(str1);				//��ʾ�û���ǰ��ϵͳʱ��
*/

return TRUE;
}

void CMy12Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

HCURSOR CMy12Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//DEL void CMy12Dlg::OnButton2() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL //	GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
//DEL 	


void CMy12Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
//	CString str="";

char sever[100];
	GetDlgItem(IDC_EDIT2)->GetWindowText((LPTSTR)sever,100);
//	MessageBox(sever);
	CString str="",str1="";
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	if(str!="")
	{str+="\r\n";}
	GetDlgItem(IDC_EDIT2)->GetWindowText(str1);
	str+=str1;
    GetDlgItem(IDC_EDIT1)->SetWindowText(str);///��ֵת������*/
  send(s1,sever,100,0);
	//::ShellExecute(NULL,NULL,"mailto:lymlrl@163.com",NULL,NULL,SW_SHOW);
	/*STARTUPINFO si={sizeof(si)};								//����ṹ�����
PROCESS_INFORMATION pi;								
char* str="notepad.exe";										//���±�����
CreateProcess(NULL,str,NULL,NULL,false,NULL,NULL,NULL,&si,&pi);	//���ú����򿪼��±�����							//��ʼ���׽��ֿ�
   SOCKET s;									//�����׽��ֶ���
hostent *host;										//���������ṹ�����
sockaddr_in addr;									//���������ַ�ṹ����		
addr.sin_family=AF_INET;							//Ϊ��ַ�ṹ�еĳ�Ա��ֵ
	addr.sin_port=htons(25);
    //host=gethostbyname("mail.163.com");					//�ӷ���������ȡ������ַ
	addr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");	//����SMTP�������ĵ�ַ
	s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);		//�����׽���
    ::connect(s, (sockaddr*) &addr,sizeof(addr));				//����SMTP������*/
							//������ջ�����



}
void CMy12Dlg::Onsoc(WPARAM wParam,LPARAM lParam)
{   char cs[100],cs1[10000],name[15];
	switch (lParam)

{
       case FD_ACCEPT:
			{
				s1=::accept(s,NULL,NULL);
		  n=n+1;
		  str13.Format("��%d�ͻ��Ѿ���������",n);
         this->SetWindowText(str13);
		 GetDlgItem(IDC_EDIT1)->GetWindowText((LPTSTR)cs1,10000);
		 ::getpeername(s1,(SOCKADDR*)&add,(int*)sizeof(add));
		 str13+=cs1;
		 str13+="\r\n";
		 str13+=::inet_ntoa(add.sin_addr);
		 str13+="��½��������";
		 GetDlgItem(IDC_EDIT1)->SetWindowText(str13);
		 char d='a';
		 send(s1,&d,sizeof(d),0);
			}
			break;
        
		case FD_READ:
	           { 
			   CString num="";
					   recv(s1,cs,100,NULL);
					   GetDlgItem(IDC_EDIT1)->GetWindowText((LPTSTR)cs1,10000);
					   //GetDlgItem(IDC_EDIT2)->GetWindowText((LPTSTR)cs,100);
		                num+=(LPTSTR)cs1;
						num+="\r\n";
						num+=::inet_ntoa(add.sin_addr);
						num+="����˵��";
						 num+=cs;
				   GetDlgItem(IDC_EDIT1)->SetWindowText(num);}
			  // }
			break;
		default:  break;
	  
}

}



//DEL void CMy12Dlg::OnTimer(UINT nIDEvent) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 
//DEL 	//	else
//DEL 	//	{
//DEL        //    CString str="û������";
//DEL 	//	   GetDlgItem(IDC_EDIT1)->SetWindowText(str);
//DEL 	//	}
//DEL 	CDialog::OnTimer(nIDEvent);
//DEL }



HBRUSH CMy12Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	
	HBRUSH hbr;
	
//	if(pWnd->GetDlgCtrlID()==IDC_EDIT1)
//	{
	//	pDC->SetTextColor(RGB(255,0,0));
//		pDC->SetBkColor(RGB(255,0,0));
//	}
	return hbr;
}

void CMy12Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
//	a.Open("sadsa",NULL);
		i+=15;
	j+=15;
	n2+=0.5;

	CString str;
	if(i>255)
	{i=120;}
	else{
		::SendMessage(statu,SB_SETBKCOLOR,0,(long)RGB(255,i,0));}
	n2+=1;
str.Format("����Ѿ�������%d��",n2);

	this->SetWindowText(str);
	
	if(l<=1){
		::SendMessage(m_hWnd,WM_SETICON,0,(long)hh[l++]/*(long)RGB(45,45,45)*/);}
	else
	{l=0;}
	CDialog::OnTimer(nIDEvent);
}


void CMy12Dlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect reWindow;
GetWindowRect(reWindow);

//Make the window twice as wide and twice as tall .
//SetWindowPos (NULL,0,0,reWindow.Width()/2,reWindow.Height()/2,SWP_NOMOVE|SWP_NOZORDER);
//::MoveWindow(statu,0,0,reWindow.Width()/2,reWindow.Height()/2,0);
//::PostMessage(this->m_hWnd,WM_NCHITTEST,(unsigned int)point,0);
/*HWND hwndParent = ::FindWindow( NULL, "QQ�û���½" );
	if( hwndParent == NULL )
	{
		hwndParent = ::FindWindow( NULL, "���ٴ������¼����" );
		if( hwndParent == NULL )
		{
			AfxMessageBox( "OICQ��¼���ڲ�����" );
			return;
		}
	}

	HWND hwndPasswd = ::FindWindowEx( hwndParent, NULL, "Edit", NULL );
	if( hwndPasswd == NULL )
	{
		AfxMessageBox( "�Ƿ�OICQ�ĵ�¼����" );
		return;
	}

	if( !(::GetWindowLong( hwndPasswd, GWL_STYLE ) & ES_PASSWORD ))
	{
		AfxMessageBox( "�Ƿ�OICQ�ĵ�¼����" );
		return;
	}


	DWORD dwThreadID = ::GetWindowThreadProcessId( hwndPasswd, NULL );
	DWORD dwCurThread = ::GetCurrentThreadId();

	if( !AttachThreadInput( dwThreadID, dwCurThread, TRUE ) )
	{
		AfxMessageBox( "Unable to attach thread to me" );
		return;
	}


	HWND hwndOldForegroundWnd = ::GetForegroundWindow();
	::SetForegroundWindow( hwndParent );
	::SetFocus( hwndPasswd );

	TCHAR szBuf[32]="888888";
	for( int i=0; i<lstrlen(szBuf); i++ )
	{
		::SendMessage( hwndPasswd, WM_CHAR, szBuf[i], NULL );
	}
	
	keybd_event( VK_RETURN, 0, 0, 0 );
	keybd_event( VK_RETURN, 0, KEYEVENTF_KEYUP, 0 );

	::SetForegroundWindow( hwndOldForegroundWnd );
	
	AttachThreadInput( GetWindowThreadProcessId( hwndParent, NULL ),
			GetCurrentThreadId(), FALSE );

*/
	CDialog::OnLButtonDown(nFlags, point);
}



