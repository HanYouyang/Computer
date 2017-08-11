//��·�鲢������
#include "Sorter.h"

template <class Record,class Compare>
class TwoWayMergeSorter:public Sorter<Record,Compare>
{	//��·�鲢������
private:
	void Merge(Record Array[],Record TempArray[],int left,int right,int middle);//�鲢����
public:
	void Sort(Record Array[],Record TempArray[],int left, int right);
};

//��·�鲢����Array[]Ϊ���������飬nΪ���鳤��
template <class Record,class Compare>
void TwoWayMergeSorter<Record,Compare>::Sort(Record Array[],Record TempArray[], int left, int right) 
{ 
	if (left < right)					// ���ֻ����һ��Ԫ�أ�ֱ�ӷ���
	{
		int middle=(left+right)/2;		//���м仮��Ϊ����������
		Sort(Array,TempArray,left,middle);		//�����һ����еݹ�
		Sort(Array,TempArray,middle+1,right);		//���ұ�һ����еݹ�
		Merge(Array,TempArray,left,right,middle);	// ���й鲢
	}

}

//�鲢����
template <class Record,class Compare>
void TwoWayMergeSorter<Record,Compare>::Merge(Record Array[],Record TempArray[],int left,int right,int middle)
{
	for (int j=left; j<=right; j++)   			// �������ݴ�����ʱ����
		TempArray[j] = Array[j];
	int index1=left;		//��������е���ʼλ��
	int index2=middle+1;	//�ұ������е���ʼλ��
	int i=left;				//����ʼ�鲢
	while ((index1 <= middle)&&(index2 <= right))
	{
		//ȡ��С�߲���ϲ�������
		if (Compare::lt(TempArray[index1], TempArray[index2]))
			Array[i++] = TempArray[index1++];
		else
			Array[i++] = TempArray[index2++];
	}
	while (index1 <= middle)
		Array[i++] = TempArray[index1++];
	while (index2 <= right)
		Array[i++] = TempArray[index2++];
}
