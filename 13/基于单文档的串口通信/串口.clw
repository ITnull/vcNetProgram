; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "串口.h"
LastPage=0

ClassCount=5
Class1=CMyApp
Class2=CMyDoc
Class3=CMyView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_MY_FORM

[CLS:CMyApp]
Type=0
HeaderFile=串口.h
ImplementationFile=串口.cpp
Filter=N

[CLS:CMyDoc]
Type=0
HeaderFile=串口Doc.h
ImplementationFile=串口Doc.cpp
Filter=N

[CLS:CMyView]
Type=0
HeaderFile=串口View.h
ImplementationFile=串口View.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CMyView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=串口.cpp
ImplementationFile=串口.cpp
Filter=D

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
CommandCount=13

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_MY_FORM]
Type=1
Class=CMyView
ControlCount=17
Control1=IDC_STATIC,static,1342308864
Control2=IDC_COMNUM,combobox,1344340226
Control3=IDC_STATIC,static,1342308864
Control4=IDC_COMBO,combobox,1344340226
Control5=IDC_STATIC,static,1342308864
Control6=IDC_COMJIAOYAN,combobox,1344340226
Control7=IDC_STATIC,static,1342308864
Control8=IDC_COMDATA,combobox,1344340226
Control9=IDC_COMSTOP,combobox,1344340226
Control10=IDC_OPENCOM,button,1342242816
Control11=IDC_MSG,edit,1484849280
Control12=IDC_RECVDATA,button,1342242816
Control13=IDC_SENDDATA,button,1342242816
Control14=IDC_SAVEDATA,button,1342242816
Control15=IDC_EDIT2,edit,1350631552
Control16=IDC_MSCOMM,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control17=IDC_STATIC,static,1342308864

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

