//��С��

//�Զ����swap����
template<class Elem>
swap(Elem A[],int x,int y)
{
	Elem temp=A[x];
	A[x]=A[y];
	A[y]=temp;
}

//��С��
template <class Elem>
class minheap
{
private:
	Elem *Heap;                         //��ָ��
	int size;						    //�Ѵ�С
	int n;								//����ʵ��Ԫ�ظ���

public:	
	//���캯������һ�����е�����Ϊ����	
	minheap(Elem *A,int num,int max)    
	{
		Heap=A;                     //ָ����������
		n=num;
		size=max;
		buildHeap();
	}

	bool isempty() const
	{
		return n<=0;
	}

	bool isLeaf(int pos)            //�ж��Ƿ�ΪҶ
	{
		return (pos>=n/2)&&(pos<n);
	}
	int leftchild(int pos)          //�����
	{
		return 2*pos+1;
	}
	int rightchild(int pos)         //�Ҷ���
	{
		return 2*pos+2;
	}
	int parent(int pos)             //����
	{
		return (pos-1)/2;
	}
	void buildHeap()                //���ѣ��ο�siftdown����
	{
		for(int i=n/2-1;i>=0;i--)
			siftdown(i);
	}
	//�ú�����ÿһ��Ԫ�ط������ڶ��еĺ���λ��
	void siftdown(int pos)
	{
		while(!isLeaf(pos))
		{
			int j=leftchild(pos);
			int rc=rightchild(pos);
			if((rc<n)&&(Heap[j]>Heap[rc]))    //ȡ��С�Ķ���
				j=rc;
			if(!(Heap[pos]>Heap[j])) return;  //����
			//��С���Ӵ󣬺�С���ӽ���
			swap(Heap,pos,j);
			pos=j;
		}
	}
	bool insert(Elem &val)
	{
		if(n>=size) return false;
		int curr=n++;               //�Ƚ������Ԫ�طŵ��ѵ�ĩβ
		Heap[curr]=val;
		//����ʵ��һ��siftup�Ĺ���
		while((curr!=0)&&(Heap[curr]<Heap[parent(curr)]))
		{
			swap(Heap,curr,parent(curr));
			curr=parent(curr);
		}
		return true;
	}
	Elem removemin()               //ȡ��СԪ��
	{
		swap(Heap,0,--n);          //�Ƚ���СԪ�طŵ��ѵ�ĩβ
		if(n!=0) siftdown(0);      //�ؽ���
		return Heap[n];
	}
	//ȡ�κ�һ��Ԫ�أ�������ĺ�����һ��siftup�Ĺ��̣�ע��siftup��siftdown��������ִֻ�����е�һ��
	bool remove(int pos,Elem &it)  
	{
		if((pos<0)||(pos>=n)) return false;
		swap(Heap,pos,--n);
		while(pos!=0&&(Heap[pos]<Heap[parent(pos)]))
		{
			swap(Heap,pos,parent(pos));
			pos=parent(pos);
		}
		//siftdown(pos);
		it=Heap[n];
		return true;
	}
};
