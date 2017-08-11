//优化的起泡排序

#include "iostream.h"
#include "stdlib.h"
#include "string.h"
#include "Compare.h"
#include "ImprovedBubbleSorter.h"

// 设定随即函数的种子
inline void Randomize() 
  { srand(1); }

//返回一个0到n-1之间的随机数
inline int Random(int n)
  { return rand() % (n); }

void main()
{
	//产生随机数组,长度为100
	Randomize();	
	int * sortarray =new int[100];
	for(int i=0;i<100;i++)
		sortarray[i]=Random(100);
	//实例化优化的起泡排序类
	ImprovedBubbleSorter<int,Compare> sorter;
	//输出排序前数组内容
	cout<<"排序前：";cout<<endl;
	sorter.PrintArray(sortarray,100);
	//排序
	sorter.Sort(sortarray,100);
	//输出排序后数组内容
	cout<<"排序后：";cout<<endl;
	sorter.PrintArray(sortarray,100);
}