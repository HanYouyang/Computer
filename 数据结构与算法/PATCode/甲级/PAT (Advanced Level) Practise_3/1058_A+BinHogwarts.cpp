//2016年1月31日15时57分27秒
//2016年1月31日16时05分51秒

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int ga, sa, ka;
	int gb, sb, kb;
	int gc, sc, kc;
	int carry;
	scanf("%d.%d.%d", &ga, &sa, &ka);
	scanf("%d.%d.%d", &gb, &sb, &kb);
	kc = (ka + kb) % 29;
	carry = (ka + kb) / 29;
	sc = (sa + carry + sb) % 17;
	carry = (sa + carry + sb) /17;
	gc = ga + gb + carry;
	printf("%d.%d.%d", gc, sc, kc);
	return 0;
}
