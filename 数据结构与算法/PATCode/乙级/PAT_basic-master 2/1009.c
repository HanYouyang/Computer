#include<stdio.h>
#include<string.h>

int main()
{
	char s[81]={};
	gets(s);
	if(strchr(s,' ')==NULL)
//考虑只有一个单词，即字符串中没有空格 
	{
		printf("%s\n",s);
	}
	else
	{
		while(strrchr(s,' ')!=NULL)
		{
			printf("%s ", strrchr(s,' ')+sizeof(char));
//			打印最后一个单词，注意要加 sizeof(char)
    		*strrchr(s,' ')=0;
//    		最后一个空格改为‘/0’ 
		}
		printf("%s",s);
//		最后一个单词直接打印字符串 
	}
	
	
	
	return 0;
}
