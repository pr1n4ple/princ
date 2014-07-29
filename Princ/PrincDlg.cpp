
// PrincDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Princ.h"
#include "PrincDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPrincDlg �Ի���




CPrincDlg::CPrincDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPrincDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrincDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_cTabCtrl);
}

BEGIN_MESSAGE_MAP(CPrincDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CPrincDlg::OnTcnSelchangeTab1)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CPrincDlg ��Ϣ��������

BOOL CPrincDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ����Ӷ���ĳ�ʼ������
	// creat tab ctrl

	CRect tabRect;
	m_cTabCtrl.InsertItem(0,_T("Computer"));
	m_cTabCtrl.InsertItem(1,_T("Cmd"));
	m_cTabCtrl.InsertItem(2,_T("File"));
	m_ListDlg.Create(IDD_LISTDLG,&m_cTabCtrl);
	m_ShellDlg.Create(IDD_SHELLDLG,&m_cTabCtrl);
	m_FileDlg.Create(IDD_FILEDLG,&m_cTabCtrl);

	m_cTabCtrl.GetClientRect(&tabRect);
	tabRect.left += 2;                  
	tabRect.right -= 2;   
	tabRect.top += 22;   
	tabRect.bottom -= 2; 
	m_ListDlg.SetWindowPos(NULL, tabRect.left, tabRect.top,
		tabRect.Width(), tabRect.Height(),SWP_SHOWWINDOW);  
	m_ShellDlg.SetWindowPos(NULL,tabRect.left, tabRect.top,
		tabRect.Width(), tabRect.Height(),SWP_HIDEWINDOW);
	m_FileDlg.SetWindowPos(NULL,tabRect.left, tabRect.top,
		tabRect.Width(), tabRect.Height(),SWP_HIDEWINDOW);
// 	CRect mainDlgRect;
// 	GetClientRect(&mainDlgRect);
// 	m_cTabCtrl.AdjustRect(FALSE, &mainDlgRect);
// 	m_cTabCtrl.MoveWindow(&mainDlgRect, TRUE);   
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPrincDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPrincDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPrincDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPrincDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	*pResult = 0; 
	switch(m_cTabCtrl.GetCurSel())
	{
	case 0:
		m_ListDlg.ShowWindow(TRUE);
		m_ShellDlg.ShowWindow(FALSE);
		m_FileDlg.ShowWindow(FALSE);
		break;
	case 1:
		m_ListDlg.ShowWindow(FALSE);
		m_ShellDlg.ShowWindow(TRUE);
		m_FileDlg.ShowWindow(FALSE);
		break;
	case 2:
		m_ListDlg.ShowWindow(FALSE);
		m_ShellDlg.ShowWindow(FALSE);
		m_FileDlg.ShowWindow(TRUE);
		break;
	default:
		break;
	}
}


void CPrincDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴�������Ϣ�����������
	if(m_cTabCtrl.m_hWnd == NULL)
		return;      // Return if window is not created yet.
	CRect mainDlgRect;
 	GetClientRect(&mainDlgRect);
 	m_cTabCtrl.MoveWindow(&mainDlgRect);   
	CRect tabRect;
	m_cTabCtrl.GetClientRect(&tabRect);
 	tabRect.left += 2;                  
 	tabRect.right -= 2;   
 	tabRect.top += 22;   
 	tabRect.bottom -= 2; 
	m_ListDlg.MoveWindow(tabRect);
	m_ShellDlg.MoveWindow(tabRect);
	m_FileDlg.MoveWindow(tabRect);
}