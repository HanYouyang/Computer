// MinHeap.h: interface for the MinHeap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MINHEAP_H__6BC12E9A_B926_47C2_8ACF_AA4004A0546F__INCLUDED_)
#define AFX_MINHEAP_H__6BC12E9A_B926_47C2_8ACF_AA4004A0546F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T>
class MinHeap  
{
private:
	T* heapArray;
	int CurrentSize;
	int MaxSize;
public:
	MinHeap(const int n);
	virtual ~MinHeap()
	{delete []heapArray;};
	void BuildHeap();
	bool isLeaf(int pos) const;
	int leftchild(int pos) const;
	int rightchild(int pos) const;
	// Return parent position
	int parent(int pos) const;
	// ɾ�������±��Ԫ��
	bool Remove(int pos, T& node);
	void SiftDown(int left);
	//��position���Ͽ�ʼ������ʹ���г�Ϊ��
	void SiftUp(int position); 
	BOOL Insert(const T& newNode);
	T& RemoveMin();
};

template<class T>
MinHeap<T>::MinHeap(const int n)
{
	if(n<=0)
		return;
	CurrentSize=0;
	MaxSize=n;
	heapArray=new T[MaxSize];
	BuildHeap();
}

template<class T>
void MinHeap<T>::BuildHeap()
{
	for (int i=CurrentSize/2-1; i>=0; i--) 
		SiftDown(i); 
}

template<class T>
bool MinHeap<T>::isLeaf(int pos) const
{
		return (pos>=CurrentSize/2)&&(pos<CurrentSize);
}

template<class T>
int MinHeap<T>::leftchild(int pos) const
{
	return 2*pos+1;						//��������λ��
}

template<class T>
int MinHeap<T>::rightchild(int pos) const
{
	return 2*pos+2;						//�����Һ���λ��
}

template<class T>
int MinHeap<T>::parent(int pos) const	// ���ظ��ڵ�λ��
{
	return (pos-1)/2;
}

template<class T>
void MinHeap<T>::SiftDown(int left)
{
	//׼��
	int i=left;							//��ʶ�����
	int j=2*i+1;						//��ʶ�ؼ�ֵ��С���ӽ��		
	T	temp=heapArray[i];				//���游���
	//��ɸ
	while(j<CurrentSize)
	{
		if((j<CurrentSize-1)&&(heapArray[j]>heapArray[j+1]))
			j++;						//jָ�����ӽ��
		if(temp>heapArray[j])
		{
			heapArray[i]=heapArray[j];
			i=j;
			j=2*j+1;
		}
		else break;
	}
	heapArray[i]=temp;
}

template<class T>
void MinHeap<T>::SiftUp(int position) 
{//��position���Ͽ�ʼ������ʹ���г�Ϊ��
	int temppos=position;
	T temp=heapArray[temppos];
	while((temppos>0)&&(heapArray[parent(temppos)]>temp))
	{
		heapArray[temppos]=heapArray[parent(temppos)];
		temppos=parent(temppos);
	}
	heapArray[temppos]=temp;
}

template<class T>
BOOL MinHeap<T>::Insert(const T& newNode)
{//����в���һ�����
	if(CurrentSize==MaxSize)
		return FALSE;
	heapArray[CurrentSize]=newNode;
	SiftUp(CurrentSize);
	CurrentSize++;
}

template<class T>
T& MinHeap<T>::RemoveMin()
{
	if(CurrentSize==0)
	{
		AfxMessageBox("Can't Delete");

	}
	else
	{
		T temp=heapArray[0];					//ȡ�Ѷ�Ԫ��
		heapArray[0]=heapArray[CurrentSize-1];	//��ĩԪ���������Ѷ�
		CurrentSize--;
		if(CurrentSize>1)
			SiftDown(0);						//�ӶѶ���ʼɸѡ
		return temp;
	}
}

template<class T>
bool MinHeap<T>::Remove(int pos, T& node)
{// ɾ�������±��Ԫ��
	if((pos<0)||(pos>=CurrentSize))
		return false;
	T temp=heapArray[pos];
	heapArray[pos]=heapArray[--CurrentSize];	//ָ��Ԫ���������
	SiftUp(pos);								//����ɸ
	SiftDown(pos);								//����ɸ	
	node=temp;
	return true;
}

#endif // !defined(AFX_MINHEAP_H__6BC12E9A_B926_47C2_8ACF_AA4004A0546F__INCLUDED_)
