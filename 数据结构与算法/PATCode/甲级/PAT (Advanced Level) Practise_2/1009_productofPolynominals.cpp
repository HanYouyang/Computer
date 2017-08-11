//2016年1月29日19时02分58秒
//2016年1月29日19时30分31秒

//注意：浮点数判零更应该注意要abs(*)>zero;
//改进：没有必要开两个数组存放两个多项式然后读完系数之后再处理
//	在读第二个多项式的系数时边读边处理
#include <iostream>
#include <cstdio>
#include <cmath>
//algorithm库中abs的参数只有整型，因此当使用abs对double型做绝对值处理时
//应使用cmath库，使用algorithm库会出现call of overloaded ‘abs(double&)’ is ambiguous
//但是在pat的online judge上面不会出现这问题
//#include <algorithm>

using namespace std;

const double zero = 10e-8;
const int maxn = 2010;

int main()
{
	int m, n;
	double pm[1002]; //, pn[1002];
	double p[maxn] = {0};
	int count = 0;
	cin >> m;
	while(m--){
		int temp;
		cin >> temp;
		cin >>pm[temp];
	}
	cin >> n;
	while(n--){
		int expo;
		double coe;
		cin >> expo;
		cin >> coe;
		for(int i = 0; i <= 1000; i++){
			if(pm[i])
				p[i + expo] += pm[i] * coe;
		}
	}
//	for(int i = 0; i <= 1000; i++){
//		if(!pm[i]) continue;
//		for(int j = 0; j <= 1000; j++){
//			if(!pn[j]) continue;
//			p[i+j] += pm[i] * pn[j];
//		}
//	}
	for(int i = 0; i <= 2002; i++){
		if(abs(p[i]) > zero)	count++;
	}
	printf("%d", count);
	for(int i = 2002; i >= 0; i--){
		if(abs(p[i]) > zero)
			printf(" %d %.1f", i, p[i]);
	}
	return 0;
}
