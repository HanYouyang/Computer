#include<iostream>
#include<vector>
#include<string>
int main()
{
	std::string str;
	std::vector<std::string> vec;
	while (std::cin.peek()!= '\n')
	{    
			std::cin >> str;
			vec.push_back(str);
	}

	for (int i = vec.size()-1; i >0; --i)
	{
		std::cout << vec[i]<<' ';
	}
	std::cout << vec[0];
		return 0;
}

