#include "pch.h"
#include "ListenSocket.h"

ListenSocket::~ListenSocket()
{
	DSock.Close();
	Sleep(0);
}

void ListenSocket::OnAccept(int nErrorCode)
{
	CSocket socket;
	Accept(socket);

	SOCKET DSocket = socket.Detach();
	DSock.Attach(DSocket);

	CSocket::OnAccept(nErrorCode);
}

void ListenSocket::OnClose(int nErrorCode)
{
	SetDlgItemText(AfxGetApp()->m_pMainWnd->m_hWnd, 1001, L"Соединение разорвано, попробуйте снова...");
	DSock.Close();
	
	CSocket::OnClose(nErrorCode);
}