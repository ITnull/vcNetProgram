// �ʼ��շ���Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "�ʼ��շ���.h"
#include "�ʼ��շ���Dlg.h"

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
	statu=::CreateStatusWindow(WS_CHILD|WS_VISIBLE,"��ӭʹ�ñ������(���ߣ�Liangwei)",this->m_hWnd,IDC_123);
	this->SetWindowText("�ʼ��շ��� v1.0");
	//::SendMessage(h,SB_SETBKCOLOR,0,RGB(255,0,0));
file.Open("״̬�����ļ�.lw",CFile::modeNoTruncate|CFile::modeCreate|CFile::modeReadWrite);
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
GetDlgItem(IDC_SENDER)->EnableWindow(false);							//���ø����ؼ�״̬
GetDlgItem(IDC_RECVER)->EnableWindow(false);
GetDlgItem(IDC_SUBJECT)->EnableWindow(false);
GetDlgItem(IDC_SENDMAIL)->EnableWindow(false);
GetDlgItem(IDC_RECVMAIL)->EnableWindow(false);
GetDlgItem(IDC_MAILTEXT)->EnableWindow(false);
CString str="���û����Ȳ鿴��ʹ��ǰ��֪�� ";
GetDlgItem(IDC_SENDER)->SetWindowText(str);
//CFile file("��ֲ�ļ�.txt",CFile::modeReadWrite);
//CString str="������������һ�����";
//file.Write(str.GetBuffer(1),sizeof(str));

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CMyDlg::OnHelp() 
{
	// TODO: Add your control notification handler code here
	CString str;
      str+="�������ʹ�÷�����";
	  str+="\r\n";
        str+="��һ��������SMTP��������������������ַ���˿ں���";
		str+="\r\n";
         str+="�ڶ��������÷����˵�ַ���ռ��˵�ַ���ʼ����⡢�ʼ����ݣ�";
			str+="���У������˵�ַ���ʼ����ݿ���Ϊ�գ����������Ϊ�ա�";
			   str+="\r\n";
             str+="(ע�⣬�����Ҫ���ʼ����͵����ˣ������ռ��˵�ַ��ʹ�ö��Ž���ַ���ֿ�����)";
			 str+="\r\n";
			 str+="���ߣ�liangwei,QQ:393817181";
			 if(MessageBox(str)==IDOK){
				 GetDlgItem(IDC_HELP)->SetWindowText("���ܴ���");
			  GetDlgItem(IDC_HELP)->EnableWindow(false);
                 GetDlgItem(IDC_PEIZHI)-> EnableWindow(true);
			 CFile file1("״̬�����ļ�.lw",CFile::modeReadWrite|CFile::modeNoTruncate|CFile::modeCreate);
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
	addr.sin_family=AF_INET;								//Ϊ��ַ�ṹ�еĳ�Ա��ֵ
	addr.sin_port=htons(set.m_port);
	host=::gethostbyname(set.m_severadd.GetBuffer(1));					//�ӷ���������ȡ������ַ
	addr.sin_addr.S_un.S_addr=inet_addr(host-> h_addr_list[0]);	
	s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);		//�����׽���
if(connect(s,(sockaddr*)&addr,sizeof(addr)))
{
::SendMessage(statu,SB_SETTEXT,0,(long)"SMTP��������Ϣ���óɹ����Ѿ����ӷ�������");
GetDlgItem(IDC_SENDER)->EnableWindow(true);	//���ø����ؼ�״̬
GetDlgItem(IDC_RECVER)->EnableWindow(true);
GetDlgItem(IDC_SUBJECT)->EnableWindow(true);
GetDlgItem(IDC_SENDMAIL)->EnableWindow(true);
GetDlgItem(IDC_RECVMAIL)->EnableWindow(true);
GetDlgItem(IDC_MAILTEXT)->EnableWindow(true);
GetDlgItem(IDC_SENDER)->SetWindowText("");	
 }
else
{
	MessageBox("�����������ӻ��������÷�������Ϣ��");
}

	}
	else{MessageBox("��������ַ����Ϊ��");}
	}
else
	{
		MessageBox("�˿ڷ�Χ(0~100)");
	}
}*/
	set.DoModal();											//����ģʽ�Ի���
	if(set.m_port>0 && set.m_port<100)							//�ж϶˿ڷ�Χ 
  {
	if(set.m_severadd!="")									//��������ַ����Ϊ��
	{
addr.sin_family=AF_INET;									//Ϊ��ַ�ṹ�еĳ�Ա��ֵ
addr.sin_port=htons(set.m_port);
//host=::gethostbyname(set.m_severadd.GetBuffer(1));				//�ӷ���������ȡ������ַ
addr.sin_addr.S_un.S_addr=inet_addr(/*host-> h_addr_list[0]*/set.m_severadd.GetBuffer(1));	
s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);				//�����׽���
if(connect(s,(sockaddr*)&addr,sizeof(addr))!=-1)
{
	char buf[1024];			//���建���� 
recv(s,buf,1024,0);		//������Ӧ����
::SendMessage(statu,SB_SETTEXT,0,(long)"�Ѿ����ӷ�����,���Ѿ�����");/**/
GetDlgItem(IDC_SENDER)->EnableWindow(true);					//���ø����ؼ�״̬
GetDlgItem(IDC_RECVER)->EnableWindow(true);
GetDlgItem(IDC_SUBJECT)->EnableWindow(true);
GetDlgItem(IDC_SENDMAIL)->EnableWindow(true);
GetDlgItem(IDC_RECVMAIL)->EnableWindow(true);
GetDlgItem(IDC_MAILTEXT)->EnableWindow(true);
GetDlgItem(IDC_SENDER)->SetWindowText("");
	}
else
{
	::SendMessage(statu,SB_SETTEXT,0,(long)"����ʧ�ܣ������ԣ�");
	}}

	else{
		if(MessageBox("��������ַ����Ϊ��")==IDOK)
		{
	GetDlgItem(IDC_SENDER)->EnableWindow(false);					//���ø����ؼ�״̬
GetDlgItem(IDC_RECVER)->EnableWindow(false);
GetDlgItem(IDC_SUBJECT)->EnableWindow(false);
GetDlgItem(IDC_SENDMAIL)->EnableWindow(false);
GetDlgItem(IDC_RECVMAIL)->EnableWindow(false);
GetDlgItem(IDC_MAILTEXT)->EnableWindow(false);
			this->OnPeizhi();
			
	}}}
else
	{
		MessageBox("�˿ڷ�Χ(0~100)");
		this->OnPeizhi();
	}
//::SendMessage(statu,SB_SETTEXT,0,(long)"�ʼ����ͳɹ���");
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
