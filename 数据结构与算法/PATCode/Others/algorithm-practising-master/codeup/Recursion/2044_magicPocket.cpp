//递归写法
//2016年2月18日10时18分37秒
//2016年2月18日11时10分52秒
//numbers[], n与递归没有太大的关系，可以考虑使用全局变量
//但是使用局部变量使用参数传递numbers， n可以增强函数的独立性
#include <cstdio>

const int maxn = 30;

int count(int numbers[], int n, int ith, int sum){
	if (sum == 0) return 1;
	else if (sum < 0 || ith == n) return 0;
	else return count(numbers, n, ith + 1, sum - numbers[ith])
			+ count(numbers, n, ith + 1, sum);
}

int main()
{
	int n, numbers[maxn] = {0}, sum = 40;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &numbers[i]);
		}
		printf("%d\n", count(numbers, n, 0, sum));
	}
	return 0;
}
