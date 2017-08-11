//2016年2月23日14时33分45秒
//2016年2月23日15时15分48秒
#include <cstdio>
#include <cmath>

bool isPrime(int n)
{//判断是否为素数
	if(n <= 1) return false;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

int main()
{
	int n, d, a[30] = {0};
	scanf("%d", &n);
	while(n >= 0){
		scanf("%d", &d);
		if(!isPrime(n)){//如果n本身不是素数，输出“No”
			printf("No\n");
		} else {//n是素数，判断n在radix进制下的逆序是否为素数
			int len = 0;
			while(n){//转换进制
				a[len++] = n % d;
				n /= d;
			}
			for(int i = 0; i < len; i++){//逆序转换进制
				n = n * d + a[i];
			}
			if(!isPrime(n)) printf("No\n");//逆序是素数，输出“Yes”
			else printf("Yes\n");//逆序不是素数，输出“No”
		}
		scanf("%d", &n);
	}
	return 0;
}
