// Tree.h: interface for the Tree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREE_H__703FFCCE_C340_4198_98E7_00F503CF8261__INCLUDED_)
#define AFX_TREE_H__703FFCCE_C340_4198_98E7_00F503CF8261__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TreeNode.h"
#include "DualTagTreeNode.h"
#include "LeftLinkTreeNode.h"
#include <queue>
#include <stack>

template <class T>
class Tree  
{
private:
	TreeNode<T>* root;								//�������
													//����current���ڵ�,��Parent����
	TreeNode<T>* getParent(TreeNode<T>* root,TreeNode<T>* current);
	void DestroyNodes(TreeNode<T>*root);			//ɾ��rootΪ��������

public:
	Tree();											//���캯��
	Tree(DualTagTreeNode<T>* nodeArray,int count);	//���캯��,����˫���λ�ȸ���������
	Tree(LeftLinkTreeNode<T>* nodeArray,int count);	//���캯��,�����������˳������

	virtual ~Tree();								//��������
	TreeNode<T>* getRoot();							//�������еĸ����
	void CreateRoot(const T& rootValue);			//�������ĸ���㣬ʹ�����Ԫ�ص�ֵΪrootValue
	bool isEmpty();									//�ж��Ƿ�Ϊ�����������򷵻�true
	TreeNode<T>* Parent(TreeNode<T>* current);	    //����current���ڵ�
	TreeNode<T>* PrevSibling(TreeNode<T>* current); //����current��ǰһ���ھӽ��
	TreeNode<T>* PrevSibling2(TreeNode<T>* current); //����current��ǰһ���ھӽ��
	void DeleteSubTree(TreeNode<T>* subroot);		//�ͷ���rootΪ�������������н��
	void RootFirstTraverse(TreeNode<T>* root);		//�ȸ��������������
	void RootLastTraverse(TreeNode<T>* root);		//����������������
	void WidthTraverse(TreeNode<T>* root);			//�������������
	void WidthTraverse2(TreeNode<T>* root);			//�������������:�汾2
};

template <class T>
Tree<T>::Tree()
{//���캯��
	root=NULL;
}

template <class T>
Tree<T>::Tree(DualTagTreeNode<T>* nodeArray,int count)
{
	//ʹ��STL�е�stack
	using std::stack;
	stack<TreeNode<T>* > aStack;
	//׼�����������
	TreeNode<T>* pointer=new TreeNode<T>;
	root=pointer;
	//����һ�����
	for(int i=0;i<count-1;i++)
	{
		pointer->setValue(nodeArray[i].info);
		if(nodeArray[i].rtag==0)
			aStack.push(pointer);
		else
			pointer->setSibling(NULL);

		TreeNode<T>* temppointer=new TreeNode<T>;
		if(nodeArray[i].ltag==0)
			pointer->setChild(temppointer);
		else
		{
			pointer->setChild(NULL);
			pointer=aStack.top();
  			aStack.pop();		
			pointer->setSibling(temppointer);
		}
		pointer=temppointer;
	}
	//�������һ�����
	pointer->setValue(nodeArray[count-1].info);
	pointer->setChild(NULL);
	pointer->setSibling(NULL);
}

template <class T>
Tree<T>::Tree(LeftLinkTreeNode<T>* nodeArray,int count)
{//���캯��,�����������˳������
	using std::queue;							//ʹ��STL����
	queue<TreeNode<T>*> aQueue;

	//׼�����������
	TreeNode<T>* pointer=new TreeNode<T>;
	root=pointer;

	int currentIndex=-1;

	while(pointer||!aQueue.empty())
	{
		if(pointer)
		{
			currentIndex++;
			pointer->setValue(nodeArray[currentIndex].info);
			if(nodeArray[currentIndex].llink)
			{
				TreeNode<T>* leftpointer=new TreeNode<T>;				
				pointer->setChild(leftpointer);
				aQueue.push(leftpointer);
			} 
			else pointer->setChild(NULL);

			if(nodeArray[currentIndex].rtag==0)
			{
				TreeNode<T>* rightpointer=new TreeNode<T>;				
				pointer->setSibling(rightpointer);
			}
			else pointer->setSibling(NULL);

			pointer=pointer->RightSibling();//����pointer���ֵ�
		}
		else
		{
			pointer=aQueue.front();
			aQueue.pop();
		}
	}
}

template <class T>
Tree<T>::~Tree()
{//��������
	while(root)
		DeleteSubTree(root);
}

template <class T>
TreeNode<T>* Tree<T>::getRoot()
{//�������еĸ����
		return root;
}

template <class T>
void Tree<T>::CreateRoot(const T& rootValue)
{//�������ĸ���㣬ʹ�����Ԫ�ص�ֵΪrootValue
	if(!root)
		root=new TreeNode<T>(rootValue);
}

template <class T>
bool Tree<T>::isEmpty()
{//�ж��Ƿ�Ϊ�����������򷵻�true
	if(root)
		return false;
	return true;
}

template <class T>
void Tree<T>::RootFirstTraverse(TreeNode<T>* root)
{//�ȸ��������������
	while(NULL!=root)
	{
		AfxMessageBox(root->Value());				//���ʵ�ǰ���
		RootFirstTraverse(root->LeftMostChild());	//����ͷһ��������������
		root=root->RightSibling();					//������������
	}
}

template <class T>
void Tree<T>::RootLastTraverse(TreeNode<T>* root)
{//����������������
	while(NULL!=root)
	{
		RootLastTraverse(root->LeftMostChild());	//����ͷһ��������������
		AfxMessageBox(root->Value());				//���ʵ�ǰ���
		root=root->RightSibling();					//������������
	}
}

