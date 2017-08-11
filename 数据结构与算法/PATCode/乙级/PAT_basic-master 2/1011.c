#include<stdio.h>
int main()
{
	
	int T,i;
	long long A[11]={0},B[11]={0},C[11]={0};
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%ld %ld %ld",&A[i],&B[i],&C[i]);
	}
	for(i=1;i<=T;i++)
	{
		
	
		if(A[i]+B[i]>C[i])
		{
			printf("Case #%d: true\n",i);
		}else
		{
			printf("Case #%d: false\n",i);
		}	
	

	}
	
	
	return 0;	
}
