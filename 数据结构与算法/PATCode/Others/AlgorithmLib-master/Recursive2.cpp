//递归函数的应用 回溯法枚举 素数环问题
//Miibotree
//2015.2.14
#include <stdio.h>
#include <string.h>

int ans[22];//ans数组里面存放已经满足条件的数字
bool hash[22];//相当于标记
int n;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};

bool judge(int x)
{
	for(int i = 0; i < 13; i++)
	{
		if(prime[i] == x)
			return true;
	}
	return false;
}

void check()//检查输出有回溯法输出得到的解
{
	//判断最后一个数和第一个数加起来是不是素数
	if(judge(ans[n]+ans[1]) == false)
		return;
	for(int i = 1; i <= n; i++)
	{
		if(i != 1)	printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}

void DFS(int num)//这里是关键代码,num为当前已经放入环中的数字个数
{
	if(num > 1)
	{
		if(judge(ans[num-1] + ans[num]) ==false)
			return;//不符合，递归出口
		if(num == n)
		{
			check();
			return;//返回，继续枚举下一组，递归出口
		}
	}
	for(int i = 2; i <= n; i++)
	{
		if(hash[i] == false)//i还没有放入环中
		{
			hash[i] = true;
			ans[num+1] = i;
			DFS(num+1);		//递归入口
			hash[i] = false;//回溯枚举该位数字，将i重新标记为未使用
		}
	}
}

int main()
{
	int cas = 0;
	while(scanf("%d", &n) != EOF)
	{
		cas++;
		for(int i = 0; i < 22; i++)	hash[i] = false;
		printf("Case %d:\n", cas);
		ans[1] = 1;
		hash[1] = true;
		DFS(1);
		printf("\n");
	}
	return 0;
}

