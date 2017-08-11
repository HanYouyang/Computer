#include<iostream>
#include<string>
int main()
{
	std::string num, n;
	int n_t;
	int count[10] = { 0 };
	std::cin >> num;
	for (int i = 0; i < num.size(); ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if ((num[i] - '0') == j)
				++ count[j];
		}
	}
	
	for (int i = 0; i < 10; ++i)
	{
		if (count[i] != 0)
			std::cout << i << ':' << count[i] << std::endl;
	}

		return 0;
}
