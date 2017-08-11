//���ھ�̬���Ļ�������

#include "iostream.h"
#include "stdlib.h"
#include "string.h"
#include "Node.h"
#include "Compare.h"
#include "LinkRadixSorter.h"

// �趨�漴����������
inline void Randomize() 
  { srand(1); }

//����һ��0��n-1֮��������
inline int Random(int n)
  { return rand() % (n); }

void main()
{
	//�����������,����Ϊ100
	Randomize();	
	Node* sortarray=new Node[100];
	for(int i=0;i<100;i++)
		sortarray[i].key=Random(100);
	for (i=0; i<100; i++)			// ��������ʼΪnext��ָ����һ����¼
		sortarray[i].next = i+1;
	sortarray[99].next = -1;   		//��βnextΪ��

	//ʵ�������ھ�̬���Ļ���������
	LinkRadixSorter<Node> sorter;
	cout<<"����ǰ��";
	cout<<endl;
	sorter.PrintArray(sortarray, 0);			//���ԭʼ����
	//����
	int first=sorter.Sort(sortarray,100,2,100);
	cout<<"�����";
	cout<<endl;
	sorter.PrintArray(sortarray, first);		//����ź����Ľ��
}