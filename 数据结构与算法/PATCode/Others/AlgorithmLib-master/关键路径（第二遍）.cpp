//最后再写一遍关键路径和写一下大数，素数筛选法就走人
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#define N 101
using namespace std;

struct Edge{
	int next;
	int c;
};
int ve[N], vl[N];
stack<int> topoOrder;
priority_queue<int, vector<int>, greater<int> > q;//拓扑排序需要一个优先队列
vector<Edge>edge[N * N];
int n, m;
int inDegree[N];

int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		Edge tmp;
		tmp.c = c;
		tmp.next = b;
		edge[a].push_back(tmp);
		inDegree[b]++;
	}
	//step 1.拓扑排序的同时计算出ve
	for(i = 1; i <= n; i++)
	{
		if(inDegree[i] == 0)
		{
			q.push(i);
		}
	}
	while(q.empty() == false)
	{
		int u = q.top();
		topoOrder.push(u);
		q.pop();
		for(i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i].next;
			int c = edge[u][i].c;
			if(ve[u] + c > ve[v])//ve是最大的
				ve[v] = ve[u] + c;
			inDegree[v]--;
			if(inDegree[v] == 0)
				q.push(v);
		}
	}
	//判断拓扑排序是不是存在
	if(topoOrder.size() != n)//拓扑排序不存在
	{
		printf("0\n");
		return 0;
	}
	//step2 计算vl  栈正好符合了这个顺序
	int e;//e是终点
	e = topoOrder.top();
	vl[e] = ve[e];
	topoOrder.pop();//注意这里必须pop一个出来
	while(topoOrder.empty() == false)
	{
		int u = topoOrder.top();
		topoOrder.pop();
		vl[u] = 0x3fffffff;//因为是取最小值，所以一开始要赋一个最大值
		for(i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i].next;
			int c = edge[u][i].c;
			if(vl[u] > vl[v] - c)//最小
				vl[u] = vl[v] - c;
		}
	}
	printf("%d\n", ve[e]);
	//step3.分别计算ee el
	for(i = 1; i <= n; i++)
	{
		for(j = edge[i].size() - 1; j >= 0; j--)//这里把顺序反一下的目的是按照题目要求来
		{
			int v = edge[i][j].next;
			int c = edge[i][j].c;
			int ee = ve[i];
			int el = vl[v] - c;
			if(ee == el)
				printf("%d->%d\n", i, v);
		}
	}
	return 0;
}