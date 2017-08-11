//MST 最小生成树算法
//Miibotree
//2015.1.24
//注意：最小生成树算法可以看成是并查集的一个应用

#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 101

int findRoot(int x);

int Tree[N];//顶点

struct Edge//边
{
	int a, b;
	int cost;
	bool operator < (const Edge &A) const{
		return cost < A.cost;
	}
}edge[600];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF && n != 0)
	{
		for (int i = 1; i <= n * (n - 1) / 2; i++)
			scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
		sort(edge+1, edge+1+n*(n-1)/2);
		for(int i = 1; i <= n; i++)
			Tree[i] = -1;
		int ans = 0;
		for (int i = 1; i <= n*(n-1)/2; i++)
		{
			int a = findRoot(edge[i].a);
			int b = findRoot(edge[i].b);
			if (a != b)
			{
				Tree[a] = b;
				ans += edge[i].cost;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

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