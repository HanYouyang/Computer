// BinaryTreeView.h : interface of the CBinaryTreeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BINARYTREEVIEW_H__A6DF445B_C043_421D_93F7_AB4F9D13782B__INCLUDED_)
#define AFX_BINARYTREEVIEW_H__A6DF445B_C043_421D_93F7_AB4F9D13782B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BinaryTreeNode.h"
#include "BinaryTree1.h"
#include "ThreadBinaryTreeNode.h"
#include "ThreadBinaryTree.h"
#include "BinarySearchTree.h"
#include "MinHeap.h"
#include "MaxHeap.h"
#include "InputDialog.h"

#define HEAP_SIZE	32

class BinaryTree<class T>;

class CBinaryTreeView : public CView
{
protected: // create from serialization only
	CBinaryTreeView();
	DECLARE_DYNCREATE(CBinaryTreeView)

// Attributes
public:
	BinaryTree<CString> EmptyTree;
	BinaryTree<CString> Element1,Element2,Element3,Element4;
	BinaryTree<CString> MyTree;

	ThreadBinaryTree<CString> EmptyThreadTree;
	ThreadBinaryTree<CString> ElementThread1,ElementThread2,ElementThread3,ElementThread4;
	ThreadBinaryTree<CString> MyThreadTree;

	BinarySearchTree<CString> MyBSTtree;
	MinHeap<int>* heap;	

	CBinaryTreeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBinaryTreeView)
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
	virtual ~CBinaryTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBinaryTreeView)
	afx_msg void OnCreateTree();
	afx_msg void OnCreateThreadTree();
	afx_msg void OnInorderTraverseThreadtree();
	afx_msg void OnInsertNode();
	afx_msg void OnBstAddnode();
	afx_msg void OnBstDeletenode();
	afx_msg void OnTraverseBsttree();
	afx_msg void OnInsertheapnode();
	afx_msg void OnDeleteheapnode();
	afx_msg void OnMaxheapTest();
	afx_msg void OnDeleteHeapnode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BinaryTreeView.cpp
inline CBinaryTreeDoc* CBinaryTreeView::GetDocument()
   { return (CBinaryTreeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BINARYTREEVIEW_H__A6DF445B_C043_421D_93F7_AB4F9D13782B__INCLUDED_)
