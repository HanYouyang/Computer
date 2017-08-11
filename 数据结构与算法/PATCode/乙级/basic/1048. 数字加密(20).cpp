#include<iostream>
#include<string>
#include<algorithm>
int main()
{
	std::string A;
	std::string B;
	std::cin >> A >> B;
	std::reverse(A.begin(), A.end());
	std::reverse(B.begin(), B.end());
	for (int i = 0; i <A.size(); ++i)
	{
		if (i>=B.size())//被加密数小于，补0
			B.push_back('0');
		if ((i + 1) % 2 == 0)
		{
			if (B[i] - A[i] < 0)
				B[i] = B[i] - A[i] + 10 + '0';
			else B[i] = B[i] - A[i] + '0';
		}
		else
		{
			B[i] = (B[i] - '0' + A[i] - '0') % 13 + '0';
			if (B[i] == 10 + '0') B[i] = 'J';
			if (B[i] == 11 + '0') B[i] = 'Q';
			if (B[i] == 12 + '0') B[i] = 'K';
		}
	}
	std::reverse(B.begin(), B.end());
	std::cout << B;

	return 0;
}