#include<iostream>
#include<string>
#include<algorithm>
int main()
{
	int day;
	std::string weeks[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	std::string password[4];
	std::string str;
	int min = 0;
	std::cin >> password[0] >> password[1] >> password[2] >> password[3];
	for (int i = 0; i < std::min(password[0].size(), password[1].size()); ++i)
	{
		if (password[0][i] == password[1][i])
		{
			str.push_back(password[0][i]);
		}
	}
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i]<='G' && str[i]>='A')
		{
			std::cout << weeks[str[i] - 'A'] << ' ';
			for (int j = i + 1; j < str.size(); ++j)
			{
				if ((str[j]<='9' && str[i]>='0') || (str[j]<='N' && str[j]>='A'))
				{
					if (str[j] <= '9')
						printf("%02d:", str[j] - '0');
					else
						std::cout << str[j] - 'A'+10 << ':';
					break;
				}
			}
			break;
		}

	}

	for (int i = 0; i < std::min(password[2].size(), password[3].size()); ++i)
	{
		if ((password[2][i] == password[3][i]) && ((password[2][i]>='a' && password[2][i]<='z') || (password[2][i]<='Z' && password[2][i]>='A')))
		{
			min = i;
			break;
		}
	}
	printf("%02d", min);
	return 0;
}