//2016年3月2日19时21分31秒
//2016年3月2日19时39分14秒
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 100010;最大结点书目
int n, lowestDepth, lowestNum = 0;
//实际结点数目，叶子结点的最小深度，最小深度中叶子结点个数
double p, r;//单价，提价比
vector<int> node[maxn];//存放树的孩子信息，其中下标标志树的结点

void DFS(int index, int depth)
{//深度优先遍历找到每个有最小深度的叶子结点
	//if(depth > lowestDepth) return;//剪枝，对于深度大于已知最小深度，直接返回
	if(node[index].size() == 0){//如果是叶子结点
		if(depth < lowestDepth){//如果该叶子结点的深度比最小深度小
			lowestDepth = depth;//更新最小深度
			lowestNum = 1;//更新最小深度中叶子结点个数为1
		} else if(depth == lowestDepth){//如果该叶子结点在最小深度中
			lowestNum++;//最小深度中叶子结点个数+1
		}
		return;//返回
	}
	if(depth < lowestDepth){//剪枝,在PAT平台上这种写法的剪枝与不剪枝时间相同，为什么？？？？？？？？？？？
		for(int i = 0; i < node[index].size(); i++){
			DFS(node[index][i], depth + 1);//递归遍历每一个叶子节点
		}
	}
}

int main()
{
	scanf("%d%lf%lf", &n, &p, &r);//输入结点个数，单价，提价比
	for(int i = 0; i < n; i++){//对每个结点
		int k;
		scanf("%d", &k);//输入孩子结点个数
		if(k != 0){//如果有孩子结点
			for(int j = 0; j < k; j++){
				int child;
				scanf("%d", &child);//输入孩子结点
				node[i].push_back(child);//将孩子节点存放在vector中
			}
		}
	}
	lowestDepth = n;//初始化最小深度为结点个数（取不到的最大值）
	DFS(0, 0);//深度遍历入口
	printf("%.4f %d\n", p * pow(1 + r * 0.01, lowestDepth), lowestNum);//输出
	return 0;
}
