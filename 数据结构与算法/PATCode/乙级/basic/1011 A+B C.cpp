#include<iostream>
#include<vector>
int main()
{
	int num;
	std::vector<double> A, B, C;
	std::cin >> num;
	for (int i = 0; i < num; ++i)
	{
		int a=0, b=0, c=0;
		std::cin >> a >> b >> c;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
	}
	for (int i = 0; i < num; ++i)
	{
		if (A[i] + B[i]>C[i])
			std::cout << "Case #" << i + 1 << ": " << "true\n";
		else
			std::cout << "Case #" << i + 1 << ": " << "false\n";

	}
	return 0;
}

