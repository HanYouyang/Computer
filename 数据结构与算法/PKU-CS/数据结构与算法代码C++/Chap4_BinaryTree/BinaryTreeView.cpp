// BinaryTreeView.cpp : implementation of the CBinaryTreeView class
//

#include "stdafx.h"
#include "BinaryTree.h"

#include "BinaryTreeDoc.h"
#include "BinaryTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeView

IMPLEMENT_DYNCREATE(CBinaryTreeView, CView)

BEGIN_MESSAGE_MAP(CBinaryTreeView, CView)
	//{{AFX_MSG_MAP(CBinaryTreeView)
	ON_COMMAND(ID_CREATE, OnCreateTree)
	ON_COMMAND(ID_CREATE_THREAD_TREE, OnCreateThreadTree)
	ON_COMMAND(ID_INORDER_TRAVERSE_THREADTREE, OnInorderTraverseThreadtree)
	ON_COMMAND(ID_INSERT_NODE, OnInsertNode)
	ON_COMMAND(IDD_BST_ADDNODE, OnBstAddnode)
	ON_COMMAND(IDD_BST_DELETENODE, OnBstDeletenode)
	ON_COMMAND(ID_TRAVERSE_BSTTREE, OnTraverseBsttree)
	ON_COMMAND(IDD_INSERTHEAPNODE, OnInsertheapnode)
	ON_COMMAND(ID_DELETEHEAPNODE, OnDeleteheapnode)
	ON_COMMAND(ID_MAXHEAP_TEST, OnMaxheapTest)
	ON_COMMAND(ID_DELETE_HEAPNODE, OnDeleteHeapnode)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeView construction/destruction

CBinaryTreeView::CBinaryTreeView()
{
	heap=new MinHeap<int>(HEAP_SIZE);
}

CBinaryTreeView::~CBinaryTreeView()
{
	if(heap)
		delete heap;
}

BOOL CBinaryTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeView drawing

void CBinaryTreeView::OnDraw(CDC* pDC)
{
	CBinaryTreeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeView printing

BOOL CBinaryTreeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBinaryTreeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBinaryTreeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeView diagnostics

#ifdef _DEBUG
void CBinaryTreeView::AssertValid() const
{
	CView::AssertValid();
}

void CBinaryTreeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBinaryTreeDoc* CBinaryTreeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBinaryTreeDoc)));
	return (CBinaryTreeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeView message handlers

void CBinaryTreeView::OnCreateTree() 
{
	if(!MyTree.getRoot())
	{
		Element1.CreateTree("3",EmptyTree,EmptyTree);
		Element2.CreateTree("4",EmptyTree,EmptyTree);
		Element3.CreateTree("1",Element1,Element2);
		Element1.CreateTree("5",EmptyTree,EmptyTree);
		Element2.CreateTree("6",EmptyTree,EmptyTree);
		Element4.CreateTree("2",Element1,Element2);
		MyTree.CreateTree("0",Element3,Element4);

/*		
		BinaryTreeNode<CString>* Node=MyTree.getRoot()->leftchild()->rightchild();
		BinaryTreeNode<CString>* pNode=MyTree.Parent(Node);
		MessageBox(pNode->value());
		pNode=MyTree.LeftSibling(Node);
		MessageBox(pNode->value());
*/
//		MyTree.PreOrder(MyTree.getRoot());
//		MyTree.InOrder(MyTree.getRoot());
//		MyTree.PostOrder(MyTree.getRoot());

//		MyTree.PreOrderWithoutRecusion(MyTree.getRoot());
//		MyTree.InOrderWithoutRecusion(MyTree.getRoot());
//		MyTree.PostOrderWithoutRecusion(MyTree.getRoot());

//		MyTree.LevelOrder(MyTree.getRoot());
		MyTree.PostOrderWithoutRecusion2(MyTree.getRoot());

	}
}


void CBinaryTreeView::OnCreateThreadTree() 
{
	if(!MyTree.getRoot())
	{
		ElementThread1.CreateTree("3",EmptyThreadTree,EmptyThreadTree);
		ElementThread2.CreateTree("4",EmptyThreadTree,EmptyThreadTree);
		ElementThread3.CreateTree("1",ElementThread1,ElementThread2);
		ElementThread1.CreateTree("5",EmptyThreadTree,EmptyThreadTree);
		ElementThread2.CreateTree("6",EmptyThreadTree,EmptyThreadTree);
		ElementThread4.CreateTree("2",ElementThread1,ElementThread2);
		MyThreadTree.CreateTree("0",ElementThread3,ElementThread4);

//		MyThreadTree.InThread(MyThreadTree.getRoot());
		ThreadBinaryTreeNode<CString>* pNode=NULL;
		MyThreadTree.InThread(MyThreadTree.getRoot(),pNode);
	}
}

void CBinaryTreeView::OnInorderTraverseThreadtree() 
{
	if(MyThreadTree.getRoot())
		MyThreadTree.InOrder(MyThreadTree.getRoot());
	
}

void CBinaryTreeView::OnInsertNode() 
{
	if(MyThreadTree.getRoot())
	{
		ThreadBinaryTreeNode<CString>* newpointer=new ThreadBinaryTreeNode<CString>("hehe",0,NULL,0,NULL);
		MyThreadTree.InsertNode(MyThreadTree.getRoot(),newpointer);
	}
}

void CBinaryTreeView::OnBstAddnode() 
{
	CInputDialog dlg;
	if(dlg.DoModal()==IDOK)
	{
		BinaryTreeNode<CString>* root=MyBSTtree.getRoot();
		BinaryTreeNode<CString>* newpointer=new BinaryTreeNode<CString>(dlg.m_Input,NULL,NULL);
		MyBSTtree.InsertNode(root,newpointer);
	}
}

void CBinaryTreeView::OnBstDeletenode() 
{
	BinaryTreeNode<CString>* root=MyBSTtree.getRoot();
	if(root)
	{
		//MyBSTtree.DeleteNode(root);
		//BinaryTreeNode<CString>* pointer=root->leftchild();
		BinaryTreeNode<CString>* pointer=root->rightchild();
		MyBSTtree.DeleteNode(pointer);
		//MyBSTtree.DeleteNodeEx(pointer);

	}
}

void CBinaryTreeView::OnTraverseBsttree() 
{
	MyBSTtree.InOrder(MyBSTtree.getRoot());
}

void CBinaryTreeView::OnInsertheapnode() 
{
	if(heap)
	{
		heap->Insert(73);
		heap->Insert(23);
		heap->Insert(5);
		heap->Insert(68);
		heap->Insert(94);
		heap->Insert(16);
		heap->Insert(72);
		heap->Insert(71);
		heap->Insert(27);
		heap->Insert(29);
		heap->Insert(31);

	}
}

void CBinaryTreeView::OnDeleteheapnode() 
{
	if(heap)
	{
		int str=heap->RemoveMin();
	}
}


void CBinaryTreeView::OnMaxheapTest() 
{
	srand(1);
	int* array=new int[10];
	for(int i=0;i<10;i++)
		array[i]=rand() % 100;
	MaxHeap<int>* maxheap=new MaxHeap<int>(array,10,10);	

	int j=0;
	for(i=0;i<10;i++)
	  maxheap->MoveMax();
	delete array;
	delete maxheap;
	

}

void CBinaryTreeView::OnDeleteHeapnode() 
{
	if(heap)
	{
		bool flag=false;
		int  str;
		flag=heap->Remove(9,str);
	}
	
}
