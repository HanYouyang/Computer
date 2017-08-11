//二叉排序树
//Miibotree
//2015.1.16

#include <stdio.h>
#include <string.h>

struct Node{
	Node *lchild;
	Node *rchild;
	int c;
}Tree[110];
int loc;
Node *Create()
{
	Tree[loc].lchild = NULL;
	Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

void PostOrder(Node *T)	//后序遍历
{
	if (T->lchild != NULL)
		PostOrder(T->lchild);
	if (T->rchild != NULL)
		PostOrder(T->rchild);
	printf("%d ", T->c);
}

void InOrder(Node *T)	//中序遍历
{
	if (T->lchild != NULL)
		InOrder(T->lchild);

	printf("%d ", T->c);

	if (T->rchild != NULL)
		InOrder(T->rchild);
}

void PreOrder(Node *T)	//前序遍历
{
	printf("%d ", T->c);
	if (T->lchild != NULL)
		PreOrder(T->lchild);
	if (T->rchild != NULL)
		PreOrder(T->rchild);
}

Node *Insert(Node *T, int x)//二叉排序树节点插入
{
	if (T == NULL)
	{
		T = Create();
		T->c = x;
		return T;
	}
	else if (x < T->c)//这里没有考虑节点相同的情况
		T->lchild = Insert(T->lchild, x);
	else
		T->rchild = Insert(T->rchild, x);
	return T;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		loc = 0;
		Node *T = NULL;
		for (int i = 0; i < = n; i++)
		{
			int x;
			scanf("%d", &x);
			T = Insert(T, x);
		}

		PreOrder(T);
		printf("\n");
		InOrder(T);
		printf("\n");
		PostOrder(T);
		printf("\n");
	}
	return 0;
}