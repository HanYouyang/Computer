//图的BFS遍历模板
//核心思想：1.使用队列 2.增加inq[maxn]数组标记是否进过队列
//Miibotree
//2015.3.3
//希望熟练敲出
#include <queue>8
using namespace std;
#define MAXN 1000
struct Node
{
	int id;
	int level;
};
vector<Node> Adj[MAXN];
int inq[MAXN] = {false};
void Graph_BFS(int s)//起点编号
{
	queue<Node> q;
	Node start;
	start.id = s;
	start.level = 0;
	q.push(start);
	inq[s] = ture;
	while(q.empty() == false)
	{
		Node topNode = q.top();
		q.pop();
		int u = topNode.id;
		for(int i = 0; i < Adj[u].size(); i++)
		{
			int idx = Adj[u][i].id;
			if(inq[idx] == false)
			{
				Node next;
				next.id = idx;
				next.level = nowlevel + 1;
				q.push(next);
				inq[idx] = true;
			}
		} 
	}
}