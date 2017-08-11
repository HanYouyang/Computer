#include <iostream>
#include <cstring>
using namespace std;
//走出迷宫 *****
int m, n, steps = 0;
char map[101][101];
int pass[101][101];

void route(int u, int v, int i, int j)
{
    int t = pass[u][v];
    if(u == i && v == j){
        steps = t;
    }
    t++;

    if(v < m - 1 && map[u][v+1] != '#'  && pass[u][v+1] > t){
        pass[u][v+1] = t;
        route(u, v+1, i, j);
    }
    if(u > 0 && map[u-1][v] != '#'  && pass[u-1][v] > t){
        pass[u-1][v] = t;
        route(u-1, v, i, j);
    }
    if(v > 0 && map[u][v-1] != '#'  && pass[u][v-1] > t){
        pass[u][v-1] = t;
        route(u, v-1, i, j);
    }
    if(u < n - 1 && map[u+1][v] != '#' && pass[u+1][v] > t){
        pass[u+1][v] = t;
        route(u+1, v, i, j);
    }
}

int main(){
    int startx, starty, endx, endy;
    cin >> n >> m;

    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'S'){
                startx = i;
                starty = j;
            }
            if(map[i][j] == 'T'){
                endx = i;
                endy = j;
            }
        }
    }

    memset(pass, 1, sizeof(pass));
    pass[startx][starty] = 0;
    route(startx, starty, endx, endy);
    cout << steps << endl;

    return 0;
}
