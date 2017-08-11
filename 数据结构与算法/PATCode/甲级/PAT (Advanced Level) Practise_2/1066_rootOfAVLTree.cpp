//2016年3月3日21时37分31秒
//2016年3月3日22时15分20秒
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 25;//结点总数
int n, data[maxn];//实际结点数，结点权值保存在数组里

struct Node{
	int data, height;//结点权值，结点高度
	Node *left, *right;//左右孩子结点地址
};//结点的结构体结构

Node * newNode(int data)
{//生成一个新的结点，data为结点权值
	Node * root = new Node;//申请一个Node型变量的地址空间
	root->data = data;
	root->height = 1;//初始高度为1（因为刚插入一定是在叶子结点）
	root->left = root->right = NULL;//初始状态下没有左右孩子********
	return root;//返回新建结点的地址
}

int getHeight(Node * root)
{//获取以root为根结点的子树的当前height
	if(root == NULL) return 0;//如果root节点为空，返回0
	else return root->height;
}

void updateHeight(Node * root)
{//更新结点root的height
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBalanceFactor(Node * root)
{//计算结点root的平衡因子
	return getHeight(root->left) - getHeight(root->right);
}

void L(Node * &root)
{//左旋（Left Rotation）
	Node * temp = root->right;//root指向根结点，temp指向根结点的右孩子
	root->right = temp->left;//step1
	temp->left = root;//step2
	updateHeight(root);//更新root的高度
	updateHeight(temp);//更新temp的高度，必须在更新root高度之后**********
	root = temp;//现在temp为新的root
}

void R(Node * &root)
{//右旋（Right Rotation）
	Node * temp = root->left;//root指向根结点，temp指向根结点左孩子
	root->left = temp->right;//step1
	temp->right = root;//step2
	updateHeight(root);//更新root的高度
	updateHeight(temp);//更新temp的高度，必须在更新root高度之后**********
	root = temp;//现在temp为新的root
}

void insert(Node * &root, int data)
{//插入权值为data的结点
	if(root == NULL){//到达空结点
		root = newNode(data);
		return;
	}
	if(data < root->data){//data比根结点权值小
		insert(root->left, data);//插入到根结点的左子树
		updateHeight(root);//更新树高
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->left) == 1){//LL型
				R(root);
			} else if(getBalanceFactor(root->left) == -1){//LR型
				L(root->left);
				R(root);
			}
		}
	} else {//data比根结点权值大
		insert(root->right, data);//插入到根结点的右子树
		updateHeight(root);//更新树高
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->right) == -1){//RR型
				L(root);
			} else if(getBalanceFactor(root->right) == 1){//RL型
				R(root->right);
				L(root);
			}
		}
	}
}

Node * create(int data[], int n)
{//建立AVL树
	Node * root = NULL;//新建空根结点root
	for(int i = 0; i < n; i++){
		insert(root, data[i]);//将data[0]~data[n-1]插入到AVL树中
	}
	return root;//返回根结点
}

int main()
{
	scanf("%d", &n);//输入结点的个数
	for(int i = 0; i < n; i++){//输入每个结点的权值
		scanf("%d", &data[i]);
	}
	Node * root = create(data, n);//建立AVL树
	printf("%d\n", root->data);//输出根结点的权值
	return 0;
}
