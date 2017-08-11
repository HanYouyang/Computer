//2016年2月22日19时27分32秒
//2016年2月22日20时39分59秒
#include <cstdio>
#include <algorithm>

using namespace std;

struct Fraction{
	long long up;//分子numerator
	long long down;//分母denumerator
};

long long gcd(long long a, long long b)
{//求最大公约数
	if(b == 0) return a;
	else return gcd(b, a % b);
}

Fraction reduction(Fraction result)
{//化简分数
	if(result.down < 0){//表示负数时，让分子为负
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0){//分子为零时，分母为1
		result.down = 1;
	} else {//约分到最简
		long long temp = gcd(abs(result.up), abs(result.down));
		result.up /= temp;
		result.down /= temp;
	}
	return result;
}

Fraction add(Fraction a, Fraction b)
{//两个分数相加
	Fraction temp;
	temp.up = a.up * b.down + a.down * b.up;
	temp.down = a.down * b.down;
	return temp;
}

void printResult(Fraction r)
{//打印结果
	if(r.down == 1) printf("%lld\n", r.up);//分母为1时，分数等于分子
	else if(r.up > r.down)//假分数要表示成带分数形式
		printf("%lld %lld/%lld\n", r.up / r.down, abs(r.up) % r.down, r.down);
	else printf("%lld/%lld\n", r.up, r.down);//真分数直接输出
}

int main()
{
	int n;
	scanf("%d", &n);
	Fraction temp, sum;
	sum.up = 0; sum.down = 1;
	for(int i = 0; i < n; i++){
		scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
		sum = reduction(sum);//每次加法后要化简分数，防止溢出
	}
	printResult(sum);
	return 0;
}
