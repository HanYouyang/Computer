#include<stdio.h>

int main()
{
	char N[1000]={0};
	int number[10]={0};
	scanf("%s",N);
	int i,j;
	for(i=0;N[i]!=0;i++)
	{
		j=(int)N[i]-48;
		number[j]+=1;
	}
	for(i=0;i<10;i++)
	{
		if(number[i]>0)
		{
			printf("%d:%d\n",i,number[i]);
		}
		
	}
	
	
	
	
	return 0;
}
