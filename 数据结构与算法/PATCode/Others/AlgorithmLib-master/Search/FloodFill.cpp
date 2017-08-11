//FloodFill 递归的应用，将相邻的点联合成一个块的算法
//Miibotree
//2015.2.14
#include <stdio.h>

char maze[101][101];
int mark[101][101];
int n, m;
int go[][2] = {-1,-1, -1,0, -1,1, 0,-1, 0,1, 1,-1, 1,0, 1,1};//八个方向

void DFS(int x, int y)
{
	//依次递归8个方向
	for(int i = 0; i < 8; i++)
	{
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		if(nx < 1 || nx > n || ny < 1 || ny > m)	continue;
		if(maze[nx][ny] == '*')	continue;
		if(mark[nx][ny] == true)	continue;
		mark[nx][ny] = true;
		DFS(nx, ny);
	}
	return;
}

int main()
{
	while(scanf("%d%d", &m, &n) != EOF)//m行n列
	{
		if (m == 0 && n == 0)	break;
		for(int i = 1; i <= m; i++)
			scanf("%s", maze[i]+1);
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				mark[i][j] = false;
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)//注意从左到右，从上到下
		{
			for(int j = 1; j <= m; j++)
			{
				if(maze[i][j] == '*')
					continue;
				if(mark[i][j] == true)
					continue;
				DFS(i, j);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}