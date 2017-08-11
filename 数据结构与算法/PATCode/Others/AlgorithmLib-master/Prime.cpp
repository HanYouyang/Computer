//素数分解代码
#include <stdio.h>

int primeSize = 0;
int prime[10000];
int num[10000] = {0};
int mark[100001];

void FindPrime()
{
	for(int i = 2; i <= 100000; i++)
		mark[i] = false;
	for(int i = 2; i <= 100000; i++)
	{
		if(mark[i] == true)
			continue;
		prime[primeSize++] = i;
		for(int j = i + i; j <= 100000; j+=i)
			mark[j] = true;
	}
}

int main()
{
	long long n, m;
	scanf("%lld", &n);
	if(n == 1)
	{
		printf("1=1\n");
		return 0;
	}
	m = n;
	FindPrime();
	int last = 0;
	for(int i = 0; i < primeSize; i++)
	{
		if(n % prime[i] == 0)
		{
			last = prime[i];
			while(n % prime[i] == 0)
			{
				num[i]++;
				n /= prime[i];
			}
		}
		if(n == 1)
			break;
	}
	printf("%lld=", m);
	for(int i = 0; i < primeSize; i++)
	{
		if(num[i] > 0)
		{
			if(num[i] == 1)
				printf("%d", prime[i]);
			else
				printf("%d^%d", prime[i], num[i]);
			if(prime[i] != last)
				printf("*");
		}
	}
	return 0;
}