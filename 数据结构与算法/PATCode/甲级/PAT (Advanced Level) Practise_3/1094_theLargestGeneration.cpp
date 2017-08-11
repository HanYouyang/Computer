//2016年3月2日15时35分38秒
//2016年3月2日15时43分54秒
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 110;
int n, k;
vector<int> node[maxn];
int hashTable[maxn] = {0};//使用数组来记录每层的结点个数

void DFS(int root, int level)
{//深度遍历并记录每层结点的个数
	hashTable[level]++;
	for(int i = 0; i < node[root].size(); i++){
		DFS(node[root][i], level + 1);
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < k; i++){
		int father, childNum, child;
		scanf("%d%d", &father, &childNum);//父亲编号，孩子个数
		for(int j = 0; j < childNum; j++){
			scanf("%d", &child);//孩子编号
			node[father].push_back(child);//建树
		}
	}
	DFS(1, 1);//根结点为1号节点，层号为1
	int maxLevel = -1, maxValue = 0;
	for(int i = 1; i <= maxn; i++){//求hashTable的最大值及取得最大值的下标
		if(hashTable[i] > maxValue){
			maxLevel = i;
			maxValue = hashTable[i];
		}
	}
	printf("%d %d\n", maxValue, maxLevel);//输出
	return 0;
}

////BFS 测试点2答案错误
////2016年3月2日14时55分14秒
////2016年3月2日15时25分46秒
//#include <cstdio>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//const int maxn = 110;//最大结点数
//int n, k, maxNum = 1, maxGen = 1;
////实际结点数，有孩子的结点数，最大代的结点数，最大代是第几代
//struct Node{
//	int layer;
//	vector<int> child;
//}node[maxn];//节点
//
//void BFS(int root)
//{//BFS
//	queue<int> q;//定义队列
//	q.push(root);//入队
//	node[root].layer = 1;//根节点的层数为1
//	int thisLayer = node[root].layer;//当前层（初始是第一层）
//	int num = 0;//当前层的结点数
//	while(!q.empty()){//当队列非空时
//		int now = q.front();//取队首元素
//		q.pop();//队首元素出队
//		if(node[now].layer == thisLayer){
//			num++;结点属于当前层，则当前层个数+1
//		} else {//结点不属于当前层
//			if(num > maxNum){//如果当前层个数比最大层大
//				maxNum = num;//更新最大层的个数
//				maxGen = thisLayer;//更新最大层的代
//			}
//			num = 1;//更新当前层的个数
//			thisLayer = node[now].layer;//更新当前层
//		}
//		for(int i = 0; i < node[now].child.size(); i++){
//			int temp = node[now].child[i];
//			q.push(temp);
//			node[temp].layer = node[now].layer + 1;//孩子所在的层数等于当前层+1
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d%d", &n, &k);
//	for(int i = 0; i < k; i++){
//		int father, childNum, child;
//		scanf("%d%d", &father, &childNum);
//		for(int j = 0; j < childNum; j++){
//			scanf("%d", &child);
//			node[father].child.push_back(child);
//		}
//	}
//	if(n){
//		BFS(1);//广度遍历入口
//		printf("%d %d\n", maxNum, maxGen);
//	} else {
//		printf("0 0\n");
//	}
//	return 0;
//}
