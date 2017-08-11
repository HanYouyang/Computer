#include <iostream>
#include <cstring>
using namespace std;

int m, n; 
char map[101][101];
int already[101][101];
int min_count=0;

void cross(int u, int v, int i, int j) {
    int t = already[u][v];
    if (u == i && v == j) {
        min_count = t;
    }
    t = t + 1;

    if (v < m - 1 && map[u][v + 1] != '#'  && already[u][v + 1] > t) {
        already[u][v + 1] = t;
        cross(u, v + 1, i, j);
    }
    if (u > 0 && map[u - 1][v] != '#'  && already[u - 1][v]>t) {
        already[u - 1][v] = t;
        cross(u - 1, v, i, j);
    }
    if (v > 0 && map[u][v - 1] != '#'  && already[u][v - 1] > t) {
        already[u][v - 1] = t;
        cross(u, v - 1, i, j);
    }
    if (u < n - 1 && map[u + 1][v] != '#' && already[u + 1][v] > t) {
        already[u + 1][v] = t;
        cross(u + 1, v, i, j);
    }
}

int main() {
    int startx,starty,endx,endy;
    cin >> n >> m ;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                startx = i;
                starty = j;
            }
            if (map[i][j] == 'T') {
                endx = i;
                endy = j;
            }
        }
    }
    memset(already, 1, sizeof(already));
    already[startx][starty] = 0;
    cross(startx, starty, endx, endy);
    cout << min_count << endl;
    return 0;
}
