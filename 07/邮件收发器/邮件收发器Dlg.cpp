// 邮件收发器Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "邮件收发器.h"
#include "邮件收发器Dlg.h"

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
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_HELP, OnHelp)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_PEIZHI, OnPeizhi)
	ON_BN_CLICKED(IDC_SENDMAIL, OnSendmail)
	ON_BN_CLICKED(IDC_RECVMAIL, OnRecvmail)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

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

 
 

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CMyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	statu=::CreateStatusWindow(WS_CHILD|WS_VISIBLE,"欢迎使用本软件！(作者：Liangwei)",this->m_hWnd,IDC_123);
	this->SetWindowText("邮件收发器 v1.0");
	//::SendMessage(h,SB_SETBKCOLOR,0,RGB(255,0,0));
file.Open("状态配置文件.lw",CFile::modeNoTruncate|CFile::modeCreate|CFile::modeReadWrite);
char d;
file.Read(&d,1);
file.Close();
if(d=='Y')
{
	GetDlgItem(IDC_HELP)->EnableWindow(false);
	GetDlgItem(IDC_PEIZHI)->EnableWindow(true);
}
else
{GetDlgItem(IDC_PEIZHI)->EnableWindow(false);}
GetDlgItem(IDC_SENDER)->EnableWindow(false);							//设置各个控件状态
GetDlgItem(IDC_RECVER)->EnableWindow(false);
GetDlgItem(IDC_SUBJECT)->EnableWindow(false);
GetDlgItem(IDC_SENDMAIL)->EnableWindow(false);
GetDlgItem(IDC_RECVMAIL)->EnableWindow(false);
GetDlgItem(IDC_MAILTEXT)->EnableWindow(false);
CString str="请用户首先查看“使用前须知” ";
GetDlgItem(IDC_SENDER)->SetWindowText(str);
//CFile file("培植文件.txt",CFile::modeReadWrite);
//CString str="爱迪生大会洒家挥洒机";
//file.Write(str.GetBuffer(1),sizeof(str));

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CMyDlg::OnHelp() 
{
	// TODO: Add your control notification handler code here
	CString str;
      str+="本程序的使用方法：";
	  str+="\r\n";
        str+="第一步：设置SMTP服务器，包括服务器地址、端口号码";
		str+="\r\n";
         str+="第二步：设置发件人地址、收件人地址、邮件主题、邮件内容，";
			str+="其中，发件人地址与邮件内容可以为空，其余均不能为空。";
			   str+="\r\n";
             str+="(注意，如果需要将邮件发送到多人，请在收件人地址内使用逗号将地址区分开即可)";
			 str+="\r\n";
			 str+="作者：liangwei,QQ:393817181";
			 if(MessageBox(str)==IDOK){
				 GetDlgItem(IDC_HELP)->SetWindowText("功能待用");
			  GetDlgItem(IDC_HELP)->EnableWindow(false);
                 GetDlgItem(IDC_PEIZHI)-> EnableWindow(true);
			 CFile file1("状态配置文件.lw",CFile::modeReadWrite|CFile::modeNoTruncate|CFile::modeCreate);
		char d='Y';
		file1.Write(&d,sizeof(d));
		file1.Close();
			 }
		
}


void CMyDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}

void CMyDlg::OnPeizhi() 
{
	// TODO: Add your control notification handler code here
	/*set.DoModal();
	if(set.m_port>0 && set.m_port<100)
  {
	if(set.m_severadd!="")
	{
	addr.sin_family=AF_INET;								//为地址结构中的成员赋值
	addr.sin_port=htons(set.m_port);
	host=::gethostbyname(set.m_severadd.GetBuffer(1));					//从服务器名获取主机地址
	addr.sin_addr.S_un.S_addr=inet_addr(host-> h_addr_list[0]);	
	s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);		//创建套接字
if(connect(s,(sockaddr*)&addr,sizeof(addr)))
{
::SendMessage(statu,SB_SETTEXT,0,(long)"SMTP服务器信息设置成功并已经连接服务器！");
GetDlgItem(IDC_SENDER)->EnableWindow(true);	//设置各个控件状态
GetDlgItem(IDC_RECVER)->EnableWindow(true);
GetDlgItem(IDC_SUBJECT)->EnableWindow(true);
GetDlgItem(IDC_SENDMAIL)->EnableWindow(true);
GetDlgItem(IDC_RECVMAIL)->EnableWindow(true);
GetDlgItem(IDC_MAILTEXT)->EnableWindow(true);
GetDlgItem(IDC_SENDER)->SetWindowText("");	
 }
else
{
	MessageBox("请检查网络连接或重新设置服务器信息！");
}

	}
	else{MessageBox("服务器地址不能为空");}
	}
else
	{
		MessageBox("端口范围(0~100)");
	}
}*/
	set.DoModal();											//调用模式对话框
	if(set.m_port>0 && set.m_port<100)							//判断端口范围 
  {
	if(set.m_severadd!="")									//服务器地址不能为空
	{
addr.sin_family=AF_INET;									//为地址结构中的成员赋值
addr.sin_port=htons(set.m_port);
//host=::gethostbyname(set.m_severadd.GetBuffer(1));				//从服务器名获取主机地址
addr.sin_addr.S_un.S_addr=inet_addr(/*host-> h_addr_list[0]*/set.m_severadd.GetBuffer(1));	
s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);				//创建套接字
if(connect(s,(sockaddr*)&addr,sizeof(addr))!=-1)
{
	char buf[1024];			//定义缓冲区 
recv(s,buf,1024,0);		//接收响应数据
::SendMessage(statu,SB_SETTEXT,0,(long)"已经连接服务器,并已就绪！");/**/
GetDlgItem(IDC_SENDER)->EnableWindow(true);					//设置各个控件状态
GetDlgItem(IDC_RECVER)->EnableWindow(true);
GetDlgItem(IDC_SUBJECT)->EnableWindow(true);
GetDlgItem(IDC_SENDMAIL)->EnableWindow(true);
GetDlgItem(IDC_RECVMAIL)->EnableWindow(true);
GetDlgItem(IDC_MAILTEXT)->EnableWindow(true);
GetDlgItem(IDC_SENDER)->SetWindowText("");
	}
else
{
	::SendMessage(statu,SB_SETTEXT,0,(long)"连接失败，请重试！");
	}}

	else{
		if(MessageBox("服务器地址不能为空")==IDOK)
		{
	GetDlgItem(IDC_SENDER)->EnableWindow(false);					//设置各个控件状态
GetDlgItem(IDC_RECVER)->EnableWindow(false);
GetDlgItem(IDC_SUBJECT)->EnableWindow(false);
GetDlgItem(IDC_SENDMAIL)->EnableWindow(false);
GetDlgItem(IDC_RECVMAIL)->EnableWindow(false);
GetDlgItem(IDC_MAILTEXT)->EnableWindow(false);
			this->OnPeizhi();
			
	}}}
else
	{
		MessageBox("端口范围(0~100)");
		this->OnPeizhi();
	}
//::SendMessage(statu,SB_SETTEXT,0,(long)"邮件发送成功！");
}


//DEL void CMyDlg::OnSendmail() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	
//DEL }

void CMyDlg::OnSendmail() 
{

	
}



void CMyDlg::OnRecvmail() 
{
	// TODO: Add your control notification handler code here
	recvdlg.DoModal();
		
}
