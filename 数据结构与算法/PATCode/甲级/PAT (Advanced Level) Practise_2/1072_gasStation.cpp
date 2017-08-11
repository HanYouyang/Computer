//2016年3月7日14时13分12秒
//2016年3月7日15时20分36秒
/*思路
	只需要对每一个加油站点使用一次Dijkstra求出d[]
	然后根据数组d[]求出最小距离和平均距离
	注意的点：在Dijkstra时加油站点也要算进去
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1020;
const int INF = 1000000000;

int n, m, k, ds, G[maxn][maxn];
int d[maxn];
bool vis[maxn] = {false};

void Dijkstra(int s)
{
	fill(d, d + maxn, INF);
	memset(vis, false, sizeof(vis));
	d[s] = 0;
	for(int i = 1; i <= n + m; i++){
		int u = -1, min = INF;
		for(int j = 1; j <= n + m; j++){
			if(vis[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 1; v <= n + m; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
				}
			}
		}
	}
}

int getID(char str[])
{
	int id;
	if(str[0] > '0' && str[0] <= '9'){
		sscanf(str, "%d", &id);//sscanf()的用法
		return id;
	} else {
		sscanf(str + 1, "%d", &id);//可以这样用*******************************************
		return n + id;
	}
}

int main()
{
	fill(G[0], G[0] + maxn * maxn, INF);
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	for(int i = 0; i < k; i++){
		char p1[10], p2[10];
		scanf("%s %s", p1, p2);
		int id1 = getID(p1);
		int id2 = getID(p2);
		scanf("%d", &G[id1][id2]);
		G[id2][id1] = G[id1][id2];
	}
	double ansDis = -1, ansAvg = INF;//最大的最短距离，最小的平均距离
	int ansID = -1;//最终的加油站ID
	for(int i = n + 1; i <= n + m; i++){
		Dijkstra(i);//进行Dijkstra算法，求出d数组
		double minDis = INF, avg = 0;//当前加油站的最小距离，平均距离
		for(int j = 1; j <= n; j++){
			if(d[j] > ds){//存在大于服务距离的军民房，直接跳出
				minDis = -1;
				break;
			}
			if(d[j] < minDis) minDis = d[j];//更新最近距离
			avg += 1.0 * d[j] / n;//求平均距离
		}
		if(minDis == -1) continue;//最小距离为-1说明存在距离大于DS的居民
		if(minDis > ansDis){//如果当前最小距离大于已有最小距离
			ansDis = minDis;//更新最小距离
			ansAvg = avg;//更新平均距离
			ansID = i;//更新加油站ID
		} else if(minDis == ansDis && avg < ansAvg){//如果最小距离相等但平均距离小
			ansAvg = avg;//更新平均距离
			ansID = i;//更新加油站ID
		}
	}
	if(ansID == -1) printf("No Solution\n");//如果最小距离等于-1，无解
	else{
		printf("G%d\n", ansID - n);//输出加油站
		printf("%.1f %.1f\n", ansDis, ansAvg);//输出最小距离和平均距离
	}
	return 0;
}
