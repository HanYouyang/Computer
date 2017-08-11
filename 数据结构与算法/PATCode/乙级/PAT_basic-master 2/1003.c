#include<stdio.h>
#include<string.h>

int main()
{
	int n,i,j;
	int a[10];
	char string[120]="hello";
	int P,A,T,poP,poT;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",string);
		P=0,A=0,T=0,poP=0,poT=0;
		for(j=0;j<strlen(string);j++)
		{
			if(string[j]=='P')
			{
				P++;
				poP=j;
			}
			if(string[j]=='A')
			{
				A++;
			}
			if(string[j]=='T')
			{
				T++;
				poT=j;
			}
		}
		
	
		if(A+P+T!=strlen(string)||poT-poP<=1||P>1 || T>1||poP*(poT-poP-1)!=strlen(string)-poT-1)
		{
			a[i]=0;
		}
		else
		{
			a[i]=1;
		}	
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	
	
	
	
	
	return 0;
}
