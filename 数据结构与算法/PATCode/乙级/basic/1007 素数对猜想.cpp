#include<iostream>
#include<vector>
#include<cmath>
bool isprime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i <=sqrt(x); ++i){
		if (x%i == 0)
			return false;
	}
	return true;
}

int main()
{
	std::vector<int> prime;
	int num;
	std::cin >> num;
	int sum = 0;
	for (int i = 0; i <= num; ++i)
	{
		if (isprime(i))
			prime.push_back(i);
	}
	for (unsigned int i = 1; i < prime.size(); ++i)
	{
		if (prime[i] - prime[i - 1] == 2)
			++sum;
	}
	std::cout << sum;
	return 0;
}