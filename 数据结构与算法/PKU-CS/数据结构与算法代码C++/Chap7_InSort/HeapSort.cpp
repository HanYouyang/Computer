 //堆排序

#include "iostream.h"
#include "stdlib.h"
#include "string.h"
#include "Compare.h"
#include "HeapSorter.h"

// 设定随即函数的种子
inline void Randomize() 
  { srand(1); }

//返回一个0到n-1之间的随机数
inline int Random(int n)
  { return rand() % (n); }

void main()
{
	//产生随机数组,长度为100
	int size=1000;
	Randomize();	
	int * sortarray =new int[size];
	for(int i=0;i<size;i++)
		sortarray[i]=Random(32001);
	//实例化堆排序类
	HeapSorter<int,Compare> sorter;
	//输出排序前数组内容
	cout<<"排序前：";cout<<endl;
	sorter.PrintArray(sortarray,size);
	//排序
	sorter.Sort(sortarray,size);
	//输出排序后数组内容
	cout<<"排序后：";cout<<endl;
	sorter.PrintArray(sortarray,size);
}