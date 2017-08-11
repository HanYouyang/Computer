//LIS(最长递增子序列)相关例题:拦截导弹
//Miibotree
//2015.2.17
//F[i] = {max(1, F[j] + 1 | j < i && a[j] >= a[i])}
#include <stdio.h>
#include <algorithm>//使用max函数

using namespace std;

int a[26], f[26];

int main()
{
	int k;
	int tmax;
	while(scanf("%d", &k) != EOF)
	{
		for(int i = 1; i <= k; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= k; i++)
		{
			tmax = 1;
			for(int j = 1; j < i; j++)
			{
				if(a[j] >= a[i])//当前的i比之前的j导弹要低
					tmax = max(tmax, f[j]+1);
			}
			f[i] = tmax;
		}
		int ans = 1;
		for(int i = 1; i <= k; i++)
			ans = max(ans, f[i]);
		printf("%d\n",  ans);
	}

	return 0;
}