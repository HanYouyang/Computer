#if !defined(AFX_Sorter)
#define AFX_Sorter

//总排序类
template <class Record,class Compare>
class Sorter{
protected:
	static void swap(Record Array[],int i,int j);	//交换数组中的两个记录
public:
	void Sort(Record Array[],int n);			//对数组Array进行排序
	void PrintArray(Record array[], int n);		//输出数组内容
};

//交换数组中的两个记录
template <class Record,class Compare>
void Sorter<Record,Compare>::swap(Record Array[],int i,int j)
{
	Record TempRecord = Array[i];
	Array[i] = Array[j];
	Array[j] = TempRecord;
	
}

//输出数组内容
template <class Record,class Compare>
void Sorter<Record,Compare>::PrintArray(Record Array[], int n)
{
	for(int i=0;i<n;i++)
		cout<<Array[i]<<" ";
	cout<<endl;
}  

#endif