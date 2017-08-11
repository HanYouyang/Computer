#include <stdio.h>
#include <stdbool.h>

int main()
{
	int coefficient;
	int exponent;
	bool first = true;
	while(scanf("%d%d", &coefficient, &exponent) == 2){
		if(exponent*coefficient){
			if(first){
				printf("%d", coefficient*exponent);
				first = false;
			}
			else{
				printf(" %d", coefficient*exponent);
			}
			printf(" %d", exponent-1);
		}
	}
	if(first)
		printf("0 0");
	return 0;
}