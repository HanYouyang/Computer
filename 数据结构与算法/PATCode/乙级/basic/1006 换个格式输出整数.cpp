#include<iostream>

int main()
{
	int num;
	std::cin >> num;
	int b = num / 100;
	int s = num % 100 / 10;
	int g = num % 10;
	for (int i = 0; i <b; ++i)
		std::cout << 'B';
	for (int i = 0; i < s; ++i)
		std::cout << 'S';
	for (int i = 1; i <= g; ++i)
		std::cout <<i;
	return 0;
}