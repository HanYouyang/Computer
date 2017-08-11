#include<iostream>
#include<vector>
int main()
{
	std::vector<int>vec;
	int num;
	while (std::cin.peek() != '\n')
	{
		std::cin >> num;
		vec.push_back(num);
	}
	if ((vec.size() == 2 && vec[1] == 0)||vec.size()==1)
	{
		std::cout << 0 << ' ' << 0;
	}
	else
	{
		if (vec[vec.size() - 1] == 0)
		{
			for (int i = 0; i < vec.size() - 2; i = i + 2)
			{
				int a = 0, b = 0;
				a = vec[i] * vec[i + 1];
				b = vec[i + 1] - 1;
				std::cout << a << ' ' << b;
				if (i < vec.size() - 4)
					std::cout << ' ';
			}
		}
		else 
		{
			for (int i = 0; i < vec.size() - 2; i = i + 2)
			{
				int a = 0, b = 0;
				a = vec[i] * vec[i + 1];
				b = vec[i + 1] - 1;
				std::cout << a << ' ' << b<<' ';
			}
			std::cout << vec[vec.size() - 2] * vec[vec.size() - 1] << ' ' << vec[vec.size() - 1] - 1;
		}
	}
	return 0;
}

