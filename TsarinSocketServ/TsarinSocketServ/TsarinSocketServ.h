
// TsarinSocketServ.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CTsarinSocketServApp:
// Сведения о реализации этого класса: TsarinSocketServ.cpp
//

class CTsarinSocketServApp : public CWinApp
{
public:
	CTsarinSocketServApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CTsarinSocketServApp theApp;
