//��������
#include "Sorter.h"
#include "MaxHeap.h"

template <class Record,class Compare>
class HeapSorter:public Sorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//������Array[]Ϊ���������飬nΪ���鳤��
template <class Record,class Compare>
void HeapSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
//	Record record;
	MaxHeap<Record> max_heap = MaxHeap<Record>(Array,n,n);	//����
	for (int i=0; i<n; i++)		 // �����ҳ�ʣ���¼�е�����¼�����Ѷ�
		max_heap.MoveMax();	
}
