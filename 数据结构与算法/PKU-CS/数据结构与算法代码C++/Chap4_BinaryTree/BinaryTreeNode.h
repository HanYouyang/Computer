// BinaryTreeNode.h: interface for the BinaryTreeNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BINARYTREENODE_H__65C73C3B_E763_40D9_8460_F5703119C756__INCLUDED_)
#define AFX_BINARYTREENODE_H__65C73C3B_E763_40D9_8460_F5703119C756__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T> class BinaryTree;
template <class T> class BinarySearchTree;

template <class T>
class BinaryTreeNode  
{
friend class BinaryTree<T>;
friend class BinarySearchTree<T>;
private:
	T  element;					               			//���������������
	BinaryTreeNode<T>*  left; 							//���������ָ����������ָ��
	BinaryTreeNode<T>*  right; 							//���������ָ����������ָ��

public:
	BinaryTreeNode();
	BinaryTreeNode(const T& ele);						//�������ݵĹ��캯��
	BinaryTreeNode(const T& ele,BinaryTreeNode* l, BinaryTreeNode* r);//�������ݵ�����ָ��Ĺ��캯��
	T  value() const;									//���ص�ǰ��������
	BinaryTreeNode<T>& operator= (const BinaryTreeNode<T>& Node)
	{this=Node;};										//���ظ�ֵ������
	BinaryTreeNode<T>*  leftchild() const;				//���ص�ǰ���ָ����������ָ��
	BinaryTreeNode<T>*  rightchild() const;				//���ص�ǰ���ָ����������ָ��
    void  setLeftchild(BinaryTreeNode<T>*);				//���õ�ǰ����������
    void  setRightchild(BinaryTreeNode<T>*);			//���õ�ǰ����������

	void  setValue(const T& val);						//���õ�ǰ����������
	bool  isLeaf() const;								//�ж���ǰ����Ƿ�ΪҶ���,���Ƿ���true
};

  //***************************************************************************//
 //**********************Class BinaryTreeNode Implementation******************//
//***************************************************************************//

template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	left=right=NULL;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele)	//�������ݵĹ��캯��
{
	element=ele;
	left=right=NULL;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele,BinaryTreeNode* l, BinaryTreeNode* r)
//�������ݵ�����ָ��Ĺ��캯��
{
	element=ele;
	left=l;
	right=r;
}

template<class T>
T  BinaryTreeNode<T>::value() const
{
	return element; 
}	

template<class T>
BinaryTreeNode<T>*  BinaryTreeNode<T>::leftchild() const
{
	return left;
}												//���ص�ǰ���ָ����������ָ��

template<class T>
BinaryTreeNode<T>*  BinaryTreeNode<T>::rightchild() const
{
	return right;								//���ص�ǰ���ָ����������ָ��
}			

template<class T>
void  BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T>* subroot)//���õ�ǰ����������
{
	left=subroot;
}

template<class T>
void  BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T>* subroot)//���õ�ǰ����������
{
	right=subroot;
}

template<class T>
void  BinaryTreeNode<T>::setValue(const T& val)	//���õ�ǰ����������
{
	element = val; 
} 									

template<class T>
bool  BinaryTreeNode<T>::isLeaf() const			//�ж���ǰ����Ƿ�ΪҶ���,���Ƿ���true
{
	return (left == NULL) && (right == NULL); 
}


#endif // !defined(AFX_BINARYTREENODE_H__65C73C3B_E763_40D9_8460_F5703119C756__INCLUDED_)
