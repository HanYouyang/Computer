//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//int n, m,sx,sy,ex,ey;
//int maze[100][100] = { 0 };
//int fx[4] = { 1, -1, 0, 0 };
//int fy[4] = { 0, 0, -1, 1 };
//int i, j, k;
//int check(int i, int j, int k){
//	int flag = 1; i = i + fx[k]; j = j + fy[k];
//	if (i<0 || i>n-1 || j<0 || j>m-1) flag = 0;
//	if (maze[i][j] != 0){
//		flag = 0;
//	}
//	return flag;
//}
//void search(int i, int j){
//	static int count = 0;
//	int k, newi, newj;
//	for (k = 0; k < 4; k++){
//		if (check(i, j, k) == 1){
//			newi = i + fx[k]; newj = j + fy[k];
//			maze[newi][newj] = 3; count++;
//			if (newi == ex && newj == ey){
//				cout << count << endl;
//			}
//			else{
//				search(newi, newj);
//			}	
//		}	
//	}
//	maze[i][j] = 2;
//}
//int main333(){
//	cin >> n >> m;
//	char square[101][101] = { 0 };
//	for (int i = 0; i < n; i++){
//		cin >> square[i];
//	}
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++){
//			if (square[i][j] == 'S'){
//				sx = i; sy = j;
//				maze[i][j] = 0;
//			}
//			if (square[i][j] == 'T'){
//				ex = i; ey = j;
//				maze[i][j] = 0;
//			}
//			if (square[i][j] == '.'){
//				maze[i][j] = 0;
//			}
//			if (square[i][j] == '#'){
//				maze[i][j] = 1;
//			}
//		}
//	}
//	maze[sx][sy] = 3;
//	search(sx, sy);
//	return 0;
//}
