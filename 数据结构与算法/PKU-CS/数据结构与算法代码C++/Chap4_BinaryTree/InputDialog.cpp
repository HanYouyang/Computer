// InputDialog.cpp : implementation file
//

#include "stdafx.h"
#include "BinaryTree.h"
#include "InputDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputDialog dialog


CInputDialog::CInputDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CInputDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInputDialog)
	m_Input = _T("");
	//}}AFX_DATA_INIT
}


void CInputDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputDialog)
	DDX_Text(pDX, IDC_INPUT_EDIT, m_Input);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInputDialog, CDialog)
	//{{AFX_MSG_MAP(CInputDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputDialog message handlers
