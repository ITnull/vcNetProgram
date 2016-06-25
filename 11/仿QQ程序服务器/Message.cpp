// Message.cpp : implementation file
//

#include "stdafx.h"
#include "仿QQ程序服务器.h"
#include "Message.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMessage dialog


CMessage::CMessage(CWnd* pParent /*=NULL*/)
	: CDialog(CMessage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMessage)
	m_num = 0;
	m_text = _T("");
	m_text2 = _T("");
	//}}AFX_DATA_INIT
}


void CMessage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMessage)
	DDX_Text(pDX, IDC_IP, m_ip);
	DDX_Text(pDX, IDC_NUM, m_num);
	DDX_Text(pDX, IDC_TEXT, m_text);
	DDX_Text(pDX, IDC_TEXT2, m_text2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMessage, CDialog)
	//{{AFX_MSG_MAP(CMessage)
	ON_BN_CLICKED(IDC_RELAY, OnRelay)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMessage message handlers

BOOL CMessage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_NUM)->EnableWindow(false);
	GetDlgItem(IDC_IP)->EnableWindow(false);
	GetDlgItem(IDC_TEXT)->EnableWindow(false);
	GetDlgItem(IDC_TEXT2)->ShowWindow(false);
	GetDlgItem(IDC_SEND)->ShowWindow(false);
		GetDlgItem(IDC_NUM)->SetWindowText("393817181");
	GetDlgItem(IDC_IP)->SetWindowText("218.6.132.5");
//	GetDlgItem(IDC_TEXT)->SetWindowText("你还在吗？");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMessage::OnRelay() 
{

	GetDlgItem(IDC_TEXT2)->ShowWindow(true);
	GetDlgItem(IDC_SEND)->ShowWindow(true);
}

void CMessage::OnSend() 
{

}
