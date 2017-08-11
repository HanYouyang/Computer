// TreeProjectDoc.cpp : implementation of the CTreeProjectDoc class
//

#include "stdafx.h"
#include "TreeProject.h"

#include "TreeProjectDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeProjectDoc

IMPLEMENT_DYNCREATE(CTreeProjectDoc, CDocument)

BEGIN_MESSAGE_MAP(CTreeProjectDoc, CDocument)
	//{{AFX_MSG_MAP(CTreeProjectDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeProjectDoc construction/destruction

CTreeProjectDoc::CTreeProjectDoc()
{
	// TODO: add one-time construction code here

}

CTreeProjectDoc::~CTreeProjectDoc()
{
}

BOOL CTreeProjectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTreeProjectDoc serialization

void CTreeProjectDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTreeProjectDoc diagnostics

#ifdef _DEBUG
void CTreeProjectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTreeProjectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreeProjectDoc commands
