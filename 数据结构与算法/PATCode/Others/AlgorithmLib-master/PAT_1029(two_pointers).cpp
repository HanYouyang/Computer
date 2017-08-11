//PAT_1029.Median(25)
//two pointers
//Miibotree
//2015.2.25
#include <stdio.h>
#include <algorithm>
#define MAXN 1000001

using namespace std;

int a[MAXN], b[MAXN];

int main()
{
	int m, n;
	while(scanf("%d", &m) != EOF)
	{
		for(int i = 1; i <= m; i++)
			scanf("%d", &a[i]);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		int i = 1, j = 1, mid = (m + n + 1) / 2;
		int cnt = 0;
		while(cnt < mid)
		{
			if(i <= m && j <= n)//都没有到头
			{
				if(a[i] < b[j])
					i++;
				else
					j++;
			}
			else if(i == m + 1&& j < n)
				j++;
			else if(i < m && j == n + 1)
				i++;
			cnt++;
		}
		printf("%d\n", min(a[i-1], b[j-1]));
	}
	return 0;
}