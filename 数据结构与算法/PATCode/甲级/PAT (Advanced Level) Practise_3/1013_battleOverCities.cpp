//2016年3月5日20时27分20秒
//2016年3月5日20时56分15秒
#include <cstdio>
#include <cstring>

const int maxn = 1010;//最大结点数
int n, m, k;//实际结点数，边数，检查的结点数
int G[maxn][maxn] = {0};//存储图的结构
bool vis[maxn] = {false};//判断是否访问过

void DFS(int u, int v)
{//遍历顶点v所在的连通块，顶点u为已经被敌人占据
	vis[v] = true;//标记顶点v已被访问
	for(int i = 1; i <= n; i++){
		if(i != u && vis[i] == false && G[v][i] == 1){
		//遍历v的所有除了顶点u的邻接点
			DFS(u, i);
		}
	}
}

int DFSTrave(int u)
{//深度遍历连通块，u是已经被攻占的点
	int cnt = 0;//记录总共有多少个连通块，则需要修多少条路
	for(int i = 1; i <= n; i++){//对于每一个顶点
		if(i != u && vis[i] == false){//如果不是顶点u且没被访问
			DFS(u, i);//深度遍历顶点i的连通块
			cnt++;//连通块数+1
		}
	}
	return cnt - 1;//有cnt个连通块，则需要修筑cnt - 1条高速公路
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);//输入城市数量，高速公路的数量，需要检查的顶点
	for(int i = 0; i < m; i++){
		int id1, id2;//每一条路线的两个顶点
		scanf("%d%d", &id1, &id2);
		G[id1][id2] = 1;//将两个顶点连通起来
		G[id2][id1] = 1;
	}
	for(int i = 0; i < k; i++){
		int u;
		memset(vis, 0, sizeof(vis));//每次都要初始化访问数组
		scanf("%d", &u);//输入要检测的结点
		printf("%d\n", DFSTrave(u));//深度遍历如果丢失该结点需要修建多少个highway
	}
	return 0;
}
