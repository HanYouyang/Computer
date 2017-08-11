#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int date;
	int flag;
}aNode;
int cmp(const void *a,const void *b);
int main()
{
	int N,i,n=0;
	int max,min;
	scanf("%d",&N);
	aNode *A=malloc(N*sizeof(aNode));
	int *B=malloc(N*sizeof(int));
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i].date);
		A[i].flag=1;
	}
	max=A[0].date;
	min=A[N-1].date;
	for(i=0;i<N;i++)
	{
		if(A[i].date>=max)
		{
			max=A[i].date;
		}else
		{
			A[i].flag=0;
		}
	}
	for(i=N-1;i>=0;i--)
	{
		if(A[i].date<=min)
		{
			min=A[i].date;
		}else
		{
			A[i].flag=0;
		}
	}
	for(i=0;i<N;i++)
	{
		if(A[i].flag==1)
		{
			B[n++]=A[i].date;
		}
	}
	qsort(B,n,sizeof(B[0]),cmp);
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",B[i]);
	}
	printf("\n");
	return 0;
}
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
