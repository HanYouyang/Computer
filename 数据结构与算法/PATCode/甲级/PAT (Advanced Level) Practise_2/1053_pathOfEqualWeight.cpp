//2016年3月3日15时10分35秒
//2016年3月3日16时30分00秒
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 110;//结点最大数目
int n, m, s, path[maxn] = {0};
//实际结点数，非叶结点数，Equal weight，路径上的节点下标
struct Node{
	int weight;
	vector<int>  child;
}node[maxn];//静态二叉链表

bool cmp(int a, int b)
{//在输入孩子节点完毕后对孩子结点的全值按照从大到小排序
	return node[a].weight > node[b].weight;
}

void DFS(int index, int numNode, int sum)
{
	if(sum > s) return;
	if(sum == s){
		if(node[index].child.size() != 0) return;//如果不是叶子节点，返回
		for(int i = 0; i < numNode; i++){
			printf("%d", node[path[i]].weight);
			if(i < numNode - 1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for(int i = 0; i < node[index].child.size(); i++){
		int child = node[index].child[i];
		path[numNode] = child;//记录当前检索的路径结点下标
		DFS(child, numNode + 1, sum + node[child].weight);
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 0; i < n; i++){
		scanf("%d", &node[i].weight);
	}
	for(int i = 0; i < m; i++){
		int id, k, child;
		scanf("%d%d", &id, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			node[id].child.push_back(child);
		}
		sort(node[id].child.begin(), node[id].child.end(), cmp);
		//对结点孩子从大到小排序
	}
	DFS(0, 1, node[0].weight);//遍历入口
	return 0;
}
