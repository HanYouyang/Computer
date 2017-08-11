//2016年2月23日18时01分12秒
//2016年2月23日18时31分00秒
#include <cstdio>
#include <cmath>

struct Factor{//用来存放质因子及其个数
	long long x;//质因子
	int cnt;//个数
}fac[20];

int main()
{
	long long n, backup;
	//backup备份n用作最后输出
	//input
	scanf("%lld", &n);
	if(n == 1){//特判n==1 直接输出
		printf("1=1");
		return 0;
	}
	//process
	backup = n;
	long long range = (long long)sqrt(1.0 * n);
	//根据结论：对于一个正整数n来说，如果它存在[2,n]范围内的质因子的话, >>
	//要么这些质因子全部小于等于sqrt(n),要么只存在一个大于sqrt(n)的质因子
	//根据上面的结论，只需要遍历到sqrt(n)即可
	int index = 0;
	for(int i = 2; i <= range; i++){
		if(n % i == 0){//如果i是n的质因子
			fac[index].x = i;
			fac[index].cnt = 0;
			while(n % i == 0){//求某个质因子的个数
				fac[index].cnt++;
				n /= i;
			}
			index++;
		}
	}
	if(n != 1){//当n!=1时，说名有一个大于sqrt(n)的质因子，则要记录这个质因子
		fac[index].x = n;
		fac[index].cnt = 1;
		index++;
	}
	//output
	printf("%lld=", backup);
	for(int i = 0; i < index; i++){
		if(i) printf("*");
		if(fac[i].cnt > 1) printf("%lld^%d", fac[i].x, fac[i].cnt);
		else printf("%lld", fac[i].x);
	}
	return 0;
}
