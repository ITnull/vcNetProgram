// ��QQ����Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "��QQ����.h"
#include "��QQ����Dlg.h"

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
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME1);
	m_bit.LoadBitmap(IDB_BITMAP1);
	
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
	ON_BN_CLICKED(IDC_EMAIL, OnEmail)
	ON_BN_CLICKED(IDC_NET, OnNet)
	ON_WM_CTLCOLOR()
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, OnColumnclickList1)
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
	::SendMessage(this->m_hWnd,WM_SETICON,0,(unsigned int)m_hIcon);
	CImageList *img;
	img=new CImageList();
	img->Create(32,32,ILC_COLOR4,3,2); 
	img->Add(&m_bit,RGB(255,0,255));


	LVCOLUMN lv;							//�����б�ṹ�����
lv.mask=LVCF_TEXT|LVCF_FMT|LVCF_WIDTH|LVIF_IMAGE;	//��ʼ���ṹ�������Ա
lv.fmt=LVCFMT_CENTER;
lv.pszText="   �����б�";						//�����б����
lv.cx=140;							//ָ�����п��
m_list.InsertColumn(0,&lv);	
m_list.SetImageList(img,LVSIL_SMALL);
















CString str[7]={"lymlrl","���","star","��Ӱ","C++","ds","����"};
for(int i=0;i<7;i++)
{
m_list.InsertItem(i,str[i],i);
}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

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

m_bit1.LoadBitmap(IDB_BITMAP2);
dc1=::CreateCompatibleDC(::GetDC(this->m_hWnd));	
::SelectObject(dc1,m_bit1.m_hObject);
::StretchBlt(::GetDC(this->m_hWnd),0,0,500,650,dc1,0,0,300,300,SRCCOPY);
}
// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQQDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



//DEL HBRUSH CQQDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
//DEL {	
//DEL CBitmap bm; 
//DEL bm.LoadBitmap(IDB_BITMAP1); // IDB_BITMAP1ΪBITMAP��ԴID,����ָ��bitmapͼƬ��·�� 
//DEL CBrush m_Brush;
//DEL m_Brush.CreatePatternBrush(&bm); 
//DEL 	return m_Brush;
//DEL }



void CQQDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	POSITION pos=m_list.GetFirstSelectedItemPosition(); 	//��ȡ���˫��λ��
	if(pos==NULL)								//�ж�λ���Ƿ�Ϊ��
{
	MessageBox("�û�˫����λ�ô������б�Ϊ��!");
}
else
{
	    int nItem=m_list.GetNextSelectedItem(pos);	//��ȡ��λ�õ�����ֵ
    CString  str=m_list.GetItemText(nItem,0);		//��ȡ��Ӧ�Ŀͻ�������ǳ�=
send.m_name="�ͻ��ǳƣ�";								//�Ի����ʼ��ʱ��ֵ
strcat(send.m_name.GetBuffer(1),str.GetBuffer(1));
send.DoModal( );								//��ʾ��Ϣ���Ϳ�
}
	*pResult = 0;
}

void CQQDlg::OnEmail() 
{
 ::ShellExecute(NULL,NULL,"mailto:",NULL,NULL,SW_SHOW);
}

void CQQDlg::OnNet() 
{
net.DoModal( );
}



HBRUSH CQQDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	 CBrush m_Brush; 
	 CBitmap bm;
if(CTLCOLOR_BTN==nCtlColor)
	{
		 if(pWnd->GetDlgCtrlID()==IDC_NET)  
		 {
          pDC->SetBkMode(TRANSPARENT);  
		  pDC->SetBkColor(RGB(0,0,0));
		  pDC->SetTextColor(RGB(255,0,0));
		  
bm.LoadBitmap(IDB_BITMAP1);
		 
 m_Brush.CreatePatternBrush(&bm);
	}}
	return (HBRUSH)m_Brush;
}

void CQQDlg::OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_LIST1)->ShowWindow(false);
	*pResult = 0;
}
