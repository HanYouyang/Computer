//Jungle Roads
//2015.1.24
//Miibotree
//最小生成树算法
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define N 28

using namespace std;

int Tree[N];

struct Edge
{
	int a;
	int b;
	int w;
	bool operator < (const Edge &A) const{
		return w < A.w;
	}
}edge[100];

int findRoot(int x)
{
	if (Tree[x] == -1)
		return x;
	else
	{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}

int main()
{
	int n;
	while (scanf("%d", &n)!= EOF && n != 0)
	{
		int cnt = 1;
		getchar();
		for (int i = 1; i < n; i++)
		{
			char c;
			int k;
			scanf("%c%d", &c, &k);
			getchar();
			for(int j = 1; j <= k; j++)
			{
				char d;
				int cost;
				scanf("%c%d", &d, &cost);
				getchar();
				if (cost)
				{
					edge[cnt].a = c - 'A' + 1;
					edge[cnt].b = d - 'A' + 1;
					edge[cnt++].w = cost;
				}
			}
		}
		sort(edge+1, edge+cnt);
		for (int i = 1; i <= n; i++)
			Tree[i] = -1;
		int sum = 0;
		for (int i = 1; i < cnt; i++)
		{
			int a = findRoot(edge[i].a);
			int b = findRoot(edge[i].b);
			if (a != b)
			{
				Tree[a] = b;
				sum += edge[i].w;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}