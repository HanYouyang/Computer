//2016年3月1日13时58分48秒
//2016年3月1日15时01分18秒
#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

const int maxn = 30;//结点的最大数量为30
int n, data, num = 0;//实际结点数，结点值，已经输出节点数
char op[10];//存储操作英文名 Push 或 Pop
bool lastPop = false;//上一个操作是否是Pop操作，如果是且这次操作是Push，
			//则新的节点为上一个结点的右孩子，否则为左孩子

struct node {//二叉树的结点结构
	int data;
	node * lchild;
	node * rchild;
}*last, *root;//上一个操作的节点，根结点

stack<node*> s;//栈用于创建二叉树

node * init(int data)
{//初始化结点
	node * temp = new node;//申请一个内存空间并赋予node结点
	temp->data = data;
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
}

void postOrder(node *root){//后续遍历
	if(root == NULL) return;
	postOrder(root->lchild);//遍历左子树
	postOrder(root->rchild);//遍历右子树
	printf("%d", root->data);//输出
	num = num + 1;
	if(num < n) printf(" ");//如果不是最后一个，则输出空格
}

int main()
{
	scanf("%d", &n);
	root = init(0);//这个根节点相当于链表中的头结点，为了好操作
	last = root;//上一个节点等于root
	for(int i = 0; i < 2 * n; i++){//对于每一个输入
		scanf("%s", op);
		if(strcmp(op, "Push") == 0){//如果是Push
			scanf("%d", &data);//输入数据
			node * now = init(data);
			if(lastPop == true){//上一个操作是Pop
				last->rchild = now;//右孩子
			} else {//上一个操作不是Pop
				last->lchild = now;//左孩子
			}
			s.push(now);//入栈
			last = now;//更新上一个操作结点
			lastPop = false;//更新是否是Pop
		} else {//如果是Pop
			last = s.top();//更新上一个操作结点
			s.pop();//弹出结点
			lastPop = true;//更新是否时Pop
		}
	}
	postOrder(root->lchild);//后续遍历输出二叉树
	return 0;
}
