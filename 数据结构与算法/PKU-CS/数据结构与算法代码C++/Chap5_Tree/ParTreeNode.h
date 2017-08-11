// ParTreeNode.h: interface for the ParTreeNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARTREENODE_H__3A24E23B_0E76_4DF3_9EC1_75461437404A__INCLUDED_)
#define AFX_PARTREENODE_H__3A24E23B_0E76_4DF3_9EC1_75461437404A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template<class T>
class ParTreeNode  
{
private:
	T				value;							//����ֵ
	ParTreeNode<T>* parent;							//�����ָ��
	int		nCount;									//�Դ˽��Ϊ�����������ܽ�����
public:
	ParTreeNode();									//���캯��
	virtual ~ParTreeNode(){};						//��������
	T	getValue();									//���ؽ���ֵ
	void  setValue(const T& val);					//���ý���ֵ
	ParTreeNode<T>*  getParent();					//���ظ����ָ��
	void  setParent(ParTreeNode<T>* par);			//���ø����ָ��
	int  getCount();								//���ؽ����Ŀ
	void  setCount(const int count);				//���ý����Ŀ
};

template<class T>
ParTreeNode<T>::ParTreeNode()
{
	parent=NULL;
	nCount=1;
}
template<class T>
T ParTreeNode<T>::getValue()
{
	return value;
}
template<class T>
void ParTreeNode<T>::setValue(const T& val)
{
	value=val;
}
template<class T>
ParTreeNode<T>* ParTreeNode<T>::getParent()
{
	return parent;
}
template<class T>
void ParTreeNode<T>::setParent(ParTreeNode<T>* par)
{
	parent=par;
}
template<class T>
int ParTreeNode<T>::getCount()
{
	return nCount;
}
template<class T>
void ParTreeNode<T>::setCount(const int count)
{
	nCount=count;
}


#endif // !defined(AFX_PARTREENODE_H__3A24E23B_0E76_4DF3_9EC1_75461437404A__INCLUDED_)
