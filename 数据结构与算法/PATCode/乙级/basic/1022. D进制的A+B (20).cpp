#include<iostream>
#include<vector>
int main()
{
	unsigned int A, B, D;
	std::cin >> A >> B >> D;
	unsigned int sum = A + B;
	std::vector<int> remainder;
	unsigned int dividend = 1,r=0;
	while (dividend != 0)
	{
		dividend = sum / D;
		r = sum%D;
		remainder.push_back(r);
		sum = dividend;
	}
	for (int i = remainder.size() - 1; i >= 0; --i)
	{
		std::cout << remainder[i];
	}

	return 0;
}
