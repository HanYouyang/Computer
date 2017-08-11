#include<stdio.h>

int main()
{
	int N,i,j,k,l,max=0;
	int number[100001]={0};
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&j,&k);
		number[j]+=k;
		if(j>max)
		{
			max=j;	
		}
	}
	for(i=1;i<max+1;i++)
	{
		if(number[i]>number[0])
		{
			number[0]=number[i];
			l=i;
		}
	}
	printf("%d %d",l,number[0]);
	return 0;
} 
