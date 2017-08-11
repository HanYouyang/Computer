//广度优先搜索
//胜利大逃亡
//Miibotree
//2015.2.14
//思路:明确查找空间、查找目标、查找方法

#include <stdio.h>
#include <queue>

using namespace std;
bool mark[50][50][50];
int maze[50][50][50];

struct N{
	int x, y, z;
	int t;
};

queue <N> Q;
int go[][3] = {
	1, 0, 0,
	-1, 0, 0,
	0, 1, 0,
	0, -1, 0,
	0, 0, 1,
	0, 0, -1
};

int BFS(int a, int b, int c)
{
	while(Q.empty() == false)
	{
		N now = Q.front();
		Q.pop();
		for(int i = 0; i < 6; i++)
		{
			int nx = now.x + go[i][0];
			int ny = now.y + go[i][1];
			int nz = now.z + go[i][2];
			if(nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c )//超出边界
				continue;
			if(maze[nx][ny][nz] == 1)//若该位置为墙，丢弃该坐标
				continue;
			if(mark[nx][ny][nz] == 1)//之前已经到达过，丢弃该状态
				continue;
			N tmp;
			tmp.x = nx;
			tmp.y = ny;
			tmp.z = nz;
			tmp.t = now.t + 1;
			Q.push(tmp);
			mark[nx][ny][nz] = true;
			if(nx == a-1 && ny == b-1 && nz == c-1)//到达终点
				return tmp.t;
		}
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int a, b, c, t;
		scanf("%d%d%d%d", &a, &b, &c, &t);
		
		for(int i = 0; i < a; i++)
		{
			for(int j = 0; j < b; j++)
			{
				for(int k = 0; k < c; k++)
				{
					scanf("%d", &maze[i][j][k]);
					mark[i][j][k] = false;
				}
			}
		}
		while(Q.empty() == false)	Q.pop();
		mark[0][0][0] = true;
		N tmp;
		tmp.t = tmp.x = tmp.y = tmp.z = 0;
		Q.push(tmp);
		int res = BFS(a, b, c);
		if (res <= t)
			printf("%d\n", res);
		else
			printf("-1\n");	
	}
	return 0;
}