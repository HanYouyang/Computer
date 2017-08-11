// ThreadBinaryTree.h: interface for the ThreadBinaryTree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREADBINARYTREE_H__73E5ADE5_F47C_463B_B199_91EE62DE38D6__INCLUDED_)
#define AFX_THREADBINARYTREE_H__73E5ADE5_F47C_463B_B199_91EE62DE38D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ThreadBinaryTreeNode.h"

template <class T>
class ThreadBinaryTree  
{
private:
	ThreadBinaryTreeNode<T>* root;						//�����ָ��
public:
	ThreadBinaryTree(){	root=NULL;};					//���캯��
	virtual ~ThreadBinaryTree(){DeleteTree(root);};
	ThreadBinaryTreeNode<T>* getRoot(){return root;};	//���ظ����ָ��
	//��element��Ϊ����㣬leftTree��Ϊ������������rightTree��Ϊ����������������һ���µĶ�����
	void CreateTree(const T& elem, ThreadBinaryTree<T>& leftTree, ThreadBinaryTree<T>& rightTree);
	//ɾ����������������
	void DeleteTree(ThreadBinaryTreeNode<T>* root);
	//�Գ���������������
	void InThread(ThreadBinaryTreeNode<T>* root);
	//�ݹ�Գ���������������
	void InThread(ThreadBinaryTreeNode<T>* root,ThreadBinaryTreeNode<T>* &pre);
	//�Գ�������
	void InOrder(ThreadBinaryTreeNode<T>* root);
	//�ڶԳ�����������ָ�������ǰ���µĺ��
	ThreadBinaryTreeNode<T>* FindNextinInorderTree(ThreadBinaryTreeNode<T>* pointer);
	//���Գ������������һ���½��
	void InsertNode(ThreadBinaryTreeNode<T>*pointer,ThreadBinaryTreeNode<T>* newpointer);
};

template <class T>
void ThreadBinaryTree<T>::CreateTree(const T& elem, ThreadBinaryTree<T>& leftTree, ThreadBinaryTree<T>& rightTree)
{
	root=new ThreadBinaryTreeNode<T>(elem,leftTree.root,0,rightTree.root,0);//��������
	leftTree.root=rightTree.root=NULL;							//ԭ�����������ĸ����ָ�գ��������

}

template <class T>
void ThreadBinaryTree<T>::DeleteTree(ThreadBinaryTreeNode<T>* root)//ɾ����������������
{
	if(root)
	{
		if(root->lTag==0)
			DeleteTree(root->left);
		if(root->rTag==0)
		DeleteTree(root->right);
		delete root;
	}
	else
		delete root;
}

template <class T>
void ThreadBinaryTree<T>::InThread(ThreadBinaryTreeNode<T>* root,ThreadBinaryTreeNode<T>* &pre)
//�ݹ�Գ���������������
{
	if(root!=NULL)
	{
		//����������������
		InThread(root->leftchild(),pre);
		if(root->leftchild()==NULL)
		{
		//����ǰ������
			root->left=pre;			
			root->lTag=1;
		}
		if((pre)&&(pre->rightchild()==NULL))
		{
		//�����������
			pre->right=root;
			pre->rTag=1;
		}
		pre=root;
		//����������������
		InThread(root->rightchild(),pre);
	}
}

template <class T>
void ThreadBinaryTree<T>::InThread(ThreadBinaryTreeNode<T>* root)//�Գ���������������
//�Գ���������������
{
	//��ʼ��
	using std::stack;
	stack<ThreadBinaryTreeNode<T>*> aStack;
	ThreadBinaryTreeNode<T>* pointer=root;
	ThreadBinaryTreeNode<T>* temppointer=NULL;		//�ݹ�Գ���������������
	//����һ����㣬��Ҫʱ��������
	while(1)
	{
		while(NULL!=pointer)
		{
			aStack.push(pointer);
			pointer=pointer->leftchild();			//�������������½�
		}
		if(aStack.empty())							//ջ�գ��㷨����
			return;
		else
		{
			pointer=aStack.top();
			aStack.pop();
			if(NULL!=temppointer)
			{
				if(NULL==temppointer->right)
				{
					temppointer->rTag=1;
					temppointer->right=pointer;		//ȷ��������
				};
				if(NULL==pointer->left)
				{
					pointer->lTag=1;
					pointer->left=temppointer;		//ȷ������ǰ��
				}
			}
			temppointer=pointer;
			pointer=pointer->rightchild();			//ת���������������
		}
	}
}

template <class T>
void ThreadBinaryTree<T>::InOrder(ThreadBinaryTreeNode<T>* root)//�Գ�������
{
	ThreadBinaryTreeNode<T>* pointer;
	//�Ƿ�Ϊ�ն�����
	if(root==NULL)
		return;
	else pointer=root;
	//�ҡ������¡����
	while(pointer->leftchild()!=NULL)
		pointer=pointer->leftchild();
	//���ʵ�ǰ��㲢�ҳ���ǰ���ĶԳ�����
	while(1)
	{
		AfxMessageBox(pointer->value());			//���ʵ�ǰ���
		if(pointer->rightchild()==NULL)
			return;
		if(pointer->rTag==1)
			pointer=pointer->rightchild();
		else
		{
			pointer=pointer->rightchild();
			while(pointer->lTag==0)
				pointer=pointer->leftchild();
		}
	}
}

template <class T>
ThreadBinaryTreeNode<T>* ThreadBinaryTree<T>::FindNextinInorderTree(ThreadBinaryTreeNode<T>* pointer)		
//�ڶԳ�����������ָ�������ǰ���µĺ��
{
	ThreadBinaryTreeNode<T>* temppointer=NULL;
	if(pointer->lTag==0)
		return pointer->leftchild();
	else
		temppointer=pointer;
	while(temppointer->rTag==1)
		temppointer=temppointer->rightchild();
	temppointer=temppointer->rightchild();
	return temppointer;
}

template <class T>
void ThreadBinaryTree<T>::InsertNode(ThreadBinaryTreeNode<T>*pointer,ThreadBinaryTreeNode<T>* newpointer)
//���Գ������������һ���½��
{
	ThreadBinaryTreeNode<T>* temppointer=NULL;
	//��ָ�����ĶԳ�����
	if(pointer->rightchild()==NULL)
		temppointer=NULL;
	else if(pointer->rTag==1)
			temppointer=pointer->rightchild();
		 else
		 {
			temppointer=pointer->rightchild();
			while(temppointer->lTag==0)
				temppointer=temppointer->leftchild();
		 }
	//temppointerָ��ָ��pointer���ĶԳ�����
	//����ָ�����ĶԳ����̵�������
	if((temppointer!=NULL)&&(temppointer->lTag==1))
		temppointer->left=newpointer;
	//�����½�����ָ���������
	newpointer->rTag=pointer->rTag;
	newpointer->right=pointer->rightchild();
	//�����½��
	pointer->rTag=0;
	pointer->right=newpointer;
	//�����½��������
	newpointer->lTag=1;
	newpointer->left=pointer;
}

#endif // !defined(AFX_THREADBINARYTREE_H__73E5ADE5_F47C_463B_B199_91EE62DE38D6__INCLUDED_)
