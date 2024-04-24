#include "pch.h"
#include "framework.h"
#include "TsarinSocketClient.h"
#include "TsarinSocketClientDlg.h"
#include "afxdialogex.h"

#define BUFFERSIZE 128
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CTsarinSocketClientDlg
CTsarinSocketClientDlg::CTsarinSocketClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CTsarinSocketClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTsarinSocketClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTsarinSocketClientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONSEND, &CTsarinSocketClientDlg::OnBnClickedButtonsend)
	ON_BN_CLICKED(IDC_BUTTONCON, &CTsarinSocketClientDlg::OnBnClickedButtoncon)
	ON_EN_CHANGE(IDC_EDITIP, &CTsarinSocketClientDlg::OnEnChangeEditip)
	ON_EN_CHANGE(IDC_EDITPORT, &CTsarinSocketClientDlg::OnEnChangeEditport)
	ON_EN_CHANGE(IDC_EDITDIS, &CTsarinSocketClientDlg::OnEnChangeEditdis)
END_MESSAGE_MAP()

// Обработчики сообщений CMFSSOCKETSCLIENTDlg
BOOL CTsarinSocketClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);	
	SetIcon(m_hIcon, FALSE);

	SetDlgItemTextW(IDC_EDITIP, ClientIP);
	SetDlgItemTextW(IDC_EDITPORT, ClientPORT);
	SetDlgItemTextW(IDC_EDITCLIENT, L"Подключитесь!");
	return TRUE;
}

void CTsarinSocketClientDlg::OnPaint()
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

HCURSOR CTsarinSocketClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTsarinSocketClientDlg::OnBnClickedButtonsend()
{
	
	CString str;
	GetDlgItemText(IDC_EDITCLIENT, str);
		if (str)
		{
			server.Send(str, BUFFERSIZE);
		}
}

void CTsarinSocketClientDlg::OnBnClickedButtoncon()
{
	SetDlgItemTextW(IDC_EDITCLIENT, L"Подключение...");
	AfxSocketInit();
	GetDlgItemText(IDC_EDITIP, ClientIP);
	GetDlgItemText(IDC_EDITPORT, ClientPORT);
	UINT PORT = _tstoi(ClientPORT);
	server.Create();

	if (server.Connect(ClientIP, PORT) != FALSE)
	{
		GetDlgItem(IDC_BUTTONCON)->SetWindowTextW(L"Подключено");
		GetDlgItem(IDC_BUTTONCON)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTONSEND)->EnableWindow(TRUE);
		SetDlgItemTextW(IDC_EDITCLIENT, L"Подключено. Введите текст для сервера...");
	}
	else
	{
		server.Close();
		GetDlgItem(IDC_BUTTONSEND)->EnableWindow(FALSE);
		SetDlgItemTextW(IDC_EDITCLIENT, L"Нет доступного подключения, повторите попытку...");
	}
}

void CTsarinSocketClientDlg::OnEnChangeEditip()
{
	AfxSocketInit();
	server.Close();
	GetDlgItem(IDC_BUTTONCON)->SetWindowTextW(L"Подключиться");
	GetDlgItem(IDC_BUTTONCON)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTONSEND)->EnableWindow(FALSE);
}

void CTsarinSocketClientDlg::OnEnChangeEditport()
{
	AfxSocketInit();
	server.Close();
	GetDlgItem(IDC_BUTTONCON)->SetWindowTextW(L"Подключиться");
	GetDlgItem(IDC_BUTTONCON)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTONSEND)->EnableWindow(FALSE);
}

void CTsarinSocketClientDlg::OnEnChangeEditdis()
{
	AfxSocketInit();
	server.Close();
	GetDlgItem(IDC_BUTTONCON)->SetWindowTextW(L"Подключиться");
	GetDlgItem(IDC_BUTTONCON)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTONSEND)->EnableWindow(FALSE);
}