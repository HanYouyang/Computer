//2016年2月21日17时43分27秒
//2016年2月21日18时49分20秒

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n, a = 1, ans = 0;
	int left, now, right;
	scanf("%d", &n);
	while (n/a) {
		left = n / (a * 10);
		now = n / a % 10;
		right = n % a;
		if(now == 0) ans += left * a;
		else if (now == 1) ans += left * a + right + 1;
		else ans += (left + 1) * a;
		a *= 10;
	}
	printf("%d", ans);
	return 0;
}
