// ����View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "����.h"

#include "����Doc.h"
#include "����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CFormView)

BEGIN_MESSAGE_MAP(CMyView, CFormView)
	//{{AFX_MSG_MAP(CMyView)
	ON_BN_CLICKED(IDC_OPENCOM, OnOpencom)
	ON_BN_CLICKED(IDC_SENDDATA, OnSenddata)
	ON_BN_CLICKED(IDC_RECVDATA, OnRecvdata)
	ON_BN_CLICKED(IDC_SAVEDATA, OnSavedata)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView construction/destruction

CMyView::CMyView()
	: CFormView(CMyView::IDD)
{
	//{{AFX_DATA_INIT(CMyView)
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMyView::~CMyView()
{
}

void CMyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyView)
	DDX_Control(pDX, IDC_COMSTOP, m_comstop);
	DDX_Control(pDX, IDC_COMNUM, m_comnum);
	DDX_Control(pDX, IDC_COMJIAOYAN, m_comjiaoyan);
	DDX_Control(pDX, IDC_COMDATA, m_comdata);
	DDX_Control(pDX, IDC_COMBO, m_botelv);
	DDX_Control(pDX, IDC_MSCOMM, mm);
	//}}AFX_DATA_MAP
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMyView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_comnum.SetWindowText("COM1");
	m_comnum.AddString("COM1");
	m_comnum.AddString("COM2");
	m_comnum.AddString("COM3");
	m_comnum.AddString("COM4");
	m_botelv.SetWindowText("9600");
	m_botelv.AddString("1200");
	m_botelv.AddString("2400");
	m_botelv.AddString("9600");
	m_comjiaoyan.SetWindowText("��У��");
	m_comjiaoyan.AddString("��У��");
	m_comjiaoyan.AddString("żУ��");
	m_comjiaoyan.AddString("��У��");
	m_comdata.SetWindowText("8");
	m_comdata.AddString("4");
	m_comdata.AddString("8");
	m_comstop.SetWindowText("�ı�");
	m_comstop.AddString("�ı�");
	m_comstop.AddString("������");
}

/////////////////////////////////////////////////////////////////////////////
// CMyView printing

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMyView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

void CMyView::InitComm()
{
	mm.SetCommPort(n);
	mm.SetInputMode(1);//���ý������ݵ�����Ϊ�ı�����
	mm.SetSettings(str);//���ô��ڵ���ز���
	mm.SetRThreshold(1);//�����Ƿ���������¼�
	mm.SetInputLen(0);//�Ƿ�ȫ����ȡ���ڻ������е�����
		if(mm.GetPortOpen())			//�жϴ����Ƿ��Ѿ���
	{
		MessageBox("�ô����Ѿ���,������ѡ�񴮿ں�");		//������ڹر�״̬���򽫶˿ڴ�
		mm.SetPortOpen(false);
		}
	else								//������ڴ��ڴ�״̬������ʾ�û������Ѿ���
	{
		mm.SetPortOpen(true);	
		}
}

void CMyView::OnOpencom() 
{

	m_comnum.GetWindowText(str);
	if(str.Find("COM1",0)!=-1)
	{
		n=1;
	}
	else
	{
		if(str.Find("COM2",0)!=-1)
		{
			n=2;
		}
		else
		{
			if(str.Find("COM3",0)!=-1)
			{
				n=3;
			}
			else
			{
				n=4;
			}
		}
	}
	str.Empty();
	m_botelv.GetWindowText(str1);
	str+=str1;
	str+=",";
	m_comjiaoyan.GetWindowText(str1);
	if(str1.Find("��У��",0)!=-1)
		{
			str+="o";
		}
		else
		{
			if(str1.Find("żУ��",0)!=-1)
			{
				str+="e";
			}
			else
			{
				str+="n";
			}
		}
	
	str+=",";
	m_comdata.GetWindowText(str1);
	str+=str1;
	str+=",";
	str+="1";
	this->InitComm();
}

void CMyView::OnSenddata() 
{
	CString str,str1;
	char*  a;
		GetDlgItem(IDC_EDIT2)->GetWindowText(str);
		if(str.GetLength()!=0)
		{
			for(int i=0;i<str.GetLength();i++)
			{
				a=str.GetBuffer(i);
				mm.SetOutput(COleVariant(a));	//���ô������ݷ��ͺ�����������
				memset(a,0,1);
			}

		}
		else
		{
			MessageBox("�������ݲ���Ϊ�գ�");
		}
		str1.Format("�û��������ݳɹ�!\r\n");
		GetDlgItem(IDC_MSG)->SetWindowText(str1);
}

BEGIN_EVENTSINK_MAP(CMyView, CFormView)
    //{{AFX_EVENTSINK_MAP(CMyView)
	ON_EVENT(CMyView, IDC_MSCOMM, 1 /* OnComm */, OnComm, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CMyView::OnComm() 
{
	// TODO: Add your control notification handler code here
	
}

void CMyView::OnRecvdata() 
{
	CString str,str1;									//�����ַ���
	GetDlgItem(IDC_MSG)->GetWindowText(str);			//��ȡ��Ϣ���տ���ԭ�е�����
	str1.Format("���յ��������ǣ�%s","��ð���");			//��ʽ�����յ�������
	str+="\r\n";									//��ӻ��з�
	str+=str1;										//��������
	str+="\r\n";
	GetDlgItem(IDC_MSG)->SetWindowText(str1);			//������Ϣ���տ��е�����

}

void CMyView::OnSavedata() 
{
CFile file("���ݼ�¼.txt",CFile::modeRead|CFile::modeWrite|CFile::modeCreate|CFile::modeNoTruncate|CFile::typeBinary);
	CString str;									//�����ַ���
	DWORD data;
	char szdata[100];
	DWORD leth=file.GetLength();
	GetDlgItem(IDC_MSG)->GetWindowText(str);			//��ȡ��Ϣ���տ���ԭ�е�����
	strcpy(szdata,str.GetBuffer(100));
		file.SeekToEnd();
	file.Write("\r\n",2);
	file.Write(szdata,str.GetLength());
	file.Flush();
	if(file.GetLength()!=leth)
	{
		MessageBox("���ݱ���ɹ���");
	}
	else
	{
		MessageBox("���ݱ���ʧ�ܣ�");
	}
	file.Close();
}

void CMyView::OnClose() 
{

	CFormView::OnClose();
}
