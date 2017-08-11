#include<iostream>
#include<cstdio>

double Num[100010] = { 0 };

int main()
{
	int N;double sum=0;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &Num[i]);
	}

	for (int i = 0; i < N; ++i)
	{
		sum += Num[i] * (i + 1)*(N - i);//¹æÂÉ (i + 1)*(N - i)
	}
	printf("%.2lf", sum);

	return 0;
}