//基数排序类
#include "Sorter.h"

template <class Record>
class RadixSorter:public Sorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n,int min,int max);
};

//数组实现的基数排序，n为数组长度，d为排序码个数，r为基数
template <class Record>
void RadixSorter<Record>::Sort(Record Array[], int n,int d, int r) 
{ 
	Record *TempArray =new Record[n];	//辅助排序的临时数组
	int* count= new int[r];				//计数器，Count[i] 存储了第i个桶中的记录数
	int i,j,k;
	int Radix=1;							//用来取Array[j]的第i位排序码
	for (i=1; i<=d; i++)				// 分别对第i个排序码进行分配
	{
		for (j=0; j<r; j++)				// 初始计数器均为0
			count[j] = 0;    
		 for (j=0; j<n; j++)			// 统计每个桶中的记录数
		 {
			k=(Array[j] /Radix)%r;		//取Array[j]的第i位排序码
			count[k]++;					//相应计数器加1
		 }
    
		for (j=1; j<r; j++)				// 将TempArray中的位置依次分配给r个桶
			count[j] = count[j-1] + count[j];
		for (j=n-1; j>=0; j--)			// 将所有桶中的记录依次收集到TempArray中 
		{
			k=(Array[j] /Radix)%r;		//取Array[j]的第i位排序码
			count[k]--;					//从第k个桶中取出一个记录，计数器减1
			TempArray[count[k]] = Array[j];
		}
		for (j=0; j<n; j++)				// 将临时数组中的内容复制到Array中
			Array[j] = TempArray[j];         
		Radix*=r;
	}
}
