// LeftLinkTreeNode.h: interface for the LeftLinkTreeNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEFTLINKTREENODE_H__FDAF9906_FFDB_4436_911F_99EF37E1285C__INCLUDED_)
#define AFX_LEFTLINKTREENODE_H__FDAF9906_FFDB_4436_911F_99EF37E1285C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template<class T>
class LeftLinkTreeNode  
{
public:
	T	info;							//�������Ϣ
	LeftLinkTreeNode<T>*	llink;		//��ָ��
	int rtag;							//�ұ��
	LeftLinkTreeNode();
	virtual ~LeftLinkTreeNode(){};
};

template <class T>
LeftLinkTreeNode<T>::LeftLinkTreeNode()
{
		llink=NULL;
		rtag=1;
}

#endif // !defined(AFX_LEFTLINKTREENODE_H__FDAF9906_FFDB_4436_911F_99EF37E1285C__INCLUDED_)
