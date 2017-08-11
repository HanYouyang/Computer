#include<iostream>
#include<vector>
#include<string>

int main()
{
	int N, sum = 0;
	std::cin >> N;
	std::string id;
	std::vector<std::string> vec;
	std::vector<std::string> fvec;
	int Q[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int M[11] = { 1, 0, 40, 9, 8, 7, 6, 5, 4, 3, 2 };
	while (N--)
	{
		std::cin >> id;
		vec.push_back(id);
	}
	int count;
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < 17; ++j)
		{
			count = fvec.size();
			if (isdigit((vec[i][j])))
				sum += (vec[i][j] - '0')*Q[j];
			else
			{
				fvec.push_back(vec[i]);
				break;
			}
		}
		sum = sum % 11;
		if (vec[i][17]-'0'!= M[sum]&&count==fvec.size())
			fvec.push_back(vec[i]);
		sum = 0;
	}
	if (fvec.size() == 0)
		std::cout << "All passed";
	else
	{
		for (int i = 0; i < fvec.size(); ++i)
			std::cout << fvec[i] << std::endl;
	}
	
	return 0;
}