// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#if !defined(AFX_STDAFX_H__INCLUDED_)
#define AFX_STDAFX_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// 从 Windows 头中排除极少使用的资料

#include <afxwin.h>			// MFC 核心组件和标准组件
#include <afxext.h>			// MFC 扩展

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>			// MFC OLE 支持
#include <afxodlgs.h>		// MFC OLE 对话框支持
#include <afxdisp.h>		// MFC OLE 自动化支持
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>			// MFC ODBC 数据库支持
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			// MFC DAO 数据库支持
#endif // _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>		// MFC 对 Internet Explorer 4 公共控件的支持
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ 编译器生成的添加位置

#endif // !defined(AFX_STDAFX_H__INCLUDED_)
