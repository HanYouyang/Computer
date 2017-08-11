//畅通工程
//Miibotree
//2015.1.22

#include <stdio.h>

#define N 1000
int Tree[N]

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
			Tree[i] = -1;
		while(m--)
		{
			int a, b;
			scanf("%d%d", &a, &b);//输入一条路径
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
				Tree[a] = b;
		}
		int ans = 0;//ans表示极大联通子图个数
		for (int i = 1; i <= n; i++)
		{
			if (Tree[i] == -1)
				ans++;
		}
		ans--;//再修建ans-1条路就可以形成连通图
		printf("%d\n", ans);
	}
}