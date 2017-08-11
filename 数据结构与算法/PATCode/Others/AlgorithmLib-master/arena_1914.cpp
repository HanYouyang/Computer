//1914
#include <stdio.h>
#include <math.h>

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}
int main()
{
	int n;
	int a[1001];
	while( scanf("%d", &n) != EOF && n != 0)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int m;
		scanf("%d", &m);
		if(pow(2.0, m-1) > n)
			printf("EMPTY\n");
		else
		{
			int L = pow(2.0, m - 1);
			int R = min(n, pow(2.0, m) - 1);
			for(int i = L; i <= R; i++)
			{
				if(i != L)
					printf(" ");
				printf("%d", a[i]);
			}
			printf("\n");
		}
	}
	return 0;
}