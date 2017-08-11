#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 100005

bool isPrime(int n){
	for(int i =  2; i*i <= n; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int mark[MAXN];
	memset(mark, 0, sizeof(mark));
	int N;
	int count = 0;
	scanf("%d", &N);
	for(int i = 2; i <= N; i++){
		// Why segmentation fault (core dumped)??????????????????????????
		// if(0 == mark[i]){ 			//has not yet judged whether i is prime or not.
		// 	if(isPrime(i)){
		// 		for(int j = i; i*j <= N; j++){
		// 			mark[i*j] = 1;		//i*j is not a prime.
		// 		}
		// 	}
		// 	else{
		// 		mark[i] = 1;	//i is not a prime.
		// 	}
		// }
		if(!isPrime(i)){
			mark[i] = 1;
		}
	}

	int tag = 0;
	for(int i = 2; i <= N; i++){
		if(1 == mark[i]){
			tag += 1;
		}
		else{
			if(1 == tag)
				count ++;
			tag = 0;
		}
	}
	printf("%d", count);
	return 0;
}
