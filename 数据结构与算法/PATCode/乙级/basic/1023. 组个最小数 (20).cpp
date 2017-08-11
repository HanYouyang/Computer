#include<iostream>
int main()
{
	int a[10];
	for (int i = 0; i < 10; ++i)
	{
		std::cin >> a[i];
	}
	if (a[0] == 0)
		for (int i = 0; i < 10; ++i)
		{
			if (a[i] != 0)
			{
				for (int j = 0; j < a[i]; ++j)
					std::cout << i;
			}
		}
	else
	for (int i = 1,count=0; i < 10; ++i)
	{
		if (a[i] != 0&&count==0)
		{
			std::cout << i;
			for (int k = 0; k < a[0]; ++k) std::cout << 0;
			for (int k = 0; k < a[i]-1; ++k) std::cout << i;
			++count;
		}
		else
		for (int k = 0; k < a[i]; ++k) std::cout << i;
	}
	

	return 0;
}
