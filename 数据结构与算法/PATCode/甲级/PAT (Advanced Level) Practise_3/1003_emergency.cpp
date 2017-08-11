//2016年3月6日15时33分35秒
//2016年3月6日15时57分11秒
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 510;//最大城市数量
const int INF = 1000000000;//INF代表一个很大很大的数
int G[maxn][maxn], d[maxn];//图的结构，d[i]代表起点城市到城市i的最短距离
int team[maxn], num[maxn] = {0}, w[maxn] = {0};//每个城市驻扎的军队数量，最短路条数，收集的军队数量
int n, m, s, t;//城市数量，城市间道路的数量，起点，终点
bool vis[maxn];//标记城市i是否已经被访问

void Dijkstra(int s, int t)
{//s代表起点，t代表终点
	fill(d, d + maxn, INF);//初始时的最短距离均为INF
	d[s] = 0;//起点到起点的最短距离为零
	num[s] = 1;//到起点的最短路径条数为1******
	w[s] = team[s];//到起点时手机的军队数量最多为起点的军队数量
	for(int i = 0; i < n; i++){//循环n次
		int u = -1, min = INF;//u使d[u]最小，min存放该最小的d[u]
		for(int j = 0; j < n; j++){//找到未访问的顶点中d[]最小的
			if(vis[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;//如果找不到小于INF的，说明剩下的顶点和起点s不连通
		vis[u] = true;//标记u为已访问
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF){//如果v未访问 && u能到达v
				if(d[u] + G[u][v] < d[v]){//以u为中介点可以使d[v]变小
					d[v] = d[u] + G[u][v];//覆盖d[v]
					num[v] = num[u];//覆盖num[v]
					w[v] = team[v] + w[u];//覆盖w[v]
				} else if(d[u] + G[u][v] == d[v]){//找到一条相同长度的路径
					num[v] += num[u];//最短路径条数更新
					if(w[u] + team[v] > w[v]){//以u为中介点时点权之和更大
						w[v] = w[u] + team[v];//w[v]继承自w[u]
					}
				}
			}
			if(vis[t] == true) return;//如果已到达终点，返回
		}
	}
}

int main()
{
	fill(G[0], G[0] + maxn * maxn, INF);//初始化所有城市为孤立状态
	scanf("%d%d%d%d", &n, &m, &s, &t);//输入城市数，城市间道路数，起点，终点
	for(int i = 0; i < n; i++){
		scanf("%d", &team[i]);//输入每个城市军队数量
	}
	for(int i = 0; i < m; i++){
		int c1, c2, l;
		scanf("%d%d%d", &c1, &c2, &l);//输入每条道路的起点，终点，道路长度
		G[c1][c2] = l;//创建图
		G[c2][c1] = l;
	}
	Dijkstra(s, t);//Dijkstra算法入口
	printf("%d %d\n", num[t], w[t]);//最短距离条数，最短路径中的最大点权（能号召的最大军队数量）
}


////Dijkstra最短路邻接矩阵版
//const int maxn = 1010;//最大结点数
//const int INF = 1000000000;//INF为一个很大的数
//int n, G[maxn][maxn];//实际结点数，图的邻接矩阵//根据实际情况进行初始化，可能为0可能为INF
//bool vis[maxn] = {false};//标记数组，vis[i] == true表示结点i已访问，初始均为false
//int d[maxn];//起点到达各个结点的最短路径长度
//
//void dijkstra(int s)
//{//s为起点
//	fill(d, d + maxn, INF);//fill函数将整个d数组赋值为INF
//	d[s] = 0;//起点s到达自身的距离为0
//	for(int i = 0; i < n; i++){//循环n次
//		int u = -1, min = INF;//u使d[u]最小，min存放该最小的d[u]
//		for(int j = 0; j < n; j++){//找到u与min
//			if(vis[j] == false && d[j] < min){//要在没访问过的结点集合中找
//				u = j;
//				min = d[j];
//			}
//		}
//		if(u == -1) return;//如果找不到小于INF的d[u],说明剩下的结点和起点s不连通
//		vis[u] = true;//标记u为已访问
//		for(int v = 0; v < n; v++)
//		{//v未访问 && u能到达v && 以u为中介点可以使d[v]更优，则更新d[v]
//			if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
//				d[v] = d[u] + G[u][v];
//			}
//		}
//	}
//}
//
////Dijkstra最短路邻接表版
//const int maxn = 10010;//最大结点数
//const int INF = 1000000000;//INF为一个很大的数
//struct Node{
//	int v, dis;//v为边的目标节点，dis为边权
//};
//vector<Node> Adj[maxn];//图G，Adj[u]存放从顶点u出发可以到达的所有顶点
//bool vis[maxn] = {false};//标记数组，vis[i] == true表示结点i已访问。初始均为false
//int d[maxn], n;//起点到达各点的最短路径长度，实际结点数
//
//void dijkstra(int s)
//{//s为起点
//	fill(d, d + maxn, INF);//fill函数将整个d数组赋值为INF
//	d[s] = 0;//起点s到达自身的距离为0
//	for(int i = 0; i < n; i++){//循环n次
//		int u = -1, min = INF;//u使d[u]最小，min存放该最小的d[u]
//		for(int j = 0; j < n; j++){//找到未访问的顶点中d[]最小的
//			if(vis[j] == false && d[j] < min){
//				u = j;
//				min = d[j];
//			}
//		}
//		if(u == -1) return;//找不到小于INF的d[u],说明剩下的顶点和起点s不连通
//		vis[u] = true;//标记u为已访问
//		for(int j = 0; j < Adj[u].size(); j++){
//			int v = Adj[u][j].v;//通过邻接表直接获得u能达到的顶点v
//			int dis = Adj[u][j].dis;//通过邻接表直接获得u到v的边权
//			if(vis[v] == false && d[v] > d[u] + dis)
//			{//v未访问 && 以u为中介可以使d[v]更优
//				d[v] = d[u] + dis;//优化d[v]
//			}
//		}
//	}
//}
