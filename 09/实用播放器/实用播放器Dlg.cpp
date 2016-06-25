// ʵ�ò�����Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ʵ�ò�����.h"
#include "ʵ�ò�����Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog
MCI_OPEN_PARMS open;
DWORD WINAPI setprocess(LPVOID lpParameter);
DWORD *npo,npos,err;
static int index=0;
CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
memset(&mp.str,0,51);
n=0;
m=0;
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_LIST2, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, OnDblclkList2)
	ON_BN_CLICKED(IDC_PRE, OnPre)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_ZANTING, OnZanting)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_SOUSUOMULU, OnSousuomulu)
	ON_BN_CLICKED(IDC_SOUSUOMULU2, OnSousuomulu2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	bit=::LoadBitmap(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDB_BITMAP1));
	dc1=::CreateCompatibleDC(::GetDC(::GetDlgItem(this->m_hWnd,IDC_TUPIAN)));
	// TODO: Add extra initialization here
	memset(&mp,0,sizeof(mp));
	LVCOLUMN lv;
lv.mask=LVCF_TEXT|LVCF_FMT|LVCF_WIDTH;
lv.fmt=LVCFMT_CENTER;
lv.pszText="������";
lv.cx=100;
m_list.InsertColumn(0,&lv);
lv.pszText="�ݳ���";
m_list.InsertColumn(1,&lv);
lv.pszText="��������";
m_list.InsertColumn(2,&lv);
lv.pszText="�ļ�·��";
m_list.InsertColumn(3,&lv);	
CFile file1("�����б�.lw",CFile::modeRead|CFile::modeCreate|CFile::modeNoTruncate|CFile::typeBinary);
int i=file1.GetLength()/sizeof(mp);
if(i!=0)
{
for(int j=0;j<=i;j++)
{
file1.Read(&mp,sizeof(mp));
//
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,mp.mp3.title);//������
m_list.SetItemText(nRow,1,mp.mp3.arti);//��������
if(mp.mp3.heade &&"TAG")
{
	CString mp3="MP3";
m_list.SetItemText(nRow,2,mp3);//��������
}
m_list.SetItemText(nRow,3,(LPTSTR)mp.str);
}
}
//MessageBox(mp.str);
mp3struct mp3={0};										//���岢��ʼ���ַ�����
CFile file("C:\\���� .mp3",CFile::modeReadWrite|CFile::typeBinary);	//�����ļ�����
file.Seek(-128,CFile::end);									//���ļ���β���ƶ��ļ�ָ��
file.Read(&mp3,128);										//���ļ��ж�ȡ128���ֽ�
CString str="";
str+="��������"	;										//���岢��ʼ���ַ���
str+=mp3.title;											//��ʾ���ֱ���
str+="\r\n";												//��ӻ��з�
str+="�ݳ��ߣ�";
str+=mp3.arti;											//��ʾ�����ݳ���
MessageBox(str);										//��ʾ�����ļ������Ϣ
		

file1.Close();
statu=::CreateStatusWindow(WS_CHILD|WS_VISIBLE,"���ֲ�����V1.0",this->m_hWnd,IDC_123);
m_tab.InsertItem(TCIF_TEXT,0,"�����б�",NULL,NULL);
m_tab.InsertItem(TCIF_TEXT,1,"��������",NULL,NULL);
GetDlgItem(IDC_SOUSUOMULU)->ShowWindow(false);
		GetDlgItem(IDC_SOUSUOMULU2)->ShowWindow(false);
		GetDlgItem(IDC_PLAY)->EnableWindow(false);
GetDlgItem(IDC_ZANTING)->EnableWindow(false);
GetDlgItem(IDC_PRE)->EnableWindow(false);
GetDlgItem(IDC_NEXT)->EnableWindow(false);
GetDlgItem(IDC_STOP)->EnableWindow(false);
SetTimer(1,1000,NULL);
this->SetWindowText("������ V1.0 ����ΰ��");
	return TRUE;  // return TRUE  unless you set the focus to a control
}



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
	::SelectObject(dc1,bit);
	::StretchBlt(::GetDC(::GetDlgItem(this->m_hWnd,IDC_TUPIAN)),1,1,450,80,dc1,0,0,400,330,SRCCOPY);
