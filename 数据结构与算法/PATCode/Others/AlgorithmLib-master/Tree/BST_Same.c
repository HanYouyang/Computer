//判断二叉排序树是否相同
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
char str1[25], str2[25];
int size1, size2;
char *str;
int *size;

void PostOrder(Node *T)	//后序遍历
{
	if (T->lchild != NULL)
		PostOrder(T->lchild);
	if (T->rchild != NULL)
		PostOrder(T->rchild);
	str[(*size)++] = T->c + '0';
}

void InOrder(Node *T)	//中序遍历
{
	if (T->lchild != NULL)
		InOrder(T->lchild);

	str[(*size)++] = T->c + '0';

	if (T->rchild != NULL)
		InOrder(T->rchild);
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
	else if (x > T->c)
		T->rchild = Insert(T->rchild, x);
	return T;
}

int main()
{
	int n;
	char tmp[12];
	while (scanf("%d", &n) != EOF && n != 0)
	{
		loc = 0;
		Node *T = NULL;
		scanf("%s", tmp);
		for (int i = 0; tmp[i] != 0; i++)
		{
			T = Insert(T, tmp[i]-'0');
		}
		size1 = 0;
		str = str1;
		size = &size1;
		PostOrder(T);
		InOrder(T);
		str1[size1] = 0;

		while(n-- != 0)
		{
			scanf("%s", tmp);
			Node *T2 = NULL;
			for (int i = 0; tmp[i] != 0; i++)
			{
				T2 = Insert(T2, tmp[i]-'0');
			}
			size2 = 0;
			str = str2;
			size = &size2;
			PostOrder(T2);
			InOrder(T2);
			str2[size2] = 0;
			puts(strcmp(str1, str2) == 0?"YES":"NO");
		}
	}
	return 0;
}