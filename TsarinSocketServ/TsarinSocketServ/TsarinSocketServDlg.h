#include <afxsock.h>
#include "ListenSocket.h"
#pragma once

// Диалоговое окно CTsarinSocketServDlg
class CTsarinSocketServDlg : public CDialogEx
{
public:
	CTsarinSocketServDlg(CWnd* pParent = nullptr);	// стандартный конструктор
	ListenSocket ServerSocket;
	enum { IDD = IDD_TSARINSOCKETSERV_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV

protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CString ServerPort = L"666";
	afx_msg void OnBnClickedButtonserver();
	afx_msg void OnEnChangeEditport();
	afx_msg void OnEnChangeEditserver();
};
