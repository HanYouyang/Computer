//�Ż�����·�鲢������
#include "ImprovedInsertSorter.h"
#define THRESHOLD 16

template <class Record,class Compare>
class ImprovedTwoWayMergeSorter:public Sorter<Record,Compare>
{
private:
	void Merge(Record Array[],Record TempArray[],int left,int right,int middle);	//�鲢����
	void DoSort(Record Array[],Record TempArray[],int left, int right);
public:
	void Sort(Record Array[],Record TempArray[],int left, int right);

};


//�Ż�����·�鲢����Array[]Ϊ���������飬left��right�ֱ�Ϊ��������
template <class Record,class Compare>
void ImprovedTwoWayMergeSorter<Record,Compare>::Sort(Record Array[],Record TempArray[], int left, int right) 
{
	DoSort(Array,TempArray,left,right);
//	ImprovedInsertSorter<Record,Compare> insert_sorter;
//	insert_sorter.Sort(&Array[left],right-left+1);
}

template <class Record,class Compare>
void ImprovedTwoWayMergeSorter<Record,Compare>::DoSort(Record Array[],Record TempArray[],int left, int right)
{ 
	if (right <= left)				// ���ֻ����һ��Ԫ�أ�ֱ�ӷ���
		return;    
	//������г���С�ڵ�����ֵ(16���)������ֱ�Ӳ�������
	if (right-left+1 > THRESHOLD)
	{
		int middle=(left+right)/2;		//���м仮��Ϊ����������
		DoSort(Array, TempArray ,left,middle);		//�����һ����еݹ�
		DoSort(Array, TempArray ,middle+1,right);		//���ұ�һ����еݹ�
		Merge(Array, TempArray ,left,right,middle);		// ���й鲢
	}
	else { 
    	ImprovedInsertSorter<Record,Compare> insert_sorter;
		insert_sorter.Sort(&Array[left],right-left+1);
	}
}

//�鲢����
template <class Record,class Compare>
void ImprovedTwoWayMergeSorter<Record,Compare>::Merge(Record Array[],Record TempArray[],int left,int right,int middle)
{
	int index1,index2;				//���������е���ʼλ��
	int i,j,k ;
	for (i=left; i<=middle; i++)	//������ߵ�������
		TempArray[i] = Array[i];
	for (j=1; j<=right-middle; j++)	//�����ұߵ������У���˳��ߵ�����
		TempArray[right-j+1] = Array[j+middle];
	// ��ʼ�鲢
	for (index1=left,index2=right,k=left; k<=right; k++)
		if (Compare::lt(TempArray[index1], TempArray[index2]))
			Array[k] = TempArray[index1++];
		else Array[k] = TempArray[index2--];
}