if(m_list.GetItemCount()==0)
{
GetDlgItem(IDC_PLAY)->EnableWindow(false);
GetDlgItem(IDC_ZANTING)->EnableWindow(false);
GetDlgItem(IDC_PRE)->EnableWindow(false);
GetDlgItem(IDC_NEXT)->EnableWindow(false);
GetDlgItem(IDC_STOP)->EnableWindow(false);
}
else
{
GetDlgItem(IDC_PLAY)->EnableWindow(true);
GetDlgItem(IDC_ZANTING)->EnableWindow(true);
GetDlgItem(IDC_PRE)->EnableWindow(true);
GetDlgItem(IDC_NEXT)->EnableWindow(true);
GetDlgItem(IDC_STOP)->EnableWindow(true);
}

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
int n=m_tab.GetCurSel();
switch(n)
{
case 0:
{
	GetDlgItem(IDC_SOUSUOMULU)->ShowWindow(false);
		GetDlgItem(IDC_SOUSUOMULU2)->ShowWindow(false);
		GetDlgItem(IDC_LIST2)->ShowWindow(true);
		break;}
case 1:
	{
		GetDlgItem(IDC_SOUSUOMULU)->ShowWindow(true);
		GetDlgItem(IDC_SOUSUOMULU2)->ShowWindow(true);
		GetDlgItem(IDC_LIST2)->ShowWindow(false);
		break;
	}
}

	*pResult = 0;
}

void CMyDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
//	m_process.SetStep(5);
   //m_process.StepIt();

	 CTime time=time.GetCurrentTime();
	 CString str=time.Format("��ǰʱ�䣺 %H:%M:%S");
	 ::SetWindowText(statu,str);
     
	CDialog::OnTimer(nIDEvent);
	
}

void CMyDlg::OnAdd() 
{
CString strpath="MP3����(*.mp3)|*.mp3||";
CFileDialog filed(true,NULL,NULL,OFN_HIDEREADONLY,strpath,NULL);
if(filed.DoModal()==IDOK)
{
POSITION pt=filed.GetStartPosition();
CString path=filed.GetNextPathName(pt);	
CFile file(path,CFile::modeRead);	//�����ļ�����
file.Seek(-128,CFile::end);	//���ļ���β���ƶ��ļ�ָ�뵽128�ֽڴ�
file.Read(&mp.mp3,128);
file.Close();
//mp.str=path.GetBuffer(0);
//strcpy(mp.str,path.GetBuffer(1));
mp.mp3.text[28]=0;
mp.mp3.year[4]=0;
mp.mp3.alb[30]=0;
CFile file1("�����б�.lw",CFile::modeReadWrite|CFile::typeBinary);//CFile::typeText
file1.Seek(0,CFile::end);
file1.WriteHuge(&mp,sizeof(mp));
file1.Flush();
file1.Close();
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,mp.mp3.title);//������
m_list.SetItemText(nRow,1,mp.mp3.arti);//��������
if(mp.mp3.heade && "TAG")
{
	CString mp3="MP3";
m_list.SetItemText(nRow,2,mp3);//��������
}
m_list.SetItemText(nRow,3,path);
	

/*

CFile file3("�����б�.txt",CFile::modeWrite|CFile::typeBinary);
file3.Write(path.GetBuffer(0),path.GetLength());
file3.Flush();
file3.Close();*/
}}
void CMyDlg::OnPlay() 
{
//mciSendCommand(NULL,MCI_OPEN,MCI_WAIT|MCI_OPEN_TYPE,(DWORD)&openParms);
//mciID=mciGetDeviceID( openParms.lpstrDeviceType );
//mciSendCommand(mciID,MCI_SET,MCI_WAIT|MCI_SET_DOOR_OPEN,NULL);
//mciSendCommand(mciID,MCI_SET,MCI_WAIT|MCI_SET_DOOR_CLOSED,NULL);

CString str;
	char str1[100];
	int nItem;
	POSITION pos=m_list.GetFirstSelectedItemPosition(); 
if(pos!=NULL)
{
	nItem=m_list.GetNextSelectedItem(pos);
index=nItem;
   str=m_list.GetItemText(nItem,3);
}
if(open.wDeviceID)
{
  mciSendCommand(open.wDeviceID,MCI_CLOSE,0,0);
}

open.lpstrElementName=str;//"F:\\����\\11\\�³���  ��û���˸�����.mp3";//"C:\\oo.mp3";
open.lpstrDeviceType="mpegvideo";
err=mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT|MCI_WAIT,(DWORD)(LPVOID)&open);
if(err==0)
{
MCI_PLAY_PARMS play;
//play.dwFrom=0;
//play.dwCallback=(UINT)this->m_hWnd;
mciSendCommand(open.wDeviceID,MCI_PLAY,0,(DWORD)&play);
::Sleep(1000);
::CreateThread(NULL,0,setprocess,GetDlgItem(IDC_STA1)->m_hWnd,0,NULL);

//char wStr[256]={0};
//ReadProcessMemory(::GetCurrentProcess(),LPVOID(npos),&wStr,sizeof(npos),0);
}
else
{

	mciGetErrorString(err,(LPSTR)str1,100);
	MessageBox(str1);
}
 GetDlgItem(IDC_STOP)->SetWindowText("ֹͣ");
}

