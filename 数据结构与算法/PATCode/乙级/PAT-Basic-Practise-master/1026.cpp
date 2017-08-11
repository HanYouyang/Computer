#include <stdio.h>
#include <math.h>
int main()
{
	int c1, c2;
	scanf("%d %d", &c1, &c2);
	int m = round((c2 - c1) / 100.0);
	printf("%02d:%02d:%02d\n", m/3600, m%3600/60, m%60);
	return 0;
}
