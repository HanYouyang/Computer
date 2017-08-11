//最大连续子序列
//dp方程： dp[0] = a[0]
//		   dp[i] = max{a[i], dp[i - 1]}
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 10001
int main()
{
	int n, i, minusCnt = 0;
	int a[MAXN], dp[MAXN], k[MAXN];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] < 0)
			minusCnt++;
	}
	if(minusCnt == n)
	{
		printf("0 %d %d\n", a[0], a[n - 1]);
		return 0;
	}
	dp[0] = a[0];

	for(i = 1; i < n; i++)
	{
		dp[i] = max(a[i], dp[i - 1] + a[i]);
		if(dp[i - 1] + a[i] > a[i])
			k[i] = k[i - 1];
		else
			k[i] = i;
	}
	int ans = -10000000;
	int idx;
	for(int i = 0; i < n; i++)
	{
		if(dp[i] > ans)
		{
			ans = dp[i];
			idx = i;
		}
	}
	printf("%d %d %d\n", ans, a[k[idx]], a[idx]);
	return 0;
}