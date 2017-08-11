#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>

const int maxn = 100010;
int Num[maxn] = { 0 };
int leftmax[maxn] = { 0 };
int rightmin[maxn] = { 0 };


int main()
{
	int N;
	std::vector<int> vec;
	std::cin >> N;

	//*****************************
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &Num[i]);
		if (Num[i]>leftmax[i])
			leftmax[i+1] = Num[i];
		else leftmax[i + 1] = leftmax[i];
	}

	// ****************************
	rightmin[N - 1] = 2147483647;
	rightmin[N - 2] = Num[N - 1];
	for (int i = N-1; i > 0; --i)
	{
		if (Num[i]<rightmin[i])
			rightmin[i - 1] = Num[i];
		else rightmin[i - 1] = rightmin[i];
	}
	//******************************************
	int count=0;
	for (int i = 0; i < N; ++i)
	{
		if (Num[i]>leftmax[i] && Num[i] < rightmin[i])
		{
			++count; vec.push_back(i);
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < count; ++i)
	{
		printf("%d", Num[vec[i]]);
		if (i != count - 1) printf(" ");
	}
	if (count == 0)//第二行如果无元素，必须输出一个换行！！！！！
		printf("\n");
	return 0;
}