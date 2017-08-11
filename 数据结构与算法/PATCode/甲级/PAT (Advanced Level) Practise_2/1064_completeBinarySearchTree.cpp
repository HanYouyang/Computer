//2016年3月3日20时09分51秒
//2016年3月3日20时25分10秒
/*思路：
	使用数组CBT[maxn]存放完全二叉树的层序遍历序列，则二叉树的结点i的左孩子为i*2 右孩子为i*2+1
	对二叉树进行中序遍历，在遍历过程中将数字从小到大填入数组，最后就能得到一颗完全二叉树
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1010;//最大结点数
int n, sequ[maxn], CBT[maxn] = {0}, index = 0;
//实际结点数，结点值序列，层序序列，结点值序列的下标
void inOrder(int root)
{//中序遍历
	if(root > n) return;//当节点下标大于结点数n时返回
	inOrder(root * 2);
	CBT[root] = sequ[index++];//将数据从小到大赋值
	inOrder(root * 2 + 1);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &sequ[i]);
	}
	sort(sequ, sequ + n);//从小到大排序
	inOrder(1);//根节点为1号位
	for(int i = 1; i <= n; i++){
		printf("%d", CBT[i]);
		if(i < n) printf(" ");
		else printf("\n");
	}
	return 0;
}
