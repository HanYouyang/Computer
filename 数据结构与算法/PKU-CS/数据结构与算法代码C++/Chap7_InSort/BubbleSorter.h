//起泡排序类
#include "Sorter.h"

template <class Record,class Compare>
class BubbleSorter:public Sorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//起泡排序，Array[]为待排序数组，n为数组长度
template <class Record,class Compare>
void BubbleSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
	for (int i=1; i<n; i++)				// 第i个记录起泡
		for (int j=n-1; j>=i; j--)		// 依次比较相邻记录
			if (Compare ::lt(Array[j], Array[j-1]))	//如果逆置，就交换
				swap(Array, j, j-1);
}
