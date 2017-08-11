//2016年3月2日13时15分39秒
//2016年3月2日13时25分50秒
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 100010;//最大结点数

struct Node{
	int data;
	vector<int> child;
}node[maxn];
int n;
double p, r, total;

void DFS(int index, int depth)//当前处理的结点，当前结点的深度
{//深度遍历过程中求出最终结果
	if(node[index].child.size() == 0){//如果是叶子节点
		total += p * node[index].data * pow(1 + r * 0.01, depth);
		return;
	}
	for(int i = 0; i < node[index].child.size(); i++){
		DFS(node[index].child[i], depth + 1);//如果不是叶子节点，对孩子结点继续递归，递归深度参数 + 1
	}
}

int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	for(int i = 0; i < n; i++){
		int tempNum;
		scanf("%d", &tempNum);
		if(tempNum == 0){//如果是叶子节点，输入产品量
			scanf("%d", &node[i].data);
		} else {//不是叶子节点，输入孩子结点
			for(int j = 0; j < tempNum; j++){
				int child;
				scanf("%d", &child);
				node[i].child.push_back(child);
			}
		}
	}
	DFS(0, 0);//进行递归
	printf("%.1f\n", total);//输出
	return 0;
}

//下面的方法是边输入边处理，测试点0（12分）过不去
//原因是因为下面的方法是错误的。不能输入边处理的原因是当输入结点1孩子的信息时，
//可能并不知道结点1的父结点的信息，因此有一种情况就是结点1还没初始化，就开始初始化结点1孩子结点的信息
//比如下面这一组数据
/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
*/
//结点9是结点1的孩子，但是输入结点9的时候并不知道结点1处在第几层，只有到第五个结点时才能够确定节点1的层数
//因此边输入边处理是错误的，要先根据输入信息构造出整个树

////2016年3月2日10时54分20秒
////2016年3月2日11时44分33秒
//#include <cstdio>
//#include <cmath>
//
//const int maxn = 100010;//供应链最大的结点数
//int n;//实际结点数
//double p, r;//单价，价格提高的百分比
//double total = 0.0;//最后输出的总价格
//
//struct node{
//	int layer;//该结点的层数
//	int product;//该结点的产品数
//}Node[maxn];//结点
//
//int main()
//{
//	scanf("%d%lf%lf", &n, &p, &r);
//	r /= 100;
//	Node[0].layer = 0;//根结点为第0层
//	for(int i = 0; i < n; i++){
//		int num;//当前结点i的孩子结点数
//		scanf("%d", &num);
//		if(num == 0){//如果当前结点i为叶子结点
//			scanf("%d", &Node[i].product);//输入当前的产品数
//		} else {//当前结点i不是叶子结点
//			Node[i].product = 0;//产品数为0
//			for(int j = 0; j < num; j++){//输入每个孩子结点
//				int child;
//				scanf("%d", &child);//输入孩子结点
//				Node[child].layer = Node[i].layer + 1;//设置孩子节点的层数
//			}
//		}
//	}
//	for(int i = 0; i < n; i++){
//		if(Node[i].product != 0){//如果该结点是叶子结点
//			total += Node[i].product * pow(1 + r, Node[i].layer);
//			printf("%f\n",  Node[i].product * pow(1 + r, Node[i].layer));
//			if(i == 9) printf("%d\n", Node[i].layer);
//		}
//	}
//	printf("%.2f\n", total * p);//输出总价格
//	return 0;
//}
