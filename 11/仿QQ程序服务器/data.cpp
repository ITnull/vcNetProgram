#include "Data.h"
#include <iostream.h>
CData::CData()									//构造函数
{

   }

void CData::bind()									//服务器绑定套接字函数
{
  WSADATA data;								//定义结构体变量
   CString name;									//定义主机名字符串
	DWORD ss=MAKEWORD(2,0);					//指定套接字版本
   ::WSAStartup(ss,&data);							//初始化套接字库
   s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);	//创建套接字
   sockaddr_in addr;								//定义地址结构变量
::gethostname((char*)&name,(int)sizeof(name));			//获得主机名字
	hostent *p=::gethostbyname((char*)&name);			//从主机名获取主机地址
	 in_addr *a=(in_addr*)*p->h_addr_list;				//获得本机IP地址
	 CString str14=::inet_ntoa(a[0]);					//转换字符串IP地址
   addr.sin_family=AF_INET;						//填充地址结构
	addr.sin_port=htons(80);							//指定监听端口为80
	addr.sin_addr.S_un.S_addr=inet_addr(str14);			//指定主机IP地址
	::bind(s,(sockaddr*)&addr,sizeof(addr));				//将本地信息绑定到套接字
	::listen(s,5);									//监听
WSAAsyncSelect(s,this->m_hWnd,WM_SOCK,FD_ACCEPT|FD_READ);
												//将套接字设置为异步模式
}

void CData::sevsend(SOCKET s,char* buff,int len,int flags)	//自定义服务器发送函数
{
            send(s,buff,len,flags);					//调用API发送函数
}

void CData::sevrecv(SOCKET s,char* buff,int len,int flags)	//自定义服务器接收函数
{
 recv(s,buff,len,flags);								//调用API接收函数
  }

void CData::connect()
{
sockaddr_in addr;						//定义地址结构变量
 addr.sin_family=AF_INET;							//填充地址结构
addr.sin_port=htons(80);					//指定监听端口为80
addr.sin_addr.S_un.S_addr=inet_addr(str14);	//指定主机IP地址
 if(connect(s,( sockaddr*)addr,sizeof(addr),NULL)==-1)		//连接服务器
{
  MessageBox("连接服务器失败！");					//提示用户连接服务器失败
  }
}

void CData::send(SOCKET s,char* buff,int len,int flags)		//自定义客户端发送函数
{
  GetDlgItem(IDC_EDIT1)->GetWindowText(str);			//获取用户输入的数据
send(s,str.GetBuffer(1),sizeof(str),NULL);				//发送信息
GetDlgItem(IDC_EDIT2)->GetWindowText(str1);			//获取信息显示框中的内容
str1+="\r\n";										//添加回车换行符
str1+=str;										//连接字符串	
GetDlgItem(IDC_EDIT2)->SetWindowText(str1);			//设置信息显示框的内容
}

void CData::recv(SOCKET s,char* buff,int len,int flags)		//自定义客户端接收函数
{
  char buff[1024];									//定义字符缓冲区
 memset(&buff,0,1024);							//初始化字符缓冲区
 recv(s,&buff,1024,NULL);							//接收数据
}

void CData::~CData()								//析构函数
{
  }
