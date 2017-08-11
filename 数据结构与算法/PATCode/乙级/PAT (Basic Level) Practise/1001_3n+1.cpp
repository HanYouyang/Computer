#include <stdio.h>

int main()
{
	int n, count = 0;
	scanf("%d", &n);
	while(n != 1){
		if(n%2 == 0){
			n = n/2;
			count++;
		}
		else{
			n = (3*n+1)/2;
			count++;
		}
		// 改进如下：
		// if(n % 2 == 1)
		// 	n = n*3 +1;
		// else
		// 	n /= 2;
		// count++;
	}
	printf("%d\n", count);
	return 0;
}



// 题目条件是n < 1000，若条件改为 n < 1000000000(别数了，九个零)会发生什么条件？如何修改？
// 乘法会溢出。解决方法使用 long long 型整数来保存n，代码如下
// #include <stdio.h>
// int main()
// {
// 	int n2, count = 0;
// 	scanf("%d", &n2);
// 	long long n = n2;
// 	while(n != 1){
// 		if(n % 2 == 1)
// 			n = (n*3 +1)/2;
// 		else
// 			n /= 2;
// 		count++;
// 	}
// 	printf("%d\n", count);
// 	return 0;
// }
