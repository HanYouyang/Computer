#include<stdio.h>
#include<string.h>
int main()
{
	char alphabet[256]={0};
	char string[1010]={0};
	char temp;
	int i,max=0,index;
	gets(string);
	for(i=0;i<strlen(string);i++)
	{
		alphabet[string[i]]++;
	}
	for(i=65;i<91;i++)
	{
		alphabet[i+32]+=alphabet[i];
	}
	for(i=97;i<123;i++)
	{
		if(alphabet[i]>max)
		{
			max=alphabet[i];
			index=i;
		}
	}
	
	printf("%c %d",index,max);
	return 0;
}
