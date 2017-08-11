#include<iostream>
#include<algorithm>

int main()
{
	int s_num[100010] = {0};

	int N;
	std::cin >> N;
	int sch_num, score;
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d %d", &sch_num, &score);
		s_num[sch_num] += score;	
	}
	int max = 0;
	max = std::max_element(s_num, s_num +N+1)-s_num;//注意数组从1开始！
	std::cout << max <<' '<< s_num[max];

	return 0;
}