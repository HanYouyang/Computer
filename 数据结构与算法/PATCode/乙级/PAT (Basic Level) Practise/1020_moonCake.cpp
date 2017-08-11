//2016年1月29日11时22分56秒
//2016年1月29日12时19分52
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 1010;
struct moon{
	double stock;
	double sumprice;
	double unitprice;
};

bool cmp(const moon &a, const moon &b)
{
	return a.unitprice > b.unitprice;
}

int main()
{
	int N;
	int D;
	moon cake[maxn];
	cin >> N >> D;
	for(int i = 0; i < N; i++){
		cin >> cake[i].stock;
	}
	for(int i = 0; i < N; i++){
		cin >> cake[i].sumprice;
		if(cake[i].stock){
			cake[i].unitprice = cake[i].sumprice / (double)cake[i].stock;
		}
	}
	sort(cake, cake+N, cmp);
	double profit = 0;
	int quantity = 0;
	for(int i = 0; quantity < D && i < N; i++){
		if((quantity + cake[i].stock) <= D){
			quantity += cake[i].stock;
			profit += cake[i].sumprice;
		}
		else{
			profit += cake[i].sumprice * ((D-quantity) / (double)cake[i].stock);
			quantity += cake[i].stock;
		}
	}
	printf("%.2f", profit);
	return 0;
}
