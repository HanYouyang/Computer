//两路归并排序类
#include "Sorter.h"

template <class Record,class Compare>
class TwoWayMergeSorter:public Sorter<Record,Compare>
{	//两路归并排序类
private:
	void Merge(Record Array[],Record TempArray[],int left,int right,int middle);//归并过程
public:
	void Sort(Record Array[],Record TempArray[],int left, int right);
};

//两路归并排序，Array[]为待排序数组，n为数组长度
template <class Record,class Compare>
void TwoWayMergeSorter<Record,Compare>::Sort(Record Array[],Record TempArray[], int left, int right) 
{ 
	if (left < right)					// 如果只含有一个元素，直接返回
	{
		int middle=(left+right)/2;		//从中间划分为两个子序列
		Sort(Array,TempArray,left,middle);		//对左边一半进行递归
		Sort(Array,TempArray,middle+1,right);		//对右边一半进行递归
		Merge(Array,TempArray,left,right,middle);	// 进行归并
	}

}

//归并过程
template <class Record,class Compare>
void TwoWayMergeSorter<Record,Compare>::Merge(Record Array[],Record TempArray[],int left,int right,int middle)
{
	for (int j=left; j<=right; j++)   			// 将数组暂存入临时数组
		TempArray[j] = Array[j];
	int index1=left;		//左边子序列的起始位置
	int index2=middle+1;	//右边子序列的起始位置
	int i=left;				//从左开始归并
	while ((index1 <= middle)&&(index2 <= right))
	{
		//取较小者插入合并数组中
		if (Compare::lt(TempArray[index1], TempArray[index2]))
			Array[i++] = TempArray[index1++];
		else
			Array[i++] = TempArray[index2++];
	}
	while (index1 <= middle)
		Array[i++] = TempArray[index1++];
	while (index2 <= right)
		Array[i++] = TempArray[index2++];
}
