// 仿QQ程序服务器Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "仿QQ程序服务器.h"
#include "仿QQ程序服务器Dlg.h"
#include "Message.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQQDlg dialog

CQQDlg::CQQDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQQDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQQDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQQDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CQQDlg, CDialog)
	//{{AFX_MSG_MAP(CQQDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQQDlg message handlers

BOOL CQQDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
LVCOLUMN lv;							//定义列表结构体变量
lv.mask=LVCF_TEXT|LVCF_FMT|LVCF_WIDTH;	//初始化结构体各个成员
lv.fmt=LVCFMT_CENTER;
lv.pszText="用户号码";						//设置列表标题
lv.cx=120;								//指定该列宽度
m_list.InsertColumn(0,&lv);					//插入指定列
lv.pszText="IP地址";						//修改列标题
m_list.InsertColumn(1,&lv);					//插入指定列
lv.pszText="用户类型";						//修改列标题
m_list.InsertColumn(2,&lv);					//插入指定列

//msg.DoModal();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
/*CString str[7]={"lymlrl","坚持","star","幻影","C++","ds","星星"};
CString ss[7]={"127.0.0.1","218.6.132.5","192.168.1.1","217.5.6.12","215.6.54.8","218.53.6.5","23.5.88.5"};
for(int i=0;i<=7;i++)
{
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,str[i]);
m_list.SetItemText(nRow,1,ss[i]);		//设置数据	

}*/
void CQQDlg::OnPaint() 
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
HCURSOR CQQDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CQQDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
POSITION pos=m_list.GetFirstSelectedItemPosition(); 
if(pos==NULL)
{
	MessageBox("用户双击的位置错误或该列表为空!");
}
else
{
	    int nItem=m_list.GetNextSelectedItem(pos);
CMessage mesg;
mesg.DoModal( );
}
	*pResult = 0;
}
