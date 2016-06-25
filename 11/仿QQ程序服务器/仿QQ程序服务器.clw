; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMessage
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "仿QQ程序服务器.h"

ClassCount=3
Class1=CQQApp
Class2=CQQDlg

ResourceCount=3
Resource2=IDD_QQ_DIALOG
Resource1=IDR_MAINFRAME
Class3=CMessage
Resource3=IDD_DIALOG1

[CLS:CQQApp]
Type=0
HeaderFile=仿QQ程序服务器.h
ImplementationFile=仿QQ程序服务器.cpp
Filter=N
LastObject=CQQApp

[CLS:CQQDlg]
Type=0
HeaderFile=仿QQ程序服务器Dlg.h
ImplementationFile=仿QQ程序服务器Dlg.cpp
Filter=D
LastObject=CQQDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_QQ_DIALOG]
Type=1
Class=CQQDlg
ControlCount=2
Control1=IDC_STATIC,static,1342308865
Control2=IDC_LIST1,SysListView32,1350631681

[DLG:IDD_DIALOG1]
Type=1
Class=CMessage
ControlCount=8
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308865
Control3=IDC_NUM,edit,1350631552
Control4=IDC_IP,edit,1350631552
Control5=IDC_TEXT2,edit,1350631552
Control6=IDC_RELAY,button,1342242816
Control7=IDC_SEND,button,1342242816
Control8=IDC_TEXT,edit,1350631552

[CLS:CMessage]
Type=0
HeaderFile=Message.h
ImplementationFile=Message.cpp
BaseClass=CDialog
Filter=D
LastObject=CMessage
VirtualFilter=dWC

