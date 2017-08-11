//2016年3月6日00时09分06秒
//2016年3月6日00时37分55秒
/*思路
	本题采用BFS， 
	如果一次BFS能遍历所有结点，则说明是一颗树，在BFS中记录树的深度，如果比原有树深高，则更新结果数组，如果相等，则添加到数组后
	如果一次BFS不能遍历所有结点，则记录遍历的趟数，并按照要求输出
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 10010;//最大结点数

int layer[maxn] = {0};//每个结点的层数
int n, block = 0;//实际结点总数，连通块数
vector<int> Adj[maxn];//邻接表存储图
bool vis[maxn] = {false};//标记是否访问
int ans[maxn] = {0}, ansNum = 0, maxDeep = 0;
//结果数组，结果数组中有效数的个数，最大深度

void BFS(int s)
{//s是遍历的起始节点
	int deep = 0;//初始深度
	queue<int> q;//创建一个队列
	q.push(s);//入队
	layer[s] = 1;//初始的层数为1，因为是比较层数的大小，因此初始是1还是0无所谓
	while(!q.empty()){
		int now = q.front();//获取队首元素
		q.pop();//出队
		vis[now] = true;//标记结点已经访问过
		for(int i = 0; i < Adj[now].size(); i++){
			int next = Adj[now][i];//与now连接的结点
			if(vis[next] == false){//如果没有被访问
				layer[next] = layer[now] + 1;//层数为now的层数+1
				deep = layer[next];//深度为next的层数
				q.push(next);//入队
			}
		}
	}
	if(deep > maxDeep){//如果深度大于已有的最大深度，则更新
		ansNum = 0;//初始下表为零
		maxDeep = deep;//更新最大深度
		ans[ansNum++] = s;//将得到最大深度的起始结点压入数组
	} else if(deep == maxDeep){//如果深度等于最大深度，则将得到该深度的节点直接压入数组
		ans[ansNum++] = s;
	}
}

void BFSTrave(int s)
{//s是遍历的起始结点
	block = 1;//刚开始连通块假设为1
	BFS(s);//遍历初始结点所在的连通块
	for(int u = 1; u <= n; u++){
		if(vis[u] == false){//如果还有没遍历的连通块
			block++;//连通块+1
			BFS(u);//继续BFS
		}
	}
}

int main()
{
	scanf("%d", &n);//输入节点的个数
	for(int i = 1; i < n; i++){
		int id1, id2;
		scanf("%d%d", &id1, &id2);//输入边的两个结点
		Adj[id1].push_back(id2);//创建图的结构
		Adj[id2].push_back(id1);
	}
	for(int s = 1; s <= n; s++){
		if(block > 1) break;//如果连通块大于1，则退出
		memset(vis, 0, sizeof(vis));//vis数组初始化
		BFSTrave(s);//BFS
	}
	if(block > 1){//如果连通块大于1
		printf("Error: %d components", block);
	} else {//如果连通块等于1
		for(int i = 0; i < ansNum; i++){
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
