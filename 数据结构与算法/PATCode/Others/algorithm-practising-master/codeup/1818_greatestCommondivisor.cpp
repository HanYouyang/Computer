
#include <cstdio>

int gcd(int a, int b)
{
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	int a, b;
	while(~scanf("%d%d", &a, &b)){
		if(a > b) printf("%d\n", gcd(a, b));
		else printf("%d\n", gcd(b, a));
	}
	return 0;
}
