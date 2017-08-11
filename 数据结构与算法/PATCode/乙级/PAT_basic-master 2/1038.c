#include<stdio.h>

int main()
{
	int N,K,i;
	const int Number=101;
	int Score[101]={0};
	int Search[100000]={0};
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		int score;
		scanf("%d",&score);
		Score[score]+=1;
	}
	scanf("%d",&K);
	for(i=0;i<K;i++)
	{
		scanf("%d",&Search[i]);
	}
	for(i=0;i<K;i++)
	{
		printf("%d",Score[Search[i]]);
		if(i<K-1)
		{
			printf(" ");
		}
	}
	
	
	return 0;
}
