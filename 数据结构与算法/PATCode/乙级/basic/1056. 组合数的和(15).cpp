#include<iostream>

int main()
{
	int N,sum=0;
	int num[9];
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> num[i];

	for (int i = 0; i < N; ++i)
	{
		for (int j = i+1; j < N; ++j)
		{
			sum += num[i] * 10 +num[j]+ num[j] * 10 + num[i];
		}
	}
	std::cout << sum;
	return 0;
}
