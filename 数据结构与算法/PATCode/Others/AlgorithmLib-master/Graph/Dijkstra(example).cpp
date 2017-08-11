//Dijkstra Algorithm
//Miibotree
//2015.1.25

#include <stdio.h>
#include <vector>

using namespace std;
struct E{
	int next;//代表直接相邻的节点
	int c;//代表该边的权值
	int cost;//增加了花费
};
vector<E> edge[1001];
bool mark[1001];//标记，当mark[j]为true时表示节点j的最短路径已经找到，该节点已经加入集合k
int Dis[1001];
int cost[1001];

int main()
{
	int n, m;
	int s, t;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		for(int i = 1; i <= n; i++)//初始化邻接链表
			edge[i].clear();
		while(m--)
		{
			int a, b, c, cost;
			scanf("%d%d%d%d", &a, &b, &c, &cost);
			E tmp;
			tmp.c = c;
			temp.cost = cost;
			tmp.next = b;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}
		scanf("%d%d", &s, &t);
		for (int i = 1; i <= n; i++)
		{
			Dis[i] = -1;
			mark[i] = false;
		}
		Dis[s] = 0;
		mark[s] = true;
		int newP = s;

		for (int i = 1; i < n; i++)
		{
			for(int j = 0; j < edge[newP].size(); j++)
			{
				int t = edge[newP][j].next;
				int c = edge[newP][j].c;
				int co = edge[newP][j].cost;
				if(mark[t] == true)
					continue;
				if(Dis[t] == -1 || Dis[t] > Dis[newP] + c || 
					(Dis[t] == Dis[newP] + c && cost[t] > cost[newP] + co) )
				{
					Dis[t] = Dis[newP] + c;
					cost[t] = cost[newP] + co;
				}
			}
			int min = 123123123;
			for(int j = 1; j <= n; j++)
			{
				if (mark[j] == true)
					continue;
				if(Dis[j] == -1)
					continue;
				if(Dis[j] < min)
				{
					min = Dis[j];
					newP = j;
				}
			} 
			mark[newP] = true;
		}
		printf("%d %d\n", Dis[T], cost[T]);
	}
	return 0;
}