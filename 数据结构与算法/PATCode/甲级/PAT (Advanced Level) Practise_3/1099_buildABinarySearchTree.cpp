//2016年3月3日20时46分27秒
//2016年3月3日21时00分47秒
/*思路
	题目直接给出了结点编号的关系，因此使用二叉树的静态写法。
	与1064题相同的思路，对于一棵二叉查找树，中序遍历序列是递增的。因此我们只需要把
	给定的整数序列从小到达排序，然后对给定的二叉树进行中序遍历，将排序序列的整数
	按中序遍历的顺序填入二叉树，就可以形成二叉查找树。
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 110;//结点最大数目

struct Node{
	int data;
	int left, right;
}node[maxn];//静态链表存储树的结构

int n, seq[maxn], index = 0, layer[maxn];
//实际结点数目，初始序列（需要排序），初始序列的下标，层序序列
int printNum = 0;
//输出时记录已经输出的个数，用来控制空格的输出

void inOrder(int root)
{//中序遍历序列实现结点赋值
	if(root == -1) return;
	inOrder(node[root].left);
	node[root].data = seq[index++];//填入序列中的整数，并且下标自动加1
	inOrder(node[root].right);
}

void layerOrder(int root)
{//层序遍历并输出
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();//取出队首元素
		q.pop();
		printf("%d", node[now].data);
		printNum++;
		if(printNum < n) printf(" ");//输出个数小于n，输出空格
		if(node[now].left != -1) q.push(node[now].left);//左子树非空
		if(node[now].right != -1) q.push(node[now].right);//右子树非空
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int left, right;
		scanf("%d%d", &left, &right);//左右孩子编号
		node[i].left = left;
		node[i].right = right;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &seq[i]);//输入排序前的序列
	}
	sort(seq, seq + n);//对序列进行排序
	inOrder(0);//以0号结点为根结点进行中序遍历，填入整数
	layerOrder(0);//输出层序遍历序列
	return 0;
}
