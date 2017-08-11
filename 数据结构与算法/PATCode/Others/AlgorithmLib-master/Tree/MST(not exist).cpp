//题目1024：畅通工程 
//Miibotree
//2015.1.24
//还是最小生成树问题 可能不存在

#include <stdio.h>
#include <algorithm>

using namespace std;

int Tree[101];//边

struct Edge
{
	int a;
	int b;
	int w;
	bool operator < (const Edge &A) const{
		return w < A.w;
	}
}edge[101];

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
	while(scanf("%d%d", &n, &m) != EOF && n != 0)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].w);
		sort(edge+1, edge+n+1);//注意这里
		for(int i = 1; i <= m; i++)
			Tree[i] = -1;
		int sum = 0;
		int cnt = 1;
		for(int i = 1; i <= n; i++)
		{
			int a = findRoot(edge[i].a);
			int b = findRoot(edge[i].b);
			if(a != b)
			{
				Tree[a] = b;
				sum+=edge[i].w;
				cnt++;
			}
		}
		if(cnt == m)//判断最小生成树的节点个数是不是节点总数
			printf("%d\n", sum);
		else
			printf("?\n");
	}
	return 0;
}