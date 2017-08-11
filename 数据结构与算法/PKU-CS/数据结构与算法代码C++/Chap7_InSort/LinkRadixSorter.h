//���ھ�̬���Ļ�������

//��̬������
class StaticQueue{  
public:
    int head;
    int tail;
};

//���ھ�̬���Ļ���������
template <class Record>
class LinkRadixSorter{
private:
	void Distribute(Record* Array,int first,int i,int d,int r, StaticQueue* queue);		//�������
	void Collect(Record* Array, int& first, int i, int d, int r, StaticQueue* queue);	//�ռ�����
public:
	int Sort(Record* Array,int n, int d, int r);										//����������һ����¼���±�
	void PrintArray(Record* A, int first);												//�������
};

//��̬��ʵ�ֵĻ�������nΪ���鳤�ȣ�dΪ�����������rΪ����
template <class Record>
int LinkRadixSorter<Record>::Sort(Record* Array, int n, int d, int r) 
{ 
	int first=0;					// firstָ��̬���е�һ����¼
	StaticQueue *queue;
	queue = new StaticQueue[r];		//���r��Ͱ�ľ�̬����
	for (int i=0; i<n; i++)				// ��������ʼΪnext��ָ����һ����¼
		Array[i].next = i+1;
	Array[n-1].next = -1;   	//��βnextΪ��

	for (int j=0; j<d; j++)			//�Ե�j����������з�����ռ���һ��d��
	{
		Distribute(Array, first, j, d, r, queue);
		Collect(Array, first, j, d, r, queue);
	}
	return first;
}

//�������,Array�д�Ŵ������¼��firstΪ��̬���еĵ�һ����¼,iΪ��i�������룬dΪ�����������rΪ����
template <class Record>
void LinkRadixSorter<Record>::Distribute(Record* Array,int first,int i,int d,int r, StaticQueue* queue)  
{
	for (int j=0; j<r; j++)			//��ʼ��r������
		queue[j].head=-1;     
	while (first != -1)				//��������̬�����з���
	{   
		int k=Array[first].key;		//ȡ��iλ����������k
		for (int a=0;a<i;a++)
			k= k/r;
		k=k%r;
		// ��Array[first]���䵽��k����������
		if (queue[k].head == -1)	//���������Ϊ�գ�Array[first]���ǵ�һ����¼
			queue[k].head = first;    
		else 
			Array[queue[k].tail].next = first;  // �ӵ������е�β��
		queue[k].tail = first;			//firstΪ�����е�β��	
		first = Array[first].next;		//����������һ����¼ 
	}
}
//�ռ�����,Array�д�Ŵ������¼��firstΪ��̬���еĵ�һ����¼��iΪ��i�������룬dΪ�����������rΪ����
template <class Record>
void LinkRadixSorter<Record>::Collect(Record* Array, int& first, int i, int d, int r, StaticQueue* queue) 
{
	int last, k=0;								//���ռ��������һ����¼
	while (queue[k].head == -1) k++;				// �ҵ���һ���ǿն���    
	first = queue[k].head;
	last = queue[k].tail;
	
	while (k<r-1)								//�����ռ���һ���ǿն���
	{
		k++; 
		while (k<r-1 && queue[k].head==-1) k++;	//�ҵ���һ���ǿն���
		if (queue[k].head!= -1) 
		{
			Array[last].next = queue[k].head;		//������ǿ���������һ���ǿ�������������
			last = queue[k].tail;					//��ʱ���һ����¼Ϊ������е�β����¼
		}
	}
	Array[last].next = -1;						//�ռ����
}

//�����������������
template <class Record>
void LinkRadixSorter<Record>::PrintArray(Record* Array, int first) 
{	//firstΪ��̬��Array�е�һ����¼���±�

	int tmp;							//����ɨ����������ָ��
	tmp = first;
	while (tmp != -1) 
	{
		cout << Array[tmp].key <<" ";	//�����¼
		tmp = Array[tmp].next;			//����ָ����һ����¼
	}
	cout << '\n';
}
