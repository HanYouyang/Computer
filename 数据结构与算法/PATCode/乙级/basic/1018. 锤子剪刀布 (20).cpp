#include<iostream>
#include<string>
#include<vector>

int main()
{
	int N,p=0;
	int js[3] = { 0 };
	int ys[3] = { 0 };
	char sl[3] = { 'B', 'C', 'J' };
	int yb = 0, yc = 0, yj = 0;
	std::cin >> N;	
	std::cin.get();
	std::vector<std::string> vec;
	std::string str;
	for (int i = 0; i < N; ++i)
	{
	    getline(std::cin,str);
		vec.push_back(str);
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i][0] == 'B'&&vec[i][2] == 'C')
			++js[0];
		if (vec[i][0] == 'C'&&vec[i][2] == 'J')
			++js[1];
		if (vec[i][0] == 'J'&&vec[i][2] == 'B')
			++js[2];
		if (vec[i][2] == 'B'&&vec[i][0] == 'C')
			++ys[0];
		if (vec[i][2] == 'C'&&vec[i][0] == 'J')
			++ys[1];
		if (vec[i][2] == 'J'&&vec[i][0] == 'B')
			++ys[2];
		if (vec[i][0] == vec[i][2])
			++p;
	}
	int jv = js[0]+js[1]+js[2];
	std::cout << jv << ' ' << p << ' ' << N - jv - p << std::endl;
	std::cout << N - jv - p << ' ' << p << ' ' << jv << std::endl;

	int id1 = 0, id2 = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (js[i]>js[id1])
			id1 = i;
		if (ys[i] > ys[id2])
			id2 = i;
	}
	std::cout << sl[id1] << ' ';
	std::cout << sl[id2];

	return 0;
}