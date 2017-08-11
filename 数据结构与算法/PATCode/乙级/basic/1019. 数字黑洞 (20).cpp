
#include<iostream>
#include<algorithm>
#include<functional>
void change(int &num, int*a)
{
	a[0] = num / 1000;
	a[1] = num % 1000 / 100;
	a[2] = num % 100 / 10;
	a[3] = num % 10;
}
int main()
{
	int a[4] = { 0 };
	int b[4] = { 0 };
	int num;
	std::cin >> num;
	change(num, a);
	if (a[0] == a[1]&&a[1] == a[2]&&a[2] == a[3])
	{
		printf("%04d - %04d = %04d\n", num, num, 0); return 0;
	}
	if (a[0] == 6 && a[1] == 1 && a[2] == 7 && a[3] == 4)
	{
		printf("7641 - 1467 = 6174\n"); return 0;
	}
	while (num != 6174)
	{
		change(num, a);
		for (int i = 0; i < 4; ++i)
			b[i] = a[i];
		std::sort(a, a + 4, std::less<int>());
		std::sort(b, b + 4, std::greater<int>());
		int B = b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3];
		int A = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
		num = B-A;
		printf("%04d - %04d = %04d\n", B, A, num);
	}

	return 0;
}

