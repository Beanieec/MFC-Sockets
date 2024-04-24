#include "pch.h"
#include "DutySocket.h"

#define BUFFERSIZE 128

DutySocket::DutySocket()
{
	Buffer = NULL;
	Buffer = new TCHAR[BUFFERSIZE];
	MAIL = NULL;
	Port = NULL;
}

DutySocket::~DutySocket()
{
	if (Buffer != NULL)
	{
		delete Buffer;
		Buffer = NULL;
	}
	Close();
}

void DutySocket::OnClose(int nErrorCode)
{
	SetDlgItemText(AfxGetApp()->m_pMainWnd->m_hWnd, 1001, L"Соединение разорвано, попробуйте снова...");
	Close();
	
	CSocket::OnClose(nErrorCode);
}

void DutySocket::OnReceive(int nErrorCode)
{
	MAIL = Receive(Buffer, BUFFERSIZE);

	if (MAIL != 0)
	{
		Buffer[MAIL] = '\0';
		GetPeerName(IP, Port);
		strMAIL.Format(L"%s:%d: %s", IP, Port, Buffer);
		SetDlgItemTextW(AfxGetApp()->m_pMainWnd->m_hWnd, 1001, strMAIL);
	}
	CSocket::OnReceive(nErrorCode);
}