//0-1背包
//Miibotree
//2015.2.21
#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[1001][1001], w[101], v[101];
int main()
{
	int V, n;
	while(scanf("%d%d", &V, &n) != EOF)
	{
		for(int i = 1; i <= n; i++)	scanf("%d%d", &w[i], &v[i]);
		for(int i = 0; i <= V; i++)	dp[0][i] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = V; j >= v[i]; j--)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
		printf("%d\n", dp[n][V]);	
	}
}