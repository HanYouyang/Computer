#include <stdio.h>
const int MAX = 10000;		//代表+∞
const int MIN = -10000;		//代表-∞
const int SIZE = 3;

struct node{
	int grid[SIZE][SIZE];
};

//判断第i行是否已经被三颗同一方的棋子占据
bool RowFull(node * x , int i)
{
	return ((x->grid[i][0]==x->grid[i][1])&&(x->grid[i][1]==x->grid[i][2]));
}
//判断第i列是否已经被三颗同一方的棋子占据
bool ColFull(node * x , int j)
{
	return ((x->grid[0][j]==x->grid[1][j])&&(x->grid[1][j]==x->grid[2][j]));
}
//判断对角线是否已经被三颗同一方的棋子占据
bool DiagnoalFull(node * x)
{
	return (((x->grid[0][0]==x->grid[1][1])&&(x->grid[1][1]==x->grid[2][2]))
		||((x->grid[0][2]==x->grid[1][1])&&(x->grid[1][1]==x->grid[2][0])));
}

//对状态x进行估值，求E(x)
int E(node * x)
{
	int RCDC=0,RCDO=0;	//RCDC表示计算机还有可能占据的行、列，对角线数之和，
						// RCDO表示对方还有可能占据的行，列、对角线之和
	int i,j;
	//首先检查有没有哪一方获胜
	//先判断是否有一行已经被三颗同一方的棋子占据
	for(i=0;i<SIZE;i++)
		if (RowFull(x,i))
			{
				if (x->grid[i][0]==1)
					return MAX;
				else if (x->grid[i][0]==-1)
					return MIN;
			}
	//再判断是否有一列已经
	for(j=0;j<SIZE;j++)
		if (ColFull(x,j))
		{
			if (x->grid[0][j]==1)
				return MAX;
				else if (x->grid[0][j]==-1)
					return MIN;
		}
	//再判断对角线是否已经被三颗同一方的棋子占据
	if (DiagnoalFull(x))	//
	{
		if (x->grid[1][1]==1)
			return MAX;
		else if (x->grid[1][1]==-1)
			return MIN;
	}

	//计算RCDC和RCDO
	//先扫描行
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
	//再扫描列
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
	//再来扫描两条对角线
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

//产生下一步所有可能状态
node* generate(node * x,int player,int & StatusCount)
{
	int i,j;
	int count=0;
	//搜索所有可能的空余位置

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
//		p[count]= NULL;	//所有状态列表的结尾
		return p;
}

int ValueOf(node * x, int player, int depth, node * best)
{
	int value,Evalue;
	node * p;
	node * bes=new node;
	int i,j,count;
	for (i=0;i<SIZE;i++)		//bes初始为空棋盘状态
		for (j=0;j<SIZE;j++)
			bes->grid[i][j]=0;

	Evalue=E(x);
	if ((Evalue==MAX) || (Evalue==MIN) || (depth==0))	// x是代表终局状态的结点或1=0
	{
		for (int i=0;i<SIZE;i++)		//best为空棋盘状态
			for (int j=0;j<SIZE;j++)
				best->grid[i][j]=0;
		if (player == 1)
			return Evalue;				//返回E(x)
		else return (-Evalue);			//返回-E(x)
	}
	p = generate(x,player,count);	//产生下一步所有可能状态
	value=MIN;				//准备执行最大最小过程
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

	//输出棋盘
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
	printf("棋盘规格为3*3。\n");
	printf("请按行输入棋盘状态(3*3的整数矩阵)，0代表空格，1代表计算机占据，-1代表对方占据：\n");
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			scanf("%d",&(ChessBoard->grid[i][j]));
	printf("下一步轮到谁走？1为计算机，-1为对方：");
	scanf("%d",&player);
	printf("请输入博弈树深度(0-9)：");
	scanf("%d",&depth);
	int f= ValueOf(ChessBoard,player,depth,best);
	printf("当前棋盘状态的值为（1000代表必赢，-1000代表必输）：\n%i\n",f);
}