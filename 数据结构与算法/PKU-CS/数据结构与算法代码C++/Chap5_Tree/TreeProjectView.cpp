// TreeProjectView.cpp : implementation of the CTreeProjectView class
//

#include "stdafx.h"
#include "TreeProject.h"

#include "TreeProjectDoc.h"
#include "TreeProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeProjectView

IMPLEMENT_DYNCREATE(CTreeProjectView, CView)

BEGIN_MESSAGE_MAP(CTreeProjectView, CView)
	//{{AFX_MSG_MAP(CTreeProjectView)
	ON_COMMAND(ID_TEST, OnTest)
	ON_COMMAND(ID_PARENT, OnParent)
	ON_COMMAND(ID_DUALTAGTREE, OnDualtagtree)
	ON_COMMAND(ID_LEFTLEVEL, OnLeftlevel)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeProjectView construction/destruction

CTreeProjectView::CTreeProjectView()
{
	m_ParTree=new ParTree<CString>(10);
	m_ParTree->array[0].setValue("a");
	m_ParTree->array[1].setValue("b");
	m_ParTree->array[2].setValue("c");
	m_ParTree->array[3].setValue("d");
	m_ParTree->array[4].setValue("e");
	m_ParTree->array[5].setValue("f");
	m_ParTree->array[6].setValue("g");
	m_ParTree->array[7].setValue("h");
	m_ParTree->array[8].setValue("i");
	m_ParTree->array[9].setValue("j");

	m_NodeArray=new DualTagTreeNode<CString>[10];
	m_NodeArray[0].info="a";
	m_NodeArray[0].ltag=0;
	m_NodeArray[0].rtag=0;
	m_NodeArray[1].info="b";
	m_NodeArray[1].ltag=1;
	m_NodeArray[1].rtag=0;
	m_NodeArray[2].info="c";
	m_NodeArray[2].ltag=0;
	m_NodeArray[2].rtag=1;
	m_NodeArray[3].info="k";
	m_NodeArray[3].ltag=1;
	m_NodeArray[3].rtag=1;
	m_NodeArray[4].info="d";
	m_NodeArray[4].ltag=0;
	m_NodeArray[4].rtag=1;
	m_NodeArray[5].info="e";
	m_NodeArray[5].ltag=0;
	m_NodeArray[5].rtag=0;
	m_NodeArray[6].info="h";
	m_NodeArray[6].ltag=1;
	m_NodeArray[6].rtag=1;
	m_NodeArray[7].info="f";
	m_NodeArray[7].ltag=0;
	m_NodeArray[7].rtag=0;
	m_NodeArray[8].info="j";
	m_NodeArray[8].ltag=1;
	m_NodeArray[8].rtag=1;
	m_NodeArray[9].info="g";
	m_NodeArray[9].ltag=1;
	m_NodeArray[9].rtag=1;

	m_LinkNodeArray=new LeftLinkTreeNode<CString>[10];
	m_LinkNodeArray[0].info="a";
	m_LinkNodeArray[0].llink=m_LinkNodeArray+2;
	m_LinkNodeArray[0].rtag=0;
	m_LinkNodeArray[1].info="d";
	m_LinkNodeArray[1].llink=m_LinkNodeArray+4;
	m_LinkNodeArray[1].rtag=1;
	m_LinkNodeArray[2].info="b";
	m_LinkNodeArray[2].llink=NULL;
	m_LinkNodeArray[2].rtag=0;
	m_LinkNodeArray[3].info="c";
	m_LinkNodeArray[3].llink=m_LinkNodeArray+7;
	m_LinkNodeArray[3].rtag=1;
	m_LinkNodeArray[4].info="e";
	m_LinkNodeArray[4].llink=m_LinkNodeArray+8;
	m_LinkNodeArray[4].rtag=0;
	m_LinkNodeArray[5].info="f";
	m_LinkNodeArray[5].llink=m_LinkNodeArray+9;
	m_LinkNodeArray[5].rtag=0;
	m_LinkNodeArray[6].info="g";
	m_LinkNodeArray[6].llink=NULL;
	m_LinkNodeArray[6].rtag=1;
	m_LinkNodeArray[7].info="k";
	m_LinkNodeArray[7].llink=NULL;
	m_LinkNodeArray[7].rtag=1;
	m_LinkNodeArray[8].info="h";
	m_LinkNodeArray[8].llink=NULL;
	m_LinkNodeArray[8].rtag=1;
	m_LinkNodeArray[9].info="j";
	m_LinkNodeArray[9].llink=NULL;
	m_LinkNodeArray[9].rtag=1;

}

