//主要的坑就是Q=0这种情况 。 


#include<stdio.h>
#include<string.h>
int main()
{
	char A[1001]={},Q[1001]={};
	int B=0,R=0,i=0,j=1;
	scanf("%s %d",A,&B);
	while(A[i]!=0)
	{
		Q[i]=(R*10+A[i]-'0')/B;
		R=(R*10+A[i]-'0')%B;
		i++;
//	i	A[i]	B	R	Q
//	0	1		7	1	0	
//	1	2		7	5	1
//	2	3		7	4	7
//	3	4		7	2	6
	}
	if(Q[0]!=0)
	{
		printf("%d",Q[0]);
	}else
	{
		if(Q[1]==0)
		{
			printf("0");
		}
	}
	for(j=1;j<strlen(A);j++)
	{
		printf("%d",Q[j]);
	}
	
	printf(" %d",R);
	return 0;
}
