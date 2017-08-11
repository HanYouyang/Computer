#include <stdio.h>
#include <math.h>

#define MAX 1001
int d, n;
bool a[MAX];
int cnt;



int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			a[i] = x;
		}
		scanf("%d", &d);
		if(d > pow(2, n - 1))
			printf("EMPTY\n");
		else
		{
			int s = pow(2, n - 1);
			int e = pow(2, n) - 1;
			for(int i = s; i <= e && i <= n; i++)
				if(i == e || i == n)
					printf("%d\n", a[i]);
				else
				    printf("%d ", a[i]);
		}
	}
	return 0;
}