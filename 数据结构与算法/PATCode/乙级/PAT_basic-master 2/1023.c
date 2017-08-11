#include<stdio.h>

int main()
{

	int A[10]={0};
	int i,x,flag=0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&A[i]);
	}

	for(i=1;i<10;i++)
	{
		if(A[i]!=0)
		{
			printf("%d",i);
			A[i]--;
			flag=1;
			break;
		}
	}
	{
		for(i=0;i<10;i++)
		{
			while(A[i]!=0)
			{
				printf("%d",i);
				A[i]--;
			}
		}
	}
	
	
	
	return 0;
}
