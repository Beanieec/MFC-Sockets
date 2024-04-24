
// TsarinSocketClient.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CTsarinSocketClientApp:
// Сведения о реализации этого класса: TsarinSocketClient.cpp
//

class CTsarinSocketClientApp : public CWinApp
{
public:
	CTsarinSocketClientApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CTsarinSocketClientApp theApp;
