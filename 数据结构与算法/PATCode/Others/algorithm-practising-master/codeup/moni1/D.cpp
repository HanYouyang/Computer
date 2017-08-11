//2017年3月9日15时40分32秒
//2016年3月9日17时17分45秒
//codeup题目编号26852
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 510;
const int INF = 1000000000;

int G[maxn][maxn], weight[maxn], layer[maxn] = {0};
bool inq[maxn] = {false}, vis[maxn] = {false};
vector<int> pre[maxn];
vector<int> tempPath, path;
int n, m, l, k, s, t;
int d[maxn];
int maxTotal = -1, minBack = INF;
int numPath = 0;

void BFS(int s)
{
	queue<int> q;
	q.push(s);
	inq[s] = true;
	layer[s] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(layer[u] < l){
			weight[u] += (int)ceil(weight[u] * 1.0 * (l - layer[u]) / l);
		}
		for(int v = 0; v < n; v++){
			if(inq[v] == false && G[u][v] != INF){
				layer[v] = layer[u] + 1;
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

void Dijkstra(int s)
{
	fill(d, d + maxn, INF);
	for(int i = 0; i < n; i++){
		pre[i].push_back(i);
	}
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, min = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if(d[u] + G[u][v] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v)
{
	if(v == s){
		numPath++;
		tempPath.push_back(v);
		int tempMax = 0, tempMin = 0;
		int half = tempPath.size() / 2;
		for(int i = tempPath.size() - 1; i >= 0; i--){
			tempMax += weight[tempPath[i]];
			if(i < half) tempMin += weight[tempPath[i]];
		}
		if(tempMax % k > maxTotal){
			maxTotal = tempMax % k;
			minBack = tempMin;
			path = tempPath;
		} else if(tempMax % k == maxTotal && tempMin < minBack){
			minBack = tempMin;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

int Shortest()
{
	int dis = 0;
	for(int i = path.size() - 1; i > 0; i--){
		int u = path[i], v = path[i - 1];
		dis += G[u][v];
	}
	return dis;
}

void print()
{
	printf("%d %d %d %d\n", numPath, d[t], maxTotal, minBack);
	for(int i = path.size() - 1; i >= 0; i--){
		printf("%d", path[i]);
		if(i) printf("->");
		else printf("\n");
	}
}

int main()
{
	fill(G[0], G[0] + maxn * maxn, INF);
	scanf("%d%d%d%d%d%d", &n, &m, &l, &k, &s, &t);
	for(int i = 0; i < n; i++){
		scanf("%d", &weight[i]);
	}
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u][v] = w; G[v][u] = w;
	}
	BFS(s);
	Dijkstra(s);
	if(!inq[t]) {
		printf("-1\n");
		return 0;
    	}
	DFS(t);
	print();
	return 0;
}
