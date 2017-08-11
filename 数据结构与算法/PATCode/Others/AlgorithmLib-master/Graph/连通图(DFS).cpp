//联通图的判断
#include <stdio.h>
#include <vector>
#define N 1000
using namespace std;
vector<int>edge[N];
int hashTable[N];
int ans = 0;
bool visit[N];

void DFS(int x)
{
	visit[x] = true;
	for(int i = 0; i < edge[x].size(); i++)
	{
		int v = edge[x][i];
		if(visit[v] == false && hashTable[v] > 0)
			DFS(v);
	}
}

void DFSTrave()
{
	for(int i = 1; i < N; i++)
	{
		if(visit[i] == false && hashTable[i] > 0)//该顶点存在且没有被访问过
		{
			DFS(i);
			ans++;
		}
	}
}

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	int n, m;
	int sum = 0;
	while(scanf("%d%d", &m, &n) != EOF)
	{
		if(hashTable[m] == 0)
		{
			sum++;
			hashTable[m]++;
		}
		if(hashTable[n] == 0)
		{
			sum++;
			hashTable[n]++;
		}
		if(m == n)
			continue;
		edge[m].push_back(n);
		edge[n].push_back(m);
	}
	DFSTrave();
	printf("%d\n", ans);
	return 0;
}