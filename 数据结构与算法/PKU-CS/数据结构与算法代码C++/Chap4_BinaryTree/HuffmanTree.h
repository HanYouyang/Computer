// HuffmanTree.h: interface for the HuffmanTree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HUFFMANTREE_H__E2FE6C12_C0A9_4483_AF1B_9623F1FD0EF8__INCLUDED_)
#define AFX_HUFFMANTREE_H__E2FE6C12_C0A9_4483_AF1B_9623F1FD0EF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HuffmanTreeNode.h"
#include "MinHeap.h"

template <class T>
class HuffmanTree  
{
private:
	HuffmanTreeNode<T>* root;						//Huffman��������
	//��ht1��ht2Ϊ����Huffman�����ϲ���һ����parentΪ���Ķ�����
	void MergeTree(HuffmanTreeNode<T> &ht1,HuffmanTreeNode<T> &ht2, HuffmanTreeNode<T>* parent);
public:
	//����Huffman����weight�Ǵ洢Ȩֵ�����飬n�����鳤��
	HuffmanTree(T weight[],int n);
	//ɾ��Huffman����������
	void DeleteTree(HuffmanTreeNode<T>* root);
	virtual ~HuffmanTree();							//��������
};

template <class T>
void HuffmanTree<T>::MergeTree(HuffmanTreeNode<T> &ht1,HuffmanTreeNode<T> &ht2, HuffmanTreeNode<T>* parent)
{
	parent->left=&ht1;
	parent->right=&ht2;
	parent->element=ht1.element+ht2.element;
	parent->parent=NULL;
	ht1.parent=ht2.parent=parent;
}

template <class T>
HuffmanTree<T>::HuffmanTree(T weight[],int n)
{
	MinHeap<HuffmanTreeNode<T>> heap(n);			//������Сֵ��
	HuffmanTreeNode<T> *parent,&firstchild,&secondchild;
	HuffmanTreeNode<T>* NodeList=new HuffmanTreeNode<T>[n];
	for(int i=0;i<n;i++)							//��ʼ��
	{
		NodeList[i].element=weight[i];
		NodeList[i].parent=NodeList[i].left=NodeList[i].right=NULL;
		heap.Insert(NodeList[i]);					//��������Ԫ��
	}

	for(i=0;i<n-1;i++)			
	//ͨ��n-1�κϲ�����Huffman��
	{
		parent=new HuffmanTreeNode<T>;
		firstchild=heap.RemoveMin();				//ѡ��Ȩֵ��С�Ľ��
		secondchild=heap.RemoveMin();				//ѡ��Ȩֵ��С�Ľ��
		MergeTree(firstchild,secondchild,parent);	//�ϲ�Ȩֵ��С��������
		heap.Insert(*parent);						//��parent���뵽����ȥ
		root=parent;								//���������
	}
	delete []NodeList;
}

template <class T>
void HuffmanTree<T>::DeleteTree(HuffmanTreeNode<T>* root)
{
	if(root)
	{
		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
	}
}

template <class T>
virtual HuffmanTree<T>::~HuffmanTree()
{
	DeleteTree(root);
}

#endif // !defined(AFX_HUFFMANTREE_H__E2FE6C12_C0A9_4483_AF1B_9623F1FD0EF8__INCLUDED_)
