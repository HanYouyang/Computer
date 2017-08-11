//�Ż��Ĳ���������
#if !defined(AFX_ImprovedInsertSorter)
#define AFX_ImprovedInsertSorter



#include "InsertSorter.h"
template <class Record,class Compare>
class ImprovedInsertSorter:public InsertSorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//�Ż��Ĳ�������Array[]Ϊ���������飬nΪ���鳤��
template <class Record,class int_intCompare>
void ImprovedInsertSorter<Record,int_intCompare>::Sort(Record Array[], int n) 
{ 
	Record TempRecord;
	// ���β����i����¼
	for (int i=1; i<n; i++) 
	{
		TempRecord=Array[i];
		int j = i-1;
		//��i��ʼ��ǰѰ�Ҽ�¼i����ȷλ��
		while ((j>=0) && (int_intCompare::lt(TempRecord, Array[j])))
		{    
			Array[j+1] = Array[j];	//����Щ���ڵ��ڼ�¼i�ļ�¼����
			j = j - 1;
		}
		//��ʱj������Ǽ�¼i����ȷλ�ã�����
		Array[j+1] = TempRecord; 
	}
}

#endif