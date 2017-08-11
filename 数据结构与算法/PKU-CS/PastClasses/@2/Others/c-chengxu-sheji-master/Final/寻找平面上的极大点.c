#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
	}a[300];
int N;
int cmp(const node&w,const node&e){
    if(w.x>e.x) return 1;
     else if(w.x==e.x){
         if(w.y>e.y) return 1;
     }
     return 0;
}
int tot;
int ansx[300];
int ansy[300];
int maxy;
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+N+1,cmp);
	for(int i=1;i<=N;i++){
		if(a[i].y>maxy){
			maxy=a[i].y;
			tot++;
			ansx[tot]=a[i].x;
			ansy[tot]=a[i].y;
		}            
	}
	for(int i=tot;i>=2;i--){
		cout<<"("<<ansx[i]<<","<<ansy[i]<<")"<<",";
	}
	cout<<"("<<ansx[1]<<","<<ansy[1]<<")";
	return 0;
}