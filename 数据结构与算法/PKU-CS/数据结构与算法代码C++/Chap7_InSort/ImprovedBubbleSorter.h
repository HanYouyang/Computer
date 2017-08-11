//优化的起泡排序类
#include "Sorter.h"

template <class Record,class Compare>
class ImprovedBubbleSorter:public Sorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//优化的起泡排序，Array[]为待排序数组，n为数组长度
template <class Record,class Compare>
void ImprovedBubbleSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
  bool NoSwap;			// 是否发生了交换的标志
  for (int i=1; i<n; i++)    {
    NoSwap = true;			// 标志初始为假
    for (int j=n-1; j>=i; j--)
      if (Compare::lt(Array[j], Array[j-1])) {
        swap(Array, j, j-1);	//如果发生了交换，标志为真
        NoSwap = false;
      }
    if (NoSwap)  // 如果没发生过交换，表示已排好序，结束算法
      return;
    } 
}