#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_BUFFER 512	//buffer�������
#define NO_MEANING 99999999	//��ĳ˳���Ѿ�ȫ��������ʱ�����ܷ����ⲿ�ڵ�����������ֵ
#define MAX 10	//���ѡ����Ŀ


/********************* �������࣬�û�״����ʵ�ֵĶ�����ʵ��֮ ********************/
//����ͷָ��front��βָ��rear
//������rear����ɾ����front��
template <class Elem> class Buffer{
	
	private:
		Elem * buf;	//���Ԫ�ص�����
		int front, rear;
		int n; //buffer�е�ǰԪ�ص���Ŀ
	
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

		//�ж�buffer�Ƿ�Ϊ��
		bool isEmpty(){
			return (n==0);
		}

		//�ж�buffer�Ƿ���
		bool isFull(){
			return (n==MAX_BUFFER);
		}
		
		//�г�buffer�����е�Ԫ��
		//����Ԫ������Ϊ�ڽ�����
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
		
		//��buffer�в���Ԫ��x
		bool insert(Elem x){
			if(isFull()==false){//����
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

		//��buffer�ж�ȡԪ��x������buffer��ɾ����
		bool read(Elem & x){
			if(isEmpty()==false){//�ǿ�
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
			
			//д������ļ�
			int temp = front;
			for(int i = 0; i < n; i++){
				fprintf(outputFile,"%d ", buf[temp % MAX_BUFFER]);
				//cout<<buf[temp % MAX_BUFFER]<<"  ";
				temp++;
			}

			//����
			n = 0;
			front = 0;
			rear = 0;
		}

};


/******** ȫ��Winner������ȷ��A[b]��A[c]��ʤ�ߣ��������±꣬Ϊb��c֮һ ********/
//����ȡֵС��Ϊʤ��
template<class T>
int Winner(T A[], int b, int c){
	//ע�⣺�����Ҽٶ�T���ڽ����ͣ���������ֱ�ӱȽϴ�С
	if(A[b] < A[c])
		return b;
	else return c;
}


/********* ȫ��Loser������ȷ��A[b]��A[c]�İ��ߣ��������±꣬Ϊb��c֮һ **********/
//����ȡֵ���Ϊ����
template<class T>
int Loser(T A[], int b, int c){
	//ע�⣺�����Ҽٶ�T���ڽ����ͣ���������ֱ�ӱȽϴ�С
	if(A[b] >= A[c])
		return b;
	else return c;
}


/**************** �ܷ�����ʵ�� ***************/
template<class T>
class LoserTree{
	private:
		int MaxSize;	//���ѡ����
		int n;	//��ǰѡ����
		int LowExt;	//��ײ��ⲿ�ڵ���
		int offset;	//��ײ��ⲿ�ڵ�֮�ϵĽڵ�����
		int * B;	//Ӯ�������飬ʵ�ʴ�ŵ����±�
		T * L;	//Ԫ������
		void Play(int p, int lc, int rc, int(* winner)(T A[], int b, int c), int(* loser)(T A[], int b, int c));

	public:
		LoserTree(int Treesize = MAX);
		~LoserTree(){delete [] B;}
		//��ʼ���ܷ���
		void Initialize(T A[], int size,int (*winner)(T A[], int b, int c), int(*loser)(T A[], int b, int c));
		//��������ʤ������
		int Winner();
		//λ��i��ѡ�ָı���ع��ܷ���
		void RePlay(int i, int(*winner)(T A[], int b, int c), int (*loser)(T A[], int b, int c));
};


template<class T>
LoserTree<T>::LoserTree(int TreeSize){
	MaxSize = TreeSize;
	B = new int[MaxSize];
	n = 0;
}


//��Ա����Winner����������ʤ�ߵ�����
template<class T>
int LoserTree<T>::Winner(){
	return (n)?B[0]:0;
}


//��Ա����Initilalize�����ʼ��������
template<class T>
void LoserTree<T>::Initialize(T A[], int size, int(*winner)(T A[], int b, int c), int(*loser)(T A[], int b, int c)) {

	//�ܷ���size��ѡ�ֵ�����a[]
	if(size > MaxSize || size < 2){
		cout<<"Bad Input!"<<endl<<endl;
		return;
	}

	//��ʼ����Ա����
	n = size;
	L = A;

	//����s=2^log(n-1)
	int i,s;
	for(s = 1; 2*s <= n-1; s+=s);

	LowExt = 2*(n-s);
	offset = 2*s-1;

	//��ײ��ⲿ�ڵ�ı���
	for(i = 2; i <= LowExt; i+=2)
		Play((offset+i)/2, i-1, i, winner, loser);
	//���������ⲿ�ڵ�
	if(n%2){//nΪ�������ڲ��ڵ���ⲿ�ڵ����
		//������L[LowExt+1]�����ĸ��ڵ����
		//��Ϊ��ʱ���ĸ��ڵ��д�ŵ������ֵܽڵ㴦�ı���ʤ������
		Play(n/2, B[(n-1)/2], LowExt+1, winner, loser);
		i = LowExt+3;
	}
	else i = LowExt+2;

	//ʣ���ⲿ�ڵ�ı���
	for(; i<=n; i+=2)
		Play((i-LowExt+n-1)/2, i-1, i, winner, loser);

	/*
	///////////////ӳ��ɰ�����/////////////////
	//�������Ӯ������Play��Ա���������ʼ���ܷ���ʱ��Ҫ���µĲ���
	  
	int * temp;
	temp = new int [MaxSize];

	temp[0] = B[1];  //ȫ��ʤ��
	
	int j;
	//����ײ��ⲿ�ڵ���ص��ڲ��ڵ�
	for(j = 2; j <= LowExt; j+=2)
		temp[(offset+j)/2] = loser(L, j-1, j);
	//����ĵ�һ���ⲿ�ڵ�
	if(n%2){
		temp[n/2] = loser(L, B[n-1], LowExt+1);
		j = LowExt+3;
	}
	else j = LowExt+2;
	//ʣ���ⲿ�ڵ�
	for(; j<=n; j+=2)
		temp[(j-LowExt+n-1)/2] = loser(L, j-1, j);

	//���Ӷ����ڲ��ڵ���ڲ��ڵ�
	if(n%2){
		for(int k=n-1-(n+1)/2; k >= 1; k--)
			temp[k] = loser(L, B[2*k], B[2*k+1]);
	}
	else{
		for(int kk = n-1-n/2; kk >= 1; kk--)
			temp[kk] = loser(L, B[2*kk], B[2*kk+1]);
	}

	//��temp��ֵ��B
	delete [] B;
	B = temp;
	*/
}



//��Ա����Play�������ڲ��ڵ�B[p]����ʼ����
template<class T>
void LoserTree<T>::Play(int p, int lc, int rc, int(* winner)(T A[], int b, int c), int(* loser)(T A[], int b, int c)){
	
		B[p] = loser(L, lc, rc);//������������B[p]��
			
		int temp1, temp2;
		temp1 = winner(L, lc, rc);//p����ʤ������

		while(p>1 && p%2){//�Һ��ӣ���Ҫ��·���������ϱ���
							  //��B[p]�ĸ��������ʶ���ⲿ�����Ƚ�
			temp2 = winner(L, temp1, B[p/2]);//p��ʤ�ߺ�p�ĸ����Ƚϣ�Ӯ���ݴ���temp2��
			B[p/2] = loser(L, temp1, B[p/2]);//������������B[p/2]
			temp1 = temp2;
			p/=2;
		}//while

		//����ѭ��(B[p]�����ӣ�����B[1])֮����B[p]�ĸ����д��ʤ������
		B[p/2] = temp1; 


	/*
	//�����Ӯ����ӳ��ɰܷ����ķ�������κ�Ӯ������ȫһ��
	//�ⲿ�ֺ�Ӯ������Play��Ա������ȫһ��
	//��B[p]����ʼ����
	//lc��rc�ֱ���B[p]�����Һ���
	B[p] = winner(L, lc, rc);

	//���B[p]λ���Һ��Ӵ���û�е�����������Ҫ�������ϱ���
	while(p > 1 && p % 2){//�Һ���
		B[p/2] = winner(L, B[p-1], B[p]);
		p/=2;
	}
	*/
}



//��Ա����RePlay����ѡ��i��ֵ�ı�����¿�ʼ����
template<class T>
void LoserTree<T>::RePlay(int i, int (*winner)(T A[], int b, int c), int (*loser)(T A[], int b, int c)){
	if(i <= 0 || i > n){
		cout<<"Out of Bounds!"<<endl<<endl;
		return;
	}

	int p;
	//ȷ�����ڵ��λ��
	if(i <= LowExt)
		p = (i+offset)/2;
	else
		p = (i-LowExt+n-1)/2;

	//�������޸�
	//B[0]��ʼ�ձ���ʤ�ߵ�����
	B[0] = winner(L, i, B[p]);
	//B[p]�б�����ߵ�����
	B[p] = loser(L, i, B[p]);

	//�������޸�
	//��·�����ϱ���
	for(; (p/2)>=1; p/=2){
		int temp;//��ʱ���Ӯ�ߵ�����
		temp = winner(L,B[p/2], B[0]);
		B[p/2] = loser(L,B[p/2], B[0]);	
		B[0] = temp;
	}
}


/*************** ���ļ�����һ�����ݽ��뻺���� *****************/
//��������ֱ��ǣ�
//f - �����ļ����, b - ���뻺����

template <class T>
void fillBuffer(FILE * f, Buffer<T> & b){
	int m = 0;
	T read;  //�����������÷�������
	while((!feof(f))&&(m < MAX_BUFFER)){
		fscanf(f, "%d ", &read);
		b.insert(read);
		m++;
	}//while
}


/******************** ��·�鲢�㷨 ********************/
//��������ֱ��ǣ�
//lt���ܷ�����racer������ľ����ߣ�bufferPool������أ�f������/����ļ��������
//��������ļ������f[0]�������ļ������f[1]��f[MAX]��MAXΪ�����ļ�����Ŀ
//NO_MEANING�����һ������ֵ

template <class T>
void multiMerge(LoserTree<T> & lt, T * racer, Buffer<T> * bufferPool, FILE * * f){
	
	int winner;	//����ʤ������

	//��ʼ���ܷ���
	lt.Initialize(racer, MAX, Winner, Loser);

	////���´���f[1]��f[MAX]�������MAX������˳�������ѽ�������f[0]����������˳����
	
	//ȡ������ʤ������
	winner = lt.Winner();
	
	while(racer[winner] != NO_MEANING){//ѭ���˳�ʱʤ��ΪNO_MEANING�����е�����˳�����Ѿ��������
		

		//��ʤ�߲��뵽�����������
		if(bufferPool[0].isFull())//�������������flush�������ļ�ȥ
			bufferPool[0].flush(f[0]);
		bufferPool[0].insert(racer[winner]);
	
		//�����뻺��������һ���µľ�����
		if(bufferPool[winner].isEmpty()==false)//���뻺������Ϊ��
			bufferPool[winner].read(racer[winner]);//�ӻ���������ֵ�Ž�racer[winner]
		else{//���뻺����Ϊ��
				
				if(!feof(f[winner])){//�����Ӧ�������ļ���������
					
					//�������ļ�����һ�����ݵ����뻺����
					fillBuffer(f[winner], bufferPool[winner]);

					//�ӻ����������ݷŽ�racer[winner]
					bufferPool[winner].read(racer[winner]);
				}
				else{//��Ӧ�������ļ�û������
					//��racer[winner]λ�÷�NO_MEANING
					racer[winner] = NO_MEANING;
				}//else		
		}//else

		//���½��б�����ȡ��ʤ������
		lt.RePlay(winner, Winner<int>, Loser<int>);
		winner = lt.Winner();

	}//while
	 
	//�������������ʣ�������д�������ļ�
	bufferPool[0].flush(f[0]);

}