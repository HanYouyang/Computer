#include<iostream>
#include<cstdio>


int main()
{
	int N,team,id,sco;
	int max = 0;
	int t_score[1001] = { 0 };
	scanf_s("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d-%d %d", &team, &id, &sco);
		t_score[team] += sco;
	}
	for (int i = 0; i < 1001; ++i)
	{
		if (t_score[i]>t_score[max])
			max = i;
	}
	printf("%d %d",max,t_score[max]);

	return 0;
}