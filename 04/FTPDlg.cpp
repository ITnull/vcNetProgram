// FTPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTP.h"
#include "FTPDlg.h"

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
// CFTPDlg dialog

CFTPDlg::CFTPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFTPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFTPDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFTPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFTPDlg)
	
	DDX_Control(pDX, IDC_COMBO1, m_c1);
	DDX_Control(pDX, IDC_COMBO2, m_c2);
	DDX_Control(pDX, IDC_LIST2, m_2);
	DDX_Control(pDX, IDC_LIST1, m_3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFTPDlg, CDialog)
	//{{AFX_MSG_MAP(CFTPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Connect, OnConnect)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFTPDlg message handlers

BOOL CFTPDlg::OnInitDialog()
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
	this->GetDlgItem(IDC_EDIT3)->SetWindowText("anonymous");
	this->GetDlgItem(IDC_EDIT4)->SetWindowText("lymlrl@163.com");
		this->GetDlgItem(IDC_EDIT3)->EnableWindow(false);
		this->GetDlgItem(IDC_EDIT4)->EnableWindow(false);
	   // m_ch1.SetCheck(1);
	
		m_3.InsertColumn(1,"文件名",LVCFMT_CENTER,80);
		m_3.InsertColumn(2,"日期",LVCFMT_CENTER,70);
		m_3.InsertColumn(3,"大小",LVCFMT_CENTER,60);

		m_2.InsertColumn(1,"文件名",LVCFMT_CENTER,80);
		m_2.InsertColumn(2,"日期",LVCFMT_CENTER,70);
		m_2.InsertColumn(3,"大小",LVCFMT_CENTER,60);
			
		m_c1.SetWindowText("C:\\");
		m_c1.AddString("C:\\");
		m_c1.AddString("D:\\");
		m_c1.AddString("E:\\");
		m_c1.AddString("F:\\");
		m_c1.AddString("G:\\");
		m_c1.AddString("H:\\");
		int i=0;/////////设置列表控件内容
	/*	while(i<=1)
	{
	m_3.InsertItem(i,"sda",NULL);
	m_3.SetItemText(i,1,"123132");
	if(i==5)m_3.SetItemText(i,2,"123132");
else
{m_3.SetItemText(i,2,"897984");}
	i++;
		}*/
	//m_3.InsertItem(&v);
		
        return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFTPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFTPDlg::OnPaint() 
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

m_3.SetTextColor(RGB(255,0,0));
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFTPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//DEL void CFTPDlg::OnButton1() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	
//DEL }



void CFTPDlg::OnConnect() 
{
	CString str1,str2;
	int port=0;
	this->GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	this->GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	port=(int)atoi(str2);

	//str1.Format("sahsgd:%d\n",port);
//	MessageBox(str1);

}
void CFTPDlg::OnSelchangeCombo1()			//组合框出现选择
{
	// TODO: Add your control notification handler code here
	int i=m_c1.GetCurSel();
	m_c1.GetLBText(i,str);


}

void CFTPDlg::OnSelchangeCombo2() 
{	
	
}


void CFTPDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	this->GetDlgItem(IDC_EDIT3)->EnableWindow(true);
		this->GetDlgItem(IDC_EDIT4)->EnableWindow(true);
}
void CFTPDlg::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{	
/*	CMenu menu;
	CRect rc(0,0,1200,1200);
	menu.LoadMenu(IDR_MENU1);
	CMenu* menu2=menu.GetSubMenu(0);
	POINT pt;
	::GetCursorPos(&pt);
	::TrackPopupMenu(menu2->m_hMenu,TPM_RIGHTALIGN|TPM_RIGHTBUTTON,pt.x,pt.y,0,AfxGetMainWnd()->m_hWnd,rc);*/	
	
//	m_2.GetItemText(
//	struct LVITEM v;
	int j;
CString str;

	j=m_3.GetCheck(1);
	str=m_3.GetItemText(2,2);
	MessageBox(str);
	*pResult = 0;
}


