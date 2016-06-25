// P2P���粥����View.cpp : implementation of the CP2PView class
//

#include "stdafx.h"
#include "P2P���粥����.h"

#include "P2P���粥����Doc.h"
#include "P2P���粥����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#pragma comment( lib, "winmm.lib")
/////////////////////////////////////////////////////////////////////////////
// CP2PView

IMPLEMENT_DYNCREATE(CP2PView, CFormView)

BEGIN_MESSAGE_MAP(CP2PView, CFormView)
	//{{AFX_MSG_MAP(CP2PView)
	ON_BN_CLICKED(IDC_FIND, OnFind)
	ON_BN_CLICKED(IDC_FIND2, OnFind2)
	ON_BN_CLICKED(IDC_KONGZHI, OnKongzhi)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_PRE, OnPre)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_MESSAGE(WM_SOCK,Onsoc)
	ON_BN_CLICKED(IDC_LIULAN, OnLiulan)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CP2PView construction/destruction

CP2PView::CP2PView()
	: CFormView(CP2PView::IDD)
{
	//{{AFX_DATA_INIT(CP2PView)
	//}}AFX_DATA_INIT
	// TODO: add construction code here
index=0;
n=0;
flag=0;
}

CP2PView::~CP2PView()
{
}

void CP2PView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CP2PView)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_RADIO2,m_radio2);
	DDX_Control(pDX, IDC_RADIO1,m_radio1);
	//}}AFX_DATA_MAP
}

BOOL CP2PView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CP2PView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
LVCOLUMN lv;

lv.mask=LVCF_TEXT|LVCF_FMT|LVCF_WIDTH;
lv.fmt=LVCFMT_CENTER;
lv.pszText="������";
lv.cx=110;
m_list.InsertColumn(0,&lv);
lv.pszText="�ݳ���";
m_list.InsertColumn(1,&lv);
lv.pszText="��������";
m_list.InsertColumn(2,&lv);
lv.pszText="�ļ�·��";
m_list.InsertColumn(3,&lv);
m_radio2.SetCheck(1);
//GetDlgItem(IDC_EDIT1)->EnableWindow(false);
GetDlgItem(IDC_LIULAN)->EnableWindow(false);
GetDlgItem(IDC_PLAY)->EnableWindow(false);
GetDlgItem(IDC_STOP)->EnableWindow(false);
GetDlgItem(IDC_PRE)->EnableWindow(false);
GetDlgItem(IDC_NEXT)->EnableWindow(false);
    WSADATA data;
	char name;
	DWORD ss=MAKEWORD(2,0);//��ʼ��SOCKET��
   ::WSAStartup(ss,&data);
   s1=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
   s2=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	::gethostname((char*)&name,(int)sizeof(name));//�����������
	hostent *p=::gethostbyname((char*)&name);
	 in_addr *a=(in_addr*)*p->h_addr_list;// ��ñ���IP��ַ
	 CString str=::inet_ntoa(a[0]);
	 sockaddr_in addr;
	 addr.sin_family=AF_INET;
	addr.sin_port=htons(80);
	addr.sin_addr.S_un.S_addr=inet_addr(str);
	::bind(s1,(sockaddr*)&addr,sizeof(addr));
	::listen(s1,1);
WSAAsyncSelect(s1,this->m_hWnd,WM_SOCK,FD_ACCEPT|FD_READ);
WSAAsyncSelect(s2,this->m_hWnd,WM_SOCK,FD_ACCEPT|FD_READ);
memset(&s,0,5);
i=0;
}
/////////////////////////////////////////////////////////////////////////////
// CP2PView printing

BOOL CP2PView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CP2PView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CP2PView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CP2PView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CP2PView diagnostics

#ifdef _DEBUG
void CP2PView::AssertValid() const
{
	CFormView::AssertValid();
}

