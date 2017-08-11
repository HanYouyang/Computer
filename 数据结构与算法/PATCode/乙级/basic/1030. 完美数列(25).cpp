#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<cstdio>
int main()
{
	std::vector<int> vec;
	int N, p, num = 0;
	std::cin >> N >> p;
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &num);
		vec.push_back(num);
	}

	std::sort(vec.begin(), vec.end(), std::less<int>());
	int max = 0,j=0;

	for (int i = 0; i < vec.size(); ++i)
	{
		j = std::upper_bound(vec.begin()+i+1, vec.end(), (long long)vec[i] * p)-vec.begin();
		max = std::max(max, j - i);
	}
	std::cout << max;

	return 0;
}
//iterator lower_bound( const key_type &key ): 返回一个迭代器，指向键值>= key的第一个元素。

//iterator upper_bound(const key_type &key) :返回一个迭代器，指向键值> key的第一个元素。