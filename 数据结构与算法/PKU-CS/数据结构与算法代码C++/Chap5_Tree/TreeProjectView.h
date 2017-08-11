// TreeProjectView.h : interface of the CTreeProjectView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREEPROJECTVIEW_H__9FDE4CCA_12CC_4045_929A_D9521021B2E9__INCLUDED_)
#define AFX_TREEPROJECTVIEW_H__9FDE4CCA_12CC_4045_929A_D9521021B2E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tree.h"
#include "TreeNode.h"
#include "ParTree.h"
#include "DualTagTreeNode.h"
#include "LeftLinkTreeNode.h"

class CTreeProjectView : public CView
{
protected: // create from serialization only
	CTreeProjectView();
	DECLARE_DYNCREATE(CTreeProjectView)

// Attributes
public:
	CTreeProjectDoc* GetDocument();
	Tree<CString> m_Tree;
	Tree<CString>* pTree;
	Tree<CString>* pTree2;
	ParTree<CString>* m_ParTree;
	DualTagTreeNode<CString>* m_NodeArray;
	LeftLinkTreeNode<CString>* m_LinkNodeArray;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeProjectView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTreeProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTreeProjectView)
	afx_msg void OnTest();
	afx_msg void OnParent();
	afx_msg void OnDualtagtree();
	afx_msg void OnLeftlevel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TreeProjectView.cpp
inline CTreeProjectDoc* CTreeProjectView::GetDocument()
   { return (CTreeProjectDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEPROJECTVIEW_H__9FDE4CCA_12CC_4045_929A_D9521021B2E9__INCLUDED_)
