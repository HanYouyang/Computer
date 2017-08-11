//2016年2月19日21时07分25秒
//2016年2月19日
#include <cstdio>
#include <algorithm>

using namespace std;
int a[100010];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		int v1 = a[i];
		int left = i + 1, right = n - 1, mid;
		while(left <= right){
			mid = (left + right) / 2;
			if(a[mid] + v1 == m){
				printf("%d %d\n", v1, a[mid]);
				return 0;
			} else if(a[mid] + v1 < m){
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
	}
	printf("No Solution\n");
	return 0;
}
