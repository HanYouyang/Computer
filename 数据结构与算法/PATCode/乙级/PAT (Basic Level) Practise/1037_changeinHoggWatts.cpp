//2016年1月31日14时13分23秒
//2016年1月31日14时34分36秒

//若sumkp,sumka使用int型,那么在中间转换成sumkp与sumka时
//最大可以达到4930000000 这已经超出int型的范围了
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long gp, sp, kp;
	long long ga, sa, ka;
	long long sumkp, sumka;
	long long back;
	long long gback, sback, kback;
	scanf("%lld.%lld.%lld", &gp, &sp, &kp);
	scanf("%lld.%lld.%lld", &ga, &sa, &ka);
	sumkp = (gp * 17 + sp) * 29 + kp;
	sumka = (ga * 17 + sa) * 29 + ka;
	back = sumka - sumkp;
	if(back < 0){
		printf("-");
		back = -1 * back;
	}
	gback = (back / 17) / 29;
	sback = (back % (17 * 29)) / 29;
	kback = (back % (17 * 29)) % 29;
	printf("%lld.%lld.%lld", gback, sback, kback);
	return 0;
}
