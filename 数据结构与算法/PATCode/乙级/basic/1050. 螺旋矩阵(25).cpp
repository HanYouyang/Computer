#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
//为何最后一个测试点耗费那么多内存，排序？
const int maxn = 10010;
int matrix[maxn][maxn] = { 0 };
int main()
{
	int N,m,n,num;
	std::vector<int> vec;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &num);
		vec.push_back(num);
	}
	if (N == 1)
	{
		printf("%d", vec[0]); return 0;
	}
	std::sort(vec.begin(), vec.end(), std::greater<int>());


	for (int i = sqrt(N); i <= N; ++i)
	{
		if (N%i == 0)
		{
			m = i; n = N / m; break;
		}
	}
	if (m < n) std::swap(m, n);
	

	

	
	int count = 0;
	int i = 0, j = 0, left = 0, up = 0,right=n,down=m;
	
	while (count < N)
	{
		while (j < right-1&&count < N)
		{
			matrix[i][j++] = vec[count++];
		}

		while (i < down-1&&count < N)
		{
			matrix[i++][j] = vec[count++];	
		}

		while (j>left&&count < N)
		{
			matrix[i][j--] = vec[count++];
		}
 
		while (i>up&&count < N)
		{
			matrix[i--][j] = vec[count++];
		}
		
		left++, up++, down--, right--, i++, j++;
		if (count == N - 1)
		{
			matrix[i][j] = vec[count++];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d", matrix[i][j]);
			(j != n - 1) ? printf(" ") : printf("\n");
		}
	}
	
	return 0;
}