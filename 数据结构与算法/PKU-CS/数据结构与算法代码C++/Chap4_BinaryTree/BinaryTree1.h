// BinaryTree1.h: interface for the BinaryTree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BINARYTREE1_H__99C2FAA0_E42F_4CB0_8B01_C36F1FA6F1EE__INCLUDED_)
#define AFX_BINARYTREE1_H__99C2FAA0_E42F_4CB0_8B01_C36F1FA6F1EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BinaryTreeNode.h"
#include <stack>
#include <queue>

enum Tags{Left,Right};

template <class T>
class StackElement
{
public:
	BinaryTreeNode<T>* pointer;
	Tags tag;
};	

template <class T>
class BinaryTree  
{
protected:
	BinaryTreeNode<T>*  root;      							//�����������ָ��
public:
	BinaryTree(){root=NULL;};								//���캯��
	virtual ~BinaryTree(){DeleteBinaryTree(root);};			//��������
	BOOL isEmpty() const							
	{return ((root)?TRUE:FALSE);};							//�ж��������Ƿ�Ϊ����
	BinaryTreeNode<T>* getRoot(){return root;};
	void Initialize(BinaryTreeNode<T>* pointer){root=pointer;};
	//�Ӷ�������root��㿪ʼ������current���ĸ����
	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T>* root,BinaryTreeNode<T>* current);
	//����current���ĸ����ָ��
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* current);
	//����current�������ֵ�
	BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T>* current);
	//����current�������ֵ�
	BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T>* current);
	//��elem��Ϊ����㣬leftTree��Ϊ������������rightTree��Ϊ����������������һ���µĶ�����
	void CreateTree(const T& elem, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree);
	//ɾ����������������
	void DeleteBinaryTree(BinaryTreeNode<T>* root);				
	//ǰ�������������������
	void PreOrder(BinaryTreeNode<T>* root);
	//���������������������
	void InOrder(BinaryTreeNode<T>* root);
	//���������������������
	void PostOrder(BinaryTreeNode<T>* root);
	//�ǵݹ�ǰ�������������������
	void PreOrderWithoutRecusion(BinaryTreeNode<T>* root);
	//�ǵݹ����������������������
	void InOrderWithoutRecusion(BinaryTreeNode<T>* root);
	//�ǵݹ���������������������
	void PostOrderWithoutRecusion(BinaryTreeNode<T>* root);
	//�ǵݹ���������������������, ��һ���汾
	void PostOrderWithoutRecusion2(BinaryTreeNode<T>* root);
	//����α�����������������
	void LevelOrder(BinaryTreeNode<T>* root);
};

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::GetParent(BinaryTreeNode<T>* root,BinaryTreeNode<T>* current)
{
	//�Ӷ�������root��㿪ʼ������current���ĸ����
	BinaryTreeNode<T>* temp;
	if(root==NULL)
		return NULL;
	//�ҵ������
	if((root->leftchild()==current)||(root->rightchild()==current))
		return root;
	//�ݹ�Ѱ�Ҹ����
	if((temp=GetParent(root->leftchild(),current))!=NULL)
		return temp;
	else return GetParent(root->rightchild(),current);	
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* current)
{//����current���ĸ����ָ��
	if((current==NULL)||(current==root))
		return NULL;					//�ս�����currentΪ�����ʱ������NULL
	return GetParent(root,current);		//���õݹ麯��Ѱ�Ҹ����
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T>* current)
{//����current�������ֵ�
	if(current)											//current��Ϊ��
	{
			BinaryTreeNode<T>* temp=Parent(current);	//����current���ĸ����
			if((temp==NULL)||current==temp->leftchild())
				return  NULL;		    //��������Ϊ�գ�����currentû�����ֵ�
			else return temp->leftchild();
	}
	return NULL;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T>* current)
{//����current�������ֵ�
	if(current)									//current��Ϊ��
	{
			BinaryTreeNode<T>* temp=Parent(current);//����current���ĸ����
			if((temp==NULL)||current==temp->rightchild())
				return  NULL;					//��������Ϊ�գ�����currentû�����ֵ�
			else return temp->rightchild();
	}
	return NULL;
}

template<class T>
void BinaryTree<T>::CreateTree(const T& elem, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree)
{//��elem��Ϊ����㣬leftTree��Ϊ������������rightTree��Ϊ����������������һ���µĶ�����
	root=new BinaryTreeNode<T>(elem,leftTree.root,rightTree.root);  //��������
	leftTree.root=rightTree.root=NULL;								//ԭ�����������ĸ����ָ�գ��������

}

template<class T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T>* root)		//ɾ����������������
{
	if(root)
	{
		DeleteBinaryTree(root->left);
		DeleteBinaryTree(root->right);
		delete root;
	};
};

template<class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T>* root)				//ǰ�������������������
{
	if(root!=NULL)
	{
		AfxMessageBox(root->value());			//���ʵ�ǰ���
		PreOrder(root->leftchild());			//����������
		PreOrder(root->rightchild());			//����������
	}
};

