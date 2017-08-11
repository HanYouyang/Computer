//2016年3月2日19时57分34秒
//2016年3月2日20时11分30秒
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100;//结点的最大数目
vector<int> node[maxn];//存放树
int n, m, maxLevel = 0;//实际结点数，非叶子结点数，最大深度
int hashTable[maxn] = {0};//存放每层的叶子结点数，跟结点为第一层

void DFS(int index, int depth)
{//深度遍历，index为当前遍历到的结点编号，depth为当前结点的深度
	maxLevel = max(depth, maxLevel);//标记最大深度为maxLeval
	if(node[index].size() == 0){//如果当前结点是叶结点
		hashTable[depth]++;//记录该层叶结点的变量+1
		return;
	}
	for(int i = 0; i < node[index].size(); i++){
		DFS(node[index][i], depth + 1);//枚举所有孩子结点
	}
}

int main()
{
	scanf("%d%d", &n, &m);//实际结点数，非叶子结点数
	for(int i = 0; i < m; i++){//输入每个非叶子结点的孩子结点并记录
		int father, childNum, child;//双亲节点，孩子节点数，孩子节点
		scanf("%d%d", &father, &childNum);
		for(int j = 0; j < childNum; j++){
			scanf("%d", &child);
			node[father].push_back(child);//将孩子结点加到双亲存储孩子结点的vector中
		}
	}
	DFS(1, 1);//初始入口为根结点与第一层
	for(int i = 1; i <= maxLevel; i++){
		printf("%d", hashTable[i]);//输出
		if(i < maxLevel) printf(" ");//为了最后一个输出后面没有空格
	}
	return 0;
}
