/************�ܷ���source**********/
//����MAX��˳���ļ�
//����˳������1.txt��MAX.txt�У����˳������0.txt��

#include "LoserTree.h"

void main(){
	
	//��������
	Buffer<int> bufferPool [MAX+1];	//���ٳ���ΪMAX+1�Ļ���أ�bufferPool[0]�������buffer�������������buffer
	int racer[MAX+1];	//ѡ��
	char fname [20];	//�����ļ�������
	FILE * f [MAX+1];	//��������ļ��ľ������. 
						//����ļ���������Ϊf[0], �����ļ���������f[1]��f[MAX]
	LoserTree<int> lt;	//�ܷ���
	int read;	//�����������÷�������
	
	
	//��ʼ������ļ�
	f[0] = fopen("0.txt", "w+");

	
	//��ʼ�����뻺����buffer[1..MAX]
	for(int i = 1; i <= MAX; i++){
		
		//��ʼ�����˳�����ļ�������1.txt��MAX.txt
		_itoa(i, fname, 10);
		strcat(fname, ".txt");
		cout<<fname<<"  ";
		
		//��ʼ���ļ��������
		//���������ź��ļ���������Ӧ��Ҳ�ͻ����������Ӧ
		f[i] = fopen(fname, "r");

		//�����뻺������������
		cout<<"The initial data in the input buffer are: ";
		for(int j = 0; j < MAX_BUFFER; j++ ){
			fscanf(f[i], "%d ", &read);
			bufferPool[i].insert(read);
			cout<<read<<"  ";
		}//for
		cout<<endl<<endl;

	}//for

	
	//��ʼ��ѡ��
	cout<<"the initial racers are:"<<endl;
	for(int k = 1; k <= MAX; k++){
		bufferPool[k].read(racer[k]);
		cout<<racer[k]<<"  ";
	}
	cout<<endl;

	
	//***���ö�·�鲢�㷨������MAX·�鲢***//
	multiMerge<int>(lt, racer, bufferPool, f);
	
	
	//�ر��ļ����
	for(int n = 0; n <= MAX; n++){
	fclose(f[n]);
	} 

	//ͳ������ļ��еļ�¼��
	//���û��̫���ô�����������
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
	//��������
	LoserTree<int> lt;	//�ܷ���
	int winner;	//����ʤ������
	int racer[MAX+1];	//ѡ��

	//��ʼ��ѡ��
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


	//��ʼ���ܷ���
	lt.Initialize(racer, MAX, Winner<int>, Loser<int>);

	//ȡ������ʤ������
	winner = lt.Winner();	
	*/
}

