#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_BUFFER 512	//buffer最大容量
#define NO_MEANING 99999999	//当某顺串已经全部处理完时，给败方树外部节点填充这个超大值
#define MAX 10	//最大选手数目


/********************* 缓冲区类，用环状数组实现的队列来实现之 ********************/
//设置头指针front，尾指针rear
//插入在rear处，删除在front处
template <class Elem> class Buffer{
	
	private:
		Elem * buf;	//存放元素的数组
		int front, rear;
		int n; //buffer中当前元素的数目
	
	public:
		
		//constructor
		Buffer(){
			buf = new Elem [MAX_BUFFER];
			front = 0;
			rear = 0;
			n = 0;
			
		}

		//destructor
		~Buffer(){
		delete buf;
		}

		//判断buffer是否为空
		bool isEmpty(){
			return (n==0);
		}

		//判断buffer是否满
		bool isFull(){
			return (n==MAX_BUFFER);
		}
		
		//列出buffer中所有的元素
		//假设元素类型为内建类型
		void list(){
			if (isEmpty()){
				cout<<"no data!"<<endl<<endl;
				return;
			}

			int temp = front;
			for(int i = 0; i < n; i++){
				cout<<buf[temp % MAX_BUFFER]<<"  ";
				temp++;
			}
			cout<<endl<<endl;
		}
		
		//往buffer中插入元素x
		bool insert(Elem x){
			if(isFull()==false){//非满
			buf[rear] = x;
			rear = (rear+1)%MAX_BUFFER;
			n++;
			return true;
			}
			else{
				cout<<"BUFFER FULL!"<<endl;
				return false;
			}
		}

		//从buffer中读取元素x，并在buffer中删除它
		bool read(Elem & x){
			if(isEmpty()==false){//非空
				x = buf[front];
				front = (front+1)%MAX_BUFFER;
				n--;
				return true;
			}
			else{
				cout<<"BUFFER EMPTY!"<<endl;
				return false;
			}
		}

		void flush(FILE  * outputFile){
			
			//写入输出文件
			int temp = front;
			for(int i = 0; i < n; i++){
				fprintf(outputFile,"%d ", buf[temp % MAX_BUFFER]);
				//cout<<buf[temp % MAX_BUFFER]<<"  ";
				temp++;
			}

			//清零
			n = 0;
			front = 0;
			rear = 0;
		}

};


/******** 全局Winner函数，确认A[b]和A[c]的胜者，返回其下标，为b和c之一 ********/
//这里取值小的为胜者
template<class T>
int Winner(T A[], int b, int c){
	//注意：这里我假定T是内建类型，这样才能直接比较大小
	if(A[b] < A[c])
		return b;
	else return c;
}


/********* 全局Loser函数，确认A[b]和A[c]的败者，返回其下标，为b和c之一 **********/
//这里取值大的为败者
template<class T>
int Loser(T A[], int b, int c){
	//注意：这里我假定T是内建类型，这样才能直接比较大小
	if(A[b] >= A[c])
		return b;
	else return c;
}


/**************** 败方树的实现 ***************/
template<class T>
class LoserTree{
	private:
		int MaxSize;	//最大选手数
		int n;	//当前选手数
		int LowExt;	//最底层外部节点数
		int offset;	//最底层外部节点之上的节点总数
		int * B;	//赢者树数组，实际存放的是下标
		T * L;	//元素数组
		void Play(int p, int lc, int rc, int(* winner)(T A[], int b, int c), int(* loser)(T A[], int b, int c));

	public:
		LoserTree(int Treesize = MAX);
		~LoserTree(){delete [] B;}
		//初始化败方树
		void Initialize(T A[], int size,int (*winner)(T A[], int b, int c), int(*loser)(T A[], int b, int c));
		//返回最终胜者索引
		int Winner();
		//位置i的选手改变后重构败方树
		void RePlay(int i, int(*winner)(T A[], int b, int c), int (*loser)(T A[], int b, int c));
};


