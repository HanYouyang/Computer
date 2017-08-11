//DFS 深搜 注意跟BFS之间的比较
//Miibotree
//2015.2.14
#include <stdio.h>

char maze[8][8];
int n, m, t;
bool success;//用一个全局变量来表示搜索是否成功
int go[][2] = {1,0, -1,0, 0,1, 0,-1};

void DFS(int x, int y, int time)
{
	for(int i = 0; i < 4; i++)
	{
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		if(nx < 1 || nx > n || ny < 1 || ny > m )
			continue;
		if(maze[nx][ny] == 'X')//坐标为墙
			continue;
		if(maze[nx][ny] == 'D')
		{
			if(time + 1 == t)//搜索成功
			{
				success = true;
				return;
			}
			else
				continue;
		}
		maze[nx][ny] = 'X';//递归前将该坐标状态改为墙
		DFS(nx, ny, time+1);
		maze[nx][ny] = '.';//递归后将该坐标状态改为普通位置

		if(success)
			return;
	}
}

int main()
{
	while(scanf("%d%d%d", &n, &m, &t) != EOF)
	{
		if(n == 0 && m == 0 && t == 0)
			break;
		for(int i = 1; i <= n; i++)
			scanf("%s", maze[i]+1);//坐标都从1开始算起
		success = false;
		int sx, sy;
		for(int i = 1; i <= n; i++)//寻找D的位置坐标
		{
			for(int j = 1; j <= m; j++)
			{
				if(maze[i][j] == 'D')
				{
					sx = i; sy = j;
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				
				if(maze[i][j] == 'S' && (i+j)%2==((sx+sy)%2+t%2)%2)//这里有奇偶减枝,不剪也能过 
				{
					maze[i][j] = 'X';
					DFS(i, j, 0);
				}
			}
		}
		puts(success == true?"YES":"NO");
	}
	return 0;
}