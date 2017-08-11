//用vector模拟单链表
//Miibotree
//2015.1.22
#include <vector>

#define N 1000

using namespace std;

struct Edge{
	int nextNode;
	int cost;
};

vector<Edge> edge[N];

//初始化清空
for (int i = 0; i < N; i++)
	edge[i].clear();

//插入
Edge tmp;
tmp.nextNode = 3;
tmp.cost = 38;
edge[1].push_back(tmp);

//查询
for(int i = 0; i < edge[2].size(); i++)
{
	int nextNode = edge[2][i].nextNode;
	int cost = edge[2][i].cost;
}

//删除某个边
edge[1].erase(edge[1].begin()+i, edge[1].begin+i+1);
