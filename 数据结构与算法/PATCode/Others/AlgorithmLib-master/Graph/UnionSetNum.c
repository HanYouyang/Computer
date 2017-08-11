//9duOJ 67
//Miibotree
//2015.1.22

#include <stdio.h>

#define N 10000001
int Tree[N];
int Num[N];

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
	int n, m;
	while(scanf("%d", &n) != EOF && n != 0)
	{
		scanf("%d", &m);
		for (int i = 1 ;i <= n; i++)
			{Tree[i] = -1;Num[i] = 1;}
		while(n--)
		{
			int a, b;
			scanf("%d%d", &a, &b);//输入一条路径
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
			{
				Tree[a] = b;//a的根节点是b
				Sum[b] += Sum[a];
			}

		}


		int ans = 1;//ans表示极大联通子图个数
		for (int i = 1; i <= N; i++)
		{
			if (Tree[i] == -1 && Sum[i] > ans)
				ans = Sum[i];
		}
		printf("%d\n", ans);
	}
}