template <class T>
void Tree<T>::WidthTraverse(TreeNode<T>* root)
{
	using std::queue;							//ʹ��STL����
	queue<TreeNode<T>*> aQueue;
	TreeNode<T>* pointer=root;
	if(pointer)
	{
		aQueue.push(pointer);
		while(!aQueue.empty())
		{
			pointer=aQueue.front();
			AfxMessageBox(pointer->Value());
			while(pointer->RightSibling())
			{
				if(pointer->LeftMostChild())
					aQueue.push(pointer->LeftMostChild());
				pointer=pointer->RightSibling();
				AfxMessageBox(pointer->Value());
			}
			if(pointer->LeftMostChild())
				aQueue.push(pointer->LeftMostChild());
			aQueue.pop();
		}
	}
}

template <class T>
void Tree<T>::WidthTraverse2(TreeNode<T>* root)
{//�������������:�汾2
	using std::queue;							//ʹ��STL����
	queue<TreeNode<T>*> aQueue;
	TreeNode<T>* pointer=root;
	if(pointer)
	{
		while(NULL!=pointer)
		{
			aQueue.push(pointer);
			pointer=pointer->RightSibling();
		}
		while(!aQueue.empty())
		{
			pointer=aQueue.front();
			aQueue.pop();
			AfxMessageBox(pointer->Value());
			pointer=pointer->LeftMostChild();
			while(pointer)
			{
				aQueue.push(pointer);
				pointer=pointer->RightSibling();
			}
		}
	}
}

template <class T>
TreeNode<T>* Tree<T>::PrevSibling(TreeNode<T>* current)
{//����current��ǰһ���ھӽ��
	using std::queue;								//ʹ��ATL�Ķ���
	queue<TreeNode<T>*> aQueue;
	TreeNode<T>* pointer=root;
	TreeNode<T>* prev=NULL;

	if(pointer)
	{
		aQueue.push(pointer);
		while(!aQueue.empty())
		{
			pointer=aQueue.front();				 	//ȡ�����׽��
			if(pointer==current)
				return prev;
			while(pointer->RightSibling())
			{
				prev=pointer;
				pointer=pointer->pSibling;
				if(pointer==current)
					return prev;
				else 
				{
					if(prev->LeftMostChild())
						aQueue.push(prev->LeftMostChild());
				}
			}
			if(pointer->LeftMostChild())
				aQueue.push(pointer->LeftMostChild());
			aQueue.pop();
			prev=NULL;
		}
			
	}
	return NULL;
}

template <class T>
TreeNode<T>* Tree<T>::PrevSibling2(TreeNode<T>* current)
{//����current��ǰһ���ھӽ��
	using std::queue;								//ʹ��ATL�Ķ���
	queue<TreeNode<T>*> aQueue;
	TreeNode<T>* pointer=root;
	TreeNode<T>* prev=NULL;
	if((NULL==current)||(NULL==pointer)||(current==pointer))
		return NULL;
	while(pointer)
	{
		if(pointer==current)
			return prev;
		aQueue.push(pointer);
		prev=pointer;
		pointer=pointer->pSibling;
	}
	while(!aQueue.empty())
	{
		prev=NULL;
		pointer=aQueue.front();				 	//ȡ�����׽��
		aQueue.pop();
		pointer=pointer->LeftMostChild();
		while(pointer)
		{
			if(pointer==current)
				return prev;
			aQueue.push(pointer);
			prev=pointer;
			pointer=pointer->pSibling;
		}
	}
	return NULL;
}

template <class T>
TreeNode<T>* Tree<T>::getParent(TreeNode<T>* root,TreeNode<T>* current)
{//����current���ڵ�,��Parent����
	TreeNode<T>* temp;
	if(root==NULL)
		return NULL;
	//�ҵ������
	if(root->LeftMostChild()==current)
		return root;
	//�ݹ�Ѱ�Ҹ����
	if((temp=getParent(root->LeftMostChild(),current))!=NULL)
		return temp;
	else return getParent(root->RightSibling(),current);	

}

template <class T>
TreeNode<T>* Tree<T>::Parent(TreeNode<T>* current)
{//����current���ڵ�
	TreeNode<T>* pointer=current;
	if(NULL!=pointer)
	{
		TreeNode<T>* leftmostChild=NULL;
		while((leftmostChild=PrevSibling(pointer))!=NULL)
			pointer=leftmostChild;
		leftmostChild=pointer;
		pointer=root;
		if(leftmostChild==root)
			return NULL;
		else return getParent(pointer,leftmostChild);
	}
}

template <class T>
void Tree<T>::DestroyNodes(TreeNode<T>* root)
{//ɾ��rootΪ���������Ľ��
	if(root)
	{
		DestroyNodes(root->LeftMostChild());		//�ݹ�ɾ��root�������ӽ��Ϊ��������
		DestroyNodes(root->RightSibling());		    //�ݹ�ɾ��root�������ֵܽ��Ϊ��������
		delete root;								//ɾ�������
	}

}

template <class T>
void Tree<T>::DeleteSubTree(TreeNode<T>* subroot)
{//�ͷ���subrootΪ�������������н��
	TreeNode<T>* pointer=PrevSibling(subroot);
	if(NULL==pointer)
	{
		pointer=Parent(subroot);
		if(pointer)
		{
			pointer->pChild=subroot->RightSibling();
			subroot->pSibling=NULL;
		}
		else
		{
			root=subroot->RightSibling();
			subroot->pSibling=NULL;
			
		}
	}
	else
	{
		pointer->pSibling=subroot->RightSibling();
		subroot->pSibling=NULL;
	}
	DestroyNodes(subroot);
}

#endif // !defined(AFX_TREE_H__703FFCCE_C340_4198_98E7_00F503CF8261__INCLUDED_)
