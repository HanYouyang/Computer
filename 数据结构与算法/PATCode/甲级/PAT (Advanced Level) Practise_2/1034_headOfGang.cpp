//2016年3月5日14时13分42秒
//2016年3月5日14时45分08秒
//最下面有图的DFS模板
/*思路
	需要处理的变量：
		姓名到编号的转化与编号到姓名的转换	//均使用map
		记录最后结果gang的头目与人数的对应关系	//使用map（满足元素按照字典序从小到大的顺序输出），也可以用结构体
		点权直接用数组在开始输入数据的时候就记录下来
		边权存储在图中
		深度遍历需要做的事情只是记录每个连通块成员人数，成员头目，以及连通块的总边权******************************
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

const int maxn = 2020;//总人数 因为通话记录最多有1000条，所以总人数最多有2000人

map<string, int> string2int;//姓名->编号
map<int, string> int2string;//编号->姓名
map<string, int> gang;//head->人数
int G[maxn][maxn] = {0}, weight[maxn] = {0};
//邻接矩阵G、点权weight
int n, k, numPerson = 0;//边数n，下限k，总人数numPerson
bool vis[maxn] = {false};//标记是否被访问

int change(string str)
{//返回姓名str对应的编号（同时编号也可标记总人数）
	if(string2int.find(str) != string2int.end()){
		return string2int[str];//已经记录，则直接返回编号
	} else {
		string2int[str] = numPerson;//str的编号为numPerson
		int2string[numPerson] = str;//numPerson对应str
		return numPerson++;//总人数加1
	}
}

void DFS(int nowVisit, int& head, int& numMember, int& totalValue)
{//访问单个连通块，nowVisit为当前访问的编号
//head为头目，numMember为成员数量，totalValue为连通块的总边权
	numMember++;//成员人数加1
	vis[nowVisit] = true;//标记nowVisit已访问
	if(weight[nowVisit] > weight[head]){
		head = nowVisit;//当前访问结点的点权大于头目的点权，则更新头目
	}
	for(int i = 0; i < numPerson; i++){//枚举所有人
		if(G[nowVisit][i] > 0){//如果从nowVisit能到达i
			totalValue += G[nowVisit][i];//连通块的总边权增加该边权
			G[nowVisit][i] = G[i][nowVisit] = 0;//删除这条边，防止回头
			if(vis[i] == false){//如果i未被访问，则递归访问i
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}

void DFSTrave()
{//DFSTrave函数遍历整个图，获取每个连通块的信息
	for(int i = 0; i < numPerson; i++){//枚举所有人
		if(vis[i] == false){//如果i未被访问
			int head = i, numMember = 0, totalValue = 0;
			//头目，成员数，总边权
			DFS(i, head, numMember, totalValue);//遍历i所在的连通块
			if(numMember > 2 && totalValue > k){//成员数大于2且总边权大于k
				gang[int2string[head]] = numMember;//head人数为numMember
			}
		}
	}
}

int main()
{
	string str1, str2;
	int time;
	cin >> n >> k;//输入通话数量和最低门限
	for(int i = 0; i < n; i++){
		cin >> str1 >> str2 >> time;//输入通话两人的姓名，与通话时间
		int id1 = change(str1);//将str1变为id1
		int id2 = change(str2);//将str2变为id2
		weight[id1] += time;//id1的点权增加time
		weight[id2] += time;//id2的点权增加time
		G[id1][id2] += time;//边id1->id2的边权增加time
		G[id2][id1] += time;//边id2->id1的边权增加time
	}
	DFSTrave();//遍历整个图的所有连通块，获取gang的信息
	cout << gang.size() << endl;//gang的个数
	map<string, int>::iterator it;
	for(it = gang.begin(); it != gang.end(); it++){//遍历所有的gang
		cout << it->first << " " << it->second << endl;//输处gang的头目和成员数量
	}
	return 0;
}

////图的DFS邻接矩阵版
//
//int n, G[maxn][maxn];
//bool vis[maxn] = {false};
//
//void DFS(int u, int depth)
//{
//	vis[u] = true;
//	//需要顶点进行的一些操作在这里进行
//	for(int v = 0; v < n; v++){
//		if(G[u][v] > 0 && vis[v] == false){
//			//需要对边进行的一些操作在这里进行
//			DFS(v, depth + 1);
//		}
//	}
//}
//
//void DFSTrave(int u, int depth)
//{
//	for(int u = 0; u < n; u++){
//		if(vis[u] == false){
//			//进入DFS后只对一个连通块进行操作，需要记录连通块中的某些信息可以在这里进行初始化
//			DFS(u, 1);
//			//连通块中的某些信息在这里就已经记录完成，可以对其进行存储或者输出
//		}
//	}
//}
//
////图的DFS邻接表版
//
//vector<int> Adj[maxn];
//int n;
//bool vis[maxn] = {false};
//
//void DFS(int u, int depth)
//{
//	vis[u] = true;
//	for(int i = 0; i < Adj[u].size(); i++){
//		int v = Adj[u][i];//注意实际要遍历的节点存储在Adj[u][i]而不是i
//		if(vis[v] == false){
//			DFS(v, depth + 1);
//		}
//	}
//}
//
//void DFSTrave()
//{
//	for(int u = 0; u < n; u++){
//		if(vis[u] == false){
//			DFS(u, 1);
//		}
//	}
//}
//
