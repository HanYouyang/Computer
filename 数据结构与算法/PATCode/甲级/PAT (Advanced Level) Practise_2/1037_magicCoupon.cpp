//2016年2月18日19时40分56秒
//2016年2月18日20时18分56秒
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

long long NC[maxn] = {0};
long long NP[maxn] = {0};

bool cmp(long long a, long long b){
	return a > b;
}

int main()
{
	long long maxMoney = 0;
	int c;
	scanf("%d", &c);
	for(int i = 0; i < c; i++) scanf("%lld", &NC[i]);
	sort(NC, NC + c, cmp);
	int p;
	scanf("%d", &p);
	for(int i = 0; i < p; i++) scanf("%lld", &NP[i]);
	sort(NP, NP + p, cmp);
	for(int i = 0; i < c && i < p; i++){
		if(NC[i] <= 0 || NP[i] <= 0) break;
		maxMoney += NC[i] * NP[i];
	}
	//NC与NP可能不等长，因此下表不能共用一个变量
	int i = c - 1, j = p - 1;
	for(; i >= 0 && j >= 0; i--, j--){
		if(NC[i] >= 0 || NP[j] >= 0) break;
		maxMoney += NC[i] * NP[j];
	}
	printf("%lld\n", maxMoney);
	return 0;
}
