//Flood Fill 
//BFS version
//Miibotree
//2015.3.2
#include <stdio.h>
#include <queue>
using namespace std;
#define MAXN 101

struct Node
{
	int x;
	int y;
};

int x[] = {-1, 1, 0, 0};
int y[] = {0,  0, -1, 1};

bool inq[MAXN][MAXN];//是否已经入队列标记
int maze[MAXN][MAXN];//迷宫
int m, n;//输入m * n的地图

bool judge(Node s)
{
	if(s.x > m || s.x <= 0 || s.y > n || s.y <= 0)//出了边界
		return false;
	if(inq[s.x][s.y] == true || maze[s.x][s.y] == 0)//墙或者已经入过队列
		return false;
	return true;
}

void BFS(Node s)
{
	queue<Node> q;
	q.push(s);
	inq[s.x][s.y] = true;//已经入队列
	while(q.empty() == false)
	{
		Node tmp = q.front();
		int nowx = tmp.x;
		int nowy = tmp.y;
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			tmp.x = nowx + x[i];
			tmp.y = nowy + y[i];
			if(judge(tmp))
			{
				q.push(tmp);
				inq[tmp.x][tmp.y] = true;
			}
		}
	}
}

int main()
{
	
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &maze[i][j]);
			inq[i][j] = false;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(maze[i][j] == 1 && inq[i][j] == false)//是通路且没有进过队列
			{
				Node tmp;
				tmp.x = i;
				tmp.y = j;
				BFS(tmp);
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}
