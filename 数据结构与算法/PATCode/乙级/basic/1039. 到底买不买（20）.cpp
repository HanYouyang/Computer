#include<iostream>
#include<cstdio>



int main()
{
	int count[123] = { 0 };
	int acount[123] = { 0 };
	std::string str;
	char c;
	while (std::cin.peek() != '\n')
	{
		scanf_s("%c", &c,1);
		count[(int)c]++;
	}
	std::cin.get();
	while (std::cin.peek() != '\n')
	{
		scanf_s("%c", &c,1);
		acount[(int)c]++;
	}
	int d = 0, q = 0;
	for (int i = 0; i < 123; ++i)
	{
		if (count[i] < acount[i])
			q += acount[i] - count[i];
		else
			d += count[i] - acount[i];
	}
	if (q>0) printf("No %d", q);
	else printf("Yes %d", d);
}