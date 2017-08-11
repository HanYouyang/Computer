//直接插入排序类
#include "InsertSorter.h"
template <class Record,class Compare>
class StraightInsertSorter:public InsertSorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//直接插入排序，Array[]为待排序数组，n为数组长度
template <class Record,class Compare>
void StraightInsertSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
	// 依次插入第i个记录
	for (int i=1; i<n; i++) 
	{
		//依次与前面的记录进行比较，如果发现比它小的记录，就交换
		for (int j=i;j>0;j--)
		{
			if (Compare::lt(Array[j], Array[j-1]))
				swap(Array, j, j-1);
			else break;		//此时i前面的所有记录(包括i)已排好序		
		}
	}
}
