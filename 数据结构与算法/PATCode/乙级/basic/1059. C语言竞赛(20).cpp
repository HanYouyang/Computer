#include<iostream>
#include<string>
#include<vector>
#include<cmath>
std::string ans[10000] ;
int count[10000] = { 0 };
bool isPrime(int a)
{
	if (a == 1 || a == 3) return true;
	if (a == 2) return false;
	for (int i = sqrt(a); i < a; ++i)
	{
		if (a%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int N,K,id;
	std::string str;
	std::vector<int> seek;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> id;
		if (i == 0) ans[id] = "Mystery Award";
		else if (isPrime(i+1)) ans[id] = "Minion";
		else ans[id] = "Chocolate";
	}
	std::cin >> K;
	int num;
	for (int i = 0; i < K; ++i)
		std::cin >> num, seek.push_back(num);

	for (int i = 0; i < K; ++i)
	{
		if (ans[seek[i]] != "")
		{
			if (count[seek[i]] == 0)
			{
				printf("%04d: %s\n", seek[i], ans[seek[i]].c_str());
				count[seek[i]]++;
			}
			else printf("%04d: %s\n", seek[i], "Checked");
		}
		else printf("%04d: %s\n", seek[i], "Are you kidding?");
	}


	return 0;
}