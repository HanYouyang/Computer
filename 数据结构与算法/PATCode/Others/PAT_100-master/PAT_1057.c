//PAT_1057. Stack (25 / 30)
//Miibotree
//2015.2.20
//2015.3.1 
//即使用二分来做也会超时的

#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

stack<int> s;
vector<int>vi;

void PeekMedian()
{
	int size = vi.size();
	if(size % 2 == 1)
		size = (size + 1) / 2;
	else
		size = size / 2;
	printf("%d\n", vi[size - 1]);
}	

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	char cmd[20];
	while(n--)
	{
		gets(cmd);
		int key;
		char str[10];
		switch(cmd[1])
		{
			case 'u'://push 
				sscanf(cmd, "%s%d", str, &key);
				s.push(key);
				vi.insert(lower_bound(vi.begin(), vi.end(), key), key);
			break;

			case 'o'://pop
				if(s.empty() == true)//栈是空的
					printf("Invalid\n");
				else
				{
					int x = s.top();
					s.pop();
					vi.erase(lower_bound(vi.begin(), vi.end(), x));
					printf("%d\n", x);
				}
				break;
			case 'e'://PeekMedian
				if(s.empty() == true)//栈是空的
					printf("Invalid\n");
				else
				{
					PeekMedian();
				}
		}
	}
	return 0;
}