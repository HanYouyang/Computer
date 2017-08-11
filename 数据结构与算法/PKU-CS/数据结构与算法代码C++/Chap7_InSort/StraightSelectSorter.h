//ֱ��ѡ��������
#include "Sorter.h"
template <class Record,class Compare>
class StraightSelectSorter:public Sorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//ֱ��ѡ������Array[]Ϊ���������飬nΪ���鳤��
template <class Record,class Compare>
void StraightSelectSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
	for (int i=0; i<n-1; i++)	// ����ѡ����iС�ļ�¼����ʣ���¼����С���Ǹ�
	{
        int Smallest = i;		// ���ȼ����¼i������С��
        for (int j=i+1;j<n; j++)	// ��ʼ���ɨ������ʣ���¼
            if (Compare::lt(Array[j], Array[Smallest]))
      	       Smallest = j;		// ������ָ�С�ļ�¼����¼����λ��
        swap(Array, i, Smallest);	//����iС�ļ�¼���������е�i��λ��
	}
}