void CP2PView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CP2PDoc* CP2PView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CP2PDoc)));
	return (CP2PDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CP2PView message handlers


void CP2PView::OnLiulan() 
{
	// TODO: Add your control notification handler code here
	CFileFind findfile;
	CString str2,strTmp;
	CString strpath="";
//CFileDialog filed(true,NULL,NULL,OFN_HIDEREADONLY,strpath,NULL);
//if(filed.DoModal()==IDOK)
	BROWSEINFO   bBinfo;   
    memset(&bBinfo,0,sizeof(BROWSEINFO));     //����ṹ����ʼ��   
    bBinfo.hwndOwner=m_hWnd;//���öԻ��������߾��   
    
            bBinfo.lpszTitle="��ѡ�񱣴�·����";   
            bBinfo.ulFlags=BIF_RETURNONLYFSDIRS;   //���ñ�־ֻ����ѡ��Ŀ¼           
            LPITEMIDLIST lpDlist;   

    lpDlist=SHBrowseForFolder(&bBinfo)   ;   //��ʾѡ��Ի���   
    if(lpDlist!=NULL)   
    {   
      SHGetPathFromIDList(lpDlist,strTmp.GetBuffer(0));//����Ŀ��ʶ�б�ת����Ŀ¼   
		GetDlgItem(IDC_EDIT1)->SetWindowText(strTmp);
	}
													   
/*strcat(strTmp.GetBuffer(0),"\\*.mp3");//"F:\\����\\11\\*.mp3"

//POSITION pt=filed.GetStartPosition();
//CString path=filed.GetNextPathName(pt);
findfile.FindFile(strTmp);	
while(findfile.FindNextFile())
{						
str2=findfile.GetFilePath();					//��ȡ�ļ�·��
CFile file(str2,CFile::modeRead);	//�����ļ�����
file.Seek(-128,CFile::end);	//���ļ���β���ƶ��ļ�ָ�뵽128�ֽڴ�
file.Read(&mp.mp3,128);
file.Close();
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,mp.mp3.title);//������
m_list.SetItemText(nRow,1,mp.mp3.arti);//��������
if(mp.mp3.heade && "TAG")
{
	CString mp3="MP3";
m_list.SetItemText(nRow,2,mp3);//��������
}
m_list.SetItemText(nRow,3,str2);
sprintf(mp.str,"%s",str2.GetBuffer(0));
mp.mp3.text[28]=0;
mp.mp3.year[4]=0;
mp.mp3.alb[30]=0;

CFile file1("�����б�.lw",CFile::modeReadWrite|CFile::modeNoTruncate|CFile::modeCreate|CFile::typeBinary);//CFile::typeText
file1.Seek(0,CFile::end);
file1.Write(&mp,sizeof(mp));
file1.Flush();
file1.Close();
}}*/
}

void CP2PView::OnFind() 
{

	
}

void CP2PView::OnFind2() 
{
	
	CFileFind findfile;
	CString str2,strTmp;
	CString strpath="";
	BROWSEINFO   bBinfo;   
    memset(&bBinfo,0,sizeof(BROWSEINFO));     //����ṹ����ʼ��   
    bBinfo.hwndOwner=m_hWnd;//���öԻ��������߾��   
    
            bBinfo.lpszTitle="��ѡ��װ·����";   
            bBinfo.ulFlags=BIF_RETURNONLYFSDIRS;   //���ñ�־ֻ����ѡ��Ŀ¼           
            LPITEMIDLIST lpDlist;   

    lpDlist=SHBrowseForFolder(&bBinfo)   ;   //��ʾѡ��Ի���   
    if(lpDlist!=NULL)   
    {   
      SHGetPathFromIDList(lpDlist,strTmp.GetBuffer(0));//����Ŀ��ʶ�б�ת����Ŀ¼   
strcat(strTmp.GetBuffer(0),"\\*.mp3");//"F:\\����\\11\\*.mp3"
findfile.FindFile(strTmp);	
while(findfile.FindNextFile())
{						
str2=findfile.GetFilePath();					//��ȡ�ļ�·��
CFile file(str2,CFile::modeRead);	//�����ļ�����
file.Seek(-128,CFile::end);	//���ļ���β���ƶ��ļ�ָ�뵽128�ֽڴ�
file.Read(&mp.mp3,128);
file.Close();
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,mp.mp3.title);//������
m_list.SetItemText(nRow,1,mp.mp3.arti);//��������
if(mp.mp3.heade && "TAG")
{
	CString mp3="MP3";
m_list.SetItemText(nRow,2,mp3);//��������
}
m_list.SetItemText(nRow,3,str2);
sprintf(mp.str,"%s",str2.GetBuffer(1));
mp.mp3.text[28]=0;
mp.mp3.year[4]=0;
mp.mp3.alb[30]=0;
CFile file1("�б�.txt",CFile::modeReadWrite|CFile::modeNoTruncate|CFile::modeCreate|CFile::typeBinary);//CFile::typeText
file1.Seek(0,CFile::end);
file1.Write(&mp,sizeof(mp));
file1.Flush();
file1.Close();
}}
}

void CP2PView::OnKongzhi() 
{
GetDlgItem(IDC_PLAY)->EnableWindow(true);
GetDlgItem(IDC_STOP)->EnableWindow(true);
GetDlgItem(IDC_PRE)->EnableWindow(true);
GetDlgItem(IDC_NEXT)->EnableWindow(true);
flag=1;	
}

void CP2PView::OnPlay() 
{
CString str,text;									//�����ַ�������
	char str1[100];									//�����ַ�����
	str=m_list.GetItemText(n,3);						//��ȡĬ���б����е�MP3�ļ�·��
if(open.wDeviceID)								//�ж�ָ��ID��MCI�豸�Ƿ��ʼ��
{
  mciSendCommand(open.wDeviceID,MCI_CLOSE,0,0);	//����ʼ�������͹ر����MCI
}
open.lpstrElementName=str;							//��ȡ��·������MCI��ʼ���ṹ��	
open.lpstrDeviceType="mpegvideo";					//ָ��MCI���豸����
err=mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT|MCI_WAIT,(DWORD)(LPVOID)&open);//��ʼ��MCI�豸
if(err==0)										//����ʼ���ɹ�
{
MCI_PLAY_PARMS play;							
mciSendCommand(open.wDeviceID,MCI_PLAY,0,(DWORD)&play);
												//��MCI�豸���Ͳ�������

}
else											//���豸��ʼ��ʧ��			
{
mciGetErrorString(err,(LPSTR)str1,100);				//��ȡ������Ϣ
	MessageBox(str1);								//��ʾ������Ϣ
}
m_list.SetCheck(n,true);
}
void CP2PView::OnStop() 
{
	mciSendCommand(open.wDeviceID,MCI_STOP,0,0);
	if(n<m_list.GetItemCount())
	{
		n+=3;
	}
	else
	{
		n=0;
	}
	m_list.SetCheck(n,true);
}

