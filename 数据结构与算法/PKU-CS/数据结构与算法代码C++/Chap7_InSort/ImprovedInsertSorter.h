//优化的插入排序类
#if !defined(AFX_ImprovedInsertSorter)
#define AFX_ImprovedInsertSorter



#include "InsertSorter.h"
template <class Record,class Compare>
class ImprovedInsertSorter:public InsertSorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//优化的插入排序，Array[]为待排序数组，n为数组长度
template <class Record,class int_intCompare>
void ImprovedInsertSorter<Record,int_intCompare>::Sort(Record Array[], int n) 
{ 
	Record TempRecord;
	// 依次插入第i个记录
	for (int i=1; i<n; i++) 
	{
		TempRecord=Array[i];
		int j = i-1;
		//从i开始往前寻找记录i的正确位置
		while ((j>=0) && (int_intCompare::lt(TempRecord, Array[j])))
		{    
			Array[j+1] = Array[j];	//将那些大于等于记录i的记录后移
			j = j - 1;
		}
		//此时j后面就是记录i的正确位置，回填
		Array[j+1] = TempRecord; 
	}
}

#endif