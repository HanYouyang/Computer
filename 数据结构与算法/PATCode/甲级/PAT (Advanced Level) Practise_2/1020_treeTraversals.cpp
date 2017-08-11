//2016年3月1日10时23分26秒
//2016年3月1日10时45分44秒
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct node{//树的节点结构
	int data;
	node * lchild;
	node * rchild;
};
const int maxn = 30;//最大节点数
int n, post[maxn], in[maxn];//实际节点数，后序，中序

node * create(int postL, int postR, int inL, int inR)
{//当前二叉树的后序序列区间为[postL, postR], 中序序列区间为[inL, inR]
//create函数返回构建出的二叉树的根节点地址
	if(postL > postR) return NULL;//长度小于0，直接返回
	node * root = new node;//新建一个新的节点，用来存放当前二叉树的根节点
	root->data = post[postR];//新节点的数据域为根节点的值
	int k;//标记中序中根节点的位置
	for(k = inL; k <= inR; k++){
		if(in[k] == post[postR])//找到中序序列中根节点的位置时，退出循环
			break;
	}
	int numLeft = k - inL;//左子树的节点个数
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	//返回左子树的根结点地址，赋值给root的左指针
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	//返回右子树的根节点地址，赋值给root的右指针
	return root;//返回根结点地址
}

void layerOrder(node * root)
{//层序遍历
	queue<node*> q;//队列里存的是地址
	q.push(root);//将根结点地址入队
	while(!q.empty()){//队列非空，则继续循环
		node * now = q.front();//取出队首元素
		q.pop();//队首元素出队
		if(now != root) printf(" ");//如果当前结点不是第一个结点,在结点data前输出空格
		printf("%d", now->data);//输出队首元素值
		if(now->lchild != NULL) q.push(now->lchild);//左子树非空入队
		if(now->rchild != NULL) q.push(now->rchild);//右子树非空入队
	}
}

int main()
{
	scanf("%d", &n);//输入节点个数
	for(int i = 0; i < n; i++){//输入后序遍历序列
		scanf("%d", &post[i]);
	}
	for(int i = 0; i < n; i++){//输入中序遍历序列
		scanf("%d", &in[i]);
	}
	node * root = create(0, n - 1, 0, n - 1);//根据后序和中序创建二叉树
	layerOrder(root);//层序遍历
	return 0;
}
