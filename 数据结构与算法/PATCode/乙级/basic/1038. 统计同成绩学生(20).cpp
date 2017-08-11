#include<iostream>
#include<cstdio>
#include<vector>
int main()
{
	int N,M;
	std::vector<int>vec;
	int count[101] = { 0 };
	scanf_s("%d", &N);
	for (int temp,i = 0; i < N; ++i)
	{
		scanf_s("%d", &temp);
		if (temp>=0&&temp<=100)
			count[temp]++;
	}
	scanf_s("%d", &M);
	for (int temp, i = 0; i < M; ++i)
	{
		scanf_s("%d", &temp);
		vec.push_back(temp);
	}
	for (int i = 0; i < M ; ++i)
	{
		printf("%d", count[vec[i]]);
		(i != M - 1) ? printf(" ") : printf("\n");
	}
	return 0;
}