//拓扑排序
//Miibotree
//2015.2.2
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[501];
queue<int> Q;

int main()
{
	int inDegree[501];//save every vertex's in-degree
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		for(int i = 0; i < n; i++)//init
		{
			inDegree[i] = 0;
			edge[i].clear();
		}
		while(Q.empty() == false)	
			Q.pop();
		
		while(m--)
		{
			int a, b;
			scanf("%d%d", &a, &b);//the edge from a to b
			inDegree[b]++;
			edge[a].push_back(b);
		}

		for(int i = 0; i < n; i++)
		{
			if(inDegree[i] == 0)//put the vertex which the value of indegree
								//is 0 to the queue 
				Q.push(i);
		}
		int cnt = 0;
		while(Q.empty() == false)
		{
			int nowP = Q.front();
			//这里可以输出拓扑排序
			Q.pop();
			cnt++;
			for(int i = 0; i < edge[nowP].size(); i++)
			{
				inDegree[edge[nowP][i]]--;
				if(inDegree[edge[nowP][i]] == 0)
					Q.push(edge[nowP][i]);
			}
		}
		if(cnt == n)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}