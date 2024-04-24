#pragma once
#include <afxsock.h>

class Socket : public CSocket
{
public:
	virtual void OnClose(int nErrorCode);
};

