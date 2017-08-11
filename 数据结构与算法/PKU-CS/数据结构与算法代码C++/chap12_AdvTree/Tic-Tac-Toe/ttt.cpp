#include <stdio.h>
const int MAX = 10000;		//����+��
const int MIN = -10000;		//����-��
const int SIZE = 3;

struct node{
	int grid[SIZE][SIZE];
};

//�жϵ�i���Ƿ��Ѿ�������ͬһ��������ռ��
bool RowFull(node * x , int i)
{
	return ((x->grid[i][0]==x->grid[i][1])&&(x->grid[i][1]==x->grid[i][2]));
}
//�жϵ�i���Ƿ��Ѿ�������ͬһ��������ռ��
bool ColFull(node * x , int j)
{
	return ((x->grid[0][j]==x->grid[1][j])&&(x->grid[1][j]==x->grid[2][j]));
}
//�ж϶Խ����Ƿ��Ѿ�������ͬһ��������ռ��
bool DiagnoalFull(node * x)
{
	return (((x->grid[0][0]==x->grid[1][1])&&(x->grid[1][1]==x->grid[2][2]))
		||((x->grid[0][2]==x->grid[1][1])&&(x->grid[1][1]==x->grid[2][0])));
}

//��״̬x���й�ֵ����E(x)
int E(node * x)
{
	int RCDC=0,RCDO=0;	//RCDC��ʾ��������п���ռ�ݵ��С��У��Խ�����֮�ͣ�
						// RCDO��ʾ�Է����п���ռ�ݵ��У��С��Խ���֮��
	int i,j;
	//���ȼ����û����һ����ʤ
	//���ж��Ƿ���һ���Ѿ�������ͬһ��������ռ��
	for(i=0;i<SIZE;i++)
		if (RowFull(x,i))
			{
				if (x->grid[i][0]==1)
					return MAX;
				else if (x->grid[i][0]==-1)
					return MIN;
			}
	//���ж��Ƿ���һ���Ѿ�
	for(j=0;j<SIZE;j++)
		if (ColFull(x,j))
		{
			if (x->grid[0][j]==1)
				return MAX;
				else if (x->grid[0][j]==-1)
					return MIN;
		}
	//���ж϶Խ����Ƿ��Ѿ�������ͬһ��������ռ��
	if (DiagnoalFull(x))	//
	{
		if (x->grid[1][1]==1)
			return MAX;
		else if (x->grid[1][1]==-1)
			return MIN;
	}

	//����RCDC��RCDO
	//��ɨ����
	for(i=0;i<SIZE;i++)
	{
		switch (x->grid[i][0])
		{
		case 0:
			if (x->grid[i][1]==0)
			{
				if (x->grid[i][2]==1)
					RCDC++;
				else if (x->grid[i][2]==-1)
					RCDO++;
			}
			else if ((x->grid[i][1]==1)&&(x->grid[i][2]!=-1))
				RCDC++;
			else if ((x->grid[i][1]==-1)&&(x->grid[i][2]!=1))
				RCDO++;
			break;
		case 1:
			if ((x->grid[i][1]!=-1)&&(x->grid[i][2]!=-1))
				RCDC++;
			break;
		case -1:
			if ((x->grid[i][1]!=1)&&(x->grid[i][2]!=1))
				RCDO++;
			break;
		default: break;
		}
	}
	//��ɨ����
	for(j=0;j<SIZE;j++)
	{
		switch (x->grid[0][j])
		{
		case 0:
			if (x->grid[1][j]==0)
			{
				if (x->grid[2][j]==1)
					RCDC++;
				else if (x->grid[2][j]==-1)
					RCDO++;
			}
			else if ((x->grid[1][j]==1)&&(x->grid[2][j]!=-1))
				RCDC++;
			else if ((x->grid[1][j]==-1)&&(x->grid[2][j]!=1))
				RCDO++;
			break;
		case 1:
			if ((x->grid[1][j]!=-1)&&(x->grid[2][j]!=-1))
				RCDC++;
			break;
		case -1:
			if ((x->grid[1][j]!=1)&&(x->grid[2][j]!=1))
				RCDO++;
			break;
		default: break;
		}
	}
	//����ɨ�������Խ���
	switch (x->grid[0][0])
	{
		case 0:
			if (x->grid[1][1]==0)
			{
				if (x->grid[2][2]==1)
					RCDC++;
				else if (x->grid[2][2]==-1)
					RCDO++;
			}
			else if ((x->grid[1][1]==1)&&(x->grid[2][2]!=-1))
				RCDC++;
			else if ((x->grid[1][1]==-1)&&(x->grid[2][2]!=1))
				RCDO++;
			break;
		case 1:
			if ((x->grid[1][1]!=-1)&&(x->grid[2][2]!=-1))
				RCDC++;
			break;
		case -1:
			if ((x->grid[1][1]!=1)&&(x->grid[2][2]!=1))
				RCDO++;
			break;
		default: break;	
	}
	switch (x->grid[0][2])
	{
		case 0:
			if (x->grid[1][1]==0)
			{
				if (x->grid[2][0]==1)
					RCDC++;
				else if (x->grid[2][0]==-1)
					RCDO++;
			}
			else if ((x->grid[1][1]==1)&&(x->grid[2][0]!=-1))
				RCDC++;
			else if ((x->grid[1][1]==-1)&&(x->grid[2][0]!=1))
				RCDO++;
			break;
		case 1:
			if ((x->grid[1][1]!=-1)&&(x->grid[2][0]!=-1))
				RCDC++;
			break;
		case -1:
			if ((x->grid[1][1]!=1)&&(x->grid[2][0]!=1))
				RCDO++;
			break;
		default: break;	
	}
	return (RCDC-RCDO);
}

