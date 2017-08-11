#include<iostream>
#include<string>
#include<cstdio>
float data[1010][100];
int count[1010] = {0};
int main()
{
	int N, D; float e;
	std::cin >> N >> e >> D;
	
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%f", &data[i][0]);
		for (int j = 1; j <= data[i][0]; ++j)
		{
			scanf_s("%f", &data[i][j]);
			if (data[i][j] < e)
				count[i]++;
		}
	}
	int k = 0, pk = 0;
	for (int i = 0; i < N; ++i)
	{
		if (count[i] / (float)data[i][0]>0.5)
		{
			pk++;
			if (data[i][0]>D)
				k++;
		}
	}

	printf("%.1f%% %.1f%%", (float)(pk-k) / N*100, (float)k / N*100);

	return 0;
}