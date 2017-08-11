// TreeProjectDoc.h : interface of the CTreeProjectDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREEPROJECTDOC_H__1279FA22_5E1E_4EBA_A162_3ED903FECDFE__INCLUDED_)
#define AFX_TREEPROJECTDOC_H__1279FA22_5E1E_4EBA_A162_3ED903FECDFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTreeProjectDoc : public CDocument
{
protected: // create from serialization only
	CTreeProjectDoc();
	DECLARE_DYNCREATE(CTreeProjectDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeProjectDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTreeProjectDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTreeProjectDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEPROJECTDOC_H__1279FA22_5E1E_4EBA_A162_3ED903FECDFE__INCLUDED_)
