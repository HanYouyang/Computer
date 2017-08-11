// ���������㷨��ʵ��Ƚ�
//���㲻ͬ��ʼ״̬�������ģ�µĸ��������㷨������ʱ��

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


char a[3][10]={"���","����","����"};

// �趨�漴����������
inline void Randomize() 
  { srand(1); }

//����һ��0��n-1֮��������
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

inline void swap(int * array, int x, int y)	//����λ��x��y��Ԫ��
{
	int temp=array[x];
	array[x]=array[y];
	array[y]=temp;
}
void main()
{
	int numofsort;	//�����ģ��10, 100 ,1000 ,10000 ,100000 ,1000000 
	int wayofsort;	//�����㷨�����
	int flag;		//��ʼ����˳�������������˳��,�������������ֱ�Ϊ������������
	while(1)
	{
		Randomize();	
		cout<<endl;			
		cout<<"  ֱ�Ӳ�������                   1   �Ż��Ĳ�������                    2"<<endl;
		cout<<"  ���ַ���������                 3   ��������                           4"<<endl;
		cout<<"  �Ż�����������                 5   ֱ��ѡ������                       6"<<endl;
		cout<<"  Shell ����/2                   7   Shell ����/3                       8"<<endl;
		cout<<"  ��������                       9   �Ż��Ŀ�������                    10"<<endl;
		cout<<"  ��·�鲢����                  11   �Ż�����·�鲢����                12"<<endl;
		cout<<"  ������                        13   ��������/2                        14"<<endl;
		cout<<"  ��������/4                    15   ��������/8                        16"<<endl;
		cout<<"  ��������(����ʵ��)/2          17   ��������(����ʵ��)/4              18"<<endl;
		cout<<"  ��������(����ʵ��)/8          19   ������������ʱ��                  20"<<endl;
		cout<<endl;

		cout<<"�����������㷨�����(0-�˳�):";
		cin>>wayofsort;
		if(wayofsort==0) exit(1);
		cout<<"�����������ģ:";
		cin>>numofsort;
		if(numofsort>1000000)
		{
			cout<<"sorry,���ݹ�ģ̫��!";
			exit(1);
		}
		cout<<"�������ʼ״̬(���0 ����1 ����2):";
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
		//�����������,����Ϊ1000000
		Randomize();	
		for(int i=0;i<1000000;i++)
		sortarray[i]=Random(32003);
		//����������������
		if(flag==1||flag==2)
		{
			//ʵ��������������
			ImprovedQuickSorter<int,Compare> sorter;
			sorter.Sort(sortarray,0,1000000-1);
			if(flag==2)
			{
				for(int i=0;i<1000000/2;i++)
					swap(sortarray,i,999999-i);
			}
		}
		//��ʼ����
		switch(wayofsort)
		{
		case 1:
			{	//ֱ�Ӳ�������
				//ʵ����ֱ�Ӳ���������
				StraightInsertSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"ֱ�Ӳ�������"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 2:
			{	//�Ľ��Ĳ�������
				//ʵ�����Ż��Ĳ���������
				ImprovedInsertSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"�Ľ��Ĳ�������"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 3:
			{	//���ַ���������
				//ʵ�������ַ�����������
				BinaryInsertSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"���ַ���������"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 4:
			{	//��������
				//ʵ��������������
				BubbleSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"��������"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 5:
			{	//�Ľ�����������
				//ʵ�����Ż�������������
				ImprovedBubbleSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"�Ľ�����������"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 6:
			{	//ֱ��ѡ������
				//ʵ����ֱ��ѡ��������
				StraightSelectSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"ֱ��ѡ������"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 7:
			{//Shell ����/2
				//ʵ����Shell������
				ShellSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"Shell ����/2"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 8:
			{//Shell ����/3
				//ʵ����Shell������
				ShellSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.delta3Sort(sortarray+numofsort*i,numofsort);
				cout<<"Shell ����/3"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 9:
			{	//��������
				//ʵ��������������
				QuickSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray,0+numofsort*i,numofsort-1+numofsort*i);
				cout<<"��������"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 10:
			{	//�Ż��Ŀ�������
				//ʵ�����Ż��Ŀ���������
				ImprovedQuickSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray,0+numofsort*i,numofsort-1+numofsort*i);
				cout<<"�Ż��Ŀ�������"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 11:
			{	//��·�鲢����
				//ʵ������·�鲢������
				TwoWayMergeSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray,temparray,0+numofsort*i,numofsort-1+numofsort*i);
				cout<<"��·�鲢����"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 12:
			{	//�Ż�����·�鲢����
				//ʵ�����Ż�����·�鲢������
				ImprovedTwoWayMergeSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray,temparray,0+numofsort*i,numofsort-1+numofsort*i);
				cout<<"�Ż�����·�鲢����"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 13:
			{	//������
				//ʵ������������
				HeapSorter<int,Compare> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort);
				cout<<"������"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 14:
			{	//��������/2
				//ʵ��������������
				RadixSorter<int> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort,16,2);
				cout<<"��������/2"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 15:
			{	//��������/4
				//ʵ��������������
				RadixSorter<int> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
					sorter.Sort(sortarray+numofsort*i,numofsort,8,4);
				cout<<"��������/4"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 16:
			{	//��������/8
				//ʵ��������������
				RadixSorter<int> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
				{
				sorter.Sort(sortarray+numofsort*i,numofsort,5,8);
				}
				cout<<"��������/8"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 17:
			{	//��������(����ʵ��)/2
				Node* sortarray1=new Node[1000000];
				for(int ii=0;ii<1000000;ii++)
					sortarray1[ii].key=sortarray[ii];

				//ʵ�������ھ�̬���Ļ���������
				LinkRadixSorter<Node> sorter;

				Settime();
				for(int i=0;i<1000000/numofsort;i++)
				{
				sorter.Sort(sortarray1+numofsort*i,numofsort,16,2);
				}
				cout<<"��������(����ʵ��)/2"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				delete[] sortarray1;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 18:
			{	//��������(����ʵ��)/4
				Node* sortarray1=new Node[1000000];
				for(int ii=0;ii<1000000;ii++)
					sortarray1[ii].key=sortarray[ii];

				//ʵ�������ھ�̬���Ļ���������
				LinkRadixSorter<Node> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
				{
				sorter.Sort(sortarray1+numofsort*i,numofsort,8,4);
				}
				cout<<"��������(����ʵ��)/4"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
					<<Gettime()/1000000*numofsort<<"seconds"<<endl;
				delete[] sortarray;
				delete[] sortarray1;
				if(allflag==1)  
					goto begin;
				break;
			}
		case 19:
			{	//��������(����ʵ��)/8
				Node* sortarray1=new Node[1000000];
				for(int ii=0;ii<1000000;ii++)
					sortarray1[ii].key=sortarray[ii];

				//ʵ�������ھ�̬���Ļ���������
				LinkRadixSorter<Node> sorter;
				Settime();
				for(int i=0;i<1000000/numofsort;i++)
				{
				sorter.Sort(sortarray1+numofsort*i,numofsort,5,8);
				}
				cout<<"��������(����ʵ��)/8"<<endl
					<<"�����ģ:"<<numofsort<<endl<<"��ʼ״̬��"<<a[flag]<<endl
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
