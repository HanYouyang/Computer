//
//  main.cpp
//  test
//
//  Created by LuJiayi on 11/19/15.
//  Copyright © 2015 LuJiayi. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int n = 0; int m = 0;
bool map[110][110] = {0};//map
char a[110][110] = {}; //输入的样子
//int c[110][110] = {0}; //计算是否走过????
int dis[110][110] ; //计算步数
int zx[4] = {1,-1,0,0}; int zy[4] = {0,0,1,-1};
int beginx = 0; int beginy = 0;
int endx =0; int endy = 0;
struct location{
    int x;
    int y;
    location(int xx,int yy):x(xx),y(yy){}
};
queue<location> q;



void init()
{
    for( int i = 0; i < 110; i++){
        for(int j = 0; j < 110; j++){
            dis[i][j] = 0;
        }
    }
    cin >> n >> m;
    //建立n+2和m+2的数组，其中四周都为#
    for( int i = 0; i < n  ;i++){
        for( int j = 0; j < m ; j++){
            cin >> a[i][j];
        }
    }
    for( int i = 0; i < n  ;i++){
        for( int j = 0; j < m ; j++){
            if(a[i][j] == '.'){
                map[i][j] = 1;
            }
            if(a[i][j] == 'S'){
                map[i][j] = 1;
                beginx = i;
                beginy = j;
            }
            if(a[i][j] == 'T'){
                map[i][j] = 1;
                endx = i;
                endy = j;
            }
        }
    }
}



int check(int x, int y)
{
    if(map[x][y] && x >= 0 && y >= 0 ){
        
        return 1;
    }
    return 0;
}

int bfs()
{
    dis[beginx][beginy] = 0;
    q.push(location (beginx,beginy));
    map[beginx][beginy] = 0;
    while(!q.empty()){
        location l = q.front();
        //check T
        if(l.x == endx && l.y == endy){
            break;
        }
        for(int i = 0; i < 4; i++){
            int nextx = l.x + zx[i];
            int nexty = l.y + zy[i];
            if(check(nextx,nexty)){
                q.push(location(nextx,nexty));
                dis[nextx][nexty] = dis[l.x][l.y]+1;
                map[nextx][nexty] = 0;
            }
        }
        q.pop();
        
    }
    
    
    return dis[endx][endy];
}





int main() {
    init();
    
    cout << bfs() << endl;
    
    return 0;
}







