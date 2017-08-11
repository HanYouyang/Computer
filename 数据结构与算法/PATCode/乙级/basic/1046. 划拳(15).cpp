#include<iostream>
#include<cstdio>
#include<vector>
struct Record
{
	int js, jh, ys, yh;
}record;

int main()
{
	int N;
	std::vector<Record> vec;
	scanf_s("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d %d %d %d", &record.js, &record.jh, &record.ys, &record.yh);
		vec.push_back(record);
	}
	int js = 0, ys = 0;
	for (int i = 0; i < N; ++i)
	{
		if (vec[i].jh == vec[i].js + vec[i].ys)
		{
			if (vec[i].yh != vec[i].js + vec[i].ys)
				++ys;
		}
		if (vec[i].yh == vec[i].js + vec[i].ys)
		{
			if (vec[i].jh != vec[i].js + vec[i].ys)
				++js;
		}
		
	}
	printf("%d %d", js, ys);

	return 0;
}