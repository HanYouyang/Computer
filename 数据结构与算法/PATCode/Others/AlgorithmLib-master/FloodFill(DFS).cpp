//Flood Fill 
//DFS version
//Miibotree
//2015.3.2
#include <stdio.h>
#include <queue>
#define MAXN 101

using namespace std;

struct Node
{
	int x;
	int y;
};

int x[] = {-1, 1, 0, 0};
int y[] = {0,  0, -1, 1};

bool mark[MAXN][MAXN];//是否已经入队列标记
int maze[MAXN][MAXN];//迷宫
int m, n;//输入m * n的地图

bool judge(Node s)
{
	if(s.x > m || s.x <= 0 || s.y > n || s.y <= 0)//出了边界
		return false;
	if(mark[s.x][s.y] == true || maze[s.x][s.y] == 0)//墙或者已经入过队列
		return false;
	return true;
}

void DFS(Node s)
{
	mark[s.x][s.y] = true;
	for(int i = 0; i < 4; i++)
	{
		int newX = s.x + x[i];
		int newY = s.y + y[i];
		Node tmp;
		tmp.x = newX;tmp.y = newY;
		if(judge(tmp))
			DFS(tmp);
		else
			continue;
	}
	return;
}

int main()
{
	
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &maze[i][j]);
			mark[i][j] = false;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(maze[i][j] == 1 && mark[i][j] == false)//是通路且没有进过队列
			{
				Node tmp;
				tmp.x = i;
				tmp.y = j;
				DFS(tmp);
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}
