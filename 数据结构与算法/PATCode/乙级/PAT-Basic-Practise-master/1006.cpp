#include <stdio.h>
int main()
{
	int i,n;
	scanf("%d", &n);
	for(i=0; i<n/100; i++)
		printf("B");
	for(i=0; i<n/10%10; i++)
		printf("S");
	for(i=1; i<=n%10; i++)
		printf("%d",i);
	printf("\n");
	return 0;
}
