#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int>edge[100001];
int tree[100001];
int Dis[100001], mark[100001];
int n, m;
int flag = true;
int findRoot(int x)
{
	if(tree[x] == -1)
		return x;
	else
	{
		int tmp = findRoot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}

void Dijkstra(int s)
{
	for(int i = 1; i < 100001; i++)
	{
		Dis[i] = -1;
		mark[i] = false;
	}
	Dis[s] = 0;
	mark[s] = true;
	int newP = s;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < edge[newP].size(); j++)
		{
			int next = edge[newP][j];
			if(mark[next] == true)
				continue;
			if(Dis[next] == -1 ||Dis[newP] + 1 < Dis[next])
				Dis[next] = Dis[newP] + 1;
		}
		int min = 0x3fffffff;
		for(int j = 1; j <= n; j++)
		{
			if(mark[j] == true || Dis[j] == -1)
				continue;
			if(Dis[j] < min)
			{
				min  = Dis[j];
				newP = j;
			}
		}
		mark[newP] = true; 
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	//1.判断是否连通
	int cnt = 0;
	for(int i = 1;i <= n; i++)
		tree[i] = -1;
	for(int i = 1;i <= n; i++)
	{
		for(int j = 0; j < edge[i].size(); j++)
		{
			int a = findRoot(i);
			int b = findRoot(edge[i][j]);
			if(a != b)
			{
				tree[a] = b;
				cnt++;
			}
		}
	}
	if(cnt < n - 1)
		flag = false;

	int num;
	scanf("%d", &num);
	for(int i = 0; i < num; i++)
	{
		int q;
		scanf("%d", &q);
		if(flag == false)
			printf("Cc(%d)=0.00\n", q);
		else
		{
			Dijkstra(q);
			double sum = 0;
			for(int j = 1; j <= n; j++)
			{
				if(j != q)
					sum += Dis[j];
			}
			sum /= n-1;
			sum = 1 / sum;
			printf("Cc(%d)=%.2f\n", q, sum);
		}
	}
	return 0;
}