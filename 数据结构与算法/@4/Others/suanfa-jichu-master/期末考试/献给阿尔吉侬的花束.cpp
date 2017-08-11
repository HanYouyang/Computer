#include "iostream"
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
const int LIMIT = 400;
int map[LIMIT][LIMIT];
bool visited[LIMIT][LIMIT];
//int result[LIMIT][LIMIT];
int R, C;
struct Node
{
	int x;  //纵坐标
	int y; //横坐标
	int step;
	Node(int x_, int y_, int step_):x(x_),y(y_),step(step_){}
	Node():x(-1),y(-1),step(-1){}
}startpoint,endpoint;
queue <Node> que;
int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
int main(int argc, char const *argv[])
{
	int T;
	char temp;
	int haveresult = 0;
	int x, y, nextx, nexty;
	scanf("%d", &T);
	Node current_node;
	while (T--) {
		scanf("%d%d", &R, &C); //R是行数，C是列数
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		//memset(result, 0, sizeof(result));
		haveresult = 0;
		//start input
		getchar();
		for (int i = 1; i < R + 1; ++i) {
			for (int j = 1; j < C + 1; ++j)
			{
				scanf("%c", &temp);
				if (temp == '.')
					map[i][j] = 1; //可以通行
				else if (temp == 'S')
				{
					startpoint.x = i;
					startpoint.y = j;
					map[i][j] = 1;
				}
				else if (temp == 'E')
				{
					endpoint.x = i;
					endpoint.y = j;
					map[i][j] = 1;
				}
			}
			getchar();
		}
		//end input	
		//begin bfs
		startpoint.step = 0;
		endpoint.step = -1;
		que.push(startpoint);
		visited[startpoint.x][startpoint.y] = true;
		//result[startpoint.x][startpoint.y] = 0;
		while(!que.empty()){
			current_node = que.front();
			que.pop();
			x = current_node.x;
			y = current_node.y;
			if (x == endpoint.x && y == endpoint.y)
			{
				cout << current_node.step << endl;
				haveresult = 1;
				break;
			}
			for (int i = 0; i < 4; ++i)
			{
				nextx = x + direction[i][0];
				nexty = y + direction[i][1];
				if (!visited[nextx][nexty] && map[nextx][nexty]){
					visited[nextx][nexty] = true;
					que.push(Node(nextx, nexty,current_node.step + 1));
					//result[nextx][nexty] = current_node.step + 1;
				}
			}
		}
		if (haveresult == 0)
		{
			cout << "oop!" << endl;
		}
		while(!que.empty())
			que.pop();
	}
	return 0;
}