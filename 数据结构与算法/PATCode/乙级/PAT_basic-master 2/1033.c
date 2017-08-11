#include<stdio.h>
#include<string.h>
int main()
{
	char s1[100010]={0};
	char s2[100010]={0};
	char s3[100010]={0};// 把s1中的大写字母转化为小写字母记录下来 
	int i,j=0,len;
	gets(s1);
	gets(s2);
//	scanf("%s",s1);题目只保证第二个字符串为非空，所以用gets()函数比较合适 
//	scanf("%s",s2);
	len=strlen(s2);
	for(i=0;i<strlen(s1);i++)
	{
		if(s1[i]>='A'&&s1[i]<='Z')
		{
			s3[j]=s1[i]+32;
			j++;
		}
	}
	if(strchr(s1,'+')!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(s2[i]>='A'&&s2[i]<='Z')
			{
				s2[i]=' ';// 有"+"则所有大写字母不输出 
			}
		}
	}
	for(i=0;i<strlen(s1);i++)
	{
		while(strchr(s2,s1[i]))
		{
			s2[strchr(s2,s1[i])-s2]=' ';
		}
		
	}
	for(i=0;i<strlen(s3);i++)
	{
		while(strchr(s2,s3[i]))
		{
			s2[strchr(s2,s3[i])-s2]=' ';
		}
		
	}
	for(i=0;i<len;i++)
	{
		if(s2[i]!=' ')
		{
			printf("%c",s2[i]);
		}
	}
	printf("\n");
	return 0;
}
