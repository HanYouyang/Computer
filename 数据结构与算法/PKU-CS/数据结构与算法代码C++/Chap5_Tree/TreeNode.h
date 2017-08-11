// TreeNode.h: interface for the TreeNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREENODE_H__13C52CCB_6E4A_493C_9F1A_AA230FD1F057__INCLUDED_)
#define AFX_TREENODE_H__13C52CCB_6E4A_493C_9F1A_AA230FD1F057__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T> class Tree;

template<class T>
class TreeNode  
{
friend class Tree<T>;
private:
	T m_Value;							//������ֵ
	TreeNode<T>*	pChild;				//���ӽ��
	TreeNode<T>*	pSibling;			//���ֵܽ��
public:
  TreeNode();							//ȱʡ���캯��
  TreeNode(const T&);					//�������캯��
  ~TreeNode(){};						//��������
  bool isLeaf();					    //��������Ҷ������true
  T Value();							//���ؽ���ֵ 
  TreeNode<T>* LeftMostChild();			//���ص�һ������
  TreeNode<T>* RightSibling();			//�������ֵ�
  void setValue(T&);					//���ý���ֵ 
  void setChild(TreeNode<T>* pointer);	//��������
  void setSibling(TreeNode<T>* pointer);//�������ֵ�
  void InsertFirst(TreeNode<T>* node);	//�Ե�һ�����ӵ���ݲ�����
  void InsertNext(TreeNode<T>* node);	//�����ֵܵ���ݲ�����
};

template<class T>
TreeNode<T>::TreeNode()
{//ȱʡ���캯��
		pChild=NULL;
		pSibling=NULL;
}
template<class T>
TreeNode<T>::TreeNode(const T& value)
{//�������캯��
		m_Value=value;
		pChild=NULL;
		pSibling=NULL;
}

template<class T>
T TreeNode<T>::Value()
{//���ؽ���ֵ 
	return m_Value;
}

template<class T>
bool TreeNode<T>::isLeaf()
{//��������Ҷ������true
	if(NULL==pChild)
		return true;
	return false;
}

template<class T>
TreeNode<T>* TreeNode<T>::LeftMostChild()
{//���ص�һ������
	return pChild;
}

template<class T>
TreeNode<T>* TreeNode<T>::RightSibling()
{//�������ֵ�
	return pSibling;
}

template<class T>
void TreeNode<T>::setValue(T& value)
{//���ý���ֵ 
	m_Value=value;
}

template<class T>
void TreeNode<T>::setChild(TreeNode<T>* pointer)
{//��������
	pChild=pointer;
}

template<class T>
void TreeNode<T>::setSibling(TreeNode<T>* pointer)
{//�������ֵ�
	pSibling=pointer;
}

template<class T>
void TreeNode<T>::InsertFirst(TreeNode<T>* node)
{//�Ե�һ�����ӵ���ݲ�����
	if(!pChild)
		pChild=node;
	else
	{
		node->pSibling=pChild;
		pChild=node;
	}
}

template<class T>
void TreeNode<T>::InsertNext(TreeNode<T>* node)
{//�����ֵܵ���ݲ�����
	if(!pSibling)
		pSibling=node;
	else
	{
		node->pSibling=pSibling;
		pSibling=node;
	}
}

#endif // !defined(AFX_TREENODE_H__13C52CCB_6E4A_493C_9F1A_AA230FD1F057__INCLUDED_)
