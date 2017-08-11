#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=105,tx[4]={0,1,0,-1},ty[4]={1,0,-1,0};
bool a[N][N];
struct node
{
    int x,y,s;
}k;
queue<node>q;
int main()
{
    cin.sync_with_stdio(false);
    int n,m,sta_x,sta_y,end_x,end_y,qx,qy,qs,i,j,l;
    char c;
    bool flag;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            cin>>c;
            if(c=='#')
                a[i][j]=true;
            if(c=='S')
                sta_x=i,sta_y=j;
            if(c=='T')
                end_x=i,end_y=j;
        }
    k.x=sta_x;
    k.y=sta_y;
    k.s=0;
    q.push(k);
    a[sta_x][sta_y]=true;
    flag=false;
    while(!q.empty())
    {
        for(l=0;l<4;l++)
        {
            k=q.front();
            qx=k.x+tx[l];
            qy=k.y+ty[l];
            qs=k.s;
            if(qx<1||qx>n||qy<1||qy>m)
                continue;
            if(a[qx][qy]==false)
            {
                a[qx][qy]=true;
                k.x=qx;
                k.y=qy;
                k.s=qs+1;
                q.push(k);
            }
            if(qx==end_x&&qy==end_y)
            {
                flag=true;
                break;
            }
        }
        if(flag==true)
            break;
        q.pop();
    }
    k=q.back();
    cout<<k.s;
    return 0;
}