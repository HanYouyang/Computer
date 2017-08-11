#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
	int N, num;
	int A[5] = { 0 };
	int p = 2,countA4=0;
	scanf_s("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &num);
		if (num % 5 == 0)
		{
			if (num % 2 == 0)
				A[0]+= num;
		}
		else if (num % 5 == 1)
		{
			A[1] += pow(-1, p)*num;
			p++;
		}
		else if (num % 5 == 2)
		{
			A[2]++;
		}
		else if (num % 5 == 3)
		{
			A[3] += num;
			countA4++;
		}
		else
		{
			if (num > A[4])
				A[4] = num;
		}
	}
	//输出答案
	if (A[0] == 0) printf("N ");
	else printf("%d ", A[0]);

	if (p == 2) printf("N ");//！！！这里只能用p来判断数字是否存在！！！！
	else printf("%d ", A[1]);

	if (A[2] == 0) printf("N ");
	else printf("%d ", A[2]);

	if (A[3] == 0) printf("N ");
	else printf("%.1f ", (double)A[3] / countA4);

	if (A[4] == 0) printf("N");
	else	printf("%d", A[4]);

	return 0;
}