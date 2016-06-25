// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "SmsTest.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_SHOWTASK WM_USER+100
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_SEND, OnSend)
		ON_MESSAGE(WM_SHOWTASK,onShowTask)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	if (!m_wndDialogBar.Create(this, IDD_SEND_SM,
      CBRS_BOTTOM|CBRS_TOOLTIPS|CBRS_FLYBY, IDD_SEND_SM))
	{
		TRACE0("Failed to create dialog bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndDialogBar.EnableDocking(CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_wndDialogBar);
	NOTIFYICONDATA nid;
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
    nid.hWnd = this->m_hWnd;
    nid.uID = IDR_MAINFRAME;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP ;
    nid.uCallbackMessage = WM_SHOWTASK;//自定义的消息名称
    nid.hIcon=LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
    strcpy(nid.szTip, "计划任务提醒");//信息提示条为"计划任务提醒"
    Shell_NotifyIcon(NIM_ADD,&nid);//在托盘区添加图标
    this->ShowWindow(SW_HIDE);//隐藏主窗口

	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnSend() 
{
	CComboBox* pNumberWnd=(CComboBox*)m_wndDialogBar.GetDlgItem(IDC_NUMBER);
	CComboBox* pContentWnd=(CComboBox*)m_wndDialogBar.GetDlgItem(IDC_CONTENT);
	CString strSmsc;
	CString strNumber;
	CString strContent;
	strSmsc = theApp.m_strSmsc;
	pNumberWnd->GetWindowText(strNumber);
	pContentWnd->GetWindowText(strContent);
	// 检查号码
	if(strNumber.GetLength() < 11)
	{
		AfxMessageBox("请输入正确的号码！");
		pNumberWnd->SetFocus();
		pNumberWnd->SetEditSel(-1, 0);
		return;
	}

	// 检查短消息内容是否空，或者超长
	CString strUnicode;
	WCHAR wchar[1024];
	int nCount = ::MultiByteToWideChar(CP_ACP, 0, strContent, -1, wchar, 1024);
	if(nCount <= 1)
	{
		AfxMessageBox("请输入消息内容！");
		pContentWnd->SetFocus();
		pContentWnd->SetEditSel(-1, 0);
		return;
	}
	else if(nCount > 70)		// 我们决定全部用UCS2编码，最大70个字符(半角/全角)
	{
		AfxMessageBox("消息内容太长，无法发送！");
		pContentWnd->SetFocus();
		pContentWnd->SetEditSel(-1, 0);
		return;
	}
	if(AfxMessageBox("确定发送吗？", MB_YESNO) == IDYES)
	{
		SM_PARAM SmParam;

		memset(&SmParam, 0, sizeof(SM_PARAM));

		// 去掉号码前的"+"
		if(strSmsc[0] == '+')  strSmsc = strSmsc.Mid(1);
		if(strNumber[0] == '+')  strNumber = strNumber.Mid(1);

		// 在号码前加"86"
		if(strSmsc.Left(2) != "86")  strSmsc = "86" + strSmsc;
		if(strNumber.Left(2) != "86")  strNumber = "86" + strNumber;

		// 填充短消息结构
		strcpy(SmParam.SCA, strSmsc);
		strcpy(SmParam.TPA, strNumber);
		strcpy(SmParam.TP_UD, strContent);
		SmParam.TP_PID = 0;
		SmParam.TP_DCS = GSM_UCS2;

		// 发送短消息
		theApp.m_pSmsTraffic->PutSendMessage(&SmParam);

		// 列表中加入新串
		if(pNumberWnd->FindStringExact(-1, strNumber)<0)  pNumberWnd->InsertString(0, strNumber);
		if(pContentWnd->FindStringExact(-1, strContent)<0)  pContentWnd->InsertString(0, strContent);
	}
	
	pContentWnd->SetFocus();
	pContentWnd->SetEditSel(-1, 0);	
}
LRESULT CMainFrame::onShowTask(WPARAM wParam,LPARAM lParam)

{

    //wParam接收的是图标的ID，而lParam接收的是鼠标的行为

    {
        if(wParam==IDR_MAINFRAME)
            return 1;
        switch(lParam)
        {

        case WM_RBUTTONUP://右键起来时弹出快捷菜单，这里只有一个"关闭"
            {
                LPPOINT lpoint = new tagPOINT;
                ::GetCursorPos(lpoint);//得到鼠标位置
                CMenu menu;
                menu.CreatePopupMenu();//声明一个弹出式菜单
                //增加菜单项"关闭"，点击则发送消息WM_DESTROY给主窗口（已
                //隐藏），将程序结束。
                menu.AppendMenu(MF_STRING, WM_DESTROY,"关闭");
                //确定弹出式菜单的位置
                menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x, lpoint->y, this);
                //资源回收
                HMENU hmenu = menu.Detach();
                menu.DestroyMenu();
                delete lpoint;
            }
            break;
        case WM_LBUTTONDBLCLK://双击左键的处理
            {
                this->ShowWindow(SW_SHOW);//
            }
            break;
        }
        return 0;
    }
}
