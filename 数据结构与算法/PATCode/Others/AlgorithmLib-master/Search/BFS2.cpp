//非常可乐
//Miibotree
//2015.2.14
//广度优先搜索的另一个例题
#include <stdio.h>
#include <queue>
using namespace std;
struct N{
	int a;
	int b;
	int c;
	int t;
};
bool mark[101][101][101];
queue <N> Q;

void AtoB(int &a, int sa, int &b, int sb)//从容积为sa的杯子倒到容积为sb的杯子
{										 //注意这里是引用而不是取址
	if (sb - b >= a)//a可以全部倒入b中
	{
		b += a;
		a = 0;
	}
	else
	{
		a -= sb - b;
		b = sb;
	}
}

int BFS(int s, int n, int m)
{
	while (Q.empty() == false)
	{
		N now = Q.front();
		Q.pop();
		int a, b, c;
		//a->b
		a = now.a;
		b = now.b;
		c = now.c;
		AtoB(a, s, b, n);//a倒入b中
		if(mark[a][b][c] == false)//该状态尚未出现
		{
			mark[a][b][c] = true;
			N tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = now.t + 1;
			if(a == s / 2 && b == s / 2 || 
			   a == s / 2 && c == s / 2 ||
			   b == s / 2 && c == s / 2)	return tmp.t;
			Q.push(tmp);
		}

		//b->a
		a = now.a;
		b = now.b;
		c = now.c;
		AtoB(b, n, a, s);
		if(mark[a][b][c] == false)//该状态尚未出现
		{
			mark[a][b][c] = true;
			N tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = now.t + 1;
			if(a == s / 2 && b == s / 2 || 
			   a == s / 2 && c == s / 2 ||
			   b == s / 2 && c == s / 2)	return tmp.t;
			Q.push(tmp);
		}

		//a->c
		a = now.a;
		b = now.b;
		c = now.c;
		AtoB(a, s, c, m);
		if(mark[a][b][c] == false)//该状态尚未出现
		{
			mark[a][b][c] = true;
			N tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = now.t + 1;
			if(a == s / 2 && b == s / 2 || 
			   a == s / 2 && c == s / 2 ||
			   b == s / 2 && c == s / 2)	return tmp.t;
			Q.push(tmp);
		}

		//c->a
		a = now.a;
		b = now.b;
		c = now.c;
		AtoB(c, m, a, s);
		if(mark[a][b][c] == false)//该状态尚未出现
		{
			mark[a][b][c] = true;
			N tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = now.t + 1;
			if(a == s / 2 && b == s / 2 || 
			   a == s / 2 && c == s / 2 ||
			   b == s / 2 && c == s / 2)	return tmp.t;
			Q.push(tmp);
		}

		//b->c
		a = now.a;
		b = now.b;
		c = now.c;
		AtoB(b, n, c, m);
		if(mark[a][b][c] == false)//该状态尚未出现
		{
			mark[a][b][c] = true;
			N tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = now.t + 1;
			if(a == s / 2 && b == s / 2 || 
			   a == s / 2 && c == s / 2 ||
			   b == s / 2 && c == s / 2)	return tmp.t;
			Q.push(tmp);
		}

		//c->b
		a = now.a;
		b = now.b;
		c = now.c;
		AtoB(c, m, b, n);
		if(mark[a][b][c] == false)//该状态尚未出现
		{
			mark[a][b][c] = true;
			N tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = now.t + 1;
			if(a == s / 2 && b == s / 2 || 
			   a == s / 2 && c == s / 2 ||
			   b == s / 2 && c == s / 2)	return tmp.t;
			Q.push(tmp);
		}
	}
	return -1;
}

int main()
{
	int s, n, m;
	while(scanf("%d%d%d", &s, &n, &m) != EOF)
	{
		if (s == 0 && n == 0 && m == 0)
			break;
		if(s % 2 == 1)//这里做了优化，奇数肯定不能平分
		{
			puts("NO");
			continue;
		}
		for(int i = 0; i <= s; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				for(int k = 0; k <= m; k++)
				{
					mark[i][j][k] = false;
				}
			}
		}
		while(Q.empty() == false)	Q.pop();
		N tmp;
		tmp.a = s;
		tmp.b = 0;
		tmp.c = 0;
		tmp.t = 0;
		Q.push(tmp);
		mark[s][0][0] = true;
		int res = BFS(s,n,m);
		if (res == -1)
			puts("NO");
		else
			printf("%d\n", res);
	}
	return 0;
}