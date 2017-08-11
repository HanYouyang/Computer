//二分法插入排序类
#include "InsertSorter.h"

template <class Record,class Compare>
class BinaryInsertSorter:public InsertSorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//二分法插入排序，Array[]为待排序数组，n为数组长度
template <class Record,class Compare>
void BinaryInsertSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
	Record TempRecord;		//用来保存当前待插入纪录的临时变量
	int left,right,middle;  //记录已排好序序列的左、右、中位置
	for (int i=1;i<n;i++)  //插入第i个记录
	{          
		TempRecord = Array[i];	//将当前待插入记录保存在临时变量中
		left = 0; right = i-1;	//记录已排好序序列的左右位置
		while(left <= right)	//开始查找待插入记录的正确位置
		{
			middle = (left+right)/2;		//记录中间位置
			//如果待插入记录比中间记录小，就在左一半中查找，否则，在右一半中查找
			if (Compare::lt(TempRecord, Array[middle]))
				right = middle-1;
			else left = middle+1;
		}
		//将前面所有大于当前待插入记录的记录后移
		for(int j = i-1; j >= left; j --)
			Array[j+1] = Array[j];
			Array[left] = TempRecord;	//将待插入记录回填到正确位置
	}
}	

