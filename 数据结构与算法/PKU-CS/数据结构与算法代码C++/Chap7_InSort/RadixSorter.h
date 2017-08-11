//����������
#include "Sorter.h"

template <class Record>
class RadixSorter:public Sorter<Record,Compare>
{
public:
	void Sort(Record Array[],int n,int min,int max);
};

//����ʵ�ֵĻ�������nΪ���鳤�ȣ�dΪ�����������rΪ����
template <class Record>
void RadixSorter<Record>::Sort(Record Array[], int n,int d, int r) 
{ 
	Record *TempArray =new Record[n];	//�����������ʱ����
	int* count= new int[r];				//��������Count[i] �洢�˵�i��Ͱ�еļ�¼��
	int i,j,k;
	int Radix=1;							//����ȡArray[j]�ĵ�iλ������
	for (i=1; i<=d; i++)				// �ֱ�Ե�i����������з���
	{
		for (j=0; j<r; j++)				// ��ʼ��������Ϊ0
			count[j] = 0;    
		 for (j=0; j<n; j++)			// ͳ��ÿ��Ͱ�еļ�¼��
		 {
			k=(Array[j] /Radix)%r;		//ȡArray[j]�ĵ�iλ������
			count[k]++;					//��Ӧ��������1
		 }
    
		for (j=1; j<r; j++)				// ��TempArray�е�λ�����η����r��Ͱ
			count[j] = count[j-1] + count[j];
		for (j=n-1; j>=0; j--)			// ������Ͱ�еļ�¼�����ռ���TempArray�� 
		{
			k=(Array[j] /Radix)%r;		//ȡArray[j]�ĵ�iλ������
			count[k]--;					//�ӵ�k��Ͱ��ȡ��һ����¼����������1
			TempArray[count[k]] = Array[j];
		}
		for (j=0; j<n; j++)				// ����ʱ�����е����ݸ��Ƶ�Array��
			Array[j] = TempArray[j];         
		Radix*=r;
	}
}
