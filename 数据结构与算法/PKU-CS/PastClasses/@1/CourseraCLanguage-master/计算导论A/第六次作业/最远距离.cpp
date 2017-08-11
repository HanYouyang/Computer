#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>
int main3()
{
	int n, i;
	float p[9][2], dis = -1.0;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		int j;
		scanf("%f%f", &p[i][0], &p[i][1]);
		for (j = 0; j<i; j++)
		{
			double l;
			l = (p[i][0] - p[j][0])*(p[i][0] - p[j][0]) + (p[i][1] - p[j][1])*(p[i][1] - p[j][1]);
			if (dis<l) dis = l;
		}
	}
	printf("%.4f\n", sqrt(dis));
	return 0;
}