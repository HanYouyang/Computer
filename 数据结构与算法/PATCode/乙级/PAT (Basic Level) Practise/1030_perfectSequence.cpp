//2016年2月19日10时32分56秒
//2016年2月19日
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 100010;
long long a[maxn];

int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		//If no element in the range compares greater than a[i] * p, the function returns last.
		int j = upper_bound(a + i + 1, a + n, a[i] * p) - a;
		ans = max(ans, j - i);
	}
	printf("%d", ans);
	return 0;
}
//ForwardIter lower_bound(ForwardIter first, ForwardIter last,const _Tp& val)算法返回一个非递减序列[first, last)中的第一个大于等于值val的位置。
//ForwardIter upper_bound(ForwardIter first, ForwardIter last, const _Tp& val)算法返回一个非递减序列[first, last)中的第一个大于值val的位置。
