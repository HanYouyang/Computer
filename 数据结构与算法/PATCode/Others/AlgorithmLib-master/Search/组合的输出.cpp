//组合的输出
#include <stdio.h>
int n, r;
int ans[22];
bool flag[22];

void DFS(int depth)
{
	for(int i = 1; i <= n; i++)
	{
		if(flag[i] == false && ans[i-1] < i)
		{
			flag[i] = true;
			ans[depth] = i;
			if(depth < r)
				DFS(depth + 1);
			else
			{	
				for(int j = 1; j <= r; j++)
				{
					if(j != 1)
						printf(" ");
					printf("%d", ans[j]);
				}
				printf("\n");
			}
			flag[i] = false;
		}
	}
}

int main()
{
	ans[0] = -1;
	scanf("%d%d", &n, &r);
	DFS(1);
}