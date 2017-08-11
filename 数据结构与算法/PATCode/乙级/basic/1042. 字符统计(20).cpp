#include<iostream>
#include<string>


int main()
{
	
	int count[123] = { 0 };
	std::string str;
	std::getline(std::cin, str);
	for (int i = 0; i < str.size(); ++i)
	{
		count[(int)tolower(str[i])]++;
	}
	int max = 0;
	for (int i = 95; i < 123; ++i)
	{
		if (count[i]>count[max])
			max = i;
	}
	std::cout << (char)max << ' ' << count[max];
	return 0;
}