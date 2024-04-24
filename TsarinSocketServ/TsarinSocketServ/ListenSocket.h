#pragma once
#include <afxsock.h>
#include "DutySocket.h"

class ListenSocket : public CSocket
{
public:
	DutySocket DSock;
	virtual ~ListenSocket();
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};

