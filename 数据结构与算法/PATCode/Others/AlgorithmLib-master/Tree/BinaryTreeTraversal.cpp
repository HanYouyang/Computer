//Binary Tree Trace
//Miibotree
//2015.1.15
//输入前序 中序 输出后序

#include <stdio.h>
#include <string.h>

struct Node{		//二叉树的定义
	Node *lchild;
	Node *rchild;
	char c;
}Tree[50];

Node *create()；							//创建二叉树
void PostOrder(node *T)；					//后序遍历
Node *build(int s1, int e1, int s2, int e2)；

char str1[30], str2[30];
int loc;

int main()
{
	while (scanf("%d", str1) != EOF)
	{
		scanf("%d", str2);
		loc = 0;
		int l1 = strlen(str1);
		int l2 = strlen(str2);
		Node *T = build(0, l1-1, 0，l2-1);
		PostOrder(T);
		printf("\n");
	}
	return 0;
}

Node *create()
{
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

void PostOrder(node *T)
{
	if (T->lchild != NULL)
		PostOrder(T->lchild);
	if (T->rchild != NULL)
		PostOrder(T->rchild);
	printf("%c", T->c);
}

Node *build(int s1, int e1, int s2, int e2)//前序遍历结果为str1[s1]-str1[e1],中序遍历结果为str2[s2]-str2[e2]
{
	Node* ret = create();
	ret->c = str1[s1];//前序遍历的第一个节点肯定是根节点
	int rootIdx;
	for (int i = s2; i <= e2; i++)//在中序遍历里面找根节点
	{
		if (str2[i] == str1[s1])	//找到了
		{
			rootIdx = i;			//把根节点的标号记录下来
			break;
		}
	}
	if (rootIdx != s2)//递归遍历左子树
		ret->lchild = build(s1+1, s1+(rootIdx-s2), s2, rootIdx-1);
	if (rootIdx != e2)//递归遍历右子树
		ret->rchild = build(s1+(rootIdx-s2)+1, e1, rootIdx+1, e2);
	return ret;
}