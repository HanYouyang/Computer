// ParTree.h: interface for the ParTree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARTREE_H__CBF85D1A_1086_4E89_9CB6_BEE7FBE72DD0__INCLUDED_)
#define AFX_PARTREE_H__CBF85D1A_1086_4E89_9CB6_BEE7FBE72DD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParTreeNode.h"

template<class T>
class ParTree  
{
public:
	ParTreeNode<T>* array;							//�洢����������
	int	Size;										//�����С
	ParTreeNode<T>*	Find(ParTreeNode<T>* node)const;//����node���ĸ����
	ParTreeNode<T>*	FindPC(ParTreeNode<T>* node)const;//ѹ��·����������node���ĸ����
	ParTree(const int size);						//���캯��
	virtual ~ParTree();								//��������
	void Union(int i,int j);						//���±�Ϊi��j�Ľ��ϲ�Ϊһ������
	bool Different(int i,int j);					//�ж��±�Ϊi��j�Ľ���Ƿ���һ������
};

template <class T>
ParTree<T>::ParTree(const int size)
{
	Size=size;
	array=new ParTreeNode<T>[size];
}

template <class T>
ParTree<T>::~ParTree()
{
	delete []array;
}

template <class T>
ParTreeNode<T>*	ParTree<T>::Find(ParTreeNode<T>* node) const
{
	ParTreeNode<T>* pointer=node;
	while(pointer->getParent()!=NULL)
		pointer=pointer->getParent();
	return pointer;
}

template <class T>
ParTreeNode<T>*	ParTree<T>::FindPC(ParTreeNode<T>* node) const
{
	if(node->getParent()==NULL)
		return node;
	node->setParent(FindPC(node->getParent()));
	return node->getParent();
}

template<class T>
bool ParTree<T>::Different(int i,int j)
{
	ParTreeNode<T>* pointeri=Find(&array[i]);		//�ҵ����i�ĸ�
	ParTreeNode<T>* pointerj=Find(&array[j]);		//�ҵ����j�ĸ�
	return pointeri!=pointerj;
}

template<class T>
void ParTree<T>::Union(int i,int j)
{
	ParTreeNode<T>* pointeri=Find(&array[i]);		//�ҵ����i�ĸ�
	ParTreeNode<T>* pointerj=Find(&array[j]);		//�ҵ����j�ĸ�
	if(pointeri!=pointerj)
	{
		if(pointeri->getCount()>=pointerj->getCount())
		{
			pointerj->setParent(pointeri);
			pointeri->setCount(pointeri->getCount()+pointerj->getCount());
		}
		else
		{
			pointeri->setParent(pointerj);
			pointerj->setCount(pointeri->getCount()+pointerj->getCount());
		}
	}

}


#endif // !defined(AFX_PARTREE_H__CBF85D1A_1086_4E89_9CB6_BEE7FBE72DD0__INCLUDED_)
