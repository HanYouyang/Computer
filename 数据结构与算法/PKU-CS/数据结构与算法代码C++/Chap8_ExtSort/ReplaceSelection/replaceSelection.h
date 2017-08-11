//注意：为了突出算法，简化输入输出，本算法实现的文件输入和输出视数据类型为int型
//       具体实现需要更新文件的读写操作部分

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream.h>

#define MAX 10
#define MAX_BUFFER 512

/********** less template **********/
//x小于y，返回TRUE，否则返回FALSE
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



/************** 最小值堆template ***************/
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



/********* 缓冲区类，用环状数组实现的队列来实现之 **********/
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



/****************** 置换选择算法 *********************/
//模板参数Elem代表数组中每一个元素的类型
//A是从外存读入n个元素后所存放的数组，n是数组元素的个数
//inputFile和outputFile分别是指向输入和输出文件结构体的指针
//input和output分别是输入和输出缓冲区
template <class Elem>
void replacementSelection(Elem * A, int n, FILE *  inputFile, FILE * outputFile, Buffer<Elem> & input,Buffer<Elem> & output){

	Elem mval;  //存放最小值堆的最小值
	Elem r;  //存放从输入缓冲区中读入的元素


	/****************** 算法主体部分 *******************/
	//初始化堆的数据，从磁盘文件中读入n个数据置入数组A
	initRacer(inputFile, input, A, n);
	
	//建立最小值堆
	MinHeap<Elem> H(A, n, n);  
	cout<<"The data in the MinHeap are:"<<endl;
	for(int t = 0; t < n; t++)
		cout<<H.heapArray[t]<<"  ";
	cout<<endl<<endl;
			
	
	for(int last = (n-1); last >= 0;){//堆不为空，就作这个循环
		mval = H.heapArray[0];  //堆的最小值
		sendToOutputBuffer(input, output, inputFile, outputFile, mval);//把mval送到输出缓冲区，同时处理因缓冲区空或满造成的各种情形
		
		input.read(r);  //从输入缓冲区读入一个记录
			
		if(!less(r, mval)){//如果r的关键码值大于刚才输出缓冲区记录的关键码值，把r放到根结点
			H.heapArray[0] = r;
		}
		else{  //否则用last位置的记录代替根结点，把r放到last位置
			H.heapArray[0] = H.heapArray[last];
			H.heapArray[last] = r;
			H.setSize(last);
			last--;
		}
		
		//if(last != 0){//重新排列堆
			H.SiftDown(0);  //把根结点记录下降到合适的位置
		//	}			
		}  //for
  }



/****** 函数initRacer负责从输入文件中读取数据初始化racer *****/
template <class Elem>
void initRacer(FILE * inputFile, Buffer<Elem> & input, Elem * A, int n){
	
	cout<<"Originally the data in the array A are:"<<endl;
	for(int j = 0; j < n; j++){
		if(input.isEmpty() == false){	//输入缓冲不为空
			input.read(A[j]);	//读数据置入数组A
		}
		else{	//输入缓冲为空
			
			//往缓冲区中插入数据
			Elem read;
			for(int i = 0; i < MAX_BUFFER; i++ ){
				fscanf(inputFile, "%d ", &read);
				input.insert(read);
			}//for

			//读数据置入数组A
			input.read(A[j]);

		}

		cout<<A[j]<<"  ";
	}
	cout<<endl<<endl;
}


/********* sendToOutputBuffer负责把mval送到输出缓冲区中 **********/
//若输出缓冲区满，把数据写进输出文件
//若输入缓冲区空，从输入文件读取数据
template <class Elem>
void sendToOutputBuffer(Buffer<Elem> & input, Buffer<Elem> & output, FILE * inputFile, FILE * outputFile, Elem mval){
	
	Elem read;

	if(output.isFull()){//输出缓冲区为满
		output.flush(outputFile);//把数据写入输出文件
	}
	output.insert(mval);  //最小值输出到输出缓冲区	
		
	if(input.isEmpty()){//输入缓冲区为空
		//从文件读入一批数据
		cout<<"The new-read data into the input buffer are:"<<endl;
		int m = 0;
		while((!feof(inputFile))&&(m < MAX_BUFFER)){
			fscanf(inputFile, "%d ", &read);
			input.insert(read);
			m++;
		}
		input.list();//显示当前输入缓冲区中的数据
	}

}


/***************** 置换选择算法结尾工作 ******************/
template <class Elem>
void endUp(Buffer<Elem> & output, FILE * & inputFile, FILE * & outputFile){
	
	//把输出缓冲区中剩余的内容flush到输出文件中
	output.flush(outputFile);

	fclose(inputFile);
	fclose(outputFile);
}