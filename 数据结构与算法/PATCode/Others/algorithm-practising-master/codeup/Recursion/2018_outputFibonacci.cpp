//递归
//2016年2月18日10时03分45秒
//2016年2月18日
#include <cstdio>

int fibonacci(int n)
{
	if (n == 1) return 1;
	else if (n == 2) return 1;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int m = 0, n = 0;
	while(~scanf("%d", &m)){
		for(int i = 0; i < m; i++){
			scanf("%d", &n);
			for(int j = 0; j < n; j++){
				for(int k = 0; k < 2 * (n - j - 1); k++) printf(" ");
				printf("0");
				for(int k = 1 ; k < 2 * j + 1; k++) {
					printf(" %d", fibonacci(k)); 
				}
				printf("\n");
			}
		}
	}
	return 0;
}

//非递归（用递推法）
////2016年2月18日09时30分21秒
////2016年2月18日10时01分21秒
//#include <cstdio>
//
////maxn要大于等于2 * 10 - 1//*********************
//const int maxn = 25;
//
//void printGraph(int n){
//	int fibonacci[maxn] = {0};
//	fibonacci[0] = 0; fibonacci[1] = 1; fibonacci[2] = 1;
//	for(int i = 3; i < maxn; i++) fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < 2 * (n - i - 1); j++) printf(" ");
//		for(int j = 0; j < 2 * i + 1; j++) {
//			if(j) printf(" ");
//			printf("%d", fibonacci[j]);
//		}
//		printf("\n");
//	}
//	return;
//}
//
//int main()
//{
//	int m = 0;
//	while(~scanf("%d", &m)){
//		for(int i = 0; i < m; i++){
//			int n;
//			scanf("%d", &n);
//		//	if(n) printGraph(n);
//			printGraph(n);
//		}
//	}
//	return 0;
//}
