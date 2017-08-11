#include<iostream>
#include<string>
#include<cmath>
int main()
{
	std::string A, B;
	int  Da, Db;
	int acount = 0, bcount = 0, a = 0, b = 0;
	std::cin >> A >> Da >> B >> Db;
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] == Da+48)
			++acount;
	}
	for (int i = 0; i < B.size(); ++i)
	{
		if (B[i] == Db+48)
			++bcount;
	}
	for (int i = acount; i >0; --i)
	{
		a += Da*pow(10,i-1);
	}
	for (int i = bcount; i >0; --i)
	{
		b += Db*pow(10, i - 1);
	}
	std::cout << a + b;
	return 0;
}
