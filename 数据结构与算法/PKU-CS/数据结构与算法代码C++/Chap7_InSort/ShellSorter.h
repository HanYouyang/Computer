
//Shell排序类
#include "Sorter.h"

template <class Record,class Compare>
class ShellSorter:public Sorter<Record,Compare>
{
private:
	// 针对变化的增量而修改的插入排序算法，参数delta表示当前的增量
	void ModifiedInsertSort(Record Array[],int n,int delta);
public:
	void Sort(Record Array[],int n);
	void delta3Sort(Record Array[], int n);
};

//Shell排序，Array[]为待排序数组，n为数组长度
template <class Record,class Compare>
void ShellSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
	for (int delta=n/2; delta>0; delta/=2)      //增量delta每次除以2递减
		for (int j=0; j<delta; j++)       //分别对delta个子序列进行插入排序
			ModifiedInsertSort(&Array[j], n-j, delta);
}

//Shell排序，Array[]为待排序数组，n为数组长度
template <class Record,class int_intCompare>
void ShellSorter<Record,int_intCompare>::delta3Sort(Record Array[], int n) 
{ 
	for (int delta=n/3; delta>=3; delta/=3)      //增量delta每次除以3递减
		for (int j=0; j<delta; j++)       //分别对delta个子序列进行插入排序
			ModifiedInsertSort(&Array[j],n-j, delta);
	ModifiedInsertSort(Array,n,1);
}

// 针对变化的增量而修改的插入排序算法，参数delta表示当前的增量
template <class Record,class Compare>
void ShellSorter<Record,Compare>::ModifiedInsertSort(Record Array[],int n, int delta) 
{
	for (int i=delta; i<n; i+=delta) // 对子序列中第i个记录排序
		for (int j=i; (j>=delta)&&(Compare::lt(Array[j], Array[j-delta])); j-=delta)
		{
//			if 
				swap(Array, j, j-delta);
//			else break;
		}
}
