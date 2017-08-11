//2016年3月3日17时44分44秒
//2016年3月3日19时06分06秒
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};//二叉查找树用结构体存储

int n;
vector<int> origin, pre, preM, post, postM;
//原始序列，先序遍历序列，先序镜像遍历序列，后序遍历序列，后序镜像遍历序列
//使用vector可以方便地使用 “>” “<” “==” “=”等操作*********************************
//如果使用数组只能使用循环
void insert(Node * &root, int data)
{//建树过程插入节点，根节点必须使用引用
//一般来说，如果函数中需要新建节点，即对二叉树的结构做出修改的话，就需要加引用；
//而如果只是修改当前已有节点的内容，或仅仅是遍历树，则不需要加引用。
	if(root == NULL){
		root = new Node;//新建结点不可写成Node * root = new Node;这样写是局部变量，函数返回时变量就失效
		root->data = data;
		root->left = root->right = NULL;//必须让叶子结点的左右孩子结点为空
		return;
	}
	if(data < root->data) insert(root->left, data);//插在左子树
	else insert(root->right, data);//插在右子树
}

void preOrder(Node * root, vector<int> &pre)
{//先序遍历，结果存于pre
	if(root == NULL) return;
	pre.push_back(root->data);
	preOrder(root->left, pre);
	preOrder(root->right, pre);
}

void preOrderMirror(Node * root, vector<int> &preM)
{//镜像树先序遍历，结果存于preM
	if(root == NULL) return;
	preM.push_back(root->data);
	preOrderMirror(root->right, preM);
	preOrderMirror(root->left, preM);
}

void postOrder(Node * root, vector<int> &post)
{//后序遍历，结果存于post
	if(root == NULL) return;
	postOrder(root->left, post);
	postOrder(root->right, post);
	post.push_back(root->data);
}

void postOrderMirror(Node * root, vector<int> &postM)
{//镜像树后序遍历，结果存于postM
	if(root == NULL) return;
	postOrderMirror(root->right, postM);
	postOrderMirror(root->left, postM);
	postM.push_back(root->data);
}

void print(vector<int> &temp)
{//输出相应的遍历序列
	for(int i = 0; i < temp.size(); i++){
		printf("%d", temp[i]);
		if(i < temp.size() - 1) printf(" ");
		else printf("\n");
	}
}

int main()
{
	Node * root = NULL;//定义头结点
	scanf("%d", &n);//输入结点个数
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		origin.push_back(temp);//将数据加入origin
		insert(root, temp);//将data插入二叉树
	}
	preOrder(root, pre);//求先序序列
	preOrderMirror(root, preM);//求镜像树先序序列
	postOrder(root, post);//求后序序列
	postOrderMirror(root, postM);//求镜像树后序序列
	if(pre == origin){//如果原始序列是先序序列
		printf("YES\n");
		print(post);//输出后序序列
	} else if(preM == origin) {//如果原始序列是镜像树先序序列
		printf("YES\n");
		print(postM);//输出镜像树后序序列
	} else {
		printf("NO\n");//输出NO
	}
	return 0;
}
