//2016年2月28日18时12分07秒
//2016年2月28日19时36分28秒
#include <cstdio>
#include <queue>

using namespace std;
const int maxm = 1290;
const int maxn = 130;
const int maxl = 65;

struct Node{
	int x, y, z;//位置(x, y, z)
}node;

int m, n, l, t;//l片m行n列的三维矩阵，阀值是t
int matrix[maxm][maxn][maxl];//存储三维矩阵的信息
bool inq[maxm][maxn][maxl] = {false};//记录位置(x, y, z)是否入过队
int X[6] = {0, 0, 0, 0, 1, -1};//坐标增量
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool judge(int x, int y, int z){//判断(x, y, z)位置点是否有效
	if(x >= m || x < 0 || y >= n || y < 0 || z >= l || z < 0) return false;
	//越界，无效
	if(inq[x][y][z] == true || matrix[x][y][z] == 0) return false;
	//已经入队过或者位置的值为零，无效
	return true;
}

int BFS(int x, int y, int z){
//遍历以(x, y, z)为中心的点
	queue<Node> q;//定义一个队列
	int cnt = 0;//记录当前块1的个数
	node.x = x, node.y = y, node.z = z;//设置节点node的坐标为(x, y, z)
	q.push(node);//将节点node入队
	inq[x][y][z] = true;//设置(x, y, z)已经入过队
	while(!q.empty()){//队列非空时循环
		Node top = q.front();//取出队首元素
		q.pop();//队首元素出队
		cnt++;//当前块中1的个数加1
		for(int i = 0; i < 6; i++){//循环6次，得到六个增量方向
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if(judge(newX, newY, newZ)){//新位置(newX, newY, newZ)需要访问
				node.x = newX, node.y = newY, node.z = newZ;//重新设置node的坐标
				q.push(node);//将节点node入队
				inq[newX][newY][newZ] = true;//设置(newX, newY, newZ)已入过队
			}
		}
	}
	if(cnt >= t) return cnt;//如果当前块1的个数大于阀值则返回当前值
	else return 0;//否则返回0
}

int main()
{
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for(int k = 0; k < l; k++){//先枚举片层号
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &matrix[i][j][k]);
			}
		}
	}
	int ans = 0;//记录大于阀值的肿瘤块中1的个数总和
	for(int k = 0; k < l; k++){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j][k] == 1 && inq[i][j][k] == false){
				//如果当前位置为1且未被访问，则BFS当前块
					ans += BFS(i, j, k);
				}
			}
		}
	}
	printf("%d\n", ans);//输出有效1的个数
	return 0;
}
