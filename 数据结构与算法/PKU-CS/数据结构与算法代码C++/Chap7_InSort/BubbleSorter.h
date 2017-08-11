//����������
#include "Sorter.h"

template <class Record,class Compare>
class BubbleSorter:public Sorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//��������Array[]Ϊ���������飬nΪ���鳤��
template <class Record,class Compare>
void BubbleSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
	for (int i=1; i<n; i++)				// ��i����¼����
		for (int j=n-1; j>=i; j--)		// ���αȽ����ڼ�¼
			if (Compare ::lt(Array[j], Array[j-1]))	//������ã��ͽ���
				swap(Array, j, j-1);
}
