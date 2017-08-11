//2016年3月5日17时18分08秒
//2016年3月5日17时36分30秒
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int maxn = 1010;//最大节点数

struct Node{
	int id;//节点编号
	int layer;//节点层数
};

vector<Node> Adj[maxn];//使用邻接表存储图
bool inq[maxn] = {false};//是否已被加入过队列
int n, l;//节点总数，层数

int BFS(int s)
{//广度遍历求出1～l层的转发数，s为起始结点
	queue<Node> q;//BFS队列
	int cnt = 0;//转发数
	Node start;//定义起始节点
	start.id = s;//起始结点编号
	start.layer = 0;//起始结点层号
	q.push(start);//将起始结点压入队列
	inq[start.id] = true;//起始结点的编号设为已被加入过队列
	while(!q.empty()){//队列非空
		Node topNode = q.front();//获取队首结点
		q.pop();//弹出队首元素
		if(topNode.layer > l) break;//如果出现层数大于l，退出
		cnt++;//转发数加1
		for(int i = 0; i < Adj[topNode.id].size(); i++){
			Node next = Adj[topNode.id][i];//从topNode节点出发能够到达的节点next
			next.layer = topNode.layer + 1;//next层数加1
			if(inq[next.id] == false){//如果next还没进入队列
				q.push(next);//将next入队
				inq[next.id] = true;//入队标志记为true
			}
		}
	}
	return cnt - 1;//返回转发数，减去起始点的转发
}

int main()
{
	scanf("%d%d", &n, &l);//输入结点总数和层数
	for(int i = 1; i <= n; i++){//对于每一个结点
		int m, followed;
		scanf("%d", &m);//输入他关注的人数
		for(int j = 0; j < m; j++){//对于每个他关注的人
			scanf("%d", &followed);//输入关注的人的编号
			Node node;
			node.id = i;//新建关注的人的结点
			Adj[followed].push_back(node);//邻接矩阵记录
		}
	}
	int k, s;
	scanf("%d", &k);//输入查询的个数
	for(int i = 0; i < k; i++){
		scanf("%d", &s);//每一个查询的起始点
		printf("%d\n", BFS(s));//输出转发数
		memset(inq, 0, sizeof(inq));//每一次查询之后将inq数组初始化
	}
}



////DFS版本22分
////2016年3月5日16时30分05秒
////2016年3月5日17时16分59秒
//#include <cstdio>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//const int maxn = 1010;
//int G[maxn][maxn] = {0};
//int n, l;
//bool vis[maxn] = {false};
//
//void DFS(int u, int& cnt, int layer)
//{
//	if(layer > l) return;
//	if(layer > 0){
//		cnt++;
//		vis[u] = true;
//	}
//	for(int v = 1; v <= n; v++){
//		if(vis[v] == false && G[u][v] != 0){
//			DFS(v, cnt, layer + 1);
//		}
//	}
//}
//
//void DFSTrave(int s)
//{
//	int cnt = 0;
//	DFS(s, cnt, 0);
//	printf("%d\n", cnt);
//}
//
//int main()
//{
//	scanf("%d%d", &n, &l);
//	for(int i = 1; i <= n; i++){
//		int m, followed;
//		scanf("%d", &m);
//		for(int j = 0; j < m; j++){
//			scanf("%d", &followed);
//			G[followed][i] = 1;
//		}
//	}
//	int k, s;
//	scanf("%d", &k);
//	for(int i = 0; i < k; i++){
//		scanf("%d", &s);
//		DFSTrave(s);
//		memset(vis, 0, sizeof(vis));
//	}
//	return 0;
//}


////图的遍历BFS链接矩阵版
//int n, G[maxn][maxn];
//bool inq[maxn] = {false};
//const int INF = 1000000000;
//
//void BFS(queue<int> q)
//{
//	while(!q.empty()){
//		int u = q.front();
//		q.pop();
//		//访问u
//		for(int v = 0; v < n; v++){
//			if(G[u][v] != INF && inq[v] == false){
//				q.push(v);
//				inq[v] = true;
//			}
//		}
//	}
//}
//
//void DFSTrave()
//{
//	for(int u = 0; u < n; u++){
//		if(inq[u] == false){
//			queue<int> q;
//			q.push(u);
//			inq[u] = true;
//			BFS(q);
//		}
//	}
//}
//
////图的遍历BFS邻接表版
//vector<int> Adj[maxn];
//int n;
//bool inq[maxn] = {false};
//
//void BFS(queue<int> q)
//{
//	while(!q.empty()){
//		int u = q.front();
//		q.pop();
//		for(int i = 0; i < Adj[u].size(); i++){
//			int v = Adj[u][i];
//			if(inq[v] == false){
//				q.push(v);
//				inq[u] = true;
//			}
//		}
//	}
//}
//
//void BFSTrave()
//{
//	for(int u = 0; u < n; u++){
//		if(inq[u] == false){
//			queue<int> q;
//			q.push(u);
//			inq[u] = true;
//			BFS(q);
//		}
//	}
//}

////图的BFS带层数版
//struct Node{
//	int v;
//	int layer;
//};
//
//vector<Node> Adj[maxn];
//
//void BFS(int s)
//{
//	queue<Node> q;
//	Node start;
//	start.v = s;
//	start.layer = 0;
//	q.push(start);
//	inq[start.v] = true;
//	while(!q.empty()){
//		Node topNode = q.front();
//		q.pop();
//		int u = topNode.v;
//		for(int i = 0; i < Adj[u].size(); i++){
//			Node next = Adj[u][i];
//			next.layer = topNode.layer + 1;
//			if(inq[next.v] == false){
//				q.push(next);
//				inq[next.v] = true;
//			}
//		}
//	}
//}
