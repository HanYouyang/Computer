// BinaryTreeDoc.cpp : implementation of the CBinaryTreeDoc class
//

#include "stdafx.h"
#include "BinaryTree.h"

#include "BinaryTreeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeDoc

IMPLEMENT_DYNCREATE(CBinaryTreeDoc, CDocument)

BEGIN_MESSAGE_MAP(CBinaryTreeDoc, CDocument)
	//{{AFX_MSG_MAP(CBinaryTreeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeDoc construction/destruction

CBinaryTreeDoc::CBinaryTreeDoc()
{
	// TODO: add one-time construction code here

}

CBinaryTreeDoc::~CBinaryTreeDoc()
{
}

BOOL CBinaryTreeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeDoc serialization

void CBinaryTreeDoc::Serialize(CArchive& ar)
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
// CBinaryTreeDoc diagnostics

#ifdef _DEBUG
void CBinaryTreeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBinaryTreeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeDoc commands
