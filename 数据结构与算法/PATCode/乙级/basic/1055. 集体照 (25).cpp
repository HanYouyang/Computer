#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
struct Person
{
	std::string name;
	int height;
}person;

bool compare(Person &p1, Person&p2)
{
	if (p1.height > p2.height)
		return true;
	else if (p1.height == p2.height&&p1.name < p2.name)//注意！！！只比较第一个字母为错！！！！！！累
		return true;
	else return false;
}
int main()
{
	int N, k;
	std::vector<Person> vec;
	std::string result,line;
	std::cin >> N >> k;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> person.name >> person.height;
		vec.push_back(person);
	}
	int p_num = N / k;
	int lp_num = N - N / k*(k-1);
	std::sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < lp_num; ++i)
	{
		if (i % 2 == 0)
		{
			if (i != lp_num - 1)
				result = " " + result;
			result = result + vec[i].name;
		}
		else
		{ 
			if (i != lp_num - 1)
				result = result + " ";
			result = vec[i].name + result;
		}
	}

	for (int i = lp_num; i < vec.size(); i=i+p_num)
	{
		line = "";
		for (int j = i; j < i+p_num; ++j)
		{
			if ((j-i) % 2 == 0)
			{
				if (j != i + p_num - 1)
					line = " " + line;
				line = line + vec[j].name;
			}
			else
			{
				if (j != i + p_num - 1)
					line = line + " ";
				line = vec[j].name + line;
			}
		}
		result = result + "\n" + line;
	}

	std::cout << result;

	return 0;
}