#include <stdio.h>

bool visit[11];
int n;
//递归入口，递归边界
void DFS()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		if(visit[i] == false)
		{
			visit[i] = true;
			printf("%d ");
			DFS();
			visit[i] = false;
		}
	}
	printf("\n");
	return;
}

int main()
{

	scanf("%d", &n);
	DFS();
	return 0;
}