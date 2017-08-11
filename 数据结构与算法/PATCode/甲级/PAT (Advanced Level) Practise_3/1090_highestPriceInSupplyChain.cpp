//2016年3月2日13时35分19秒
//2016年3月2日13时59分56秒
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int maxn = 100010;//最大结点数
int n, root, maxDepth = -1, maxNum = 0;//实际结点数，根结点，最大深度，处于最大深度的节点数目
double p, r;//单价，提价百分比r%

vector<int> child[maxn];//存放树的孩子结点

void DFS(int index, int depth)
{//深度遍历求最大深度
	if(child[index].size() == 0){//到达叶结点
		if(depth > maxDepth){//深度比最大深度大
			maxDepth = depth;//更新最大深度
			maxNum = 1;//重置最大深度叶结点个数为1
		} else if(depth == maxDepth){//深度等于最大深度
			maxNum++;//最大深度叶结点个数加1
		}
		return;
	}
	for(int i = 0; i < child[index].size(); i++){
		DFS(child[index][i], depth + 1);//递归访问结点index的孩子结点
	}
}

int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	for(int i = 0; i < n; i++){
		int father;//父结点
		scanf("%d", &father);
		if(father == -1){//父结点为-1
			root = i;//i为根结点
		} else {//i是father的子结点
			child[father].push_back(i);
		}
	}
	DFS(root, 0);//DFS入口
	printf("%.2f %d\n", p * pow(1 + r * 0.01, maxDepth), maxNum);//输出结果
	return 0;
}
