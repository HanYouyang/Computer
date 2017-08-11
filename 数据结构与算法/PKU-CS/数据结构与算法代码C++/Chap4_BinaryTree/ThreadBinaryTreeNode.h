// ThreadBinaryTreeNode.h: interface for the ThreadBinaryTreeNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREADBINARYTREENODE_H__C8A1F5EE_AE5A_4117_AFA5_53BB64912CA5__INCLUDED_)
#define AFX_THREADBINARYTREENODE_H__C8A1F5EE_AE5A_4117_AFA5_53BB64912CA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T> class ThreadBinaryTree;

template <class T>
class ThreadBinaryTreeNode  
{
friend class ThreadBinaryTree<T>;
private:
	int lTag,rTag;							//���ұ�־λ
	ThreadBinaryTreeNode<T> *left,*right;	//��������������
	T	element;
public:
	ThreadBinaryTreeNode();
	//���캯��
	ThreadBinaryTreeNode(const T&):element(T),left(NULL),right(NULL),lTag(0),rTag(0){};
	//�������ݵ�����ָ��Ĺ��캯��
	ThreadBinaryTreeNode(const T& ele,ThreadBinaryTreeNode<T>* l,int leftTag, ThreadBinaryTreeNode<T>* r,int rightTag);
	T value() const{return element;};						 		
	ThreadBinaryTreeNode<T>* leftchild()const {return left;};	
	ThreadBinaryTreeNode<T>* rightchild()const {return right;};
	void setValue(const T& type){element=type;};
	virtual ~ThreadBinaryTreeNode(){};						//��������
};

template<class T>
ThreadBinaryTreeNode<T>::ThreadBinaryTreeNode(const T& ele,ThreadBinaryTreeNode<T>* l,int leftTag, ThreadBinaryTreeNode<T>* r,int rightTag)
//�������ݵ�����ָ��Ĺ��캯��
{
	element=ele;
	left=l;
	lTag=leftTag;
	right=r;
	rTag=rightTag;
}

#endif // !defined(AFX_THREADBINARYTREENODE_H__C8A1F5EE_AE5A_4117_AFA5_53BB64912CA5__INCLUDED_)