//������һ�����п���״̬
node* generate(node * x,int player,int & StatusCount)
{
	int i,j;
	int count=0;
	//�������п��ܵĿ���λ��

	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
		{
			if (x->grid[i][j]==0)
			{
				count++;			
			}
		}
	node * p=new node[count];
	StatusCount = count;
	count=0;
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
		{
			if (x->grid[i][j]==0)
			{
				//p[count].grid=x->grid;
				for (int m=0;m<SIZE;m++)
					for(int n=0;n<SIZE;n++)
					{
						p[count].grid[m][n]=x->grid[m][n];
					}
				p[count].grid[i][j]=player;
				count++;			
			}
		}
//		p[count]= NULL;	//����״̬�б�Ľ�β
		return p;
}

int ValueOf(node * x, int player, int depth, node * best)
{
	int value,Evalue;
	node * p;
	node * bes=new node;
	int i,j,count;
	for (i=0;i<SIZE;i++)		//bes��ʼΪ������״̬
		for (j=0;j<SIZE;j++)
			bes->grid[i][j]=0;

	Evalue=E(x);
	if ((Evalue==MAX) || (Evalue==MIN) || (depth==0))	// x�Ǵ����վ�״̬�Ľ���1=0
	{
		for (int i=0;i<SIZE;i++)		//bestΪ������״̬
			for (int j=0;j<SIZE;j++)
				best->grid[i][j]=0;
		if (player == 1)
			return Evalue;				//����E(x)
		else return (-Evalue);			//����-E(x)
	}
	p = generate(x,player,count);	//������һ�����п���״̬
	value=MIN;				//׼��ִ�������С����
	best=p;
	for (i=0;i<count;i++)
	{
		int val = ValueOf(p,-player,depth-1,bes);
		if (value < -val)
		{
			 value=-val;
			 best=p;
		}
		p++;
	}

	//�������
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
			printf("%6d",best->grid[i][j]);
		printf("\n");
	}
	printf("\n");
	return value;
}



void main()
{
	node * ChessBoard = new node;
	node * best = new node;
	int depth;
	int player;
	int i,j;
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			best->grid[i][j]=0;
	ChessBoard->grid[1][1] = 1;
	ChessBoard->grid[0][1] = -1;
	ChessBoard->grid[0][0] = 1;
	ChessBoard->grid[2][2] = -1;
	printf("���̹��Ϊ3*3��\n");
	printf("�밴����������״̬(3*3����������)��0����ո�1��������ռ�ݣ�-1����Է�ռ�ݣ�\n");
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			scanf("%d",&(ChessBoard->grid[i][j]));
	printf("��һ���ֵ�˭�ߣ�1Ϊ�������-1Ϊ�Է���");
	scanf("%d",&player);
	printf("�����벩�������(0-9)��");
	scanf("%d",&depth);
	int f= ValueOf(ChessBoard,player,depth,best);
	printf("��ǰ����״̬��ֵΪ��1000�����Ӯ��-1000������䣩��\n%i\n",f);
}