
//Shell������
#include "Sorter.h"

template <class Record,class Compare>
class ShellSorter:public Sorter<Record,Compare>
{
private:
	// ��Ա仯���������޸ĵĲ��������㷨������delta��ʾ��ǰ������
	void ModifiedInsertSort(Record Array[],int n,int delta);
public:
	void Sort(Record Array[],int n);
	void delta3Sort(Record Array[], int n);
};

//Shell����Array[]Ϊ���������飬nΪ���鳤��
template <class Record,class Compare>
void ShellSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
	for (int delta=n/2; delta>0; delta/=2)      //����deltaÿ�γ���2�ݼ�
		for (int j=0; j<delta; j++)       //�ֱ��delta�������н��в�������
			ModifiedInsertSort(&Array[j], n-j, delta);
}

//Shell����Array[]Ϊ���������飬nΪ���鳤��
template <class Record,class int_intCompare>
void ShellSorter<Record,int_intCompare>::delta3Sort(Record Array[], int n) 
{ 
	for (int delta=n/3; delta>=3; delta/=3)      //����deltaÿ�γ���3�ݼ�
		for (int j=0; j<delta; j++)       //�ֱ��delta�������н��в�������
			ModifiedInsertSort(&Array[j],n-j, delta);
	ModifiedInsertSort(Array,n,1);
}

// ��Ա仯���������޸ĵĲ��������㷨������delta��ʾ��ǰ������
template <class Record,class Compare>
void ShellSorter<Record,Compare>::ModifiedInsertSort(Record Array[],int n, int delta) 
{
	for (int i=delta; i<n; i+=delta) // ���������е�i����¼����
		for (int j=i; (j>=delta)&&(Compare::lt(Array[j], Array[j-delta])); j-=delta)
		{
//			if 
				swap(Array, j, j-delta);
//			else break;
		}
}