template<class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T>* root)				//���������������������
{
	if(root!=NULL)
	{
		InOrder (root->leftchild());			//����������
		AfxMessageBox(root->value());			//���ʵ�ǰ���
		InOrder (root->rightchild());			//����������
	}
}

template<class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T>* root)				//���������������������
{
	if(root!=NULL)
	{
		PostOrder(root->leftchild());			//����������
		PostOrder (root->rightchild());			//����������
		AfxMessageBox(root->value());			//���ʵ�ǰ���
	}
}

template<class T>
void BinaryTree<T>::PreOrderWithoutRecusion(BinaryTreeNode<T>* root)//�ǵݹ�ǰ�������������������
{
	using std::stack;
	
	stack<BinaryTreeNode<T>* > aStack;
  	BinaryTreeNode<T>* pointer=root;       			//�����������	

	while(!aStack.empty()||pointer)				
	{
	 if(pointer){
		  	  AfxMessageBox(pointer->value());		//���ʵ�ǰ���
			  aStack.push(pointer);					//��ǰ����ַ��ջ
			  pointer=pointer->leftchild();			//��ǰ���ӽṹָ������
		  }
	 else {	        							    //������������ϣ�ת�����������
			  pointer=aStack.top();					//ջ��Ԫ����ջ                 
			  aStack.pop();
			  pointer=pointer->rightchild();		//��ǰ���ӽṹָ���Һ���
		   } //else
   } //while
}

template<class T>
void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T>* root)	//�ǵݹ����������������������
{
	using std::stack;
	stack<BinaryTreeNode<T>* > aStack;
  	BinaryTreeNode<T>* pointer=root;				//�����������	

	while(!aStack.empty()||pointer)				
	{
	 if(pointer){
			  aStack.push(pointer);					//��ǰ����ַ��ջ
			  pointer=pointer->leftchild();			//��ǰ���ӽṹָ������
		  }
	 else {        								    //������������ϣ�ת�����������
			  pointer=aStack.top();				
		  	  AfxMessageBox(pointer->value());		//���ʵ�ǰ���
			  pointer=pointer->rightchild(); 		//��ǰ���ӽṹָ���Һ���
			  aStack.pop();							//ջ��Ԫ����ջ                 
		   } //else
   } //while
}

template<class T>
void BinaryTree<T>::PostOrderWithoutRecusion(BinaryTreeNode<T>* root)//�ǵݹ���������������������
{
	using std::stack;
	StackElement<T> element;
	stack<StackElement<T > > aStack;
	BinaryTreeNode<T>* pointer;
	if(NULL==root)
		return;										//����������
	else pointer=root;
	while(true)
	{
		//����������
		while(pointer!=NULL)
		{
			element.pointer=pointer;
			element.tag=Left;
			aStack.push(element);
			pointer=pointer->leftchild();
		}
		//�г�ջ��Ԫ��
		element=aStack.top();
		aStack.pop();
		pointer=element.pointer;
		//������������
		while(element.tag==Right)
		{
		  	  AfxMessageBox(pointer->value());	//���ʵ�ǰ���
			  if(aStack.empty())
				  return;
			  else
			  {
				element=aStack.top();
				aStack.pop();
				pointer=element.pointer;
			  }
		}
		//������������
		element.tag=Right;
		aStack.push(element);
		pointer=pointer->rightchild();
	}
}

template<class T>
void BinaryTree<T>::PostOrderWithoutRecusion2(BinaryTreeNode<T>* root)
{//�ǵݹ���������������������, ��һ���汾
	using std::stack;
	stack<BinaryTreeNode<T>* > aStack;
	BinaryTreeNode<T> *p, *q;
	if(root==NULL)
		return;
	p=root;
	do{
		while(p!=NULL)							//����·��֧�½�			
		{
			aStack.push(p);
			p=p->leftchild();
		}
		q=NULL;
		while(!aStack.empty())
		{
			p=aStack.top();
			aStack.pop();
			if(p->rightchild()==q)				//������Ϊ�ջ�ոձ����ʹ�
			{
		  	  AfxMessageBox(p->value());	//���ʵ�ǰ���
			  q=p;
			}
			else
			{
				aStack.push(p);
				p=p->rightchild();
				break;
			}
		}
	}while(!aStack.empty());
}

template<class T>
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T>* root)	//����α�����������������
{
	using std::queue;
	queue<BinaryTreeNode<T>*> aQueue;
	BinaryTreeNode<T>* pointer=root;
	
	if(pointer)
		aQueue.push(pointer);
	while(!aQueue.empty())
	{
		pointer=aQueue.front();
        AfxMessageBox(pointer->value());				//���ʵ�ǰ���
		aQueue.pop();
		if(pointer->leftchild())
			aQueue.push(pointer->leftchild());
		if(pointer->rightchild())
			aQueue.push(pointer->rightchild());
	}
}

#endif // !defined(AFX_BINARYTREE1_H__99C2FAA0_E42F_4CB0_8B01_C36F1FA6F1EE__INCLUDED_)
