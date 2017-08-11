#include <stdio.h>
#include <vector>
using namespace std;
vector<int> tree[1000];
int maxH = 0;
void DFS(int x, int depth)
{
	if(tree[x].size() == 0)
	{
		if(depth > maxH)
			maxH = depth;
	}
	for(int i = 0; i < tree[x].size(); i++)
		DFS(tree[x][i], depth + 1);
}

int main()
{
	int n, p, c;
	scanf("%d", &n);
	while(scanf("%d%d", &p, &c) != EOF)
	{
		tree[p].push_back(c);
	}
	DFS(1, 1);
	printf("%d\n", maxH);
	return 0;
}