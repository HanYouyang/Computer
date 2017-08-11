#include <stack>
#include <iostream>
#include <stdlib.h>
using namespace std;
int maze[120][120];int n, m;
struct Postion{
	int _X, _Y;
	Postion(){}
	Postion(int X, int Y)
		: _X(X), _Y(Y){}
};

bool isCanGo(const int prePosValue,
	const int posX,
	const int posY)
{
	if (posX < 0 || posX > n-1		// 越界
		|| posY < 0 || posY > m-1
		|| maze[posX][posY] == -1)	// 墙
	{
		return false;
	}

	if (maze[posX][posY] == 0)	// 未走过
		return true;
	else						// 更近的路径
		return (prePosValue + 1) < maze[posX][posY];
}
Postion offset[4];				// 偏移量
void shortestPath(Postion start,Postion end){
	if (start._X == end._X&& start._Y == end._Y){
		return;
	}
	for (int i = 0; i < 4; i++){
		int nNextPos_X = start._X + offset[i]._X;
		int nNextPos_Y = start._Y + offset[i]._Y;
		if (isCanGo(maze[start._X][start._Y], nNextPos_X, nNextPos_Y)){
			maze[nNextPos_X][nNextPos_Y] = maze[start._X][start._Y] + 1;
			shortestPath(Postion(nNextPos_X, nNextPos_Y), end);
		}
	}
}

int main111(){
	offset[0]._X = -1;	offset[0]._Y = 0;	// 上
	offset[1]._X = 1;	offset[1]._Y = 0;	// 下
	offset[2]._X = 0;	offset[2]._Y = -1;	// 左
	offset[3]._X = 0;	offset[3]._Y = 1;	// 右
	cin >> n >> m;
	int sx, sy, ex, ey;
	char square[120][120] = { 0 };
	for (int i = 0; i < n; i++){
		cin >> square[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (square[i][j] == 'S'){
				sx = i; sy = j;
				maze[i][j] = 0;
			}
			if (square[i][j] == 'T'){
				ex = i; ey = j;
				maze[i][j] = 0;
			}
			if (square[i][j] == '.'){
				maze[i][j] = 0;
			}
			if (square[i][j] == '#'){
				maze[i][j] = -1;
			}
		}
	}
	Postion start(sx, sy), end(ex, ey);
	maze[start._X][start._Y] = 1;			// 置起点值1, 防止走回起点
	shortestPath(start, end);
	cout << maze[ex][ey] -1<< endl;
	return 0;
}

