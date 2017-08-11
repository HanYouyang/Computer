#include<stdio.h>

int main()
{
	int n,i;
	char s1[21]={};
	char s2[21]="                    ";
	char c;
	int line;
	scanf("%d %c",&n,&c);
	if(n%2==0)
	{
		line=n/2;
	}else
	{
		line=n/2+1;
	}
	for(i=0;i<n;i++)
	{
		s1[i]=c;
	}
	s2[0]=c;
	s2[n-1]=c;
	s2[n]='\0';
	printf("%s\n",s1);
	for(i=0;i<line-2;i++)
	{
		printf("%s\n",s2);
	}
	printf("%s\n",s1);
	return 0;
}