void CP2PView::OnPre() 
{
CString str;
if(n==0)
{
	n=0;
}
else
{
n=n-1;
}
str=m_list.GetItemText(n,3);
if(open.wDeviceID)
{
  mciSendCommand(open.wDeviceID,MCI_CLOSE,0,0);
}
open.lpstrElementName=str;
open.lpstrDeviceType="mpegvideo";
err=mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT|MCI_WAIT,(DWORD)(LPVOID)&open);
if(err==0)
{
MCI_PLAY_PARMS play;
mciSendCommand(open.wDeviceID,MCI_PLAY,0,(DWORD)&play);
}	
}

void CP2PView::OnNext() 
{
	if(n<m_list.GetItemCount())
	{
		n+=1;
	m_list.SetCheck(n,true);
	CString str=m_list.GetItemText(n,3);						//��ȡĬ���б����е�MP3�ļ�·��
if(open.wDeviceID)								//�ж�ָ��ID��MCI�豸�Ƿ��ʼ��
{
  mciSendCommand(open.wDeviceID,MCI_CLOSE,0,0);	//����ʼ�������͹ر����MCI
}
open.lpstrElementName=str;							//��ȡ��·������MCI��ʼ���ṹ��	
open.lpstrDeviceType="mpegvideo";					//ָ��MCI���豸����
err=mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT|MCI_WAIT,(DWORD)(LPVOID)&open);
}
	if(err==0)										//����ʼ���ɹ�
{
MCI_PLAY_PARMS play;							
mciSendCommand(open.wDeviceID,MCI_PLAY,0,(DWORD)&play);
	}
}

void CP2PView::OnRadio1() 
{
	
	GetDlgItem(IDC_LIULAN)->EnableWindow(true);
	GetDlgItem(IDC_RADIO2)->EnableWindow(false);
	::SetWindowText(this->GetParent()->m_hWnd,"ע�⣺��ʹ���ļ��󣬸��ļ������浽����ѡ��ı���·���У�");
}

void CP2PView::OnRadio2() 
{
	::SetWindowText(this->GetParent()->m_hWnd,"ע�⣺��ѡ����ʹ���ļ��󣬽���ɾ����");
	GetDlgItem(IDC_RADIO1)->EnableWindow(false);
}

void CP2PView::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString str;
POSITION pos=m_list.GetFirstSelectedItemPosition(); 
if(pos==NULL)
{
	MessageBox("�û�˫����λ�ô������б�Ϊ�գ����û�˫��λ��Ӧ��Ϊÿ�е�һ�У�");
}
else
{
	    int nItem=m_list.GetNextSelectedItem(pos);    
		int index=nItem;
str=m_list.GetItemText(nItem,3);
if(open.wDeviceID)
{
  mciSendCommand(open.wDeviceID,MCI_CLOSE,0,0);
}

open.lpstrElementName=str;
open.lpstrDeviceType="mpegvideo";
err=mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT|MCI_WAIT,(DWORD)(LPVOID)&open);
if(err==0)
{
MCI_PLAY_PARMS play;
mciSendCommand(open.wDeviceID,MCI_PLAY,0,(DWORD)&play);
}
}
	*pResult = 0;
}


void CP2PView::OnDraw(CDC* pDC) 
{
	if(m_list.GetItemCount()!=0 && flag!=1)
	{
GetDlgItem(IDC_PLAY)->EnableWindow(true);
GetDlgItem(IDC_STOP)->EnableWindow(true);
GetDlgItem(IDC_PRE)->EnableWindow(true);
GetDlgItem(IDC_NEXT)->EnableWindow(true);	
	}
	
}

void CP2PView::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int nItem;
	POSITION pos=m_list.GetFirstSelectedItemPosition(); 
if(pos!=NULL)
{
	nItem=m_list.GetNextSelectedItem(pos);
	n=nItem;
}
	*pResult = 0;
}


void CP2PView::Onsoc(WPARAM wParam,LPARAM lParam)
{   
	
	switch (lParam)

{
       case FD_ACCEPT:
		     if(i<5)
			 {
				 s[i]=::accept(s1,NULL,NULL);
				 WSAAsyncSelect(s[i],this->m_hWnd,WM_SOCK,FD_READ);
			 }
			break;
        
		case FD_READ:
	         
			break;
		default:  break;
	  
}
}
DWORD WINAPI Senddata(LPVOID lpParameter)
{

	return 1;
}

