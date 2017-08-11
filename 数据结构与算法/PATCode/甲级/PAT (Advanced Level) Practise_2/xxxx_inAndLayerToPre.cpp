//2016年3月2日16时02分44秒
//2016年3月2日16时26分13秒
//这是一个根据层序序列和中序序列建树，并求其先序序列的代码
#include <cstdio>

const int maxn = 50;
int n, pre[maxn], in[maxn], layer[maxn];
int printNum = 0;
struct Node{
	int data;
	Node * lchild;
	Node * rchild;
};

Node * create(int layerL, int layerR, int inL, int inR)
{//建树，返回根结点
	if(inL > inR) return NULL;//如果中序序列左边界大于右边界，返回NULL
	//先不申请内存创建节点，首先查找层序序列的第一个元素是否在中序序列中
	int k;
	for(k = inL; k <= inR; k++){//在中序序列中找层序的第一个结点
		if(in[k] == layer[layerL]){
			break;
		}
	}
	if(k > inR){//如果没找到，则删除层序的第一个结点，其他不变，继续创建
		return create(layerL + 1, layerR, inL, inR);
	} else {//如果找到了
		Node * root = new Node;
		root->data = layer[layerL];//申请内存空间新建根结点
		int numLeft = k - inL;//左子树结点个数
		root->lchild = create(layerL + 1, layerR, inL, k - 1);//递归创建左子树
		root->rchild = create(layerL + 1, layerR, k + 1, inR);//递归创建右子树
		return root;
	}
}

void DFS(Node * root){//深度优先遍历输出二叉树的先序序列
	if(root == NULL) return;
	printf("%d", root->data);
	printNum++;
	if(printNum < n) printf(" ");
	DFS(root->lchild);
	DFS(root->rchild);
}

int main()
{
	scanf("%d", &n);//输入结点数目
	for(int i = 0; i < n; i++){
		scanf("%d", &layer[i]);//先输入层序序列
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &in[i]);//再输入中序序列
	}
	Node * root = create(0, n-1, 0, n-1);//建树
	DFS(root);//输出先序序列
	return 0;
}
