// BinaryTreeDoc.h : interface of the CBinaryTreeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BINARYTREEDOC_H__8579BA80_8A89_4595_AF4D_43F8D64FE123__INCLUDED_)
#define AFX_BINARYTREEDOC_H__8579BA80_8A89_4595_AF4D_43F8D64FE123__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBinaryTreeDoc : public CDocument
{
protected: // create from serialization only
	CBinaryTreeDoc();
	DECLARE_DYNCREATE(CBinaryTreeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBinaryTreeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBinaryTreeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBinaryTreeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BINARYTREEDOC_H__8579BA80_8A89_4595_AF4D_43F8D64FE123__INCLUDED_)
