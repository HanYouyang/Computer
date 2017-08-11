#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
struct Exam
{
	std::string id;
	int sj;
	int ks;
}exam;
int main()
{
	int N,M;
	int sj[1010] = { 0 };
	std::vector<Exam> vec;
	scanf_s("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		std::cin>> exam.id>>exam.sj>>exam.ks;//读入string字符串最好用cin
		vec.push_back(exam);
	}
	scanf_s("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d", &sj[i]);
	}
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (vec[j].sj == sj[i])
				printf("%s %d\n",vec[j].id.c_str(),vec[j].ks);//printf输出string字符串
		}
	}

	return 0;
}