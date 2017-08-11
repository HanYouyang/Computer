//函数replacementSelection模拟生成一个顺串的操作
//所有的输入数据存放在InputData.txt中，产生的顺串存放在OutputData.txt中

#include "replaceSelection.h"

void main(){
	
	//template实例化比较和交换函数
	bool less(int, int);
	void swap(int * , int, int);

	int A[MAX];
	
	//输入输出文件名
	char * in = "InputData.txt";
	char * out = "OutputData.txt";

	//打开输入、输出文件
	FILE * inputFile = fopen(in, "r");
	FILE * outputFile = fopen(out, "w+");

	//输入输出buffer
	Buffer<int> input;
	Buffer<int> output;
	
	////调用置换选择算法	
	replacementSelection<int>(A, MAX, inputFile, outputFile, input, output);
	
	//算法结束工作：处理输出缓冲区，输入/输出文件
	endUp(output, inputFile, outputFile);
}