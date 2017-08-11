//2016年1月29日15时37分46秒
//2016年1月29日16时38分20秒
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double zero = 10e-7;
const int maxn = 1010;

int main()
{
	int m, n;
	double pm[maxn] = {0}, pn[maxn] = {0};
	int count = 0;
	cin >> m;
	while(m--){
		int temp;
		cin >> temp;
		cin >> pm[temp];
	}
	cin >> n;
	while(n--){
		int temp;
		cin >> temp;
		cin >> pn[temp];
	}
	for(int i = 0; i <= 1000; i++){
		pm[i] += pn[i];
		if(abs(pm[i]) > zero) count++;
	}
	printf("%d", count);
	for(int i = 1000; i >= 0; i--){
		if(pm[i]){
			printf(" %d %.1lf", i, pm[i]);
		}
	}
	return 0;
}
