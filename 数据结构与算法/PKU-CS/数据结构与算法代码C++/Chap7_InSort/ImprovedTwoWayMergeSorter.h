//优化的两路归并排序类
#include "ImprovedInsertSorter.h"
#define THRESHOLD 16

template <class Record,class Compare>
class ImprovedTwoWayMergeSorter:public Sorter<Record,Compare>
{
private:
	void Merge(Record Array[],Record TempArray[],int left,int right,int middle);	//归并过程
	void DoSort(Record Array[],Record TempArray[],int left, int right);
public:
	void Sort(Record Array[],Record TempArray[],int left, int right);

};


//优化的两路归并排序，Array[]为待排序数组，left，right分别为数组两端
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
	if (right <= left)				// 如果只含有一个元素，直接返回
		return;    
	//如果序列长度小于等于阈值(16最佳)，采用直接插入排序
	if (right-left+1 > THRESHOLD)
	{
		int middle=(left+right)/2;		//从中间划分为两个子序列
		DoSort(Array, TempArray ,left,middle);		//对左边一半进行递归
		DoSort(Array, TempArray ,middle+1,right);		//对右边一半进行递归
		Merge(Array, TempArray ,left,right,middle);		// 进行归并
	}
	else { 
    	ImprovedInsertSorter<Record,Compare> insert_sorter;
		insert_sorter.Sort(&Array[left],right-left+1);
	}
}

//归并过程
template <class Record,class Compare>
void ImprovedTwoWayMergeSorter<Record,Compare>::Merge(Record Array[],Record TempArray[],int left,int right,int middle)
{
	int index1,index2;				//两个子序列的起始位置
	int i,j,k ;
	for (i=left; i<=middle; i++)	//复制左边的子序列
		TempArray[i] = Array[i];
	for (j=1; j<=right-middle; j++)	//复制右边的子序列，但顺序颠倒过来
		TempArray[right-j+1] = Array[j+middle];
	// 开始归并
	for (index1=left,index2=right,k=left; k<=right; k++)
		if (Compare::lt(TempArray[index1], TempArray[index2]))
			Array[k] = TempArray[index1++];
		else Array[k] = TempArray[index2--];
}
