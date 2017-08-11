#include<stdio.h>
int main()
{
	int N, i;
	int cnt1 = 0;
	int cnt2 = 0;
	scanf("%d", &N);
	for(i = 0; i < N; ++i)
	{
		int guess1, guess2, sum, n1, n2;
		scanf("%d %d %d %d", &n1, &guess1, &n2, &guess2);
		sum = n1 + n2;
		if (sum == guess1 && sum != guess2)
		{
			cnt1 ++;
		}
		else if (sum != guess1 && sum == guess2)
		{
			cnt2 ++;
		}
	}
	printf("%d %d", cnt2, cnt1);
	return 0;
}
