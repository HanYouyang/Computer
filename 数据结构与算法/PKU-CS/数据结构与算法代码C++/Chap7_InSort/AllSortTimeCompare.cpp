// 各种排序算法的实验比较
//计算不同初始状态与排序规模下的各种排序算法的运行时间

#include "time.h"
#include "iostream.h"
#include "stdlib.h"
#include "string.h"
#include "Compare.h"
#include "Node.h"
#include "StraightInsertSorter.h"
#include "ImprovedInsertSorter.h"
#include "BinaryInsertSorter.h"
#include "BubbleSorter.h"
#include "ImprovedBubbleSorter.h"
#include "StraightSelectSorter.h"
#include "ShellSorter.h"
#include "HeapSorter.h"
#include "QuickSorter.h"
#include "ImprovedQuickSorter.h"
#include "TwoWayMergeSorter.h"
#include "ImprovedTwoWayMergeSorter.h"
#include "BucketSorter.h"
#include "RadixSorter.h"
#include "LinkRadixSorter.h"


char a[3][10]={"随机","正序","逆序"};

// 设定随即函数的种子
inline void Randomize() 
  { srand(1); }

//返回一个0到n-1之间的随机数
inline int Random(int n)
  { return rand() % (n); }

// Timing variables and functions
clock_t tstart = 0;  // Time at beginning of timed section

// Initialize the program timer
void Settime()
  { tstart = clock(); }

// Return the elapsed time since the last call to Settime
double Gettime()
  { return (double)((double)clock() - (double)tstart)/
           (double)CLOCKS_PER_SEC; }

