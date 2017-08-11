//
//  main.cpp
//  编程题＃2： 滑雪
//
//  Created by CYC on 12/30/15.
//  Copyright © 2015 CYC. All rights reserved.
//

#define INF 2100000000
#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;


multimap<int, pair<int,int> > sortbaba (vector<vector<int> > & h){
    multimap<int, pair< int, int> > m;
    for( int i = 1; i < h.size() - 1; i++){
        for( int j = 1; j < h[i].size() - 1; j++){
            m.insert(make_pair(h[i][j], make_pair(i, j)));
        }
    }
    // 在地图上的点，从低到高排列
    return m;
}

void bigger (vector<vector<int> > & h, vector<vector<int> > & maxlp, int i , int j){
    //每一点的最大路径
    int a1[4] = {0,0,1,-1};
    int a2[4] = {1,-1,0,0};
    for( int z = 0; z < 4; z++){
        if(h[i][j] > h[i + a1[z]][j + a2[z]]){
            maxlp[i][j] = max(maxlp[i][j],maxlp[i +a1[z]][j + a2[z]]+1 );
        }
    }
    // 比较周围点的最大路径值
}

int longestpath (vector<vector<int> > & h){
    if ( h.size() == 0) {
        return 0;
    }
    vector<vector<int> > maxlp(h.size(),vector<int>(h[0].size(),1 ));
    
    multimap<int,pair<int ,int > > M (sortbaba(h));
    multimap<int,pair<int ,int > > ::iterator i;
    
    for( i = M.begin(); i != M.end(); i++){
        bigger(h, maxlp, (i ->second).first, (i -> second).second );
    }
    //指针i 指向map
    
    int maxpath = 0;
    for( int i = 1; i < maxlp.size()- 1; i++){
        for( int j = 1; j < maxlp[0].size() - 1; j++){
            if(maxpath < maxlp[i][j]){
                maxpath = maxlp[i][j];
            }
        }
    }
    
    return maxpath;
}


int main() {
    int r = 0;
    int c = 0;
    cin >> r >> c;

    vector<vector<int> > h( r+2,vector<int>( c+2, INF));
    
    for( int i = 1; i < r + 1; i++){
        for( int j = 1; j < c + 1; j++){
            cin >>h[i][j];
        }
    }
    
   
     cout << longestpath(h) << endl;
    
    
    return 0;
}
