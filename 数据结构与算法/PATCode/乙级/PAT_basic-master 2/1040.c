#include<stdio.h>
#include<string.h>
int main()
{
	char s[100010]={0};
	int i;
	int p=0,pa=0,pat=0; 
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='P')
		{
			p++;
		}else if(s[i]=='A')
		{
			pa=(pa+p)%1000000007;
		}else
		{
			pat=(pat+pa)%1000000007;
		}
	}
	printf("%d",pat);
	
	return 0;
}
