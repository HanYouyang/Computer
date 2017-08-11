#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>

int change(std::string &s)
{
	int l = s.size();
	int sum = 0;
	for (int i = 0; i < l; ++i)
	{
		sum += (s[i] - '0')*pow(10, l - i - 1);
	}
	return sum;
}
int main()
{
	std::string low[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	std::string high[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	int N; std::string str;
	std::vector<std::string> vec;
	std::cin >> N;
	std::cin.get();
	for (int i = 0; i < N; ++i)
	{
		std::getline(std::cin, str);
		vec.push_back(str);
	}
	int h, l;
	for (int i = 0; i<vec.size(); ++i)
	{
		if (isdigit(vec[i][0]))
		{
			int sum = change(vec[i]);
			if (sum>12 && sum % 13 != 0)
				printf("%s %s\n", high[sum / 13 - 1].c_str(), low[sum % 13].c_str());
			else if (sum > 12 && sum % 13 == 0)
				printf("%s\n", high[sum / 13 - 1].c_str());
			else printf("%s\n", low[sum].c_str());
		}
		else
		{
			if (vec[i].size() > 4)
			{
				for (int j = 0; j < 12; j++)
				{
					if (vec[i].find(high[j]) < 100)
						h = j + 1;
				}
				for (int j = 0; j < 13; j++)
				{
					if (vec[i].find(low[j]) < 100)
						l = j;
				}
				printf("%d\n", h * 13 + l);
			}
			else
			{
				for (int j = 0; j < 13; j++)
				{
					if (vec[i].find(low[j]) < 100)
						printf("%d\n", j);
				}
				for (int j = 0; j < 12; j++)//若j<13,越界可执行，检查不出错误在哪，但提交后错
				{
					if (vec[i].find(high[j]) < 100)
						printf("%d\n", (j + 1) * 13);
				}
			}
		}
	}

	return 0;
}