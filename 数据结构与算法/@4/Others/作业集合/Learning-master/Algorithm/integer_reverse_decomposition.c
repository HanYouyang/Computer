#include <stdio.h>
int main() {
	int x;
//	scanf("%d", %x);
	x = 12345;
	do {
		int d = x % 10;
		printf("%d", d);
		if (x > 9) {
			printf(" ");
		}
		x = x / 10;	
	} while (x > 0);
	printf("\n");
	return 0;
} 
