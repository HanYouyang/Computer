#include<iostream>
#include<cstdio>
#include<algorithm>
struct Currency
{
	int G,S,K;
}P,A;
long long change(Currency &a)
{
	return a.G * 493 + a.S * 29 + a.K;
}
void show(long long &x)
{
	int a = x / 493;
	int b = x % 493 / 29;
	int c = x % 29;
	printf("%d.%d.%d", a, abs(b), abs(c));
}
int main()
{
	long long back;
	scanf_s("%d.%d.%d", &P.G, &P.S, &P.K);
	scanf_s("%d.%d.%d", &A.G, &A.S, &A.K);

	back = change(A) - change(P);
	show(back);
	return 0;
}