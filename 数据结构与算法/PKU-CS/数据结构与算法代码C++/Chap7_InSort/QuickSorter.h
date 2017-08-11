//快速排序类
#include "Sorter.h"

template <class Record,class Compare>
class QuickSorter:public Sorter<Record,Compare>
{
private:
	int SelectPivot(int left, int right);//选择轴值，返回轴值下标
	int Partition(Record Array[], int left, int right);  //分割,返回轴值位置
public:
	void Sort(Record Array[],int left,int right);
};

//快速排序，Array[]为待排序数组，i,j分别为数组两端
template <class Record,class Compare>
void QuickSorter<Record,Compare>::Sort(Record Array[], int left,int right) 
{
    // 如果子序列中包含0或1个记录，就不用排序
	if (right <= left) 
		return;    
	//选择轴值
	int pivot = SelectPivot(left, right);
	// 将轴值放在数组末端
    swap(Array, pivot, right);   
    // 对剩余的记录进行分割，分割后轴值已到达正确位置
    pivot = Partition(Array, left, right);
    //对分割出的子序列进行递归快速排序
    Sort(Array, left, pivot-1);  //对轴值左边的子序列进行递归快速排序
    Sort(Array, pivot+1, right); //对轴值右边的子序列进行递归快速排序
}

//选择轴值
template <class Record,class Compare>
int QuickSorter<Record,Compare>::SelectPivot(int left,int right) 
{   //参数left,right分别表示序列的左右端下标
   //选择中间纪录作为轴值
	return (left+right)/2; 
}

//分割
template <class Record,class Compare>
int QuickSorter<Record,Compare>::Partition(Record Array[], int left,int right) 
{
	Record TempRecord;		//存放轴值的临时变量
    int i = left;				// i为左指针，j为右指针
	int j = right;	
    TempRecord = Array[j];	//将轴值存放在临时变量中
    while (i != j)  {	//开始进行分割，i,j开始向中间移动，直到相遇
       //i指针向右移动，直到找到一个大于等于轴值的记录
       while (Compare::lt(Array[i], TempRecord) && (j>i))
		   i++;
       // 如果i,j尚未相遇，就将逆序元素换到右边的空闲位置
       if (i<j)
       {  
			Array[j] = Array[i];   
			j--;	//j指针向左移动一步
       }
       // j指针向左移动，直到找到一个小于等于轴值的记录
       while (Compare::gt(Array[j], TempRecord) && (j > i))  j--;
       //如果i,j尚未相遇，就将逆序元素换到左边的空闲位置
       if (i<j)
		{
			  Array[i] = Array[j];
			  i++;	//i指针向右移动一步
		}
    }	//end while
    Array[i] = TempRecord;	//把轴值回填到分界位置i上
	return i;	//返回分界位置i
}

