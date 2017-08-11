#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
int N; int oriarray[100] = { 0 }; int temparray[100] = { 0 }; int change[100] = { 0 };
bool issame(int A[], int B[])
{
	for (int i = 0; i < N; i++)
	{
		if (A[i] != B[i]) return false;
	}
	return true;
}
void showarray(int A[])
{
	for (int i = 0; i < N-1; ++i)
		printf("%d ", A[i]);
	printf("%d",A[N-1]);
}
bool Insertionsort(int A[], int N)
{
	int tmp,i,P,flag=false;
	for (P = 1; P < N; ++P)
	{
		if (P != 1 && issame(A, change))
			flag = true;
		tmp = A[P];
		for (i = P; i>0 && A[i-1]>tmp; --i)
			A[i] = A[i - 1];
		A[i] = tmp;
		if (flag == true)
			return true;	
	}
	return false;
}


void mergesort(int A[], int N)
{
	for (int step = 2; step/2 <= N; step *= 2)
	{
		for (int i = 0; i < N; i += step)
			std::sort(A + i, A+std::min((i + step),N));
	}
}

int main()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf_s("%d",&oriarray[i]);
	for (int i = 0; i < N; ++i)
		scanf_s("%d",&change[i]);
	for (int i = 0; i < N; ++i)
		temparray[i]=oriarray[i];
	if (Insertionsort(oriarray, N))
	{
		printf("Insertion Sort\n");
		showarray(oriarray);
	}
	else
	{
		printf("Merge Sort\n");
		mergesort(temparray, N);
		showarray(temparray);
	}
	return 0;
}