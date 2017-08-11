//桶式排序类
#include "Sorter.h"

template <class Record>
class BucketSorter:public Sorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n,int max);
};

//桶式排序，Array[]为待排序数组，数组长度为n,所有记录都位于区间[0,max)上
template <class Record>
void BucketSorter<Record>::Sort(Record Array[], int n,int max) 
{ 
  int* TempArray=new Record[n];	//临时数组
  int* count=new int[max];	//小于或等于i的元素个数
  int i;

  for (i=0;i<n;i++)
  	TempArray[i]=Array[i];
  //所有计数器初始都为0
  for (i=0;i<max;i++)
  	count[i]=0;
  //统计每个取值出现的次数
  for (i=0;i<n;i++)
	count[Array[i]]++;
  //统计小于等于i的元素个数
  for (i=1;i<max;i++)
  	count[i]=count[i-1]+count [i];
  
  //按顺序输出有序序列
  for (i=n-1;i>0;i--)
     Array[--count[TempArray[i]]] = TempArray[i];
}
