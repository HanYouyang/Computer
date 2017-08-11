// TreeProject.h : main header file for the TREEPROJECT application
//

#if !defined(AFX_TREEPROJECT_H__C061FDC0_706B_44F2_841F_9A2A525CECED__INCLUDED_)
#define AFX_TREEPROJECT_H__C061FDC0_706B_44F2_841F_9A2A525CECED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTreeProjectApp:
// See TreeProject.cpp for the implementation of this class
//

class CTreeProjectApp : public CWinApp
{
public:
	CTreeProjectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeProjectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTreeProjectApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEPROJECT_H__C061FDC0_706B_44F2_841F_9A2A525CECED__INCLUDED_)
