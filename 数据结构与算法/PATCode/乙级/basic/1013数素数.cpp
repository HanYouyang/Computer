#include<iostream>
#include<vector>
#include<cmath>
bool isprime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int M,N;
	std::cin >> M >> N;
	std::vector<int> prime;
	for (int i = 0,count=0; count < N; i++)
	{
		if (isprime(i))
		{
			prime.push_back(i);
			++count;
		}
	}
	for (int i = M - 1,j=1; i < prime.size() - 1; ++i)
	{
		std::cout << prime[i];
		if (j % 10 != 0)
			std::cout << ' ';
		else
			std::cout << std::endl;
		++j;
	}
	std::cout << prime[prime.size()-1];
	return 0;
}

