//2016年2月28日15时52分57秒
//2016年2月28日
/*题目
	在给定一个n*m大小的迷宫，其中"*"代表不可通过的墙壁，而"."代表平地
	S表示起点，T代表终点，如果当前位置为(x, y)（下表从0开始），且每次
	只能前往上下左右(x, y+1), (x, y-1), (x-1, y), (x+1, y)四个位置的平地
	求从起点S到达终点T的最少步数
	输入样例：
	5 5		//5行5列
	.....		//迷宫信息
	.*.*.
	.*S*.
	.***.
	...T*
	2 2 4 3		//起点S坐标与终点T的坐标
*/

#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 100;
int n, m;//n行m列矩阵
char matrix[maxn][maxn];//存储矩阵元素信息
bool inq[maxn][maxn] = {false};//记录位置(x, y)是否已入过队
int X[4] = {0, 0, -1, 1};//增量数组
int Y[4] = {1, -1, 0, 0};

struct Node{
	int x, y;//位置(x, y)
	int step;//起点到位置的距离
}S, T, node;

bool judge(int x, int y){//判断坐标(x, y)是否需要访问
	if(x >= n || x < 0 || y >= m || y < 0) return false;
	//越界返回false
	if(inq[x][y] == true) return false;
	//已经入过队返回false
	if(matrix[x][y] == '*') return false;
	//前面是墙壁返回false
	return true;
}

int BFS(){
	queue<Node> q;//定义队列
	q.push(S);//将起点入队
	while(!q.empty()){
		Node top = q.front();//取队首元素
		q.pop();//队首元素出队
		if(top.x == T.x && top.y == T.y){
			return top.step;//到达终点，直接返回最少步数
		}
		for(int i = 0; i < 4; i++){//循环4次，得到4个相邻位置
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			if(judge(newX, newY)){//位置(newX, newY)有效
				node.x = newX; node.y = newY;//设置node的坐标为(newX, newY)
				node.step = top.step + 1;//Node的步数为上一个节点的步数+1
				q.push(node);//将node加入队列
				inq[newX][newY] = true;//设置位置(newX, newY)已加入队列
	
			}
		}
	}
	return -1;//无法到达终点，返回-1
}

int main()
{
	scanf("%d%d", &n, &m);//输入矩阵行数和列数
	for(int i = 0; i < n; i++){//输入矩阵信息
		getchar();//无论是用scanf还是用getchar()输入都必须吸收掉换行符**************************************
		for(int j = 0; j < m; j++){
			//matrix[i][j] = getchar();
			scanf("%c", &matrix[i][j]);
		}
		matrix[i][m] = '\0';
	}
	scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);//起点坐标和终点坐标的位置
	S.step = 0;//初始化起点的层数为0
	printf("%d\n", BFS());
	return 0;
}
