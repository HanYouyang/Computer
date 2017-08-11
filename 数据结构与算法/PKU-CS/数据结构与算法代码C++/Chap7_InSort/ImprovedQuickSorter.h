//�Ż��Ŀ���������
#include "ImprovedInsertSorter.h"
#define THRESHOLD 16
template <class Record,class Compare>
class ImprovedQuickSorter:public Sorter<Record,Compare>
{
private:
	int SelectPivot(int left, int right);//ѡ����ֵ��������ֵ�±�
	int Partition(Record Array[], int left, int right);  //�ָ�,������ֵλ��
	void DoSort(Record Array[],int left,int right);
public:
	void Sort(Record Array[],int left,int right);
};

//�Ż��Ŀ�������Array[]Ϊ���������飬i,j�ֱ�Ϊ��������
template <class Record,class Compare>
void ImprovedQuickSorter<Record,Compare>::Sort(Record Array[], int left,int right) 
{
	//�ȶ����н��еݹ�����
	DoSort(Array,left,right);
	//�����������н���һ��ֱ�Ӳ�������
	ImprovedInsertSorter<Record,Compare> insert_sorter;
	insert_sorter.Sort(Array,right-left+1);
}

template <class Record,class Compare>
void ImprovedQuickSorter<Record,Compare>::DoSort(Record Array[], int left,int right) 
{
    // ����������а���0��1����¼���Ͳ�������
	if (right <= left) 
		return;    
	if (right-left+1 > THRESHOLD)
	{
		//ѡ����ֵ
		//int pivot = SelectPivot(left, right);
		int pivot = (left+right)/2;
		// ����ֵ��������ĩ��
		swap(Array, pivot, right);   
		// ��ʣ��ļ�¼���зָ�ָ����ֵ�ѵ�����ȷλ��
		pivot = Partition(Array, left, right);
		//�Էָ���������н��еݹ��������
		Sort(Array, left, pivot-1);  //����ֵ��ߵ������н��еݹ��������
		Sort(Array, pivot+1, right); //����ֵ�ұߵ������н��еݹ��������
	}
}

//ѡ����ֵ
template <class Record,class Compare>
int ImprovedQuickSorter<Record,Compare>::SelectPivot(int left,int right) 
{   //����left,right�ֱ��ʾ���е����Ҷ��±�
   //ѡ���м��¼��Ϊ��ֵ
	return (left+right)/2; 
}

//�ָ�
template <class Record,class Compare>
int ImprovedQuickSorter<Record,Compare>::Partition(Record Array[], int left,int right) 
{
	Record TempRecord;		//�����ֵ����ʱ����
    int i = left;				// iΪ��ָ�룬jΪ��ָ��
	int j = right;	
    TempRecord = Array[j];	//����ֵ�������ʱ������
    while (i != j)  {	//��ʼ���зָi,j��ʼ���м��ƶ���ֱ������
       //iָ�������ƶ���ֱ���ҵ�һ�����ڵ�����ֵ�ļ�¼
       while (Compare::lt(Array[i], TempRecord) && (j>i))
		   i++;
       // ���i,j��δ�������ͽ�����Ԫ�ػ����ұߵĿ���λ��
       if (i<j)
       {  
			Array[j] = Array[i];   
			j--;	//jָ�������ƶ�һ��
       }
       // jָ�������ƶ���ֱ���ҵ�һ��С�ڵ�����ֵ�ļ�¼
       while (Compare::gt(Array[j], TempRecord) && (j > i))  j--;
       //���i,j��δ�������ͽ�����Ԫ�ػ�����ߵĿ���λ��
       if (i<j)
		{
			  Array[i] = Array[j];
			  i++;	//iָ�������ƶ�һ��
		}
    }	//end while
    Array[i] = TempRecord;	//����ֵ����ֽ�λ��i��
	return i;	//���طֽ�λ��i
}
