//2016年2月20日18时49分43秒
//2016年2月20日19时41分31秒
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int INF = 0x7fffffff;
const int maxn = 100010;
int n, a[maxn], mina[maxn], maxa = 0;
int pivot[maxn], total = 0;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
	}
	mina[n - 1] = INF;
	for(int i = n - 2; i >= 0; i--){
		mina[i] = min(mina[i + 1], a[i + 1]);
	}
	for(int i = 0; i < n; i++){
		if(a[i] > maxa && a[i] < mina[i]){
			pivot[total++] = a[i];
		}
		maxa = max(maxa, a[i]);
	}
	sort(pivot, pivot + total);
	printf("%d\n", total);
	for(int i = 0; i < total; i++){
		if(i) printf(" ");
		printf("%d", pivot[i]);
	}
	printf("\n");
	return 0;
}
