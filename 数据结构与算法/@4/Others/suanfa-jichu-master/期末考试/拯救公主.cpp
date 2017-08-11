#include "iostream"
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
const int MAXSIZE = 210;
const int MAXK = 5;
const int MAXDOOR = 10;
char map[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE][1 << MAXK]; //拥有宝石的姿势有1<<MAXK种，从低位起，第i位为1代表拥有第i个宝石
int R, C, K;
int door_number;
int doors[MAXDOOR][2];
int haveresult = 0;
struct Node
{
	int x;  //纵坐标
	int y; //横坐标
	int step;
	int gem_status; //拥有宝石的姿势
	Node(int x_, int y_, int step_, int gem_status_) :x(x_), y(y_), step(step_), gem_status(gem_status_) {}
	Node() :x(-1), y(-1), step(-1), gem_status(0) {}
}startpoint, endpoint;
queue <Node> que;
int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
void reset() {
	for (int i = 0; i < MAXSIZE; ++i)
		for (int j = 0; j < MAXSIZE; ++j)
			map[i][j] = '#';
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < MAXDOOR; ++i)
		for (int j = 0; j < 2; ++j)
			doors[i][j] = -1;
	haveresult = 0;
	door_number = 0;
	while (!que.empty())
		que.pop();

}
int main(int argc, char const *argv[])
{
	int T;
	char temp;
	int x, y, gem_status, next_x, next_y, next_gem_status;
	scanf("%d", &T);
	Node current_node;
	while (T--) {
		reset();
		//start input
		cin >> R >> C >> K; //R是行数，C是列数
		for (int i = 1; i < R + 1; ++i)
			for (int j = 1; j < C + 1; ++j)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S')
				{
					startpoint.x = i;
					startpoint.y = j;
				}
				else if (map[i][j] == 'E')
				{
					endpoint.x = i;
					endpoint.y = j;
				}
				else if (map[i][j] == '$')
				{
					doors[door_number][0] = i;
					doors[door_number][1] = j;
					door_number++;
				}
			}
		//end input
		//begin bfs
		startpoint.step = 0; //0步
		startpoint.gem_status = 0; //没有宝石
		endpoint.step = -1;
		que.push(startpoint);
		visited[startpoint.x][startpoint.y][0] = true;
		while (!que.empty()) {
			current_node = que.front();
			que.pop();
			x = current_node.x;
			y = current_node.y;
			gem_status = current_node.gem_status;
			if (x == endpoint.x && y == endpoint.y && gem_status == ((1 << K) - 1))
			{
				cout << current_node.step << endl;
				haveresult = 1;
				break;
			}
			for (int i = 0; i < 4; ++i)
			{
				next_x = x + direction[i][0];
				next_y = y + direction[i][1];
				next_gem_status = gem_status;
				if (map[next_x][next_y] >= '0' && map[next_x][next_y] <= '4')
				{
					next_gem_status = gem_status | (1 << (map[next_x][next_y] - '0'));
				}
				if (!visited[next_x][next_y][next_gem_status] && map[next_x][next_y] != '#') {
					if (map[next_x][next_y] != '$')
					{
						visited[next_x][next_y][next_gem_status] = true;
						que.push(Node(next_x, next_y, current_node.step + 1, next_gem_status));
					}else{
						for (int door_loop = 0; door_loop < door_number; ++door_loop)
						{
							next_x = doors[door_loop][0];
							next_y = doors[door_loop][1];
							visited[next_x][next_y][next_gem_status] = true;
							que.push(Node(next_x, next_y, current_node.step + 1, next_gem_status));
						}
					}

				}
			}
		}
		if (haveresult == 0)
		{
			cout << "oop!" << endl;
		}
	}
	return 0;
}