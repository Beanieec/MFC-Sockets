#include "pch.h"
#include "Socket.h"

void Socket::OnClose(int nErrorCode) 
{
	SetDlgItemText(AfxGetApp()->m_pMainWnd->m_hWnd, 1005, L"������������");
	SetDlgItemText(AfxGetApp()->m_pMainWnd->m_hWnd, 1008, L"");
	CSocket::OnClose(nErrorCode);
}
