//判断一个数是否是素数
//Miibotree
//2015.1.17

#include <stdio.h>
#include <math.h>

bool judge(int x)
{
	if (x <= 1)
		return false;
	int bound = (int)sqrt(x)+1;
	for (int i = 2; i < bound; i++)
	{
		if (x%i==0)
			return false;
	}
	return true;
}

int main()
{
	int x;
	while(scanf("%d", &x) != EOF)
	{
		puts(judeg(x)?"yes":"no");
	}
	return 0;
}
