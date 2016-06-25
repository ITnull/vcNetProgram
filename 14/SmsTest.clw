; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSmsTestView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "smstest.h"
LastPage=0

ClassCount=6
Class1=CMainFrame
Class2=CSettingsDlg
Class3=CSmsTestApp
Class4=CAboutDlg
Class5=CSmsTestDoc
Class6=CSmsTestView

ResourceCount=4
Resource1=IDD_SEND_SM
Resource2=IDD_SETTINGS
Resource3=IDR_MAINFRAME
Resource4=IDD_DIALOG1

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame

[CLS:CSettingsDlg]
Type=0
BaseClass=CDialog
HeaderFile=SettingsDlg.h
ImplementationFile=SettingsDlg.cpp
LastObject=CSettingsDlg
Filter=D
VirtualFilter=dWC

[CLS:CSmsTestApp]
Type=0
BaseClass=CWinApp
HeaderFile=SmsTest.h
ImplementationFile=SmsTest.cpp
Filter=N
LastObject=ID_SETTING
VirtualFilter=AC

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=SmsTest.cpp
ImplementationFile=SmsTest.cpp

[CLS:CSmsTestDoc]
Type=0
BaseClass=CDocument
HeaderFile=SmsTestDoc.h
ImplementationFile=SmsTestDoc.cpp
Filter=N
LastObject=CSmsTestDoc

[CLS:CSmsTestView]
Type=0
BaseClass=CListView
HeaderFile=SmsTestView.h
ImplementationFile=SmsTestView.cpp
Filter=C
LastObject=CSmsTestView
VirtualFilter=VWC

[DLG:IDD_SETTINGS]
Type=1
Class=CSettingsDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_COMM_LIST,combobox,1344339971
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SMSC,edit,1350639744
Control5=IDOK,button,1342373889
Control6=IDCANCEL,button,1342373888
Control7=IDC_STATIC,static,1342177283
Control8=IDC_STATIC,static,1342308352
Control9=IDC_RATE_LIST,combobox,1344339971

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

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_SETTING
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=?
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

[DLG:IDD_SEND_SM]
Type=1
Class=?
ControlCount=5
Control1=IDC_SEND,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_NUMBER,combobox,1344340290
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CONTENT,combobox,1344340290

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=2
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_EDIT1,edit,1350631552

