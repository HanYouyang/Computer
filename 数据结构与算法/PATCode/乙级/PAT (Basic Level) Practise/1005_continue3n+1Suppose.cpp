#include <stdio.h>

int main()
{
	int n;
	int num;
	int tag = 1;
	int mark[105] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		mark[num] = 1;
	}
	for(int i = 1; i <= 100; i++){
		if(mark[i] == 0)
			continue;
		num = i;
		while(num != 1){
			if(num % 2 == 0){
				num = num/2;
				if(num < 101)
					mark[num] = 0;
			}
			else{
				num = (3*num+1)/2;
				if(num < 101)
					mark[num] = 0;
			}
		}	
	}
	for(int i = 100; i > 1; i--){
		if(mark[i] == 1){
			if(tag){
				tag = 0;
				printf("%d", i);
			}
			else
				printf(" %d", i);
		}
	}
	return 0;
}



