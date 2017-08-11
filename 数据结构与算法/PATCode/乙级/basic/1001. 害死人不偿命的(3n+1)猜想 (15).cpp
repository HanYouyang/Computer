#include<iostream>

int main()
{
	int n;
	int s = 0;
	std::cin >> n;
	while (n != 1)
	{
		if (n % 2)
			n = (3 * n + 1) / 2;
		else n = n / 2;
		++s;
	}
	std::cout << s << std::endl;

	return 0;
}
