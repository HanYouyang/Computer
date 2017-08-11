#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int *A,int n);
int is_insertion(int *A,int *B,int n);
void Merge1(int A[],int TempA[],int L,int R,int RightEnd);
void Merge_pass(int A[],int TempA[],int N,int length);
void Merge_sort_b(int A[],int N,int step);//在归并排序的函数中加入一个参数step，代表迭代几步 
int is_Merge(int *A,int *B,int n);
int main()
{
	int A[105]={0};
	int B[105]={0};
	int C[105]={0};
	int n,i,j;
	int step;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		C[i]=A[i];
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&B[i]);
	}
	step=is_insertion(C,B,n);
	if(step)
	{
		insertion_sort(A,step+2);
		printf("Insertion Sort\n");
		for(i=0;i<n;i++)
		{
			printf("%d",A[i]);
			if(i<n-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}else if(step=is_Merge(A,B,n)) 
	{
		Merge_sort_b(A,n,step+1);
		printf("Merge Sort\n");
		for(i=0;i<n;i++)
		{
			printf("%d",A[i]);
			if(i<n-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	
	
	
	return 0;
}
void insertion_sort(int *A,int n)
{
	int i,p;
	for(p=1;p<n;p++)
	{
		int temp=A[p];
		for(i=p;i>0&&A[i-1]>temp;i--)
		{
			A[i]=A[i-1];
		}
		A[i]=temp;
	}
} 
int is_insertion(int *A,int *B,int n)
{
	int i,j;
	int ret=0;
	for(i=1;i<n+1;i++)//i从2开始，至少有2个元素才需要进行排序。
	{
		int flag=0;
		insertion_sort(A,i);

		for(j=0;j<n;j++)
		{
			if(A[j]!=B[j])
			{
				flag=1;
				break;
			}	
		}
		if(flag!=1)
		{
			ret=i-1;
			return ret;
		}
	}
	return ret;
}
void Merge1(int A[],int TempA[],int L,int R,int RightEnd)
{
	int i;
	int LeftEnd=R-1;
	int Tmp=L;
	while(L<=LeftEnd&&R<=RightEnd)
	{
		if(A[L]<=A[R])
		{
			TempA[Tmp++]=A[L++];
		}else
		{
			TempA[Tmp++]=A[R++];
		}
	}
	while(L<=LeftEnd)
	{
		TempA[Tmp++]=A[L++];
	}
	while(R<=RightEnd)
	{
		TempA[Tmp++]=A[R++];
	}
}
void Merge_pass(int A[],int TempA[],int N,int length)
{
	int i,j;
	for(i=0;i<=N-2*length;i+=2*length)
	{
		Merge1(A,TempA,i,i+length,i+2*length-1);
	}
	if(i+length<N)
	{
		Merge1(A,TempA,i,i+length,N-1);
	}else
	{
		for(j=i;j<N;j++)
		{
			TempA[j]=A[j];
		}
	}
	for(j=0;j<N;j++)
	{
		A[j]=TempA[j];
	}

} 
void Merge_sort_b(int A[],int N,int step)
{
	int *TempA;
	TempA=malloc(N*sizeof(int));
	if(TempA!=NULL)
	{
		int length=1;
		while(length<=step)
		{
			Merge_pass(A,TempA,N,length);
			length*=2;
		}
		free(TempA);
	}else
	{
		printf("Error(空间不足)");
	}
} 
int is_Merge(int *A,int *B,int n)
{
	int i,j;
	int ret=0;
	for(i=1;i<n;i*=2)
	{
		int flag=0;
		Merge_sort_b(A,n,i);
		for(j=0;j<n;j++)
		{
			if(A[j]!=B[j])
			{
				flag=1;
				break;
			}	
		}
		if(flag!=1)
		{
			ret=i;
			return ret;
		}
	}
	return ret;
}
