 //������

#include "iostream.h"
#include "stdlib.h"
#include "string.h"
#include "Compare.h"
#include "HeapSorter.h"

// �趨�漴����������
inline void Randomize() 
  { srand(1); }

//����һ��0��n-1֮��������
inline int Random(int n)
  { return rand() % (n); }

void main()
{
	//�����������,����Ϊ100
	int size=1000;
	Randomize();	
	int * sortarray =new int[size];
	for(int i=0;i<size;i++)
		sortarray[i]=Random(32001);
	//ʵ������������
	HeapSorter<int,Compare> sorter;
	//�������ǰ��������
	cout<<"����ǰ��";cout<<endl;
	sorter.PrintArray(sortarray,size);
	//����
	sorter.Sort(sortarray,size);
	//����������������
	cout<<"�����";cout<<endl;
	sorter.PrintArray(sortarray,size);
}