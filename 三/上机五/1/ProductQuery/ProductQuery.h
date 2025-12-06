// ProductQuery.h : 主头文件，包含应用程序类声明

#pragma once

#include "framework.h"

//////////////////////////////////////////////////////////////////////////// CProductQueryApp:
// 有关此类的实现，请参阅 ProductQuery.cpp
//

class CProductQueryApp : public CWinApp
{
public:
	CProductQueryApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

// 应用程序全局对象
extern CProductQueryApp theApp;
