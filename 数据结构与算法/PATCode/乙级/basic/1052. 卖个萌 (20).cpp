#include<iostream>
#include<string>
#include<vector>

struct Express
{
	int lh, le, mou, rh, re;
}express;
std::string hands[12];
std::string eyes[12];
std::string mouths[12];

int main()
{
	int N, h = 1, e = 1, m = 1;
	std::vector<Express> vec;
	std::string hand, eye, mouth;
	std::getline(std::cin, hand);
	std::getline(std::cin, eye);
	std::getline(std::cin, mouth);


	for (int i = 0, flag = 0; i < hand.size(); ++i)
	{
		if (hand[i] == ']')
			flag = 0, ++h;
		if (flag)
			hands[h].push_back(hand[i]);
		if (hand[i] == '[')
			flag = 1;
	}
	for (int i = 0, flag = 0; i < eye.size(); ++i)
	{
		if (eye[i] == ']')
			flag = 0, ++e;
		if (flag)
			eyes[e].push_back(eye[i]);
		if (eye[i] == '[')
			flag = 1;
	}
	for (int i = 0, flag = 0; i < mouth.size(); ++i)
	{
		if (mouth[i] == ']')
			flag = 0, ++m;
		if (flag)
			mouths[m].push_back(mouth[i]);
		if (mouth[i] == '[')
			flag = 1;
	}
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> express.lh >> express.le >> express.mou >> express.re >> express.rh;
		vec.push_back(express);
	}
	for (int i = 0; i < N; ++i)
	{
		if (vec[i].lh>h - 1 || vec[i].le>e - 1 || vec[i].mou > m - 1 || vec[i].re > e - 1 || vec[i].rh > h - 1)
			std::cout << "Are you kidding me? @\\/@\n";
		else if (vec[i].lh< 1 || vec[i].le< 1 || vec[i].mou < 1 || vec[i].re< 1 || vec[i].rh < 1)//注意小于1的情况！！！
			std::cout << "Are you kidding me? @\\/@\n";
		else	std::cout << hands[vec[i].lh] << '(' << eyes[vec[i].le] << mouths[vec[i].mou]
			<< eyes[vec[i].re] << ')' << hands[vec[i].rh] << std::endl;
	}

	return 0;
}