CTreeProjectView::~CTreeProjectView()
{
	if(m_ParTree)
		delete m_ParTree;
	if(m_NodeArray)
		delete []m_NodeArray;
	if(m_LinkNodeArray)
		delete []m_LinkNodeArray;
	if(pTree)
		delete pTree;
	if(pTree2)
		delete pTree2;
}

BOOL CTreeProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTreeProjectView drawing

void CTreeProjectView::OnDraw(CDC* pDC)
{
	CTreeProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTreeProjectView printing

BOOL CTreeProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTreeProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTreeProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTreeProjectView diagnostics

#ifdef _DEBUG
void CTreeProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CTreeProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTreeProjectDoc* CTreeProjectView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreeProjectDoc)));
	return (CTreeProjectDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreeProjectView message handlers

void CTreeProjectView::OnTest() 
{
	m_Tree.CreateRoot("a");

	TreeNode<CString>* pb=new TreeNode<CString>("b");

	TreeNode<CString>* pc=new TreeNode<CString>("c");
	TreeNode<CString>* pd=new TreeNode<CString>("d");
	TreeNode<CString>* pe=new TreeNode<CString>("e");
	TreeNode<CString>* pf=new TreeNode<CString>("f");
	TreeNode<CString>* pg=new TreeNode<CString>("g");
	TreeNode<CString>* pk=new TreeNode<CString>("k");
	TreeNode<CString>* pl=new TreeNode<CString>("l");
	TreeNode<CString>* ph=new TreeNode<CString>("h");
	TreeNode<CString>* pi=new TreeNode<CString>("i");
	TreeNode<CString>* pm=new TreeNode<CString>("m");
	TreeNode<CString>* pj=new TreeNode<CString>("j");
	TreeNode<CString>* pn=new TreeNode<CString>("n");

	TreeNode<CString>* px=new TreeNode<CString>("x");
	TreeNode<CString>* py=new TreeNode<CString>("y");

	m_Tree.getRoot()->InsertFirst(pb);

	pb->InsertFirst(pe);
	pb->InsertNext(pc);
	pc->InsertNext(pd);
	pe->InsertNext(pf);
	pc->InsertFirst(pg);
	pf->InsertFirst(pk);
	pk->InsertNext(pl);
	pd->InsertFirst(ph);
	ph->InsertNext(pi);
	pi->InsertFirst(pm);
	pi->InsertNext(pj);
	pm->InsertNext(pn);

	m_Tree.getRoot()->InsertNext(px);
	px->InsertNext(py);

//	MessageBox(m_Tree.Parent(pl)->Value());
//	MessageBox(m_Tree.Parent(pj)->Value());

//	m_Tree.RootFirstTraverse(m_Tree.getRoot());
//	m_Tree.RootLastTraverse(m_Tree.getRoot());
	m_Tree.WidthTraverse(m_Tree.getRoot());
//	m_Tree.WidthTraverse2(m_Tree.getRoot());


//	m_Tree.DeleteSubTree(pb);
//	m_Tree.DeleteSubTree(pc);

//	MessageBox(m_Tree.PrevSibling(pl)->Value());

//	m_Tree.RootFirstTraverse(m_Tree.getRoot());
}

void CTreeProjectView::OnParent() 
{
	m_ParTree->Union(0,1);
	m_ParTree->Union(1,2);

	m_ParTree->Union(3,4);
	m_ParTree->Union(5,6);
	m_ParTree->Union(3,6);

	m_ParTree->Union(7,8);
	m_ParTree->Union(8,9);

	bool check=m_ParTree->Different(0,2);
	check=m_ParTree->Different(1,6);
	check=m_ParTree->Different(4,9);
	check=m_ParTree->Different(8,9);
}

void CTreeProjectView::OnDualtagtree() 
{
	pTree=new Tree<CString>(m_NodeArray,10);	
	pTree->RootFirstTraverse(pTree->getRoot());
}

void CTreeProjectView::OnLeftlevel() 
{
	pTree2=new Tree<CString>(m_LinkNodeArray,10);	
	pTree2->RootFirstTraverse(pTree2->getRoot());

}
