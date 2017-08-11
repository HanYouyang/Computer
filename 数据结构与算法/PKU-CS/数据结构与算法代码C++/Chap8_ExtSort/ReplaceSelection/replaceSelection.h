//ע�⣺Ϊ��ͻ���㷨����������������㷨ʵ�ֵ��ļ�������������������Ϊint��
//       ����ʵ����Ҫ�����ļ��Ķ�д��������

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream.h>

#define MAX 10
#define MAX_BUFFER 512

/********** less template **********/
//xС��y������TRUE�����򷵻�FALSE
template <class Elem>
bool less(Elem x, Elem y){
	return(x < y);
}


/*********** swap template***********/
template <class Elem>
void swap(Elem * A, int i, int j){
	Elem temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}



/************** ��Сֵ��template ***************/
template <class T>class MinHeap{
	private:

		int MaxSize;	//heapArray max MaxSize
		int CurrenSize;	//curren number of elements in the heapArray
			
	public:
		T * heapArray;	//pointer to the heapArray array		
		//constructor
		MinHeap(T * h, int num, int max){
			heapArray = h;
			CurrenSize = num;
			MaxSize = max;
			BuildHeap();
			}

		//set the MaxSize of heapArray
		void setSize(int x){
			CurrenSize = x;
		}
		
		//put an elment in its correct place
		void SiftDown(int pos){
			while(!isLeaf(pos)){
				//get children
				int j = leftchild(pos);
				int rc = rightchild(pos);

				if((rc < CurrenSize) && (less(heapArray[rc], heapArray[j])))	//j is the less child
					j = rc;
				if(less(heapArray[pos], heapArray[j]))
					return;
				swap(heapArray, pos, j);
				pos = j;
 			}
		}

		//MaxSize
		int heapsize() const{
			return CurrenSize;
		}

		//judge a leaf
		bool isLeaf(int pos) const{
			return (pos >= CurrenSize/2)&&(pos < CurrenSize);
		}

		//left child
		int leftchild(int pos) const{
			return 2*pos+1;
		}

		//right child
		int rightchild(int pos) const {
			return 2*pos+2;
		}

		//parent
		int parent(int pos) const{
			return (pos-1)/2;
		}

		T getmin(){
			return heapArray[0];
		}
		
		//minValue
		bool removemin(T & it){
			if(CurrenSize == 0)
				return false;
			
			//swap min with the last element
			swap(heapArray, 0, --CurrenSize);

			//shif down new root
			if(CurrenSize != 0)
				SiftDown(0);
			
			//return deleted value
			it = heapArray[CurrenSize];
			return true;

		}

		//bulid heapArray
		void BuildHeap(){
			for(int i = CurrenSize/2-1; i >= 0; i--)
				SiftDown(i);
		}

};



/********* �������࣬�û�״����ʵ�ֵĶ�����ʵ��֮ **********/
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



/****************** �û�ѡ���㷨 *********************/
//ģ�����Elem����������ÿһ��Ԫ�ص�����
//A�Ǵ�������n��Ԫ�غ�����ŵ����飬n������Ԫ�صĸ���
//inputFile��outputFile�ֱ���ָ�����������ļ��ṹ���ָ��
//input��output�ֱ�����������������
template <class Elem>
void replacementSelection(Elem * A, int n, FILE *  inputFile, FILE * outputFile, Buffer<Elem> & input,Buffer<Elem> & output){

	Elem mval;  //�����Сֵ�ѵ���Сֵ
	Elem r;  //��Ŵ����뻺�����ж����Ԫ��


	/****************** �㷨���岿�� *******************/
	//��ʼ���ѵ����ݣ��Ӵ����ļ��ж���n��������������A
	initRacer(inputFile, input, A, n);
	
	//������Сֵ��
	MinHeap<Elem> H(A, n, n);  
	cout<<"The data in the MinHeap are:"<<endl;
	for(int t = 0; t < n; t++)
		cout<<H.heapArray[t]<<"  ";
	cout<<endl<<endl;
			
	
	for(int last = (n-1); last >= 0;){//�Ѳ�Ϊ�գ��������ѭ��
		mval = H.heapArray[0];  //�ѵ���Сֵ
		sendToOutputBuffer(input, output, inputFile, outputFile, mval);//��mval�͵������������ͬʱ�����򻺳����ջ�����ɵĸ�������
		
		input.read(r);  //�����뻺��������һ����¼
			
		if(!less(r, mval)){//���r�Ĺؼ���ֵ���ڸղ������������¼�Ĺؼ���ֵ����r�ŵ������
			H.heapArray[0] = r;
		}
		else{  //������lastλ�õļ�¼�������㣬��r�ŵ�lastλ��
			H.heapArray[0] = H.heapArray[last];
			H.heapArray[last] = r;
			H.setSize(last);
			last--;
		}
		
		//if(last != 0){//�������ж�
			H.SiftDown(0);  //�Ѹ�����¼�½������ʵ�λ��
		//	}			
		}  //for
  }



/****** ����initRacer����������ļ��ж�ȡ���ݳ�ʼ��racer *****/
template <class Elem>
void initRacer(FILE * inputFile, Buffer<Elem> & input, Elem * A, int n){
	
	cout<<"Originally the data in the array A are:"<<endl;
	for(int j = 0; j < n; j++){
		if(input.isEmpty() == false){	//���뻺�岻Ϊ��
			input.read(A[j]);	//��������������A
		}
		else{	//���뻺��Ϊ��
			
			//���������в�������
			Elem read;
			for(int i = 0; i < MAX_BUFFER; i++ ){
				fscanf(inputFile, "%d ", &read);
				input.insert(read);
			}//for

			//��������������A
			input.read(A[j]);

		}

		cout<<A[j]<<"  ";
	}
	cout<<endl<<endl;
}


/********* sendToOutputBuffer�����mval�͵������������ **********/
//���������������������д������ļ�
//�����뻺�����գ��������ļ���ȡ����
template <class Elem>
void sendToOutputBuffer(Buffer<Elem> & input, Buffer<Elem> & output, FILE * inputFile, FILE * outputFile, Elem mval){
	
	Elem read;

	if(output.isFull()){//���������Ϊ��
		output.flush(outputFile);//������д������ļ�
	}
	output.insert(mval);  //��Сֵ��������������	
		
	if(input.isEmpty()){//���뻺����Ϊ��
		//���ļ�����һ������
		cout<<"The new-read data into the input buffer are:"<<endl;
		int m = 0;
		while((!feof(inputFile))&&(m < MAX_BUFFER)){
			fscanf(inputFile, "%d ", &read);
			input.insert(read);
			m++;
		}
		input.list();//��ʾ��ǰ���뻺�����е�����
	}

}


/***************** �û�ѡ���㷨��β���� ******************/
template <class Elem>
void endUp(Buffer<Elem> & output, FILE * & inputFile, FILE * & outputFile){
	
	//�������������ʣ�������flush������ļ���
	output.flush(outputFile);

	fclose(inputFile);
	fclose(outputFile);
}