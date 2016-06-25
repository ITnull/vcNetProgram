; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRecv
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "邮件收发器.h"

ClassCount=5
Class1=CMyApp
Class2=CMyDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_MY_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG1
Class4=CSet
Resource4=IDD_ABOUTBOX
Class5=CRecv
Resource5=IDD_DIALOG2

[CLS:CMyApp]
Type=0
HeaderFile=邮件收发器.h
ImplementationFile=邮件收发器.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=邮件收发器Dlg.h
ImplementationFile=邮件收发器Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMyDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=邮件收发器Dlg.h
ImplementationFile=邮件收发器Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SENDER,edit,1350631552
Control5=IDC_RECVER,edit,1350631552
Control6=IDC_SUBJECT,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_MAILTEXT,edit,1350565956
Control9=IDC_PEIZHI,button,1342242816
Control10=IDC_SENDMAIL,button,1342242816
Control11=IDC_RECVMAIL,button,1342242816
Control12=IDC_HELP,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CSet
ControlCount=6
Control1=IDC_SEVERADD,static,1342308352
Control2=IDC_PORT,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_BUTTON1,button,1342242816
Control6=IDC_BUTTON2,button,1342242816

[CLS:CSet]
Type=0
HeaderFile=Set1.h
ImplementationFile=Set1.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON2

[DLG:IDD_DIALOG2]
Type=1
Class=CRecv
ControlCount=10
Control1=IDC_STATIC,static,1342308864
Control2=IDC_NAME,static,1342308864
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_SHANG,button,1342242816
Control5=IDC_NEXT,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_ZHANGHU,edit,1350631552
Control9=IDC_PASS,edit,1350631584
Control10=IDC_RECV,button,1342242816

[CLS:CRecv]
Type=0
HeaderFile=Recv1.h
ImplementationFile=Recv1.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PASS
VirtualFilter=dWC

