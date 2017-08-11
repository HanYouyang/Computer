//1.判断是不是一个aov网
//2.如果是的话，求出关键活动
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
struct Edge{
	int next;
	int cost;
};
vector<Edge>edge[101];
int inDegree[101];
int outDegree[101];
int ve[101], vl[101], ee[101], el[101];
priority_queue<int, vector<int>, greater<int> > q;
stack<int> topoOrder;
int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		inDegree[b]++;
		outDegree[a]++;
		Edge tmp;
		tmp.cost = c;
		tmp.next = b;
		edge[a].push_back(tmp);
	}
	//求解关键路径的算法
	//step1.时间的最早发生时间 按照拓扑排序来计算每个顶点的最早发生时间,同时用一个队列来记录拓扑序列
	for(int i = 1; i <= n; i++)
	{
		if(inDegree[i] == 0)
			q.push(i);
	}
	while(q.empty() == false)
	{
		int top = q.top();
		q.pop();
		topoOrder.push(top);
		for(int i = 0; i < edge[top].size(); i++)
		{
			int v = edge[top][i].next;
			int cost = edge[top][i].cost;
			inDegree[v]--;
			if(inDegree[v] == 0)
				q.push(v);
			if(ve[top] + cost > ve[v])
				ve[v] = ve[top] + cost;
		}
		//edge[top].clear();
	}
	if(topoOrder.size() < n)
	{
		printf("0\n");
		return 0;
	}
	int e = topoOrder.top();
	//step2. 求解时间的最迟发生时间vl 这里用邻接链表求解节点需要遍历，故直接再加一个邻接矩阵来计算
	vl[e] = ve[e];
	topoOrder.pop();
	while(topoOrder.empty() == false)
	{
		int top = topoOrder.top();
		topoOrder.pop();
		vl[top] = 0x3fffffff;
		for(int i = 0; i < edge[top].size(); i++)
		{
			int v = edge[top][i].next;
			int cost = edge[top][i].cost;
			if(vl[v] - cost < vl[top])
				vl[top] = vl[v] - cost;
		}
	}
	//step3.求解活动的最早发生时间和活动的最迟开始时间
	printf("%d\n", ve[e]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = edge[i].size() - 1; j >= 0; j--)
		{
			int v = edge[i][j].next;
			int cost = edge[i][j].cost;
			ee[i] = ve[i];
			el[i] = vl[v] - cost;
			if(ee[i] == el[i])
				printf("%d->%d\n", i, v);
		}
	}
 	return 0;
}