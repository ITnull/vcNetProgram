// Set1.cpp : implementation file
//

#include "stdafx.h"
#include "�ʼ��շ���.h"
#include "Set1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSet dialog


CSet::CSet(CWnd* pParent /*=NULL*/)
	: CDialog(CSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSet)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSet, CDialog)
	//{{AFX_MSG_MAP(CSet)
	ON_BN_CLICKED(IDC_BUTTON2, OnReset)
	ON_BN_CLICKED(IDC_BUTTON1, OnOK)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSet message handlers

void CSet::OnOK() 
{
	// TODO: Add your control notification handler code here
	CString str;										//��ʱ����
	GetDlgItem(IDC_EDIT1)->GetWindowText(m_severadd);		//��÷�������ַ
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);				//��ȡ�˿ں���
    m_port=atoi(str.GetBuffer(1));							//ת���˿�Ϊ������
    ::SendMessage(this->m_hWnd,WM_CLOSE,0,0);
}

void CSet::OnReset() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT1)->SetWindowText("");				//���������༭��Ϊ��
	GetDlgItem(IDC_EDIT2)->SetWindowText("");				

}

BOOL CSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_severadd="mail.163.com";							//��ʼ������
    GetDlgItem(IDC_EDIT1)->SetWindowText(m_severadd);		//���÷�������ַ	
GetDlgItem(IDC_EDIT2)->SetWindowText("25");			//���ö˿ں�

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
