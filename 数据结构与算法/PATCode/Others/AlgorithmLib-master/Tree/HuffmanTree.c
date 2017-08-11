#include <queue>
#include <stdio.h>

using namespace std;

priority_queue<int, vector<int>, greater<int> > Q;//注意这里如果是>>编译会不通过
int main(){
	int n;
	while(scanf("%d", &n) != EOF)
	{
		while(Q.empty()== false) Q.pop();
		for(int i = 1; i <= n; i++)//建堆
		{
			int x;
			scanf("%d", &x);
			Q.push(x);
		}
		int ans = 0;
		while(Q.size() > 1)
		{
			int a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();

			ans += a + b;
			Q.push(a+b);			
		}
		printf("%d\n",  ans);
	}
	return 0;
}