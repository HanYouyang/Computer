//���ַ�����������
#include "InsertSorter.h"

template <class Record,class Compare>
class BinaryInsertSorter:public InsertSorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//���ַ���������Array[]Ϊ���������飬nΪ���鳤��
template <class Record,class Compare>
void BinaryInsertSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
	Record TempRecord;		//�������浱ǰ�������¼����ʱ����
	int left,right,middle;  //��¼���ź������е����ҡ���λ��
	for (int i=1;i<n;i++)  //�����i����¼
	{          
		TempRecord = Array[i];	//����ǰ�������¼��������ʱ������
		left = 0; right = i-1;	//��¼���ź������е�����λ��
		while(left <= right)	//��ʼ���Ҵ������¼����ȷλ��
		{
			middle = (left+right)/2;		//��¼�м�λ��
			//����������¼���м��¼С��������һ���в��ң���������һ���в���
			if (Compare::lt(TempRecord, Array[middle]))
				right = middle-1;
			else left = middle+1;
		}
		//��ǰ�����д��ڵ�ǰ�������¼�ļ�¼����
		for(int j = i-1; j >= left; j --)
			Array[j+1] = Array[j];
			Array[left] = TempRecord;	//���������¼�����ȷλ��
	}
}	