DWORD WINAPI setprocess(LPVOID lpParameter)
{
CString str,str1;
int i=0;
MCI_STATUS_PARMS stat={0};
stat.dwItem=MCI_STATUS_LENGTH;
mciSendCommand(open.wDeviceID,MCI_STATUS,MCI_STATUS_ITEM,(DWORD)&stat);
npo=&stat.dwReturn;
BYTE a=MCI_MSF_MINUTE(npo);
BYTE b=MCI_MSF_SECOND(npo);
npos=MCI_MAKE_HMS(0,a,b);
str.Format("%d",npo);
SetWindowText((HWND)lpParameter,str);
str+="/";
while(1)
{
Sleep(1000);
stat.dwItem=MCI_STATUS_POSITION ;
err=mciSendCommand(open.wDeviceID,MCI_STATUS,MCI_STATUS_ITEM,(DWORD)&stat);
str1.Format("%d",stat.dwReturn);
strcat((char*)str.GetBuffer(0),(char*)str1.GetBuffer(0));
SetWindowText((HWND)lpParameter,str);
}
return 0;
}



void CMyDlg::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult) 
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
		index=nItem;
str=m_list.GetItemText(nItem,3);
if(open.wDeviceID)
{
  mciSendCommand(open.wDeviceID,MCI_CLOSE,0,0);
}

open.lpstrElementName=str;//"F:\\����\\11\\�³���  ��û���˸�����.mp3";//"C:\\oo.mp3";
open.lpstrDeviceType="mpegvideo";
err=mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT|MCI_WAIT,(DWORD)(LPVOID)&open);
if(err==0)
{
MCI_PLAY_PARMS play;
mciSendCommand(open.wDeviceID,MCI_PLAY,0,(DWORD)&play);
}
}}

void CMyDlg::OnPre() 
{
CString str;
if(index==0)
{
	index=0;
}
else
{
index=index-1;
}
str=m_list.GetItemText(index,3);
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
m_list.SetCheck(index-1,true);	
 GetDlgItem(IDC_STOP)->SetWindowText("ֹͣ");
}

void CMyDlg::OnNext() 
{
	CString str;
//	m_list.GetCurSel

	index=index+1;
	if(index==m_list.GetItemCount())
	{
		//MessageBox("�Բ����Ѿ������һ�׸����ˣ�������ļ�");
		//::SendMessage(statu,SBPS_SETTEXT,"�Բ����Ѿ������һ�׸����ˣ�������ļ�",NULL);
	}
str=m_list.GetItemText(index,3);
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
 GetDlgItem(IDC_STOP)->SetWindowText("ֹͣ");
}

