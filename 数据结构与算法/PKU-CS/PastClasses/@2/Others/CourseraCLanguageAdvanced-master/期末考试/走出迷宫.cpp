//#include<iostream>
//#include<stdlib.h>
//#include<stack>
//using namespace std;
//int a[120][120] = { { 0 } }; int n, m; 
//typedef struct Point{
//	int x; int y;
//} point;
//typedef struct Path{
//	point p;
//	int direction;
//} path;
//point NextPos(point p, int di)
//{ /* 根据当前位置及移动方向，返回下一位置 */
//	point direc[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; /* {行增量,列增量} */
//	/* 移动方向,依次为东南西北 */
//	p.x += direc[di].x;
//	p.y += direc[di].y;
//	return p;
//}
//int main(){
//	cin >> n >> m;
//	char square[120][120] = { 0 }; point start, end;
//	for (int i = 0; i < n; i++){
//		cin >> square[i + 1] + 1;
//	}
//	for (int i = 0; i < n + 2; i++){
//		square[i][0] = square[i][m + 1] = '#';
//	}
//	for (int i = 0; i < m + 2; i++){
//		square[0][i] = square[n + 1][i] = '#';
//	}
//	for (int i = 1; i < n + 1; i++){
//		for (int j = 1; j < m + 1; j++){
//			if (square[i][j] == 'S'){
//				start.x = i; start.y = j;
//			}
//			if (square[i][j] == 'T'){
//				end.x = i; end.y = j;
//			}
//		}
//	}
//	stack<path> s; point curpos = start; path temp; int countstep = 0;
//	do{
//
//		if ((square[curpos.x][curpos.y] == '.' || 
//			square[curpos.x][curpos.y] == 'S' || square[curpos.x][curpos.y] == 'T')
//			&&(a[curpos.x][curpos.y]==0)){
//			temp.p.x = curpos.x; temp.p.y = curpos.y; temp.direction = 0;
//			s.push(temp); countstep++; a[curpos.x][curpos.y] = 1;
//			if (curpos.x == end.x&&curpos.y == end.y) {
//				cout << --countstep << endl;
//				return 0;
//			}			
//			curpos = NextPos(curpos, temp.direction);
//		}
//		else{
//			/* 当前位置不能通过 */
//			if (!s.empty()){
//				temp = s.top(); s.pop(); countstep--; a[temp.p.x][temp.p.y] = 0;
//				while ((temp.direction == 3) && (!s.empty())) {
//					/* 前一位置处于最后一个方向(北) */
//					a[temp.p.x][temp.p.y] = -1;
//					temp = s.top(); s.pop(); countstep--; a[temp.p.x][temp.p.y] = 0;
//				}
//				/* 没到最后一个方向(北) */
//				if (temp.direction<3) {
//					/* 换下一个方向探索 */
//					temp.direction++;
//					s.push(temp); countstep++;
//					curpos = NextPos(temp.p, temp.direction); /* 设定当前位置是该新方向上的相邻块 */
//				}
//			}
//		}
//	} while (!s.empty());
//	return 0;
//}