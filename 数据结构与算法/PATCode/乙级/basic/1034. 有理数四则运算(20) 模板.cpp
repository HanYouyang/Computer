#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
struct Friction
{
	ll up;
	ll down;
}a,b;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}
Friction reduction(Friction result)
{
	if (result.down < 0){
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0)
		result.down = 1;//分子为0，令分母为1
	else
	{
		ll d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}
Friction add(Friction f1, Friction f2)
{
	Friction result;
	result.up = f1.up*f2.down + f2.up*f1.down;
	result.down = f1.down*f2.down;
	return reduction(result);
}
Friction minu(Friction f1, Friction f2)
{
	Friction result;
	result.up = f1.up*f2.down-f2.up*f1.down;
	result.down = f1.down*f2.down;
	return reduction(result);
}
Friction multi(Friction f1, Friction f2)
{
	Friction result;
	result.up = f1.up*f2.up;
	result.down = f1.down*f2.down;
	return reduction(result);
}
Friction divide(Friction f1, Friction f2)
{
	Friction result;
	result.up = f1.up*f2.down;
	result.down = f1.down*f2.up;
	return reduction(result);
}
void showresult(Friction r)
{
	r = reduction(r);
	if (r.up < 0) printf("(");
	if (r.down == 1) printf("%lld", r.up);
	else if (abs(r.up)>r.down)
	{
		printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
	}
	else printf("%lld/%lld", r.up, r.down);
	if (r.up < 0)
		printf(")");
}

int main()
{
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	//加法
	showresult(a);
	printf(" + ");
	showresult(b);
	printf(" = ");
	showresult(add(a, b));
	printf("\n");
	//减法
	showresult(a);
	printf(" - ");
	showresult(b);
	printf(" = ");
	showresult(minu(a, b));
	printf("\n");
	//乘法
	showresult(a);
	printf(" * ");
	showresult(b);
	printf(" = ");
	showresult(multi(a, b));
	printf("\n");
	//除法
	showresult(a);
	printf(" / ");
	showresult(b);
	printf(" = ");
	if (b.up == 0) printf("Inf");
	else showresult(divide(a, b));
	printf("\n");
	return 0;
}