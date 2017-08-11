#include<iostream>
#include<string>
int main()
{
	std::string num, n;
	int sum = 0;
	std::string zs[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	std::cin >> num;
	for (int i = 0; i < num.size(); ++i)
	{
		sum += (num[i] - '0');
	}
	if (sum >= 100)
	{
		std::cout << zs[sum / 100] << ' ';
		std::cout << zs[sum % 100 / 10] << ' ';
		std::cout << zs[sum % 10];
	}
	else if (sum >= 10)
	{
		std::cout << zs[sum % 100 / 10] << ' ';
		std::cout << zs[sum % 10];
	}
	else
		std::cout << zs[sum % 10];
	return 0;
}
