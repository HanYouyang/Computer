/************败方树source**********/
//利用MAX个顺串文件
//输入顺串放在1.txt到MAX.txt中，输出顺串放在0.txt中

#include "LoserTree.h"

void main(){
	
	//变量声明
	Buffer<int> bufferPool [MAX+1];	//开辟长度为MAX+1的缓冲池，bufferPool[0]用作输出buffer，其余的作输入buffer
	int racer[MAX+1];	//选手
	char fname [20];	//输入文件名数组
	FILE * f [MAX+1];	//输入输出文件的句柄数组. 
						//输出文件句柄存放在为f[0], 输入文件句柄存放在f[1]到f[MAX]
	LoserTree<int> lt;	//败方树
	int read;	//读出的数据置放在里面
	
	
	//初始化输出文件
	f[0] = fopen("0.txt", "w+");

	
	//初始化输入缓冲区buffer[1..MAX]
	for(int i = 1; i <= MAX; i++){
		
		//初始化存放顺串的文件名，从1.txt到MAX.txt
		_itoa(i, fname, 10);
		strcat(fname, ".txt");
		cout<<fname<<"  ";
		
		//初始化文件句柄数组
		//句柄数组序号和文件名序号相对应，也和缓冲区号相对应
		f[i] = fopen(fname, "r");

		//往输入缓冲区置入数据
		cout<<"The initial data in the input buffer are: ";
		for(int j = 0; j < MAX_BUFFER; j++ ){
			fscanf(f[i], "%d ", &read);
			bufferPool[i].insert(read);
			cout<<read<<"  ";
		}//for
		cout<<endl<<endl;

	}//for

	
	//初始化选手
	cout<<"the initial racers are:"<<endl;
	for(int k = 1; k <= MAX; k++){
		bufferPool[k].read(racer[k]);
		cout<<racer[k]<<"  ";
	}
	cout<<endl;

	
	//***调用多路归并算法，进行MAX路归并***//
	multiMerge<int>(lt, racer, bufferPool, f);
	
	
	//关闭文件句柄
	for(int n = 0; n <= MAX; n++){
	fclose(f[n]);
	} 

	//统计输出文件中的记录数
	//这个没有太大用处，起检查作用
	int a;
	int x = 0;
	FILE * ff;
	ff = fopen("0.txt", "r");
	while(!feof(ff)){
	fscanf(ff, "%d ", &a);
	x++;
	}//while
	cout<<"the all number is:";
	cout<<x<<endl;
	

	/*
	//测试用例
	LoserTree<int> lt;	//败方树
	int winner;	//最终胜者索引
	int racer[MAX+1];	//选手

	//初始化选手
	cout<<"the initial racers are:"<<endl;
	racer[1] = 33;
	racer[2] = 28;
	racer[3] = 17;
	racer[4] = 11;
	racer[5] = 30;
	//racer[6] = 11;
	//racer[7] = 161;
	//racer[8] = 63;
	//racer[9] = 28;
	//racer[10] = 2;


	//初始化败方树
	lt.Initialize(racer, MAX, Winner<int>, Loser<int>);

	//取得最终胜者索引
	winner = lt.Winner();	
	*/
}

