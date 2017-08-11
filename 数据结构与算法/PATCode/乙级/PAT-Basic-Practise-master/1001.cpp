#include <stdio.h>
int main()
{
	int n;
	int i=0;
	scanf("%d", &n);
	while(n != 1){
		if(n % 2 == 0){
			n /= 2;
		} else {
			n = (3*n+1)/2;
		}
		i++;
	}
	printf("%d\n", i);
	return 0;
}
