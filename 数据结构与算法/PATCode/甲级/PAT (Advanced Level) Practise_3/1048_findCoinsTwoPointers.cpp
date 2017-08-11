//2016年2月20日17时37分37秒
//2016年2月20日
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int a[maxn];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
	}
	sort(a, a + n);
	int i = 0, j = n - 1;
	while(i < j){
		int temp = a[i] + a[j];
		if(temp == m){
			printf("%d %d", a[i], a[j]);
			return 0;
		}
		else if(temp > m) j--;
		else i++;
	}
	printf("No Solution");
	return 0;
}
