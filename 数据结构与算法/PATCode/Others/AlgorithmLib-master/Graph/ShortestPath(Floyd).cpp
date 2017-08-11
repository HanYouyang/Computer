//Floyd
//Miibotree
//2015.2.1

#include <stdio.h>
#define INF -1

int ans[101][101];

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0)
	{
		for(int i = 1; i <= 100; i++)
		{
			for (int j = 1; j <= 100; j++)
			{
				ans[i][j] = -1;
			}
			ans[i][i] = 0;
		}
		while(m--)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			ans[a][b] = c;
			ans[b][a] = c;
		}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if(ans[i][k] == INF || ans[k][j] == INF)
						continue;
					if(ans[i][j] == INF || ans[i][k]+ans[k][j] < ans[i][j])//该if执行在上一个if条件不成立的情况下
						ans[i][j] = ans[i][k]+ans[k][j];
				}
			}
		}
		printf("%d\n", ans[1][n]);
	}
	return 0;
}



/*
#define INF 999999
//第一个版本
for (int k = 1; k <= n; k++)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(ans[k-1][i][k] == INF || ans[k-1][k][j] == INF)
			{
				ans[k][i][j] == ans[k-1][i][j];
				continue;
			}
			if(ans[k-1][i][j] == INF || ans[k-1][i][k]+ans[k-1][k][j] < ans[k-1][i][j])
				ans[k][i][j] = ans[k-1][i][k]+ans[k-1][k][j];
			else
				ans[k][i][j] = ans[k-1][i][j];
		}
	}
}
//化简版本
for (int k = 1; k <= n; k++)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(ans[i][k] == INF || ans[k][j] == INF)
				continue;
			if(ans[i][j] == INF || ans[i][k]+ans[k][j] < ans[i][j])//该if执行在上一个if条件不成立的情况下
				ans[i][j] = ans[i][k]+ans[k][j];
		}
	}
}
*/