//Dijkstra+DFS版本
//2016年3月6日19时38分23秒
//2016年3月6日20时18分04秒
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 510;//最大顶点数
const int INF = 1000000000;//无穷大

int n, m, s, t, G[maxn][maxn], cost[maxn][maxn];
//实际顶点数，边数，起点，终点，距离矩阵，花费矩阵
int d[maxn], minCost = INF;
//d[i]代表从起点s到顶点i的最短距离，s到t的最小花费
bool vis[maxn];//vis[i] == true表示顶点i已访问，初始均为false
vector<int> pre[maxn];//前驱
vector<int> path, tempPath;//最优路径，临时路径

void DFS(int v)
{//v为当前结点
	if(v == s){//递归边界，到达叶子结点（路径起点）
		tempPath.push_back(v);//每一个push_back(v)都对应一个pop_back()
		int tempCost = 0;//记录当前路径的花费之和
		for(int i = tempPath.size() - 1; i > 0; i--){//倒着访问
			int id = tempPath[i], idNext = tempPath[i - 1];
			tempCost += cost[id][idNext];//累加路径花费
		}
		if(tempCost < minCost){//当前花费比最小花费少
			minCost = tempCost;//更新最小花费
			path = tempPath;//更新路径
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);//不是叶子结点则压入vector
	for(int i = 0; i < pre[v].size(); i++){//对pre[v]中的结点DFS
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

void Dijkstra(int s)
{
	fill(d, d + maxn, INF);//fill函数将整个d数组赋值为INF
	for(int i = 0; i < n; i++) pre[i].push_back(i);//初始化pre数组
	d[s] = 0;//起点s到达自身的距离为0
	for(int i = 0; i < n; i++){//循环n次
		int u = -1, min = INF;//u使d[u]最小，min存放该最小的d[u]
		for(int j = 0; j < n; j++){//找到未访问的顶点中d[]最小的
			if(vis[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;//说明剩下的顶点和起点不连通
		vis[u] = true;//标记u为已访问
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF){//如果v未访问 && u能到达v
				if(d[u] + G[u][v] < d[v]){//以u为中介点使d[v]更小
					d[v] = d[u] + G[u][v];//优化d[v]
					pre[v].clear();//清空pre[v]
					pre[v].push_back(u);//u为v的前驱
				} else if(d[u] + G[u][v] == d[v]){//找到相同长度的路径
					pre[v].push_back(u);//u为v的前驱之一
				}
			}
		}
	}
}

int main()
{
	fill(G[0], G[0] + maxn * maxn, INF);
	scanf("%d%d%d%d", &n, &m, &s, &t);//输入顶点数，边数，起点，终点
	for(int i = 0; i < m; i++){
		int c1, c2;
		scanf("%d%d", &c1, &c2);//输入边的两个顶点的编号
		scanf("%d%d", &G[c1][c2], &cost[c1][c2]);//输入边的距离，花费
		G[c2][c1] = G[c1][c2];//建立无向边
		cost[c2][c1] = cost[c1][c2];
	}
	Dijkstra(s);//Dijkstra算法入口
	DFS(t);//获取最优路径
	for(int i = path.size() - 1;  i >= 0; i--){
		printf("%d ", path[i]);//倒着输出路径上的结点
	}
	printf("%d %d\n", d[t], minCost);//输出最短距离，最短路径上的最小花费
	return 0;
}



////Dijkstra版本
////2016年3月6日18时54分35秒
////2016年3月6日19时25分04秒
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 510;//最大顶点数
//const int INF = 1000000000;//无穷大
//
//int dis[maxn][maxn], cost[maxn][maxn];//距离矩阵，花费矩阵
//int d[maxn], w[maxn];//最短距离，最小花费
//bool vis[maxn] = {false};//标记顶点是否被访问，vis[i] == true表示顶点i被访问
//int n, m, s, t;//顶点数，边数，起点，终点
//int pre[maxn];//pre[i]的值是最短路径上顶点i的前驱
//
//void Dijkstra(int s)
//{//s是起点
//	fill(d, d + maxn, INF);//将整个d数组赋值为INF
//	fill(w, w + maxn, INF);
//	for(int i = 0; i < n; i++){
//		pre[i] = i;//初始化顶点前驱为自身
//	}
//	d[s] = 0;//起点s到达自身的距离为0
//	w[s] = 0;//起点s到达自身的花费为0
//	for(int i = 0; i < n; i++){//循环n次
//		int u = -1, min = INF;//u使未访问的节点中d[u]最小，min存放该最小的d[u];
//		for(int j = 0; j < n; j++){//找到未访问的节点中d[]最小的
//			if(vis[j] == false && d[j] < min){
//				u = j;
//				min = d[j];
//			}
//		}
//		if(u == -1) return;//u==-1代表剩下的顶点和起点不连通
//		vis[u] = true;//标记u为已访问
//		for(int v = 0; v < n; v++){
//			if(vis[v] == false && dis[u][v] != INF){//如果未被访问 && u能到达v
//				if(d[u] + dis[u][v] < d[v]){//以u为中介点时能令d[v]变小
//					d[v] = d[u] + dis[u][v];//优化d[v]
//					w[v] = w[u] + cost[u][v];//优化w[v]
//					pre[v] = u;//令v的前驱为u
//				} else if(d[u] + dis[u][v] == d[v]){//找到一条相同长度的路径
//					if(w[u] + cost[u][v] < w[v]){//以u为中介点时w[v]更小
//						w[v] = w[u] + cost[u][v];//优化w[v]
//						pre[v] = u;//令v的前驱为u
//					}
//				}
//			}
//			//if(vis[t] == true) return;
//		}
//	}
//}
//
//void DFS(int v){//DFS打印路径
//	if(v == s){
//		printf("%d ", v);
//		return;
//	}
//	DFS(pre[v]);
//	printf("%d ", v);
//}
//
//int main()
//{
//	fill(dis[0], dis[0] + maxn * maxn, INF);
//	fill(cost[0], cost[0] + maxn * maxn, INF);
//	scanf("%d%d%d%d", &n, &m, &s, &t);//输入顶点数，边数，起点，终点
//	for(int i = 0; i < m; i++){
//		int c1, c2;
//		scanf("%d%d", &c1, &c2);//输入边的两定点
//		scanf("%d%d", &dis[c1][c2], &cost[c1][c2]);//输入边的距离和花费
//		dis[c2][c1] = dis[c1][c2];//建立无向图
//		cost[c2][c1] = cost[c1][c2];
//	}
//	Dijkstra(s);//Dijkstra算法入口
//	DFS(t);//打印路径
//	printf("%d %d\n", d[t], w[t]);//最短距离、最短路径下的最小花费
//}




// //Dijkstra + DFS 模板
// //Dijkstra
// vector<int> pre[maxn];
// void Dijkstra(int s)
// {
// 	fill(d, d + maxn, INF);
// 	for(int i = 0; i < n; i++){
// 		pre[i].push_back(i);
// 	}
// 	d[s] = 0;
// 	for(int i = 0; i < n; i++){
// 		int u = -1, min = INF;
// 		for(int j = 0; j < n; j++){
// 			if(vis[j] == false && d[j] < min){
// 				u = j;
// 				min = d[j];
// 			}
// 		}
// 		if(u == -1) return;
// 		vis[u] = true;
// 		for(int v = 0; v < n; v++){
// 			if(vis[v] = false && G[u][v] != INF){
// 				if(d[u] + G[u][v] < d[v]){
// 					d[v] = d[u] + G[u][v];
// 					pre[v].clear();
// 					pre[v].push_back(u);
// 				} else if(d[u] + G[u][v] == d[v]){
// 					pre[v].push_back(u);
// 				}
// 			}
// 		}
// 	}
// }
// //DFS
// int optValue;
// vector<int> pre[maxn];
// vector<int> path, tempPath;
// void DFS(int v)
// {
// 	if(v == s){
// 		tempPath.push_back(v);
// 		int value;
// 		计算路径tempPath上的value值;
// 		if(value 优于 optValue){
// 			optvalue = value;
// 			path = tempPath;
// 		}
// 		tempPath.pop_back();
// 		return;
// 	}
// 	tempPath.push_back();
// 	for(int i = 0; i < pre[v].size(); i++){
// 		DFS(pre[v][i]);
// 	}
// 	tempPath.pop_back();
// }
