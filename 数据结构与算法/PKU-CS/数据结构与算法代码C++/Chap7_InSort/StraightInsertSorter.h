//ֱ�Ӳ���������
#include "InsertSorter.h"
template <class Record,class Compare>
class StraightInsertSorter:public InsertSorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//ֱ�Ӳ�������Array[]Ϊ���������飬nΪ���鳤��
template <class Record,class Compare>
void StraightInsertSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
	// ���β����i����¼
	for (int i=1; i<n; i++) 
	{
		//������ǰ��ļ�¼���бȽϣ�������ֱ���С�ļ�¼���ͽ���
		for (int j=i;j>0;j--)
		{
			if (Compare::lt(Array[j], Array[j-1]))
				swap(Array, j, j-1);
			else break;		//��ʱiǰ������м�¼(����i)���ź���		
		}
	}
}
