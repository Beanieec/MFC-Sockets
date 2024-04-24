#pragma once
#include <afxsock.h>
class DutySocket : public CSocket
{
public:
    DutySocket();
    virtual ~DutySocket();
    virtual void OnClose(int nErrorCode);
    virtual void OnReceive(int nErrorCode);
    
protected:
    int MAIL;
    TCHAR* Buffer;
    CString IP, strMAIL;
    UINT Port;
};

