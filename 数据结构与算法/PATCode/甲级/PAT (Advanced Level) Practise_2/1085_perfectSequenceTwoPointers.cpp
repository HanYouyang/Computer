//2016年2月20日13时33分40秒
//2016年2月20日13时44分39秒
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int a[maxn];

int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	//count = 0也正
	int i = 0, j = 0, count = 1;
	while(i < n && j < n){
		while( j < n &&  a[j] <= (long long)a[i] * p) j++;
		//if(count < j - i) count = j - i;
		count = max(count, j - i);
		i++;
	}
	printf("%d", count);
	return 0;
}
