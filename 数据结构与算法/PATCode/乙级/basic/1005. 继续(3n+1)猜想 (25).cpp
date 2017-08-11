#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>

int main()
{
	int size;
	int s = 0;
	std::vector<int> num;
	std::vector<int> comp;
	std::vector<int> answer;
	std::cin >> size;
	for (int i = 0; i < size; ++i)
	{
		int t = 0;
		std::cin >> t;
		num.push_back(t);
		int n = num[i];
		while (n != 1)
		{
			if (n % 2)
				n = (3 * n + 1) / 2;
			else n = n / 2;
			comp.push_back(n);
			++s;
		}
	}

	for (int i = 0; i < size; ++i)
	{
		if (comp.end() == find(comp.begin(), comp.end(), num[i]))
			answer.push_back(num[i]);
	}
	sort(answer.begin(), answer.end(), std::greater<int>());
	for (int i = 0; i < answer.size(); ++i)
	{
		std::cout << answer[i] ;
		if (i != answer.size() - 1)
			std::cout << ' ';
	}

	return 0;
}