inline void swap(int * array, int x, int y)	//交换位置x和y的元素
{
	int temp=array[x];
	array[x]=array[y];
	array[y]=temp;
}
void main()
{
	int numofsort;	//输入规模：10, 100 ,1000 ,10000 ,100000 ,1000000 
	int wayofsort;	//排序算法的序号
	int flag;		//初始数组顺序：正序、逆序、随机顺序,其中正序和逆序分别为已排序及逆排序
	while(1)
	{
		Randomize();	
		cout<<endl;			
		cout<<"  直接插入排序                   1   优化的插入排序                    2"<<endl;
		cout<<"  二分法插入排序                 3   起泡排序                           4"<<endl;
		cout<<"  优化的起泡排序                 5   直接选择排序                       6"<<endl;
		cout<<"  Shell 排序/2                   7   Shell 排序/3                       8"<<endl;
		cout<<"  快速排序                       9   优化的快速排序                    10"<<endl;
		cout<<"  两路归并排序                  11   优化的两路归并排序                12"<<endl;
		cout<<"  堆排序                        13   基数排序/2                        14"<<endl;
		cout<<"  基数排序/4                    15   基数排序/8                        16"<<endl;
		cout<<"  基数排序(队列实现)/2          17   基数排序(队列实现)/4              18"<<endl;
		cout<<"  基数排序(队列实现)/8          19   计算所有排序时间                  20"<<endl;
		cout<<endl;

		cout<<"请输入排序算法的序号(0-退出):";
		cin>>wayofsort;
		if(wayofsort==0) exit(1);
		cout<<"请输入数组规模:";
		cin>>numofsort;
		if(numofsort>1000000)
		{
			cout<<"sorry,数据规模太大!";
			exit(1);
		}
		cout<<"请输入初始状态(随机0 正序1 逆序2):";
		cin>>flag;
		int allflag=0;
		wayofsort--;
		if(wayofsort==19)
		{
			wayofsort=0;
			allflag=1;
		}
begin:
		wayofsort++;
		int *sortarray =new int[1000000];
		int *temparray =new int[1000000];
		//产生随机数组,长度为1000000
		Randomize();	
		for(int i=0;i<1000000;i++)
		sortarray[i]=Random(32003);
		//产生正序、逆序数组
		if(flag==1||flag==2)
		{
			//实例化快速排序类
			ImprovedQuickSorter<int,Compare> sorter;
			sorter.Sort(sortarray,0,1000000-1);
			if(flag==2)
			{
				for(int i=0;i<1000000/2;i++)
					swap(sortarray,i,999999-i);
			}
		}
		//开始排序
		switch(wayofsort)
		{
		case 1:
			{	//直接插入排序
				//实例化直接插入排序类
				StraightInsertSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"直接插入排序"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 2:
			{	//改进的插入排序
				//实例化优化的插入排序类
				ImprovedInsertSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"改进的插入排序"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 3:
			{	//二分法插入排序
				//实例化二分法插入排序类
				BinaryInsertSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"二分法插入排序"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 4:
			{	//起泡排序
				//实例化起泡排序类
				BubbleSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"起泡排序"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 5:
			{	//改进的起泡排序
				//实例化优化的起泡排序类
				ImprovedBubbleSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"改进的起泡排序"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 6:
			{	//直接选择排序
				//实例化直接选择排序类
				StraightSelectSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"直接选择排序"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 7:
			{//Shell 排序/2
				//实例化Shell排序类
				ShellSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"Shell 排序/2"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 8:
			{//Shell 排序/3
				//实例化Shell排序类
				ShellSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.delta3Sort(sortarray+numofsort*i,numofsort);
				cout<<"Shell 排序/3"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 9:
			{	//快速排序
				//实例化快速排序类
				QuickSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray,0+numofsort*i,numofsort-1+numofsort*i);
				cout<<"快速排序"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 10:
			{	//优化的快速排序
				//实例化优化的快速排序类
				ImprovedQuickSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray,0+numofsort*i,numofsort-1+numofsort*i);
				cout<<"优化的快速排序"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 11:
			{	//两路归并排序
				//实例化两路归并排序类
				TwoWayMergeSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray,temparray,0+numofsort*i,numofsort-1+numofsort*i);
				cout<<"两路归并排序"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 12:
			{	//优化的两路归并排序
				//实例化优化的两路归并排序类
				ImprovedTwoWayMergeSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray,temparray,0+numofsort*i,numofsort-1+numofsort*i);
				cout<<"优化的两路归并排序"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 13:
			{	//堆排序
				//实例化堆排序类
				HeapSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"堆排序"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 14:
			{	//基数排序/2
				//实例化基数排序类
				RadixSorter<int> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort,16,2);
				cout<<"基数排序/2"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 15:
			{	//基数排序/4
				//实例化基数排序类
				RadixSorter<int> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort,8,4);
				cout<<"基数排序/4"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 16:
			{	//基数排序/8
				//实例化基数排序类
				RadixSorter<int> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
				{
				sorter.Sort(sortarray+numofsort*i,numofsort,5,8);
				}
				cout<<"基数排序/8"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 17:
			{	//基数排序(队列实现)/2
				Node* sortarray1=new Node[1000000];
				for(int ii=0;ii<1000000;ii++)
					sortarray1[ii].key=sortarray[ii];

				//实例化基于静态链的基数排序类
				LinkRadixSorter<Node> sorter;

				Settime();
				for(int i=0;i<1000000/numofsort;i++)
				{
				sorter.Sort(sortarray1+numofsort*i,numofsort,16,2);
				}
				cout<<"基数排序(队列实现)/2"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				delete[] sortarray1;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 18:
			{	//基数排序(队列实现)/4
				Node* sortarray1=new Node[1000000];
				for(int ii=0;ii<1000000;ii++)
					sortarray1[ii].key=sortarray[ii];

				//实例化基于静态链的基数排序类
				LinkRadixSorter<Node> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
				{
				sorter.Sort(sortarray1+numofsort*i,numofsort,8,4);
				}
				cout<<"基数排序(队列实现)/4"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				delete[] sortarray1;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 19:
			{	//基数排序(队列实现)/8
				Node* sortarray1=new Node[1000000];
				for(int ii=0;ii<1000000;ii++)
					sortarray1[ii].key=sortarray[ii];

				//实例化基于静态链的基数排序类
				LinkRadixSorter<Node> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
				{
				sorter.Sort(sortarray1+numofsort*i,numofsort,5,8);
				}
				cout<<"基数排序(队列实现)/8"<<endl
					<<"排序规模:"<<numofsort<<endl<<"初始状态："<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				delete[] sortarray1;
				if(allflag==1)  
					goto begin;
				break;
			}
			
		}

	}//end while
}
