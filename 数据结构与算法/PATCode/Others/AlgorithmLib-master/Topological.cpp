//默写拓扑排序的模板
//按照思路来就可以了
//miibotree
//2015.3.3
#include <vector>
#define maxn 1001
int inDegree[maxn];
vector<int> G[maxn];
bool topological(int n)
{
	int cnt = 0;
	queue<int> q;
	for(int i = 0; i < n; i++)//找到入度为0的顶点，加入队列中
	{
		if(inDegree[i] == 0)
			q.push(i);
	}
	while(q.empty() == false)
	{
		int top = q.front();
		q.pop();
		//printf("%d", top);
		//将以该顶点为边的另外一个顶点的入度减1
		for(int i = 0; i < G[top].size(); i++)
		{
			int v = G[top][v];
			inDegree[v]--;
			if(inDegree[v] == 0)
			{
				q.push(v);
				
			}
		}
		//删除所有以该顶点为出边的边
		G[top].clear();
		cnt++;//每删除一个顶点，加入拓扑序列的顶点数就+1
	}
	if(cnt == n)
		return true;
	else
		return false;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
	}
	int flag = topological(n);
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}