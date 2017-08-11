//2016年3月8日16时19分09秒
//2016年3月8日16时49分24秒
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1010;//最大结点数
int n, m, k;//结点，边，查询数
vector<int> Adj[maxn];//邻接表存储矩阵
bool vis[maxn];//记录结点是否被访问
int father[maxn];//存放父亲结点

int findFather(int x)
{//查找x所在的根结点
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){//路径压缩
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b)
{//合并a和b的所在的集合
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

void init()
{//初始化father数组与is数组//每一次查询都要初始化**************************************
	for(int i = 1; i <= maxn; i++){
		father[i] = i;
		vis[i] = false;
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);//输入结点数，边数，查询数
	for(int i = 0; i < m; i++){
		int c1, c2;
		scanf("%d%d", &c1, &c2);//输入边的两个结点
		Adj[c1].push_back(c2);//边a->b
		Adj[c2].push_back(c1);//边b->a
	}
	for(int query = 0; query < k; query++){
		init();//初始化********************************************************
		int city;
		scanf("%d", &city);//输入查询的结点
		for(int i = 1; i <= n; i++){//对每一个结点（节点不是0，要从1开始遍历到n，题目给的条件）
			for(int j = 0; j < Adj[i].size(); j++){
				int u = i, v = Adj[i][j];//边的两个结点
				if(u == city || v == city) continue;//如果是被攻占的结点，则边失效
				Union(u, v);//负责合并边上的两个结点
			}
		}
		int block = 0;//连通块的个数
		for(int i = 1; i <= n; i++){//遍历所有结点
			if(i == city) continue;//不考虑被攻占的结点
			int faI = findFather(i);//找到节点i的根结点
			if(vis[faI] == false){//如果当前连通块的根结点未被访问
				block++;//连通块个数加1
				vis[faI] = true;//当前连通块的根结点设置已访问
			}
		}
		printf("%d\n", block - 1);//输出连通块个数-1，即需要增加的边的数量
	}
	return 0;
}
