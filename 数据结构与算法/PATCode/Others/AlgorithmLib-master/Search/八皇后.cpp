//八皇后问题
#include <stdio.h>
int n;

int ans[11];
bool mark[11][11];
int flag = false;
void DFS(int depth)
{
	if(depth == n + 1)//放满了
	{
		for(int i = 1; i <= n; i++)
		{
			if(i != 1)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(mark[i][j] == true)//说明该位置不能放
				continue;
			if(judge(i, j))//说明该位置可以放置
			{
				add(i, j);
				ans[depth] = j;//列
				DFS(depth+1);
				clear(i, j);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	DFS(1);
	if(flag == false)
		printf("no solute!\n");
	return 0;
}