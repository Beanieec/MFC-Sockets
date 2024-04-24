#include "pch.h"
#include "framework.h"
#include "TsarinSocketServ.h"
#include "TsarinSocketServDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Диалоговое окно CTsarinSocketServDlg
CTsarinSocketServDlg::CTsarinSocketServDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CTsarinSocketServDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTsarinSocketServDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTsarinSocketServDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONSERVER, &CTsarinSocketServDlg::OnBnClickedButtonserver)
	ON_EN_CHANGE(IDC_EDITPORT, &CTsarinSocketServDlg::OnEnChangeEditport)
	ON_EN_CHANGE(ID_EDITSERVER, &CTsarinSocketServDlg::OnEnChangeEditserver)
END_MESSAGE_MAP()

// Обработчики сообщений CMFCSOCKETSDlg
BOOL CTsarinSocketServDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	SetIcon(m_hIcon, TRUE);	
	SetIcon(m_hIcon, FALSE);

	SetDlgItemTextW(IDC_EDITPORT, ServerPort);
	return TRUE;
}

void CTsarinSocketServDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CTsarinSocketServDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTsarinSocketServDlg::OnBnClickedButtonserver()
{
	AfxSocketInit();
	GetDlgItemText(IDC_EDITPORT, ServerPort);
	UINT CServerPort = _tstoi(ServerPort);
	if (ServerSocket.Create(CServerPort) > 0)
	{
		if (ServerSocket.Listen() > 0)
		{
			GetDlgItem(IDC_BUTTONSERVER)->SetWindowTextW(L"Сервер работает");
			GetDlgItem(IDC_BUTTONSERVER)->EnableWindow(FALSE);
		}
	}
}

void CTsarinSocketServDlg::OnEnChangeEditport()
{
	ServerSocket.Close();
	GetDlgItem(IDC_BUTTONSERVER)->SetWindowTextW(L"Создать сервер");
	GetDlgItem(IDC_BUTTONSERVER)->EnableWindow(TRUE);
}


void CTsarinSocketServDlg::OnEnChangeEditserver()
{
	CString Disconnect;
	GetDlgItemText(ID_EDITSERVER, Disconnect);
	if (Disconnect == L"Соединение разорвано, попробуйте снова...")
	{
		ServerSocket.Close();
		GetDlgItem(IDC_BUTTONSERVER)->SetWindowTextW(L"Создать сервер");
		GetDlgItem(IDC_BUTTONSERVER)->EnableWindow(TRUE);
	}
}
