#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<cstdio>
using std::cout;
using std::cin;
int main()
{
	int N,num;
	cin >> N;
	std::vector<int> vec;
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &num);
		vec.push_back(num);
	}

	std::sort(vec.begin(), vec.end(),std::greater<int>());
	
	/*for (int i =0; i <vec.size(); ++i)  错误！！！！满足有E天骑车超过E英里的最大整数E,不包括等于！！！
	{
		if (vec[i]<(i + 1))               加上等号还是有一个测试点无法通过！
		{
			printf("%d", i);break;        遗漏——如果所有公里数大于最大天数！！！
		}
	}*/
	int i = 0;
	while (i<vec.size(), vec[i]>i + 1)
	{
		++i;
	}
	printf("%d", i);
	return 0;
}