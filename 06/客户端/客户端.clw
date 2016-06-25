; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Cd1
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "客户端.h"

ClassCount=4
Class1=CMyApp
Class2=CMyDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MY_DIALOG
Class4=Cd1
Resource4=IDD_DIALOG1

[CLS:CMyApp]
Type=0
HeaderFile=客户端.h
ImplementationFile=客户端.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=客户端Dlg.h
ImplementationFile=客户端Dlg.cpp
Filter=D
LastObject=CMyDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=客户端Dlg.h
ImplementationFile=客户端Dlg.cpp
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
ControlCount=5
Control1=IDC_EDIT1,edit,1486881092
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_BUTTON3,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=Cd1
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_EDIT2,edit,1350633600
Control4=IDC_STATIC,static,1342308865
Control5=IDC_STATIC,static,1342308865

[CLS:Cd1]
Type=0
HeaderFile=d1.h
ImplementationFile=d1.cpp
BaseClass=CDialog
Filter=D
LastObject=Cd1
VirtualFilter=dWC

