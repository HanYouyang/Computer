#include<stdio.h>
#include<string.h>

int main()
{
	char A[10],B[10],DA=0,DB=0;
	int numberA=0,numberB=0,result=0,i;
	scanf("%s %c %s %c",A,&DA,B,&DB);
	for(i=0;i<strlen(A);i++)
	{
		if(A[i]==DA)
		{
			numberA=numberA*10+DA-'0';
		}
	}
	for(i=0;i<strlen(B);i++)
	{
		if(B[i]==DB)
		{
			numberB=numberB*10+DB-'0';
		}
	}
	
	result=numberA+numberB;
	
	printf("%d",result);
	return 0;
} 
