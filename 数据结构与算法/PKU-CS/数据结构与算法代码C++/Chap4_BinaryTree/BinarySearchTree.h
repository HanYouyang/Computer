// BinarySearchTree.h: interface for the BinarySearchTree class.
//
//////////////////////////////////////////////////////////////////////
#include "BinaryTreeNode.h"
#include "BinaryTree1.h"

#if !defined(AFX_BINARYSEARCHTREE_H__1CD2FF9D_73F2_4194_974A_12892DFB325F__INCLUDED_)
#define AFX_BINARYSEARCHTREE_H__1CD2FF9D_73F2_4194_974A_12892DFB325F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T>
class BinarySearchTree:public BinaryTree<T> 
{
public:
	BinarySearchTree(){};
	virtual ~BinarySearchTree(){};
	void InsertNode(BinaryTreeNode<T>* root,BinaryTreeNode<T>* newpointer);
	void DeleteNode(BinaryTreeNode<T>* pointer);
	void DeleteNodeEx(BinaryTreeNode<T>* pointer);
};
template <class T>
void BinarySearchTree<T>::InsertNode(BinaryTreeNode<T>* root,BinaryTreeNode<T>* newpointer)
{
	BinaryTreeNode<T>* pointer=NULL;
	//��ʼ��
	if(NULL==root)
	{
		//��ָ��newpointer��ʼ��������������������ֵʵ��
		Initialize(newpointer);
		return;
	}
	else pointer=root;
	while(1)
	{
		if(newpointer->value()==pointer->value())
			return ;									//������ò���
		else if(newpointer->value()<pointer->value())	//��Ϊ������
		{
			if(pointer->leftchild()==NULL)				
			{
				pointer->left=newpointer;
				return;
			}
			else	pointer=pointer->leftchild();

		}
		else{											//��Ϊ������
			if(pointer->rightchild()==NULL)
			{
				pointer->right=newpointer;
				return;
			}
			else	pointer=pointer->rightchild();
		}
	}
}
template <class T>
void BinarySearchTree<T>::DeleteNode(BinaryTreeNode<T>* pointer)
{//������������ɾ��
	BinaryTreeNode<T>* temppointer=NULL;	
	if(!pointer)
		return;
	BinaryTreeNode<T>* parent=GetParent(root,pointer);
	//��ɾ�������������
	if(NULL==pointer->leftchild())
	{
		//��ɾ������Ǹ������
		if(NULL==parent)
			root=pointer->rightchild();
		else if(parent->leftchild()==pointer)
			parent->left=pointer->rightchild();
		else
			parent->right=pointer->rightchild();
		delete pointer;
		pointer=NULL;
		return;
	}
	else temppointer=pointer->leftchild();
	//�����������ҶԳ�������һ�����
	while(temppointer->rightchild()!=NULL)
		temppointer=temppointer->rightchild();
	//��ɾ��������������Ϊtemppointer��������
	temppointer->right=pointer->rightchild();
	//��ɾ�����������������汻ɾ�����
	if(parent==NULL)
		root=pointer->leftchild();
	else if(parent->leftchild()==pointer)
		parent->left=pointer->leftchild();
	else 
		parent->right=pointer->leftchild();
	delete pointer;
	pointer=NULL;
	return;
}

template <class T>
void BinarySearchTree<T>::DeleteNodeEx(BinaryTreeNode<T>* pointer)
{
	//�����ɾ���ڵ㲻����,����
	if( pointer == NULL )
		return;
	//����Ҫ�滻�����Ľڵ�
	BinaryTreeNode<T> * temppointer;
	//����Ҫ�滻�����Ľڵ�ĸ��ڵ�
	BinaryTreeNode<T> * tempparent = NULL;
	//����Ҫɾ���ڵ�ĸ��ڵ�
	BinaryTreeNode<T> * parent = GetParent(root ,pointer );

	//�����ɾ���ڵ��������Ϊ��,�ͽ���������������������
	if( pointer->leftchild() == NULL )
	{
		//��������������ɾ���ڵ�ĸ��ĺ���λ��
		if( parent == NULL )
			root = pointer->rightchild();
		else if( parent->leftchild() == pointer )
			parent->left = pointer->rightchild();
		else
			parent->right = pointer->rightchild();
		delete pointer;
		pointer=NULL;
		return;
	}

	//����ɾ���ڵ���������Ϊ��,������������Ѱ�����ڵ��滻��ɾ���ڵ�
	temppointer = pointer->leftchild();
	while(temppointer->rightchild() != NULL )
	{
		tempparent = temppointer;
		temppointer = temppointer->rightchild();
	}

	//ɾ���滻���
	if(tempparent==NULL)
		pointer->left=temppointer->leftchild();
	else
		tempparent->right=temppointer->leftchild();

	//���滻���ȥ���������ɾ�����
	if(parent==NULL)
		root=temppointer;
	else if( parent->leftchild() == pointer )
		     parent->left=temppointer;
		 else parent->right=temppointer;

	temppointer->left=pointer->leftchild();
	temppointer->right=pointer->rightchild();

	delete pointer;
	pointer=NULL;
	return;
}

#endif // !defined(AFX_BINARYSEARCHTREE_H__1CD2FF9D_73F2_4194_974A_12892DFB325F__INCLUDED_)
