//�Ż�������������
#include "Sorter.h"

template <class Record,class Compare>
class ImprovedBubbleSorter:public Sorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n);
};

//�Ż�����������Array[]Ϊ���������飬nΪ���鳤��
template <class Record,class Compare>
void ImprovedBubbleSorter<Record,Compare>::Sort(Record Array[], int n) 
{ 
  bool NoSwap;			// �Ƿ����˽����ı�־
  for (int i=1; i<n; i++)    {
    NoSwap = true;			// ��־��ʼΪ��
    for (int j=n-1; j>=i; j--)
      if (Compare::lt(Array[j], Array[j-1])) {
        swap(Array, j, j-1);	//��������˽�������־Ϊ��
        NoSwap = false;
      }
    if (NoSwap)  // ���û��������������ʾ���ź��򣬽����㷨
      return;
    } 
}