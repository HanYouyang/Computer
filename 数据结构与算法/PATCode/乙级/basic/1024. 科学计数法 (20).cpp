#include<iostream>
#include<string>
#include<cmath>
int main()
{
	std::string k_num;
	std::string num;
	std::string s_index;
	int index = 0;
	std::cin >> k_num;
	for (int i = 1; i < k_num.size() && k_num[i] != 'E'; i++)
	{
		if (k_num[i]<='9'&&k_num[i]>='0')
		num.push_back( k_num[i]);
	}
	for (int i = k_num.size() - 1; k_num[i] != 'E'; --i)
	{
		s_index.push_back(k_num[i]);
	}
	for (int i = 0; i < s_index.size()-1; ++i)
	{
		index += (s_index[i]-'0') * pow(10, i);
	}
	if (k_num[0] == '-')
		std::cout << k_num[0];

	if (index == 0) std::cout << num;
	else
	{
		if (s_index[s_index.size() - 1] == '-')
		{
			std::cout << 0 << '.';
			for (int i = 0; i < index - 1; i++) std::cout << 0;
			std::cout << num;
		}
		if (s_index[s_index.size() - 1] == '+')
		{
			if (num.size() - 1 <= index)
			{
				std::cout << num;
				for (int i = 0; i < index - num.size() + 1; ++i) std::cout << 0;
			}
			else
			{
				for (int i = 0; i <= index; i++)std::cout << num[i];
				std::cout << '.';
				for (int i = index + 1; i < num.size(); ++i) std::cout << num[i];
			}
		}
	}

		return 0;
}
