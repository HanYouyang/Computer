//出栈序列统计

#include <stdio.h>
#include <queue>
#include <stack>
queue<int> q;
stack<int> s;
int cnt = 0;

void DFS(int depth)
{
	if(depth == n)//递归出口
	{
		cnt++;
		return;
	}
	if(q.size() > 0)//元素可以压栈
	{
		int x = q.front();
		q.pop();
		s.push(x);
		DFS(depth);//递归入口
	}
	if(s.size() > 0)//可以出栈
	{
		s.pop();
		DFS(depth + 1);//递归入口
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		q.push(i);
	DFS(0);
	print("%d\n", cnt);
	return 0;
}