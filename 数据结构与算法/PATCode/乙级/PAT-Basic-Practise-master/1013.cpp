#include <stdio.h>
#include <string.h>
char arr[105000];
int main()
{
	//筛法找出所有素数 
	//memset(arr, 1, sizeof(char) * 105000);
	int i, j;
	for(i=0; i<105000; i++)
		arr[i] = 1;
	arr[0] = 0; arr[1] = 0;
	
	for(i=2; i<=105000/2; i++)
		for(j=2; i*j<105000; j++)
			arr[i*j] = 0;
	
	int M, N, K=0;
	scanf("%d %d", &M, &N);
	for(i=2; i<=105000; i++){
		if(arr[i] == 1)
			K++;
		if(K == M)
			break;
	}
	int p = 1;
	for(; K<=N; i++){
		if(arr[i] == 1){
			if(p == 1){
				printf("%d", i);
				p++;
			} else if(p == 10){
				printf(" %d\n", i);
				p = 1;
			} else {
				printf(" %d", i);
				p++;
			}
			K++;
		}
	}
	
	return 0;
}
