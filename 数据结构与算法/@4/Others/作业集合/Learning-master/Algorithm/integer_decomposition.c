#include <stdio.h>
int main() {
	int x;
//	scanf("%d", &x);
	x = 70000;
	int mask = 1;
	int t = x;
	while (t > 9) {
		t = t / 10;
		mask = mask * 10;
	}
	do {
		int d = x / mask;
		printf("%d", d);
		if (mask > 9) {
			printf(" ");
		}
		x = x % mask;
		mask = mask / 10;
	} while (mask > 0);
	printf("\n");
	return 0;
}
