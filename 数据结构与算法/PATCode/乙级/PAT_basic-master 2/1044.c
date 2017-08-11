#include<stdio.h>
#include<string.h>
typedef struct trans
{
	char *mars;
}translist;
int isMarsNumber(char *A);
char *earthToMars(char *A,int lenth);
int marsToEarth(char *A);
translist a[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
translist b[13]={0,"tam", "hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
int main()
{
	int N,i;
	char string[10];
	scanf("%d",&N);
	gets(string);
	for(i=0;i<N;i++)
	{
		gets(string);
		if(isMarsNumber(string))
		{
			printf("%d\n",marsToEarth(string));
		}else
		{
			printf("%s\n",earthToMars(string,strlen(string)));
		}
	}
	
	return 0;
}
int isMarsNumber(char *A)
{
	if(A[0]>='0'&&A[0]<='9')
	{
		return 0;
	}else
	{
		return 1;
	}
}
char *earthToMars(char *A,int lenth)
{
	int number=0,i;
	for(i=0;i<lenth;i++)
	{
		number*=10;
		number+=(A[i]-'0');
	}
	A[0]=0;
	for(i=1;i<13;i++)
	{
		if(i==(number/13))
		{
			strcpy(A,b[i].mars);
			if(number%13==0)//13的整数倍不输出个位的tret 
			{
				return A;
			}
			A[3]=' ';
			A[4]=0;
			break;
		}
	}
	for(i=0;i<13;i++)
	{
		if(i==(number%13))
		{
			strcat(A,a[i].mars);
			break;
		}
	}
	return A;
}
int marsToEarth(char *A)
{
	int result=0,i;
	for(i=1;i<13;i++)
	{
		if(strstr(A,b[i].mars)!=NULL)
		{
			result+=i*13;
			break;
		}
	}
	for(i=0;i<13;i++)
	{
		if(strstr(A,a[i].mars)!=NULL)
		{
			result+=i;
			break;
		}
	}
	return result;
}