template<class T>
LoserTree<T>::LoserTree(int TreeSize){
	MaxSize = TreeSize;
	B = new int[MaxSize];
	n = 0;
}


//成员函数Winner，返回最终胜者的索引
template<class T>
int LoserTree<T>::Winner(){
	return (n)?B[0]:0;
}


//成员函数Initilalize负责初始化败者树
template<class T>
void LoserTree<T>::Initialize(T A[], int size, int(*winner)(T A[], int b, int c), int(*loser)(T A[], int b, int c)) {

	//能否处理size个选手的数组a[]
	if(size > MaxSize || size < 2){
		cout<<"Bad Input!"<<endl<<endl;
		return;
	}

	//初始化成员变量
	n = size;
	L = A;

	//计算s=2^log(n-1)
	int i,s;
	for(s = 1; 2*s <= n-1; s+=s);

	LowExt = 2*(n-s);
	offset = 2*s-1;

	//最底层外部节点的比赛
	for(i = 2; i <= LowExt; i+=2)
		Play((offset+i)/2, i-1, i, winner, loser);
	//处理其余外部节点
	if(n%2){//n为奇数，内部节点和外部节点比赛
		//这里用L[LowExt+1]和它的父节点比赛
		//因为此时它的父节点中存放的是其兄弟节点处的比赛胜者索引
		Play(n/2, B[(n-1)/2], LowExt+1, winner, loser);
		i = LowExt+3;
	}
	else i = LowExt+2;

	//剩余外部节点的比赛
	for(; i<=n; i+=2)
		Play((i-LowExt+n-1)/2, i-1, i, winner, loser);

	/*
	///////////////映射成败者树/////////////////
	//如果采用赢者树的Play成员函数，则初始化败方树时需要以下的部分
	  
	int * temp;
	temp = new int [MaxSize];

	temp[0] = B[1];  //全局胜者
	
	int j;
	//和最底层外部节点相关的内部节点
	for(j = 2; j <= LowExt; j+=2)
		temp[(offset+j)/2] = loser(L, j-1, j);
	//其余的第一个外部节点
	if(n%2){
		temp[n/2] = loser(L, B[n-1], LowExt+1);
		j = LowExt+3;
	}
	else j = LowExt+2;
	//剩余外部节点
	for(; j<=n; j+=2)
		temp[(j-LowExt+n-1)/2] = loser(L, j-1, j);

	//孩子都是内部节点的内部节点
	if(n%2){
		for(int k=n-1-(n+1)/2; k >= 1; k--)
			temp[k] = loser(L, B[2*k], B[2*k+1]);
	}
	else{
		for(int kk = n-1-n/2; kk >= 1; kk--)
			temp[kk] = loser(L, B[2*kk], B[2*kk+1]);
	}

	//把temp赋值给B
	delete [] B;
	B = temp;
	*/
}



//成员函数Play负责在内部节点B[p]处开始比赛
template<class T>
void LoserTree<T>::Play(int p, int lc, int rc, int(* winner)(T A[], int b, int c), int(* loser)(T A[], int b, int c)){
	
		B[p] = loser(L, lc, rc);//败者索引放在B[p]中
			
		int temp1, temp2;
		temp1 = winner(L, lc, rc);//p处的胜者索引

		while(p>1 && p%2){//右孩子，需要沿路径继续向上比赛
							  //和B[p]的父结点所标识的外部结点相比较
			temp2 = winner(L, temp1, B[p/2]);//p的胜者和p的父结点比较，赢者暂存在temp2中
			B[p/2] = loser(L, temp1, B[p/2]);//败者索引放入B[p/2]
			temp1 = temp2;
			p/=2;
		}//while

		//结束循环(B[p]是左孩子，或者B[1])之后，在B[p]的父结点写入胜者索引
		B[p/2] = temp1; 


	/*
	//如果用赢者树映射成败方树的方法，这段和赢者树完全一样
	//这部分和赢者树的Play成员函数完全一样
	//在B[p]处开始比赛
	//lc和rc分别是B[p]的左右孩子
	B[p] = winner(L, lc, rc);

	//如果B[p]位于右孩子处且没有到树根，则需要继续向上比赛
	while(p > 1 && p % 2){//右孩子
		B[p/2] = winner(L, B[p-1], B[p]);
		p/=2;
	}
	*/
}



