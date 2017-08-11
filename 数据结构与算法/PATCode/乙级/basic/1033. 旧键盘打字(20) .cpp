#include<iostream>
#include<algorithm>
#include<string>
int main()
{
	std::string b_Key;
	std::string input;
	std::string r_input;
	std::getline(std::cin,b_Key);//防止第一行是空格！！！
	std::cin >> input;
	for (int i = 0; i < input.size(); ++i)
	{
		if (b_Key.find(toupper(input[i]))>100010)
			r_input.push_back(input[i]);

	}
	int count = 0;
	if (b_Key.find('+') < 100010)//上档键坏掉！！！
	{
		for (int i = 0; i < r_input.size(); ++i)
		{
			if (!(r_input[i] >= 'A'&&r_input[i] <= 'Z'))
			{
				printf("%c", r_input[i]);
		
			}
		}
	}
	else
		std::cout << r_input;
	
	
		printf("\n");
	return 0;
}