//����������
#include "Sorter.h"

template <class Record,class Compare>
class QuickSorter:public Sorter<Record,Compare>
{
private:
	int SelectPivot(int left, int right);//ѡ����ֵ��������ֵ�±�
	int Partition(Record Array[], int left, int right);  //�ָ�,������ֵλ��
public:
	void Sort(Record Array[],int left,int right);
};

//��������Array[]Ϊ���������飬i,j�ֱ�Ϊ��������
template <class Record,class Compare>
void QuickSorter<Record,Compare>::Sort(Record Array[], int left,int right) 
{
    // ����������а���0��1����¼���Ͳ�������
	if (right <= left) 
		return;    
	//ѡ����ֵ
	int pivot = SelectPivot(left, right);
	// ����ֵ��������ĩ��
    swap(Array, pivot, right);   
    // ��ʣ��ļ�¼���зָ�ָ����ֵ�ѵ�����ȷλ��
    pivot = Partition(Array, left, right);
    //�Էָ���������н��еݹ��������
    Sort(Array, left, pivot-1);  //����ֵ��ߵ������н��еݹ��������
    Sort(Array, pivot+1, right); //����ֵ�ұߵ������н��еݹ��������
}

//ѡ����ֵ
template <class Record,class Compare>
int QuickSorter<Record,Compare>::SelectPivot(int left,int right) 
{   //����left,right�ֱ��ʾ���е����Ҷ��±�
   //ѡ���м��¼��Ϊ��ֵ
	return (left+right)/2; 
}

//�ָ�
template <class Record,class Compare>
int QuickSorter<Record,Compare>::Partition(Record Array[], int left,int right) 
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

