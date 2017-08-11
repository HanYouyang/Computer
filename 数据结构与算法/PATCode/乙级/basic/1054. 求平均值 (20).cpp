#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<cmath>
bool check_error(std::string &s)
{
	int po = 0, p = 3,j=0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (!isdigit(s[i]) && s[i] != '.' && s[i] != '-')
			return true;
		if (s[i] == '-')
			++j;
		if (s[i] == '.')
			po++;
		if (s[i] == '.')
			p = i;
	}
	if (po > 1 || (int)s.size() - p > 3 || j > 1)//unsigned int 为负数后变成无穷大！！！！
		 return true;
	return false;
}
float change(std::string &s)
{
	int f = 1, p=s.size()-1; double sum = 0.0;
	std::vector<int> vec;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '-')
		{
			f = -1; continue;
		}
		if (s[i] == '.')
		{
			p = i; continue;
		}
		vec.push_back(s[i] - '0');
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		sum += vec[i] * pow(10, vec.size() - i - 1);
	}
	sum = f*sum / pow(10,s.size() - p-1);
	return sum;
}

int main()
{
	int N,hs=0;
	float num, sum = 0.0;
	std::cin >> N;
	std::string str;
	std::vector<std::string> vec;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> str;
		vec.push_back(str);
	}
	for (int i = 0; i < vec.size(); i++)
	{
		if (check_error(vec[i]))
			std::cout << "ERROR: " << vec[i] << " is not a legal number\n";
		else
		{
			num = change(vec[i]);
			if (num>1000 || num < -1000)
				std::cout << "ERROR: " << vec[i] << " is not a legal number\n";
			else
				sum += num, ++hs;
		}
	}
	float average = sum / hs;
	if (hs == 0)
		std::cout << "The average of 0 numbers is Undefined";
	else if (hs==1)
		std::cout << "The average of " << hs << " number is " << std::fixed << std::setprecision(2) << average;//注意为1时的情况
	else
		std::cout << "The average of " << hs  << " numbers is " <<std::fixed<<std::setprecision(2)<<average;

	return 0;
}