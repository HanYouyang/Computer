//递推求解 N阶楼梯上楼问题
//Miibotree
//2015.2.17
//递推公式：
//    f(1) = 1;
//    f(2) = 2;
//    f(n) = f(n-1) + f(n-2);
#include <stdio.h>
int main()
{
	long long a[91];
	a[1] = 1;
	a[2] = 2;
	for(int i = 3; i < 90; i++)
		a[i] = a[i-1] + a[i-2];
	int n;
	while(scanf("%d", &n) != EOF)
	{
		printf("%lld\n", a[n]);
	}
}