//成员函数RePlay负责选手i的值改变后重新开始比赛
template<class T>
void LoserTree<T>::RePlay(int i, int (*winner)(T A[], int b, int c), int (*loser)(T A[], int b, int c)){
	if(i <= 0 || i > n){
		cout<<"Out of Bounds!"<<endl<<endl;
		return;
	}

	int p;
	//确定父节点的位置
	if(i <= LowExt)
		p = (i+offset)/2;
	else
		p = (i-LowExt+n-1)/2;

	//这里有修改
	//B[0]中始终保存胜者的索引
	B[0] = winner(L, i, B[p]);
	//B[p]中保存败者的索引
	B[p] = loser(L, i, B[p]);

	//这里有修改
	//沿路径向上比赛
	for(; (p/2)>=1; p/=2){
		int temp;//临时存放赢者的索引
		temp = winner(L,B[p/2], B[0]);
		B[p/2] = loser(L,B[p/2], B[0]);	
		B[0] = temp;
	}
}


/*************** 从文件读入一批数据进入缓冲区 *****************/
//输入参数分别是：
//f - 输入文件句柄, b - 输入缓冲区

template <class T>
void fillBuffer(FILE * f, Buffer<T> & b){
	int m = 0;
	T read;  //读出的数据置放在里面
	while((!feof(f))&&(m < MAX_BUFFER)){
		fscanf(f, "%d ", &read);
		b.insert(read);
		m++;
	}//while
}


/******************** 多路归并算法 ********************/
//输入参数分别是：
//lt－败方树，racer－最初的竞赛者，bufferPool－缓冲池，f－输入/输出文件句柄数组
//这里输出文件句柄是f[0]，输入文件句柄是f[1]到f[MAX]，MAX为输入文件的数目
//NO_MEANING宏代表一个极大值

template <class T>
void multiMerge(LoserTree<T> & lt, T * racer, Buffer<T> * bufferPool, FILE * * f){
	
	int winner;	//最终胜者索引

	//初始化败方树
	lt.Initialize(racer, MAX, Winner, Loser);

	////以下处理f[1]到f[MAX]所代表的MAX个输入顺串，并把结果输出到f[0]所代表的输出顺串中
	
	//取得最终胜者索引
	winner = lt.Winner();
	
	while(racer[winner] != NO_MEANING){//循环退出时胜者为NO_MEANING，所有的输入顺串都已经处理完毕
		

		//把胜者插入到输出缓冲区中
		if(bufferPool[0].isFull())//输出缓冲区满，flush到磁盘文件去
			bufferPool[0].flush(f[0]);
		bufferPool[0].insert(racer[winner]);
	
		//从输入缓冲区读入一个新的竞赛者
		if(bufferPool[winner].isEmpty()==false)//输入缓冲区不为空
			bufferPool[winner].read(racer[winner]);//从缓冲区读入值放进racer[winner]
		else{//输入缓冲区为空
				
				if(!feof(f[winner])){//如果对应的输入文件还有数据
					
					//从输入文件读入一批数据到输入缓冲区
					fillBuffer(f[winner], bufferPool[winner]);

					//从缓冲区读数据放进racer[winner]
					bufferPool[winner].read(racer[winner]);
				}
				else{//对应的输入文件没有数据
					//在racer[winner]位置放NO_MEANING
					racer[winner] = NO_MEANING;
				}//else		
		}//else

		//重新进行比赛，取得胜者索引
		lt.RePlay(winner, Winner<int>, Loser<int>);
		winner = lt.Winner();

	}//while
	 
	//把输出缓冲区中剩余的数据写进磁盘文件
	bufferPool[0].flush(f[0]);

}