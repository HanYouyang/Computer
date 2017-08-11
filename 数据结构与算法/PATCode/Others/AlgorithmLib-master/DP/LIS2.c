//合唱队形
//Miibotree
//2015.2.17
#include <stdio.h>
#include <algorithm>

using namespace std;

int a[101], lp[101], rp[101];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
		{
			int tmax = 1;
			for(int j = 1; j < i; j++)
			{
				if(a[j] < a[i])
					tmax = max(tmax, lp[j] + 1);
			}
			lp[i] = tmax;
		}

		for(int i = n; i >= 1; i--)
		{
			int tmax = 1;
			for(int j = n; j > i; j--)
			{
				if(a[j] < a[i])
					tmax = max(tmax, rp[j] + 1);
			}
			rp[i] = tmax;
		}
		int res = 1;
		for(int i = 1; i<= n; i++)
			res = max(res, lp[i] + rp[i]);
		res = n - (res - 1);
		printf("%d\n", res);

	}
	return 0;
}