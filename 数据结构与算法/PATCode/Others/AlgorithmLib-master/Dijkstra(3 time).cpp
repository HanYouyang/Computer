//Dijkstra (4 times)
#include <stdio.h>
#include <vector>
using namespace std;

struct Edge{
	int next;
	int cost;//花费
	int c;//距离
};
vector<Edge> edge[1001];
int Dis[1001];
int Cost[1001];
bool mark[1001];
int n, m;

void Dijkstra(int s)
{
	for(int i = 1; i <= n; i++)
	{
		Cost[i] = 0;
		Dis[i] = -1;
		mark[i] =false;
	}
	mark[s] = true;
	Dis[s] = 0;
	int newP = s;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < edge[newP].size(); j++)
		{
			int t = edge[newP][j].next;
			int c = edge[newP][j].c;
			int cost =edge[newP][j].cost;
			if(mark[t] == true)
				continue;
			if(Dis[t] == -1 || Dis[newP] + c < Dis[t] || 
				Dis[newP] + c == Dis[t] && Cost[newP] + cost < Cost[t])
			{
				Dis[t] = Dis[newP] + c;
				Cost[t]  = Cost[newP] + cost;
			}
		}
		int min = 0x3fffffff;
		for(int j = 1; j <= n; j++)
		{
			if(Dis[j] == -1 || mark[j] == true)
				continue;
			if(Dis[j] < min)
			{
				min = Dis[j];
				newP = j;
			}
		}
		mark[newP] = true;
	}
}


int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		for(int i = 1; i <= n; i++)
			edge[i].clear();
		while(m--)
		{
			int a, b, d, p;
			scanf("%d%d%d%d", &a, &b, &d, &p);
			Edge tmp;
			tmp.c = d;
			tmp.cost = p;
			tmp.next = a;
			edge[b].push_back(tmp);
			tmp.next = b;
			edge[a].push_back(tmp);			
		}
		int s, t;
		scanf("%d%d", &s, &t);
		Dijkstra(s);
		printf("%d%d\n", Dis[t], Cost[t]);
	}
	return 0;
}