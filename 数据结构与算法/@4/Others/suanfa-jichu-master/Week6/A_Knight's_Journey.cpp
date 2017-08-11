#include "iostream"
#include <memory.h>
using namespace std;
int p, q, total;
int visited[30][30];
//int dir[8][2] = {-2,-1 , -2,1 ,-1,-2 , -1,2 ,1,-2 ,1,2 , 2,-1 , 2,1};
int dir[8][2] = {-1,-2,1,-2,-2,-1,2,-1,-2,1,2,1,-1,2,1,2}; 
bool success;
struct Path
{
	int x;  //纵坐标
	char y; //横坐标
}path[30];

bool inbound(int i, int j) {
	return (i >= 0) && (i < p) && (j >= 0) && (j < q);
}
void dfs(int x, int y) {  //当前位置为x,y
	int nextx, nexty;
	if (success)
	{
		return;
	}

	path[total].x = x + 1;
	path[total].y = char(y + 'A'); 
	total++;

	if (total == p * q) {
		success = true;
		return;
	}
	visited[x][y] = 1;
	for (int i = 0; i < 8; ++i)
	{
		nextx = x + dir[i][0];
		nexty = y + dir[i][1];
		if (inbound(nextx, nexty) && !visited[nextx][nexty]) {
			dfs(nextx, nexty);
			total--;
		}
	}
	visited[x][y] = 0;
}


int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for (int k = 0; k < count; ++k) {
		cin >> p >> q;
	//初始化
		total = 0;
		memset(visited, 0, sizeof(visited));
		success = false;
	//计算
		dfs(0, 0);
	//输出结果
		cout << "Scenario #" << k + 1 << ":" << endl;
		if (success) {
			for (int i = 0, sum = p*q; i < sum; ++i)
			{
				cout << path[i].y << path[i].x; 
			}
		}
		else {
			cout << "impossible";
		}
		cout << endl;
		if (k != count - 1)
			cout << endl;
	}
	return 0;
}