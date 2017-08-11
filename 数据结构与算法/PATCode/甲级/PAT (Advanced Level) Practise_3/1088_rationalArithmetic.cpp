//2016年2月22日20时52分10秒
//2016年2月22日21时38分46秒
#include <cstdio>
#include <algorithm>

using namespace std;

struct Fraction{
	long long up;//分子
	long long down;//分母
};

long long gcd(long long a, long long b)
{//求a和b的最大公约数
	if(b == 0) return a;
	else return gcd(b, a % b);
}

Fraction reduction(Fraction a)
{//化简分数
	if(a.down < 0){//分数为负数，则让分子为负
		a.up = -a.up;
		a.down = -a.down;
	}
	if(a.up == 0){//分子为零，则把分母置为1
		a.down = 1;
	} else {//约分
		long long temp = gcd(abs(a.up), abs(a.down));
		//gcd参数要为整数，不加abs会出现答案错误
		a.up /= temp;
		a.down /= temp;
	}
	return a;
}

Fraction add(Fraction a, Fraction b)
{//a+b
	Fraction temp;
	temp.up = a.up * b.down + b.up * a.down;
	temp.down = a.down * b.down;
	return reduction(temp);//返回时化
}

Fraction sub(Fraction a, Fraction b)
{//a-b
	Fraction temp;
	temp.up = a.up * b.down - b.up * a.down;
	temp.down = a.down * b.down;
	return reduction(temp);//返回时化简
}

Fraction mul(Fraction a, Fraction b)
{//a*b
	Fraction temp;
	temp.up = a.up * b.up;
	temp.down = a.down * b.down;
	return reduction(temp);//返回时化简
}

Fraction div(Fraction a, Fraction b)
{//a/b
	Fraction temp;
	temp.up = a.up * b.down;
	temp.down = a.down * b.up;
	return reduction(temp);//返回时化简
}

void printResult(Fraction r)
{//输出
	r = reduction(r);
	if(r.up < 0) printf("(");
	if(r.down == 1){//整数
		printf("%lld", r.up);
	} else if(abs(r.up) > r.down){//假分数
		printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
	} else {//真分数
		printf("%lld/%lld", r.up, r.down);
	}
	if(r.up < 0) printf(")");
}

int main()
{
	Fraction a, b;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	//加法
	printResult(a);
	printf(" + ");
	printResult(b);
	printf(" = ");
	printResult(add(a, b));
	printf("\n");
	//减法
	printResult(a);
	printf(" - ");
	printResult(b);
	printf(" = ");
	printResult(sub(a, b));
	printf("\n");
	//乘法
	printResult(a);
	printf(" * ");
	printResult(b);
	printf(" = ");
	printResult(mul(a, b));
	printf("\n");
	//除法
	printResult(a);
	printf(" / ");
	printResult(b);
	printf(" = ");
	if(b.up == 0) printf("Inf");//除数为零时输出Inf
	else printResult(div(a, b));
	printf("\n");

	return 0;
}
