// 实用播放器Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "实用播放器.h"
#include "实用播放器Dlg.h"

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
lv.pszText="歌曲名";
lv.cx=100;
m_list.InsertColumn(0,&lv);
lv.pszText="演唱者";
m_list.InsertColumn(1,&lv);
lv.pszText="歌曲类型";
m_list.InsertColumn(2,&lv);
lv.pszText="文件路径";
m_list.InsertColumn(3,&lv);	
CFile file1("歌曲列表.lw",CFile::modeRead|CFile::modeCreate|CFile::modeNoTruncate|CFile::typeBinary);
int i=file1.GetLength()/sizeof(mp);
if(i!=0)
{
for(int j=0;j<=i;j++)
{
file1.Read(&mp,sizeof(mp));
//
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,mp.mp3.title);//插入行
m_list.SetItemText(nRow,1,mp.mp3.arti);//设置数据
if(mp.mp3.heade &&"TAG")
{
	CString mp3="MP3";
m_list.SetItemText(nRow,2,mp3);//设置数据
}
m_list.SetItemText(nRow,3,(LPTSTR)mp.str);
}
}
//MessageBox(mp.str);
mp3struct mp3={0};										//定义并初始化字符数组
CFile file("C:\\卡门 .mp3",CFile::modeReadWrite|CFile::typeBinary);	//创建文件对象
file.Seek(-128,CFile::end);									//从文件结尾处移动文件指针
file.Read(&mp3,128);										//从文件中读取128个字节
CString str="";
str+="歌曲名："	;										//定义并初始化字符串
str+=mp3.title;											//显示音乐标题
str+="\r\n";												//添加换行符
str+="演唱者：";
str+=mp3.arti;											//显示音乐演唱者
MessageBox(str);										//显示音乐文件相关信息
		

file1.Close();
statu=::CreateStatusWindow(WS_CHILD|WS_VISIBLE,"音乐播放器V1.0",this->m_hWnd,IDC_123);
m_tab.InsertItem(TCIF_TEXT,0,"播放列表",NULL,NULL);
m_tab.InsertItem(TCIF_TEXT,1,"搜索歌曲",NULL,NULL);
GetDlgItem(IDC_SOUSUOMULU)->ShowWindow(false);
		GetDlgItem(IDC_SOUSUOMULU2)->ShowWindow(false);
		GetDlgItem(IDC_PLAY)->EnableWindow(false);
GetDlgItem(IDC_ZANTING)->EnableWindow(false);
GetDlgItem(IDC_PRE)->EnableWindow(false);
GetDlgItem(IDC_NEXT)->EnableWindow(false);
GetDlgItem(IDC_STOP)->EnableWindow(false);
SetTimer(1,1000,NULL);
this->SetWindowText("播放器 V1.0 （梁伟）");
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
	 CString str=time.Format("当前时间： %H:%M:%S");
	 ::SetWindowText(statu,str);
     
	CDialog::OnTimer(nIDEvent);
	
}