void CMyDlg::OnZanting() 
{
	CString str;
GetDlgItem(IDC_ZANTING)->GetWindowText(str); 
if(n==0)
	{
		mciSendCommand(open.wDeviceID,MCI_PAUSE,0,0);
		GetDlgItem(IDC_ZANTING)->SetWindowText("����");
		n=1;
	}
else
	{
		mciSendCommand(open.wDeviceID,MCI_RESUME,0,0);
		GetDlgItem(IDC_ZANTING)->SetWindowText("��ͣ");
		n=0;
	}
}


void CMyDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	mciSendCommand(open.wDeviceID,MCI_STOP,0,0);
	  index=index+1;	
	  GetDlgItem(IDC_STOP)->SetWindowText("��ֹͣ");

}

void CMyDlg::OnSousuomulu() 
{
	// TODO: Add your control notification handler code here
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
file1.Seek(1,CFile::end);
file1.Write(&mp,sizeof(mp));
file1.Flush();
file1.Close();
}}}
/*
WIN32_FIND_DATA data;
BOOL boo;
HANDLE file=::FindFirstFile("F:\\\\����\\\\11\\\\*.mp3",&data);
if(file!=NULL)
{
 do{ 
CString str;
   str=data.cFileName;				//��ȡ�ļ�·��
CFile file2(str,CFile::modeRead);	//�����ļ�����
file2.Seek(-128,CFile::end);	//���ļ���β���ƶ��ļ�ָ�뵽128�ֽڴ�
file2.Read(&mp.mp3,128);
file2.Close();
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,mp.mp3.title);//������
m_list.SetItemText(nRow,1,mp.mp3.arti);//��������
if(mp.mp3.heade && "TAG")
{
	CString mp3="MP3";
m_list.SetItemText(nRow,2,mp3);//��������
}
m_list.SetItemText(nRow,3,str);
mp.mp3.text[28]=0;
mp.mp3.year[4]=0;
mp.mp3.alb[30]=0;

CFile file1("�����б�.lw",CFile::modeWrite|CFile::modeNoTruncate|CFile::modeCreate);//CFile::typeText
file1.Seek(0,CFile::end);
file1.Write(&mp,sizeof(mp));
file1.Flush();
file1.Close();
boo=:: FindNextFile(file,&data);
}while(boo);
::FindClose(file);								//�ر��ļ��������
}*/



void CMyDlg::OnSousuomulu2() 
{
	// TODO: Add your control notification handler code here
	CFileFind findfile;	
	//CString str[4]={"C:\\","D:\\","E:\\","F:\\"};//�����ļ���������
	CString str2,str3;
							//����Ŀ¼�е�MP3��
findfile.FindFile("F:\\����\\11\\*.mp3",0);	
while(findfile.FindNextFile())
{						
str2=findfile.GetFilePath();										//��ȡ�ļ�·��
CFile file(str2,CFile::modeRead);									//�����ļ�����
file.Seek(-128,CFile::end);										//���ļ���β�ƶ�ָ��
file.Read(&mp.mp3,128);										//��ȡ�ļ�
file.Close();													//�ر��ļ�
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,mp.mp3.title);		//���б��в�����	
m_list.SetItemText(nRow,1,mp.mp3.arti);							//��������
if(mp.mp3.heade && "TAG")
{
	CString mp3="MP3";
m_list.SetItemText(nRow,2,mp3);									//��������
}
m_list.SetItemText(nRow,3,str2);
//mp.str=str2;
sprintf(mp.str,"%s",str2.GetBuffer(0));
//MessageBox(mp.str);
mp.mp3.text[28]=0;											//����ֵ
mp.mp3.year[4]=0;
mp.mp3.alb[30]=0;
CFile file1("�����б�.lw",CFile::modeWrite|CFile::modeNoTruncate|CFile::modeCreate|CFile::typeBinary);													//�����б��ļ�
file1.Seek(0,CFile::end);										//��λ�ļ�ָ�뵽��β
file1.Write(&mp,sizeof(mp));										//д���ļ�
file1.Flush();													//ǿ��д���ļ�
file1.Close();													//�ر��ļ�
}


}
