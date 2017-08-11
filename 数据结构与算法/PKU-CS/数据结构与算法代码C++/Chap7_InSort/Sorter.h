#if !defined(AFX_Sorter)
#define AFX_Sorter

//��������
template <class Record,class Compare>
class Sorter{
protected:
	static void swap(Record Array[],int i,int j);	//���������е�������¼
public:
	void Sort(Record Array[],int n);			//������Array��������
	void PrintArray(Record array[], int n);		//�����������
};

//���������е�������¼
template <class Record,class Compare>
void Sorter<Record,Compare>::swap(Record Array[],int i,int j)
{
	Record TempRecord = Array[i];
	Array[i] = Array[j];
	Array[j] = TempRecord;
	
}

//�����������
template <class Record,class Compare>
void Sorter<Record,Compare>::PrintArray(Record Array[], int n)
{
	for(int i=0;i<n;i++)
		cout<<Array[i]<<" ";
	cout<<endl;
}  

#endif