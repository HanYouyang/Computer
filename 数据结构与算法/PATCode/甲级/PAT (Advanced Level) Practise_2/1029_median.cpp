//2016年2月20日16时08分12秒
//2016年2月20日
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000010;
const int INF = 0x7fffffff;
long a[maxn];
long b[maxn];

int main()
{
	int m, n;
	//输入
	scanf("%d", &m);
	for(int i = 0; i < m; i++) scanf("%ld", a + i);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%ld", b + i);
	//处理
	//赋值INF后可以不用单独考虑还没到中位数时一个序列已经结束的情况
	a[m] = b[n] = INF;
	int medianPos = (m + n - 1) / 2;
	int i = 0, j = 0, count = 0;
	while(count < medianPos){
		if(a[i] < b[j]) i++;
		else j++;
		count++;
	}
	if(a[i] < b[j]) printf("%ld", a[i]);
	else printf("%ld", b[j]);
	return 0;
}
