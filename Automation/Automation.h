
// Automation.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAutomationApp:
// �йش����ʵ�֣������ Automation.cpp
//

class CAutomationApp : public CWinApp
{
public:
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	CAutomationApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAutomationApp theApp;