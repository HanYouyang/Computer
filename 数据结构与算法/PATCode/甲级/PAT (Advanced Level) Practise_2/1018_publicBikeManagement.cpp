//2016年3月7日10时47分42秒
//2016年3月7日11时42分35秒
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 510;
const int INF = 1000000000;
int c, n, s, m;//顶点容量，顶点数，出问题的顶点，边数
int G[maxn][maxn], weight[maxn] = {0};//图中存储边权，点权
int d[maxn], minTake = INF, minBack = INF;//d[i]代表起点到i的最短距离，最少携带数目，最少带回数目
bool vis[maxn] = {false};//标记顶点是否已访问
vector<int> pre[maxn];//前驱
vector<int> path, tempPath;//最优路径，临时路径

void Dijkstra(int s)
{//s为起点
	fill(d, d + maxn, INF);
	for(int i = 0; i <= n; i++){
		pre[i].push_back(i);
	}
	d[s] = 0;
	for(int i = 0; i <= n; i++){//循环n + 1次
		int u = -1, min = INF;
		for(int j = 0; j <= n; j++){
			if(vis[j] == false && d[j] < min){//找到未访问顶点中d[]最小的，注意一定是未访问******否则pre结果出错，并在DFS中出现段错误
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v <= n; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					pre[v].clear();//一定先清空
					pre[v].push_back(u);
				} else if(d[u] + G[u][v] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v){
	if(v == 0){
		tempPath.push_back(v);
		int tempTake = 0, tempBack = 0;
		for(int i = tempPath.size() - 2; i >= 0; i--){
			int id = tempPath[i];
			if(weight[id] + tempBack >= c / 2){
				tempBack = tempBack + weight[id] - c / 2;
			} else if (weight[id] + tempBack == c / 2){
				tempBack = 0;
			} else {
				tempTake += c / 2 - weight[id] - tempBack;
				tempBack = 0;
			}
		}
		if(tempTake < minTake){
			path = tempPath;
			minTake = tempTake;
			minBack = tempBack;
		} else if(tempTake == minTake && tempBack < minBack){
			path = tempPath;
			minTake = tempTake;
			minBack = tempBack;
		}
		tempPath.pop_back();//每一个push_back()都对应一个pop_back()
		return;//记得返回
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++){
		DFS(pre[v][i]);//DFS
	}
	tempPath.pop_back();//在for循环之外
}

int main()
{
	fill(G[0], G[0] + maxn * maxn, INF);
	scanf("%d%d%d%d", &c, &n, &s, &m);//输入容量，顶点数，出问题的顶点，边数
	for(int i = 1; i <= n; i++){
		scanf("%d", &weight[i]);//输入点权
	}
	for(int i = 1; i <= m; i++){
		int s1, s2;
		scanf("%d%d", &s1, &s2);
		scanf("%d", &G[s1][s2]);//创建图
		G[s2][s1] = G[s1][s2];
	}
	Dijkstra(0);//Dijkstra算法入口
	DFS(s);//递归求出优解
	printf("%d ", minTake);//按照格式输出
	for(int i = path.size() - 1; i >= 0; i--){
		printf("%d", path[i]);
		if(i) printf("->");
	}
	printf(" %d", minBack);
	return 0;
}

////只使用Dijkstra，测试点7过不去
////2016年3月7日09时29分20秒
////2016年3月7日
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 510;
//const int INF = 100000000;
//
//int c, n, s, m;
//int G[maxn][maxn], weight[maxn] = {0};
//int d[maxn], w[maxn] = {0}, remain[maxn] = {0};
//int pre[maxn] = {0};
//bool vis[maxn] = {false};
//
//void Dijkstra()
//{
//	fill(d, d + maxn, INF);
//	d[0] = 0;
//	w[0] = 0;
//	remain[0] = 0;
//	for(int i = 0; i <= n; i++){
//		int u = -1, min = INF;
//		for(int j = 0; j <= n; j++){
//			if(vis[j] == false && d[j] < min){
//				u = j;
//				min = d[j];
//			}
//		}
//		if(u == -1) return;
//		vis[u] = true;
//		for(int v = 0; v <= n; v++){
//			if(vis[v] == false && G[u][v] != INF){
//				if(d[u] + G[u][v] < d[v]){//如果路径小与最短路径
//					d[v] = d[u] + G[u][v];//更新v结点的最短路径
//					pre[v] = u;//将v的前驱置为u
//					if(weight[v] + remain[u] >= c / 2){
//						w[v] = w[u];//对结点v不需要新带车辆，即到v结点带的车辆与到u结点带的车辆相同
//						remain[v] = remain[u] + weight[v] - c / 2;//更新剩下的车辆数
//					} else {
//						int takeV = c / 2 - weight[v] - remain[u];
//						w[v] = w[u] + takeV;
//						remain[v] = 0;
//					}
//				} else if(d[u] + G[u][v] == d[v]){
//					if(weight[v] + remain[u] >= c / 2){
//						if(w[u] < w[v]){
//							pre[v] = u;
//							w[v] = w[u];
//							remain[v] = remain[u] +weight[v] - c / 2;
//						} else if(w[u] == w[v]){
//							int backV = remain[u] + weight[v] - c / 2;
//							if(backV < remain[v]){
//								pre[v] = u;
//								w[v] = w[u];
//								remain[v] = backV;
//							}
//						}
//					} else {
//						int takeV = c / 2 - weight[v] - remain[u];
//						if(w[u] + takeV < w[v]){
//							pre[v] = u;
//							w[v] = w[u] + takeV;
//							remain[v] = 0;
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//void DFS(int v)
//{
//	if(v == 0){
//		printf("0");
//		return;
//	}
//	DFS(pre[v]);
//	printf("->%d", v);
//}
//
//int main()
//{
//	fill(G[0], G[0] + maxn * maxn, INF);
//	scanf("%d%d%d%d", &c, &n, &s, &m);
//	for(int i = 1; i <= n; i++){
//		scanf("%d", &weight[i]);
//	}
//	for(int i = 1; i <= m; i++){
//		int s1, s2;
//		scanf("%d%d", &s1, &s2);
//		scanf("%d", &G[s1][s2]);
//		G[s2][s1] = G[s1][s2];
//	}
//	for(int i = 1; i <= n; i++){
//		pre[i] = i;
//	}
//	Dijkstra();
//	printf("%d ", w[s]);
//	DFS(s);
//	printf(" %d\n", remain[s]);
//	return 0;
//}
