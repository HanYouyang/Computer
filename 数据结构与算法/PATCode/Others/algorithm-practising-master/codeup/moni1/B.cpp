//2016年3月8日19时20分52秒
//2016年3月8日20时20分41秒
//codeup题目编号27731
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 33;
struct Node{
	int data;
	Node *left, *right;
}*root1, *root2;
int n, num1[maxn] = {0}, num2[maxn] = {0};
int numPostPrint = 0, numLayerPrint = 0;

void insert(Node * &root, int n)
{
	if(root == NULL){
		root = new Node;
		root->data = n;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if(root->data > n) insert(root->left, n);
	else insert(root->right, n);
}

Node * insertTree(int num[], int n)
{
	Node *root = NULL;
	for(int i = 0; i < n; i++){
		insert(root, num[i]);
		//printf("%d\n", root->data);
	}
	return root;
}

bool judge(Node *root1, Node *root2)
{
	if(root1 != NULL && root2 != NULL){
		return judge(root1->left, root2->left) && judge(root1->right, root2->right);
	} else {
		if(root1 == NULL && root2 == NULL) return true;
		else return false;
	}
}

void PostOrder(Node *root)
{
	if(root == NULL){
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d", root->data);
	numPostPrint++;
	if(numPostPrint < n) printf(" ");
	else printf("\n");
}

void LayerOrder(Node *root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *now = q.front();
		q.pop();
		printf("%d", now->data);
		numLayerPrint++;
		if(numLayerPrint < n) printf(" ");
		else printf("\n");
		if(now->left != NULL) q.push(now->left);
		if(now->right != NULL) q.push(now->right);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num1[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &num2[i]);
	}
	root1 = insertTree(num1, n);
	root2 = insertTree(num2, n);
	if(judge(root1, root2)){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	PostOrder(root1);
	LayerOrder(root1);
	return 0;
}
