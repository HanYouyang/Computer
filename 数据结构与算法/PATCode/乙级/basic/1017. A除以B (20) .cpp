#include<iostream>
#include<string>
int main()
{
	std::string A;
	int Aresult[1000] = {0};
	int S,B,R=0;
	std::cin >> A >>  B ;
	for (int i = 0; i < A.size(); ++i)
	{
		S = ((A[i] - 48)+R*10)/B;
		Aresult[i]=S;
		R = ((A[i] - 48) + R * 10) % B;
	}
	if (Aresult[0]) std::cout << Aresult[0];
	else if (Aresult[0] == 0 && Aresult[1] == 0)
		std::cout << Aresult[0];
	for (int i = 1; i < A.size(); ++i)
		std::cout << Aresult[i];
	std::cout << ' ' << R;
	return 0;
}

/*  ÓÃstring ÎªÊ²Ã´´í
#include<iostream>
#include<string>
int main()
{
	std::string A, Aresult;
	int S, B, R = 0;
	std::cin >> A >> B;
	for (int i = 0; i < A.size(); ++i)
	{
		S = ((A[i] - '0') + R * 10) / B;
		Aresult.push_back(S + '0');
		R = ((A[i] - '0') + R * 10) % B;
	}
	if (Aresult[0] - '0') std::cout << Aresult[0];
	else if (Aresult[0] == '0' && Aresult[1] == '0')
		std::cout << Aresult[0];
	for (int i = 1; i < Aresult.size(); ++i)
		std::cout << Aresult[i];
	std::cout << ' ' << R;
	return 0;
}
*/