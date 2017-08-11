#include<iostream>
#include<cstdio>
#include<algorithm>
int main()
{
	int count[123] = { 0 };
	char c;
	while (std::cin.peek() != '\n')
	{
		c = std::cin.get();
		count[(int)c]++;
	}
	int arr[6] = { count[(int)'P'], count[(int)'A'], count[(int)'T'],
		 count[(int)'e'], count[(int)'s'], count[(int)'t'] };
	int *m = std::max_element(arr, arr+6);
	int M = *m;
	for (int i = 0; i <M; ++i)
	{
		if (arr[0]>0)
		{
			printf("P"); --arr[0];
		}
		if (arr[1]>0)
		{
			printf("A"); --arr[1];
		}
		if (arr[2]>0)
		{
			printf("T"); --arr[2];
		}
		if (arr[3]>0)
		{
			printf("e"); --arr[3];
		}
		if (arr[4]>0)
		{
			printf("s"); --arr[4];
		}
		if (arr[5]>0)
		{
			printf("t"); --arr[5];
		}
		
	}

	return 0;
}