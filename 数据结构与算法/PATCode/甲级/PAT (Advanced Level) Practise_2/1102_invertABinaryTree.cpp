//2016年3月1日15时34分57秒
//2016年3月1日16时14分50秒
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 10;//最大的结点数目
int left[maxn], right[maxn];
//使用数组存储树的左子树left、右子树right；下标为树的值data
int n, num = 0;//结点的实际数目，中序遍历时已输出的节点数目
bool isRoot[maxn];//是否是根结点

void levelOrder(int root)
{//反转的层序遍历
	queue<int> q;//定义一个队列
	q.push(root);//将根结点入队
	while(!q.empty()){//队列不为空
		int now = q.front();//获取队首元素
		q.pop();//队首元素出队
		if(now != root) printf(" ");
		printf("%d", now);//输出当前已遍历的序列
		if(right[now] != -1) q.push(right[now]);//右子树不为空时遍历右子树
		if(left[now] != -1) q.push(left[now]);//左子树不为空时遍历左子树
		//因为题目要求翻转输出链表，所以对右子树的遍历放在左子树之前
	}
	printf("\n");//还要输出翻转的中序遍历，因此要换行
}

void inOrder(int root)
{//反转的中序遍历
	if(root == -1) return;//如果结点为空，返回
	inOrder(right[root]);//遍历右子树
	printf("%d", root);//遍历完右子树时输出当前结点
	num = num + 1;//输出的个数加1，初始为0
	if(num < n) printf(" ");//如果没有输出完，输出空行
	inOrder(left[root]);//遍历左子树
}

int main()
{
	scanf("%d", &n);//输入结点数目
	memset(isRoot, true, sizeof(isRoot));//将isRoot所有元素赋值为true，头文件为cstring
	for(int i = 0; i < n; i++){//对于每一个结点左右子树信息的输入
		char templ, tempr;
		getchar();//吸收换行符，否则scanf会把换行符读入**************************************
		scanf("%c %c", &templ, &tempr);//输入左右子树信息
		if(templ >= '0' && templ <= '9'){//若有左子树
			left[i] = templ - '0';
			isRoot[templ - '0'] = false;//则左子树的根节点不是二叉树根节点
		} else {
			left[i] = -1;//没有左子树时为-1
		}
		if(tempr >= '0' && tempr <= '9'){
			right[i] = tempr - '0';
			isRoot[tempr - '0'] = false;
		} else {
			right[i] = -1;
		}
	}
	int root;//根结点
	for(int i = 0; i < n; i++){
		if(isRoot[i] == true){//找到根结点，赋值，退出
			root = i; break;
		}
	}
	levelOrder(root);//反转层序遍历
	inOrder(root);//反转中序遍历
	printf("\n");
	return 0;
}
