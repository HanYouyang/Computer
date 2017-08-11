//基于静态链的基数排序

//静态队列类
class StaticQueue{  
public:
    int head;
    int tail;
};

//基于静态链的基数排序类
template <class Record>
class LinkRadixSorter{
private:
	void Distribute(Record* Array,int first,int i,int d,int r, StaticQueue* queue);		//分配过程
	void Collect(Record* Array, int& first, int i, int d, int r, StaticQueue* queue);	//收集过程
public:
	int Sort(Record* Array,int n, int d, int r);										//返回排序后第一个记录的下标
	void PrintArray(Record* A, int first);												//输出序列
};

//静态链实现的基数排序，n为数组长度，d为排序码个数，r为基数
template <class Record>
int LinkRadixSorter<Record>::Sort(Record* Array, int n, int d, int r) 
{ 
	int first=0;					// first指向静态链中第一个记录
	StaticQueue *queue;
	queue = new StaticQueue[r];		//存放r个桶的静态队列
	for (int i=0; i<n; i++)				// 建链，初始为next域指向下一个记录
		Array[i].next = i+1;
	Array[n-1].next = -1;   	//链尾next为空

	for (int j=0; j<d; j++)			//对第j个排序码进行分配和收集，一共d趟
	{
		Distribute(Array, first, j, d, r, queue);
		Collect(Array, first, j, d, r, queue);
	}
	return first;
}

//分配过程,Array中存放待排序记录，first为静态链中的第一个记录,i为第i个排序码，d为排序码个数，r为基数
template <class Record>
void LinkRadixSorter<Record>::Distribute(Record* Array,int first,int i,int d,int r, StaticQueue* queue)  
{
	for (int j=0; j<r; j++)			//初始化r个队列
		queue[j].head=-1;     
	while (first != -1)				//对整个静态链进行分配
	{   
		int k=Array[first].key;		//取第i位排序码数字k
		for (int a=0;a<i;a++)
			k= k/r;
		k=k%r;
		// 把Array[first]分配到第k个子序列中
		if (queue[k].head == -1)	//如果子序列为空，Array[first]就是第一个记录
			queue[k].head = first;    
		else 
			Array[queue[k].tail].next = first;  // 加到子序列的尾部
		queue[k].tail = first;			//first为子序列的尾部	
		first = Array[first].next;		//继续分配下一个记录 
	}
}
//收集过程,Array中存放待排序记录，first为静态链中的第一个记录，i为第i个排序码，d为排序码个数，r为基数
template <class Record>
void LinkRadixSorter<Record>::Collect(Record* Array, int& first, int i, int d, int r, StaticQueue* queue) 
{
	int last, k=0;								//已收集到的最后一个记录
	while (queue[k].head == -1) k++;				// 找到第一个非空队列    
	first = queue[k].head;
	last = queue[k].tail;
	
	while (k<r-1)								//继续收集下一个非空队列
	{
		k++; 
		while (k<r-1 && queue[k].head==-1) k++;	//找到下一个非空队列
		if (queue[k].head!= -1) 
		{
			Array[last].next = queue[k].head;		//将这个非空序列与上一个非空序列连接起来
			last = queue[k].tail;					//此时最后一个记录为这个序列的尾部记录
		}
	}
	Array[last].next = -1;						//收集完毕
}

//输出序列中所有内容
template <class Record>
void LinkRadixSorter<Record>::PrintArray(Record* Array, int first) 
{	//first为静态链Array中第一个记录的下标

	int tmp;							//用来扫描整个链的指针
	tmp = first;
	while (tmp != -1) 
	{
		cout << Array[tmp].key <<" ";	//输出记录
		tmp = Array[tmp].next;			//继续指向下一个记录
	}
	cout << '\n';
}
