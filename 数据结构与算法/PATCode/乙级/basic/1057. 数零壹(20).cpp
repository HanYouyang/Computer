#include<iostream>
#include<string>

int main()
{
	std::string str;
	std::getline(std::cin,str);
	int sum = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (isalpha(str[i]))
		{
			sum += tolower(str[i]) - 'a' + 1;
		}
	}
	int c, y[10] = {0},i=0;
	int count0 = 0, count1 = 0;
	while (sum!=0)
	{
		y[i] = sum % 2;
		if (y[i] == 0)
			count0++;
		else
			count1++;
		sum = sum / 2;
		i++;
	}

	std::cout << count0<<' '<<count1;
	return 0;
}
