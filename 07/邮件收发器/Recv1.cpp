// Recv1.cpp : implementation file
//

#include "stdafx.h"
#include "�ʼ��շ���.h"
#include "Recv1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecv dialog


CRecv::CRecv(CWnd* pParent /*=NULL*/)
	: CDialog(CRecv::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecv)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRecv::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecv)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRecv, CDialog)
	//{{AFX_MSG_MAP(CRecv)
	ON_BN_CLICKED(IDC_RECV, OnRecv)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_EN_CHANGE(IDC_PASS, OnChangePass)
	ON_BN_CLICKED(IDC_SHANG, OnShang)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecv message handlers

BOOL CRecv::OnInitDialog() 
{
	CDialog::OnInitDialog();
	

	i=0;
	stat=::CreateStatusWindow(WS_CHILD|WS_VISIBLE,"�����ʼ�",this->m_hWnd,IDC_123);
	GetDlgItem(IDC_EDIT1)->SetWindowText("����ʼ����Ѿ��յ���");
	/*GetDlgItem(IDC_NAME)->SetWindowText("lymlrl@163.com");
		GetDlgItem(IDC_RECV)->EnableWindow(false);
	GetDlgItem(IDC_EDIT1)->EnableWindow(false);
	GetDlgItem(IDC_SHANG)->EnableWindow(true);
	GetDlgItem(IDC_NEXT)->EnableWindow(true);*/
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
	
}

void CRecv::OnRecv() 
{
	MessageBox("�Բ��𣬲������ӵ�ָ���ķ������������������¼���ߵ����˲��ͣ�");
}


void CRecv::OnNext() 
{
	// TODO: Add your control notification handler code here
	MessageBox("�Բ����ʼ����մ���");
}

void CRecv::OnChangePass() 
{
	if(i>3)
	{
		CString str;
	
		this->GetWindowText(str);
	
		if(str.Find("&"))
	
		{
			GetDlgItem(IDC_RECV)->EnableWindow(true);
		GetDlgItem(IDC_NEXT)->EnableWindow(true);
		}
	}
	else
	{
		i+=1;
	}
	
}

void CRecv::SendCmd()
{

}

void CRecv::OnShang() 
{
	// TODO: Add your control notification handler code here
	MessageBox("��ǰ�ʼ��Ѿ��ǵ�һ���ʼ�");
}
