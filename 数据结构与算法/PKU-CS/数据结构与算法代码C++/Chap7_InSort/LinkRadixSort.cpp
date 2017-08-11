//基于静态链的基数排序

#include "iostream.h"
#include "stdlib.h"
#include "string.h"
#include "Node.h"
#include "Compare.h"
#include "LinkRadixSorter.h"

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
	Node* sortarray=new Node[100];
	for(int i=0;i<100;i++)
		sortarray[i].key=Random(100);
	for (i=0; i<100; i++)			// 建链，初始为next域指向下一个记录
		sortarray[i].next = i+1;
	sortarray[99].next = -1;   		//链尾next为空

	//实例化基于静态链的基数排序类
	LinkRadixSorter<Node> sorter;
	cout<<"排序前：";
	cout<<endl;
	sorter.PrintArray(sortarray, 0);			//输出原始序列
	//排序
	int first=sorter.Sort(sortarray,100,2,100);
	cout<<"排序后：";
	cout<<endl;
	sorter.PrintArray(sortarray, first);		//输出排好序后的结果
}