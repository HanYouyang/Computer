#include<iostream>
#include<string>
#include<vector>
int main()
{
	int N;
	int na = 0, nb = 0, nc = 0;
	std::cin >> N;
	std::vector<std::string> vec;
	std::string str;
	for (int i = 0; i < N; i++)
	{
		std::cin >> str;
		vec.push_back(str);
	}
	int acount = 0, bcount = 0;
	for (int i = 0; i < vec.size(); ++i)
	{

		for (int j = 0; j < vec[i].size(); ++j)
		{
			bcount = acount;
			if (!(vec[i][j] == 'P' || vec[i][j] == 'A' || vec[i][j] == 'T'))
			{
				std::cout << "NO\n"; ++acount; break;
			}
			if (vec[i][j] == 'P')
				na = j;
			if (vec[i][j] == 'T')
				nb = j - na - 1;
		}
		nc = vec[i].size() - na - nb - 2;
		if (na == nc&&nb == 1)
			std::cout << "YES\n";
		else if (na*nb==nc&&nb>=1)//×¢ÒâµÝÍÆ£¡£¡£¡
			std::cout << "YES\n";
		else if (acount == bcount)
			std::cout << "NO\n";
	}


	return 0;
}