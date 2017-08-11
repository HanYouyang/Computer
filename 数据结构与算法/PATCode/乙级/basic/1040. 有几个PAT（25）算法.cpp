#include<iostream>
#include<string>
int main()
{
	std::string str;
	std::cin >> str;
	long long sum = 0;
	int leftnumP[100010] = { 0 };
	int rightnumT[100010] = { 0 };
	for (int i = 0, j = 0; i < str.size(); ++i)
	{
		if (str[i] == 'P')
			j++;
		if (str[i] == 'A')
			leftnumP[i] = j;
	}
	for (int i = str.size() - 1, j = 0; i >= 0; --i)
	{
		if (str[i] == 'T')
			j++;
		if (str[i] == 'A')
			rightnumT[i] = j;
	}
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'A')
		{
			sum += leftnumP[i] * rightnumT[i];
		}
	}
	std::cout << sum % 1000000007;
	return 0;
}