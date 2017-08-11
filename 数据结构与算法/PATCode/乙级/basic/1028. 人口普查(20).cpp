#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
struct People
{
	char name[6];
	int birthday;
};
int change(char a[11])
{
	int num = 0;
	for (int i = 0; i < 4; ++i)
		num += (a[i] - '0')*pow(10, 7 - i);
	num += (a[5] - '0') * 1000;
	num += (a[6] - '0') * 100;
	num += (a[8] - '0') * 10;
	num += a[9] - '0';
	return num;
}
int main()
{
	int N;
	People people;
	std::vector<People> vec;
	char birth[11];
	std::cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		scanf("%s %s",&name,&birth);
		people.birthday = change(birth);
		vec.push_back(people);
	}

	int count = 0,max,min;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i].birthday <= 20140906 && vec[i].birthday >= 18140906)
		{
			if (!count)
				max = min = i;
			if (vec[i].birthday<vec[max].birthday)
				max = i;
			if (vec[i].birthday > vec[min].birthday)
				min = i;
			++count;
		}
	}
	if (count == 0)//×¢Òâ£¡£¡£¡£¡
		std::cout << 0;
	else
		std::cout << count << ' ' << vec[max].name << ' ' << vec[min].name;

	return 0;
}