void CMyDlg::OnAdd() 
{
CString strpath="MP3音乐(*.mp3)|*.mp3||";
CFileDialog filed(true,NULL,NULL,OFN_HIDEREADONLY,strpath,NULL);
if(filed.DoModal()==IDOK)
{
POSITION pt=filed.GetStartPosition();
CString path=filed.GetNextPathName(pt);	
CFile file(path,CFile::modeRead);	//创建文件对象
file.Seek(-128,CFile::end);	//从文件结尾处移动文件指针到128字节处
file.Read(&mp.mp3,128);
file.Close();
//mp.str=path.GetBuffer(0);
//strcpy(mp.str,path.GetBuffer(1));
mp.mp3.text[28]=0;
mp.mp3.year[4]=0;
mp.mp3.alb[30]=0;
CFile file1("歌曲列表.lw",CFile::modeReadWrite|CFile::typeBinary);//CFile::typeText
file1.Seek(0,CFile::end);
file1.WriteHuge(&mp,sizeof(mp));
file1.Flush();
file1.Close();
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,mp.mp3.title);//插入行
m_list.SetItemText(nRow,1,mp.mp3.arti);//设置数据
if(mp.mp3.heade && "TAG")
{
	CString mp3="MP3";
m_list.SetItemText(nRow,2,mp3);//设置数据
}
m_list.SetItemText(nRow,3,path);
	

/*

CFile file3("歌曲列表.txt",CFile::modeWrite|CFile::typeBinary);
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

open.lpstrElementName=str;//"F:\\音乐\\11\\陈楚生  有没有人告诉你.mp3";//"C:\\oo.mp3";
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
 GetDlgItem(IDC_STOP)->SetWindowText("停止");
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
	MessageBox("用户双击的位置错误或该列表为空！（用户双击位置应该为每行第一列）");
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

open.lpstrElementName=str;//"F:\\音乐\\11\\陈楚生  有没有人告诉你.mp3";//"C:\\oo.mp3";
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
 GetDlgItem(IDC_STOP)->SetWindowText("停止");
}

void CMyDlg::OnNext() 
{
	CString str;
//	m_list.GetCurSel

	index=index+1;
	if(index==m_list.GetItemCount())
	{
		//MessageBox("对不起，已经是最后一首歌曲了，请添加文件");
		//::SendMessage(statu,SBPS_SETTEXT,"对不起，已经是最后一首歌曲了，请添加文件",NULL);
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
 GetDlgItem(IDC_STOP)->SetWindowText("停止");
}

void CMyDlg::OnZanting() 
{
	CString str;
GetDlgItem(IDC_ZANTING)->GetWindowText(str); 
if(n==0)
	{
		mciSendCommand(open.wDeviceID,MCI_PAUSE,0,0);
		GetDlgItem(IDC_ZANTING)->SetWindowText("继续");
		n=1;
	}
else
	{
		mciSendCommand(open.wDeviceID,MCI_RESUME,0,0);
		GetDlgItem(IDC_ZANTING)->SetWindowText("暂停");
		n=0;
	}
}


void CMyDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	mciSendCommand(open.wDeviceID,MCI_STOP,0,0);
	  index=index+1;	
	  GetDlgItem(IDC_STOP)->SetWindowText("已停止");

}

void CMyDlg::OnSousuomulu() 
{
	// TODO: Add your control notification handler code here
	CFileFind findfile;
	CString str2,strTmp;
	CString strpath="";
	BROWSEINFO   bBinfo;   
    memset(&bBinfo,0,sizeof(BROWSEINFO));     //定义结构并初始化   
    bBinfo.hwndOwner=m_hWnd;//设置对话框所有者句柄   
    
            bBinfo.lpszTitle="请选择安装路径：";   
            bBinfo.ulFlags=BIF_RETURNONLYFSDIRS;   //设置标志只允许选择目录           
            LPITEMIDLIST lpDlist;   

    lpDlist=SHBrowseForFolder(&bBinfo)   ;   //显示选择对话框   
    if(lpDlist!=NULL)   
    {   
      SHGetPathFromIDList(lpDlist,strTmp.GetBuffer(0));//把项目标识列表转化成目录   
strcat(strTmp.GetBuffer(0),"\\*.mp3");//"F:\\音乐\\11\\*.mp3"
findfile.FindFile(strTmp);	
while(findfile.FindNextFile())
{						
str2=findfile.GetFilePath();					//获取文件路径
CFile file(str2,CFile::modeRead);	//创建文件对象
file.Seek(-128,CFile::end);	//从文件结尾处移动文件指针到128字节处
file.Read(&mp.mp3,128);
file.Close();
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,mp.mp3.title);//插入行
m_list.SetItemText(nRow,1,mp.mp3.arti);//设置数据
if(mp.mp3.heade && "TAG")
{
	CString mp3="MP3";
m_list.SetItemText(nRow,2,mp3);//设置数据
}
m_list.SetItemText(nRow,3,str2);
sprintf(mp.str,"%s",str2.GetBuffer(1));
mp.mp3.text[28]=0;
mp.mp3.year[4]=0;
mp.mp3.alb[30]=0;
CFile file1("列表.txt",CFile::modeReadWrite|CFile::modeNoTruncate|CFile::modeCreate|CFile::typeBinary);//CFile::typeText
file1.Seek(1,CFile::end);
file1.Write(&mp,sizeof(mp));
file1.Flush();
file1.Close();
}}}
/*
WIN32_FIND_DATA data;
BOOL boo;
HANDLE file=::FindFirstFile("F:\\\\音乐\\\\11\\\\*.mp3",&data);
if(file!=NULL)
{
 do{ 
CString str;
   str=data.cFileName;				//获取文件路径
CFile file2(str,CFile::modeRead);	//创建文件对象
file2.Seek(-128,CFile::end);	//从文件结尾处移动文件指针到128字节处
file2.Read(&mp.mp3,128);
file2.Close();
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,mp.mp3.title);//插入行
m_list.SetItemText(nRow,1,mp.mp3.arti);//设置数据
if(mp.mp3.heade && "TAG")
{
	CString mp3="MP3";
m_list.SetItemText(nRow,2,mp3);//设置数据
}
m_list.SetItemText(nRow,3,str);
mp.mp3.text[28]=0;
mp.mp3.year[4]=0;
mp.mp3.alb[30]=0;

CFile file1("歌曲列表.lw",CFile::modeWrite|CFile::modeNoTruncate|CFile::modeCreate);//CFile::typeText
file1.Seek(0,CFile::end);
file1.Write(&mp,sizeof(mp));
file1.Flush();
file1.Close();
boo=:: FindNextFile(file,&data);
}while(boo);
::FindClose(file);								//关闭文件搜索句柄
}*/



void CMyDlg::OnSousuomulu2() 
{
	// TODO: Add your control notification handler code here
	CFileFind findfile;	
	//CString str[4]={"C:\\","D:\\","E:\\","F:\\"};//创建文件搜索对象
	CString str2,str3;
							//搜索目录中的MP3文
findfile.FindFile("F:\\音乐\\11\\*.mp3",0);	
while(findfile.FindNextFile())
{						
str2=findfile.GetFilePath();										//获取文件路径
CFile file(str2,CFile::modeRead);									//创建文件对象
file.Seek(-128,CFile::end);										//从文件结尾移动指针
file.Read(&mp.mp3,128);										//读取文件
file.Close();													//关闭文件
int nRow=m_list.InsertItem(m_list.GetItemCount()+1,mp.mp3.title);		//在列表中插入行	
m_list.SetItemText(nRow,1,mp.mp3.arti);							//设置数据
if(mp.mp3.heade && "TAG")
{
	CString mp3="MP3";
m_list.SetItemText(nRow,2,mp3);									//设置数据
}
m_list.SetItemText(nRow,3,str2);
//mp.str=str2;
sprintf(mp.str,"%s",str2.GetBuffer(0));
//MessageBox(mp.str);
mp.mp3.text[28]=0;											//赋初值
mp.mp3.year[4]=0;
mp.mp3.alb[30]=0;
CFile file1("歌曲列表.lw",CFile::modeWrite|CFile::modeNoTruncate|CFile::modeCreate|CFile::typeBinary);													//关联列表文件
file1.Seek(0,CFile::end);										//定位文件指针到结尾
file1.Write(&mp,sizeof(mp));										//写入文件
file1.Flush();													//强制写入文件
file1.Close();													//关闭文件
}


}
