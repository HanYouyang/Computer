//����replacementSelectionģ������һ��˳���Ĳ���
//���е��������ݴ����InputData.txt�У�������˳�������OutputData.txt��

#include "replaceSelection.h"

void main(){
	
	//templateʵ�����ȽϺͽ�������
	bool less(int, int);
	void swap(int * , int, int);

	int A[MAX];
	
	//��������ļ���
	char * in = "InputData.txt";
	char * out = "OutputData.txt";

	//�����롢����ļ�
	FILE * inputFile = fopen(in, "r");
	FILE * outputFile = fopen(out, "w+");

	//�������buffer
	Buffer<int> input;
	Buffer<int> output;
	
	////�����û�ѡ���㷨	
	replacementSelection<int>(A, MAX, inputFile, outputFile, input, output);
	
	//�㷨�����������������������������/����ļ�
	endUp(output, inputFile, outputFile);
}