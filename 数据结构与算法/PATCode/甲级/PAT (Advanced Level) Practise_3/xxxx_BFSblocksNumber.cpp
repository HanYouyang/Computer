//2016年2月28日14时35分20秒
//2016年2月28日
/*题目
	给出m*n矩阵，矩阵中的元素为0或1.我们称位置(x, y)与其上下左右四个
	位置(x, y+1), (x, y-1), (x+1, y), (x-1, y)是相邻的（不必两两相邻）
	那么我们称这些1构成了一个“块”。求给定的矩阵中“块”的个数
	0 1 1 1 0 0 1
	0 0 1 0 0 0 0
	0 0 0 0 1 0 0
	0 0 0 1 1 1 0
	1 1 1 0 1 0 0
	1 1 1 1 0 0 0
	例如上面的6*7矩阵中，“块”的个数为4
	输入格式：
	6 7//6行7列
	0 1 1 1 0 0 1
        0 0 1 0 0 0 0
        0 0 0 0 1 0 0
        0 0 0 1 1 1 0
        1 1 1 0 1 0 0
        1 1 1 1 0 0 0
*/

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 100;
struct Node{
//用结构体保存位置
	int x, y;
}node;
int n, m;//矩阵大小是n*m
int matrix[maxn][maxn];//存储01矩阵
bool inq[maxn][maxn] = {false};//是否进入过队列
int X[4] = {0, 0, 1, -1};//x增量数组
int Y[4] = {1, -1, 0, 0};//y增量数组

bool judge(int x, int y){
	if(x >= n || x < 0 || y >= m || y < 0) return false;
	//越界返回false
	if(matrix[x][y] == 0 || inq[x][y] == true) return false;
	//矩阵元素为0或者已经入队返回false
	return true;
}

void BFS(int x, int y)
{
	queue<Node> q;//定义队列
	node.x = x; node.y =  y;//当前节点坐标为(x, y)
	q.push(node);//将节点Node入队
	inq[x][y] = true;//节点入队标志置为true
	while(!q.empty()){//当队列不为空是循环
		Node top = q.front();//取出队首元素
		q.pop();//队首元素出队
		for(int i = 0; i < 4; i++){//循环四次，得到四个相邻位置
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			if(judge(newX, newY)){//如果新位置需要访问
				node.x = newX; node.y = newY;
				q.push(node);//将新位置节点入队
				inq[newX][newY] = true;//节点入队标志置为true
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);//n*m矩阵
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &matrix[i][j]);//输入矩阵元素
		}
	}
	int ans = 0;//存放块数
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 1 && inq[i][j] == false){
				ans++;//当节点值为1且没被访问时，块数+1
				BFS(i, j);//访问整个块，将该块所有的1的inq都标记为true
			}
		}
	}
	printf("%d\n", ans);//输出块数
	return 0;
}
