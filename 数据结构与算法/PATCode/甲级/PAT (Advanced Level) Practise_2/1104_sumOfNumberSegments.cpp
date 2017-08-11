//2016年2月20日21时34分44秒
//2016年2月20日21时48分24秒
#include <cstdio>

int main()
{
	int n;
	double positive, sum = 0.0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lf", &positive);
		sum += positive * (n - i) * (i + 1);
	}
	printf("%.2f\n", sum);
	return 0;
}
