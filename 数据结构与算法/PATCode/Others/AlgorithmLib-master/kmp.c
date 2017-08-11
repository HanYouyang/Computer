//KMP Algorithm
//Miibotree
//2015.1.13
#include <stdio.h>
#include <string.h>

void ModifyString(char str[]);
void get_next(char T[], int next[]);
int KMP(char S[], char T[], int next[], int pos);

int main()
{
	char S[256];
	char T[256];
	int next[256];
	int pos = 0;
	gets(S);
	gets(T);
	ModifyString(S);
	ModifyString(T);
	
	KMP(S, T, next, pos)
	printf("%d\n", pos);
	return 0;
}

void get_next(char T[], int next[])
{
	int i = 1;
	next[1] = 0;
	while (i <= T[0])	//T[0]用于保存字符串长度
	{
		if (j == 0 || T[i] == T[j])
		{
			++i; ++j; next[i] = j;
		}
		else
			j = next[j];
	}
}

int KMP(char S[], char T[], int next[], int pos)
{
	int i = pos;
	int j = 1;
	while (i <= S[0] && j <= T[0])
	{
		if (j == 0 || S[i] == T[j])
		{
			++i; ++j;
		}
		else
			j = next[j];
	}
}

void ModifyString(char str[])
{
	int len = strlen(str);
	for (int i = len + 1; i > 0; i--)
		str[i] = str[i-1];
	str[0] = len;
}