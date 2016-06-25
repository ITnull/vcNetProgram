; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CQQDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "·ÂQQ³ÌÐò.h"

ClassCount=5
Class1=CQQApp
Class2=CQQDlg

ResourceCount=5
Resource2=IDD_DIALOG2
Resource1=IDR_MAINFRAME
Class3=CSend
Resource3=IDD_DIALOG1
Class4=CSet
Resource4=IDD_QQ_DIALOG
Class5=CNet
Resource5=IDD_DIALOG3

[CLS:CQQApp]
Type=0
HeaderFile=·ÂQQ³ÌÐò.h
ImplementationFile=·ÂQQ³ÌÐò.cpp
Filter=N

[CLS:CQQDlg]
Type=0
HeaderFile=·ÂQQ³ÌÐòDlg.h
ImplementationFile=·ÂQQ³ÌÐòDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EMAIL4



[DLG:IDD_QQ_DIALOG]
Type=1
Class=CQQDlg
ControlCount=4
Control1=IDC_LIST1,SysListView32,1350631441
Control2=IDC_EMAIL,button,1342242816
Control3=IDC_NET,button,1342242816
Control4=IDC_EMAIL4,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CSend
ControlCount=4
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_SEND,button,1342242816
Control3=IDC_EDIT2,edit,1352730820
Control4=IDC_NAME,static,1342308352

[CLS:CSend]
Type=0
HeaderFile=Send.h
ImplementationFile=Send.cpp
BaseClass=CDialog
Filter=D
LastObject=CSend
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=CSet
ControlCount=4
Control1=IDC_STATIC,static,1342308864
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816

[CLS:CSet]
Type=0
HeaderFile=Set.h
ImplementationFile=Set.cpp
BaseClass=CDialog
Filter=D
LastObject=CSet
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=CNet
ControlCount=4
Control1=IDC_STATIC,static,1342308864
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816

[CLS:CNet]
Type=0
HeaderFile=Net.h
ImplementationFile=Net.cpp
BaseClass=CDialog
Filter=D
LastObject=CNet
VirtualFilter=dWC

