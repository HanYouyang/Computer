#include <stdio.h>

int main()
{
	int T;
	long long a[10], b[10], c[10];
	scanf("%d", &T);
	for(int i = 0; i < T; i ++){
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	}
	for(int i = 0; i < T; i++){
		if(a[i] > (c[i] - b[i])){
			printf("Case #%d: true\n", i+1);
		}
		else{
			printf("Case #%d: false\n", i+1);
		}
	}
	return 0;
}
