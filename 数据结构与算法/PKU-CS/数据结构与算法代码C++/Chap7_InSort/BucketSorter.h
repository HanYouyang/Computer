//Ͱʽ������
#include "Sorter.h"

template <class Record>
class BucketSorter:public Sorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n,int max);
};

//Ͱʽ����Array[]Ϊ���������飬���鳤��Ϊn,���м�¼��λ������[0,max)��
template <class Record>
void BucketSorter<Record>::Sort(Record Array[], int n,int max) 
{ 
  int* TempArray=new Record[n];	//��ʱ����
  int* count=new int[max];	//С�ڻ����i��Ԫ�ظ���
  int i;

  for (i=0;i<n;i++)
  	TempArray[i]=Array[i];
  //���м�������ʼ��Ϊ0
  for (i=0;i<max;i++)
  	count[i]=0;
  //ͳ��ÿ��ȡֵ���ֵĴ���
  for (i=0;i<n;i++)
	count[Array[i]]++;
  //ͳ��С�ڵ���i��Ԫ�ظ���
  for (i=1;i<max;i++)
  	count[i]=count[i-1]+count [i];
  
  //��˳�������������
  for (i=n-1;i>0;i--)
     Array[--count[TempArray[i]]] = TempArray[i];
}
