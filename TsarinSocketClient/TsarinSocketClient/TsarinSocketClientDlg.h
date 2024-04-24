#include <afxsock.h>
#include "Socket.h"
#pragma once


// Диалоговое окно CTsarinSocketClientDlg
class CTsarinSocketClientDlg : public CDialogEx
{
public:
	CTsarinSocketClientDlg(CWnd* pParent = nullptr);	// стандартный конструктор
	Socket server;
	enum { IDD = IDD_TSARINSOCKETCLIENT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV

protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonsend();
	afx_msg void OnBnClickedButtoncon();
	afx_msg void OnEnChangeEditip();
	afx_msg void OnEnChangeEditport();
	afx_msg void OnEnChangeEditdis();
	CString ClientIP = L"127.0.0.1";
	CString ClientPORT = L"666";
};
