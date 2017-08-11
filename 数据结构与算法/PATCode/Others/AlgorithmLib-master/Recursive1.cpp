//汉诺塔III 递归例题
//Miibotree
//2015.2.14
//分析：1.递归函数：F(N) = 3 * F(N-1) + 2;
//		2.递归出口：F(1) = 2;
#include <stdio.h>

long long F(int n)
{
	if (n == 1)
		return 2;
	else
		return 3 * F(n-1) + 2; 
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		long long res = F(n);
		printf("%lld\n", res);
	}
}