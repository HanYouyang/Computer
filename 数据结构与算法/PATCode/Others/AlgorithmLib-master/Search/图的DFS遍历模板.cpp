//图的遍历模板
//Miibotree
//2015.3.2
//伪代码如下：
DFS(u)
{
	vis[u] = true;
	for(从u出发能到达的所有顶点v)
	{
		if(vis[v] == false)
			DFS(v);
	}

}

DFSTrave(G)
{
	for(G的所有顶点u)
	{
		if(vis[u] == false)
		DFS(u);
	}
}

//下面给出邻接表版的DFS(这里边没有存储任何信息，不然的话vector应为struct类型)
#define MAXNV 1000
#define INF 1000000000
vector<int> Adj[MAXNV];//Adj[u]存放从顶点u出发可以到达的所有顶点
int n;//顶点总数
bool vis[n] = {false};


DFS(int u, int depth)
{
	vis[u] = true;//先置该顶点为访问过
	//如果要对图进行一些操作，可以在这里进行
	for(int i = 0; i < Adj[u].size(); i++)
	{
		int v = Adj[u][i];
		if(vis[v] == false)
			DFS(v, depth + 1);
	}
}

TraveDFS()
{
	for(int u = 0; u < n; u++)
	{
		if(vis[u] == false)
			DFS(u, 1);//当前深度为1
	}
}