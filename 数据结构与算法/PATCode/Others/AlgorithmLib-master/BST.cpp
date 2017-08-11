//PAT_1043. Is It a Binary Search Tree (25)
//把这道题目作为二叉树的练习结尾题
//Miibotree
//2015.2.28
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> Origin, preOrder, MpreOrder, postOrder, MpostOrder;

struct Node{
	int key;
	Node *lchild;
	Node *rchild;
}Tree[1001];
int loc = 0;

int a[1001];

Node *Create()
{
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

Node *Build(Node *T, int data)
{
	if(T == NULL)//空树
	{
		T = Create();
		T->key = data;
	}
	if(data < T->key)
		T->lchild = Build(T->lchild, data);
	else
		T->rchild = Build(T->rchild, data);
	return T;
}

void GetPreOrder(Node *root)
{
	if(root == NULL)
		return;
	preOrder.push_back(root->key);
	GetPreOrder(root->lchild);
	GetPreOrder(root->rchild);
}

void GetMPreOrder(Node *root)
{
	if(root == NULL)
		return;
	MpreOrder.push_back(root->key);
	GetMPreOrder(root->rchild);
	GetMPreOrder(root->lchild);	
}

void GetPostOrder(Node *root)
{
	if(root == NULL)
		return;
	GetPostOrder(root->lchild);
	GetPostOrder(root->rchild);
	postOrder.push_back(root->key);
}

void GetMPostOrder(Node *root)
{
	if(root == NULL)
		return;
	GetMPostOrder(root->rchild);
	GetMPostOrder(root->lchild);
	MpostOrder.push_back(root->key);
}

int Compare()
{
	//先判断是不是MST
	int i;
	for(i = 0; i < Origin.size(); i++)
	{
		if(Origin[i] != preOrder[i])
			return -1;
	}
	if (i == Origin.size())
		return 1;
	for(i = 0; i < Origin.size(); i++)
	{
		if(Origin[i] != MpreOrder[i])
			return -1;
	}
	if (i == Origin.size())
		return 2;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		Node *root = NULL; 
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			root = Build(root, a[i]);
			Origin.push_back(a[i]);
		}
		GetPreOrder(root);
		GetMPreOrder(root);
		GetPostOrder(root);
		GetMPostOrder(root);
		int flag = Compare();
		if(flag == -1)
			printf("NO\n");
		else if(flag == 1)
		{
			for(int i = 0; i < postOrder.size() - 1; i++)
				printf("%d ", postOrder[i]);
			printf("%d\n", postOrder[postOrder.size() - 1]);
		}
		else
		{
			for(int i = 0; i < MpostOrder.size() - 1; i++)
				printf("%d ", MpostOrder[i]);
			printf("%d\n", MpostOrder[MpostOrder.size() - 1]);
		}
	}
	return 0;
}