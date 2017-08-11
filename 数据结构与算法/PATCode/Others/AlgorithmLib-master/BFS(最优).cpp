//BFS 寻找迷宫的最短路径步数
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
	int step;
}S, E, node;

int x[] = {0, 0, -1, 1};
int y[] = {1, -1, 0, 0}; 
int m, n;

bool inq[MAXN][MAXN];
char maze[MAXN][MAXN];

bool Judge(Node a)
{
	if(a.x < 0 || a.x >= m || a.y < 0 || a.y >= n)
		return false;
	if(inq[a.x][a.y] == true || maze[a.x][a.y] == '*')
		return false;
	return true;
}

int BFS(Node a)
{
	queue<Node> q;
	q.push(a);
	inq[a.x][a.y] = true;
	while(q.empty() == false)
	{
		Node tmp = q.front();
		q.pop();
		if(tmp.x == E.x && tmp.y == E.y)
		{
			return tmp.step;
		}
		int nowX = tmp.x;
		int nowY = tmp.y;
		int nowStep = tmp.step;
		for(int i = 0; i < 4; i++)
		{
			tmp.x = nowX + x[i];
			tmp.y = nowY + y[i];
			tmp.step = nowStep + 1;
			if(Judge(tmp))
			{
				q.push(tmp);
				inq[tmp.x][tmp.y] = true;
			}
		}
	}
	return -1;
}

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m ; i++)
		scanf("%s", maze[i]);
	int sx, sy, ex, ey;
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	S.x = sx;	S.y = sy;
	S.step = 0;
	E.x = ex;	E.y = ey;
	printf("%d\n", BFS(S));

	return 0;
}